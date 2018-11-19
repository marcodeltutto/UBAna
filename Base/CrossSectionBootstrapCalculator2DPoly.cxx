#ifndef __BASE_CROSSSECTIONBOOTSTRAPCALCULATOR2DPOLY_CXX__
#define __BASE_CROSSSECTIONBOOTSTRAPCALCULATOR2DPOLY_CXX__

#include "CrossSectionBootstrapCalculator2DPoly.h"

namespace Base {


	void CrossSectionBootstrapCalculator2DPoly::Reset() 
  {

    _configured = false;

    _name = "Not configured!";
    _label = "Not configured!";

    _rwgt_flux = false;

    _do_smear = true;

    _hmap_bnbcosmic.clear();
    _hmap_dirt.clear();
    _h_bnbon = NULL;
    _h_extbnb = NULL;
    _h_intimecosmic = NULL;

    _true_to_reco_is_set = false;

    //_h_eff_mumom_num = NULL;
    //_h_eff_mumom_den = NULL;

    //_h_true_reco_mom = NULL;
  }

  void CrossSectionBootstrapCalculator2DPoly::SetScaleFactors(double bnbcosmic, double bnbon, double extbnb, double dirt, double intimecosmic)
  {
    _scale_factor_mc_bnbcosmic = bnbcosmic;
    _scale_factor_bnbon = bnbon;
    _scale_factor_extbnb = extbnb;
    _scale_factor_mc_dirt = dirt;
    _scale_factor_mc_intimecosmic = intimecosmic;

    _configured = true;
  }

  void CrossSectionBootstrapCalculator2DPoly::SetPOT(double pot)
  {
    _pot = pot;
  }

  void CrossSectionBootstrapCalculator2DPoly::SetBkgToSubtract(std::vector<std::string> bkg_names)
  {
    _bkg_names = bkg_names;
  }

  void CrossSectionBootstrapCalculator2DPoly::SetNameAndLabel(std::string name, std::string label)
  {
    _name = name;
    _label = label;
  }


  void CrossSectionBootstrapCalculator2DPoly::SetHistograms(std::map<std::string,std::map<std::string,UBTH2Poly*>>/*std::map<std::string,BootstrapTH1D>*/ bnbcosmic, UBTH2Poly* bnbon, UBTH2Poly* extbnb, std::map<std::string,UBTH2Poly*> dirt, UBTH2Poly* intimecosmic) 
  {

    _hmap_bnbcosmic = bnbcosmic;
    
    _hmap_dirt = dirt;

    if (bnbon != NULL) {
      _h_bnbon = (UBTH2Poly*)bnbon->Clone("_h_bnbon");
    }
    if (extbnb != NULL) {
      _h_extbnb = (UBTH2Poly*)extbnb->Clone("_h_extbnb");
    }
    if (intimecosmic != NULL) {
      _h_intimecosmic = (UBTH2Poly*)intimecosmic->Clone("_h_intimecosmic");
    }
  }

  void CrossSectionBootstrapCalculator2DPoly::SetTruthHistograms(BootstrapTH2DPoly* num, BootstrapTH2DPoly* den, std::map<std::string,std::vector<std::vector<double>>> bs_reco_per_true)
  {
    _h_eff_mumom_num = num;
    _h_eff_mumom_den = den;

    _bs_reco_per_true = bs_reco_per_true;

    _true_to_reco_is_set = true;

  }

  void CrossSectionBootstrapCalculator2DPoly::SetTruthHistograms(BootstrapTH2DPoly* num, BootstrapTH2DPoly* den)
  {
    _h_eff_mumom_num = num;
    _h_eff_mumom_den = den;
  }

  void CrossSectionBootstrapCalculator2DPoly::SetMigrationMatrixDimensions(int n, int m) 
  {
  	_n = n;
  	_m = m;
  }

  void CrossSectionBootstrapCalculator2DPoly::DoNotSmear()
  {
    _do_smear = false;
  }

  void CrossSectionBootstrapCalculator2DPoly::DrawProgressBar(double progress, double barWidth) {
  
    std::cout << "[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
    if (i < pos) std::cout << "=";
      else if (i == pos) std::cout << ">";
      else std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " % of universes completed.\r";
    std::cout.flush();
  }


  void CrossSectionBootstrapCalculator2DPoly::SetSavePrefix(std::string s, std::string folder)
  {
    std::string out_folder_base = std::getenv("MYSW_OUTDIR");

    std::string out_folder = out_folder_base + folder;

    std::string timestamp;
    auto now = std::time(nullptr);
    char buf[sizeof("YYYY-MM-DD_HH-MM-SS")];
    timestamp = std::string(buf,buf + std::strftime(buf,sizeof(buf),"%F_%H-%M-%S",std::gmtime(&now)));
      
    system(("mkdir -p " + out_folder + "_" + s + "_" + timestamp).c_str());    
    _save_prefix = out_folder + "_" + s + "_" + timestamp + "/" + s;
  }

  void CrossSectionBootstrapCalculator2DPoly::SetFluxHistogramType(bool rwgt_flux, std::string flux_unc_type)
  {
  	_rwgt_flux = rwgt_flux;
  	_flux_unc_type = flux_unc_type;
  }

  void CrossSectionBootstrapCalculator2DPoly::GetCovarianceMatrix(TH2D & h)
  {
    h = _cov_matrix;
  }

  void CrossSectionBootstrapCalculator2DPoly::GetFractionalCovarianceMatrix(TH2D & h)
  {
    h = _frac_cov_matrix;
  }

  void CrossSectionBootstrapCalculator2DPoly::SaveCovarianceMatrix(std::string file_name, std::string name)
  {
    TFile* cov_file = TFile::Open(file_name.c_str(), "UPDATE");
    cov_file->cd();
    _cov_matrix.Write(name.c_str());
    cov_file->Close();
  }

  void CrossSectionBootstrapCalculator2DPoly::SaveFractionalCovarianceMatrix(std::string file_name, std::string name)
  {
    TFile* cov_file = TFile::Open(file_name.c_str(), "UPDATE");
    cov_file->cd();
    _frac_cov_matrix.Write(name.c_str());
    cov_file->Close();
  }




  //
  // Main method
  //

	void CrossSectionBootstrapCalculator2DPoly::Run() 
	{

		gROOT->SetBatch(kTRUE);

		LOG_NORMAL() << "Started running." << std::endl;

		std::map<std::string, UBTH2Poly*> xsec_mumom_per_universe;

		
    _xsec_calc.set_verbosity(this->logger().level());
    _xsec_calc.SetScaleFactors(_scale_factor_mc_bnbcosmic, _scale_factor_bnbon, _scale_factor_extbnb, _scale_factor_mc_dirt);
    _xsec_calc.SetPOT(_pot);
    _xsec_calc.SetOutDir("output_data_mc_multisim");
    _xsec_calc.SetFluxCorrectionWeight(_flux_correction_weight);
    std::cout << _prefix << "Flux Correction Weight Set to: " << _flux_correction_weight << std::endl;
    std::cout << _prefix << "FLUX: " << _xsec_calc.EstimateFlux() << std::endl;
    _xsec_calc.SetVerbosity(false);


    size_t n_universe = _h_eff_mumom_num->GetNWeights();
    std::vector<std::string> universe_names = _h_eff_mumom_num->GetUniverseNames();

    LOG_NORMAL() << "Number of Universes: " << n_universe << std::endl;

    LOG_NORMAL() << "Universes Names: ";
    for (auto s : universe_names) {
    	std::cout << s << ", ";
    }
    std::cout << std::endl;

    
    UBTH2Poly * this_eff_num;
    UBTH2Poly * this_eff_den; 
    std::vector<std::vector<double>> this_reco_per_true;
    TMatrix S;

    // n_universe = 10;

    for (size_t s = 0; s < n_universe; s++) { 

      DrawProgressBar((double)s/(double)n_universe, 70);

      LOG_DEBUG() << "This is universe: " << universe_names.at(s) << std::endl;

      //
    	// Construct the hmap for the MC histograms (bnbcosmic)
      //
      std::map<std::string, UBTH2Poly*> input_map_mc;
      for (auto iter : _hmap_bnbcosmic) {

      	std::map<std::string, UBTH2Poly*> temp_map = iter.second;

        for (auto i2 : temp_map) {

          if (i2.first == universe_names.at(s)) {
            input_map_mc[iter.first] = i2.second;
            break;
          }
        }      
      }



      std::string hname; 

      //
      // Construct the hmap for the efficiency numerator and denominator
      //
      hname = "this_eff_num" + universe_names.at(s);
      this_eff_num = _h_eff_mumom_num->GetUniverseHisto(universe_names.at(s));
      hname = "this_eff_den" + universe_names.at(s);
      this_eff_den = _h_eff_mumom_den->GetUniverseHisto(universe_names.at(s));


      //
      // Costruct the reco_per_true histos for this universe
      //
      auto iter = _bs_reco_per_true.find(universe_names.at(s));
      if (iter == _bs_reco_per_true.end()) {
        LOG_CRITICAL() << "Can't find bs_reco_per_true for universe " << universe_names.at(s) << std::endl;
        throw std::exception();
      }
      this_reco_per_true = iter->second;


      //
      // Calculate flux for this universe
      //
      if (_rwgt_flux && universe_names.at(s) != "nominal") {
      	std::string flux_file = "MCC8_FluxHistograms_Uncertainties.root";

        // Find the universe number
        std::string universe_number;
        std::string::size_type pos = universe_names.at(s).find("universe");
        if (universe_names.at(s).npos != pos) {
          universe_number = universe_names.at(s).substr(pos+8);
        } else {
          std::cout << _prefix << "Universe name is not nominal nor universeXXX." << std::endl;
          throw std::exception();
        }

      	std::stringstream sstm;
        sstm << "numu/" << _flux_unc_type << "/Active_TPC_Volume/numu_" << _flux_unc_type << "_Uni_" << universe_number << "_AV_TPC";
        std::string flux_name = sstm.str();

        // std::cout << _prefix << "Using flux file: " << flux_file << ", with name " << flux_name << std::endl;
        _xsec_calc.EstimateFlux(flux_file, flux_name);
      }
      if (universe_names.at(s) == "nominal") {
        std::string flux_file = "MCC8_FluxHistograms_Uncertainties.root";

        // std::cout << _prefix << "Using flux file: " << flux_file << ", with name " << "numu/numu_CV_AV_TPC" << std::endl;
        _xsec_calc.EstimateFlux(flux_file, "numu/numu_CV_AV_TPC");
      }


      //
      // Calculate the migration matrix for this universe
      //
      if (_true_to_reco_is_set) {

        LOG_DEBUG() << "Calculating migration matrix. It will have " << input_map_mc["total"]->GetNumberOfBins() << " bins." << std::endl;

        MigrationMatrix4DPoly migrationmatrix4d;
        migrationmatrix4d.DoMakePlots(false);
        migrationmatrix4d.SetRecoPerTrueVectors(this_reco_per_true);
        migrationmatrix4d.SetTemplateHisto(input_map_mc["total"]);
        migrationmatrix4d.SetBins(input_map_mc["total"]->GetNumberOfBins());

        S.ResizeTo(input_map_mc["total"]->GetNumberOfBins(), input_map_mc["total"]->GetNumberOfBins());

        S = migrationmatrix4d.CalculateMigrationMatrix();
      }

      LOG_DEBUG() << "Migration matrix calculated for universe " << s << "." << std::endl;


      //
      // Calculate the cross section with these new objects in this universe
      //
      _xsec_calc.Reset();

      //h_trkmom_total_extbnb->Scale(1./scale_factor_extbnb);
      _xsec_calc.SetHistograms(input_map_mc, _h_bnbon, _h_extbnb, _hmap_dirt);  
      if (_true_to_reco_is_set) {
        _xsec_calc.SetTruthHistograms(this_eff_num, this_eff_den);
      } else {
        _xsec_calc.SetTruthHistograms(this_eff_num, this_eff_den);
      }
      //_xsec_calc.SetTruthXSec(h_truth_xsec_mumom);
      _xsec_calc.SetNameAndLabel("trkcostheta_trkmumom_", ";Candidate Track cos(#theta) [GeV];Candidate Track Momentum (MCS) [GeV]");
      _xsec_calc.ProcessPlots();
      _xsec_calc.SetSmearingMatrix(S);
      _xsec_calc.Smear();

      LOG_DEBUG() << "Smearing done for universe " << s << "." << std::endl;

      UBTH2Poly* universe_xsec = _xsec_calc.ExtractCrossSection(_bkg_names, "cos(#theta_{#mu})", "p_{#mu} [GeV]", "d^{2}#sigma/dcos(#theta_{#mu}dp_{#mu}) [10^{-38} cm^{2}/GeV]", false);

      LOG_DEBUG() << "Cross section calculated for universe " << s << "." << std::endl;
      
      xsec_mumom_per_universe[universe_names.at(s)] = universe_xsec;

    } // end loop over universes
    std::cout << std::endl;

    LOG_NORMAL() << "Finished loop over universes." << std::endl;

    


    
    

    //
    // Calculate the covariance matrix
    //

    BootstrapTH2DPoly xsec_mumom_bs;
    xsec_mumom_bs.SetAllHistograms(xsec_mumom_per_universe);

    CovarianceCalculator4D _cov_calc;
    _cov_calc.set_verbosity(this->logger().level());
    _cov_calc.SetPrefix(_save_prefix);
    _cov_calc.SetBootstrap(xsec_mumom_bs);
    _cov_calc.AddExtraDiagonalUncertainty(_extra_relative_uncertainty);
    _cov_calc.CalculateCovarianceMatrix();
    _cov_calc.PlotMatrices();
    _cov_calc.GetCovarianceMatrix(_cov_matrix);
    _cov_calc.GetFractionalCovarianceMatrix(_frac_cov_matrix);

    LOG_NORMAL() << "Covariance matrix calculated." << std::endl;




    //
    // Plot all the xsec in one plot
    //
    
    LOG_NORMAL() << "Generating plots. This may take a while." << std::endl;

    DrawXSec(xsec_mumom_per_universe);

    LOG_NORMAL() << "All done here." << std::endl;


	}




  void CrossSectionBootstrapCalculator2DPoly::DrawXSec(std::map<std::string, UBTH2Poly*> xsec_mumom_per_universe) 
  {

    int x_bins = xsec_mumom_per_universe["nominal"]->GetNBinsX();

    int horizontal_division = 2;
    int vertical_division = floor(x_bins / 2.);

    if (x_bins / 2. != floor(x_bins / 2.)) vertical_division++;

    LOG_INFO() << "Horizontal divisions " << horizontal_division << std::endl;
    LOG_INFO() << "Vertical divisions " << vertical_division << std::endl;

    TCanvas *c_test = new TCanvas("c_test", "multipads",0,45,1006,1150);
    c_test->SetBottomMargin(0.15);
    // gStyle->SetOptStat(0);
    c_test->Divide(horizontal_division, vertical_division, 0.01, 0.01);

    // reverse_iterator because we want to have the nominal at the end
    std::map<std::string, UBTH2Poly*>::reverse_iterator it = xsec_mumom_per_universe.rbegin();

    std::vector<double> maxima;
    maxima.resize(xsec_mumom_per_universe["nominal"]->GetNBinsX(), 0);

    std::vector<std::vector<int>> bin_numbers;
  
    TH1D* h_nominal; // just for the legend
    TH1D* h_other; // just for the legend

    while (it != xsec_mumom_per_universe.rend()) {    

      UBTH2Poly * h_xsec_2d = it->second;

      LOG_INFO() << "Drawing universe " << it->first << std::endl;

      // std::vector<TH1D> xsec_data_histos;
      std::vector<TH1D> xsec_mc_histos;
      std::vector<std::string> costhetamu_ranges = {"-1.00 #leq cos(#theta_{#mu}^{reco}) < -0.50",
                                                  "-0.50 #leq cos(#theta_{#mu}^{reco}) < 0.00",
                                                  "0.00 #leq cos(#theta_{#mu}^{reco}) < 0.27",
                                                  "0.27 #leq cos(#theta_{#mu}^{reco}) < 0.45",
                                                  "0.45 #leq cos(#theta_{#mu}^{reco}) < 0.62",
                                                  "0.62 #leq cos(#theta_{#mu}^{reco}) < 0.76",
                                                  "0.76 #leq cos(#theta_{#mu}^{reco}) < 0.86",
                                                  "0.86 #leq cos(#theta_{#mu}^{reco}) < 0.94",
                                                  "0.94 #leq cos(#theta_{#mu}^{reco}) < 1.00",
                                                  "nan #leq cos(#theta_{#mu}^{reco}) < nan",
                                                  "nan #leq cos(#theta_{#mu}^{reco}) < nan",};

     
      bin_numbers.resize(h_xsec_2d->GetNBinsX());
      for (int i = 0; i < h_xsec_2d->GetNBinsX(); i++) {
        // xsec_data_histos.emplace_back(*h_data->ProjectionY("fuck", i+1, i+2));
        xsec_mc_histos.emplace_back(*h_xsec_2d->ProjectionY("fuck", i+1, bin_numbers.at(i)));
      }


      for (size_t i = 0; i < xsec_mc_histos.size(); i++) {

        c_test->cd(i+1);
        gPad->SetBottomMargin(0.15);
        gPad->SetLeftMargin(0.15);
        gPad->SetTopMargin(0.1128947);
        xsec_mc_histos.at(i).SetTitle(costhetamu_ranges.at(i).c_str());
        xsec_mc_histos.at(i).GetXaxis()->SetTitle("p_{#mu}^{reco} [GeV]");
        xsec_mc_histos.at(i).GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{#mu}^{reco}dcos(#theta_{#mu}^{reco})} [10^{-38} cm^{2}/GeV/n]");
        xsec_mc_histos.at(i).GetXaxis()->CenterTitle();
        xsec_mc_histos.at(i).GetYaxis()->CenterTitle();
        xsec_mc_histos.at(i).SetLineColor(kGreen+1);
        xsec_mc_histos.at(i).SetFillColor(29);
        xsec_mc_histos.at(i).GetXaxis()->SetTitleOffset(0.92);
        xsec_mc_histos.at(i).GetYaxis()->SetTitleOffset(1.11);
        // if (it->first == "nominal") {
        //   xsec_mc_histos.at(i).SetLineColor(kRed+2);
        // }
        // xsec_mc_histos.at(i).Draw("E2");
        TH1D* h_main = (TH1D*) xsec_mc_histos.at(i).Clone("h_main");
        h_main->SetLineColor(kGreen+2);
        if (it->first == "nominal") {
          h_main->SetLineColor(kRed+2);
          h_main->SetLineWidth(2);

          // Add uncertainties if nominal histo
          for (int bin = 1; bin <= h_main->GetNbinsX(); bin++) {
            int original_bin_number = bin_numbers.at(i).at(bin-1);
            h_main->SetBinError(bin, std::sqrt(_cov_matrix.GetBinContent(original_bin_number, original_bin_number)));
            // if (bin == 2) LOG_CRITICAL() << "Setting bin " << bin << " with error " << std::sqrt(_cov_matrix.GetBinContent(original_bin_number, original_bin_number)) << " (coming from original bin " << original_bin_number << ")" << std::endl;
          }
          h_main->SetFillColor(0); // fully transparent
          h_main->Draw("E1 same"); // also error bars for nominal
          h_nominal = h_main;
        }
        else {
          h_main->SetFillColor(0); // fully transparent
          h_main->Draw("histo same");
          h_other = h_main;
        }

        // if (h_main->GetMaximum() > maxima.at(i)) maxima.at(i) = h_main->GetMaximum();
        // h_main->SetMaximum(maxima.at(i));
        h_main->SetMaximum(h_main->GetMaximum() * 1.5);

        xsec_mc_histos.at(i).SetMinimum(0.);
        if (i == 0) xsec_mc_histos.at(i).SetMaximum(0.40);
        if (i == 1) xsec_mc_histos.at(i).SetMaximum(0.40);
        if (i == 2) xsec_mc_histos.at(i).SetMaximum(0.60);
        if (i == 3) xsec_mc_histos.at(i).SetMaximum(0.80);
        if (i == 4) xsec_mc_histos.at(i).SetMaximum(1.25);
        if (i == 5) xsec_mc_histos.at(i).SetMaximum(1.90);


      }

      

      it++;
    } // Loop over universes in reverse order


    // Add a legend
    int legend_pad = 0;
    if (x_bins / 2. != floor(x_bins / 2.)) legend_pad = horizontal_division * vertical_division; // Last empty pad
    else legend_pad = 1; // First pad

    c_test->cd(legend_pad);
    TLegend *leg = new TLegend(0.15,0.44,0.82,0.670,NULL,"brNDC");
    leg->SetBorderSize(0);
    leg->SetTextAlign(22);
    leg->SetTextSize(0.08402531);
    leg->SetLineColor(1);
    leg->SetLineStyle(1);
    leg->SetLineWidth(1);
    leg->SetFillColor(0);
    leg->SetFillStyle(0);
    leg->AddEntry(h_other,   "Data Cross Section - All Universes","l");
    leg->AddEntry(h_nominal, "Data Cross Section - Central Value","le");
    leg->Draw();

    c_test->SaveAs((_save_prefix + "_xsec_all_fancy_2d.pdf").c_str());
    c_test->SaveAs((_save_prefix + "_xsec_all_fancy_2d.C").c_str());
  }
}

#endif

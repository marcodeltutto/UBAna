#ifndef __BASE_CROSSSECTIONBOOTSTRAPCALCULATOR2D_CXX__
#define __BASE_CROSSSECTIONBOOTSTRAPCALCULATOR2D_CXX__

#include "CrossSectionBootstrapCalculator2D.h"

namespace Base {


	void CrossSectionBootstrapCalculator2D::Reset() 
  {

    _configured = false;

    _name = "Not configured!";
    _label = "Not configured!";

    _rwgt_flux = false;

    _do_smear = true;

    _hmap_bnbcosmic.clear();
    _h_bnbon = NULL;
    _h_extbnb = NULL;
    _h_intimecosmic = NULL;

    _true_to_reco_is_set = false;

    //_h_eff_mumom_num = NULL;
    //_h_eff_mumom_den = NULL;

    //_h_true_reco_mom = NULL;
  }

  void CrossSectionBootstrapCalculator2D::SetScaleFactors(double bnbcosmic, double bnbon, double extbnb, double intimecosmic)
  {
    _scale_factor_mc_bnbcosmic = bnbcosmic;
    _scale_factor_bnbon = bnbon;
    _scale_factor_extbnb = extbnb;
    _scale_factor_mc_intimecosmic = intimecosmic;

    _configured = true;
  }

  void CrossSectionBootstrapCalculator2D::SetPOT(double pot)
  {
    _pot = pot;
  }

  void CrossSectionBootstrapCalculator2D::SetNameAndLabel(std::string name, std::string label)
  {
    _name = name;
    _label = label;
  }

  void CrossSectionBootstrapCalculator2D::SetOutDir(std::string dir)
  {
    _outdir = dir;

    auto now = std::time(nullptr);
    char buf[sizeof("YYYY-MM-DD_HH-MM-SS")];
    std::string timestamp = std::string(buf,buf + std::strftime(buf,sizeof(buf),"%F_%H-%M-%S",std::gmtime(&now)));

    _folder = _outdir + "_" + timestamp + "/";

    system(("mkdir " + _folder).c_str());

  }



/*
  void CrossSectionBootstrapCalculator2D::PrintConfig() {

    std::cout << "--- CrossSectionBootstrapCalculator2D:" << std::endl;
    std::cout << "---   _scale_factor_mc_bnbcosmic     = " << _scale_factor_mc_bnbcosmic << std::endl;
    std::cout << "---   _scale_factor_bnbon            = " << _scale_factor_bnbon << std::endl;
    std::cout << "---   _scale_factor_extbnb           = " << _scale_factor_extbnb << std::endl;
    std::cout << "---   _scale_factor_mc_intimecosmic  = " << _scale_factor_mc_intimecosmic << std::endl;
    std::cout << "---   _pot                           = " << _pot << std::endl;

  }
  */

  void CrossSectionBootstrapCalculator2D::SetHistograms(std::map<std::string,std::map<std::string,TH2D*>>/*std::map<std::string,BootstrapTH1D>*/ bnbcosmic, TH2D* bnbon, TH2D* extbnb, TH2D* intimecosmic) 
  {

    _hmap_bnbcosmic = bnbcosmic;
    
    if (bnbon != NULL) {
      _h_bnbon = (TH2D*)bnbon->Clone("_h_bnbon");
    }
    if (extbnb != NULL) {
      _h_extbnb = (TH2D*)extbnb->Clone("_h_extbnb");
    }
    if (intimecosmic != NULL) {
      _h_intimecosmic = (TH2D*)intimecosmic->Clone("_h_intimecosmic");
    }
  }

  void CrossSectionBootstrapCalculator2D::SetTruthHistograms(BootstrapTH2D num, BootstrapTH2D den, TTree *t)
  {
    _h_eff_mumom_num = num;
    _h_eff_mumom_den = den;

    _t_true_reco = t;

    _true_to_reco_is_set = true;

    std::cout << "_true_to_reco_is_set is true" << std::endl;

  }

  void CrossSectionBootstrapCalculator2D::SetTruthHistograms(BootstrapTH2D num, BootstrapTH2D den)
  {
    _h_eff_mumom_num = num;
    _h_eff_mumom_den = den;
  }

  void CrossSectionBootstrapCalculator2D::SetMigrationMatrixDimensions(int n, int m) 
  {
  	_n = n;
  	_m = m;
  }

  void CrossSectionBootstrapCalculator2D::DoNotSmear()
  {
    _do_smear = false;
  }

  void CrossSectionBootstrapCalculator2D::DrawProgressBar(double progress, double barWidth) {
  
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


  void CrossSectionBootstrapCalculator2D::SetSavePrefix(std::string s, std::string folder)
  {
    if (folder != "") {
      auto now = std::time(nullptr);
      char buf[sizeof("YYYY-MM-DD_HH-MM-SS")];
      std::string timestamp = std::string(buf,buf + std::strftime(buf,sizeof(buf),"%F_%H-%M-%S",std::gmtime(&now)));
      
      system(("mkdir -p " + folder + "_" + timestamp).c_str());    
    }
  	_save_prefix = folder + "/" + s;
  }

  void CrossSectionBootstrapCalculator2D::SetFluxHistogramType(bool rwgt_flux, std::string flux_unc_type)
  {
  	_rwgt_flux = rwgt_flux;
  	_flux_unc_type = flux_unc_type;
  }

  void CrossSectionBootstrapCalculator2D::GetCovarianceMatrix(TH2D & h)
  {
    h = _cov_matrix;
  }

  void CrossSectionBootstrapCalculator2D::SaveCovarianceMatrix(std::string file_name, std::string name)
  {
    TFile* cov_file = TFile::Open(file_name.c_str(), "UPDATE");
    cov_file->cd();
    _cov_matrix.Write(name.c_str());
    cov_file->Close();
  }


  //
  // Main method
  //

	void CrossSectionBootstrapCalculator2D::Run() 
	{

		gROOT->SetBatch(kTRUE);

		std::cout << _prefix << "Started running." << std::endl;

		std::map<std::string, TH2D*> xsec_mumom_per_universe;


		CrossSectionCalculator2D _xsec_calc;
    _xsec_calc.SetScaleFactors(_scale_factor_mc_bnbcosmic, _scale_factor_bnbon, _scale_factor_extbnb);
    _xsec_calc.SetPOT(_pot);
    _xsec_calc.SetOutDir("output_data_mc_multisim");
    _xsec_calc.SetFluxCorrectionWeight(_flux_correction_weight);
    std::cout << _prefix << "Flux Correction Weight Set to: " << _flux_correction_weight << std::endl;
    std::cout << _prefix << "FLUX: " << _xsec_calc.EstimateFlux() << std::endl;
    _xsec_calc.SetVerbosity(false);

    std::vector<std::string> hist_to_subtract = {"beam-off", "cosmic", "outfv", "nc", "nue", "anumu"};




    size_t n_universe = _h_eff_mumom_num.GetNWeights();
    std::vector<std::string> universe_names = _h_eff_mumom_num.GetUniverseNames();

    std::cout << _prefix << "Number of Universes: " << n_universe << std::endl;
    // std::cout << _prefix << "universe_names.size() " << universe_names.size() << std::endl;

    std::cout << _prefix << "Universes Names: ";
    for (auto s : universe_names) {
    	std::cout << s << ", ";
    }
    std::cout << std::endl;

    
    TH2D this_h;
    TH2D this_eff_num;
    TH2D this_eff_den; 
    // TTree* this_reco_true;
    Mat4D S_4d;

    // n_universe = 2;

    for (size_t s = 0; s < n_universe; s++) { 

      DrawProgressBar((double)s/(double)n_universe, 70);

    	// std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> This is universe " << s << ", with name " << universe_names.at(s) << std::endl;

      //
    	// Construct the hmap for the MC histograms
      //
      // to be removed int counter = 0;
      std::map<std::string, TH2D*> input_map_mc;
      for (auto iter : _hmap_bnbcosmic) {

      	std::map<std::string, TH2D*> temp_map = iter.second;

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
      _h_eff_mumom_num.GetUniverseHisto(universe_names.at(s), this_eff_num);
      hname = "this_eff_den" + universe_names.at(s);
      _h_eff_mumom_den.GetUniverseHisto(universe_names.at(s), this_eff_den);

    
      //
      // Construct the map true vs reco
      //
      // if (_true_to_reco_is_set) {
      //   hname = "this_reco_true" + universe_names.at(s);
      //   _h_true_reco_mom.GetUniverseHisto(universe_names.at(s), this_reco_true);
      // }


      //
      // Calculate flux for this universe
      //
      if (_rwgt_flux && universe_names.at(s) != "nominal") {
      	std::string flux_file = "MCC8_FluxHistograms_Uncertainties.root";

      	std::stringstream sstm;
        sstm << "numu/" << _flux_unc_type << "/Active_TPC_Volume/numu_" << _flux_unc_type << "_Uni_" << s << "_AV_TPC";
        std::string flux_name = sstm.str();

        std::cout << _prefix << "Using flux file: " << flux_file << ", with name " << flux_name << std::endl;
        _xsec_calc.EstimateFlux(flux_file, flux_name);
      }
      if (universe_names.at(s) == "nominal") {
        std::string flux_file = "MCC8_FluxHistograms_Uncertainties.root";

        std::cout << _prefix << "Using flux file: " << flux_file << ", with name " << "numu/numu_CV_AV_TPC" << std::endl;
        _xsec_calc.EstimateFlux(flux_file, "numu/numu_CV_AV_TPC");
      }


      // Calculate the migration matrix for this universe
      if (_true_to_reco_is_set) {

        MigrationMatrix4D migrationmatrix4d;
        migrationmatrix4d.SetTTree(_t_true_reco);
        migrationmatrix4d.UseWeights(universe_names.at(s));
        int n_bins_mumom_temp = 4;
        double bins_mumom_temp[5] = {0.00, 0.25, 0.50, 1.0, 2.50};
        int n_bins_mucostheta_temp = 6;
        double bins_mucostheta_temp[7] = {-1.00, -0.50, 0.00, 0.25, 0.50, 0.75, 1.00};
        migrationmatrix4d.SetBins(bins_mucostheta_temp, n_bins_mucostheta_temp, bins_mumom_temp, n_bins_mumom_temp);
        S_4d = migrationmatrix4d.CalculateMigrationMatrix();
        migrationmatrix4d.SetOutputFileName("latex_test_bootstrap.tex");
        migrationmatrix4d.PrintSmearingMatrixLatex();
      }



      // Calculate the cross section with these new objects in this universe

      _xsec_calc.Reset();
      //h_trkmom_total_extbnb->Scale(1./scale_factor_extbnb);
      _xsec_calc.SetHistograms(input_map_mc, _h_bnbon, _h_extbnb);  
      if (_true_to_reco_is_set) {
        _xsec_calc.SetTruthHistograms(&this_eff_num, &this_eff_den);
      } else {
        _xsec_calc.SetTruthHistograms(&this_eff_num, &this_eff_den);
      }
      //_xsec_calc.SetTruthXSec(h_truth_xsec_mumom);
      _xsec_calc.SetNameAndLabel("trkcostheta_trkmumom_", ";Candidate Track cos(#theta) [GeV];Candidate Track Momentum (MCS) [GeV]");
      _xsec_calc.ProcessPlots();
      _xsec_calc.SetSmearingMatrix(S_4d);
      _xsec_calc.Smear();

      TH2D* universe_xsec = _xsec_calc.ExtractCrossSection("cos(#theta_{#mu})", "p_{#mu} [GeV]", "d^{2}#sigma/dcos(#theta_{#mu}dp_{#mu}) [10^{-38} cm^{2}/GeV]");

      xsec_mumom_per_universe[universe_names.at(s)] = universe_xsec;

      // if(universe_names.at(s) == "nominal") {
      //   std::cout << "Nominal xsec, 00: " << universe_xsec->GetBinContent(1,1) << std::endl;
      //   std::cout << "Nominal xsec, 01: " << universe_xsec->GetBinContent(1,2) << std::endl;
      //   std::cout << "Nominal xsec, 10: " << universe_xsec->GetBinContent(2,1) << std::endl;
      //   std::cout << "Nominal xsec, 11: " << universe_xsec->GetBinContent(2,2) << std::endl;
      // }

    } // endl loop over universes


    
    

    //
    // Make the cross section plot with all the variations
    //

    BootstrapTH2D xsec_mumom_bs;
    xsec_mumom_bs.SetAllHistograms(xsec_mumom_per_universe);

    // std::cout << "xsec_mumom_bs.GetNbinsX() " << xsec_mumom_bs.GetNbinsX() << std::endl;
    // std::cout << "xsec_mumom_bs.GetNbinsY() " << xsec_mumom_bs.GetNbinsY() << std::endl;



    
    // Covariance Matrix
    CovarianceCalculator4D _cov_calc;
    _cov_calc.SetPrefix(_save_prefix);
    _cov_calc.SetBootstrap(xsec_mumom_bs);
    _cov_calc.AddExtraDiagonalUncertainty(_extra_relative_uncertainty);
    _cov_calc.CalculateCovarianceMatrix();
    _cov_calc.PlotMatrices();

    // _cov_calc.GetCovarianceMatrix(_cov_matrix);



    //
    // Plot all the xsec in one plot
    //
    
    DrawXSec(xsec_mumom_per_universe);

   


    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;

	}




  void CrossSectionBootstrapCalculator2D::DrawXSec(std::map<std::string, TH2D*> xsec_mumom_per_universe) 
  {

    TCanvas *c_test = new TCanvas("c_test", "multipads",0,45,1006,1150);
    c_test->SetBottomMargin(0.15);
    // gStyle->SetOptStat(0);
    c_test->Divide(2,3,0.01,0.01);

    // reverse_iterator because we want to have the nominal at the end
    std::map<std::string, TH2D*>::reverse_iterator it = xsec_mumom_per_universe.rbegin();

    while (it != xsec_mumom_per_universe.rend()) {    
    // for (auto it : xsec_mumom_per_universe) {

      TH2D h_xsec_2d = *it->second;


      // std::vector<TH1D> xsec_data_histos;
    std::vector<TH1D> xsec_mc_histos;
    std::vector<std::string> costhetamu_ranges = {"-1.00 #leq cos(#theta_{#mu}^{reco}) < -0.50",
                                                  "-0.50 #leq cos(#theta_{#mu}^{reco}) < 0.00",
                                                  "0.00 #leq cos(#theta_{#mu}^{reco}) < 0.25",
                                                  "0.25 #leq cos(#theta_{#mu}^{reco}) < 0.50",
                                                  "0.50 #leq cos(#theta_{#mu}^{reco}) < 0.75",
                                                  "1.75 #leq cos(#theta_{#mu}^{reco}) < 1.00"};

    std::cout << "n bins x " << h_xsec_2d.GetNbinsX() << std::endl;
    std::cout << "n bins y " << h_xsec_2d.GetNbinsY() << std::endl;    

    for (int i = 0; i < h_xsec_2d.GetNbinsX(); i++) {
      // xsec_data_histos.emplace_back(*h_data->ProjectionY("fuck", i+1, i+2));
      xsec_mc_histos.emplace_back(*h_xsec_2d.ProjectionY("fuck", i+1, i+1));
    }


    for (int i = 0; i < xsec_mc_histos.size(); i++) {
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
      if (it->first == "nominal") {
        xsec_mc_histos.at(i).SetLineColor(kGreen+3);
      }
      // xsec_mc_histos.at(i).Draw("E2");
      TH1D* h_main = (TH1D*) xsec_mc_histos.at(i).Clone("h_main");
      h_main->SetLineColor(kGreen+2);
      if (it->first == "nominal") {
        h_main->SetLineColor(kGreen+3);
        h_main->SetLineWidth(3);
      }
      h_main->SetFillColor(0); // fully transparent
      h_main->Draw("histo same");

      xsec_mc_histos.at(i).SetMinimum(0.);
      if (i == 0) {
        xsec_mc_histos.at(i).SetMaximum(0.7);
      }



    }


    
    

      // xsec_data_histos.at(i).Draw("E1 X0 same");

      // if (i == 0) {
      //   TLegend *l;
      //   l = new TLegend(0.3671979,0.67415,0.7178785,0.8019232,NULL,"brNDC");
      //   l->SetFillColor(0);
      //   l->SetFillStyle(0);
      //   l->SetTextSize(0.03407284);
      //   l->AddEntry(&xsec_mc_histos.at(i), "GENIE Default + Emp. MEC (Stat. Unc.)");
      //   // l->AddEntry(&xsec_data_histos.at(i), "Measured (Stat. Unc.)", "ep");
      //   l->Draw();
      // }

      c_test->SaveAs((_save_prefix + "_xsec_all_fancy_2d.pdf").c_str());
      c_test->SaveAs((_save_prefix + "_xsec_all_fancy_2d.C").c_str());

      it++;
    }
  }
}

#endif

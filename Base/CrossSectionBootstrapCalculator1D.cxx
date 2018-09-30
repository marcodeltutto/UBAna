#ifndef __BASE_CROSSSECTIONBOOTSTRAPCALCULATOR1D_CXX__
#define __BASE_CROSSSECTIONBOOTSTRAPCALCULATOR1D_CXX__

#include "CrossSectionBootstrapCalculator1D.h"
#include "PlottingTools.h"

namespace Base {


	void CrossSectionBootstrapCalculator1D::Reset() 
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

  void CrossSectionBootstrapCalculator1D::SetScaleFactors(double bnbcosmic, double bnbon, double extbnb, double dirt, double intimecosmic)
  {
    _scale_factor_mc_bnbcosmic = bnbcosmic;
    _scale_factor_bnbon = bnbon;
    _scale_factor_extbnb = extbnb;
    _scale_factor_mc_dirt = dirt;
    _scale_factor_mc_intimecosmic = intimecosmic;

    _configured = true;
  }

  void CrossSectionBootstrapCalculator1D::SetPOT(double pot)
  {
    _pot = pot;
  }

  void CrossSectionBootstrapCalculator1D::SetBkgToSubtract(std::vector<std::string> bkg_names)
  {
    _bkg_names = bkg_names;
  }

  void CrossSectionBootstrapCalculator1D::SetNameAndLabel(std::string name, std::string label)
  {
    _name = name;
    _label = label;
  }



  void CrossSectionBootstrapCalculator1D::SetHistograms(std::map<std::string,std::map<std::string,TH1D*>>/*std::map<std::string,BootstrapTH1D>*/ bnbcosmic, TH1D* bnbon, TH1D* extbnb, std::map<std::string,TH1D*> dirt, TH1D* intimecosmic) 
  {

    _hmap_bnbcosmic = bnbcosmic;
    
    _hmap_dirt = dirt;

    if (bnbon != NULL) {
      _h_bnbon = (TH1D*)bnbon->Clone("_h_bnbon");
    }
    if (extbnb != NULL) {
      _h_extbnb = (TH1D*)extbnb->Clone("_h_extbnb");
    }
    if (intimecosmic != NULL) {
      _h_intimecosmic = (TH1D*)intimecosmic->Clone("_h_intimecosmic");
    }
  }

  void CrossSectionBootstrapCalculator1D::SetTruthHistograms(BootstrapTH1D num, BootstrapTH1D den, BootstrapTH2D h)
  {
    _h_eff_mumom_num = num;
    _h_eff_mumom_den = den;

    _h_true_reco_mom = h;

    _true_to_reco_is_set = true;

    LOG_DEBUG() << "_true_to_reco_is_set is true" << std::endl;

  }

  void CrossSectionBootstrapCalculator1D::SetTruthHistograms(BootstrapTH1D num, BootstrapTH1D den)
  {
    _h_eff_mumom_num = num;
    _h_eff_mumom_den = den;
    LOG_DEBUG() << "called SetTruthHistograms with no true to reco" << std::endl;
  }

  void CrossSectionBootstrapCalculator1D::SetMigrationMatrixDimensions(int n, int m) 
  {
  	_n = n;
  	_m = m;
  }

  void CrossSectionBootstrapCalculator1D::DoNotSmear()
  {
    _do_smear = false;
  }


  void CrossSectionBootstrapCalculator1D::SetSavePrefix(std::string s, std::string folder)
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

  void CrossSectionBootstrapCalculator1D::SetFluxHistogramType(bool rwgt_flux, std::string flux_unc_type)
  {
  	_rwgt_flux = rwgt_flux;
  	_flux_unc_type = flux_unc_type;
  }

  void CrossSectionBootstrapCalculator1D::GetCovarianceMatrix(TH2D & h)
  {
    h = _cov_matrix;
  }

  void CrossSectionBootstrapCalculator1D::GetFractionalCovarianceMatrix(TH2D & h)
  {
    h = _frac_cov_matrix;
  }

  void CrossSectionBootstrapCalculator1D::SaveCovarianceMatrix(std::string file_name, std::string name)
  {
    TFile* cov_file = TFile::Open(file_name.c_str(), "UPDATE");
    cov_file->cd();
    _cov_matrix.Write(name.c_str());
    cov_file->Close();
  }

  void CrossSectionBootstrapCalculator1D::SaveFractionalCovarianceMatrix(std::string file_name, std::string name)
  {
    TFile* cov_file = TFile::Open(file_name.c_str(), "UPDATE");
    cov_file->cd();
    _frac_cov_matrix.Write(name.c_str());
    cov_file->Close();
  }


  //
  // Main method
  //

	void CrossSectionBootstrapCalculator1D::Run() 
	{

		gROOT->SetBatch(kTRUE);

		LOG_NORMAL() << "CrossSectionBootstrapCalculator1D Starts Running" << std::endl;

		std::map<std::string, TH1D*> xsec_mumom_per_universe;


		CrossSectionCalculator1D _xsec_calc;
    _xsec_calc.SetVerbose(false);
    _xsec_calc.set_verbosity(Base::msg::kNORMAL);
    _xsec_calc.SetScaleFactors(_scale_factor_mc_bnbcosmic, _scale_factor_bnbon, _scale_factor_extbnb, _scale_factor_mc_dirt);
    _xsec_calc.SetPOT(_pot);
    _xsec_calc.SetOutDir("output_data_mc_multisim");
    _xsec_calc.SetFluxCorrectionWeight(_flux_correction_weight);
    LOG_NORMAL() << "Flux Correction Weight Set to: " << _flux_correction_weight << std::endl;
    LOG_NORMAL() << "CrossSectionBootstrapCalculator1D FLUX: " << _xsec_calc.EstimateFlux() << std::endl;

    std::vector<std::string> hist_to_subtract = {"beam-off", "cosmic", "outfv", "nc", "nue", "anumu"};




    size_t n_universe = _h_eff_mumom_num.GetNWeights();
    std::vector<std::string> universe_names = _h_eff_mumom_num.GetUniverseNames();

    LOG_NORMAL() << "Number of universes: " << n_universe << std::endl;
    LOG_NORMAL() << "Universes names: "; 
    for (auto s : universe_names) {
    	std::cout << s << ", ";
    }
    std::cout << std::endl;

    
    TH1D this_h;
    TH1D this_eff_num;
    TH1D this_eff_den; 
    TH2D this_reco_true;
    TMatrix S_2d;

    // n_universe = 30;

    for (size_t s = 0; s < n_universe; s++) { 

      PlottingTools::DrawProgressBar((double)s/(double)n_universe, 70);

    	LOG_DEBUG() << ">>>>>>>>>>>>>>>>>>>>>>>>>> This is universe " << s << ", with name " << universe_names.at(s) << std::endl;

      //
    	// Construnct the hmap for the MC histograms (bnbcosmic)
      //
      // to be removed int counter = 0;
      std::map<std::string, TH1D*> input_map_mc;
      for (auto iter : _hmap_bnbcosmic) {

      	std::map<std::string, TH1D*> temp_map = iter.second;

        for (auto i2 : temp_map) {

          if (i2.first == universe_names.at(s)) {
            input_map_mc[iter.first] = i2.second;
            break;
          }
        }      
      }

      //
      // Construnct the hmap for the MC histograms (dirt)
      //
      // to be removed int counter = 0;
      // std::map<std::string, TH1D*> input_map_mc_dirt;
      // for (auto iter : _hmap_dirt) {

      //   std::map<std::string, TH1D*> temp_map = iter.second;

      //   for (auto i2 : temp_map) {

      //     if (i2.first == universe_names.at(s)) {
      //       input_map_mc_dirt[iter.first] = i2.second;
      //       break;
      //     }
      //   }      
      // }

        //std::string hname = "this_h" + iter.first;
      	//TH1D * this_h = (TH1D*) iter.second.GetUniverseHisto(universe_names.at(s)).Clone(hname.c_str());
      	//m iter.second.GetUniverseHistoFast(universe_names.at(s), this_h);

    	  //input_map_mc[iter.first] = &this_h;
      //}


      std::string hname; 

      //
      // Construct the hmap for the efficiency numerator and denominator
      //
      hname = "this_eff_num" + universe_names.at(s);
      //TH1D * this_eff_num = (TH1D*) _h_eff_mumom_num.GetUniverseHisto(universe_names.at(s)).Clone(hname.c_str());
      _h_eff_mumom_num.GetUniverseHisto(universe_names.at(s), this_eff_num);
      hname = "this_eff_den" + universe_names.at(s);
      //TH1D * this_eff_den = (TH1D*) _h_eff_mumom_den.GetUniverseHisto(universe_names.at(s)).Clone(hname.c_str());
      _h_eff_mumom_den.GetUniverseHisto(universe_names.at(s), this_eff_den);

    
      //
      // Construct the map true vs reco
      //
      if (_true_to_reco_is_set) {
        hname = "this_reco_true" + universe_names.at(s);
        //TH2D * this_reco_true = (TH2D*) _h_true_reco_mom.GetUniverseHisto(universe_names.at(s)).Clone(hname.c_str());
        _h_true_reco_mom.GetUniverseHisto(universe_names.at(s), this_reco_true);
      }


      //
      // Calculate flux for this universe
      //
      //std::string _flux_unc_type = "FluxUnisim";
      if (_rwgt_flux && universe_names.at(s) != "nominal") {
      	std::string flux_file = "MCC8_FluxHistograms_Uncertainties.root";

        // Find the universe number
        std::string universe_number;
        std::string::size_type pos = universe_names.at(s).find("universe");
        if (universe_names.at(s).npos != pos) {
          universe_number = universe_names.at(s).substr(pos+8);
        } else {
          LOG_CRITICAL() << "[CrossSectionBootstrapCalculator1D] Universe name is not nominal nor universeXXX." << std::endl;
          throw std::exception();
        }

      	std::stringstream sstm;
        sstm << "numu/" << _flux_unc_type << "/Active_TPC_Volume/numu_" << _flux_unc_type << "_Uni_" << universe_number << "_AV_TPC";
        std::string flux_name = sstm.str();

        LOG_DEBUG() << "Using flux file: " << flux_file << ", with name " << flux_name << std::endl;
        _xsec_calc.EstimateFlux(flux_file, flux_name);
      }
      if (universe_names.at(s) == "nominal") {
        std::string flux_file = "MCC8_FluxHistograms_Uncertainties.root";

        LOG_DEBUG() << "Using flux file: " << flux_file << ", with name " << "numu/numu_CV_AV_TPC" << std::endl;
        _xsec_calc.EstimateFlux(flux_file, "numu/numu_CV_AV_TPC");
      }


      // Calculate the migration matrix for this universe
      if (_true_to_reco_is_set) {
        S_2d.Clear(); S_2d.ResizeTo(_n, _m);
        MigrationMatrix2D migrationmatrix2d;
        migrationmatrix2d.SetNBins(_n, _m);
        migrationmatrix2d.SetTrueRecoHistogram(&this_reco_true);
        S_2d = migrationmatrix2d.CalculateMigrationMatrix();
        LOG_DEBUG() << "S_2d calculated" << std::endl;
      }


      // Calculate the cross section with these new objects in this universe

      _xsec_calc.Reset();
      //h_trkmom_total_extbnb->Scale(1./scale_factor_extbnb);
      _xsec_calc.SetHistograms(input_map_mc, _h_bnbon, _h_extbnb, _hmap_dirt);  
      if (_true_to_reco_is_set) {
        _xsec_calc.SetTruthHistograms(&this_eff_num, &this_eff_den, &this_reco_true);
      } else {
        _xsec_calc.SetTruthHistograms(&this_eff_num, &this_eff_den);
      }
      //_xsec_calc.SetTruthXSec(h_truth_xsec_mumom);
      _xsec_calc.SetNameAndLabel("trkmom", ";Candidate Track Momentum (MCS) [GeV]; Selected Events");
      _xsec_calc.ProcessPlots();
      _xsec_calc.Draw();
      _xsec_calc.Draw(hist_to_subtract);
      if (_do_smear && _true_to_reco_is_set) {
        _xsec_calc.SetMigrationMatrix(S_2d);
        _xsec_calc.Smear(_n, _m);
      } else {
        _xsec_calc.DoNotSmear(); 
      }
      TH1D* universe_xsec = _xsec_calc.ExtractCrossSection(_bkg_names, "p_{#mu} [GeV]", "d#sigma/dp_{#mu} [10^{-38} cm^{2}/GeV]");


      xsec_mumom_per_universe[universe_names.at(s)] = universe_xsec;


    } // endl loop over universes


    
    

    //
    // Make the cross section plot with all the variations
    //

    BootstrapTH1D xsec_mumom_bs;
    xsec_mumom_bs.SetAllHistograms(xsec_mumom_per_universe);

    LOG_NORMAL() << "xsec_mumom_bs.GetNbinsX() " << xsec_mumom_bs.GetNbinsX() << std::endl;

    //genie_rw_plotter.SetXSecBootstrap(xsec_mumom_bs);
    //genie_rw_plotter.MakeXsecDiffPlots(true);
    
    // Covariance Matrix
    CovarianceCalculator2D _cov_calc;
    _cov_calc.SetPrefix(_save_prefix);
    _cov_calc.SetBootstrap(xsec_mumom_bs);
    _cov_calc.AddExtraDiagonalUncertainty(_extra_relative_uncertainty);
    _cov_calc.CalculateCovarianceMatrix();
    _cov_calc.PlotMatrices();

    _cov_calc.GetCovarianceMatrix(_cov_matrix);
    _cov_calc.GetFractionalCovarianceMatrix(_frac_cov_matrix);



    //
    // Plot all the xsec in one plot
    //

    TCanvas * multisim_xsec_canvas = new TCanvas();
    for (auto it : xsec_mumom_per_universe) {
      if (it.first == "nominal") {
        continue;
      }
      if (it.first == "universe0") {
        if (_save_prefix.find("mumom") != std::string::npos) {
          it.second->GetXaxis()->SetTitle("p_{#mu} [GeV]");
          it.second->GetYaxis()->SetTitle("d#sigma/dp_{#mu} [10^{-38} cm^{2}/GeV]");
          it.second->SetMinimum(0.);
          it.second->SetMaximum(1.6);
        } else if (_save_prefix.find("onebin") != std::string::npos) {
          it.second->GetXaxis()->SetTickLength(0);
          it.second->GetXaxis()->SetLabelSize(0);
          it.second->GetXaxis()->SetTitle("");
          it.second->GetYaxis()->SetTitle("#sigma [10^{-38} cm^{2}");
          it.second->SetMinimum(0.4);
          it.second->SetMaximum(1.2);
        }else {
          it.second->GetXaxis()->SetTitle("cos(#theta_{#mu})");
          it.second->GetYaxis()->SetTitle("d#sigma/dcos(#theta_{#mu}) [10^{-38} cm^{2}]");
          it.second->SetMaximum(2.2);
        }
        it.second->GetYaxis()->SetTitleOffset(0.8);
      }
      it.second->SetLineWidth(1);
      it.second->SetLineColor(kGreen+2);
      it.second->Draw("histo same");
    }
    xsec_mumom_per_universe["nominal"]->SetLineColor(kGreen+3);
    xsec_mumom_per_universe["nominal"]->SetLineWidth(3);
    xsec_mumom_per_universe["nominal"]->Draw("histo same");

    TLegend *l = new TLegend(0.5873926,0.7621053,0.8166189,0.8589474,NULL,"brNDC");
    l->SetBorderSize(0);
    l->SetTextSize(0.03789474);
    l->SetLineColor(1);
    l->SetLineStyle(1);
    l->SetLineWidth(1);
    l->SetFillColor(0);
    l->SetFillStyle(1001);
    l->AddEntry(xsec_mumom_per_universe["nominal"], "Central Value", "l");
    l->AddEntry(xsec_mumom_per_universe["universe0"], "Other Universes", "l");
    l->Draw();

    TLatex* label = new TLatex(.10, .92, _upper_label.c_str());
    label->SetTextFont(62);
    label->SetTextColor(kRed+2);
    label->SetNDC();
    label->SetTextSize(1/30.);
    label->SetTextAlign(10);//left adjusted
    label->Draw();
    multisim_xsec_canvas->SaveAs((_save_prefix + "_xsec_all.pdf").c_str());
    multisim_xsec_canvas->SaveAs((_save_prefix + "_xsec_all.C").c_str());


    // Make the fancy plot
    int n_bins_y = 240; // was 60, 120, 240
    double bins_y[241];
    for (int i = 0; i < n_bins_y+1; i++) { 
      if(_save_prefix.find("mumom") != std::string::npos) {
        bins_y[i] = (double)i/(double)n_bins_y * 1.6; 
      } else if (_save_prefix.find("onebin") != std::string::npos) {
        bins_y[i] = (double)i/(double)n_bins_y * 1.2; 
      } else {
        bins_y[i] = (double)i/(double)n_bins_y * 2.2; 
      }
    }
    TH2D *h_2d_all_xsec = new TH2D("h_2d_all_xsec", "", xsec_mumom_per_universe["nominal"]->GetNbinsX(), 
                                                        xsec_mumom_per_universe["nominal"]->GetXaxis()->GetXbins()->GetArray(),
                                                        n_bins_y,
                                                        bins_y);

    for (auto it : xsec_mumom_per_universe) {
      if (it.first == "nominal") {
        continue;
      }
      for (int bin = 1; bin < it.second->GetNbinsX()+1; bin++) {
        h_2d_all_xsec->Fill(h_2d_all_xsec->GetXaxis()->GetBinLowEdge(bin), it.second->GetBinContent(bin));
      }
    }

    TH1D * h_nominal_werror = (TH1D*) xsec_mumom_per_universe["nominal"]->Clone("h_nominal_werror");
    for (int bin = 1; bin < h_nominal_werror->GetNbinsX()+1; bin++) {
      h_nominal_werror->SetBinError(bin, std::sqrt(_cov_matrix.GetBinContent(bin, bin)));
    }

    gStyle->SetPalette(kBlueGreenYellow);

    TCanvas * multisim_xsec_fancy_canvas = new TCanvas();

    if (_save_prefix.find("mumom") != std::string::npos) {
      h_2d_all_xsec->GetXaxis()->SetTitle("p_{#mu} [GeV]");
      h_2d_all_xsec->GetYaxis()->SetTitle("d#sigma/dp_{#mu} [10^{-38} cm^{2}/GeV]");
      h_2d_all_xsec->GetYaxis()->SetTitleOffset(0.75);
      h_2d_all_xsec->SetMaximum(200); // should be 50 or 20
    } else if (_save_prefix.find("onebin") != std::string::npos) {
      h_2d_all_xsec->GetXaxis()->SetTitle("");
      h_2d_all_xsec->GetYaxis()->SetTitle("#sigma [10^{-38} cm^{2}]");
      h_2d_all_xsec->GetYaxis()->SetTitleOffset(0.75);
      h_2d_all_xsec->GetXaxis()->SetTickLength(0);
      h_2d_all_xsec->GetXaxis()->SetLabelSize(0);
    } else {
      h_2d_all_xsec->GetXaxis()->SetTitle("cos(#theta_{#mu})");
      h_2d_all_xsec->GetYaxis()->SetTitle("d#sigma/dcos(#theta_{#mu}) [10^{-38} cm^{2}]");
      h_2d_all_xsec->GetYaxis()->SetTitleOffset(0.75);
      h_2d_all_xsec->SetMaximum(200);
    }

    h_2d_all_xsec->Draw("colz");

    h_nominal_werror->SetLineColor(kRed+2);
    h_nominal_werror->SetMarkerColor(kRed+2);
    h_nominal_werror->Draw("E1 same");

    label->Draw();

    TLegend *l2;
    if (_save_prefix.find("mumom") != std::string::npos) {
      l2 = new TLegend(0.5931232,0.7284211,0.8166189,0.8589474,NULL,"brNDC");
    } else if (_save_prefix.find("onebin") != std::string::npos) {
      l2 = new TLegend(0.5931232,0.7284211,0.8166189,0.8589474,NULL,"brNDC");
    } else {
      l2 = new TLegend(0.1962751,0.6863158,0.4197708,0.8168421,NULL,"brNDC");
    }
     
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03789474);
    l2->SetLineColor(1);
    l2->SetLineStyle(1);
    l2->SetLineWidth(1);
    l2->SetFillColor(0);
    l2->SetFillStyle(1001);
    l2->AddEntry(h_nominal_werror, "Central Value", "lep");
    l2->AddEntry(h_2d_all_xsec, "Color map shows", "");
    l2->AddEntry(h_2d_all_xsec, "other universes", "");
    l2->Draw();

    multisim_xsec_fancy_canvas->SaveAs((_save_prefix + "_xsec_all_fancy.pdf").c_str());
    multisim_xsec_fancy_canvas->SaveAs((_save_prefix + "_xsec_all_fancy.C").c_str());

    gStyle->SetPalette(kRainBow);




    LOG_NORMAL() << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;

	}
}

#endif

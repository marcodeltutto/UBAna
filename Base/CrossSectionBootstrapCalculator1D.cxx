#ifndef __BASE_CROSSSECTIONBOOTSTRAPCALCULATOR1D_CXX__
#define __BASE_CROSSSECTIONBOOTSTRAPCALCULATOR1D_CXX__

#include "CrossSectionBootstrapCalculator1D.h"

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

    //_h_eff_mumom_num = NULL;
    //_h_eff_mumom_den = NULL;

    //_h_true_reco_mom = NULL;
  }

  void CrossSectionBootstrapCalculator1D::SetScaleFactors(double bnbcosmic, double bnbon, double extbnb, double intimecosmic)
  {
    _scale_factor_mc_bnbcosmic = bnbcosmic;
    _scale_factor_bnbon = bnbon;
    _scale_factor_extbnb = extbnb;
    _scale_factor_mc_intimecosmic = intimecosmic;

    _configured = true;
  }

  void CrossSectionBootstrapCalculator1D::SetPOT(double pot)
  {
    _pot = pot;
  }

  void CrossSectionBootstrapCalculator1D::SetNameAndLabel(std::string name, std::string label)
  {
    _name = name;
    _label = label;
  }

  void CrossSectionBootstrapCalculator1D::SetOutDir(std::string dir)
  {
    _outdir = dir;

    auto now = std::time(nullptr);
    char buf[sizeof("YYYY-MM-DD_HH-MM-SS")];
    std::string timestamp = std::string(buf,buf + std::strftime(buf,sizeof(buf),"%F_%H-%M-%S",std::gmtime(&now)));

    _folder = _outdir + "_" + timestamp + "/";

    system(("mkdir " + _folder).c_str());

  }



/*
  void CrossSectionBootstrapCalculator1D::PrintConfig() {

    std::cout << "--- CrossSectionBootstrapCalculator1D:" << std::endl;
    std::cout << "---   _scale_factor_mc_bnbcosmic     = " << _scale_factor_mc_bnbcosmic << std::endl;
    std::cout << "---   _scale_factor_bnbon            = " << _scale_factor_bnbon << std::endl;
    std::cout << "---   _scale_factor_extbnb           = " << _scale_factor_extbnb << std::endl;
    std::cout << "---   _scale_factor_mc_intimecosmic  = " << _scale_factor_mc_intimecosmic << std::endl;
    std::cout << "---   _pot                           = " << _pot << std::endl;

  }
  */

  void CrossSectionBootstrapCalculator1D::SetHistograms(std::map<std::string,std::map<std::string,TH1D*>>/*std::map<std::string,BootstrapTH1D>*/ bnbcosmic, TH1D* bnbon, TH1D* extbnb, TH1D* intimecosmic) 
  {

    _hmap_bnbcosmic = bnbcosmic;
    
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

  }

  void CrossSectionBootstrapCalculator1D::SetTruthHistograms(BootstrapTH1D num, BootstrapTH1D den)
  {
    _h_eff_mumom_num = num;
    _h_eff_mumom_den = den;
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


  void CrossSectionBootstrapCalculator1D::SetSavePrefix(std::string s)
  {
  	_save_prefix = s;
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


  //
  // Main method
  //

	void CrossSectionBootstrapCalculator1D::Run() 
	{

		gROOT->SetBatch(kTRUE);

		std::cout << "CrossSectionBootstrapCalculator1D::Run() called" << std::endl;

		std::map<std::string, TH1D*> xsec_mumom_per_universe;

    std::cout << "$here1" << std::endl;

		CrossSectionCalculator1D _xsec_calc;
    _xsec_calc.SetScaleFactors(_scale_factor_mc_bnbcosmic, _scale_factor_bnbon, _scale_factor_extbnb);
    _xsec_calc.SetPOT(_pot);
    _xsec_calc.SetOutDir("output_data_mc_multisim");
    std::cout << "CrossSectionBootstrapCalculator1D FLUX: " << _xsec_calc.EstimateFlux() << std::endl;

    std::vector<std::string> hist_to_subtract = {"beam-off", "cosmic", "outfv", "nc", "nue", "anumu"};


    std::cout << "$here2" << std::endl;


    size_t n_universe = _h_eff_mumom_num.GetNWeights();
    std::vector<std::string> universe_names = _h_eff_mumom_num.GetUniverseNames();

    std::cout << "n_universe " << n_universe << std::endl;
    std::cout << "universe_names.size() " << universe_names.size() << std::endl;

    for (auto s : universe_names) {
    	std::cout << ">>>>>>> name is " << s << std::endl;
    }

    
    TH1D this_h;
    TH1D this_eff_num;
    TH1D this_eff_den; 
    TH2D this_reco_true;

    std::cout << "$here3" << std::endl;

    for (size_t s = 0; s < n_universe; s++) {

    	std::cout << "$>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>this is universe " << s << ", with name " << universe_names.at(s) << std::endl;

      //
    	// Construnct the hmap for the MC histograms
      //
      int counter = 0;
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
      hname = "this_reco_true" + universe_names.at(s);
      //TH2D * this_reco_true = (TH2D*) _h_true_reco_mom.GetUniverseHisto(universe_names.at(s)).Clone(hname.c_str());
      _h_true_reco_mom.GetUniverseHisto(universe_names.at(s), this_reco_true);



      //
      // Calculate flux for this universe
      //
      //std::string _flux_unc_type = "FluxUnisim";
      if (_rwgt_flux && universe_names.at(s) != "nominal") {
      	std::string flux_file = "MCC8_FluxHistograms_Uncertainties.root";

      	std::stringstream sstm;
        sstm << "numu/" << _flux_unc_type << "/Active_TPC_Volume/numu_" << _flux_unc_type << "_Uni_" << s << "_AV_TPC";
        std::string flux_name = sstm.str();

        std::cout << "[CrossSectionBootstrapCalculator1D] Using flux file: " << flux_file << ", with name " << flux_name << std::endl;
        _xsec_calc.EstimateFlux(flux_file, flux_name);
      }
      if (universe_names.at(s) == "nominal") {
        std::string flux_file = "MCC8_FluxHistograms_Uncertainties.root";

        std::cout << "[CrossSectionBootstrapCalculator1D] Using flux file: " << flux_file << ", with name " << "numu/numu_CV_AV_TPC" << std::endl;
        _xsec_calc.EstimateFlux(flux_file, "numu/numu_CV_AV_TPC");
      }





      // Calculate the migration matrix for this universe
      TMatrix S_2d; S_2d.Clear(); S_2d.ResizeTo(_n, _m);
      MigrationMatrix2D migrationmatrix2d;
      migrationmatrix2d.SetNBins(_n, _m);
      migrationmatrix2d.SetTrueRecoHistogram(&this_reco_true);
      S_2d = migrationmatrix2d.CalculateMigrationMatrix();



      // Calculate the cross section with these new objects in this universe

      _xsec_calc.Reset();
      //h_trkmom_total_extbnb->Scale(1./scale_factor_extbnb);
      _xsec_calc.SetHistograms(input_map_mc, _h_bnbon, _h_extbnb);  
      _xsec_calc.SetTruthHistograms(&this_eff_num, &this_eff_den, &this_reco_true);
      //_xsec_calc.SetTruthXSec(h_truth_xsec_mumom);
      _xsec_calc.SetNameAndLabel("trkmom", ";Candidate Track Momentum (MCS) [GeV]; Selected Events");
      _xsec_calc.ProcessPlots();
      _xsec_calc.Draw();
      _xsec_calc.Draw(hist_to_subtract);
      if (_do_smear) {
        _xsec_calc.SetMigrationMatrix(S_2d);
        _xsec_calc.Smear(_n, _m);
      } else {
        _xsec_calc.DoNotSmear(); 
      }
      TH1D* universe_xsec = _xsec_calc.ExtractCrossSection("p_{#mu} [GeV]", "d#sigma/dp_{#mu} [10^{-38} cm^{2}/GeV]");


      xsec_mumom_per_universe[universe_names.at(s)] = universe_xsec;

    } // endl loop over universes


    
    

    //
    // Make the cross section plot with all the variations
    //

    BootstrapTH1D xsec_mumom_bs;
    xsec_mumom_bs.SetAllHistograms(xsec_mumom_per_universe);

    std::cout << "xsec_mumom_bs.GetNbinsX() " <<xsec_mumom_bs.GetNbinsX() << std::endl;

    //genie_rw_plotter.SetXSecBootstrap(xsec_mumom_bs);
    //genie_rw_plotter.MakeXsecDiffPlots(true);
    
    // Covariance Matrix
    CovarianceCalculator2D _cov_calc;
    _cov_calc.SetPrefix(_save_prefix);
    _cov_calc.SetBootstrap(xsec_mumom_bs);
    _cov_calc.CalculateCovarianceMatrix();
    _cov_calc.PlotMatrices();

    _cov_calc.GetCovarianceMatrix(_cov_matrix);


    //
    // Plot all the xsec in one plot
    //

    TCanvas * genie_multisim_xsec_canvas = new TCanvas();
    for (auto it : xsec_mumom_per_universe) {
      if (it.first == "nominal") {
        continue;
      }
      if (it.first == "universe0") {
        it.second->GetXaxis()->SetTitle("p_{#mu} [GeV]");
        it.second->GetYaxis()->SetTitle("d#sigma/dp_{#mu} [10^{-38} cm^{2}/GeV]");
        it.second->GetYaxis()->SetTitleOffset(0.8);
      }
      it.second->SetLineWidth(1);
      it.second->SetLineColor(kGreen+2);
      it.second->Draw("histo same");
    }
    xsec_mumom_per_universe["nominal"]->SetLineColor(kGreen+3);
    xsec_mumom_per_universe["nominal"]->SetLineWidth(3);
    xsec_mumom_per_universe["nominal"]->Draw("histo same");

    TLegend *l = new TLegend(0.5644699,0.7347368,0.8868195,0.8673684,NULL,"brNDC");
    l -> AddEntry(xsec_mumom_per_universe["nominal"], "Central Value", "l");
    l -> AddEntry(xsec_mumom_per_universe["universe0"], "Other Universes", "l");
    l -> Draw();

    TLatex* genie_label = new TLatex(.10, .92, _upper_label.c_str());
    genie_label->SetTextFont(62);
    genie_label->SetTextColor(kRed+2);
    genie_label->SetNDC();
    genie_label->SetTextSize(1/30.);
    genie_label->SetTextAlign(10);//left adjusted
    genie_label->Draw();
    genie_multisim_xsec_canvas->SaveAs((_save_prefix + "_xsec_all.pdf").c_str());//  "xx_genie_multisim_xsec_all.pdf");

    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;

	}
}

#endif

#ifndef __MAIN_ANALYSE_CXX__
#define __MAIN_ANALYSE_CXX__

#include "Analyse.h"


namespace Main {


	void Analyse::SetBNBCosmicFile(std::string f) {
   
    mc_bnbcosmic_file_name = f;

	}

	void Analyse::SetInTimeCosmicFile(std::string f) {
   
    mc_intimecosmic_file_name = f;

	}

  void Analyse::SetDirtFile(std::string f) {
   
    mc_dirt_file_name = f;

  }

	void Analyse::SetBNBONFile(std::string f) {
   
    bnbon_file_name = f;

	}

	void Analyse::SetEXTBNBFile(std::string f) {
   
    extbnb_file_name = f;

	}

	void Analyse::SetBNBPOT(double v) {
   
    bnbon_pot_meas = v;

	}

	void Analyse::SetBNBONTriggers(double v) {
   
    bnbon_triggers = v;

	}

	void Analyse::SetEXTBNBTriggers(double v) {
   
    extbnb_triggers = v;

	}

	void Analyse::SetTargetFluxSystematic(std::string s) {
		_target_flux_syst = s;
	}

	void Analyse::SetPrefix(std::string p) {
		_prefix = p;
	}


  // void Analyse::AddExtraDiagonalUncertainty(TH2D & matrix, double frac_unc)
  // {

  //   for (int i = 0; i < matrix.GetNbinsX(); i++) {
  //     double current_content = matrix.GetBinContent(i+1, i+1);
  //     matrix.SetBinContent(i+1, i+1, current_content + )
  //   }

  // }




	void Analyse::DoAnalise() 
	{

	clock_t begin = clock();


  std::string analyser_outdir = std::getenv("MYSW_OUTDIR");
  analyser_outdir += "output_data_mc/";
  std::string mkdir_command = "mkdir -p ";
  mkdir_command += analyser_outdir;
  system(mkdir_command.c_str());
  
  //gROOT->SetBatch(kTRUE);
  gROOT->ProcessLine("gErrorIgnoreLevel = 2001;"); // 1001: INFO, 2001: WARNINGS, 3001: ERRORS

  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  int bnbon_total_events = 1000;
  int extbnb_total_events = 1000;
  //int intimecosmic_total_events = 1000;
  int dirt_total_events = 1000;
  int bnbcosmic_total_events = 1000;
  double mc_pot_sim = 6.e19;
  double mc_pot_sim_dirt = 6.e19;

  
  // *************************************
  // Opening files
  // *************************************
  TFile* mc_bnbcosmic_file = TFile::Open(mc_bnbcosmic_file_name.c_str(), "READ");
  //TFile* mc_intimecosmic_file = TFile::Open(mc_intimecosmic_file_name.c_str(), "READ");
  TFile* mc_dirt_file = TFile::Open(mc_dirt_file_name.c_str(), "READ");
  TFile* bnbon_file = TFile::Open(bnbon_file_name.c_str(), "READ");
  TFile* extbnb_file = TFile::Open(extbnb_file_name.c_str(), "READ");

  if (!mc_dirt_file) 
    std::cout << "MC Dirt File not available." << std::endl;
  

  // *************************************
  // Getting number of events for bnbon
  // *************************************
  TH1D* h_nevts_bnbon = (TH1D*)bnbon_file->Get("h_nevts");
  bnbon_total_events = h_nevts_bnbon->GetBinContent(1);
  std::cout << "Number of events (BNBON):  " << bnbon_total_events << std::endl;
  
  
  // *************************************
  // Getting number of events for extbnb
  // *************************************
  TH1D* h_nevts_extbnb = (TH1D*)extbnb_file->Get("h_nevts");
  extbnb_total_events = h_nevts_extbnb->GetBinContent(1);
  std::cout << "Number of events (EXTBNB): " << extbnb_total_events << std::endl << std::endl;
  
  // *************************************
  // Getting number of events for bnbcosmic
  // *************************************
  TH1D* h_nevts_bnbcosmic = (TH1D*)mc_bnbcosmic_file->Get("h_nevts");
  bnbcosmic_total_events = h_nevts_bnbcosmic->GetBinContent(1);
  std::cout << "Number of events (BNBCosmic): " << bnbcosmic_total_events << std::endl;

  // *************************************
  // Getting number of events for dirt
  // *************************************
  if (mc_dirt_file) {
    TH1D* h_nevts_dirt = (TH1D*)mc_dirt_file->Get("h_nevts");
    dirt_total_events = h_nevts_dirt->GetBinContent(1);
    std::cout << "Number of events (Dirt): " << dirt_total_events << std::endl;
  }
  
  // *************************************
  // Getting number of events for intimecosmic
  // *************************************
  //TH1D* h_nevts_intimecosmic = (TH1D*)mc_intimecosmic_file->Get("h_nevts");
  //intimecosmic_total_events = h_nevts_intimecosmic->GetBinContent(1);
  //std::cout << "Number of events (InTimeCosmic): " << intimecosmic_total_events << std::endl;
  
  std::cout << std::endl;
  
  
  // *************************************
  // Getting simulated POT
  // *************************************
  TH1D* h_simpot = (TH1D*)mc_bnbcosmic_file->Get("h_pot");
  mc_pot_sim = h_simpot->GetBinContent(1);
  std::cout << "Simulated POT:      " << mc_pot_sim << std::endl;
  std::cout << "BNBON Measured POT: " << bnbon_pot_meas << std::endl << std::endl;

  if (mc_dirt_file) {
    TH1D* h_simpot_dirt = (TH1D*)mc_dirt_file->Get("h_pot");
    mc_pot_sim_dirt = h_simpot_dirt->GetBinContent(1);
    std::cout << "Dirt Simulated POT: " << mc_pot_sim_dirt << std::endl;
  }
  
  // *************************************
  // Calculating scale factors
  // *************************************
  double scale_factor_extbnb = (double)bnbon_triggers/(double)extbnb_triggers;
  double scale_factor_bnbon = 1.; 
  double scale_factor_mc_bnbcosmic = bnbon_pot_meas / mc_pot_sim;
  double scale_factor_mc_dirt = bnbon_pot_meas / mc_pot_sim_dirt;

  std::cout << "Data Scale Factors:" << std::endl;
  std::cout << "\t BNBON: " << scale_factor_bnbon << std::endl;
  std::cout << "\t EXTBNB: " << scale_factor_extbnb << std::endl;
  std::cout << "MC Scale Factors:" << std::endl;
  std::cout << "\t BNBCOSMIC: " << scale_factor_mc_bnbcosmic << std::endl;
  std::cout << "\t DIRT: " << scale_factor_mc_dirt << std::endl;
  //std::cout << "\t INTIMECOSMIC: " << scale_factor_mc_intimecosmic << std::endl;

  
  // *************************************
  // Getting the relevant histograms from MC file BNBCosmic
  // *************************************
  std::map<std::string,TH1D*>* temp_map;
  mc_bnbcosmic_file->GetObject("hmap_trklen", temp_map);
  std::map<std::string,TH1D*> hmap_trklen_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_onebin", temp_map);
  std::map<std::string,TH1D*> hmap_onebin_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_trkmom", temp_map);
  std::map<std::string,TH1D*> hmap_trkmom_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_trkmom_classic", temp_map);
  std::map<std::string,TH1D*> hmap_trkmom_classic_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_trktheta", temp_map);
  std::map<std::string,TH1D*> hmap_trktheta_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_trktheta_classic", temp_map);
  std::map<std::string,TH1D*> hmap_trktheta_classic_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_trkphi", temp_map);
  std::map<std::string,TH1D*> hmap_trkphi_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_multpfp", temp_map);
  std::map<std::string,TH1D*> hmap_multpfp_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_multtracktol", temp_map);
  std::map<std::string,TH1D*> hmap_multtracktol_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_xdiff_b", temp_map);
  std::map<std::string,TH1D*> hmap_xdiff_b_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_zdiff_b", temp_map);
  std::map<std::string,TH1D*> hmap_zdiff_b_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_xdiff", temp_map);
  std::map<std::string,TH1D*> hmap_xdiff_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_zdiff", temp_map);
  std::map<std::string,TH1D*> hmap_zdiff_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_vtxx", temp_map);
  std::map<std::string,TH1D*> hmap_vtxx_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_vtxy", temp_map);
  std::map<std::string,TH1D*> hmap_vtxy_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_vtxz", temp_map);
  std::map<std::string,TH1D*> hmap_vtxz_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_vtxz_upborder", temp_map);
  std::map<std::string,TH1D*> hmap_vtxz_upborder_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_vtxx_upborder", temp_map);
  std::map<std::string,TH1D*> hmap_vtxx_upborder_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_flsmatch_score", temp_map);
  std::map<std::string,TH1D*> hmap_flsmatch_score_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_flsmatch_score_second", temp_map);
  std::map<std::string,TH1D*> hmap_flsmatch_score_second_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_flsmatch_score_difference", temp_map);
  std::map<std::string,TH1D*> hmap_flsmatch_score_difference_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_ntpcobj", temp_map);
  std::map<std::string,TH1D*> hmap_ntpcobj_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_vtxcheck_angle", temp_map);
  std::map<std::string,TH1D*> hmap_vtxcheck_angle_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_residuals_std", temp_map);
  std::map<std::string,TH1D*> hmap_residuals_std_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_residuals_mean", temp_map);
  std::map<std::string,TH1D*> hmap_residuals_mean_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_perc_used_hits", temp_map);
  std::map<std::string,TH1D*> hmap_perc_used_hits_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_mom_mcs_length", temp_map);
  std::map<std::string,TH1D*> hmap_mom_mcs_length_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_mctruth_nuenergy", temp_map);
  std::map<std::string,TH1D*> hmap_mctruth_nuenergy_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_mctruth_mumom", temp_map);
  std::map<std::string,TH1D*> hmap_mctruth_mumom_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_mctruth_mucostheta", temp_map);
  std::map<std::string,TH1D*> hmap_mctruth_mucostheta_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_mctruth_muphi", temp_map);
  std::map<std::string,TH1D*> hmap_mctruth_muphi_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_mctruth_nuenergy_gen", temp_map);
  std::map<std::string,TH1D*> hmap_mctruth_nuenergy_gen_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_mctruth_mumom_gen", temp_map);
  std::map<std::string,TH1D*> hmap_mctruth_mumom_gen_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_mctruth_mucostheta_gen", temp_map);
  std::map<std::string,TH1D*> hmap_mctruth_mucostheta_gen_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_mctruth_muphi_gen", temp_map);
  std::map<std::string,TH1D*> hmap_mctruth_muphi_gen_mc = *temp_map;
  TH1D* h_flsPe_wcut_mc = (TH1D*)mc_bnbcosmic_file->Get("h_flsPe_wcut");

  
  mc_bnbcosmic_file->GetObject("hmap_dqdx_trunc", temp_map);
  std::map<std::string,TH1D*> hmap_dqdx_trunc_mc = *temp_map;
  TH2D* h_dqdx_trunc_length_mc = (TH2D*)mc_bnbcosmic_file->Get("h_dqdx_trunc_length");

  // Reco Per True - GENIE Multisim
  std::vector<std::vector<TH2D*>> * temp_reco_per_true;
  mc_bnbcosmic_file->GetObject("h_reco_per_true", temp_reco_per_true);
  std::vector<std::vector<TH2D*>> h_reco_per_true_mc = *temp_reco_per_true;


  // Create placeholders to get stuff from file
  std::map<std::string,std::map<std::string,TH1D*>>* temp_map_bs;
  std::map<std::string,std::map<std::string,TH2D*>>* temp_map2d_bs;
  BootstrapTH1D * temp_bs;
  BootstrapTH2D * temp2d_bs;
  std::map<std::string,std::vector<std::vector<TH2D*>>> * temp_bs_reco_per_true;




  mc_bnbcosmic_file->GetObject("hmap_trkmom_genie_pm1_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> map_bs = *temp_map_bs;

  //BootstrapTH1D * h_eff_mumom_num_bs_temp;
  //mc_bnbcosmic_file->GetObject("h_eff_mumom_num_bs", h_eff_mumom_num_bs_temp);
  //BootstrapTH1D h_eff_mumom_num_bs = *h_eff_mumom_num_bs_temp;


  std::cout << ">> here1" << std::endl;

  // Bootstrap efficiency - GENIE pm1sigma
  mc_bnbcosmic_file->GetObject("bs_genie_pm1_eff_mumom_num", temp_bs);
  BootstrapTH1D bs_genie_pm1_eff_mumom_num = *temp_bs;
  mc_bnbcosmic_file->GetObject("bs_genie_pm1_eff_mumom_den", temp_bs);
  BootstrapTH1D bs_genie_pm1_eff_mumom_den = *temp_bs;

  // Bootstrap efficiency - GENIE Multisim
  mc_bnbcosmic_file->GetObject("bs_genie_multisim_eff_onebin_num", temp_bs);
  BootstrapTH1D bs_genie_multisim_eff_onebin_num = *temp_bs;
  mc_bnbcosmic_file->GetObject("bs_genie_multisim_eff_onebin_den", temp_bs);
  BootstrapTH1D bs_genie_multisim_eff_onebin_den = *temp_bs;

  mc_bnbcosmic_file->GetObject("bs_genie_multisim_eff_mumom_num", temp_bs);
  BootstrapTH1D  bs_genie_multisim_eff_mumom_num = *temp_bs;
  mc_bnbcosmic_file->GetObject("bs_genie_multisim_eff_mumom_den", temp_bs);
  BootstrapTH1D  bs_genie_multisim_eff_mumom_den = *temp_bs;

  mc_bnbcosmic_file->GetObject("bs_genie_multisim_eff_muangle_num", temp_bs);
  BootstrapTH1D  bs_genie_multisim_eff_muangle_num = *temp_bs;
  mc_bnbcosmic_file->GetObject("bs_genie_multisim_eff_muangle_den", temp_bs);
  BootstrapTH1D  bs_genie_multisim_eff_muangle_den = *temp_bs;

  mc_bnbcosmic_file->GetObject("bs_genie_multisim_eff_muangle_mumom_num", temp2d_bs);
  BootstrapTH2D  bs_genie_multisim_eff_muangle_mumom_num = *temp2d_bs;
  mc_bnbcosmic_file->GetObject("bs_genie_multisim_eff_muangle_mumom_den", temp2d_bs);
  BootstrapTH2D  bs_genie_multisim_eff_muangle_mumom_den = *temp2d_bs;

  // Bootstrap efficiency - GENIE Models
  mc_bnbcosmic_file->GetObject("bs_extra_syst_eff_onebin_num", temp_bs);
  BootstrapTH1D bs_extra_syst_eff_onebin_num = *temp_bs;
  mc_bnbcosmic_file->GetObject("bs_extra_syst_eff_onebin_den", temp_bs);
  BootstrapTH1D bs_extra_syst_eff_onebin_den = *temp_bs;

  mc_bnbcosmic_file->GetObject("bs_extra_syst_eff_mumom_num", temp_bs);
  BootstrapTH1D  bs_extra_syst_eff_mumom_num = *temp_bs;
  mc_bnbcosmic_file->GetObject("bs_extra_syst_eff_mumom_den", temp_bs);
  BootstrapTH1D  bs_extra_syst_eff_mumom_den = *temp_bs;

  mc_bnbcosmic_file->GetObject("bs_extra_syst_eff_muangle_num", temp_bs);
  BootstrapTH1D  bs_extra_syst_eff_muangle_num = *temp_bs;
  mc_bnbcosmic_file->GetObject("bs_extra_syst_eff_muangle_den", temp_bs);
  BootstrapTH1D  bs_extra_syst_eff_muangle_den = *temp_bs;

  mc_bnbcosmic_file->GetObject("bs_extra_syst_eff_muangle_mumom_num", temp2d_bs);
  BootstrapTH2D  bs_extra_syst_eff_muangle_mumom_num = *temp2d_bs;
  mc_bnbcosmic_file->GetObject("bs_extra_syst_eff_muangle_mumom_den", temp2d_bs);
  BootstrapTH2D  bs_extra_syst_eff_muangle_mumom_den = *temp2d_bs;



  // Bootstrap efficiency - FLUX Multisim
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_onebin_num", temp_bs);
  BootstrapTH1D bs_flux_multisim_eff_onebin_num = *temp_bs;
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_onebin_den", temp_bs);
  BootstrapTH1D bs_flux_multisim_eff_onebin_den = *temp_bs;

  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_muangle_num", temp_bs);
  BootstrapTH1D bs_flux_multisim_eff_muangle_num = *temp_bs;
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_muangle_den", temp_bs);
  BootstrapTH1D bs_flux_multisim_eff_muangle_den = *temp_bs;

  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_muangle_mumom_num", temp2d_bs);
  BootstrapTH2D  bs_flux_multisim_eff_muangle_mumom_num = *temp2d_bs;
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_muangle_mumom_den", temp2d_bs);
  BootstrapTH2D  bs_flux_multisim_eff_muangle_mumom_den = *temp2d_bs;

  // Boostrap reco-true
  std::map<std::string,TH2D*>* temp_map_bs2;
  mc_bnbcosmic_file->GetObject("bs_genie_pm1_true_reco_mom", temp_map_bs2);
  std::map<std::string,TH2D*> bs_true_reco_mom_mc = *temp_map_bs2;
  std::cout << ">> here6" << std::endl;

  // Instantiate the GENIE reweighting plotter
  ReweightingPlotter genie_rw_plotter;


  if (_do_pm1sigma_plots) {

    // Bootstrap number of events per type
    std::map<std::string, BootstrapTH1D> bs;
    for (auto it : map_bs) {
      BootstrapTH1D temp;
      temp.SetAllHistograms(it.second);
      bs[it.first] = temp;
    }
    // Make +-1 sigma plots from GENIE
    genie_rw_plotter.SetEventBootstrapMap(bs);
    genie_rw_plotter.SetEfficiencyBootstraps(bs_genie_pm1_eff_mumom_num, bs_genie_pm1_eff_mumom_den);
    genie_rw_plotter.MakePlots(0, false, true);
    genie_rw_plotter.MakePlots(2, false, true);
    genie_rw_plotter.MakeBackgroundPlots(0, false, true);  
  }

  std::cout << ">> here7" << std::endl;


  //
  // Events - GENIE Multisim
  //
  mc_bnbcosmic_file->GetObject("hmap_onebin_genie_multisim_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_genie_multisim_bs_mc = *temp_map_bs;

  mc_bnbcosmic_file->GetObject("hmap_trkmom_genie_multisim_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_genie_multisim_bs_mc = *temp_map_bs;

  mc_bnbcosmic_file->GetObject("hmap_trkangle_genie_multisim_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_genie_multisim_bs_mc = *temp_map_bs;

  mc_bnbcosmic_file->GetObject("hmap_trktheta_trkmom_genie_multisim_bs", temp_map2d_bs);
  std::map<std::string,std::map<std::string,TH2D*>> hmap_trktheta_trkmom_genie_multisim_bs_mc = *temp_map2d_bs;


  // Currently not used
  std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_genie_multisim_bs_mc_dirt;
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_genie_multisim_bs_mc_dirt;
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_genie_multisim_bs_mc_dirt;
  std::map<std::string,std::map<std::string,TH2D*>> hmap_trktheta_trkmom_genie_multisim_bs_mc_dirt;

  if (mc_dirt_file) {
    mc_dirt_file->GetObject("hmap_onebin_genie_multisim_bs", temp_map_bs);
    hmap_onebin_genie_multisim_bs_mc_dirt = *temp_map_bs;
    // hmap_onebin_genie_multisim_bs_mc["dirt"] = hmap_onebin_genie_multisim_bs_mc_dirt["total"];

    mc_dirt_file->GetObject("hmap_trkmom_genie_multisim_bs", temp_map_bs);
    hmap_trkmom_genie_multisim_bs_mc_dirt = *temp_map_bs;
    // hmap_trkmom_genie_multisim_bs_mc["dirt"] = hmap_trkmom_genie_multisim_bs_mc_dirt["total"];

    mc_dirt_file->GetObject("hmap_trkangle_genie_multisim_bs", temp_map_bs);
    hmap_trkangle_genie_multisim_bs_mc_dirt = *temp_map_bs;
    // hmap_trkangle_genie_multisim_bs_mc["dirt"] = hmap_trkangle_genie_multisim_bs_mc_dirt["total"];

    mc_dirt_file->GetObject("hmap_trktheta_trkmom_genie_multisim_bs", temp_map2d_bs);
    hmap_trktheta_trkmom_genie_multisim_bs_mc_dirt = *temp_map2d_bs;
    // hmap_trktheta_trkmom_genie_multisim_bs_mc["dirt"] = hmap_trktheta_trkmom_genie_multisim_bs_mc_dirt["total"];
  } 

  std::cout << ">> here aaa" << std::endl;


  // Reco Per True - GENIE Multisim
  mc_bnbcosmic_file->GetObject("bs_genie_multisim_reco_per_true", temp_bs_reco_per_true);
  std::map<std::string,std::vector<std::vector<TH2D*>>> bs_genie_multisim_reco_per_true_mc = *temp_bs_reco_per_true;

  std::cout << ">> here bbb" << std::endl;




  // Events - Extra Systs
  mc_bnbcosmic_file->GetObject("hmap_onebin_extra_syst_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_extra_syst_bs_mc = *temp_map_bs;

  mc_bnbcosmic_file->GetObject("hmap_trkmom_extra_syst_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_extra_syst_bs_mc = *temp_map_bs;

  mc_bnbcosmic_file->GetObject("hmap_trkangle_extra_syst_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_extra_syst_bs_mc = *temp_map_bs;

  mc_bnbcosmic_file->GetObject("hmap_trktheta_trkmom_extra_syst_bs", temp_map2d_bs);
  std::map<std::string,std::map<std::string,TH2D*>> hmap_trktheta_trkmom_extra_syst_bs_mc = *temp_map2d_bs;

  // Reco Per True - Extra Systs
  mc_bnbcosmic_file->GetObject("bs_extra_syst_multisim_reco_per_true", temp_bs_reco_per_true);
  std::map<std::string,std::vector<std::vector<TH2D*>>> bs_extra_syst_multisim_reco_per_true_mc = *temp_bs_reco_per_true;

  BootstrapTH2D * temp_bs_2d;

  // Events - FLUX Multisim
  mc_bnbcosmic_file->GetObject("hmap_onebin_flux_multisim_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_flux_multisim_bs_mc = *temp_map_bs;

  mc_bnbcosmic_file->GetObject("hmap_trkmom_flux_multisim_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_flux_multisim_bs_mc = *temp_map_bs;

  mc_bnbcosmic_file->GetObject("hmap_trkangle_flux_multisim_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_flux_multisim_bs_mc = *temp_map_bs;

  mc_bnbcosmic_file->GetObject("hmap_trktheta_trkmom_flux_multisim_bs", temp_map2d_bs);
  std::map<std::string,std::map<std::string,TH2D*>> hmap_trktheta_trkmom_flux_multisim_bs_mc = *temp_map2d_bs;
  

  std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_flux_multisim_bs_mc_dirt;
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_flux_multisim_bs_mc_dirt;
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_flux_multisim_bs_mc_dirt;
  std::map<std::string,std::map<std::string,TH2D*>> hmap_trktheta_trkmom_flux_multisim_bs_mc_dirt;

  if (mc_dirt_file) {
    mc_dirt_file->GetObject("hmap_onebin_flux_multisim_bs", temp_map_bs);
    hmap_onebin_flux_multisim_bs_mc_dirt = *temp_map_bs;
    // hmap_onebin_flux_multisim_bs_mc["dirt"] = hmap_onebin_flux_multisim_bs_mc_dirt["total"];

    mc_dirt_file->GetObject("hmap_trkmom_flux_multisim_bs", temp_map_bs);
    hmap_trkmom_flux_multisim_bs_mc_dirt = *temp_map_bs;
    // hmap_trkmom_flux_multisim_bs_mc["dirt"] = hmap_trkmom_flux_multisim_bs_mc_dirt["total"];

    mc_dirt_file->GetObject("hmap_trkangle_flux_multisim_bs", temp_map_bs);
    hmap_trkangle_flux_multisim_bs_mc_dirt = *temp_map_bs;
    // hmap_trkangle_flux_multisim_bs_mc["dirt"] = hmap_trkangle_flux_multisim_bs_mc_dirt["total"];

    mc_dirt_file->GetObject("hmap_trktheta_trkmom_flux_multisim_bs", temp_map2d_bs);
    hmap_trktheta_trkmom_flux_multisim_bs_mc_dirt = *temp_map2d_bs;
    // hmap_trktheta_trkmom_flux_multisim_bs_mc["dirt"] = hmap_trktheta_trkmom_flux_multisim_bs_mc_dirt["total"];
  } 


  // Boostrap reco-true - GENIE Multisim
  mc_bnbcosmic_file->GetObject("bs_genie_multisim_true_reco_mumom", temp_bs_2d);
  BootstrapTH2D bs_genie_multisim_reco_true_mumom = *temp_bs_2d;

  std::cout << ">> herea" << std::endl;

  mc_bnbcosmic_file->GetObject("bs_genie_multisim_true_reco_muangle", temp_bs_2d);
  BootstrapTH2D bs_genie_multisim_true_reco_muangle = *temp_bs_2d;

  // Boostrap reco-true - GENIE Models
  mc_bnbcosmic_file->GetObject("bs_extra_syst_true_reco_mumom", temp_bs_2d);
  BootstrapTH2D bs_extra_syst_reco_true_mumom = *temp_bs_2d;

  std::cout << ">> herea" << std::endl;

  mc_bnbcosmic_file->GetObject("bs_extra_syst_true_reco_muangle", temp_bs_2d);
  BootstrapTH2D bs_extra_syst_true_reco_muangle = *temp_bs_2d;

  std::cout << ">> here8" << std::endl;

  

  // Bootstrap efficiency - FLUX Multisim
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_mumom_num", temp_bs);
  BootstrapTH1D bs_flux_multisim_eff_mumom_num = *temp_bs;
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_mumom_den", temp_bs);
  BootstrapTH1D bs_flux_multisim_eff_mumom_den = *temp_bs;

std::cout << ">> here9" << std::endl;


  // Boostrap reco-true - FLUX Multisim
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_true_reco_mumom", temp_bs_2d);
  BootstrapTH2D bs_flux_multisim_true_reco_mumom = *temp_bs_2d;
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_true_reco_muangle", temp_bs_2d);
  BootstrapTH2D bs_flux_multisim_true_reco_muangle = *temp_bs_2d;

std::cout << ">> here10" << std::endl;

  // Reco Per True - FLUX Multisim
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_reco_per_true", temp_bs_reco_per_true);
  std::map<std::string,std::vector<std::vector<TH2D*>>> bs_flux_multisim_reco_per_true_mc = *temp_bs_reco_per_true;


std::cout << ">> here11" << std::endl;




  // *************************************
  // Getting the relevant histograms from MC file DIRT
  // *************************************
  if (mc_dirt_file) {
    mc_dirt_file->GetObject("hmap_trklen", temp_map);
    hmap_trklen_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_onebin", temp_map);
    hmap_onebin_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_trkmom", temp_map);
    hmap_trkmom_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_trkmom_classic", temp_map);
    hmap_trkmom_classic_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_trktheta", temp_map);
    hmap_trktheta_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_trktheta_classic", temp_map);
    hmap_trktheta_classic_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_trkphi", temp_map);
    hmap_trkphi_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_multpfp", temp_map);
    hmap_multpfp_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_multtracktol", temp_map);
    hmap_multtracktol_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_xdiff_b", temp_map);
    hmap_xdiff_b_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_zdiff_b", temp_map);
    hmap_zdiff_b_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_xdiff", temp_map);
    hmap_xdiff_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_zdiff", temp_map);
    hmap_zdiff_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_vtxx", temp_map);
    hmap_vtxx_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_vtxy", temp_map);
    hmap_vtxy_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_vtxz", temp_map);
    hmap_vtxz_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_vtxz_upborder", temp_map);
    hmap_vtxz_upborder_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_vtxx_upborder", temp_map);
    hmap_vtxx_upborder_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_flsmatch_score", temp_map);
    hmap_flsmatch_score_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_flsmatch_score_second", temp_map);
    hmap_flsmatch_score_second_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_flsmatch_score_difference", temp_map);
    hmap_flsmatch_score_difference_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_ntpcobj", temp_map);
    hmap_ntpcobj_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_vtxcheck_angle", temp_map);
    hmap_vtxcheck_angle_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_residuals_std", temp_map);
    hmap_residuals_std_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_residuals_mean", temp_map);
    hmap_residuals_mean_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_perc_used_hits", temp_map);
    hmap_perc_used_hits_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_mom_mcs_length", temp_map);
    hmap_mom_mcs_length_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_mctruth_nuenergy", temp_map);
    hmap_mctruth_nuenergy_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_mctruth_mumom", temp_map);
    hmap_mctruth_mumom_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_mctruth_mucostheta", temp_map);
    hmap_mctruth_mucostheta_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_mctruth_muphi", temp_map);
    hmap_mctruth_muphi_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_mctruth_nuenergy_gen", temp_map);
    hmap_mctruth_nuenergy_gen_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_mctruth_mumom_gen", temp_map);
    hmap_mctruth_mumom_gen_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_mctruth_mucostheta_gen", temp_map);
    hmap_mctruth_mucostheta_gen_mc_dirt = *temp_map;
    mc_dirt_file->GetObject("hmap_mctruth_muphi_gen", temp_map);
    hmap_mctruth_muphi_gen_mc_dirt = *temp_map;

    //
    // Add them to the bnbcosmic maps (they will be scaled in xsec calculator)
    //
    // // for (auto it : hmap_onebin_mc_dirt) it.second->Scale(scale_factor_mc_dirt);
    // hmap_onebin_mc["dirt"] = hmap_onebin_mc_dirt["total"];
    // // hmap_onebin_mc["total"]->Add(hmap_onebin_mc_dirt["total"]);
    // hmap_onebin_mc["dirt_outfv"] = hmap_onebin_mc_dirt["outfv"];
    // hmap_onebin_mc["dirt_cosmic"] = hmap_onebin_mc_dirt["cosmic"];

    // // for (auto it : hmap_trkmom_mc_dirt) it.second->Scale(scale_factor_mc_dirt);
    // hmap_trkmom_mc["dirt"] = hmap_trkmom_mc_dirt["total"];
    // // hmap_trkmom_mc["total"]->Add(hmap_trkmom_mc_dirt["total"]);
    // hmap_trkmom_mc["dirt_outfv"] = hmap_trkmom_mc_dirt["outfv"];
    // hmap_trkmom_mc["dirt_cosmic"] = hmap_trkmom_mc_dirt["cosmic"];

    // // for (auto it : hmap_trktheta_mc_dirt) it.second->Scale(scale_factor_mc_dirt);
    // hmap_trktheta_mc["dirt"] = hmap_trktheta_mc_dirt["total"];
    // // hmap_trktheta_mc["total"]->Add(hmap_trktheta_mc_dirt["total"]);
    // hmap_trktheta_mc["dirt_outfv"] = hmap_trktheta_mc_dirt["outfv"];
    // hmap_trktheta_mc["dirt_cosmic"] = hmap_trktheta_mc_dirt["cosmic"];

  } else {
    // Create an empy histogram
    // TH1D * h_empty = (TH1D*) hmap_onebin_mc["total"]->Clone("empty");
    // h_empty->Reset();

    // hmap_onebin_mc["dirt"] = h_empty;
    // hmap_onebin_mc["outfv_dirt"] = h_empty;
    // hmap_onebin_mc["cosmic_dirt"] = h_empty;

    // hmap_trkmom_mc["dirt"] = h_empty;
    // hmap_trkmom_mc["outfv_dirt"] = h_empty;
    // hmap_trkmom_mc["cosmic_dirt"] = h_empty;

    // hmap_trktheta_mc["dirt"] = h_empty;
    // hmap_trktheta_mc["outfv_dirt"] = h_empty;
    // hmap_trktheta_mc["cosmic_dirt"] = h_empty;
  }



  

  // *************************************
  // Getting the relevant histograms from data file
  // *************************************

  TH1D* h_trklen_total_bnbon = (TH1D*)bnbon_file->Get("h_trklen_total");
  TH1D* h_trklen_total_extbnb = (TH1D*)extbnb_file->Get("h_trklen_total");
  TH1D* h_onebin_total_bnbon = (TH1D*)bnbon_file->Get("h_onebin_total");
  TH1D* h_onebin_total_extbnb = (TH1D*)extbnb_file->Get("h_onebin_total");
  TH1D* h_trkmom_total_bnbon = (TH1D*)bnbon_file->Get("h_trkmom_total");
  TH1D* h_trkmom_total_extbnb = (TH1D*)extbnb_file->Get("h_trkmom_total");
  TH1D* h_trkmom_classic_total_bnbon = (TH1D*)bnbon_file->Get("h_trkmom_classic_total");
  TH1D* h_trkmom_classic_total_extbnb = (TH1D*)extbnb_file->Get("h_trkmom_classic_total");
  TH1D* h_trktheta_total_bnbon = (TH1D*)bnbon_file->Get("h_trktheta_total");
  TH1D* h_trktheta_total_extbnb = (TH1D*)extbnb_file->Get("h_trktheta_total");
  TH1D* h_trktheta_classic_total_bnbon = (TH1D*)bnbon_file->Get("h_trktheta_classic_total");
  TH1D* h_trktheta_classic_total_extbnb = (TH1D*)extbnb_file->Get("h_trktheta_classic_total");
  TH1D* h_trkphi_total_bnbon = (TH1D*)bnbon_file->Get("h_trkphi_total");
  TH1D* h_trkphi_total_extbnb = (TH1D*)extbnb_file->Get("h_trkphi_total");
  TH1D* h_multpfp_total_bnbon = (TH1D*)bnbon_file->Get("h_multpfp_total");
  TH1D* h_multpfp_total_extbnb = (TH1D*)extbnb_file->Get("h_multpfp_total");
  TH1D* h_multtracktol_total_bnbon = (TH1D*)bnbon_file->Get("h_multtracktol_total");
  TH1D* h_multtracktol_total_extbnb = (TH1D*)extbnb_file->Get("h_multtracktol_total");
  TH1D* h_xdiff_b_total_bnbon = (TH1D*)bnbon_file->Get("h_xdiff_total_b");
  TH1D* h_xdiff_b_total_extbnb = (TH1D*)extbnb_file->Get("h_xdiff_total_b");
  TH1D* h_zdiff_b_total_bnbon = (TH1D*)bnbon_file->Get("h_zdiff_total_b");
  TH1D* h_zdiff_b_total_extbnb = (TH1D*)extbnb_file->Get("h_zdiff_total_b");
  TH1D* h_xdiff_total_bnbon = (TH1D*)bnbon_file->Get("h_xdiff_total");
  TH1D* h_xdiff_total_extbnb = (TH1D*)extbnb_file->Get("h_xdiff_total");
  TH1D* h_zdiff_total_bnbon = (TH1D*)bnbon_file->Get("h_zdiff_total");
  TH1D* h_zdiff_total_extbnb = (TH1D*)extbnb_file->Get("h_zdiff_total");
  TH1D* h_vtxx_total_bnbon = (TH1D*)bnbon_file->Get("h_vtxx_total");
  TH1D* h_vtxx_total_extbnb = (TH1D*)extbnb_file->Get("h_vtxx_total");
  TH1D* h_vtxy_total_bnbon = (TH1D*)bnbon_file->Get("h_vtxy_total");
  TH1D* h_vtxy_total_extbnb = (TH1D*)extbnb_file->Get("h_vtxy_total");
  TH1D* h_vtxz_total_bnbon = (TH1D*)bnbon_file->Get("h_vtxz_total");
  TH1D* h_vtxz_total_extbnb = (TH1D*)extbnb_file->Get("h_vtxz_total");
  TH1D* h_vtxz_upborder_total_bnbon = (TH1D*)bnbon_file->Get("h_vtxz_upborder_total");
  TH1D* h_vtxz_upborder_total_extbnb = (TH1D*)extbnb_file->Get("h_vtxz_upborder_total");
  TH1D* h_vtxx_upborder_total_bnbon = (TH1D*)bnbon_file->Get("h_vtxx_upborder_total");
  TH1D* h_vtxx_upborder_total_extbnb = (TH1D*)extbnb_file->Get("h_vtxx_upborder_total");
  TH1D* h_flsmatch_score_total_bnbon = (TH1D*)bnbon_file->Get("h_flsmatch_score_total");
  TH1D* h_flsmatch_score_total_extbnb = (TH1D*)extbnb_file->Get("h_flsmatch_score_total");
  TH1D* h_flsmatch_score_second_total_bnbon = (TH1D*)bnbon_file->Get("h_flsmatch_score_second_total");
  TH1D* h_flsmatch_score_second_total_extbnb = (TH1D*)extbnb_file->Get("h_flsmatch_score_second_total");
  TH1D* h_flsmatch_score_difference_total_bnbon = (TH1D*)bnbon_file->Get("h_flsmatch_score_difference_total");
  TH1D* h_flsmatch_score_difference_total_extbnb = (TH1D*)extbnb_file->Get("h_flsmatch_score_difference_total");
  TH1D* h_ntpcobj_total_bnbon = (TH1D*)bnbon_file->Get("h_ntpcobj_total");
  TH1D* h_ntpcobj_total_extbnb = (TH1D*)extbnb_file->Get("h_ntpcobj_total");
  TH1D* h_vtxcheck_angle_total_bnbon = (TH1D*)bnbon_file->Get("h_vtxcheck_angle_total");
  TH1D* h_vtxcheck_angle_total_extbnb = (TH1D*)extbnb_file->Get("h_vtxcheck_angle_total");
  TH1D* h_residuals_std_total_bnbon = (TH1D*)bnbon_file->Get("h_residuals_std_total");
  TH1D* h_residuals_std_total_extbnb = (TH1D*)extbnb_file->Get("h_residuals_std_total");
  TH1D* h_residuals_mean_total_bnbon = (TH1D*)bnbon_file->Get("h_residuals_mean_total");
  TH1D* h_residuals_mean_total_extbnb = (TH1D*)extbnb_file->Get("h_residuals_mean_total");
  TH1D* h_perc_used_hits_total_bnbon = (TH1D*)bnbon_file->Get("h_perc_used_hits_total");
  TH1D* h_perc_used_hits_total_extbnb = (TH1D*)extbnb_file->Get("h_perc_used_hits_total");
  TH1D* h_mom_mcs_length_total_bnbon = (TH1D*)bnbon_file->Get("h_mom_mcs_length_total");
  TH1D* h_mom_mcs_length_total_extbnb = (TH1D*)extbnb_file->Get("h_mom_mcs_length_total");

  // Get the true histo from the data file, for when we run in fake data mode
  TH1D * h_truth_xsec_mumom_fake = (TH1D*)bnbon_file->Get("h_truth_xsec_mumom");
  TH1D * h_truth_xsec_muangle_fake = (TH1D*)bnbon_file->Get("h_truth_xsec_muangle");

  TH1D* h_flsPe_wcut_bnbon = (TH1D*)bnbon_file->Get("h_flsPe_wcut");
  TH1D* h_flsPe_wcut_extbnb = (TH1D*)extbnb_file->Get("h_flsPe_wcut");

  TH1D* h_dqdx_trunc_total_bnbon = (TH1D*)bnbon_file->Get("h_dqdx_trunc_total");
  TH1D* h_dqdx_trunc_total_extbnb = (TH1D*)extbnb_file->Get("h_dqdx_trunc_total");
  TH2D* h_dqdx_trunc_length_bnbon = (TH2D*)bnbon_file->Get("h_dqdx_trunc_length");
  TH2D* h_dqdx_trunc_length_extbnb = (TH2D*)extbnb_file->Get("h_dqdx_trunc_length");
  
  TH1D* h_deltax_2d_mc = (TH1D*)mc_bnbcosmic_file->Get("h_deltax_2d");
  TH1D* h_deltax_2d_bnbon = (TH1D*)bnbon_file->Get("h_deltax_2d");
  TH1D* h_deltax_2d_extbnb = (TH1D*)extbnb_file->Get("h_deltax_2d");

  // Total
  TH1D * h_eff_onebin_num = (TH1D*)mc_bnbcosmic_file->Get("h_eff_onebin_num");
  TH1D * h_eff_onebin_den = (TH1D*)mc_bnbcosmic_file->Get("h_eff_onebin_den");

  // Muon momentum
  TH1D * h_truth_xsec_mumom = (TH1D*)mc_bnbcosmic_file->Get("h_truth_xsec_mumom");
  TH1D * h_eff_mumom_num = (TH1D*)mc_bnbcosmic_file->Get("h_eff_mumom_num");
  TH1D * h_eff_mumom_den = (TH1D*)mc_bnbcosmic_file->Get("h_eff_mumom_den");
  TH2D * h_true_reco_mom = (TH2D*)mc_bnbcosmic_file->Get("h_true_reco_mom");

  // Muon costheta
  TH1D * h_truth_xsec_muangle = (TH1D*)mc_bnbcosmic_file->Get("h_truth_xsec_muangle");
  TH1D * h_eff_muangle_num = (TH1D*)mc_bnbcosmic_file->Get("h_eff_muangle_num");
  TH1D * h_eff_muangle_den = (TH1D*)mc_bnbcosmic_file->Get("h_eff_muangle_den");
  TH2D * h_true_reco_costheta = (TH2D*)mc_bnbcosmic_file->Get("h_true_reco_costheta");

  // Double differential
  std::map<std::string,TH2D*>* temp_map2;
  mc_bnbcosmic_file->GetObject("hmap_trktheta_trkmom", temp_map2);
  std::map<std::string,TH2D*> hmap_trktheta_trkmom_mc = *temp_map2;
  TH2D* h_trktheta_trkmom_total_bnbon = (TH2D*)bnbon_file->Get("h_trktheta_trkmom_total");
  TH2D* h_trktheta_trkmom_total_extbnb = (TH2D*)extbnb_file->Get("h_trktheta_trkmom_total");
  TH2D* h_eff_muangle_mumom_num = (TH2D*)mc_bnbcosmic_file->Get("h_eff_muangle_mumom_num");
  TH2D* h_eff_muangle_mumom_den = (TH2D*)mc_bnbcosmic_file->Get("h_eff_muangle_mumom_den");
  std::map<std::string,TH2D*> hmap_trktheta_trkmom_mc_dirt;
  if (mc_dirt_file) {
    mc_dirt_file->GetObject("hmap_trktheta_trkmom", temp_map2);
    hmap_trktheta_trkmom_mc_dirt = *temp_map2;
    // for (auto it : hmap_trktheta_trkmom_mc_dirt) it.second->Scale(scale_factor_mc_dirt);
    // hmap_trktheta_trkmom_mc["dirt"] = hmap_trktheta_trkmom_mc_dirt["total"];
    // hmap_trktheta_trkmom_mc["total"]->Add(hmap_trktheta_trkmom_mc_dirt["total"]);
    // hmap_trktheta_trkmom_mc["dirt_outfv"] = hmap_trktheta_trkmom_mc_dirt["outfv"];
    // hmap_trktheta_trkmom_mc["dirt_cosmic"] = hmap_trktheta_trkmom_mc_dirt["cosmic"];
  } else {
    // TH2D * h_empty = (TH2D*) hmap_trktheta_trkmom_mc["total"]->Clone("empty2d");
    // h_empty->Reset();
    // hmap_trktheta_trkmom_mc["dirt"] = h_empty;
    // hmap_trktheta_trkmom_mc["outfv_dirt"] = h_empty;
    // hmap_trktheta_trkmom_mc["cosmic_dirt"] = h_empty;
  }

  std::map<std::string,UBTH2Poly*>* temp_poly_map2;
  mc_bnbcosmic_file->GetObject("hmap_trktheta_trkmom_poly", temp_poly_map2);
  std::map<std::string,UBTH2Poly*> hmap_trktheta_trkmom_poly_mc = *temp_poly_map2;

  UBTH2Poly* h_eff_muangle_mumom_poly_num = (UBTH2Poly*)mc_bnbcosmic_file->Get("h_eff_muangle_mumom_poly_num");
  UBTH2Poly* h_eff_muangle_mumom_poly_den = (UBTH2Poly*)mc_bnbcosmic_file->Get("h_eff_muangle_mumom_poly_den");

  bnbon_file->GetObject("hmap_trktheta_trkmom_poly", temp_poly_map2);
  UBTH2Poly* h_trktheta_trkmom_total_poly_bnbon = (*temp_poly_map2)["total"];

  extbnb_file->GetObject("hmap_trktheta_trkmom_poly", temp_poly_map2);
  UBTH2Poly* h_trktheta_trkmom_total_poly_extbnb = (*temp_poly_map2)["total"];

  // Reco Per True - GENIE Multisim
  std::vector<UBTH2Poly*> * temp_poly_reco_per_true;
  mc_bnbcosmic_file->GetObject("h_poly_reco_per_true", temp_poly_reco_per_true);
  std::vector<UBTH2Poly*> h_poly_reco_per_true_mc = *temp_poly_reco_per_true;


  
    std::cout << "JJJJJ Just before" << std::endl;
    // hmap_trktheta_trkmom_poly_mc["signal"]->ChangePartition(50, 50);
    // h_trktheta_trkmom_total_poly_bnbon->ChangePartition(50, 50);
    std::cout << "maximum " << hmap_trktheta_trkmom_poly_mc["signal"]->GetMaximum() << std::endl;
    std::cout << "calling ProjectionY " << std::endl;
    TH1D * h_test = hmap_trktheta_trkmom_poly_mc["signal"]->ProjectionY("test", 1);
    std::cout << "before calling GetCopyWithBinNumbers" << std::endl;
    UBTH2Poly* h_poly_binnumber = hmap_trktheta_trkmom_poly_mc["signal"]->GetCopyWithBinNumbers("bs");
    std::cout << "after calling GetCopyWithBinNumbers" << std::endl;

    std::cout << "Original   bin 2, content: " << hmap_trktheta_trkmom_poly_mc["signal"]->GetBinContent(9) << " +- " << hmap_trktheta_trkmom_poly_mc["signal"]->GetBinError(9) << std::endl;
    std::cout << "Projection bin 2, content: " << h_test->GetBinContent(2) << " +- " << h_test->GetBinError(2) << std::endl;

    // std::cout << "Just before subtratcion" << std::endl;
    // std::cout << "Subtracting   h_trktheta_trkmom_total_poly_bnbonbin 2, content: " << h_trktheta_trkmom_total_poly_bnbon->GetBinContent(9) << " +- " << h_trktheta_trkmom_total_poly_bnbon->GetBinError(9) << std::endl;
    // hmap_trktheta_trkmom_poly_mc["signal"]->Add(h_trktheta_trkmom_total_poly_bnbon, 1);
    // std::cout << "After subtraction   bin 2, content: " << hmap_trktheta_trkmom_poly_mc["signal"]->GetBinContent(9) << " +- " << hmap_trktheta_trkmom_poly_mc["signal"]->GetBinError(9) << std::endl;
    // std::cout << "Just after subtratcion" << std::endl;
    // std::cout << "h_trktheta_trkmom_total_poly_bnbon->GetSumw2N() " << h_trktheta_trkmom_total_poly_bnbon->GetSumw2N() << std::endl;


    // std::cout << "JJJJJ Just after" << std::endl;

    // std::cout << "Just before divide" << std::endl;
    // std::cout << "Before divide   bin 2, content: " << hmap_trktheta_trkmom_poly_mc["signal"]->GetBinContent(9) << " +- " << hmap_trktheta_trkmom_poly_mc["signal"]->GetBinError(9) << std::endl;
    // std::cout << "Before divide   h_trktheta_trkmom_total_poly_bnbonbin 2, content: " << h_trktheta_trkmom_total_poly_bnbon->GetBinContent(9) << " +- " << h_trktheta_trkmom_total_poly_bnbon->GetBinError(9) << std::endl;
    // hmap_trktheta_trkmom_poly_mc["signal"]->Divide(h_trktheta_trkmom_total_poly_bnbon);
    // std::cout << "After divide   bin 2, content: " << hmap_trktheta_trkmom_poly_mc["signal"]->GetBinContent(9) << " +- " << hmap_trktheta_trkmom_poly_mc["signal"]->GetBinError(9) << std::endl;
    // std::cout << "Just after divide" << std::endl;



  

  std::cout << "maximum h_eff_muangle_mumom_poly_num " << h_eff_muangle_mumom_poly_num->GetMaximum() << std::endl;
  std::cout << "maximum h_eff_muangle_mumom_poly_den " << h_eff_muangle_mumom_poly_den->GetMaximum() << std::endl;
  std::cout << "maximum h_trktheta_trkmom_total_poly_bnbon " << h_trktheta_trkmom_total_poly_bnbon->GetMaximum() << std::endl;
  std::cout << "maximum h_trktheta_trkmom_total_poly_extbnb " << h_trktheta_trkmom_total_poly_extbnb->GetMaximum() << std::endl;



  
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;


    MigrationMatrix4DPoly migrationmatrix4dpoly;
    migrationmatrix4dpoly.SetRecoPerTrueHistos(h_poly_reco_per_true_mc);
    migrationmatrix4dpoly.SetBins(hmap_trktheta_trkmom_poly_mc["signal"]->GetNumberOfBins());
    TMatrix S = migrationmatrix4dpoly.CalculateMigrationMatrix();
    
    // migrationmatrix4dpoly.SetOutputFileName("latex_test.tex");
    // migrationmatrix4dpoly.PrintSmearingMatrixLatex();
    // migrationmatrix4dpoly.PlotMatrix();

    // int n_bins = h_eff_muangle_mumom_poly_num->GetNumberOfBins();
    // std::cout << "Number of bins: " << n_bins << std::endl;
    // TMatrix S;
    // S.Clear(); 
    // S.ResizeTo(n_bins, n_bins);
    // for (int i = 0; i < n_bins; i++) {
    //   for (int j = 0; j < n_bins; j++) {
    //     S[i][j] = 0;
    //     if (i == j) S[i][j] = 1;
    //   }
    // }

    CrossSectionCalculator2DPoly xsec_calc_poly;
    xsec_calc_poly.set_verbosity(Base::msg::kDEBUG);
    xsec_calc_poly.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
    xsec_calc_poly.SetPOT(bnbon_pot_meas);
    xsec_calc_poly.SetOutDir("output_data_mc_xsec2d_POLY");
    xsec_calc_poly.SetFluxCorrectionWeight(_flux_correction_weight);
    std::cout << "FLUX: " << xsec_calc_poly.EstimateFlux() << std::endl;

    xsec_calc_poly.SetHistograms(hmap_trktheta_trkmom_poly_mc, h_trktheta_trkmom_total_poly_bnbon, h_trktheta_trkmom_total_poly_extbnb);
    xsec_calc_poly.SetTruthHistograms(h_eff_muangle_mumom_poly_num, h_eff_muangle_mumom_poly_den);
    xsec_calc_poly.SetNameAndLabel("trkcostheta_trkmumom_", ";Candidate Track cos(#theta) [GeV];Candidate Track Momentum (MCS) [GeV]");
    xsec_calc_poly.ProcessPlots();
    xsec_calc_poly.SetSmearingMatrix(S);
    xsec_calc_poly.Smear();
    xsec_calc_poly.Draw();

    std::vector<std::string> bkg_names = {"beam-off", "cosmic", "outfv", "nc", "nue", "anumu"};
    UBTH2Poly * xsec_muangle_mumom = xsec_calc_poly.ExtractCrossSection(bkg_names, "cos(#theta_{#mu})", "p_{#mu} [GeV]", "d^{2}#sigma/dcos(#theta_{#mu}dp_{#mu}) [10^{-38} cm^{2}/GeV]");
    UBTH2Poly * xsec_muangle_mumom_mc = xsec_calc_poly.GetMCCrossSection();


    // file_out->cd();
    // save_name = "xsec_muangle_mumom_POLY_" + _prefix;
    // xsec_muangle_mumom->Write(save_name.c_str());
    // save_name = "xsec_muangle_mumom_POLY_mc_" + _prefix;
    // xsec_muangle_mumom_mc->Write(save_name.c_str());
    // save_name = "covariance_matrix_muangle_mumom_POLY_" + _prefix;
    // covariance_matrix_muangle_mumom.Write(save_name.c_str());
  



    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;






  gROOT->SetBatch(kTRUE);

  if (_fake_data_mode || _overlay_mode) {
  	this->PrintFakeDataMessage();
  }

  std::string xsec_file_name = "xsec_file_" + _prefix + ".root";
  std::cout << "Opening output file with name " << xsec_file_name << std::endl;
  TFile *file_out = new TFile(xsec_file_name.c_str(),"RECREATE");
  if ( file_out->IsOpen() )
    std::cout << "File opened successfully" << std::endl;
  std::string save_name = "";



  if (_calculate_xsec) {

    // Intantiate cross section calculator for 1D cross section
    CrossSectionCalculator1D _xsec_calc;
    _xsec_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
    _xsec_calc.SetPOT(bnbon_pot_meas);
    _xsec_calc.SetOutDir("output_data_mc");
    _xsec_calc.SetFluxCorrectionWeight(_flux_correction_weight);
    std::cout << "FLUX: " << _xsec_calc.EstimateFlux() << std::endl;

    _xsec_calc.set_verbosity(Base::msg::kDEBUG);

    if (_fake_data_mode) {
    	this->PrintFakeDataMessage();
    	_xsec_calc.SetFakeDataMode(true);
    }
    if (_overlay_mode) {
      this->PrintFakeDataMessage();
      _xsec_calc.SetOverlayMode(true);
    }

    TFile *file_alt_mc;
    if (_import_alternative_mc) {
      file_alt_mc = TFile::Open(_alternative_mc_file.c_str(),"READ");
      if ( !file_alt_mc->IsOpen() ) {
        std::cout << "Cannot open file containing alternative MC with name " << _alternative_mc_file << std::endl;
        exit(0);
      }
    }


    // Create a list of the backgrounds that will be subtracted
    std::vector<std::string> bkg_names = {"beam-off", "cosmic", "outfv", "nc", "nue", "anumu"};
    if (mc_dirt_file) {
      bkg_names = {"beam-off", "cosmic", "outfv", "nc", "nue", "anumu", "dirt"};
    }


    std::cout << "***************" << std::endl;
    std::cout << "* Total cross section" << std::endl;
    std::cout << "***************" << std::endl;


    //
    // Total cross section
    //

    _xsec_calc.Reset();
    _xsec_calc.SetVerbose(true);
    _xsec_calc.SetHistograms(hmap_onebin_mc, h_onebin_total_bnbon, h_onebin_total_extbnb, hmap_onebin_mc_dirt);  
    _xsec_calc.SetTruthHistograms(h_eff_onebin_num, h_eff_onebin_den);//, h_true_reco_mom); /*h_true_reco_mom is a placeholder*/
    _xsec_calc.SetTruthXSec(h_truth_xsec_mumom); /*h_truth_xsec_mumom is a placeholder*/
    _xsec_calc.SetNameAndLabel("onebin", ";One Bin; Selected Events");
    _xsec_calc.ProcessPlots();
    _xsec_calc.Draw();
    _xsec_calc.Draw(bkg_names);
    _xsec_calc.DoNotSmear(); // No smearing for total cross section
    _xsec_calc.PrintOnFile(_prefix);
    TH1D * xsec = _xsec_calc.ExtractCrossSection(bkg_names, "One Bin", "#sigma [10^{-38} cm^{2}/GeV]");

    save_name = "xsec_onebin_" + _prefix;
    file_out->cd();
    xsec->Write(save_name.c_str());




    // 
    // Total cross section: Cross section reweighting
    //
    

    if (_do_reweighting_plots) {

      //
      // GENIE Multisim Systematics
      //

      CrossSectionBootstrapCalculator1D _xsec_bs_calc;
      _xsec_bs_calc.SetFluxCorrectionWeight(_flux_correction_weight);

      if (_do_genie_systs) {
        _xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("onebin", ";One Bin; Selected Events");
        _xsec_bs_calc.SetHistograms(hmap_onebin_genie_multisim_bs_mc, h_onebin_total_bnbon, h_onebin_total_extbnb, hmap_onebin_mc_dirt);
        _xsec_bs_calc.SetTruthHistograms(bs_genie_multisim_eff_onebin_num, bs_genie_multisim_eff_onebin_den);
        _xsec_bs_calc.SetBkgToSubtract(bkg_names);
        _xsec_bs_calc.DoNotSmear(); // No smearing for total cross section
        _xsec_bs_calc.SetSavePrefix("genie_multisim_onebin");
        _xsec_bs_calc.SetUpperLabel("GENIE Re-Weighting Only");
        _xsec_bs_calc.Run();
      }

      if (_do_extra_syst_systs) {
        _xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("onebin", ";One Bin; Selected Events");
        _xsec_bs_calc.SetHistograms(hmap_onebin_extra_syst_bs_mc, h_onebin_total_bnbon, h_onebin_total_extbnb, hmap_onebin_mc_dirt);
        _xsec_bs_calc.SetTruthHistograms(bs_extra_syst_eff_onebin_num, bs_extra_syst_eff_onebin_den);
        _xsec_bs_calc.SetBkgToSubtract(bkg_names);
        _xsec_bs_calc.DoNotSmear(); // No smearing for total cross section
        _xsec_bs_calc.SetSavePrefix("extra_syst_onebin");
        _xsec_bs_calc.SetUpperLabel("EXTRA SYSTS Re-Weighting Only");
        _xsec_bs_calc.Run();
      }

      //
      // FLUX Multisim Systematics
      //

      if (_do_flux_systs) {
      	_xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("onebin", ";One Bin; Selected Events");
        _xsec_bs_calc.SetHistograms(hmap_onebin_flux_multisim_bs_mc, h_onebin_total_bnbon, h_onebin_total_extbnb, hmap_onebin_mc_dirt);
        _xsec_bs_calc.SetTruthHistograms(bs_flux_multisim_eff_onebin_num, bs_flux_multisim_eff_onebin_den);
        _xsec_bs_calc.SetBkgToSubtract(bkg_names);
        _xsec_bs_calc.DoNotSmear(); // No smearing for total cross section
        _xsec_bs_calc.SetSavePrefix("flux_multisim_onebin");
        _xsec_bs_calc.SetUpperLabel("FLUX Re-Weighting Only");
        _xsec_bs_calc.SetFluxHistogramType(true, _target_flux_syst); // Also reweight the flux
        _xsec_bs_calc.Run();
      }
      

    } // _do_reweighting_plots
    


    std::cout << "***************" << std::endl;
    std::cout << "* Muon Momentum cross section" << std::endl;
    std::cout << "***************" << std::endl;

    TH2D covariance_matrix_genie;
    TH2D covariance_matrix_extra_syst;
    TH2D covariance_matrix_flux;
    TH2D covariance_matrix_detector;
    TH2D covariance_matrix_cosmic;
    TH2D covariance_matrix_dirt;

    TH2D frac_covariance_matrix_genie;
    TH2D frac_covariance_matrix_extra_syst;
    TH2D frac_covariance_matrix_flux;
    TH2D frac_covariance_matrix_detector;
    TH2D frac_covariance_matrix_cosmic;
    TH2D frac_covariance_matrix_dirt;


    // 
    // Muon Momentum: Cross section reweighting
    //

    if (_do_reweighting_plots) {

      //
      // GENIE Multisim Systematics
      //

      CrossSectionBootstrapCalculator1D _xsec_bs_calc;
      _xsec_bs_calc.SetFluxCorrectionWeight(_flux_correction_weight);
      _xsec_bs_calc.set_verbosity(Base::msg::kINFO);

      if (_do_genie_systs) {
        _xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("trkmom_bs", ";p_{#mu}^{reco} [GeV]; Selected Events");
        _xsec_bs_calc.SetHistograms(hmap_trkmom_genie_multisim_bs_mc/*map_bs_trkmom_genie_multisim*/, h_trkmom_total_bnbon, h_trkmom_total_extbnb, hmap_trkmom_mc_dirt);
        _xsec_bs_calc.SetTruthHistograms(bs_genie_multisim_eff_mumom_num, bs_genie_multisim_eff_mumom_den, bs_genie_multisim_reco_true_mumom);
        _xsec_bs_calc.SetMigrationMatrixDimensions(7, 7);
        _xsec_bs_calc.SetBkgToSubtract(bkg_names);
        _xsec_bs_calc.SetSavePrefix("genie_multisim_mumom");
        _xsec_bs_calc.SetUpperLabel("GENIE Re-Weighting Only");
        _xsec_bs_calc.Run();

        _xsec_bs_calc.SaveCovarianceMatrix("covariance_genie.root", "covariance_matrix_genie_mumom");
        _xsec_bs_calc.SaveFractionalCovarianceMatrix("covariance_genie.root", "frac_covariance_matrix_genie_mumom");
        _xsec_bs_calc.GetCovarianceMatrix(covariance_matrix_genie);
        _xsec_bs_calc.GetFractionalCovarianceMatrix(frac_covariance_matrix_genie);

        for (int i = 0; i < covariance_matrix_genie.GetNbinsX(); i++) {
      	  std::cout << "GENIE Multisim - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_genie.GetBinContent(i+1, i+1) << std::endl;
        }
      }

      if (_import_genie_systs) {

      	TFile* cov_file = TFile::Open("covariance_genie.root", "READ");
        TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_genie_mumom");
        frac_covariance_matrix_genie = *m;

      }

      if (_do_extra_syst_systs) {
        _xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("trkmom_bs", ";p_{#mu}^{reco} [GeV]; Selected Events");
        _xsec_bs_calc.SetHistograms(hmap_trkmom_extra_syst_bs_mc, h_trkmom_total_bnbon, h_trkmom_total_extbnb, hmap_trkmom_mc_dirt);
        _xsec_bs_calc.SetTruthHistograms(bs_extra_syst_eff_mumom_num, bs_extra_syst_eff_mumom_den, bs_extra_syst_reco_true_mumom);
        _xsec_bs_calc.SetMigrationMatrixDimensions(7, 7);
        _xsec_bs_calc.SetBkgToSubtract(bkg_names);
        _xsec_bs_calc.SetSavePrefix("extra_syst_mumom");
        _xsec_bs_calc.SetUpperLabel("EXTRA SYSTS Re-Weighting Only");
        _xsec_bs_calc.Run();

        _xsec_bs_calc.SaveCovarianceMatrix("covariance_extra_syst.root", "covariance_matrix_extra_syst_mumom");
        _xsec_bs_calc.SaveFractionalCovarianceMatrix("covariance_extra_syst.root", "frac_covariance_matrix_extra_syst_mumom");
        _xsec_bs_calc.GetCovarianceMatrix(covariance_matrix_extra_syst);
        _xsec_bs_calc.GetFractionalCovarianceMatrix(frac_covariance_matrix_extra_syst);

        for (int i = 0; i < covariance_matrix_extra_syst.GetNbinsX(); i++) {
          std::cout << "EXTRA SYSTS - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_extra_syst.GetBinContent(i+1, i+1) << std::endl;
        }
      }

      if (_import_extra_syst_systs) {

        TFile* cov_file = TFile::Open("covariance_extra_syst.root", "READ");
        TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_extra_syst_mumom");
        frac_covariance_matrix_extra_syst = *m;

      }



      //
      // FLUX Multisim Systematics
      //
      if (_do_flux_systs) {
        _xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("trkmom_bs", ";p_{#mu}^{reco} [GeV]; Selected Events");
        _xsec_bs_calc.SetHistograms(hmap_trkmom_flux_multisim_bs_mc/*map_bs_trkmom_genie_multisim*/, h_trkmom_total_bnbon, h_trkmom_total_extbnb, hmap_trkmom_mc_dirt);
        _xsec_bs_calc.SetTruthHistograms(bs_flux_multisim_eff_mumom_num, bs_flux_multisim_eff_mumom_den, bs_flux_multisim_true_reco_mumom);
        _xsec_bs_calc.SetMigrationMatrixDimensions(7, 7);
        _xsec_bs_calc.SetBkgToSubtract(bkg_names);
        _xsec_bs_calc.SetSavePrefix("flux_multisim_mumom");
        _xsec_bs_calc.SetUpperLabel("FLUX Re-Weighting Only");
        _xsec_bs_calc.SetFluxHistogramType(true, _target_flux_syst); // Also reweight the flux
        _xsec_bs_calc.AddExtraDiagonalUncertainty(_extra_flux_fractional_uncertainty); // For POT uncertainty
        _xsec_bs_calc.Run();

        _xsec_bs_calc.SaveCovarianceMatrix("covariance_flux.root", "covariance_matrix_flux_mumom");
        _xsec_bs_calc.SaveFractionalCovarianceMatrix("covariance_flux.root", "frac_covariance_matrix_flux_mumom");
        _xsec_bs_calc.GetCovarianceMatrix(covariance_matrix_flux);
        _xsec_bs_calc.GetFractionalCovarianceMatrix(frac_covariance_matrix_flux);

        file_out->cd();
        covariance_matrix_flux.Write(("flux_syst_covariance_matrix_mumom_" + _target_flux_syst).c_str());

        for (int i = 0; i < covariance_matrix_flux.GetNbinsX(); i++) {
      	  std::cout << "FLUX Multisim - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_flux.GetBinContent(i+1, i+1) << std::endl;
        }
      }

      if (_import_flux_systs) {

      	TFile* cov_file = TFile::Open("covariance_flux.root", "READ");
        TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_flux_mumom");
        frac_covariance_matrix_flux = *m;
      }

    } // _do_reweighting_plots


    if (_import_detector_systs) {

      TFile* cov_file = TFile::Open("covariance_detector.root", "READ");
      TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_detector_mumom");
      frac_covariance_matrix_detector = *m;
    }

    if (_import_cosmic_systs) {

      TFile* cov_file = TFile::Open("covariance_cosmic.root", "READ");
      TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_cosmic_mumom");
      frac_covariance_matrix_cosmic = *m;
    }

    if (_import_dirt_systs) {

      TFile* cov_file = TFile::Open("covariance_dirt.root", "READ");
      TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_dirt_mumom");
      frac_covariance_matrix_dirt = *m;
    }

    TH2D frac_covariance_matrix_mumom = * ((TH2D*)frac_covariance_matrix_genie.Clone("frac_covariance_matrix_mumom"));
    frac_covariance_matrix_mumom.Add(&frac_covariance_matrix_extra_syst);
    frac_covariance_matrix_mumom.Add(&frac_covariance_matrix_flux);
    frac_covariance_matrix_mumom.Add(&frac_covariance_matrix_detector);
    frac_covariance_matrix_mumom.Add(&frac_covariance_matrix_cosmic);
    frac_covariance_matrix_mumom.Add(&frac_covariance_matrix_dirt);


    // if (_extra_fractional_uncertainty != 0.) {
    //   std::cout << "Adding extra uncertainty of " << _extra_fractional_uncertainty << std::endl;
    //   this->AddExtraDiagonalUncertainty(covariance_matrix_mumom, _extra_fractional_uncertainty);
    // }

    // for (int i = 0; i < covariance_matrix_mumom.GetNbinsX(); i++) {
    //   std::cout << "TOTAL - Momentum - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_mumom.GetBinContent(i+1, i+1) << std::endl;
    // }

    
    //
    // Muon Momentum Cross Section
    //
    TMatrix S_2d; S_2d.Clear(); S_2d.ResizeTo(7, 7);
    MigrationMatrix2D migrationmatrix2d;
    migrationmatrix2d.SetOutDir("migration_matrix_2d_trkmom");
    migrationmatrix2d.SetNBins(7, 7);
    migrationmatrix2d.SetTrueRecoHistogram(h_true_reco_mom);
    S_2d = migrationmatrix2d.CalculateMigrationMatrix();
    migrationmatrix2d.PlotMatrix();
    migrationmatrix2d.SetOutputFileName("migration_matrix_2d_trkmom.tex");
    migrationmatrix2d.PrintSmearingMatrixLatex();

    _xsec_calc.Reset();
    _xsec_calc.set_verbosity(Base::msg::kINFO);
    _xsec_calc.SetMigrationMatrix(S_2d);
    _xsec_calc.SetHistograms(hmap_trkmom_mc, h_trkmom_total_bnbon, h_trkmom_total_extbnb, hmap_trkmom_mc_dirt);  
    _xsec_calc.SetTruthHistograms(h_eff_mumom_num, h_eff_mumom_den, h_true_reco_mom);
    _xsec_calc.SetTruthXSec(h_truth_xsec_mumom);
    if (_fake_data_mode) {
    	_xsec_calc.SetTruthXSec(h_truth_xsec_mumom_fake, 7, 7);
    }
    _xsec_calc.SetNameAndLabel("trkmom", ";p_{#mu}^{reco} [GeV]; Selected Events");
    _xsec_calc.ProcessPlots();
    _xsec_calc.SaveEventNumbers("trkmom_eventsperbin_table.tex");
    _xsec_calc.Draw();
    _xsec_calc.Draw(bkg_names);
    _xsec_calc.Smear(7, 7);
    if (frac_covariance_matrix_mumom.GetNbinsX() > 1) {
      _xsec_calc.SetFractionalCovarianceMatrix(frac_covariance_matrix_mumom);
    }
    _xsec_calc.AddExtraDiagonalUncertainty(_extra_fractional_uncertainty);
    if (_import_alternative_mc) {
      TH1D* h = (TH1D*)file_alt_mc->Get("xsec_mumom_mc_cv_tune3");
      _xsec_calc.ImportAlternativeMC(*h);
    }

    TH1D * xsec_mumom = _xsec_calc.ExtractCrossSection(bkg_names, "p_{#mu}^{reco} [GeV]", "d#sigma/dp_{#mu}^{reco} [10^{-38} cm^{2}/GeV]");

    TH1D * xsec_mumom_mc = _xsec_calc.GetMCCrossSection();
    file_out->cd();
    save_name = "xsec_mumom_" + _prefix;
    xsec_mumom->Write(save_name.c_str());
    save_name = "xsec_mumom_mc_" + _prefix;
    xsec_mumom_mc->Write(save_name.c_str());
    save_name = "frac_covariance_matrix_mumom_" + _prefix;
    frac_covariance_matrix_mumom.Write(save_name.c_str());










    std::cout << "***************" << std::endl;
    std::cout << "* Muon cos(theta) cross section" << std::endl;
    std::cout << "***************" << std::endl;




    // 
    // Muon CosTheta: Cross section reweighting
    //

    if (_do_reweighting_plots) {

      //
      // GENIE Multisim Systematics
      //

      CrossSectionBootstrapCalculator1D _xsec_bs_calc;
      _xsec_bs_calc.SetFluxCorrectionWeight(_flux_correction_weight);

      if (_do_genie_systs) {
        _xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("trkcostheta_genie_multisim", ";cos(#theta_{#mu}^{reco}); Selected Events");
        _xsec_bs_calc.SetHistograms(hmap_trkangle_genie_multisim_bs_mc, h_trktheta_total_bnbon, h_trktheta_total_extbnb, hmap_trktheta_mc_dirt);
        _xsec_bs_calc.SetTruthHistograms(bs_genie_multisim_eff_muangle_num, bs_genie_multisim_eff_muangle_den, bs_genie_multisim_true_reco_muangle);
        _xsec_bs_calc.SetMigrationMatrixDimensions(9, 9);
        _xsec_bs_calc.SetBkgToSubtract(bkg_names);
        _xsec_bs_calc.SetSavePrefix("genie_multisim_muangle");
        _xsec_bs_calc.SetUpperLabel("GENIE Re-Weighting Only");
        _xsec_bs_calc.Run();

        _xsec_bs_calc.SaveCovarianceMatrix("covariance_genie.root", "covariance_matrix_genie_muangle");
        _xsec_bs_calc.SaveFractionalCovarianceMatrix("covariance_genie.root", "frac_covariance_matrix_genie_muangle");
        _xsec_bs_calc.GetCovarianceMatrix(covariance_matrix_genie);
        _xsec_bs_calc.GetFractionalCovarianceMatrix(frac_covariance_matrix_genie);

        for (int i = 0; i < covariance_matrix_genie.GetNbinsX(); i++) {
      	  std::cout << "GENIE Multisim - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_genie.GetBinContent(i+1, i+1) << std::endl;
        }
      }

      if (_import_genie_systs) {

      	TFile* cov_file = TFile::Open("covariance_genie.root", "READ");
        TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_genie_muangle");
        frac_covariance_matrix_genie = *m;
      	
      }

      if (_do_extra_syst_systs) {
        _xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("trkcostheta_extra_syst", ";cos(#theta_{#mu}^{reco}); Selected Events");
        _xsec_bs_calc.SetHistograms(hmap_trkangle_extra_syst_bs_mc, h_trktheta_total_bnbon, h_trktheta_total_extbnb, hmap_trktheta_mc_dirt);
        _xsec_bs_calc.SetTruthHistograms(bs_extra_syst_eff_muangle_num, bs_extra_syst_eff_muangle_den, bs_extra_syst_true_reco_muangle);
        _xsec_bs_calc.SetMigrationMatrixDimensions(9, 9);
        _xsec_bs_calc.SetBkgToSubtract(bkg_names);
        _xsec_bs_calc.SetSavePrefix("extra_syst_muangle");
        _xsec_bs_calc.SetUpperLabel("EXTRA SYSTS Re-Weighting Only");
        _xsec_bs_calc.Run();

        _xsec_bs_calc.SaveCovarianceMatrix("covariance_extra_syst.root", "covariance_matrix_extra_syst_muangle");
        _xsec_bs_calc.SaveFractionalCovarianceMatrix("covariance_extra_syst.root", "frac_covariance_matrix_extra_syst_muangle");
        _xsec_bs_calc.GetCovarianceMatrix(covariance_matrix_extra_syst);
        _xsec_bs_calc.GetFractionalCovarianceMatrix(frac_covariance_matrix_extra_syst);

        for (int i = 0; i < covariance_matrix_extra_syst.GetNbinsX(); i++) {
          std::cout << "EXTRA SYSTS - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_extra_syst.GetBinContent(i+1, i+1) << std::endl;
        }
      }

      if (_import_extra_syst_systs) {

        TFile* cov_file = TFile::Open("covariance_extra_syst.root", "READ");
        TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_extra_syst_muangle");
        frac_covariance_matrix_extra_syst = *m;
        
      }


      //
      // FLUX Multisim Systematics
      //
      if (_do_flux_systs) {
        _xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("trkcostheta_flux_multisim", ";Candidate Track cos(#theta_{#mu}^{reco}) [GeV]; Selected Events");
        _xsec_bs_calc.SetHistograms(hmap_trkangle_flux_multisim_bs_mc, h_trktheta_total_bnbon, h_trktheta_total_extbnb, hmap_trktheta_mc_dirt);
        _xsec_bs_calc.SetTruthHistograms(bs_flux_multisim_eff_muangle_num, bs_flux_multisim_eff_muangle_den, bs_flux_multisim_true_reco_muangle);
        _xsec_bs_calc.SetMigrationMatrixDimensions(9, 9);
        _xsec_bs_calc.SetBkgToSubtract(bkg_names);
        _xsec_bs_calc.SetSavePrefix("flux_multisim_muangle");
        _xsec_bs_calc.SetUpperLabel("FLUX Re-Weighting Only");
        _xsec_bs_calc.SetFluxHistogramType(true, _target_flux_syst); // Also reweight the flux
        _xsec_bs_calc.AddExtraDiagonalUncertainty(_extra_flux_fractional_uncertainty); // For POT uncertainty
        _xsec_bs_calc.Run();

        _xsec_bs_calc.SaveCovarianceMatrix("covariance_flux.root", "covariance_matrix_flux_muangle");
        _xsec_bs_calc.SaveFractionalCovarianceMatrix("covariance_flux.root", "frac_covariance_matrix_flux_muangle");
        _xsec_bs_calc.GetCovarianceMatrix(covariance_matrix_flux);
        _xsec_bs_calc.GetFractionalCovarianceMatrix(frac_covariance_matrix_flux);

        file_out->cd();
        covariance_matrix_flux.Write(("flux_syst_covariance_matrix_muangle_" + _target_flux_syst).c_str());

        for (int i = 0; i < covariance_matrix_flux.GetNbinsX(); i++) {
      	  std::cout << "FLUX Multisim - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_flux.GetBinContent(i+1, i+1) << std::endl;
        }
      }

      if (_import_flux_systs) {

      	TFile* cov_file = TFile::Open("covariance_flux.root", "READ");
        TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_flux_muangle");
        frac_covariance_matrix_flux = *m;

      }

    } // _do_reweighting_plots

    if (_import_detector_systs) {

      TFile* cov_file = TFile::Open("covariance_detector.root", "WRITE");
      TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_detector_muangle");
      frac_covariance_matrix_detector = *m;
    }


    if (_import_cosmic_systs) {

      TFile* cov_file = TFile::Open("covariance_cosmic.root", "WRITE");
      TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_cosmic_muangle");
      frac_covariance_matrix_cosmic = *m; 
    }


    if (_import_dirt_systs) {

      TFile* cov_file = TFile::Open("covariance_dirt.root", "WRITE");
      TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_dirt_muangle");
      frac_covariance_matrix_dirt = *m; 
    }




    TH2D frac_covariance_matrix_muangle = * ((TH2D*)frac_covariance_matrix_genie.Clone("frac_covariance_matrix"));
    frac_covariance_matrix_muangle.Add(&frac_covariance_matrix_extra_syst);
    frac_covariance_matrix_muangle.Add(&frac_covariance_matrix_flux);
    frac_covariance_matrix_muangle.Add(&frac_covariance_matrix_detector);
    frac_covariance_matrix_muangle.Add(&frac_covariance_matrix_cosmic);
    frac_covariance_matrix_muangle.Add(&frac_covariance_matrix_dirt);

    // for (int i = 0; i < covariance_matrix_muangle.GetNbinsX(); i++) {
    //   std::cout << "TOTAL - Angle - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_muangle.GetBinContent(i+1, i+1) << std::endl;
    // }


    //
    // Muon CosTheta Cross Section
    // 

    S_2d.Clear(); S_2d.ResizeTo(9, 9);
    migrationmatrix2d.SetOutDir("migration_matrix_2d_trkcostheta");
    migrationmatrix2d.SetVerbosity(false);
    migrationmatrix2d.SetNBins(9, 9);
    migrationmatrix2d.SetTrueRecoHistogram(h_true_reco_costheta);
    S_2d = migrationmatrix2d.CalculateMigrationMatrix();
    migrationmatrix2d.PlotMatrix();
    migrationmatrix2d.SetOutputFileName("migration_matrix_2d_trkangle.tex");
    migrationmatrix2d.PrintSmearingMatrixLatex();

    _xsec_calc.Reset();
    _xsec_calc.set_verbosity(Base::msg::kINFO);
    _xsec_calc.SetMigrationMatrix(S_2d);
    _xsec_calc.SetHistograms(hmap_trktheta_mc, h_trktheta_total_bnbon, h_trktheta_total_extbnb, hmap_trktheta_mc_dirt);  
    _xsec_calc.SetTruthHistograms(h_eff_muangle_num, h_eff_muangle_den, h_true_reco_costheta);
    _xsec_calc.SetTruthXSec(h_truth_xsec_muangle);
    if (_fake_data_mode) {
    	_xsec_calc.SetTruthXSec(h_truth_xsec_muangle_fake, 9, 9);
    }
    _xsec_calc.SetNameAndLabel("trkcostheta", ";cos(#theta_{#mu}^{reco}); Selected Events");
    _xsec_calc.ProcessPlots();
    _xsec_calc.SaveEventNumbers("trkcostheta_eventsperbin_table.tex");
    _xsec_calc.Draw();
    _xsec_calc.Draw(bkg_names);
    _xsec_calc.Smear(9, 9);
    if (frac_covariance_matrix_muangle.GetNbinsX() > 1) {
      _xsec_calc.SetFractionalCovarianceMatrix(frac_covariance_matrix_muangle);
    }
    _xsec_calc.AddExtraDiagonalUncertainty(_extra_fractional_uncertainty);
    if (_import_alternative_mc) {
      TH1D* h = (TH1D*)file_alt_mc->Get("xsec_muangle_mc_cv_tune3");
      _xsec_calc.ImportAlternativeMC(*h);
    }
    TH1D * xsec_muangle = _xsec_calc.ExtractCrossSection(bkg_names, "cos(#theta_{#mu}^{reco})", "d#sigma/dcos(#theta_{#mu}^{reco}) [10^{-38} cm^{2}]");
    TH1D * xsec_muangle_mc = _xsec_calc.GetMCCrossSection();

    file_out->cd();
    save_name = "xsec_muangle_" + _prefix;
    xsec_muangle->Write(save_name.c_str());
    save_name = "xsec_muangle_mc_" + _prefix;
    xsec_muangle_mc->Write(save_name.c_str());
    save_name = "frac_covariance_matrix_muangle_" + _prefix;
    frac_covariance_matrix_muangle.Write(save_name.c_str());









    std::cout << "***************" << std::endl;
    std::cout << "* Double differential cross section" << std::endl;
    std::cout << "***************" << std::endl;


    //
    // Double Differential Cross Section
    //

    std::cout << "Here 1" << std::endl;

    TTree * tt;
    mc_bnbcosmic_file->GetObject("true_reco_tree", tt);

    CrossSectionBootstrapCalculator2D _xsec_bs_calc;
    _xsec_bs_calc.SetFluxCorrectionWeight(_flux_correction_weight);

    if (_do_genie_systs) {
      _xsec_bs_calc.Reset();
      _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
      _xsec_bs_calc.SetPOT(bnbon_pot_meas);
      _xsec_bs_calc.SetNameAndLabel("trkcostheta_trkmom_genie_multisim", ";cos(#theta_{#mu}^{reco});p_{#mu} [GeV]");
      _xsec_bs_calc.SetHistograms(hmap_trktheta_trkmom_genie_multisim_bs_mc, h_trktheta_trkmom_total_bnbon, h_trktheta_trkmom_total_extbnb, hmap_trktheta_trkmom_mc_dirt);
      _xsec_bs_calc.SetTruthHistograms(bs_genie_multisim_eff_muangle_mumom_num, bs_genie_multisim_eff_muangle_mumom_den, bs_genie_multisim_reco_per_true_mc);
      _xsec_bs_calc.SetBkgToSubtract(bkg_names);
      _xsec_bs_calc.SetSavePrefix("genie_multisim_muangle_mumom");
      _xsec_bs_calc.SetUpperLabel("GENIE Re-Weighting Only");
      _xsec_bs_calc.Run();

      _xsec_bs_calc.SaveCovarianceMatrix("covariance_genie.root", "covariance_matrix_genie_muangle_mumom");
      _xsec_bs_calc.SaveFractionalCovarianceMatrix("covariance_genie.root", "frac_covariance_matrix_genie_muangle_mumom");
      _xsec_bs_calc.GetCovarianceMatrix(covariance_matrix_genie);
      _xsec_bs_calc.GetFractionalCovarianceMatrix(frac_covariance_matrix_genie);

      for (int i = 0; i < covariance_matrix_genie.GetNbinsX(); i++) {
        std::cout << "GENIE Multisim - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_genie.GetBinContent(i+1, i+1) << std::endl;
      }
    }

    if (_import_genie_systs) {

      TFile* cov_file = TFile::Open("covariance_genie.root", "READ");
      TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_genie_muangle_mumom");
      frac_covariance_matrix_genie = *m;
        
    }

    if (_do_extra_syst_systs) {
      _xsec_bs_calc.Reset();
      _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
      _xsec_bs_calc.SetPOT(bnbon_pot_meas);
      _xsec_bs_calc.SetNameAndLabel("trkcostheta_trkmom_extra_syst_multisim", ";cos(#theta_{#mu}^{reco});p_{#mu} [GeV]");
      _xsec_bs_calc.SetHistograms(hmap_trktheta_trkmom_extra_syst_bs_mc, h_trktheta_trkmom_total_bnbon, h_trktheta_trkmom_total_extbnb, hmap_trktheta_trkmom_mc_dirt);
      _xsec_bs_calc.SetTruthHistograms(bs_extra_syst_eff_muangle_mumom_num, bs_extra_syst_eff_muangle_mumom_den, bs_extra_syst_multisim_reco_per_true_mc);
      _xsec_bs_calc.SetBkgToSubtract(bkg_names);
      _xsec_bs_calc.SetSavePrefix("extra_syst_muangle_mumom");
      _xsec_bs_calc.SetUpperLabel("EXTRA SYSTS Re-Weighting Only");
      _xsec_bs_calc.Run();

      _xsec_bs_calc.SaveCovarianceMatrix("covariance_extra_syst.root", "covariance_matrix_extra_syst_muangle_mumom");
      _xsec_bs_calc.SaveFractionalCovarianceMatrix("covariance_extra_syst.root", "frac_covariance_matrix_extra_syst_muangle_mumom");
      _xsec_bs_calc.GetCovarianceMatrix(covariance_matrix_extra_syst);
      _xsec_bs_calc.GetFractionalCovarianceMatrix(frac_covariance_matrix_extra_syst);

      for (int i = 0; i < covariance_matrix_extra_syst.GetNbinsX(); i++) {
        std::cout << "EXTRA SYSTS - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_extra_syst.GetBinContent(i+1, i+1) << std::endl;
      }
    }

    if (_import_extra_syst_systs) {

      TFile* cov_file = TFile::Open("covariance_extra_syst.root", "READ");
      TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_extra_syst_muangle_mumom");
      frac_covariance_matrix_extra_syst = *m;
        
    }

    if (_do_flux_systs) {
      _xsec_bs_calc.Reset();
      _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
      _xsec_bs_calc.SetPOT(bnbon_pot_meas);
      _xsec_bs_calc.SetNameAndLabel("trkcostheta_trkmom_flux_multisim", ";cos(#theta_{#mu}^{reco});p_{#mu} [GeV]");
      _xsec_bs_calc.SetHistograms(hmap_trktheta_trkmom_flux_multisim_bs_mc, h_trktheta_trkmom_total_bnbon, h_trktheta_trkmom_total_extbnb, hmap_trktheta_trkmom_mc_dirt);
      _xsec_bs_calc.SetTruthHistograms(bs_flux_multisim_eff_muangle_mumom_num, bs_flux_multisim_eff_muangle_mumom_den, bs_flux_multisim_reco_per_true_mc);
      _xsec_bs_calc.SetBkgToSubtract(bkg_names);
      _xsec_bs_calc.SetSavePrefix("flux_multisim_muangle_mumom");
      _xsec_bs_calc.SetUpperLabel("FLUX Re-Weighting Only");
      _xsec_bs_calc.SetFluxHistogramType(true, _target_flux_syst); // Also reweight the flux
      _xsec_bs_calc.AddExtraDiagonalUncertainty(_extra_flux_fractional_uncertainty); // For POT uncertainty
      _xsec_bs_calc.Run();

      _xsec_bs_calc.SaveCovarianceMatrix("covariance_flux.root", "covariance_matrix_flux_muangle_mumom");
      _xsec_bs_calc.SaveFractionalCovarianceMatrix("covariance_flux.root", "frac_covariance_matrix_flux_muangle_mumom");
      _xsec_bs_calc.GetCovarianceMatrix(covariance_matrix_flux);
      _xsec_bs_calc.GetFractionalCovarianceMatrix(frac_covariance_matrix_flux);

      for (int i = 0; i < covariance_matrix_flux.GetNbinsX(); i++) {
        std::cout << "FLUX Multisim - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_flux.GetBinContent(i+1, i+1) << std::endl;
      }
    }

    if (_import_flux_systs) {

      TFile* cov_file = TFile::Open("covariance_flux.root", "READ");
      TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_flux_muangle_mumom");
      frac_covariance_matrix_flux = *m;

    }


    if (_import_detector_systs) {

      TFile* cov_file = TFile::Open("covariance_detector.root", "WRITE");
      TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_detector_muangle_mumom");
      frac_covariance_matrix_detector = *m;
    }


    if (_import_cosmic_systs) {

      TFile* cov_file = TFile::Open("covariance_cosmic.root", "WRITE");
      TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_cosmic_muangle_mumom");
      frac_covariance_matrix_cosmic = *m;
    }


    if (_import_dirt_systs) {

      TFile* cov_file = TFile::Open("covariance_dirt.root", "WRITE");
      TH2D* m = (TH2D*)cov_file->Get("frac_covariance_matrix_dirt_muangle_mumom");
      frac_covariance_matrix_dirt = *m;
    }

    TH2D frac_covariance_matrix_muangle_mumom = * ((TH2D*)frac_covariance_matrix_genie.Clone("frac_covariance_matrix_muangle_mumom"));
    frac_covariance_matrix_muangle_mumom.Add(&frac_covariance_matrix_extra_syst);
    frac_covariance_matrix_muangle_mumom.Add(&frac_covariance_matrix_flux);
    frac_covariance_matrix_muangle_mumom.Add(&frac_covariance_matrix_detector);
    frac_covariance_matrix_muangle_mumom.Add(&frac_covariance_matrix_cosmic);
    frac_covariance_matrix_muangle_mumom.Add(&frac_covariance_matrix_dirt);

    // for (int i = 0; i < covariance_matrix_muangle_mumom.GetNbinsX(); i++) {
    //   std::cout << "TOTAL - Angle - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_muangle_mumom.GetBinContent(i+1, i+1) << std::endl;
    // }



    //
    // Double diff cross section
    //

    std::cout << "Here 2" << std::endl;

    MigrationMatrix4D migrationmatrix4d;
    migrationmatrix4d.SetTTree(tt); 
    std::cout << "Here 3" << std::endl;


    migrationmatrix4d.SetRecoPerTrueHistos(h_reco_per_true_mc);
    std::cout << "Here 4" << std::endl;

    migrationmatrix4d.SetOutDir();



    // int n_bins_double_mumom = 4;
    // double bins_double_mumom[5] = {0.00, 0.25, 0.50, 1.0, 2.50};
    // int n_bins_double_mucostheta = 6;
    // double bins_double_mucostheta[7] = {-1.00, -0.50, 0.00, 0.25, 0.50, 0.75, 1.00};

    // int n_bins_double_mumom = 6; ///< Number of momentum bins for double differential
    // double bins_double_mumom[7] = {0.00, 0.18, 0.30, 0.45, 0.77, 1.28, 2.50}; ///< Momentum bins for double differential
    // // int n_bins_double_mumom = 5; ///< Number of momentum bins for double differential
    // // double bins_double_mumom[6] = {0.00, 0.25, 0.50, 0.85, 1.40, 2.50}; ///< Momentum bins for double differential
    // int n_bins_double_mucostheta = 9; ///< Number of costheta bins for double differential
    // double bins_double_mucostheta[10] = {-1.00, -0.50, 0.00, 0.27, 0.45, 0.62, 0.76, 0.86, 0.94, 1.00}; ///< costheta bins for double differential

    // Get the bins first
    int n_bins_double_mucostheta = hmap_trktheta_trkmom_mc["total"]->GetNbinsX();
    const double *bins_double_mucostheta = hmap_trktheta_trkmom_mc["total"]->GetXaxis()->GetXbins()->GetArray();
    int n_bins_double_mumom = hmap_trktheta_trkmom_mc["total"]->GetNbinsY();
    const double *bins_double_mumom = hmap_trktheta_trkmom_mc["total"]->GetYaxis()->GetXbins()->GetArray();

    migrationmatrix4d.SetBins(bins_double_mucostheta, n_bins_double_mucostheta, bins_double_mumom, n_bins_double_mumom);
    
    Mat4D S_4d = migrationmatrix4d.CalculateMigrationMatrix();
    
    migrationmatrix4d.SetOutputFileName("latex_test.tex");
    migrationmatrix4d.PrintSmearingMatrixLatex();
    migrationmatrix4d.PlotMatrix();

    CrossSectionCalculator2D xseccalc2d;
    xseccalc2d.set_verbosity(Base::msg::kINFO);
    xseccalc2d.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb, scale_factor_mc_dirt);
    xseccalc2d.SetPOT(bnbon_pot_meas);
    xseccalc2d.SetOutDir("output_data_mc_xsec2d");
    xseccalc2d.SetFluxCorrectionWeight(_flux_correction_weight);
    std::cout << "FLUX: " << xseccalc2d.EstimateFlux() << std::endl;

    xseccalc2d.SetHistograms(hmap_trktheta_trkmom_mc, h_trktheta_trkmom_total_bnbon, h_trktheta_trkmom_total_extbnb, hmap_trktheta_trkmom_mc_dirt);
    xseccalc2d.SetTruthHistograms(h_eff_muangle_mumom_num, h_eff_muangle_mumom_den);
    xseccalc2d.SetNameAndLabel("trkcostheta_trkmumom_", ";Candidate Track cos(#theta) [GeV];Candidate Track Momentum (MCS) [GeV]");
    xseccalc2d.ProcessPlots();
    xseccalc2d.SetSmearingMatrix(S_4d);
    xseccalc2d.Smear();
    xseccalc2d.Draw();

    if (frac_covariance_matrix_muangle_mumom.GetNbinsX() > 1) {
      xseccalc2d.SetFractionalCovarianceMatrix(frac_covariance_matrix_muangle_mumom);
    }
    xseccalc2d.AddExtraDiagonalUncertainty(_extra_fractional_uncertainty);


    TH2D * xsec_muangle_mumom = xseccalc2d.ExtractCrossSection(bkg_names, "cos(#theta_{#mu})", "p_{#mu} [GeV]", "d^{2}#sigma/dcos(#theta_{#mu}dp_{#mu}) [10^{-38} cm^{2}/GeV]");
    TH2D * xsec_muangle_mumom_mc = xseccalc2d.GetMCCrossSection();


    file_out->cd();
    save_name = "xsec_muangle_mumom_" + _prefix;
    xsec_muangle_mumom->Write(save_name.c_str());
    save_name = "xsec_muangle_mumom_mc_" + _prefix;
    xsec_muangle_mumom_mc->Write(save_name.c_str());
    save_name = "frac_covariance_matrix_muangle_mumom_" + _prefix;
    frac_covariance_matrix_muangle_mumom.Write(save_name.c_str());
  }



  // file_out->Write();
  file_out->Close();


  gROOT->SetBatch(kFALSE);

  
  // *************************************
  // Doing beam-on minus beam-off subtraction
  // *************************************
  h_trklen_total_extbnb->Scale(scale_factor_extbnb);
  h_trklen_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_trklen_data = (TH1D*)h_trklen_total_bnbon->Clone("h_trklen_data");
  h_trklen_data->Sumw2();
  h_trklen_data->Add(h_trklen_total_extbnb, -1.);
  
  std::cout << std::endl;

  std::cout << "With the correct normalisation: " << std::endl;
  std::cout << "\t Number of BNBON events:   " << h_trklen_total_bnbon->Integral(0, h_trklen_total_bnbon->GetNbinsX()+1) << std::endl;
  std::cout << "\t Number of EXTBNB events:  " << h_trklen_total_extbnb->Integral(0, h_trklen_total_extbnb->GetNbinsX()+1) << std::endl;
  std::cout << "\t           BNBON - EXTBNB: " << h_trklen_total_bnbon->Integral(0, h_trklen_total_bnbon->GetNbinsX()+1) - h_trklen_total_extbnb->Integral(0, h_trklen_total_extbnb->GetNbinsX()+1) << std::endl;

/*
  h_trkmom_total_extbnb->Scale(scale_factor_extbnb);
  h_trkmom_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_trkmom_data = (TH1D*)h_trkmom_total_bnbon->Clone("h_trkmom_data");
  h_trkmom_data->Sumw2();
  h_trkmom_data->Add(h_trkmom_total_extbnb, -1.);
  */
  
  /*
  h_trktheta_total_extbnb->Scale(scale_factor_extbnb);
  h_trktheta_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_trktheta_data = (TH1D*)h_trktheta_total_bnbon->Clone("h_trktheta_data");
  h_trktheta_data->Sumw2();
  h_trktheta_data->Add(h_trktheta_total_extbnb, -1.);
  */

  h_trkmom_classic_total_extbnb->Scale(scale_factor_extbnb);
  h_trkmom_classic_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_trkmom_classic_data = (TH1D*)h_trkmom_classic_total_bnbon->Clone("h_trkmom_classic_data");
  h_trkmom_classic_data->Sumw2();
  h_trkmom_classic_data->Add(h_trkmom_classic_total_extbnb, -1.);
  
  h_trktheta_classic_total_extbnb->Scale(scale_factor_extbnb);
  h_trktheta_classic_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_trktheta_classic_data = (TH1D*)h_trktheta_classic_total_bnbon->Clone("h_trktheta_classic_data");
  h_trktheta_classic_data->Sumw2();
  h_trktheta_classic_data->Add(h_trktheta_classic_total_extbnb, -1.);

  h_trktheta_trkmom_total_extbnb->Scale(scale_factor_extbnb);
  h_trktheta_trkmom_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_trktheta_trkmom_data = (TH1D*)h_trktheta_trkmom_total_bnbon->Clone("h_trktheta_trkmom_data");
  h_trktheta_trkmom_data->Sumw2();
  h_trktheta_trkmom_data->Add(h_trktheta_trkmom_total_extbnb, -1.);

  h_trkphi_total_extbnb->Scale(scale_factor_extbnb);
  h_trkphi_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_trkphi_data = (TH1D*)h_trkphi_total_bnbon->Clone("h_trklen_data");
  h_trkphi_data->Sumw2();
  h_trkphi_data->Add(h_trkphi_total_extbnb, -1.);
  
  h_multpfp_total_extbnb->Scale(scale_factor_extbnb);
  h_multpfp_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_multpfp_data = (TH1D*)h_multpfp_total_bnbon->Clone("h_multpfp_data");
  h_multpfp_data->Sumw2();
  h_multpfp_data->Add(h_multpfp_total_extbnb, -1.);
  
  h_multtracktol_total_extbnb->Scale(scale_factor_extbnb);
  h_multtracktol_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_multtracktol_data = (TH1D*)h_multtracktol_total_bnbon->Clone("h_multtracktol_data");
  h_multtracktol_data->Sumw2();
  h_multtracktol_data->Add(h_multtracktol_total_extbnb, -1.);
  
  h_xdiff_b_total_extbnb->Scale(scale_factor_extbnb);
  h_xdiff_b_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_xdiff_b_data = (TH1D*)h_xdiff_b_total_bnbon->Clone("h_xdiff_b_data");
  h_xdiff_b_data->Sumw2();
  h_xdiff_b_data->Add(h_xdiff_b_total_extbnb, -1.);
  
  h_zdiff_b_total_extbnb->Scale(scale_factor_extbnb);
  h_zdiff_b_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_zdiff_b_data = (TH1D*)h_zdiff_b_total_bnbon->Clone("h_zdiff_b_data");
  h_zdiff_b_data->Sumw2();
  h_zdiff_b_data->Add(h_zdiff_b_total_extbnb, -1.);
  
  h_xdiff_total_extbnb->Scale(scale_factor_extbnb);
  h_xdiff_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_xdiff_data = (TH1D*)h_xdiff_total_bnbon->Clone("h_xdiff_data");
  h_xdiff_data->Sumw2();
  h_xdiff_data->Add(h_xdiff_total_extbnb, -1.);
  
  h_zdiff_total_extbnb->Scale(scale_factor_extbnb);
  h_zdiff_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_zdiff_data = (TH1D*)h_zdiff_total_bnbon->Clone("h_zdiff_data");
  h_zdiff_data->Sumw2();
  h_zdiff_data->Add(h_zdiff_total_extbnb, -1.);
  
  h_vtxx_total_extbnb->Scale(scale_factor_extbnb);
  h_vtxx_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_vtxx_data = (TH1D*)h_vtxx_total_bnbon->Clone("h_vtxx_data");
  h_vtxx_data->Sumw2();
  h_vtxx_data->Add(h_vtxx_total_extbnb, -1.);
  
  h_vtxy_total_extbnb->Scale(scale_factor_extbnb);
  h_vtxy_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_vtxy_data = (TH1D*)h_vtxy_total_bnbon->Clone("h_vtxx_data");
  h_vtxy_data->Sumw2();
  h_vtxy_data->Add(h_vtxy_total_extbnb, -1.);
  
  h_vtxz_total_extbnb->Scale(scale_factor_extbnb);
  h_vtxz_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_vtxz_data = (TH1D*)h_vtxz_total_bnbon->Clone("h_vtxx_data");
  h_vtxz_data->Sumw2();
  h_vtxz_data->Add(h_vtxz_total_extbnb, -1.);

  h_vtxz_upborder_total_extbnb->Scale(scale_factor_extbnb);
  h_vtxz_upborder_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_vtxz_upborder_data = (TH1D*)h_vtxz_upborder_total_bnbon->Clone("h_vtxz_upborder_data");
  h_vtxz_upborder_data->Sumw2();
  h_vtxz_upborder_data->Add(h_vtxz_upborder_total_extbnb, -1.);

  h_vtxx_upborder_total_extbnb->Scale(scale_factor_extbnb);
  h_vtxx_upborder_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_vtxx_upborder_data = (TH1D*)h_vtxx_upborder_total_bnbon->Clone("h_vtxx_upborder_data");
  h_vtxx_upborder_data->Sumw2();
  h_vtxx_upborder_data->Add(h_vtxx_upborder_total_extbnb, -1.);
  
  h_flsmatch_score_total_extbnb->Scale(scale_factor_extbnb);
  h_flsmatch_score_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_flsmatch_score_data = (TH1D*)h_flsmatch_score_total_bnbon->Clone("h_flsmatch_score_data");
  h_flsmatch_score_data->Sumw2();
  h_flsmatch_score_data->Add(h_flsmatch_score_total_extbnb, -1.);
  
  h_ntpcobj_total_extbnb->Scale(scale_factor_extbnb);
  h_ntpcobj_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_ntpcobj_data = (TH1D*)h_ntpcobj_total_bnbon->Clone("h_ntpcobj_data");
  h_ntpcobj_data->Sumw2();
  h_ntpcobj_data->Add(h_ntpcobj_total_extbnb, -1.);
  
  h_dqdx_trunc_total_extbnb->Scale(scale_factor_extbnb);
  h_dqdx_trunc_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_dqdx_trunc_data = (TH1D*)h_dqdx_trunc_total_bnbon->Clone("h_dqdx_trunc_data");
  h_dqdx_trunc_data->Sumw2();
  h_dqdx_trunc_data->Add(h_dqdx_trunc_total_extbnb, -1.);
  
  h_dqdx_trunc_length_extbnb->Scale(scale_factor_extbnb);
  h_dqdx_trunc_length_bnbon->Scale(scale_factor_bnbon);
  TH2D* h_dqdx_trunc_length_data = (TH2D*)h_dqdx_trunc_length_bnbon->Clone("h_dqdx_trunc_length_data");
  h_dqdx_trunc_length_data->Sumw2();
  h_dqdx_trunc_length_data->Add(h_dqdx_trunc_length_extbnb, -1.);
  
  h_deltax_2d_mc->Scale(scale_factor_mc_bnbcosmic);
  h_deltax_2d_bnbon->Scale(scale_factor_bnbon);
  h_deltax_2d_extbnb->Scale(scale_factor_extbnb);
  TH2D* h_deltax_2d_data = (TH2D*)h_deltax_2d_bnbon->Clone("h_deltax_2d_bnbon");
  h_deltax_2d_data->Sumw2();
  h_deltax_2d_data->Add(h_deltax_2d_extbnb, -1.);

  h_vtxcheck_angle_total_extbnb->Scale(scale_factor_extbnb);
  h_vtxcheck_angle_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_vtxcheck_angle_total_data = (TH1D*)h_vtxcheck_angle_total_bnbon->Clone("h_vtxcheck_angle_total_data");
  h_vtxcheck_angle_total_data->Sumw2();
  h_vtxcheck_angle_total_data->Add(h_vtxcheck_angle_total_extbnb, -1.);

  h_residuals_std_total_extbnb->Scale(scale_factor_extbnb);
  h_residuals_std_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_residuals_std_total_data = (TH1D*)h_residuals_std_total_bnbon->Clone("h_residuals_std_total_data");
  h_residuals_std_total_data->Sumw2();
  h_residuals_std_total_data->Add(h_residuals_std_total_extbnb, -1.);

  h_residuals_mean_total_extbnb->Scale(scale_factor_extbnb);
  h_residuals_mean_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_residuals_mean_total_data = (TH1D*)h_residuals_mean_total_bnbon->Clone("h_residuals_mean_total_data");
  h_residuals_mean_total_data->Sumw2();
  h_residuals_mean_total_data->Add(h_residuals_mean_total_extbnb, -1.);

  h_perc_used_hits_total_extbnb->Scale(scale_factor_extbnb);
  h_perc_used_hits_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_perc_used_hits_total_data = (TH1D*)h_perc_used_hits_total_bnbon->Clone("h_perc_used_hits_total_data");
  h_perc_used_hits_total_data->Sumw2();
  h_perc_used_hits_total_data->Add(h_perc_used_hits_total_extbnb, -1.);

  h_mom_mcs_length_total_extbnb->Scale(scale_factor_extbnb);
  h_mom_mcs_length_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_mom_mcs_length_total_data = (TH1D*)h_mom_mcs_length_total_bnbon->Clone("h_mom_mcs_length_total_data");
  h_mom_mcs_length_total_data->Sumw2();
  h_mom_mcs_length_total_data->Add(h_mom_mcs_length_total_extbnb, -1.);

  h_flsPe_wcut_extbnb->Scale(scale_factor_extbnb);
  h_flsPe_wcut_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_flsPe_wcut_data = (TH1D*)h_flsPe_wcut_bnbon->Clone("h_flsPe_wcut_bnbon");
  h_flsPe_wcut_data->Sumw2();
  h_flsPe_wcut_data->Add(h_flsPe_wcut_extbnb, -1.);


  // *************************************
  // Plotting data and MC distribution
  // *************************************
  
  TLegend* leg;
  TString name;
  TString outdir = analyser_outdir;
  
  TCanvas* canvas_trklen = new TCanvas("canvas_trklen", "canvas", 800, 700);
  THStack *hs_trklen_mc = new THStack("hs_trklen",";Candidate Track Length [cm]; Selected Events");
  hmap_trklen_mc["beam-off"] = h_trklen_total_extbnb;
  if (_fake_data_mode || _overlay_mode) h_trklen_total_bnbon->Add(h_trklen_total_extbnb);
  if (mc_dirt_file) {
    hmap_trklen_mc_dirt["cosmic"]->Scale(scale_factor_mc_dirt);
    hmap_trklen_mc_dirt["outfv"]->Scale(scale_factor_mc_dirt);
    hmap_trklen_mc_dirt["total"]->Scale(scale_factor_mc_dirt);
    hmap_trklen_mc["dirt_cosmic"] = hmap_trklen_mc_dirt["cosmic"];
    hmap_trklen_mc["dirt_outfv"] = hmap_trklen_mc_dirt["outfv"];
    hmap_trklen_mc["dirt"] = hmap_trklen_mc_dirt["total"];
  } else {
    TH1D * h_empty = (TH1D*) hmap_trktheta_trkmom_mc["total"]->Clone("empty2d");
    h_empty->Reset();
    hmap_trklen_mc["dirt"] = h_empty;
  }
  this->DrawDataMC(canvas_trklen, hs_trklen_mc, scale_factor_mc_bnbcosmic, _breakdown_plots, hmap_trklen_mc, h_trklen_total_bnbon, bnbon_pot_meas);

  
  std::cout << "\t             MC BNBCOSMIC: " << hmap_trklen_mc["total"]->Integral(0, hmap_trklen_mc["total"]->GetNbinsX()+1) << std::endl;
  std::cout << "\t             DATA (on-off): " << h_trklen_data->Integral(0, h_trklen_data->GetNbinsX()+1) << std::endl;
  

  double den = hmap_trklen_mc["signal"]->Integral() +
  hmap_trklen_mc["cosmic"]->Integral() +
  hmap_trklen_mc["outfv"]->Integral() +
  hmap_trklen_mc["nc"]->Integral() +
  hmap_trklen_mc["anumu"]->Integral() +
  hmap_trklen_mc["nue"]->Integral() +
  hmap_trklen_mc["beam-off"]->Integral();

  // std::cout << std::endl;
  
  // std::cout << "Number of events per channel:" << std::endl;
  // std::cout << "signal: " << hmap_trklen_mc["signal"]->Integral() << ", " << hmap_trklen_mc["signal"]->Integral() / den << std::endl;
  // std::cout << "cosmic: " << hmap_trklen_mc["cosmic"]->Integral() << ", " << hmap_trklen_mc["cosmic"]->Integral() / den << std::endl;
  // std::cout << "outfv: " << hmap_trklen_mc["outfv"]->Integral() << ", " << hmap_trklen_mc["outfv"]->Integral() / den << std::endl;
  // std::cout << "nc: " << hmap_trklen_mc["nc"]->Integral() << ", " << hmap_trklen_mc["nc"]->Integral() / den << std::endl;
  // std::cout << "anumu: " << hmap_trklen_mc["anumu"]->Integral() << ", " << hmap_trklen_mc["anumu"]->Integral() / den << std::endl;
  // std::cout << "nue: " << hmap_trklen_mc["nue"]->Integral() << ", " << hmap_trklen_mc["nue"]->Integral() / den << std::endl;
  // std::cout << "beam-off: " << hmap_trklen_mc["beam-off"]->Integral() << ", " << hmap_trklen_mc["beam-off"]->Integral() / den << std::endl;
  // std::cout << std::endl;
  // std::cout << "PURITY: " << hmap_trklen_mc["signal"]->Integral() / den << std::endl;
  
  std::cout << std::endl;

  std::cout << "Number of events per channel (including over/underflow bins):" << std::endl;

  int nbins = hmap_trklen_mc["signal"]->GetNbinsX();

  den = hmap_trklen_mc["signal"]->Integral(0, nbins+1) +
  hmap_trklen_mc["cosmic"]->Integral(0, nbins+1) +
  hmap_trklen_mc["outfv"]->Integral(0, nbins+1) +
  hmap_trklen_mc["nc"]->Integral(0, nbins+1) +
  hmap_trklen_mc["anumu"]->Integral(0, nbins+1) +
  hmap_trklen_mc["nue"]->Integral(0, nbins+1) +
  hmap_trklen_mc["dirt"]->Integral(0, nbins+1) +
  hmap_trklen_mc["beam-off"]->Integral(0, nbins+1);

  std::cout << "signal: " << hmap_trklen_mc["signal"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["signal"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << "cosmic: " << hmap_trklen_mc["cosmic"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["cosmic"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << "outfv: " << hmap_trklen_mc["outfv"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["outfv"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << "nc: " << hmap_trklen_mc["nc"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["nc"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << "anumu: " << hmap_trklen_mc["anumu"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["anumu"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << "nue: " << hmap_trklen_mc["nue"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["nue"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << "dirt: " << hmap_trklen_mc["dirt"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["dirt"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << "beam-off: " << hmap_trklen_mc["beam-off"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["beam-off"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << std::endl;
  std::cout << "PURITY: " << hmap_trklen_mc["signal"]->Integral(0, nbins+1) / den << std::endl;
  
  
  name = outdir + "trklen";
  canvas_trklen->SaveAs(name + ".pdf");
  canvas_trklen->SaveAs(name + ".C","C");


  // TCanvas* canvas_trkmom_classic_sub = new TCanvas("canvas_trkmom_classic_sub", "canvas", 800, 700);
  // THStack *hs_trkmom_classic_mc_sub = new THStack("hs_trkmom_classic_sub",";Candidate Track Momentum [GeV]; Selected Events");
  // this->DrawDataMC(canvas_trkmom_classic_sub, hs_trkmom_classic_mc_sub, scale_factor_mc_bnbcosmic, true, hmap_trkmom_classic_mc, h_trkmom_classic_data, bnbon_pot_meas);
  
  // name = outdir + "trkmomclassic_sub";
  // canvas_trkmom_classic_sub->SaveAs(name + ".pdf");
  // canvas_trkmom_classic_sub->SaveAs(name + ".C","C");




  TCanvas* canvas_trktheta_trkmom_poly = new TCanvas("canvas_trktheta_trkmom_poly", "canvas", 800, 700);

  hmap_trktheta_trkmom_poly_mc["signal"]->Draw("colz text");

  name = outdir + "trktheta_trkmom_poly_signal";
  canvas_trktheta_trkmom_poly->SaveAs(name + ".pdf");
  canvas_trktheta_trkmom_poly->SaveAs(name + ".C","C");

TCanvas* canvas_binnumber_poly = new TCanvas("canvas_binnumber_poly", "canvas", 800, 700);

  h_poly_binnumber->Draw("colz text");

  name = outdir + "binnumber_poly_signal";
  canvas_binnumber_poly->SaveAs(name + ".pdf");
  canvas_binnumber_poly->SaveAs(name + ".C","C");




  TCanvas* canvas_trkmom_classic = new TCanvas("canvas_trkmom_classic", "canvas", 800, 700);
  THStack *hs_trkmom_classic_mc = new THStack("hs_trkmom_classic",";p_{#mu}^{reco} [GeV]; Selected Events");
  if (mc_dirt_file) {
    hmap_trkmom_classic_mc_dirt["cosmic"]->Scale(scale_factor_mc_dirt);
    hmap_trkmom_classic_mc_dirt["outfv"]->Scale(scale_factor_mc_dirt);
    hmap_trkmom_classic_mc["dirt_cosmic"] = hmap_trkmom_classic_mc_dirt["cosmic"];
    hmap_trkmom_classic_mc["dirt_outfv"] = hmap_trkmom_classic_mc_dirt["outfv"];
  }
  if (!_beamoff_sub) hmap_trkmom_classic_mc["beam-off"] = h_trkmom_classic_total_extbnb;
  if (_fake_data_mode || _overlay_mode) h_trkmom_classic_total_bnbon->Add(h_trkmom_classic_total_extbnb);
  if (_beamoff_sub) this->DrawDataMC(canvas_trkmom_classic, hs_trkmom_classic_mc, scale_factor_mc_bnbcosmic, _breakdown_plots, hmap_trkmom_classic_mc, h_trkmom_classic_data, bnbon_pot_meas);
  else this->DrawDataMC(canvas_trkmom_classic, hs_trkmom_classic_mc, scale_factor_mc_bnbcosmic, _breakdown_plots, hmap_trkmom_classic_mc, h_trkmom_classic_total_bnbon, bnbon_pot_meas);

  name = outdir + "trkmomclassic";
  if (_beamoff_sub) name = outdir + "trkmomclassic_sub";
  canvas_trkmom_classic->SaveAs(name + ".pdf");
  canvas_trkmom_classic->SaveAs(name + ".C","C");


  TCanvas* canvas_trktheta_classic = new TCanvas("canvas_trktheta_classic", "canvas", 800, 700);
  THStack *hs_trktheta_classic_mc = new THStack("hs_trktheta_classic",";cos(#theta_{#mu}^{reco}); Selected Events");
  if (!_beamoff_sub) hmap_trktheta_classic_mc["beam-off"] = h_trktheta_classic_total_extbnb;
  if (_fake_data_mode || _overlay_mode) h_trktheta_classic_total_bnbon->Add(h_trktheta_classic_total_extbnb);
  if (mc_dirt_file) {
    hmap_trktheta_classic_mc_dirt["cosmic"]->Scale(scale_factor_mc_dirt);
    hmap_trktheta_classic_mc_dirt["outfv"]->Scale(scale_factor_mc_dirt);
    hmap_trktheta_classic_mc["dirt_cosmic"] = hmap_trktheta_classic_mc_dirt["cosmic"];
    hmap_trktheta_classic_mc["dirt_outfv"] = hmap_trktheta_classic_mc_dirt["outfv"];
  }
  if (_beamoff_sub) this->DrawDataMC(canvas_trktheta_classic, hs_trktheta_classic_mc, scale_factor_mc_bnbcosmic, _breakdown_plots, hmap_trktheta_classic_mc, h_trktheta_classic_data, bnbon_pot_meas);
  else this->DrawDataMC(canvas_trktheta_classic, hs_trktheta_classic_mc, scale_factor_mc_bnbcosmic, _breakdown_plots, hmap_trktheta_classic_mc, h_trktheta_classic_total_bnbon, bnbon_pot_meas);

  name = outdir + "trkthetaclassic";
  canvas_trktheta_classic->SaveAs(name + ".pdf");
  canvas_trktheta_classic->SaveAs(name + ".C","C");



  TCanvas* canvas_trkphi = new TCanvas("canvas_trkphi", "canvas", 800, 700);
  THStack *hs_trkphi_mc = new THStack("hs_trkphi",";#phi_{#mu}^{reco}; Selected Events");
  if (mc_dirt_file) {
    hmap_trkphi_mc_dirt["cosmic"]->Scale(scale_factor_mc_dirt);
    hmap_trkphi_mc_dirt["outfv"]->Scale(scale_factor_mc_dirt);
    hmap_trkphi_mc["dirt_cosmic"] = hmap_trkphi_mc_dirt["cosmic"];
    hmap_trkphi_mc["dirt_outfv"] = hmap_trkphi_mc_dirt["outfv"];
  }
  if (!_beamoff_sub) hmap_trkphi_mc["beam-off"] = h_trkphi_total_extbnb;
  if (_fake_data_mode || _overlay_mode) h_trkphi_total_bnbon->Add(h_trkphi_total_extbnb);
  if (_beamoff_sub) this->DrawDataMC(canvas_trkphi, hs_trkphi_mc, scale_factor_mc_bnbcosmic, _breakdown_plots, hmap_trkphi_mc, h_trkphi_data, bnbon_pot_meas);
  else this->DrawDataMC(canvas_trkphi, hs_trkphi_mc, scale_factor_mc_bnbcosmic, _breakdown_plots, hmap_trkphi_mc, h_trkphi_total_bnbon, bnbon_pot_meas);
  
  name = outdir + "trkphi";
  canvas_trkphi->SaveAs(name + ".pdf");
  canvas_trkphi->SaveAs(name + ".C","C");



  TH2D* test = new TH2D("test", "test", 20, -3.15, 3.15, 1, 0, 1);
  for (int i = 1; i < test->GetNbinsX()+1; i++) {
    test->SetBinContent(i, 1, h_trkphi_total_bnbon->GetBinContent(i));
  }

  TCanvas* canvas_trkphi_test = new TCanvas("canvas_trkphi_test", "canvas", 800, 700);
  test->Draw("LEGO1 CYL");
  name = outdir + "trkphi_test";
  canvas_trkphi_test->SaveAs(name + ".pdf");
  canvas_trkphi_test->SaveAs(name + ".C","C");
  
  TCanvas* canvas_multpfp = new TCanvas("canvas_multpfp", "canvas", 800, 700);
  THStack *hs_multpfp_mc = new THStack("hs_multpfp",";Particle Multiplicity; Selected Events");
  if (mc_dirt_file) {
    hmap_multpfp_mc_dirt["cosmic"]->Scale(scale_factor_mc_dirt);
    hmap_multpfp_mc_dirt["outfv"]->Scale(scale_factor_mc_dirt);
    hmap_multpfp_mc["dirt_cosmic"] = hmap_multpfp_mc_dirt["cosmic"];
    hmap_multpfp_mc["dirt_outfv"] = hmap_multpfp_mc_dirt["outfv"];
  }
  if (!_beamoff_sub) hmap_multpfp_mc["beam-off"] = h_multpfp_total_extbnb;
  if (_fake_data_mode || _overlay_mode) h_multpfp_total_bnbon->Add(h_multpfp_total_extbnb);
  if (_beamoff_sub) this->DrawDataMC(canvas_multpfp, hs_multpfp_mc, scale_factor_mc_bnbcosmic, _breakdown_plots, hmap_multpfp_mc, h_multpfp_data, bnbon_pot_meas);
  else this->DrawDataMC(canvas_multpfp, hs_multpfp_mc, scale_factor_mc_bnbcosmic, _breakdown_plots, hmap_multpfp_mc, h_multpfp_total_bnbon, bnbon_pot_meas);
  
  name = outdir + "multpfp";
  canvas_multpfp->SaveAs(name + ".pdf");
  canvas_multpfp->SaveAs(name + ".C","C");


  TCanvas* canvas_multtracktol = new TCanvas("canvas_multtracktol", "canvas", 800, 700);
  THStack *hs_multtracktol_mc = new THStack("hs_multtracktol",";Track Multiplicity; Selected Events");
  if (mc_dirt_file) {
    hmap_multtracktol_mc_dirt["cosmic"]->Scale(scale_factor_mc_dirt);
    hmap_multtracktol_mc_dirt["outfv"]->Scale(scale_factor_mc_dirt);
    hmap_multtracktol_mc["dirt_cosmic"] = hmap_multtracktol_mc_dirt["cosmic"];
    hmap_multtracktol_mc["dirt_outfv"] = hmap_multtracktol_mc_dirt["outfv"];
  }
  if (!_beamoff_sub) hmap_multtracktol_mc["beam-off"] = h_multtracktol_total_extbnb;
  if (_fake_data_mode || _overlay_mode) h_multtracktol_total_bnbon->Add(h_multtracktol_total_extbnb);
  if (_beamoff_sub) this->DrawDataMC(canvas_multtracktol, hs_multtracktol_mc, scale_factor_mc_bnbcosmic, _breakdown_plots, hmap_multtracktol_mc, h_multtracktol_data, bnbon_pot_meas);
  else this->DrawDataMC(canvas_multtracktol, hs_multtracktol_mc, scale_factor_mc_bnbcosmic, _breakdown_plots, hmap_multtracktol_mc, h_multtracktol_total_bnbon, bnbon_pot_meas);
  
  name = outdir + "multtracktol";
  canvas_multtracktol->SaveAs(name + ".pdf");
  canvas_multtracktol->SaveAs(name + ".C","C");

  
  TCanvas* canvas_xdiff_b = new TCanvas();
  THStack *hs_xdiff_b_mc = new THStack("hs_xdiff_b",";QLL x - TPC x [cm]; TPCObjects (Before Selection)");
  leg = PlottingTools::DrawTHStack2(hs_xdiff_b_mc, scale_factor_mc_bnbcosmic, true, hmap_xdiff_b_mc);
  PlottingTools::DrawDataHisto(h_xdiff_b_data);
  leg->AddEntry(h_xdiff_b_data,"Data (Beam-on - Beam-off)","lep");
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "xdiff_b";
  canvas_xdiff_b->SaveAs(name + ".pdf");
  canvas_xdiff_b->SaveAs(name + ".C","C");


  
  TCanvas* canvas_b_zdiff = new TCanvas();
  THStack *hs_zdiff_b_mc = new THStack("hs_zdiff_b",";Hypo z - Flash z [cm]; TPCObjects (Before Selection)");
  leg = PlottingTools::DrawTHStack2(hs_zdiff_b_mc, scale_factor_mc_bnbcosmic, true, hmap_zdiff_b_mc);
  PlottingTools::DrawDataHisto(h_zdiff_b_data);
  leg->AddEntry(h_zdiff_b_data,"Data (Beam-on - Beam-off)","lep");
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "zdiff_b";
  canvas_b_zdiff->SaveAs(name + ".pdf");
  canvas_b_zdiff->SaveAs(name + ".C","C");
  
  TCanvas* canvas_xdiff = new TCanvas();
  THStack *hs_xdiff_mc = new THStack("hs_xdiff",";QLL x - TPC x [cm]; Selected Events");
  leg = PlottingTools::DrawTHStack2(hs_xdiff_mc, scale_factor_mc_bnbcosmic, true, hmap_xdiff_mc);
  PlottingTools::DrawDataHisto(h_xdiff_data);
  leg->AddEntry(h_xdiff_data,"Data (Beam-on - Beam-off)","lep");
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "xdiff";
  canvas_xdiff->SaveAs(name + ".pdf");
  canvas_xdiff->SaveAs(name + ".C","C");



  TCanvas* canvas_zdiff = new TCanvas();
  THStack *hs_zdiff_mc = new THStack("hs_zdiff",";Hypo z - Flash z [cm]; Selected Events");
  leg = PlottingTools::DrawTHStack2(hs_zdiff_mc, scale_factor_mc_bnbcosmic, true, hmap_zdiff_mc);
  PlottingTools::DrawDataHisto(h_zdiff_data);
  leg->AddEntry(h_zdiff_data,"Data (Beam-on - Beam-off)","lep");
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "zdiff";
  canvas_zdiff->SaveAs(name + ".pdf");
  canvas_zdiff->SaveAs(name + ".C","C");



  TCanvas* canvas_vtxz_upborder = new TCanvas();
  THStack *hs_vtxz_upborder_mc = new THStack("hs_vtxz_upborder",";Candidate Neutrino Vertex Z [cm]; Selected Events");
  leg = PlottingTools::DrawTHStack2(hs_vtxz_upborder_mc, scale_factor_mc_bnbcosmic, true, hmap_vtxz_upborder_mc);
  PlottingTools::DrawDataHisto(h_vtxz_upborder_data);
  leg->AddEntry(h_vtxz_upborder_data,"Data (Beam-on - Beam-off)","lep");
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "vtxz_upborder";
  canvas_vtxz_upborder->SaveAs(name + ".pdf");
  canvas_vtxz_upborder->SaveAs(name + ".C","C");

  TCanvas* canvas_vtxx_upborder = new TCanvas();
  THStack *hs_vtxx_upborder_mc = new THStack("hs_vtxx_upborder",";Candidate Neutrino Vertex X [cm]; Selected Events");
  leg = PlottingTools::DrawTHStack2(hs_vtxx_upborder_mc, scale_factor_mc_bnbcosmic, true, hmap_vtxx_upborder_mc);
  PlottingTools::DrawDataHisto(h_vtxx_upborder_data);
  leg->AddEntry(h_vtxx_upborder_data,"Data (Beam-on - Beam-off)","lep");
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "vtxx_upborder";
  canvas_vtxx_upborder->SaveAs(name + ".pdf");
  canvas_vtxx_upborder->SaveAs(name + ".C","C");




  TCanvas* canvas_vtxcheck_angle = new TCanvas();
  THStack *hs_vtxcheck_angle_mc = new THStack("hs_vtxcheck_angle",";Angle [rad]; TPCObjects (Before Selection)");
  hmap_vtxcheck_angle_mc["beam-off"] = h_vtxcheck_angle_total_extbnb;
  if (mc_dirt_file) {
    hmap_vtxcheck_angle_mc_dirt["signal"]->Scale(scale_factor_mc_dirt);
    hmap_vtxcheck_angle_mc_dirt["background"]->Scale(scale_factor_mc_dirt);
    hmap_vtxcheck_angle_mc_dirt["total"]->Scale(scale_factor_mc_dirt);
    hmap_vtxcheck_angle_mc["signal"]->Add(hmap_vtxcheck_angle_mc_dirt["signal"]);
    hmap_vtxcheck_angle_mc["background"]->Add(hmap_vtxcheck_angle_mc_dirt["background"]);
    hmap_vtxcheck_angle_mc["total"]->Add(hmap_vtxcheck_angle_mc_dirt["total"]);

  }

  leg = PlottingTools::DrawTHStack2(hs_vtxcheck_angle_mc, scale_factor_mc_bnbcosmic, true, hmap_vtxcheck_angle_mc);
  leg->AddEntry(h_vtxcheck_angle_total_bnbon,"Data (Beam-on)","lep");  // DrawDataHisto(h_vtxx_total_bnbon);
  PlottingTools::DrawDataHisto(h_vtxcheck_angle_total_bnbon);
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "vtxcheck_angle";
  canvas_vtxcheck_angle->SaveAs(name + ".pdf");
  canvas_vtxcheck_angle->SaveAs(name + ".C","C");  





  TCanvas* canvas_residuals_std = new TCanvas();
  THStack *hs_residulas_std_mc = new THStack("hs_residulas_std",";#sigma_{r_{i}}; TPCObjects (Before Selection)");
  hmap_residuals_std_mc["beam-off"] = h_residuals_std_total_extbnb;
  if (mc_dirt_file) {
    hmap_residuals_std_mc_dirt["signal"]->Scale(scale_factor_mc_dirt);
    hmap_residuals_std_mc_dirt["background"]->Scale(scale_factor_mc_dirt);
    hmap_residuals_std_mc_dirt["total"]->Scale(scale_factor_mc_dirt);
    hmap_residuals_std_mc["signal"]->Add(hmap_residuals_std_mc_dirt["signal"]);
    hmap_residuals_std_mc["background"]->Add(hmap_residuals_std_mc_dirt["background"]);
    hmap_residuals_std_mc["total"]->Add(hmap_residuals_std_mc_dirt["total"]);
  }
  leg = PlottingTools::DrawTHStack2(hs_residulas_std_mc, scale_factor_mc_bnbcosmic, true, hmap_residuals_std_mc);
  leg->AddEntry(h_residuals_std_total_bnbon,"Data (Beam-on)","lep");  // DrawDataHisto(h_vtxx_total_bnbon);
  PlottingTools::DrawDataHisto(h_residuals_std_total_bnbon);
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "residulas_std";
  canvas_residuals_std->SaveAs(name + ".pdf");
  canvas_residuals_std->SaveAs(name + ".C","C");  





  TCanvas* canvas_residuals_mean = new TCanvas();
  THStack *hs_residulas_mean_mc = new THStack("hs_residulas_mean",";<r_{i}>; TPCObjects (Before Selection)");
  hmap_residuals_mean_mc["beam-off"] = h_residuals_mean_total_extbnb;
  if (mc_dirt_file) {
    hmap_residuals_mean_mc_dirt["signal"]->Scale(scale_factor_mc_dirt);
    hmap_residuals_mean_mc_dirt["background"]->Scale(scale_factor_mc_dirt);
    hmap_residuals_mean_mc_dirt["total"]->Scale(scale_factor_mc_dirt);
    hmap_residuals_mean_mc["signal"]->Add(hmap_residuals_mean_mc_dirt["signal"]);
    hmap_residuals_mean_mc["background"]->Add(hmap_residuals_mean_mc_dirt["background"]);
    hmap_residuals_mean_mc["total"]->Add(hmap_residuals_mean_mc_dirt["total"]);
  }
  leg = PlottingTools::DrawTHStack2(hs_residulas_mean_mc, scale_factor_mc_bnbcosmic, true, hmap_residuals_mean_mc);
  leg->AddEntry(h_residuals_mean_total_bnbon,"Data (Beam-on)","lep");  // DrawDataHisto(h_vtxx_total_bnbon);
  PlottingTools::DrawDataHisto(h_residuals_mean_total_bnbon);
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "residulas_mean";
  canvas_residuals_mean->SaveAs(name + ".pdf");
  canvas_residuals_mean->SaveAs(name + ".C","C");





  TCanvas* canvas_perc_used_hits = new TCanvas();
  THStack *hs_perc_used_hits_mc = new THStack("hs_residulas_mean",";Fraction of used hits in cluster; TPCObjects (Before Selection)");
  hmap_perc_used_hits_mc["beam-off"] = h_perc_used_hits_total_extbnb;
  if (mc_dirt_file) {
    hmap_perc_used_hits_mc_dirt["signal"]->Scale(scale_factor_mc_dirt);
    hmap_perc_used_hits_mc_dirt["background"]->Scale(scale_factor_mc_dirt);
    hmap_perc_used_hits_mc_dirt["total"]->Scale(scale_factor_mc_dirt);
    hmap_perc_used_hits_mc["signal"]->Add(hmap_perc_used_hits_mc_dirt["signal"]);
    hmap_perc_used_hits_mc["background"]->Add(hmap_perc_used_hits_mc_dirt["background"]);
    hmap_perc_used_hits_mc["total"]->Add(hmap_perc_used_hits_mc_dirt["total"]);
  }
  leg = PlottingTools::DrawTHStack2(hs_perc_used_hits_mc, scale_factor_mc_bnbcosmic, true, hmap_perc_used_hits_mc);
  leg->AddEntry(h_perc_used_hits_total_bnbon,"Data (Beam-on)","lep");  // DrawDataHisto(h_vtxx_total_bnbon);
  PlottingTools::DrawDataHisto(h_perc_used_hits_total_bnbon);
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "residulas_mean";
  canvas_perc_used_hits->SaveAs(name + ".pdf");
  canvas_perc_used_hits->SaveAs(name + ".C","C");

  
  TCanvas* canvas_mom_mcs_length = new TCanvas();
  THStack *hs_mom_mcs_length_mc = new THStack("hs_residulas_mean",";(MCS - Length) Reconstructed Momentum [GeV]; TPCObjects (Before Selection)");
  hmap_mom_mcs_length_mc["beam-off"] = h_mom_mcs_length_total_extbnb;
  if (mc_dirt_file) {
    hmap_mom_mcs_length_mc_dirt["signal"]->Scale(scale_factor_mc_dirt);
    hmap_mom_mcs_length_mc_dirt["background"]->Scale(scale_factor_mc_dirt);
    hmap_mom_mcs_length_mc_dirt["total"]->Scale(scale_factor_mc_dirt);
    hmap_mom_mcs_length_mc["signal"]->Add(hmap_mom_mcs_length_mc_dirt["signal"]);
    hmap_mom_mcs_length_mc["background"]->Add(hmap_mom_mcs_length_mc_dirt["background"]);
    hmap_mom_mcs_length_mc["total"]->Add(hmap_mom_mcs_length_mc_dirt["total"]);
  }
  leg = PlottingTools::DrawTHStack2(hs_mom_mcs_length_mc, scale_factor_mc_bnbcosmic, true, hmap_mom_mcs_length_mc);
  leg->AddEntry(h_mom_mcs_length_total_bnbon,"Data (Beam-on)","lep");  // DrawDataHisto(h_vtxx_total_bnbon);
  PlottingTools::DrawDataHisto(h_mom_mcs_length_total_bnbon);
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "mom_mcs_length";
  canvas_mom_mcs_length->SaveAs(name + ".pdf");
  canvas_mom_mcs_length->SaveAs(name + ".C","C");
  
  
  TCanvas* canvas_vtxx = new TCanvas("canvas_vtxx", "canvas", 800, 700);
  THStack *hs_vtxx_mc = new THStack("hs_vtxx",";Candidate Neutrino Vertex X [cm]; Selected Events");
  hmap_vtxx_mc["beam-off"] = h_vtxx_total_extbnb;
  if (mc_dirt_file) {
    hmap_vtxx_mc_dirt["signal"]->Scale(scale_factor_mc_dirt);
    hmap_vtxx_mc_dirt["background"]->Scale(scale_factor_mc_dirt);
    hmap_vtxx_mc_dirt["total"]->Scale(scale_factor_mc_dirt);
    hmap_vtxx_mc["dirt"] = hmap_vtxx_mc_dirt["total"];
    // hmap_vtxx_mc["signal"]->Add(hmap_vtxx_mc_dirt["signal"]);
    // hmap_vtxx_mc["background"]->Add(hmap_vtxx_mc_dirt["background"]);
    // hmap_vtxx_mc["total"]->Add(hmap_vtxx_mc_dirt["total"]);
  }
  this->DrawDataMC(canvas_vtxx, hs_vtxx_mc, scale_factor_mc_bnbcosmic, true, hmap_vtxx_mc, h_vtxx_total_bnbon, bnbon_pot_meas);

  name = outdir + "vtxx";
  canvas_vtxx->SaveAs(name + ".pdf");
  canvas_vtxx->SaveAs(name + ".C","C");

   
  TCanvas* canvas_vtxy = new TCanvas("canvas_vtxy", "canvas", 800, 700);
  THStack *hs_vtxy_mc = new THStack("hs_vtxy",";Candidate Neutrino Vertex Y [cm]; Selected Events");
  if (mc_dirt_file) {
    hmap_vtxy_mc_dirt["signal"]->Scale(scale_factor_mc_dirt);
    hmap_vtxy_mc_dirt["background"]->Scale(scale_factor_mc_dirt);
    hmap_vtxy_mc_dirt["total"]->Scale(scale_factor_mc_dirt);
    hmap_vtxy_mc["dirt"] = hmap_vtxy_mc_dirt["total"];
    // hmap_vtxy_mc["signal"]->Add(hmap_vtxy_mc_dirt["signal"]);
    // hmap_vtxy_mc["background"]->Add(hmap_vtxy_mc_dirt["background"]);
    // hmap_vtxy_mc["total"]->Add(hmap_vtxy_mc_dirt["total"]);
  }
  hmap_vtxy_mc["beam-off"] = h_vtxy_total_extbnb;
  this->DrawDataMC(canvas_vtxy, hs_vtxy_mc, scale_factor_mc_bnbcosmic, true, hmap_vtxy_mc, h_vtxy_total_bnbon, bnbon_pot_meas);
  
  name = outdir + "vtxy";
  canvas_vtxy->SaveAs(name + ".pdf");
  canvas_vtxy->SaveAs(name + ".C","C");
  
  TCanvas* canvas_vtxz = new TCanvas("canvas_vtxz", "canvas", 800, 700);
  THStack *hs_vtxz_mc = new THStack("hs_vtxz",";Candidate Neutrino Vertex Z [cm]; Selected Events");
  hmap_vtxz_mc["beam-off"] = h_vtxz_total_extbnb;
  if (mc_dirt_file) {
    hmap_vtxz_mc_dirt["signal"]->Scale(scale_factor_mc_dirt);
    hmap_vtxz_mc_dirt["background"]->Scale(scale_factor_mc_dirt);
    hmap_vtxz_mc_dirt["total"]->Scale(scale_factor_mc_dirt);
    hmap_vtxz_mc["dirt"] = hmap_vtxz_mc_dirt["total"];
    // hmap_vtxz_mc["signal"]->Add(hmap_vtxz_mc_dirt["signal"]);
    // hmap_vtxz_mc["background"]->Add(hmap_vtxz_mc_dirt["background"]);
    // hmap_vtxz_mc["total"]->Add(hmap_vtxz_mc_dirt["total"]);
  }
  this->DrawDataMC(canvas_vtxz, hs_vtxz_mc, scale_factor_mc_bnbcosmic, true, hmap_vtxz_mc, h_vtxz_total_bnbon, bnbon_pot_meas);

  name = outdir + "vtxz";
  canvas_vtxz->SaveAs(name + ".pdf");
  canvas_vtxz->SaveAs(name + ".C","C");
  
  TCanvas* canvas_flsmatch_score = new TCanvas("canvas_flsmatch_score", "canvas", 800, 700);
  THStack *hs_flsmatch_score_mc = new THStack("hs_flsmatch_score",";1/(-log(L_{1})); Selected Events");
  hmap_flsmatch_score_mc["beam-off"] = h_flsmatch_score_total_extbnb;
  if (mc_dirt_file) {
    hmap_flsmatch_score_mc_dirt["signal"]->Scale(scale_factor_mc_dirt);
    hmap_flsmatch_score_mc_dirt["background"]->Scale(scale_factor_mc_dirt);
    hmap_flsmatch_score_mc_dirt["total"]->Scale(scale_factor_mc_dirt);
    // hmap_flsmatch_score_mc["signal"]->Add(hmap_flsmatch_score_mc_dirt["signal"]);
    // hmap_flsmatch_score_mc["background"]->Add(hmap_flsmatch_score_mc_dirt["background"]);
    // hmap_flsmatch_score_mc["total"]->Add(hmap_flsmatch_score_mc_dirt["total"]);
  }
  this->DrawDataMC(canvas_flsmatch_score, hs_flsmatch_score_mc, scale_factor_mc_bnbcosmic, true, hmap_flsmatch_score_mc, h_flsmatch_score_total_bnbon, bnbon_pot_meas);  
  name = outdir + "flsmatch_score";
  canvas_flsmatch_score->SaveAs(name + ".pdf");
  canvas_flsmatch_score->SaveAs(name + ".C","C");


  TCanvas* canvas_flsmatch_score_second = new TCanvas("canvas_flsmatch_score_second", "canvas", 800, 700);
  THStack *hs_flsmatch_score_second_mc = new THStack("hs_flsmatch_score_second",";1/(-log(L_{2})); Selected Events");
  hmap_flsmatch_score_second_mc["beam-off"] = h_flsmatch_score_second_total_extbnb;
  if (mc_dirt_file) {
    hmap_flsmatch_score_second_mc_dirt["signal"]->Scale(scale_factor_mc_dirt);
    hmap_flsmatch_score_second_mc_dirt["background"]->Scale(scale_factor_mc_dirt);
    hmap_flsmatch_score_second_mc_dirt["total"]->Scale(scale_factor_mc_dirt);
    hmap_flsmatch_score_second_mc["signal"]->Add(hmap_flsmatch_score_second_mc_dirt["signal"]);
    hmap_flsmatch_score_second_mc["background"]->Add(hmap_flsmatch_score_second_mc_dirt["background"]);
    hmap_flsmatch_score_second_mc["total"]->Add(hmap_flsmatch_score_second_mc_dirt["total"]);
  }
  this->DrawDataMC(canvas_flsmatch_score_second, hs_flsmatch_score_second_mc, scale_factor_mc_bnbcosmic, true, hmap_flsmatch_score_second_mc, h_flsmatch_score_second_total_bnbon, bnbon_pot_meas);
  name = outdir + "flsmatch_score_second";
  canvas_flsmatch_score_second->SaveAs(name + ".pdf");
  canvas_flsmatch_score_second->SaveAs(name + ".C","C");


  TCanvas* canvas_flsmatch_score_difference = new TCanvas("canvas_flsmatch_score_difference", "canvas", 800, 700);
  THStack *hs_flsmatch_score_difference_mc = new THStack("hs_flsmatch_score_difference",";1/(-log(L_{1})) - 1/(-log(L_{2})); Selected Events");
  hmap_flsmatch_score_difference_mc["beam-off"] = h_flsmatch_score_difference_total_extbnb;
  if (mc_dirt_file) {
    hmap_flsmatch_score_difference_mc_dirt["signal"]->Scale(scale_factor_mc_dirt);
    hmap_flsmatch_score_difference_mc_dirt["background"]->Scale(scale_factor_mc_dirt);
    hmap_flsmatch_score_difference_mc_dirt["total"]->Scale(scale_factor_mc_dirt);
    hmap_flsmatch_score_difference_mc["signal"]->Add(hmap_flsmatch_score_difference_mc_dirt["signal"]);
    hmap_flsmatch_score_difference_mc["background"]->Add(hmap_flsmatch_score_difference_mc_dirt["background"]);
    hmap_flsmatch_score_difference_mc["total"]->Add(hmap_flsmatch_score_difference_mc_dirt["total"]);
  }
  this->DrawDataMC(canvas_flsmatch_score_difference, hs_flsmatch_score_difference_mc, scale_factor_mc_bnbcosmic, true, hmap_flsmatch_score_difference_mc, h_flsmatch_score_difference_total_bnbon, bnbon_pot_meas);
  name = outdir + "flsmatch_score_difference";
  canvas_flsmatch_score_difference->SaveAs(name + ".pdf");
  canvas_flsmatch_score_difference->SaveAs(name + ".C","C");
  

  TCanvas* canvas_ntpcobj = new TCanvas("canvas_ntpcobj", "canvas", 800, 700);
  THStack *hs_ntpcobj_mc = new THStack("hs_ntpcobj",";Number of TPCObjects per Event;");
  hmap_ntpcobj_mc["beam-off"] = h_ntpcobj_total_extbnb;
  if (mc_dirt_file) {
    hmap_ntpcobj_mc_dirt["signal"]->Scale(scale_factor_mc_dirt);
    hmap_ntpcobj_mc_dirt["background"]->Scale(scale_factor_mc_dirt);
    hmap_ntpcobj_mc_dirt["total"]->Scale(scale_factor_mc_dirt);
    hmap_ntpcobj_mc["signal"]->Add(hmap_ntpcobj_mc_dirt["signal"]);
    hmap_ntpcobj_mc["background"]->Add(hmap_ntpcobj_mc_dirt["background"]);
    hmap_ntpcobj_mc["total"]->Add(hmap_ntpcobj_mc_dirt["total"]);
  }
  this->DrawDataMC(canvas_ntpcobj, hs_ntpcobj_mc, scale_factor_mc_bnbcosmic, true, hmap_ntpcobj_mc, h_ntpcobj_total_bnbon, bnbon_pot_meas);
  name = outdir + "ntpcobj";
  canvas_ntpcobj->SaveAs(name + ".pdf");
  canvas_ntpcobj->SaveAs(name + ".C","C");

  // TCanvas* canvas_ntpcobj = new TCanvas();
  // THStack *hs_ntpcobj_mc = new THStack("hs_ntpcobj",";Number of TPCObjects per events; ");
  // leg = PlottingTools::DrawTHStack2(hs_ntpcobj_mc, scale_factor_mc_bnbcosmic, true, hmap_ntpcobj_mc);
  // PlottingTools::DrawDataHisto(h_ntpcobj_data);
  // leg->AddEntry(h_ntpcobj_data,"Data (Beam-on - Beam-off)","lep");
  // PlottingTools::DrawPOT(bnbon_pot_meas);
  // leg->Draw();
  
  // name = outdir + "ntpcobj";
  // canvas_ntpcobj->SaveAs(name + ".pdf");
  // canvas_ntpcobj->SaveAs(name + ".C","C");
  
  TCanvas* canvas_dqdx_trunc = new TCanvas();
  THStack *hs_dqdx_trunc_mc = new THStack("hs_dqdx_trunc",";Candidate Track <dQ/dx>_{trunc} [e^{-}/cm];");
  leg = PlottingTools::DrawTHStack3(hs_dqdx_trunc_mc, scale_factor_mc_bnbcosmic, true, hmap_dqdx_trunc_mc);
  PlottingTools::DrawDataHisto(h_dqdx_trunc_data);
  leg->AddEntry(h_dqdx_trunc_data,"Data (Beam-on - Beam-off)","lep");
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();

  name = outdir + "dqdx_trunc";
  canvas_dqdx_trunc->SaveAs(name + ".pdf");
  canvas_dqdx_trunc->SaveAs(name + ".C","C");
  
  TCanvas* canvas_dqdx_trunc_length_mc = new TCanvas();
  h_dqdx_trunc_length_mc->Draw("colz");
 
  name = outdir + "dqdx_trunc_length_mc";
  canvas_dqdx_trunc_length_mc->SaveAs(name + ".pdf");
  canvas_dqdx_trunc_length_mc->SaveAs(name + ".C","C");
 
  TCanvas* canvas_dqdx_trunc_length_data = new TCanvas();
  h_dqdx_trunc_length_data->Draw("colz");

  name = outdir + "dqdx_trunc_length_data";
  canvas_dqdx_trunc_length_data->SaveAs(name + ".pdf");
  canvas_dqdx_trunc_length_data->SaveAs(name + ".C","C");


  TCanvas* canvas_flsPe_wcut_data = new TCanvas();
  h_flsPe_wcut_mc->Scale(scale_factor_mc_bnbcosmic);
  h_flsPe_wcut_mc->Draw("histo");
  h_flsPe_wcut_data->Draw("E1 same");

  name = outdir + "flsPe_wcut";
  canvas_flsPe_wcut_data->SaveAs(name + ".pdf");
  canvas_flsPe_wcut_data->SaveAs(name + ".C","C");
 

  
  // *************************************
  // Other data/MC distributions
  // *************************************
  TH1D* h_flsTime_mc = (TH1D*)mc_bnbcosmic_file->Get("h_flsTime_wcut");
  TH1D* h_flsTime_bnbon = (TH1D*)bnbon_file->Get("h_flsTime_wcut");
  TH1D* h_flsTime_extbnb = (TH1D*)extbnb_file->Get("h_flsTime_wcut");
  h_flsTime_extbnb->Scale(scale_factor_extbnb);
  h_flsTime_bnbon->Scale(scale_factor_bnbon);
  h_flsTime_mc->Scale(scale_factor_mc_bnbcosmic);
  TH1D* h_flsTime_data = (TH1D*)h_flsTime_bnbon->Clone("h_flsTime_data");
  h_flsTime_data->Sumw2();
  h_flsTime_data->Add(h_flsTime_extbnb, -1.);
  
  new TCanvas();
  h_flsTime_mc->Draw("histo");
  h_flsTime_data->SetLineColor(kRed);
  h_flsTime_data->SetMarkerColor(kRed);
  PlottingTools::DrawDataHisto(h_flsTime_data);
  TLegend* leg2;
  leg2 = new TLegend(0.13,0.69,0.45,0.87,NULL,"brNDC");
  leg2->AddEntry(h_flsTime_mc,"MC BNB+COSMIC","l");
  leg2->AddEntry(h_flsTime_data,"Data (Beam-on - Beam-off)","lep");
  leg2->Draw();
  PlottingTools::DrawPOT(bnbon_pot_meas);

  std::cout << "Flash Plot - MC Integral: " << h_flsTime_mc->Integral() << std::endl;
  std::cout << "Flash Plot - Data (on-off) Integral: " << h_flsTime_data->Integral() << std::endl;
  std::cout << "Flash Plot - DATA/MC: " << h_flsTime_data->Integral() / h_flsTime_mc->Integral() << std::endl;
  std::cout << "Flash Plot - On/(Off+MC): " << h_flsTime_bnbon->Integral() / (h_flsTime_extbnb->Integral() + h_flsTime_mc->Integral())<< std::endl;

  std::cout << std::endl;
  std::cout << "Flash lost in 3.2 to 3.3 us in data: " << h_flsTime_data->Integral(h_flsTime_data->GetXaxis()->FindBin(3.2), h_flsTime_data->GetXaxis()->FindBin(3.29999)) / h_flsTime_data->Integral(h_flsTime_data->GetXaxis()->FindBin(3.3), h_flsTime_data->GetXaxis()->FindBin(4.9))  << std::endl;
  std::cout << "Flash lost in 4.9 to 5.0 us in data: " << h_flsTime_data->Integral(h_flsTime_data->GetXaxis()->FindBin(4.9001), h_flsTime_data->GetXaxis()->FindBin(5.0)) / h_flsTime_data->Integral(h_flsTime_data->GetXaxis()->FindBin(3.3), h_flsTime_data->GetXaxis()->FindBin(4.9))  << std::endl;
  std::cout << "Flash lost in 4.9 to 5.0 us and in 3.2 to 3.3 us in data: " << (h_flsTime_data->Integral(h_flsTime_data->GetXaxis()->FindBin(4.9001), h_flsTime_data->GetXaxis()->FindBin(5.0)) + h_flsTime_data->Integral(h_flsTime_data->GetXaxis()->FindBin(3.2), h_flsTime_data->GetXaxis()->FindBin(3.29999))) / h_flsTime_data->Integral(h_flsTime_data->GetXaxis()->FindBin(3.3), h_flsTime_data->GetXaxis()->FindBin(4.9))  << std::endl;
  std::cout << "In MC, in 4.8 to 4.85 us, we loose: " << h_flsTime_mc->Integral(h_flsTime_data->GetXaxis()->FindBin(4.8001), h_flsTime_data->GetXaxis()->FindBin(4.85)) /h_flsTime_mc->Integral(h_flsTime_data->GetXaxis()->FindBin(3.2), h_flsTime_data->GetXaxis()->FindBin(4.8)) << std::endl;

  new TCanvas();
  h_flsTime_mc->SetLineColor(kBlack);
  h_flsTime_bnbon->SetLineColor(kRed);
  h_flsTime_extbnb->SetLineColor(kBlue);
  h_flsTime_mc->Draw("histo");
  h_flsTime_bnbon->Draw("histo same");
  h_flsTime_extbnb->Draw("histo same");
  TLegend* leg3;
  leg3 = new TLegend(0.13,0.69,0.45,0.87,NULL,"brNDC");
  leg3->AddEntry(h_flsTime_mc,"MC BNB+COSMIC","l");
  leg3->AddEntry(h_flsTime_bnbon,"DATA BNBON","l");
  leg3->AddEntry(h_flsTime_extbnb,"DATA EXTBNB","l");
  leg3->Draw();
  PlottingTools::DrawPOT(bnbon_pot_meas);

  
  new TCanvas();
  h_deltax_2d_mc->Draw("colz");
  new TCanvas();
  h_deltax_2d_data->Draw("colz");





  // *************************************
  // MC distributions only
  // *************************************

  TCanvas* canvas_mctruth_nuenergy = new TCanvas();
  THStack *hs_mctruth_nuenergy = new THStack("hs_mctruth_nuenergy",";True Neutrino Energy [GeV];Selected Signal Events");
  this->PlotMCTHStack(hs_mctruth_nuenergy, hmap_mctruth_nuenergy_mc, scale_factor_mc_bnbcosmic);
  PlottingTools::DrawSimPOT(mc_pot_sim, bnbon_pot_meas);
  name = outdir + "mctruth_nuenergy_sel";
  canvas_mctruth_nuenergy->SaveAs(name + ".pdf");
  canvas_mctruth_nuenergy->SaveAs(name + ".C","C");

  TCanvas* canvas_mctruth_mumom = new TCanvas();
  THStack *hs_mctruth_mumom = new THStack("hs_mctruth_mumom",";True Muon Momentum [GeV];Selected Signal Events");
  this->PlotMCTHStack(hs_mctruth_mumom, hmap_mctruth_mumom_mc, scale_factor_mc_bnbcosmic);
  PlottingTools::DrawSimPOT(mc_pot_sim, bnbon_pot_meas);
  name = outdir + "mctruth_mumom_sel";
  canvas_mctruth_mumom->SaveAs(name + ".pdf");
  canvas_mctruth_mumom->SaveAs(name + ".C","C");

  TCanvas* canvas_mctruth_mucostheta = new TCanvas();
  THStack *hs_mctruth_mucostheta = new THStack("hs_mctruth_mucostheta",";True Muon cos(#theta);Selected Signal Events");
  this->PlotMCTHStack(hs_mctruth_mucostheta, hmap_mctruth_mucostheta_mc, scale_factor_mc_bnbcosmic);
  PlottingTools::DrawSimPOT(mc_pot_sim, bnbon_pot_meas);
  name = outdir + "mctruth_mucostheta_sel";
  canvas_mctruth_mucostheta->SaveAs(name + ".pdf");
  canvas_mctruth_mucostheta->SaveAs(name + ".C","C");

  TCanvas* canvas_mctruth_muphi = new TCanvas();
  THStack *hs_mctruth_muphi = new THStack("hs_mctruth_muphi",";True Muon #phi;Selected Signal Events");
  this->PlotMCTHStack(hs_mctruth_muphi, hmap_mctruth_muphi_mc, scale_factor_mc_bnbcosmic);
  PlottingTools::DrawSimPOT(mc_pot_sim, bnbon_pot_meas);
  name = outdir + "mctruth_muphi_sel";
  canvas_mctruth_muphi->SaveAs(name + ".pdf");
  canvas_mctruth_muphi->SaveAs(name + ".C","C");



  TCanvas* canvas_mctruth_nuenergy_gen = new TCanvas();
  THStack *hs_mctruth_nuenergy_gen = new THStack("hs_mctruth_nuenergy_gen",";True Neutrino Energy [GeV];Generated Signal Events");
  this->PlotMCTHStack(hs_mctruth_nuenergy_gen, hmap_mctruth_nuenergy_gen_mc, scale_factor_mc_bnbcosmic);
  PlottingTools::DrawSimPOT(mc_pot_sim, bnbon_pot_meas);
  name = outdir + "mctruth_nuenergy_gen";
  canvas_mctruth_nuenergy_gen->SaveAs(name + ".pdf");
  canvas_mctruth_nuenergy_gen->SaveAs(name + ".C","C");

  TCanvas* canvas_mctruth_mumom_gen = new TCanvas();
  THStack *hs_mctruth_mumom_gen = new THStack("hs_mctruth_mumom_gen",";True Muon Momentum [GeV];Generated Signal Events");
  this->PlotMCTHStack(hs_mctruth_mumom_gen, hmap_mctruth_mumom_gen_mc, scale_factor_mc_bnbcosmic);
  PlottingTools::DrawSimPOT(mc_pot_sim, bnbon_pot_meas);
  name = outdir + "mctruth_mumom_gen";
  canvas_mctruth_mumom_gen->SaveAs(name + ".pdf");
  canvas_mctruth_mumom_gen->SaveAs(name + ".C","C");

  TCanvas* canvas_mctruth_mucostheta_gen = new TCanvas();
  THStack *hs_mctruth_mucostheta_gen = new THStack("hs_mctruth_mucostheta_gen",";True Muon cos(#theta);Generated Signal Events");
  this->PlotMCTHStack(hs_mctruth_mucostheta_gen, hmap_mctruth_mucostheta_gen_mc, scale_factor_mc_bnbcosmic);
  PlottingTools::DrawSimPOT(mc_pot_sim, bnbon_pot_meas);
  name = outdir + "mctruth_mucostheta_gen";
  canvas_mctruth_mucostheta_gen->SaveAs(name + ".pdf");
  canvas_mctruth_mucostheta_gen->SaveAs(name + ".C","C");

  TCanvas* canvas_mctruth_muphi_gen = new TCanvas();
  THStack *hs_mctruth_muphi_gen = new THStack("hs_mctruth_muphi_gen",";True Muon #phi;Generated Signal Events");
  this->PlotMCTHStack(hs_mctruth_muphi_gen, hmap_mctruth_muphi_gen_mc, scale_factor_mc_bnbcosmic);
  PlottingTools::DrawSimPOT(mc_pot_sim, bnbon_pot_meas);
  name = outdir + "mctruth_muphi_gen";
  canvas_mctruth_muphi_gen->SaveAs(name + ".pdf");
  canvas_mctruth_muphi_gen->SaveAs(name + ".C","C");




  
  // Computing time
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << endl << endl << "Computing time: " << elapsed_secs << " seconds = " << elapsed_secs/60. << " minutes." << endl << endl;
  
  //rootapp->Run();
  //rootapp->Terminate(0);
  
  return;
	}

	void Analyse::DrawDataMC(TCanvas *c,
		                       THStack *hs_mc, 
		                       double scale_factor_mc_bnbcosmic, 
		                       bool breakdown_plots, 
		                       std::map<std::string,TH1D*> hmap_mc, 
		                       TH1D* h_data_bnbon,
		                       double bnbon_pot_meas) 
	{
		// Define the Canvas
    //TCanvas *c = new TCanvas("c", "canvas", 800, 800);

    // Upper plot will be in pad1
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.25, 1, 1.0);
    pad1->SetBottomMargin(0); // Upper and lower plot are joined
    pad1->SetRightMargin(0.06);
    pad1->SetLeftMargin(0.13);
    pad1->SetGridx();         // Vertical grid
    pad1->Draw();             // Draw the upper pad: pad1
    pad1->cd();               // pad1 becomes the current pad
    //if (variable == 0 || variable == 1) histo_p1->SetMaximum(1.);

    // histo_p1->Draw("histo");               // Draw h1
    // histo->Draw("histo same");         // Draw h2 on top of h1
    // histo_m1->Draw("histo same");

    TLegend * leg;
    if (hmap_mc.find("outfv") != hmap_mc.end()) {
      leg = PlottingTools::DrawTHStack(hs_mc, scale_factor_mc_bnbcosmic, breakdown_plots, hmap_mc);
    } else {
    	leg = PlottingTools::DrawTHStack2(hs_mc, scale_factor_mc_bnbcosmic, breakdown_plots, hmap_mc);
    }
    PlottingTools::DrawDataHisto(h_data_bnbon);

    leg->AddEntry(hmap_mc["total"],"Stat. Unc.","f");
    if (hmap_mc["beam-off"] != NULL) {
      if (_overlay_mode) {
        leg->AddEntry(h_data_bnbon,"Overlay + Beam-off","lep");
      } else {
        leg->AddEntry(h_data_bnbon,"Data (Beam-on, stat. only)","lep");
      }
    } else {
      leg->AddEntry(h_data_bnbon,"Data (Beam-on - Beam-off)","lep");
    }
    leg->Draw();

    PlottingTools::DrawPOTRatio(bnbon_pot_meas);
    if (_overlay_mode) PlottingTools::DrawOverlay();
    else PlottingTools::DrawPreliminary();



    // Do not draw the Y axis label on the upper plot and redraw a small
    // axis instead, in order to avoid the first label (0) to be clipped.
    // hs_mc->GetYaxis()->SetLabelSize(0.);
    // TGaxis *axis = new TGaxis( -5, 0.1, -5, 4000, 0.1,4000,510,"");
    // axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    // axis->SetLabelSize(15);
    // axis->Draw();
    hs_mc->SetMinimum(0.01);
    hs_mc->GetYaxis()->SetTitleOffset(1.18);
    hs_mc->GetYaxis()->CenterTitle(true);

    double max_up = hmap_mc["total"]->GetBinContent(hmap_mc["total"]->GetMaximumBin());
    hs_mc->SetMaximum(max_up+max_up*0.4);

    // lower plot will be in pad
    c->cd();          // Go back to the main canvas before defining pad2
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.01, 1, 0.25);
    pad2->SetTopMargin(0);
    pad2->SetFrameFillStyle(4000);
    pad2->SetBottomMargin(0.35);
    pad2->SetRightMargin(0.06);
    pad2->SetLeftMargin(0.13);
    pad2->SetGridx(); // vertical grid
    //pad2->SetGridy(); // orizontal grid
    pad2->Draw();
    pad2->cd();       // pad2 becomes the current pad

    // Define the first ratio plot
    TH1D *ratio = (TH1D*)h_data_bnbon->Clone("ratio");
    //ratio->SetMinimum(0.92);  // Define Y ..
    //ratio->SetMaximum(1.08); // .. range
    //ratio->Sumw2();
    ratio->SetStats(0);      // No statistics on lower plot
    ratio->Divide(hmap_mc["total"]);
    ratio->SetLineWidth(2);
    ratio->SetLineColor(kBlack);
    ratio->SetMarkerStyle(kFullCircle);
    ratio->SetMarkerSize(0.6);

    ratio->GetYaxis()->SetTitle("Ratio");
    ratio->GetXaxis()->SetTitle(hs_mc->GetXaxis()->GetTitle());

    ratio->GetXaxis()->CenterTitle(true);
    ratio->GetXaxis()->SetLabelFont(42);
    ratio->GetXaxis()->SetLabelSize(0.12);
    ratio->GetXaxis()->SetTitleSize(0.18);
    ratio->GetXaxis()->SetTickLength(0.09);
    ratio->GetXaxis()->SetTitleOffset(0.8);
    ratio->GetXaxis()->SetTitleFont(42);

    ratio->GetYaxis()->CenterTitle(true);
    ratio->GetYaxis()->SetLabelFont(42);
    ratio->GetYaxis()->SetLabelSize(0.12);
    ratio->GetYaxis()->SetTitleSize(0.16);
    ratio->GetYaxis()->SetTitleOffset(0.27);
    ratio->GetYaxis()->SetTitleFont(42);

    ratio->Draw("E1");       // Draw the ratio plot

    double max = ratio->GetBinContent(ratio->GetMaximumBin());
    double min = ratio->GetBinContent(ratio->GetMinimumBin());

    // std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> max: " << max << std::endl;
    // std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> min: " << min << std::endl;

    ratio->SetMaximum(max+max*0.1);
    ratio->SetMinimum(min-min*0.1);

    gPad->Update();

    TLine *line = new TLine(ratio->GetXaxis()->GetXmin(),1,ratio->GetXaxis()->GetXmax(),1);
    line->SetLineColor(kBlack);
    line->SetLineStyle(9); // dashed
    line->Draw();



	}

	void Analyse::PlotMCTHStack(THStack *hs_trklen, std::map<std::string,TH1D*> themap, double scale_factor_mc_bnbcosmic)
{

	for (auto iter : themap) {
    iter.second->Scale(scale_factor_mc_bnbcosmic);
  }

  themap["total"]->SetFillColor(kBlack);
  themap["total"]->SetFillStyle(3005);
  themap["qe"]->SetLineColor(kGreen+2);
  themap["qe"]->SetFillColor(kGreen+2);
  themap["res"]->SetLineColor(kRed+1);
  themap["res"]->SetFillColor(kRed+1);
  themap["dis"]->SetLineColor(kBlue+2);
  themap["dis"]->SetFillColor(kBlue+2);
  themap["coh"]->SetLineColor(kMagenta+1);
  themap["coh"]->SetFillColor(kMagenta+1);
  themap["mec"]->SetLineColor(kOrange-3);
  themap["mec"]->SetFillColor(kOrange-3);

  hs_trklen->Add(themap["qe"]);
  hs_trklen->Add(themap["mec"]);
  hs_trklen->Add(themap["res"]);
  hs_trklen->Add(themap["coh"]);
  hs_trklen->Add(themap["dis"]);
  
  

  hs_trklen->Draw("hist");

  themap["total"]->Draw("E2 same");

  TLegend* leg2;

  TString xaxis_title = hs_trklen->GetXaxis()->GetTitle();
  if (xaxis_title.Contains("theta")) {
  	leg2 = new TLegend(0.1747851,0.5431579,0.4355301,0.8231579,NULL,"brNDC");
  	hs_trklen->SetMaximum(6200);
  } else if (xaxis_title.Contains("phi")) {
  	leg2 = new TLegend(0.6203438,0.5905263,0.8810888,0.8705263,NULL,"brNDC");
  	hs_trklen->SetMaximum(2500);
  } else if (xaxis_title.Contains("Energy")){
  	leg2 = new TLegend(0.56,0.54,0.82,0.82,NULL,"brNDC");
  	hs_trklen->SetMaximum(3600);
  } else if (xaxis_title.Contains("Momentum")){
  	leg2 = new TLegend(0.56,0.54,0.82,0.82,NULL,"brNDC");
  	hs_trklen->SetMaximum(4200);
  } else {
  	leg2 = new TLegend(0.56,0.54,0.82,0.82,NULL,"brNDC");
  }

  std::stringstream sstm;

  sstm << "QE, " << std::setprecision(2)  << themap["qe"]->Integral() / themap["total"]->Integral()*100. << "%";
  leg2->AddEntry(themap["qe"],sstm.str().c_str(),"f");
  sstm.str("");

  sstm << "MEC, " << std::setprecision(2)  << themap["mec"]->Integral() / themap["total"]->Integral()*100. << "%";
  leg2->AddEntry(themap["mec"],sstm.str().c_str(),"f");
  sstm.str("");

  sstm << "RES, " << std::setprecision(2)  << themap["res"]->Integral() / themap["total"]->Integral()*100. << "%";
  leg2->AddEntry(themap["res"],sstm.str().c_str(),"f");
  sstm.str("");

  sstm << "COH, " << std::setprecision(2)  << themap["coh"]->Integral() / themap["total"]->Integral()*100. << "%";
  leg2->AddEntry(themap["coh"],sstm.str().c_str(),"f");
  sstm.str("");

  sstm << "DIS, " << std::setprecision(2)  << themap["dis"]->Integral() / themap["total"]->Integral()*100. << "%";
  leg2->AddEntry(themap["dis"],sstm.str().c_str(),"f");
  sstm.str("");

  

  

  leg2->AddEntry(themap["total"],"Stat. Unc. ","f");
  sstm.str("");

  leg2->Draw();

  return;

}

void Analyse::PrintFakeDataMessage() {
  for (int i = 0; i < 100; i++) {  	
  	std::cout << "****************************** RUNNING WITH FAKE DATA ******************************" << std::endl;
  }
}




}

#endif

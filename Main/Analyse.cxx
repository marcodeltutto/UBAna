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




	void Analyse::DoAnalise() 
	{

	clock_t begin = clock();
  


  system("mkdir -p output_data_mc/");
  
  gROOT->SetBatch(kTRUE);
  gROOT->ProcessLine("gErrorIgnoreLevel = 2001;"); // 1001: INFO, 2001: WARNINGS, 3001: ERRORS

  int bnbon_total_events = 1000;
  int extbnb_total_events = 1000;
  //int intimecosmic_total_events = 1000;
  int bnbcosmic_total_events = 1000;
  double mc_pot_sim = 6.e19;
  
  // *************************************
  // Opening files
  // *************************************
  TFile* mc_bnbcosmic_file = TFile::Open(mc_bnbcosmic_file_name.c_str(), "READ");
  //TFile* mc_intimecosmic_file = TFile::Open(mc_intimecosmic_file_name.c_str(), "READ");
  TFile* bnbon_file = TFile::Open(bnbon_file_name.c_str(), "READ");
  TFile* extbnb_file = TFile::Open(extbnb_file_name.c_str(), "READ");
  
  
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
  mc_pot_sim = 5.052719378E19;
  
  // *************************************
  // Calculating scale factors
  // *************************************
  double scale_factor_extbnb = (double)bnbon_triggers/(double)extbnb_triggers;
  double scale_factor_bnbon = 1.; 
  double scale_factor_mc_bnbcosmic = bnbon_pot_meas / mc_pot_sim;

  std::cout << "Data Scale Factors:" << std::endl;
  std::cout << "\t BNBON: " << scale_factor_bnbon << std::endl;
  std::cout << "\t EXTBNB: " << scale_factor_extbnb << std::endl;
  std::cout << "MC Scale Factors:" << std::endl;
  std::cout << "\t BNBCOSMIC: " << scale_factor_mc_bnbcosmic << std::endl;
  //std::cout << "\t INTIMECOSMIC: " << scale_factor_mc_intimecosmic << std::endl;

  
  // *************************************
  // Getting the relevant histograms from MC file
  // *************************************
  std::map<std::string,TH1D*>* temp_map;
  mc_bnbcosmic_file->GetObject("hmap_trklen", temp_map);
  std::map<std::string,TH1D*> hmap_trklen_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_onebin", temp_map);
  std::map<std::string,TH1D*> hmap_onebin_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_trkmom", temp_map);
  std::map<std::string,TH1D*> hmap_trkmom_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("hmap_trktheta", temp_map);
  std::map<std::string,TH1D*> hmap_trktheta_mc = *temp_map;
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
  mc_bnbcosmic_file->GetObject("hmap_flsmatch_score", temp_map);
  std::map<std::string,TH1D*> hmap_flsmatch_score_mc = *temp_map;
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

  
  mc_bnbcosmic_file->GetObject("hmap_dqdx_trunc", temp_map);
  std::map<std::string,TH1D*> hmap_dqdx_trunc_mc = *temp_map;
  TH2D* h_dqdx_trunc_length_mc = (TH2D*)mc_bnbcosmic_file->Get("h_dqdx_trunc_length");


  std::map<std::string,std::map<std::string,TH1D*>>* temp_map_bs;
  mc_bnbcosmic_file->GetObject("hmap_trkmom_genie_pm1_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> map_bs = *temp_map_bs;

  //BootstrapTH1D * h_eff_mumom_num_bs_temp;
  //mc_bnbcosmic_file->GetObject("h_eff_mumom_num_bs", h_eff_mumom_num_bs_temp);
  //BootstrapTH1D h_eff_mumom_num_bs = *h_eff_mumom_num_bs_temp;

  BootstrapTH1D * temp_bs; // temp Bootstrap to get stuff from file

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

  // Bootstrap efficiency - FLUX Multisim
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_onebin_num", temp_bs);
  BootstrapTH1D bs_flux_multisim_eff_onebin_num = *temp_bs;
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_onebin_den", temp_bs);
  BootstrapTH1D bs_flux_multisim_eff_onebin_den = *temp_bs;

  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_muangle_num", temp_bs);
  BootstrapTH1D bs_flux_multisim_eff_muangle_num = *temp_bs;
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_muangle_den", temp_bs);
  BootstrapTH1D bs_flux_multisim_eff_muangle_den = *temp_bs;

/* to remove
  std::map<std::string,TH1D*>  map_bs_eff_mumom_num_mc = *temp_map;
  std::cout << ">> here2" << std::endl;
  mc_bnbcosmic_file->GetObject("bs_genie_pm1_eff_mumom_den", temp_map);
  std::map<std::string,TH1D*>  map_bs_eff_mumom_den_mc = *temp_map;
  std::cout << ">> here3" << std::endl;
  BootstrapTH1D bs_eff_mumom_num;
  bs_eff_mumom_num.SetAllHistograms(map_bs_eff_mumom_num_mc);
  std::cout << ">> here4" << std::endl;
  BootstrapTH1D bs_eff_mumom_den;
  bs_eff_mumom_den.SetAllHistograms(map_bs_eff_mumom_den_mc);
  std::cout << ">> here5" << std::endl;
  */
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

  // Events - GENIE Multisim
  mc_bnbcosmic_file->GetObject("hmap_onebin_genie_multisim_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_genie_multisim_bs_mc = *temp_map_bs;

  mc_bnbcosmic_file->GetObject("hmap_trkmom_genie_multisim_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_genie_multisim_bs_mc = *temp_map_bs;

  mc_bnbcosmic_file->GetObject("hmap_trkangle_genie_multisim_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_genie_multisim_bs_mc = *temp_map_bs;

  std::cout << ">> Just before" << std::endl;
  std::map<std::string,BootstrapTH1D>* map_bs_temp;  //BootstrapTH1D* temp;
  mc_bnbcosmic_file->GetObject("map_bs_trkmom_genie_multisim", map_bs_temp);
  std::map<std::string,BootstrapTH1D> map_bs_trkmom_genie_multisim = *map_bs_temp;
  std::cout << ">> Just after" << std::endl;

  // Events - FLUX Multisim
  mc_bnbcosmic_file->GetObject("hmap_onebin_flux_multisim_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_flux_multisim_bs_mc = *temp_map_bs;

  //mc_bnbcosmic_file->GetObject("hmap_onebin_genie_multisim_bs", temp_map_bs);
  //std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_genie_multisim_bs_mc = *temp_map_bs;




/*
  BootstrapTH1D bs_genie_multisim_eff_mumom_num;
  bs_genie_multisim_eff_mumom_num.SetAllHistograms(map_bs_genie_multisim_eff_mumom_num_mc);

  BootstrapTH1D bs_genie_multisim_eff_mumom_den;
  bs_genie_multisim_eff_mumom_den.SetAllHistograms(map_bs_genie_multisim_eff_mumom_den_mc);
*/

  //mc_bnbcosmic_file->GetObject("bs_genie_multisim_eff_onebin_num", temp_map);
  //std::map<std::string,TH1D*>  map_bs_genie_multisim_eff_onebin_num_mc = *temp_map;
  //mc_bnbcosmic_file->GetObject("bs_genie_multisim_eff_onebin_den", temp_map);
  //std::map<std::string,TH1D*>  map_bs_genie_multisim_eff_onebin_den_mc = *temp_map;
  //BootstrapTH1D bs_genie_multisim_eff_onebin_num;
  //bs_genie_multisim_eff_mumom_num.SetAllHistograms(map_bs_genie_multisim_eff_onebin_num_mc);
  //BootstrapTH1D bs_genie_multisim_eff_onebin_den;
  //bs_genie_multisim_eff_mumom_den.SetAllHistograms(map_bs_genie_multisim_eff_onebin_den_mc);

  BootstrapTH2D * temp_bs_2d;

  // Boostrap reco-true - GENIE Multisim
  mc_bnbcosmic_file->GetObject("bs_genie_multisim_true_reco_mumom", temp_bs_2d);
  BootstrapTH2D bs_genie_multisim_reco_true_mumom = *temp_bs_2d;

  std::cout << ">> herea" << std::endl;

  mc_bnbcosmic_file->GetObject("bs_genie_multisim_true_reco_muangle", temp_bs_2d);
  BootstrapTH2D bs_genie_multisim_true_reco_muangle = *temp_bs_2d;

std::cout << ">> here8" << std::endl;

  // Events - FLUX Multisim
  mc_bnbcosmic_file->GetObject("hmap_trkmom_flux_multisim_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_flux_multisim_bs_mc = *temp_map_bs;
  mc_bnbcosmic_file->GetObject("hmap_trkangle_flux_multisim_bs", temp_map_bs);
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_flux_multisim_bs_mc = *temp_map_bs;

  // Bootstrap efficiency - FLUX Multisim
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_mumom_num", temp_bs);
  BootstrapTH1D bs_flux_multisim_eff_mumom_num = *temp_bs;
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_mumom_den", temp_bs);
  BootstrapTH1D bs_flux_multisim_eff_mumom_den = *temp_bs;

std::cout << ">> here9" << std::endl;

/* to remove
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_mumom_num", temp_map);
  std::map<std::string,TH1D*>  map_bs_flux_multisim_eff_mumom_num_mc = *temp_map;
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_eff_mumom_den", temp_map);
  std::map<std::string,TH1D*>  map_bs_flux_multisim_eff_mumom_den_mc = *temp_map;
  BootstrapTH1D bs_flux_multisim_eff_mumom_num;
  bs_flux_multisim_eff_mumom_num.SetAllHistograms(map_bs_flux_multisim_eff_mumom_num_mc);
  BootstrapTH1D bs_flux_multisim_eff_mumom_den;
  bs_flux_multisim_eff_mumom_den.SetAllHistograms(map_bs_flux_multisim_eff_mumom_den_mc);
*/

  // Boostrap reco-true - FLUX Multisim
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_true_reco_mumom", temp_bs_2d);
  BootstrapTH2D bs_flux_multisim_true_reco_mumom = *temp_bs_2d;
  mc_bnbcosmic_file->GetObject("bs_flux_multisim_true_reco_muangle", temp_bs_2d);
  BootstrapTH2D bs_flux_multisim_true_reco_muangle = *temp_bs_2d;

std::cout << ">> here10" << std::endl;

  // *************************************
  // Getting the relevant histograms from data file
  // *************************************

  TH1D* h_trklen_total_bnbon = (TH1D*)bnbon_file->Get("h_trklen_total");
  TH1D* h_trklen_total_extbnb = (TH1D*)extbnb_file->Get("h_trklen_total");
  TH1D* h_onebin_total_bnbon = (TH1D*)bnbon_file->Get("h_onebin_total");
  TH1D* h_onebin_total_extbnb = (TH1D*)extbnb_file->Get("h_onebin_total");
  TH1D* h_trkmom_total_bnbon = (TH1D*)bnbon_file->Get("h_trkmom_total");
  TH1D* h_trkmom_total_extbnb = (TH1D*)extbnb_file->Get("h_trkmom_total");
  TH1D* h_trktheta_total_bnbon = (TH1D*)bnbon_file->Get("h_trktheta_total");
  TH1D* h_trktheta_total_extbnb = (TH1D*)extbnb_file->Get("h_trktheta_total");
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
  TH1D* h_flsmatch_score_total_bnbon = (TH1D*)bnbon_file->Get("h_flsmatch_score_total");
  TH1D* h_flsmatch_score_total_extbnb = (TH1D*)extbnb_file->Get("h_flsmatch_score_total");
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


  std::cout << ">> here11" << std::endl;

  gROOT->SetBatch(kTRUE);


  std::cout << "Opening output file with name " << "xsec_file.root" << std::endl;
    TFile *file_out = new TFile("xsec_file.root","RECREATE");
    if ( file_out->IsOpen() )
      std::cout << "File opened successfully" << std::endl;



  if (_calculate_xsec) {

    // Intantiate cross section calculator for 1D cross section
    CrossSectionCalculator1D _xsec_calc;
    _xsec_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb);
    _xsec_calc.SetPOT(bnbon_pot_meas);
    _xsec_calc.SetOutDir("output_data_mc");
    std::cout << "FLUX: " << _xsec_calc.EstimateFlux() << std::endl;


    // Create a list of the backgrounds that will be subtracted
    std::vector<std::string> hist_to_subtract = {"beam-off", "cosmic", "outfv", "nc", "nue", "anumu"};


    std::cout << "***************" << std::endl;
    std::cout << "* Total cross section" << std::endl;
    std::cout << "***************" << std::endl;


    //
    // Total cross section
    //

    _xsec_calc.Reset();
    _xsec_calc.SetHistograms(hmap_onebin_mc, h_onebin_total_bnbon, h_onebin_total_extbnb);  
    _xsec_calc.SetTruthHistograms(h_eff_onebin_num, h_eff_onebin_den);//, h_true_reco_mom); /*h_true_reco_mom is a placeholder*/
    _xsec_calc.SetTruthXSec(h_truth_xsec_mumom); /*h_truth_xsec_mumom is a placeholder*/
    _xsec_calc.SetNameAndLabel("onebin", ";One Bin; Selected Events");
    _xsec_calc.ProcessPlots();
    _xsec_calc.Draw();
    _xsec_calc.Draw(hist_to_subtract);
    _xsec_calc.DoNotSmear(); // No smearing for total cross section
    TH1D * xsec = _xsec_calc.ExtractCrossSection("One Bin", "#sigma [10^{-38} cm^{2}/GeV]");

    xsec->SetTitle("xsec_onebin");
    file_out->cd();
    xsec->Write("xsec_onebin");


    // 
    // Total cross section: Cross section reweighting
    //
    

    if (_do_reweighting_plots) {

      //
      // GENIE Multisim Systematics
      //

      CrossSectionBootstrapCalculator1D _xsec_bs_calc;

      if (_do_genie_systs) {
        _xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("onebin", ";One Bin; Selected Events");
        _xsec_bs_calc.SetOutDir("output_data_mc_bs");
        _xsec_bs_calc.SetHistograms(hmap_onebin_genie_multisim_bs_mc, h_onebin_total_bnbon, h_onebin_total_extbnb);
        _xsec_bs_calc.SetTruthHistograms(bs_genie_multisim_eff_onebin_num, bs_genie_multisim_eff_onebin_den);
        _xsec_bs_calc.DoNotSmear(); // No smearing for total cross section
        _xsec_bs_calc.SetSavePrefix("genie_multisim_onebin");
        _xsec_bs_calc.SetUpperLabel("GENIE Re-Weighting Only");
        _xsec_bs_calc.Run();
      }

      //
      // FLUX Multisim Systematics
      //

      if (_do_flux_systs) {
      	_xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("onebin", ";One Bin; Selected Events");
        _xsec_bs_calc.SetOutDir("output_data_mc_bs");
        _xsec_bs_calc.SetHistograms(hmap_onebin_flux_multisim_bs_mc, h_onebin_total_bnbon, h_onebin_total_extbnb);
        _xsec_bs_calc.SetTruthHistograms(bs_flux_multisim_eff_onebin_num, bs_flux_multisim_eff_onebin_den);
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
    TH2D covariance_matrix_flux;



    // 
    // Muon Momentum: Cross section reweighting
    //

    if (_do_reweighting_plots) {

      //
      // GENIE Multisim Systematics
      //

      CrossSectionBootstrapCalculator1D _xsec_bs_calc;

      if (_do_genie_systs) {
        _xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("trkmom_bs", ";Candidate Track Momentum (MCS) [GeV]; Selected Events");
        _xsec_bs_calc.SetOutDir("output_data_mc_bs");
        _xsec_bs_calc.SetHistograms(hmap_trkmom_genie_multisim_bs_mc/*map_bs_trkmom_genie_multisim*/, h_trkmom_total_bnbon, h_trkmom_total_extbnb);
        _xsec_bs_calc.SetTruthHistograms(bs_genie_multisim_eff_mumom_num, bs_genie_multisim_eff_mumom_den, bs_genie_multisim_reco_true_mumom);
        _xsec_bs_calc.SetMigrationMatrixDimensions(7,6);
        _xsec_bs_calc.SetSavePrefix("genie_multisim_mumom");
        _xsec_bs_calc.SetUpperLabel("GENIE Re-Weighting Only");
        _xsec_bs_calc.Run();

        _xsec_bs_calc.GetCovarianceMatrix(covariance_matrix_genie);

        for (int i = 0; i < covariance_matrix_genie.GetNbinsX(); i++) {
      	  std::cout << "GENIE Multisim - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_genie.GetBinContent(i+1, i+1) << std::endl;
        }
      }

      


      //
      // FLUX Multisim Systematics
      //
      if (_do_flux_systs) {
        _xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("trkmom_bs", ";Candidate Track Momentum (MCS) [GeV]; Selected Events");
        _xsec_bs_calc.SetOutDir("output_data_mc_bs");
        _xsec_bs_calc.SetHistograms(hmap_trkmom_flux_multisim_bs_mc/*map_bs_trkmom_genie_multisim*/, h_trkmom_total_bnbon, h_trkmom_total_extbnb);
        _xsec_bs_calc.SetTruthHistograms(bs_flux_multisim_eff_mumom_num, bs_flux_multisim_eff_mumom_den, bs_flux_multisim_true_reco_mumom);
        _xsec_bs_calc.SetMigrationMatrixDimensions(7,6);
        _xsec_bs_calc.SetSavePrefix("flux_multisim_mumom");
        _xsec_bs_calc.SetUpperLabel("FLUX Re-Weighting Only");
        _xsec_bs_calc.SetFluxHistogramType(true, _target_flux_syst); // Also reweight the flux
        _xsec_bs_calc.Run();

        _xsec_bs_calc.GetCovarianceMatrix(covariance_matrix_flux);

        for (int i = 0; i < covariance_matrix_flux.GetNbinsX(); i++) {
      	  std::cout << "FLUX Multisim - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_flux.GetBinContent(i+1, i+1) << std::endl;
        }
      }



    } // _do_reweighting_plots


    TH2D covariance_matrix_mumom = * ((TH2D*)covariance_matrix_genie.Clone("covariance_matrix"));
    covariance_matrix_mumom.Add(&covariance_matrix_flux);

    for (int i = 0; i < covariance_matrix_mumom.GetNbinsX(); i++) {
      std::cout << "TOTAL - Momentum - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_mumom.GetBinContent(i+1, i+1) << std::endl;
    }


    //
    // Muon Momentum Cross Section
    //
    TMatrix S_2d; S_2d.Clear(); S_2d.ResizeTo(7, 6);
    MigrationMatrix2D migrationmatrix2d;
    migrationmatrix2d.SetNBins(7, 6);
    migrationmatrix2d.SetTrueRecoHistogram(h_true_reco_mom);
    S_2d = migrationmatrix2d.CalculateMigrationMatrix();
    migrationmatrix2d.PlotMatrix();
    _xsec_calc.Reset();
    _xsec_calc.SetHistograms(hmap_trkmom_mc, h_trkmom_total_bnbon, h_trkmom_total_extbnb);  
    _xsec_calc.SetTruthHistograms(h_eff_mumom_num, h_eff_mumom_den, h_true_reco_mom);
    _xsec_calc.SetTruthXSec(h_truth_xsec_mumom);
    _xsec_calc.SetNameAndLabel("trkmom", ";Candidate Track Momentum (MCS) [GeV]; Selected Events");
    _xsec_calc.ProcessPlots();
    _xsec_calc.Draw();
    _xsec_calc.Draw(hist_to_subtract);
    _xsec_calc.SetMigrationMatrix(S_2d);
    _xsec_calc.Smear(7, 6);
    _xsec_calc.SetCovarianceMatrix(covariance_matrix_mumom);
    TH1D * xsec_mumom = _xsec_calc.ExtractCrossSection("p_{#mu} [GeV]", "d#sigma/dp_{#mu} [10^{-38} cm^{2}/GeV]");

    xsec_mumom->SetTitle("xsec_mumom");
    file_out->cd();
    xsec_mumom->Write("xsec_mumom");





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

      if (_do_genie_systs) {
        _xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("trkcostheta_genie_multisim", ";Candidate Track cos(#theta) [GeV]; Selected Events");
        _xsec_bs_calc.SetOutDir("output_data_mc_bs");
        _xsec_bs_calc.SetHistograms(hmap_trkangle_genie_multisim_bs_mc, h_trktheta_total_bnbon, h_trktheta_total_extbnb);
        _xsec_bs_calc.SetTruthHistograms(bs_genie_multisim_eff_muangle_num, bs_genie_multisim_eff_muangle_den, bs_genie_multisim_true_reco_muangle);
        _xsec_bs_calc.SetMigrationMatrixDimensions(9, 9);
        _xsec_bs_calc.SetSavePrefix("genie_multisim_muangle");
        _xsec_bs_calc.SetUpperLabel("GENIE Re-Weighting Only");
        _xsec_bs_calc.Run();

        _xsec_bs_calc.GetCovarianceMatrix(covariance_matrix_genie);

        for (int i = 0; i < covariance_matrix_genie.GetNbinsX(); i++) {
      	  std::cout << "FLUX Multisim - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_genie.GetBinContent(i+1, i+1) << std::endl;
        }
      }


      //
      // FLUX Multisim Systematics
      //
      if (_do_flux_systs) {
        _xsec_bs_calc.Reset();
        _xsec_bs_calc.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb);
        _xsec_bs_calc.SetPOT(bnbon_pot_meas);
        _xsec_bs_calc.SetNameAndLabel("trkcostheta_flux_multisim", ";Candidate Track cos(#theta) [GeV]; Selected Events");
        _xsec_bs_calc.SetOutDir("output_data_mc_bs");
        _xsec_bs_calc.SetHistograms(hmap_trkangle_flux_multisim_bs_mc, h_trktheta_total_bnbon, h_trktheta_total_extbnb);
        _xsec_bs_calc.SetTruthHistograms(bs_flux_multisim_eff_muangle_num, bs_flux_multisim_eff_muangle_den, bs_flux_multisim_true_reco_muangle);
        _xsec_bs_calc.SetMigrationMatrixDimensions(9, 9);
        _xsec_bs_calc.SetSavePrefix("flux_multisim_muangle");
        _xsec_bs_calc.SetUpperLabel("FLUX Re-Weighting Only");
        _xsec_bs_calc.SetFluxHistogramType(true, _target_flux_syst); // Also reweight the flux
        _xsec_bs_calc.Run();

        _xsec_bs_calc.GetCovarianceMatrix(covariance_matrix_flux);

        for (int i = 0; i < covariance_matrix_flux.GetNbinsX(); i++) {
      	  std::cout << "FLUX Multisim - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_flux.GetBinContent(i+1, i+1) << std::endl;
        }
      }

    } // _do_reweighting_plots


    TH2D covariance_matrix_muangle = * ((TH2D*)covariance_matrix_genie.Clone("covariance_matrix"));
    covariance_matrix_muangle.Add(&covariance_matrix_flux);

    for (int i = 0; i < covariance_matrix_muangle.GetNbinsX(); i++) {
      std::cout << "TOTAL - Angle - Uncertainties on the diagonal: " << i << " => " << covariance_matrix_muangle.GetBinContent(i+1, i+1) << std::endl;
    }


    //
    // Muon CosTheta Cross Section
    // 
    S_2d.Clear(); S_2d.ResizeTo(9, 9);
    migrationmatrix2d.SetNBins(9, 9);
    migrationmatrix2d.SetTrueRecoHistogram(h_true_reco_costheta);
    S_2d = migrationmatrix2d.CalculateMigrationMatrix();
    migrationmatrix2d.PlotMatrix();
    _xsec_calc.Reset();
    _xsec_calc.SetHistograms(hmap_trktheta_mc, h_trktheta_total_bnbon, h_trktheta_total_extbnb);  
    _xsec_calc.SetTruthHistograms(h_eff_muangle_num, h_eff_muangle_den, h_true_reco_costheta);
    _xsec_calc.SetTruthXSec(h_truth_xsec_muangle);
    _xsec_calc.SetNameAndLabel("trkcostheta", ";Candidate Track cos(#theta) [GeV]; Selected Events");
    _xsec_calc.ProcessPlots();
    _xsec_calc.Draw();
    _xsec_calc.Draw(hist_to_subtract);
    _xsec_calc.SetMigrationMatrix(S_2d);
    _xsec_calc.Smear(9, 9);
    _xsec_calc.SetCovarianceMatrix(covariance_matrix_muangle);
    TH1D * xsec_muangle = _xsec_calc.ExtractCrossSection("cos(#theta_{#mu})", "d#sigma/dcos(#theta_{#mu}) [10^{-38} cm^{2}]");

    xsec_muangle->SetTitle("xsec_muangle");
    file_out->cd();
    xsec_muangle->Write("xsec_muangle");





    //
    // Double Differential Cross Section
    // 
    MigrationMatrix4D migrationmatrix4d;
    TTree * tt;
    mc_bnbcosmic_file->GetObject("mom_tree", tt);
    migrationmatrix4d.SetTTree(tt);
    int n_bins_mumom_temp = 4;
    double bins_mumom_temp[5] = {0.00, 0.25, 0.50, 1.0, 2.50};
    int n_bins_mucostheta_temp = 6;
    double bins_mucostheta_temp[7] = {-1.00, -0.50, 0.00, 0.25, 0.50, 0.75, 1.00};
    migrationmatrix4d.SetBins(bins_mucostheta_temp, n_bins_mucostheta_temp, bins_mumom_temp, n_bins_mumom_temp);
    auto S_4d = migrationmatrix4d.CalculateMigrationMatrix();
    migrationmatrix4d.SetOutputFileName("latex_test.tex");
    migrationmatrix4d.PrintSmearingMatrixLatex();
    migrationmatrix4d.PlotMatrix();

    CrossSectionCalculator2D xseccalc2d;
    xseccalc2d.SetScaleFactors(scale_factor_mc_bnbcosmic, scale_factor_bnbon, scale_factor_extbnb);
    xseccalc2d.SetPOT(bnbon_pot_meas);
    xseccalc2d.SetOutDir("output_data_mc_xsec2d");
    std::cout << "FLUX: " << xseccalc2d.EstimateFlux() << std::endl;

    xseccalc2d.SetHistograms(hmap_trktheta_trkmom_mc, h_trktheta_trkmom_total_bnbon, h_trktheta_trkmom_total_extbnb);
    xseccalc2d.SetTruthHistograms(h_eff_muangle_mumom_num, h_eff_muangle_mumom_den);
    xseccalc2d.SetNameAndLabel("trkcostheta_trkmumom_", ";Candidate Track cos(#theta) [GeV];Candidate Track Momentum (MCS) [GeV]");
    xseccalc2d.ProcessPlots();
    xseccalc2d.SetSmearingMatrix(S_4d);
    xseccalc2d.Smear();

    xseccalc2d.ExtractCrossSection("cos(#theta_{#mu})", "p_{#mu} [GeV]", "d^{2}#sigma/dcos(#theta_{#mu}dp_{#mu}) [10^{-38} cm^{2}/GeV]");
  }

  file_out->Write();
  file_out->Close();

  
  // *************************************
  // Doing beam-on minus beam-off subtraction
  // *************************************
  h_trklen_total_extbnb->Scale(scale_factor_extbnb);
  h_trklen_total_bnbon->Scale(scale_factor_bnbon);
  TH1D* h_trklen_data = (TH1D*)h_trklen_total_bnbon->Clone("h_trklen_data");
  h_trklen_data->Sumw2();
  h_trklen_data->Add(h_trklen_total_extbnb, -1.);
  
  std::cout << "With the correct normalisation: " << std::endl;
  std::cout << "\t Number of BNBON events:   " << h_trklen_total_bnbon->Integral() << std::endl;
  std::cout << "\t Number of EXTBNB events:  " << h_trklen_total_extbnb->Integral() << std::endl;
  std::cout << "\t           BNBON - EXTBNB: " << h_trklen_total_bnbon->Integral() - h_trklen_total_extbnb->Integral() << std::endl;

  std::cout << std::endl;

  std::cout << "With the correct normalisation (including under/overflows): " << std::endl;
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

  // *************************************
  // Plotting data and MC distribution
  // *************************************
  
  TLegend* leg;
  TString name;
  TString outdir = "./output_data_mc/";
  
  TCanvas* canvas_trklen = new TCanvas();
  THStack *hs_trklen_mc = new THStack("hs_trklen",";Candidate Track Length [cm]; Selected Events");
  hmap_trklen_mc["beam-off"] = h_trklen_total_extbnb;
  leg = PlottingTools::DrawTHStack(hs_trklen_mc, scale_factor_mc_bnbcosmic, true, hmap_trklen_mc);
  PlottingTools::DrawDataHisto(h_trklen_total_bnbon);
  leg->AddEntry(hmap_trklen_mc["beam-off"],"Data (Beam-off)","f");
  leg->AddEntry(h_trklen_total_bnbon,"Data (Beam-on)","lep");
  //DrawDataHisto(h_trklen_data);
  //leg->AddEntry(h_trklen_data,"Data (Beam-on - Beam-off)","lep");
  PlottingTools::DrawPOT(bnbon_pot_meas);
  
  std::cout << "\t             MC BNBCOSMIC: " << hmap_trklen_mc["total"]->Integral(0, hmap_trklen_mc["total"]->GetNbinsX()+1) << std::endl;
  std::cout << "\t             DATA (on-off): " << h_trklen_data->Integral(0, h_trklen_data->GetNbinsX()+1) << std::endl;
  

  double den = hmap_trklen_mc["signal"]->Integral() +
  hmap_trklen_mc["cosmic"]->Integral() +
  hmap_trklen_mc["outfv"]->Integral() +
  hmap_trklen_mc["nc"]->Integral() +
  hmap_trklen_mc["anumu"]->Integral() +
  hmap_trklen_mc["nue"]->Integral() +
  hmap_trklen_mc["beam-off"]->Integral();

  std::cout << std::endl;
  
  std::cout << "Number of events per channel:" << std::endl;
  std::cout << "signal: " << hmap_trklen_mc["signal"]->Integral() << ", " << hmap_trklen_mc["signal"]->Integral() / den << std::endl;
  std::cout << "cosmic: " << hmap_trklen_mc["cosmic"]->Integral() << ", " << hmap_trklen_mc["cosmic"]->Integral() / den << std::endl;
  std::cout << "outfv: " << hmap_trklen_mc["outfv"]->Integral() << ", " << hmap_trklen_mc["outfv"]->Integral() / den << std::endl;
  std::cout << "nc: " << hmap_trklen_mc["nc"]->Integral() << ", " << hmap_trklen_mc["nc"]->Integral() / den << std::endl;
  std::cout << "anumu: " << hmap_trklen_mc["anumu"]->Integral() << ", " << hmap_trklen_mc["anumu"]->Integral() / den << std::endl;
  std::cout << "nue: " << hmap_trklen_mc["nue"]->Integral() << ", " << hmap_trklen_mc["nue"]->Integral() / den << std::endl;
  std::cout << "beam-off: " << hmap_trklen_mc["beam-off"]->Integral() << ", " << hmap_trklen_mc["beam-off"]->Integral() / den << std::endl;
  std::cout << std::endl;
  std::cout << "PURITY: " << hmap_trklen_mc["signal"]->Integral() / den << std::endl;
  
  std::cout << std::endl;

  std::cout << "Number of events per channel (including over/underflow bins):" << std::endl;

  int nbins = hmap_trklen_mc["signal"]->GetNbinsX();

  den = hmap_trklen_mc["signal"]->Integral(0, nbins+1) +
  hmap_trklen_mc["cosmic"]->Integral(0, nbins+1) +
  hmap_trklen_mc["outfv"]->Integral(0, nbins+1) +
  hmap_trklen_mc["nc"]->Integral(0, nbins+1) +
  hmap_trklen_mc["anumu"]->Integral(0, nbins+1) +
  hmap_trklen_mc["nue"]->Integral(0, nbins+1) +
  hmap_trklen_mc["beam-off"]->Integral(0, nbins+1);

  std::cout << "signal: " << hmap_trklen_mc["signal"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["signal"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << "cosmic: " << hmap_trklen_mc["cosmic"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["cosmic"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << "outfv: " << hmap_trklen_mc["outfv"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["outfv"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << "nc: " << hmap_trklen_mc["nc"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["nc"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << "anumu: " << hmap_trklen_mc["anumu"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["anumu"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << "nue: " << hmap_trklen_mc["nue"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["nue"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << "beam-off: " << hmap_trklen_mc["beam-off"]->Integral(0, nbins+1) << ", " << hmap_trklen_mc["beam-off"]->Integral(0, nbins+1) / den << std::endl;
  std::cout << std::endl;
  std::cout << "PURITY: " << hmap_trklen_mc["signal"]->Integral(0, nbins+1) / den << std::endl;
  
  
  name = outdir + "trklen";
  canvas_trklen->SaveAs(name + ".pdf");
  canvas_trklen->SaveAs(name + ".C","C");


  


  TCanvas* canvas_trkphi = new TCanvas();
  THStack *hs_trkphi_mc = new THStack("hs_trkphi",";Candidate Track #phi; Selected Events");
  hmap_trkphi_mc["beam-off"] = h_trkphi_total_extbnb;
  leg = PlottingTools::DrawTHStack(hs_trkphi_mc, scale_factor_mc_bnbcosmic, true, hmap_trkphi_mc);
  PlottingTools::DrawDataHisto(h_trkphi_total_bnbon);
  leg->AddEntry(hmap_trkphi_mc["beam-off"],"Data (Beam-off)","f");
  leg->AddEntry(h_trkphi_total_bnbon,"Data (Beam-on)","lep");  //DrawDataHisto(h_trkphi_data);
  //leg->AddEntry(h_trkphi_data,"Data (Beam-on - Beam-off)","lep");
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "trkphi";
  canvas_trkphi->SaveAs(name + ".pdf");
  canvas_trkphi->SaveAs(name + ".C","C");
  
  TCanvas* canvas_multpfp = new TCanvas();
  THStack *hs_multpfp_mc = new THStack("hs_multpfp",";PFP Multiplicity; Selected Events");
  leg = PlottingTools::DrawTHStack(hs_multpfp_mc, scale_factor_mc_bnbcosmic, true, hmap_multpfp_mc);
  PlottingTools::DrawDataHisto(h_multpfp_data);
  leg->AddEntry(h_multpfp_data,"Data (Beam-on - Beam-off)","lep");
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "multpfp";
  canvas_multpfp->SaveAs(name + ".pdf");
  canvas_multpfp->SaveAs(name + ".C","C");
  
  TCanvas* canvas_multtracktol = new TCanvas();
  THStack *hs_multtracktol_mc = new THStack("hs_multtracktol",";Track Multiplicity (5 cm); Selected Events");
  leg = PlottingTools::DrawTHStack(hs_multtracktol_mc, scale_factor_mc_bnbcosmic, true, hmap_multtracktol_mc);
  PlottingTools::DrawDataHisto(h_multtracktol_data);
  leg->AddEntry(h_multtracktol_data,"Data (Beam-on - Beam-off)","lep");
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
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




  TCanvas* canvas_vtxcheck_angle = new TCanvas();
  THStack *hs_vtxcheck_angle_mc = new THStack("hs_vtxcheck_angle",";Angle [rad]; TPCObjects (Before Selection)");
  hmap_vtxcheck_angle_mc["beam-off"] = h_vtxcheck_angle_total_extbnb;
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
  leg = PlottingTools::DrawTHStack2(hs_mom_mcs_length_mc, scale_factor_mc_bnbcosmic, true, hmap_mom_mcs_length_mc);
  leg->AddEntry(h_mom_mcs_length_total_bnbon,"Data (Beam-on)","lep");  // DrawDataHisto(h_vtxx_total_bnbon);
  PlottingTools::DrawDataHisto(h_mom_mcs_length_total_bnbon);
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "mom_mcs_length";
  canvas_mom_mcs_length->SaveAs(name + ".pdf");
  canvas_mom_mcs_length->SaveAs(name + ".C","C");
  
  
  TCanvas* canvas_vtxx = new TCanvas();
  THStack *hs_vtxx_mc = new THStack("hs_vtxx",";Candidate Neutrino Vertex X [cm]; Selected Events");
  hmap_vtxx_mc["beam-off"] = h_vtxx_total_extbnb;
  leg = PlottingTools::DrawTHStack2(hs_vtxx_mc, scale_factor_mc_bnbcosmic, true, hmap_vtxx_mc);
  leg->AddEntry(h_vtxx_total_bnbon,"Data (Beam-on)","lep");  // DrawDataHisto(h_vtxx_total_bnbon);
  PlottingTools::DrawDataHisto(h_vtxx_total_bnbon);
  hs_vtxx_mc->SetMaximum(600);
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "vtxx";
  canvas_vtxx->SaveAs(name + ".pdf");
  canvas_vtxx->SaveAs(name + ".C","C");

   
  TCanvas* canvas_vtxy = new TCanvas();
  THStack *hs_vtxy_mc = new THStack("hs_vtxy",";Candidate Neutrino Vertex Y [cm]; Selected Events");
  hmap_vtxy_mc["beam-off"] = h_vtxy_total_extbnb;
  leg = PlottingTools::DrawTHStack2(hs_vtxy_mc, scale_factor_mc_bnbcosmic, true, hmap_vtxy_mc);
  leg->AddEntry(h_vtxy_total_bnbon,"Data (Beam-on)","lep");  // DrawDataHisto(h_vtxy_data);
  PlottingTools::DrawDataHisto(h_vtxy_total_bnbon);
  hs_vtxy_mc->SetMaximum(650);
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "vtxy";
  canvas_vtxy->SaveAs(name + ".pdf");
  canvas_vtxy->SaveAs(name + ".C","C");
  
  TCanvas* canvas_vtxz = new TCanvas();
  THStack *hs_vtxz_mc = new THStack("hs_vtxz",";Candidate Neutrino Vertex Z [cm]; Selected Events");
  hmap_vtxz_mc["beam-off"] = h_vtxz_total_extbnb;
  leg = PlottingTools::DrawTHStack2(hs_vtxz_mc, scale_factor_mc_bnbcosmic, true, hmap_vtxz_mc);
  leg->AddEntry(h_vtxz_total_bnbon,"Data (Beam-on)","lep");  // DrawDataHisto(h_vtxz_data);
  PlottingTools::DrawDataHisto(h_vtxz_total_bnbon);
  hs_vtxz_mc->SetMaximum(900);
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "vtxz";
  canvas_vtxz->SaveAs(name + ".pdf");
  canvas_vtxz->SaveAs(name + ".C","C");
  
  TCanvas* canvas_flsmatch_score = new TCanvas();
  THStack *hs_flsmatch_score_mc = new THStack("hs_flsmatch_score",";1/(-log(L)); Selected Events");
  leg = PlottingTools::DrawTHStack2(hs_flsmatch_score_mc, scale_factor_mc_bnbcosmic, true, hmap_flsmatch_score_mc);
  PlottingTools::DrawDataHisto(h_flsmatch_score_data);
  leg->AddEntry(h_flsmatch_score_data,"Data (Beam-on - Beam-off)","lep");
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "flsmatch_score";
  canvas_flsmatch_score->SaveAs(name + ".pdf");
  canvas_flsmatch_score->SaveAs(name + ".C","C");
  
  TCanvas* canvas_ntpcobj = new TCanvas();
  THStack *hs_ntpcobj_mc = new THStack("hs_ntpcobj",";Number of TPCObjects per events; ");
  leg = PlottingTools::DrawTHStack2(hs_ntpcobj_mc, scale_factor_mc_bnbcosmic, true, hmap_ntpcobj_mc);
  PlottingTools::DrawDataHisto(h_ntpcobj_data);
  leg->AddEntry(h_ntpcobj_data,"Data (Beam-on - Beam-off)","lep");
  PlottingTools::DrawPOT(bnbon_pot_meas);
  leg->Draw();
  
  name = outdir + "ntpcobj";
  canvas_ntpcobj->SaveAs(name + ".pdf");
  canvas_ntpcobj->SaveAs(name + ".C","C");
  
  TCanvas* canvas_dqdx_trunc = new TCanvas();
  THStack *hs_dqdx_trunc_mc = new THStack("hs_dqdx_trunc",";Candidate Track <dQ/dx>_{trunc};");
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
  
  // Computing time
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << endl << endl << "Computing time: " << elapsed_secs << " seconds = " << elapsed_secs/60. << " minutes." << endl << endl;
  
  //rootapp->Run();
  //rootapp->Terminate(0);
  
  return;
	}


}

#endif

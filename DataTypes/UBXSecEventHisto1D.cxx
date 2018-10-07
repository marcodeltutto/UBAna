#ifndef __DATATYPES_UBXSECEVENTHISTO1D_CXX__
#define __DATATYPES_UBXSECEVENTHISTO1D_CXX__

#include "UBXSecEventHisto1D.h"


namespace DataTypes {


    void UBXSecEventHisto1D::InitializeBootstraps()
    {

      //
      // Total Cross Section
      //

      // Efficiency - Total Cross Section
      h_eff_onebin_num = new TH1D("h_eff_onebin_num", "h_eff_onebin_num", 1, 0, 1);
      h_eff_onebin_den = new TH1D("h_eff_onebin_den", "h_eff_onebin_den", 1, 0, 1);

      // Number of events per channel - Total Cross Section
      hmap_onebin["total"] = new TH1D("h_onebin_total", "; Track length;", 1, 0, 1);
      hmap_onebin["signal"] = new TH1D("h_onebin_signal", "; Track length;", 1, 0, 1);
      hmap_onebin["cosmic"] = new TH1D("h_onebin_cosmic", "; Track length;", 1, 0, 1);
      hmap_onebin["cosmic_stopmu"] = new TH1D("h_onebin_cosmic_stopmu", "; Track length;", 1, 0, 1);
      hmap_onebin["cosmic_nostopmu"] = new TH1D("h_onebin_cosmic_nostopmu", "; Track length;", 1, 0, 1);
      hmap_onebin["outfv"] = new TH1D("h_onebin_outfv", "; Track length;", 1, 0, 1);
      hmap_onebin["outfv_stopmu"] = new TH1D("h_onebin_outfv_stopmu", "; Track length;", 1, 0, 1);
      hmap_onebin["outfv_nostopmu"] = new TH1D("h_onebin_outfv_nostopmu", "; Track length;", 1, 0, 1);
      hmap_onebin["nc"] = new TH1D("h_onebin_nc", "; Track length;", 1, 0, 1);
      hmap_onebin["nc_proton"] = new TH1D("h_onebin_nc_proton", "; Track length;", 1, 0, 1);
      hmap_onebin["nc_pion"] = new TH1D("h_onebin_nc_pion", "; Track length;", 1, 0, 1);
      hmap_onebin["nc_other"] = new TH1D("h_onebin_nc_other", "; Track length;", 1, 0, 1);
      hmap_onebin["anumu"] = new TH1D("h_onebin_anumu", "; Track length;", 1, 0, 1);
      hmap_onebin["nue"] = new TH1D("h_onebin_nue", "; Track length;", 1, 0, 1);
      hmap_onebin["signal_stopmu"] = new TH1D("h_onebin_signal_stopmu", "; Track length;", 1, 0, 1);
      hmap_onebin["signal_nostopmu"] = new TH1D("h_onebin_signal_nostopmu", "; Track length;", 1, 0, 1);

      // Efficiency - Total Cross Section - Multisim
      bs_genie_multisim_eff_onebin_num = new BootstrapTH1D("bs_genie_multisim_eff_onebin_num", "bs_genie_multisim_eff_onebin_num_title", 1, 0, 1);
      bs_genie_multisim_eff_onebin_den = new BootstrapTH1D("bs_genie_multisim_eff_onebin_den", "bs_genie_multisim_eff_onebin_den_title", 1, 0, 1);
      bs_flux_multisim_eff_onebin_num = new BootstrapTH1D("bs_flux_multisim_eff_onebin_num", "bs_flux_multisim_eff_onebin_num_title", 1, 0, 1);
      bs_flux_multisim_eff_onebin_den = new BootstrapTH1D("bs_flux_multisim_eff_onebin_den", "bs_flux_multisim_eff_onebin_den_title", 1, 0, 1);
      bs_extra_syst_multisim_eff_onebin_num = new BootstrapTH1D("bs_extra_syst_multisim_eff_onebin_num", "bs_extra_syst_eff_onebin_num_title", 1, 0, 1);
      bs_extra_syst_multisim_eff_onebin_den = new BootstrapTH1D("bs_extra_syst_multisim_eff_onebin_den", "bs_extra_syst_eff_onebin_den_title", 1, 0, 1);
      bs_mc_stat_multisim_eff_onebin_num = new BootstrapTH1D("bs_mc_stat_multisim_eff_onebin_num", "bs_mc_stat_eff_onebin_num_title", 1, 0, 1);
      bs_mc_stat_multisim_eff_onebin_den = new BootstrapTH1D("bs_mc_stat_multisim_eff_onebin_den", "bs_mc_stat_eff_onebin_den_title", 1, 0, 1);

      // Number of events per channel and universe - Total Cross Section - Genie Multisim
      hmap_onebin_genie_multisim_bs["total"]["nominal"] = new TH1D("h_onebin_total_genie_mulinominal", "; Track length;", 1, 0, 1);
      hmap_onebin_genie_multisim_bs["signal"]["nominal"] = new TH1D("h_onebin_signal_genie_mulinominal", "; Track length;", 1, 0, 1);
      hmap_onebin_genie_multisim_bs["cosmic"]["nominal"] = new TH1D("h_onebin_cosmic_genie_mulinominal", "; Track length;", 1, 0, 1);
      hmap_onebin_genie_multisim_bs["outfv"]["nominal"] = new TH1D("h_onebin_outfv_genie_mulinominal", "; Track length;", 1, 0, 1);
      hmap_onebin_genie_multisim_bs["nc"]["nominal"] = new TH1D("h_onebin_nc_genie_mulinominal", "; Track length;", 1, 0, 1);
      hmap_onebin_genie_multisim_bs["anumu"]["nominal"] = new TH1D("h_onebin_anumu_genie_mulinominal", "; Track length;", 1, 0, 1);
      hmap_onebin_genie_multisim_bs["nue"]["nominal"] = new TH1D("h_onebin_nue_genie_mulinominal", "; Track length;", 1, 0, 1);

      // Number of events per channel and universe - Total Cross Section - Flux Multisim
      hmap_onebin_flux_multisim_bs["total"]["nominal"] = new TH1D("h_onebin_total_flux_mulinominal", "; Track length;", 1, 0, 1);
      hmap_onebin_flux_multisim_bs["signal"]["nominal"] = new TH1D("h_onebin_signal_flux_mulinominal", "; Track length;", 1, 0, 1);
      hmap_onebin_flux_multisim_bs["cosmic"]["nominal"] = new TH1D("h_onebin_cosmic_flux_mulinominal", "; Track length;", 1, 0, 1);
      hmap_onebin_flux_multisim_bs["outfv"]["nominal"] = new TH1D("h_onebin_outfv_flux_mulinominal", "; Track length;", 1, 0, 1);
      hmap_onebin_flux_multisim_bs["nc"]["nominal"] = new TH1D("h_onebin_nc_flux_mulinominal", "; Track length;", 1, 0, 1);
      hmap_onebin_flux_multisim_bs["anumu"]["nominal"] = new TH1D("h_onebin_anumu_flux_mulinominal", "; Track length;", 1, 0, 1);
      hmap_onebin_flux_multisim_bs["nue"]["nominal"] = new TH1D("h_onebin_nue_flux_mulinominal", "; Track length;", 1, 0, 1);

      // Number of events per channel and universe - Total Cross Section - Extra Syst
      hmap_onebin_extra_syst_multisim_bs["total"]["nominal"] = new TH1D("h_onebin_total_extra_syst_multisim_nominal", "; Track length;", 1, 0, 1);
      hmap_onebin_extra_syst_multisim_bs["signal"]["nominal"] = new TH1D("h_onebin_signal_extra_syst_multisim_nominal", "; Track length;", 1, 0, 1);
      hmap_onebin_extra_syst_multisim_bs["cosmic"]["nominal"] = new TH1D("h_onebin_cosmic_extra_syst_multisim_nominal", "; Track length;", 1, 0, 1);
      hmap_onebin_extra_syst_multisim_bs["outfv"]["nominal"] = new TH1D("h_onebin_outfv_extra_syst_multisim_nominal", "; Track length;", 1, 0, 1);
      hmap_onebin_extra_syst_multisim_bs["nc"]["nominal"] = new TH1D("h_onebin_nc_extra_syst_multisim_nominal", "; Track length;", 1, 0, 1);
      hmap_onebin_extra_syst_multisim_bs["anumu"]["nominal"] = new TH1D("h_onebin_anumu_extra_syst_multisim_nominal", "; Track length;", 1, 0, 1);
      hmap_onebin_extra_syst_multisim_bs["nue"]["nominal"] = new TH1D("h_onebin_nue_extra_syst_multisim_nominal", "; Track length;", 1, 0, 1);

      // Number of events per channel and universe - Total Cross Section - MC Stat
      hmap_onebin_mc_stat_multisim_bs["total"]["nominal"] = new TH1D("h_onebin_total_mc_stat_multisim_nominal", "; Track length;", 1, 0, 1);
      hmap_onebin_mc_stat_multisim_bs["signal"]["nominal"] = new TH1D("h_onebin_signal_mc_stat_multisim_nominal", "; Track length;", 1, 0, 1);
      hmap_onebin_mc_stat_multisim_bs["cosmic"]["nominal"] = new TH1D("h_onebin_cosmic_mc_stat_multisim_nominal", "; Track length;", 1, 0, 1);
      hmap_onebin_mc_stat_multisim_bs["outfv"]["nominal"] = new TH1D("h_onebin_outfv_mc_stat_multisim_nominal", "; Track length;", 1, 0, 1);
      hmap_onebin_mc_stat_multisim_bs["nc"]["nominal"] = new TH1D("h_onebin_nc_mc_stat_multisim_nominal", "; Track length;", 1, 0, 1);
      hmap_onebin_mc_stat_multisim_bs["anumu"]["nominal"] = new TH1D("h_onebin_anumu_mc_stat_multisim_nominal", "; Track length;", 1, 0, 1);
      hmap_onebin_mc_stat_multisim_bs["nue"]["nominal"] = new TH1D("h_onebin_nue_mc_stat_multisim_nominal", "; Track length;", 1, 0, 1);

      


      //
      // Single differential (mumom)
      //

      // Efficiency - Single Differential (mumom)
      h_eff_mumom_num = new TH1D("h_eff_mumom_num", "h_eff_mumom_num", n_bins_mumom, bins_mumom);
      h_eff_mumom_den = new TH1D("h_eff_mumom_den", "h_eff_mumom_den", n_bins_mumom, bins_mumom);

      // Reco to true histograms - Single Differential (mumom)
      h_true_reco_mom= new TH2D("h_true_reco_mom", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", n_bins_mumom, bins_mumom, n_bins_mumom, bins_mumom);

      // Number of events per channel - Single Differential (mumom)
      hmap_trkmom["total"] = new TH1D("h_trkmom_total", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["signal"] = new TH1D("h_trkmom_signal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["cosmic"] = new TH1D("h_trkmom_cosmic", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["cosmic_stopmu"] = new TH1D("h_trkmom_cosmic_stopmu", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["cosmic_nostopmu"] = new TH1D("h_trkmom_cosmic_nostopmu", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["outfv"] = new TH1D("h_trkmom_outfv", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["outfv_stopmu"] = new TH1D("h_trkmom_outfv_stopmu", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["outfv_nostopmu"] = new TH1D("h_trkmom_outfv_nostopmu", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["nc"] = new TH1D("h_trkmom_nc", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["nc_proton"] = new TH1D("h_trkmom_nc_proton", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["nc_pion"] = new TH1D("h_trkmom_nc_pion", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["nc_other"] = new TH1D("h_trkmom_nc_other", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["anumu"] = new TH1D("h_trkmom_anumu", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["nue"] = new TH1D("h_trkmom_nue", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["signal_stopmu"] = new TH1D("h_trkmom_signal_stopmu", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom["signal_nostopmu"] = new TH1D("h_trkmom_signal_nostopmu", "; Track length;", n_bins_mumom, bins_mumom);

      // Efficiency - Single Differential (mumom) - Multisim
      bs_genie_multisim_eff_mumom_num = new BootstrapTH1D("bs_genie_multisim_eff_mumom_num", "bs_genie_multisim_eff_mumom_num_title", n_bins_mumom, bins_mumom);
      bs_genie_multisim_eff_mumom_den = new BootstrapTH1D("bs_genie_multisim_eff_mumom_den", "bs_genie_multisim_eff_mumom_den_title", n_bins_mumom, bins_mumom);
      bs_flux_multisim_eff_mumom_num = new BootstrapTH1D("bs_flux_multisim_eff_mumom_num", "bs_flux_multisim_eff_mumom_num_title", n_bins_mumom, bins_mumom);
      bs_flux_multisim_eff_mumom_den = new BootstrapTH1D("bs_flux_multisim_eff_mumom_den", "bs_flux_multisim_eff_mumom_den_title", n_bins_mumom, bins_mumom);
      bs_extra_syst_multisim_eff_mumom_num = new BootstrapTH1D("bs_extra_syst_multisim_eff_mumom_num", "bs_extra_syst_eff_mumom_num_title", n_bins_mumom, bins_mumom);
      bs_extra_syst_multisim_eff_mumom_den = new BootstrapTH1D("bs_extra_syst_multisim_eff_mumom_den", "bs_extra_syst_eff_mumom_den_title", n_bins_mumom, bins_mumom);
      bs_mc_stat_multisim_eff_mumom_num = new BootstrapTH1D("bs_mc_stat_multisim_eff_mumom_num", "bs_mc_stat_eff_mumom_num_title", n_bins_mumom, bins_mumom);
      bs_mc_stat_multisim_eff_mumom_den = new BootstrapTH1D("bs_mc_stat_multisim_eff_mumom_den", "bs_mc_stat_eff_mumom_den_title", n_bins_mumom, bins_mumom);

      // Number of events per channel and universe - Single Differential (mumom) - Genie Multisim
      hmap_trkmom_genie_multisim_bs["total"]["nominal"] = new TH1D("h_trkmom_total_genie_mulinominal", "; Track length;", n_bins_mumom, bins_mumom); // 20, 0, 2.5
      hmap_trkmom_genie_multisim_bs["signal"]["nominal"] = new TH1D("h_trkmom_signal_genie_mulinominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_genie_multisim_bs["cosmic"]["nominal"] = new TH1D("h_trkmom_cosmic_genie_mulinominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_genie_multisim_bs["outfv"]["nominal"] = new TH1D("h_trkmom_outfv_genie_mulinominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_genie_multisim_bs["nc"]["nominal"] = new TH1D("h_trkmom_nc_genie_mulinominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_genie_multisim_bs["anumu"]["nominal"] = new TH1D("h_trkmom_anumu_genie_mulinominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_genie_multisim_bs["nue"]["nominal"] = new TH1D("h_trkmom_nue_genie_mulinominal", "; Track length;", n_bins_mumom, bins_mumom);

      // Number of events per channel and universe - Single Differential (mumom) - Flux Multisim
      hmap_trkmom_flux_multisim_bs["total"]["nominal"] = new TH1D("h_trkmom_total_flux_mulinominal", "; Track length;", n_bins_mumom, bins_mumom); // 20, 0, 2.5
      hmap_trkmom_flux_multisim_bs["signal"]["nominal"] = new TH1D("h_trkmom_signal_flux_mulinominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_flux_multisim_bs["cosmic"]["nominal"] = new TH1D("h_trkmom_cosmic_flux_mulinominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_flux_multisim_bs["outfv"]["nominal"] = new TH1D("h_trkmom_outfv_flux_mulinominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_flux_multisim_bs["nc"]["nominal"] = new TH1D("h_trkmom_nc_flux_mulinominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_flux_multisim_bs["anumu"]["nominal"] = new TH1D("h_trkmom_anumu_flux_mulinominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_flux_multisim_bs["nue"]["nominal"] = new TH1D("h_trkmom_nue_flux_mulinominal", "; Track length;", n_bins_mumom, bins_mumom);

      // Number of events per channel and universe - Single Differential (mumom) - Extra Syst
      hmap_trkmom_extra_syst_multisim_bs["total"]["nominal"] = new TH1D("h_trkmom_total_extra_syst_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom); // 20, 0, 2.5
      hmap_trkmom_extra_syst_multisim_bs["signal"]["nominal"] = new TH1D("h_trkmom_signal_extra_syst_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_extra_syst_multisim_bs["cosmic"]["nominal"] = new TH1D("h_trkmom_cosmic_extra_syst_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_extra_syst_multisim_bs["outfv"]["nominal"] = new TH1D("h_trkmom_outfv_extra_syst_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_extra_syst_multisim_bs["nc"]["nominal"] = new TH1D("h_trkmom_nc_extra_syst_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_extra_syst_multisim_bs["anumu"]["nominal"] = new TH1D("h_trkmom_anumu_extra_syst_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_extra_syst_multisim_bs["nue"]["nominal"] = new TH1D("h_trkmom_nue_extra_syst_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom);

      // Number of events per channel and universe - Single Differential (mumom) - MC Stat
      hmap_trkmom_mc_stat_multisim_bs["total"]["nominal"] = new TH1D("h_trkmom_total_mc_stat_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom); // 20, 0, 2.5
      hmap_trkmom_mc_stat_multisim_bs["signal"]["nominal"] = new TH1D("h_trkmom_signal_mc_stat_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_mc_stat_multisim_bs["cosmic"]["nominal"] = new TH1D("h_trkmom_cosmic_mc_stat_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_mc_stat_multisim_bs["outfv"]["nominal"] = new TH1D("h_trkmom_outfv_mc_stat_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_mc_stat_multisim_bs["nc"]["nominal"] = new TH1D("h_trkmom_nc_mc_stat_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_mc_stat_multisim_bs["anumu"]["nominal"] = new TH1D("h_trkmom_anumu_mc_stat_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom);
      hmap_trkmom_mc_stat_multisim_bs["nue"]["nominal"] = new TH1D("h_trkmom_nue_mc_stat_multisim_nominal", "; Track length;", n_bins_mumom, bins_mumom);

      // Reco to true histograms for every universe - Single Differential (mumom) - Genie Multisim
      bs_genie_multisim_true_reco_mumom = new BootstrapTH2D("bs_genie_multisim_true_reco_mumom", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", n_bins_mumom, bins_mumom, n_bins_mumom, bins_mumom);
      bs_flux_multisim_true_reco_mumom = new BootstrapTH2D("bs_flux_multisim_true_reco_mumom", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", n_bins_mumom, bins_mumom, n_bins_mumom, bins_mumom);
      bs_extra_syst_true_reco_mumom = new BootstrapTH2D("bs_extra_syst_true_reco_mumom", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", n_bins_mumom, bins_mumom, n_bins_mumom, bins_mumom);
      bs_mc_stat_multisim_true_reco_mumom = new BootstrapTH2D("bs_mc_stat_multisim_true_reco_mumom", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", n_bins_mumom, bins_mumom, n_bins_mumom, bins_mumom);


      //
      // Single differential (muangle)
      //

      // Efficiency - Single Differential (muangle)
      h_eff_muangle_num = new TH1D("h_eff_muangle_num", "h_eff_muangle_num", n_bins_mucostheta, bins_mucostheta);
      h_eff_muangle_den = new TH1D("h_eff_muangle_den", "h_eff_muangle_den", n_bins_mucostheta, bins_mucostheta);

      // Reco to true histograms - Single Differential (muangle)
      h_true_reco_costheta= new TH2D("h_true_reco_costheta", ";Muon cos(#theta) (Truth) [GeV]; Muon cos(#theta) (MCS) [GeV]", n_bins_mucostheta, bins_mucostheta, n_bins_mucostheta, bins_mucostheta);

      // Number of events per channel - Single Differential (muangle)
      hmap_trktheta["total"] = new TH1D("h_trktheta_total", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["signal"] = new TH1D("h_trktheta_signal", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["cosmic"] = new TH1D("h_trktheta_cosmic", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["outfv"] = new TH1D("h_trktheta_outfv", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["nc"] = new TH1D("h_trktheta_nc", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["anumu"] = new TH1D("h_trktheta_anumu", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["nue"] = new TH1D("h_trktheta_nue", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["cosmic_stopmu"] = new TH1D("h_trktheta_cosmic_stopmu", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["cosmic_nostopmu"] = new TH1D("h_trktheta_cosmic_nostopmu", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["outfv_stopmu"] = new TH1D("h_trktheta_outfv_stopmu", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["outfv_nostopmu"] = new TH1D("h_trktheta_outfv_nostopmu", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["nc_proton"] = new TH1D("h_trktheta_nc_proton", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["nc_pion"] = new TH1D("h_trktheta_nc_pion", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["nc_other"] = new TH1D("h_trktheta_nc_other", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["signal_stopmu"] = new TH1D("h_trktheta_signal_stopmu", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);
      hmap_trktheta["signal_nostopmu"] = new TH1D("h_trktheta_signal_nostopmu", "; Track cos(#theta);", n_bins_mucostheta, bins_mucostheta);

      // Efficiency - Single Differential (muangle) - Multisim
      bs_genie_multisim_eff_muangle_num = new BootstrapTH1D("bs_genie_multisim_eff_muangle_num", "bs_genie_multisim_eff_muangle_num_title", n_bins_mucostheta, bins_mucostheta);
      bs_genie_multisim_eff_muangle_den = new BootstrapTH1D("bs_genie_multisim_eff_muangle_den", "bs_genie_multisim_eff_muangle_den_title", n_bins_mucostheta, bins_mucostheta);
      bs_flux_multisim_eff_muangle_num = new BootstrapTH1D("bs_flux_multisim_eff_muangle_num", "bs_flux_multisim_eff_muangle_num_title", n_bins_mucostheta, bins_mucostheta);
      bs_flux_multisim_eff_muangle_den = new BootstrapTH1D("bs_flux_multisim_eff_muangle_den", "bs_flux_multisim_eff_muangle_den_title", n_bins_mucostheta, bins_mucostheta);
      bs_extra_syst_multisim_eff_muangle_num = new BootstrapTH1D("bs_extra_syst_multisim_eff_muangle_num", "bs_extra_syst_eff_muangle_num_title", n_bins_mucostheta, bins_mucostheta);
      bs_extra_syst_multisim_eff_muangle_den = new BootstrapTH1D("bs_extra_syst_multisim_eff_muangle_den", "bs_extra_syst_eff_muangle_den_title", n_bins_mucostheta, bins_mucostheta);
      bs_mc_stat_multisim_eff_muangle_num = new BootstrapTH1D("bs_mc_stat_multisim_eff_muangle_num", "bs_mc_stat_eff_muangle_num_title", n_bins_mucostheta, bins_mucostheta);
      bs_mc_stat_multisim_eff_muangle_den = new BootstrapTH1D("bs_mc_stat_multisim_eff_muangle_den", "bs_mc_stat_eff_muangle_den_title", n_bins_mucostheta, bins_mucostheta);

      // Number of events per channel and universe - Single Differential (muangle) - Genie Multisim
      hmap_trkangle_genie_multisim_bs["total"]["nominal"] = new TH1D("h_trkangle_total_genie_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta); // 20, 0, 2.5
      hmap_trkangle_genie_multisim_bs["signal"]["nominal"] = new TH1D("h_trkangle_signal_genie_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_genie_multisim_bs["cosmic"]["nominal"] = new TH1D("h_trkangle_cosmic_genie_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_genie_multisim_bs["outfv"]["nominal"] = new TH1D("h_trkangle_outfv_genie_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_genie_multisim_bs["nc"]["nominal"] = new TH1D("h_trkangle_nc_genie_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_genie_multisim_bs["anumu"]["nominal"] = new TH1D("h_trkangle_anumu_genie_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_genie_multisim_bs["nue"]["nominal"] = new TH1D("h_trkangle_nue_genie_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);

      // Number of events per channel and universe - Single Differential (muangle) - Flux Multisim
      hmap_trkangle_flux_multisim_bs["total"]["nominal"] = new TH1D("h_trkangle_total_flux_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta); // 20, 0, 2.5
      hmap_trkangle_flux_multisim_bs["signal"]["nominal"] = new TH1D("h_trkangle_signal_flux_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_flux_multisim_bs["cosmic"]["nominal"] = new TH1D("h_trkangle_cosmic_flux_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_flux_multisim_bs["outfv"]["nominal"] = new TH1D("h_trkangle_outfv_flux_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_flux_multisim_bs["nc"]["nominal"] = new TH1D("h_trkangle_nc_flux_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_flux_multisim_bs["anumu"]["nominal"] = new TH1D("h_trkangle_anumu_flux_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_flux_multisim_bs["nue"]["nominal"] = new TH1D("h_trkangle_nue_flux_mulinominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);

      // Number of events per channel and universe - Single Differential (muangle) - Extra Syst
      hmap_trkangle_extra_syst_multisim_bs["total"]["nominal"] = new TH1D("h_trkangle_total_extra_syst_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta); // 20, 0, 2.5
      hmap_trkangle_extra_syst_multisim_bs["signal"]["nominal"] = new TH1D("h_trkangle_signal_extra_syst_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_extra_syst_multisim_bs["cosmic"]["nominal"] = new TH1D("h_trkangle_cosmic_extra_syst_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_extra_syst_multisim_bs["outfv"]["nominal"] = new TH1D("h_trkangle_outfv_extra_syst_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_extra_syst_multisim_bs["nc"]["nominal"] = new TH1D("h_trkangle_nc_extra_syst_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_extra_syst_multisim_bs["anumu"]["nominal"] = new TH1D("h_trkangle_anumu_extra_syst_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_extra_syst_multisim_bs["nue"]["nominal"] = new TH1D("h_trkangle_nue_extra_syst_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);

      // Number of events per channel and universe - Single Differential (muangle) - MC Stat
      hmap_trkangle_mc_stat_multisim_bs["total"]["nominal"] = new TH1D("h_trkangle_total_mc_stat_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta); // 20, 0, 2.5
      hmap_trkangle_mc_stat_multisim_bs["signal"]["nominal"] = new TH1D("h_trkangle_signal_mc_stat_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_mc_stat_multisim_bs["cosmic"]["nominal"] = new TH1D("h_trkangle_cosmic_mc_stat_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_mc_stat_multisim_bs["outfv"]["nominal"] = new TH1D("h_trkangle_outfv_mc_stat_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_mc_stat_multisim_bs["nc"]["nominal"] = new TH1D("h_trkangle_nc_mc_stat_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_mc_stat_multisim_bs["anumu"]["nominal"] = new TH1D("h_trkangle_anumu_mc_stat_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);
      hmap_trkangle_mc_stat_multisim_bs["nue"]["nominal"] = new TH1D("h_trkangle_nue_mc_stat_multisim_nominal", "; Track length;", n_bins_mucostheta, bins_mucostheta);

      // Reco to true histograms for every universe - Single Differential (muangle) - Genie Multisim
      bs_genie_multisim_true_reco_muangle = new BootstrapTH2D("bs_genie_multisim_true_reco_muangle", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", n_bins_mucostheta, bins_mucostheta, n_bins_mucostheta, bins_mucostheta);
      bs_flux_multisim_true_reco_muangle = new BootstrapTH2D("bs_flux_multisim_true_reco_muangle", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", n_bins_mucostheta, bins_mucostheta, n_bins_mucostheta, bins_mucostheta);
      bs_extra_syst_true_reco_muangle = new BootstrapTH2D("bs_extra_syst_true_reco_muangle", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", n_bins_mucostheta, bins_mucostheta, n_bins_mucostheta, bins_mucostheta);
      bs_mc_stat_multisim_true_reco_muangle = new BootstrapTH2D("bs_mc_stat_multisim_true_reco_muangle", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", n_bins_mucostheta, bins_mucostheta, n_bins_mucostheta, bins_mucostheta);

    }

  }

#endif

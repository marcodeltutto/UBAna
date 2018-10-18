#ifndef __DATATYPES_UBXSECEVENTHISTO_CXX__
#define __DATATYPES_UBXSECEVENTHISTO_CXX__

#include "UBXSecEventHisto.h"


namespace DataTypes {


    void UBXSecEventHisto::InitializeBootstraps()
    {

      double n_bins_double_mucostheta = _n_bins_double_mucostheta;
      double * bins_double_mucostheta = _bins_double_mucostheta;
      double n_bins_double_mumom = _n_bins_double_mumom;
      double * bins_double_mumom = _bins_double_mumom;


      //
      // Double differential
      //

      // Efficiency - Double differential
      h_eff_muangle_mumom_num = new TH2D("h_eff_muangle_mumom_num", "h_eff_muangle_mumom_num", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      h_eff_muangle_mumom_den = new TH2D("h_eff_muangle_mumom_den", "h_eff_muangle_mumom_den", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);

      // Reco per true histograms - Double Differential
      h_reco_per_true.resize(n_bins_double_mucostheta, std::vector<TH2D*>(n_bins_double_mumom));
      for (int m = 0; m < n_bins_double_mucostheta; m++) {
        for (int n = 0; n < n_bins_double_mumom; n++) { 
          std::stringstream sstm;
          sstm << "reco_per_true_" << m << "_" << n; 
          h_reco_per_true[m][n] = new TH2D(sstm.str().c_str(), "reco_per_true", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
        }
      }

      // Number of events per channel - Double differential
      hmap_trktheta_trkmom["total"] = new TH2D("h_trktheta_trkmom_total", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["signal"] = new TH2D("h_trktheta_trkmom_signal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["cosmic"] = new TH2D("h_trktheta_trkmom_cosmic", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["outfv"] = new TH2D("h_trktheta_trkmom_outfv", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["nc"] = new TH2D("h_trktheta_trkmom_nc", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["anumu"] = new TH2D("h_trktheta_trkmom_anumu", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["nue"] = new TH2D("h_trktheta_trkmom_nue", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["cosmic_stopmu"] = new TH2D("h_trktheta_trkmom_cosmic_stopmu", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["cosmic_nostopmu"] = new TH2D("h_trktheta_trkmom_cosmic_nostopmu", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["outfv_stopmu"] = new TH2D("h_trktheta_trkmom_outfv_stopmu", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["outfv_nostopmu"] = new TH2D("h_trktheta_trkmom_outfv_nostopmu", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["nc_proton"] = new TH2D("h_trktheta_trkmom_nc_proton", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["nc_pion"] = new TH2D("h_trktheta_trkmom_nc_pion", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["nc_other"] = new TH2D("h_trktheta_trkmom_nc_other", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["signal_stopmu"] = new TH2D("h_trktheta_trkmom_signal_stopmu", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom["signal_nostopmu"] = new TH2D("h_trktheta_trkmom_signal_nostopmu", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);

      // Efficiency - Double Differential - Multisim
      bs_genie_multisim_eff_muangle_mumom_num = new BootstrapTH2D("bs_genie_multisim_eff_muangle_mumom_num", "bs_genie_multisim_eff_muangle_mumom_num_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      bs_genie_multisim_eff_muangle_mumom_den = new BootstrapTH2D("bs_genie_multisim_eff_muangle_mumom_den", "bs_genie_multisim_eff_muangle_mumom_den_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      bs_flux_multisim_eff_muangle_mumom_num = new BootstrapTH2D("bs_flux_multisim_eff_muangle_mumom_num", "bs_flux_multisim_eff_muangle_mumom_num_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      bs_flux_multisim_eff_muangle_mumom_den = new BootstrapTH2D("bs_flux_multisim_eff_muangle_mumom_den", "bs_flux_multisim_eff_muangle_mumom_den_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      bs_extra_syst_multisim_eff_muangle_mumom_num = new BootstrapTH2D("bs_extra_syst_multisim_eff_muangle_mumom_num", "bs_extra_syst_eff_muangle_mumom_num_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      bs_extra_syst_multisim_eff_muangle_mumom_den = new BootstrapTH2D("bs_extra_syst_multisim_eff_muangle_mumom_den", "bs_extra_syst_eff_muangle_mumom_den_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      bs_mc_stat_multisim_eff_muangle_mumom_num = new BootstrapTH2D("bs_mc_stat_multisim_eff_muangle_mumom_num", "bs_mc_stat_eff_muangle_mumom_num_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      bs_mc_stat_multisim_eff_muangle_mumom_den = new BootstrapTH2D("bs_mc_stat_multisim_eff_muangle_mumom_den", "bs_mc_stat_eff_muangle_mumom_den_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);

      // Number of events per channel and universe - Double Differential PolyBins - Genie Multisim
      hmap_trktheta_trkmom_genie_multisim_bs["total"]["nominal"] = new TH2D("h_trktheta_trkmom_total_genie_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_genie_multisim_bs["signal"]["nominal"] = new TH2D("h_trktheta_trkmom_signal_genie_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_genie_multisim_bs["cosmic"]["nominal"] = new TH2D("h_trktheta_trkmom_cosmic_genie_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_genie_multisim_bs["outfv"]["nominal"] = new TH2D("h_trktheta_trkmom_outfv_genie_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_genie_multisim_bs["nc"]["nominal"] = new TH2D("h_trktheta_trkmom_nc_genie_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_genie_multisim_bs["anumu"]["nominal"] = new TH2D("h_trktheta_trkmom_anumu_genie_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_genie_multisim_bs["nue"]["nominal"] = new TH2D("h_trktheta_trkmom_nue_genie_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);

      // Number of events per channel and universe - Double Differential - Flux Multisim
      hmap_trktheta_trkmom_flux_multisim_bs["total"]["nominal"] = new TH2D("h_trktheta_trkmom_total_flux_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_flux_multisim_bs["signal"]["nominal"] = new TH2D("h_trktheta_trkmom_signal_flux_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_flux_multisim_bs["cosmic"]["nominal"] = new TH2D("h_trktheta_trkmom_cosmic_flux_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_flux_multisim_bs["outfv"]["nominal"] = new TH2D("h_trktheta_trkmom_outfv_flux_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_flux_multisim_bs["nc"]["nominal"] = new TH2D("h_trktheta_trkmom_nc_flux_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_flux_multisim_bs["anumu"]["nominal"] = new TH2D("h_trktheta_trkmom_anumu_flux_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_flux_multisim_bs["nue"]["nominal"] = new TH2D("h_trktheta_trkmom_nue_flux_multisim_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);

      // Number of events per channel and universe - Double Differential - Extra Syst
      hmap_trktheta_trkmom_extra_syst_multisim_bs["total"]["nominal"] = new TH2D("h_trktheta_trkmom_total_extra_syst_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_extra_syst_multisim_bs["signal"]["nominal"] = new TH2D("h_trktheta_trkmom_signal_extra_syst_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_extra_syst_multisim_bs["cosmic"]["nominal"] = new TH2D("h_trktheta_trkmom_cosmic_extra_syst_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_extra_syst_multisim_bs["outfv"]["nominal"] = new TH2D("h_trktheta_trkmom_outfv_extra_syst_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_extra_syst_multisim_bs["nc"]["nominal"] = new TH2D("h_trktheta_trkmom_nc_extra_syst_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_extra_syst_multisim_bs["anumu"]["nominal"] = new TH2D("h_trktheta_trkmom_anumu_extra_syst_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_extra_syst_multisim_bs["nue"]["nominal"] = new TH2D("h_trktheta_trkmom_nue_extra_syst_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);

      // Number of events per channel and universe - Double Differential - MC Stat
      hmap_trktheta_trkmom_mc_stat_multisim_bs["total"]["nominal"] = new TH2D("h_trktheta_trkmom_total_mc_stat_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_mc_stat_multisim_bs["signal"]["nominal"] = new TH2D("h_trktheta_trkmom_signal_mc_stat_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_mc_stat_multisim_bs["cosmic"]["nominal"] = new TH2D("h_trktheta_trkmom_cosmic_mc_stat_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_mc_stat_multisim_bs["outfv"]["nominal"] = new TH2D("h_trktheta_trkmom_outfv_mc_stat_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_mc_stat_multisim_bs["nc"]["nominal"] = new TH2D("h_trktheta_trkmom_nc_mc_stat_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_mc_stat_multisim_bs["anumu"]["nominal"] = new TH2D("h_trktheta_trkmom_anumu_mc_stat_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      hmap_trktheta_trkmom_mc_stat_multisim_bs["nue"]["nominal"] = new TH2D("h_trktheta_trkmom_nue_mc_stat_nominal", "; Track cos(#theta);", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);

      // Reco per true histograms per universe - Double Differential - Genie Multisim
      bs_genie_multisim_reco_per_true["nominal"].resize(_n_bins_double_mucostheta, std::vector<TH2D*>(_n_bins_double_mumom));
      for (int m = 0; m < _n_bins_double_mucostheta; m++) {
        for (int n = 0; n < _n_bins_double_mumom; n++) { 
          std::stringstream sstm;
          sstm << "bs_genie_multisim_reco_per_true_nominal_" << m << "_" << n;
          bs_genie_multisim_reco_per_true["nominal"][m][n] = new TH2D(sstm.str().c_str(), "reco_per_true", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
        }
      }

      // Reco per true histograms per universe - Double Differential - Flux Multisim
      bs_flux_multisim_reco_per_true["nominal"].resize(n_bins_double_mucostheta, std::vector<TH2D*>(n_bins_double_mumom));
      for (int m = 0; m < n_bins_double_mucostheta; m++) {
        for (int n = 0; n < n_bins_double_mumom; n++) { 
          std::stringstream sstm;
          sstm << "bs_flux_multisim_reco_per_true_nominal_" << m << "_" << n;
          bs_flux_multisim_reco_per_true["nominal"][m][n] = new TH2D(sstm.str().c_str(), "reco_per_true", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
        }
      }    

      // Reco per true histograms per universe - Double Differential - Extra Syst
      bs_extra_syst_multisim_reco_per_true["nominal"].resize(n_bins_double_mucostheta, std::vector<TH2D*>(n_bins_double_mumom));
      for (int m = 0; m < n_bins_double_mucostheta; m++) {
        for (int n = 0; n < n_bins_double_mumom; n++) { 
          std::stringstream sstm;
          sstm << "bs_extra_syst_multisim_reco_per_true_nominal_" << m << "_" << n;
          bs_extra_syst_multisim_reco_per_true["nominal"][m][n] = new TH2D(sstm.str().c_str(), "reco_per_true", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
        }
      }

      // Reco per true histograms per universe - Double Differential - MC Stat
      bs_mc_stat_multisim_reco_per_true["nominal"].resize(n_bins_double_mucostheta, std::vector<TH2D*>(n_bins_double_mumom));
      for (int m = 0; m < n_bins_double_mucostheta; m++) {
        for (int n = 0; n < n_bins_double_mumom; n++) { 
          std::stringstream sstm;
          sstm << "bs_mc_stat_multisim_reco_per_true_nominal_" << m << "_" << n;
          bs_mc_stat_multisim_reco_per_true["nominal"][m][n] = new TH2D(sstm.str().c_str(), "reco_per_true", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
        }
      }



      //
      // Double differential (polybin)
      //

      // Efficiency - Double differential (polybin)
      h_eff_muangle_mumom_poly_num = new UBTH2Poly("h_eff_muangle_mumom_poly_num", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      h_eff_muangle_mumom_poly_den = new UBTH2Poly("h_eff_muangle_mumom_poly_den", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);

      // Number of events per channel - Double differential (polybin)
      hmap_trktheta_trkmom_poly["total"] = new UBTH2Poly("h_trktheta_trkmom_poly_total", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["signal"] = new UBTH2Poly("h_trktheta_trkmom_poly_signal", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["cosmic"] = new UBTH2Poly("h_trktheta_trkmom_poly_cosmic", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["outfv"] = new UBTH2Poly("h_trktheta_trkmom_poly_outfv", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["nc"] = new UBTH2Poly("h_trktheta_trkmom_poly_nc", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["anumu"] = new UBTH2Poly("h_trktheta_trkmom_poly_anumu", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["nue"] = new UBTH2Poly("h_trktheta_trkmom_poly_nue", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["cosmic_stopmu"] = new UBTH2Poly("h_trktheta_trkmom_poly_cosmic_stopmu", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["cosmic_nostopmu"] = new UBTH2Poly("h_trktheta_trkmom_poly_cosmic_nostopmu", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["outfv_stopmu"] = new UBTH2Poly("h_trktheta_trkmom_poly_outfv_stopmu", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["outfv_nostopmu"] = new UBTH2Poly("h_trktheta_trkmom_poly_outfv_nostopmu", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["nc_proton"] = new UBTH2Poly("h_trktheta_trkmom_poly_nc_proton", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["nc_pion"] = new UBTH2Poly("h_trktheta_trkmom_poly_nc_pion", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["nc_other"] = new UBTH2Poly("h_trktheta_trkmom_poly_nc_other", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["signal_stopmu"] = new UBTH2Poly("h_trktheta_trkmom_poly_signal_stopmu", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly["signal_nostopmu"] = new UBTH2Poly("h_trktheta_trkmom_poly_signal_nostopmu", ";cos(#theta);p_{#mu}", -1., 1., 0., 2.5);

      h_poly_reco_per_true.resize(_n_poly_bins);
      for (int m = 0; m < _n_poly_bins; m++) {
        std::stringstream sstm;
        sstm << "poly_reco_per_true_" << m; 
        h_poly_reco_per_true[m] = new UBTH2Poly(sstm.str().c_str(), "poly_reco_per_true", -1., 1., 0., 2.5);
      }

      // Efficiency - Double Differential PolyBins - Multisim
      bs_genie_multisim_eff_poly_muangle_mumom_num = new BootstrapTH2DPoly("bs_genie_multisim_eff_poly_muangle_mumom_num", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      bs_genie_multisim_eff_poly_muangle_mumom_den = new BootstrapTH2DPoly("bs_genie_multisim_eff_poly_muangle_mumom_den", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      bs_flux_multisim_eff_poly_muangle_mumom_num = new BootstrapTH2DPoly("bs_flux_multisim_eff_poly_muangle_mumom_num", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      bs_flux_multisim_eff_poly_muangle_mumom_den = new BootstrapTH2DPoly("bs_flux_multisim_eff_poly_muangle_mumom_den", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      bs_extra_syst_multisim_eff_poly_muangle_mumom_num = new BootstrapTH2DPoly("bs_extra_syst_multisim_eff_poly_muangle_mumom_num", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      bs_extra_syst_multisim_eff_poly_muangle_mumom_den = new BootstrapTH2DPoly("bs_extra_syst_multisim_eff_poly_muangle_mumom_den", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      bs_mc_stat_multisim_eff_poly_muangle_mumom_num = new BootstrapTH2DPoly("bs_mc_stat_multisim_eff_poly_muangle_mumom_num", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      bs_mc_stat_multisim_eff_poly_muangle_mumom_den = new BootstrapTH2DPoly("bs_mc_stat_multisim_eff_poly_muangle_mumom_den", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      
      // Number of events per channel and universe - Double Differential PolyBins - Genie Multisim
      hmap_trktheta_trkmom_poly_genie_multisim_bs["total"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_total_genie_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_genie_multisim_bs["signal"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_signal_genie_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_genie_multisim_bs["cosmic"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_cosmic_genie_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_genie_multisim_bs["outfv"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_outfv_genie_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_genie_multisim_bs["nc"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_nc_genie_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_genie_multisim_bs["anumu"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_anumu_genie_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_genie_multisim_bs["nue"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_nue_genie_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);

      // Number of events per channel and universe - Double Differential PolyBins - Flux Multisim
      hmap_trktheta_trkmom_poly_flux_multisim_bs["total"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_total_flux_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_flux_multisim_bs["signal"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_signal_flux_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_flux_multisim_bs["cosmic"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_cosmic_flux_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_flux_multisim_bs["outfv"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_outfv_flux_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_flux_multisim_bs["nc"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_nc_flux_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_flux_multisim_bs["anumu"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_anumu_flux_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_flux_multisim_bs["nue"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_nue_flux_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);

      // Number of events per channel and universe - Double Differential PolyBins - Extra Syst
      hmap_trktheta_trkmom_poly_extra_syst_multisim_bs["total"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_total_extra_syst_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_extra_syst_multisim_bs["signal"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_signal_extra_syst_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_extra_syst_multisim_bs["cosmic"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_cosmic_extra_syst_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_extra_syst_multisim_bs["outfv"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_outfv_extra_syst_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_extra_syst_multisim_bs["nc"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_nc_extra_syst_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_extra_syst_multisim_bs["anumu"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_anumu_extra_syst_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_extra_syst_multisim_bs["nue"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_nue_extra_syst_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);

      // Number of events per channel and universe - Double Differential PolyBins - MC Stat
      hmap_trktheta_trkmom_poly_mc_stat_multisim_bs["total"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_total_mc_stat_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_mc_stat_multisim_bs["signal"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_signal_mc_stat_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_mc_stat_multisim_bs["cosmic"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_cosmic_mc_stat_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_mc_stat_multisim_bs["outfv"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_outfv_mc_stat_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_mc_stat_multisim_bs["nc"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_nc_mc_stat_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_mc_stat_multisim_bs["anumu"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_anumu_mc_stat_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);
      hmap_trktheta_trkmom_poly_mc_stat_multisim_bs["nue"]["nominal"] = new UBTH2Poly("h_trktheta_trkmom_poly_nue_mc_stat_multisim_nominal", "; Track cos(#theta);", -1., 1., 0., 2.5);

      // Reco per true histograms per universe - Double Differential PolyBins - Genie Multisim
      bs_genie_multisim_poly_reco_per_true["nominal"].resize(_n_poly_bins);
      for (int m = 0; m < _n_poly_bins; m++) {
        bs_genie_multisim_poly_reco_per_true["nominal"][m].resize(_n_poly_bins, 0.);
      }

      // Reco per true histograms per universe - Double Differential PolyBins - Flux Multisim
      bs_flux_multisim_poly_reco_per_true["nominal"].resize(_n_poly_bins);
      for (int m = 0; m < _n_poly_bins; m++) {
        bs_flux_multisim_poly_reco_per_true["nominal"][m].resize(_n_poly_bins, 0.);
      }

      // Reco per true histograms per universe - Double Differential PolyBins - Extra Syst
      bs_extra_syst_multisim_poly_reco_per_true["nominal"].resize(_n_poly_bins);
      for (int m = 0; m < _n_poly_bins; m++) {
        bs_extra_syst_multisim_poly_reco_per_true["nominal"][m].resize(_n_poly_bins, 0.);
      }

      // Reco per true histograms per universe - Double Differential PolyBins - MC Stat
      bs_mc_stat_multisim_poly_reco_per_true["nominal"].resize(_n_poly_bins);
      for (int m = 0; m < _n_poly_bins; m++) {
        bs_mc_stat_multisim_poly_reco_per_true["nominal"][m].resize(_n_poly_bins, 0.);
      }

    }




    void UBXSecEventHisto::AddPolyBins() {

      _AddPolyBins_(h_eff_muangle_mumom_poly_num);
      _AddPolyBins_(h_eff_muangle_mumom_poly_den);
      _AddPolyBins_(hmap_trktheta_trkmom_poly);
      _AddPolyBins_(h_poly_reco_per_true);

      _AddPolyBins_(bs_genie_multisim_eff_poly_muangle_mumom_num);
      _AddPolyBins_(bs_genie_multisim_eff_poly_muangle_mumom_den);
      _AddPolyBins_(bs_flux_multisim_eff_poly_muangle_mumom_num);
      _AddPolyBins_(bs_flux_multisim_eff_poly_muangle_mumom_den);
      _AddPolyBins_(bs_extra_syst_multisim_eff_poly_muangle_mumom_num);
      _AddPolyBins_(bs_extra_syst_multisim_eff_poly_muangle_mumom_den);
      _AddPolyBins_(bs_mc_stat_multisim_eff_poly_muangle_mumom_num);
      _AddPolyBins_(bs_mc_stat_multisim_eff_poly_muangle_mumom_den);

      _AddPolyBins_(hmap_trktheta_trkmom_poly_genie_multisim_bs);
      _AddPolyBins_(hmap_trktheta_trkmom_poly_flux_multisim_bs);
      _AddPolyBins_(hmap_trktheta_trkmom_poly_extra_syst_multisim_bs);
      _AddPolyBins_(hmap_trktheta_trkmom_poly_mc_stat_multisim_bs);

      UBTH2Poly* h_poly_binnumber = h_eff_muangle_mumom_poly_num->GetCopyWithBinNumbers("bs");
      TCanvas* canvas_binnumber_poly = new TCanvas("canvas_binnumber_poly", "canvas", 800, 700);
      // gStyle->SetPaintTextFormat("4.0f");
      h_poly_binnumber->Draw("text");
      canvas_binnumber_poly->SaveAs("bin_numbers.pdf");

    }





    void UBXSecEventHisto::_AddPolyBins_(std::map<std::string,UBTH2Poly*> h) {
      for (auto it : h) {
        _AddPolyBins_(it.second);
      }
    }

    void UBXSecEventHisto::_AddPolyBins_(std::vector<UBTH2Poly*> h) {
      for (auto h1 : h) {
        _AddPolyBins_(h1);
      }
    }

    void UBXSecEventHisto::_AddPolyBins_(std::vector<std::vector<UBTH2Poly*>> h) {
      for (int i = 0; i < (int)h.size(); i++) {
        for (int m = 0; m < _n_poly_bins; m++) {
          _AddPolyBins_(h.at(i).at(m));
        }
      }
    }

    void UBXSecEventHisto::_AddPolyBins_(std::map<std::string,std::vector<UBTH2Poly*>> h) {
      for (auto it1 : h) {
        for (int m = 0; m < _n_poly_bins; m++) {
          _AddPolyBins_(it1.second.at(m));
        }
      }
    }


    void UBXSecEventHisto::_AddPolyBins_(std::map<std::string,std::map<std::string,UBTH2Poly*>> h) {
      for (auto it1 : h) { 
        for (auto it2 : it1.second) { 
          _AddPolyBins_(it2.second); 
        } 
      }
    }


    void UBXSecEventHisto::_AddPolyBins_(BootstrapTH2DPoly * h) {

      std::map<int, std::pair<int, int>> _exclusion_map2 = { {4, std::make_pair(0, 1)},
                                                             {5, std::make_pair(0, 1)}, };

      h->SetNBinsX(_n_bins_double_mucostheta);

      int separator_counter = 0;
      std::vector<int> separators;
      separators.clear();

      for (int x = 0; x < _n_bins_double_mucostheta; x++) {
        for (int y = 0; y < _n_bins_double_mumom; y++) {

          auto it = _exclusion_map1.find(x);
          if (it != _exclusion_map1.end()) {
            if (y == it->second.first) {
              separator_counter++;
              h->AddBin(_bins_double_mucostheta[it->first], _bins_double_mumom[it->second.first], _bins_double_mucostheta[it->first+1], _bins_double_mumom[it->second.second+1]);
              continue;
            } else if (y == it->second.second) {
              continue;
            }
          }

          it = _exclusion_map2.find(x);
          if (it != _exclusion_map2.end()) {
            if (y == it->second.first) {
              separator_counter++;
              h->AddBin(_bins_double_mucostheta[it->first], _bins_double_mumom[it->second.first], _bins_double_mucostheta[it->first+1], _bins_double_mumom[it->second.second+1]);
              continue;
            } else if (y == it->second.second) {
              continue;
            }
          }

          separator_counter++;
          h->AddBin(_bins_double_mucostheta[x], _bins_double_mumom[y], _bins_double_mucostheta[x+1], _bins_double_mumom[y+1]);
        }
        separators.emplace_back(separator_counter);
        separator_counter = 0;
      }

      h->SetSeparators(separators);
    }


    void UBXSecEventHisto::_AddPolyBins_(UBTH2Poly * h) {

      std::map<int, std::pair<int, int>> _exclusion_map2 = { {4, std::make_pair(0, 1)},
                                                             {5, std::make_pair(0, 1)}, };

      h->SetNBinsX(_n_bins_double_mucostheta);

      int separator_counter = 0;
      std::vector<int> separators;
      separators.clear();

      for (int x = 0; x < _n_bins_double_mucostheta; x++) {
        for (int y = 0; y < _n_bins_double_mumom; y++) {

          auto it = _exclusion_map1.find(x);
          if (it != _exclusion_map1.end()) {
            if (y == it->second.first) {
              separator_counter++;
              h->AddBin(_bins_double_mucostheta[it->first], _bins_double_mumom[it->second.first], _bins_double_mucostheta[it->first+1], _bins_double_mumom[it->second.second+1]);
              continue;
            } else if (y == it->second.second) {
              continue;
            }
          }

          it = _exclusion_map2.find(x);
          if (it != _exclusion_map2.end()) {
            if (y == it->second.first) {
              separator_counter++;
              h->AddBin(_bins_double_mucostheta[it->first], _bins_double_mumom[it->second.first], _bins_double_mucostheta[it->first+1], _bins_double_mumom[it->second.second+1]);
              continue;
            } else if (y == it->second.second) {
              continue;
            }
          }

          separator_counter++;
          h->AddBin(_bins_double_mucostheta[x], _bins_double_mumom[y], _bins_double_mucostheta[x+1], _bins_double_mumom[y+1]);
        }
        separators.emplace_back(separator_counter);
        separator_counter = 0;
      }

      h->SetSeparators(separators);
    }

  }

#endif

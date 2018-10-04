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
      // Single differential (mumom)
      //


      //
      // Single differential (muangle)
      //


      //
      // Double differential
      //

      // Efficiency - Double Differential - Multisim
      bs_genie_multisim_eff_muangle_mumom_num = new BootstrapTH2D("bs_genie_multisim_eff_muangle_mumom_num", "bs_genie_multisim_eff_muangle_mumom_num_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      bs_genie_multisim_eff_muangle_mumom_den = new BootstrapTH2D("bs_genie_multisim_eff_muangle_mumom_den", "bs_genie_multisim_eff_muangle_mumom_den_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      bs_flux_multisim_eff_muangle_mumom_num = new BootstrapTH2D("bs_flux_multisim_eff_muangle_mumom_num", "bs_flux_multisim_eff_muangle_mumom_num_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      bs_flux_multisim_eff_muangle_mumom_den = new BootstrapTH2D("bs_flux_multisim_eff_muangle_mumom_den", "bs_flux_multisim_eff_muangle_mumom_den_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      bs_extra_syst_multisim_eff_muangle_mumom_num = new BootstrapTH2D("bs_extra_syst_multisim_eff_muangle_mumom_num", "bs_extra_syst_eff_muangle_mumom_num_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
      bs_extra_syst_multisim_eff_muangle_mumom_den = new BootstrapTH2D("bs_extra_syst_multisim_eff_muangle_mumom_den", "bs_extra_syst_eff_muangle_mumom_den_title", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);

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

      // Efficiency - Double Differential PolyBins - Multisim
      bs_genie_multisim_eff_poly_muangle_mumom_num = new BootstrapTH2DPoly("bs_genie_multisim_eff_poly_muangle_mumom_num", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      bs_genie_multisim_eff_poly_muangle_mumom_den = new BootstrapTH2DPoly("bs_genie_multisim_eff_poly_muangle_mumom_den", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      bs_flux_multisim_eff_poly_muangle_mumom_num = new BootstrapTH2DPoly("bs_flux_multisim_eff_poly_muangle_mumom_num", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      bs_flux_multisim_eff_poly_muangle_mumom_den = new BootstrapTH2DPoly("bs_flux_multisim_eff_poly_muangle_mumom_den", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      bs_extra_syst_multisim_eff_poly_muangle_mumom_num = new BootstrapTH2DPoly("bs_extra_syst_multisim_eff_poly_muangle_mumom_num", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      bs_extra_syst_multisim_eff_poly_muangle_mumom_den = new BootstrapTH2DPoly("bs_extra_syst_multisim_eff_poly_muangle_mumom_den", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", -1., 1., 0., 2.5, _n_bins_double_mucostheta);
      
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

    }




    void UBXSecEventHisto::AddPolyBins() {
      _AddPolyBins_(bs_genie_multisim_eff_poly_muangle_mumom_num);
      _AddPolyBins_(bs_genie_multisim_eff_poly_muangle_mumom_den);
      _AddPolyBins_(bs_flux_multisim_eff_poly_muangle_mumom_num);
      _AddPolyBins_(bs_flux_multisim_eff_poly_muangle_mumom_den);
      _AddPolyBins_(bs_extra_syst_multisim_eff_poly_muangle_mumom_num);
      _AddPolyBins_(bs_extra_syst_multisim_eff_poly_muangle_mumom_den);

      _AddPolyBins_(hmap_trktheta_trkmom_poly_genie_multisim_bs);
      _AddPolyBins_(hmap_trktheta_trkmom_poly_flux_multisim_bs);
      _AddPolyBins_(hmap_trktheta_trkmom_poly_extra_syst_multisim_bs);

    }





    
    void UBXSecEventHisto::_AddPolyBins_(std::vector<std::vector<UBTH2Poly*>> h) {
      for (int i = 0; i < h.size(); i++) {
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

      for (int y = 0; y < _n_bins_double_mumom; y++) {
        for (int x = 0; x < _n_bins_double_mucostheta; x++) {

          auto it = _exclusion_map.find(x);
          if (it != _exclusion_map.end()) {
            if (y == it->second.first) {
              h->AddBin(_bins_double_mucostheta[it->first], _bins_double_mumom[it->second.first], _bins_double_mucostheta[it->first+1], _bins_double_mumom[it->second.second+1]);
              continue;
            } else if (y == it->second.second) {
              continue;
            }
          }
          h->AddBin(_bins_double_mucostheta[x], _bins_double_mumom[y], _bins_double_mucostheta[x+1], _bins_double_mumom[y+1]);
        }
      }

    }


    void UBXSecEventHisto::_AddPolyBins_(UBTH2Poly * h) {

      h->SetNBinsX(_n_bins_double_mucostheta);

      for (int y = 0; y < _n_bins_double_mumom; y++) {
        for (int x = 0; x < _n_bins_double_mucostheta; x++) {

          auto it = _exclusion_map.find(x);
          if (it != _exclusion_map.end()) {
            if (y == it->second.first) {
              h->AddBin(_bins_double_mucostheta[it->first], _bins_double_mumom[it->second.first], _bins_double_mucostheta[it->first+1], _bins_double_mumom[it->second.second+1]);
              continue;
            } else if (y == it->second.second) {
              continue;
            }
          }
          h->AddBin(_bins_double_mucostheta[x], _bins_double_mumom[y], _bins_double_mucostheta[x+1], _bins_double_mumom[y+1]);
        }
      }
    }

  }

#endif

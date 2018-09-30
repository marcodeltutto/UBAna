#ifndef __DATATYPES_UBXSECEVENTHISTO_CXX__
#define __DATATYPES_UBXSECEVENTHISTO_CXX__

#include "UBXSecEventHisto.h"


namespace DataTypes {

  void UBXSecEventHisto::OpenFile(std::string name)
  {
    _file = new TFile(name.c_str(),"RECREATE");
  }

  void UBXSecEventHisto::SaveToFile()
  {
    if( !_file->IsOpen() ) {
      std::cout << "File is not opened!" << std::endl;
      throw std::exception();
    }

    std::cout << "UBXSecEventHisto checkpoint 1" << std::endl;

    _file->WriteObject(bs_flux_multisim_eff_poly_muangle_mumom_num, "bs_flux_multisim_eff_poly_muangle_mumom_num");
    std::cout << "UBXSecEventHisto checkpoint 2" << std::endl;
    _file->WriteObject(bs_flux_multisim_eff_poly_muangle_mumom_den, "bs_flux_multisim_eff_poly_muangle_mumom_den");

    std::cout << "UBXSecEventHisto checkpoint 3" << std::endl;
    _file->WriteObject(&hmap_trktheta_trkmom_poly_flux_multisim_bs, "hmap_trktheta_trkmom_poly_flux_multisim_bs");
    std::cout << "UBXSecEventHisto checkpoint 4" << std::endl;
    _file->WriteObject(&bs_flux_multisim_poly_reco_per_true, "bs_flux_multisim_poly_reco_per_true");
    std::cout << "UBXSecEventHisto checkpoint 5" << std::endl;
  }


    void UBXSecEventHisto::InitializeBootstraps()
    {

      // Efficiency - Double Differential PolyBins = Multisim
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
        std::stringstream sstm;
        sstm << "bs_genie_multisim_poly_reco_per_true_nominal_" << m;
        bs_genie_multisim_poly_reco_per_true["nominal"][m] = new UBTH2Poly(sstm.str().c_str(), "poly_reco_per_true", -1., 1., 0., 2.5);
      }

      // Reco per true histograms per universe - Double Differential PolyBins - Flux Multisim
      bs_flux_multisim_poly_reco_per_true["nominal"].resize(_n_poly_bins);
      for (int m = 0; m < _n_poly_bins; m++) {
        std::stringstream sstm;
        sstm << "bs_flux_multisim_poly_reco_per_true_nominal_" << m;
        bs_flux_multisim_poly_reco_per_true["nominal"][m] = new UBTH2Poly(sstm.str().c_str(), "poly_reco_per_true", -1., 1., 0., 2.5);
      }

      // Reco per true histograms per universe - Double Differential PolyBins - Extra Syst
      bs_extra_syst_multisim_poly_reco_per_true["nominal"].resize(_n_poly_bins);
      for (int m = 0; m < _n_poly_bins; m++) {
        std::stringstream sstm;
        sstm << "bs_extra_syst_multisim_poly_reco_per_true_nominal_" << m;
        bs_extra_syst_multisim_poly_reco_per_true["nominal"][m] = new UBTH2Poly(sstm.str().c_str(), "poly_reco_per_true", -1., 1., 0., 2.5);
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

      _AddPolyBins_(bs_genie_multisim_poly_reco_per_true);
      _AddPolyBins_(bs_flux_multisim_poly_reco_per_true);
      _AddPolyBins_(bs_extra_syst_multisim_poly_reco_per_true);
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

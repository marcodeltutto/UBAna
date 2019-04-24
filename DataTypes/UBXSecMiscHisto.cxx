#ifndef __DATATYPES_UBXSECMISCHISTO1D_CXX__
#define __DATATYPES_UBXSECMISCHISTO1D_CXX__

#include "UBXSecMiscHisto.h"


namespace DataTypes {


    void UBXSecMiscHisto::Initialize()
    {

        //
        // Truth histograms stacked in interaction type - Selected
        //
        hmap_mctruth_nuenergy["total"] = new TH1D("h_mctruth_nuenergy_total", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
        hmap_mctruth_nuenergy["qe"] = new TH1D("h_mctruth_nuenergy_qe", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
        hmap_mctruth_nuenergy["res"] = new TH1D("h_mctruth_nuenergy_res", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
        hmap_mctruth_nuenergy["dis"] = new TH1D("h_mctruth_nuenergy_dis", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
        hmap_mctruth_nuenergy["coh"] = new TH1D("h_mctruth_nuenergy_coh", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
        hmap_mctruth_nuenergy["mec"] = new TH1D("h_mctruth_nuenergy_mec", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
        hmap_mctruth_nuenergy["other"] = new TH1D("h_mctruth_nuenergy_other", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);      

        hmap_mctruth_mumom["total"] = new TH1D("h_mctruth_mumom_total", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
        hmap_mctruth_mumom["qe"] = new TH1D("h_mctruth_mumom_qe", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
        hmap_mctruth_mumom["res"] = new TH1D("h_mctruth_mumom_res", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
        hmap_mctruth_mumom["dis"] = new TH1D("h_mctruth_mumom_dis", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
        hmap_mctruth_mumom["coh"] = new TH1D("h_mctruth_mumom_coh", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
        hmap_mctruth_mumom["mec"] = new TH1D("h_mctruth_mumom_mec", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
        hmap_mctruth_mumom["other"] = new TH1D("h_mctruth_mumom_other", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);      

        hmap_mctruth_mucostheta["total"] = new TH1D("h_mctruth_mucostheta_total", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);
        hmap_mctruth_mucostheta["qe"] = new TH1D("h_mctruth_mucostheta_qe", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);
        hmap_mctruth_mucostheta["res"] = new TH1D("h_mctruth_mucostheta_res", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);
        hmap_mctruth_mucostheta["dis"] = new TH1D("h_mctruth_mucostheta_dis", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);
        hmap_mctruth_mucostheta["coh"] = new TH1D("h_mctruth_mucostheta_coh", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);
        hmap_mctruth_mucostheta["mec"] = new TH1D("h_mctruth_mucostheta_mec", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);
        hmap_mctruth_mucostheta["other"] = new TH1D("h_mctruth_mucostheta_other", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);      

        hmap_mctruth_muphi["total"] = new TH1D("h_mctruth_muphi_total", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);
        hmap_mctruth_muphi["qe"] = new TH1D("h_mctruth_muphi_qe", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);
        hmap_mctruth_muphi["res"] = new TH1D("h_mctruth_muphi_res", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);
        hmap_mctruth_muphi["dis"] = new TH1D("h_mctruth_muphi_dis", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);
        hmap_mctruth_muphi["coh"] = new TH1D("h_mctruth_muphi_coh", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);
        hmap_mctruth_muphi["mec"] = new TH1D("h_mctruth_muphi_mec", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);
        hmap_mctruth_muphi["other"] = new TH1D("h_mctruth_muphi_other", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);      

        //
        // Truth histograms stacked in interaction type - Generated
        //
        hmap_mctruth_nuenergy_gen["total"] = new TH1D("h_mctruth_nuenergy_gen_total", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
        hmap_mctruth_nuenergy_gen["qe"] = new TH1D("h_mctruth_nuenergy_gen_qe", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
        hmap_mctruth_nuenergy_gen["res"] = new TH1D("h_mctruth_nuenergy_gen_res", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
        hmap_mctruth_nuenergy_gen["dis"] = new TH1D("h_mctruth_nuenergy_gen_dis", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
        hmap_mctruth_nuenergy_gen["coh"] = new TH1D("h_mctruth_nuenergy_gen_coh", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
        hmap_mctruth_nuenergy_gen["mec"] = new TH1D("h_mctruth_nuenergy_gen_mec", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
        hmap_mctruth_nuenergy_gen["other"] = new TH1D("h_mctruth_nuenergy_gen_other", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);      

        hmap_mctruth_mumom_gen["total"] = new TH1D("h_mctruth_mumom_gen_total", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
        hmap_mctruth_mumom_gen["qe"] = new TH1D("h_mctruth_mumom_gen_qe", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
        hmap_mctruth_mumom_gen["res"] = new TH1D("h_mctruth_mumom_gen_res", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
        hmap_mctruth_mumom_gen["dis"] = new TH1D("h_mctruth_mumom_gen_dis", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
        hmap_mctruth_mumom_gen["coh"] = new TH1D("h_mctruth_mumom_gen_coh", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
        hmap_mctruth_mumom_gen["mec"] = new TH1D("h_mctruth_mumom_gen_mec", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
        hmap_mctruth_mumom_gen["other"] = new TH1D("h_mctruth_mumom_gen_other", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);      

        hmap_mctruth_mucostheta_gen["total"] = new TH1D("h_mctruth_mucostheta_gen_total", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);
        hmap_mctruth_mucostheta_gen["qe"] = new TH1D("h_mctruth_mucostheta_gen_qe", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);
        hmap_mctruth_mucostheta_gen["res"] = new TH1D("h_mctruth_mucostheta_gen_res", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);
        hmap_mctruth_mucostheta_gen["dis"] = new TH1D("h_mctruth_mucostheta_gen_dis", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);
        hmap_mctruth_mucostheta_gen["coh"] = new TH1D("h_mctruth_mucostheta_gen_coh", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);
        hmap_mctruth_mucostheta_gen["mec"] = new TH1D("h_mctruth_mucostheta_gen_mec", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);
        hmap_mctruth_mucostheta_gen["other"] = new TH1D("h_mctruth_mucostheta_gen_other", ";True Muon cos(#theta) [GeV];Selected Events", 25, -1, 1);      

        hmap_mctruth_muphi_gen["total"] = new TH1D("h_mctruth_muphi_gen_total", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);
        hmap_mctruth_muphi_gen["qe"] = new TH1D("h_mctruth_muphi_gen_qe", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);
        hmap_mctruth_muphi_gen["res"] = new TH1D("h_mctruth_muphi_gen_res", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);
        hmap_mctruth_muphi_gen["dis"] = new TH1D("h_mctruth_muphi_gen_dis", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);
        hmap_mctruth_muphi_gen["coh"] = new TH1D("h_mctruth_muphi_gen_coh", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);
        hmap_mctruth_muphi_gen["mec"] = new TH1D("h_mctruth_muphi_gen_mec", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);
        hmap_mctruth_muphi_gen["other"] = new TH1D("h_mctruth_muphi_gen_other", ";True Muon #phi [GeV];Selected Events", 20, -3.15, 3.15);



    }

  }

#endif

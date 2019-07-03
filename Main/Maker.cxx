#ifndef __MAIN_MAKER_CXX__
#define __MAIN_MAKER_CXX__

#include "Maker.h"

using namespace Base;

void Main::Maker::SetInputFile(std::string in)
{
  filen = in;
}

void Main::Maker::SetOutputFile(std::string in)
{
  fileoutn = in;
}

void Main::Maker::SetEntries(int e)
{
  maxEntries = e;
}

void Main::Maker::SetInitialEntry(int e)
{
  _initial_entry = e;
}

void Main::Maker::SetBeamSpillStart(double v)
{
  _beamSpillStarts = v;
}

void Main::Maker::SetBeamSpillEnd(double v)
{
  _beamSpillEnds = v;
}

void Main::Maker::SetFlashShift(double v)
{
  _flashShift = v;
}

void Main::Maker::SetGainCalibration(double v)
{
  _gainCalib = v;
}

void Main::Maker::SetCalculatePOT(bool v)
{
  evalPOT = v;
}


void Main::Maker::SetIsData(bool v)
{
  isdata = v;
}



void Main::Maker::PrintConfig()
{
  LOG_INFO() << "--- Main::Maker::PrintConfig" << std::endl;

  LOG_INFO() << "--- _breakdownPlots: " << _breakdownPlots << std::endl;
  LOG_INFO() << "--- _makePlots " << _makePlots << std::endl;
  LOG_INFO() << "--- _fill_bootstrap_flux " << _fill_bootstrap_flux << std::endl;
  LOG_INFO() << "--- _fill_bootstrap_genie " << _fill_bootstrap_genie << std::endl;
  LOG_INFO() << "--- _target_flux_syst " << _target_flux_syst << std::endl;
  LOG_INFO() << "--- _check_duplicate_events " << _check_duplicate_events << std::endl;

  LOG_INFO() << "--- _beamSpillStarts " << _beamSpillStarts << std::endl;
  LOG_INFO() << "--- _beamSpillEnds " << _beamSpillEnds << std::endl;
  LOG_INFO() << "--- _flashShift " << _flashShift << std::endl;
  LOG_INFO() << "--- _gainCalib " << _gainCalib << std::endl;

  LOG_INFO() << "--- filen " << filen << std::endl;
  LOG_INFO() << "--- evalPOT " << evalPOT << std::endl;
  LOG_INFO() << "--- maxEntries " << maxEntries << std::endl;
  LOG_INFO() << "--- isdata " << isdata << std::endl;

  LOG_INFO() << "--- _pe_cut " << _pe_cut << std::endl;

  LOG_INFO() << "--- targetPOT " << targetPOT << std::endl;
}

void Main::Maker::PrintMaUpMECOff()
{
  for (int i = 0; i < 10; i++) {
    std::cout << "**************************** RUNNING WITH MA+1SIGMA AND MEC OFF ****************************" << std::endl;
  }
}

void Main::Maker::PrintReweighKaons()
{
  for (int i = 0; i < 10; i++) {
    std::cout << "**************************** RUNNING WITH KAON FLUX SCALED BY " << _kaon_reweigh_factor << " ****************************" << std::endl;
  }
}








//____________________________________________________________________________________________________
void Main::Maker::DrawProgressBar(double progress, double barWidth) {
  
  std::cout << "[";
  int pos = barWidth * progress;
  for (int i = 0; i < barWidth; ++i) {
    if (i < pos) std::cout << "=";
    else if (i == pos) std::cout << ">";
    else std::cout << " ";
  }
  std::cout << "] " << int(progress * 100.0) << " %\r";
  std::cout.flush();
}

//____________________________________________________________________________________________________
void Main::Maker::DrawPOT2(double pot, double target)
{
  //std::string str = "Simulated POT:" + std::to_string(pot);
  
  std::stringstream sstm;
  sstm << "Simulated POT: " << pot;
  std::string str = sstm.str();
  
  TLatex* pot_latex = new TLatex(.10, .96, str.c_str());
  pot_latex->SetTextColor(kGray+2);
  pot_latex->SetNDC();
  pot_latex->SetTextSize(1/30.);
  pot_latex->SetTextAlign(10); //left adjusted
  pot_latex->Draw();
  
  
  std::stringstream sstm2;
  sstm2 << "Scaled to POT: " << target;
  str = sstm2.str();
  
  TLatex* pot_latex_2 = new TLatex(.10, .92, str.c_str());
  pot_latex_2->SetTextFont(62);
  pot_latex_2->SetTextColor(kGray+2);
  pot_latex_2->SetNDC();
  pot_latex_2->SetTextSize(1/30.);
  pot_latex_2->SetTextAlign(10);//left adjusted
  pot_latex_2->Draw();
  
}



//____________________________________________________________________________________________________
double Main::Maker::eff_uncertainty(int _n, int _N) {

  double n = (double) _n;
  double N = (double) _N;

  double unc = 1/std::sqrt(N) * std::sqrt((n/N)*(1-n/N));

  return unc;

}


//___________________________________________________________________________________________________
void Main::Maker::FillBootstrap(double fill_value,
                                double evt_wgt,
                                std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_genie_pm1_bs, 
                                std::string channel_namel, 
                                std::vector<std::string> fname, 
                                std::vector<double> wgts_genie) {

  auto iter = hmap_trkmom_genie_pm1_bs.find(channel_namel);
  if (iter == hmap_trkmom_genie_pm1_bs.end()) {
    LOG_CRITICAL() << "Can't find " << channel_namel << std::endl;
    throw std::exception();
  }
  std::map<std::string,TH1D*> this_map = iter->second;

  this_map["nominal"]->Fill(fill_value, evt_wgt);

  for (size_t i = 0; i < fname.size(); i++) {

    //std::cout << i << ": Fill value: " << fill_value << ", weight: " << wgts_genie.at(i) << ", name is " << fname.at(i) << std::endl;

    this_map[fname.at(i)]->Fill(fill_value, wgts_genie.at(i) * evt_wgt);

  }


} 

//___________________________________________________________________________________________________
void Main::Maker::FillBootstrap(double fill_value1,
                                double fill_value2,
                                double evt_wgt,
                                std::map<std::string,std::map<std::string,TH2D*>> hmap, 
                                std::string channel_namel, 
                                std::vector<std::string> fname, 
                                std::vector<double> wgts_genie) {

  auto iter = hmap.find(channel_namel);
  if (iter == hmap.end()) {
    LOG_CRITICAL() << "Can't find " << channel_namel << std::endl;
    throw std::exception();
  }
  std::map<std::string,TH2D*> this_map = iter->second;

  this_map["nominal"]->Fill(fill_value1, fill_value2, evt_wgt);

  for (size_t i = 0; i < fname.size(); i++) {

    //std::cout << i << ": Fill value: " << fill_value << ", weight: " << wgts_genie.at(i) << ", name is " << fname.at(i) << std::endl;

    this_map[fname.at(i)]->Fill(fill_value1, fill_value2, wgts_genie.at(i) * evt_wgt);

  }


} 


//___________________________________________________________________________________________________
void Main::Maker::FillBootstrap(double fill_value1,
                                double fill_value2,
                                double evt_wgt,
                                std::map<std::string,std::map<std::string,UBTH2Poly*>> hmap, 
                                std::string channel_namel, 
                                std::vector<std::string> fname, 
                                std::vector<double> wgts_genie) {

  auto iter = hmap.find(channel_namel);
  if (iter == hmap.end()) {
    LOG_CRITICAL() << "Can't find " << channel_namel << std::endl;
    throw std::exception();
  }
  std::map<std::string,UBTH2Poly*> this_map = iter->second;

  this_map["nominal"]->Fill(fill_value1, fill_value2, evt_wgt);

  for (size_t i = 0; i < fname.size(); i++) {

    //std::cout << i << ": Fill value: " << fill_value << ", weight: " << wgts_genie.at(i) << ", name is " << fname.at(i) << std::endl;

    this_map[fname.at(i)]->Fill(fill_value1, fill_value2, wgts_genie.at(i) * evt_wgt);

  }


} 

//___________________________________________________________________________________________________
void Main::Maker::FillBootstrap(double fill_value1,
                                double fill_value2,
                                double evt_wgt,
                                std::map<std::string,TH2D*> hmap_trkmom_genie_pm1_bs, 
                                std::vector<std::string> fname, 
                                std::vector<double> wgts_genie) {


  hmap_trkmom_genie_pm1_bs["nominal"]->Fill(fill_value1, fill_value2, evt_wgt);

  for (size_t i = 0; i < fname.size(); i++) {

    hmap_trkmom_genie_pm1_bs[fname.at(i)]->Fill(fill_value1, fill_value2, wgts_genie.at(i) * evt_wgt);

    //std::cout << "Fill value: " << fill_value << ", weight: " << wgts_genie_pm1.at(i) << std::endl;

  }

}

//___________________________________________________________________________________________________
void Main::Maker::FillBootstrap(double fill_value1, // reco value x (costheta)
                                double fill_value2, // reco value y (momentum)
                                int m, // true bin m (costheta)
                                int n, // true bin n (momentum)
                                double evt_wgt,
                                std::map<std::string,std::vector<std::vector<TH2D*>>> bs_reco_per_true, 
                                std::vector<std::string> fname, 
                                std::vector<double> wgts) {


  bs_reco_per_true["nominal"][m][n]->Fill(fill_value1, fill_value2, evt_wgt);

  for (size_t i = 0; i < fname.size(); i++) {

    bs_reco_per_true[fname.at(i)][m][n]->Fill(fill_value1, fill_value2, wgts.at(i) * evt_wgt);

    //std::cout << "Fill value: " << fill_value << ", weight: " << wgts_genie_pm1.at(i) << std::endl;

  }

}


//___________________________________________________________________________________________________
void Main::Maker::FillBootstrap(double fill_value1, // reco value x (costheta)
                                double fill_value2, // reco value y (momentum)
                                int m, // true bin m (1 number, unrolled)
                                double evt_wgt,
                                std::map<std::string,std::vector<UBTH2Poly*>> bs_poly_reco_per_true, 
                                std::vector<std::string> fname, 
                                std::vector<double> wgts) {


  bs_poly_reco_per_true["nominal"][m]->Fill(fill_value1, fill_value2, evt_wgt);

  for (size_t i = 0; i < fname.size(); i++) {

    bs_poly_reco_per_true[fname.at(i)][m]->Fill(fill_value1, fill_value2, wgts.at(i) * evt_wgt);

    //std::cout << "Fill value: " << fill_value << ", weight: " << wgts_genie_pm1.at(i) << std::endl;

  }

}

//___________________________________________________________________________________________________
void Main::Maker::FillBootstrap(int m, // true bin m (1 number, unrolled)
                                int j, // reco bin i (1 number, unrolled)
                                double evt_wgt,
                                std::map<std::string,std::vector<std::vector<double>>> & bs_poly_reco_per_true, 
                                std::vector<std::string> fname, 
                                std::vector<double> wgts) {


  if (j < 0) j = 0; // Negative bins are overflows, and are all added to entry 0 of the vector

  bs_poly_reco_per_true["nominal"][m][j] += evt_wgt;

  for (size_t i = 0; i < fname.size(); i++) {

    bs_poly_reco_per_true[fname.at(i)][m][j] += wgts.at(i) * evt_wgt;

    //std::cout << "Fill value: " << fill_value << ", weight: " << wgts_genie_pm1.at(i) << std::endl;

  }

}




//___________________________________________________________________________________________________
void Main::Maker::AddPolyBins(UBTH2Poly * h) {

  // std::map<int, std::pair<int, int>> _exclusion_map;
  // _exclusion_map[0] = std::make_pair(2, 3);

  h->SetNBinsX(n_bins_double_mucostheta);

  for (int y = 0; y < n_bins_double_mumom; y++) {
    for (int x = 0; x < n_bins_double_mucostheta; x++) {

      auto it = _exclusion_map.find(x);
      if (it != _exclusion_map.end()) {
        if (y == it->second.first) {
          h->AddBin(bins_double_mucostheta[it->first], bins_double_mumom[it->second.first], bins_double_mucostheta[it->first+1], bins_double_mumom[it->second.second+1]);
          continue;
        } else if (y == it->second.second) {
          continue;
        }
      }
      h->AddBin(bins_double_mucostheta[x], bins_double_mumom[y], bins_double_mucostheta[x+1], bins_double_mumom[y+1]);
    }
  }
}



//___________________________________________________________________________________________________
void Main::Maker::AddPolyBins(BootstrapTH2DPoly h) {

  // std::map<int, std::pair<int, int>> _exclusion_map;
  // _exclusion_map[0] = std::make_pair(2, 3);

  // h->SetNBinsX(n_bins_double_mucostheta);

  for (int y = 0; y < n_bins_double_mumom; y++) {
    for (int x = 0; x < n_bins_double_mucostheta; x++) {

      auto it = _exclusion_map.find(x);
      if (it != _exclusion_map.end()) {
        if (y == it->second.first) {
          h.AddBin(bins_double_mucostheta[it->first], bins_double_mumom[it->second.first], bins_double_mucostheta[it->first+1], bins_double_mumom[it->second.second+1]);
          continue;
        } else if (y == it->second.second) {
          continue;
        }
      }
      h.AddBin(bins_double_mucostheta[x], bins_double_mumom[y], bins_double_mucostheta[x+1], bins_double_mumom[y+1]);
    }
  }
}
















void Main::Maker::MakeFile() 
{

	clock_t begin = clock();

  double n_signal = 0;


  system("mkdir -p output/");
  
  // CSV file for dqdx and track lenght values
  std::ofstream _csvfile;
  _csvfile.open ("./dqdx_trklen.csv", std::ofstream::out | std::ofstream::trunc);
  _csvfile << "dqdx,trklen,y" << std::endl;

   
  if (isdata) {
    LOG_NORMAL() << "Running on a data file." << std::endl;
  }
  else {
    LOG_NORMAL() << "Running on a MC file." << std::endl;
  }

  

  if (_scale_cosmics) {
    for (int i = 0; i < 10; i++) {
      std::cout << "****** Scaling cosmic background by " << _scale_factor_cosmic << "******" << std::endl;
    }
  }
  

  //*************************
  //* Starting ROOT application
  //*************************

  
  //TApplication* rootapp = new TApplication("ROOT Application",&argc, argv);
  gROOT->SetBatch(kTRUE);
  gROOT->ProcessLine("gErrorIgnoreLevel = 2001;"); // 1001: INFO, 2001: WARNINGS, 3001: ERRORS
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();


  //gROOT->ProcessLine(".x rootlogon.C");



  LOG_NORMAL() << "Opening output file with name " << fileoutn << std::endl;
  TFile *file_out = new TFile(fileoutn.c_str(),"RECREATE");
  if ( file_out->IsOpen() ) {
    LOG_NORMAL() << "File opened successfully." << std::endl;
  } else {
    LOG_CRITICAL() << "File not opened (maybe not found?). File: " << fileoutn << std::endl;
    exit(0);
  }
  
  string pattern = filen;
  
  
  
  //*************************
  //* Getting POTs
  //*************************
  
  double totalPOT = 0.;
  
  if (maxEntries > 0) evalPOT = false;
  
  if (evalPOT) {
    
    LOG_NORMAL() << " ~~~~~~~~~~~~~~ " << endl;
    LOG_NORMAL() << " |   Calculating POT" << endl;
    LOG_NORMAL() << " |" << endl;
    TChain *cpot;
    cpot = new TChain("UBXSec/pottree");
    cpot->Add(pattern.c_str());
    LOG_NORMAL() << " | Number of entries in the pot tree: " << cpot->GetEntries() << endl;
    Double_t pot;
    cpot->SetBranchAddress("pot", &pot);
    for (int potEntry = 0; potEntry < cpot->GetEntries(); potEntry++) {
      cpot->GetEntry(potEntry);
      totalPOT += pot;
    } // end loop entries
    LOG_NORMAL() << " | Total POT: " << totalPOT << endl;
    LOG_NORMAL() << " ~~~~~~~~~~~~~~ " << endl << endl;
  } // end if evalPOT
  else
    totalPOT = -1.;
  
  double pot_scaling = 1.;
  if (evalPOT) pot_scaling = targetPOT/totalPOT;
  
  
  TChain *chain_ubxsec;
  chain_ubxsec = new TChain("UBXSec/tree");
  chain_ubxsec->Add(pattern.c_str());
  
  LOG_NORMAL() << "Using file: " << pattern << endl;
  
  int Nfiles = chain_ubxsec->GetNtrees();
  LOG_NORMAL() << "Number of files: " << Nfiles << endl;
  
  int evts = chain_ubxsec -> GetEntries();
  LOG_NORMAL() << "Number of events used is: " << evts << endl;
  
  UBXSecEvent * t = new UBXSecEvent(chain_ubxsec);
  //ActivateBranches(t);

  _event_histo_1d = new UBXSecEventHisto1D();
  _event_histo_1d->InitializeBootstraps();

  _event_histo = new UBXSecEventHisto();
  _event_histo->InitializeBootstraps();
  // _event_histo->OpenFile(fileoutn + "mytest");

  _n_poly_bins = _event_histo->_n_poly_bins;
  LOG_NORMAL() << "Number of polybins: " << _n_poly_bins << std::endl;

  double nsignal = 0;
  // double nsignal_all = 0;

  double nsignal_qe = 0;
  double nsignal_res = 0;
  double nsignal_dis = 0;
  double nsignal_coh = 0;
  double nsignal_mec = 0;
  
  double signal_sel = 0;
  double bkg_anumu_sel = 0;
  double bkg_nue_sel = 0;
  double bkg_nc_sel = 0;
  double bkg_outfv_sel = 0;
  double bkg_cosmic_sel = 0;
  double bkg_cosmic_top_sel = 0;

  double real_muon_sel = 0;

  double signal_sel_qe = 0;
  double signal_sel_res = 0;
  double signal_sel_dis = 0;
  double signal_sel_coh = 0;
  double signal_sel_mec = 0;
  
  int nEvtsWFlashInBeamSpill = 0;
  int nNumuCC = 0;
  
  double nue_cc_fv = 0;
  double nue_cc_selected = 0;
  double nue_cc_selected_total = 0;
  double nue_cc_selected_total_energy_range = 0;
  double nue_selected_total_energy_range = 0;
  double n_nue_electron = 0;
  double n_nue_proton = 0;
  double n_nue_pion = 0;

  int nSignalWMuonReco = 0;
  int nSignalMuonRecoVtxOk = 0;
  
  int nSignalFlashMatched = 0;
  
  int n_slc_nu_origin = 0;

  std::map<std::string, double> selected_events_percut;
  selected_events_percut["initial"] = 0.;
  selected_events_percut["beamflash"] = 0.;
  selected_events_percut["flash_match"] = 0.;
  selected_events_percut["flash_match_deltax"] = 0.;
  selected_events_percut["flash_match_deltaz"] = 0.;
  selected_events_percut["fiducial_volume"] = 0.;
  selected_events_percut["quality"] = 0.;
  selected_events_percut["mcs_length_quality"] = 0.;
  selected_events_percut["mip_consistency"] = 0.;

  std::map<std::string, double> selected_signal_events_percut;
  selected_signal_events_percut["initial"] = 0.;
  selected_signal_events_percut["beamflash"] = 0.;
  selected_signal_events_percut["flash_match"] = 0.;
  selected_signal_events_percut["flash_match_deltax"] = 0.;
  selected_signal_events_percut["flash_match_deltaz"] = 0.;
  selected_signal_events_percut["fiducial_volume"] = 0.;
  selected_signal_events_percut["quality"] = 0.;
  selected_signal_events_percut["mcs_length_quality"] = 0.;
  selected_signal_events_percut["mip_consistency"] = 0.;

  
  TTree* _shower_tree = new TTree("shower_tree", "shower_tree");
  double _s_nupdg, _s_track_pdg, _s_tpcobj_origin, _s_shower_length, _s_shower_phi, _s_shower_theta, _s_shower_openangle, _s_shower_startx, _s_shower_starty, _s_shower_startz, _s_flash_z;
  _shower_tree->Branch("s_nupdg", &_s_nupdg, "s_nupdg/D");
  _shower_tree->Branch("s_track_pdg", &_s_track_pdg, "s_track_pdg/D");
  _shower_tree->Branch("s_tpcobj_origin", &_s_tpcobj_origin, "s_tpcobj_origin/D");
  _shower_tree->Branch("s_shower_length", &_s_shower_length, "s_shower_length/D");
  _shower_tree->Branch("s_shower_phi", &_s_shower_phi, "s_shower_phi/D");
  _shower_tree->Branch("s_shower_theta", &_s_shower_theta, "s_shower_theta/D");
  _shower_tree->Branch("s_shower_openangle", &_s_shower_openangle, "s_shower_openangle/D");
  _shower_tree->Branch("s_shower_startx", &_s_shower_startx, "s_shower_startx/D");
  _shower_tree->Branch("s_shower_starty", &_s_shower_starty, "s_shower_starty/D");
  _shower_tree->Branch("s_shower_startz", &_s_shower_startz, "s_shower_startz/D");
  _shower_tree->Branch("s_flash_z", &_s_flash_z, "s_flash_z/D");


  TTree* _true_reco_tree = new TTree("true_reco_tree", "true_reco_tree");
  _true_reco_tree->Branch("mom_true", &_mom_true, "mom_true/D");
  _true_reco_tree->Branch("mom_mcs", &_mom_mcs, "mom_mcs/D");
  _true_reco_tree->Branch("contained", &_contained, "contained/O");
  _true_reco_tree->Branch("selected", &_selected, "selected/O");
  _true_reco_tree->Branch("angle_true", &_angle_true, "angle_true/D");
  _true_reco_tree->Branch("angle_reco", &_angle_reco, "angle_reco/D");
  _true_reco_tree->Branch("event_weight", &_event_weight_fortree, "event_weight/D");
  _true_reco_tree->Branch("wgtsnames_genie_multisim", "std::vector<std::string>", &_wgtsnames_genie_multisim);
  _true_reco_tree->Branch("wgts_genie_multisim", "std::vector<double>", &_wgts_genie_multisim);
  _true_reco_tree->Branch("wgtsnames_extra_syst", "std::vector<std::string>", &_wgtsnames_extra_syst);
  _true_reco_tree->Branch("wgts_extra_syst", "std::vector<double>", &_wgts_extra_syst);
  _true_reco_tree->Branch("wgtsnames_flux_multisim", "std::vector<std::string>", &_wgtsnames_flux_multisim);
  _true_reco_tree->Branch("wgts_flux_multisim", "std::vector<double>", &_wgts_flux_multisim);


  

  //
  // Truth histograms stacked in interaction type - Selected
  //
  std::map<std::string,TH1D*> hmap_mctruth_nuenergy;
  hmap_mctruth_nuenergy["total"] = new TH1D("h_mctruth_nuenergy_total", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
  hmap_mctruth_nuenergy["qe"] = new TH1D("h_mctruth_nuenergy_qe", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
  hmap_mctruth_nuenergy["res"] = new TH1D("h_mctruth_nuenergy_res", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
  hmap_mctruth_nuenergy["dis"] = new TH1D("h_mctruth_nuenergy_dis", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
  hmap_mctruth_nuenergy["coh"] = new TH1D("h_mctruth_nuenergy_coh", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
  hmap_mctruth_nuenergy["mec"] = new TH1D("h_mctruth_nuenergy_mec", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
  hmap_mctruth_nuenergy["other"] = new TH1D("h_mctruth_nuenergy_other", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);

  std::map<std::string,TH1D*> hmap_mctruth_mumom;
  hmap_mctruth_mumom["total"] = new TH1D("h_mctruth_mumom_total", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
  hmap_mctruth_mumom["qe"] = new TH1D("h_mctruth_mumom_qe", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
  hmap_mctruth_mumom["res"] = new TH1D("h_mctruth_mumom_res", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
  hmap_mctruth_mumom["dis"] = new TH1D("h_mctruth_mumom_dis", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
  hmap_mctruth_mumom["coh"] = new TH1D("h_mctruth_mumom_coh", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
  hmap_mctruth_mumom["mec"] = new TH1D("h_mctruth_mumom_mec", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
  hmap_mctruth_mumom["other"] = new TH1D("h_mctruth_mumom_other", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);

  std::map<std::string,TH1D*> hmap_mctruth_mucostheta;
  hmap_mctruth_mucostheta["total"] = new TH1D("h_mctruth_mucostheta_total", ";True Muon cos(#theta);Selected Events", 25, -1, 1);
  hmap_mctruth_mucostheta["qe"] = new TH1D("h_mctruth_mucostheta_qe", ";True Muon cos(#theta);Selected Events", 25, -1, 1);
  hmap_mctruth_mucostheta["res"] = new TH1D("h_mctruth_mucostheta_res", ";True Muon cos(#theta);Selected Events", 25, -1, 1);
  hmap_mctruth_mucostheta["dis"] = new TH1D("h_mctruth_mucostheta_dis", ";True Muon cos(#theta);Selected Events", 25, -1, 1);
  hmap_mctruth_mucostheta["coh"] = new TH1D("h_mctruth_mucostheta_coh", ";True Muon cos(#theta);Selected Events", 25, -1, 1);
  hmap_mctruth_mucostheta["mec"] = new TH1D("h_mctruth_mucostheta_mec", ";True Muon cos(#theta);Selected Events", 25, -1, 1);
  hmap_mctruth_mucostheta["other"] = new TH1D("h_mctruth_mucostheta_other", ";True Muon cos(#theta);Selected Events", 25, -1, 1);

  std::map<std::string,TH1D*> hmap_mctruth_muphi;
  hmap_mctruth_muphi["total"] = new TH1D("h_mctruth_muphi_total", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);
  hmap_mctruth_muphi["qe"] = new TH1D("h_mctruth_muphi_qe", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);
  hmap_mctruth_muphi["res"] = new TH1D("h_mctruth_muphi_res", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);
  hmap_mctruth_muphi["dis"] = new TH1D("h_mctruth_muphi_dis", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);
  hmap_mctruth_muphi["coh"] = new TH1D("h_mctruth_muphi_coh", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);
  hmap_mctruth_muphi["mec"] = new TH1D("h_mctruth_muphi_mec", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);
  hmap_mctruth_muphi["other"] = new TH1D("h_mctruth_muphi_other", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);

  std::map<std::string,TH1D*> hmap_mctruth_chargedmult;
  hmap_mctruth_chargedmult["total"] = new TH1D("h_mctruth_chargedmult_total", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);
  hmap_mctruth_chargedmult["qe"] = new TH1D("h_mctruth_chargedmult_qe", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);
  hmap_mctruth_chargedmult["res"] = new TH1D("h_mctruth_chargedmult_res", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);
  hmap_mctruth_chargedmult["dis"] = new TH1D("h_mctruth_chargedmult_dis", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);
  hmap_mctruth_chargedmult["coh"] = new TH1D("h_mctruth_chargedmult_coh", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);
  hmap_mctruth_chargedmult["mec"] = new TH1D("h_mctruth_chargedmult_mec", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);
  hmap_mctruth_chargedmult["other"] = new TH1D("h_mctruth_chargedmult_other", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);

  std::map<std::string,TH2D*> hmap_mctruth_mucostheta_mumom;
  hmap_mctruth_mucostheta_mumom["total"] = new TH2D("hmap_mctruth_mucostheta_mumom_total", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);
  hmap_mctruth_mucostheta_mumom["qe"] = new TH2D("hmap_mctruth_mucostheta_mumom_qe", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);
  hmap_mctruth_mucostheta_mumom["res"] = new TH2D("hmap_mctruth_mucostheta_mumom_res", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);
  hmap_mctruth_mucostheta_mumom["dis"] = new TH2D("hmap_mctruth_mucostheta_mumom_dis", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);
  hmap_mctruth_mucostheta_mumom["coh"] = new TH2D("hmap_mctruth_mucostheta_mumom_coh", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);
  hmap_mctruth_mucostheta_mumom["mec"] = new TH2D("hmap_mctruth_mucostheta_mumom_mec", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);
  hmap_mctruth_mucostheta_mumom["other"] = new TH2D("hmap_mctruth_mucostheta_mumom_other", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);

  std::map<std::string,TH2D*> hmap_mctruth_q0_q3;
  hmap_mctruth_q0_q3["total"] = new TH2D("hmap_mctruth_q0_q3_total", ";Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);
  hmap_mctruth_q0_q3["qe"] = new TH2D("hmap_mctruth_q0_q3_qe", ";;Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);
  hmap_mctruth_q0_q3["res"] = new TH2D("hmap_mctruth_q0_q3_res", ";;Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);
  hmap_mctruth_q0_q3["dis"] = new TH2D("hmap_mctruth_q0_q3_dis", ";;Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);
  hmap_mctruth_q0_q3["coh"] = new TH2D("hmap_mctruth_q0_q3_coh", ";;Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);
  hmap_mctruth_q0_q3["mec"] = new TH2D("hmap_mctruth_q0_q3_mec", ";;Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);
  hmap_mctruth_q0_q3["other"] = new TH2D("hmap_mctruth_q0_q3_other", ";;Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);

  //
  // Truth histograms stacked in interaction type - Generated
  //
  std::map<std::string,TH1D*> hmap_mctruth_nuenergy_gen;
  hmap_mctruth_nuenergy_gen["total"] = new TH1D("h_mctruth_nuenergy_gen_total", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
  hmap_mctruth_nuenergy_gen["qe"] = new TH1D("h_mctruth_nuenergy_gen_qe", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
  hmap_mctruth_nuenergy_gen["res"] = new TH1D("h_mctruth_nuenergy_gen_res", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
  hmap_mctruth_nuenergy_gen["dis"] = new TH1D("h_mctruth_nuenergy_gen_dis", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
  hmap_mctruth_nuenergy_gen["coh"] = new TH1D("h_mctruth_nuenergy_gen_coh", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
  hmap_mctruth_nuenergy_gen["mec"] = new TH1D("h_mctruth_nuenergy_gen_mec", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);
  hmap_mctruth_nuenergy_gen["other"] = new TH1D("h_mctruth_nuenergy_gen_other", ";True Neutrino Energy [GeV];Selected Events", 20, 0, 3);

  std::map<std::string,TH1D*> hmap_mctruth_mumom_gen;
  hmap_mctruth_mumom_gen["total"] = new TH1D("h_mctruth_mumom_gen_total", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
  hmap_mctruth_mumom_gen["qe"] = new TH1D("h_mctruth_mumom_gen_qe", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
  hmap_mctruth_mumom_gen["res"] = new TH1D("h_mctruth_mumom_gen_res", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
  hmap_mctruth_mumom_gen["dis"] = new TH1D("h_mctruth_mumom_gen_dis", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
  hmap_mctruth_mumom_gen["coh"] = new TH1D("h_mctruth_mumom_gen_coh", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
  hmap_mctruth_mumom_gen["mec"] = new TH1D("h_mctruth_mumom_gen_mec", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);
  hmap_mctruth_mumom_gen["other"] = new TH1D("h_mctruth_mumom_gen_other", ";True Muon Momentum [GeV];Selected Events", 20, 0, 2.5);

  std::map<std::string,TH1D*> hmap_mctruth_mucostheta_gen;
  hmap_mctruth_mucostheta_gen["total"] = new TH1D("h_mctruth_mucostheta_gen_total", ";True Muon cos(#theta);Selected Events", 25, -1, 1);
  hmap_mctruth_mucostheta_gen["qe"] = new TH1D("h_mctruth_mucostheta_gen_qe", ";True Muon cos(#theta);Selected Events", 25, -1, 1);
  hmap_mctruth_mucostheta_gen["res"] = new TH1D("h_mctruth_mucostheta_gen_res", ";True Muon cos(#theta);Selected Events", 25, -1, 1);
  hmap_mctruth_mucostheta_gen["dis"] = new TH1D("h_mctruth_mucostheta_gen_dis", ";True Muon cos(#theta);Selected Events", 25, -1, 1);
  hmap_mctruth_mucostheta_gen["coh"] = new TH1D("h_mctruth_mucostheta_gen_coh", ";True Muon cos(#theta);Selected Events", 25, -1, 1);
  hmap_mctruth_mucostheta_gen["mec"] = new TH1D("h_mctruth_mucostheta_gen_mec", ";True Muon cos(#theta);Selected Events", 25, -1, 1);
  hmap_mctruth_mucostheta_gen["other"] = new TH1D("h_mctruth_mucostheta_gen_other", ";True Muon cos(#theta);Selected Events", 25, -1, 1);

  std::map<std::string,TH1D*> hmap_mctruth_muphi_gen;
  hmap_mctruth_muphi_gen["total"] = new TH1D("h_mctruth_muphi_gen_total", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);
  hmap_mctruth_muphi_gen["qe"] = new TH1D("h_mctruth_muphi_gen_qe", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);
  hmap_mctruth_muphi_gen["res"] = new TH1D("h_mctruth_muphi_gen_res", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);
  hmap_mctruth_muphi_gen["dis"] = new TH1D("h_mctruth_muphi_gen_dis", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);
  hmap_mctruth_muphi_gen["coh"] = new TH1D("h_mctruth_muphi_gen_coh", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);
  hmap_mctruth_muphi_gen["mec"] = new TH1D("h_mctruth_muphi_gen_mec", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);
  hmap_mctruth_muphi_gen["other"] = new TH1D("h_mctruth_muphi_gen_other", ";True Muon #phi;Selected Events", 20, -3.15, 3.15);

  std::map<std::string,TH1D*> hmap_mctruth_chargedmult_gen;
  hmap_mctruth_chargedmult_gen["total"] = new TH1D("h_mctruth_chargedmult_gen_total", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);
  hmap_mctruth_chargedmult_gen["qe"] = new TH1D("h_mctruth_chargedmult_gen_qe", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);
  hmap_mctruth_chargedmult_gen["res"] = new TH1D("h_mctruth_chargedmult_gen_res", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);
  hmap_mctruth_chargedmult_gen["dis"] = new TH1D("h_mctruth_chargedmult_gen_dis", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);
  hmap_mctruth_chargedmult_gen["coh"] = new TH1D("h_mctruth_chargedmult_gen_coh", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);
  hmap_mctruth_chargedmult_gen["mec"] = new TH1D("h_mctruth_chargedmult_gen_mec", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);
  hmap_mctruth_chargedmult_gen["other"] = new TH1D("h_mctruth_chargedmult_gen_other", ";True Charged Particle Multiplicity;Selected Events", 10, 0, 10);

  std::map<std::string,TH2D*> hmap_mctruth_mucostheta_mumom_gen;
  hmap_mctruth_mucostheta_mumom_gen["total"] = new TH2D("hmap_mctruth_mucostheta_mumom_gen_total", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);
  hmap_mctruth_mucostheta_mumom_gen["qe"] = new TH2D("hmap_mctruth_mucostheta_mumom_gen_qe", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);
  hmap_mctruth_mucostheta_mumom_gen["res"] = new TH2D("hmap_mctruth_mucostheta_mumom_gen_res", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);
  hmap_mctruth_mucostheta_mumom_gen["dis"] = new TH2D("hmap_mctruth_mucostheta_mumom_gen_dis", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);
  hmap_mctruth_mucostheta_mumom_gen["coh"] = new TH2D("hmap_mctruth_mucostheta_mumom_gen_coh", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);
  hmap_mctruth_mucostheta_mumom_gen["mec"] = new TH2D("hmap_mctruth_mucostheta_mumom_gen_mec", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);
  hmap_mctruth_mucostheta_mumom_gen["other"] = new TH2D("hmap_mctruth_mucostheta_mumom_gen_other", ";True Muon cos(#theta);True Muon Momentum [GeV]", 25, -1, 1, 20, 0, 2.5);

  std::map<std::string,TH2D*> hmap_mctruth_q0_q3_gen;
  hmap_mctruth_q0_q3_gen["total"] = new TH2D("hmap_mctruth_q0_q3_gen_total", ";Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);
  hmap_mctruth_q0_q3_gen["qe"] = new TH2D("hmap_mctruth_q0_q3_gen_qe", ";;Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);
  hmap_mctruth_q0_q3_gen["res"] = new TH2D("hmap_mctruth_q0_q3_gen_res", ";;Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);
  hmap_mctruth_q0_q3_gen["dis"] = new TH2D("hmap_mctruth_q0_q3_gen_dis", ";;Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);
  hmap_mctruth_q0_q3_gen["coh"] = new TH2D("hmap_mctruth_q0_q3_gen_coh", ";;Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);
  hmap_mctruth_q0_q3_gen["mec"] = new TH2D("hmap_mctruth_q0_q3_gen_mec", ";;Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);
  hmap_mctruth_q0_q3_gen["other"] = new TH2D("hmap_mctruth_q0_q3_gen_other", ";;Three-momentum transfer q^{3} [GeV];Energy transfer q^{0} [GeV]", 30, 0, 1.3, 30, 0, 1.3);


  //
  // True v.s. reco histograms for constructing smearing matrices
  //
  std::map<std::string,TH2D*> bs_genie_pm1_true_reco_mom;
  bs_genie_pm1_true_reco_mom["nominal"] = new TH2D("bs_genie_pm1_true_reco_mom_nominal", ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", n_bins_mumom, bins_mumom, n_bins_mumom, bins_mumom);
  

  
  TH1D* h_eff_num = new TH1D("h_eff_num", "h_eff_num", 15, 0, 3);
  TH1D* h_eff_den = new TH1D("h_eff_den", "h_eff_den", 15, 0, 3);
  TEfficiency* pEff = new TEfficiency("eff",";Neutrino Energy (truth) [GeV];Efficiency",6, 0, 4);


  // Efficiency - GENIE pm1sigma
  BootstrapTH1D bs_genie_pm1_eff_mumom_num("bs_genie_pm1_eff_mumom_num", "bs_genie_pm1_eff_mumom_num_title", n_bins_mumom, bins_mumom);
  BootstrapTH1D bs_genie_pm1_eff_mumom_den("bs_genie_pm1_eff_mumom_den", "bs_genie_pm1_eff_mumom_den_title", n_bins_mumom, bins_mumom);

  
  

  TH1D* h_eff_mult_num = new TH1D("h_eff_mult_num", "h_eff_mult_num", 20, 0, 20);
  TH1D* h_eff_mult_den = new TH1D("h_eff_mult_den", "h_eff_mult_den", 20, 0, 20);
  TH1D* h_eff_mult_ch_num = new TH1D("h_eff_mult_ch_num", "h_eff_mult_ch_num", 10, 0, 15);
  TH1D* h_eff_mult_ch_den = new TH1D("h_eff_mult_ch_den", "h_eff_mult_ch_den", 10, 0, 15);
  TH1D* h_eff_muphi_num = new TH1D("h_eff_muphi_num", "h_eff_muphi_num", 15, -3.1415, 3.1415);
  TH1D* h_eff_muphi_den = new TH1D("h_eff_muphi_den", "h_eff_muphi_den", 15, -3.1415, 3.1415);

  TH1D* h_eff_qe_num = new TH1D("h_eff_qe_num", "h_eff_qe_num", 15, 0, 3);
  TH1D* h_eff_qe_den = new TH1D("h_eff_qe_den", "h_eff_qe_den", 15, 0, 3);
  TH1D* h_eff_res_num = new TH1D("h_eff_res_num", "h_eff_res_num", 15, 0, 3);
  TH1D* h_eff_res_den = new TH1D("h_eff_res_den", "h_eff_res_den", 15, 0, 3);
  TH1D* h_eff_dis_num = new TH1D("h_eff_dis_num", "h_eff_dis_num", 15, 0, 3);
  TH1D* h_eff_dis_den = new TH1D("h_eff_dis_den", "h_eff_dis_den", 15, 0, 3);
  TH1D* h_eff_coh_num = new TH1D("h_eff_coh_num", "h_eff_coh_num", 15, 0, 3);
  TH1D* h_eff_coh_den = new TH1D("h_eff_coh_den", "h_eff_coh_den", 15, 0, 3);
  TH1D* h_eff_mec_num = new TH1D("h_eff_mec_num", "h_eff_mec_num", 15, 0, 3);
  TH1D* h_eff_mec_den = new TH1D("h_eff_mec_den", "h_eff_mec_den", 15, 0, 3);

  TH1D* h_truth_xsec_mumom = new TH1D("h_truth_xsec_mumom", "h_truth_xsec_mumom", n_bins_mumom, bins_mumom);
  TH1D* h_truth_xsec_muangle = new TH1D("h_truth_xsec_muangle", "h_truth_xsec_muangle", n_bins_mucostheta, bins_mucostheta);

  TH1D* h_nue_selected_energy = new TH1D("h_nue_selected_energy", ";True Neutrino Energy [GeV];#nu_{e} Selected Events", 100, 0, 1.5);


  TH1D* h_true_nu_eng_beforesel = new TH1D("h_true_nu_eng_beforesel", ";True Neutrino Energy [GeV];Events", 200, 0, 3);
  TH1D* h_true_nu_eng_afterflash = new TH1D("h_true_nu_eng_afterflash", ";True Neutrino Energy [GeV];Events", 200, 0, 3);
  TH1D* h_true_nu_eng_aftersel = new TH1D("h_true_nu_eng_aftersel", ";True Neutrino Energy [GeV];Events", 200, 0, 3);

  
  
  TH1D* h_chi2 = new TH1D("h_chi2", "h_chi2", 50, 0, 50);
  TH1D* h_flsTime = new TH1D("h_flsTime", ";Flash time w.r.t. trigger [#mus];Flashes", 125, 0, 25);
  TH1D* h_flsTime_wcut = new TH1D("h_flsTime_wcut", ";Flash time w.r.t. trigger [#mus];Flashes (> 50PE)", 500, 0, 25);
  TH1D* h_flsTime_wcut_2 = new TH1D("h_flsTime_wcut_2", "(2);Flash time w.r.t. trigger [#mus];Flashes (> 50PE)", 125, 0, 25);
  TH1D* h_flsTime_wcut_3 = new TH1D("h_flsTime_wcut_3", "(3);Flash time w.r.t. trigger [#mus];Flashes (> 50PE)", 125, 0, 25);
  TH1D* h_flsTime_wcut_4 = new TH1D("h_flsTime_wcut_4", "(4);Flash time w.r.t. trigger [#mus];Flashes (> 50PE)", 125, 0, 25);
  TH1D* h_flsTime_wcut_5 = new TH1D("h_flsTime_wcut_5", "(5);Flash time w.r.t. trigger [#mus];Flashes (> 50PE)", 125, 0, 25);
  TH1D* h_flsTime_wcut_6 = new TH1D("h_flsTime_wcut_6", "(6);Flash time w.r.t. trigger [#mus];Flashes (> 50PE)", 125, 0, 25);
  TH1D* h_flsTime_wcut_7 = new TH1D("h_flsTime_wcut_7", "(7);Flash time w.r.t. trigger [#mus];Flashes (> 50PE)", 125, 0, 25);
  TH1D* h_flsTime_wcut_8 = new TH1D("h_flsTime_wcut_8", "(8);Flash time w.r.t. trigger [#mus];Flashes (> 50PE)", 125, 0, 25);
  h_flsTime->Sumw2(); h_flsTime_wcut->Sumw2(); h_flsTime_wcut_2->Sumw2(); h_flsTime_wcut_3->Sumw2(); h_flsTime_wcut_4->Sumw2(); h_flsTime_wcut_5->Sumw2(); h_flsTime_wcut_6->Sumw2(); h_flsTime_wcut_7->Sumw2(); h_flsTime_wcut_8->Sumw2();

  TH1D* h_flsPe_wcut = new TH1D("h_flsPe_wcut", ";Flash PE;Flashes (> 50PE)", 700, 0, 50000);
  TH2D* h_flsTime_flsPe_wcut = new TH2D("h_flsTime_flsPe_wcut", "Flashes (> 50PE);Flash time w.r.t. trigger [#mus];Flash PE", 125, 0, 25, 700, 0, 50000);
  
  TH1D* h_deltax = new TH1D("h_deltax", "(4);QLL X - TPC X [cm];;", 500, -200,200);
  TH2D* h_deltax_2d = new TH2D("h_deltax_2d", "(4);QLL X [cm];TPC X [cm]", 70, -100,350, 70, -100,350);
  TH1D* h_deltaz_4 = new TH1D("h_deltaz_4", "(4);Delta z [cm];", 100, -200,200);
  TH1D* h_deltaz_6 = new TH1D("h_deltaz_6", "(6);Delta z [cm];", 100, -200,200);

  TH1D* h_nslices = new TH1D("h_nslices", ";Number of slices per event;Entries per bin", 15, 0, 15);
  TH1D* h_vtx_resolution = new TH1D("h_nslh_vtx_resolutionices", ";Vertex resolution (2D) [cm];Entries per bin", 300, 0, 500);
  
  TH2D* h_frac_diff = new TH2D("h_frac_diff", ";PMT ID; Fractional difference", 32, 0, 32, 80, -2, 2);
  TH2D* h_frac_diff_others = new TH2D("h_frac_diff", ";PMT ID; Fractional difference", 32, 0, 32, 80, -2, 2);
  double hypo_spec_x[32], hypo_spec_y[32];
  double meas_spec_x[32], meas_spec_y[32];
  double numc_spec_x[32], numc_spec_y[32];
  
  TH1D* h_xdiff = new TH1D("h_xdiff", "h_xdiff", 1000, -100,100);
  TH1D* h_xdiff_others = new TH1D("h_xdiff_others", "h_xdiff_others", 1000, -100,100);
  TH1D* h_zdiff = new TH1D("h_zdiff", "h_zdiff", 1000, 0,1000);
  TH1D* h_zdiff_others = new TH1D("h_zdiff_others", "h_zdiff_others", 1000, 0,1000);
  // Before selection
  std::map<std::string,TH1D*> hmap_xdiff_b;
  hmap_xdiff_b["total"] = new TH1D("h_xdiff_total_b", ";QLL x - TPC x [cm];", 80, -200,200);//  100, 0,22
  hmap_xdiff_b["signal"] = new TH1D("h_xdiff_signal_b", ";QLL x - TPC x [cm];", 80, -200,200);
  hmap_xdiff_b["background"] = new TH1D("h_xdiff_background_b", ";QLL x - TPC x [cm];", 80, -200,200);
  std::map<std::string,TH1D*> hmap_zdiff_b;
  hmap_zdiff_b["total"] = new TH1D("h_zdiff_total_b", ";Hypo z - Flash z [cm];", 160, -400,400);
  hmap_zdiff_b["signal"] = new TH1D("h_zdiff_signal_b", ";Hypo z - Flash z [cm];", 160, -400,400);
  hmap_zdiff_b["background"] = new TH1D("h_zdiff_background_b", ";Hypo z - Flash z [cm];", 160, -400,400);
  // After selection
  std::map<std::string,TH1D*> hmap_xdiff;
  hmap_xdiff["total"] = new TH1D("h_xdiff_total", ";QLL x - TPC x [cm];", 80, -200,200);
  hmap_xdiff["signal"] = new TH1D("h_xdiff_signal", ";QLL x - TPC x [cm];", 80, -200,200);
  hmap_xdiff["background"] = new TH1D("h_xdiff_background", ";QLL x - TPC x [cm];", 80, -200,200);
  std::map<std::string,TH1D*> hmap_zdiff;
  hmap_zdiff["total"] = new TH1D("h_zdiff_total", ";Hypo z - Flash z [cm];", 160, -400,400);
  hmap_zdiff["signal"] = new TH1D("h_zdiff_signal", ";Hypo z - Flash z [cm];", 160, -400,400);
  hmap_zdiff["background"] = new TH1D("h_zdiff_background", ";Hypo z - Flash z [cm];", 160, -400,400);
  std::map<std::string,TH1D*> hmap_pediff;
  hmap_pediff["total"] = new TH1D("h_pediff_total", ";Hypo PE - Flash PE [p.e.];", 160, -400,400);
  hmap_pediff["signal"] = new TH1D("h_pediff_signal", ";Hypo PE - Flash PE [p.e.];", 160, -400,400);
  hmap_pediff["background"] = new TH1D("h_pediff_background", ";Hypo PE - Flash PE [p.e.];", 160, -600,600);

  std::map<std::string,TH1D*> hmap_vtxcheck_angle;
  hmap_vtxcheck_angle["total"] = new TH1D("h_vtxcheck_angle_total", ";Angle [rad];Entries per bin", 80, 0, 4);
  hmap_vtxcheck_angle["signal"] = new TH1D("h_vtxcheck_angle_signal", ";Angle [rad];Entries per bin", 80, 0, 4);
  hmap_vtxcheck_angle["background"] = new TH1D("h_vtxcheck_angle_background", ";Angle [rad];Entries per bin", 80, 0, 4);
  
  TH1D* h_vtxcheck_angle_good = new TH1D("h_vtxcheck_angle_good", ";Angle [rad];Entries per bin", 100, 0, 4);
  TH1D* h_vtxcheck_angle_bad  = new TH1D("h_vtxcheck_angle_bad",  ";Angle [rad];Entries per bin",  100, 0, 4);
  
  std::map<std::string,TH1D*> hmap_residuals_std;
  hmap_residuals_std["total"] = new TH1D("h_residuals_std_total", ";#sigma_{r_{i}};Entries per bin", 40, 0, 10);
  hmap_residuals_std["signal"] = new TH1D("h_residuals_std_signal", ";Angle [rad];Entries per bin", 40, 0, 10);
  hmap_residuals_std["background"] = new TH1D("h_residuals_std_background", ";Angle [rad];Entries per bin", 40, 0, 10);
  std::map<std::string,TH1D*> hmap_residuals_mean;
  hmap_residuals_mean["total"] = new TH1D("h_residuals_mean_total", ";<r_{i}>;Entries per bin", 40, -5, 5);
  hmap_residuals_mean["signal"] = new TH1D("h_residuals_mean_signal", ";<r_{i}>;Entries per bin", 40, -5, 5);
  hmap_residuals_mean["background"] = new TH1D("h_residuals_mean_background", ";<r_{i}>;Entries per bin", 40, -5, 5);
  std::map<std::string,TH1D*> hmap_perc_used_hits;
  hmap_perc_used_hits["total"] = new TH1D("h_perc_used_hits_total", ";Fraction of used hits in cluster;Entries per bin", 30, 0, 1);
  hmap_perc_used_hits["signal"] = new TH1D("h_perc_used_hits_signal", ";Fraction of used hits in cluster;Entries per bin", 30, 0, 1);
  hmap_perc_used_hits["background"] = new TH1D("h_perc_used_hits_background", ";Fraction of used hits in cluster;Entries per bin", 30, 0, 1);

  std::map<std::string,TH1D*> hmap_mom_mcs_length;
  hmap_mom_mcs_length["total"] = new TH1D("h_mom_mcs_length_total", ";(MCS - Length) Reconstructed Momentum [GeV];Entries per bin", 20, -0.5, 1.5);
  hmap_mom_mcs_length["signal"] = new TH1D("h_mom_mcs_length_signal", ";(MCS - Length) Reconstructed Momentum [GeV];Entries per bin", 20, -0.5, 1.5);
  hmap_mom_mcs_length["background"] = new TH1D("h_mom_mcs_length_background", ";(MCS - Length) Reconstructed Momentum [GeV];Entries per bin", 20, -0.5, 1.5);

  TH1D* h_muon_track_eff  = new TH1D("h_muon_track_eff",  ";Muon track efficiency;Entries per bin",  100, 0, 1);
  TH1D* h_muon_track_pur  = new TH1D("h_muon_track_pur",  ";Muon track purity;Entries per bin",  100, 0, 1);
  
  TH1D* h_mueff_num = new TH1D("h_mueff_num", "h_mueff_num", 30, 0, 2);
  TH1D* h_mueff_2_num = new TH1D("h_mueff_2_num", "h_mueff_2_num", 30, 0, 2);
  TH1D* h_mueff_den = new TH1D("h_mueff_den", "h_mueff_den", 30, 0, 2);
  TH1D* h_mueff_angle_num = new TH1D("h_mueff_angle_num", "h_mueff_num", 15, -1, 1);
  TH1D* h_mueff_angle_den = new TH1D("h_mueff_angle_den", "h_mueff_den", 15, -1, 1);

  TH2D* h_mu_eff_mom = new TH2D("h_mu_eff_mom", ";True Muon Momentum [GeV]; Efficiency", 50, 0, 2, 20, 0, 1);
  TH2D* h_mu_pur_mom = new TH2D("h_mu_pur_mom", ";True Muon Momentum [GeV]; Purity", 50, 0, 2, 20, 0, 1);
  TH2D* h_mu_eff_mom_sel = new TH2D("h_mu_eff_mom_sel", "After Selection;True Muon Momentum [GeV]; Efficiency", 50, 0, 2, 20, 0, 1);
  
  TH2D* h_mumom_nue = new TH2D("h_mumom_nue", ";True Neutrino Energy [GeV]; True Muon Momentum [GeV]", 50, 0, 2, 50, 0, 4);
  
  TH1D* h_acpt_tagged  = new TH1D("h_acpt_tagged",  ";Tagged TPC Objects;Entries per bin",  10, 0, 10);
  
  TH1D* h_slice_origin = new TH1D("h_slice_origin",  ";;",  3, -0.5, 2.5);
  
  TH1D* h_slice_npfp = new TH1D("h_slice_npfp",  ";npfp;",  10, 0, 10);
  TH1D* h_slice_npfp_others = new TH1D("h_slice_npfp_others",  ";npfp;",  10, 0, 10);
  
  TH1D* h_slice_ntrack = new TH1D("h_slice_ntrack",  ";npfp;",  10, 0, 10);
  TH1D* h_slice_ntrack_others = new TH1D("h_slice_ntrack_others",  ";npfp;",  10, 0, 10);
  
  TH1D* h_fm_score = new TH1D("h_fm_score",  ";fm score;",  500, 0, 10);
  TH1D* h_fm_score_others = new TH1D("h_fm_score_other",  ";fm score;",  500, 0, 10);
  TH2D* h_fm_score_pe = new TH2D("h_fm_score_pe",  ";fm score;Reco PE",  500, 0, 10, 500, 0, 2000);
  
  TH1D* h_n_slc_flsmatch = new TH1D("h_n_slc_flsmatch",  ";n slices flash matched per event;",  10, 0, 10);



  std::map<std::string,TH1D*> hmap_trklen;
  hmap_trklen["total"] = new TH1D("h_trklen_total", "; Track length;", 30, 0, 700);
  hmap_trklen["signal"] = new TH1D("h_trklen_signal", "; Track length;", 30, 0, 700);
  hmap_trklen["cosmic"] = new TH1D("h_trklen_cosmic", "; Track length;", 30, 0, 700);
  hmap_trklen["cosmic_stopmu"] = new TH1D("h_trklen_cosmic_stopmu", "; Track length;", 30, 0, 700);
  hmap_trklen["cosmic_nostopmu"] = new TH1D("h_trklen_cosmic_nostopmu", "; Track length;", 30, 0, 700);
  hmap_trklen["outfv"] = new TH1D("h_trklen_outfv", "; Track length;", 30, 0, 700);
  hmap_trklen["outfv_stopmu"] = new TH1D("h_trklen_outfv_stopmu", "; Track length;", 30, 0, 700);
  hmap_trklen["outfv_nostopmu"] = new TH1D("h_trklen_outfv_nostopmu", "; Track length;", 30, 0, 700);
  hmap_trklen["nc"] = new TH1D("h_trklen_nc", "; Track length;", 30, 0, 700);
  hmap_trklen["nc_proton"] = new TH1D("h_trklen_nc_proton", "; Track length;", 30, 0, 700);
  hmap_trklen["nc_pion"] = new TH1D("h_trklen_nc_pion", "; Track length;", 30, 0, 700);
  hmap_trklen["nc_other"] = new TH1D("h_trklen_nc_other", "; Track length;", 30, 0, 700);
  hmap_trklen["anumu"] = new TH1D("h_trklen_anumu", "; Track length;", 30, 0, 700);
  hmap_trklen["nue"] = new TH1D("h_trklen_nue", "; Track length;", 30, 0, 700);
  hmap_trklen["signal_stopmu"] = new TH1D("h_trklen_signal_stopmu", "; Track length;", 30, 0, 700);
  hmap_trklen["signal_nostopmu"] = new TH1D("h_trklen_signal_nostopmu", "; Track length;", 30, 0, 700);
  
  
  std::map<std::string,TH1D*> hmap_trkmom_classic;
  hmap_trkmom_classic["total"] = new TH1D("h_trkmom_classic_total", "; Track length;", 20, 0, 2.5); // 20, 0, 2.5
  hmap_trkmom_classic["signal"] = new TH1D("h_trkmom_classic_signal", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["cosmic"] = new TH1D("h_trkmom_classic_cosmic", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["cosmic_stopmu"] = new TH1D("h_trkmom_classic_cosmic_stopmu", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["cosmic_nostopmu"] = new TH1D("h_trkmom_classic_cosmic_nostopmu", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["outfv"] = new TH1D("h_trkmom_classic_outfv", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["outfv_stopmu"] = new TH1D("h_trkmom_classic_outfv_stopmu", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["outfv_nostopmu"] = new TH1D("h_trkmom_classic_outfv_nostopmu", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["nc"] = new TH1D("h_trkmom_classic_nc", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["nc_proton"] = new TH1D("h_trkmom_classic_nc_proton", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["nc_pion"] = new TH1D("h_trkmom_classic_nc_pion", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["nc_other"] = new TH1D("h_trkmom_classic_nc_other", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["anumu"] = new TH1D("h_trkmom_classic_anumu", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["nue"] = new TH1D("h_trkmom_classic_nue", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["signal_stopmu"] = new TH1D("h_trkmom_classic_signal_stopmu", "; Track length;", 20, 0, 2.5);
  hmap_trkmom_classic["signal_nostopmu"] = new TH1D("h_trkmom_classic_signal_nostopmu", "; Track length;", 20, 0, 2.5);

  // Number of events histograms - Cross Section Muon Momentum - GENIE pm1sigma
  std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_genie_pm1_bs;
  hmap_trkmom_genie_pm1_bs["total"]["nominal"] = new TH1D("h_trkmom_total_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["signal"]["nominal"] = new TH1D("h_trkmom_signal_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["cosmic"]["nominal"] = new TH1D("h_trkmom_cosmic_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["cosmic_stopmu"]["nominal"] = new TH1D("h_trkmom_cosmic_stopmu_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["cosmic_nostopmu"]["nominal"] = new TH1D("h_trkmom_cosmic_nostopmu_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["outfv"]["nominal"] = new TH1D("h_trkmom_outfv_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["outfv_stopmu"]["nominal"] = new TH1D("h_trkmom_outfv_stopmu_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["outfv_nostopmu"]["nominal"] = new TH1D("h_trkmom_outfv_nostopmu_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["nc"]["nominal"] = new TH1D("h_trkmom_nc_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["nc_proton"]["nominal"] = new TH1D("h_trkmom_nc_proton_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["nc_pion"]["nominal"] = new TH1D("h_trkmom_nc_pion_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["nc_other"]["nominal"] = new TH1D("h_trkmom_nc_other_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["anumu"]["nominal"] = new TH1D("h_trkmom_anumu_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["nue"]["nominal"] = new TH1D("h_trkmom_nue_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["signal_stopmu"]["nominal"] = new TH1D("h_trkmom_signal_stopmu_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);
  hmap_trkmom_genie_pm1_bs["signal_nostopmu"]["nominal"] = new TH1D("h_trkmom_signal_nostopmu_genie_pm1_nominal", "; Track length;", n_bins_mumom, bins_mumom);

  std::map<std::string,TH1D*> hmap_trkphi;
  hmap_trkphi["total"] = new TH1D("h_trkphi_total", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["signal"] = new TH1D("h_trkphi_signal", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["cosmic"] = new TH1D("h_trkphi_cosmic", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["outfv"] = new TH1D("h_trkphi_outfv", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["nc"] = new TH1D("h_trkphi_nc", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["anumu"] = new TH1D("h_trkphi_anumu", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["nue"] = new TH1D("h_trkphi_nue", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["cosmic_stopmu"] = new TH1D("h_trkphi_cosmic_stopmu", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["cosmic_nostopmu"] = new TH1D("h_trkphi_cosmic_nostopmu", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["outfv_stopmu"] = new TH1D("h_trkphi_outfv_stopmu", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["outfv_nostopmu"] = new TH1D("h_trkphi_outfv_nostopmu", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["nc_proton"] = new TH1D("h_trkphi_nc_proton", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["nc_pion"] = new TH1D("h_trkphi_nc_pion", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["nc_other"] = new TH1D("h_trkphi_nc_other", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["signal_stopmu"] = new TH1D("h_trkphi_signal_stopmu", "; Track #phi;", 20, -3.15, 3.15);
  hmap_trkphi["signal_nostopmu"] = new TH1D("h_trkphi_signal_nostopmu", "; Track #phi;", 20, -3.15, 3.15);
  
  std::map<std::string,TH1D*> hmap_trktheta_classic;
  hmap_trktheta_classic["total"] = new TH1D("h_trktheta_classic_total", "; Track cos(#theta);", 30, -1, 1); // 30, -1, 1
  hmap_trktheta_classic["signal"] = new TH1D("h_trktheta_classic_signal", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["cosmic"] = new TH1D("h_trktheta_classic_cosmic", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["outfv"] = new TH1D("h_trktheta_classic_outfv", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["nc"] = new TH1D("h_trktheta_classic_nc", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["anumu"] = new TH1D("h_trktheta_classic_anumu", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["nue"] = new TH1D("h_trktheta_classic_nue", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["cosmic_stopmu"] = new TH1D("h_trktheta_classic_cosmic_stopmu", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["cosmic_nostopmu"] = new TH1D("h_trktheta_classic_cosmic_nostopmu", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["outfv_stopmu"] = new TH1D("h_trktheta_classic_outfv_stopmu", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["outfv_nostopmu"] = new TH1D("h_trktheta_classic_outfv_nostopmu", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["nc_proton"] = new TH1D("h_trktheta_classic_nc_proton", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["nc_pion"] = new TH1D("h_trktheta_classic_nc_pion", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["nc_other"] = new TH1D("h_trktheta_classic_nc_other", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["signal_stopmu"] = new TH1D("h_trktheta_classic_signal_stopmu", "; Track cos(#theta);", 30, -1, 1);
  hmap_trktheta_classic["signal_nostopmu"] = new TH1D("h_trktheta_classic_signal_nostopmu", "; Track cos(#theta);", 30, -1, 1);

  std::map<std::string,TH1D*> hmap_multpfp;
  hmap_multpfp["total"] = new TH1D("h_multpfp_total", "; PFP Multiplicity", 10, 0, 10);
  hmap_multpfp["signal"] = new TH1D("h_multpfp_signal", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["cosmic"] = new TH1D("h_multpfp_cosmic", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["outfv"] = new TH1D("h_multpfp_outfv", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["nc"] = new TH1D("h_multpfp_nc", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["anumu"] = new TH1D("h_multpfp_anumu", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["nue"] = new TH1D("h_multpfp_nue", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["cosmic_stopmu"] = new TH1D("h_multpfp_cosmic_stopmu", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["cosmic_nostopmu"] = new TH1D("h_multpfp_cosmic_nostopmu", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["outfv_stopmu"] = new TH1D("h_multpfp_outfv_stopmu", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["outfv_nostopmu"] = new TH1D("h_multpfp_outfv_nostopmu", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["nc_proton"] = new TH1D("h_multpfp_nc_proton", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["nc_pion"] = new TH1D("h_multpfp_nc_pion", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["nc_other"] = new TH1D("h_multpfp_nc_other", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["signal_stopmu"] = new TH1D("h_multpfp_signal_stopmu", "; PFP Multiplicity;", 10, 0, 10);
  hmap_multpfp["signal_nostopmu"] = new TH1D("h_multpfp_signal_nostopmu", "; PFP Multiplicity;", 10, 0, 10);

  std::map<std::string,TH1D*> hmap_multtracktol;
  hmap_multtracktol["total"] = new TH1D("h_multtracktol_total", "; Track Multiplicity (5 cm)", 10, 0, 10);
  hmap_multtracktol["signal"] = new TH1D("h_multtracktol_signal", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["cosmic"] = new TH1D("h_multtracktol_cosmic", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["outfv"] = new TH1D("h_multtracktol_outfv", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["nc"] = new TH1D("h_multtracktol_nc", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["anumu"] = new TH1D("h_multtracktol_anumu", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["nue"] = new TH1D("h_multtracktol_nue", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["cosmic_stopmu"] = new TH1D("h_multtracktol_cosmic_stopmu", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["cosmic_nostopmu"] = new TH1D("h_multtracktol_cosmic_nostopmu", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["outfv_stopmu"] = new TH1D("h_multtracktol_outfv_stopmu", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["outfv_nostopmu"] = new TH1D("h_multtracktol_outfv_nostopmu", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["nc_proton"] = new TH1D("h_multtracktol_nc_proton", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["nc_pion"] = new TH1D("h_multtracktol_nc_pion", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["nc_other"] = new TH1D("h_multtracktol_nc_other", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["signal_stopmu"] = new TH1D("h_multtracktol_signal_stopmu", "; Track Multiplicity (5 cm);", 10, 0, 10);
  hmap_multtracktol["signal_nostopmu"] = new TH1D("h_multtracktol_signal_nostopmu", "; Track Multiplicity (5 cm);", 10, 0, 10);
  
  std::map<std::string,TH1D*> hmap_dqdx_trunc;
  hmap_dqdx_trunc["total"] = new TH1D("h_dqdx_trunc_total", ";<dQ/dx>_{trunc};", 40, 0, 200000);//40, 0, 800);
  hmap_dqdx_trunc["muon"] = new TH1D("h_dqdx_trunc_muon", ";<dQ/dx>_{trunc};", 40, 0, 200000);
  hmap_dqdx_trunc["proton"] = new TH1D("h_dqdx_trunc_proton", ";<dQ/dx>_{trunc};", 40, 0, 200000);
  hmap_dqdx_trunc["pion"] = new TH1D("h_dqdx_trunc_pions", ";<dQ/dx>_{trunc};", 40, 0, 200000);
  hmap_dqdx_trunc["photon"] = new TH1D("h_dqdx_trunc_photon", ";<dQ/dx>_{trunc};", 40, 0, 200000);
  hmap_dqdx_trunc["electron"] = new TH1D("h_dqdx_trunc_electron", ";<dQ/dx>_{trunc};", 40, 0, 200000);
  hmap_dqdx_trunc["else"] = new TH1D("h_dqdx_trunc_else", ";<dQ/dx>_{trunc};", 40, 0, 200000);
  
  TH2D *h_dqdx_trunc_length = new TH2D("h_dqdx_trunc_length", ";Candidate Track <dQ/dx>_{trunc};Track Length [cm]", 40, 0, 200000,40, 0, 700);
  TH2D *h_dqdx_trunc_length_muon = new TH2D("h_dqdx_trunc_length_muon", ";Candidate Track <dQ/dx>_{trunc};Track Length [cm]", 40, 0, 200000,40, 0, 700);
  TH2D *h_dqdx_trunc_length_proton = new TH2D("h_dqdx_trunc_length_proton", ";Candidate Track <dQ/dx>_{trunc};Track Length [cm]", 40, 0, 200000,40, 0, 700);

  std::map<std::string,TH1D*> hmap_vtxx;
  hmap_vtxx["total"] = new TH1D("h_vtxx_total", ";Candidate Neutrino Vertex X [cm];", 40, 0, 275);
  hmap_vtxx["signal"] = new TH1D("h_vtxx_signal", ";Candidate Neutrino Vertex X [cm];", 40, 0,275);
  hmap_vtxx["background"] = new TH1D("h_vtxx_background", ";Candidate Neutrino Vertex X [cm];", 40, 0,275);
  
  std::map<std::string,TH1D*> hmap_vtxx_b;
  hmap_vtxx_b["total"] = new TH1D("h_vtxx_total_b", ";Candidate Neutrino Vertex X [cm];", 40, 0, 275);
  hmap_vtxx_b["signal"] = new TH1D("h_vtxx_signal_b", ";Candidate Neutrino Vertex X [cm];", 40, 0,275);
  hmap_vtxx_b["background"] = new TH1D("h_vtxx_background_b", ";Candidate Neutrino Vertex X [cm];", 40, 0,275);
  
  std::map<std::string,TH1D*> hmap_vtxy;
  hmap_vtxy["total"] = new TH1D("h_vtxy_total", ";Candidate Neutrino Vertex Y [cm];", 40, -125,125);
  hmap_vtxy["signal"] = new TH1D("h_vtxy_signal", ";Candidate Neutrino Vertex Y [cm];", 40, -125,125);
  hmap_vtxy["background"] = new TH1D("h_vtxy_background", ";Candidate Neutrino Vertex Y [cm];", 40, -125,125);
  
  std::map<std::string,TH1D*> hmap_vtxy_b;
  hmap_vtxy_b["total"] = new TH1D("h_vtxy_total_b", ";Candidate Neutrino Vertex Y [cm];", 40, -125,125);
  hmap_vtxy_b["signal"] = new TH1D("h_vtxy_signal_b", ";Candidate Neutrino Vertex Y [cm];", 40, -125,125);
  hmap_vtxy_b["background"] = new TH1D("h_vtxy_background_b", ";Candidate Neutrino Vertex Y [cm];", 40, -125,125);
  
  std::map<std::string,TH1D*> hmap_vtxz;
  hmap_vtxz["total"] = new TH1D("h_vtxz_total", ";Candidate Neutrino Vertex Z [cm];", 50, 0,1050);
  hmap_vtxz["signal"] = new TH1D("h_vtxz_signal", ";Candidate Neutrino Vertex Z [cm];", 50, 0,1050);
  hmap_vtxz["background"] = new TH1D("h_vtxz_background", ";Candidate Neutrino Vertex Z [cm];", 50, 0,1050);
  
  std::map<std::string,TH1D*> hmap_vtxz_b;
  hmap_vtxz_b["total"] = new TH1D("h_vtxz_total_b", ";Candidate Neutrino Vertex Z [cm];", 50, 0,1050);
  hmap_vtxz_b["signal"] = new TH1D("h_vtxz_signal_b", ";Candidate Neutrino Vertex Z [cm];", 50, 0,1050);
  hmap_vtxz_b["background"] = new TH1D("h_vtxz_background_b", ";Candidate Neutrino Vertex Z [cm];", 50, 0,1050);
  
  TH2D * h_vtx_xz = new TH2D("h_vtx_xz", ";X;Z", 40, 0, 275, 50, 0,1050);
  TH2D * h_vtx_xy = new TH2D("h_vtx_xy", ";X;Y", 40, 0, 275, 40, -125,125);

  std::map<std::string,TH1D*> hmap_vtxz_upborder;
  hmap_vtxz_upborder["total"] = new TH1D("h_vtxz_upborder_total", ";Candidate Neutrino Vertex Z [cm];", 3, 0,1050);
  hmap_vtxz_upborder["signal"] = new TH1D("h_vtxz_upborder_signal", ";Candidate Neutrino Vertex Z [cm];", 3, 0,1050);
  hmap_vtxz_upborder["background"] = new TH1D("h_vtxz_upborder_background", ";Candidate Neutrino Vertex Z [cm];", 3, 0,1050);

  std::map<std::string,TH1D*> hmap_vtxx_upborder;
  hmap_vtxx_upborder["total"] = new TH1D("h_vtxx_upborder_total", ";Candidate Neutrino Vertex X [cm];", 5, 0, 275);
  hmap_vtxx_upborder["signal"] = new TH1D("h_vtxx_upborder_signal", ";Candidate Neutrino Vertex X [cm];", 5, 0, 275);
  hmap_vtxx_upborder["background"] = new TH1D("h_vtxx_upborder_background", ";Candidate Neutrino Vertex X [cm];", 5, 0, 275);

  std::map<std::string,TH1D*> hmap_flsmatch_score;
  hmap_flsmatch_score["total"] = new TH1D("h_flsmatch_score_total", ";1/(-log(L));", 80, 0, 1.5);
  hmap_flsmatch_score["signal"] = new TH1D("h_flsmatch_score_signal", ";1/(-log(L));", 80, 0, 1.5);
  hmap_flsmatch_score["background"] = new TH1D("h_flsmatch_score_background", ";1/(-log(L));", 80, 0, 1.5);

  std::map<std::string,TH1D*> hmap_flsmatch_score_second;
  hmap_flsmatch_score_second["total"] = new TH1D("h_flsmatch_score_second_total", ";1/(-log(L));", 80, 0, 1.5);
  hmap_flsmatch_score_second["signal"] = new TH1D("h_flsmatch_score_second_signal", ";1/(-log(L));", 80, 0, 1.5);
  hmap_flsmatch_score_second["background"] = new TH1D("h_flsmatch_score_second_background", ";1/(-log(L));", 80, 0, 1.5);

  std::map<std::string,TH1D*> hmap_flsmatch_score_difference;
  hmap_flsmatch_score_difference["total"] = new TH1D("h_flsmatch_score_difference_total", ";1/(-log(L));", 80, 0, 0.2);
  hmap_flsmatch_score_difference["signal"] = new TH1D("h_flsmatch_score_difference_signal", ";1/(-log(L));", 80, 0, 0.2);
  hmap_flsmatch_score_difference["background"] = new TH1D("h_flsmatch_score_difference_background", ";1/(-log(L));", 80, 0, 0.2);

  std::map<std::string,TH1D*> hmap_ntpcobj;
  hmap_ntpcobj["total"] = new TH1D("h_ntpcobj_total", ";1/(-log(L));", 10, 0, 10);
  hmap_ntpcobj["signal"] = new TH1D("h_ntpcobj_signal", ";1/(-log(L));", 10, 0, 10);
  hmap_ntpcobj["background"] = new TH1D("h_ntpcobj_background", ";1/(-log(L));", 10, 0, 10);
  
  TH1D* h_pot = new TH1D("h_pot", "First bin contains number of POT (not valid on data)", 1, 0, 1);
  TH1D* h_nevts = new TH1D("h_nevts", "First bin contains number of events", 1, 0, 1);

  
  TH1D * h_deltall_cosmic_stop = new TH1D("h_deltall_cosmic_stop", "Cosmic stopping Muons;MCS Delta LL;", 400, -30, 30);
  TH2D * h_deltall_length_cosmic_stop = new TH2D("h_deltall_length_cosmic_stop", "Cosmic stopping Muons;MCS Delta LL;Track Length [cm]", 70, -30, 30, 70, 0, 700);
  TH1D * h_deltall_cosmic_nostop = new TH1D("h_deltall_cosmic_nostop", "Cosmic non-stopping Muons;MCS Delta LL;", 400, -30, 30);
  TH2D * h_deltall_length_cosmic_nostop = new TH2D("h_deltall_length_cosmic_nostop", "Cosmic non-stopping Muons;MCS Delta LL;Track Length [cm]", 70, -30, 30, 70, 0, 700);
  TH1D * h_deltall_nu = new TH1D("h_deltall_nu", "Neutrino origin;MCS Delta LL;", 400, -30, 30);
  TH2D * h_deltall_length_nu = new TH2D("h_deltall_length_nu", "Neutrino origin;MCS Delta LL;Track Length [cm]", 70, -30, 30, 70, 0, 700);

  TH1D* h_trklen_first = new TH1D("h_trklen_first", "h_trklen_first", 60, 0, 700);
  TH1D* h_trklen_second = new TH1D("h_trklen_second", "h_trklen_second", 60, 0, 700);

  std::vector<std::string> fname_genie_pm1;
  std::vector<std::string> fname_genie_multisim;
  std::vector<std::string> fname_mc_stat_multisim;
  std::vector<std::string> fname_extra_syst;
  std::vector<std::string> fname_flux_multisim;


  if (_maup_mecoff && !isdata) {
    PrintMaUpMECOff();
  }

  if (_reweigh_kaons) {
    PrintReweighKaons();
  }
    
  int barWidth = 70;
  
  if(maxEntries > 0.) evts = maxEntries;

  evts += _initial_entry;

  LOG_NORMAL() << "Looping over " << evts - _initial_entry << " events starting with entry " << _initial_entry << std::endl;
  
  int total_events = 0;

  std::vector<int> run_numbers, subrun_numbers, event_numbers;
  run_numbers.resize(evts); subrun_numbers.resize(evts); event_numbers.resize(evts);
  
  
  for(int i = _initial_entry; i < evts; i++) {
    
    if (i != 0) DrawProgressBar((double)i/(double)evts, barWidth);
    
    chain_ubxsec->GetEntry(i);
    
    total_events ++;
    
    //cout << "***** Event " << i << endl;
    //cout << "***** Event Number " << t->event << endl;
    run_numbers.at(i) = t->run;
    subrun_numbers.at(i) = t->subrun;
    event_numbers.at(i) = t->event;

    // Check for duplicate MC events
    if (_check_duplicate_events){
      
      if (std::count (event_numbers.begin(), event_numbers.end(), t->event) > 1) {

        // Now check the subrun
        for (size_t i_ev = 0; i_ev < event_numbers.size(); i_ev++) {
          if (event_numbers.at(i_ev) == t->event) {

            if (run_numbers.at(i_ev) == t->run && subrun_numbers.at(i_ev) == t->subrun) {
              std::cout << "Found duplicate event: " << t->event << std::endl;
            }
            break;
          }
        }
      }
    }


    // ************************
    //
    // Total event weight (BNB Correction)
    //
    // ************************

    double event_weight = t->bnb_weight;
    event_weight *= _extra_weight;
    if (isdata) event_weight = 1.;

    if (t->file_type == "dirt") event_weight /= _extra_weight;


    bool is_from_kaon = false;

    // ************************
    //
    // Check if running with Ma+1sigma and MEC off
    //
    // ************************

    if(_maup_mecoff && !isdata) {

      // Remove MEC events
      if (t->mode == 10) {
        continue;
      }

      // Scale up Ma CCQE
      for (size_t i = 0; i < t->evtwgt_genie_pm1_weight.size(); i++) {
        if (t->evtwgt_genie_pm1_funcname.at(i) == "genie_qema_Genie") {
          event_weight *= t->evtwgt_genie_pm1_weight.at(i).at(0);
        }
      }
    }

    if (!isdata && false) {
      LOG_CRITICAL() << "SPECIAL WEIGHTS APPLIED!!! MODEL 0" << std::endl;
      if (t->mode == 0) { // QE
        event_weight *= 0.95; 
      }
      if (t->mode == 1) { // RES
        event_weight *= 0.75; 
      }
      if (t->mode == 2) { // DIS
        event_weight *= 0.85; 
      }
      if (t->mode == 3) { // COH
        event_weight *= 1.00; 
      }
      if (t->mode == 10) { // MEC
        event_weight *= 0.85; 
      }
    }

    if (!isdata && false) {
      LOG_CRITICAL() << "SPECIAL WEIGHTS APPLIED!!! MODEL 1" << std::endl;
      if (t->mode == 0) { // QE
        event_weight *= 0.90; 
      }
      if (t->mode == 1) { // RES
        event_weight *= 0.00; 
      }
      if (t->mode == 2) { // DIS
        event_weight *= 3.00; 
      }
      if (t->mode == 3) { // COH
        event_weight *= 1.00; 
      }
      if (t->mode == 10) { // MEC
        event_weight *= 1.10; 
      }
    }

    if (!isdata && false) {
      LOG_CRITICAL() << "SPECIAL WEIGHTS APPLIED!!! MODEL 2" << std::endl;
      if (t->mode == 0) { // QE
        event_weight *= 1.00; 
      }
      if (t->mode == 1) { // RES
        event_weight *= 1.50; 
      }
      if (t->mode == 2) { // DIS
        event_weight *= 1.00; 
      }
      if (t->mode == 3) { // COH
        event_weight *= 1.00; 
      }
      if (t->mode == 10) { // MEC
        event_weight *= 0.00; 
      }
    }




    // ************************
    //
    // Set weight names, prepare bootstraps -- PM1SIGMA
    //
    // ************************

    // Set the weight names, just do it once (first event only)

    if (i == _initial_entry && !isdata && _fill_bootstrap_genie) {

      for (auto name : t->evtwgt_genie_pm1_funcname) {
        fname_genie_pm1.push_back(name + "_p1");
        fname_genie_pm1.push_back(name + "_m1");
      }


      // Number of events
      for (auto iter : hmap_trkmom_genie_pm1_bs) {

        std::string this_name = iter.first;
        std::map<std::string, TH1D*> bs_map = iter.second;

        // Now emplace the histograms for the variations
        for (size_t i = 0; i < fname_genie_pm1.size(); i++) {

          std::string histo_name = "h_trkmom_" + this_name + "_" + fname_genie_pm1.at(i);
          double this_bins_mumom[7] = {0.00, 0.18, 0.30, 0.45, 0.77, 1.28, 2.50};
          hmap_trkmom_genie_pm1_bs[this_name][fname_genie_pm1.at(i)] = new TH1D(histo_name.c_str(), "; Track length;", 6, this_bins_mumom); 

        }

      }

      // Efficiency
      for (size_t i = 0; i < fname_genie_pm1.size(); i++) {
        double this_bins_mumom[7] = {0.00, 0.18, 0.30, 0.45, 0.77, 1.28, 2.50};
        std::string histo_name;// = "bs_genie_pm1_eff_mumom_num_" + fname_genie_pm1.at(i);

        histo_name = "bs_genie_pm1_true_reco_mom_" + fname_genie_pm1.at(i);
        bs_genie_pm1_true_reco_mom[fname_genie_pm1.at(i)] = new TH2D(histo_name.c_str(), ";Muon Momentum (Truth) [GeV]; Muon Momentum (MCS) [GeV]", 6, this_bins_mumom, 6, this_bins_mumom);
      }
      

      bs_genie_pm1_eff_mumom_num.SetWeightNames(fname_genie_pm1);
      bs_genie_pm1_eff_mumom_den.SetWeightNames(fname_genie_pm1);
      
    }

    // Prepare the vector of weights to be used for bootstraps
    std::vector<double> wgts_genie_pm1;
    if (!isdata && _fill_bootstrap_genie) {
      for (size_t i = 0; i < t->evtwgt_genie_pm1_weight.size(); i++) {
        wgts_genie_pm1.push_back(t->evtwgt_genie_pm1_weight.at(i).at(0));
        wgts_genie_pm1.push_back(t->evtwgt_genie_pm1_weight.at(i).at(1));
      }
    }


    // ************************
    //
    // Set weight names, prepare bootstraps -- GENIE MULTISIM
    //
    // ************************


    if (i == _initial_entry && !isdata && _fill_bootstrap_genie) {

      if (t->evtwgt_genie_multisim_nfunc == 1) {

        if (t->evtwgt_genie_multisim_funcname.at(0) != "genie_all_Genie") {
          std::cout << "GENIE Multisim: func name is " << t->evtwgt_genie_multisim_funcname.at(0) 
                    << " which is different than genie_all" << std::endl;
        }

        fname_genie_multisim.clear();
        fname_genie_multisim.resize(t->evtwgt_genie_multisim_nweight.at(0));

        std::ostringstream oss;
        for (size_t i_wgt = 0; i_wgt < fname_genie_multisim.size(); i_wgt++) {
          oss.str("");
          oss << "universe" << i_wgt;
          fname_genie_multisim.at(i_wgt) = oss.str();
        }

        LOG_NORMAL() << "GENIE Multisim Number of universes: " << fname_genie_multisim.size() << std::endl;


        // Number of events
        for (auto & iter : _event_histo_1d->hmap_trkmom_genie_multisim_bs /*map_bs_trkmom_genie_multisim*/) {


          std::string this_name = iter.first;

          // Now emplace the histograms for the variations
          for (size_t i = 0; i < fname_genie_multisim.size(); i++) {

            // Single - Muon Momentum
            std::string histo_name = "h_genie_multisim_trkmom_" + this_name + "_" + fname_genie_multisim.at(i);
            _event_histo_1d->hmap_trkmom_genie_multisim_bs[this_name][fname_genie_multisim.at(i)] = new TH1D(histo_name.c_str(), "; Track length;", n_bins_mumom, bins_mumom);

            // Signle - Muon Angle
            histo_name = "h_genie_multisim_trkangle_" + this_name + "_" + fname_genie_multisim.at(i); 
            _event_histo_1d->hmap_trkangle_genie_multisim_bs[this_name][fname_genie_multisim.at(i)] = new TH1D(histo_name.c_str(), "; Track angle;", n_bins_mucostheta, bins_mucostheta); 

            // Total
            histo_name = "h_genie_multisim_onebin_" + this_name + "_" + fname_genie_multisim.at(i); 
            _event_histo_1d->hmap_onebin_genie_multisim_bs[this_name][fname_genie_multisim.at(i)] = new TH1D(histo_name.c_str(), "; Track angle;", 1, 0, 1);

            // Double Diff
            histo_name = "h_genie_multisim_trkmom_trkangle_" + this_name + "_" + fname_genie_multisim.at(i); 
            _event_histo->hmap_trktheta_trkmom_genie_multisim_bs[this_name][fname_genie_multisim.at(i)] = new TH2D(histo_name.c_str(), "; Track angle;", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);

            // Double Diff (polybins)
            histo_name = "h_poly_genie_multisim_trkmom_trkangle_" + this_name + "_" + fname_genie_multisim.at(i); 
            _event_histo->hmap_trktheta_trkmom_poly_genie_multisim_bs[this_name][fname_genie_multisim.at(i)] = new UBTH2Poly(histo_name.c_str(), "; Track angle;", -1.0, 1.0, 0.0, 2.5);
          }

        }

        
        for (size_t i = 0; i < fname_genie_multisim.size(); i++) {

          // Normal Bins
          std::string histo_name;
          histo_name = "bs_genie_multisim_reco_per_true_" + fname_genie_multisim.at(i);
          _event_histo->bs_genie_multisim_reco_per_true[fname_genie_multisim.at(i)].resize(n_bins_double_mucostheta, std::vector<TH2D*>(n_bins_double_mumom));
          
          for (int m = 0; m < n_bins_double_mucostheta; m++) {
            for (int n = 0; n < n_bins_double_mumom; n++) { 
              std::stringstream sstm;
              sstm << histo_name << "_" << m << "_" << n;
              _event_histo->bs_genie_multisim_reco_per_true[fname_genie_multisim.at(i)][m][n] = new TH2D(sstm.str().c_str(), "reco_per_true", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
            }
          }


          // Poly bins
          histo_name = "bs_genie_multisim_poly_reco_per_true_" + fname_genie_multisim.at(i);
          _event_histo->bs_genie_multisim_poly_reco_per_true[fname_genie_multisim.at(i)].resize(_n_poly_bins);
          
          for (int m = 0; m < _n_poly_bins; m++) {
            _event_histo->bs_genie_multisim_poly_reco_per_true[fname_genie_multisim.at(i)].at(m).resize(_n_poly_bins, 0.);
          }

        }

      }

      _event_histo_1d->bs_genie_multisim_eff_onebin_num->SetWeightNames(fname_genie_multisim);
      _event_histo_1d->bs_genie_multisim_eff_onebin_den->SetWeightNames(fname_genie_multisim);

	    _event_histo_1d->bs_genie_multisim_eff_mumom_num->SetWeightNames(fname_genie_multisim);
	    _event_histo_1d->bs_genie_multisim_eff_mumom_den->SetWeightNames(fname_genie_multisim);

      _event_histo_1d->bs_genie_multisim_eff_muangle_num->SetWeightNames(fname_genie_multisim);
      _event_histo_1d->bs_genie_multisim_eff_muangle_den->SetWeightNames(fname_genie_multisim);

      _event_histo_1d->bs_genie_multisim_true_reco_mumom->SetWeightNames(fname_genie_multisim);
      _event_histo_1d->bs_genie_multisim_true_reco_muangle->SetWeightNames(fname_genie_multisim);

      _event_histo->bs_genie_multisim_eff_muangle_mumom_num->SetWeightNames(fname_genie_multisim);
      _event_histo->bs_genie_multisim_eff_muangle_mumom_den->SetWeightNames(fname_genie_multisim);

      _event_histo->bs_genie_multisim_eff_poly_muangle_mumom_num->SetWeightNames(fname_genie_multisim);
      _event_histo->bs_genie_multisim_eff_poly_muangle_mumom_den->SetWeightNames(fname_genie_multisim);

    }

    // Prepare the vector of weights to be used for bootstraps
    std::vector<double> wgts_genie_multisim;
    if (!isdata && _fill_bootstrap_genie) {
      for (size_t i_wgt = 0; i_wgt < fname_genie_multisim.size(); i_wgt++) {
        double wgt = t->evtwgt_genie_multisim_weight.at(0).at(i_wgt);
        if (wgt > 100 || wgt < 0) {
          // LOG_WARNING() << "GENIE multisim weight for universe " << i << " is >100 or <0. Value: " << wgt << std::endl;
          wgt = 1.;
        }
        wgts_genie_multisim.push_back(wgt);
      }
    }





    // ************************
    //
    // Set weight names, prepare bootstraps -- EXTRA SYSTS
    //
    // ************************

    if (i == _initial_entry && !isdata && _fill_bootstrap_extra_syst) {


        fname_extra_syst.clear();
        fname_extra_syst.resize(100/*t->evtwgt_extra_syst_multisim_nweight.at(i_func)*/);

        std::ostringstream oss;
        for (size_t i_wgt = 0; i_wgt < fname_extra_syst.size(); i_wgt++) {
          oss.str("");
          oss << "universe" << i_wgt;
          fname_extra_syst.at(i_wgt) = oss.str();
        }

        LOG_NORMAL() << "EXTRA SYST Number of universes: " << fname_extra_syst.size() << std::endl;

        // Number of events
        for (auto & iter : _event_histo_1d->hmap_trkmom_extra_syst_multisim_bs /*map_bs_trkmom_extra_syst*/) {


          std::string this_name = iter.first;

          // Now emplace the histograms for the variations
          for (size_t i = 0; i < fname_extra_syst.size(); i++) {

            // Single - Muon Momentum
            std::string histo_name = "h_genie_multisim_trkmom_" + this_name + "_" + fname_extra_syst.at(i);
            _event_histo_1d->hmap_trkmom_extra_syst_multisim_bs[this_name][fname_extra_syst.at(i)] = new TH1D(histo_name.c_str(), "; Track length;", n_bins_mumom, bins_mumom);

            // Signle - Muon Angle
            histo_name = "h_extra_syst_trkangle_" + this_name + "_" + fname_extra_syst.at(i); 
            _event_histo_1d->hmap_trkangle_extra_syst_multisim_bs[this_name][fname_extra_syst.at(i)] = new TH1D(histo_name.c_str(), "; Track angle;", n_bins_mucostheta, bins_mucostheta); 

            // Total
            histo_name = "h_extra_syst_onebin_" + this_name + "_" + fname_extra_syst.at(i); 
            _event_histo_1d->hmap_onebin_extra_syst_multisim_bs[this_name][fname_extra_syst.at(i)] = new TH1D(histo_name.c_str(), "; Track angle;", 1, 0, 1);

            // Double Diff
            histo_name = "h_extra_syst_trkmom_trkangle_" + this_name + "_" + fname_extra_syst.at(i); 
            _event_histo->hmap_trktheta_trkmom_extra_syst_multisim_bs[this_name][fname_extra_syst.at(i)] = new TH2D(histo_name.c_str(), "; Track angle;", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);

            histo_name = "h_poly_extra_syst_multisim_trkmom_trkangle_" + this_name + "_" + fname_extra_syst.at(i); 
            _event_histo->hmap_trktheta_trkmom_poly_extra_syst_multisim_bs[this_name][fname_extra_syst.at(i)] = new UBTH2Poly(histo_name.c_str(), "; Track angle;", -1.0, 1.0, 0.0, 2.5);
          }

          for (size_t i = 0; i < fname_extra_syst.size(); i++) {

            std::string histo_name;
            histo_name = "bs_extra_syst_multisim_reco_per_true_" + fname_extra_syst.at(i);
            _event_histo->bs_extra_syst_multisim_reco_per_true[fname_extra_syst.at(i)].resize(n_bins_double_mucostheta, std::vector<TH2D*>(n_bins_double_mumom));
          
            for (int m = 0; m < n_bins_double_mucostheta; m++) {
              for (int n = 0; n < n_bins_double_mumom; n++) { 
                std::stringstream sstm;
                sstm << histo_name << "_" << m << "_" << n;
                _event_histo->bs_extra_syst_multisim_reco_per_true[fname_extra_syst.at(i)][m][n] = new TH2D(sstm.str().c_str(), "reco_per_true", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
              }
            }

            // Poly bins
            histo_name = "bs_extra_syst_multisim_poly_reco_per_true_" + fname_extra_syst.at(i);
            _event_histo->bs_extra_syst_multisim_poly_reco_per_true[fname_extra_syst.at(i)].resize(_n_poly_bins);
          
            for (int m = 0; m < _n_poly_bins; m++) {
              _event_histo->bs_extra_syst_multisim_poly_reco_per_true[fname_extra_syst.at(i)].at(m).resize(_n_poly_bins, 0.);
            }

          }

        }

      _event_histo_1d->bs_extra_syst_multisim_eff_onebin_num->SetWeightNames(fname_extra_syst);
      _event_histo_1d->bs_extra_syst_multisim_eff_onebin_den->SetWeightNames(fname_extra_syst);

      _event_histo_1d->bs_extra_syst_multisim_eff_mumom_num->SetWeightNames(fname_extra_syst);
      _event_histo_1d->bs_extra_syst_multisim_eff_mumom_den->SetWeightNames(fname_extra_syst);

      _event_histo_1d->bs_extra_syst_multisim_eff_muangle_num->SetWeightNames(fname_extra_syst);
      _event_histo_1d->bs_extra_syst_multisim_eff_muangle_den->SetWeightNames(fname_extra_syst);

      _event_histo_1d->bs_extra_syst_true_reco_mumom->SetWeightNames(fname_extra_syst);
      _event_histo_1d->bs_extra_syst_true_reco_muangle->SetWeightNames(fname_extra_syst);

      _event_histo->bs_extra_syst_multisim_eff_muangle_mumom_num->SetWeightNames(fname_extra_syst);
      _event_histo->bs_extra_syst_multisim_eff_muangle_mumom_den->SetWeightNames(fname_extra_syst);

      _event_histo->bs_extra_syst_multisim_eff_poly_muangle_mumom_num->SetWeightNames(fname_extra_syst);
      _event_histo->bs_extra_syst_multisim_eff_poly_muangle_mumom_den->SetWeightNames(fname_extra_syst);
      
    }

    // Prepare the vector of weights to be used for bootstraps
    std::vector<double> wgts_extra_syst;
    wgts_extra_syst.clear();
    wgts_extra_syst.resize(fname_extra_syst.size(), 1.);

    if (!isdata && _fill_bootstrap_extra_syst) {

      bool keep_all = false;
      if (_extra_syst_target_syst == "total") {
        keep_all = true;
      }

      // Loop over all the flux reweighting function names and find the one we want unlsee "total" was requested
      for (size_t i_func = 0; i_func < t->evtwgt_extra_syst_multisim_funcname.size(); i_func++) {

        std::string func_name = t->evtwgt_extra_syst_multisim_funcname.at(i_func);

        size_t found = std::string::npos;

        if (keep_all) {
          found = 0;
        } else {
          found = func_name.find(_extra_syst_target_syst);
        }

        if (found == std::string::npos) {
          continue;
        }

        if (i == _initial_entry) LOG_NORMAL() << "Filling bootstraps for extra systematic " << func_name << std::endl;

        // Always exclude the bnbcorrection weight, this is not a systematic, though should be applied to every event
        if (func_name == "bnbcorrection_FluxHist") {
          continue;
        }

        for (size_t i_wgt = 0; i_wgt < fname_extra_syst.size(); i_wgt++) {

          double wgt = t->evtwgt_extra_syst_multisim_weight.at(i_func).at(i_wgt);
          if (wgt > 100 || wgt < 0) {
            // LOG_WARNING() << "EXTRA SYST multisim weight for universe " << i << " is >100 or <0. Value: " << wgt << std::endl;
            wgt = 1.;
          }

          // std::cout << "weight number " << i_wgt << " = " << t->evtwgt_extra_syst_multisim_weight.at(i_func).at(i_wgt) << std::endl;

          wgts_extra_syst.at(i_wgt) *= wgt;
        }
      }
    }

/*
*        0 *        0 *                                                                               bnbcorrection_FluxHist *
*        0 *        1 *                                                                     model_q0q3_ccmec_HistogramWeight *
*        0 *        2 *                                                                      model_q0q3_ccqe_HistogramWeight *
*/




    // ************************
    //
    // Set weight names, prepare bootstraps -- FLUX MULTISIM
    //
    // ************************

    if (i == _initial_entry && !isdata && _fill_bootstrap_flux) {

      fname_flux_multisim.clear();
      fname_flux_multisim.resize(t->evtwgt_flux_multisim_nweight.at(1));

      std::ostringstream oss;
      for (size_t i_wgt = 0; i_wgt < fname_flux_multisim.size(); i_wgt++) {
       oss.str("");
        oss << "universe" << i_wgt;
        fname_flux_multisim.at(i_wgt) = oss.str();
      }

      LOG_NORMAL()  << "FLUX Multisim Number of universes: " << fname_flux_multisim.size() << std::endl;

      // Number of events
      for (auto iter : _event_histo_1d->hmap_trkmom_flux_multisim_bs) {

        std::string this_name = iter.first;
        std::map<std::string, TH1D*> bs_map = iter.second;

        // Now emplace the histograms for the variations
        for (size_t i = 0; i < fname_flux_multisim.size(); i++) {

          // Single diff - Momentum
          std::string histo_name = "h_flux_multisim_trkmom_" + this_name + "_" + fname_flux_multisim.at(i);
          _event_histo_1d->hmap_trkmom_flux_multisim_bs[this_name][fname_flux_multisim.at(i)] = new TH1D(histo_name.c_str(), "; Track length;", n_bins_mumom, bins_mumom); 

          // Single diff - Angle
          histo_name = "h_flux_multisim_trkangle_" + this_name + "_" + fname_flux_multisim.at(i);
          _event_histo_1d->hmap_trkangle_flux_multisim_bs[this_name][fname_flux_multisim.at(i)] = new TH1D(histo_name.c_str(), "; Track angle;", n_bins_mucostheta, bins_mucostheta); 

          // Total
          histo_name = "h_flux_multisim_onebin_" + this_name + "_" + fname_flux_multisim.at(i);
          _event_histo_1d->hmap_onebin_flux_multisim_bs[this_name][fname_flux_multisim.at(i)] = new TH1D(histo_name.c_str(), "; Track angle;", 1, 0, 1);

          // Double Diff
          histo_name = "h_flux_multisim_trkmom_trkangle_" + this_name + "_" + fname_flux_multisim.at(i); 
          _event_histo->hmap_trktheta_trkmom_flux_multisim_bs[this_name][fname_flux_multisim.at(i)] = new TH2D(histo_name.c_str(), "; Track angle;", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
 
          // Double Diff PolyBin
          histo_name = "h_poly_flux_multisim_trkmom_trkangle_" + this_name + "_" + fname_flux_multisim.at(i); 
          _event_histo->hmap_trktheta_trkmom_poly_flux_multisim_bs[this_name][fname_flux_multisim.at(i)] = new UBTH2Poly(histo_name.c_str(), "; Track angle;", -1.0, 1.0, 0.0, 2.5);

        }

      }

      // Reco per true
      for (size_t i = 0; i < fname_flux_multisim.size(); i++) {

        // Normal Bins
        std::string histo_name;
        histo_name = "bs_flux_multisim_reco_per_true_" + fname_flux_multisim.at(i);
        _event_histo->bs_flux_multisim_reco_per_true[fname_flux_multisim.at(i)].resize(n_bins_double_mucostheta, std::vector<TH2D*>(n_bins_double_mumom));

        for (int m = 0; m < n_bins_double_mucostheta; m++) {
          for (int n = 0; n < n_bins_double_mumom; n++) { 
            std::stringstream sstm;
            sstm << histo_name << "_" << m << "_" << n;
            _event_histo->bs_flux_multisim_reco_per_true[fname_flux_multisim.at(i)][m][n] = new TH2D(sstm.str().c_str(), "reco_per_true", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
          }
        }

        // Poly bins
        histo_name = "bs_flux_multisim_poly_reco_per_true_" + fname_flux_multisim.at(i);
        _event_histo->bs_flux_multisim_poly_reco_per_true[fname_flux_multisim.at(i)].resize(_n_poly_bins);

        for (int m = 0; m < _n_poly_bins; m++) {
          std::stringstream sstm;
          sstm << histo_name << "_" << m;
          _event_histo->bs_flux_multisim_poly_reco_per_true[fname_flux_multisim.at(i)].at(m).resize(_n_poly_bins, 0.);
        }

      }

      // Efficiency
      
      _event_histo_1d->bs_flux_multisim_eff_onebin_num->SetWeightNames(fname_flux_multisim);
      _event_histo_1d->bs_flux_multisim_eff_onebin_den->SetWeightNames(fname_flux_multisim);

      _event_histo_1d->bs_flux_multisim_eff_mumom_num->SetWeightNames(fname_flux_multisim);
      _event_histo_1d->bs_flux_multisim_eff_mumom_den->SetWeightNames(fname_flux_multisim);

      _event_histo_1d->bs_flux_multisim_eff_muangle_num->SetWeightNames(fname_flux_multisim);
      _event_histo_1d->bs_flux_multisim_eff_muangle_den->SetWeightNames(fname_flux_multisim);

      _event_histo_1d->bs_flux_multisim_true_reco_mumom->SetWeightNames(fname_flux_multisim);
      _event_histo_1d->bs_flux_multisim_true_reco_muangle->SetWeightNames(fname_flux_multisim);

      _event_histo->bs_flux_multisim_eff_muangle_mumom_num->SetWeightNames(fname_flux_multisim);
      _event_histo->bs_flux_multisim_eff_muangle_mumom_den->SetWeightNames(fname_flux_multisim);

      _event_histo->bs_flux_multisim_eff_poly_muangle_mumom_num->SetWeightNames(fname_flux_multisim);
      _event_histo->bs_flux_multisim_eff_poly_muangle_mumom_den->SetWeightNames(fname_flux_multisim);
      
    }

    // Prepare the vector of weights to be used for bootstraps
    std::vector<double> wgts_flux_multisim;
    wgts_flux_multisim.clear();
    wgts_flux_multisim.resize(fname_flux_multisim.size(), 1.);

    if (!isdata && _fill_bootstrap_flux) {

      bool keep_all = false;
      if (_target_flux_syst == "total") {
        keep_all = true;
      }

      // Loop over all the flux reweighting function names and find the one we want unless "total" was requested
      for (size_t i_func = 0; i_func < t->evtwgt_flux_multisim_funcname.size(); i_func++) {

        std::string func_name = t->evtwgt_flux_multisim_funcname.at(i_func);

        size_t found = std::string::npos;

        if (keep_all) {
          found = 0;
        } else {
          found = func_name.find(_target_flux_syst);
        }

        if (found == std::string::npos) {
          continue;
        }

        // Always exclude the bnbcorrection weight, this is not a systematic, though should be applied to every event
        if (func_name == "bnbcorrection_FluxHist") {
          continue;
        }

        if (i == _initial_entry) LOG_NORMAL() << "Filling bootstraps for flux systematic " << func_name << std::endl;

        for (size_t i_wgt = 0; i_wgt < fname_flux_multisim.size(); i_wgt++) {

          double wgt = t->evtwgt_flux_multisim_weight.at(i_func).at(i_wgt);
          if (wgt > 100 || wgt < 0) {
            // LOG_WARNING() << "FLUX multisim weight for universe " << i << " is >100 or <0. Value: " << wgt << std::endl;
            wgt = 1.;
          }

          wgts_flux_multisim.at(i_wgt) *= wgt;

          if (_reweigh_kaons
             && (t->evtwgt_flux_multisim_funcname.at(i_func) == "kminus_PrimaryHadronNormalization" 
             || t->evtwgt_flux_multisim_funcname.at(i_func) == "kplus_PrimaryHadronFeynmanScaling" 
             || t->evtwgt_flux_multisim_funcname.at(i_func) == "kzero_PrimaryHadronSanfordWang")) {
            // std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            if (t->evtwgt_flux_multisim_weight.at(i_func).at(i_wgt) != 1) {
              is_from_kaon = true;
            }
          }
        }
      }
    }

    if (is_from_kaon && _reweigh_kaons) {
      event_weight *= _kaon_reweigh_factor;
    }


/*
*        0 *        0 *         bnbcorrection_FluxHist *                              1 *
*        0 *        1 *             expskin_FluxUnisim *                            100 *
*        0 *        2 *         horncurrent_FluxUnisim *                            100 *
*        0 *        3 * kminus_PrimaryHadronNormalizat *                            100 *
*        0 *        4 * kplus_PrimaryHadronFeynmanScal *                            100 *
*        0 *        5 * kzero_PrimaryHadronSanfordWang *                            100 *
*        0 *        6 *      nucleoninexsec_FluxUnisim *                            100 *
*        0 *        7 *       nucleonqexsec_FluxUnisim *                            100 *
*        0 *        8 *      nucleontotxsec_FluxUnisim *                            100 *
*        0 *        9 * piminus_PrimaryHadronSWCentral *                            100 *
*        0 *       10 *         pioninexsec_FluxUnisim *                            100 *
*        0 *       11 *          pionqexsec_FluxUnisim *                            100 *
*        0 *       12 *         piontotxsec_FluxUnisim *                            100 *
*        0 *       13 * piplus_PrimaryHadronSWCentralS *                            100 *
*/


    

    // ************************
    //
    // Set weight names, prepare bootstraps -- MC STAT MULTISIM
    //
    // ************************

    if (i == _initial_entry && !isdata && _fill_bootstrap_mc_stat) {

      if (_mc_stat_n_events > 0) {

        fname_mc_stat_multisim.clear();
        fname_mc_stat_multisim.resize(_mc_stat_n_events);

        std::ostringstream oss;
        for (size_t i_wgt = 0; i_wgt < fname_mc_stat_multisim.size(); i_wgt++) {
          oss.str("");
          oss << "universe" << i_wgt;
          fname_mc_stat_multisim.at(i_wgt) = oss.str();
        }

        LOG_NORMAL()  << "MC STAT Multisim Number of universes: " << fname_mc_stat_multisim.size() << std::endl;

        // Number of events
        for (auto & iter : _event_histo_1d->hmap_trkmom_mc_stat_multisim_bs) {


          std::string this_name = iter.first;

          // Now emplace the histograms for the variations
          for (size_t i = 0; i < fname_mc_stat_multisim.size(); i++) {

            // Single - Muon Momentum
            std::string histo_name = "h_mc_stat_multisim_trkmom_" + this_name + "_" + fname_mc_stat_multisim.at(i);
            _event_histo_1d->hmap_trkmom_mc_stat_multisim_bs[this_name][fname_mc_stat_multisim.at(i)] = new TH1D(histo_name.c_str(), "; Track length;", n_bins_mumom, bins_mumom);

            // Signle - Muon Angle
            histo_name = "h_mc_stat_multisim_trkangle_" + this_name + "_" + fname_mc_stat_multisim.at(i); 
            _event_histo_1d->hmap_trkangle_mc_stat_multisim_bs[this_name][fname_mc_stat_multisim.at(i)] = new TH1D(histo_name.c_str(), "; Track angle;", n_bins_mucostheta, bins_mucostheta); 

            // Total
            histo_name = "h_mc_stat_multisim_onebin_" + this_name + "_" + fname_mc_stat_multisim.at(i); 
            _event_histo_1d->hmap_onebin_mc_stat_multisim_bs[this_name][fname_mc_stat_multisim.at(i)] = new TH1D(histo_name.c_str(), "; Track angle;", 1, 0, 1);

            // Double Diff
            histo_name = "h_mc_stat_multisim_trkmom_trkangle_" + this_name + "_" + fname_mc_stat_multisim.at(i); 
            _event_histo->hmap_trktheta_trkmom_mc_stat_multisim_bs[this_name][fname_mc_stat_multisim.at(i)] = new TH2D(histo_name.c_str(), "; Track angle;", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);

            // Double Diff PolyBin
            histo_name = "h_poly_flux_multisim_trkmom_trkangle_" + this_name + "_" + fname_flux_multisim.at(i); 
            _event_histo->hmap_trktheta_trkmom_poly_mc_stat_multisim_bs[this_name][fname_flux_multisim.at(i)] = new UBTH2Poly(histo_name.c_str(), "; Track angle;", -1.0, 1.0, 0.0, 2.5);
          }

        }

        // Efficiency 

        for (size_t i = 0; i < fname_mc_stat_multisim.size(); i++) {

          // Normal bins
          std::string histo_name;
          histo_name = "bs_mc_stat_multisim_reco_per_true_" + fname_mc_stat_multisim.at(i);
          _event_histo->bs_mc_stat_multisim_reco_per_true[fname_mc_stat_multisim.at(i)].resize(n_bins_double_mucostheta, std::vector<TH2D*>(n_bins_double_mumom));
          
          for (int m = 0; m < n_bins_double_mucostheta; m++) {
            for (int n = 0; n < n_bins_double_mumom; n++) { 
              std::stringstream sstm;
              sstm << histo_name << "_" << m << "_" << n;
              _event_histo->bs_mc_stat_multisim_reco_per_true[fname_mc_stat_multisim.at(i)][m][n] = new TH2D(sstm.str().c_str(), "reco_per_true", n_bins_double_mucostheta, bins_double_mucostheta, n_bins_double_mumom, bins_double_mumom);
            }
          }

          // Poly bins
          histo_name = "bs_mc_stat_multisim_poly_reco_per_true_" + fname_flux_multisim.at(i);
          _event_histo->bs_mc_stat_multisim_poly_reco_per_true[fname_flux_multisim.at(i)].resize(_n_poly_bins);

          for (int m = 0; m < _n_poly_bins; m++) {
            std::stringstream sstm;
            sstm << histo_name << "_" << m;
            _event_histo->bs_mc_stat_multisim_poly_reco_per_true[fname_flux_multisim.at(i)].at(m).resize(_n_poly_bins, 0.);
          }

        }

      }

      _event_histo_1d->bs_mc_stat_multisim_eff_onebin_num->SetWeightNames(fname_mc_stat_multisim);
      _event_histo_1d->bs_mc_stat_multisim_eff_onebin_den->SetWeightNames(fname_mc_stat_multisim);

      _event_histo_1d->bs_mc_stat_multisim_eff_mumom_num->SetWeightNames(fname_mc_stat_multisim);
      _event_histo_1d->bs_mc_stat_multisim_eff_mumom_den->SetWeightNames(fname_mc_stat_multisim);

      _event_histo_1d->bs_mc_stat_multisim_eff_muangle_num->SetWeightNames(fname_mc_stat_multisim);
      _event_histo_1d->bs_mc_stat_multisim_eff_muangle_den->SetWeightNames(fname_mc_stat_multisim);

      _event_histo_1d->bs_mc_stat_multisim_true_reco_mumom->SetWeightNames(fname_mc_stat_multisim);
      _event_histo_1d->bs_mc_stat_multisim_true_reco_muangle->SetWeightNames(fname_mc_stat_multisim);

      _event_histo->bs_mc_stat_multisim_eff_muangle_mumom_num->SetWeightNames(fname_mc_stat_multisim);
      _event_histo->bs_mc_stat_multisim_eff_muangle_mumom_den->SetWeightNames(fname_mc_stat_multisim);

      _event_histo->bs_mc_stat_multisim_eff_poly_muangle_mumom_num->SetWeightNames(fname_mc_stat_multisim);
      _event_histo->bs_mc_stat_multisim_eff_poly_muangle_mumom_den->SetWeightNames(fname_mc_stat_multisim);
      
    }

    // Prepare the vector of weights to be used for bootstraps
    std::vector<double> wgts_mc_stat_multisim;
    wgts_mc_stat_multisim.resize(fname_mc_stat_multisim.size());
    if (!isdata && _fill_bootstrap_mc_stat) {
      for (size_t i = 0; i < fname_mc_stat_multisim.size(); i++) {
        wgts_mc_stat_multisim.at(i) = _random_engine.PoissonD(1);
      }
    }
    //********************************************



    if (i == _initial_entry) {
      _event_histo->AddPolyBins();
      LOG_NORMAL() << "Polybins set." << std::endl;
    }


    // ************************
    //
    // Preliminary - Truth
    //
    // ************************
    
    // This variable will store if this is a signal event or not
    bool isSignal = false;

    if (t->nupdg == 14 && t->ccnc == 0 && t->fv == 1 /*&& (t->tvtx_z[0] < 675 || t->tvtx_z[0] > 775)*/){

      nsignal += event_weight;
      isSignal = true;

      if (t->mode == 0) nsignal_qe += event_weight;
      if (t->mode == 1) nsignal_res += event_weight;
      if (t->mode == 2) nsignal_dis += event_weight;
      if (t->mode == 3) nsignal_coh += event_weight;
      if (t->mode == 10) nsignal_mec += event_weight;
      
    }
    
    
    // Check if it's a nue event
    bool isNueCCFV = false;
    if (t->nupdg == 12 && t->ccnc == 0 && t->fv == 1) {
      isNueCCFV = true;
      nue_cc_fv+=t->bnb_weight;
    }
    bool isNue = false;
    if (t->nupdg == 12) {
      isNue = true;
    }

    
    //
    // Construct the denominator for the efficiency plots
    //
    // for (int j = 0; j < t->truth_nu_e.size(); j++) {
    //   if (t->truth_nupdg.at(j) == 14 && t->truth_ccnc.at(j) == 0 && t->truth_fv.at(j) == 1) {
    //     nsignal_all += event_weight;
    //   }
    // }
    if (isSignal) {
      
      _event_histo_1d->h_eff_onebin_den->Fill(0.5, event_weight);
      h_eff_den->Fill(t->nu_e, event_weight);
      _event_histo_1d->h_eff_mumom_den->Fill(t->true_muon_mom, event_weight);
      if (!isdata && _fill_bootstrap_genie) bs_genie_pm1_eff_mumom_den.Fill(t->true_muon_mom, event_weight, wgts_genie_pm1);
      
      if (!isdata && _fill_bootstrap_genie) _event_histo_1d->bs_genie_multisim_eff_onebin_den->Fill(0.5, event_weight, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) _event_histo_1d->bs_genie_multisim_eff_mumom_den->Fill(t->true_muon_mom, event_weight, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) _event_histo_1d->bs_genie_multisim_eff_muangle_den->Fill(t->lep_costheta, event_weight, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) _event_histo->bs_genie_multisim_eff_muangle_mumom_den->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) _event_histo->bs_genie_multisim_eff_poly_muangle_mumom_den->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_genie_multisim);

      if (!isdata && _fill_bootstrap_extra_syst) _event_histo_1d->bs_extra_syst_multisim_eff_onebin_den->Fill(0.5, event_weight, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) _event_histo_1d->bs_extra_syst_multisim_eff_mumom_den->Fill(t->true_muon_mom, event_weight, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) _event_histo_1d->bs_extra_syst_multisim_eff_muangle_den->Fill(t->lep_costheta, event_weight, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) _event_histo->bs_extra_syst_multisim_eff_muangle_mumom_den->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) _event_histo->bs_extra_syst_multisim_eff_poly_muangle_mumom_den->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_extra_syst);

      if (!isdata && _fill_bootstrap_flux) _event_histo_1d->bs_flux_multisim_eff_onebin_den->Fill(0.5, event_weight, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) _event_histo_1d->bs_flux_multisim_eff_mumom_den->Fill(t->true_muon_mom, event_weight, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) _event_histo_1d->bs_flux_multisim_eff_muangle_den->Fill(t->lep_costheta, event_weight, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) _event_histo->bs_flux_multisim_eff_muangle_mumom_den->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) _event_histo->bs_flux_multisim_eff_poly_muangle_mumom_den->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_flux_multisim);

      if (!isdata && _fill_bootstrap_mc_stat) _event_histo_1d->bs_mc_stat_multisim_eff_onebin_den->Fill(0.5, event_weight, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) _event_histo_1d->bs_mc_stat_multisim_eff_mumom_den->Fill(t->true_muon_mom, event_weight, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) _event_histo_1d->bs_mc_stat_multisim_eff_muangle_den->Fill(t->lep_costheta, event_weight, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) _event_histo->bs_mc_stat_multisim_eff_muangle_mumom_den->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) _event_histo->bs_mc_stat_multisim_eff_poly_muangle_mumom_den->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_mc_stat_multisim);


      _event_histo_1d->h_eff_muangle_den->Fill(t->lep_costheta, event_weight);
      _event_histo->h_eff_muangle_mumom_den->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
      _event_histo->h_eff_muangle_mumom_poly_den->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
      h_eff_muphi_den->Fill(t->lep_phi, event_weight);
      h_eff_mult_den->Fill(t->genie_mult, event_weight);
      h_eff_mult_ch_den->Fill(t->genie_mult_ch, event_weight);

      if (t->mode == 0) h_eff_qe_den->Fill(t->nu_e, event_weight);
      if (t->mode == 1) h_eff_res_den->Fill(t->nu_e, event_weight);
      if (t->mode == 2) h_eff_dis_den->Fill(t->nu_e, event_weight);
      if (t->mode == 3) h_eff_coh_den->Fill(t->nu_e, event_weight);
      if (t->mode == 10) h_eff_mec_den->Fill(t->nu_e, event_weight);

      h_truth_xsec_mumom->Fill(t->true_muon_mom, event_weight);
      h_truth_xsec_muangle->Fill(t->lep_costheta, event_weight);

      h_mueff_den->Fill(t->true_muon_mom, event_weight);
      h_mueff_angle_den->Fill(t->lep_costheta, event_weight);

      h_true_nu_eng_beforesel->Fill(t->nu_e, event_weight);
      
      if (t->muon_is_reco){
        h_mumom_nue->Fill(t->nu_e, t->true_muon_mom, event_weight);
        nSignalWMuonReco++;
        h_mueff_num->Fill(t->true_muon_mom, event_weight);
        h_mueff_angle_num->Fill(t->lep_costheta, event_weight);
        for (auto origin : t->slc_origin){
          if (origin == 0 || origin == 2) {
            h_mueff_2_num->Fill(t->true_muon_mom, event_weight);
            break;
          }
        }
        if (t->vtx_resolution > -1 && t->vtx_resolution < 10) nSignalMuonRecoVtxOk++;
        
        h_muon_track_eff->Fill(t->muon_reco_eff, event_weight);
        h_muon_track_pur->Fill(t->muon_reco_pur, event_weight);
        
        h_mu_eff_mom->Fill(t->true_muon_mom, t->muon_reco_eff, event_weight);
        h_mu_pur_mom->Fill(t->true_muon_mom, t->muon_reco_pur, event_weight);
      }
      else{
        //std::cout << "This is a signal event but the muon was not reconstructed. Event: " << event << std::endl;
      }

      double m_mu = 0.105658; // GeV
      double mu_px = t->true_muon_mom * std::sin(std::acos(t->lep_costheta)) * std::cos(t->lep_phi);
      double mu_py = t->true_muon_mom * std::sin(std::acos(t->lep_costheta)) * std::sin(t->lep_phi);
      double mu_pz = t->true_muon_mom * t->lep_costheta;
      double q0 = t->nu_e - std::sqrt(t->true_muon_mom * t->true_muon_mom + m_mu * m_mu);
      double q3 = std::sqrt(mu_px * mu_px + mu_py * mu_py + (t->nu_e - mu_pz) * (t->nu_e - mu_pz));


      // Also save the mc truth histogram per interaction type
      hmap_mctruth_nuenergy_gen["total"]->Fill(t->nu_e, event_weight);
      hmap_mctruth_mumom_gen["total"]->Fill(t->true_muon_mom, event_weight);
      hmap_mctruth_mucostheta_gen["total"]->Fill(t->lep_costheta, event_weight);
      hmap_mctruth_muphi_gen["total"]->Fill(t->lep_phi, event_weight);
      hmap_mctruth_chargedmult_gen["total"]->Fill(t->genie_mult_ch, event_weight);
      hmap_mctruth_mucostheta_mumom_gen["total"]->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
      hmap_mctruth_q0_q3_gen["total"]->Fill(q3, q0, event_weight);
      if (t->mode == 0) {
        hmap_mctruth_nuenergy_gen["qe"]->Fill(t->nu_e, event_weight);
        hmap_mctruth_mumom_gen["qe"]->Fill(t->true_muon_mom, event_weight);
        hmap_mctruth_mucostheta_gen["qe"]->Fill(t->lep_costheta, event_weight);
        hmap_mctruth_muphi_gen["qe"]->Fill(t->lep_phi, event_weight);
        hmap_mctruth_chargedmult_gen["qe"]->Fill(t->genie_mult_ch, event_weight);
        hmap_mctruth_mucostheta_mumom_gen["qe"]->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
        hmap_mctruth_q0_q3_gen["qe"]->Fill(q3, q0, event_weight);
      }
      if (t->mode == 1) {
        hmap_mctruth_nuenergy_gen["res"]->Fill(t->nu_e, event_weight);
        hmap_mctruth_mumom_gen["res"]->Fill(t->true_muon_mom, event_weight);
        hmap_mctruth_mucostheta_gen["res"]->Fill(t->lep_costheta, event_weight);
        hmap_mctruth_muphi_gen["res"]->Fill(t->lep_phi, event_weight);
        hmap_mctruth_chargedmult_gen["res"]->Fill(t->genie_mult_ch, event_weight);
        hmap_mctruth_mucostheta_mumom_gen["res"]->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
        hmap_mctruth_q0_q3_gen["res"]->Fill(q3, q0, event_weight);
      }
      if (t->mode == 2) {
        hmap_mctruth_nuenergy_gen["dis"]->Fill(t->nu_e, event_weight);
        hmap_mctruth_mumom_gen["dis"]->Fill(t->true_muon_mom, event_weight);
        hmap_mctruth_mucostheta_gen["dis"]->Fill(t->lep_costheta, event_weight);
        hmap_mctruth_muphi_gen["dis"]->Fill(t->lep_phi, event_weight);
        hmap_mctruth_chargedmult_gen["dis"]->Fill(t->genie_mult_ch, event_weight);
        hmap_mctruth_mucostheta_mumom_gen["dis"]->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
        hmap_mctruth_q0_q3_gen["dis"]->Fill(q3, q0, event_weight);
      }
      if (t->mode == 3) {
        hmap_mctruth_nuenergy_gen["coh"]->Fill(t->nu_e, event_weight);
        hmap_mctruth_mumom_gen["coh"]->Fill(t->true_muon_mom, event_weight);
        hmap_mctruth_mucostheta_gen["coh"]->Fill(t->lep_costheta, event_weight);
        hmap_mctruth_muphi_gen["coh"]->Fill(t->lep_phi, event_weight);
        hmap_mctruth_chargedmult_gen["coh"]->Fill(t->genie_mult_ch, event_weight);
        hmap_mctruth_mucostheta_mumom_gen["coh"]->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
        hmap_mctruth_q0_q3_gen["coh"]->Fill(q3, q0, event_weight);
      }
      if (t->mode == 10) {
        hmap_mctruth_nuenergy_gen["mec"]->Fill(t->nu_e, event_weight);
        hmap_mctruth_mumom_gen["mec"]->Fill(t->true_muon_mom, event_weight);
        hmap_mctruth_mucostheta_gen["mec"]->Fill(t->lep_costheta, event_weight);
        hmap_mctruth_muphi_gen["mec"]->Fill(t->lep_phi, event_weight);
        hmap_mctruth_chargedmult_gen["mec"]->Fill(t->genie_mult_ch, event_weight);
        hmap_mctruth_mucostheta_mumom_gen["mec"]->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
        hmap_mctruth_q0_q3_gen["mec"]->Fill(q3, q0, event_weight);
      }
    } // if is signal

    if(t->nupdg == 14 && t->ccnc == 0){
      nNumuCC++;
    }

    
    

      
    
    // VTX before selection
    if(t->slc_nuvtx_x.size()>0) {
      hmap_vtxx_b["total"]->Fill(t->slc_nuvtx_x.at(0), event_weight);
      hmap_vtxy_b["total"]->Fill(t->slc_nuvtx_y.at(0), event_weight);
      hmap_vtxz_b["total"]->Fill(t->slc_nuvtx_z.at(0), event_weight);
      h_vtx_xz->Fill(t->slc_nuvtx_x.at(0), t->slc_nuvtx_z.at(0), event_weight);
      h_vtx_xy->Fill(t->slc_nuvtx_x.at(0), t->slc_nuvtx_y.at(0), event_weight);
    }
    
    // Number of TPCObjects
    hmap_ntpcobj["total"]->Fill(t->nslices, event_weight);
    if (isSignal) hmap_ntpcobj["signal"]->Fill(t->nslices, event_weight);
    else hmap_ntpcobj["background"]->Fill(t->nslices, event_weight);
    
    // Vertex Resolution plot
    if (isSignal) h_vtx_resolution->Fill(t->vtx_resolution, event_weight);
    
    
    for (int slc = 0; slc < t->nslices; slc ++) {
      
      if (t->slc_origin.at(slc) == 0 || t->slc_origin.at(slc) == 2) {
        h_slice_npfp->Fill(t->slc_npfp.at(slc), event_weight);
        h_slice_ntrack->Fill(t->slc_ntrack.at(slc), event_weight);
      } else {
        h_slice_npfp_others->Fill(t->slc_npfp.at(slc), event_weight);
        h_slice_ntrack_others->Fill(t->slc_ntrack.at(slc), event_weight);
      }
      

      
      if (t->slc_origin.at(slc) == 0) h_slice_origin->Fill(2., event_weight);
      if (t->slc_origin.at(slc) == 1) h_slice_origin->Fill(0., event_weight);
      if (t->slc_origin.at(slc) == 2) h_slice_origin->Fill(1., event_weight);
      
      
      if ((t->slc_origin.at(slc) == 0 || t->slc_origin.at(slc) == 2) && t->fv == 1) {
        n_slc_nu_origin ++;
        
      }
    }
    
    
    
    
    
    
    

    
    
    
    // ************************
    //
    //  Selection
    //
    // ***********************


    if (isSignal) selected_signal_events_percut["initial"]+=event_weight;
    selected_events_percut["initial"]+=event_weight;
    
    
    //
    // Optical
    //

    if (t->nbeamfls == 0) continue;
    

    int flashInBeamSpill = -1;
    double old_pe = -1;
    
    for (int fls = 0; fls < t->nbeamfls; fls ++){

      h_flsTime->Fill(t->beamfls_time.at(fls) - _flashShift, event_weight);
      if(t->beamfls_pe.at(fls) > _pe_cut) {
        h_flsTime_wcut->Fill(t->beamfls_time.at(fls) - _flashShift, event_weight);
      }
      if (t->beamfls_time.at(fls) > _beamSpillStarts && t->beamfls_time.at(fls) < _beamSpillEnds) {
        
        //flashInBeamSpill = fls;
        if (t->beamfls_pe.at(fls) >= _pe_cut) {
          if (t->beamfls_pe.at(fls) > old_pe) {
            flashInBeamSpill = fls;
            old_pe = t->beamfls_pe.at(fls);
          }
          nEvtsWFlashInBeamSpill++;
        }
      }
    }
    
    
    if (flashInBeamSpill == -1) continue;
    h_flsPe_wcut->Fill(t->beamfls_pe.at(flashInBeamSpill), event_weight);
    
    h_flsTime_flsPe_wcut->Fill(t->beamfls_time.at(flashInBeamSpill) - _flashShift, t->beamfls_pe.at(flashInBeamSpill), event_weight);

    h_flsTime_wcut_2->Fill(t->beamfls_time.at(flashInBeamSpill) - _flashShift, event_weight);
    

    
    
    if (isSignal) h_true_nu_eng_afterflash->Fill(t->nu_e, event_weight);

    if (isSignal) selected_signal_events_percut["beamflash"]+=event_weight;
    selected_events_percut["beamflash"]+=event_weight;
    
    
    if (t->nslices > 0) h_trklen_first->Fill(t->slc_longesttrack_length.at(0));
    if (t->nslices > 1) h_trklen_second->Fill(t->slc_longesttrack_length.at(1));

    //
    // Loop over TPC Events - Preliminary plots with only the flash cut applied
    //

    for (int slc = 0; slc < t->nslices; slc ++) {
      
      bool nu_origin = (t->slc_origin.at(slc) == 0 || t->slc_origin.at(slc) == 2);
      
      // PMTs
      if (flashInBeamSpill > -1 && t->slc_flsmatch_score.at(slc) > -1
          && t->slc_flsmatch_qllx.at(slc)!= -9999 && t->slc_flsmatch_tpcx.at(slc)!=-9999) {
        hmap_xdiff_b["total"]->Fill(t->slc_flsmatch_qllx.at(slc) - t->slc_flsmatch_tpcx.at(slc), event_weight);
        hmap_zdiff_b["total"]->Fill(t->slc_flsmatch_hypoz.at(slc) - t->beamfls_z.at(flashInBeamSpill), event_weight);
        if ( isSignal && nu_origin) {
          hmap_xdiff_b["signal"]->Fill(t->slc_flsmatch_qllx.at(slc) - t->slc_flsmatch_tpcx.at(slc), event_weight);
          hmap_zdiff_b["signal"]->Fill(t->slc_flsmatch_hypoz.at(slc) - t->beamfls_z.at(flashInBeamSpill), event_weight);
        } else {
          hmap_xdiff_b["background"]->Fill(t->slc_flsmatch_qllx.at(slc) - t->slc_flsmatch_tpcx.at(slc), event_weight);
          hmap_zdiff_b["background"]->Fill(t->slc_flsmatch_hypoz.at(slc) - t->beamfls_z.at(flashInBeamSpill), event_weight);
        }
      }
      
      //   nu
      if ( isSignal && nu_origin && flashInBeamSpill > -1 && t->slc_flsmatch_score.at(slc) > -1){
        for (int pmt = 0; pmt < 32; pmt++) {
          if ((t->slc_flshypo_spec.at(slc))[pmt] < 5 || (t->beamfls_spec.at(flashInBeamSpill))[pmt] < 5) continue;
          double mean = ((t->slc_flshypo_spec.at(slc))[pmt] + (t->beamfls_spec.at(flashInBeamSpill))[pmt]) / 2.;
          h_frac_diff->Fill(pmt, ( (t->slc_flshypo_spec.at(slc))[pmt] - (t->beamfls_spec.at(flashInBeamSpill))[pmt] ) / (mean) , event_weight);
        }
        if (t->slc_flsmatch_qllx.at(slc)!= -9999 && t->slc_flsmatch_tpcx.at(slc)!=-9999){
          h_xdiff->Fill(t->slc_flsmatch_qllx.at(slc) - t->slc_flsmatch_tpcx.at(slc), event_weight);
          h_zdiff->Fill(t->slc_flsmatch_hypoz.at(slc) - t->beamfls_z.at(flashInBeamSpill), event_weight);
        }
      }
      //   others
      if (t->slc_origin.at(slc) == 1 && flashInBeamSpill > -1 && t->slc_flsmatch_score.at(slc) > -1){
        for (int pmt = 0; pmt < 32; pmt++) {
          if ((t->slc_flshypo_spec.at(slc))[pmt] < 5 || (t->beamfls_spec.at(flashInBeamSpill))[pmt] < 5) continue;
          double mean = ((t->slc_flshypo_spec.at(slc))[pmt] + (t->beamfls_spec.at(flashInBeamSpill))[pmt]) / 2.;
          h_frac_diff_others->Fill(pmt, ( (t->slc_flshypo_spec.at(slc))[pmt] - (t->beamfls_spec.at(flashInBeamSpill))[pmt] ) / (mean) , event_weight);
        }
        if (t->slc_flsmatch_qllx.at(slc)!= -9999 && t->slc_flsmatch_tpcx.at(slc)!=-9999){
          h_xdiff_others->Fill(t->slc_flsmatch_qllx.at(slc) - t->slc_flsmatch_tpcx.at(slc), event_weight);
          h_zdiff_others->Fill(t->slc_flsmatch_hypoz.at(slc) - t->beamfls_z.at(flashInBeamSpill), event_weight);
        }
      }
      //  spec
      if (/*t->event==900 && t->run==5326*/t->event==-1 /*150801 4990051 3099969*/) {
        if (flashInBeamSpill > -1 && t->slc_flsmatch_score.at(slc) > -1){
          int instance = 0;
          std::cout << "tpcx " << t->slc_flsmatch_tpcx.at(instance) << std::endl;
          std::cout << "qllx " << t->slc_flsmatch_qllx.at(instance) << std::endl;
          std::cout << "SCORE IS " << t->slc_flsmatch_score.at(instance) << std::endl;
          for (int pmt = 0; pmt < 32; pmt++) {
            hypo_spec_x[pmt] = pmt;
            hypo_spec_y[pmt] = (t->slc_flshypo_spec.at(instance))[pmt]; ;//(t->slc_flshypo_spec.at(3))[pmt];
            meas_spec_x[pmt] = pmt;
            meas_spec_y[pmt] = (t->beamfls_spec.at(flashInBeamSpill))[pmt];
            numc_spec_x[pmt] = pmt;
            //numc_spec_y[pmt] = t->numc_flash_spec.at(pmt);
          }
        }
      }
      
      // CheckVertex
      hmap_vtxcheck_angle["total"]->Fill(t->slc_vtxcheck_angle.at(slc), event_weight);
      if (isSignal && nu_origin) {
        h_vtxcheck_angle_good->Fill(t->slc_vtxcheck_angle.at(slc), event_weight);
        hmap_vtxcheck_angle["signal"]->Fill(t->slc_vtxcheck_angle.at(slc), event_weight);
      } else {
        h_vtxcheck_angle_bad->Fill(t->slc_vtxcheck_angle.at(slc), event_weight);
        hmap_vtxcheck_angle["background"]->Fill(t->slc_vtxcheck_angle.at(slc), event_weight);
      }

      // Residuals std, mean
      hmap_residuals_std["total"]->Fill(t->slc_muoncandidate_residuals_std.at(slc), event_weight);
      hmap_residuals_mean["total"]->Fill(t->slc_muoncandidate_residuals_mean.at(slc), event_weight);
      hmap_perc_used_hits["total"]->Fill(t->slc_muoncandidate_perc_used_hits_in_cluster.at(slc), event_weight);
      if(t->slc_muoncandidate_contained.at(slc)) {
        hmap_mom_mcs_length["total"]->Fill(t->slc_muoncandidate_mom_mcs.at(slc) - t->slc_muoncandidate_mom_range.at(slc), event_weight);
      }
      if (isSignal && nu_origin) {
        hmap_residuals_std["signal"]->Fill(t->slc_muoncandidate_residuals_std.at(slc), event_weight);
        hmap_residuals_mean["signal"]->Fill(t->slc_muoncandidate_residuals_mean.at(slc), event_weight);
        hmap_perc_used_hits["signal"]->Fill(t->slc_muoncandidate_perc_used_hits_in_cluster.at(slc), event_weight);
        if(t->slc_muoncandidate_contained.at(slc)) {
          hmap_mom_mcs_length["signal"]->Fill(t->slc_muoncandidate_mom_mcs.at(slc) - t->slc_muoncandidate_mom_range.at(slc), event_weight);
        }
      } else {
        hmap_residuals_std["background"]->Fill(t->slc_muoncandidate_residuals_std.at(slc), event_weight);
        hmap_residuals_mean["background"]->Fill(t->slc_muoncandidate_residuals_mean.at(slc), event_weight);
        hmap_perc_used_hits["background"]->Fill(t->slc_muoncandidate_perc_used_hits_in_cluster.at(slc), event_weight);
        if(t->slc_muoncandidate_contained.at(slc))  {
          hmap_mom_mcs_length["background"]->Fill(t->slc_muoncandidate_mom_mcs.at(slc) - t->slc_muoncandidate_mom_range.at(slc), event_weight);
        }
      }
      
      // Track chi2
      h_chi2->Fill(t->slc_kalman_chi2.at(slc)/(double)t->slc_kalman_ndof.at(slc), event_weight);
      
      // Number of TPCObjects per event
      h_nslices->Fill(t->nslices, event_weight);
      
      
      
      
    } // slice loop
    

      
    int n_slc_flsmatch = 0;
    
    //
    // Find slice with maximum score
    //

    double score_max = -1;
    int scl_ll_max = -1;
    std::vector<double> temp_score; temp_score.clear();
    for (int slc = 0; slc < t->nslices; slc ++){

      temp_score.emplace_back(t->slc_flsmatch_score.at(slc));
      
      if (t->slc_flsmatch_score.at(slc) > 0.00000001) {
        n_slc_flsmatch++;
      }
      
      if (t->slc_flsmatch_score.at(slc) > score_max){
        scl_ll_max = slc;
        score_max = t->slc_flsmatch_score.at(slc);
      }
    }
    
    h_n_slc_flsmatch->Fill(n_slc_flsmatch, event_weight);

    std::sort(temp_score.begin(), temp_score.end(), std::greater<double>());


    //*******************************************
    //*******************************************
    //*******************************************
    // if (!t->is_selected) continue;
    //*******************************************
    //*******************************************
    //*******************************************

    // In no flash-matched object, continue
    if (scl_ll_max == -1) continue;

    
    bool nu_origin = (t->slc_origin.at(scl_ll_max) == 0 || t->slc_origin.at(scl_ll_max) == 2);
    
    double dqdx_calib = t->slc_muoncandidate_dqdx_trunc.at(scl_ll_max) * _gainCalib;

    
    
    
    
    
    h_flsTime_wcut_3->Fill(t->beamfls_time.at(flashInBeamSpill) - _flashShift, event_weight);
    
    if (isSignal && nu_origin) nSignalFlashMatched ++;

    // A score < 3e-4 or inf means no flash-matched object, continue
    if (score_max <= 3e-4) continue;
    if (std::isinf(score_max)) continue;


    if (isSignal && nu_origin) selected_signal_events_percut["flash_match"]+=event_weight;
    selected_events_percut["flash_match"]+=event_weight;
    
    
    h_flsTime_wcut_4->Fill(t->beamfls_time.at(flashInBeamSpill) - _flashShift, event_weight);
    h_deltax->Fill(t->slc_flsmatch_qllx.at(scl_ll_max) - t->slc_flsmatch_tpcx.at(scl_ll_max), event_weight);
    h_deltax_2d->Fill(t->slc_flsmatch_qllx.at(scl_ll_max), t->slc_flsmatch_tpcx.at(scl_ll_max), event_weight);
    h_deltaz_4->Fill(t->slc_flsmatch_hypoz.at(scl_ll_max) - t->beamfls_z.at(flashInBeamSpill), event_weight);
    

    // If it doens't pass the flash-match deltaX cut, continue
    if(t->slc_flsmatch_qllx.at(scl_ll_max) - t->slc_flsmatch_tpcx.at(scl_ll_max) > 50) continue;
    
    h_flsTime_wcut_5->Fill(t->beamfls_time.at(flashInBeamSpill) - _flashShift, event_weight);

    if(t->slc_flsmatch_qllx.at(scl_ll_max) - t->slc_flsmatch_tpcx.at(scl_ll_max) < -100) continue;

    if (isSignal && nu_origin) selected_signal_events_percut["flash_match_deltax"]+=event_weight;
    selected_events_percut["flash_match_deltax"]+=event_weight;
    
    h_flsTime_wcut_6->Fill(t->beamfls_time.at(flashInBeamSpill) - _flashShift, event_weight);
    h_deltaz_6->Fill(t->slc_flsmatch_hypoz.at(scl_ll_max) - t->beamfls_z.at(flashInBeamSpill), event_weight);
    
    // If it doens't pass the flash-match deltaZ cut, continue
    if(t->slc_flsmatch_hypoz.at(scl_ll_max) - t->beamfls_z.at(flashInBeamSpill) > 75) continue;
    
    h_flsTime_wcut_7->Fill(t->beamfls_time.at(flashInBeamSpill) - _flashShift, event_weight);

    if(t->slc_flsmatch_hypoz.at(scl_ll_max) - t->beamfls_z.at(flashInBeamSpill) < -75) continue;

    if (isSignal && nu_origin) selected_signal_events_percut["flash_match_deltaz"]+=event_weight;
    selected_events_percut["flash_match_deltaz"]+=event_weight;
    
    h_flsTime_wcut_8->Fill(t->beamfls_time.at(flashInBeamSpill) - _flashShift, event_weight);

    
      

    // if(t->slc_vtxcheck_angle.at(scl_ll_max) > 2.9) continue;
    
    //if(t->slc_vtxcheck_angle.at(scl_ll_max) < 0.05 && t->slc_vtxcheck_angle.at(scl_ll_max) !=-9999 ) continue;
    
    // If zero tracks in this tpcobject, continue
    if(t->slc_ntrack.at(scl_ll_max) == 0) continue;

    // Cut on residuala ans fraction of used hits in cluster
    if (t->slc_muoncandidate_residuals_std.at(scl_ll_max) > 2.5) continue;
    // if (std::abs(t->slc_muoncandidate_residuals_mean.at(scl_ll_max)) > 0.7) continue;
    if (t->slc_muoncandidate_perc_used_hits_in_cluster.at(scl_ll_max) < 0.7) continue;
    
    //if(!t->slc_passed_min_track_quality.at(scl_ll_max)) continue;
    
    //if(!t->slc_passed_min_vertex_quality.at(scl_ll_max)) continue;

    if (isSignal && nu_origin) selected_signal_events_percut["quality"]+=event_weight;
    selected_events_percut["quality"]+=event_weight;
    
    //if (!t->slc_muoncandidate_contained.at(scl_ll_max)) continue;
    
    if(t->slc_muoncandidate_contained.at(scl_ll_max) && (t->slc_muoncandidate_mom_mcs.at(scl_ll_max) - t->slc_muoncandidate_mom_range.at(scl_ll_max) > 0.2)) continue;
    
    if (isSignal && nu_origin) selected_signal_events_percut["mcs_length_quality"]+=event_weight;
    selected_events_percut["mcs_length_quality"]+=event_weight;


    // DqDx cut
    std::vector<double> svm_x = {86300, 86050, 85850, 85600, 85400, 85150, 84950, 84700, 84500, 84300, 84100, 83850, 83650, 83450, 83250, 83050, 82850, 82650, 82450, 82250, 82050, 81900, 81700, 81500, 81300, 81150, 80950, 80750, 80600, 80400, 80250, 80050, 79900, 79750, 79550, 79400, 79250, 79050, 78900, 78750, 78600, 78400, 78250, 78100, 77950, 77800, 77650, 77500, 77350, 77200, 77050, 76900, 76750, 76650, 76500, 76350, 76200, 76050, 75950, 75800, 75650, 75550, 75400, 75300, 75150, 75000, 74900, 74750, 74650, 74500, 74400, 74250, 74150, 74050, 73900, 73800, 73700, 73550, 73450, 73350, 73250, 73100, 73000, 72900, 72800, 72700, 72550, 72450, 72350, 72250, 72150, 72050, 71950, 71850, 71750, 71650, 71550, 71450, 71350, 71250, 71150, 71100, 71000, 70900, 70800, 70700, 70600, 70550, 70450, 70350, 70250, 70200, 70100, 70000, 69950, 69850, 69750, 69700, 69600, 69550, 69450, 69350, 69300, 69200, 69150, 69050, 69000, 68900, 68850, 68750, 68700, 68600, 68550, 68500, 68400, 68350, 68250, 68200, 68150, 68050, 68000, 67950, 67850, 67800, 67750, 67700, 67600, 67550, 67500, 67450, 67350, 67300, 67250, 67200, 67150, 67100, 67000, 66950, 66900, 66850, 66800, 66750, 66700, 66650, 66600, 66550, 66500, 66450, 66400, 66350, 66300, 66250, 66200, 66150, 66100, 66050, 66000, 65950, 65900, 65850, 65800, 65750, 65750, 65700, 65650, 65600, 65550, 65500, 65450, 65450, 65400, 65350, 65300, 65250, 65250, 65200, 65150, 65100, 65100, 65050, 65000, 65000, 64950, 64900, 64850, 64850, 64800, 64750, 64750, 64700, 64700, 64650, 64600, 64600, 64550, 64500, 64500, 64450, 64450, 64400, 64400, 64350, 64350, 64300, 64250, 64250, 64200, 64200, 64150, 64150, 64100, 64100, 64100, 64050, 64050, 64000, 64000, 63950, 63950, 63900, 63900, 63900, 63850, 63850, 63800, 63800, 63800, 63750, 63750, 63750, 63700, 63700, 63700, 63650, 63650, 63650, 63600, 63600, 63600, 63550, 63550, 63550, 63500, 63500, 63500, 63500, 63450, 63450, 63450, 63450, 63400, 63400, 63400, 63400, 63400, 63350, 63350, 63350, 63350, 63350, 63350, 63300, 63300, 63300, 63300, 63300, 63300, 63250, 63250, 63250, 63250, 63250, 63250, 63250, 63250, 63250, 63250, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63200, 63250, 63250, 63250, 63250, 63250, 63250, 63250, 63250, 63250, 63250, 63300, 63300, 63300, 63300, 63300, 63300, 63300, 63350, 63350, 63350, 63350, 63350, 63350, 63400, 63400, 63400, 63400, 63400, 63400, 63450, 63450, 63450, 63450, 63500, 63500, 63500, 63500, 63500, 63550, 63550, 63550, 63550, 63600, 63600, 63600, 63600, 63650, 63650, 63650, 63650, 63700, 63700, 63700, 63750, 63750, 63750, 63800, 63800, 63800, 63800, 63850, 63850, 63850, 63900, 63900, 63900, 63950, 63950, 63950, 64000, 64000, 64000, 64050, 64050, 64100, 64100, 64100, 64150, 64150, 64150, 64200, 64200, 64250, 64250, 64250, 64300, 64300, 64350, 64350, 64350, 64400, 64400, 64450, 64450, 64450, 64500, 64500, 64550, 64550, 64600, 64600, 64650, 64650, 64650, 64700, 64700, 64750, 64750, 64800, 64800, 64850, 64850, 64900, 64900, 64950, 64950, 65000, 65000, 65050, 65050, 65100, 65100, 65150, 65150, 65200, 65200, 65250, 65250, 65300, 65300, 65350, 65350, 65400, 65400, 65450, 65500, 65500, 65550, 65550, 65600, 65600, 65650, 65650, 65700, 65750, 65750, 65800, 65800, 65850, 65850, 65900, 65950, 65950, 66000, 66000, 66050, 66100, 66100, 66150, 66150, 66200, 66250, 66250, 66300, 66350, 66350, 66400, 66400, 66450, 66500, 66500, 66550, 66600, 66600, 66650, 66700, 66700, 66750, 66750, 66800, 66850, 66850, 66900, 66950, 66950, 67000, 67050, 67050, 67100, 67150, 67150, 67200, 67250, 67300, 67300, 67350, 67400, 67400, 67450, 67500, 67500, 67550, 67600, 67650, 67650, 67700, 67750, 67750, 67800, 67850, 67900, 67900, 67950, 68000, 68050, 68050, 68100, 68150, 68150, 68200, 68250, 68300, 68300, 68350, 68400, 68450, 68450, 68500, 68550, 68600, 68650, 68650, 68700, 68750, 68800, 68800, 68850, 68900, 68950, 69000, 69000, 69050, 69100, 69150, 69150, 69200, 69250, 69300, 69350, 69350, 69400, 69450, 69500, 69550, 69600, 69600, 69650, 69700, 69750, 69800, 69800, 69850, 69900, 69950, 70000, 70050, 70050, 70100, 70150, 70200, 70250, 70300, 70300, 70350, 70400, 70450, 70500, 70550, 70600, 70600, 70650, 70700, 70750, 70800, 70850, 70900, 70900, 70950, 71000, 71050, 71100, 71150, 71200, 71250, 71300, 71300, 71350, 71400, 71450, 71500, 71550, 71600, 71650, 71700, 71700, 71750, 71800, 71850, 71900, 71950, 72000, 72050, 72100, 72150, 72200, 72200, 72250, 72300, 72350, 72400, 72450, 72500, 72550, 72600, 72650, 72700, 72750, 72800, 72850, 72850, 72900, 72950, 73000, 73050, 73100, 73150, 73200, 73250, 73300, 73350, 73400, 73450, 73500, 73550, 73600, 73650, 73700, 73750, 73800, 73850, 73900, 73900, 73950, 74000, 74050, 74100, 74150, 74200, 74250, 74300, 74350, 74400, 74450, 74500, 74550, 74600, 74650, 74700, 74750, 74800, 74850, 74900, 74950, 75000, 75050, 75100, 75150, 75200, 75250, 75300, 75350, 75400, 75450, 75500, 75550, 75600, 75650, 75700, 75750, 75800, 75850, 75900, 76000, 76050, 76100, 76150, 76200, 76250, 76300, 76350, 76400, 76450, 76500, 76550, 76600, 76650, 76700, 76750, 76800, 76850, 76900, 76950, 77000, 77050, 77100, 77200, 77250, 77300, 77350, 77400, 77450, 77500, 77550, 77600, 77650, 77700, 77750, 77800, 77850, 77900, 78000, 78050, 78100, 78150, 78200, 78250, 78300, 78350, 78400, 78450, 78500, 78550, 78600, 78700, 78750, 78800, 78850, 78900, 78950, 79000, 79050, 79100, 79150, 79250, 79300, 79350, 79400, 79450, 79500, 79550, 79600, 79650, 79750, 79800, 79850, 79900, 79950, 80000, 80050, 80100, 80150, 80250, 80300, 80350, 80400, 80450, 80500, 80550, 80600, 80700, 80750, 80800, 80850, 80900, 80950, 81000, 81100, 81150, 81200, 81250, 81300, 81350, 81400, 81450, 81550, 81600, 81650, 81700, 81750, 81800, 81900, 81950, 82000, 82050, 82100, 82150, 82200, 82300, 82350, 82400, 82450, 82500, 82550, 82650, 82700, 82750, 82800, 82850, 82900, 83000, 83050, 83100, 83150, 83200, 83250, 83350, 83400, 83450, 83500, 83550, 83650, 83700, 83750, 83800, 83850, 83900, 84000, 84050, 84100, 84150, 84200, 84300, 84350, 84400, 84450, 84500, 84600, 84650, 84700, 84750, 84800, 84900, 84950, 85000, 85050, 85100, 85200, 85250, 85300, 85350, 85400, 85500, 85550, 85600, 85650, 85700, 85800, 85850, 85900, 85950, 86000, 86100, 86150, 86200, 86250, 86350, 86400, 86450, 86500, 86550, 86650, 86700, 86750, 86800, 86900, 86950, 87000, 87050, 87150, 87200, 87250, 87300, 87350, 87450, 87500, 87550, 87600, 87700, 87750, 87800, 87850, 87950, 88000, 88050, 88100, 88200, 88250, 88300, 88350, 88450, 88500, 88550, 88600, 88700, 88750, 88800, 88850, 88950, 89000, 89050, 89100, 89200, 89250, 89300, 89350, 89450, 89500, 89550, 89600, 89700, 89750, 89800, 89900, 89950, 90000, 90050, 90150, 90200, 90250, 90300, 90400, 90450, 90500, 90600, 90650, 90700, 90750, 90850, 90900, 90950, 91000, 91100, 91150, 91200, 91300, 91350, 91400, 91450, 91550, 91600, 91650, 91750, 91800, 91850, 91950, 92000, 92050, 92100, 92200, 92250};

    double l = std::round(t->slc_muoncandidate_length.at(scl_ll_max));
    double dqdx_cut = 200000;
    if (l >= 0 && l < 1000) {
      dqdx_cut = svm_x.at(l);
    }
      
    if (dqdx_calib > dqdx_cut) continue;
    // if(t->slc_nuvtx_z.at(scl_ll_max) <= 500) continue;

    if (isSignal && nu_origin) selected_signal_events_percut["mip_consistency"]+=event_weight;
    selected_events_percut["mip_consistency"]+=event_weight;



    // Just before the FV cut, make distribution of vtxz
    if (t->slc_nuvtx_y.at(scl_ll_max) > 82) {
      hmap_vtxz_upborder["total"]->Fill(t->slc_nuvtx_z.at(scl_ll_max));
      hmap_vtxx_upborder["total"]->Fill(t->slc_nuvtx_z.at(scl_ll_max));
      if (isSignal && nu_origin) {
        hmap_vtxz_upborder["signal"]->Fill(t->slc_nuvtx_z.at(scl_ll_max));
        hmap_vtxx_upborder["signal"]->Fill(t->slc_nuvtx_z.at(scl_ll_max));
      } else {
        hmap_vtxz_upborder["background"]->Fill(t->slc_nuvtx_z.at(scl_ll_max));
        hmap_vtxx_upborder["background"]->Fill(t->slc_nuvtx_z.at(scl_ll_max));
      }
    }


    // FV cut
    if(t->slc_nuvtx_fv.at(scl_ll_max) == 0) continue;
    if(t->slc_nuvtx_z.at(scl_ll_max) > 675 && t->slc_nuvtx_z.at(scl_ll_max) < 775) continue;
    // if(t->slc_nuvtx_z.at(scl_ll_max) < 200) continue;

    if (isSignal && nu_origin) selected_signal_events_percut["fiducial_volume"]+=event_weight;
    selected_events_percut["fiducial_volume"]+=event_weight;

    // Select the bump only
    // if(t->slc_iscontained.at(scl_ll_max)) continue; // Uncontained
    // if(t->slc_ntrack.at(scl_ll_max) != 1) continue; // Multiplicity == 1
    // if(t->slc_nuvtx_y.at(scl_ll_max) > 0) continue; // Vertex in the bottom half of the detector
    // if(t->slc_nuvtx_x.at(scl_ll_max) > 128.175) continue; // Vertex in the anode half of the detector
    // if(t->slc_longesttrack_theta.at(scl_ll_max) > -0.6) continue; // cos(theta) < -0.6


    // if(t->slc_nuvtx_x.at(scl_ll_max) > 128.175) continue; // anode_vtx
    // if(t->slc_nuvtx_x.at(scl_ll_max) <= 128.175) continue; // cathode_vtx
    
    // if (abs(t->slc_longesttrack_phi.at(scl_ll_max)) < TMath::Pi()/2.) continue; // right (towards the anode)
    // if (abs(t->slc_longesttrack_phi.at(scl_ll_max)) >= TMath::Pi()/2.) continue; // left (towards the cathode)

    // if (!(t->slc_longesttrack_phi.at(scl_ll_max) > -TMath::Pi()/4 && t->slc_longesttrack_phi.at(scl_ll_max) < TMath::Pi()/4)) continue; // cathode
    // if (!(t->slc_longesttrack_phi.at(scl_ll_max) > TMath::Pi()/4 && t->slc_longesttrack_phi.at(scl_ll_max) < (3./4.)*TMath::Pi())) continue; // up
    // if (!(t->slc_longesttrack_phi.at(scl_ll_max) > -(3./4.)*TMath::Pi() && t->slc_longesttrack_phi.at(scl_ll_max) < -TMath::Pi()/4)) continue; // down
    // if (!((t->slc_longesttrack_phi.at(scl_ll_max) > (3./4.)*TMath::Pi() && t->slc_longesttrack_phi.at(scl_ll_max) < TMath::Pi())
    //         || (t->slc_longesttrack_phi.at(scl_ll_max) > -TMath::Pi() && t->slc_longesttrack_phi.at(scl_ll_max) < -(3./4.)*TMath::Pi()))) continue; // anode


    // No 30 degree
    // if (t->slc_longesttrack_theta.at(scl_ll_max) > 0.85 && t->slc_longesttrack_theta.at(scl_ll_max) < 0.89) continue;

    //if(t->slc_mult_track_tolerance.at(scl_ll_max) <= 1) continue;


    //if (t->slc_nuvtx_z.at(scl_ll_max) < 300) continue;

    //if(t->slc_longesttrack_length.at(scl_ll_max) < 25.) continue;
    
    // if(t->slc_iscontained.at(scl_ll_max)) continue;
    
    //if(t->slc_crosses_top_boundary.at(scl_ll_max) == 1) continue;

    // if (t->slc_muoncandidate_mom_mcs.at(scl_ll_max) > 2.5) continue;

    // Remove flipped tracks (truth cut)
    // if (isSignal && (t->lep_costheta * t->slc_longesttrack_theta.at(scl_ll_max) < 0) ) continue;


    
    
    //
    // EVENT IS SELECTED
    //
    
    // if (isSignal && nu_origin)std::cout << ">>>>>>>>>>>>>>>>> Event is selected, " << t->run << ", " << t->subrun << ", " << t->event << ", slice " << scl_ll_max << std::endl;
    
    _event_histo_1d->hmap_onebin["total"]->Fill(0.5, event_weight);
    hmap_trklen["total"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
    _event_histo_1d->hmap_trkmom["total"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
    hmap_trkmom_classic["total"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
    hmap_trkphi["total"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
    _event_histo_1d->hmap_trktheta["total"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
    hmap_trktheta_classic["total"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
    hmap_multpfp["total"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
    hmap_multtracktol["total"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
    _event_histo->hmap_trktheta_trkmom["total"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
    _event_histo->hmap_trktheta_trkmom_poly["total"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);


    if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, hmap_trkmom_genie_pm1_bs, "total", fname_genie_pm1, wgts_genie_pm1);

    if (!isdata && _fill_bootstrap_genie) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_genie_multisim_bs, "total", fname_genie_multisim, wgts_genie_multisim);
    if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_genie_multisim_bs, "total", fname_genie_multisim, wgts_genie_multisim);
    if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_genie_multisim_bs, "total", fname_genie_multisim, wgts_genie_multisim);
    if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_genie_multisim_bs, "total", fname_genie_multisim, wgts_genie_multisim);
    if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_genie_multisim_bs, "total", fname_genie_multisim, wgts_genie_multisim);

    if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_extra_syst_multisim_bs, "total", fname_extra_syst, wgts_extra_syst);
    if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_extra_syst_multisim_bs, "total", fname_extra_syst, wgts_extra_syst);
    if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_extra_syst_multisim_bs, "total", fname_extra_syst, wgts_extra_syst);
    if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_extra_syst_multisim_bs, "total", fname_extra_syst, wgts_extra_syst);
    if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_extra_syst_multisim_bs, "total", fname_extra_syst, wgts_extra_syst);

    if (!isdata && _fill_bootstrap_flux) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_flux_multisim_bs, "total", fname_flux_multisim, wgts_flux_multisim);
    if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_flux_multisim_bs, "total", fname_flux_multisim, wgts_flux_multisim);
    if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_flux_multisim_bs, "total", fname_flux_multisim, wgts_flux_multisim);
    if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_flux_multisim_bs, "total", fname_flux_multisim, wgts_flux_multisim);
    if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_flux_multisim_bs, "total", fname_flux_multisim, wgts_flux_multisim);

    if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_mc_stat_multisim_bs, "total", fname_mc_stat_multisim, wgts_mc_stat_multisim);
    if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_mc_stat_multisim_bs, "total", fname_mc_stat_multisim, wgts_mc_stat_multisim);
    if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_mc_stat_multisim_bs, "total", fname_mc_stat_multisim, wgts_mc_stat_multisim);
    if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_mc_stat_multisim_bs, "total", fname_mc_stat_multisim, wgts_mc_stat_multisim);
    if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_mc_stat_multisim_bs, "total", fname_mc_stat_multisim, wgts_mc_stat_multisim);


    if (isSignal) {
      h_true_nu_eng_aftersel->Fill(t->nu_e, event_weight);
    }

    if (isSignal) {

      // Fill the true-reco TTree for the nominal case
      _mom_true = t->true_muon_mom;
      _mom_mcs = t->slc_muoncandidate_mom_mcs.at(scl_ll_max);
      _contained = t->slc_muoncandidate_contained.at(scl_ll_max);
      _selected = true;

      _angle_true = t->lep_costheta;
      _angle_reco = t->slc_longesttrack_theta.at(scl_ll_max); //t->slc_muoncandidate_theta.at(scl_ll_max);

      _event_weight_fortree = event_weight;
      
      _wgtsnames_genie_multisim = fname_genie_multisim;
      _wgts_genie_multisim = wgts_genie_multisim;

      _wgtsnames_extra_syst = fname_extra_syst;
      _wgts_extra_syst = wgts_extra_syst;

      _wgtsnames_flux_multisim = fname_flux_multisim;
      _wgts_flux_multisim = wgts_flux_multisim;

      _true_reco_tree->Fill();

      // For the migration matrix
      int m = _event_histo->h_reco_per_true[0][0]->GetXaxis()->FindBin(_angle_true) - 1; // true bin
      int n = _event_histo->h_reco_per_true[0][0]->GetYaxis()->FindBin(_mom_true) - 1; // true bin
      if (m >= 0 && n >= 0 
          && m < _event_histo->h_reco_per_true[0][0]->GetNbinsX()    // Avoid overflows
          && n < _event_histo->h_reco_per_true[0][0]->GetNbinsY()) { // Avoid overflows
        _event_histo->h_reco_per_true[m][n]->Fill(_angle_reco, _mom_mcs, event_weight);
        if(!isdata && _fill_bootstrap_genie) FillBootstrap(_angle_reco, _mom_mcs, m, n, event_weight, _event_histo->bs_genie_multisim_reco_per_true, fname_genie_multisim, wgts_genie_multisim);
        if(!isdata && _fill_bootstrap_extra_syst) FillBootstrap(_angle_reco, _mom_mcs, m, n, event_weight, _event_histo->bs_extra_syst_multisim_reco_per_true, fname_extra_syst, wgts_extra_syst);
        if(!isdata && _fill_bootstrap_flux) FillBootstrap(_angle_reco, _mom_mcs, m, n, event_weight, _event_histo->bs_flux_multisim_reco_per_true, fname_flux_multisim, wgts_flux_multisim);
        if(!isdata && _fill_bootstrap_mc_stat) FillBootstrap(_angle_reco, _mom_mcs, m, n, event_weight, _event_histo->bs_mc_stat_multisim_reco_per_true, fname_mc_stat_multisim, wgts_mc_stat_multisim);
      }

      // For the migration matrix (poly)
      m = _event_histo->h_poly_reco_per_true[0]->FindBin(_angle_true, _mom_true); // true bin
      int i = _event_histo->h_poly_reco_per_true[0]->FindBin(_angle_reco, _mom_mcs); // reco bin
      if (m < 0) m = 0; // Negative bins are overflows, and are all added in entry 0 of the vector
      if (m < _event_histo->h_poly_reco_per_true[0]->GetNumberOfBins()+1) {
        _event_histo->h_poly_reco_per_true[m]->Fill(_angle_reco, _mom_mcs, event_weight);
        if(!isdata && _fill_bootstrap_genie) FillBootstrap(m, i, event_weight, _event_histo->bs_genie_multisim_poly_reco_per_true, fname_genie_multisim, wgts_genie_multisim);
        if(!isdata && _fill_bootstrap_flux) FillBootstrap(m, i, event_weight, _event_histo->bs_flux_multisim_poly_reco_per_true, fname_flux_multisim, wgts_flux_multisim);
        if(!isdata && _fill_bootstrap_extra_syst) FillBootstrap(m, i, event_weight, _event_histo->bs_extra_syst_multisim_poly_reco_per_true, fname_extra_syst, wgts_extra_syst);
        if(!isdata && _fill_bootstrap_mc_stat) FillBootstrap(m, i, event_weight, _event_histo->bs_mc_stat_multisim_poly_reco_per_true, fname_mc_stat_multisim, wgts_mc_stat_multisim);
      }

      _event_histo_1d->h_true_reco_mom->Fill(_mom_true, _mom_mcs, event_weight);
      _event_histo_1d->h_true_reco_costheta->Fill(_angle_true, _angle_reco, event_weight);

      if(!isdata && _fill_bootstrap_genie) FillBootstrap(_mom_true, _mom_mcs, event_weight, bs_genie_pm1_true_reco_mom, fname_genie_pm1, wgts_genie_pm1);

      if(!isdata && _fill_bootstrap_genie) _event_histo_1d->bs_genie_multisim_true_reco_mumom->Fill(_mom_true, _mom_mcs, event_weight, wgts_genie_multisim);
      if(!isdata && _fill_bootstrap_genie) _event_histo_1d->bs_genie_multisim_true_reco_muangle->Fill(_angle_true, _angle_reco, event_weight, wgts_genie_multisim);

      if(!isdata && _fill_bootstrap_extra_syst) _event_histo_1d->bs_extra_syst_true_reco_mumom->Fill(_mom_true, _mom_mcs, event_weight, wgts_extra_syst);
      if(!isdata && _fill_bootstrap_extra_syst) _event_histo_1d->bs_extra_syst_true_reco_muangle->Fill(_angle_true, _angle_reco, event_weight, wgts_extra_syst);

      if(!isdata && _fill_bootstrap_flux) _event_histo_1d->bs_flux_multisim_true_reco_mumom->Fill(_mom_true, _mom_mcs, event_weight, wgts_flux_multisim);
      if(!isdata && _fill_bootstrap_flux) _event_histo_1d->bs_flux_multisim_true_reco_muangle->Fill(_angle_true, _angle_reco, event_weight, wgts_flux_multisim);

      if(!isdata && _fill_bootstrap_mc_stat) _event_histo_1d->bs_mc_stat_multisim_true_reco_mumom->Fill(_mom_true, _mom_mcs, event_weight, wgts_mc_stat_multisim);
      if(!isdata && _fill_bootstrap_mc_stat) _event_histo_1d->bs_mc_stat_multisim_true_reco_muangle->Fill(_angle_true, _angle_reco, event_weight, wgts_mc_stat_multisim);

    }
    
    int true_pdg = t->slc_muoncandidate_truepdg.at(scl_ll_max);
   
    //
    // Fill dQ/ds histograms
    //
    hmap_dqdx_trunc["total"]->Fill(dqdx_calib, event_weight);
    h_dqdx_trunc_length->Fill(dqdx_calib, t->slc_muoncandidate_length.at(scl_ll_max), event_weight);
    if (true_pdg == 13 || true_pdg == -13) {
      hmap_dqdx_trunc["muon"]->Fill(dqdx_calib, event_weight);
      h_dqdx_trunc_length_muon->Fill(dqdx_calib, t->slc_muoncandidate_length.at(scl_ll_max), event_weight);
      if (dqdx_calib >= 0. && dqdx_calib <=200000. && t->slc_muoncandidate_length.at(scl_ll_max) < 2000) {
        _csvfile << dqdx_calib << ","
                 << t->slc_muoncandidate_length.at(scl_ll_max) << "," << "1" << std::endl;
      }
    } else if (true_pdg == 211 || true_pdg == -211) {
      hmap_dqdx_trunc["pion"]->Fill(dqdx_calib, event_weight);
    } else if (true_pdg == 2212) {
      hmap_dqdx_trunc["proton"]->Fill(dqdx_calib, event_weight);
      h_dqdx_trunc_length_proton->Fill(dqdx_calib, t->slc_muoncandidate_length.at(scl_ll_max), event_weight);
      if (dqdx_calib >= 0. && dqdx_calib <=200000. && t->slc_muoncandidate_length.at(scl_ll_max) < 2000) {
        _csvfile << dqdx_calib << ","
                 << t->slc_muoncandidate_length.at(scl_ll_max) << "," << "0" << std::endl;
      }
    } else if (true_pdg == 22) {
      hmap_dqdx_trunc["photon"]->Fill(dqdx_calib, event_weight);
    } else if (true_pdg == 11 || true_pdg == -11) {
      hmap_dqdx_trunc["electron"]->Fill(dqdx_calib, event_weight);
    } else {
      hmap_dqdx_trunc["else"]->Fill(dqdx_calib, event_weight);
    }
    
    double hypo_pe = 0;
    for (int pmt = 0; pmt < 32; pmt++) {
      hypo_pe += (t->slc_flshypo_spec.at(scl_ll_max))[pmt];
    }
    hmap_xdiff["total"]->Fill(t->slc_flsmatch_qllx.at(scl_ll_max) - t->slc_flsmatch_tpcx.at(scl_ll_max), event_weight);
    // reintro hmap_zdiff["total"]->Fill(t->slc_flsmatch_hypoz.at(scl_ll_max) - t->beamfls_z.at(flashInBeamSpill), event_weight);
    // reintro hmap_pediff["total"]->Fill(hypo_pe - t->beamfls_pe.at(flashInBeamSpill), event_weight);
        
    hmap_vtxx["total"]->Fill(t->slc_nuvtx_x.at(scl_ll_max), event_weight);
    hmap_vtxy["total"]->Fill(t->slc_nuvtx_y.at(scl_ll_max), event_weight);
    hmap_vtxz["total"]->Fill(t->slc_nuvtx_z.at(scl_ll_max), event_weight);
    
    double second_score = -9999, score_difference = -9999;
    if (temp_score.size() > 1) {
      second_score = temp_score.at(1);
      score_difference = temp_score.at(0) - temp_score.at(1);
    }

    hmap_flsmatch_score["total"]->Fill(t->slc_flsmatch_score.at(scl_ll_max), event_weight);
    hmap_flsmatch_score_second["total"]->Fill(second_score, event_weight);
    hmap_flsmatch_score_difference["total"]->Fill(score_difference, event_weight);


    // SIGNAL
    if ( isSignal && nu_origin) {
      n_signal ++;
      hmap_xdiff["signal"]->Fill(t->slc_flsmatch_qllx.at(scl_ll_max) - t->slc_flsmatch_tpcx.at(scl_ll_max), event_weight);
      // reintro hmap_zdiff["signal"]->Fill(t->slc_flsmatch_hypoz.at(scl_ll_max) - t->beamfls_z.at(flashInBeamSpill), event_weight);
      // reintro hmap_pediff["signal"]->Fill(hypo_pe - t->beamfls_pe.at(flashInBeamSpill), event_weight);
      
      hmap_vtxx["signal"]->Fill(t->slc_nuvtx_x.at(scl_ll_max), event_weight);
      hmap_vtxy["signal"]->Fill(t->slc_nuvtx_y.at(scl_ll_max), event_weight);
      hmap_vtxz["signal"]->Fill(t->slc_nuvtx_z.at(scl_ll_max), event_weight);
      
      hmap_flsmatch_score["signal"]->Fill(t->slc_flsmatch_score.at(scl_ll_max), event_weight);
      hmap_flsmatch_score_second["signal"]->Fill(second_score, event_weight);
      hmap_flsmatch_score_difference["signal"]->Fill(score_difference, event_weight);
    }
    // BACKGROUND
    else {
      hmap_xdiff["background"]->Fill(t->slc_flsmatch_qllx.at(scl_ll_max) - t->slc_flsmatch_tpcx.at(scl_ll_max), event_weight);
      // reintro hmap_zdiff["background"]->Fill(t->slc_flsmatch_hypoz.at(scl_ll_max) - t->beamfls_z.at(flashInBeamSpill), event_weight);
      // reintro hmap_pediff["background"]->Fill(hypo_pe - t->beamfls_pe.at(flashInBeamSpill), event_weight);

      hmap_vtxx["background"]->Fill(t->slc_nuvtx_x.at(scl_ll_max), event_weight);
      hmap_vtxy["background"]->Fill(t->slc_nuvtx_y.at(scl_ll_max), event_weight);
      hmap_vtxz["background"]->Fill(t->slc_nuvtx_z.at(scl_ll_max), event_weight);
      
      hmap_flsmatch_score["background"]->Fill(t->slc_flsmatch_score.at(scl_ll_max), event_weight);
      hmap_flsmatch_score_second["background"]->Fill(second_score, event_weight);
      hmap_flsmatch_score_difference["background"]->Fill(score_difference, event_weight);
    }
    
    if (isNueCCFV) {
      nue_cc_selected_total+=t->bnb_weight;
      if (t->nu_e >= 0.05 && t->nu_e <= 1.5){
        nue_cc_selected_total_energy_range+=t->bnb_weight;
      }
    }
    if (isNue) {
      if (t->nu_e >= 0.05 && t->nu_e <= 1.5 && t->ccnc==0 
        && t->tvtx_x[0] > 0. && t->tvtx_x[0] < 256.35
        && t->tvtx_y[0] > -116.5 && t->tvtx_y[0] < 116.5
        && t->tvtx_z[0] > 0. && t->tvtx_y[0] < 1036.8){
        nue_selected_total_energy_range+=t->bnb_weight;

        h_nue_selected_energy->Fill(t->nu_e, event_weight); 
        if (std::abs(true_pdg) == 11) n_nue_electron+=t->bnb_weight;
        if (std::abs(true_pdg) == 2212) n_nue_proton+=t->bnb_weight;
        if (std::abs(true_pdg) == 211) n_nue_pion+=t->bnb_weight;
      }
    }


    //
    // SIGNAL
    //
    if(nu_origin && isSignal /*&& true_pdg==13 && true_origin == 0*/) {

      if (true_pdg==13) real_muon_sel += event_weight;
      
      //std::cout << "Is signal and is selected. event: " << t->event << std::endl;

      signal_sel += event_weight;
      _event_histo_1d->h_eff_onebin_num->Fill(0.5, event_weight);
      h_eff_num->Fill(t->nu_e, event_weight);
      _event_histo_1d->h_eff_mumom_num->Fill(t->true_muon_mom, event_weight);
      if (!isdata && _fill_bootstrap_genie) bs_genie_pm1_eff_mumom_num.Fill(t->true_muon_mom, event_weight, wgts_genie_pm1);
       
      if (!isdata && _fill_bootstrap_genie) _event_histo_1d->bs_genie_multisim_eff_onebin_num->Fill(0.5, event_weight, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) _event_histo_1d->bs_genie_multisim_eff_mumom_num->Fill(t->true_muon_mom, event_weight, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) _event_histo_1d->bs_genie_multisim_eff_muangle_num->Fill(t->lep_costheta, event_weight, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) _event_histo->bs_genie_multisim_eff_muangle_mumom_num->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) _event_histo->bs_genie_multisim_eff_poly_muangle_mumom_num->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_genie_multisim);

      if (!isdata && _fill_bootstrap_extra_syst) _event_histo_1d->bs_extra_syst_multisim_eff_onebin_num->Fill(0.5, event_weight, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) _event_histo_1d->bs_extra_syst_multisim_eff_mumom_num->Fill(t->true_muon_mom, event_weight, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) _event_histo_1d->bs_extra_syst_multisim_eff_muangle_num->Fill(t->lep_costheta, event_weight, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) _event_histo->bs_extra_syst_multisim_eff_muangle_mumom_num->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) _event_histo->bs_extra_syst_multisim_eff_poly_muangle_mumom_num->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_extra_syst);

      if (!isdata && _fill_bootstrap_flux) _event_histo_1d->bs_flux_multisim_eff_onebin_num->Fill(0.5, event_weight, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) _event_histo_1d->bs_flux_multisim_eff_mumom_num->Fill(t->true_muon_mom, event_weight, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) _event_histo_1d->bs_flux_multisim_eff_muangle_num->Fill(t->lep_costheta, event_weight, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) _event_histo->bs_flux_multisim_eff_muangle_mumom_num->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) _event_histo->bs_flux_multisim_eff_poly_muangle_mumom_num->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_flux_multisim);

      if (!isdata && _fill_bootstrap_mc_stat) _event_histo_1d->bs_mc_stat_multisim_eff_onebin_num->Fill(0.5, event_weight, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) _event_histo_1d->bs_mc_stat_multisim_eff_mumom_num->Fill(t->true_muon_mom, event_weight, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) _event_histo_1d->bs_mc_stat_multisim_eff_muangle_num->Fill(t->lep_costheta, event_weight, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) _event_histo->bs_mc_stat_multisim_eff_muangle_mumom_num->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) _event_histo->bs_mc_stat_multisim_eff_poly_muangle_mumom_num->Fill(t->lep_costheta, t->true_muon_mom, event_weight, wgts_mc_stat_multisim);


      _event_histo_1d->h_eff_muangle_num->Fill(t->lep_costheta, event_weight);
      _event_histo->h_eff_muangle_mumom_num->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
      _event_histo->h_eff_muangle_mumom_poly_num->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
      h_eff_muphi_num->Fill(t->lep_phi, event_weight);
      h_eff_mult_num->Fill(t->genie_mult, event_weight);
      h_eff_mult_ch_num->Fill(t->genie_mult_ch, event_weight);
      h_mu_eff_mom_sel->Fill(t->true_muon_mom, t->muon_reco_eff, event_weight);

      if (t->mode == 0) {
        h_eff_qe_num->Fill(t->nu_e, event_weight);
        signal_sel_qe += event_weight;
      }
      if (t->mode == 1) {
        h_eff_res_num->Fill(t->nu_e, event_weight);
        signal_sel_res += event_weight;
      }
      if (t->mode == 2) {
        h_eff_dis_num->Fill(t->nu_e, event_weight);
        signal_sel_dis += event_weight;
      }
      if (t->mode == 3) {
        h_eff_coh_num->Fill(t->nu_e, event_weight);
        signal_sel_coh += event_weight;
      }
      if (t->mode == 10) {
        h_eff_mec_num->Fill(t->nu_e, event_weight);
        signal_sel_mec += event_weight;
      }

      double m_mu = 0.105658; // GeV
      double mu_px = t->true_muon_mom * std::sin(std::acos(t->lep_costheta)) * std::cos(t->lep_phi);
      double mu_py = t->true_muon_mom * std::sin(std::acos(t->lep_costheta)) * std::sin(t->lep_phi);
      double mu_pz = t->true_muon_mom * t->lep_costheta;
      double q0 = t->nu_e - std::sqrt(t->true_muon_mom * t->true_muon_mom + m_mu * m_mu);
      double q3 = std::sqrt(mu_px * mu_px + mu_py * mu_py + (t->nu_e - mu_pz) * (t->nu_e - mu_pz));

      // Also save themc truth histogram per interaction type
      hmap_mctruth_nuenergy["total"]->Fill(t->nu_e, event_weight);
      hmap_mctruth_mumom["total"]->Fill(t->true_muon_mom, event_weight);
      hmap_mctruth_mucostheta["total"]->Fill(t->lep_costheta, event_weight);
      hmap_mctruth_muphi["total"]->Fill(t->lep_phi, event_weight);
      hmap_mctruth_chargedmult["total"]->Fill(t->genie_mult_ch, event_weight);
      hmap_mctruth_mucostheta_mumom["total"]->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
      hmap_mctruth_q0_q3["total"]->Fill(q3, q0, event_weight);
      if (t->mode == 0) {
        hmap_mctruth_nuenergy["qe"]->Fill(t->nu_e, event_weight);
        hmap_mctruth_mumom["qe"]->Fill(t->true_muon_mom, event_weight);
        hmap_mctruth_mucostheta["qe"]->Fill(t->lep_costheta, event_weight);
        hmap_mctruth_muphi["qe"]->Fill(t->lep_phi, event_weight);
        hmap_mctruth_chargedmult["qe"]->Fill(t->genie_mult_ch, event_weight);
        hmap_mctruth_mucostheta_mumom["qe"]->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
        hmap_mctruth_q0_q3["qe"]->Fill(q3, q0, event_weight);
      }
      if (t->mode == 1) {
        hmap_mctruth_nuenergy["res"]->Fill(t->nu_e, event_weight);
        hmap_mctruth_mumom["res"]->Fill(t->true_muon_mom, event_weight);
        hmap_mctruth_mucostheta["res"]->Fill(t->lep_costheta, event_weight);
        hmap_mctruth_muphi["res"]->Fill(t->lep_phi, event_weight);
        hmap_mctruth_chargedmult["res"]->Fill(t->genie_mult_ch, event_weight);
        hmap_mctruth_mucostheta_mumom["res"]->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
        hmap_mctruth_q0_q3["res"]->Fill(q3, q0, event_weight);
      }
      if (t->mode == 2) {
        hmap_mctruth_nuenergy["dis"]->Fill(t->nu_e, event_weight);
        hmap_mctruth_mumom["dis"]->Fill(t->true_muon_mom, event_weight);
        hmap_mctruth_mucostheta["dis"]->Fill(t->lep_costheta, event_weight);
        hmap_mctruth_muphi["dis"]->Fill(t->lep_phi, event_weight);
        hmap_mctruth_chargedmult["dis"]->Fill(t->genie_mult_ch, event_weight);
        hmap_mctruth_mucostheta_mumom["dis"]->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
        hmap_mctruth_q0_q3["dis"]->Fill(q3, q0, event_weight);
      }
      if (t->mode == 3) {
        hmap_mctruth_nuenergy["coh"]->Fill(t->nu_e, event_weight);
        hmap_mctruth_mumom["coh"]->Fill(t->true_muon_mom, event_weight);
        hmap_mctruth_mucostheta["coh"]->Fill(t->lep_costheta, event_weight);
        hmap_mctruth_muphi["coh"]->Fill(t->lep_phi, event_weight);
        hmap_mctruth_chargedmult["coh"]->Fill(t->genie_mult_ch, event_weight);
        hmap_mctruth_mucostheta_mumom["coh"]->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
        hmap_mctruth_q0_q3["coh"]->Fill(q3, q0, event_weight);
      }
      if (t->mode == 10) {
        hmap_mctruth_nuenergy["mec"]->Fill(t->nu_e, event_weight);
        hmap_mctruth_mumom["mec"]->Fill(t->true_muon_mom, event_weight);
        hmap_mctruth_mucostheta["mec"]->Fill(t->lep_costheta, event_weight);
        hmap_mctruth_muphi["mec"]->Fill(t->lep_phi, event_weight);
        hmap_mctruth_chargedmult["mec"]->Fill(t->genie_mult_ch, event_weight);
        hmap_mctruth_mucostheta_mumom["mec"]->Fill(t->lep_costheta, t->true_muon_mom, event_weight);
        hmap_mctruth_q0_q3["mec"]->Fill(q3, q0, event_weight);
      }

      pEff->Fill(true, t->nu_e);
      _event_histo_1d->hmap_onebin["signal"]->Fill(0.5, event_weight);
      hmap_trklen["signal"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
      _event_histo_1d->hmap_trkmom["signal"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      hmap_trkmom_classic["signal"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      //hmap_trkmom_genie_pm1_bs["signal"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, hmap_trkmom_genie_pm1_bs, "signal", fname_genie_pm1, wgts_genie_pm1);

      if (!isdata && _fill_bootstrap_genie) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_genie_multisim_bs, "signal", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_genie_multisim_bs, "signal", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_genie_multisim_bs, "signal", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_genie_multisim_bs, "signal", fname_genie_multisim, wgts_genie_multisim);      
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_genie_multisim_bs, "signal", fname_genie_multisim, wgts_genie_multisim);      

      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_extra_syst_multisim_bs, "signal", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_extra_syst_multisim_bs, "signal", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_extra_syst_multisim_bs, "signal", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_extra_syst_multisim_bs, "signal", fname_extra_syst, wgts_extra_syst);      
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_extra_syst_multisim_bs, "signal", fname_extra_syst, wgts_extra_syst);
      
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_flux_multisim_bs, "signal", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_flux_multisim_bs, "signal", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_flux_multisim_bs, "signal", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_flux_multisim_bs, "signal", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_flux_multisim_bs, "signal", fname_flux_multisim, wgts_flux_multisim);
 
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_mc_stat_multisim_bs, "signal", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_mc_stat_multisim_bs, "signal", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_mc_stat_multisim_bs, "signal", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_mc_stat_multisim_bs, "signal", fname_mc_stat_multisim, wgts_mc_stat_multisim);      
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_mc_stat_multisim_bs, "signal", fname_mc_stat_multisim, wgts_mc_stat_multisim);      

      hmap_trkphi["signal"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
      _event_histo_1d->hmap_trktheta["signal"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
      hmap_trktheta_classic["signal"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
      hmap_multpfp["signal"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
      hmap_multtracktol["signal"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
      _event_histo->hmap_trktheta_trkmom["signal"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      _event_histo->hmap_trktheta_trkmom_poly["signal"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      
      if (t->slc_origin_extra.at(scl_ll_max) == 0) {
        _event_histo_1d->hmap_onebin["signal_stopmu"]->Fill(0.5, event_weight);
        hmap_trklen["signal_stopmu"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trkmom["signal_stopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        hmap_trkmom_classic["signal_stopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        //hmap_trkmom_genie_pm1_bs["signal_stopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

        hmap_trkphi["signal_stopmu"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trktheta["signal_stopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_trktheta_classic["signal_stopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_multpfp["signal_stopmu"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
        hmap_multtracktol["signal_stopmu"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom["signal_stopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom_poly["signal_stopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);

      } else {
        _event_histo_1d->hmap_onebin["signal_nostopmu"]->Fill(0.5, event_weight);
        hmap_trklen["signal_nostopmu"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trkmom["signal_nostopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        hmap_trkmom_classic["signal_nostopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        //hmap_trkmom_genie_pm1_bs["signal_nostopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

        hmap_trkphi["signal_nostopmu"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trktheta["signal_nostopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_trktheta_classic["signal_nostopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_multpfp["signal_nostopmu"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
        hmap_multtracktol["signal_nostopmu"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom["signal_nostopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom_poly["signal_nostopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      }
    }
    //
    // ANUMU
    //
    else if(nu_origin && t->ccnc==0 && t->nupdg==-14 && t->fv==1){
      bkg_anumu_sel += event_weight;
      pEff->Fill(false, t->nu_e);
      _event_histo_1d->hmap_onebin["anumu"]->Fill(0.5, event_weight);
      hmap_trklen["anumu"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
      _event_histo_1d->hmap_trkmom["anumu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      hmap_trkmom_classic["anumu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      //hmap_trkmom_genie_pm1_bs["anumu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, hmap_trkmom_genie_pm1_bs, "anumu", fname_genie_pm1, wgts_genie_pm1);

      if (!isdata && _fill_bootstrap_genie) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_genie_multisim_bs, "anumu", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_genie_multisim_bs, "anumu", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_genie_multisim_bs, "anumu", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_genie_multisim_bs, "anumu", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_genie_multisim_bs, "anumu", fname_genie_multisim, wgts_genie_multisim);

      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_extra_syst_multisim_bs, "anumu", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_extra_syst_multisim_bs, "anumu", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_extra_syst_multisim_bs, "anumu", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_extra_syst_multisim_bs, "anumu", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_extra_syst_multisim_bs, "anumu", fname_extra_syst, wgts_extra_syst);
      
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_flux_multisim_bs, "anumu", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_flux_multisim_bs, "anumu", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_flux_multisim_bs, "anumu", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_flux_multisim_bs, "anumu", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_flux_multisim_bs, "anumu", fname_flux_multisim, wgts_flux_multisim);

      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_mc_stat_multisim_bs, "anumu", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_mc_stat_multisim_bs, "anumu", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_mc_stat_multisim_bs, "anumu", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_mc_stat_multisim_bs, "anumu", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_mc_stat_multisim_bs, "anumu", fname_mc_stat_multisim, wgts_mc_stat_multisim);


      hmap_trkphi["anumu"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
      _event_histo_1d->hmap_trktheta["anumu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
      hmap_trktheta_classic["anumu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
      hmap_multpfp["anumu"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
      hmap_multtracktol["anumu"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
      _event_histo->hmap_trktheta_trkmom["anumu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      _event_histo->hmap_trktheta_trkmom_poly["anumu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
    }
    //
    // NUE
    //
    else if(nu_origin && t->ccnc==0 && (t->nupdg==-12 || t->nupdg==12) && t->fv==1){
      bkg_nue_sel += event_weight;
      pEff->Fill(false, t->nu_e);
      _event_histo_1d->hmap_onebin["nue"]->Fill(0.5, event_weight);
      hmap_trklen["nue"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
      _event_histo_1d->hmap_trkmom["nue"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      hmap_trkmom_classic["nue"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      //hmap_trkmom_genie_pm1_bs["nue"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, hmap_trkmom_genie_pm1_bs, "nue", fname_genie_pm1, wgts_genie_pm1);

      if (!isdata && _fill_bootstrap_genie) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_genie_multisim_bs, "nue", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_genie_multisim_bs, "nue", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_genie_multisim_bs, "nue", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_genie_multisim_bs, "nue", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_genie_multisim_bs, "nue", fname_genie_multisim, wgts_genie_multisim);

      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_extra_syst_multisim_bs, "nue", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_extra_syst_multisim_bs, "nue", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_extra_syst_multisim_bs, "nue", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_extra_syst_multisim_bs, "nue", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_extra_syst_multisim_bs, "nue", fname_extra_syst, wgts_extra_syst);
      
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_flux_multisim_bs, "nue", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_flux_multisim_bs, "nue", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_flux_multisim_bs, "nue", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_flux_multisim_bs, "nue", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_flux_multisim_bs, "nue", fname_flux_multisim, wgts_flux_multisim);

      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_mc_stat_multisim_bs, "nue", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_mc_stat_multisim_bs, "nue", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_mc_stat_multisim_bs, "nue", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_mc_stat_multisim_bs, "nue", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_mc_stat_multisim_bs, "nue", fname_mc_stat_multisim, wgts_mc_stat_multisim);
 

      hmap_trkphi["nue"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
      _event_histo_1d->hmap_trktheta["nue"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
      hmap_trktheta_classic["nue"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
      hmap_multpfp["nue"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
      hmap_multtracktol["nue"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
      _event_histo->hmap_trktheta_trkmom["nue"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      _event_histo->hmap_trktheta_trkmom_poly["nue"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      if (t->nupdg == 12)
        nue_cc_selected+=t->bnb_weight;
    }
    //
    // NC
    //
    else if(nu_origin && t->ccnc==1 && t->fv==1){
      bkg_nc_sel += event_weight;
      pEff->Fill(false, t->nu_e);
      _event_histo_1d->hmap_onebin["nc"]->Fill(0.5, event_weight);
      hmap_trklen["nc"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
      _event_histo_1d->hmap_trkmom["nc"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      hmap_trkmom_classic["nc"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      //hmap_trkmom_genie_pm1_bs["nc"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, hmap_trkmom_genie_pm1_bs, "nc", fname_genie_pm1, wgts_genie_pm1);

      if (!isdata && _fill_bootstrap_genie) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_genie_multisim_bs, "nc", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_genie_multisim_bs, "nc", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_genie_multisim_bs, "nc", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_genie_multisim_bs, "nc", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_genie_multisim_bs, "nc", fname_genie_multisim, wgts_genie_multisim);

      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_extra_syst_multisim_bs, "nc", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_extra_syst_multisim_bs, "nc", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_extra_syst_multisim_bs, "nc", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_extra_syst_multisim_bs, "nc", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_extra_syst_multisim_bs, "nc", fname_extra_syst, wgts_extra_syst);
      
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_flux_multisim_bs, "nc", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_flux_multisim_bs, "nc", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_flux_multisim_bs, "nc", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_flux_multisim_bs, "nc", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_flux_multisim_bs, "nc", fname_flux_multisim, wgts_flux_multisim);

      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_mc_stat_multisim_bs, "nc", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_mc_stat_multisim_bs, "nc", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_mc_stat_multisim_bs, "nc", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_mc_stat_multisim_bs, "nc", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_mc_stat_multisim_bs, "nc", fname_mc_stat_multisim, wgts_mc_stat_multisim);

      hmap_trkphi["nc"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
      _event_histo_1d->hmap_trktheta["nc"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
      hmap_trktheta_classic["nc"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
      hmap_multpfp["nc"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
      hmap_multtracktol["nc"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
      _event_histo->hmap_trktheta_trkmom["nc"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      _event_histo->hmap_trktheta_trkmom_poly["nc"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      // proton
      if (t->slc_origin_extra.at(scl_ll_max) == 3) {
        _event_histo_1d->hmap_onebin["nc_proton"]->Fill(0.5, event_weight);
        hmap_trklen["nc_proton"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trkmom["nc_proton"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        hmap_trkmom_classic["nc_proton"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        //hmap_trkmom_genie_pm1_bs["nc_proton"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

        hmap_trkphi["nc_proton"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trktheta["nc_proton"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_trktheta_classic["nc_proton"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_multpfp["nc_proton"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
        hmap_multtracktol["nc_proton"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom["nc_proton"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom_poly["nc_proton"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      }
      // pion
      else if (t->slc_origin_extra.at(scl_ll_max) == 2) {
        _event_histo_1d->hmap_onebin["nc_pion"]->Fill(0.5, event_weight);
        hmap_trklen["nc_pion"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trkmom["nc_pion"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        hmap_trkmom_classic["nc_pion"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        //hmap_trkmom_genie_pm1_bs["nc_pion"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

        hmap_trkphi["nc_pion"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trktheta["nc_pion"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_trktheta_classic["nc_pion"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_multpfp["nc_pion"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
        hmap_multtracktol["nc_pion"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom["nc_pion"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom_poly["nc_pion"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      }
      // other
      else {
        _event_histo_1d->hmap_onebin["nc_other"]->Fill(0.5, event_weight);
        hmap_trklen["nc_other"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trkmom["nc_other"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        hmap_trkmom_classic["nc_other"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        //hmap_trkmom_genie_pm1_bs["nc_other"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

        hmap_trkphi["nc_other"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trktheta["nc_other"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_trktheta_classic["nc_other"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_multpfp["nc_other"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
        hmap_multtracktol["nc_other"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom["nc_other"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom_poly["nc_other"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      }
    }
    //
    // OUTFV
    //
    else if(nu_origin && t->fv==0){
      bkg_outfv_sel += event_weight;
      pEff->Fill(false, t->nu_e);
      _event_histo_1d->hmap_onebin["outfv"]->Fill(0.5, event_weight);
      hmap_trklen["outfv"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
      _event_histo_1d->hmap_trkmom["outfv"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      hmap_trkmom_classic["outfv"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      //hmap_trkmom_genie_pm1_bs["outfv"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, hmap_trkmom_genie_pm1_bs, "outfv", fname_genie_pm1, wgts_genie_pm1);

      if (!isdata && _fill_bootstrap_genie) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_genie_multisim_bs, "outfv", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_genie_multisim_bs, "outfv", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_genie_multisim_bs, "outfv", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_genie_multisim_bs, "outfv", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_genie_multisim_bs, "outfv", fname_genie_multisim, wgts_genie_multisim);

      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_extra_syst_multisim_bs, "outfv", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_extra_syst_multisim_bs, "outfv", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_extra_syst_multisim_bs, "outfv", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_extra_syst_multisim_bs, "outfv", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_extra_syst_multisim_bs, "outfv", fname_extra_syst, wgts_extra_syst);
      
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_flux_multisim_bs, "outfv", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_flux_multisim_bs, "outfv", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_flux_multisim_bs, "outfv", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_flux_multisim_bs, "outfv", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_flux_multisim_bs, "outfv", fname_flux_multisim, wgts_flux_multisim);

      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_mc_stat_multisim_bs, "outfv", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_mc_stat_multisim_bs, "outfv", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_mc_stat_multisim_bs, "outfv", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_mc_stat_multisim_bs, "outfv", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_mc_stat_multisim_bs, "outfv", fname_mc_stat_multisim, wgts_mc_stat_multisim);

      hmap_trkphi["outfv"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
      _event_histo_1d->hmap_trktheta["outfv"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
      hmap_trktheta_classic["outfv"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
      hmap_multpfp["outfv"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
      hmap_multtracktol["outfv"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
      _event_histo->hmap_trktheta_trkmom["outfv"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      _event_histo->hmap_trktheta_trkmom_poly["outfv"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      
      if (t->slc_origin_extra.at(scl_ll_max) == 0) {
        _event_histo_1d->hmap_onebin["outfv_stopmu"]->Fill(0.5, event_weight);
        hmap_trklen["outfv_stopmu"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trkmom["outfv_stopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        hmap_trkmom_classic["outfv_stopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        //hmap_trkmom_genie_pm1_bs["outfv_stopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

        hmap_trkphi["outfv_stopmu"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trktheta["outfv_stopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_trktheta_classic["outfv_stopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_multpfp["outfv_stopmu"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
        hmap_multtracktol["outfv_stopmu"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom["outfv_stopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom_poly["outfv_stopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      } else {
        _event_histo_1d->hmap_onebin["outfv_nostopmu"]->Fill(0.5, event_weight);
        hmap_trklen["outfv_nostopmu"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trkmom["outfv_nostopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        hmap_trkmom_classic["outfv_nostopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);

        hmap_trkphi["outfv_nostopmu"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trktheta["outfv_nostopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_trktheta_classic["outfv_nostopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_multpfp["outfv_nostopmu"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
        hmap_multtracktol["outfv_nostopmu"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom["outfv_nostopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom_poly["outfv_nostopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      }
    }
    //
    // COSMIC
    //
    else {
      bkg_cosmic_sel += event_weight;
      // Add extra weight to event_weight if we are scaling the cosmic background (for example from overlays)
      if (_scale_cosmics) event_weight *= _scale_factor_cosmic;
      if (t->slc_crosses_top_boundary.at(scl_ll_max) == 1 ) bkg_cosmic_top_sel++;
      pEff->Fill(false, t->nu_e);
      _event_histo_1d->hmap_onebin["cosmic"]->Fill(0.5, event_weight);
      hmap_trklen["cosmic"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
      _event_histo_1d->hmap_trkmom["cosmic"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      hmap_trkmom_classic["cosmic"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      //hmap_trkmom_genie_pm1_bs["cosmic"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, hmap_trkmom_genie_pm1_bs, "cosmic", fname_genie_pm1, wgts_genie_pm1);

      if (!isdata && _fill_bootstrap_genie) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_genie_multisim_bs, "cosmic", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_genie_multisim_bs, "cosmic", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_genie_multisim_bs, "cosmic", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_genie_multisim_bs, "cosmic", fname_genie_multisim, wgts_genie_multisim);
      if (!isdata && _fill_bootstrap_genie) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_genie_multisim_bs, "cosmic", fname_genie_multisim, wgts_genie_multisim);

      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_extra_syst_multisim_bs, "cosmic", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_extra_syst_multisim_bs, "cosmic", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_extra_syst_multisim_bs, "cosmic", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_extra_syst_multisim_bs, "cosmic", fname_extra_syst, wgts_extra_syst);
      if (!isdata && _fill_bootstrap_extra_syst) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_extra_syst_multisim_bs, "cosmic", fname_extra_syst, wgts_extra_syst);
      
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_flux_multisim_bs, "cosmic", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_flux_multisim_bs, "cosmic", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_flux_multisim_bs, "cosmic", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_flux_multisim_bs, "cosmic", fname_flux_multisim, wgts_flux_multisim);
      if (!isdata && _fill_bootstrap_flux) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_flux_multisim_bs, "cosmic", fname_flux_multisim, wgts_flux_multisim);

      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(0.5, event_weight, _event_histo_1d->hmap_onebin_mc_stat_multisim_bs, "cosmic", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkmom_mc_stat_multisim_bs, "cosmic", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), event_weight, _event_histo_1d->hmap_trkangle_mc_stat_multisim_bs, "cosmic", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_mc_stat_multisim_bs, "cosmic", fname_mc_stat_multisim, wgts_mc_stat_multisim);
      if (!isdata && _fill_bootstrap_mc_stat) FillBootstrap(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight, _event_histo->hmap_trktheta_trkmom_poly_mc_stat_multisim_bs, "cosmic", fname_mc_stat_multisim, wgts_mc_stat_multisim);

      hmap_trkphi["cosmic"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
      _event_histo_1d->hmap_trktheta["cosmic"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
      hmap_trktheta_classic["cosmic"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
      hmap_multpfp["cosmic"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
      hmap_multtracktol["cosmic"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
      _event_histo->hmap_trktheta_trkmom["cosmic"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      _event_histo->hmap_trktheta_trkmom_poly["cosmic"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      //std::cout << "Is a cosmic but is selected. event: " << t->event << std::endl;
      
      if (t->slc_origin_extra.at(scl_ll_max) == 0) {
        _event_histo_1d->hmap_onebin["cosmic_stopmu"]->Fill(0.5, event_weight);
        hmap_trklen["cosmic_stopmu"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trkmom["cosmic_stopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        hmap_trkmom_classic["cosmic_stopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        //hmap_trkmom_genie_pm1_bs["cosmic_stopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

        hmap_trkphi["cosmic_stopmu"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trktheta["cosmic_stopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_trktheta_classic["cosmic_stopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_multpfp["cosmic_stopmu"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
        hmap_multtracktol["cosmic_stopmu"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom["cosmic_stopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom_poly["cosmic_stopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      } else {
        _event_histo_1d->hmap_onebin["cosmic_nostopmu"]->Fill(0.5, event_weight);
        hmap_trklen["cosmic_nostopmu"]->Fill(t->slc_longesttrack_length.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trkmom["cosmic_nostopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        hmap_trkmom_classic["cosmic_nostopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        //hmap_trkmom_genie_pm1_bs["cosmic_nostopmu"]->Fill(t->slc_muoncandidate_mom_mcs.at(scl_ll_max), 1., wgts_genie_pm1);

        hmap_trkphi["cosmic_nostopmu"]->Fill(t->slc_longesttrack_phi.at(scl_ll_max), event_weight);
        _event_histo_1d->hmap_trktheta["cosmic_nostopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_trktheta_classic["cosmic_nostopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), event_weight);
        hmap_multpfp["cosmic_nostopmu"]->Fill(t->slc_mult_pfp.at(scl_ll_max), event_weight);
        hmap_multtracktol["cosmic_nostopmu"]->Fill(t->slc_mult_track_tolerance.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom["cosmic_nostopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
        _event_histo->hmap_trktheta_trkmom_poly["cosmic_nostopmu"]->Fill(t->slc_longesttrack_theta.at(scl_ll_max), t->slc_muoncandidate_mom_mcs.at(scl_ll_max), event_weight);
      }

      // Restore the event weight
      if (_scale_cosmics) event_weight /= _scale_factor_cosmic;
    }

    
  } // end of event loop
  
  
  // Save POT and number of events 
  h_pot->SetBinContent(1, totalPOT);
  h_nevts->SetBinContent(1, total_events);


  

  
  
  
  
  // ************************
  //
  //  Printing
  //
  // ************************
  std::cout << std::endl << std::endl;
  LOG_NORMAL() << "Number of simulated signal events is " << nsignal << std::endl;
  // LOG_NORMAL() << "Number of ALL simulated signal events is " << nsignal_all << std::endl;
  int sel_tot = signal_sel + bkg_anumu_sel + bkg_nue_sel + bkg_nc_sel + bkg_outfv_sel + bkg_cosmic_sel;
  LOG_NORMAL() << "Selected signal is " << signal_sel     << ", " << (double)signal_sel/(double)sel_tot * 100. << std::endl;
  LOG_NORMAL() << "Selected anumu is  " << bkg_anumu_sel  << ", " << (double)bkg_anumu_sel/(double)sel_tot * 100. << std::endl;
  LOG_NORMAL() << "Selected nue is    " << bkg_nue_sel    << ", " << (double)bkg_nue_sel/(double)sel_tot * 100. << std::endl;
  LOG_NORMAL() << "Selected nc is     " << bkg_nc_sel     << ", " << (double)bkg_nc_sel/(double)sel_tot * 100. << std::endl;
  LOG_NORMAL() << "Selected outfv is  " << bkg_outfv_sel  << ", " << (double)bkg_outfv_sel/(double)sel_tot * 100. << std::endl;
  LOG_NORMAL() << "Selected cosmic is " << bkg_cosmic_sel << ", " << (double)bkg_cosmic_sel/(double)sel_tot * 100. << std::endl << std::endl;
  
  LOG_NORMAL() << "Number of signal events where we selected a true muon " << real_muon_sel << std::endl;
  
  LOG_NORMAL() << "Efficiency: " << signal_sel/(double)nsignal << std::endl;
  LOG_NORMAL() << "Purity (does not include off-beam and dirt): " << signal_sel/(double)(signal_sel+bkg_anumu_sel+bkg_nue_sel+bkg_nc_sel+bkg_outfv_sel+bkg_cosmic_sel) << std::endl;
  LOG_NORMAL() << "Cosmic contamination: " << bkg_cosmic_sel/(double)(bkg_anumu_sel+bkg_nue_sel+bkg_nc_sel+bkg_outfv_sel+bkg_cosmic_sel) << std::endl;
  LOG_NORMAL() << "  of which crossing top: " << bkg_cosmic_top_sel/(double)bkg_cosmic_sel << std::endl;
  LOG_NORMAL() << "NC contamination: " << bkg_nc_sel/(double)(bkg_anumu_sel+bkg_nue_sel+bkg_nc_sel+bkg_outfv_sel+bkg_cosmic_sel) << std::endl;
  LOG_NORMAL() << "OUTFV contamination: " << bkg_outfv_sel/(double)(bkg_anumu_sel+bkg_nue_sel+bkg_nc_sel+bkg_outfv_sel+bkg_cosmic_sel) << std::endl << std::endl;
  
  LOG_NORMAL() << "Efficiency QE:  " << signal_sel_qe/(double)nsignal_qe   << " +- " << eff_uncertainty(signal_sel_qe, nsignal_qe) << std::endl;
  LOG_NORMAL() << "Efficiency RES: " << signal_sel_res/(double)nsignal_res << " +- " << eff_uncertainty(signal_sel_res, nsignal_res) << std::endl;
  LOG_NORMAL() << "Efficiency COH: " << signal_sel_coh/(double)nsignal_coh << " +- " << eff_uncertainty(signal_sel_coh, nsignal_coh) << std::endl;
  LOG_NORMAL() << "Efficiency DIS: " << signal_sel_dis/(double)nsignal_dis << " +- " << eff_uncertainty(signal_sel_dis, nsignal_dis) << std::endl;
  LOG_NORMAL() << "Efficiency MEC: " << signal_sel_mec/(double)nsignal_mec << " +- " << eff_uncertainty(signal_sel_mec, nsignal_mec) << std::endl << std::endl;

  LOG_NORMAL() << "Number of events with a flash in the beam spill: " << nEvtsWFlashInBeamSpill << std::endl;
  LOG_NORMAL() << "Number of events numu CC (all voulumes): " << nNumuCC << std::endl;
  LOG_NORMAL() << " Signal events that have a recon muon: " << nSignalWMuonReco << std::endl;
  LOG_NORMAL() << " Signal events that have a recon muon and a recon vertex 10 cm close in YZ plane: " << nSignalMuonRecoVtxOk << std::endl << std::endl;
  
  LOG_NORMAL() << "Number of signal events that were correctly flash-matched: " << nSignalFlashMatched << std::endl << std::endl;
  
  LOG_NORMAL() << "Number of neutrino origin slices in total: " << n_slc_nu_origin << std::endl;
    
  LOG_NORMAL() << "Number of simulated nue CC in FV (scaled to 6.6e20):                            " << nue_cc_fv                          * 6.6e20/totalPOT << std::endl;
  LOG_NORMAL() << "Number of selected nue CC in FV (as such) (scaled to 6.6e20):                   " << nue_cc_selected                    * 6.6e20/totalPOT << std::endl;
  LOG_NORMAL() << "Number of selected nue CC in FV (total) (scaled to 6.6e20):                     " << nue_cc_selected_total              * 6.6e20/totalPOT << std::endl;
  LOG_NORMAL() << "Number of selected nue CC in FV in [0.05, 1.5] GeV (total) (scaled to 6.6e20):  " << nue_cc_selected_total_energy_range * 6.6e20/totalPOT << std::endl;
  LOG_NORMAL() << "Number of selected nue in [0.05, 1.5] GeV (total) (scaled to 6.6e20):           " << nue_selected_total_energy_range    * 6.6e20/totalPOT << std::endl << std::endl << std::endl;
  
  LOG_NORMAL() << "Number of selected nue where an electron is selected (scaled to 6.6e20):        " << n_nue_electron                     * 6.6e20/totalPOT << std::endl;
  LOG_NORMAL() << "Number of selected nue where a proton is selected (scaled to 6.6e20):           " << n_nue_proton                       * 6.6e20/totalPOT << std::endl;
  LOG_NORMAL() << "Number of selected nue where a pion is selected (scaled to 6.6e20):             " << n_nue_pion                         * 6.6e20/totalPOT << std::endl;

  std::cout << std::endl;

  std::cout << std::endl;
  std::sort(run_numbers.begin(), run_numbers.end());
  LOG_NORMAL() << "First analysed run: " << run_numbers.at(0) << std::endl;
  LOG_NORMAL() << "Last analysed run: " << run_numbers.at(run_numbers.size()-1) << std::endl;


  // ************************
  //
  //  Plotting
  //
  // ************************
  
  TString temp2;
  
  TCanvas * canvas_efficiency = new TCanvas();
  TEfficiency* pEff2 = new TEfficiency(*h_eff_num,*h_eff_den);
  pEff2->SetTitle(";True Neutrino Energy [GeV];Efficiency");
  pEff2->SetLineColor(kGreen+3);
  pEff2->SetMarkerColor(kGreen+3);
  pEff2->SetMarkerStyle(20);
  pEff2->SetMarkerSize(0.5);
  pEff2->Draw("AP");
  gPad->Update();
  auto g = pEff2->GetPaintedGraph();
  g->SetMinimum(0);
  g->SetMaximum(1);
  gPad->Update();
  PlottingTools::DrawSimulationXSec();
  
  temp2 = "./output/efficiency";
  canvas_efficiency->SaveAs(temp2 + ".pdf");
  canvas_efficiency->SaveAs(temp2 + ".C","C");
  
  TCanvas * canvas_muon_reco_efficiency = new TCanvas();
  TEfficiency* pEff3 = new TEfficiency(*h_mueff_num,*h_mueff_den);
  pEff3->SetTitle(";True Muon Momentum [GeV];Reconstruction Efficiency");
  pEff3->Draw("AP");
  gPad->Update();
  g = pEff3->GetPaintedGraph();
  g->SetMinimum(0);
  g->SetMaximum(1);
  gPad->Update();
  PlottingTools::DrawSimulationXSec();
  
  temp2 = "./output/muon_reco_efficiency";
  canvas_muon_reco_efficiency->SaveAs(temp2 + ".pdf");
  canvas_muon_reco_efficiency->SaveAs(temp2 + ".C","C");

  TCanvas * canvas_muon_reco_efficiency_angle = new TCanvas();
  TEfficiency* pEff3_2 = new TEfficiency(*h_mueff_angle_num,*h_mueff_angle_den);
  pEff3_2->SetTitle(";True Muon cos(#theta);Reconstruction Efficiency");
  pEff3_2->Draw("AP");
  gPad->Update();
  g = pEff3_2->GetPaintedGraph();
  g->SetMinimum(0);
  g->SetMaximum(1);
  gPad->Update();
  PlottingTools::DrawSimulationXSec();
  
  temp2 = "./output/muon_reco_efficiency_angle";
  canvas_muon_reco_efficiency_angle->SaveAs(temp2 + ".pdf");
  canvas_muon_reco_efficiency_angle->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * canvas_efficiency_mumom = new TCanvas();
  TEfficiency* pEff4 = new TEfficiency(*_event_histo_1d->h_eff_mumom_num,*_event_histo_1d->h_eff_mumom_den);
  pEff4->SetTitle(";True Muon Momentum [GeV];Efficiency");
  pEff4->SetLineColor(kGreen+3);
  pEff4->SetMarkerColor(kGreen+3);
  pEff4->SetMarkerStyle(20);
  pEff4->SetMarkerSize(0.5);
  pEff4->Draw("AP");
  gPad->Update();
  g = pEff4->GetPaintedGraph();
  g->SetMinimum(0);
  g->SetMaximum(1);
  gPad->Update();
  PlottingTools::DrawSimulationXSec();

  temp2 = "./output/efficiency_mumom";
  canvas_efficiency_mumom->SaveAs(temp2 + ".pdf");
  canvas_efficiency_mumom->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * canvas_efficiency_muangle = new TCanvas();
  TEfficiency* pEff5 = new TEfficiency(*_event_histo_1d->h_eff_muangle_num,*_event_histo_1d->h_eff_muangle_den);
  pEff5->SetTitle(";True Muon cos(#theta);Efficiency");
  pEff5->SetLineColor(kGreen+3);
  pEff5->SetMarkerColor(kGreen+3);
  pEff5->SetMarkerStyle(20);
  pEff5->SetMarkerSize(0.5);
  pEff5->Draw("AP");
  gPad->Update();
  g = pEff5->GetPaintedGraph();
  g->SetMinimum(0);
  g->SetMaximum(1);
  gPad->Update();
  PlottingTools::DrawSimulationXSec();
  
  temp2 = "./output/efficiency_muangle";
  canvas_efficiency_muangle->SaveAs(temp2 + ".pdf");
  canvas_efficiency_muangle->SaveAs(temp2 + ".C","C");


  TCanvas * canvas_efficiency_muangle_mumom = new TCanvas();
  TEfficiency* pEff5_3 = new TEfficiency(*_event_histo->h_eff_muangle_mumom_num,*_event_histo->h_eff_muangle_mumom_den);
  pEff5_3->SetTitle("Efficiency;True Muon cos(#theta);True Muon Momentum [GeV]");
  pEff5_3->SetLineColor(kGreen+3);
  pEff5_3->SetMarkerColor(kGreen+3);
  pEff5_3->SetMarkerStyle(20);
  pEff5_3->SetMarkerSize(0.5);
  pEff5_3->Draw("colz");
  PlottingTools::DrawSimulationXSec();

  
  temp2 = "./output/efficiency_muangle_mumom";
  canvas_efficiency_muangle_mumom->SaveAs(temp2 + ".pdf");
  canvas_efficiency_muangle_mumom->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * canvas_efficiency_muphi = new TCanvas();
  TEfficiency* pEff5_2 = new TEfficiency(*h_eff_muphi_num,*h_eff_muphi_den);
  pEff5_2->SetTitle(";True Muon #phi angle;Efficiency");
  pEff5_2->SetLineColor(kGreen+3);
  pEff5_2->SetMarkerColor(kGreen+3);
  pEff5_2->SetMarkerStyle(20);
  pEff5_2->SetMarkerSize(0.5);
  pEff5_2->Draw("AP");
  gPad->Update();
  g = pEff5_2->GetPaintedGraph();
  g->SetMinimum(0);
  g->SetMaximum(1);
  gPad->Update();
  PlottingTools::DrawSimulationXSec();
  
  temp2 = "./output/efficiency_muphi";
  canvas_efficiency_muphi->SaveAs(temp2 + ".pdf");
  canvas_efficiency_muphi->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * canvas_efficiency_mult = new TCanvas();
  TEfficiency* pEff6 = new TEfficiency(*h_eff_mult_num,*h_eff_mult_den);
  pEff6->SetTitle(";True GENIE Particle Multiplicity;Efficiency");
  pEff6->SetLineColor(kGreen+3);
  pEff6->SetMarkerColor(kGreen+3);
  pEff6->SetMarkerStyle(20);
  pEff6->SetMarkerSize(0.5);
  pEff6->Draw("AP");
  gPad->Update();
  g = pEff6->GetPaintedGraph();
  g->SetMinimum(0);
  g->SetMaximum(1);
  gPad->Update();
  PlottingTools::DrawSimulationXSec();
  
  temp2 = "./output/efficiency_mult";
  canvas_efficiency_mult->SaveAs(temp2 + ".pdf");
  canvas_efficiency_mult->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * canvas_efficiency_mult_ch = new TCanvas();
  TEfficiency* pEff7 = new TEfficiency(*h_eff_mult_ch_num,*h_eff_mult_ch_den);
  pEff7->SetTitle(";True GENIE Charged Particle Multiplicity;Efficiency");
  pEff7->SetLineColor(kGreen+3);
  pEff7->SetMarkerColor(kGreen+3);
  pEff7->SetMarkerStyle(20);
  pEff7->SetMarkerSize(0.5);
  pEff7->Draw("AP");
  gPad->Update();
  g = pEff7->GetPaintedGraph();
  g->SetMinimum(0);
  g->SetMaximum(1);
  gPad->Update();
  PlottingTools::DrawSimulationXSec();
  
  temp2 = "./output/efficiency_mult_ch";
  canvas_efficiency_mult_ch->SaveAs(temp2 + ".pdf");
  canvas_efficiency_mult_ch->SaveAs(temp2 + ".C","C");


  TCanvas * canvas_efficiency_mode = new TCanvas();
  TEfficiency* pEff_qe = new TEfficiency(*h_eff_qe_num,*h_eff_qe_den);
  pEff_qe->SetTitle(";True Neutrino Energy [GeV];Efficiency");
  pEff_qe->SetLineColor(kGreen+2); 
  pEff_qe->SetLineWidth(2);
  pEff_qe->SetMarkerColor(kGreen+2);
  pEff_qe->SetMarkerStyle(20);
  pEff_qe->SetMarkerSize(0.5);
  pEff_qe->Draw("ALP");
  gPad->Update();
  auto g_qe = pEff_qe->GetPaintedGraph();
  g_qe->SetMinimum(0);
  g_qe->SetMaximum(1);
  gPad->Update();

  TEfficiency* pEff_res = new TEfficiency(*h_eff_res_num,*h_eff_res_den);
  pEff_res->SetLineColor(kRed+1);
  pEff_res->SetMarkerColor(kRed+1);
  pEff_res->SetLineWidth(2);
  pEff_res->SetMarkerStyle(20);
  pEff_res->SetMarkerSize(0.5);
  pEff_res->Draw("LP same");

  TEfficiency* pEff_dis = new TEfficiency(*h_eff_dis_num,*h_eff_dis_den);
  pEff_dis->SetLineColor(kBlue+1);
  pEff_dis->SetMarkerColor(kBlue+1);
  pEff_dis->SetLineWidth(2);
  pEff_dis->SetMarkerStyle(20);
  pEff_dis->SetMarkerSize(0.5);
  pEff_dis->Draw("LP same");

  TEfficiency* pEff_coh = new TEfficiency(*h_eff_coh_num,*h_eff_coh_den);
  pEff_coh->SetLineColor(kOrange-3);
  pEff_coh->SetMarkerColor(kOrange-3);
  pEff_coh->SetLineWidth(2);
  pEff_coh->SetMarkerStyle(20);
  pEff_coh->SetMarkerSize(0.5);
  //pEff_coh->Draw("LP same");

  TEfficiency* pEff_mec = new TEfficiency(*h_eff_mec_num,*h_eff_mec_den);
  pEff_mec->SetLineColor(kMagenta+1); 
  pEff_mec->SetMarkerColor(kMagenta+1);
  pEff_mec->SetLineWidth(2);
  pEff_mec->SetMarkerStyle(20);
  pEff_mec->SetMarkerSize(0.5);
  pEff_mec->Draw("LP same");

  TLegend* leg_mode = new TLegend(0.6475645,0.1368421,0.8968481,0.3368421,NULL,"brNDC");
  leg_mode->AddEntry(pEff_qe,"GENIE QE","lep");
  leg_mode->AddEntry(pEff_res,"GENIE RES","lep");  
  leg_mode->AddEntry(pEff_dis,"GENIE DIS","lep");  
  // leg_mode->AddEntry(pEff_coh,"GENIE COH","lep");  
  leg_mode->AddEntry(pEff_mec,"GENIE MEC","lep");  
  leg_mode->Draw();

  PlottingTools::DrawSimulation();

  temp2 = "./output/efficiency_mode";
  canvas_efficiency_mode->SaveAs(temp2 + ".pdf");
  canvas_efficiency_mode->SaveAs(temp2 + ".C","C");

  
  
  TCanvas * canvas_chi2 = new TCanvas();
  h_chi2->Draw("histo");
  
  temp2 = "./output/chi2_mult";
  canvas_chi2->SaveAs(temp2 + ".pdf");
  canvas_chi2->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * canvas_flsTime = new TCanvas();
  h_flsTime->Draw("histo");
  
  temp2 = "./output/flsTime";
  canvas_flsTime->SaveAs(temp2 + ".pdf");
  canvas_flsTime->SaveAs(temp2 + ".C","C");
  
  new TCanvas();
  h_nslices->Draw("histo");
  
  TCanvas * canvas_vtx_resolution = new TCanvas();
  h_vtx_resolution->Draw("histo");

  temp2 = "./output/vtx_resolution";
  canvas_vtx_resolution->SaveAs(temp2 + ".pdf");
  canvas_vtx_resolution->SaveAs(temp2 + ".C","C");
  
  new TCanvas();
  h_frac_diff->Draw("colz");
  
  new TCanvas();
  h_frac_diff_others->Draw("colz");
  
  // PE spec
  TCanvas * canvas_fm_pe_comparison = new TCanvas();
  TGraph* gr = new TGraph(32,hypo_spec_x,hypo_spec_y);
  TGraph* gr2 = new TGraph(32,meas_spec_x,meas_spec_y);
  TGraph* gr3 = new TGraph(32,numc_spec_x,numc_spec_y);
  gr->SetLineColor(kGreen+2);
  gr->SetLineWidth(2);
  gr->SetMarkerColor(kGreen+2);
  gr->SetMarkerSize(1.2);
  gr->SetMarkerStyle(20);
  gr->SetTitle("");
  gr->GetXaxis()->SetTitle("PMT ID");
  gr->GetYaxis()->SetTitle("PE Count");
  gr->Draw("ALP");
  gr2->SetLineColor(kBlue+2);
  gr2->SetLineWidth(2);
  gr2->SetMarkerColor(kBlue+2);
  gr2->SetMarkerSize(1.2);
  gr2->SetMarkerStyle(20);
  gr2->SetTitle("");
  gr2->GetXaxis()->SetTitle("PMT ID");
  gr2->GetYaxis()->SetTitle("PE Count");
  gr2->Draw("LP");
  gr3->SetLineColor(kRed+2);
  gr3->SetLineWidth(2);
  gr3->SetMarkerColor(kRed+2);
  gr3->SetMarkerSize(1.2);
  gr3->SetMarkerStyle(20);
  gr3->SetTitle("");
  gr3->GetXaxis()->SetTitle("PMT ID");
  gr3->GetYaxis()->SetTitle("PE Count");
  //gr3->Draw("LP");
  TLegend* leg = new TLegend(0.1,0.7,0.48,0.9);
  leg->AddEntry(gr,"Hypo flash","l");
  leg->AddEntry(gr2,"Reco flash","l");
  //leg->AddEntry(gr3,"Neutrino MCFlash","l");
  leg->Draw();
  temp2 = "./output/fm_pe_comparison";
  canvas_fm_pe_comparison->SaveAs(temp2 + ".pdf");
  canvas_fm_pe_comparison->SaveAs(temp2 + ".C","C");

  
  TCanvas * canvas_vtxcheck = new TCanvas();
  h_vtxcheck_angle_good->Scale(1./h_vtxcheck_angle_good->Integral());
  h_vtxcheck_angle_bad->Scale(1./h_vtxcheck_angle_bad->Integral());
  h_vtxcheck_angle_good->Draw("histo");
  h_vtxcheck_angle_bad->Draw("histo same");
  h_vtxcheck_angle_bad->SetLineColor(kRed);

  TLegend* vtx_leg = new TLegend(0.1,0.7,0.48,0.9);
  vtx_leg->AddEntry(h_vtxcheck_angle_good,"Signal","l");
  vtx_leg->AddEntry(h_vtxcheck_angle_bad,"Background","l");
  vtx_leg->Draw();
  
  temp2 = "./output/vtxcheck";
  canvas_vtxcheck->SaveAs(temp2 + ".pdf");
  canvas_vtxcheck->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * canvas_mu_eff_mom = new TCanvas();
  h_mu_eff_mom->Draw("colz");
  
  temp2 = "./output/mu_eff_mom";
  canvas_mu_eff_mom->SaveAs(temp2 + ".pdf");
  canvas_mu_eff_mom->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * canvas_mu_eff_mom_sel = new TCanvas();
  h_mu_eff_mom_sel->Draw("colz");
  
  temp2 = "./output/mu_eff_mom_sel";
  canvas_mu_eff_mom_sel->SaveAs(temp2 + ".pdf");
  canvas_mu_eff_mom_sel->SaveAs(temp2 + ".C","C");

  
  new TCanvas();
  //h_muon_track_pur->Draw();
  h_mu_pur_mom->Draw("colz");
  
  new TCanvas();
  h_mumom_nue->Draw("colz");
  
  new TCanvas();
  h_acpt_tagged->Draw("histo");
  
  new TCanvas();
  h_xdiff->Draw("histo");
  h_xdiff_others->Draw("histo same");
  h_xdiff_others->SetLineColor(kRed);
  //TCanvas *c16 = new TCanvas();
  //h_xdiff_others->Draw("histo");
  
  new TCanvas();
  h_zdiff->Draw("histo");
  h_zdiff_others->Draw("histo same");
  h_zdiff_others->SetLineColor(kRed);
  
  
  new TCanvas();
  h_slice_origin->Draw("histo");
  
  new TCanvas();
  h_slice_npfp->DrawNormalized("histo");
  h_slice_npfp_others->DrawNormalized("histo same");
  h_slice_npfp_others->SetLineColor(kRed);
  
  new TCanvas();
  h_slice_ntrack->DrawNormalized("histo");
  h_slice_ntrack_others->DrawNormalized("histo same");
  h_slice_ntrack_others->SetLineColor(kRed);
  
  new TCanvas();
  h_fm_score->Draw("histo");
  h_fm_score_others->Draw("histo same");
  h_fm_score_others->SetLineColor(kRed);
  
  new TCanvas();
  h_n_slc_flsmatch->Draw("histo");
  
  new TCanvas();
  h_fm_score_pe->Draw("colz");
  
  
  TCanvas * final1 = new TCanvas();
  THStack *hs_trklen = new THStack("hs_trklen",";Candidate Track Length [cm]; Selected Events");
  if (_makePlots) PlottingTools::DrawTHStack(hs_trklen, pot_scaling, _breakdownPlots, hmap_trklen);
  
  //
  // Construct legend
  // used basically for all plots
  //
  TLegend* leg2;
  if (_breakdownPlots){
    leg2 = new TLegend(0.56,0.37,0.82,0.82,NULL,"brNDC");
  } else {
    leg2 = new TLegend(0.56,0.54,0.82,0.82,NULL,"brNDC");
  }
  std::stringstream sstm;
  // numu
  if (_breakdownPlots) {
  leg2->AddEntry(hmap_trklen["signal_stopmu"],"#nu_{#mu} CC (stopping #mu)","f");
  leg2->AddEntry(hmap_trklen["signal_nostopmu"],"#nu_{#mu} CC (other)","f");
  } else {
    sstm << "#nu_{#mu} CC (signal), " << std::setprecision(2)  << hmap_trklen["signal"]->Integral() / hmap_trklen["total"]->Integral()*100. << "%";
    leg2->AddEntry(hmap_trklen["signal"],sstm.str().c_str(),"f");
    sstm.str("");
  }
  
  // nue
  sstm << "#nu_{e}, #bar{#nu}_{e} CC, " << std::setprecision(2)  << hmap_trklen["nue"]->Integral() / hmap_trklen["total"]->Integral()*100. << "%";
  leg2->AddEntry(hmap_trklen["nue"],sstm.str().c_str(),"f");
  sstm.str("");
  
  // anumu
  sstm << "#bar{#nu}_{#mu} CC, " << std::setprecision(2)  << hmap_trklen["anumu"]->Integral() / hmap_trklen["total"]->Integral()*100. << "%";
  leg2->AddEntry(hmap_trklen["anumu"],sstm.str().c_str(),"f");
  sstm.str("");
  
  // nc, outfv, cosmic
  if (_breakdownPlots) {
  leg2->AddEntry(hmap_trklen["nc_other"],"NC (other)","f");
  leg2->AddEntry(hmap_trklen["nc_pion"],"NC (pion)","f");
  leg2->AddEntry(hmap_trklen["nc_proton"],"NC (proton)","f");
  leg2->AddEntry(hmap_trklen["outfv_stopmu"],"OUTFV (stopping #mu)","f");
  leg2->AddEntry(hmap_trklen["outfv_nostopmu"],"OUTFV (other)","f");
  leg2->AddEntry(hmap_trklen["cosmic_stopmu"],"Cosmic (stopping #mu)","f");
  leg2->AddEntry(hmap_trklen["cosmic_nostopmu"],"Cosmic (other)","f");
  } else {
    sstm << "NC, " << std::setprecision(2)  << hmap_trklen["nc"]->Integral() / hmap_trklen["total"]->Integral()*100. << "%";
    leg2->AddEntry(hmap_trklen["nc"],sstm.str().c_str(),"f");
    sstm.str("");
    
    sstm << "OUTFV, " << std::setprecision(2)  << hmap_trklen["outfv"]->Integral() / hmap_trklen["total"]->Integral()*100. << "%";
    leg2->AddEntry(hmap_trklen["outfv"],sstm.str().c_str(),"f");
    sstm.str("");
    
    sstm << "Cosmic, " << std::setprecision(2)  << hmap_trklen["cosmic"]->Integral() / hmap_trklen["total"]->Integral()*100. << "%";
    leg2->AddEntry(hmap_trklen["cosmic"],sstm.str().c_str(),"f");
    sstm.str("");
  }
  leg2->AddEntry(hmap_trklen["total"],"MC Stat Unc.","f");
  leg2->Draw();
  DrawPOT2(totalPOT);
  
  temp2 = "./output/trklen";
  final1->SaveAs(temp2 + ".pdf");
  final1->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * final1_1 = new TCanvas();
  THStack *hs_trkmom = new THStack("hs_trkmom",";Reconstructed Momentum [GeV]; Selected Events");
  if (_makePlots) PlottingTools::DrawTHStack(hs_trkmom, pot_scaling, _breakdownPlots, _event_histo_1d->hmap_trkmom);
  leg2->Draw();
  DrawPOT2(totalPOT);
  
  temp2 = "./output/trkmom";
  final1_1->SaveAs(temp2 + ".pdf");
  final1_1->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * final2 = new TCanvas();
  THStack *hs_trkphi = new THStack("hs_trkphi",";Candidate Track #phi; Selected Events");
  if (_makePlots) PlottingTools::DrawTHStack(hs_trkphi, pot_scaling, _breakdownPlots, hmap_trkphi);
  leg2->Draw();
  DrawPOT2(totalPOT);
  
  temp2 = "./output/trkphi";
  final2->SaveAs(temp2 + ".pdf");
  final2->SaveAs(temp2 + ".C","C");
  
  
  
  TCanvas * final3 = new TCanvas();
  THStack *hs_trktheta = new THStack("hs_trktheta",";Candidate Track cos(#theta); Selected Events");
  if (_makePlots) PlottingTools::DrawTHStack(hs_trktheta, pot_scaling, _breakdownPlots, _event_histo_1d->hmap_trktheta);
  leg2->Draw();
  DrawPOT2(totalPOT);
  
  temp2 = "./output/trktheta";
  final3->SaveAs(temp2 + ".pdf");
  final3->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * final4 = new TCanvas();
  THStack *hs_multpfp = new THStack("hs_multpfp",";PFP Multiplicity; Selected Events");
  if (_makePlots) PlottingTools::DrawTHStack(hs_multpfp, pot_scaling, _breakdownPlots, hmap_multpfp);
  leg2->Draw();
  DrawPOT2(totalPOT);
  
  temp2 = "./output/multpfp";
  final4->SaveAs(temp2 + ".pdf");
  final4->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * final5 = new TCanvas();
  THStack *hs_multtracktol = new THStack("hs_multtracktol",";Track Multiplicity (5 cm); Selected Events");
  if (_makePlots) PlottingTools::DrawTHStack(hs_multtracktol, pot_scaling, _breakdownPlots, hmap_multtracktol);
  leg2->Draw();
  DrawPOT2(totalPOT);
  
  temp2 = "./output/multtracktol";
  final5->SaveAs(temp2 + ".pdf");
  final5->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * canvas_dqdx = new TCanvas();
  THStack *hs_dqdx_trunc = new THStack("hs_dqdx_trunc",";Candidate Track <dQ/dx>_{trunc};Selected Events");
  if (_makePlots) PlottingTools::DrawTHStack3(hs_dqdx_trunc, pot_scaling, _breakdownPlots, hmap_dqdx_trunc);
  
  temp2 = "./output/dqdx_trunc";
  canvas_dqdx->SaveAs(temp2 + ".pdf");
  canvas_dqdx->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * canvas_dqdx_length = new TCanvas();
  h_dqdx_trunc_length_muon->Draw("BOX");
  h_dqdx_trunc_length_muon->SetLineColor(kRed+2);
  h_dqdx_trunc_length_proton->Draw("BOX same");
  h_dqdx_trunc_length_proton->SetLineColor(kBlue+2);

  temp2 = "./output/dqdx_trunc_length";
  canvas_dqdx_length->SaveAs(temp2 + ".pdf");
  canvas_dqdx_length->SaveAs(temp2 + ".C","C");
  
  
  TCanvas * canvas_dqdx_length_muon = new TCanvas();
  h_dqdx_trunc_length_muon->Draw("colz");
  
  temp2 = "./output/dqdx_trunc_length_muon";
  canvas_dqdx_length_muon->SaveAs(temp2 + ".pdf");
  canvas_dqdx_length_muon->SaveAs(temp2 + ".C","C");

  
  TCanvas * canvas_dqdx_length_proton = new TCanvas();
  h_dqdx_trunc_length_proton->Draw("colz");
  
  temp2 = "./output/dqdx_trunc_length_proton";
  canvas_dqdx_length_proton->SaveAs(temp2 + ".pdf");
  canvas_dqdx_length_proton->SaveAs(temp2 + ".C","C");

  
  
  
  TCanvas * canvas_deltall_cosmic_stop = new TCanvas();
  h_deltall_cosmic_stop->Draw();
  
  temp2 = "./output/deltall_cosmic_stop";
  canvas_deltall_cosmic_stop->SaveAs(temp2 + ".pdf");
  canvas_deltall_cosmic_stop->SaveAs(temp2 + ".C","C");
  
  TCanvas * canvas_deltall_cosmic_nostop = new TCanvas();
  h_deltall_cosmic_nostop->Draw();
  
  temp2 = "./output/deltall_cosmic_nostop";
  canvas_deltall_cosmic_nostop->SaveAs(temp2 + ".pdf");
  canvas_deltall_cosmic_nostop->SaveAs(temp2 + ".C","C");

  TCanvas * canvas_deltall_nu = new TCanvas();
  h_deltall_nu->Draw();
  
  temp2 = "./output/deltall_nu";
  canvas_deltall_nu->SaveAs(temp2 + ".pdf");
  canvas_deltall_nu->SaveAs(temp2 + ".C","C");

  
  
  
  TCanvas * canvas_deltall_length_cosmic_stop = new TCanvas();
  h_deltall_length_cosmic_stop->Draw("colz");
  
  temp2 = "./output/deltall_cosmic_stop_length";
  canvas_deltall_length_cosmic_stop->SaveAs(temp2 + ".pdf");
  canvas_deltall_length_cosmic_stop->SaveAs(temp2 + ".C","C");
  
  TCanvas * canvas_deltall_length_cosmic_nostop = new TCanvas();
  h_deltall_length_cosmic_nostop->Draw("colz");
  
  temp2 = "./output/deltall_cosmic_nostop_length";
  canvas_deltall_length_cosmic_nostop->SaveAs(temp2 + ".pdf");
  canvas_deltall_length_cosmic_nostop->SaveAs(temp2 + ".C","C");
  
  TCanvas * canvas_deltall_length_nu = new TCanvas();
  h_deltall_length_nu->Draw("colz");
  
  temp2 = "./output/deltall_nu_length";
  canvas_deltall_length_nu->SaveAs(temp2 + ".pdf");
  canvas_deltall_length_nu->SaveAs(temp2 + ".C","C");
  
  
  
  
  
  TCanvas * canvas_nue_flash = new TCanvas();
  h_true_nu_eng_beforesel->SetLineColor(kBlue+2);
  h_true_nu_eng_beforesel->Draw();
  h_true_nu_eng_afterflash->SetLineColor(kRed+2);
  h_true_nu_eng_afterflash->Draw("same");
  h_true_nu_eng_aftersel->SetLineColor(kGreen+2);
  h_true_nu_eng_aftersel->Draw("same");
  TLegend* l01 = new TLegend(0.1,0.7,0.48,0.9);
  l01->AddEntry(h_true_nu_eng_beforesel,"Generated CC #nu_{#mu} events in FV","l");
  l01->AddEntry(h_true_nu_eng_afterflash,"CC #nu_{#mu} Passing Flash Finding","l");
  l01->AddEntry(h_true_nu_eng_aftersel,"Selected CC #nu_{#mu} events","l");
  l01->Draw();
  temp2 = "./output/nue_flash";
  canvas_nue_flash->SaveAs(temp2 + ".pdf");
  canvas_nue_flash->SaveAs(temp2 + ".C","C");


  TCanvas * canvas_nue_selected = new TCanvas();
  h_nue_selected_energy->Scale(6.6e20/totalPOT);
  h_nue_selected_energy->Draw("histo");
  DrawPOT2(totalPOT, 6.6e20);
  temp2 = "./output/nue_selected_contamination";
  canvas_nue_selected->SaveAs(temp2 + ".pdf");
  canvas_nue_selected->SaveAs(temp2 + ".C","C");



  // Efficiency for every cut

  TH1D * selected_percut = new TH1D("selected_percut", "selected_percut", 9, 0, 9);
  TH1D * selected_signal_percut = new TH1D("selected_signal_percut", "selected_percut", 9, 0, 9);
  // TH1D * generated_percut = new TH1D("generated_percut", "generated_percut", 8, 0, 7);
  TH1D * generated_signal_percut = new TH1D("generated_signal_percut", "generated_percut", 9, 0, 9);

  double pot_scale = 35388924/72299264;
  selected_percut->SetBinContent(1, selected_events_percut["initial"] * pot_scale); // + 1280310);
  selected_percut->SetBinContent(2, selected_events_percut["beamflash"] * pot_scale); // + 821708);
  selected_percut->SetBinContent(3, selected_events_percut["flash_match"] * pot_scale); // + 194732);
  selected_percut->SetBinContent(4, selected_events_percut["flash_match_deltax"] * pot_scale); // + 154544);
  selected_percut->SetBinContent(5, selected_events_percut["flash_match_deltaz"] * pot_scale); // + 106802);
  selected_percut->SetBinContent(6, selected_events_percut["quality"] * pot_scale); // + 76023);
  selected_percut->SetBinContent(7, selected_events_percut["mcs_length_quality"] * pot_scale); // + 72577);
  selected_percut->SetBinContent(8, selected_events_percut["mip_consistency"] * pot_scale); // + 69692);
  selected_percut->SetBinContent(9, selected_events_percut["fiducial_volume"] * pot_scale); // + 22657);

  selected_signal_percut->SetBinContent(1, selected_signal_events_percut["initial"]);
  selected_signal_percut->SetBinContent(2, selected_signal_events_percut["beamflash"]);
  selected_signal_percut->SetBinContent(3, selected_signal_events_percut["flash_match"]);
  selected_signal_percut->SetBinContent(4, selected_signal_events_percut["flash_match_deltax"]);
  selected_signal_percut->SetBinContent(5, selected_signal_events_percut["flash_match_deltaz"]);
  selected_signal_percut->SetBinContent(6, selected_signal_events_percut["quality"]);
  selected_signal_percut->SetBinContent(7, selected_signal_events_percut["mcs_length_quality"]);
  selected_signal_percut->SetBinContent(8, selected_signal_events_percut["mip_consistency"]);
  selected_signal_percut->SetBinContent(9, selected_signal_events_percut["fiducial_volume"]);

  std::vector<std::string> cut_names = {"initial", "beamflash", "flashmatch", "flashmatchdeltax", "flashmatchdeltaz", "quality", "mcslengthquality", "mipconsistency", "fiducialvolume"};

  for (int i = 0; i < 9; i++) {
    std::cout << cut_names.at(i) << " & " << selected_signal_percut->GetBinContent(i+1) 
       << " => " << selected_percut->GetBinContent(i+1) 
              << " & " << selected_signal_percut->GetBinContent(i+1)/selected_signal_percut->GetBinContent(1) * 100 
              << " & " << selected_signal_percut->GetBinContent(i+1)/selected_signal_percut->GetBinContent(i) * 100  << "\\\\" << std::endl;
    generated_signal_percut->SetBinContent(i+1, (double)nsignal);
    //generated_percut->SetBinContent(i+1, (double)sel_tot);
  }

  TCanvas * canvas_eff_pur_graph_percut = new TCanvas();

  canvas_eff_pur_graph_percut->SetLeftMargin(0.05157593);
  canvas_eff_pur_graph_percut->SetRightMargin(0.1475645);
  canvas_eff_pur_graph_percut->SetTopMargin(0.04210526);
  canvas_eff_pur_graph_percut->SetBottomMargin(0.1578947);

  TH1F *h = new TH1F("h","",9, 0, 9);
  h->SetMaximum(1);
  h->GetXaxis()->SetBinLabel(1,"Initial");
  h->GetXaxis()->SetBinLabel(2,"Beam Flash");
  h->GetXaxis()->SetBinLabel(3,"Flash Match");
  h->GetXaxis()->SetBinLabel(4,"Flash Match #Deltax");
  h->GetXaxis()->SetBinLabel(5,"Flash Match #Deltaz");
  h->GetXaxis()->SetBinLabel(6,"Track Quality");
  h->GetXaxis()->SetBinLabel(7,"MCS-Length Quality");
  h->GetXaxis()->SetBinLabel(8,"MIP Consistency");
  h->GetXaxis()->SetBinLabel(9,"Fiducial Volume");

  h->GetXaxis()->SetLabelOffset(0.009);
  h->GetXaxis()->SetLabelSize(0.06);

  h->Draw();

  TEfficiency* pEff_percut = new TEfficiency(*selected_signal_percut,*generated_signal_percut);
  pEff_percut->SetTitle("EfficiencyPerCut;Cut index;Efficiency");
  pEff_percut->SetLineColor(kGreen+3);
  pEff_percut->SetMarkerColor(kGreen+3);
  pEff_percut->SetMarkerStyle(20);
  pEff_percut->SetMarkerSize(0.6);
  TGraphAsymmErrors * pEff_percut_graph = pEff_percut->CreateGraph();
  for (int i = 0; i < 9; i++) {
    pEff_percut_graph->SetPointEXhigh(i, 0.);
    pEff_percut_graph->SetPointEXlow(i, 0.);
  }
  auto axis = pEff_percut_graph->GetYaxis();
  axis->SetLimits(0.,1.); 

  pEff_percut_graph->GetHistogram()->GetXaxis()->SetBinLabel(1,"Initial");
  pEff_percut_graph->GetHistogram()->GetXaxis()->SetBinLabel(2,"BeamFlash");
  pEff_percut_graph->GetHistogram()->GetXaxis()->SetBinLabel(3,"FlashMatch");
  pEff_percut_graph->GetHistogram()->GetXaxis()->SetBinLabel(4,"FlashMatch#Deltax");
  pEff_percut_graph->GetHistogram()->GetXaxis()->SetBinLabel(5,"FlashMatch#Deltaz");
  pEff_percut_graph->GetHistogram()->GetXaxis()->SetBinLabel(6,"TrackQuality");
  pEff_percut_graph->GetHistogram()->GetXaxis()->SetBinLabel(7,"MCS-LengthQuality");
  pEff_percut_graph->GetHistogram()->GetXaxis()->SetBinLabel(8,"MIPConsistency");
  pEff_percut_graph->GetHistogram()->GetXaxis()->SetBinLabel(9,"FiducialVolume");



  // pEff_percut_graph->GetXaxis()->SetLabelSize(0.07);
  pEff_percut_graph->Draw("PL");

  

  TEfficiency* pPur_percut = new TEfficiency(*selected_signal_percut,*selected_percut);
  pPur_percut->SetTitle("PurityPerCut;Cut index;Purity");
  pPur_percut->SetLineColor(kRed+3);
  pPur_percut->SetMarkerColor(kRed+3);
  pPur_percut->SetMarkerStyle(20);
  pPur_percut->SetMarkerSize(0.6);
  TGraphAsymmErrors * pPur_percut_graph = pPur_percut->CreateGraph();
  for (int i = 0; i < 9; i++) {
    pPur_percut_graph->SetPointEXhigh(i, 0.);
    pPur_percut_graph->SetPointEXlow(i, 0.);
  }

  pPur_percut_graph->Draw("PL");

  TLegend* l = new TLegend(0.4842407,0.8168421,0.777937,0.9221053,NULL,"brNDC");
  l->AddEntry(pEff_percut_graph,"Efficiency");
  l->AddEntry(pPur_percut_graph,"Purity");
  //leg->AddEntry(gr3,"Neutrino MCFlash","l");
  
  l->Draw();

  // PlottingTools::DrawSimulationXSec();

  TLatex* prelim = new TLatex(0.8524355,0.9810526, "MicroBooNE Simulation, Preliminary");
  prelim->SetTextFont(62);
  prelim->SetTextColor(kGray+2);
  prelim->SetNDC();
  prelim->SetTextSize(1/30.);
  prelim->SetTextAlign(32);
  // prelim->SetTextSize(0.04631579);
  prelim->Draw();

  temp2 = "./output/eff_pur_graph_percut";
  canvas_eff_pur_graph_percut->SaveAs(temp2 + ".pdf");
  canvas_eff_pur_graph_percut->SaveAs(temp2 + ".C","C");

  
  
  //
  // Save on file
  //

  LOG_NORMAL() << "Saving to file." << std::endl;
  
  file_out->cd();
  for (auto iter : hmap_trklen) {
    iter.second->Write();
  }
  h_pot->Write();
  h_nevts->Write();

  pEff4->Write();
  pEff5->Write();
  pEff5_3->Write();
  h_truth_xsec_mumom->Write();
  h_truth_xsec_muangle->Write();
  
  pEff_percut->Write();
  pPur_percut->Write();

  file_out->WriteObject(&hmap_trklen, "hmap_trklen");
  file_out->WriteObject(&hmap_trkmom_classic, "hmap_trkmom_classic");

  file_out->WriteObject(&hmap_trktheta_classic, "hmap_trktheta_classic");
  file_out->WriteObject(&hmap_trkphi, "hmap_trkphi");
  file_out->WriteObject(&hmap_multpfp, "hmap_multpfp");
  file_out->WriteObject(&hmap_multtracktol, "hmap_multtracktol");

  // Mc truth stacked in interaction type
  file_out->WriteObject(&hmap_mctruth_nuenergy, "hmap_mctruth_nuenergy");
  file_out->WriteObject(&hmap_mctruth_mumom, "hmap_mctruth_mumom");
  file_out->WriteObject(&hmap_mctruth_mucostheta, "hmap_mctruth_mucostheta");
  file_out->WriteObject(&hmap_mctruth_muphi, "hmap_mctruth_muphi");
  file_out->WriteObject(&hmap_mctruth_chargedmult, "hmap_mctruth_chargedmult");
  file_out->WriteObject(&hmap_mctruth_mucostheta_mumom, "hmap_mctruth_mucostheta_mumom");
  file_out->WriteObject(&hmap_mctruth_q0_q3, "hmap_mctruth_q0_q3");
  file_out->WriteObject(&hmap_mctruth_nuenergy_gen, "hmap_mctruth_nuenergy_gen");
  file_out->WriteObject(&hmap_mctruth_mumom_gen, "hmap_mctruth_mumom_gen");
  file_out->WriteObject(&hmap_mctruth_mucostheta_gen, "hmap_mctruth_mucostheta_gen");
  file_out->WriteObject(&hmap_mctruth_muphi_gen, "hmap_mctruth_muphi_gen");
  file_out->WriteObject(&hmap_mctruth_chargedmult_gen, "hmap_mctruth_chargedmult_gen");
  file_out->WriteObject(&hmap_mctruth_mucostheta_mumom_gen, "hmap_mctruth_mucostheta_mumom_gen");
  file_out->WriteObject(&hmap_mctruth_q0_q3_gen, "hmap_mctruth_q0_q3_gen");




  // Efficiency - GENIE pm1sigma
  file_out->WriteObject(&bs_genie_pm1_eff_mumom_num, "bs_genie_pm1_eff_mumom_num");
  file_out->WriteObject(&bs_genie_pm1_eff_mumom_den, "bs_genie_pm1_eff_mumom_den");

  // All MC Histo - GENIE pm1sigma
  file_out->WriteObject(&hmap_trkmom_genie_pm1_bs, "hmap_trkmom_genie_pm1_bs");

  // Reco-True - GENIE pm1sigma
  file_out->WriteObject(&bs_genie_pm1_true_reco_mom, "bs_genie_pm1_true_reco_mom");

 



  file_out->WriteObject(&hmap_vtxcheck_angle, "hmap_vtxcheck_angle");
  file_out->WriteObject(&hmap_residuals_std, "hmap_residuals_std");
  file_out->WriteObject(&hmap_residuals_mean, "hmap_residuals_mean");
  file_out->WriteObject(&hmap_perc_used_hits, "hmap_perc_used_hits");
  file_out->WriteObject(&hmap_mom_mcs_length, "hmap_mom_mcs_length");

  file_out->WriteObject(&hmap_xdiff_b, "hmap_xdiff_b");
  file_out->WriteObject(&hmap_zdiff_b, "hmap_zdiff_b");
  file_out->WriteObject(&hmap_xdiff, "hmap_xdiff");
  file_out->WriteObject(&hmap_zdiff, "hmap_zdiff");
  file_out->WriteObject(&hmap_pediff, "hmap_pediff");
  
  file_out->WriteObject(&hmap_vtxx_b, "hmap_vtxx_b");
  file_out->WriteObject(&hmap_vtxx, "hmap_vtxx");
  file_out->WriteObject(&hmap_vtxy, "hmap_vtxy");
  file_out->WriteObject(&hmap_vtxz, "hmap_vtxz");
  h_vtx_xz->Write();
  h_vtx_xy->Write();
  file_out->WriteObject(&hmap_vtxz_upborder, "hmap_vtxz_upborder");
  file_out->WriteObject(&hmap_vtxx_upborder, "hmap_vtxx_upborder");
  
  file_out->WriteObject(&hmap_dqdx_trunc, "hmap_dqdx_trunc");
  h_dqdx_trunc_length->Write();
  
  file_out->WriteObject(&hmap_ntpcobj, "hmap_ntpcobj");

  file_out->WriteObject(&hmap_flsmatch_score, "hmap_flsmatch_score");
  file_out->WriteObject(&hmap_flsmatch_score_second, "hmap_flsmatch_score_second");
  file_out->WriteObject(&hmap_flsmatch_score_difference, "hmap_flsmatch_score_difference");

  h_trklen_first->Write();
  h_trklen_second->Write();

  h_flsTime->Write();
  h_flsTime_wcut->Write();
  h_flsTime_wcut_2->Write();
  h_flsTime_wcut_3->Write();
  h_flsTime_wcut_4->Write();
  h_flsTime_wcut_5->Write();
  h_flsTime_wcut_6->Write();
  h_flsTime_wcut_7->Write();
  h_flsTime_wcut_8->Write();
  
  h_flsPe_wcut->Write();
  h_flsTime_flsPe_wcut->Write();
  
  h_deltax->Write();
  h_deltax_2d->Write();
  h_deltaz_4->Write();
  h_deltaz_6->Write();

  _true_reco_tree->Write();




  LOG_NORMAL() << "Saving 1D Event Histo." << std::endl;
  
  file_out->WriteObject(_event_histo_1d, "UBXSecEventHisto1D");

  LOG_NORMAL() << "1D Event Histo saved." << std::endl;

 


  LOG_NORMAL() << "Saving 2D Event Histo." << std::endl;
 
  file_out->WriteObject(_event_histo, "UBXSecEventHisto");

  LOG_NORMAL() << "2D Event Histo saved." << std::endl;
  




  file_out->Write();

  LOG_NORMAL() << "All saved." << std::endl;
  
  file_out->Close();

  LOG_NORMAL() << "Output file closed." << std::endl;







  
  
  // Computing time
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << std::endl << std::endl;
  LOG_NORMAL() << "Computing time: " << elapsed_secs << " seconds = " << elapsed_secs/60. << " minutes." << endl << endl;
  
  //rootapp->Run();
  //rootapp->Terminate(0);
  
  return;
}

#endif

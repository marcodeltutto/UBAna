#define NeutrinoMCFlash_cxx
#include "NeutrinoMCFlash.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void NeutrinoMCFlash::Loop()
{
//   In a ROOT session, you can do:
//      root> .L NeutrinoMCFlash.C
//      root> NeutrinoMCFlash t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

  TH1D * h_flash_sc = new TH1D("h_flash_sc", "h_flash", 31, 0, 31);
  TH1D * h_flash_ch = new TH1D("h_flash_ch", "h_flash", 31, 0, 31);

  TH1D * h_photon_time_sc = new TH1D("h_photon_time_sc", ";Photon G4 Time [ns];", 500, 3000, 10000);
  TH1D * h_photon_time_ch = new TH1D("h_photon_time_ch", ";Photon G4 Time [ns];", 500, 3000, 10000);



   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;


      for (int i = 0; i < cherenkov_pmt_v->size(); i++) {
        h_flash_ch->Fill(cherenkov_pmt_v->at(i));
        h_photon_time_ch->Fill(cherenkov_time_v->at(i));
      }

      for (int i = 0; i < scintillation_pmt_v->size(); i++) {
        h_flash_sc->Fill(scintillation_pmt_v->at(i));
        h_photon_time_sc->Fill(scintillation_time_v->at(i));
      }
   }

  


  TCanvas* canvas_1 = new TCanvas();

  THStack *hs_flash = new THStack("hs_flash",";OpDet; PE Count");

  h_flash_ch->SetLineColor(kBlue+2);
  h_flash_ch->SetFillColor(kBlue+2);
  hs_flash->Add(h_flash_ch);

  h_flash_sc->SetLineColor(kGreen+2);
  h_flash_sc->SetFillColor(kGreen+2);
  hs_flash->Add(h_flash_sc);

  hs_flash->Draw("hist");

  std::stringstream sstm;

  TLegend* leg = new TLegend(0.5689223,0.3165432,0.8909774,0.8538272,NULL,"brNDC");
  sstm.str("");
  sstm << "Cherenkov, " << std::setprecision(2)  << h_flash_ch->Integral() / (h_flash_ch->Integral() + h_flash_sc->Integral()) * 100. << "%";
  leg->AddEntry(h_flash_ch, sstm.str().c_str(),"f");
  sstm.str("");
  sstm << "Scintillation, " << std::setprecision(2)  << h_flash_sc->Integral() / (h_flash_ch->Integral() + h_flash_sc->Integral()) * 100. << "%";
  leg->AddEntry(h_flash_sc, sstm.str().c_str(),"f");
  leg->Draw();


  TCanvas* canvas_2 = new TCanvas();
  h_photon_time_sc->Draw("histo");
  h_photon_time_ch->SetLineColor(kRed);
  h_photon_time_ch->Draw("histo same");
  


}

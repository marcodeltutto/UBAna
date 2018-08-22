//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jul 26 09:51:48 2018 by ROOT version 6.06/06
// from TTree tree/
// found on file: ./ubxsec_output_mc_bnbcosmic_candle_file_cherenkov.root
//////////////////////////////////////////////////////////

#ifndef NeutrinoMCFlash_h
#define NeutrinoMCFlash_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class NeutrinoMCFlash {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           subrun;
   Int_t           event;
   Int_t           pe_total;
   Int_t           pe_scintillation;
   Int_t           pe_cherenkov;
   vector<double>  *cherenkov_time_v;
   vector<int>     *cherenkov_pmt_v;
   vector<double>  *scintillation_time_v;
   vector<int>     *scintillation_pmt_v;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_subrun;   //!
   TBranch        *b_event;   //!
   TBranch        *b_pe_total;   //!
   TBranch        *b_pe_scintillation;   //!
   TBranch        *b_pe_cherenkov;   //!
   TBranch        *b_cherenkov_time_v;   //!
   TBranch        *b_cherenkov_pmt_v;   //!
   TBranch        *b_scintillation_time_v;   //!
   TBranch        *b_scintillation_pmt_v;   //!

   NeutrinoMCFlash(TTree *tree=0);
   virtual ~NeutrinoMCFlash();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef NeutrinoMCFlash_cxx
NeutrinoMCFlash::NeutrinoMCFlash(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("./ubxsec_output_mc_bnbcosmic_other_file_cherenkov.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("./ubxsec_output_mc_bnbcosmic_other_file_cherenkov.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("./ubxsec_output_mc_bnbcosmic_other_file_cherenkov.root:/NeutrinoMCFlash");
      dir->GetObject("tree",tree);

   }
   Init(tree);
}

NeutrinoMCFlash::~NeutrinoMCFlash()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t NeutrinoMCFlash::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t NeutrinoMCFlash::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void NeutrinoMCFlash::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   cherenkov_time_v = 0;
   cherenkov_pmt_v = 0;
   scintillation_time_v = 0;
   scintillation_pmt_v = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("subrun", &subrun, &b_subrun);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("pe_total", &pe_total, &b_pe_total);
   fChain->SetBranchAddress("pe_scintillation", &pe_scintillation, &b_pe_scintillation);
   fChain->SetBranchAddress("pe_cherenkov", &pe_cherenkov, &b_pe_cherenkov);
   fChain->SetBranchAddress("cherenkov_time_v", &cherenkov_time_v, &b_cherenkov_time_v);
   fChain->SetBranchAddress("cherenkov_pmt_v", &cherenkov_pmt_v, &b_cherenkov_pmt_v);
   fChain->SetBranchAddress("scintillation_time_v", &scintillation_time_v, &b_scintillation_time_v);
   fChain->SetBranchAddress("scintillation_pmt_v", &scintillation_pmt_v, &b_scintillation_pmt_v);
   Notify();
}

Bool_t NeutrinoMCFlash::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void NeutrinoMCFlash::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t NeutrinoMCFlash::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef NeutrinoMCFlash_cxx

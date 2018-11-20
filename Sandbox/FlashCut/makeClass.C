#include "/Users/deltutto/Documents/RealWork/CCInclusive/UBAna/build/include/ubana/DataTypes/UBXSecEventHisto1D.h"
//using namespace DataTypes;

void makeClass() {

  TFile *f = new TFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_new.root");
  TTree *v = (TTree*)f->Get("UBXSec/tree");
  v->MakeClass("FlashAnaTree");
}

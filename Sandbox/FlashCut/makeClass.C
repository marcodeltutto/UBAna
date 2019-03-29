void makeClass() {

  TFile *f = new TFile("/uboone/data/users/mdeltutt/ubxsec_static/v06_26_01_22/ubxsec_output_mc_bnbcosmic_ubcodev06_26_01_22__v5.root");
  TTree *v = (TTree*)f->Get("UBXSec/tree");
  v->MakeClass("FlashAnaTree");
}

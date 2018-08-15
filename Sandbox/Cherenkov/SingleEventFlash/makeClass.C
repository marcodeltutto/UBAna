void makeClass() {

  TFile *f = new TFile("./ubxsec_output_mc_bnbcosmic_candle_file_cherenkov.root");
  TTree *v = (TTree*)f->Get("NeutrinoMCFlash/tree");
  v->MakeClass("NeutrinoMCFlash");
}

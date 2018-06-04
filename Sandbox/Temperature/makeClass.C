void makeClass() {

  TFile *f = new TFile("temperatures.root");
  TTree *v = (TTree*)f->Get("tree");
  v->MakeClass("AnaTree");
}

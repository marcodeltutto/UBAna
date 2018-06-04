void draw() {

	Int_t           sensor;
 TDatime         date;
   UInt_t          fDatime;
   Double_t        t;

   // List of branches
   TBranch        *b_sensor;   //!
   TBranch         *b_date;
   TBranch        *b_date_fDatime;   //!
   TBranch        *b_t;  

   TFile *f = new TFile("temperatures.root");
  TTree *tree = (TTree*)f->Get("tree");

   tree->SetBranchAddress("sensor", &sensor, &b_sensor);
   tree->SetBranchAddress("fDatime", &fDatime, &b_date);
      tree->SetBranchAddress("date", &date, &b_date_fDatime);

   tree->SetBranchAddress("t", &t, &b_t);

   float x[200], y[200];
   int counter = 0;

   Long64_t nentries = tree->GetEntriesFast();

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      tree->GetEntry(jentry); 
      std::cout << sensor << ", " << fDatime << ", " << date.Convert() << ", " << t << std::endl;

       if (t <= 0) continue;
       if (sensor != 192) continue;

      x[counter] = date.Convert();
      y[counter] = t;

      counter++;
    }

    TDatime da1(2008,02,28,15,52,00);
   TDatime da2(2008,02,28,15,53,00);

   // float x[2],y[2];
   
   // y[0] = 1.;
   // y[1] = 2.;
   // x[0] = da1.Convert();
   // x[1] = da2.Convert();

   TGraph *mgr = new TGraph(20,x,y);
   mgr->SetMarkerStyle(20);

   mgr->Draw("ap");
   mgr->GetXaxis()->SetTimeDisplay(1);
   // mgr.GetXaxis()->SetNdivisions(503);
   //  mgr->GetXaxis()->SetTimeFormat("%Y-%m-%d %H:%M");
   // mgr->GetXaxis()->SetTimeOffset(0,"gmt");

}
void cov() {

  TFile* file = new TFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v7.root");

  TH1D* CV = (TH1D*)file->Get("bs_genie_models_eff_mumom_dennominal");

  std::vector<TH1D*> syst; syst.resize(200);

  for(int i = 0; i < 200; i++){
    syst[i] = (TH1D*)file->Get(Form("bs_genie_models_eff_mumom_denuniverse%d",i));
  }

  double bins_mumom[7] = {0.00, 0.18, 0.30, 0.45, 0.77, 1.28, 2.50};
  int n_bins_mumom = 6;

  TH2D* cov  = new TH2D("cov" ,"",n_bins_mumom, bins_mumom, n_bins_mumom, bins_mumom);
  TH2D* corr = new TH2D("corr","",n_bins_mumom, bins_mumom, n_bins_mumom, bins_mumom);
  TH2D* fraccov  = new TH2D("fraccov" ,"",n_bins_mumom, bins_mumom, n_bins_mumom, bins_mumom);

  for(int i = 1; i < n_bins_mumom+1; i++){
    for(int j = 1; j < n_bins_mumom+1; j++){

      double Vi = 0;
      double Vj = 0;
      double Vij = 0;
      for(unsigned int uni = 0; uni < syst.size(); uni++){

        Vi = CV->GetBinContent(i) - syst[uni]->GetBinContent(i);
        Vj = CV->GetBinContent(j) - syst[uni]->GetBinContent(j);

        Vij += (Vi*Vj)/200;

      }

      cov->SetBinContent(i,j, Vij);

    }
  }

  for(int ibin = 1; ibin <= n_bins_mumom+1; ibin++){
    for(int jbin = 1; jbin <= n_bins_mumom+1; jbin++){
      double Vij = cov->GetBinContent(ibin, jbin);
      double sii = sqrt( cov->GetBinContent(ibin, ibin));
      double sjj = sqrt( cov->GetBinContent(jbin, jbin));
      corr->SetBinContent(ibin, jbin, Vij/(sii * sjj));
    }
  }


  for(int ibin = 1; ibin <= n_bins_mumom+1; ibin++){
    for(int jbin = 1; jbin <= n_bins_mumom+1; jbin++){
      double Vij = cov->GetBinContent(ibin, jbin);
      double Ni = CV->GetBinContent(ibin);
      double Nj = CV->GetBinContent(jbin);
      fraccov->SetBinContent(ibin, jbin, Vij/(Ni * Nj));
    }
  }



  gStyle->SetPaintTextFormat("4.2f");

  const Int_t NCont = 100;
  const Int_t NRGBs = 5;
  Double_t mainColour[NRGBs]   = { 1.00, 1.00, 1.00, 1.00, 1.00 };
  Double_t otherColour[NRGBs]   = { 0.99,0.80, 0.60, 0.40, 0.20 };
  //Double_t otherOtherColour[NRGBs]   = { 0.9,0.80, 0.80, 0.80, 0.80 };
  Double_t stops[NRGBs] = { 0.00, 0.05, 0.1, 0.4, 1.00 };

  TColor::CreateGradientColorTable(NRGBs, stops, mainColour, otherColour, otherColour, NCont);
  gStyle->SetNumberContours(NCont);




  std::string axis_label = "p_{#mu}^{reco} [GeV]";
  cov->GetXaxis()->SetTitle(axis_label.c_str());
  cov->GetYaxis()->SetTitle(axis_label.c_str());
  corr->GetXaxis()->SetTitle(axis_label.c_str());
  corr->GetYaxis()->SetTitle(axis_label.c_str());  
  fraccov->GetXaxis()->SetTitle(axis_label.c_str());
  fraccov->GetYaxis()->SetTitle(axis_label.c_str());



  TCanvas* c1 = new TCanvas("c1");
  cov->Draw("colz");
  c1->SaveAs("cov.pdf");

  TCanvas* c2 = new TCanvas("c2");
  corr->Draw("colz text");
  c2->SaveAs("corr.pdf");

  TCanvas* c3 = new TCanvas("c3");
  fraccov->Draw("colz text");
  c3->SaveAs("fraccov.pdf");


}


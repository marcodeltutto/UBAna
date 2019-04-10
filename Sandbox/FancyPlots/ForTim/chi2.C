void chi2() {

  TFile * f = new TFile("microboone_numu_cc_inclusive.root");

  TH1D * xsec_data = (TH1D*) f->Get("xsec_data");
  TH1D * xsec_tune1 = (TH1D*) f->Get("xsec_genie_default");
  TH1D * xsec_tune3 = (TH1D*) f->Get("xsec_genie_alternative");

  TH2D * cov = (TH2D*) f->Get("covariance_matrix");

  // Just plotting (statistical uncertainties only for data cross section)
  xsec_tune1->SetLineColor(kGreen+1);
  xsec_tune1->Draw("histo");
  xsec_tune3->SetLineColor(kBlue+1);
  xsec_tune3->Draw("histo same");
  xsec_data->SetLineColor(kBlack+1);
  xsec_data->Draw("E1 same");

  // Getting covariance matrix in TMatrix form
  TMatrix cov_m;
  cov_m.Clear();
  cov_m.ResizeTo(cov->GetNbinsX(), cov->GetNbinsX());

  for (int i = 0; i < cov->GetNbinsX(); i++) {
    for (int j = 0; j < cov->GetNbinsX(); j++) {
      cov_m[i][j] = cov->GetBinContent(i+1, j+1);
    }
  }

  // Inverting the covariance matrix
  TMatrix inverse_cov_m = cov_m.Invert();

  // Calculating the chi2
  double chi2_tune1 = 0;
  double chi2_tune3 = 0;

  for (int i = 0; i < cov->GetNbinsX(); i++) {
    for (int j = 0; j < cov->GetNbinsX(); j++) {
      chi2_tune1 += (xsec_data->GetBinContent(i+1) - xsec_tune1->GetBinContent(i+1)) * inverse_cov_m[i][j] * (xsec_data->GetBinContent(j+1) - xsec_tune1->GetBinContent(j+1));
      chi2_tune3 += (xsec_data->GetBinContent(i+1) - xsec_tune3->GetBinContent(i+1)) * inverse_cov_m[i][j] * (xsec_data->GetBinContent(j+1) - xsec_tune3->GetBinContent(j+1));
    }
  }

  std::cout << "Chi2 (Tune 1): " << chi2_tune1 << std::endl;
  std::cout << "Chi2 (Tune 3): " << chi2_tune3 << std::endl;

}
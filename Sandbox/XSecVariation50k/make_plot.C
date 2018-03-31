void make_plot() {

  std::vector <TH1D*> xsec_onebin_v;
  std::vector <TH1D*> xsec_mumom_v;
  std::vector <TH1D*> xsec_muangle_v;

	TFile* file_0 = new TFile("./xsec_file_0.root");
	xsec_onebin_v.push_back((TH1D*) file_0->Get("xsec_onebin"));
	xsec_mumom_v.push_back((TH1D*) file_0->Get("xsec_mumom"));
	xsec_muangle_v.push_back((TH1D*) file_0->Get("xsec_muangle"));
	TFile* file_1 = new TFile("./xsec_file_1.root");
	xsec_onebin_v.push_back((TH1D*) file_1->Get("xsec_onebin"));
	xsec_mumom_v.push_back((TH1D*) file_1->Get("xsec_mumom"));
	xsec_muangle_v.push_back((TH1D*) file_1->Get("xsec_muangle"));
	TFile* file_2 = new TFile("./xsec_file_2.root");
	xsec_onebin_v.push_back((TH1D*) file_2->Get("xsec_onebin"));
	xsec_mumom_v.push_back((TH1D*) file_2->Get("xsec_mumom"));
	xsec_muangle_v.push_back((TH1D*) file_2->Get("xsec_muangle"));
	TFile* file_3 = new TFile("./xsec_file_3.root");
	xsec_onebin_v.push_back((TH1D*) file_3->Get("xsec_onebin"));
	xsec_mumom_v.push_back((TH1D*) file_3->Get("xsec_mumom"));
	xsec_muangle_v.push_back((TH1D*) file_3->Get("xsec_muangle"));
	TFile* file_4 = new TFile("./xsec_file_4.root");
	xsec_onebin_v.push_back((TH1D*) file_4->Get("xsec_onebin"));
	xsec_mumom_v.push_back((TH1D*) file_4->Get("xsec_mumom"));
	xsec_muangle_v.push_back((TH1D*) file_4->Get("xsec_muangle"));
	TFile* file_5 = new TFile("./xsec_file_5.root");
	xsec_onebin_v.push_back((TH1D*) file_5->Get("xsec_onebin"));
	xsec_mumom_v.push_back((TH1D*) file_5->Get("xsec_mumom"));
	xsec_muangle_v.push_back((TH1D*) file_5->Get("xsec_muangle"));
	TFile* file_6 = new TFile("./xsec_file_6.root");
	xsec_onebin_v.push_back((TH1D*) file_6->Get("xsec_onebin"));
	xsec_mumom_v.push_back((TH1D*) file_6->Get("xsec_mumom"));
	xsec_muangle_v.push_back((TH1D*) file_6->Get("xsec_muangle"));
	TFile* file_7 = new TFile("./xsec_file_7.root");
	xsec_onebin_v.push_back((TH1D*) file_7->Get("xsec_onebin"));
	xsec_mumom_v.push_back((TH1D*) file_7->Get("xsec_mumom"));
	xsec_muangle_v.push_back((TH1D*) file_7->Get("xsec_muangle"));
	//TFile* file_8 = new TFile("./xsec_file_8.root");
	//xsec_onebin_v.push_back((TH1D*) file_8->Get("xsec_onebin"));
	//TH1D* xsec_mumom_8 = (TH1D*) file_8->Get("xsec_mumom");
	//TH1D* xsec_muangle_8 = (TH1D*) file_8->Get("xsec_muangle");



	new TCanvas();

	TH1D * h_onebin_histogram = new TH1D("h_onebin_histogram", ";#sigma [10^{-38} cm^{2}];", 100, 0.7, 0.8);

	double mean_onebin = 0.;
	double std_onebin = 0.;

	for (auto h : xsec_onebin_v) {
		h->Draw("histo same");
		mean_onebin += h->GetBinContent(1);
		h_onebin_histogram->Fill(h->GetBinContent(1));
	}
	mean_onebin /= (double) xsec_onebin_v.size();
  std::cout << "mean_onebin " << mean_onebin << std::endl;

  // Calculate STD
  for (auto h : xsec_onebin_v) {
		std_onebin += (h->GetBinContent(1) - mean_onebin) * (h->GetBinContent(1) - mean_onebin);
	}
	std_onebin = std::sqrt(std_onebin);

	std::cout << "std_onebin " << std_onebin << std::endl;



	new TCanvas();
	h_onebin_histogram->Draw("histo");






	new TCanvas();

  TH1D * h_mean = (TH1D*) xsec_mumom_v.at(0)->Clone("h_mean");
  TH1D * h_std  = (TH1D*) xsec_mumom_v.at(0)->Clone("h_mean");

  for (int i = 1; i < h_mean->GetNbinsX()+1; i++) {
  	h_mean->SetBinContent(i, 0.);
  	h_std->SetBinContent(i, 0.);
  }


	for (auto h : xsec_mumom_v) {
		h->SetTitle("");
		h->GetXaxis()->SetTitle("p_{#mu} [GeV]");
		h->GetYaxis()->SetTitle("d#sigma/dp_{#mu} [10^{-38} cm^{2}/GeV]");
		h->Draw("histo same");
		h_mean->Add(h);
		std::cout << "--bin 1 value is " << h->GetBinContent(1) << std::endl;
	}
	h_mean->Scale(1/(double)xsec_mumom_v.size());

  // Calculate STD
  for (auto h : xsec_mumom_v) {
  	for (int i = 1; i < h->GetNbinsX()+1; i++) {
  		double this_content = (h->GetBinContent(i) - h_mean->GetBinContent(i)) * (h->GetBinContent(i) - h_mean->GetBinContent(i));
  		h_std->SetBinContent(i, h_std->GetBinContent(i) + this_content);
  	}
	}
	for (int i = 1; i < h_std->GetNbinsX()+1; i++) {
  	h_std->SetBinContent(i, std::sqrt(h_std->GetBinContent(i)) / (double)xsec_mumom_v.size());
  	std::cout << "mumom bin " << i << ", mean is " << h_mean->GetBinContent(i) << ", std is " << h_std->GetBinContent(i) << ", frac is " << h_std->GetBinContent(i) / h_mean->GetBinContent(i) << std::endl;
  }
	





	new TCanvas();

  h_mean = (TH1D*) xsec_muangle_v.at(0)->Clone("h_mean");
  h_std  = (TH1D*) xsec_muangle_v.at(0)->Clone("h_mean");

  for (int i = 1; i < h_mean->GetNbinsX()+1; i++) {
  	h_mean->SetBinContent(i, 0.);
  	h_std->SetBinContent(i, 0.);
  }


	for (auto h : xsec_muangle_v) {
		h->SetTitle("");
		h->GetXaxis()->SetTitle("cos(#theta_{#mu})");
		h->GetYaxis()->SetTitle("d#sigma/dcos(#theta_{#mu}) [10^{-38} cm^{2}]");
		h->Draw("histo same");
		h_mean->Add(h);
		std::cout << "--bin 1 value is " << h->GetBinContent(1) << std::endl;
	}
	h_mean->Scale(1/(double)xsec_muangle_v.size());

  // Calculate STD
  for (auto h : xsec_muangle_v) {
  	for (int i = 1; i < h->GetNbinsX()+1; i++) {
  		double this_content = (h->GetBinContent(i) - h_mean->GetBinContent(i)) * (h->GetBinContent(i) - h_mean->GetBinContent(i));
  		h_std->SetBinContent(i, h_std->GetBinContent(i) + this_content);
  	}
	}
	for (int i = 1; i < h_std->GetNbinsX()+1; i++) {
  	h_std->SetBinContent(i, std::sqrt(h_std->GetBinContent(i)) / (double)xsec_muangle_v.size());
  	std::cout << "muangle bin " << i << ", mean is " << h_mean->GetBinContent(i) << ", std is " << h_std->GetBinContent(i) << ", frac is " << h_std->GetBinContent(i) / h_mean->GetBinContent(i) << std::endl;
  }

}
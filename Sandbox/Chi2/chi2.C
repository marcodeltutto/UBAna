using namespace std;

int chi2() {

   //Bin numbers as defined in Marco's analysis
   double x[42] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42};

   //Data extracted cross section from Marco's publication. Note that this array has negative cross sections, which come from subtracting backgrounds
   double xsec_data[42] = {3.8e-2, 2.5e-1, 2.2e-1, 4.1e-2, -0.9e-3, 1.4e-2, 2.2e-1, 2.9e-1, 5.9e-2, -0.2e-3, -3.1e-2, 4.7e-1, 6.7e-1, 1.3e-1, -1.1e-2, 2.1e-1, 7.8e-1, 3.5e-1, -1.3e-2, 2.4e-1, 10.2e-1, 6.4e-1, 1.8e-2, 25.0e-2, 12.5e-1, 11.2e-1, 7.4e-2, 18.1e-2, 9.3e-1, 15.3e-1, 6.9e-1, 3.4e-2, 2.3e-1, 9.6e-1, 18.0e-1, 11.8e-1, 9.7e-2, 1.8e-1, 9.8e-1, 16.9e-1, 13.9e-1, 19.4e-2};

   //Same data extracted cross section as above, but negative entries have been set to 0
   // double xsec_data[42] = {3.8e-2, 2.5e-1, 2.2e-1, 4.1e-2, 0, 1.4e-2, 2.2e-1, 2.9e-1, 5.9e-2, 0, 0, 4.7e-1, 6.7e-1, 1.3e-1, 0, 2.1e-1, 7.8e-1, 3.5e-1, 0, 2.4e-1, 10.2e-1, 6.4e-1, 1.8e-2, 25.0e-2, 12.5e-1, 11.2e-1, 7.4e-2, 18.1e-2, 9.3e-1, 15.3e-1, 6.9e-1, 3.4e-2, 2.3e-1, 9.6e-1, 18.0e-1, 11.8e-1, 9.7e-2, 1.8e-1, 9.8e-1, 16.9e-1, 13.9e-1, 19.4e-2};

   //cross section for tune 1 (graph-clicked from Marco's results plot)
   // double xsec_tune1[42] = {3.2e-2, 2.4e-1, 1.3e-1, 1.8e-2, 2.1e-3, 4.6e-2, 3.8e-1, 2.6e-1, 4.0e-2, 4.0e-3, 9.1e-2, 5.8e-1, 5.5e-1, 1.6e-1, 4.0e-2, 3.7e-1, 8.9e-1, 3.4e-1, 2.6e-2, 3.7e-1, 1.14, 6.5e-1, 2.2e-2, 3.6e-1, 1.33, 1.14, 5.3e-2, 3.5e-1, 1.39, 1.65, 7.2e-1, 2.9e-2, 3.2e-1, 1.47, 2.11, 1.54, 1.4e-1, 3.4e-1, 1.53, 2.30, 2.21, 3.6e-1};  
   
   //cross section for tune 1 (from Marco)
   double xsec_tune1[42] = {0.0316263847888, 0.239335633858, 0.124848388797, 0.0166521920017, 0.000575911135374, 0.0453195549508, 0.375775184938, 0.263489647609, 0.0387371820872, 0.00143825134809, 0.0636409505442, 0.665192970366, 0.624904249595, 0.156302935807, 0.00414156071975, 0.362495950623, 0.900763674149, 0.336649645527, 0.0101717593912, 0.37450649582, 1.12483957148, 0.645751887156, 0.0310667257594, 0.388229973783, 1.31247302026, 1.13530775968, 0.0912995792835, 0.365535507247, 1.38111272042, 1.64280372037, 0.728366975467, 0.0505779409135, 0.361041318975, 1.43463341376, 2.039155288, 1.50308323382, 0.19528783081, 0.409099897117, 1.47559992205, 2.1681043335, 2.08081836821, 0.427908946032};
   
   //cross section for tune 3 (graph-clicked from Marco's results plot)
   // double xsec_tune3[42] = {3.3e-3, 2.4e-1, 1.5e-1, 1.8e-2, 2.8e-3, 3.4e-2, 3.5e-1, 3.2e-1, 5.3e-2, 3.3e-3, 8.8e-2, 6.1e-1, 7.1e-1, 2.4e-1, 4.7e-2, 3.4e-1, 0.90, 4.1e-1, 3.2e-2, 3.2e-1, 1.02, 7.2e-1, 2.8e-2, 3.0e-1, 1.20, 1.12, 6.2e-2, 2.9e-1, 1.28, 1.50, 7.3e-1, 3.8e-2, 3.4e-1, 1.37, 1.82, 1.37, 1.42e-1, 2.6e-1, 1.41, 1.88, 1.75, 3.0e-1}; 
   
   //cross section for tune 3 (from Marco)
   double xsec_tune3[42] = {0.0309243058784, 0.236467335616, 0.152154108473, 0.0167987638847, 0.000565909136202, 0.0332848006399, 0.353974202068, 0.321145203118, 0.0524180701961, 0.00177251949326, 0.0479877364663, 0.597315799976, 0.699641473259, 0.203550600337, 0.00479861974424, 0.324573844525, 0.904141112353, 0.403487577909, 0.0124875330468, 0.330634070353, 1.01934345794, 0.719132852808, 0.0352341386342, 0.327135431787, 1.18965473259, 1.11513499517, 0.102422494179, 0.302849852298, 1.24626104823, 1.46026271278, 0.720163776802, 0.0555030489581, 0.317988304015, 1.28853353226, 1.72002763391, 1.29194290783, 0.186505849483, 0.338627770753, 1.36790967459, 1.79356686739, 1.6713595704, 0.372338722771};

   //File from Marco (through Andy Mastbaum) containing covariance and fractional covariance matrix
   TFile *f = new TFile("xsec_file_cv.root");
   TH2D *cov_frac = (TH2D*)f -> Get("frac_covariance_matrix_poly_muangle_mumom_cv");
   TH2D *cov = (TH2D*)f -> Get("tot_covariance_matrix_poly_muangle_mumom_cv");

   //Turning covariance matrix histogram into a TROOT matrix, so it can be inverted
   TMatrixD *m_cov = new TMatrixD(42, 42);
   TArrayD a_cov(1764);
   int k = 0;
   for(int i = 0; i < 42; i++) {
      for(int j = 0; j < 42; j++) {
         a_cov[k] = cov -> GetBinContent(i+1, j+1);
         k++;
      }
   }
   m_cov -> SetMatrixArray(a_cov.GetArray());

   //Inverting matrix and saving it back in a histogram
   m_cov -> Invert();

   double *d_covinv = m_cov -> GetMatrixArray();
   TH2D *covinv = new TH2D("covinv", "covinv", 42, 0, 42, 42, 0, 42); //inverted covariance matrix as 2D histogram
   k = 0;
   for(int i = 0; i < 42; i++) {
      for(int j = 0; j < 42; j++) {
         covinv -> SetBinContent(i+1, j+1, d_covinv[k]);
         k++;
      }
   }

   //Plotting the covariance matrix histogram
   TCanvas *c1 = new TCanvas("c1", "covariance matrix (Histogram)", 800, 800);
   cov -> Draw("COLZ");

   //Plotting the covariance matrix (matrix) for comparison
   TCanvas *c1a = new TCanvas("c1a", "covariance matrix (Matrix)", 800, 800);
   m_cov -> Draw("COLZ");

   //Pull terms, i.e. how many sigma is data off from MC for each of the 42 bins
   TH1D *delta_tune1 = new TH1D("delta_tune1", "Data - Exp", 42, 0, 42);
   TH1D *delta_tune3 = new TH1D("delta_tune3", "Data - Exp", 42, 0, 42);
   for(int i = 0; i < 42; i++) {
         delta_tune1 -> SetBinContent(i+1, (xsec_data[i] - xsec_tune1[i])/sqrt(cov -> GetBinContent(i+1, i+1)));
         delta_tune3 -> SetBinContent(i+1, (xsec_data[i] - xsec_tune3[i])/sqrt(cov -> GetBinContent(i+1, i+1)));
   }

   TCanvas *c2 = new TCanvas("c2", "data - exp", 800, 800);
   delta_tune1 -> SetLineWidth(2);
   delta_tune1 -> SetLineColor(8);
   delta_tune1 -> Draw();
   delta_tune3 -> SetLineWidth(2);
   delta_tune3 -> SetLineColor(4);
   delta_tune3 -> Draw("same");

   //Calculation of chi2 with and whithout correlations for tune 1 and tune 3
   double totalchi2 = 0; //tune 1, with correlations
   double totalchi2diag = 0; //tune 1, only diagonal covariance matrix elements
   double totalchi22 = 0; //tune 3, with correlations
   double totalchi2diag2 = 0; //tune 3, only diagonal covariance matrix elements

  //histogram to get the error for the result plot data values from the diagonal elements of the covariance matrix
   double *xsec_data_error = new double[42];

   //histograms to plot tune 1 and tune 3 cross sections
   TH1D *h_tune1 = new TH1D("h_tune1", "Xsec tune 1", 42, 0.5, 42.5);
   TH1D *h_tune3 = new TH1D("h_tune3", "Xsec tune 3", 42, 0.5, 42.5);

   //histograms to plot chi2 and cumulative chi2 for tune 1 and tune 3 for each bin - no correlations
   TH1D *h_chi2diag = new TH1D("h_chi2diag", "Chi2, no correlations, tune 1", 42, 0.5, 42.5);
   TH1D *h_chi2diagcum = new TH1D("h_chi2diagcum", "Cumulative chi2, no correlations, tune 1", 42, 0.5, 42.5);
   TH1D *h_chi2diag2 = new TH1D("h_chi2diag2", "Chi2, no correlations, tune 3", 42, 0.5, 42.5);
   TH1D *h_chi2diagcum2 = new TH1D("h_chi2diagcum2", "Cumulative chi2, no correlations, tune 3", 42, 0.5, 42.5);

   //histograms for chi2 calculation with correlations
   TH2D *chisquare = new TH2D("chisquare", "Chi2 with correlations, tune 1", 42, 0, 42, 42, 0, 42);
   TH2D *chisquare2 = new TH2D("chisquare2", "Chi2 with correlations, tune 3", 42, 0, 42, 42, 0, 42);

   for(int i = 0; i < 42; i++) {

      //data error bars from diagonal covariance matrix elements
      xsec_data_error[i] = sqrt(cov -> GetBinContent(i+1, i+1));

      //fill tune 1 and tune 3 cross section prediction histograms
      h_tune1 -> SetBinContent(i+1, xsec_tune1[i]);
      h_tune3 -> SetBinContent(i+1, xsec_tune3[i]);

      //calculate chi2 without correlations
      totalchi2diag += (xsec_data[i] - xsec_tune1[i])*(xsec_data[i] - xsec_tune1[i])/cov -> GetBinContent(i+1, i+1);
      totalchi2diag2 += (xsec_data[i] - xsec_tune3[i])*(xsec_data[i] - xsec_tune3[i])/cov -> GetBinContent(i+1, i+1);

      //fill histograms for chi2 without correlations
      h_chi2diag -> SetBinContent(i+1, (xsec_data[i] - xsec_tune1[i])*(xsec_data[i] - xsec_tune1[i])/cov -> GetBinContent(i+1, i+1));
      h_chi2diag2 -> SetBinContent(i+1, (xsec_data[i] - xsec_tune3[i])*(xsec_data[i] - xsec_tune3[i])/cov -> GetBinContent(i+1, i+1));
      h_chi2diagcum -> SetBinContent(i+1, totalchi2diag);
      h_chi2diagcum2 -> SetBinContent(i+1, totalchi2diag2);

      for(int j = 0; j < 42; j++) {

         //calculate chi2 with correlations
         chisquare -> SetBinContent(i+1, j+1, (xsec_data[i] - xsec_tune1[i]) *covinv -> GetBinContent(i+1, j+1) * (xsec_data[j] - xsec_tune1[j]));
         chisquare2 -> SetBinContent(i+1, j+1, (xsec_data[i] - xsec_tune3[i]) *covinv -> GetBinContent(i+1, j+1) * (xsec_data[j] - xsec_tune3[j]));
         totalchi2 += chisquare -> GetBinContent(i+1, j+1);
         totalchi22 += chisquare2 -> GetBinContent(i+1, j+1);
      }
   }

   TCanvas *c3 = new TCanvas("c3", "chi2 with correlations for tune 1", 800, 800);
   chisquare -> Draw("COLZ");

   TCanvas *c3a = new TCanvas("c3a", "chi2 with correlations for tune 3", 800, 800);
   chisquare2 -> Draw("COLZ");

   cout << "Tune 1: " << totalchi2 << "\t" << totalchi2diag << endl;
   cout << "Tune 3: " << totalchi22 << "\t" << totalchi2diag2 << endl;

   TCanvas *c4 = new TCanvas("c4", "inverse covariance matrix", 800, 800);
   covinv -> Draw("COLZ");


   TCanvas *c5 = new TCanvas("c5", "data and MC", 800, 600);
   TGraphErrors *gr_data = new TGraphErrors(42, x, xsec_data, 0, xsec_data_error);
   gr_data -> Draw("AP");
   h_tune1 -> SetLineWidth(2); h_tune1 -> SetLineColor(8);
   h_tune1 -> Draw("SAME");
   h_tune3 -> SetLineWidth(2); h_tune3 -> SetLineColor(4);
   h_tune3 -> Draw("SAME");

   TCanvas *c6 = new TCanvas("c6", "Chi2 contributions", 800, 600);
   h_chi2diag -> SetMarkerStyle(20);
   h_chi2diag -> SetMarkerColor(8);
   h_chi2diag -> Draw("P");
   h_chi2diag2 -> SetMarkerStyle(20);
   h_chi2diag2 -> SetMarkerColor(4);
   h_chi2diag2 -> Draw("PSAME");

   TCanvas *c7 = new TCanvas("c7", "cumulative chi2", 800, 600);
   h_chi2diagcum -> SetMarkerStyle(20);
   h_chi2diagcum -> SetMarkerColor(8);
   h_chi2diagcum -> Draw("P");
   h_chi2diagcum2 -> SetMarkerStyle(20);
   h_chi2diagcum2 -> SetMarkerColor(4);
   h_chi2diagcum2 -> Draw("PSAME");

   TF1 *fl = new TF1("linear", "x", 0, 42);
   fl -> SetLineColor(2);
   fl -> Draw("lsame");

   return 0;

}


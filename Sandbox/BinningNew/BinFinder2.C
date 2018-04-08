#define BinFinder2_cxx
#include "BinFinder2.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void BinFinder2::Loop()
{

	gStyle->SetPalette(kBird);
	gROOT->SetBatch(kTRUE);

	std::string plot_label = ";Muon cos(#theta) (Reco) [GeV];Muon cos(#theta) (Truth) [GeV]";
	std::string plot_label_abs = ";Muon |cos(#theta)| (Reco) [GeV];Muon |cos(#theta)| (Truth) [GeV]";
	std::string plot_label_pre = ";Muon cos(#theta) (Truth) [GeV];";

//   In a ROOT session, you can do:
//      root> .L BinFinder2.C
//      root> BinFinder2 t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
	if (fChain == 0) return;


  TH2D * h_true_reco = new TH2D("h_true_reco", plot_label.c_str(), 120, -1, 1, 120, -1, 1); //!
  TH2D * h_true_reco_abs = new TH2D("h_true_reco_abs", plot_label_abs.c_str(), 120, 0, 1, 120, 0, 1); //!

  double bins_muangle[10] = {-1.00, -0.50, 0.00, 0.28, 0.47, 0.63, 0.765, 0.865, 0.935, 1.00};
	TH2D * h_true_reco_rightbin = new TH2D("h_true_reco_rightbin", plot_label.c_str(), 9, bins_muangle, 9, bins_muangle);

  TH1D * h_truth_mom_pre = new TH1D("h_truth_mom_pre", plot_label_pre.c_str(), 50, -1, 1.5); //!

  Long64_t nentries = fChain->GetEntriesFast();


  double lower_bin = 0;
  double upper_bin = 1;

  std::vector<double> bin_v;
  bin_v.push_back(lower_bin);

  std::vector<double> points_v, error_x_v, mean_v, std_v;

  bool exit_flag = false;

  bool first = true;

	while (!exit_flag) {

		std::cout << ">>> Using lower_bin = " << lower_bin << ", and upper_bin = " << upper_bin << std::endl;

    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
    	Long64_t ientry = LoadTree(jentry);
    	if (ientry < 0) break;
    	nb = fChain->GetEntry(jentry);   nbytes += nb;

      double truth = mom_tree_angle_true; //! 
		  double reco = mom_tree_angle_reco; //!

      if (first) {
	  	  h_true_reco->Fill(reco, truth);
	  	  h_true_reco_abs->Fill(std::abs(reco), std::abs(truth));
	  	  h_true_reco_rightbin->Fill(reco, truth);
      }

	    if (reco > lower_bin && reco < upper_bin) {
         h_truth_mom_pre->Fill(truth);
		  }


	  }
	  first = false;


		double array[2];
		DoFit(h_truth_mom_pre, "test", "test", array, false);

		std::cout << "mean " << array[0] << ", std " << array[1] << std::endl;
		std::cout << "truth bin: " << upper_bin - lower_bin << std::endl;
		std::cout << "reco bin: " << 2*array[1] << std::endl;

		double reco_bin = upper_bin - lower_bin;
		double truth_bin = 2*array[1];

		if (std::abs(truth_bin - reco_bin) < 0.005) {
			bin_v.push_back(upper_bin);
			points_v.push_back((upper_bin + lower_bin)/2);
			error_x_v.push_back((upper_bin - lower_bin)/2);
			mean_v.push_back(array[0]);
			std_v.push_back(array[1]);
			// Rerun fitting just to save the plot
			ostringstream oss;
			oss << "Reco cos(#theta): " << lower_bin << "-" << upper_bin;
			std::string label = oss.str();
			ostringstream oss2;
			oss2 << "reco_costheta_" << lower_bin << "_" << upper_bin;
			std::string label2 = oss2.str();
			DoFit(h_truth_mom_pre, label, label2, array, true);

			lower_bin = upper_bin;
			upper_bin = lower_bin + 0.3;

		} else  {
			upper_bin-=0.005 ;
		}
		if (lower_bin > 0.93) {
			exit_flag = true;
		}
		h_truth_mom_pre->Reset();


	}




	std::cout << "Bins: " << std::endl;
	for (auto b : bin_v)
		std::cout << "\t" << b << std::endl;




	TCanvas * c0 = new TCanvas;
	c0->SetRightMargin(0.13);
	TLine *line = new TLine(-1,-1,1,1); //!
	line->SetLineColor(kRed);
	gStyle->SetPalette(kBird);
	h_true_reco->Draw("colz");
	//line->Draw();

	TString n = "final_nopoints";

	c0->SaveAs("output2/" + n + ".pdf");
	c0->SaveAs("output2/" + n + ".C");


	TCanvas * c00 = new TCanvas;
	c00->SetRightMargin(0.13);
	c00->Modified();
  c00->Update();
	TLine *line2 = new TLine(-1,-1,1,1);
	line2->SetLineColor(kRed);
	h_true_reco_rightbin->Draw("colz text");
	line2->Draw();

  //TPaletteAxis* palette00 = (TPaletteAxis*)h_true_reco_mom_rightbin->GetListOfFunctions()->FindObject("palette");
  //palette00->SetX1NDC(0.875);
 // palette00->SetX2NDC(0.92);
  //gPad->Modified();
  //gPad->Update();

	n = "final_nopoints_rightbin";

	c00->SaveAs("output2/" + n + ".pdf");
	c00->SaveAs("output2/" + n + ".C");



	TCanvas * c1 = new TCanvas;
	c1->SetRightMargin(0.13);
	gStyle->SetPalette(kBird);
	h_true_reco_abs->Draw("colz");
	//line->Draw();

	n = "final_nopoints_abs";

	c1->SaveAs("output2/" + n + ".pdf");
	c1->SaveAs("output2/" + n + ".C");





	double* points = &points_v[0];
	double* mean_array = &mean_v[0];
	double* error_x = &error_x_v[0];
	double* sigma_array = &std_v[0];
	int pts = points_v.size();

	TCanvas * c2 = new TCanvas;
	c2->SetRightMargin(0.13);
  
	TGraphErrors* gr = new TGraphErrors(pts,points,mean_array,error_x,sigma_array);
	gr->SetMarkerStyle(kFullCircle);
	gr->SetMarkerSize(1.0);
	gr->SetLineWidth(2.0);

	h_true_reco->Draw("colz");
	gr->Draw("P");

	line->Draw();

	n = "final";

	c2->SaveAs("output2/" + n + ".pdf");
	c2->SaveAs("output2/" + n + ".C");
}




void BinFinder2::DoFit(TH1D * the_histo, std::string name, std::string save_name, double *array, bool save_plot) {

	TCanvas * c = new TCanvas;

	Int_t status = the_histo->Fit("gaus");
	if (status == 0) {

		TF1 *myfunc = the_histo->GetFunction("gaus");
		the_histo->Draw("histo");
		myfunc->Draw("same");

		std::cout << "mean: " << myfunc->GetParameter(1) << std::endl;
		std::cout << "sigma: " << myfunc->GetParameter(2) << std::endl;
		array[0] = myfunc->GetParameter(1);
		array[1] = myfunc->GetParameter(2);

		std::string j = name;

		TLatex* range = new TLatex(0.88,0.86, j.c_str());
		range->SetTextColor(kGray+2);
		range->SetNDC();
		range->SetNDC();
    //range->SetTextSize(2/30.);
		range->SetTextSize(0.038);
		range->SetTextAlign(32);
		range->Draw();

		TString n = save_name;
		n = n + "_gaus";

		if (save_plot) {
			c->SaveAs("output2/" + n + ".pdf");
			c->SaveAs("output2/" + n + ".C");
		}

	} else {
		std::cout << "Fit failed!" << std::endl;
	}


  //_txtfile << name << " GeV |" << array[0] << "|" << array[1] << std::endl;


}

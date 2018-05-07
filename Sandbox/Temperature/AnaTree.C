#define AnaTree_cxx
#include "AnaTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>

void AnaTree::Loop()
{
//   In a ROOT session, you can do:
//      root> .L AnaTree.C
//      root> AnaTree t
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

	// TH1D * h = new TH1D("h", "", );

	float x_192[1000], y_192[1000];
	int counter_192 = 0;
	float x_189[1000], y_189[1000];
	int counter_189 = 0;
	float x_193[1000], y_193[1000];
	int counter_193 = 0;
	float x_194[1000], y_194[1000];
	int counter_194 = 0;
	float x_195[1000], y_195[1000];
	int counter_195 = 0;
	float x_190[1000], y_190[1000];
	int counter_190 = 0;
	float x_196[1000], y_196[1000];
	int counter_196 = 0;
	float x_197[1000], y_197[1000];
	int counter_197 = 0;
	float x_198[1000], y_198[1000];
	int counter_198 = 0;
	float x_199[1000], y_199[1000];
	int counter_199 = 0;

	Long64_t nentries = fChain->GetEntriesFast();

	Long64_t nbytes = 0, nb = 0;
	for (Long64_t jentry=0; jentry<nentries;jentry++) {
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
		nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

		if (t <= 0) continue;

		if (sensor == 192) {
		  x_192[counter_192] = fDatime;
		  y_192[counter_192] = t;
		  // std::cout << "fDatime = " << fDatime << ", t = " << t << std::endl;
		  // std::cout << "from x, y - fDatime = " << x[counter] << ", t = " << y[counter]  << std::endl;
		  counter_192++;
		}
		if (sensor == 189) {
		  x_189[counter_189] = fDatime;
		  y_189[counter_189] = t;
		  counter_189++;
		}
		if (sensor == 193) {
		  x_193[counter_193] = fDatime;
		  y_193[counter_193] = t;
		  counter_193++;
		}
		if (sensor == 194) {
		  x_194[counter_194] = fDatime;
		  y_194[counter_194] = t;
		  counter_194++;
		}
		if (sensor == 195) {
		  x_195[counter_195] = fDatime;
		  y_195[counter_195] = t;
		  counter_195++;
		}
		if (sensor == 190) {
		  x_190[counter_190] = fDatime;
		  y_190[counter_190] = t;
		  counter_190++;
		}
		if (sensor == 196) {
		  x_196[counter_196] = fDatime;
		  y_196[counter_196] = t;
		  counter_196++;
		}
		if (sensor == 197) {
		  x_197[counter_197] = fDatime;
		  y_197[counter_197] = t;
		  counter_197++;
		}
		if (sensor == 198) {
		  x_198[counter_198] = fDatime;
		  y_198[counter_198] = t;
		  counter_198++;
		}
		if (sensor == 199) {
		  x_199[counter_199] = fDatime;
		  y_199[counter_199] = t;
		  counter_199++;
		}

	}



	TGraph *mgr_192 = new TGraph(counter_192,x_192,y_192);
	mgr_192->SetMarkerStyle(20);
	mgr_192->SetMarkerSize(0.6);
	mgr_192->SetMarkerColor(kRed+1);
	mgr_192->GetXaxis()->SetTimeDisplay(1);
	mgr_192->GetXaxis()->SetNdivisions(503);
	mgr_192->GetXaxis()->SetLabelOffset(0.02);
	mgr_192->GetXaxis()->SetTimeFormat("#splitline{%d %b}{%Y}");
	mgr_192->GetXaxis()->SetTimeOffset(0,"gmt");
	mgr_192->SetTitle("");
	TGraph *mgr_189 = new TGraph(counter_189,x_189,y_189);
	mgr_189->SetMarkerStyle(20);
	mgr_189->SetMarkerSize(0.6);
	mgr_192->SetMarkerColor(kBlue+1);
	mgr_189->GetXaxis()->SetTimeDisplay(1);
	mgr_189->GetXaxis()->SetNdivisions(503);
	// mgr_189->GetXaxis()->SetTimeFormat("%d %b %Y");
	mgr_189->GetXaxis()->SetTimeOffset(0,"gmt");
	TGraph *mgr_193 = new TGraph(counter_193,x_193,y_193);
	mgr_193->SetMarkerStyle(20);
	mgr_193->SetMarkerSize(0.6);
	mgr_192->SetMarkerColor(kGreen+1);
	mgr_193->GetXaxis()->SetTimeDisplay(1);
	mgr_193->GetXaxis()->SetNdivisions(503);
	// mgr_193->GetXaxis()->SetTimeFormat("%d %b %Y");
	mgr_193->GetXaxis()->SetTimeOffset(0,"gmt");
	TGraph *mgr_194 = new TGraph(counter_194,x_194,y_194);
	mgr_194->SetMarkerStyle(20);
	mgr_194->SetMarkerSize(0.6);
	mgr_192->SetMarkerColor(kOrange+1);
	mgr_194->GetXaxis()->SetTimeDisplay(1);
	mgr_194->GetXaxis()->SetNdivisions(503);
	// mgr_194->GetXaxis()->SetTimeFormat("%d %b %Y");
	mgr_194->GetXaxis()->SetTimeOffset(0,"gmt");
	TGraph *mgr_195 = new TGraph(counter_195,x_195,y_195);
	mgr_195->SetMarkerStyle(20);
	mgr_195->SetMarkerSize(0.6);
	mgr_192->SetMarkerColor(kViolet+1);
	mgr_195->GetXaxis()->SetTimeDisplay(1);
	mgr_195->GetXaxis()->SetNdivisions(503);
	// mgr_195->GetXaxis()->SetTimeFormat("%d %b %Y");
	mgr_195->GetXaxis()->SetTimeOffset(0,"gmt");
	TGraph *mgr_190 = new TGraph(counter_190,x_190,y_190);
	mgr_190->SetMarkerStyle(20);
	mgr_190->SetMarkerSize(0.6);
	mgr_192->SetMarkerColor(kGray+1);
	mgr_190->GetXaxis()->SetTimeDisplay(1);
	mgr_190->GetXaxis()->SetNdivisions(503);
	// mgr_190->GetXaxis()->SetTimeFormat("%d %b %Y");
	mgr_190->GetXaxis()->SetTimeOffset(0,"gmt");
	TGraph *mgr_196 = new TGraph(counter_196,x_196,y_196);
	mgr_196->SetMarkerStyle(20);
	mgr_196->SetMarkerSize(0.6);
	mgr_192->SetMarkerColor(kRed-1);
	mgr_196->GetXaxis()->SetTimeDisplay(1);
	mgr_196->GetXaxis()->SetNdivisions(503);
	// mgr_196->GetXaxis()->SetTimeFormat("%d %b %Y");
	mgr_196->GetXaxis()->SetTimeOffset(0,"gmt");
	TGraph *mgr_197 = new TGraph(counter_197,x_197,y_197);
	mgr_197->SetMarkerStyle(20);
	mgr_197->SetMarkerSize(0.6);
	mgr_192->SetMarkerColor(kBlue+5);
	mgr_197->GetXaxis()->SetTimeDisplay(1);
	mgr_197->GetXaxis()->SetNdivisions(503);
	// mgr_197->GetXaxis()->SetTimeFormat("%d %b %Y");
	mgr_197->GetXaxis()->SetTimeOffset(0,"gmt");
	TGraph *mgr_198 = new TGraph(counter_198,x_198,y_198);
	mgr_198->SetMarkerStyle(20);
	mgr_198->SetMarkerSize(0.6);
	mgr_192->SetMarkerColor(kGreen-1);
	mgr_198->GetXaxis()->SetTimeDisplay(1);
	mgr_198->GetXaxis()->SetNdivisions(503);
	// mgr_198->GetXaxis()->SetTimeFormat("%d %b %Y");
	mgr_198->GetXaxis()->SetTimeOffset(0,"gmt");
	TGraph *mgr_199 = new TGraph(counter_199,x_199,y_199);
	mgr_199->SetMarkerStyle(20);
	mgr_199->SetMarkerSize(0.6);
	mgr_192->SetMarkerColor(kOrange+4);
	mgr_199->GetXaxis()->SetTimeDisplay(1);
	mgr_199->GetXaxis()->SetNdivisions(503);
	// mgr_199->GetXaxis()->SetTimeFormat("%d %b %Y");
	mgr_199->GetXaxis()->SetTimeOffset(0,"gmt");



  mgr_192->Draw("ap");
  mgr_189->Draw("p");
  mgr_193->Draw("p");
  mgr_194->Draw("p");
  mgr_195->Draw("p");
  mgr_190->Draw("p");
  mgr_196->Draw("p");
  mgr_197->Draw("p");
  mgr_198->Draw("p");
  mgr_199->Draw("p");

// new TCanvas;

//    TDatime da1(2008,02,28,15,52,00);
//   TDatime da2(2008,02,28,15,53,00);

//   float x[2],y[2];

//   y[0] = 1.;
//   y[1] = 2.;
//   x[0] = da1.Convert();
//   x[1] = da2.Convert();

//   TGraph * mgr = new TGraph(2,x,y);
//   mgr->SetMarkerStyle(20);

//   mgr->Draw("ap");
//   mgr->GetXaxis()->SetTimeDisplay(1);
//   mgr->GetXaxis()->SetNdivisions(503);
//   mgr->GetXaxis()->SetTimeFormat("%Y-%m-%d %H:%M");
//   mgr->GetXaxis()->SetTimeOffset(0,"gmt");

 // gPad->Modified(); gPad->Update();

}

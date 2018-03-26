void chi2_mult()
{
//=========Macro generated from canvas: c1_n11/c1_n11
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n11 = new TCanvas("c1_n11", "c1_n11",0,0,700,500);
   c1_n11->SetHighLightColor(2);
   c1_n11->Range(-6.25,-14.4375,56.25,129.9375);
   c1_n11->SetFillColor(0);
   c1_n11->SetBorderMode(0);
   c1_n11->SetBorderSize(2);
   c1_n11->SetFrameBorderMode(0);
   c1_n11->SetFrameBorderMode(0);
   
   TH1D *h_chi2__1 = new TH1D("h_chi2__1","h_chi2",50,0,50);
   h_chi2__1->SetBinContent(2,110);
   h_chi2__1->SetEntries(110);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("h_chi2");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 110    ");
   AText = ptstats->AddText("Mean  =      1");
   AText = ptstats->AddText("Std Dev   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_chi2__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_chi2__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h_chi2__1->SetLineColor(ci);
   h_chi2__1->GetXaxis()->SetLabelFont(42);
   h_chi2__1->GetXaxis()->SetLabelSize(0.035);
   h_chi2__1->GetXaxis()->SetTitleSize(0.035);
   h_chi2__1->GetXaxis()->SetTitleFont(42);
   h_chi2__1->GetYaxis()->SetLabelFont(42);
   h_chi2__1->GetYaxis()->SetLabelSize(0.035);
   h_chi2__1->GetYaxis()->SetTitleSize(0.035);
   h_chi2__1->GetYaxis()->SetTitleFont(42);
   h_chi2__1->GetZaxis()->SetLabelFont(42);
   h_chi2__1->GetZaxis()->SetLabelSize(0.035);
   h_chi2__1->GetZaxis()->SetTitleSize(0.035);
   h_chi2__1->GetZaxis()->SetTitleFont(42);
   h_chi2__1->Draw("histo");
   
   TPaveText *pt = new TPaveText(0.4354023,0.9365254,0.5645977,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("h_chi2");
   pt->Draw();
   c1_n11->Modified();
   c1_n11->cd();
   c1_n11->SetSelected(c1_n11);
}

void nue_selected_contamination()
{
//=========Macro generated from canvas: c1_n49/c1_n49
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n49 = new TCanvas("c1_n49", "c1_n49",0,0,700,500);
   c1_n49->SetHighLightColor(2);
   c1_n49->Range(-0.1875,-0.13125,1.6875,1.18125);
   c1_n49->SetFillColor(0);
   c1_n49->SetBorderMode(0);
   c1_n49->SetBorderSize(2);
   c1_n49->SetFrameBorderMode(0);
   c1_n49->SetFrameBorderMode(0);
   
   TH1D *h_nue_selected_energy__13 = new TH1D("h_nue_selected_energy__13","",100,0,1.5);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("h_nue_selected_energy");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 0      ");
   AText = ptstats->AddText("Mean  =      0");
   AText = ptstats->AddText("Std Dev   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_nue_selected_energy__13->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_nue_selected_energy__13);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h_nue_selected_energy__13->SetLineColor(ci);
   h_nue_selected_energy__13->GetXaxis()->SetTitle("True Neutrino Energy [GeV]");
   h_nue_selected_energy__13->GetXaxis()->SetLabelFont(42);
   h_nue_selected_energy__13->GetXaxis()->SetLabelSize(0.035);
   h_nue_selected_energy__13->GetXaxis()->SetTitleSize(0.035);
   h_nue_selected_energy__13->GetXaxis()->SetTitleFont(42);
   h_nue_selected_energy__13->GetYaxis()->SetTitle("#nu_{e} Selected Events");
   h_nue_selected_energy__13->GetYaxis()->SetLabelFont(42);
   h_nue_selected_energy__13->GetYaxis()->SetLabelSize(0.035);
   h_nue_selected_energy__13->GetYaxis()->SetTitleSize(0.035);
   h_nue_selected_energy__13->GetYaxis()->SetTitleFont(42);
   h_nue_selected_energy__13->GetZaxis()->SetLabelFont(42);
   h_nue_selected_energy__13->GetZaxis()->SetLabelSize(0.035);
   h_nue_selected_energy__13->GetZaxis()->SetTitleSize(0.035);
   h_nue_selected_energy__13->GetZaxis()->SetTitleFont(42);
   h_nue_selected_energy__13->Draw("histo");
      tex = new TLatex(0.1,0.96,"Simulated POT: -1");
tex->SetNDC();
   tex->SetTextAlign(10);

   ci = TColor::GetColor("#666666");
   tex->SetTextColor(ci);
   tex->SetTextSize(0.03333334);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.1,0.92,"Scaled to POT: 6.6e+20");
tex->SetNDC();
   tex->SetTextAlign(10);

   ci = TColor::GetColor("#666666");
   tex->SetTextColor(ci);
   tex->SetTextSize(0.03333334);
   tex->SetLineWidth(2);
   tex->Draw();
   c1_n49->Modified();
   c1_n49->cd();
   c1_n49->SetSelected(c1_n49);
}

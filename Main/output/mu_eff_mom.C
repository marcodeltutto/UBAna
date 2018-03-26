void mu_eff_mom()
{
//=========Macro generated from canvas: c1_n19/c1_n19
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n19 = new TCanvas("c1_n19", "c1_n19",0,0,700,500);
   c1_n19->SetHighLightColor(2);
   c1_n19->Range(-0.25,-0.125,2.25,1.125);
   c1_n19->SetFillColor(0);
   c1_n19->SetBorderMode(0);
   c1_n19->SetBorderSize(2);
   c1_n19->SetFrameBorderMode(0);
   c1_n19->SetFrameBorderMode(0);
   
   TH2D *h_mu_eff_mom = new TH2D("h_mu_eff_mom","",50,0,2,20,0,1);
   h_mu_eff_mom->SetBinContent(5,1);
   h_mu_eff_mom->SetBinContent(6,1);
   h_mu_eff_mom->SetBinContent(7,1);
   h_mu_eff_mom->SetBinContent(8,1);
   h_mu_eff_mom->SetBinContent(10,1);
   h_mu_eff_mom->SetBinContent(11,1);
   h_mu_eff_mom->SetBinContent(12,1);
   h_mu_eff_mom->SetBinContent(14,1);
   h_mu_eff_mom->SetBinContent(16,1);
   h_mu_eff_mom->SetBinContent(26,1);
   h_mu_eff_mom->SetBinContent(29,1);
   h_mu_eff_mom->SetBinContent(30,1);
   h_mu_eff_mom->SetBinContent(40,1);
   h_mu_eff_mom->SetEntries(13);
   h_mu_eff_mom->SetContour(20);
   h_mu_eff_mom->SetContourLevel(0,0);
   h_mu_eff_mom->SetContourLevel(1,0);
   h_mu_eff_mom->SetContourLevel(2,0);
   h_mu_eff_mom->SetContourLevel(3,0);
   h_mu_eff_mom->SetContourLevel(4,0);
   h_mu_eff_mom->SetContourLevel(5,0);
   h_mu_eff_mom->SetContourLevel(6,0);
   h_mu_eff_mom->SetContourLevel(7,0);
   h_mu_eff_mom->SetContourLevel(8,0);
   h_mu_eff_mom->SetContourLevel(9,0);
   h_mu_eff_mom->SetContourLevel(10,0);
   h_mu_eff_mom->SetContourLevel(11,0);
   h_mu_eff_mom->SetContourLevel(12,0);
   h_mu_eff_mom->SetContourLevel(13,0);
   h_mu_eff_mom->SetContourLevel(14,0);
   h_mu_eff_mom->SetContourLevel(15,0);
   h_mu_eff_mom->SetContourLevel(16,0);
   h_mu_eff_mom->SetContourLevel(17,0);
   h_mu_eff_mom->SetContourLevel(18,0);
   h_mu_eff_mom->SetContourLevel(19,0);
   
   TPaletteAxis *palette = new TPaletteAxis(2.0125,0,2.125,1,h_mu_eff_mom);
palette->SetLabelColor(1);
palette->SetLabelFont(42);
palette->SetLabelOffset(0.005);
palette->SetLabelSize(0.035);
palette->SetTitleOffset(1);
palette->SetTitleSize(0.035);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#52ba91");
   palette->SetFillColor(ci);
   palette->SetFillStyle(1001);
   h_mu_eff_mom->GetListOfFunctions()->Add(palette,"br");
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("h_mu_eff_mom");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 13     ");
   AText = ptstats->AddText("Mean x =      0");
   AText = ptstats->AddText("Mean y =      0");
   AText = ptstats->AddText("Std Dev x =      0");
   AText = ptstats->AddText("Std Dev y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_mu_eff_mom->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_mu_eff_mom);

   ci = TColor::GetColor("#000099");
   h_mu_eff_mom->SetLineColor(ci);
   h_mu_eff_mom->GetXaxis()->SetTitle("True Muon Momentum [GeV]");
   h_mu_eff_mom->GetXaxis()->SetLabelFont(42);
   h_mu_eff_mom->GetXaxis()->SetLabelSize(0.035);
   h_mu_eff_mom->GetXaxis()->SetTitleSize(0.035);
   h_mu_eff_mom->GetXaxis()->SetTitleFont(42);
   h_mu_eff_mom->GetYaxis()->SetTitle(" Efficiency");
   h_mu_eff_mom->GetYaxis()->SetLabelFont(42);
   h_mu_eff_mom->GetYaxis()->SetLabelSize(0.035);
   h_mu_eff_mom->GetYaxis()->SetTitleSize(0.035);
   h_mu_eff_mom->GetYaxis()->SetTitleFont(42);
   h_mu_eff_mom->GetZaxis()->SetLabelFont(42);
   h_mu_eff_mom->GetZaxis()->SetLabelSize(0.035);
   h_mu_eff_mom->GetZaxis()->SetTitleSize(0.035);
   h_mu_eff_mom->GetZaxis()->SetTitleFont(42);
   h_mu_eff_mom->Draw("colz");
   c1_n19->Modified();
   c1_n19->cd();
   c1_n19->SetSelected(c1_n19);
}

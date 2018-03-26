void mu_eff_mom_sel()
{
//=========Macro generated from canvas: c1_n20/c1_n20
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n20 = new TCanvas("c1_n20", "c1_n20",0,0,700,500);
   c1_n20->SetHighLightColor(2);
   c1_n20->Range(-0.25,-0.125,2.25,1.125);
   c1_n20->SetFillColor(0);
   c1_n20->SetBorderMode(0);
   c1_n20->SetBorderSize(2);
   c1_n20->SetFrameBorderMode(0);
   c1_n20->SetFrameBorderMode(0);
   
   TH2D *h_mu_eff_mom_sel = new TH2D("h_mu_eff_mom_sel","After Selection",50,0,2,20,0,1);
   h_mu_eff_mom_sel->SetBinContent(5,1);
   h_mu_eff_mom_sel->SetBinContent(6,1);
   h_mu_eff_mom_sel->SetBinContent(10,1);
   h_mu_eff_mom_sel->SetBinContent(26,1);
   h_mu_eff_mom_sel->SetEntries(4);
   h_mu_eff_mom_sel->SetContour(20);
   h_mu_eff_mom_sel->SetContourLevel(0,0);
   h_mu_eff_mom_sel->SetContourLevel(1,0);
   h_mu_eff_mom_sel->SetContourLevel(2,0);
   h_mu_eff_mom_sel->SetContourLevel(3,0);
   h_mu_eff_mom_sel->SetContourLevel(4,0);
   h_mu_eff_mom_sel->SetContourLevel(5,0);
   h_mu_eff_mom_sel->SetContourLevel(6,0);
   h_mu_eff_mom_sel->SetContourLevel(7,0);
   h_mu_eff_mom_sel->SetContourLevel(8,0);
   h_mu_eff_mom_sel->SetContourLevel(9,0);
   h_mu_eff_mom_sel->SetContourLevel(10,0);
   h_mu_eff_mom_sel->SetContourLevel(11,0);
   h_mu_eff_mom_sel->SetContourLevel(12,0);
   h_mu_eff_mom_sel->SetContourLevel(13,0);
   h_mu_eff_mom_sel->SetContourLevel(14,0);
   h_mu_eff_mom_sel->SetContourLevel(15,0);
   h_mu_eff_mom_sel->SetContourLevel(16,0);
   h_mu_eff_mom_sel->SetContourLevel(17,0);
   h_mu_eff_mom_sel->SetContourLevel(18,0);
   h_mu_eff_mom_sel->SetContourLevel(19,0);
   
   TPaletteAxis *palette = new TPaletteAxis(2.0125,0,2.125,1,h_mu_eff_mom_sel);
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
   h_mu_eff_mom_sel->GetListOfFunctions()->Add(palette,"br");
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("h_mu_eff_mom_sel");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 4      ");
   AText = ptstats->AddText("Mean x =      0");
   AText = ptstats->AddText("Mean y =      0");
   AText = ptstats->AddText("Std Dev x =      0");
   AText = ptstats->AddText("Std Dev y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_mu_eff_mom_sel->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_mu_eff_mom_sel);

   ci = TColor::GetColor("#000099");
   h_mu_eff_mom_sel->SetLineColor(ci);
   h_mu_eff_mom_sel->GetXaxis()->SetTitle("True Muon Momentum [GeV]");
   h_mu_eff_mom_sel->GetXaxis()->SetLabelFont(42);
   h_mu_eff_mom_sel->GetXaxis()->SetLabelSize(0.035);
   h_mu_eff_mom_sel->GetXaxis()->SetTitleSize(0.035);
   h_mu_eff_mom_sel->GetXaxis()->SetTitleFont(42);
   h_mu_eff_mom_sel->GetYaxis()->SetTitle(" Efficiency");
   h_mu_eff_mom_sel->GetYaxis()->SetLabelFont(42);
   h_mu_eff_mom_sel->GetYaxis()->SetLabelSize(0.035);
   h_mu_eff_mom_sel->GetYaxis()->SetTitleSize(0.035);
   h_mu_eff_mom_sel->GetYaxis()->SetTitleFont(42);
   h_mu_eff_mom_sel->GetZaxis()->SetLabelFont(42);
   h_mu_eff_mom_sel->GetZaxis()->SetLabelSize(0.035);
   h_mu_eff_mom_sel->GetZaxis()->SetTitleSize(0.035);
   h_mu_eff_mom_sel->GetZaxis()->SetTitleFont(42);
   h_mu_eff_mom_sel->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.3693103,0.94,0.6306897,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("After Selection");
   pt->Draw();
   c1_n20->Modified();
   c1_n20->cd();
   c1_n20->SetSelected(c1_n20);
}

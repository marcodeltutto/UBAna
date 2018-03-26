void dqdx_trunc_length_muon()
{
//=========Macro generated from canvas: c1_n40/c1_n40
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n40 = new TCanvas("c1_n40", "c1_n40",0,0,700,500);
   c1_n40->SetHighLightColor(2);
   c1_n40->Range(-25000,-87.50001,225000,787.5);
   c1_n40->SetFillColor(0);
   c1_n40->SetBorderMode(0);
   c1_n40->SetBorderSize(2);
   c1_n40->SetFrameBorderMode(0);
   c1_n40->SetFrameBorderMode(0);
   
   TH2D *h_dqdx_trunc_length_muon = new TH2D("h_dqdx_trunc_length_muon","",40,0,200000,40,0,700);
   h_dqdx_trunc_length_muon->SetBinContent(133,1);
   h_dqdx_trunc_length_muon->SetBinContent(139,1);
   h_dqdx_trunc_length_muon->SetBinContent(213,1);
   h_dqdx_trunc_length_muon->SetBinContent(262,1);
   h_dqdx_trunc_length_muon->SetBinContent(306,1);
   h_dqdx_trunc_length_muon->SetBinContent(935,1);
   h_dqdx_trunc_length_muon->SetBinContent(1480,1);
   h_dqdx_trunc_length_muon->SetEntries(7);
   h_dqdx_trunc_length_muon->SetContour(20);
   h_dqdx_trunc_length_muon->SetContourLevel(0,0);
   h_dqdx_trunc_length_muon->SetContourLevel(1,0.05);
   h_dqdx_trunc_length_muon->SetContourLevel(2,0.1);
   h_dqdx_trunc_length_muon->SetContourLevel(3,0.15);
   h_dqdx_trunc_length_muon->SetContourLevel(4,0.2);
   h_dqdx_trunc_length_muon->SetContourLevel(5,0.25);
   h_dqdx_trunc_length_muon->SetContourLevel(6,0.3);
   h_dqdx_trunc_length_muon->SetContourLevel(7,0.35);
   h_dqdx_trunc_length_muon->SetContourLevel(8,0.4);
   h_dqdx_trunc_length_muon->SetContourLevel(9,0.45);
   h_dqdx_trunc_length_muon->SetContourLevel(10,0.5);
   h_dqdx_trunc_length_muon->SetContourLevel(11,0.55);
   h_dqdx_trunc_length_muon->SetContourLevel(12,0.6);
   h_dqdx_trunc_length_muon->SetContourLevel(13,0.65);
   h_dqdx_trunc_length_muon->SetContourLevel(14,0.7);
   h_dqdx_trunc_length_muon->SetContourLevel(15,0.75);
   h_dqdx_trunc_length_muon->SetContourLevel(16,0.8);
   h_dqdx_trunc_length_muon->SetContourLevel(17,0.85);
   h_dqdx_trunc_length_muon->SetContourLevel(18,0.9);
   h_dqdx_trunc_length_muon->SetContourLevel(19,0.95);
   
   TPaletteAxis *palette = new TPaletteAxis(201250,0,212500,700,h_dqdx_trunc_length_muon);
palette->SetLabelColor(1);
palette->SetLabelFont(42);
palette->SetLabelOffset(0.005);
palette->SetLabelSize(0.035);
palette->SetTitleOffset(1);
palette->SetTitleSize(0.035);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#f9f90e");
   palette->SetFillColor(ci);
   palette->SetFillStyle(1001);
   h_dqdx_trunc_length_muon->GetListOfFunctions()->Add(palette,"br");
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("h_dqdx_trunc_length_muon");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 7      ");
   AText = ptstats->AddText("Mean x = 4.404e+04");
   AText = ptstats->AddText("Mean y =  192.9");
   AText = ptstats->AddText("Std Dev x = 1.524e+04");
   AText = ptstats->AddText("Std Dev y =    200");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_dqdx_trunc_length_muon->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_dqdx_trunc_length_muon);

   ci = TColor::GetColor("#990000");
   h_dqdx_trunc_length_muon->SetLineColor(ci);
   h_dqdx_trunc_length_muon->GetXaxis()->SetTitle("Candidate Track <dQ/dx>_{trunc}");
   h_dqdx_trunc_length_muon->GetXaxis()->SetLabelFont(42);
   h_dqdx_trunc_length_muon->GetXaxis()->SetLabelSize(0.035);
   h_dqdx_trunc_length_muon->GetXaxis()->SetTitleSize(0.035);
   h_dqdx_trunc_length_muon->GetXaxis()->SetTitleFont(42);
   h_dqdx_trunc_length_muon->GetYaxis()->SetTitle("Track Length [cm]");
   h_dqdx_trunc_length_muon->GetYaxis()->SetLabelFont(42);
   h_dqdx_trunc_length_muon->GetYaxis()->SetLabelSize(0.035);
   h_dqdx_trunc_length_muon->GetYaxis()->SetTitleSize(0.035);
   h_dqdx_trunc_length_muon->GetYaxis()->SetTitleFont(42);
   h_dqdx_trunc_length_muon->GetZaxis()->SetLabelFont(42);
   h_dqdx_trunc_length_muon->GetZaxis()->SetLabelSize(0.035);
   h_dqdx_trunc_length_muon->GetZaxis()->SetTitleSize(0.035);
   h_dqdx_trunc_length_muon->GetZaxis()->SetTitleFont(42);
   h_dqdx_trunc_length_muon->Draw("colz");
   c1_n40->Modified();
   c1_n40->cd();
   c1_n40->SetSelected(c1_n40);
}

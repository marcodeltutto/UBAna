void dqdx_trunc_length()
{
//=========Macro generated from canvas: c1_n39/c1_n39
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n39 = new TCanvas("c1_n39", "c1_n39",0,0,700,500);
   c1_n39->SetHighLightColor(2);
   c1_n39->Range(-25000,-87.50001,225000,787.5);
   c1_n39->SetFillColor(0);
   c1_n39->SetBorderMode(0);
   c1_n39->SetBorderSize(2);
   c1_n39->SetFrameBorderMode(0);
   c1_n39->SetFrameBorderMode(0);
   
   TH2D *h_dqdx_trunc_length_muon__5 = new TH2D("h_dqdx_trunc_length_muon__5","",40,0,200000,40,0,700);
   h_dqdx_trunc_length_muon__5->SetBinContent(133,1);
   h_dqdx_trunc_length_muon__5->SetBinContent(139,1);
   h_dqdx_trunc_length_muon__5->SetBinContent(213,1);
   h_dqdx_trunc_length_muon__5->SetBinContent(262,1);
   h_dqdx_trunc_length_muon__5->SetBinContent(306,1);
   h_dqdx_trunc_length_muon__5->SetBinContent(935,1);
   h_dqdx_trunc_length_muon__5->SetBinContent(1480,1);
   h_dqdx_trunc_length_muon__5->SetEntries(7);
   
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
   h_dqdx_trunc_length_muon__5->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_dqdx_trunc_length_muon__5);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990000");
   h_dqdx_trunc_length_muon__5->SetLineColor(ci);
   h_dqdx_trunc_length_muon__5->GetXaxis()->SetTitle("Candidate Track <dQ/dx>_{trunc}");
   h_dqdx_trunc_length_muon__5->GetXaxis()->SetLabelFont(42);
   h_dqdx_trunc_length_muon__5->GetXaxis()->SetLabelSize(0.035);
   h_dqdx_trunc_length_muon__5->GetXaxis()->SetTitleSize(0.035);
   h_dqdx_trunc_length_muon__5->GetXaxis()->SetTitleFont(42);
   h_dqdx_trunc_length_muon__5->GetYaxis()->SetTitle("Track Length [cm]");
   h_dqdx_trunc_length_muon__5->GetYaxis()->SetLabelFont(42);
   h_dqdx_trunc_length_muon__5->GetYaxis()->SetLabelSize(0.035);
   h_dqdx_trunc_length_muon__5->GetYaxis()->SetTitleSize(0.035);
   h_dqdx_trunc_length_muon__5->GetYaxis()->SetTitleFont(42);
   h_dqdx_trunc_length_muon__5->GetZaxis()->SetLabelFont(42);
   h_dqdx_trunc_length_muon__5->GetZaxis()->SetLabelSize(0.035);
   h_dqdx_trunc_length_muon__5->GetZaxis()->SetTitleSize(0.035);
   h_dqdx_trunc_length_muon__5->GetZaxis()->SetTitleFont(42);
   h_dqdx_trunc_length_muon__5->Draw("BOX");
   
   TH2D *h_dqdx_trunc_length_proton__6 = new TH2D("h_dqdx_trunc_length_proton__6","",40,0,200000,40,0,700);

   ci = TColor::GetColor("#000099");
   h_dqdx_trunc_length_proton__6->SetLineColor(ci);
   h_dqdx_trunc_length_proton__6->GetXaxis()->SetTitle("Candidate Track <dQ/dx>_{trunc}");
   h_dqdx_trunc_length_proton__6->GetXaxis()->SetLabelFont(42);
   h_dqdx_trunc_length_proton__6->GetXaxis()->SetLabelSize(0.035);
   h_dqdx_trunc_length_proton__6->GetXaxis()->SetTitleSize(0.035);
   h_dqdx_trunc_length_proton__6->GetXaxis()->SetTitleFont(42);
   h_dqdx_trunc_length_proton__6->GetYaxis()->SetTitle("Track Length [cm]");
   h_dqdx_trunc_length_proton__6->GetYaxis()->SetLabelFont(42);
   h_dqdx_trunc_length_proton__6->GetYaxis()->SetLabelSize(0.035);
   h_dqdx_trunc_length_proton__6->GetYaxis()->SetTitleSize(0.035);
   h_dqdx_trunc_length_proton__6->GetYaxis()->SetTitleFont(42);
   h_dqdx_trunc_length_proton__6->GetZaxis()->SetLabelFont(42);
   h_dqdx_trunc_length_proton__6->GetZaxis()->SetLabelSize(0.035);
   h_dqdx_trunc_length_proton__6->GetZaxis()->SetTitleSize(0.035);
   h_dqdx_trunc_length_proton__6->GetZaxis()->SetTitleFont(42);
   h_dqdx_trunc_length_proton__6->Draw("BOX same");
   c1_n39->Modified();
   c1_n39->cd();
   c1_n39->SetSelected(c1_n39);
}

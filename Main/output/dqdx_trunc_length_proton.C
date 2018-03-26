void dqdx_trunc_length_proton()
{
//=========Macro generated from canvas: c1_n41/c1_n41
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n41 = new TCanvas("c1_n41", "c1_n41",0,0,700,500);
   c1_n41->SetHighLightColor(2);
   c1_n41->Range(-25000,-87.50001,225000,787.5);
   c1_n41->SetFillColor(0);
   c1_n41->SetBorderMode(0);
   c1_n41->SetBorderSize(2);
   c1_n41->SetFrameBorderMode(0);
   c1_n41->SetFrameBorderMode(0);
   
   TH2D *h_dqdx_trunc_length_proton = new TH2D("h_dqdx_trunc_length_proton","",40,0,200000,40,0,700);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("h_dqdx_trunc_length_proton");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 0      ");
   AText = ptstats->AddText("Mean x =      0");
   AText = ptstats->AddText("Mean y =      0");
   AText = ptstats->AddText("Std Dev x =      0");
   AText = ptstats->AddText("Std Dev y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_dqdx_trunc_length_proton->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_dqdx_trunc_length_proton);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h_dqdx_trunc_length_proton->SetLineColor(ci);
   h_dqdx_trunc_length_proton->GetXaxis()->SetTitle("Candidate Track <dQ/dx>_{trunc}");
   h_dqdx_trunc_length_proton->GetXaxis()->SetLabelFont(42);
   h_dqdx_trunc_length_proton->GetXaxis()->SetLabelSize(0.035);
   h_dqdx_trunc_length_proton->GetXaxis()->SetTitleSize(0.035);
   h_dqdx_trunc_length_proton->GetXaxis()->SetTitleFont(42);
   h_dqdx_trunc_length_proton->GetYaxis()->SetTitle("Track Length [cm]");
   h_dqdx_trunc_length_proton->GetYaxis()->SetLabelFont(42);
   h_dqdx_trunc_length_proton->GetYaxis()->SetLabelSize(0.035);
   h_dqdx_trunc_length_proton->GetYaxis()->SetTitleSize(0.035);
   h_dqdx_trunc_length_proton->GetYaxis()->SetTitleFont(42);
   h_dqdx_trunc_length_proton->GetZaxis()->SetLabelFont(42);
   h_dqdx_trunc_length_proton->GetZaxis()->SetLabelSize(0.035);
   h_dqdx_trunc_length_proton->GetZaxis()->SetTitleSize(0.035);
   h_dqdx_trunc_length_proton->GetZaxis()->SetTitleFont(42);
   h_dqdx_trunc_length_proton->Draw("colz");
   c1_n41->Modified();
   c1_n41->cd();
   c1_n41->SetSelected(c1_n41);
}

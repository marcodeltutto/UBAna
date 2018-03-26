void vtxcheck()
{
//=========Macro generated from canvas: c1_n18/c1_n18
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n18 = new TCanvas("c1_n18", "c1_n18",0,0,700,500);
   c1_n18->SetHighLightColor(2);
   c1_n18->Range(-0.5,-0.0328125,4.5,0.2953125);
   c1_n18->SetFillColor(0);
   c1_n18->SetBorderMode(0);
   c1_n18->SetBorderSize(2);
   c1_n18->SetFrameBorderMode(0);
   c1_n18->SetFrameBorderMode(0);
   
   TH1D *h_vtxcheck_angle_good__3 = new TH1D("h_vtxcheck_angle_good__3","",100,0,4);
   h_vtxcheck_angle_good__3->SetBinContent(0,0.75);
   h_vtxcheck_angle_good__3->SetBinContent(18,0.125);
   h_vtxcheck_angle_good__3->SetBinContent(46,0.125);
   h_vtxcheck_angle_good__3->SetBinContent(48,0.125);
   h_vtxcheck_angle_good__3->SetBinContent(49,0.25);
   h_vtxcheck_angle_good__3->SetBinContent(56,0.125);
   h_vtxcheck_angle_good__3->SetBinContent(58,0.125);
   h_vtxcheck_angle_good__3->SetBinContent(77,0.125);
   h_vtxcheck_angle_good__3->SetEntries(14);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("h_vtxcheck_angle_good");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 14     ");
   AText = ptstats->AddText("Mean  =  1.985");
   AText = ptstats->AddText("Std Dev   = 0.6106");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_vtxcheck_angle_good__3->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_vtxcheck_angle_good__3);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h_vtxcheck_angle_good__3->SetLineColor(ci);
   h_vtxcheck_angle_good__3->GetXaxis()->SetTitle("Angle [rad]");
   h_vtxcheck_angle_good__3->GetXaxis()->SetLabelFont(42);
   h_vtxcheck_angle_good__3->GetXaxis()->SetLabelSize(0.035);
   h_vtxcheck_angle_good__3->GetXaxis()->SetTitleSize(0.035);
   h_vtxcheck_angle_good__3->GetXaxis()->SetTitleFont(42);
   h_vtxcheck_angle_good__3->GetYaxis()->SetTitle("Entries per bin");
   h_vtxcheck_angle_good__3->GetYaxis()->SetLabelFont(42);
   h_vtxcheck_angle_good__3->GetYaxis()->SetLabelSize(0.035);
   h_vtxcheck_angle_good__3->GetYaxis()->SetTitleSize(0.035);
   h_vtxcheck_angle_good__3->GetYaxis()->SetTitleFont(42);
   h_vtxcheck_angle_good__3->GetZaxis()->SetLabelFont(42);
   h_vtxcheck_angle_good__3->GetZaxis()->SetLabelSize(0.035);
   h_vtxcheck_angle_good__3->GetZaxis()->SetTitleSize(0.035);
   h_vtxcheck_angle_good__3->GetZaxis()->SetTitleFont(42);
   h_vtxcheck_angle_good__3->Draw("histo");
   
   TH1D *h_vtxcheck_angle_bad__4 = new TH1D("h_vtxcheck_angle_bad__4","",100,0,4);
   h_vtxcheck_angle_bad__4->SetBinContent(0,6.384615);
   h_vtxcheck_angle_bad__4->SetBinContent(24,0.07692308);
   h_vtxcheck_angle_bad__4->SetBinContent(27,0.07692308);
   h_vtxcheck_angle_bad__4->SetBinContent(30,0.07692308);
   h_vtxcheck_angle_bad__4->SetBinContent(39,0.07692308);
   h_vtxcheck_angle_bad__4->SetBinContent(57,0.07692308);
   h_vtxcheck_angle_bad__4->SetBinContent(71,0.07692308);
   h_vtxcheck_angle_bad__4->SetBinContent(74,0.07692308);
   h_vtxcheck_angle_bad__4->SetBinContent(75,0.07692308);
   h_vtxcheck_angle_bad__4->SetBinContent(77,0.07692308);
   h_vtxcheck_angle_bad__4->SetBinContent(78,0.1538462);
   h_vtxcheck_angle_bad__4->SetBinContent(79,0.1538462);
   h_vtxcheck_angle_bad__4->SetEntries(96);

   ci = TColor::GetColor("#ff0000");
   h_vtxcheck_angle_bad__4->SetLineColor(ci);
   h_vtxcheck_angle_bad__4->GetXaxis()->SetTitle("Angle [rad]");
   h_vtxcheck_angle_bad__4->GetXaxis()->SetLabelFont(42);
   h_vtxcheck_angle_bad__4->GetXaxis()->SetLabelSize(0.035);
   h_vtxcheck_angle_bad__4->GetXaxis()->SetTitleSize(0.035);
   h_vtxcheck_angle_bad__4->GetXaxis()->SetTitleFont(42);
   h_vtxcheck_angle_bad__4->GetYaxis()->SetTitle("Entries per bin");
   h_vtxcheck_angle_bad__4->GetYaxis()->SetLabelFont(42);
   h_vtxcheck_angle_bad__4->GetYaxis()->SetLabelSize(0.035);
   h_vtxcheck_angle_bad__4->GetYaxis()->SetTitleSize(0.035);
   h_vtxcheck_angle_bad__4->GetYaxis()->SetTitleFont(42);
   h_vtxcheck_angle_bad__4->GetZaxis()->SetLabelFont(42);
   h_vtxcheck_angle_bad__4->GetZaxis()->SetLabelSize(0.035);
   h_vtxcheck_angle_bad__4->GetZaxis()->SetTitleSize(0.035);
   h_vtxcheck_angle_bad__4->GetZaxis()->SetTitleFont(42);
   h_vtxcheck_angle_bad__4->Draw("histo same");
   
   TLegend *leg = new TLegend(0.1,0.7,0.48,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("h_vtxcheck_angle_good","Signal","l");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_vtxcheck_angle_bad","Background","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c1_n18->Modified();
   c1_n18->cd();
   c1_n18->SetSelected(c1_n18);
}

void eff_pur_graph_percut()
{
//=========Macro generated from canvas: c1_n50/c1_n50
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n50 = new TCanvas("c1_n50", "c1_n50",0,0,700,500);
   c1_n50->SetHighLightColor(2);
   c1_n50->Range(-1.125,-0.125,10.125,1.125);
   c1_n50->SetFillColor(0);
   c1_n50->SetBorderMode(0);
   c1_n50->SetBorderSize(2);
   c1_n50->SetFrameBorderMode(0);
   c1_n50->SetFrameBorderMode(0);
   
   TH1F *h__14 = new TH1F("h__14","",9,0,9);
   h__14->SetMaximum(1);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("h");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 0      ");
   AText = ptstats->AddText("Mean  =      0");
   AText = ptstats->AddText("Std Dev   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h__14->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h__14);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h__14->SetLineColor(ci);
   h__14->GetXaxis()->SetBinLabel(1,"initial");
   h__14->GetXaxis()->SetBinLabel(2,"beamflash");
   h__14->GetXaxis()->SetBinLabel(3,"flash_match");
   h__14->GetXaxis()->SetBinLabel(4,"flash_match_deltax");
   h__14->GetXaxis()->SetBinLabel(5,"flash_match_deltaz");
   h__14->GetXaxis()->SetBinLabel(6,"quality");
   h__14->GetXaxis()->SetBinLabel(7,"mcs_length_quality");
   h__14->GetXaxis()->SetBinLabel(8,"mip_consistency");
   h__14->GetXaxis()->SetBinLabel(9,"fiducial_volume");
   h__14->GetXaxis()->SetLabelFont(42);
   h__14->GetXaxis()->SetLabelSize(0.035);
   h__14->GetXaxis()->SetTitleSize(0.035);
   h__14->GetXaxis()->SetTitleFont(42);
   h__14->GetYaxis()->SetLabelFont(42);
   h__14->GetYaxis()->SetLabelSize(0.035);
   h__14->GetYaxis()->SetTitleSize(0.035);
   h__14->GetYaxis()->SetTitleFont(42);
   h__14->GetZaxis()->SetLabelFont(42);
   h__14->GetZaxis()->SetLabelSize(0.035);
   h__14->GetZaxis()->SetTitleSize(0.035);
   h__14->GetZaxis()->SetTitleFont(42);
   h__14->Draw("");
   
   Double_t eff_graph_fx3001[9] = {
   0.5,
   1.5,
   2.5,
   3.5,
   4.5,
   5.5,
   6.5,
   7.5,
   8.5};
   Double_t eff_graph_fy3001[9] = {
   1,
   1,
   0.5625,
   0.5,
   0.5,
   0.5,
   0.25,
   0.25,
   0.25};
   Double_t eff_graph_felx3001[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t eff_graph_fely3001[9] = {
   0.1086908,
   0.1086908,
   0.1541179,
   0.1503559,
   0.1503559,
   0.1503559,
   0.1154987,
   0.1154987,
   0.1154987};
   Double_t eff_graph_fehx3001[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t eff_graph_fehy3001[9] = {
   0,
   0,
   0.1447615,
   0.1503559,
   0.1503559,
   0.1503559,
   0.153966,
   0.153966,
   0.153966};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(9,eff_graph_fx3001,eff_graph_fy3001,eff_graph_felx3001,eff_graph_fehx3001,eff_graph_fely3001,eff_graph_fehy3001);
   grae->SetName("eff_graph");
   grae->SetTitle("EfficiencyPerCut");
   grae->SetFillColor(19);

   ci = TColor::GetColor("#006600");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#006600");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(0.6);
   
   TH1F *Graph_eff_graph3001 = new TH1F("Graph_eff_graph3001","EfficiencyPerCut",100,0,9.9);
   Graph_eff_graph3001->SetMinimum(0.04795138);
   Graph_eff_graph3001->SetMaximum(1.08655);
   Graph_eff_graph3001->SetDirectory(0);
   Graph_eff_graph3001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_eff_graph3001->SetLineColor(ci);
   Graph_eff_graph3001->GetXaxis()->SetTitle("Cut index");
   Graph_eff_graph3001->GetXaxis()->SetBinLabel(1,"initial");
   Graph_eff_graph3001->GetXaxis()->SetBinLabel(2,"beamflash");
   Graph_eff_graph3001->GetXaxis()->SetBinLabel(3,"flash_match");
   Graph_eff_graph3001->GetXaxis()->SetBinLabel(4,"flash_match_deltax");
   Graph_eff_graph3001->GetXaxis()->SetBinLabel(5,"flash_match_deltaz");
   Graph_eff_graph3001->GetXaxis()->SetBinLabel(6,"quality");
   Graph_eff_graph3001->GetXaxis()->SetBinLabel(7,"mcs_length_quality");
   Graph_eff_graph3001->GetXaxis()->SetBinLabel(8,"mip_consistency");
   Graph_eff_graph3001->GetXaxis()->SetBinLabel(9,"fiducial_volume");
   Graph_eff_graph3001->GetXaxis()->SetLabelFont(42);
   Graph_eff_graph3001->GetXaxis()->SetLabelSize(0.035);
   Graph_eff_graph3001->GetXaxis()->SetTitleSize(0.035);
   Graph_eff_graph3001->GetXaxis()->SetTitleFont(42);
   Graph_eff_graph3001->GetYaxis()->SetTitle("Efficiency");
   Graph_eff_graph3001->GetYaxis()->SetLabelFont(42);
   Graph_eff_graph3001->GetYaxis()->SetLabelSize(0.035);
   Graph_eff_graph3001->GetYaxis()->SetTitleSize(0.035);
   Graph_eff_graph3001->GetYaxis()->SetTitleFont(42);
   Graph_eff_graph3001->GetZaxis()->SetLabelFont(42);
   Graph_eff_graph3001->GetZaxis()->SetLabelSize(0.035);
   Graph_eff_graph3001->GetZaxis()->SetTitleSize(0.035);
   Graph_eff_graph3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_eff_graph3001);
   
   grae->Draw("pl");
   
   Double_t eff_graph_fx3002[9] = {
   0.5,
   1.5,
   2.5,
   3.5,
   4.5,
   5.5,
   6.5,
   7.5,
   8.5};
   Double_t eff_graph_fy3002[9] = {
   0.16,
   0.2162162,
   0.2432432,
   0.25,
   0.2666667,
   0.2962963,
   0.1818182,
   0.1904762,
   0.4};
   Double_t eff_graph_felx3002[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t eff_graph_fely3002[9] = {
   0.03768879,
   0.04995537,
   0.07481152,
   0.0815095,
   0.08654495,
   0.09535641,
   0.08488854,
   0.08881574,
   0.1800093};
   Double_t eff_graph_fehx3002[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t eff_graph_fehy3002[9] = {
   0.04536549,
   0.05862976,
   0.09104277,
   0.09991808,
   0.1048799,
   0.1131584,
   0.1205888,
   0.125184,
   0.2045969};
   grae = new TGraphAsymmErrors(9,eff_graph_fx3002,eff_graph_fy3002,eff_graph_felx3002,eff_graph_fehx3002,eff_graph_fely3002,eff_graph_fehy3002);
   grae->SetName("eff_graph");
   grae->SetTitle("PurityPerCut");
   grae->SetFillColor(19);

   ci = TColor::GetColor("#660000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#660000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(0.6);
   
   TH1F *Graph_eff_graph3002 = new TH1F("Graph_eff_graph3002","PurityPerCut",100,0,9.9);
   Graph_eff_graph3002->SetMinimum(0.04616292);
   Graph_eff_graph3002->SetMaximum(0.6553636);
   Graph_eff_graph3002->SetDirectory(0);
   Graph_eff_graph3002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_eff_graph3002->SetLineColor(ci);
   Graph_eff_graph3002->GetXaxis()->SetTitle("Cut index");
   Graph_eff_graph3002->GetXaxis()->SetLabelFont(42);
   Graph_eff_graph3002->GetXaxis()->SetLabelSize(0.035);
   Graph_eff_graph3002->GetXaxis()->SetTitleSize(0.035);
   Graph_eff_graph3002->GetXaxis()->SetTitleFont(42);
   Graph_eff_graph3002->GetYaxis()->SetTitle("Purity");
   Graph_eff_graph3002->GetYaxis()->SetLabelFont(42);
   Graph_eff_graph3002->GetYaxis()->SetLabelSize(0.035);
   Graph_eff_graph3002->GetYaxis()->SetTitleSize(0.035);
   Graph_eff_graph3002->GetYaxis()->SetTitleFont(42);
   Graph_eff_graph3002->GetZaxis()->SetLabelFont(42);
   Graph_eff_graph3002->GetZaxis()->SetLabelSize(0.035);
   Graph_eff_graph3002->GetZaxis()->SetTitleSize(0.035);
   Graph_eff_graph3002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_eff_graph3002);
   
   grae->Draw("pl");
   
   TLegend *leg = new TLegend(0.6002865,0.2105263,0.8939828,0.3157895,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("eff_graph","Efficiency","lpf");
   entry->SetFillColor(19);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#006600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#006600");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.6);
   entry->SetTextFont(42);
   entry=leg->AddEntry("eff_graph","Purity","lpf");
   entry->SetFillColor(19);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#660000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#660000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.6);
   entry->SetTextFont(42);
   leg->Draw();
   c1_n50->Modified();
   c1_n50->cd();
   c1_n50->SetSelected(c1_n50);
}

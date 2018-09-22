void smearing_matrix_true_11()
{
//=========Macro generated from canvas: c1_n12/c1_n12
//=========  (Sat Sep 22 12:03:55 2018) by ROOT version6.06/06
   TCanvas *c1_n12 = new TCanvas("c1_n12", "c1_n12",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n12->SetHighLightColor(2);
   c1_n12->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n12->SetFillColor(10);
   c1_n12->SetBorderMode(0);
   c1_n12->SetBorderSize(2);
   c1_n12->SetFrameLineWidth(2);
   c1_n12->SetFrameBorderMode(0);
   c1_n12->SetFrameLineWidth(2);
   c1_n12->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 11", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx342[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy342[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx342,Graph_fy342);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00138d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph342 = new TH1F("Graph_Graph342","Graph",100,-1.1,0);
   Graph_Graph342->SetMinimum(0);
   Graph_Graph342->SetMaximum(0.33);
   Graph_Graph342->SetDirectory(0);
   Graph_Graph342->SetStats(0);
   Graph_Graph342->SetLineWidth(2);
   Graph_Graph342->GetXaxis()->SetNdivisions(506);
   Graph_Graph342->GetXaxis()->SetLabelFont(42);
   Graph_Graph342->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph342->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph342->GetXaxis()->SetTitleFont(42);
   Graph_Graph342->GetYaxis()->SetNdivisions(506);
   Graph_Graph342->GetYaxis()->SetLabelFont(42);
   Graph_Graph342->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph342->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph342->GetYaxis()->SetTitleFont(42);
   Graph_Graph342->GetZaxis()->SetNdivisions(506);
   Graph_Graph342->GetZaxis()->SetLabelFont(42);
   Graph_Graph342->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph342->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph342->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph342);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx343[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy343[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx343,Graph_fy343);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph343 = new TH1F("Graph_Graph343","Graph",100,0,0.297);
   Graph_Graph343->SetMinimum(0);
   Graph_Graph343->SetMaximum(0.33);
   Graph_Graph343->SetDirectory(0);
   Graph_Graph343->SetStats(0);
   Graph_Graph343->SetLineWidth(2);
   Graph_Graph343->GetXaxis()->SetNdivisions(506);
   Graph_Graph343->GetXaxis()->SetLabelFont(42);
   Graph_Graph343->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph343->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph343->GetXaxis()->SetTitleFont(42);
   Graph_Graph343->GetYaxis()->SetNdivisions(506);
   Graph_Graph343->GetYaxis()->SetLabelFont(42);
   Graph_Graph343->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph343->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph343->GetYaxis()->SetTitleFont(42);
   Graph_Graph343->GetZaxis()->SetNdivisions(506);
   Graph_Graph343->GetZaxis()->SetLabelFont(42);
   Graph_Graph343->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph343->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph343->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph343);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx344[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy344[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx344,Graph_fy344);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph344 = new TH1F("Graph_Graph344","Graph",100,0.252,0.468);
   Graph_Graph344->SetMinimum(0);
   Graph_Graph344->SetMaximum(0.33);
   Graph_Graph344->SetDirectory(0);
   Graph_Graph344->SetStats(0);
   Graph_Graph344->SetLineWidth(2);
   Graph_Graph344->GetXaxis()->SetNdivisions(506);
   Graph_Graph344->GetXaxis()->SetLabelFont(42);
   Graph_Graph344->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph344->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph344->GetXaxis()->SetTitleFont(42);
   Graph_Graph344->GetYaxis()->SetNdivisions(506);
   Graph_Graph344->GetYaxis()->SetLabelFont(42);
   Graph_Graph344->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph344->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph344->GetYaxis()->SetTitleFont(42);
   Graph_Graph344->GetZaxis()->SetNdivisions(506);
   Graph_Graph344->GetZaxis()->SetLabelFont(42);
   Graph_Graph344->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph344->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph344->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph344);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx345[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy345[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx345,Graph_fy345);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#005dba");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph345 = new TH1F("Graph_Graph345","Graph",100,0.433,0.637);
   Graph_Graph345->SetMinimum(0);
   Graph_Graph345->SetMaximum(0.33);
   Graph_Graph345->SetDirectory(0);
   Graph_Graph345->SetStats(0);
   Graph_Graph345->SetLineWidth(2);
   Graph_Graph345->GetXaxis()->SetNdivisions(506);
   Graph_Graph345->GetXaxis()->SetLabelFont(42);
   Graph_Graph345->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph345->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph345->GetXaxis()->SetTitleFont(42);
   Graph_Graph345->GetYaxis()->SetNdivisions(506);
   Graph_Graph345->GetYaxis()->SetLabelFont(42);
   Graph_Graph345->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph345->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph345->GetYaxis()->SetTitleFont(42);
   Graph_Graph345->GetZaxis()->SetNdivisions(506);
   Graph_Graph345->GetZaxis()->SetLabelFont(42);
   Graph_Graph345->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph345->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph345->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph345);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx346[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy346[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx346,Graph_fy346);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph346 = new TH1F("Graph_Graph346","Graph",100,0.606,0.774);
   Graph_Graph346->SetMinimum(0);
   Graph_Graph346->SetMaximum(0.33);
   Graph_Graph346->SetDirectory(0);
   Graph_Graph346->SetStats(0);
   Graph_Graph346->SetLineWidth(2);
   Graph_Graph346->GetXaxis()->SetNdivisions(506);
   Graph_Graph346->GetXaxis()->SetLabelFont(42);
   Graph_Graph346->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph346->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph346->GetXaxis()->SetTitleFont(42);
   Graph_Graph346->GetYaxis()->SetNdivisions(506);
   Graph_Graph346->GetYaxis()->SetLabelFont(42);
   Graph_Graph346->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph346->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph346->GetYaxis()->SetTitleFont(42);
   Graph_Graph346->GetZaxis()->SetNdivisions(506);
   Graph_Graph346->GetZaxis()->SetLabelFont(42);
   Graph_Graph346->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph346->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph346->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph346);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx347[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy347[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx347,Graph_fy347);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph347 = new TH1F("Graph_Graph347","Graph",100,0.75,0.87);
   Graph_Graph347->SetMinimum(0);
   Graph_Graph347->SetMaximum(0.33);
   Graph_Graph347->SetDirectory(0);
   Graph_Graph347->SetStats(0);
   Graph_Graph347->SetLineWidth(2);
   Graph_Graph347->GetXaxis()->SetNdivisions(506);
   Graph_Graph347->GetXaxis()->SetLabelFont(42);
   Graph_Graph347->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph347->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph347->GetXaxis()->SetTitleFont(42);
   Graph_Graph347->GetYaxis()->SetNdivisions(506);
   Graph_Graph347->GetYaxis()->SetLabelFont(42);
   Graph_Graph347->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph347->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph347->GetYaxis()->SetTitleFont(42);
   Graph_Graph347->GetZaxis()->SetNdivisions(506);
   Graph_Graph347->GetZaxis()->SetLabelFont(42);
   Graph_Graph347->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph347->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph347->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph347);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx348[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy348[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx348,Graph_fy348);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph348 = new TH1F("Graph_Graph348","Graph",100,0.852,0.948);
   Graph_Graph348->SetMinimum(0);
   Graph_Graph348->SetMaximum(0.33);
   Graph_Graph348->SetDirectory(0);
   Graph_Graph348->SetStats(0);
   Graph_Graph348->SetLineWidth(2);
   Graph_Graph348->GetXaxis()->SetNdivisions(506);
   Graph_Graph348->GetXaxis()->SetLabelFont(42);
   Graph_Graph348->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph348->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph348->GetXaxis()->SetTitleFont(42);
   Graph_Graph348->GetYaxis()->SetNdivisions(506);
   Graph_Graph348->GetYaxis()->SetLabelFont(42);
   Graph_Graph348->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph348->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph348->GetYaxis()->SetTitleFont(42);
   Graph_Graph348->GetZaxis()->SetNdivisions(506);
   Graph_Graph348->GetZaxis()->SetLabelFont(42);
   Graph_Graph348->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph348->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph348->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph348);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx349[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy349[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx349,Graph_fy349);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph349 = new TH1F("Graph_Graph349","Graph",100,0.934,1.006);
   Graph_Graph349->SetMinimum(0);
   Graph_Graph349->SetMaximum(0.33);
   Graph_Graph349->SetDirectory(0);
   Graph_Graph349->SetStats(0);
   Graph_Graph349->SetLineWidth(2);
   Graph_Graph349->GetXaxis()->SetNdivisions(506);
   Graph_Graph349->GetXaxis()->SetLabelFont(42);
   Graph_Graph349->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph349->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph349->GetXaxis()->SetTitleFont(42);
   Graph_Graph349->GetYaxis()->SetNdivisions(506);
   Graph_Graph349->GetYaxis()->SetLabelFont(42);
   Graph_Graph349->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph349->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph349->GetYaxis()->SetTitleFont(42);
   Graph_Graph349->GetZaxis()->SetNdivisions(506);
   Graph_Graph349->GetZaxis()->SetLabelFont(42);
   Graph_Graph349->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph349->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph349->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph349);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx350[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy350[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx350,Graph_fy350);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph350 = new TH1F("Graph_Graph350","Graph",100,-1.1,0);
   Graph_Graph350->SetMinimum(0.285);
   Graph_Graph350->SetMaximum(0.465);
   Graph_Graph350->SetDirectory(0);
   Graph_Graph350->SetStats(0);
   Graph_Graph350->SetLineWidth(2);
   Graph_Graph350->GetXaxis()->SetNdivisions(506);
   Graph_Graph350->GetXaxis()->SetLabelFont(42);
   Graph_Graph350->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph350->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph350->GetXaxis()->SetTitleFont(42);
   Graph_Graph350->GetYaxis()->SetNdivisions(506);
   Graph_Graph350->GetYaxis()->SetLabelFont(42);
   Graph_Graph350->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph350->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph350->GetYaxis()->SetTitleFont(42);
   Graph_Graph350->GetZaxis()->SetNdivisions(506);
   Graph_Graph350->GetZaxis()->SetLabelFont(42);
   Graph_Graph350->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph350->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph350->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph350);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx351[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy351[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx351,Graph_fy351);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph351 = new TH1F("Graph_Graph351","Graph",100,0,0.297);
   Graph_Graph351->SetMinimum(0.285);
   Graph_Graph351->SetMaximum(0.465);
   Graph_Graph351->SetDirectory(0);
   Graph_Graph351->SetStats(0);
   Graph_Graph351->SetLineWidth(2);
   Graph_Graph351->GetXaxis()->SetNdivisions(506);
   Graph_Graph351->GetXaxis()->SetLabelFont(42);
   Graph_Graph351->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph351->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph351->GetXaxis()->SetTitleFont(42);
   Graph_Graph351->GetYaxis()->SetNdivisions(506);
   Graph_Graph351->GetYaxis()->SetLabelFont(42);
   Graph_Graph351->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph351->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph351->GetYaxis()->SetTitleFont(42);
   Graph_Graph351->GetZaxis()->SetNdivisions(506);
   Graph_Graph351->GetZaxis()->SetLabelFont(42);
   Graph_Graph351->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph351->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph351->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph351);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx352[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy352[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx352,Graph_fy352);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0090d9");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph352 = new TH1F("Graph_Graph352","Graph",100,0.252,0.468);
   Graph_Graph352->SetMinimum(0.285);
   Graph_Graph352->SetMaximum(0.465);
   Graph_Graph352->SetDirectory(0);
   Graph_Graph352->SetStats(0);
   Graph_Graph352->SetLineWidth(2);
   Graph_Graph352->GetXaxis()->SetNdivisions(506);
   Graph_Graph352->GetXaxis()->SetLabelFont(42);
   Graph_Graph352->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph352->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph352->GetXaxis()->SetTitleFont(42);
   Graph_Graph352->GetYaxis()->SetNdivisions(506);
   Graph_Graph352->GetYaxis()->SetLabelFont(42);
   Graph_Graph352->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph352->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph352->GetYaxis()->SetTitleFont(42);
   Graph_Graph352->GetZaxis()->SetNdivisions(506);
   Graph_Graph352->GetZaxis()->SetLabelFont(42);
   Graph_Graph352->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph352->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph352->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph352);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx353[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy353[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx353,Graph_fy353);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph353 = new TH1F("Graph_Graph353","Graph",100,0.433,0.637);
   Graph_Graph353->SetMinimum(0.285);
   Graph_Graph353->SetMaximum(0.465);
   Graph_Graph353->SetDirectory(0);
   Graph_Graph353->SetStats(0);
   Graph_Graph353->SetLineWidth(2);
   Graph_Graph353->GetXaxis()->SetNdivisions(506);
   Graph_Graph353->GetXaxis()->SetLabelFont(42);
   Graph_Graph353->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph353->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph353->GetXaxis()->SetTitleFont(42);
   Graph_Graph353->GetYaxis()->SetNdivisions(506);
   Graph_Graph353->GetYaxis()->SetLabelFont(42);
   Graph_Graph353->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph353->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph353->GetYaxis()->SetTitleFont(42);
   Graph_Graph353->GetZaxis()->SetNdivisions(506);
   Graph_Graph353->GetZaxis()->SetLabelFont(42);
   Graph_Graph353->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph353->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph353->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph353);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx354[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy354[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx354,Graph_fy354);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00ceff");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph354 = new TH1F("Graph_Graph354","Graph",100,0.606,0.774);
   Graph_Graph354->SetMinimum(0.285);
   Graph_Graph354->SetMaximum(0.465);
   Graph_Graph354->SetDirectory(0);
   Graph_Graph354->SetStats(0);
   Graph_Graph354->SetLineWidth(2);
   Graph_Graph354->GetXaxis()->SetNdivisions(506);
   Graph_Graph354->GetXaxis()->SetLabelFont(42);
   Graph_Graph354->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph354->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph354->GetXaxis()->SetTitleFont(42);
   Graph_Graph354->GetYaxis()->SetNdivisions(506);
   Graph_Graph354->GetYaxis()->SetLabelFont(42);
   Graph_Graph354->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph354->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph354->GetYaxis()->SetTitleFont(42);
   Graph_Graph354->GetZaxis()->SetNdivisions(506);
   Graph_Graph354->GetZaxis()->SetLabelFont(42);
   Graph_Graph354->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph354->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph354->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph354);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx355[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy355[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx355,Graph_fy355);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph355 = new TH1F("Graph_Graph355","Graph",100,0.75,0.87);
   Graph_Graph355->SetMinimum(0.285);
   Graph_Graph355->SetMaximum(0.465);
   Graph_Graph355->SetDirectory(0);
   Graph_Graph355->SetStats(0);
   Graph_Graph355->SetLineWidth(2);
   Graph_Graph355->GetXaxis()->SetNdivisions(506);
   Graph_Graph355->GetXaxis()->SetLabelFont(42);
   Graph_Graph355->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph355->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph355->GetXaxis()->SetTitleFont(42);
   Graph_Graph355->GetYaxis()->SetNdivisions(506);
   Graph_Graph355->GetYaxis()->SetLabelFont(42);
   Graph_Graph355->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph355->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph355->GetYaxis()->SetTitleFont(42);
   Graph_Graph355->GetZaxis()->SetNdivisions(506);
   Graph_Graph355->GetZaxis()->SetLabelFont(42);
   Graph_Graph355->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph355->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph355->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph355);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx356[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy356[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx356,Graph_fy356);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph356 = new TH1F("Graph_Graph356","Graph",100,0.852,0.948);
   Graph_Graph356->SetMinimum(0.285);
   Graph_Graph356->SetMaximum(0.465);
   Graph_Graph356->SetDirectory(0);
   Graph_Graph356->SetStats(0);
   Graph_Graph356->SetLineWidth(2);
   Graph_Graph356->GetXaxis()->SetNdivisions(506);
   Graph_Graph356->GetXaxis()->SetLabelFont(42);
   Graph_Graph356->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph356->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph356->GetXaxis()->SetTitleFont(42);
   Graph_Graph356->GetYaxis()->SetNdivisions(506);
   Graph_Graph356->GetYaxis()->SetLabelFont(42);
   Graph_Graph356->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph356->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph356->GetYaxis()->SetTitleFont(42);
   Graph_Graph356->GetZaxis()->SetNdivisions(506);
   Graph_Graph356->GetZaxis()->SetLabelFont(42);
   Graph_Graph356->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph356->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph356->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph356);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx357[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy357[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx357,Graph_fy357);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph357 = new TH1F("Graph_Graph357","Graph",100,0.934,1.006);
   Graph_Graph357->SetMinimum(0.285);
   Graph_Graph357->SetMaximum(0.465);
   Graph_Graph357->SetDirectory(0);
   Graph_Graph357->SetStats(0);
   Graph_Graph357->SetLineWidth(2);
   Graph_Graph357->GetXaxis()->SetNdivisions(506);
   Graph_Graph357->GetXaxis()->SetLabelFont(42);
   Graph_Graph357->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph357->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph357->GetXaxis()->SetTitleFont(42);
   Graph_Graph357->GetYaxis()->SetNdivisions(506);
   Graph_Graph357->GetYaxis()->SetLabelFont(42);
   Graph_Graph357->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph357->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph357->GetYaxis()->SetTitleFont(42);
   Graph_Graph357->GetZaxis()->SetNdivisions(506);
   Graph_Graph357->GetZaxis()->SetLabelFont(42);
   Graph_Graph357->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph357->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph357->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph357);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx358[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy358[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx358,Graph_fy358);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph358 = new TH1F("Graph_Graph358","Graph",100,-1.1,0);
   Graph_Graph358->SetMinimum(0.245);
   Graph_Graph358->SetMaximum(2.705);
   Graph_Graph358->SetDirectory(0);
   Graph_Graph358->SetStats(0);
   Graph_Graph358->SetLineWidth(2);
   Graph_Graph358->GetXaxis()->SetNdivisions(506);
   Graph_Graph358->GetXaxis()->SetLabelFont(42);
   Graph_Graph358->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph358->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph358->GetXaxis()->SetTitleFont(42);
   Graph_Graph358->GetYaxis()->SetNdivisions(506);
   Graph_Graph358->GetYaxis()->SetLabelFont(42);
   Graph_Graph358->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph358->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph358->GetYaxis()->SetTitleFont(42);
   Graph_Graph358->GetZaxis()->SetNdivisions(506);
   Graph_Graph358->GetZaxis()->SetLabelFont(42);
   Graph_Graph358->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph358->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph358->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph358);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx359[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy359[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx359,Graph_fy359);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph359 = new TH1F("Graph_Graph359","Graph",100,0,0.297);
   Graph_Graph359->SetMinimum(0.418);
   Graph_Graph359->SetMaximum(0.802);
   Graph_Graph359->SetDirectory(0);
   Graph_Graph359->SetStats(0);
   Graph_Graph359->SetLineWidth(2);
   Graph_Graph359->GetXaxis()->SetNdivisions(506);
   Graph_Graph359->GetXaxis()->SetLabelFont(42);
   Graph_Graph359->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph359->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph359->GetXaxis()->SetTitleFont(42);
   Graph_Graph359->GetYaxis()->SetNdivisions(506);
   Graph_Graph359->GetYaxis()->SetLabelFont(42);
   Graph_Graph359->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph359->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph359->GetYaxis()->SetTitleFont(42);
   Graph_Graph359->GetZaxis()->SetNdivisions(506);
   Graph_Graph359->GetZaxis()->SetLabelFont(42);
   Graph_Graph359->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph359->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph359->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph359);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx360[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy360[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx360,Graph_fy360);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000e8a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph360 = new TH1F("Graph_Graph360","Graph",100,0.252,0.468);
   Graph_Graph360->SetMinimum(0.418);
   Graph_Graph360->SetMaximum(0.802);
   Graph_Graph360->SetDirectory(0);
   Graph_Graph360->SetStats(0);
   Graph_Graph360->SetLineWidth(2);
   Graph_Graph360->GetXaxis()->SetNdivisions(506);
   Graph_Graph360->GetXaxis()->SetLabelFont(42);
   Graph_Graph360->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph360->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph360->GetXaxis()->SetTitleFont(42);
   Graph_Graph360->GetYaxis()->SetNdivisions(506);
   Graph_Graph360->GetYaxis()->SetLabelFont(42);
   Graph_Graph360->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph360->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph360->GetYaxis()->SetTitleFont(42);
   Graph_Graph360->GetZaxis()->SetNdivisions(506);
   Graph_Graph360->GetZaxis()->SetLabelFont(42);
   Graph_Graph360->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph360->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph360->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph360);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx361[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy361[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx361,Graph_fy361);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00afec");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph361 = new TH1F("Graph_Graph361","Graph",100,0.433,0.637);
   Graph_Graph361->SetMinimum(0.418);
   Graph_Graph361->SetMaximum(0.802);
   Graph_Graph361->SetDirectory(0);
   Graph_Graph361->SetStats(0);
   Graph_Graph361->SetLineWidth(2);
   Graph_Graph361->GetXaxis()->SetNdivisions(506);
   Graph_Graph361->GetXaxis()->SetLabelFont(42);
   Graph_Graph361->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph361->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph361->GetXaxis()->SetTitleFont(42);
   Graph_Graph361->GetYaxis()->SetNdivisions(506);
   Graph_Graph361->GetYaxis()->SetLabelFont(42);
   Graph_Graph361->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph361->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph361->GetYaxis()->SetTitleFont(42);
   Graph_Graph361->GetZaxis()->SetNdivisions(506);
   Graph_Graph361->GetZaxis()->SetLabelFont(42);
   Graph_Graph361->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph361->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph361->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph361);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx362[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy362[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx362,Graph_fy362);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002196");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph362 = new TH1F("Graph_Graph362","Graph",100,0.606,0.774);
   Graph_Graph362->SetMinimum(0.418);
   Graph_Graph362->SetMaximum(0.802);
   Graph_Graph362->SetDirectory(0);
   Graph_Graph362->SetStats(0);
   Graph_Graph362->SetLineWidth(2);
   Graph_Graph362->GetXaxis()->SetNdivisions(506);
   Graph_Graph362->GetXaxis()->SetLabelFont(42);
   Graph_Graph362->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph362->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph362->GetXaxis()->SetTitleFont(42);
   Graph_Graph362->GetYaxis()->SetNdivisions(506);
   Graph_Graph362->GetYaxis()->SetLabelFont(42);
   Graph_Graph362->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph362->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph362->GetYaxis()->SetTitleFont(42);
   Graph_Graph362->GetZaxis()->SetNdivisions(506);
   Graph_Graph362->GetZaxis()->SetLabelFont(42);
   Graph_Graph362->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph362->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph362->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph362);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx363[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy363[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx363,Graph_fy363);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph363 = new TH1F("Graph_Graph363","Graph",100,0.75,0.87);
   Graph_Graph363->SetMinimum(0.418);
   Graph_Graph363->SetMaximum(0.802);
   Graph_Graph363->SetDirectory(0);
   Graph_Graph363->SetStats(0);
   Graph_Graph363->SetLineWidth(2);
   Graph_Graph363->GetXaxis()->SetNdivisions(506);
   Graph_Graph363->GetXaxis()->SetLabelFont(42);
   Graph_Graph363->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph363->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph363->GetXaxis()->SetTitleFont(42);
   Graph_Graph363->GetYaxis()->SetNdivisions(506);
   Graph_Graph363->GetYaxis()->SetLabelFont(42);
   Graph_Graph363->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph363->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph363->GetYaxis()->SetTitleFont(42);
   Graph_Graph363->GetZaxis()->SetNdivisions(506);
   Graph_Graph363->GetZaxis()->SetLabelFont(42);
   Graph_Graph363->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph363->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph363->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph363);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx364[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy364[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx364,Graph_fy364);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph364 = new TH1F("Graph_Graph364","Graph",100,0.852,0.948);
   Graph_Graph364->SetMinimum(0.418);
   Graph_Graph364->SetMaximum(0.802);
   Graph_Graph364->SetDirectory(0);
   Graph_Graph364->SetStats(0);
   Graph_Graph364->SetLineWidth(2);
   Graph_Graph364->GetXaxis()->SetNdivisions(506);
   Graph_Graph364->GetXaxis()->SetLabelFont(42);
   Graph_Graph364->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph364->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph364->GetXaxis()->SetTitleFont(42);
   Graph_Graph364->GetYaxis()->SetNdivisions(506);
   Graph_Graph364->GetYaxis()->SetLabelFont(42);
   Graph_Graph364->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph364->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph364->GetYaxis()->SetTitleFont(42);
   Graph_Graph364->GetZaxis()->SetNdivisions(506);
   Graph_Graph364->GetZaxis()->SetLabelFont(42);
   Graph_Graph364->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph364->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph364->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph364);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx365[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy365[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx365,Graph_fy365);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph365 = new TH1F("Graph_Graph365","Graph",100,0.934,1.006);
   Graph_Graph365->SetMinimum(0.418);
   Graph_Graph365->SetMaximum(0.802);
   Graph_Graph365->SetDirectory(0);
   Graph_Graph365->SetStats(0);
   Graph_Graph365->SetLineWidth(2);
   Graph_Graph365->GetXaxis()->SetNdivisions(506);
   Graph_Graph365->GetXaxis()->SetLabelFont(42);
   Graph_Graph365->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph365->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph365->GetXaxis()->SetTitleFont(42);
   Graph_Graph365->GetYaxis()->SetNdivisions(506);
   Graph_Graph365->GetYaxis()->SetLabelFont(42);
   Graph_Graph365->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph365->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph365->GetYaxis()->SetTitleFont(42);
   Graph_Graph365->GetZaxis()->SetNdivisions(506);
   Graph_Graph365->GetZaxis()->SetLabelFont(42);
   Graph_Graph365->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph365->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph365->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph365);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx366[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy366[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx366,Graph_fy366);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph366 = new TH1F("Graph_Graph366","Graph",100,0,0.297);
   Graph_Graph366->SetMinimum(0.597);
   Graph_Graph366->SetMaximum(2.673);
   Graph_Graph366->SetDirectory(0);
   Graph_Graph366->SetStats(0);
   Graph_Graph366->SetLineWidth(2);
   Graph_Graph366->GetXaxis()->SetNdivisions(506);
   Graph_Graph366->GetXaxis()->SetLabelFont(42);
   Graph_Graph366->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph366->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph366->GetXaxis()->SetTitleFont(42);
   Graph_Graph366->GetYaxis()->SetNdivisions(506);
   Graph_Graph366->GetYaxis()->SetLabelFont(42);
   Graph_Graph366->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph366->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph366->GetYaxis()->SetTitleFont(42);
   Graph_Graph366->GetZaxis()->SetNdivisions(506);
   Graph_Graph366->GetZaxis()->SetLabelFont(42);
   Graph_Graph366->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph366->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph366->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph366);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx367[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy367[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx367,Graph_fy367);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph367 = new TH1F("Graph_Graph367","Graph",100,0.252,0.468);
   Graph_Graph367->SetMinimum(0.597);
   Graph_Graph367->SetMaximum(2.673);
   Graph_Graph367->SetDirectory(0);
   Graph_Graph367->SetStats(0);
   Graph_Graph367->SetLineWidth(2);
   Graph_Graph367->GetXaxis()->SetNdivisions(506);
   Graph_Graph367->GetXaxis()->SetLabelFont(42);
   Graph_Graph367->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph367->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph367->GetXaxis()->SetTitleFont(42);
   Graph_Graph367->GetYaxis()->SetNdivisions(506);
   Graph_Graph367->GetYaxis()->SetLabelFont(42);
   Graph_Graph367->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph367->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph367->GetYaxis()->SetTitleFont(42);
   Graph_Graph367->GetZaxis()->SetNdivisions(506);
   Graph_Graph367->GetZaxis()->SetLabelFont(42);
   Graph_Graph367->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph367->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph367->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph367);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx368[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy368[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx368,Graph_fy368);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph368 = new TH1F("Graph_Graph368","Graph",100,0.433,0.637);
   Graph_Graph368->SetMinimum(0.597);
   Graph_Graph368->SetMaximum(2.673);
   Graph_Graph368->SetDirectory(0);
   Graph_Graph368->SetStats(0);
   Graph_Graph368->SetLineWidth(2);
   Graph_Graph368->GetXaxis()->SetNdivisions(506);
   Graph_Graph368->GetXaxis()->SetLabelFont(42);
   Graph_Graph368->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph368->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph368->GetXaxis()->SetTitleFont(42);
   Graph_Graph368->GetYaxis()->SetNdivisions(506);
   Graph_Graph368->GetYaxis()->SetLabelFont(42);
   Graph_Graph368->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph368->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph368->GetYaxis()->SetTitleFont(42);
   Graph_Graph368->GetZaxis()->SetNdivisions(506);
   Graph_Graph368->GetZaxis()->SetLabelFont(42);
   Graph_Graph368->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph368->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph368->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph368);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx369[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy369[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx369,Graph_fy369);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph369 = new TH1F("Graph_Graph369","Graph",100,0.606,0.774);
   Graph_Graph369->SetMinimum(0.597);
   Graph_Graph369->SetMaximum(2.673);
   Graph_Graph369->SetDirectory(0);
   Graph_Graph369->SetStats(0);
   Graph_Graph369->SetLineWidth(2);
   Graph_Graph369->GetXaxis()->SetNdivisions(506);
   Graph_Graph369->GetXaxis()->SetLabelFont(42);
   Graph_Graph369->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph369->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph369->GetXaxis()->SetTitleFont(42);
   Graph_Graph369->GetYaxis()->SetNdivisions(506);
   Graph_Graph369->GetYaxis()->SetLabelFont(42);
   Graph_Graph369->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph369->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph369->GetYaxis()->SetTitleFont(42);
   Graph_Graph369->GetZaxis()->SetNdivisions(506);
   Graph_Graph369->GetZaxis()->SetLabelFont(42);
   Graph_Graph369->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph369->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph369->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph369);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx370[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy370[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx370,Graph_fy370);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph370 = new TH1F("Graph_Graph370","Graph",100,0.75,0.87);
   Graph_Graph370->SetMinimum(0.597);
   Graph_Graph370->SetMaximum(2.673);
   Graph_Graph370->SetDirectory(0);
   Graph_Graph370->SetStats(0);
   Graph_Graph370->SetLineWidth(2);
   Graph_Graph370->GetXaxis()->SetNdivisions(506);
   Graph_Graph370->GetXaxis()->SetLabelFont(42);
   Graph_Graph370->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph370->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph370->GetXaxis()->SetTitleFont(42);
   Graph_Graph370->GetYaxis()->SetNdivisions(506);
   Graph_Graph370->GetYaxis()->SetLabelFont(42);
   Graph_Graph370->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph370->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph370->GetYaxis()->SetTitleFont(42);
   Graph_Graph370->GetZaxis()->SetNdivisions(506);
   Graph_Graph370->GetZaxis()->SetLabelFont(42);
   Graph_Graph370->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph370->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph370->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph370);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx371[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy371[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx371,Graph_fy371);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph371 = new TH1F("Graph_Graph371","Graph",100,0.852,0.948);
   Graph_Graph371->SetMinimum(0.597);
   Graph_Graph371->SetMaximum(2.673);
   Graph_Graph371->SetDirectory(0);
   Graph_Graph371->SetStats(0);
   Graph_Graph371->SetLineWidth(2);
   Graph_Graph371->GetXaxis()->SetNdivisions(506);
   Graph_Graph371->GetXaxis()->SetLabelFont(42);
   Graph_Graph371->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph371->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph371->GetXaxis()->SetTitleFont(42);
   Graph_Graph371->GetYaxis()->SetNdivisions(506);
   Graph_Graph371->GetYaxis()->SetLabelFont(42);
   Graph_Graph371->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph371->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph371->GetYaxis()->SetTitleFont(42);
   Graph_Graph371->GetZaxis()->SetNdivisions(506);
   Graph_Graph371->GetZaxis()->SetLabelFont(42);
   Graph_Graph371->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph371->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph371->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph371);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx372[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy372[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx372,Graph_fy372);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph372 = new TH1F("Graph_Graph372","Graph",100,0.934,1.006);
   Graph_Graph372->SetMinimum(0.597);
   Graph_Graph372->SetMaximum(2.673);
   Graph_Graph372->SetDirectory(0);
   Graph_Graph372->SetStats(0);
   Graph_Graph372->SetLineWidth(2);
   Graph_Graph372->GetXaxis()->SetNdivisions(506);
   Graph_Graph372->GetXaxis()->SetLabelFont(42);
   Graph_Graph372->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph372->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph372->GetXaxis()->SetTitleFont(42);
   Graph_Graph372->GetYaxis()->SetNdivisions(506);
   Graph_Graph372->GetYaxis()->SetLabelFont(42);
   Graph_Graph372->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph372->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph372->GetYaxis()->SetTitleFont(42);
   Graph_Graph372->GetZaxis()->SetNdivisions(506);
   Graph_Graph372->GetZaxis()->SetLabelFont(42);
   Graph_Graph372->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph372->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph372->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph372);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.01331142);
   _reco_per_true->SetBinContent(2,0.007966188);
   _reco_per_true->SetBinContent(3,0.01599612);
   _reco_per_true->SetBinContent(4,0.06388196);
   _reco_per_true->SetBinContent(5,0.01599129);
   _reco_per_true->SetBinContent(6,0.002673488);
   _reco_per_true->SetBinContent(7,0.002669583);
   _reco_per_true->SetBinContent(8,0.002633542);
   _reco_per_true->SetBinContent(9,0.01595968);
   _reco_per_true->SetBinContent(10,0.008000262);
   _reco_per_true->SetBinContent(11,0.09830782);
   _reco_per_true->SetBinContent(12,0.4174499);
   _reco_per_true->SetBinContent(13,0.1409282);
   _reco_per_true->SetBinContent(14,0.007998635);
   _reco_per_true->SetBinContent(15,0.002669583);
   _reco_per_true->SetBinContent(17,0.002661301);
   _reco_per_true->SetBinContent(19,0.01064023);
   _reco_per_true->SetBinContent(20,0.1198107);
   _reco_per_true->SetBinContent(21,0.02396205);
   _reco_per_true->SetBinContent(22,0.005301773);
   _reco_per_true->SetBinContent(23,0.005301104);
   _reco_per_true->SetBinContent(24,0.005211341);
   _reco_per_true->SetBinContent(27,0.008010082);
   _reco_per_true->SetBinContent(28,0.002663768);
   _reco_per_true->SetBinError(1,0.005953089);
   _reco_per_true->SetBinError(2,0.004599285);
   _reco_per_true->SetBinError(3,0.006530397);
   _reco_per_true->SetBinError(4,0.01303992);
   _reco_per_true->SetBinError(5,0.006528423);
   _reco_per_true->SetBinError(6,0.002673488);
   _reco_per_true->SetBinError(7,0.002669583);
   _reco_per_true->SetBinError(8,0.002633542);
   _reco_per_true->SetBinError(9,0.006515613);
   _reco_per_true->SetBinError(10,0.004618959);
   _reco_per_true->SetBinError(11,0.01616256);
   _reco_per_true->SetBinError(12,0.03331802);
   _reco_per_true->SetBinError(13,0.01935913);
   _reco_per_true->SetBinError(14,0.004618027);
   _reco_per_true->SetBinError(15,0.002669583);
   _reco_per_true->SetBinError(17,0.002661301);
   _reco_per_true->SetBinError(19,0.005320129);
   _reco_per_true->SetBinError(20,0.01786037);
   _reco_per_true->SetBinError(21,0.007987356);
   _reco_per_true->SetBinError(22,0.003748921);
   _reco_per_true->SetBinError(23,0.003748524);
   _reco_per_true->SetBinError(24,0.003685807);
   _reco_per_true->SetBinError(27,0.004624625);
   _reco_per_true->SetBinError(28,0.002663768);
   _reco_per_true->SetEntries(376);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.001637058);
   _reco_per_true->SetContourLevel(2,0.003274117);
   _reco_per_true->SetContourLevel(3,0.004911175);
   _reco_per_true->SetContourLevel(4,0.006548234);
   _reco_per_true->SetContourLevel(5,0.008185292);
   _reco_per_true->SetContourLevel(6,0.009822351);
   _reco_per_true->SetContourLevel(7,0.01145941);
   _reco_per_true->SetContourLevel(8,0.01309647);
   _reco_per_true->SetContourLevel(9,0.01473353);
   _reco_per_true->SetContourLevel(10,0.01637058);
   _reco_per_true->SetContourLevel(11,0.01800764);
   _reco_per_true->SetContourLevel(12,0.0196447);
   _reco_per_true->SetContourLevel(13,0.02128176);
   _reco_per_true->SetContourLevel(14,0.02291882);
   _reco_per_true->SetContourLevel(15,0.02455588);
   _reco_per_true->SetContourLevel(16,0.02619293);
   _reco_per_true->SetContourLevel(17,0.02782999);
   _reco_per_true->SetContourLevel(18,0.02946705);
   _reco_per_true->SetContourLevel(19,0.03110411);
   _reco_per_true->SetContourLevel(20,0.03274117);
   _reco_per_true->SetContourLevel(21,0.03437823);
   _reco_per_true->SetContourLevel(22,0.03601529);
   _reco_per_true->SetContourLevel(23,0.03765234);
   _reco_per_true->SetContourLevel(24,0.0392894);
   _reco_per_true->SetContourLevel(25,0.04092646);
   _reco_per_true->SetContourLevel(26,0.04256352);
   _reco_per_true->SetContourLevel(27,0.04420058);
   _reco_per_true->SetContourLevel(28,0.04583764);
   _reco_per_true->SetContourLevel(29,0.04747469);
   _reco_per_true->SetContourLevel(30,0.04911175);
   _reco_per_true->SetContourLevel(31,0.05074881);
   _reco_per_true->SetContourLevel(32,0.05238587);
   _reco_per_true->SetContourLevel(33,0.05402293);
   _reco_per_true->SetContourLevel(34,0.05565999);
   _reco_per_true->SetContourLevel(35,0.05729705);
   _reco_per_true->SetContourLevel(36,0.0589341);
   _reco_per_true->SetContourLevel(37,0.06057116);
   _reco_per_true->SetContourLevel(38,0.06220822);
   _reco_per_true->SetContourLevel(39,0.06384528);
   _reco_per_true->SetContourLevel(40,0.06548234);
   _reco_per_true->SetContourLevel(41,0.0671194);
   _reco_per_true->SetContourLevel(42,0.06875645);
   _reco_per_true->SetContourLevel(43,0.07039351);
   _reco_per_true->SetContourLevel(44,0.07203057);
   _reco_per_true->SetContourLevel(45,0.07366763);
   _reco_per_true->SetContourLevel(46,0.07530469);
   _reco_per_true->SetContourLevel(47,0.07694175);
   _reco_per_true->SetContourLevel(48,0.0785788);
   _reco_per_true->SetContourLevel(49,0.08021586);
   _reco_per_true->SetContourLevel(50,0.08185292);
   _reco_per_true->SetContourLevel(51,0.08348998);
   _reco_per_true->SetContourLevel(52,0.08512704);
   _reco_per_true->SetContourLevel(53,0.0867641);
   _reco_per_true->SetContourLevel(54,0.08840116);
   _reco_per_true->SetContourLevel(55,0.09003821);
   _reco_per_true->SetContourLevel(56,0.09167527);
   _reco_per_true->SetContourLevel(57,0.09331233);
   _reco_per_true->SetContourLevel(58,0.09494939);
   _reco_per_true->SetContourLevel(59,0.09658645);
   _reco_per_true->SetContourLevel(60,0.09822351);
   _reco_per_true->SetContourLevel(61,0.09986056);
   _reco_per_true->SetContourLevel(62,0.1014976);
   _reco_per_true->SetContourLevel(63,0.1031347);
   _reco_per_true->SetContourLevel(64,0.1047717);
   _reco_per_true->SetContourLevel(65,0.1064088);
   _reco_per_true->SetContourLevel(66,0.1080459);
   _reco_per_true->SetContourLevel(67,0.1096829);
   _reco_per_true->SetContourLevel(68,0.11132);
   _reco_per_true->SetContourLevel(69,0.112957);
   _reco_per_true->SetContourLevel(70,0.1145941);
   _reco_per_true->SetContourLevel(71,0.1162311);
   _reco_per_true->SetContourLevel(72,0.1178682);
   _reco_per_true->SetContourLevel(73,0.1195053);
   _reco_per_true->SetContourLevel(74,0.1211423);
   _reco_per_true->SetContourLevel(75,0.1227794);
   _reco_per_true->SetContourLevel(76,0.1244164);
   _reco_per_true->SetContourLevel(77,0.1260535);
   _reco_per_true->SetContourLevel(78,0.1276906);
   _reco_per_true->SetContourLevel(79,0.1293276);
   _reco_per_true->SetContourLevel(80,0.1309647);
   _reco_per_true->SetContourLevel(81,0.1326017);
   _reco_per_true->SetContourLevel(82,0.1342388);
   _reco_per_true->SetContourLevel(83,0.1358758);
   _reco_per_true->SetContourLevel(84,0.1375129);
   _reco_per_true->SetContourLevel(85,0.13915);
   _reco_per_true->SetContourLevel(86,0.140787);
   _reco_per_true->SetContourLevel(87,0.1424241);
   _reco_per_true->SetContourLevel(88,0.1440611);
   _reco_per_true->SetContourLevel(89,0.1456982);
   _reco_per_true->SetContourLevel(90,0.1473353);
   _reco_per_true->SetContourLevel(91,0.1489723);
   _reco_per_true->SetContourLevel(92,0.1506094);
   _reco_per_true->SetContourLevel(93,0.1522464);
   _reco_per_true->SetContourLevel(94,0.1538835);
   _reco_per_true->SetContourLevel(95,0.1555206);
   _reco_per_true->SetContourLevel(96,0.1571576);
   _reco_per_true->SetContourLevel(97,0.1587947);
   _reco_per_true->SetContourLevel(98,0.1604317);
   _reco_per_true->SetContourLevel(99,0.1620688);
   _reco_per_true->SetContourLevel(100,0.1637058);
   _reco_per_true->SetContourLevel(101,0.1653429);
   _reco_per_true->SetContourLevel(102,0.16698);
   _reco_per_true->SetContourLevel(103,0.168617);
   _reco_per_true->SetContourLevel(104,0.1702541);
   _reco_per_true->SetContourLevel(105,0.1718911);
   _reco_per_true->SetContourLevel(106,0.1735282);
   _reco_per_true->SetContourLevel(107,0.1751653);
   _reco_per_true->SetContourLevel(108,0.1768023);
   _reco_per_true->SetContourLevel(109,0.1784394);
   _reco_per_true->SetContourLevel(110,0.1800764);
   _reco_per_true->SetContourLevel(111,0.1817135);
   _reco_per_true->SetContourLevel(112,0.1833505);
   _reco_per_true->SetContourLevel(113,0.1849876);
   _reco_per_true->SetContourLevel(114,0.1866247);
   _reco_per_true->SetContourLevel(115,0.1882617);
   _reco_per_true->SetContourLevel(116,0.1898988);
   _reco_per_true->SetContourLevel(117,0.1915358);
   _reco_per_true->SetContourLevel(118,0.1931729);
   _reco_per_true->SetContourLevel(119,0.19481);
   _reco_per_true->SetContourLevel(120,0.196447);
   _reco_per_true->SetContourLevel(121,0.1980841);
   _reco_per_true->SetContourLevel(122,0.1997211);
   _reco_per_true->SetContourLevel(123,0.2013582);
   _reco_per_true->SetContourLevel(124,0.2029952);
   _reco_per_true->SetContourLevel(125,0.2046323);
   _reco_per_true->SetContourLevel(126,0.2062694);
   _reco_per_true->SetContourLevel(127,0.2079064);
   _reco_per_true->SetContourLevel(128,0.2095435);
   _reco_per_true->SetContourLevel(129,0.2111805);
   _reco_per_true->SetContourLevel(130,0.2128176);
   _reco_per_true->SetContourLevel(131,0.2144547);
   _reco_per_true->SetContourLevel(132,0.2160917);
   _reco_per_true->SetContourLevel(133,0.2177288);
   _reco_per_true->SetContourLevel(134,0.2193658);
   _reco_per_true->SetContourLevel(135,0.2210029);
   _reco_per_true->SetContourLevel(136,0.2226399);
   _reco_per_true->SetContourLevel(137,0.224277);
   _reco_per_true->SetContourLevel(138,0.2259141);
   _reco_per_true->SetContourLevel(139,0.2275511);
   _reco_per_true->SetContourLevel(140,0.2291882);
   _reco_per_true->SetContourLevel(141,0.2308252);
   _reco_per_true->SetContourLevel(142,0.2324623);
   _reco_per_true->SetContourLevel(143,0.2340994);
   _reco_per_true->SetContourLevel(144,0.2357364);
   _reco_per_true->SetContourLevel(145,0.2373735);
   _reco_per_true->SetContourLevel(146,0.2390105);
   _reco_per_true->SetContourLevel(147,0.2406476);
   _reco_per_true->SetContourLevel(148,0.2422846);
   _reco_per_true->SetContourLevel(149,0.2439217);
   _reco_per_true->SetContourLevel(150,0.2455588);
   _reco_per_true->SetContourLevel(151,0.2471958);
   _reco_per_true->SetContourLevel(152,0.2488329);
   _reco_per_true->SetContourLevel(153,0.2504699);
   _reco_per_true->SetContourLevel(154,0.252107);
   _reco_per_true->SetContourLevel(155,0.2537441);
   _reco_per_true->SetContourLevel(156,0.2553811);
   _reco_per_true->SetContourLevel(157,0.2570182);
   _reco_per_true->SetContourLevel(158,0.2586552);
   _reco_per_true->SetContourLevel(159,0.2602923);
   _reco_per_true->SetContourLevel(160,0.2619293);
   _reco_per_true->SetContourLevel(161,0.2635664);
   _reco_per_true->SetContourLevel(162,0.2652035);
   _reco_per_true->SetContourLevel(163,0.2668405);
   _reco_per_true->SetContourLevel(164,0.2684776);
   _reco_per_true->SetContourLevel(165,0.2701146);
   _reco_per_true->SetContourLevel(166,0.2717517);
   _reco_per_true->SetContourLevel(167,0.2733888);
   _reco_per_true->SetContourLevel(168,0.2750258);
   _reco_per_true->SetContourLevel(169,0.2766629);
   _reco_per_true->SetContourLevel(170,0.2782999);
   _reco_per_true->SetContourLevel(171,0.279937);
   _reco_per_true->SetContourLevel(172,0.2815741);
   _reco_per_true->SetContourLevel(173,0.2832111);
   _reco_per_true->SetContourLevel(174,0.2848482);
   _reco_per_true->SetContourLevel(175,0.2864852);
   _reco_per_true->SetContourLevel(176,0.2881223);
   _reco_per_true->SetContourLevel(177,0.2897593);
   _reco_per_true->SetContourLevel(178,0.2913964);
   _reco_per_true->SetContourLevel(179,0.2930335);
   _reco_per_true->SetContourLevel(180,0.2946705);
   _reco_per_true->SetContourLevel(181,0.2963076);
   _reco_per_true->SetContourLevel(182,0.2979446);
   _reco_per_true->SetContourLevel(183,0.2995817);
   _reco_per_true->SetContourLevel(184,0.3012188);
   _reco_per_true->SetContourLevel(185,0.3028558);
   _reco_per_true->SetContourLevel(186,0.3044929);
   _reco_per_true->SetContourLevel(187,0.3061299);
   _reco_per_true->SetContourLevel(188,0.307767);
   _reco_per_true->SetContourLevel(189,0.309404);
   _reco_per_true->SetContourLevel(190,0.3110411);
   _reco_per_true->SetContourLevel(191,0.3126782);
   _reco_per_true->SetContourLevel(192,0.3143152);
   _reco_per_true->SetContourLevel(193,0.3159523);
   _reco_per_true->SetContourLevel(194,0.3175893);
   _reco_per_true->SetContourLevel(195,0.3192264);
   _reco_per_true->SetContourLevel(196,0.3208635);
   _reco_per_true->SetContourLevel(197,0.3225005);
   _reco_per_true->SetContourLevel(198,0.3241376);
   _reco_per_true->SetContourLevel(199,0.3257746);
   _reco_per_true->SetContourLevel(200,0.3274117);
   _reco_per_true->SetContourLevel(201,0.3290487);
   _reco_per_true->SetContourLevel(202,0.3306858);
   _reco_per_true->SetContourLevel(203,0.3323229);
   _reco_per_true->SetContourLevel(204,0.3339599);
   _reco_per_true->SetContourLevel(205,0.335597);
   _reco_per_true->SetContourLevel(206,0.337234);
   _reco_per_true->SetContourLevel(207,0.3388711);
   _reco_per_true->SetContourLevel(208,0.3405082);
   _reco_per_true->SetContourLevel(209,0.3421452);
   _reco_per_true->SetContourLevel(210,0.3437823);
   _reco_per_true->SetContourLevel(211,0.3454193);
   _reco_per_true->SetContourLevel(212,0.3470564);
   _reco_per_true->SetContourLevel(213,0.3486934);
   _reco_per_true->SetContourLevel(214,0.3503305);
   _reco_per_true->SetContourLevel(215,0.3519676);
   _reco_per_true->SetContourLevel(216,0.3536046);
   _reco_per_true->SetContourLevel(217,0.3552417);
   _reco_per_true->SetContourLevel(218,0.3568787);
   _reco_per_true->SetContourLevel(219,0.3585158);
   _reco_per_true->SetContourLevel(220,0.3601529);
   _reco_per_true->SetContourLevel(221,0.3617899);
   _reco_per_true->SetContourLevel(222,0.363427);
   _reco_per_true->SetContourLevel(223,0.365064);
   _reco_per_true->SetContourLevel(224,0.3667011);
   _reco_per_true->SetContourLevel(225,0.3683381);
   _reco_per_true->SetContourLevel(226,0.3699752);
   _reco_per_true->SetContourLevel(227,0.3716123);
   _reco_per_true->SetContourLevel(228,0.3732493);
   _reco_per_true->SetContourLevel(229,0.3748864);
   _reco_per_true->SetContourLevel(230,0.3765234);
   _reco_per_true->SetContourLevel(231,0.3781605);
   _reco_per_true->SetContourLevel(232,0.3797976);
   _reco_per_true->SetContourLevel(233,0.3814346);
   _reco_per_true->SetContourLevel(234,0.3830717);
   _reco_per_true->SetContourLevel(235,0.3847087);
   _reco_per_true->SetContourLevel(236,0.3863458);
   _reco_per_true->SetContourLevel(237,0.3879828);
   _reco_per_true->SetContourLevel(238,0.3896199);
   _reco_per_true->SetContourLevel(239,0.391257);
   _reco_per_true->SetContourLevel(240,0.392894);
   _reco_per_true->SetContourLevel(241,0.3945311);
   _reco_per_true->SetContourLevel(242,0.3961681);
   _reco_per_true->SetContourLevel(243,0.3978052);
   _reco_per_true->SetContourLevel(244,0.3994423);
   _reco_per_true->SetContourLevel(245,0.4010793);
   _reco_per_true->SetContourLevel(246,0.4027164);
   _reco_per_true->SetContourLevel(247,0.4043534);
   _reco_per_true->SetContourLevel(248,0.4059905);
   _reco_per_true->SetContourLevel(249,0.4076275);
   _reco_per_true->SetContourLevel(250,0.4092646);
   _reco_per_true->SetContourLevel(251,0.4109017);
   _reco_per_true->SetContourLevel(252,0.4125387);
   _reco_per_true->SetContourLevel(253,0.4141758);
   _reco_per_true->SetContourLevel(254,0.4158128);
   
   TPaletteAxis *palette = new TPaletteAxis(1.0125,0,1.125,2.5,_reco_per_true);
palette->SetLabelColor(1);
palette->SetLabelFont(42);
palette->SetLabelOffset(0.005);
palette->SetLabelSize(0.04);
palette->SetTitleOffset(0.8);
palette->SetTitleSize(0.055);

   ci = TColor::GetColor("#850100");
   palette->SetFillColor(ci);
   palette->SetFillStyle(1001);
   _reco_per_true->GetListOfFunctions()->Add(palette,"br");
   _reco_per_true->SetLineWidth(2);
   _reco_per_true->GetXaxis()->SetTitle("cos(#theta_{#mu}) [Reco Bin i]");
   _reco_per_true->GetXaxis()->SetNdivisions(506);
   _reco_per_true->GetXaxis()->SetLabelFont(42);
   _reco_per_true->GetXaxis()->SetTitleSize(0.055);
   _reco_per_true->GetXaxis()->SetTitleOffset(0.8);
   _reco_per_true->GetXaxis()->SetTitleFont(42);
   _reco_per_true->GetYaxis()->SetTitle("p_{#mu} (GeV) [Reco Bin j]");
   _reco_per_true->GetYaxis()->SetNdivisions(506);
   _reco_per_true->GetYaxis()->SetLabelFont(42);
   _reco_per_true->GetYaxis()->SetTitleSize(0.055);
   _reco_per_true->GetYaxis()->SetTitleOffset(0.8);
   _reco_per_true->GetYaxis()->SetTitleFont(42);
   _reco_per_true->GetZaxis()->SetNdivisions(506);
   _reco_per_true->GetZaxis()->SetLabelFont(42);
   _reco_per_true->GetZaxis()->SetTitleSize(0.055);
   _reco_per_true->GetZaxis()->SetTitleOffset(0.8);
   _reco_per_true->GetZaxis()->SetTitleFont(42);
   _reco_per_true->Draw("colz text");
   
   TPaveText *pt = new TPaveText(0.3961605,0.91975,0.6038395,0.98025,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetTextFont(42);
   TText *AText = pt->AddText("True Bin 11");
   pt->Draw();
   c1_n12->Modified();
   c1_n12->cd();
   c1_n12->SetSelected(c1_n12);
}

void smearing_matrix_true_29()
{
//=========Macro generated from canvas: c1_n30/c1_n30
//=========  (Sat Sep 22 12:03:58 2018) by ROOT version6.06/06
   TCanvas *c1_n30 = new TCanvas("c1_n30", "c1_n30",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n30->SetHighLightColor(2);
   c1_n30->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n30->SetFillColor(10);
   c1_n30->SetBorderMode(0);
   c1_n30->SetBorderSize(2);
   c1_n30->SetFrameLineWidth(2);
   c1_n30->SetFrameBorderMode(0);
   c1_n30->SetFrameLineWidth(2);
   c1_n30->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 29", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx900[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy900[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx900,Graph_fy900);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph900 = new TH1F("Graph_Graph900","Graph",100,-1.1,0);
   Graph_Graph900->SetMinimum(0);
   Graph_Graph900->SetMaximum(0.33);
   Graph_Graph900->SetDirectory(0);
   Graph_Graph900->SetStats(0);
   Graph_Graph900->SetLineWidth(2);
   Graph_Graph900->GetXaxis()->SetNdivisions(506);
   Graph_Graph900->GetXaxis()->SetLabelFont(42);
   Graph_Graph900->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph900->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph900->GetXaxis()->SetTitleFont(42);
   Graph_Graph900->GetYaxis()->SetNdivisions(506);
   Graph_Graph900->GetYaxis()->SetLabelFont(42);
   Graph_Graph900->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph900->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph900->GetYaxis()->SetTitleFont(42);
   Graph_Graph900->GetZaxis()->SetNdivisions(506);
   Graph_Graph900->GetZaxis()->SetLabelFont(42);
   Graph_Graph900->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph900->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph900->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph900);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx901[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy901[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx901,Graph_fy901);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph901 = new TH1F("Graph_Graph901","Graph",100,0,0.297);
   Graph_Graph901->SetMinimum(0);
   Graph_Graph901->SetMaximum(0.33);
   Graph_Graph901->SetDirectory(0);
   Graph_Graph901->SetStats(0);
   Graph_Graph901->SetLineWidth(2);
   Graph_Graph901->GetXaxis()->SetNdivisions(506);
   Graph_Graph901->GetXaxis()->SetLabelFont(42);
   Graph_Graph901->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph901->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph901->GetXaxis()->SetTitleFont(42);
   Graph_Graph901->GetYaxis()->SetNdivisions(506);
   Graph_Graph901->GetYaxis()->SetLabelFont(42);
   Graph_Graph901->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph901->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph901->GetYaxis()->SetTitleFont(42);
   Graph_Graph901->GetZaxis()->SetNdivisions(506);
   Graph_Graph901->GetZaxis()->SetLabelFont(42);
   Graph_Graph901->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph901->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph901->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph901);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx902[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy902[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx902,Graph_fy902);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph902 = new TH1F("Graph_Graph902","Graph",100,0.252,0.468);
   Graph_Graph902->SetMinimum(0);
   Graph_Graph902->SetMaximum(0.33);
   Graph_Graph902->SetDirectory(0);
   Graph_Graph902->SetStats(0);
   Graph_Graph902->SetLineWidth(2);
   Graph_Graph902->GetXaxis()->SetNdivisions(506);
   Graph_Graph902->GetXaxis()->SetLabelFont(42);
   Graph_Graph902->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph902->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph902->GetXaxis()->SetTitleFont(42);
   Graph_Graph902->GetYaxis()->SetNdivisions(506);
   Graph_Graph902->GetYaxis()->SetLabelFont(42);
   Graph_Graph902->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph902->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph902->GetYaxis()->SetTitleFont(42);
   Graph_Graph902->GetZaxis()->SetNdivisions(506);
   Graph_Graph902->GetZaxis()->SetLabelFont(42);
   Graph_Graph902->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph902->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph902->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph902);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx903[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy903[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx903,Graph_fy903);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph903 = new TH1F("Graph_Graph903","Graph",100,0.433,0.637);
   Graph_Graph903->SetMinimum(0);
   Graph_Graph903->SetMaximum(0.33);
   Graph_Graph903->SetDirectory(0);
   Graph_Graph903->SetStats(0);
   Graph_Graph903->SetLineWidth(2);
   Graph_Graph903->GetXaxis()->SetNdivisions(506);
   Graph_Graph903->GetXaxis()->SetLabelFont(42);
   Graph_Graph903->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph903->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph903->GetXaxis()->SetTitleFont(42);
   Graph_Graph903->GetYaxis()->SetNdivisions(506);
   Graph_Graph903->GetYaxis()->SetLabelFont(42);
   Graph_Graph903->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph903->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph903->GetYaxis()->SetTitleFont(42);
   Graph_Graph903->GetZaxis()->SetNdivisions(506);
   Graph_Graph903->GetZaxis()->SetLabelFont(42);
   Graph_Graph903->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph903->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph903->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph903);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx904[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy904[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx904,Graph_fy904);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph904 = new TH1F("Graph_Graph904","Graph",100,0.606,0.774);
   Graph_Graph904->SetMinimum(0);
   Graph_Graph904->SetMaximum(0.33);
   Graph_Graph904->SetDirectory(0);
   Graph_Graph904->SetStats(0);
   Graph_Graph904->SetLineWidth(2);
   Graph_Graph904->GetXaxis()->SetNdivisions(506);
   Graph_Graph904->GetXaxis()->SetLabelFont(42);
   Graph_Graph904->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph904->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph904->GetXaxis()->SetTitleFont(42);
   Graph_Graph904->GetYaxis()->SetNdivisions(506);
   Graph_Graph904->GetYaxis()->SetLabelFont(42);
   Graph_Graph904->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph904->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph904->GetYaxis()->SetTitleFont(42);
   Graph_Graph904->GetZaxis()->SetNdivisions(506);
   Graph_Graph904->GetZaxis()->SetLabelFont(42);
   Graph_Graph904->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph904->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph904->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph904);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx905[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy905[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx905,Graph_fy905);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph905 = new TH1F("Graph_Graph905","Graph",100,0.75,0.87);
   Graph_Graph905->SetMinimum(0);
   Graph_Graph905->SetMaximum(0.33);
   Graph_Graph905->SetDirectory(0);
   Graph_Graph905->SetStats(0);
   Graph_Graph905->SetLineWidth(2);
   Graph_Graph905->GetXaxis()->SetNdivisions(506);
   Graph_Graph905->GetXaxis()->SetLabelFont(42);
   Graph_Graph905->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph905->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph905->GetXaxis()->SetTitleFont(42);
   Graph_Graph905->GetYaxis()->SetNdivisions(506);
   Graph_Graph905->GetYaxis()->SetLabelFont(42);
   Graph_Graph905->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph905->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph905->GetYaxis()->SetTitleFont(42);
   Graph_Graph905->GetZaxis()->SetNdivisions(506);
   Graph_Graph905->GetZaxis()->SetLabelFont(42);
   Graph_Graph905->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph905->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph905->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph905);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx906[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy906[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx906,Graph_fy906);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph906 = new TH1F("Graph_Graph906","Graph",100,0.852,0.948);
   Graph_Graph906->SetMinimum(0);
   Graph_Graph906->SetMaximum(0.33);
   Graph_Graph906->SetDirectory(0);
   Graph_Graph906->SetStats(0);
   Graph_Graph906->SetLineWidth(2);
   Graph_Graph906->GetXaxis()->SetNdivisions(506);
   Graph_Graph906->GetXaxis()->SetLabelFont(42);
   Graph_Graph906->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph906->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph906->GetXaxis()->SetTitleFont(42);
   Graph_Graph906->GetYaxis()->SetNdivisions(506);
   Graph_Graph906->GetYaxis()->SetLabelFont(42);
   Graph_Graph906->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph906->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph906->GetYaxis()->SetTitleFont(42);
   Graph_Graph906->GetZaxis()->SetNdivisions(506);
   Graph_Graph906->GetZaxis()->SetLabelFont(42);
   Graph_Graph906->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph906->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph906->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph906);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx907[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy907[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx907,Graph_fy907);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph907 = new TH1F("Graph_Graph907","Graph",100,0.934,1.006);
   Graph_Graph907->SetMinimum(0);
   Graph_Graph907->SetMaximum(0.33);
   Graph_Graph907->SetDirectory(0);
   Graph_Graph907->SetStats(0);
   Graph_Graph907->SetLineWidth(2);
   Graph_Graph907->GetXaxis()->SetNdivisions(506);
   Graph_Graph907->GetXaxis()->SetLabelFont(42);
   Graph_Graph907->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph907->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph907->GetXaxis()->SetTitleFont(42);
   Graph_Graph907->GetYaxis()->SetNdivisions(506);
   Graph_Graph907->GetYaxis()->SetLabelFont(42);
   Graph_Graph907->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph907->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph907->GetYaxis()->SetTitleFont(42);
   Graph_Graph907->GetZaxis()->SetNdivisions(506);
   Graph_Graph907->GetZaxis()->SetLabelFont(42);
   Graph_Graph907->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph907->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph907->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph907);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx908[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy908[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx908,Graph_fy908);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph908 = new TH1F("Graph_Graph908","Graph",100,-1.1,0);
   Graph_Graph908->SetMinimum(0.285);
   Graph_Graph908->SetMaximum(0.465);
   Graph_Graph908->SetDirectory(0);
   Graph_Graph908->SetStats(0);
   Graph_Graph908->SetLineWidth(2);
   Graph_Graph908->GetXaxis()->SetNdivisions(506);
   Graph_Graph908->GetXaxis()->SetLabelFont(42);
   Graph_Graph908->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph908->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph908->GetXaxis()->SetTitleFont(42);
   Graph_Graph908->GetYaxis()->SetNdivisions(506);
   Graph_Graph908->GetYaxis()->SetLabelFont(42);
   Graph_Graph908->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph908->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph908->GetYaxis()->SetTitleFont(42);
   Graph_Graph908->GetZaxis()->SetNdivisions(506);
   Graph_Graph908->GetZaxis()->SetLabelFont(42);
   Graph_Graph908->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph908->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph908->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph908);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx909[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy909[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx909,Graph_fy909);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph909 = new TH1F("Graph_Graph909","Graph",100,0,0.297);
   Graph_Graph909->SetMinimum(0.285);
   Graph_Graph909->SetMaximum(0.465);
   Graph_Graph909->SetDirectory(0);
   Graph_Graph909->SetStats(0);
   Graph_Graph909->SetLineWidth(2);
   Graph_Graph909->GetXaxis()->SetNdivisions(506);
   Graph_Graph909->GetXaxis()->SetLabelFont(42);
   Graph_Graph909->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph909->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph909->GetXaxis()->SetTitleFont(42);
   Graph_Graph909->GetYaxis()->SetNdivisions(506);
   Graph_Graph909->GetYaxis()->SetLabelFont(42);
   Graph_Graph909->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph909->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph909->GetYaxis()->SetTitleFont(42);
   Graph_Graph909->GetZaxis()->SetNdivisions(506);
   Graph_Graph909->GetZaxis()->SetLabelFont(42);
   Graph_Graph909->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph909->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph909->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph909);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx910[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy910[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx910,Graph_fy910);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph910 = new TH1F("Graph_Graph910","Graph",100,0.252,0.468);
   Graph_Graph910->SetMinimum(0.285);
   Graph_Graph910->SetMaximum(0.465);
   Graph_Graph910->SetDirectory(0);
   Graph_Graph910->SetStats(0);
   Graph_Graph910->SetLineWidth(2);
   Graph_Graph910->GetXaxis()->SetNdivisions(506);
   Graph_Graph910->GetXaxis()->SetLabelFont(42);
   Graph_Graph910->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph910->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph910->GetXaxis()->SetTitleFont(42);
   Graph_Graph910->GetYaxis()->SetNdivisions(506);
   Graph_Graph910->GetYaxis()->SetLabelFont(42);
   Graph_Graph910->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph910->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph910->GetYaxis()->SetTitleFont(42);
   Graph_Graph910->GetZaxis()->SetNdivisions(506);
   Graph_Graph910->GetZaxis()->SetLabelFont(42);
   Graph_Graph910->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph910->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph910->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph910);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx911[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy911[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx911,Graph_fy911);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph911 = new TH1F("Graph_Graph911","Graph",100,0.433,0.637);
   Graph_Graph911->SetMinimum(0.285);
   Graph_Graph911->SetMaximum(0.465);
   Graph_Graph911->SetDirectory(0);
   Graph_Graph911->SetStats(0);
   Graph_Graph911->SetLineWidth(2);
   Graph_Graph911->GetXaxis()->SetNdivisions(506);
   Graph_Graph911->GetXaxis()->SetLabelFont(42);
   Graph_Graph911->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph911->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph911->GetXaxis()->SetTitleFont(42);
   Graph_Graph911->GetYaxis()->SetNdivisions(506);
   Graph_Graph911->GetYaxis()->SetLabelFont(42);
   Graph_Graph911->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph911->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph911->GetYaxis()->SetTitleFont(42);
   Graph_Graph911->GetZaxis()->SetNdivisions(506);
   Graph_Graph911->GetZaxis()->SetLabelFont(42);
   Graph_Graph911->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph911->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph911->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph911);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx912[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy912[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx912,Graph_fy912);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph912 = new TH1F("Graph_Graph912","Graph",100,0.606,0.774);
   Graph_Graph912->SetMinimum(0.285);
   Graph_Graph912->SetMaximum(0.465);
   Graph_Graph912->SetDirectory(0);
   Graph_Graph912->SetStats(0);
   Graph_Graph912->SetLineWidth(2);
   Graph_Graph912->GetXaxis()->SetNdivisions(506);
   Graph_Graph912->GetXaxis()->SetLabelFont(42);
   Graph_Graph912->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph912->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph912->GetXaxis()->SetTitleFont(42);
   Graph_Graph912->GetYaxis()->SetNdivisions(506);
   Graph_Graph912->GetYaxis()->SetLabelFont(42);
   Graph_Graph912->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph912->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph912->GetYaxis()->SetTitleFont(42);
   Graph_Graph912->GetZaxis()->SetNdivisions(506);
   Graph_Graph912->GetZaxis()->SetLabelFont(42);
   Graph_Graph912->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph912->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph912->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph912);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx913[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy913[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx913,Graph_fy913);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph913 = new TH1F("Graph_Graph913","Graph",100,0.75,0.87);
   Graph_Graph913->SetMinimum(0.285);
   Graph_Graph913->SetMaximum(0.465);
   Graph_Graph913->SetDirectory(0);
   Graph_Graph913->SetStats(0);
   Graph_Graph913->SetLineWidth(2);
   Graph_Graph913->GetXaxis()->SetNdivisions(506);
   Graph_Graph913->GetXaxis()->SetLabelFont(42);
   Graph_Graph913->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph913->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph913->GetXaxis()->SetTitleFont(42);
   Graph_Graph913->GetYaxis()->SetNdivisions(506);
   Graph_Graph913->GetYaxis()->SetLabelFont(42);
   Graph_Graph913->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph913->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph913->GetYaxis()->SetTitleFont(42);
   Graph_Graph913->GetZaxis()->SetNdivisions(506);
   Graph_Graph913->GetZaxis()->SetLabelFont(42);
   Graph_Graph913->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph913->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph913->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph913);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx914[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy914[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx914,Graph_fy914);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph914 = new TH1F("Graph_Graph914","Graph",100,0.852,0.948);
   Graph_Graph914->SetMinimum(0.285);
   Graph_Graph914->SetMaximum(0.465);
   Graph_Graph914->SetDirectory(0);
   Graph_Graph914->SetStats(0);
   Graph_Graph914->SetLineWidth(2);
   Graph_Graph914->GetXaxis()->SetNdivisions(506);
   Graph_Graph914->GetXaxis()->SetLabelFont(42);
   Graph_Graph914->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph914->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph914->GetXaxis()->SetTitleFont(42);
   Graph_Graph914->GetYaxis()->SetNdivisions(506);
   Graph_Graph914->GetYaxis()->SetLabelFont(42);
   Graph_Graph914->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph914->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph914->GetYaxis()->SetTitleFont(42);
   Graph_Graph914->GetZaxis()->SetNdivisions(506);
   Graph_Graph914->GetZaxis()->SetLabelFont(42);
   Graph_Graph914->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph914->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph914->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph914);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx915[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy915[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx915,Graph_fy915);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph915 = new TH1F("Graph_Graph915","Graph",100,0.934,1.006);
   Graph_Graph915->SetMinimum(0.285);
   Graph_Graph915->SetMaximum(0.465);
   Graph_Graph915->SetDirectory(0);
   Graph_Graph915->SetStats(0);
   Graph_Graph915->SetLineWidth(2);
   Graph_Graph915->GetXaxis()->SetNdivisions(506);
   Graph_Graph915->GetXaxis()->SetLabelFont(42);
   Graph_Graph915->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph915->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph915->GetXaxis()->SetTitleFont(42);
   Graph_Graph915->GetYaxis()->SetNdivisions(506);
   Graph_Graph915->GetYaxis()->SetLabelFont(42);
   Graph_Graph915->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph915->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph915->GetYaxis()->SetTitleFont(42);
   Graph_Graph915->GetZaxis()->SetNdivisions(506);
   Graph_Graph915->GetZaxis()->SetLabelFont(42);
   Graph_Graph915->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph915->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph915->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph915);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx916[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy916[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx916,Graph_fy916);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph916 = new TH1F("Graph_Graph916","Graph",100,-1.1,0);
   Graph_Graph916->SetMinimum(0.245);
   Graph_Graph916->SetMaximum(2.705);
   Graph_Graph916->SetDirectory(0);
   Graph_Graph916->SetStats(0);
   Graph_Graph916->SetLineWidth(2);
   Graph_Graph916->GetXaxis()->SetNdivisions(506);
   Graph_Graph916->GetXaxis()->SetLabelFont(42);
   Graph_Graph916->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph916->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph916->GetXaxis()->SetTitleFont(42);
   Graph_Graph916->GetYaxis()->SetNdivisions(506);
   Graph_Graph916->GetYaxis()->SetLabelFont(42);
   Graph_Graph916->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph916->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph916->GetYaxis()->SetTitleFont(42);
   Graph_Graph916->GetZaxis()->SetNdivisions(506);
   Graph_Graph916->GetZaxis()->SetLabelFont(42);
   Graph_Graph916->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph916->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph916->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph916);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx917[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy917[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx917,Graph_fy917);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph917 = new TH1F("Graph_Graph917","Graph",100,0,0.297);
   Graph_Graph917->SetMinimum(0.418);
   Graph_Graph917->SetMaximum(0.802);
   Graph_Graph917->SetDirectory(0);
   Graph_Graph917->SetStats(0);
   Graph_Graph917->SetLineWidth(2);
   Graph_Graph917->GetXaxis()->SetNdivisions(506);
   Graph_Graph917->GetXaxis()->SetLabelFont(42);
   Graph_Graph917->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph917->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph917->GetXaxis()->SetTitleFont(42);
   Graph_Graph917->GetYaxis()->SetNdivisions(506);
   Graph_Graph917->GetYaxis()->SetLabelFont(42);
   Graph_Graph917->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph917->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph917->GetYaxis()->SetTitleFont(42);
   Graph_Graph917->GetZaxis()->SetNdivisions(506);
   Graph_Graph917->GetZaxis()->SetLabelFont(42);
   Graph_Graph917->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph917->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph917->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph917);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx918[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy918[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx918,Graph_fy918);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph918 = new TH1F("Graph_Graph918","Graph",100,0.252,0.468);
   Graph_Graph918->SetMinimum(0.418);
   Graph_Graph918->SetMaximum(0.802);
   Graph_Graph918->SetDirectory(0);
   Graph_Graph918->SetStats(0);
   Graph_Graph918->SetLineWidth(2);
   Graph_Graph918->GetXaxis()->SetNdivisions(506);
   Graph_Graph918->GetXaxis()->SetLabelFont(42);
   Graph_Graph918->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph918->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph918->GetXaxis()->SetTitleFont(42);
   Graph_Graph918->GetYaxis()->SetNdivisions(506);
   Graph_Graph918->GetYaxis()->SetLabelFont(42);
   Graph_Graph918->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph918->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph918->GetYaxis()->SetTitleFont(42);
   Graph_Graph918->GetZaxis()->SetNdivisions(506);
   Graph_Graph918->GetZaxis()->SetLabelFont(42);
   Graph_Graph918->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph918->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph918->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph918);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx919[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy919[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx919,Graph_fy919);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph919 = new TH1F("Graph_Graph919","Graph",100,0.433,0.637);
   Graph_Graph919->SetMinimum(0.418);
   Graph_Graph919->SetMaximum(0.802);
   Graph_Graph919->SetDirectory(0);
   Graph_Graph919->SetStats(0);
   Graph_Graph919->SetLineWidth(2);
   Graph_Graph919->GetXaxis()->SetNdivisions(506);
   Graph_Graph919->GetXaxis()->SetLabelFont(42);
   Graph_Graph919->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph919->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph919->GetXaxis()->SetTitleFont(42);
   Graph_Graph919->GetYaxis()->SetNdivisions(506);
   Graph_Graph919->GetYaxis()->SetLabelFont(42);
   Graph_Graph919->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph919->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph919->GetYaxis()->SetTitleFont(42);
   Graph_Graph919->GetZaxis()->SetNdivisions(506);
   Graph_Graph919->GetZaxis()->SetLabelFont(42);
   Graph_Graph919->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph919->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph919->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph919);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx920[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy920[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx920,Graph_fy920);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph920 = new TH1F("Graph_Graph920","Graph",100,0.606,0.774);
   Graph_Graph920->SetMinimum(0.418);
   Graph_Graph920->SetMaximum(0.802);
   Graph_Graph920->SetDirectory(0);
   Graph_Graph920->SetStats(0);
   Graph_Graph920->SetLineWidth(2);
   Graph_Graph920->GetXaxis()->SetNdivisions(506);
   Graph_Graph920->GetXaxis()->SetLabelFont(42);
   Graph_Graph920->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph920->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph920->GetXaxis()->SetTitleFont(42);
   Graph_Graph920->GetYaxis()->SetNdivisions(506);
   Graph_Graph920->GetYaxis()->SetLabelFont(42);
   Graph_Graph920->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph920->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph920->GetYaxis()->SetTitleFont(42);
   Graph_Graph920->GetZaxis()->SetNdivisions(506);
   Graph_Graph920->GetZaxis()->SetLabelFont(42);
   Graph_Graph920->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph920->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph920->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph920);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx921[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy921[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx921,Graph_fy921);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000e8a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph921 = new TH1F("Graph_Graph921","Graph",100,0.75,0.87);
   Graph_Graph921->SetMinimum(0.418);
   Graph_Graph921->SetMaximum(0.802);
   Graph_Graph921->SetDirectory(0);
   Graph_Graph921->SetStats(0);
   Graph_Graph921->SetLineWidth(2);
   Graph_Graph921->GetXaxis()->SetNdivisions(506);
   Graph_Graph921->GetXaxis()->SetLabelFont(42);
   Graph_Graph921->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph921->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph921->GetXaxis()->SetTitleFont(42);
   Graph_Graph921->GetYaxis()->SetNdivisions(506);
   Graph_Graph921->GetYaxis()->SetLabelFont(42);
   Graph_Graph921->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph921->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph921->GetYaxis()->SetTitleFont(42);
   Graph_Graph921->GetZaxis()->SetNdivisions(506);
   Graph_Graph921->GetZaxis()->SetLabelFont(42);
   Graph_Graph921->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph921->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph921->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph921);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx922[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy922[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx922,Graph_fy922);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0062bd");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph922 = new TH1F("Graph_Graph922","Graph",100,0.852,0.948);
   Graph_Graph922->SetMinimum(0.418);
   Graph_Graph922->SetMaximum(0.802);
   Graph_Graph922->SetDirectory(0);
   Graph_Graph922->SetStats(0);
   Graph_Graph922->SetLineWidth(2);
   Graph_Graph922->GetXaxis()->SetNdivisions(506);
   Graph_Graph922->GetXaxis()->SetLabelFont(42);
   Graph_Graph922->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph922->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph922->GetXaxis()->SetTitleFont(42);
   Graph_Graph922->GetYaxis()->SetNdivisions(506);
   Graph_Graph922->GetYaxis()->SetLabelFont(42);
   Graph_Graph922->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph922->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph922->GetYaxis()->SetTitleFont(42);
   Graph_Graph922->GetZaxis()->SetNdivisions(506);
   Graph_Graph922->GetZaxis()->SetLabelFont(42);
   Graph_Graph922->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph922->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph922->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph922);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx923[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy923[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx923,Graph_fy923);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001890");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph923 = new TH1F("Graph_Graph923","Graph",100,0.934,1.006);
   Graph_Graph923->SetMinimum(0.418);
   Graph_Graph923->SetMaximum(0.802);
   Graph_Graph923->SetDirectory(0);
   Graph_Graph923->SetStats(0);
   Graph_Graph923->SetLineWidth(2);
   Graph_Graph923->GetXaxis()->SetNdivisions(506);
   Graph_Graph923->GetXaxis()->SetLabelFont(42);
   Graph_Graph923->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph923->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph923->GetXaxis()->SetTitleFont(42);
   Graph_Graph923->GetYaxis()->SetNdivisions(506);
   Graph_Graph923->GetYaxis()->SetLabelFont(42);
   Graph_Graph923->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph923->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph923->GetYaxis()->SetTitleFont(42);
   Graph_Graph923->GetZaxis()->SetNdivisions(506);
   Graph_Graph923->GetZaxis()->SetLabelFont(42);
   Graph_Graph923->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph923->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph923->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph923);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx924[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy924[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx924,Graph_fy924);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph924 = new TH1F("Graph_Graph924","Graph",100,0,0.297);
   Graph_Graph924->SetMinimum(0.597);
   Graph_Graph924->SetMaximum(2.673);
   Graph_Graph924->SetDirectory(0);
   Graph_Graph924->SetStats(0);
   Graph_Graph924->SetLineWidth(2);
   Graph_Graph924->GetXaxis()->SetNdivisions(506);
   Graph_Graph924->GetXaxis()->SetLabelFont(42);
   Graph_Graph924->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph924->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph924->GetXaxis()->SetTitleFont(42);
   Graph_Graph924->GetYaxis()->SetNdivisions(506);
   Graph_Graph924->GetYaxis()->SetLabelFont(42);
   Graph_Graph924->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph924->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph924->GetYaxis()->SetTitleFont(42);
   Graph_Graph924->GetZaxis()->SetNdivisions(506);
   Graph_Graph924->GetZaxis()->SetLabelFont(42);
   Graph_Graph924->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph924->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph924->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph924);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx925[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy925[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx925,Graph_fy925);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph925 = new TH1F("Graph_Graph925","Graph",100,0.252,0.468);
   Graph_Graph925->SetMinimum(0.597);
   Graph_Graph925->SetMaximum(2.673);
   Graph_Graph925->SetDirectory(0);
   Graph_Graph925->SetStats(0);
   Graph_Graph925->SetLineWidth(2);
   Graph_Graph925->GetXaxis()->SetNdivisions(506);
   Graph_Graph925->GetXaxis()->SetLabelFont(42);
   Graph_Graph925->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph925->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph925->GetXaxis()->SetTitleFont(42);
   Graph_Graph925->GetYaxis()->SetNdivisions(506);
   Graph_Graph925->GetYaxis()->SetLabelFont(42);
   Graph_Graph925->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph925->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph925->GetYaxis()->SetTitleFont(42);
   Graph_Graph925->GetZaxis()->SetNdivisions(506);
   Graph_Graph925->GetZaxis()->SetLabelFont(42);
   Graph_Graph925->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph925->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph925->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph925);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx926[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy926[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx926,Graph_fy926);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph926 = new TH1F("Graph_Graph926","Graph",100,0.433,0.637);
   Graph_Graph926->SetMinimum(0.597);
   Graph_Graph926->SetMaximum(2.673);
   Graph_Graph926->SetDirectory(0);
   Graph_Graph926->SetStats(0);
   Graph_Graph926->SetLineWidth(2);
   Graph_Graph926->GetXaxis()->SetNdivisions(506);
   Graph_Graph926->GetXaxis()->SetLabelFont(42);
   Graph_Graph926->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph926->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph926->GetXaxis()->SetTitleFont(42);
   Graph_Graph926->GetYaxis()->SetNdivisions(506);
   Graph_Graph926->GetYaxis()->SetLabelFont(42);
   Graph_Graph926->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph926->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph926->GetYaxis()->SetTitleFont(42);
   Graph_Graph926->GetZaxis()->SetNdivisions(506);
   Graph_Graph926->GetZaxis()->SetLabelFont(42);
   Graph_Graph926->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph926->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph926->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph926);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx927[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy927[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx927,Graph_fy927);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph927 = new TH1F("Graph_Graph927","Graph",100,0.606,0.774);
   Graph_Graph927->SetMinimum(0.597);
   Graph_Graph927->SetMaximum(2.673);
   Graph_Graph927->SetDirectory(0);
   Graph_Graph927->SetStats(0);
   Graph_Graph927->SetLineWidth(2);
   Graph_Graph927->GetXaxis()->SetNdivisions(506);
   Graph_Graph927->GetXaxis()->SetLabelFont(42);
   Graph_Graph927->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph927->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph927->GetXaxis()->SetTitleFont(42);
   Graph_Graph927->GetYaxis()->SetNdivisions(506);
   Graph_Graph927->GetYaxis()->SetLabelFont(42);
   Graph_Graph927->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph927->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph927->GetYaxis()->SetTitleFont(42);
   Graph_Graph927->GetZaxis()->SetNdivisions(506);
   Graph_Graph927->GetZaxis()->SetLabelFont(42);
   Graph_Graph927->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph927->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph927->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph927);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx928[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy928[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx928,Graph_fy928);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002d9d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph928 = new TH1F("Graph_Graph928","Graph",100,0.75,0.87);
   Graph_Graph928->SetMinimum(0.597);
   Graph_Graph928->SetMaximum(2.673);
   Graph_Graph928->SetDirectory(0);
   Graph_Graph928->SetStats(0);
   Graph_Graph928->SetLineWidth(2);
   Graph_Graph928->GetXaxis()->SetNdivisions(506);
   Graph_Graph928->GetXaxis()->SetLabelFont(42);
   Graph_Graph928->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph928->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph928->GetXaxis()->SetTitleFont(42);
   Graph_Graph928->GetYaxis()->SetNdivisions(506);
   Graph_Graph928->GetYaxis()->SetLabelFont(42);
   Graph_Graph928->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph928->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph928->GetYaxis()->SetTitleFont(42);
   Graph_Graph928->GetZaxis()->SetNdivisions(506);
   Graph_Graph928->GetZaxis()->SetLabelFont(42);
   Graph_Graph928->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph928->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph928->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph928);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx929[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy929[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx929,Graph_fy929);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph929 = new TH1F("Graph_Graph929","Graph",100,0.852,0.948);
   Graph_Graph929->SetMinimum(0.597);
   Graph_Graph929->SetMaximum(2.673);
   Graph_Graph929->SetDirectory(0);
   Graph_Graph929->SetStats(0);
   Graph_Graph929->SetLineWidth(2);
   Graph_Graph929->GetXaxis()->SetNdivisions(506);
   Graph_Graph929->GetXaxis()->SetLabelFont(42);
   Graph_Graph929->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph929->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph929->GetXaxis()->SetTitleFont(42);
   Graph_Graph929->GetYaxis()->SetNdivisions(506);
   Graph_Graph929->GetYaxis()->SetLabelFont(42);
   Graph_Graph929->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph929->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph929->GetYaxis()->SetTitleFont(42);
   Graph_Graph929->GetZaxis()->SetNdivisions(506);
   Graph_Graph929->GetZaxis()->SetLabelFont(42);
   Graph_Graph929->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph929->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph929->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph929);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx930[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy930[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx930,Graph_fy930);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0054b4");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph930 = new TH1F("Graph_Graph930","Graph",100,0.934,1.006);
   Graph_Graph930->SetMinimum(0.597);
   Graph_Graph930->SetMaximum(2.673);
   Graph_Graph930->SetDirectory(0);
   Graph_Graph930->SetStats(0);
   Graph_Graph930->SetLineWidth(2);
   Graph_Graph930->GetXaxis()->SetNdivisions(506);
   Graph_Graph930->GetXaxis()->SetLabelFont(42);
   Graph_Graph930->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph930->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph930->GetXaxis()->SetTitleFont(42);
   Graph_Graph930->GetYaxis()->SetNdivisions(506);
   Graph_Graph930->GetYaxis()->SetLabelFont(42);
   Graph_Graph930->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph930->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph930->GetYaxis()->SetTitleFont(42);
   Graph_Graph930->GetZaxis()->SetNdivisions(506);
   Graph_Graph930->GetZaxis()->SetLabelFont(42);
   Graph_Graph930->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph930->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph930->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph930);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.001483956);
   _reco_per_true->SetBinContent(2,0.0023113);
   _reco_per_true->SetBinContent(3,0.0007770397);
   _reco_per_true->SetBinContent(4,0.000773186);
   _reco_per_true->SetBinContent(5,0.000773186);
   _reco_per_true->SetBinContent(6,0.0007751494);
   _reco_per_true->SetBinContent(7,0.001547066);
   _reco_per_true->SetBinContent(9,0.000773186);
   _reco_per_true->SetBinContent(11,0.0007847215);
   _reco_per_true->SetBinContent(14,0.003095124);
   _reco_per_true->SetBinContent(15,0.009255521);
   _reco_per_true->SetBinContent(16,0.002314971);
   _reco_per_true->SetBinContent(17,0.00155186);
   _reco_per_true->SetBinContent(18,0.0007759302);
   _reco_per_true->SetBinContent(19,0.0007785531);
   _reco_per_true->SetBinContent(21,0.001507026);
   _reco_per_true->SetBinContent(22,0.01685162);
   _reco_per_true->SetBinContent(23,0.1093048);
   _reco_per_true->SetBinContent(24,0.02680384);
   _reco_per_true->SetBinContent(25,0.0007646068);
   _reco_per_true->SetBinContent(26,0.0007720668);
   _reco_per_true->SetBinContent(27,0.0007769276);
   _reco_per_true->SetBinContent(28,0.0007538748);
   _reco_per_true->SetBinContent(29,0.05085667);
   _reco_per_true->SetBinContent(30,0.6700565);
   _reco_per_true->SetBinContent(31,0.09378134);
   _reco_per_true->SetBinError(1,0.001050138);
   _reco_per_true->SetBinError(2,0.001334467);
   _reco_per_true->SetBinError(3,0.0007770397);
   _reco_per_true->SetBinError(4,0.000773186);
   _reco_per_true->SetBinError(5,0.000773186);
   _reco_per_true->SetBinError(6,0.0007751494);
   _reco_per_true->SetBinError(7,0.001093942);
   _reco_per_true->SetBinError(9,0.000773186);
   _reco_per_true->SetBinError(11,0.0007847215);
   _reco_per_true->SetBinError(14,0.001547587);
   _reco_per_true->SetBinError(15,0.00267226);
   _reco_per_true->SetBinError(16,0.001336573);
   _reco_per_true->SetBinError(17,0.001097331);
   _reco_per_true->SetBinError(18,0.0007759302);
   _reco_per_true->SetBinError(19,0.0007785531);
   _reco_per_true->SetBinError(21,0.001065992);
   _reco_per_true->SetBinError(22,0.003594841);
   _reco_per_true->SetBinError(23,0.009174917);
   _reco_per_true->SetBinError(24,0.004532431);
   _reco_per_true->SetBinError(25,0.0007646068);
   _reco_per_true->SetBinError(26,0.0007720668);
   _reco_per_true->SetBinError(27,0.0007769276);
   _reco_per_true->SetBinError(28,0.0007538748);
   _reco_per_true->SetBinError(29,0.00626118);
   _reco_per_true->SetBinError(30,0.0227341);
   _reco_per_true->SetBinError(31,0.008495334);
   _reco_per_true->SetEntries(1298);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.002627673);
   _reco_per_true->SetContourLevel(2,0.005255345);
   _reco_per_true->SetContourLevel(3,0.007883018);
   _reco_per_true->SetContourLevel(4,0.01051069);
   _reco_per_true->SetContourLevel(5,0.01313836);
   _reco_per_true->SetContourLevel(6,0.01576604);
   _reco_per_true->SetContourLevel(7,0.01839371);
   _reco_per_true->SetContourLevel(8,0.02102138);
   _reco_per_true->SetContourLevel(9,0.02364905);
   _reco_per_true->SetContourLevel(10,0.02627673);
   _reco_per_true->SetContourLevel(11,0.0289044);
   _reco_per_true->SetContourLevel(12,0.03153207);
   _reco_per_true->SetContourLevel(13,0.03415974);
   _reco_per_true->SetContourLevel(14,0.03678742);
   _reco_per_true->SetContourLevel(15,0.03941509);
   _reco_per_true->SetContourLevel(16,0.04204276);
   _reco_per_true->SetContourLevel(17,0.04467043);
   _reco_per_true->SetContourLevel(18,0.04729811);
   _reco_per_true->SetContourLevel(19,0.04992578);
   _reco_per_true->SetContourLevel(20,0.05255345);
   _reco_per_true->SetContourLevel(21,0.05518112);
   _reco_per_true->SetContourLevel(22,0.0578088);
   _reco_per_true->SetContourLevel(23,0.06043647);
   _reco_per_true->SetContourLevel(24,0.06306414);
   _reco_per_true->SetContourLevel(25,0.06569182);
   _reco_per_true->SetContourLevel(26,0.06831949);
   _reco_per_true->SetContourLevel(27,0.07094716);
   _reco_per_true->SetContourLevel(28,0.07357483);
   _reco_per_true->SetContourLevel(29,0.07620251);
   _reco_per_true->SetContourLevel(30,0.07883018);
   _reco_per_true->SetContourLevel(31,0.08145785);
   _reco_per_true->SetContourLevel(32,0.08408552);
   _reco_per_true->SetContourLevel(33,0.0867132);
   _reco_per_true->SetContourLevel(34,0.08934087);
   _reco_per_true->SetContourLevel(35,0.09196854);
   _reco_per_true->SetContourLevel(36,0.09459621);
   _reco_per_true->SetContourLevel(37,0.09722389);
   _reco_per_true->SetContourLevel(38,0.09985156);
   _reco_per_true->SetContourLevel(39,0.1024792);
   _reco_per_true->SetContourLevel(40,0.1051069);
   _reco_per_true->SetContourLevel(41,0.1077346);
   _reco_per_true->SetContourLevel(42,0.1103622);
   _reco_per_true->SetContourLevel(43,0.1129899);
   _reco_per_true->SetContourLevel(44,0.1156176);
   _reco_per_true->SetContourLevel(45,0.1182453);
   _reco_per_true->SetContourLevel(46,0.1208729);
   _reco_per_true->SetContourLevel(47,0.1235006);
   _reco_per_true->SetContourLevel(48,0.1261283);
   _reco_per_true->SetContourLevel(49,0.128756);
   _reco_per_true->SetContourLevel(50,0.1313836);
   _reco_per_true->SetContourLevel(51,0.1340113);
   _reco_per_true->SetContourLevel(52,0.136639);
   _reco_per_true->SetContourLevel(53,0.1392666);
   _reco_per_true->SetContourLevel(54,0.1418943);
   _reco_per_true->SetContourLevel(55,0.144522);
   _reco_per_true->SetContourLevel(56,0.1471497);
   _reco_per_true->SetContourLevel(57,0.1497773);
   _reco_per_true->SetContourLevel(58,0.152405);
   _reco_per_true->SetContourLevel(59,0.1550327);
   _reco_per_true->SetContourLevel(60,0.1576604);
   _reco_per_true->SetContourLevel(61,0.160288);
   _reco_per_true->SetContourLevel(62,0.1629157);
   _reco_per_true->SetContourLevel(63,0.1655434);
   _reco_per_true->SetContourLevel(64,0.168171);
   _reco_per_true->SetContourLevel(65,0.1707987);
   _reco_per_true->SetContourLevel(66,0.1734264);
   _reco_per_true->SetContourLevel(67,0.1760541);
   _reco_per_true->SetContourLevel(68,0.1786817);
   _reco_per_true->SetContourLevel(69,0.1813094);
   _reco_per_true->SetContourLevel(70,0.1839371);
   _reco_per_true->SetContourLevel(71,0.1865648);
   _reco_per_true->SetContourLevel(72,0.1891924);
   _reco_per_true->SetContourLevel(73,0.1918201);
   _reco_per_true->SetContourLevel(74,0.1944478);
   _reco_per_true->SetContourLevel(75,0.1970754);
   _reco_per_true->SetContourLevel(76,0.1997031);
   _reco_per_true->SetContourLevel(77,0.2023308);
   _reco_per_true->SetContourLevel(78,0.2049585);
   _reco_per_true->SetContourLevel(79,0.2075861);
   _reco_per_true->SetContourLevel(80,0.2102138);
   _reco_per_true->SetContourLevel(81,0.2128415);
   _reco_per_true->SetContourLevel(82,0.2154692);
   _reco_per_true->SetContourLevel(83,0.2180968);
   _reco_per_true->SetContourLevel(84,0.2207245);
   _reco_per_true->SetContourLevel(85,0.2233522);
   _reco_per_true->SetContourLevel(86,0.2259798);
   _reco_per_true->SetContourLevel(87,0.2286075);
   _reco_per_true->SetContourLevel(88,0.2312352);
   _reco_per_true->SetContourLevel(89,0.2338629);
   _reco_per_true->SetContourLevel(90,0.2364905);
   _reco_per_true->SetContourLevel(91,0.2391182);
   _reco_per_true->SetContourLevel(92,0.2417459);
   _reco_per_true->SetContourLevel(93,0.2443736);
   _reco_per_true->SetContourLevel(94,0.2470012);
   _reco_per_true->SetContourLevel(95,0.2496289);
   _reco_per_true->SetContourLevel(96,0.2522566);
   _reco_per_true->SetContourLevel(97,0.2548842);
   _reco_per_true->SetContourLevel(98,0.2575119);
   _reco_per_true->SetContourLevel(99,0.2601396);
   _reco_per_true->SetContourLevel(100,0.2627673);
   _reco_per_true->SetContourLevel(101,0.2653949);
   _reco_per_true->SetContourLevel(102,0.2680226);
   _reco_per_true->SetContourLevel(103,0.2706503);
   _reco_per_true->SetContourLevel(104,0.273278);
   _reco_per_true->SetContourLevel(105,0.2759056);
   _reco_per_true->SetContourLevel(106,0.2785333);
   _reco_per_true->SetContourLevel(107,0.281161);
   _reco_per_true->SetContourLevel(108,0.2837886);
   _reco_per_true->SetContourLevel(109,0.2864163);
   _reco_per_true->SetContourLevel(110,0.289044);
   _reco_per_true->SetContourLevel(111,0.2916717);
   _reco_per_true->SetContourLevel(112,0.2942993);
   _reco_per_true->SetContourLevel(113,0.296927);
   _reco_per_true->SetContourLevel(114,0.2995547);
   _reco_per_true->SetContourLevel(115,0.3021823);
   _reco_per_true->SetContourLevel(116,0.30481);
   _reco_per_true->SetContourLevel(117,0.3074377);
   _reco_per_true->SetContourLevel(118,0.3100654);
   _reco_per_true->SetContourLevel(119,0.312693);
   _reco_per_true->SetContourLevel(120,0.3153207);
   _reco_per_true->SetContourLevel(121,0.3179484);
   _reco_per_true->SetContourLevel(122,0.3205761);
   _reco_per_true->SetContourLevel(123,0.3232037);
   _reco_per_true->SetContourLevel(124,0.3258314);
   _reco_per_true->SetContourLevel(125,0.3284591);
   _reco_per_true->SetContourLevel(126,0.3310867);
   _reco_per_true->SetContourLevel(127,0.3337144);
   _reco_per_true->SetContourLevel(128,0.3363421);
   _reco_per_true->SetContourLevel(129,0.3389698);
   _reco_per_true->SetContourLevel(130,0.3415974);
   _reco_per_true->SetContourLevel(131,0.3442251);
   _reco_per_true->SetContourLevel(132,0.3468528);
   _reco_per_true->SetContourLevel(133,0.3494805);
   _reco_per_true->SetContourLevel(134,0.3521081);
   _reco_per_true->SetContourLevel(135,0.3547358);
   _reco_per_true->SetContourLevel(136,0.3573635);
   _reco_per_true->SetContourLevel(137,0.3599911);
   _reco_per_true->SetContourLevel(138,0.3626188);
   _reco_per_true->SetContourLevel(139,0.3652465);
   _reco_per_true->SetContourLevel(140,0.3678742);
   _reco_per_true->SetContourLevel(141,0.3705018);
   _reco_per_true->SetContourLevel(142,0.3731295);
   _reco_per_true->SetContourLevel(143,0.3757572);
   _reco_per_true->SetContourLevel(144,0.3783849);
   _reco_per_true->SetContourLevel(145,0.3810125);
   _reco_per_true->SetContourLevel(146,0.3836402);
   _reco_per_true->SetContourLevel(147,0.3862679);
   _reco_per_true->SetContourLevel(148,0.3888955);
   _reco_per_true->SetContourLevel(149,0.3915232);
   _reco_per_true->SetContourLevel(150,0.3941509);
   _reco_per_true->SetContourLevel(151,0.3967786);
   _reco_per_true->SetContourLevel(152,0.3994062);
   _reco_per_true->SetContourLevel(153,0.4020339);
   _reco_per_true->SetContourLevel(154,0.4046616);
   _reco_per_true->SetContourLevel(155,0.4072893);
   _reco_per_true->SetContourLevel(156,0.4099169);
   _reco_per_true->SetContourLevel(157,0.4125446);
   _reco_per_true->SetContourLevel(158,0.4151723);
   _reco_per_true->SetContourLevel(159,0.4177999);
   _reco_per_true->SetContourLevel(160,0.4204276);
   _reco_per_true->SetContourLevel(161,0.4230553);
   _reco_per_true->SetContourLevel(162,0.425683);
   _reco_per_true->SetContourLevel(163,0.4283106);
   _reco_per_true->SetContourLevel(164,0.4309383);
   _reco_per_true->SetContourLevel(165,0.433566);
   _reco_per_true->SetContourLevel(166,0.4361937);
   _reco_per_true->SetContourLevel(167,0.4388213);
   _reco_per_true->SetContourLevel(168,0.441449);
   _reco_per_true->SetContourLevel(169,0.4440767);
   _reco_per_true->SetContourLevel(170,0.4467043);
   _reco_per_true->SetContourLevel(171,0.449332);
   _reco_per_true->SetContourLevel(172,0.4519597);
   _reco_per_true->SetContourLevel(173,0.4545874);
   _reco_per_true->SetContourLevel(174,0.457215);
   _reco_per_true->SetContourLevel(175,0.4598427);
   _reco_per_true->SetContourLevel(176,0.4624704);
   _reco_per_true->SetContourLevel(177,0.4650981);
   _reco_per_true->SetContourLevel(178,0.4677257);
   _reco_per_true->SetContourLevel(179,0.4703534);
   _reco_per_true->SetContourLevel(180,0.4729811);
   _reco_per_true->SetContourLevel(181,0.4756087);
   _reco_per_true->SetContourLevel(182,0.4782364);
   _reco_per_true->SetContourLevel(183,0.4808641);
   _reco_per_true->SetContourLevel(184,0.4834918);
   _reco_per_true->SetContourLevel(185,0.4861194);
   _reco_per_true->SetContourLevel(186,0.4887471);
   _reco_per_true->SetContourLevel(187,0.4913748);
   _reco_per_true->SetContourLevel(188,0.4940024);
   _reco_per_true->SetContourLevel(189,0.4966301);
   _reco_per_true->SetContourLevel(190,0.4992578);
   _reco_per_true->SetContourLevel(191,0.5018855);
   _reco_per_true->SetContourLevel(192,0.5045131);
   _reco_per_true->SetContourLevel(193,0.5071408);
   _reco_per_true->SetContourLevel(194,0.5097685);
   _reco_per_true->SetContourLevel(195,0.5123962);
   _reco_per_true->SetContourLevel(196,0.5150238);
   _reco_per_true->SetContourLevel(197,0.5176515);
   _reco_per_true->SetContourLevel(198,0.5202792);
   _reco_per_true->SetContourLevel(199,0.5229068);
   _reco_per_true->SetContourLevel(200,0.5255345);
   _reco_per_true->SetContourLevel(201,0.5281622);
   _reco_per_true->SetContourLevel(202,0.5307899);
   _reco_per_true->SetContourLevel(203,0.5334175);
   _reco_per_true->SetContourLevel(204,0.5360452);
   _reco_per_true->SetContourLevel(205,0.5386729);
   _reco_per_true->SetContourLevel(206,0.5413006);
   _reco_per_true->SetContourLevel(207,0.5439282);
   _reco_per_true->SetContourLevel(208,0.5465559);
   _reco_per_true->SetContourLevel(209,0.5491836);
   _reco_per_true->SetContourLevel(210,0.5518112);
   _reco_per_true->SetContourLevel(211,0.5544389);
   _reco_per_true->SetContourLevel(212,0.5570666);
   _reco_per_true->SetContourLevel(213,0.5596943);
   _reco_per_true->SetContourLevel(214,0.5623219);
   _reco_per_true->SetContourLevel(215,0.5649496);
   _reco_per_true->SetContourLevel(216,0.5675773);
   _reco_per_true->SetContourLevel(217,0.570205);
   _reco_per_true->SetContourLevel(218,0.5728326);
   _reco_per_true->SetContourLevel(219,0.5754603);
   _reco_per_true->SetContourLevel(220,0.578088);
   _reco_per_true->SetContourLevel(221,0.5807156);
   _reco_per_true->SetContourLevel(222,0.5833433);
   _reco_per_true->SetContourLevel(223,0.585971);
   _reco_per_true->SetContourLevel(224,0.5885987);
   _reco_per_true->SetContourLevel(225,0.5912263);
   _reco_per_true->SetContourLevel(226,0.593854);
   _reco_per_true->SetContourLevel(227,0.5964817);
   _reco_per_true->SetContourLevel(228,0.5991094);
   _reco_per_true->SetContourLevel(229,0.601737);
   _reco_per_true->SetContourLevel(230,0.6043647);
   _reco_per_true->SetContourLevel(231,0.6069924);
   _reco_per_true->SetContourLevel(232,0.60962);
   _reco_per_true->SetContourLevel(233,0.6122477);
   _reco_per_true->SetContourLevel(234,0.6148754);
   _reco_per_true->SetContourLevel(235,0.6175031);
   _reco_per_true->SetContourLevel(236,0.6201307);
   _reco_per_true->SetContourLevel(237,0.6227584);
   _reco_per_true->SetContourLevel(238,0.6253861);
   _reco_per_true->SetContourLevel(239,0.6280138);
   _reco_per_true->SetContourLevel(240,0.6306414);
   _reco_per_true->SetContourLevel(241,0.6332691);
   _reco_per_true->SetContourLevel(242,0.6358968);
   _reco_per_true->SetContourLevel(243,0.6385244);
   _reco_per_true->SetContourLevel(244,0.6411521);
   _reco_per_true->SetContourLevel(245,0.6437798);
   _reco_per_true->SetContourLevel(246,0.6464075);
   _reco_per_true->SetContourLevel(247,0.6490351);
   _reco_per_true->SetContourLevel(248,0.6516628);
   _reco_per_true->SetContourLevel(249,0.6542905);
   _reco_per_true->SetContourLevel(250,0.6569182);
   _reco_per_true->SetContourLevel(251,0.6595458);
   _reco_per_true->SetContourLevel(252,0.6621735);
   _reco_per_true->SetContourLevel(253,0.6648012);
   _reco_per_true->SetContourLevel(254,0.6674288);
   
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
   
   TPaveText *pt = new TPaveText(0.3947278,0.91975,0.6052722,0.98025,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetTextFont(42);
   TText *AText = pt->AddText("True Bin 29");
   pt->Draw();
   c1_n30->Modified();
   c1_n30->cd();
   c1_n30->SetSelected(c1_n30);
}

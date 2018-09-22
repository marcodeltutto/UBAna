void smearing_matrix_true_26()
{
//=========Macro generated from canvas: c1_n27/c1_n27
//=========  (Sat Sep 22 12:03:57 2018) by ROOT version6.06/06
   TCanvas *c1_n27 = new TCanvas("c1_n27", "c1_n27",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n27->SetHighLightColor(2);
   c1_n27->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n27->SetFillColor(10);
   c1_n27->SetBorderMode(0);
   c1_n27->SetBorderSize(2);
   c1_n27->SetFrameLineWidth(2);
   c1_n27->SetFrameBorderMode(0);
   c1_n27->SetFrameLineWidth(2);
   c1_n27->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 26", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx807[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy807[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx807,Graph_fy807);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph807 = new TH1F("Graph_Graph807","Graph",100,-1.1,0);
   Graph_Graph807->SetMinimum(0);
   Graph_Graph807->SetMaximum(0.33);
   Graph_Graph807->SetDirectory(0);
   Graph_Graph807->SetStats(0);
   Graph_Graph807->SetLineWidth(2);
   Graph_Graph807->GetXaxis()->SetNdivisions(506);
   Graph_Graph807->GetXaxis()->SetLabelFont(42);
   Graph_Graph807->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph807->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph807->GetXaxis()->SetTitleFont(42);
   Graph_Graph807->GetYaxis()->SetNdivisions(506);
   Graph_Graph807->GetYaxis()->SetLabelFont(42);
   Graph_Graph807->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph807->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph807->GetYaxis()->SetTitleFont(42);
   Graph_Graph807->GetZaxis()->SetNdivisions(506);
   Graph_Graph807->GetZaxis()->SetLabelFont(42);
   Graph_Graph807->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph807->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph807->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph807);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx808[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy808[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx808,Graph_fy808);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph808 = new TH1F("Graph_Graph808","Graph",100,0,0.297);
   Graph_Graph808->SetMinimum(0);
   Graph_Graph808->SetMaximum(0.33);
   Graph_Graph808->SetDirectory(0);
   Graph_Graph808->SetStats(0);
   Graph_Graph808->SetLineWidth(2);
   Graph_Graph808->GetXaxis()->SetNdivisions(506);
   Graph_Graph808->GetXaxis()->SetLabelFont(42);
   Graph_Graph808->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph808->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph808->GetXaxis()->SetTitleFont(42);
   Graph_Graph808->GetYaxis()->SetNdivisions(506);
   Graph_Graph808->GetYaxis()->SetLabelFont(42);
   Graph_Graph808->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph808->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph808->GetYaxis()->SetTitleFont(42);
   Graph_Graph808->GetZaxis()->SetNdivisions(506);
   Graph_Graph808->GetZaxis()->SetLabelFont(42);
   Graph_Graph808->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph808->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph808->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph808);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx809[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy809[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx809,Graph_fy809);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph809 = new TH1F("Graph_Graph809","Graph",100,0.252,0.468);
   Graph_Graph809->SetMinimum(0);
   Graph_Graph809->SetMaximum(0.33);
   Graph_Graph809->SetDirectory(0);
   Graph_Graph809->SetStats(0);
   Graph_Graph809->SetLineWidth(2);
   Graph_Graph809->GetXaxis()->SetNdivisions(506);
   Graph_Graph809->GetXaxis()->SetLabelFont(42);
   Graph_Graph809->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph809->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph809->GetXaxis()->SetTitleFont(42);
   Graph_Graph809->GetYaxis()->SetNdivisions(506);
   Graph_Graph809->GetYaxis()->SetLabelFont(42);
   Graph_Graph809->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph809->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph809->GetYaxis()->SetTitleFont(42);
   Graph_Graph809->GetZaxis()->SetNdivisions(506);
   Graph_Graph809->GetZaxis()->SetLabelFont(42);
   Graph_Graph809->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph809->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph809->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph809);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx810[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy810[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx810,Graph_fy810);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph810 = new TH1F("Graph_Graph810","Graph",100,0.433,0.637);
   Graph_Graph810->SetMinimum(0);
   Graph_Graph810->SetMaximum(0.33);
   Graph_Graph810->SetDirectory(0);
   Graph_Graph810->SetStats(0);
   Graph_Graph810->SetLineWidth(2);
   Graph_Graph810->GetXaxis()->SetNdivisions(506);
   Graph_Graph810->GetXaxis()->SetLabelFont(42);
   Graph_Graph810->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph810->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph810->GetXaxis()->SetTitleFont(42);
   Graph_Graph810->GetYaxis()->SetNdivisions(506);
   Graph_Graph810->GetYaxis()->SetLabelFont(42);
   Graph_Graph810->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph810->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph810->GetYaxis()->SetTitleFont(42);
   Graph_Graph810->GetZaxis()->SetNdivisions(506);
   Graph_Graph810->GetZaxis()->SetLabelFont(42);
   Graph_Graph810->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph810->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph810->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph810);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx811[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy811[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx811,Graph_fy811);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph811 = new TH1F("Graph_Graph811","Graph",100,0.606,0.774);
   Graph_Graph811->SetMinimum(0);
   Graph_Graph811->SetMaximum(0.33);
   Graph_Graph811->SetDirectory(0);
   Graph_Graph811->SetStats(0);
   Graph_Graph811->SetLineWidth(2);
   Graph_Graph811->GetXaxis()->SetNdivisions(506);
   Graph_Graph811->GetXaxis()->SetLabelFont(42);
   Graph_Graph811->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph811->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph811->GetXaxis()->SetTitleFont(42);
   Graph_Graph811->GetYaxis()->SetNdivisions(506);
   Graph_Graph811->GetYaxis()->SetLabelFont(42);
   Graph_Graph811->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph811->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph811->GetYaxis()->SetTitleFont(42);
   Graph_Graph811->GetZaxis()->SetNdivisions(506);
   Graph_Graph811->GetZaxis()->SetLabelFont(42);
   Graph_Graph811->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph811->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph811->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph811);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx812[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy812[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx812,Graph_fy812);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph812 = new TH1F("Graph_Graph812","Graph",100,0.75,0.87);
   Graph_Graph812->SetMinimum(0);
   Graph_Graph812->SetMaximum(0.33);
   Graph_Graph812->SetDirectory(0);
   Graph_Graph812->SetStats(0);
   Graph_Graph812->SetLineWidth(2);
   Graph_Graph812->GetXaxis()->SetNdivisions(506);
   Graph_Graph812->GetXaxis()->SetLabelFont(42);
   Graph_Graph812->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph812->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph812->GetXaxis()->SetTitleFont(42);
   Graph_Graph812->GetYaxis()->SetNdivisions(506);
   Graph_Graph812->GetYaxis()->SetLabelFont(42);
   Graph_Graph812->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph812->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph812->GetYaxis()->SetTitleFont(42);
   Graph_Graph812->GetZaxis()->SetNdivisions(506);
   Graph_Graph812->GetZaxis()->SetLabelFont(42);
   Graph_Graph812->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph812->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph812->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph812);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx813[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy813[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx813,Graph_fy813);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph813 = new TH1F("Graph_Graph813","Graph",100,0.852,0.948);
   Graph_Graph813->SetMinimum(0);
   Graph_Graph813->SetMaximum(0.33);
   Graph_Graph813->SetDirectory(0);
   Graph_Graph813->SetStats(0);
   Graph_Graph813->SetLineWidth(2);
   Graph_Graph813->GetXaxis()->SetNdivisions(506);
   Graph_Graph813->GetXaxis()->SetLabelFont(42);
   Graph_Graph813->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph813->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph813->GetXaxis()->SetTitleFont(42);
   Graph_Graph813->GetYaxis()->SetNdivisions(506);
   Graph_Graph813->GetYaxis()->SetLabelFont(42);
   Graph_Graph813->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph813->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph813->GetYaxis()->SetTitleFont(42);
   Graph_Graph813->GetZaxis()->SetNdivisions(506);
   Graph_Graph813->GetZaxis()->SetLabelFont(42);
   Graph_Graph813->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph813->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph813->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph813);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx814[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy814[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx814,Graph_fy814);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph814 = new TH1F("Graph_Graph814","Graph",100,0.934,1.006);
   Graph_Graph814->SetMinimum(0);
   Graph_Graph814->SetMaximum(0.33);
   Graph_Graph814->SetDirectory(0);
   Graph_Graph814->SetStats(0);
   Graph_Graph814->SetLineWidth(2);
   Graph_Graph814->GetXaxis()->SetNdivisions(506);
   Graph_Graph814->GetXaxis()->SetLabelFont(42);
   Graph_Graph814->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph814->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph814->GetXaxis()->SetTitleFont(42);
   Graph_Graph814->GetYaxis()->SetNdivisions(506);
   Graph_Graph814->GetYaxis()->SetLabelFont(42);
   Graph_Graph814->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph814->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph814->GetYaxis()->SetTitleFont(42);
   Graph_Graph814->GetZaxis()->SetNdivisions(506);
   Graph_Graph814->GetZaxis()->SetLabelFont(42);
   Graph_Graph814->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph814->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph814->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph814);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx815[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy815[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx815,Graph_fy815);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph815 = new TH1F("Graph_Graph815","Graph",100,-1.1,0);
   Graph_Graph815->SetMinimum(0.285);
   Graph_Graph815->SetMaximum(0.465);
   Graph_Graph815->SetDirectory(0);
   Graph_Graph815->SetStats(0);
   Graph_Graph815->SetLineWidth(2);
   Graph_Graph815->GetXaxis()->SetNdivisions(506);
   Graph_Graph815->GetXaxis()->SetLabelFont(42);
   Graph_Graph815->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph815->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph815->GetXaxis()->SetTitleFont(42);
   Graph_Graph815->GetYaxis()->SetNdivisions(506);
   Graph_Graph815->GetYaxis()->SetLabelFont(42);
   Graph_Graph815->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph815->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph815->GetYaxis()->SetTitleFont(42);
   Graph_Graph815->GetZaxis()->SetNdivisions(506);
   Graph_Graph815->GetZaxis()->SetLabelFont(42);
   Graph_Graph815->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph815->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph815->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph815);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx816[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy816[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx816,Graph_fy816);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph816 = new TH1F("Graph_Graph816","Graph",100,0,0.297);
   Graph_Graph816->SetMinimum(0.285);
   Graph_Graph816->SetMaximum(0.465);
   Graph_Graph816->SetDirectory(0);
   Graph_Graph816->SetStats(0);
   Graph_Graph816->SetLineWidth(2);
   Graph_Graph816->GetXaxis()->SetNdivisions(506);
   Graph_Graph816->GetXaxis()->SetLabelFont(42);
   Graph_Graph816->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph816->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph816->GetXaxis()->SetTitleFont(42);
   Graph_Graph816->GetYaxis()->SetNdivisions(506);
   Graph_Graph816->GetYaxis()->SetLabelFont(42);
   Graph_Graph816->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph816->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph816->GetYaxis()->SetTitleFont(42);
   Graph_Graph816->GetZaxis()->SetNdivisions(506);
   Graph_Graph816->GetZaxis()->SetLabelFont(42);
   Graph_Graph816->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph816->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph816->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph816);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx817[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy817[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx817,Graph_fy817);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph817 = new TH1F("Graph_Graph817","Graph",100,0.252,0.468);
   Graph_Graph817->SetMinimum(0.285);
   Graph_Graph817->SetMaximum(0.465);
   Graph_Graph817->SetDirectory(0);
   Graph_Graph817->SetStats(0);
   Graph_Graph817->SetLineWidth(2);
   Graph_Graph817->GetXaxis()->SetNdivisions(506);
   Graph_Graph817->GetXaxis()->SetLabelFont(42);
   Graph_Graph817->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph817->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph817->GetXaxis()->SetTitleFont(42);
   Graph_Graph817->GetYaxis()->SetNdivisions(506);
   Graph_Graph817->GetYaxis()->SetLabelFont(42);
   Graph_Graph817->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph817->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph817->GetYaxis()->SetTitleFont(42);
   Graph_Graph817->GetZaxis()->SetNdivisions(506);
   Graph_Graph817->GetZaxis()->SetLabelFont(42);
   Graph_Graph817->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph817->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph817->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph817);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx818[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy818[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx818,Graph_fy818);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00289a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph818 = new TH1F("Graph_Graph818","Graph",100,0.433,0.637);
   Graph_Graph818->SetMinimum(0.285);
   Graph_Graph818->SetMaximum(0.465);
   Graph_Graph818->SetDirectory(0);
   Graph_Graph818->SetStats(0);
   Graph_Graph818->SetLineWidth(2);
   Graph_Graph818->GetXaxis()->SetNdivisions(506);
   Graph_Graph818->GetXaxis()->SetLabelFont(42);
   Graph_Graph818->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph818->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph818->GetXaxis()->SetTitleFont(42);
   Graph_Graph818->GetYaxis()->SetNdivisions(506);
   Graph_Graph818->GetYaxis()->SetLabelFont(42);
   Graph_Graph818->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph818->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph818->GetYaxis()->SetTitleFont(42);
   Graph_Graph818->GetZaxis()->SetNdivisions(506);
   Graph_Graph818->GetZaxis()->SetLabelFont(42);
   Graph_Graph818->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph818->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph818->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph818);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx819[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy819[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx819,Graph_fy819);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph819 = new TH1F("Graph_Graph819","Graph",100,0.606,0.774);
   Graph_Graph819->SetMinimum(0.285);
   Graph_Graph819->SetMaximum(0.465);
   Graph_Graph819->SetDirectory(0);
   Graph_Graph819->SetStats(0);
   Graph_Graph819->SetLineWidth(2);
   Graph_Graph819->GetXaxis()->SetNdivisions(506);
   Graph_Graph819->GetXaxis()->SetLabelFont(42);
   Graph_Graph819->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph819->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph819->GetXaxis()->SetTitleFont(42);
   Graph_Graph819->GetYaxis()->SetNdivisions(506);
   Graph_Graph819->GetYaxis()->SetLabelFont(42);
   Graph_Graph819->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph819->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph819->GetYaxis()->SetTitleFont(42);
   Graph_Graph819->GetZaxis()->SetNdivisions(506);
   Graph_Graph819->GetZaxis()->SetLabelFont(42);
   Graph_Graph819->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph819->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph819->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph819);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx820[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy820[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx820,Graph_fy820);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph820 = new TH1F("Graph_Graph820","Graph",100,0.75,0.87);
   Graph_Graph820->SetMinimum(0.285);
   Graph_Graph820->SetMaximum(0.465);
   Graph_Graph820->SetDirectory(0);
   Graph_Graph820->SetStats(0);
   Graph_Graph820->SetLineWidth(2);
   Graph_Graph820->GetXaxis()->SetNdivisions(506);
   Graph_Graph820->GetXaxis()->SetLabelFont(42);
   Graph_Graph820->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph820->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph820->GetXaxis()->SetTitleFont(42);
   Graph_Graph820->GetYaxis()->SetNdivisions(506);
   Graph_Graph820->GetYaxis()->SetLabelFont(42);
   Graph_Graph820->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph820->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph820->GetYaxis()->SetTitleFont(42);
   Graph_Graph820->GetZaxis()->SetNdivisions(506);
   Graph_Graph820->GetZaxis()->SetLabelFont(42);
   Graph_Graph820->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph820->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph820->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph820);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx821[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy821[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx821,Graph_fy821);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph821 = new TH1F("Graph_Graph821","Graph",100,0.852,0.948);
   Graph_Graph821->SetMinimum(0.285);
   Graph_Graph821->SetMaximum(0.465);
   Graph_Graph821->SetDirectory(0);
   Graph_Graph821->SetStats(0);
   Graph_Graph821->SetLineWidth(2);
   Graph_Graph821->GetXaxis()->SetNdivisions(506);
   Graph_Graph821->GetXaxis()->SetLabelFont(42);
   Graph_Graph821->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph821->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph821->GetXaxis()->SetTitleFont(42);
   Graph_Graph821->GetYaxis()->SetNdivisions(506);
   Graph_Graph821->GetYaxis()->SetLabelFont(42);
   Graph_Graph821->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph821->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph821->GetYaxis()->SetTitleFont(42);
   Graph_Graph821->GetZaxis()->SetNdivisions(506);
   Graph_Graph821->GetZaxis()->SetLabelFont(42);
   Graph_Graph821->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph821->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph821->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph821);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx822[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy822[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx822,Graph_fy822);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph822 = new TH1F("Graph_Graph822","Graph",100,0.934,1.006);
   Graph_Graph822->SetMinimum(0.285);
   Graph_Graph822->SetMaximum(0.465);
   Graph_Graph822->SetDirectory(0);
   Graph_Graph822->SetStats(0);
   Graph_Graph822->SetLineWidth(2);
   Graph_Graph822->GetXaxis()->SetNdivisions(506);
   Graph_Graph822->GetXaxis()->SetLabelFont(42);
   Graph_Graph822->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph822->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph822->GetXaxis()->SetTitleFont(42);
   Graph_Graph822->GetYaxis()->SetNdivisions(506);
   Graph_Graph822->GetYaxis()->SetLabelFont(42);
   Graph_Graph822->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph822->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph822->GetYaxis()->SetTitleFont(42);
   Graph_Graph822->GetZaxis()->SetNdivisions(506);
   Graph_Graph822->GetZaxis()->SetLabelFont(42);
   Graph_Graph822->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph822->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph822->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph822);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx823[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy823[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx823,Graph_fy823);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph823 = new TH1F("Graph_Graph823","Graph",100,-1.1,0);
   Graph_Graph823->SetMinimum(0.245);
   Graph_Graph823->SetMaximum(2.705);
   Graph_Graph823->SetDirectory(0);
   Graph_Graph823->SetStats(0);
   Graph_Graph823->SetLineWidth(2);
   Graph_Graph823->GetXaxis()->SetNdivisions(506);
   Graph_Graph823->GetXaxis()->SetLabelFont(42);
   Graph_Graph823->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph823->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph823->GetXaxis()->SetTitleFont(42);
   Graph_Graph823->GetYaxis()->SetNdivisions(506);
   Graph_Graph823->GetYaxis()->SetLabelFont(42);
   Graph_Graph823->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph823->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph823->GetYaxis()->SetTitleFont(42);
   Graph_Graph823->GetZaxis()->SetNdivisions(506);
   Graph_Graph823->GetZaxis()->SetLabelFont(42);
   Graph_Graph823->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph823->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph823->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph823);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx824[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy824[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx824,Graph_fy824);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph824 = new TH1F("Graph_Graph824","Graph",100,0,0.297);
   Graph_Graph824->SetMinimum(0.418);
   Graph_Graph824->SetMaximum(0.802);
   Graph_Graph824->SetDirectory(0);
   Graph_Graph824->SetStats(0);
   Graph_Graph824->SetLineWidth(2);
   Graph_Graph824->GetXaxis()->SetNdivisions(506);
   Graph_Graph824->GetXaxis()->SetLabelFont(42);
   Graph_Graph824->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph824->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph824->GetXaxis()->SetTitleFont(42);
   Graph_Graph824->GetYaxis()->SetNdivisions(506);
   Graph_Graph824->GetYaxis()->SetLabelFont(42);
   Graph_Graph824->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph824->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph824->GetYaxis()->SetTitleFont(42);
   Graph_Graph824->GetZaxis()->SetNdivisions(506);
   Graph_Graph824->GetZaxis()->SetLabelFont(42);
   Graph_Graph824->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph824->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph824->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph824);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx825[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy825[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx825,Graph_fy825);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002b9c");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph825 = new TH1F("Graph_Graph825","Graph",100,0.252,0.468);
   Graph_Graph825->SetMinimum(0.418);
   Graph_Graph825->SetMaximum(0.802);
   Graph_Graph825->SetDirectory(0);
   Graph_Graph825->SetStats(0);
   Graph_Graph825->SetLineWidth(2);
   Graph_Graph825->GetXaxis()->SetNdivisions(506);
   Graph_Graph825->GetXaxis()->SetLabelFont(42);
   Graph_Graph825->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph825->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph825->GetXaxis()->SetTitleFont(42);
   Graph_Graph825->GetYaxis()->SetNdivisions(506);
   Graph_Graph825->GetYaxis()->SetLabelFont(42);
   Graph_Graph825->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph825->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph825->GetYaxis()->SetTitleFont(42);
   Graph_Graph825->GetZaxis()->SetNdivisions(506);
   Graph_Graph825->GetZaxis()->SetLabelFont(42);
   Graph_Graph825->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph825->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph825->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph825);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx826[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy826[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx826,Graph_fy826);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#fb4b03");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph826 = new TH1F("Graph_Graph826","Graph",100,0.433,0.637);
   Graph_Graph826->SetMinimum(0.418);
   Graph_Graph826->SetMaximum(0.802);
   Graph_Graph826->SetDirectory(0);
   Graph_Graph826->SetStats(0);
   Graph_Graph826->SetLineWidth(2);
   Graph_Graph826->GetXaxis()->SetNdivisions(506);
   Graph_Graph826->GetXaxis()->SetLabelFont(42);
   Graph_Graph826->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph826->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph826->GetXaxis()->SetTitleFont(42);
   Graph_Graph826->GetYaxis()->SetNdivisions(506);
   Graph_Graph826->GetYaxis()->SetLabelFont(42);
   Graph_Graph826->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph826->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph826->GetYaxis()->SetTitleFont(42);
   Graph_Graph826->GetZaxis()->SetNdivisions(506);
   Graph_Graph826->GetZaxis()->SetLabelFont(42);
   Graph_Graph826->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph826->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph826->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph826);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx827[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy827[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx827,Graph_fy827);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0099df");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph827 = new TH1F("Graph_Graph827","Graph",100,0.606,0.774);
   Graph_Graph827->SetMinimum(0.418);
   Graph_Graph827->SetMaximum(0.802);
   Graph_Graph827->SetDirectory(0);
   Graph_Graph827->SetStats(0);
   Graph_Graph827->SetLineWidth(2);
   Graph_Graph827->GetXaxis()->SetNdivisions(506);
   Graph_Graph827->GetXaxis()->SetLabelFont(42);
   Graph_Graph827->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph827->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph827->GetXaxis()->SetTitleFont(42);
   Graph_Graph827->GetYaxis()->SetNdivisions(506);
   Graph_Graph827->GetYaxis()->SetLabelFont(42);
   Graph_Graph827->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph827->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph827->GetYaxis()->SetTitleFont(42);
   Graph_Graph827->GetZaxis()->SetNdivisions(506);
   Graph_Graph827->GetZaxis()->SetLabelFont(42);
   Graph_Graph827->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph827->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph827->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph827);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx828[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy828[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx828,Graph_fy828);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph828 = new TH1F("Graph_Graph828","Graph",100,0.75,0.87);
   Graph_Graph828->SetMinimum(0.418);
   Graph_Graph828->SetMaximum(0.802);
   Graph_Graph828->SetDirectory(0);
   Graph_Graph828->SetStats(0);
   Graph_Graph828->SetLineWidth(2);
   Graph_Graph828->GetXaxis()->SetNdivisions(506);
   Graph_Graph828->GetXaxis()->SetLabelFont(42);
   Graph_Graph828->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph828->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph828->GetXaxis()->SetTitleFont(42);
   Graph_Graph828->GetYaxis()->SetNdivisions(506);
   Graph_Graph828->GetYaxis()->SetLabelFont(42);
   Graph_Graph828->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph828->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph828->GetYaxis()->SetTitleFont(42);
   Graph_Graph828->GetZaxis()->SetNdivisions(506);
   Graph_Graph828->GetZaxis()->SetLabelFont(42);
   Graph_Graph828->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph828->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph828->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph828);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx829[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy829[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx829,Graph_fy829);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph829 = new TH1F("Graph_Graph829","Graph",100,0.852,0.948);
   Graph_Graph829->SetMinimum(0.418);
   Graph_Graph829->SetMaximum(0.802);
   Graph_Graph829->SetDirectory(0);
   Graph_Graph829->SetStats(0);
   Graph_Graph829->SetLineWidth(2);
   Graph_Graph829->GetXaxis()->SetNdivisions(506);
   Graph_Graph829->GetXaxis()->SetLabelFont(42);
   Graph_Graph829->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph829->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph829->GetXaxis()->SetTitleFont(42);
   Graph_Graph829->GetYaxis()->SetNdivisions(506);
   Graph_Graph829->GetYaxis()->SetLabelFont(42);
   Graph_Graph829->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph829->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph829->GetYaxis()->SetTitleFont(42);
   Graph_Graph829->GetZaxis()->SetNdivisions(506);
   Graph_Graph829->GetZaxis()->SetLabelFont(42);
   Graph_Graph829->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph829->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph829->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph829);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx830[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy830[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx830,Graph_fy830);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph830 = new TH1F("Graph_Graph830","Graph",100,0.934,1.006);
   Graph_Graph830->SetMinimum(0.418);
   Graph_Graph830->SetMaximum(0.802);
   Graph_Graph830->SetDirectory(0);
   Graph_Graph830->SetStats(0);
   Graph_Graph830->SetLineWidth(2);
   Graph_Graph830->GetXaxis()->SetNdivisions(506);
   Graph_Graph830->GetXaxis()->SetLabelFont(42);
   Graph_Graph830->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph830->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph830->GetXaxis()->SetTitleFont(42);
   Graph_Graph830->GetYaxis()->SetNdivisions(506);
   Graph_Graph830->GetYaxis()->SetLabelFont(42);
   Graph_Graph830->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph830->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph830->GetYaxis()->SetTitleFont(42);
   Graph_Graph830->GetZaxis()->SetNdivisions(506);
   Graph_Graph830->GetZaxis()->SetLabelFont(42);
   Graph_Graph830->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph830->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph830->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph830);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx831[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy831[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx831,Graph_fy831);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph831 = new TH1F("Graph_Graph831","Graph",100,0,0.297);
   Graph_Graph831->SetMinimum(0.597);
   Graph_Graph831->SetMaximum(2.673);
   Graph_Graph831->SetDirectory(0);
   Graph_Graph831->SetStats(0);
   Graph_Graph831->SetLineWidth(2);
   Graph_Graph831->GetXaxis()->SetNdivisions(506);
   Graph_Graph831->GetXaxis()->SetLabelFont(42);
   Graph_Graph831->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph831->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph831->GetXaxis()->SetTitleFont(42);
   Graph_Graph831->GetYaxis()->SetNdivisions(506);
   Graph_Graph831->GetYaxis()->SetLabelFont(42);
   Graph_Graph831->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph831->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph831->GetYaxis()->SetTitleFont(42);
   Graph_Graph831->GetZaxis()->SetNdivisions(506);
   Graph_Graph831->GetZaxis()->SetLabelFont(42);
   Graph_Graph831->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph831->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph831->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph831);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx832[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy832[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx832,Graph_fy832);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002b9c");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph832 = new TH1F("Graph_Graph832","Graph",100,0.252,0.468);
   Graph_Graph832->SetMinimum(0.597);
   Graph_Graph832->SetMaximum(2.673);
   Graph_Graph832->SetDirectory(0);
   Graph_Graph832->SetStats(0);
   Graph_Graph832->SetLineWidth(2);
   Graph_Graph832->GetXaxis()->SetNdivisions(506);
   Graph_Graph832->GetXaxis()->SetLabelFont(42);
   Graph_Graph832->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph832->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph832->GetXaxis()->SetTitleFont(42);
   Graph_Graph832->GetYaxis()->SetNdivisions(506);
   Graph_Graph832->GetYaxis()->SetLabelFont(42);
   Graph_Graph832->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph832->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph832->GetYaxis()->SetTitleFont(42);
   Graph_Graph832->GetZaxis()->SetNdivisions(506);
   Graph_Graph832->GetZaxis()->SetLabelFont(42);
   Graph_Graph832->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph832->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph832->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph832);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx833[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy833[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx833,Graph_fy833);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph833 = new TH1F("Graph_Graph833","Graph",100,0.433,0.637);
   Graph_Graph833->SetMinimum(0.597);
   Graph_Graph833->SetMaximum(2.673);
   Graph_Graph833->SetDirectory(0);
   Graph_Graph833->SetStats(0);
   Graph_Graph833->SetLineWidth(2);
   Graph_Graph833->GetXaxis()->SetNdivisions(506);
   Graph_Graph833->GetXaxis()->SetLabelFont(42);
   Graph_Graph833->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph833->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph833->GetXaxis()->SetTitleFont(42);
   Graph_Graph833->GetYaxis()->SetNdivisions(506);
   Graph_Graph833->GetYaxis()->SetLabelFont(42);
   Graph_Graph833->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph833->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph833->GetYaxis()->SetTitleFont(42);
   Graph_Graph833->GetZaxis()->SetNdivisions(506);
   Graph_Graph833->GetZaxis()->SetLabelFont(42);
   Graph_Graph833->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph833->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph833->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph833);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx834[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy834[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx834,Graph_fy834);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0056b6");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph834 = new TH1F("Graph_Graph834","Graph",100,0.606,0.774);
   Graph_Graph834->SetMinimum(0.597);
   Graph_Graph834->SetMaximum(2.673);
   Graph_Graph834->SetDirectory(0);
   Graph_Graph834->SetStats(0);
   Graph_Graph834->SetLineWidth(2);
   Graph_Graph834->GetXaxis()->SetNdivisions(506);
   Graph_Graph834->GetXaxis()->SetLabelFont(42);
   Graph_Graph834->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph834->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph834->GetXaxis()->SetTitleFont(42);
   Graph_Graph834->GetYaxis()->SetNdivisions(506);
   Graph_Graph834->GetYaxis()->SetLabelFont(42);
   Graph_Graph834->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph834->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph834->GetYaxis()->SetTitleFont(42);
   Graph_Graph834->GetZaxis()->SetNdivisions(506);
   Graph_Graph834->GetZaxis()->SetLabelFont(42);
   Graph_Graph834->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph834->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph834->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph834);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx835[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy835[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx835,Graph_fy835);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph835 = new TH1F("Graph_Graph835","Graph",100,0.75,0.87);
   Graph_Graph835->SetMinimum(0.597);
   Graph_Graph835->SetMaximum(2.673);
   Graph_Graph835->SetDirectory(0);
   Graph_Graph835->SetStats(0);
   Graph_Graph835->SetLineWidth(2);
   Graph_Graph835->GetXaxis()->SetNdivisions(506);
   Graph_Graph835->GetXaxis()->SetLabelFont(42);
   Graph_Graph835->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph835->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph835->GetXaxis()->SetTitleFont(42);
   Graph_Graph835->GetYaxis()->SetNdivisions(506);
   Graph_Graph835->GetYaxis()->SetLabelFont(42);
   Graph_Graph835->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph835->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph835->GetYaxis()->SetTitleFont(42);
   Graph_Graph835->GetZaxis()->SetNdivisions(506);
   Graph_Graph835->GetZaxis()->SetLabelFont(42);
   Graph_Graph835->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph835->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph835->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph835);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx836[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy836[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx836,Graph_fy836);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph836 = new TH1F("Graph_Graph836","Graph",100,0.852,0.948);
   Graph_Graph836->SetMinimum(0.597);
   Graph_Graph836->SetMaximum(2.673);
   Graph_Graph836->SetDirectory(0);
   Graph_Graph836->SetStats(0);
   Graph_Graph836->SetLineWidth(2);
   Graph_Graph836->GetXaxis()->SetNdivisions(506);
   Graph_Graph836->GetXaxis()->SetLabelFont(42);
   Graph_Graph836->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph836->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph836->GetXaxis()->SetTitleFont(42);
   Graph_Graph836->GetYaxis()->SetNdivisions(506);
   Graph_Graph836->GetYaxis()->SetLabelFont(42);
   Graph_Graph836->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph836->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph836->GetYaxis()->SetTitleFont(42);
   Graph_Graph836->GetZaxis()->SetNdivisions(506);
   Graph_Graph836->GetZaxis()->SetLabelFont(42);
   Graph_Graph836->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph836->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph836->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph836);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx837[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy837[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx837,Graph_fy837);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph837 = new TH1F("Graph_Graph837","Graph",100,0.934,1.006);
   Graph_Graph837->SetMinimum(0.597);
   Graph_Graph837->SetMaximum(2.673);
   Graph_Graph837->SetDirectory(0);
   Graph_Graph837->SetStats(0);
   Graph_Graph837->SetLineWidth(2);
   Graph_Graph837->GetXaxis()->SetNdivisions(506);
   Graph_Graph837->GetXaxis()->SetLabelFont(42);
   Graph_Graph837->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph837->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph837->GetXaxis()->SetTitleFont(42);
   Graph_Graph837->GetYaxis()->SetNdivisions(506);
   Graph_Graph837->GetYaxis()->SetLabelFont(42);
   Graph_Graph837->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph837->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph837->GetYaxis()->SetTitleFont(42);
   Graph_Graph837->GetZaxis()->SetNdivisions(506);
   Graph_Graph837->GetZaxis()->SetLabelFont(42);
   Graph_Graph837->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph837->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph837->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph837);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(11,0.01380253);
   _reco_per_true->SetBinContent(12,0.02639422);
   _reco_per_true->SetBinContent(13,0.01386606);
   _reco_per_true->SetBinContent(17,0.01380296);
   _reco_per_true->SetBinContent(19,0.02751929);
   _reco_per_true->SetBinContent(20,0.3132541);
   _reco_per_true->SetBinContent(21,0.09667867);
   _reco_per_true->SetBinContent(26,0.02757749);
   _reco_per_true->SetBinContent(27,0.3850642);
   _reco_per_true->SetBinContent(28,0.05466941);
   _reco_per_true->SetBinContent(29,0.01363279);
   _reco_per_true->SetBinContent(30,0.01373834);
   _reco_per_true->SetBinError(11,0.01380253);
   _reco_per_true->SetBinError(12,0.01868057);
   _reco_per_true->SetBinError(13,0.01386606);
   _reco_per_true->SetBinError(17,0.01380296);
   _reco_per_true->SetBinError(19,0.01945908);
   _reco_per_true->SetBinError(20,0.06535054);
   _reco_per_true->SetBinError(21,0.03654123);
   _reco_per_true->SetBinError(26,0.01950027);
   _reco_per_true->SetBinError(27,0.0727728);
   _reco_per_true->SetBinError(28,0.02733767);
   _reco_per_true->SetBinError(29,0.01363279);
   _reco_per_true->SetBinError(30,0.01373834);
   _reco_per_true->SetEntries(73);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.001510056);
   _reco_per_true->SetContourLevel(2,0.003020111);
   _reco_per_true->SetContourLevel(3,0.004530167);
   _reco_per_true->SetContourLevel(4,0.006040222);
   _reco_per_true->SetContourLevel(5,0.007550278);
   _reco_per_true->SetContourLevel(6,0.009060333);
   _reco_per_true->SetContourLevel(7,0.01057039);
   _reco_per_true->SetContourLevel(8,0.01208044);
   _reco_per_true->SetContourLevel(9,0.0135905);
   _reco_per_true->SetContourLevel(10,0.01510056);
   _reco_per_true->SetContourLevel(11,0.01661061);
   _reco_per_true->SetContourLevel(12,0.01812067);
   _reco_per_true->SetContourLevel(13,0.01963072);
   _reco_per_true->SetContourLevel(14,0.02114078);
   _reco_per_true->SetContourLevel(15,0.02265083);
   _reco_per_true->SetContourLevel(16,0.02416089);
   _reco_per_true->SetContourLevel(17,0.02567094);
   _reco_per_true->SetContourLevel(18,0.027181);
   _reco_per_true->SetContourLevel(19,0.02869105);
   _reco_per_true->SetContourLevel(20,0.03020111);
   _reco_per_true->SetContourLevel(21,0.03171117);
   _reco_per_true->SetContourLevel(22,0.03322122);
   _reco_per_true->SetContourLevel(23,0.03473128);
   _reco_per_true->SetContourLevel(24,0.03624133);
   _reco_per_true->SetContourLevel(25,0.03775139);
   _reco_per_true->SetContourLevel(26,0.03926144);
   _reco_per_true->SetContourLevel(27,0.0407715);
   _reco_per_true->SetContourLevel(28,0.04228155);
   _reco_per_true->SetContourLevel(29,0.04379161);
   _reco_per_true->SetContourLevel(30,0.04530167);
   _reco_per_true->SetContourLevel(31,0.04681172);
   _reco_per_true->SetContourLevel(32,0.04832178);
   _reco_per_true->SetContourLevel(33,0.04983183);
   _reco_per_true->SetContourLevel(34,0.05134189);
   _reco_per_true->SetContourLevel(35,0.05285194);
   _reco_per_true->SetContourLevel(36,0.054362);
   _reco_per_true->SetContourLevel(37,0.05587205);
   _reco_per_true->SetContourLevel(38,0.05738211);
   _reco_per_true->SetContourLevel(39,0.05889216);
   _reco_per_true->SetContourLevel(40,0.06040222);
   _reco_per_true->SetContourLevel(41,0.06191228);
   _reco_per_true->SetContourLevel(42,0.06342233);
   _reco_per_true->SetContourLevel(43,0.06493239);
   _reco_per_true->SetContourLevel(44,0.06644244);
   _reco_per_true->SetContourLevel(45,0.0679525);
   _reco_per_true->SetContourLevel(46,0.06946255);
   _reco_per_true->SetContourLevel(47,0.07097261);
   _reco_per_true->SetContourLevel(48,0.07248266);
   _reco_per_true->SetContourLevel(49,0.07399272);
   _reco_per_true->SetContourLevel(50,0.07550278);
   _reco_per_true->SetContourLevel(51,0.07701283);
   _reco_per_true->SetContourLevel(52,0.07852289);
   _reco_per_true->SetContourLevel(53,0.08003294);
   _reco_per_true->SetContourLevel(54,0.081543);
   _reco_per_true->SetContourLevel(55,0.08305305);
   _reco_per_true->SetContourLevel(56,0.08456311);
   _reco_per_true->SetContourLevel(57,0.08607316);
   _reco_per_true->SetContourLevel(58,0.08758322);
   _reco_per_true->SetContourLevel(59,0.08909328);
   _reco_per_true->SetContourLevel(60,0.09060333);
   _reco_per_true->SetContourLevel(61,0.09211339);
   _reco_per_true->SetContourLevel(62,0.09362344);
   _reco_per_true->SetContourLevel(63,0.0951335);
   _reco_per_true->SetContourLevel(64,0.09664355);
   _reco_per_true->SetContourLevel(65,0.09815361);
   _reco_per_true->SetContourLevel(66,0.09966366);
   _reco_per_true->SetContourLevel(67,0.1011737);
   _reco_per_true->SetContourLevel(68,0.1026838);
   _reco_per_true->SetContourLevel(69,0.1041938);
   _reco_per_true->SetContourLevel(70,0.1057039);
   _reco_per_true->SetContourLevel(71,0.1072139);
   _reco_per_true->SetContourLevel(72,0.108724);
   _reco_per_true->SetContourLevel(73,0.1102341);
   _reco_per_true->SetContourLevel(74,0.1117441);
   _reco_per_true->SetContourLevel(75,0.1132542);
   _reco_per_true->SetContourLevel(76,0.1147642);
   _reco_per_true->SetContourLevel(77,0.1162743);
   _reco_per_true->SetContourLevel(78,0.1177843);
   _reco_per_true->SetContourLevel(79,0.1192944);
   _reco_per_true->SetContourLevel(80,0.1208044);
   _reco_per_true->SetContourLevel(81,0.1223145);
   _reco_per_true->SetContourLevel(82,0.1238246);
   _reco_per_true->SetContourLevel(83,0.1253346);
   _reco_per_true->SetContourLevel(84,0.1268447);
   _reco_per_true->SetContourLevel(85,0.1283547);
   _reco_per_true->SetContourLevel(86,0.1298648);
   _reco_per_true->SetContourLevel(87,0.1313748);
   _reco_per_true->SetContourLevel(88,0.1328849);
   _reco_per_true->SetContourLevel(89,0.1343949);
   _reco_per_true->SetContourLevel(90,0.135905);
   _reco_per_true->SetContourLevel(91,0.1374151);
   _reco_per_true->SetContourLevel(92,0.1389251);
   _reco_per_true->SetContourLevel(93,0.1404352);
   _reco_per_true->SetContourLevel(94,0.1419452);
   _reco_per_true->SetContourLevel(95,0.1434553);
   _reco_per_true->SetContourLevel(96,0.1449653);
   _reco_per_true->SetContourLevel(97,0.1464754);
   _reco_per_true->SetContourLevel(98,0.1479854);
   _reco_per_true->SetContourLevel(99,0.1494955);
   _reco_per_true->SetContourLevel(100,0.1510056);
   _reco_per_true->SetContourLevel(101,0.1525156);
   _reco_per_true->SetContourLevel(102,0.1540257);
   _reco_per_true->SetContourLevel(103,0.1555357);
   _reco_per_true->SetContourLevel(104,0.1570458);
   _reco_per_true->SetContourLevel(105,0.1585558);
   _reco_per_true->SetContourLevel(106,0.1600659);
   _reco_per_true->SetContourLevel(107,0.1615759);
   _reco_per_true->SetContourLevel(108,0.163086);
   _reco_per_true->SetContourLevel(109,0.1645961);
   _reco_per_true->SetContourLevel(110,0.1661061);
   _reco_per_true->SetContourLevel(111,0.1676162);
   _reco_per_true->SetContourLevel(112,0.1691262);
   _reco_per_true->SetContourLevel(113,0.1706363);
   _reco_per_true->SetContourLevel(114,0.1721463);
   _reco_per_true->SetContourLevel(115,0.1736564);
   _reco_per_true->SetContourLevel(116,0.1751664);
   _reco_per_true->SetContourLevel(117,0.1766765);
   _reco_per_true->SetContourLevel(118,0.1781866);
   _reco_per_true->SetContourLevel(119,0.1796966);
   _reco_per_true->SetContourLevel(120,0.1812067);
   _reco_per_true->SetContourLevel(121,0.1827167);
   _reco_per_true->SetContourLevel(122,0.1842268);
   _reco_per_true->SetContourLevel(123,0.1857368);
   _reco_per_true->SetContourLevel(124,0.1872469);
   _reco_per_true->SetContourLevel(125,0.1887569);
   _reco_per_true->SetContourLevel(126,0.190267);
   _reco_per_true->SetContourLevel(127,0.191777);
   _reco_per_true->SetContourLevel(128,0.1932871);
   _reco_per_true->SetContourLevel(129,0.1947972);
   _reco_per_true->SetContourLevel(130,0.1963072);
   _reco_per_true->SetContourLevel(131,0.1978173);
   _reco_per_true->SetContourLevel(132,0.1993273);
   _reco_per_true->SetContourLevel(133,0.2008374);
   _reco_per_true->SetContourLevel(134,0.2023474);
   _reco_per_true->SetContourLevel(135,0.2038575);
   _reco_per_true->SetContourLevel(136,0.2053675);
   _reco_per_true->SetContourLevel(137,0.2068776);
   _reco_per_true->SetContourLevel(138,0.2083877);
   _reco_per_true->SetContourLevel(139,0.2098977);
   _reco_per_true->SetContourLevel(140,0.2114078);
   _reco_per_true->SetContourLevel(141,0.2129178);
   _reco_per_true->SetContourLevel(142,0.2144279);
   _reco_per_true->SetContourLevel(143,0.2159379);
   _reco_per_true->SetContourLevel(144,0.217448);
   _reco_per_true->SetContourLevel(145,0.218958);
   _reco_per_true->SetContourLevel(146,0.2204681);
   _reco_per_true->SetContourLevel(147,0.2219782);
   _reco_per_true->SetContourLevel(148,0.2234882);
   _reco_per_true->SetContourLevel(149,0.2249983);
   _reco_per_true->SetContourLevel(150,0.2265083);
   _reco_per_true->SetContourLevel(151,0.2280184);
   _reco_per_true->SetContourLevel(152,0.2295284);
   _reco_per_true->SetContourLevel(153,0.2310385);
   _reco_per_true->SetContourLevel(154,0.2325485);
   _reco_per_true->SetContourLevel(155,0.2340586);
   _reco_per_true->SetContourLevel(156,0.2355687);
   _reco_per_true->SetContourLevel(157,0.2370787);
   _reco_per_true->SetContourLevel(158,0.2385888);
   _reco_per_true->SetContourLevel(159,0.2400988);
   _reco_per_true->SetContourLevel(160,0.2416089);
   _reco_per_true->SetContourLevel(161,0.2431189);
   _reco_per_true->SetContourLevel(162,0.244629);
   _reco_per_true->SetContourLevel(163,0.246139);
   _reco_per_true->SetContourLevel(164,0.2476491);
   _reco_per_true->SetContourLevel(165,0.2491592);
   _reco_per_true->SetContourLevel(166,0.2506692);
   _reco_per_true->SetContourLevel(167,0.2521793);
   _reco_per_true->SetContourLevel(168,0.2536893);
   _reco_per_true->SetContourLevel(169,0.2551994);
   _reco_per_true->SetContourLevel(170,0.2567094);
   _reco_per_true->SetContourLevel(171,0.2582195);
   _reco_per_true->SetContourLevel(172,0.2597295);
   _reco_per_true->SetContourLevel(173,0.2612396);
   _reco_per_true->SetContourLevel(174,0.2627497);
   _reco_per_true->SetContourLevel(175,0.2642597);
   _reco_per_true->SetContourLevel(176,0.2657698);
   _reco_per_true->SetContourLevel(177,0.2672798);
   _reco_per_true->SetContourLevel(178,0.2687899);
   _reco_per_true->SetContourLevel(179,0.2702999);
   _reco_per_true->SetContourLevel(180,0.27181);
   _reco_per_true->SetContourLevel(181,0.27332);
   _reco_per_true->SetContourLevel(182,0.2748301);
   _reco_per_true->SetContourLevel(183,0.2763402);
   _reco_per_true->SetContourLevel(184,0.2778502);
   _reco_per_true->SetContourLevel(185,0.2793603);
   _reco_per_true->SetContourLevel(186,0.2808703);
   _reco_per_true->SetContourLevel(187,0.2823804);
   _reco_per_true->SetContourLevel(188,0.2838904);
   _reco_per_true->SetContourLevel(189,0.2854005);
   _reco_per_true->SetContourLevel(190,0.2869105);
   _reco_per_true->SetContourLevel(191,0.2884206);
   _reco_per_true->SetContourLevel(192,0.2899307);
   _reco_per_true->SetContourLevel(193,0.2914407);
   _reco_per_true->SetContourLevel(194,0.2929508);
   _reco_per_true->SetContourLevel(195,0.2944608);
   _reco_per_true->SetContourLevel(196,0.2959709);
   _reco_per_true->SetContourLevel(197,0.2974809);
   _reco_per_true->SetContourLevel(198,0.298991);
   _reco_per_true->SetContourLevel(199,0.300501);
   _reco_per_true->SetContourLevel(200,0.3020111);
   _reco_per_true->SetContourLevel(201,0.3035212);
   _reco_per_true->SetContourLevel(202,0.3050312);
   _reco_per_true->SetContourLevel(203,0.3065413);
   _reco_per_true->SetContourLevel(204,0.3080513);
   _reco_per_true->SetContourLevel(205,0.3095614);
   _reco_per_true->SetContourLevel(206,0.3110714);
   _reco_per_true->SetContourLevel(207,0.3125815);
   _reco_per_true->SetContourLevel(208,0.3140915);
   _reco_per_true->SetContourLevel(209,0.3156016);
   _reco_per_true->SetContourLevel(210,0.3171117);
   _reco_per_true->SetContourLevel(211,0.3186217);
   _reco_per_true->SetContourLevel(212,0.3201318);
   _reco_per_true->SetContourLevel(213,0.3216418);
   _reco_per_true->SetContourLevel(214,0.3231519);
   _reco_per_true->SetContourLevel(215,0.3246619);
   _reco_per_true->SetContourLevel(216,0.326172);
   _reco_per_true->SetContourLevel(217,0.327682);
   _reco_per_true->SetContourLevel(218,0.3291921);
   _reco_per_true->SetContourLevel(219,0.3307022);
   _reco_per_true->SetContourLevel(220,0.3322122);
   _reco_per_true->SetContourLevel(221,0.3337223);
   _reco_per_true->SetContourLevel(222,0.3352323);
   _reco_per_true->SetContourLevel(223,0.3367424);
   _reco_per_true->SetContourLevel(224,0.3382524);
   _reco_per_true->SetContourLevel(225,0.3397625);
   _reco_per_true->SetContourLevel(226,0.3412725);
   _reco_per_true->SetContourLevel(227,0.3427826);
   _reco_per_true->SetContourLevel(228,0.3442927);
   _reco_per_true->SetContourLevel(229,0.3458027);
   _reco_per_true->SetContourLevel(230,0.3473128);
   _reco_per_true->SetContourLevel(231,0.3488228);
   _reco_per_true->SetContourLevel(232,0.3503329);
   _reco_per_true->SetContourLevel(233,0.3518429);
   _reco_per_true->SetContourLevel(234,0.353353);
   _reco_per_true->SetContourLevel(235,0.354863);
   _reco_per_true->SetContourLevel(236,0.3563731);
   _reco_per_true->SetContourLevel(237,0.3578832);
   _reco_per_true->SetContourLevel(238,0.3593932);
   _reco_per_true->SetContourLevel(239,0.3609033);
   _reco_per_true->SetContourLevel(240,0.3624133);
   _reco_per_true->SetContourLevel(241,0.3639234);
   _reco_per_true->SetContourLevel(242,0.3654334);
   _reco_per_true->SetContourLevel(243,0.3669435);
   _reco_per_true->SetContourLevel(244,0.3684535);
   _reco_per_true->SetContourLevel(245,0.3699636);
   _reco_per_true->SetContourLevel(246,0.3714737);
   _reco_per_true->SetContourLevel(247,0.3729837);
   _reco_per_true->SetContourLevel(248,0.3744938);
   _reco_per_true->SetContourLevel(249,0.3760038);
   _reco_per_true->SetContourLevel(250,0.3775139);
   _reco_per_true->SetContourLevel(251,0.3790239);
   _reco_per_true->SetContourLevel(252,0.380534);
   _reco_per_true->SetContourLevel(253,0.382044);
   _reco_per_true->SetContourLevel(254,0.3835541);
   
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
   TText *AText = pt->AddText("True Bin 26");
   pt->Draw();
   c1_n27->Modified();
   c1_n27->cd();
   c1_n27->SetSelected(c1_n27);
}

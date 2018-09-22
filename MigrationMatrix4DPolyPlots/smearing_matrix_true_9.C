void smearing_matrix_true_9()
{
//=========Macro generated from canvas: c1_n10/c1_n10
//=========  (Sat Sep 22 12:03:54 2018) by ROOT version6.06/06
   TCanvas *c1_n10 = new TCanvas("c1_n10", "c1_n10",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n10->SetHighLightColor(2);
   c1_n10->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n10->SetFillColor(10);
   c1_n10->SetBorderMode(0);
   c1_n10->SetBorderSize(2);
   c1_n10->SetFrameLineWidth(2);
   c1_n10->SetFrameBorderMode(0);
   c1_n10->SetFrameLineWidth(2);
   c1_n10->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 9", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx280[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy280[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx280,Graph_fy280);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph280 = new TH1F("Graph_Graph280","Graph",100,-1.1,0);
   Graph_Graph280->SetMinimum(0);
   Graph_Graph280->SetMaximum(0.33);
   Graph_Graph280->SetDirectory(0);
   Graph_Graph280->SetStats(0);
   Graph_Graph280->SetLineWidth(2);
   Graph_Graph280->GetXaxis()->SetNdivisions(506);
   Graph_Graph280->GetXaxis()->SetLabelFont(42);
   Graph_Graph280->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph280->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph280->GetXaxis()->SetTitleFont(42);
   Graph_Graph280->GetYaxis()->SetNdivisions(506);
   Graph_Graph280->GetYaxis()->SetLabelFont(42);
   Graph_Graph280->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph280->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph280->GetYaxis()->SetTitleFont(42);
   Graph_Graph280->GetZaxis()->SetNdivisions(506);
   Graph_Graph280->GetZaxis()->SetLabelFont(42);
   Graph_Graph280->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph280->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph280->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph280);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx281[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy281[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx281,Graph_fy281);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#005dba");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph281 = new TH1F("Graph_Graph281","Graph",100,0,0.297);
   Graph_Graph281->SetMinimum(0);
   Graph_Graph281->SetMaximum(0.33);
   Graph_Graph281->SetDirectory(0);
   Graph_Graph281->SetStats(0);
   Graph_Graph281->SetLineWidth(2);
   Graph_Graph281->GetXaxis()->SetNdivisions(506);
   Graph_Graph281->GetXaxis()->SetLabelFont(42);
   Graph_Graph281->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph281->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph281->GetXaxis()->SetTitleFont(42);
   Graph_Graph281->GetYaxis()->SetNdivisions(506);
   Graph_Graph281->GetYaxis()->SetLabelFont(42);
   Graph_Graph281->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph281->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph281->GetYaxis()->SetTitleFont(42);
   Graph_Graph281->GetZaxis()->SetNdivisions(506);
   Graph_Graph281->GetZaxis()->SetLabelFont(42);
   Graph_Graph281->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph281->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph281->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph281);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx282[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy282[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx282,Graph_fy282);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph282 = new TH1F("Graph_Graph282","Graph",100,0.252,0.468);
   Graph_Graph282->SetMinimum(0);
   Graph_Graph282->SetMaximum(0.33);
   Graph_Graph282->SetDirectory(0);
   Graph_Graph282->SetStats(0);
   Graph_Graph282->SetLineWidth(2);
   Graph_Graph282->GetXaxis()->SetNdivisions(506);
   Graph_Graph282->GetXaxis()->SetLabelFont(42);
   Graph_Graph282->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph282->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph282->GetXaxis()->SetTitleFont(42);
   Graph_Graph282->GetYaxis()->SetNdivisions(506);
   Graph_Graph282->GetYaxis()->SetLabelFont(42);
   Graph_Graph282->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph282->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph282->GetYaxis()->SetTitleFont(42);
   Graph_Graph282->GetZaxis()->SetNdivisions(506);
   Graph_Graph282->GetZaxis()->SetLabelFont(42);
   Graph_Graph282->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph282->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph282->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph282);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx283[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy283[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx283,Graph_fy283);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph283 = new TH1F("Graph_Graph283","Graph",100,0.433,0.637);
   Graph_Graph283->SetMinimum(0);
   Graph_Graph283->SetMaximum(0.33);
   Graph_Graph283->SetDirectory(0);
   Graph_Graph283->SetStats(0);
   Graph_Graph283->SetLineWidth(2);
   Graph_Graph283->GetXaxis()->SetNdivisions(506);
   Graph_Graph283->GetXaxis()->SetLabelFont(42);
   Graph_Graph283->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph283->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph283->GetXaxis()->SetTitleFont(42);
   Graph_Graph283->GetYaxis()->SetNdivisions(506);
   Graph_Graph283->GetYaxis()->SetLabelFont(42);
   Graph_Graph283->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph283->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph283->GetYaxis()->SetTitleFont(42);
   Graph_Graph283->GetZaxis()->SetNdivisions(506);
   Graph_Graph283->GetZaxis()->SetLabelFont(42);
   Graph_Graph283->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph283->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph283->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph283);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx284[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy284[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx284,Graph_fy284);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph284 = new TH1F("Graph_Graph284","Graph",100,0.606,0.774);
   Graph_Graph284->SetMinimum(0);
   Graph_Graph284->SetMaximum(0.33);
   Graph_Graph284->SetDirectory(0);
   Graph_Graph284->SetStats(0);
   Graph_Graph284->SetLineWidth(2);
   Graph_Graph284->GetXaxis()->SetNdivisions(506);
   Graph_Graph284->GetXaxis()->SetLabelFont(42);
   Graph_Graph284->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph284->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph284->GetXaxis()->SetTitleFont(42);
   Graph_Graph284->GetYaxis()->SetNdivisions(506);
   Graph_Graph284->GetYaxis()->SetLabelFont(42);
   Graph_Graph284->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph284->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph284->GetYaxis()->SetTitleFont(42);
   Graph_Graph284->GetZaxis()->SetNdivisions(506);
   Graph_Graph284->GetZaxis()->SetLabelFont(42);
   Graph_Graph284->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph284->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph284->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph284);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx285[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy285[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx285,Graph_fy285);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph285 = new TH1F("Graph_Graph285","Graph",100,0.75,0.87);
   Graph_Graph285->SetMinimum(0);
   Graph_Graph285->SetMaximum(0.33);
   Graph_Graph285->SetDirectory(0);
   Graph_Graph285->SetStats(0);
   Graph_Graph285->SetLineWidth(2);
   Graph_Graph285->GetXaxis()->SetNdivisions(506);
   Graph_Graph285->GetXaxis()->SetLabelFont(42);
   Graph_Graph285->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph285->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph285->GetXaxis()->SetTitleFont(42);
   Graph_Graph285->GetYaxis()->SetNdivisions(506);
   Graph_Graph285->GetYaxis()->SetLabelFont(42);
   Graph_Graph285->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph285->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph285->GetYaxis()->SetTitleFont(42);
   Graph_Graph285->GetZaxis()->SetNdivisions(506);
   Graph_Graph285->GetZaxis()->SetLabelFont(42);
   Graph_Graph285->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph285->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph285->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph285);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx286[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy286[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx286,Graph_fy286);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph286 = new TH1F("Graph_Graph286","Graph",100,0.852,0.948);
   Graph_Graph286->SetMinimum(0);
   Graph_Graph286->SetMaximum(0.33);
   Graph_Graph286->SetDirectory(0);
   Graph_Graph286->SetStats(0);
   Graph_Graph286->SetLineWidth(2);
   Graph_Graph286->GetXaxis()->SetNdivisions(506);
   Graph_Graph286->GetXaxis()->SetLabelFont(42);
   Graph_Graph286->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph286->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph286->GetXaxis()->SetTitleFont(42);
   Graph_Graph286->GetYaxis()->SetNdivisions(506);
   Graph_Graph286->GetYaxis()->SetLabelFont(42);
   Graph_Graph286->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph286->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph286->GetYaxis()->SetTitleFont(42);
   Graph_Graph286->GetZaxis()->SetNdivisions(506);
   Graph_Graph286->GetZaxis()->SetLabelFont(42);
   Graph_Graph286->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph286->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph286->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph286);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx287[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy287[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx287,Graph_fy287);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph287 = new TH1F("Graph_Graph287","Graph",100,0.934,1.006);
   Graph_Graph287->SetMinimum(0);
   Graph_Graph287->SetMaximum(0.33);
   Graph_Graph287->SetDirectory(0);
   Graph_Graph287->SetStats(0);
   Graph_Graph287->SetLineWidth(2);
   Graph_Graph287->GetXaxis()->SetNdivisions(506);
   Graph_Graph287->GetXaxis()->SetLabelFont(42);
   Graph_Graph287->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph287->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph287->GetXaxis()->SetTitleFont(42);
   Graph_Graph287->GetYaxis()->SetNdivisions(506);
   Graph_Graph287->GetYaxis()->SetLabelFont(42);
   Graph_Graph287->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph287->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph287->GetYaxis()->SetTitleFont(42);
   Graph_Graph287->GetZaxis()->SetNdivisions(506);
   Graph_Graph287->GetZaxis()->SetLabelFont(42);
   Graph_Graph287->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph287->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph287->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph287);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx288[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy288[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx288,Graph_fy288);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0067c0");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph288 = new TH1F("Graph_Graph288","Graph",100,-1.1,0);
   Graph_Graph288->SetMinimum(0.285);
   Graph_Graph288->SetMaximum(0.465);
   Graph_Graph288->SetDirectory(0);
   Graph_Graph288->SetStats(0);
   Graph_Graph288->SetLineWidth(2);
   Graph_Graph288->GetXaxis()->SetNdivisions(506);
   Graph_Graph288->GetXaxis()->SetLabelFont(42);
   Graph_Graph288->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph288->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph288->GetXaxis()->SetTitleFont(42);
   Graph_Graph288->GetYaxis()->SetNdivisions(506);
   Graph_Graph288->GetYaxis()->SetLabelFont(42);
   Graph_Graph288->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph288->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph288->GetYaxis()->SetTitleFont(42);
   Graph_Graph288->GetZaxis()->SetNdivisions(506);
   Graph_Graph288->GetZaxis()->SetLabelFont(42);
   Graph_Graph288->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph288->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph288->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph288);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx289[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy289[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx289,Graph_fy289);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph289 = new TH1F("Graph_Graph289","Graph",100,0,0.297);
   Graph_Graph289->SetMinimum(0.285);
   Graph_Graph289->SetMaximum(0.465);
   Graph_Graph289->SetDirectory(0);
   Graph_Graph289->SetStats(0);
   Graph_Graph289->SetLineWidth(2);
   Graph_Graph289->GetXaxis()->SetNdivisions(506);
   Graph_Graph289->GetXaxis()->SetLabelFont(42);
   Graph_Graph289->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph289->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph289->GetXaxis()->SetTitleFont(42);
   Graph_Graph289->GetYaxis()->SetNdivisions(506);
   Graph_Graph289->GetYaxis()->SetLabelFont(42);
   Graph_Graph289->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph289->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph289->GetYaxis()->SetTitleFont(42);
   Graph_Graph289->GetZaxis()->SetNdivisions(506);
   Graph_Graph289->GetZaxis()->SetLabelFont(42);
   Graph_Graph289->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph289->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph289->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph289);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx290[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy290[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx290,Graph_fy290);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0078ca");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph290 = new TH1F("Graph_Graph290","Graph",100,0.252,0.468);
   Graph_Graph290->SetMinimum(0.285);
   Graph_Graph290->SetMaximum(0.465);
   Graph_Graph290->SetDirectory(0);
   Graph_Graph290->SetStats(0);
   Graph_Graph290->SetLineWidth(2);
   Graph_Graph290->GetXaxis()->SetNdivisions(506);
   Graph_Graph290->GetXaxis()->SetLabelFont(42);
   Graph_Graph290->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph290->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph290->GetXaxis()->SetTitleFont(42);
   Graph_Graph290->GetYaxis()->SetNdivisions(506);
   Graph_Graph290->GetYaxis()->SetLabelFont(42);
   Graph_Graph290->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph290->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph290->GetYaxis()->SetTitleFont(42);
   Graph_Graph290->GetZaxis()->SetNdivisions(506);
   Graph_Graph290->GetZaxis()->SetLabelFont(42);
   Graph_Graph290->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph290->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph290->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph290);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx291[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy291[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx291,Graph_fy291);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph291 = new TH1F("Graph_Graph291","Graph",100,0.433,0.637);
   Graph_Graph291->SetMinimum(0.285);
   Graph_Graph291->SetMaximum(0.465);
   Graph_Graph291->SetDirectory(0);
   Graph_Graph291->SetStats(0);
   Graph_Graph291->SetLineWidth(2);
   Graph_Graph291->GetXaxis()->SetNdivisions(506);
   Graph_Graph291->GetXaxis()->SetLabelFont(42);
   Graph_Graph291->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph291->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph291->GetXaxis()->SetTitleFont(42);
   Graph_Graph291->GetYaxis()->SetNdivisions(506);
   Graph_Graph291->GetYaxis()->SetLabelFont(42);
   Graph_Graph291->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph291->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph291->GetYaxis()->SetTitleFont(42);
   Graph_Graph291->GetZaxis()->SetNdivisions(506);
   Graph_Graph291->GetZaxis()->SetLabelFont(42);
   Graph_Graph291->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph291->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph291->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph291);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx292[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy292[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx292,Graph_fy292);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph292 = new TH1F("Graph_Graph292","Graph",100,0.606,0.774);
   Graph_Graph292->SetMinimum(0.285);
   Graph_Graph292->SetMaximum(0.465);
   Graph_Graph292->SetDirectory(0);
   Graph_Graph292->SetStats(0);
   Graph_Graph292->SetLineWidth(2);
   Graph_Graph292->GetXaxis()->SetNdivisions(506);
   Graph_Graph292->GetXaxis()->SetLabelFont(42);
   Graph_Graph292->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph292->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph292->GetXaxis()->SetTitleFont(42);
   Graph_Graph292->GetYaxis()->SetNdivisions(506);
   Graph_Graph292->GetYaxis()->SetLabelFont(42);
   Graph_Graph292->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph292->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph292->GetYaxis()->SetTitleFont(42);
   Graph_Graph292->GetZaxis()->SetNdivisions(506);
   Graph_Graph292->GetZaxis()->SetLabelFont(42);
   Graph_Graph292->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph292->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph292->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph292);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx293[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy293[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx293,Graph_fy293);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph293 = new TH1F("Graph_Graph293","Graph",100,0.75,0.87);
   Graph_Graph293->SetMinimum(0.285);
   Graph_Graph293->SetMaximum(0.465);
   Graph_Graph293->SetDirectory(0);
   Graph_Graph293->SetStats(0);
   Graph_Graph293->SetLineWidth(2);
   Graph_Graph293->GetXaxis()->SetNdivisions(506);
   Graph_Graph293->GetXaxis()->SetLabelFont(42);
   Graph_Graph293->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph293->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph293->GetXaxis()->SetTitleFont(42);
   Graph_Graph293->GetYaxis()->SetNdivisions(506);
   Graph_Graph293->GetYaxis()->SetLabelFont(42);
   Graph_Graph293->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph293->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph293->GetYaxis()->SetTitleFont(42);
   Graph_Graph293->GetZaxis()->SetNdivisions(506);
   Graph_Graph293->GetZaxis()->SetLabelFont(42);
   Graph_Graph293->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph293->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph293->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph293);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx294[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy294[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx294,Graph_fy294);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph294 = new TH1F("Graph_Graph294","Graph",100,0.852,0.948);
   Graph_Graph294->SetMinimum(0.285);
   Graph_Graph294->SetMaximum(0.465);
   Graph_Graph294->SetDirectory(0);
   Graph_Graph294->SetStats(0);
   Graph_Graph294->SetLineWidth(2);
   Graph_Graph294->GetXaxis()->SetNdivisions(506);
   Graph_Graph294->GetXaxis()->SetLabelFont(42);
   Graph_Graph294->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph294->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph294->GetXaxis()->SetTitleFont(42);
   Graph_Graph294->GetYaxis()->SetNdivisions(506);
   Graph_Graph294->GetYaxis()->SetLabelFont(42);
   Graph_Graph294->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph294->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph294->GetYaxis()->SetTitleFont(42);
   Graph_Graph294->GetZaxis()->SetNdivisions(506);
   Graph_Graph294->GetZaxis()->SetLabelFont(42);
   Graph_Graph294->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph294->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph294->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph294);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx295[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy295[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx295,Graph_fy295);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph295 = new TH1F("Graph_Graph295","Graph",100,0.934,1.006);
   Graph_Graph295->SetMinimum(0.285);
   Graph_Graph295->SetMaximum(0.465);
   Graph_Graph295->SetDirectory(0);
   Graph_Graph295->SetStats(0);
   Graph_Graph295->SetLineWidth(2);
   Graph_Graph295->GetXaxis()->SetNdivisions(506);
   Graph_Graph295->GetXaxis()->SetLabelFont(42);
   Graph_Graph295->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph295->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph295->GetXaxis()->SetTitleFont(42);
   Graph_Graph295->GetYaxis()->SetNdivisions(506);
   Graph_Graph295->GetYaxis()->SetLabelFont(42);
   Graph_Graph295->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph295->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph295->GetYaxis()->SetTitleFont(42);
   Graph_Graph295->GetZaxis()->SetNdivisions(506);
   Graph_Graph295->GetZaxis()->SetLabelFont(42);
   Graph_Graph295->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph295->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph295->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph295);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx296[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy296[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx296,Graph_fy296);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001890");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph296 = new TH1F("Graph_Graph296","Graph",100,-1.1,0);
   Graph_Graph296->SetMinimum(0.245);
   Graph_Graph296->SetMaximum(2.705);
   Graph_Graph296->SetDirectory(0);
   Graph_Graph296->SetStats(0);
   Graph_Graph296->SetLineWidth(2);
   Graph_Graph296->GetXaxis()->SetNdivisions(506);
   Graph_Graph296->GetXaxis()->SetLabelFont(42);
   Graph_Graph296->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph296->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph296->GetXaxis()->SetTitleFont(42);
   Graph_Graph296->GetYaxis()->SetNdivisions(506);
   Graph_Graph296->GetYaxis()->SetLabelFont(42);
   Graph_Graph296->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph296->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph296->GetYaxis()->SetTitleFont(42);
   Graph_Graph296->GetZaxis()->SetNdivisions(506);
   Graph_Graph296->GetZaxis()->SetLabelFont(42);
   Graph_Graph296->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph296->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph296->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph296);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx297[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy297[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx297,Graph_fy297);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#19d4e4");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph297 = new TH1F("Graph_Graph297","Graph",100,0,0.297);
   Graph_Graph297->SetMinimum(0.418);
   Graph_Graph297->SetMaximum(0.802);
   Graph_Graph297->SetDirectory(0);
   Graph_Graph297->SetStats(0);
   Graph_Graph297->SetLineWidth(2);
   Graph_Graph297->GetXaxis()->SetNdivisions(506);
   Graph_Graph297->GetXaxis()->SetLabelFont(42);
   Graph_Graph297->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph297->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph297->GetXaxis()->SetTitleFont(42);
   Graph_Graph297->GetYaxis()->SetNdivisions(506);
   Graph_Graph297->GetYaxis()->SetLabelFont(42);
   Graph_Graph297->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph297->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph297->GetYaxis()->SetTitleFont(42);
   Graph_Graph297->GetZaxis()->SetNdivisions(506);
   Graph_Graph297->GetZaxis()->SetLabelFont(42);
   Graph_Graph297->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph297->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph297->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph297);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx298[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy298[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx298,Graph_fy298);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00108c");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph298 = new TH1F("Graph_Graph298","Graph",100,0.252,0.468);
   Graph_Graph298->SetMinimum(0.418);
   Graph_Graph298->SetMaximum(0.802);
   Graph_Graph298->SetDirectory(0);
   Graph_Graph298->SetStats(0);
   Graph_Graph298->SetLineWidth(2);
   Graph_Graph298->GetXaxis()->SetNdivisions(506);
   Graph_Graph298->GetXaxis()->SetLabelFont(42);
   Graph_Graph298->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph298->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph298->GetXaxis()->SetTitleFont(42);
   Graph_Graph298->GetYaxis()->SetNdivisions(506);
   Graph_Graph298->GetYaxis()->SetLabelFont(42);
   Graph_Graph298->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph298->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph298->GetYaxis()->SetTitleFont(42);
   Graph_Graph298->GetZaxis()->SetNdivisions(506);
   Graph_Graph298->GetZaxis()->SetLabelFont(42);
   Graph_Graph298->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph298->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph298->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph298);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx299[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy299[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx299,Graph_fy299);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph299 = new TH1F("Graph_Graph299","Graph",100,0.433,0.637);
   Graph_Graph299->SetMinimum(0.418);
   Graph_Graph299->SetMaximum(0.802);
   Graph_Graph299->SetDirectory(0);
   Graph_Graph299->SetStats(0);
   Graph_Graph299->SetLineWidth(2);
   Graph_Graph299->GetXaxis()->SetNdivisions(506);
   Graph_Graph299->GetXaxis()->SetLabelFont(42);
   Graph_Graph299->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph299->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph299->GetXaxis()->SetTitleFont(42);
   Graph_Graph299->GetYaxis()->SetNdivisions(506);
   Graph_Graph299->GetYaxis()->SetLabelFont(42);
   Graph_Graph299->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph299->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph299->GetYaxis()->SetTitleFont(42);
   Graph_Graph299->GetZaxis()->SetNdivisions(506);
   Graph_Graph299->GetZaxis()->SetLabelFont(42);
   Graph_Graph299->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph299->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph299->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph299);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx300[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy300[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx300,Graph_fy300);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph300 = new TH1F("Graph_Graph300","Graph",100,0.606,0.774);
   Graph_Graph300->SetMinimum(0.418);
   Graph_Graph300->SetMaximum(0.802);
   Graph_Graph300->SetDirectory(0);
   Graph_Graph300->SetStats(0);
   Graph_Graph300->SetLineWidth(2);
   Graph_Graph300->GetXaxis()->SetNdivisions(506);
   Graph_Graph300->GetXaxis()->SetLabelFont(42);
   Graph_Graph300->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph300->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph300->GetXaxis()->SetTitleFont(42);
   Graph_Graph300->GetYaxis()->SetNdivisions(506);
   Graph_Graph300->GetYaxis()->SetLabelFont(42);
   Graph_Graph300->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph300->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph300->GetYaxis()->SetTitleFont(42);
   Graph_Graph300->GetZaxis()->SetNdivisions(506);
   Graph_Graph300->GetZaxis()->SetLabelFont(42);
   Graph_Graph300->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph300->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph300->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph300);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx301[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy301[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx301,Graph_fy301);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph301 = new TH1F("Graph_Graph301","Graph",100,0.75,0.87);
   Graph_Graph301->SetMinimum(0.418);
   Graph_Graph301->SetMaximum(0.802);
   Graph_Graph301->SetDirectory(0);
   Graph_Graph301->SetStats(0);
   Graph_Graph301->SetLineWidth(2);
   Graph_Graph301->GetXaxis()->SetNdivisions(506);
   Graph_Graph301->GetXaxis()->SetLabelFont(42);
   Graph_Graph301->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph301->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph301->GetXaxis()->SetTitleFont(42);
   Graph_Graph301->GetYaxis()->SetNdivisions(506);
   Graph_Graph301->GetYaxis()->SetLabelFont(42);
   Graph_Graph301->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph301->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph301->GetYaxis()->SetTitleFont(42);
   Graph_Graph301->GetZaxis()->SetNdivisions(506);
   Graph_Graph301->GetZaxis()->SetLabelFont(42);
   Graph_Graph301->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph301->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph301->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph301);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx302[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy302[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx302,Graph_fy302);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph302 = new TH1F("Graph_Graph302","Graph",100,0.852,0.948);
   Graph_Graph302->SetMinimum(0.418);
   Graph_Graph302->SetMaximum(0.802);
   Graph_Graph302->SetDirectory(0);
   Graph_Graph302->SetStats(0);
   Graph_Graph302->SetLineWidth(2);
   Graph_Graph302->GetXaxis()->SetNdivisions(506);
   Graph_Graph302->GetXaxis()->SetLabelFont(42);
   Graph_Graph302->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph302->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph302->GetXaxis()->SetTitleFont(42);
   Graph_Graph302->GetYaxis()->SetNdivisions(506);
   Graph_Graph302->GetYaxis()->SetLabelFont(42);
   Graph_Graph302->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph302->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph302->GetYaxis()->SetTitleFont(42);
   Graph_Graph302->GetZaxis()->SetNdivisions(506);
   Graph_Graph302->GetZaxis()->SetLabelFont(42);
   Graph_Graph302->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph302->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph302->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph302);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx303[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy303[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx303,Graph_fy303);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph303 = new TH1F("Graph_Graph303","Graph",100,0.934,1.006);
   Graph_Graph303->SetMinimum(0.418);
   Graph_Graph303->SetMaximum(0.802);
   Graph_Graph303->SetDirectory(0);
   Graph_Graph303->SetStats(0);
   Graph_Graph303->SetLineWidth(2);
   Graph_Graph303->GetXaxis()->SetNdivisions(506);
   Graph_Graph303->GetXaxis()->SetLabelFont(42);
   Graph_Graph303->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph303->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph303->GetXaxis()->SetTitleFont(42);
   Graph_Graph303->GetYaxis()->SetNdivisions(506);
   Graph_Graph303->GetYaxis()->SetLabelFont(42);
   Graph_Graph303->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph303->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph303->GetYaxis()->SetTitleFont(42);
   Graph_Graph303->GetZaxis()->SetNdivisions(506);
   Graph_Graph303->GetZaxis()->SetLabelFont(42);
   Graph_Graph303->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph303->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph303->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph303);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx304[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy304[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx304,Graph_fy304);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002d9d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph304 = new TH1F("Graph_Graph304","Graph",100,0,0.297);
   Graph_Graph304->SetMinimum(0.597);
   Graph_Graph304->SetMaximum(2.673);
   Graph_Graph304->SetDirectory(0);
   Graph_Graph304->SetStats(0);
   Graph_Graph304->SetLineWidth(2);
   Graph_Graph304->GetXaxis()->SetNdivisions(506);
   Graph_Graph304->GetXaxis()->SetLabelFont(42);
   Graph_Graph304->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph304->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph304->GetXaxis()->SetTitleFont(42);
   Graph_Graph304->GetYaxis()->SetNdivisions(506);
   Graph_Graph304->GetYaxis()->SetLabelFont(42);
   Graph_Graph304->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph304->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph304->GetYaxis()->SetTitleFont(42);
   Graph_Graph304->GetZaxis()->SetNdivisions(506);
   Graph_Graph304->GetZaxis()->SetLabelFont(42);
   Graph_Graph304->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph304->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph304->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph304);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx305[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy305[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx305,Graph_fy305);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph305 = new TH1F("Graph_Graph305","Graph",100,0.252,0.468);
   Graph_Graph305->SetMinimum(0.597);
   Graph_Graph305->SetMaximum(2.673);
   Graph_Graph305->SetDirectory(0);
   Graph_Graph305->SetStats(0);
   Graph_Graph305->SetLineWidth(2);
   Graph_Graph305->GetXaxis()->SetNdivisions(506);
   Graph_Graph305->GetXaxis()->SetLabelFont(42);
   Graph_Graph305->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph305->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph305->GetXaxis()->SetTitleFont(42);
   Graph_Graph305->GetYaxis()->SetNdivisions(506);
   Graph_Graph305->GetYaxis()->SetLabelFont(42);
   Graph_Graph305->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph305->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph305->GetYaxis()->SetTitleFont(42);
   Graph_Graph305->GetZaxis()->SetNdivisions(506);
   Graph_Graph305->GetZaxis()->SetLabelFont(42);
   Graph_Graph305->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph305->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph305->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph305);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx306[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy306[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx306,Graph_fy306);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph306 = new TH1F("Graph_Graph306","Graph",100,0.433,0.637);
   Graph_Graph306->SetMinimum(0.597);
   Graph_Graph306->SetMaximum(2.673);
   Graph_Graph306->SetDirectory(0);
   Graph_Graph306->SetStats(0);
   Graph_Graph306->SetLineWidth(2);
   Graph_Graph306->GetXaxis()->SetNdivisions(506);
   Graph_Graph306->GetXaxis()->SetLabelFont(42);
   Graph_Graph306->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph306->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph306->GetXaxis()->SetTitleFont(42);
   Graph_Graph306->GetYaxis()->SetNdivisions(506);
   Graph_Graph306->GetYaxis()->SetLabelFont(42);
   Graph_Graph306->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph306->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph306->GetYaxis()->SetTitleFont(42);
   Graph_Graph306->GetZaxis()->SetNdivisions(506);
   Graph_Graph306->GetZaxis()->SetLabelFont(42);
   Graph_Graph306->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph306->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph306->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph306);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx307[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy307[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx307,Graph_fy307);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph307 = new TH1F("Graph_Graph307","Graph",100,0.606,0.774);
   Graph_Graph307->SetMinimum(0.597);
   Graph_Graph307->SetMaximum(2.673);
   Graph_Graph307->SetDirectory(0);
   Graph_Graph307->SetStats(0);
   Graph_Graph307->SetLineWidth(2);
   Graph_Graph307->GetXaxis()->SetNdivisions(506);
   Graph_Graph307->GetXaxis()->SetLabelFont(42);
   Graph_Graph307->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph307->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph307->GetXaxis()->SetTitleFont(42);
   Graph_Graph307->GetYaxis()->SetNdivisions(506);
   Graph_Graph307->GetYaxis()->SetLabelFont(42);
   Graph_Graph307->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph307->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph307->GetYaxis()->SetTitleFont(42);
   Graph_Graph307->GetZaxis()->SetNdivisions(506);
   Graph_Graph307->GetZaxis()->SetLabelFont(42);
   Graph_Graph307->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph307->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph307->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph307);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx308[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy308[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx308,Graph_fy308);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph308 = new TH1F("Graph_Graph308","Graph",100,0.75,0.87);
   Graph_Graph308->SetMinimum(0.597);
   Graph_Graph308->SetMaximum(2.673);
   Graph_Graph308->SetDirectory(0);
   Graph_Graph308->SetStats(0);
   Graph_Graph308->SetLineWidth(2);
   Graph_Graph308->GetXaxis()->SetNdivisions(506);
   Graph_Graph308->GetXaxis()->SetLabelFont(42);
   Graph_Graph308->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph308->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph308->GetXaxis()->SetTitleFont(42);
   Graph_Graph308->GetYaxis()->SetNdivisions(506);
   Graph_Graph308->GetYaxis()->SetLabelFont(42);
   Graph_Graph308->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph308->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph308->GetYaxis()->SetTitleFont(42);
   Graph_Graph308->GetZaxis()->SetNdivisions(506);
   Graph_Graph308->GetZaxis()->SetLabelFont(42);
   Graph_Graph308->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph308->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph308->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph308);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx309[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy309[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx309,Graph_fy309);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph309 = new TH1F("Graph_Graph309","Graph",100,0.852,0.948);
   Graph_Graph309->SetMinimum(0.597);
   Graph_Graph309->SetMaximum(2.673);
   Graph_Graph309->SetDirectory(0);
   Graph_Graph309->SetStats(0);
   Graph_Graph309->SetLineWidth(2);
   Graph_Graph309->GetXaxis()->SetNdivisions(506);
   Graph_Graph309->GetXaxis()->SetLabelFont(42);
   Graph_Graph309->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph309->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph309->GetXaxis()->SetTitleFont(42);
   Graph_Graph309->GetYaxis()->SetNdivisions(506);
   Graph_Graph309->GetYaxis()->SetLabelFont(42);
   Graph_Graph309->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph309->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph309->GetYaxis()->SetTitleFont(42);
   Graph_Graph309->GetZaxis()->SetNdivisions(506);
   Graph_Graph309->GetZaxis()->SetLabelFont(42);
   Graph_Graph309->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph309->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph309->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph309);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx310[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy310[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx310,Graph_fy310);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph310 = new TH1F("Graph_Graph310","Graph",100,0.934,1.006);
   Graph_Graph310->SetMinimum(0.597);
   Graph_Graph310->SetMaximum(2.673);
   Graph_Graph310->SetDirectory(0);
   Graph_Graph310->SetStats(0);
   Graph_Graph310->SetLineWidth(2);
   Graph_Graph310->GetXaxis()->SetNdivisions(506);
   Graph_Graph310->GetXaxis()->SetLabelFont(42);
   Graph_Graph310->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph310->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph310->GetXaxis()->SetTitleFont(42);
   Graph_Graph310->GetYaxis()->SetNdivisions(506);
   Graph_Graph310->GetYaxis()->SetLabelFont(42);
   Graph_Graph310->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph310->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph310->GetYaxis()->SetTitleFont(42);
   Graph_Graph310->GetZaxis()->SetNdivisions(506);
   Graph_Graph310->GetZaxis()->SetLabelFont(42);
   Graph_Graph310->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph310->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph310->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph310);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.01621676);
   _reco_per_true->SetBinContent(2,0.07129197);
   _reco_per_true->SetBinContent(3,0.009735814);
   _reco_per_true->SetBinContent(4,0.003227581);
   _reco_per_true->SetBinContent(5,0.003247662);
   _reco_per_true->SetBinContent(6,0.003247056);
   _reco_per_true->SetBinContent(9,0.07756434);
   _reco_per_true->SetBinContent(10,0.4559206);
   _reco_per_true->SetBinContent(11,0.09066808);
   _reco_per_true->SetBinContent(12,0.009735452);
   _reco_per_true->SetBinContent(13,0.003247662);
   _reco_per_true->SetBinContent(14,0.003235954);
   _reco_per_true->SetBinContent(17,0.01945488);
   _reco_per_true->SetBinContent(18,0.1683756);
   _reco_per_true->SetBinContent(19,0.01298295);
   _reco_per_true->SetBinContent(20,0.00645623);
   _reco_per_true->SetBinContent(25,0.03565369);
   _reco_per_true->SetBinContent(26,0.003252413);
   _reco_per_true->SetBinContent(27,0.006485322);
   _reco_per_true->SetBinError(1,0.007252375);
   _reco_per_true->SetBinError(2,0.01519954);
   _reco_per_true->SetBinError(3,0.005620975);
   _reco_per_true->SetBinError(4,0.003227581);
   _reco_per_true->SetBinError(5,0.003247662);
   _reco_per_true->SetBinError(6,0.003247056);
   _reco_per_true->SetBinError(9,0.0158337);
   _reco_per_true->SetBinError(10,0.038398);
   _reco_per_true->SetBinError(11,0.01713473);
   _reco_per_true->SetBinError(12,0.005620777);
   _reco_per_true->SetBinError(13,0.003247662);
   _reco_per_true->SetBinError(14,0.003235954);
   _reco_per_true->SetBinError(17,0.007942441);
   _reco_per_true->SetBinError(18,0.02334965);
   _reco_per_true->SetBinError(19,0.006491483);
   _reco_per_true->SetBinError(20,0.004565373);
   _reco_per_true->SetBinError(25,0.01075002);
   _reco_per_true->SetBinError(26,0.003252413);
   _reco_per_true->SetBinError(27,0.004585816);
   _reco_per_true->SetEntries(309);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.001787924);
   _reco_per_true->SetContourLevel(2,0.003575848);
   _reco_per_true->SetContourLevel(3,0.005363772);
   _reco_per_true->SetContourLevel(4,0.007151696);
   _reco_per_true->SetContourLevel(5,0.00893962);
   _reco_per_true->SetContourLevel(6,0.01072754);
   _reco_per_true->SetContourLevel(7,0.01251547);
   _reco_per_true->SetContourLevel(8,0.01430339);
   _reco_per_true->SetContourLevel(9,0.01609132);
   _reco_per_true->SetContourLevel(10,0.01787924);
   _reco_per_true->SetContourLevel(11,0.01966716);
   _reco_per_true->SetContourLevel(12,0.02145509);
   _reco_per_true->SetContourLevel(13,0.02324301);
   _reco_per_true->SetContourLevel(14,0.02503094);
   _reco_per_true->SetContourLevel(15,0.02681886);
   _reco_per_true->SetContourLevel(16,0.02860678);
   _reco_per_true->SetContourLevel(17,0.03039471);
   _reco_per_true->SetContourLevel(18,0.03218263);
   _reco_per_true->SetContourLevel(19,0.03397055);
   _reco_per_true->SetContourLevel(20,0.03575848);
   _reco_per_true->SetContourLevel(21,0.0375464);
   _reco_per_true->SetContourLevel(22,0.03933433);
   _reco_per_true->SetContourLevel(23,0.04112225);
   _reco_per_true->SetContourLevel(24,0.04291017);
   _reco_per_true->SetContourLevel(25,0.0446981);
   _reco_per_true->SetContourLevel(26,0.04648602);
   _reco_per_true->SetContourLevel(27,0.04827395);
   _reco_per_true->SetContourLevel(28,0.05006187);
   _reco_per_true->SetContourLevel(29,0.05184979);
   _reco_per_true->SetContourLevel(30,0.05363772);
   _reco_per_true->SetContourLevel(31,0.05542564);
   _reco_per_true->SetContourLevel(32,0.05721357);
   _reco_per_true->SetContourLevel(33,0.05900149);
   _reco_per_true->SetContourLevel(34,0.06078941);
   _reco_per_true->SetContourLevel(35,0.06257734);
   _reco_per_true->SetContourLevel(36,0.06436526);
   _reco_per_true->SetContourLevel(37,0.06615319);
   _reco_per_true->SetContourLevel(38,0.06794111);
   _reco_per_true->SetContourLevel(39,0.06972903);
   _reco_per_true->SetContourLevel(40,0.07151696);
   _reco_per_true->SetContourLevel(41,0.07330488);
   _reco_per_true->SetContourLevel(42,0.07509281);
   _reco_per_true->SetContourLevel(43,0.07688073);
   _reco_per_true->SetContourLevel(44,0.07866865);
   _reco_per_true->SetContourLevel(45,0.08045658);
   _reco_per_true->SetContourLevel(46,0.0822445);
   _reco_per_true->SetContourLevel(47,0.08403242);
   _reco_per_true->SetContourLevel(48,0.08582035);
   _reco_per_true->SetContourLevel(49,0.08760827);
   _reco_per_true->SetContourLevel(50,0.0893962);
   _reco_per_true->SetContourLevel(51,0.09118412);
   _reco_per_true->SetContourLevel(52,0.09297204);
   _reco_per_true->SetContourLevel(53,0.09475997);
   _reco_per_true->SetContourLevel(54,0.09654789);
   _reco_per_true->SetContourLevel(55,0.09833582);
   _reco_per_true->SetContourLevel(56,0.1001237);
   _reco_per_true->SetContourLevel(57,0.1019117);
   _reco_per_true->SetContourLevel(58,0.1036996);
   _reco_per_true->SetContourLevel(59,0.1054875);
   _reco_per_true->SetContourLevel(60,0.1072754);
   _reco_per_true->SetContourLevel(61,0.1090634);
   _reco_per_true->SetContourLevel(62,0.1108513);
   _reco_per_true->SetContourLevel(63,0.1126392);
   _reco_per_true->SetContourLevel(64,0.1144271);
   _reco_per_true->SetContourLevel(65,0.1162151);
   _reco_per_true->SetContourLevel(66,0.118003);
   _reco_per_true->SetContourLevel(67,0.1197909);
   _reco_per_true->SetContourLevel(68,0.1215788);
   _reco_per_true->SetContourLevel(69,0.1233668);
   _reco_per_true->SetContourLevel(70,0.1251547);
   _reco_per_true->SetContourLevel(71,0.1269426);
   _reco_per_true->SetContourLevel(72,0.1287305);
   _reco_per_true->SetContourLevel(73,0.1305184);
   _reco_per_true->SetContourLevel(74,0.1323064);
   _reco_per_true->SetContourLevel(75,0.1340943);
   _reco_per_true->SetContourLevel(76,0.1358822);
   _reco_per_true->SetContourLevel(77,0.1376701);
   _reco_per_true->SetContourLevel(78,0.1394581);
   _reco_per_true->SetContourLevel(79,0.141246);
   _reco_per_true->SetContourLevel(80,0.1430339);
   _reco_per_true->SetContourLevel(81,0.1448218);
   _reco_per_true->SetContourLevel(82,0.1466098);
   _reco_per_true->SetContourLevel(83,0.1483977);
   _reco_per_true->SetContourLevel(84,0.1501856);
   _reco_per_true->SetContourLevel(85,0.1519735);
   _reco_per_true->SetContourLevel(86,0.1537615);
   _reco_per_true->SetContourLevel(87,0.1555494);
   _reco_per_true->SetContourLevel(88,0.1573373);
   _reco_per_true->SetContourLevel(89,0.1591252);
   _reco_per_true->SetContourLevel(90,0.1609132);
   _reco_per_true->SetContourLevel(91,0.1627011);
   _reco_per_true->SetContourLevel(92,0.164489);
   _reco_per_true->SetContourLevel(93,0.1662769);
   _reco_per_true->SetContourLevel(94,0.1680648);
   _reco_per_true->SetContourLevel(95,0.1698528);
   _reco_per_true->SetContourLevel(96,0.1716407);
   _reco_per_true->SetContourLevel(97,0.1734286);
   _reco_per_true->SetContourLevel(98,0.1752165);
   _reco_per_true->SetContourLevel(99,0.1770045);
   _reco_per_true->SetContourLevel(100,0.1787924);
   _reco_per_true->SetContourLevel(101,0.1805803);
   _reco_per_true->SetContourLevel(102,0.1823682);
   _reco_per_true->SetContourLevel(103,0.1841562);
   _reco_per_true->SetContourLevel(104,0.1859441);
   _reco_per_true->SetContourLevel(105,0.187732);
   _reco_per_true->SetContourLevel(106,0.1895199);
   _reco_per_true->SetContourLevel(107,0.1913079);
   _reco_per_true->SetContourLevel(108,0.1930958);
   _reco_per_true->SetContourLevel(109,0.1948837);
   _reco_per_true->SetContourLevel(110,0.1966716);
   _reco_per_true->SetContourLevel(111,0.1984596);
   _reco_per_true->SetContourLevel(112,0.2002475);
   _reco_per_true->SetContourLevel(113,0.2020354);
   _reco_per_true->SetContourLevel(114,0.2038233);
   _reco_per_true->SetContourLevel(115,0.2056113);
   _reco_per_true->SetContourLevel(116,0.2073992);
   _reco_per_true->SetContourLevel(117,0.2091871);
   _reco_per_true->SetContourLevel(118,0.210975);
   _reco_per_true->SetContourLevel(119,0.2127629);
   _reco_per_true->SetContourLevel(120,0.2145509);
   _reco_per_true->SetContourLevel(121,0.2163388);
   _reco_per_true->SetContourLevel(122,0.2181267);
   _reco_per_true->SetContourLevel(123,0.2199146);
   _reco_per_true->SetContourLevel(124,0.2217026);
   _reco_per_true->SetContourLevel(125,0.2234905);
   _reco_per_true->SetContourLevel(126,0.2252784);
   _reco_per_true->SetContourLevel(127,0.2270663);
   _reco_per_true->SetContourLevel(128,0.2288543);
   _reco_per_true->SetContourLevel(129,0.2306422);
   _reco_per_true->SetContourLevel(130,0.2324301);
   _reco_per_true->SetContourLevel(131,0.234218);
   _reco_per_true->SetContourLevel(132,0.236006);
   _reco_per_true->SetContourLevel(133,0.2377939);
   _reco_per_true->SetContourLevel(134,0.2395818);
   _reco_per_true->SetContourLevel(135,0.2413697);
   _reco_per_true->SetContourLevel(136,0.2431577);
   _reco_per_true->SetContourLevel(137,0.2449456);
   _reco_per_true->SetContourLevel(138,0.2467335);
   _reco_per_true->SetContourLevel(139,0.2485214);
   _reco_per_true->SetContourLevel(140,0.2503094);
   _reco_per_true->SetContourLevel(141,0.2520973);
   _reco_per_true->SetContourLevel(142,0.2538852);
   _reco_per_true->SetContourLevel(143,0.2556731);
   _reco_per_true->SetContourLevel(144,0.257461);
   _reco_per_true->SetContourLevel(145,0.259249);
   _reco_per_true->SetContourLevel(146,0.2610369);
   _reco_per_true->SetContourLevel(147,0.2628248);
   _reco_per_true->SetContourLevel(148,0.2646127);
   _reco_per_true->SetContourLevel(149,0.2664007);
   _reco_per_true->SetContourLevel(150,0.2681886);
   _reco_per_true->SetContourLevel(151,0.2699765);
   _reco_per_true->SetContourLevel(152,0.2717644);
   _reco_per_true->SetContourLevel(153,0.2735524);
   _reco_per_true->SetContourLevel(154,0.2753403);
   _reco_per_true->SetContourLevel(155,0.2771282);
   _reco_per_true->SetContourLevel(156,0.2789161);
   _reco_per_true->SetContourLevel(157,0.2807041);
   _reco_per_true->SetContourLevel(158,0.282492);
   _reco_per_true->SetContourLevel(159,0.2842799);
   _reco_per_true->SetContourLevel(160,0.2860678);
   _reco_per_true->SetContourLevel(161,0.2878558);
   _reco_per_true->SetContourLevel(162,0.2896437);
   _reco_per_true->SetContourLevel(163,0.2914316);
   _reco_per_true->SetContourLevel(164,0.2932195);
   _reco_per_true->SetContourLevel(165,0.2950074);
   _reco_per_true->SetContourLevel(166,0.2967954);
   _reco_per_true->SetContourLevel(167,0.2985833);
   _reco_per_true->SetContourLevel(168,0.3003712);
   _reco_per_true->SetContourLevel(169,0.3021591);
   _reco_per_true->SetContourLevel(170,0.3039471);
   _reco_per_true->SetContourLevel(171,0.305735);
   _reco_per_true->SetContourLevel(172,0.3075229);
   _reco_per_true->SetContourLevel(173,0.3093108);
   _reco_per_true->SetContourLevel(174,0.3110988);
   _reco_per_true->SetContourLevel(175,0.3128867);
   _reco_per_true->SetContourLevel(176,0.3146746);
   _reco_per_true->SetContourLevel(177,0.3164625);
   _reco_per_true->SetContourLevel(178,0.3182505);
   _reco_per_true->SetContourLevel(179,0.3200384);
   _reco_per_true->SetContourLevel(180,0.3218263);
   _reco_per_true->SetContourLevel(181,0.3236142);
   _reco_per_true->SetContourLevel(182,0.3254022);
   _reco_per_true->SetContourLevel(183,0.3271901);
   _reco_per_true->SetContourLevel(184,0.328978);
   _reco_per_true->SetContourLevel(185,0.3307659);
   _reco_per_true->SetContourLevel(186,0.3325539);
   _reco_per_true->SetContourLevel(187,0.3343418);
   _reco_per_true->SetContourLevel(188,0.3361297);
   _reco_per_true->SetContourLevel(189,0.3379176);
   _reco_per_true->SetContourLevel(190,0.3397055);
   _reco_per_true->SetContourLevel(191,0.3414935);
   _reco_per_true->SetContourLevel(192,0.3432814);
   _reco_per_true->SetContourLevel(193,0.3450693);
   _reco_per_true->SetContourLevel(194,0.3468572);
   _reco_per_true->SetContourLevel(195,0.3486452);
   _reco_per_true->SetContourLevel(196,0.3504331);
   _reco_per_true->SetContourLevel(197,0.352221);
   _reco_per_true->SetContourLevel(198,0.3540089);
   _reco_per_true->SetContourLevel(199,0.3557969);
   _reco_per_true->SetContourLevel(200,0.3575848);
   _reco_per_true->SetContourLevel(201,0.3593727);
   _reco_per_true->SetContourLevel(202,0.3611606);
   _reco_per_true->SetContourLevel(203,0.3629486);
   _reco_per_true->SetContourLevel(204,0.3647365);
   _reco_per_true->SetContourLevel(205,0.3665244);
   _reco_per_true->SetContourLevel(206,0.3683123);
   _reco_per_true->SetContourLevel(207,0.3701003);
   _reco_per_true->SetContourLevel(208,0.3718882);
   _reco_per_true->SetContourLevel(209,0.3736761);
   _reco_per_true->SetContourLevel(210,0.375464);
   _reco_per_true->SetContourLevel(211,0.3772519);
   _reco_per_true->SetContourLevel(212,0.3790399);
   _reco_per_true->SetContourLevel(213,0.3808278);
   _reco_per_true->SetContourLevel(214,0.3826157);
   _reco_per_true->SetContourLevel(215,0.3844036);
   _reco_per_true->SetContourLevel(216,0.3861916);
   _reco_per_true->SetContourLevel(217,0.3879795);
   _reco_per_true->SetContourLevel(218,0.3897674);
   _reco_per_true->SetContourLevel(219,0.3915553);
   _reco_per_true->SetContourLevel(220,0.3933433);
   _reco_per_true->SetContourLevel(221,0.3951312);
   _reco_per_true->SetContourLevel(222,0.3969191);
   _reco_per_true->SetContourLevel(223,0.398707);
   _reco_per_true->SetContourLevel(224,0.400495);
   _reco_per_true->SetContourLevel(225,0.4022829);
   _reco_per_true->SetContourLevel(226,0.4040708);
   _reco_per_true->SetContourLevel(227,0.4058587);
   _reco_per_true->SetContourLevel(228,0.4076467);
   _reco_per_true->SetContourLevel(229,0.4094346);
   _reco_per_true->SetContourLevel(230,0.4112225);
   _reco_per_true->SetContourLevel(231,0.4130104);
   _reco_per_true->SetContourLevel(232,0.4147984);
   _reco_per_true->SetContourLevel(233,0.4165863);
   _reco_per_true->SetContourLevel(234,0.4183742);
   _reco_per_true->SetContourLevel(235,0.4201621);
   _reco_per_true->SetContourLevel(236,0.42195);
   _reco_per_true->SetContourLevel(237,0.423738);
   _reco_per_true->SetContourLevel(238,0.4255259);
   _reco_per_true->SetContourLevel(239,0.4273138);
   _reco_per_true->SetContourLevel(240,0.4291017);
   _reco_per_true->SetContourLevel(241,0.4308897);
   _reco_per_true->SetContourLevel(242,0.4326776);
   _reco_per_true->SetContourLevel(243,0.4344655);
   _reco_per_true->SetContourLevel(244,0.4362534);
   _reco_per_true->SetContourLevel(245,0.4380414);
   _reco_per_true->SetContourLevel(246,0.4398293);
   _reco_per_true->SetContourLevel(247,0.4416172);
   _reco_per_true->SetContourLevel(248,0.4434051);
   _reco_per_true->SetContourLevel(249,0.4451931);
   _reco_per_true->SetContourLevel(250,0.446981);
   _reco_per_true->SetContourLevel(251,0.4487689);
   _reco_per_true->SetContourLevel(252,0.4505568);
   _reco_per_true->SetContourLevel(253,0.4523448);
   _reco_per_true->SetContourLevel(254,0.4541327);
   
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
   
   TPaveText *pt = new TPaveText(0.4054728,0.91975,0.5945272,0.98025,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetTextFont(42);
   TText *AText = pt->AddText("True Bin 9");
   pt->Draw();
   c1_n10->Modified();
   c1_n10->cd();
   c1_n10->SetSelected(c1_n10);
}

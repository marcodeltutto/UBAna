void smearing_matrix_true_10()
{
//=========Macro generated from canvas: c1_n11/c1_n11
//=========  (Sat Sep 22 12:03:55 2018) by ROOT version6.06/06
   TCanvas *c1_n11 = new TCanvas("c1_n11", "c1_n11",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n11->SetHighLightColor(2);
   c1_n11->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n11->SetFillColor(10);
   c1_n11->SetBorderMode(0);
   c1_n11->SetBorderSize(2);
   c1_n11->SetFrameLineWidth(2);
   c1_n11->SetFrameBorderMode(0);
   c1_n11->SetFrameLineWidth(2);
   c1_n11->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 10", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx311[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy311[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx311,Graph_fy311);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00138d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph311 = new TH1F("Graph_Graph311","Graph",100,-1.1,0);
   Graph_Graph311->SetMinimum(0);
   Graph_Graph311->SetMaximum(0.33);
   Graph_Graph311->SetDirectory(0);
   Graph_Graph311->SetStats(0);
   Graph_Graph311->SetLineWidth(2);
   Graph_Graph311->GetXaxis()->SetNdivisions(506);
   Graph_Graph311->GetXaxis()->SetLabelFont(42);
   Graph_Graph311->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph311->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph311->GetXaxis()->SetTitleFont(42);
   Graph_Graph311->GetYaxis()->SetNdivisions(506);
   Graph_Graph311->GetYaxis()->SetLabelFont(42);
   Graph_Graph311->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph311->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph311->GetYaxis()->SetTitleFont(42);
   Graph_Graph311->GetZaxis()->SetNdivisions(506);
   Graph_Graph311->GetZaxis()->SetLabelFont(42);
   Graph_Graph311->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph311->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph311->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph311);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx312[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy312[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx312,Graph_fy312);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002d9d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph312 = new TH1F("Graph_Graph312","Graph",100,0,0.297);
   Graph_Graph312->SetMinimum(0);
   Graph_Graph312->SetMaximum(0.33);
   Graph_Graph312->SetDirectory(0);
   Graph_Graph312->SetStats(0);
   Graph_Graph312->SetLineWidth(2);
   Graph_Graph312->GetXaxis()->SetNdivisions(506);
   Graph_Graph312->GetXaxis()->SetLabelFont(42);
   Graph_Graph312->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph312->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph312->GetXaxis()->SetTitleFont(42);
   Graph_Graph312->GetYaxis()->SetNdivisions(506);
   Graph_Graph312->GetYaxis()->SetLabelFont(42);
   Graph_Graph312->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph312->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph312->GetYaxis()->SetTitleFont(42);
   Graph_Graph312->GetZaxis()->SetNdivisions(506);
   Graph_Graph312->GetZaxis()->SetLabelFont(42);
   Graph_Graph312->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph312->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph312->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph312);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx313[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy313[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx313,Graph_fy313);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0073c7");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph313 = new TH1F("Graph_Graph313","Graph",100,0.252,0.468);
   Graph_Graph313->SetMinimum(0);
   Graph_Graph313->SetMaximum(0.33);
   Graph_Graph313->SetDirectory(0);
   Graph_Graph313->SetStats(0);
   Graph_Graph313->SetLineWidth(2);
   Graph_Graph313->GetXaxis()->SetNdivisions(506);
   Graph_Graph313->GetXaxis()->SetLabelFont(42);
   Graph_Graph313->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph313->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph313->GetXaxis()->SetTitleFont(42);
   Graph_Graph313->GetYaxis()->SetNdivisions(506);
   Graph_Graph313->GetYaxis()->SetLabelFont(42);
   Graph_Graph313->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph313->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph313->GetYaxis()->SetTitleFont(42);
   Graph_Graph313->GetZaxis()->SetNdivisions(506);
   Graph_Graph313->GetZaxis()->SetLabelFont(42);
   Graph_Graph313->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph313->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph313->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph313);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx314[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy314[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx314,Graph_fy314);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#003ea7");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph314 = new TH1F("Graph_Graph314","Graph",100,0.433,0.637);
   Graph_Graph314->SetMinimum(0);
   Graph_Graph314->SetMaximum(0.33);
   Graph_Graph314->SetDirectory(0);
   Graph_Graph314->SetStats(0);
   Graph_Graph314->SetLineWidth(2);
   Graph_Graph314->GetXaxis()->SetNdivisions(506);
   Graph_Graph314->GetXaxis()->SetLabelFont(42);
   Graph_Graph314->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph314->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph314->GetXaxis()->SetTitleFont(42);
   Graph_Graph314->GetYaxis()->SetNdivisions(506);
   Graph_Graph314->GetYaxis()->SetLabelFont(42);
   Graph_Graph314->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph314->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph314->GetYaxis()->SetTitleFont(42);
   Graph_Graph314->GetZaxis()->SetNdivisions(506);
   Graph_Graph314->GetZaxis()->SetLabelFont(42);
   Graph_Graph314->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph314->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph314->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph314);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx315[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy315[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx315,Graph_fy315);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph315 = new TH1F("Graph_Graph315","Graph",100,0.606,0.774);
   Graph_Graph315->SetMinimum(0);
   Graph_Graph315->SetMaximum(0.33);
   Graph_Graph315->SetDirectory(0);
   Graph_Graph315->SetStats(0);
   Graph_Graph315->SetLineWidth(2);
   Graph_Graph315->GetXaxis()->SetNdivisions(506);
   Graph_Graph315->GetXaxis()->SetLabelFont(42);
   Graph_Graph315->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph315->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph315->GetXaxis()->SetTitleFont(42);
   Graph_Graph315->GetYaxis()->SetNdivisions(506);
   Graph_Graph315->GetYaxis()->SetLabelFont(42);
   Graph_Graph315->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph315->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph315->GetYaxis()->SetTitleFont(42);
   Graph_Graph315->GetZaxis()->SetNdivisions(506);
   Graph_Graph315->GetZaxis()->SetLabelFont(42);
   Graph_Graph315->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph315->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph315->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph315);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx316[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy316[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx316,Graph_fy316);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph316 = new TH1F("Graph_Graph316","Graph",100,0.75,0.87);
   Graph_Graph316->SetMinimum(0);
   Graph_Graph316->SetMaximum(0.33);
   Graph_Graph316->SetDirectory(0);
   Graph_Graph316->SetStats(0);
   Graph_Graph316->SetLineWidth(2);
   Graph_Graph316->GetXaxis()->SetNdivisions(506);
   Graph_Graph316->GetXaxis()->SetLabelFont(42);
   Graph_Graph316->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph316->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph316->GetXaxis()->SetTitleFont(42);
   Graph_Graph316->GetYaxis()->SetNdivisions(506);
   Graph_Graph316->GetYaxis()->SetLabelFont(42);
   Graph_Graph316->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph316->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph316->GetYaxis()->SetTitleFont(42);
   Graph_Graph316->GetZaxis()->SetNdivisions(506);
   Graph_Graph316->GetZaxis()->SetLabelFont(42);
   Graph_Graph316->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph316->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph316->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph316);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx317[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy317[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx317,Graph_fy317);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph317 = new TH1F("Graph_Graph317","Graph",100,0.852,0.948);
   Graph_Graph317->SetMinimum(0);
   Graph_Graph317->SetMaximum(0.33);
   Graph_Graph317->SetDirectory(0);
   Graph_Graph317->SetStats(0);
   Graph_Graph317->SetLineWidth(2);
   Graph_Graph317->GetXaxis()->SetNdivisions(506);
   Graph_Graph317->GetXaxis()->SetLabelFont(42);
   Graph_Graph317->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph317->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph317->GetXaxis()->SetTitleFont(42);
   Graph_Graph317->GetYaxis()->SetNdivisions(506);
   Graph_Graph317->GetYaxis()->SetLabelFont(42);
   Graph_Graph317->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph317->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph317->GetYaxis()->SetTitleFont(42);
   Graph_Graph317->GetZaxis()->SetNdivisions(506);
   Graph_Graph317->GetZaxis()->SetLabelFont(42);
   Graph_Graph317->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph317->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph317->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph317);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx318[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy318[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx318,Graph_fy318);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph318 = new TH1F("Graph_Graph318","Graph",100,0.934,1.006);
   Graph_Graph318->SetMinimum(0);
   Graph_Graph318->SetMaximum(0.33);
   Graph_Graph318->SetDirectory(0);
   Graph_Graph318->SetStats(0);
   Graph_Graph318->SetLineWidth(2);
   Graph_Graph318->GetXaxis()->SetNdivisions(506);
   Graph_Graph318->GetXaxis()->SetLabelFont(42);
   Graph_Graph318->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph318->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph318->GetXaxis()->SetTitleFont(42);
   Graph_Graph318->GetYaxis()->SetNdivisions(506);
   Graph_Graph318->GetYaxis()->SetLabelFont(42);
   Graph_Graph318->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph318->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph318->GetYaxis()->SetTitleFont(42);
   Graph_Graph318->GetZaxis()->SetNdivisions(506);
   Graph_Graph318->GetZaxis()->SetLabelFont(42);
   Graph_Graph318->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph318->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph318->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph318);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx319[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy319[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx319,Graph_fy319);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph319 = new TH1F("Graph_Graph319","Graph",100,-1.1,0);
   Graph_Graph319->SetMinimum(0.285);
   Graph_Graph319->SetMaximum(0.465);
   Graph_Graph319->SetDirectory(0);
   Graph_Graph319->SetStats(0);
   Graph_Graph319->SetLineWidth(2);
   Graph_Graph319->GetXaxis()->SetNdivisions(506);
   Graph_Graph319->GetXaxis()->SetLabelFont(42);
   Graph_Graph319->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph319->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph319->GetXaxis()->SetTitleFont(42);
   Graph_Graph319->GetYaxis()->SetNdivisions(506);
   Graph_Graph319->GetYaxis()->SetLabelFont(42);
   Graph_Graph319->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph319->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph319->GetYaxis()->SetTitleFont(42);
   Graph_Graph319->GetZaxis()->SetNdivisions(506);
   Graph_Graph319->GetZaxis()->SetLabelFont(42);
   Graph_Graph319->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph319->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph319->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph319);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx320[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy320[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx320,Graph_fy320);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0099df");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph320 = new TH1F("Graph_Graph320","Graph",100,0,0.297);
   Graph_Graph320->SetMinimum(0.285);
   Graph_Graph320->SetMaximum(0.465);
   Graph_Graph320->SetDirectory(0);
   Graph_Graph320->SetStats(0);
   Graph_Graph320->SetLineWidth(2);
   Graph_Graph320->GetXaxis()->SetNdivisions(506);
   Graph_Graph320->GetXaxis()->SetLabelFont(42);
   Graph_Graph320->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph320->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph320->GetXaxis()->SetTitleFont(42);
   Graph_Graph320->GetYaxis()->SetNdivisions(506);
   Graph_Graph320->GetYaxis()->SetLabelFont(42);
   Graph_Graph320->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph320->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph320->GetYaxis()->SetTitleFont(42);
   Graph_Graph320->GetZaxis()->SetNdivisions(506);
   Graph_Graph320->GetZaxis()->SetLabelFont(42);
   Graph_Graph320->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph320->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph320->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph320);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx321[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy321[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx321,Graph_fy321);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph321 = new TH1F("Graph_Graph321","Graph",100,0.252,0.468);
   Graph_Graph321->SetMinimum(0.285);
   Graph_Graph321->SetMaximum(0.465);
   Graph_Graph321->SetDirectory(0);
   Graph_Graph321->SetStats(0);
   Graph_Graph321->SetLineWidth(2);
   Graph_Graph321->GetXaxis()->SetNdivisions(506);
   Graph_Graph321->GetXaxis()->SetLabelFont(42);
   Graph_Graph321->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph321->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph321->GetXaxis()->SetTitleFont(42);
   Graph_Graph321->GetYaxis()->SetNdivisions(506);
   Graph_Graph321->GetYaxis()->SetLabelFont(42);
   Graph_Graph321->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph321->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph321->GetYaxis()->SetTitleFont(42);
   Graph_Graph321->GetZaxis()->SetNdivisions(506);
   Graph_Graph321->GetZaxis()->SetLabelFont(42);
   Graph_Graph321->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph321->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph321->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph321);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx322[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy322[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx322,Graph_fy322);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#06cff8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph322 = new TH1F("Graph_Graph322","Graph",100,0.433,0.637);
   Graph_Graph322->SetMinimum(0.285);
   Graph_Graph322->SetMaximum(0.465);
   Graph_Graph322->SetDirectory(0);
   Graph_Graph322->SetStats(0);
   Graph_Graph322->SetLineWidth(2);
   Graph_Graph322->GetXaxis()->SetNdivisions(506);
   Graph_Graph322->GetXaxis()->SetLabelFont(42);
   Graph_Graph322->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph322->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph322->GetXaxis()->SetTitleFont(42);
   Graph_Graph322->GetYaxis()->SetNdivisions(506);
   Graph_Graph322->GetYaxis()->SetLabelFont(42);
   Graph_Graph322->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph322->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph322->GetYaxis()->SetTitleFont(42);
   Graph_Graph322->GetZaxis()->SetNdivisions(506);
   Graph_Graph322->GetZaxis()->SetLabelFont(42);
   Graph_Graph322->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph322->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph322->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph322);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx323[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy323[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx323,Graph_fy323);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph323 = new TH1F("Graph_Graph323","Graph",100,0.606,0.774);
   Graph_Graph323->SetMinimum(0.285);
   Graph_Graph323->SetMaximum(0.465);
   Graph_Graph323->SetDirectory(0);
   Graph_Graph323->SetStats(0);
   Graph_Graph323->SetLineWidth(2);
   Graph_Graph323->GetXaxis()->SetNdivisions(506);
   Graph_Graph323->GetXaxis()->SetLabelFont(42);
   Graph_Graph323->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph323->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph323->GetXaxis()->SetTitleFont(42);
   Graph_Graph323->GetYaxis()->SetNdivisions(506);
   Graph_Graph323->GetYaxis()->SetLabelFont(42);
   Graph_Graph323->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph323->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph323->GetYaxis()->SetTitleFont(42);
   Graph_Graph323->GetZaxis()->SetNdivisions(506);
   Graph_Graph323->GetZaxis()->SetLabelFont(42);
   Graph_Graph323->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph323->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph323->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph323);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx324[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy324[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx324,Graph_fy324);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph324 = new TH1F("Graph_Graph324","Graph",100,0.75,0.87);
   Graph_Graph324->SetMinimum(0.285);
   Graph_Graph324->SetMaximum(0.465);
   Graph_Graph324->SetDirectory(0);
   Graph_Graph324->SetStats(0);
   Graph_Graph324->SetLineWidth(2);
   Graph_Graph324->GetXaxis()->SetNdivisions(506);
   Graph_Graph324->GetXaxis()->SetLabelFont(42);
   Graph_Graph324->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph324->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph324->GetXaxis()->SetTitleFont(42);
   Graph_Graph324->GetYaxis()->SetNdivisions(506);
   Graph_Graph324->GetYaxis()->SetLabelFont(42);
   Graph_Graph324->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph324->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph324->GetYaxis()->SetTitleFont(42);
   Graph_Graph324->GetZaxis()->SetNdivisions(506);
   Graph_Graph324->GetZaxis()->SetLabelFont(42);
   Graph_Graph324->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph324->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph324->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph324);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx325[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy325[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx325,Graph_fy325);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph325 = new TH1F("Graph_Graph325","Graph",100,0.852,0.948);
   Graph_Graph325->SetMinimum(0.285);
   Graph_Graph325->SetMaximum(0.465);
   Graph_Graph325->SetDirectory(0);
   Graph_Graph325->SetStats(0);
   Graph_Graph325->SetLineWidth(2);
   Graph_Graph325->GetXaxis()->SetNdivisions(506);
   Graph_Graph325->GetXaxis()->SetLabelFont(42);
   Graph_Graph325->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph325->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph325->GetXaxis()->SetTitleFont(42);
   Graph_Graph325->GetYaxis()->SetNdivisions(506);
   Graph_Graph325->GetYaxis()->SetLabelFont(42);
   Graph_Graph325->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph325->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph325->GetYaxis()->SetTitleFont(42);
   Graph_Graph325->GetZaxis()->SetNdivisions(506);
   Graph_Graph325->GetZaxis()->SetLabelFont(42);
   Graph_Graph325->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph325->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph325->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph325);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx326[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy326[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx326,Graph_fy326);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph326 = new TH1F("Graph_Graph326","Graph",100,0.934,1.006);
   Graph_Graph326->SetMinimum(0.285);
   Graph_Graph326->SetMaximum(0.465);
   Graph_Graph326->SetDirectory(0);
   Graph_Graph326->SetStats(0);
   Graph_Graph326->SetLineWidth(2);
   Graph_Graph326->GetXaxis()->SetNdivisions(506);
   Graph_Graph326->GetXaxis()->SetLabelFont(42);
   Graph_Graph326->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph326->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph326->GetXaxis()->SetTitleFont(42);
   Graph_Graph326->GetYaxis()->SetNdivisions(506);
   Graph_Graph326->GetYaxis()->SetLabelFont(42);
   Graph_Graph326->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph326->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph326->GetYaxis()->SetTitleFont(42);
   Graph_Graph326->GetZaxis()->SetNdivisions(506);
   Graph_Graph326->GetZaxis()->SetLabelFont(42);
   Graph_Graph326->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph326->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph326->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph326);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx327[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy327[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx327,Graph_fy327);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph327 = new TH1F("Graph_Graph327","Graph",100,-1.1,0);
   Graph_Graph327->SetMinimum(0.245);
   Graph_Graph327->SetMaximum(2.705);
   Graph_Graph327->SetDirectory(0);
   Graph_Graph327->SetStats(0);
   Graph_Graph327->SetLineWidth(2);
   Graph_Graph327->GetXaxis()->SetNdivisions(506);
   Graph_Graph327->GetXaxis()->SetLabelFont(42);
   Graph_Graph327->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph327->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph327->GetXaxis()->SetTitleFont(42);
   Graph_Graph327->GetYaxis()->SetNdivisions(506);
   Graph_Graph327->GetYaxis()->SetLabelFont(42);
   Graph_Graph327->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph327->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph327->GetYaxis()->SetTitleFont(42);
   Graph_Graph327->GetZaxis()->SetNdivisions(506);
   Graph_Graph327->GetZaxis()->SetLabelFont(42);
   Graph_Graph327->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph327->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph327->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph327);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx328[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy328[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx328,Graph_fy328);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002497");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph328 = new TH1F("Graph_Graph328","Graph",100,0,0.297);
   Graph_Graph328->SetMinimum(0.418);
   Graph_Graph328->SetMaximum(0.802);
   Graph_Graph328->SetDirectory(0);
   Graph_Graph328->SetStats(0);
   Graph_Graph328->SetLineWidth(2);
   Graph_Graph328->GetXaxis()->SetNdivisions(506);
   Graph_Graph328->GetXaxis()->SetLabelFont(42);
   Graph_Graph328->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph328->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph328->GetXaxis()->SetTitleFont(42);
   Graph_Graph328->GetYaxis()->SetNdivisions(506);
   Graph_Graph328->GetYaxis()->SetLabelFont(42);
   Graph_Graph328->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph328->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph328->GetYaxis()->SetTitleFont(42);
   Graph_Graph328->GetZaxis()->SetNdivisions(506);
   Graph_Graph328->GetZaxis()->SetLabelFont(42);
   Graph_Graph328->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph328->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph328->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph328);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx329[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy329[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx329,Graph_fy329);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00c2f7");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph329 = new TH1F("Graph_Graph329","Graph",100,0.252,0.468);
   Graph_Graph329->SetMinimum(0.418);
   Graph_Graph329->SetMaximum(0.802);
   Graph_Graph329->SetDirectory(0);
   Graph_Graph329->SetStats(0);
   Graph_Graph329->SetLineWidth(2);
   Graph_Graph329->GetXaxis()->SetNdivisions(506);
   Graph_Graph329->GetXaxis()->SetLabelFont(42);
   Graph_Graph329->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph329->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph329->GetXaxis()->SetTitleFont(42);
   Graph_Graph329->GetYaxis()->SetNdivisions(506);
   Graph_Graph329->GetYaxis()->SetLabelFont(42);
   Graph_Graph329->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph329->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph329->GetYaxis()->SetTitleFont(42);
   Graph_Graph329->GetZaxis()->SetNdivisions(506);
   Graph_Graph329->GetZaxis()->SetLabelFont(42);
   Graph_Graph329->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph329->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph329->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph329);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx330[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy330[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx330,Graph_fy330);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001f94");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph330 = new TH1F("Graph_Graph330","Graph",100,0.433,0.637);
   Graph_Graph330->SetMinimum(0.418);
   Graph_Graph330->SetMaximum(0.802);
   Graph_Graph330->SetDirectory(0);
   Graph_Graph330->SetStats(0);
   Graph_Graph330->SetLineWidth(2);
   Graph_Graph330->GetXaxis()->SetNdivisions(506);
   Graph_Graph330->GetXaxis()->SetLabelFont(42);
   Graph_Graph330->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph330->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph330->GetXaxis()->SetTitleFont(42);
   Graph_Graph330->GetYaxis()->SetNdivisions(506);
   Graph_Graph330->GetYaxis()->SetLabelFont(42);
   Graph_Graph330->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph330->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph330->GetYaxis()->SetTitleFont(42);
   Graph_Graph330->GetZaxis()->SetNdivisions(506);
   Graph_Graph330->GetZaxis()->SetLabelFont(42);
   Graph_Graph330->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph330->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph330->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph330);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx331[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy331[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx331,Graph_fy331);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph331 = new TH1F("Graph_Graph331","Graph",100,0.606,0.774);
   Graph_Graph331->SetMinimum(0.418);
   Graph_Graph331->SetMaximum(0.802);
   Graph_Graph331->SetDirectory(0);
   Graph_Graph331->SetStats(0);
   Graph_Graph331->SetLineWidth(2);
   Graph_Graph331->GetXaxis()->SetNdivisions(506);
   Graph_Graph331->GetXaxis()->SetLabelFont(42);
   Graph_Graph331->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph331->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph331->GetXaxis()->SetTitleFont(42);
   Graph_Graph331->GetYaxis()->SetNdivisions(506);
   Graph_Graph331->GetYaxis()->SetLabelFont(42);
   Graph_Graph331->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph331->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph331->GetYaxis()->SetTitleFont(42);
   Graph_Graph331->GetZaxis()->SetNdivisions(506);
   Graph_Graph331->GetZaxis()->SetLabelFont(42);
   Graph_Graph331->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph331->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph331->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph331);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx332[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy332[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx332,Graph_fy332);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph332 = new TH1F("Graph_Graph332","Graph",100,0.75,0.87);
   Graph_Graph332->SetMinimum(0.418);
   Graph_Graph332->SetMaximum(0.802);
   Graph_Graph332->SetDirectory(0);
   Graph_Graph332->SetStats(0);
   Graph_Graph332->SetLineWidth(2);
   Graph_Graph332->GetXaxis()->SetNdivisions(506);
   Graph_Graph332->GetXaxis()->SetLabelFont(42);
   Graph_Graph332->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph332->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph332->GetXaxis()->SetTitleFont(42);
   Graph_Graph332->GetYaxis()->SetNdivisions(506);
   Graph_Graph332->GetYaxis()->SetLabelFont(42);
   Graph_Graph332->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph332->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph332->GetYaxis()->SetTitleFont(42);
   Graph_Graph332->GetZaxis()->SetNdivisions(506);
   Graph_Graph332->GetZaxis()->SetLabelFont(42);
   Graph_Graph332->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph332->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph332->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph332);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx333[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy333[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx333,Graph_fy333);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph333 = new TH1F("Graph_Graph333","Graph",100,0.852,0.948);
   Graph_Graph333->SetMinimum(0.418);
   Graph_Graph333->SetMaximum(0.802);
   Graph_Graph333->SetDirectory(0);
   Graph_Graph333->SetStats(0);
   Graph_Graph333->SetLineWidth(2);
   Graph_Graph333->GetXaxis()->SetNdivisions(506);
   Graph_Graph333->GetXaxis()->SetLabelFont(42);
   Graph_Graph333->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph333->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph333->GetXaxis()->SetTitleFont(42);
   Graph_Graph333->GetYaxis()->SetNdivisions(506);
   Graph_Graph333->GetYaxis()->SetLabelFont(42);
   Graph_Graph333->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph333->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph333->GetYaxis()->SetTitleFont(42);
   Graph_Graph333->GetZaxis()->SetNdivisions(506);
   Graph_Graph333->GetZaxis()->SetLabelFont(42);
   Graph_Graph333->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph333->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph333->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph333);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx334[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy334[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx334,Graph_fy334);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph334 = new TH1F("Graph_Graph334","Graph",100,0.934,1.006);
   Graph_Graph334->SetMinimum(0.418);
   Graph_Graph334->SetMaximum(0.802);
   Graph_Graph334->SetDirectory(0);
   Graph_Graph334->SetStats(0);
   Graph_Graph334->SetLineWidth(2);
   Graph_Graph334->GetXaxis()->SetNdivisions(506);
   Graph_Graph334->GetXaxis()->SetLabelFont(42);
   Graph_Graph334->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph334->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph334->GetXaxis()->SetTitleFont(42);
   Graph_Graph334->GetYaxis()->SetNdivisions(506);
   Graph_Graph334->GetYaxis()->SetLabelFont(42);
   Graph_Graph334->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph334->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph334->GetYaxis()->SetTitleFont(42);
   Graph_Graph334->GetZaxis()->SetNdivisions(506);
   Graph_Graph334->GetZaxis()->SetLabelFont(42);
   Graph_Graph334->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph334->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph334->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph334);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx335[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy335[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx335,Graph_fy335);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph335 = new TH1F("Graph_Graph335","Graph",100,0,0.297);
   Graph_Graph335->SetMinimum(0.597);
   Graph_Graph335->SetMaximum(2.673);
   Graph_Graph335->SetDirectory(0);
   Graph_Graph335->SetStats(0);
   Graph_Graph335->SetLineWidth(2);
   Graph_Graph335->GetXaxis()->SetNdivisions(506);
   Graph_Graph335->GetXaxis()->SetLabelFont(42);
   Graph_Graph335->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph335->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph335->GetXaxis()->SetTitleFont(42);
   Graph_Graph335->GetYaxis()->SetNdivisions(506);
   Graph_Graph335->GetYaxis()->SetLabelFont(42);
   Graph_Graph335->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph335->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph335->GetYaxis()->SetTitleFont(42);
   Graph_Graph335->GetZaxis()->SetNdivisions(506);
   Graph_Graph335->GetZaxis()->SetLabelFont(42);
   Graph_Graph335->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph335->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph335->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph335);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx336[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy336[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx336,Graph_fy336);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00138d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph336 = new TH1F("Graph_Graph336","Graph",100,0.252,0.468);
   Graph_Graph336->SetMinimum(0.597);
   Graph_Graph336->SetMaximum(2.673);
   Graph_Graph336->SetDirectory(0);
   Graph_Graph336->SetStats(0);
   Graph_Graph336->SetLineWidth(2);
   Graph_Graph336->GetXaxis()->SetNdivisions(506);
   Graph_Graph336->GetXaxis()->SetLabelFont(42);
   Graph_Graph336->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph336->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph336->GetXaxis()->SetTitleFont(42);
   Graph_Graph336->GetYaxis()->SetNdivisions(506);
   Graph_Graph336->GetYaxis()->SetLabelFont(42);
   Graph_Graph336->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph336->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph336->GetYaxis()->SetTitleFont(42);
   Graph_Graph336->GetZaxis()->SetNdivisions(506);
   Graph_Graph336->GetZaxis()->SetLabelFont(42);
   Graph_Graph336->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph336->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph336->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph336);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx337[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy337[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx337,Graph_fy337);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph337 = new TH1F("Graph_Graph337","Graph",100,0.433,0.637);
   Graph_Graph337->SetMinimum(0.597);
   Graph_Graph337->SetMaximum(2.673);
   Graph_Graph337->SetDirectory(0);
   Graph_Graph337->SetStats(0);
   Graph_Graph337->SetLineWidth(2);
   Graph_Graph337->GetXaxis()->SetNdivisions(506);
   Graph_Graph337->GetXaxis()->SetLabelFont(42);
   Graph_Graph337->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph337->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph337->GetXaxis()->SetTitleFont(42);
   Graph_Graph337->GetYaxis()->SetNdivisions(506);
   Graph_Graph337->GetYaxis()->SetLabelFont(42);
   Graph_Graph337->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph337->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph337->GetYaxis()->SetTitleFont(42);
   Graph_Graph337->GetZaxis()->SetNdivisions(506);
   Graph_Graph337->GetZaxis()->SetLabelFont(42);
   Graph_Graph337->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph337->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph337->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph337);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx338[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy338[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx338,Graph_fy338);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph338 = new TH1F("Graph_Graph338","Graph",100,0.606,0.774);
   Graph_Graph338->SetMinimum(0.597);
   Graph_Graph338->SetMaximum(2.673);
   Graph_Graph338->SetDirectory(0);
   Graph_Graph338->SetStats(0);
   Graph_Graph338->SetLineWidth(2);
   Graph_Graph338->GetXaxis()->SetNdivisions(506);
   Graph_Graph338->GetXaxis()->SetLabelFont(42);
   Graph_Graph338->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph338->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph338->GetXaxis()->SetTitleFont(42);
   Graph_Graph338->GetYaxis()->SetNdivisions(506);
   Graph_Graph338->GetYaxis()->SetLabelFont(42);
   Graph_Graph338->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph338->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph338->GetYaxis()->SetTitleFont(42);
   Graph_Graph338->GetZaxis()->SetNdivisions(506);
   Graph_Graph338->GetZaxis()->SetLabelFont(42);
   Graph_Graph338->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph338->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph338->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph338);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx339[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy339[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx339,Graph_fy339);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph339 = new TH1F("Graph_Graph339","Graph",100,0.75,0.87);
   Graph_Graph339->SetMinimum(0.597);
   Graph_Graph339->SetMaximum(2.673);
   Graph_Graph339->SetDirectory(0);
   Graph_Graph339->SetStats(0);
   Graph_Graph339->SetLineWidth(2);
   Graph_Graph339->GetXaxis()->SetNdivisions(506);
   Graph_Graph339->GetXaxis()->SetLabelFont(42);
   Graph_Graph339->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph339->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph339->GetXaxis()->SetTitleFont(42);
   Graph_Graph339->GetYaxis()->SetNdivisions(506);
   Graph_Graph339->GetYaxis()->SetLabelFont(42);
   Graph_Graph339->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph339->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph339->GetYaxis()->SetTitleFont(42);
   Graph_Graph339->GetZaxis()->SetNdivisions(506);
   Graph_Graph339->GetZaxis()->SetLabelFont(42);
   Graph_Graph339->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph339->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph339->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph339);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx340[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy340[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx340,Graph_fy340);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph340 = new TH1F("Graph_Graph340","Graph",100,0.852,0.948);
   Graph_Graph340->SetMinimum(0.597);
   Graph_Graph340->SetMaximum(2.673);
   Graph_Graph340->SetDirectory(0);
   Graph_Graph340->SetStats(0);
   Graph_Graph340->SetLineWidth(2);
   Graph_Graph340->GetXaxis()->SetNdivisions(506);
   Graph_Graph340->GetXaxis()->SetLabelFont(42);
   Graph_Graph340->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph340->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph340->GetXaxis()->SetTitleFont(42);
   Graph_Graph340->GetYaxis()->SetNdivisions(506);
   Graph_Graph340->GetYaxis()->SetLabelFont(42);
   Graph_Graph340->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph340->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph340->GetYaxis()->SetTitleFont(42);
   Graph_Graph340->GetZaxis()->SetNdivisions(506);
   Graph_Graph340->GetZaxis()->SetLabelFont(42);
   Graph_Graph340->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph340->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph340->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph340);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx341[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy341[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx341,Graph_fy341);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph341 = new TH1F("Graph_Graph341","Graph",100,0.934,1.006);
   Graph_Graph341->SetMinimum(0.597);
   Graph_Graph341->SetMaximum(2.673);
   Graph_Graph341->SetDirectory(0);
   Graph_Graph341->SetStats(0);
   Graph_Graph341->SetLineWidth(2);
   Graph_Graph341->GetXaxis()->SetNdivisions(506);
   Graph_Graph341->GetXaxis()->SetLabelFont(42);
   Graph_Graph341->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph341->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph341->GetXaxis()->SetTitleFont(42);
   Graph_Graph341->GetYaxis()->SetNdivisions(506);
   Graph_Graph341->GetYaxis()->SetLabelFont(42);
   Graph_Graph341->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph341->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph341->GetYaxis()->SetTitleFont(42);
   Graph_Graph341->GetZaxis()->SetNdivisions(506);
   Graph_Graph341->GetZaxis()->SetLabelFont(42);
   Graph_Graph341->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph341->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph341->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph341);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.01325271);
   _reco_per_true->SetBinContent(2,0.02980784);
   _reco_per_true->SetBinContent(3,0.0723873);
   _reco_per_true->SetBinContent(4,0.03983638);
   _reco_per_true->SetBinContent(5,0.006629768);
   _reco_per_true->SetBinContent(7,0.003322577);
   _reco_per_true->SetBinContent(9,0.006643841);
   _reco_per_true->SetBinContent(10,0.09617311);
   _reco_per_true->SetBinContent(11,0.3812179);
   _reco_per_true->SetBinContent(12,0.1324008);
   _reco_per_true->SetBinContent(13,0.006630773);
   _reco_per_true->SetBinContent(14,0.003330596);
   _reco_per_true->SetBinContent(15,0.003302151);
   _reco_per_true->SetBinContent(16,0.006621839);
   _reco_per_true->SetBinContent(17,0.003305148);
   _reco_per_true->SetBinContent(18,0.02323785);
   _reco_per_true->SetBinContent(19,0.1222052);
   _reco_per_true->SetBinContent(20,0.01984083);
   _reco_per_true->SetBinContent(22,0.003322941);
   _reco_per_true->SetBinContent(23,0.003274563);
   _reco_per_true->SetBinContent(26,0.01327888);
   _reco_per_true->SetBinContent(27,0.006646242);
   _reco_per_true->SetBinContent(29,0.003330804);
   _reco_per_true->SetBinError(1,0.006626354);
   _reco_per_true->SetBinError(2,0.009935962);
   _reco_per_true->SetBinError(3,0.01543851);
   _reco_per_true->SetBinError(4,0.01149979);
   _reco_per_true->SetBinError(5,0.004687954);
   _reco_per_true->SetBinError(7,0.003322577);
   _reco_per_true->SetBinError(9,0.004697919);
   _reco_per_true->SetBinError(10,0.017859);
   _reco_per_true->SetBinError(11,0.03554952);
   _reco_per_true->SetBinError(12,0.02093637);
   _reco_per_true->SetBinError(13,0.004688664);
   _reco_per_true->SetBinError(14,0.003330596);
   _reco_per_true->SetBinError(15,0.003302151);
   _reco_per_true->SetBinError(16,0.004682348);
   _reco_per_true->SetBinError(17,0.003305148);
   _reco_per_true->SetBinError(18,0.008783092);
   _reco_per_true->SetBinError(19,0.02009491);
   _reco_per_true->SetBinError(20,0.008100178);
   _reco_per_true->SetBinError(22,0.003322941);
   _reco_per_true->SetBinError(23,0.003274563);
   _reco_per_true->SetBinError(26,0.006639455);
   _reco_per_true->SetBinError(27,0.004699615);
   _reco_per_true->SetBinError(29,0.003330804);
   _reco_per_true->SetEntries(302);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.001494972);
   _reco_per_true->SetContourLevel(2,0.002989944);
   _reco_per_true->SetContourLevel(3,0.004484917);
   _reco_per_true->SetContourLevel(4,0.005979889);
   _reco_per_true->SetContourLevel(5,0.007474861);
   _reco_per_true->SetContourLevel(6,0.008969833);
   _reco_per_true->SetContourLevel(7,0.01046481);
   _reco_per_true->SetContourLevel(8,0.01195978);
   _reco_per_true->SetContourLevel(9,0.01345475);
   _reco_per_true->SetContourLevel(10,0.01494972);
   _reco_per_true->SetContourLevel(11,0.01644469);
   _reco_per_true->SetContourLevel(12,0.01793967);
   _reco_per_true->SetContourLevel(13,0.01943464);
   _reco_per_true->SetContourLevel(14,0.02092961);
   _reco_per_true->SetContourLevel(15,0.02242458);
   _reco_per_true->SetContourLevel(16,0.02391956);
   _reco_per_true->SetContourLevel(17,0.02541453);
   _reco_per_true->SetContourLevel(18,0.0269095);
   _reco_per_true->SetContourLevel(19,0.02840447);
   _reco_per_true->SetContourLevel(20,0.02989944);
   _reco_per_true->SetContourLevel(21,0.03139442);
   _reco_per_true->SetContourLevel(22,0.03288939);
   _reco_per_true->SetContourLevel(23,0.03438436);
   _reco_per_true->SetContourLevel(24,0.03587933);
   _reco_per_true->SetContourLevel(25,0.03737431);
   _reco_per_true->SetContourLevel(26,0.03886928);
   _reco_per_true->SetContourLevel(27,0.04036425);
   _reco_per_true->SetContourLevel(28,0.04185922);
   _reco_per_true->SetContourLevel(29,0.04335419);
   _reco_per_true->SetContourLevel(30,0.04484917);
   _reco_per_true->SetContourLevel(31,0.04634414);
   _reco_per_true->SetContourLevel(32,0.04783911);
   _reco_per_true->SetContourLevel(33,0.04933408);
   _reco_per_true->SetContourLevel(34,0.05082906);
   _reco_per_true->SetContourLevel(35,0.05232403);
   _reco_per_true->SetContourLevel(36,0.053819);
   _reco_per_true->SetContourLevel(37,0.05531397);
   _reco_per_true->SetContourLevel(38,0.05680894);
   _reco_per_true->SetContourLevel(39,0.05830392);
   _reco_per_true->SetContourLevel(40,0.05979889);
   _reco_per_true->SetContourLevel(41,0.06129386);
   _reco_per_true->SetContourLevel(42,0.06278883);
   _reco_per_true->SetContourLevel(43,0.06428381);
   _reco_per_true->SetContourLevel(44,0.06577878);
   _reco_per_true->SetContourLevel(45,0.06727375);
   _reco_per_true->SetContourLevel(46,0.06876872);
   _reco_per_true->SetContourLevel(47,0.07026369);
   _reco_per_true->SetContourLevel(48,0.07175867);
   _reco_per_true->SetContourLevel(49,0.07325364);
   _reco_per_true->SetContourLevel(50,0.07474861);
   _reco_per_true->SetContourLevel(51,0.07624358);
   _reco_per_true->SetContourLevel(52,0.07773856);
   _reco_per_true->SetContourLevel(53,0.07923353);
   _reco_per_true->SetContourLevel(54,0.0807285);
   _reco_per_true->SetContourLevel(55,0.08222347);
   _reco_per_true->SetContourLevel(56,0.08371844);
   _reco_per_true->SetContourLevel(57,0.08521342);
   _reco_per_true->SetContourLevel(58,0.08670839);
   _reco_per_true->SetContourLevel(59,0.08820336);
   _reco_per_true->SetContourLevel(60,0.08969833);
   _reco_per_true->SetContourLevel(61,0.09119331);
   _reco_per_true->SetContourLevel(62,0.09268828);
   _reco_per_true->SetContourLevel(63,0.09418325);
   _reco_per_true->SetContourLevel(64,0.09567822);
   _reco_per_true->SetContourLevel(65,0.09717319);
   _reco_per_true->SetContourLevel(66,0.09866817);
   _reco_per_true->SetContourLevel(67,0.1001631);
   _reco_per_true->SetContourLevel(68,0.1016581);
   _reco_per_true->SetContourLevel(69,0.1031531);
   _reco_per_true->SetContourLevel(70,0.1046481);
   _reco_per_true->SetContourLevel(71,0.106143);
   _reco_per_true->SetContourLevel(72,0.107638);
   _reco_per_true->SetContourLevel(73,0.109133);
   _reco_per_true->SetContourLevel(74,0.1106279);
   _reco_per_true->SetContourLevel(75,0.1121229);
   _reco_per_true->SetContourLevel(76,0.1136179);
   _reco_per_true->SetContourLevel(77,0.1151129);
   _reco_per_true->SetContourLevel(78,0.1166078);
   _reco_per_true->SetContourLevel(79,0.1181028);
   _reco_per_true->SetContourLevel(80,0.1195978);
   _reco_per_true->SetContourLevel(81,0.1210927);
   _reco_per_true->SetContourLevel(82,0.1225877);
   _reco_per_true->SetContourLevel(83,0.1240827);
   _reco_per_true->SetContourLevel(84,0.1255777);
   _reco_per_true->SetContourLevel(85,0.1270726);
   _reco_per_true->SetContourLevel(86,0.1285676);
   _reco_per_true->SetContourLevel(87,0.1300626);
   _reco_per_true->SetContourLevel(88,0.1315576);
   _reco_per_true->SetContourLevel(89,0.1330525);
   _reco_per_true->SetContourLevel(90,0.1345475);
   _reco_per_true->SetContourLevel(91,0.1360425);
   _reco_per_true->SetContourLevel(92,0.1375374);
   _reco_per_true->SetContourLevel(93,0.1390324);
   _reco_per_true->SetContourLevel(94,0.1405274);
   _reco_per_true->SetContourLevel(95,0.1420224);
   _reco_per_true->SetContourLevel(96,0.1435173);
   _reco_per_true->SetContourLevel(97,0.1450123);
   _reco_per_true->SetContourLevel(98,0.1465073);
   _reco_per_true->SetContourLevel(99,0.1480022);
   _reco_per_true->SetContourLevel(100,0.1494972);
   _reco_per_true->SetContourLevel(101,0.1509922);
   _reco_per_true->SetContourLevel(102,0.1524872);
   _reco_per_true->SetContourLevel(103,0.1539821);
   _reco_per_true->SetContourLevel(104,0.1554771);
   _reco_per_true->SetContourLevel(105,0.1569721);
   _reco_per_true->SetContourLevel(106,0.1584671);
   _reco_per_true->SetContourLevel(107,0.159962);
   _reco_per_true->SetContourLevel(108,0.161457);
   _reco_per_true->SetContourLevel(109,0.162952);
   _reco_per_true->SetContourLevel(110,0.1644469);
   _reco_per_true->SetContourLevel(111,0.1659419);
   _reco_per_true->SetContourLevel(112,0.1674369);
   _reco_per_true->SetContourLevel(113,0.1689319);
   _reco_per_true->SetContourLevel(114,0.1704268);
   _reco_per_true->SetContourLevel(115,0.1719218);
   _reco_per_true->SetContourLevel(116,0.1734168);
   _reco_per_true->SetContourLevel(117,0.1749117);
   _reco_per_true->SetContourLevel(118,0.1764067);
   _reco_per_true->SetContourLevel(119,0.1779017);
   _reco_per_true->SetContourLevel(120,0.1793967);
   _reco_per_true->SetContourLevel(121,0.1808916);
   _reco_per_true->SetContourLevel(122,0.1823866);
   _reco_per_true->SetContourLevel(123,0.1838816);
   _reco_per_true->SetContourLevel(124,0.1853766);
   _reco_per_true->SetContourLevel(125,0.1868715);
   _reco_per_true->SetContourLevel(126,0.1883665);
   _reco_per_true->SetContourLevel(127,0.1898615);
   _reco_per_true->SetContourLevel(128,0.1913564);
   _reco_per_true->SetContourLevel(129,0.1928514);
   _reco_per_true->SetContourLevel(130,0.1943464);
   _reco_per_true->SetContourLevel(131,0.1958414);
   _reco_per_true->SetContourLevel(132,0.1973363);
   _reco_per_true->SetContourLevel(133,0.1988313);
   _reco_per_true->SetContourLevel(134,0.2003263);
   _reco_per_true->SetContourLevel(135,0.2018212);
   _reco_per_true->SetContourLevel(136,0.2033162);
   _reco_per_true->SetContourLevel(137,0.2048112);
   _reco_per_true->SetContourLevel(138,0.2063062);
   _reco_per_true->SetContourLevel(139,0.2078011);
   _reco_per_true->SetContourLevel(140,0.2092961);
   _reco_per_true->SetContourLevel(141,0.2107911);
   _reco_per_true->SetContourLevel(142,0.2122861);
   _reco_per_true->SetContourLevel(143,0.213781);
   _reco_per_true->SetContourLevel(144,0.215276);
   _reco_per_true->SetContourLevel(145,0.216771);
   _reco_per_true->SetContourLevel(146,0.2182659);
   _reco_per_true->SetContourLevel(147,0.2197609);
   _reco_per_true->SetContourLevel(148,0.2212559);
   _reco_per_true->SetContourLevel(149,0.2227509);
   _reco_per_true->SetContourLevel(150,0.2242458);
   _reco_per_true->SetContourLevel(151,0.2257408);
   _reco_per_true->SetContourLevel(152,0.2272358);
   _reco_per_true->SetContourLevel(153,0.2287307);
   _reco_per_true->SetContourLevel(154,0.2302257);
   _reco_per_true->SetContourLevel(155,0.2317207);
   _reco_per_true->SetContourLevel(156,0.2332157);
   _reco_per_true->SetContourLevel(157,0.2347106);
   _reco_per_true->SetContourLevel(158,0.2362056);
   _reco_per_true->SetContourLevel(159,0.2377006);
   _reco_per_true->SetContourLevel(160,0.2391956);
   _reco_per_true->SetContourLevel(161,0.2406905);
   _reco_per_true->SetContourLevel(162,0.2421855);
   _reco_per_true->SetContourLevel(163,0.2436805);
   _reco_per_true->SetContourLevel(164,0.2451754);
   _reco_per_true->SetContourLevel(165,0.2466704);
   _reco_per_true->SetContourLevel(166,0.2481654);
   _reco_per_true->SetContourLevel(167,0.2496604);
   _reco_per_true->SetContourLevel(168,0.2511553);
   _reco_per_true->SetContourLevel(169,0.2526503);
   _reco_per_true->SetContourLevel(170,0.2541453);
   _reco_per_true->SetContourLevel(171,0.2556402);
   _reco_per_true->SetContourLevel(172,0.2571352);
   _reco_per_true->SetContourLevel(173,0.2586302);
   _reco_per_true->SetContourLevel(174,0.2601252);
   _reco_per_true->SetContourLevel(175,0.2616201);
   _reco_per_true->SetContourLevel(176,0.2631151);
   _reco_per_true->SetContourLevel(177,0.2646101);
   _reco_per_true->SetContourLevel(178,0.2661051);
   _reco_per_true->SetContourLevel(179,0.2676);
   _reco_per_true->SetContourLevel(180,0.269095);
   _reco_per_true->SetContourLevel(181,0.27059);
   _reco_per_true->SetContourLevel(182,0.2720849);
   _reco_per_true->SetContourLevel(183,0.2735799);
   _reco_per_true->SetContourLevel(184,0.2750749);
   _reco_per_true->SetContourLevel(185,0.2765699);
   _reco_per_true->SetContourLevel(186,0.2780648);
   _reco_per_true->SetContourLevel(187,0.2795598);
   _reco_per_true->SetContourLevel(188,0.2810548);
   _reco_per_true->SetContourLevel(189,0.2825497);
   _reco_per_true->SetContourLevel(190,0.2840447);
   _reco_per_true->SetContourLevel(191,0.2855397);
   _reco_per_true->SetContourLevel(192,0.2870347);
   _reco_per_true->SetContourLevel(193,0.2885296);
   _reco_per_true->SetContourLevel(194,0.2900246);
   _reco_per_true->SetContourLevel(195,0.2915196);
   _reco_per_true->SetContourLevel(196,0.2930146);
   _reco_per_true->SetContourLevel(197,0.2945095);
   _reco_per_true->SetContourLevel(198,0.2960045);
   _reco_per_true->SetContourLevel(199,0.2974995);
   _reco_per_true->SetContourLevel(200,0.2989944);
   _reco_per_true->SetContourLevel(201,0.3004894);
   _reco_per_true->SetContourLevel(202,0.3019844);
   _reco_per_true->SetContourLevel(203,0.3034794);
   _reco_per_true->SetContourLevel(204,0.3049743);
   _reco_per_true->SetContourLevel(205,0.3064693);
   _reco_per_true->SetContourLevel(206,0.3079643);
   _reco_per_true->SetContourLevel(207,0.3094592);
   _reco_per_true->SetContourLevel(208,0.3109542);
   _reco_per_true->SetContourLevel(209,0.3124492);
   _reco_per_true->SetContourLevel(210,0.3139442);
   _reco_per_true->SetContourLevel(211,0.3154391);
   _reco_per_true->SetContourLevel(212,0.3169341);
   _reco_per_true->SetContourLevel(213,0.3184291);
   _reco_per_true->SetContourLevel(214,0.3199241);
   _reco_per_true->SetContourLevel(215,0.321419);
   _reco_per_true->SetContourLevel(216,0.322914);
   _reco_per_true->SetContourLevel(217,0.324409);
   _reco_per_true->SetContourLevel(218,0.3259039);
   _reco_per_true->SetContourLevel(219,0.3273989);
   _reco_per_true->SetContourLevel(220,0.3288939);
   _reco_per_true->SetContourLevel(221,0.3303889);
   _reco_per_true->SetContourLevel(222,0.3318838);
   _reco_per_true->SetContourLevel(223,0.3333788);
   _reco_per_true->SetContourLevel(224,0.3348738);
   _reco_per_true->SetContourLevel(225,0.3363687);
   _reco_per_true->SetContourLevel(226,0.3378637);
   _reco_per_true->SetContourLevel(227,0.3393587);
   _reco_per_true->SetContourLevel(228,0.3408537);
   _reco_per_true->SetContourLevel(229,0.3423486);
   _reco_per_true->SetContourLevel(230,0.3438436);
   _reco_per_true->SetContourLevel(231,0.3453386);
   _reco_per_true->SetContourLevel(232,0.3468336);
   _reco_per_true->SetContourLevel(233,0.3483285);
   _reco_per_true->SetContourLevel(234,0.3498235);
   _reco_per_true->SetContourLevel(235,0.3513185);
   _reco_per_true->SetContourLevel(236,0.3528134);
   _reco_per_true->SetContourLevel(237,0.3543084);
   _reco_per_true->SetContourLevel(238,0.3558034);
   _reco_per_true->SetContourLevel(239,0.3572984);
   _reco_per_true->SetContourLevel(240,0.3587933);
   _reco_per_true->SetContourLevel(241,0.3602883);
   _reco_per_true->SetContourLevel(242,0.3617833);
   _reco_per_true->SetContourLevel(243,0.3632782);
   _reco_per_true->SetContourLevel(244,0.3647732);
   _reco_per_true->SetContourLevel(245,0.3662682);
   _reco_per_true->SetContourLevel(246,0.3677632);
   _reco_per_true->SetContourLevel(247,0.3692581);
   _reco_per_true->SetContourLevel(248,0.3707531);
   _reco_per_true->SetContourLevel(249,0.3722481);
   _reco_per_true->SetContourLevel(250,0.3737431);
   _reco_per_true->SetContourLevel(251,0.375238);
   _reco_per_true->SetContourLevel(252,0.376733);
   _reco_per_true->SetContourLevel(253,0.378228);
   _reco_per_true->SetContourLevel(254,0.3797229);
   
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
   TText *AText = pt->AddText("True Bin 10");
   pt->Draw();
   c1_n11->Modified();
   c1_n11->cd();
   c1_n11->SetSelected(c1_n11);
}

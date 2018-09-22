void smearing_matrix_true_19()
{
//=========Macro generated from canvas: c1_n20/c1_n20
//=========  (Sat Sep 22 12:03:56 2018) by ROOT version6.06/06
   TCanvas *c1_n20 = new TCanvas("c1_n20", "c1_n20",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n20->SetHighLightColor(2);
   c1_n20->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n20->SetFillColor(10);
   c1_n20->SetBorderMode(0);
   c1_n20->SetBorderSize(2);
   c1_n20->SetFrameLineWidth(2);
   c1_n20->SetFrameBorderMode(0);
   c1_n20->SetFrameLineWidth(2);
   c1_n20->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 19", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx590[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy590[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx590,Graph_fy590);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph590 = new TH1F("Graph_Graph590","Graph",100,-1.1,0);
   Graph_Graph590->SetMinimum(0);
   Graph_Graph590->SetMaximum(0.33);
   Graph_Graph590->SetDirectory(0);
   Graph_Graph590->SetStats(0);
   Graph_Graph590->SetLineWidth(2);
   Graph_Graph590->GetXaxis()->SetNdivisions(506);
   Graph_Graph590->GetXaxis()->SetLabelFont(42);
   Graph_Graph590->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph590->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph590->GetXaxis()->SetTitleFont(42);
   Graph_Graph590->GetYaxis()->SetNdivisions(506);
   Graph_Graph590->GetYaxis()->SetLabelFont(42);
   Graph_Graph590->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph590->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph590->GetYaxis()->SetTitleFont(42);
   Graph_Graph590->GetZaxis()->SetNdivisions(506);
   Graph_Graph590->GetZaxis()->SetLabelFont(42);
   Graph_Graph590->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph590->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph590->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph590);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx591[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy591[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx591,Graph_fy591);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph591 = new TH1F("Graph_Graph591","Graph",100,0,0.297);
   Graph_Graph591->SetMinimum(0);
   Graph_Graph591->SetMaximum(0.33);
   Graph_Graph591->SetDirectory(0);
   Graph_Graph591->SetStats(0);
   Graph_Graph591->SetLineWidth(2);
   Graph_Graph591->GetXaxis()->SetNdivisions(506);
   Graph_Graph591->GetXaxis()->SetLabelFont(42);
   Graph_Graph591->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph591->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph591->GetXaxis()->SetTitleFont(42);
   Graph_Graph591->GetYaxis()->SetNdivisions(506);
   Graph_Graph591->GetYaxis()->SetLabelFont(42);
   Graph_Graph591->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph591->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph591->GetYaxis()->SetTitleFont(42);
   Graph_Graph591->GetZaxis()->SetNdivisions(506);
   Graph_Graph591->GetZaxis()->SetLabelFont(42);
   Graph_Graph591->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph591->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph591->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph591);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx592[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy592[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx592,Graph_fy592);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph592 = new TH1F("Graph_Graph592","Graph",100,0.252,0.468);
   Graph_Graph592->SetMinimum(0);
   Graph_Graph592->SetMaximum(0.33);
   Graph_Graph592->SetDirectory(0);
   Graph_Graph592->SetStats(0);
   Graph_Graph592->SetLineWidth(2);
   Graph_Graph592->GetXaxis()->SetNdivisions(506);
   Graph_Graph592->GetXaxis()->SetLabelFont(42);
   Graph_Graph592->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph592->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph592->GetXaxis()->SetTitleFont(42);
   Graph_Graph592->GetYaxis()->SetNdivisions(506);
   Graph_Graph592->GetYaxis()->SetLabelFont(42);
   Graph_Graph592->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph592->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph592->GetYaxis()->SetTitleFont(42);
   Graph_Graph592->GetZaxis()->SetNdivisions(506);
   Graph_Graph592->GetZaxis()->SetLabelFont(42);
   Graph_Graph592->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph592->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph592->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph592);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx593[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy593[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx593,Graph_fy593);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000e8a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph593 = new TH1F("Graph_Graph593","Graph",100,0.433,0.637);
   Graph_Graph593->SetMinimum(0);
   Graph_Graph593->SetMaximum(0.33);
   Graph_Graph593->SetDirectory(0);
   Graph_Graph593->SetStats(0);
   Graph_Graph593->SetLineWidth(2);
   Graph_Graph593->GetXaxis()->SetNdivisions(506);
   Graph_Graph593->GetXaxis()->SetLabelFont(42);
   Graph_Graph593->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph593->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph593->GetXaxis()->SetTitleFont(42);
   Graph_Graph593->GetYaxis()->SetNdivisions(506);
   Graph_Graph593->GetYaxis()->SetLabelFont(42);
   Graph_Graph593->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph593->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph593->GetYaxis()->SetTitleFont(42);
   Graph_Graph593->GetZaxis()->SetNdivisions(506);
   Graph_Graph593->GetZaxis()->SetLabelFont(42);
   Graph_Graph593->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph593->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph593->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph593);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx594[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy594[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx594,Graph_fy594);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph594 = new TH1F("Graph_Graph594","Graph",100,0.606,0.774);
   Graph_Graph594->SetMinimum(0);
   Graph_Graph594->SetMaximum(0.33);
   Graph_Graph594->SetDirectory(0);
   Graph_Graph594->SetStats(0);
   Graph_Graph594->SetLineWidth(2);
   Graph_Graph594->GetXaxis()->SetNdivisions(506);
   Graph_Graph594->GetXaxis()->SetLabelFont(42);
   Graph_Graph594->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph594->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph594->GetXaxis()->SetTitleFont(42);
   Graph_Graph594->GetYaxis()->SetNdivisions(506);
   Graph_Graph594->GetYaxis()->SetLabelFont(42);
   Graph_Graph594->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph594->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph594->GetYaxis()->SetTitleFont(42);
   Graph_Graph594->GetZaxis()->SetNdivisions(506);
   Graph_Graph594->GetZaxis()->SetLabelFont(42);
   Graph_Graph594->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph594->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph594->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph594);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx595[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy595[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx595,Graph_fy595);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph595 = new TH1F("Graph_Graph595","Graph",100,0.75,0.87);
   Graph_Graph595->SetMinimum(0);
   Graph_Graph595->SetMaximum(0.33);
   Graph_Graph595->SetDirectory(0);
   Graph_Graph595->SetStats(0);
   Graph_Graph595->SetLineWidth(2);
   Graph_Graph595->GetXaxis()->SetNdivisions(506);
   Graph_Graph595->GetXaxis()->SetLabelFont(42);
   Graph_Graph595->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph595->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph595->GetXaxis()->SetTitleFont(42);
   Graph_Graph595->GetYaxis()->SetNdivisions(506);
   Graph_Graph595->GetYaxis()->SetLabelFont(42);
   Graph_Graph595->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph595->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph595->GetYaxis()->SetTitleFont(42);
   Graph_Graph595->GetZaxis()->SetNdivisions(506);
   Graph_Graph595->GetZaxis()->SetLabelFont(42);
   Graph_Graph595->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph595->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph595->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph595);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx596[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy596[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx596,Graph_fy596);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph596 = new TH1F("Graph_Graph596","Graph",100,0.852,0.948);
   Graph_Graph596->SetMinimum(0);
   Graph_Graph596->SetMaximum(0.33);
   Graph_Graph596->SetDirectory(0);
   Graph_Graph596->SetStats(0);
   Graph_Graph596->SetLineWidth(2);
   Graph_Graph596->GetXaxis()->SetNdivisions(506);
   Graph_Graph596->GetXaxis()->SetLabelFont(42);
   Graph_Graph596->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph596->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph596->GetXaxis()->SetTitleFont(42);
   Graph_Graph596->GetYaxis()->SetNdivisions(506);
   Graph_Graph596->GetYaxis()->SetLabelFont(42);
   Graph_Graph596->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph596->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph596->GetYaxis()->SetTitleFont(42);
   Graph_Graph596->GetZaxis()->SetNdivisions(506);
   Graph_Graph596->GetZaxis()->SetLabelFont(42);
   Graph_Graph596->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph596->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph596->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph596);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx597[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy597[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx597,Graph_fy597);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph597 = new TH1F("Graph_Graph597","Graph",100,0.934,1.006);
   Graph_Graph597->SetMinimum(0);
   Graph_Graph597->SetMaximum(0.33);
   Graph_Graph597->SetDirectory(0);
   Graph_Graph597->SetStats(0);
   Graph_Graph597->SetLineWidth(2);
   Graph_Graph597->GetXaxis()->SetNdivisions(506);
   Graph_Graph597->GetXaxis()->SetLabelFont(42);
   Graph_Graph597->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph597->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph597->GetXaxis()->SetTitleFont(42);
   Graph_Graph597->GetYaxis()->SetNdivisions(506);
   Graph_Graph597->GetYaxis()->SetLabelFont(42);
   Graph_Graph597->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph597->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph597->GetYaxis()->SetTitleFont(42);
   Graph_Graph597->GetZaxis()->SetNdivisions(506);
   Graph_Graph597->GetZaxis()->SetLabelFont(42);
   Graph_Graph597->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph597->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph597->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph597);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx598[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy598[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx598,Graph_fy598);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph598 = new TH1F("Graph_Graph598","Graph",100,-1.1,0);
   Graph_Graph598->SetMinimum(0.285);
   Graph_Graph598->SetMaximum(0.465);
   Graph_Graph598->SetDirectory(0);
   Graph_Graph598->SetStats(0);
   Graph_Graph598->SetLineWidth(2);
   Graph_Graph598->GetXaxis()->SetNdivisions(506);
   Graph_Graph598->GetXaxis()->SetLabelFont(42);
   Graph_Graph598->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph598->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph598->GetXaxis()->SetTitleFont(42);
   Graph_Graph598->GetYaxis()->SetNdivisions(506);
   Graph_Graph598->GetYaxis()->SetLabelFont(42);
   Graph_Graph598->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph598->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph598->GetYaxis()->SetTitleFont(42);
   Graph_Graph598->GetZaxis()->SetNdivisions(506);
   Graph_Graph598->GetZaxis()->SetLabelFont(42);
   Graph_Graph598->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph598->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph598->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph598);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx599[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy599[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx599,Graph_fy599);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph599 = new TH1F("Graph_Graph599","Graph",100,0,0.297);
   Graph_Graph599->SetMinimum(0.285);
   Graph_Graph599->SetMaximum(0.465);
   Graph_Graph599->SetDirectory(0);
   Graph_Graph599->SetStats(0);
   Graph_Graph599->SetLineWidth(2);
   Graph_Graph599->GetXaxis()->SetNdivisions(506);
   Graph_Graph599->GetXaxis()->SetLabelFont(42);
   Graph_Graph599->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph599->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph599->GetXaxis()->SetTitleFont(42);
   Graph_Graph599->GetYaxis()->SetNdivisions(506);
   Graph_Graph599->GetYaxis()->SetLabelFont(42);
   Graph_Graph599->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph599->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph599->GetYaxis()->SetTitleFont(42);
   Graph_Graph599->GetZaxis()->SetNdivisions(506);
   Graph_Graph599->GetZaxis()->SetLabelFont(42);
   Graph_Graph599->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph599->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph599->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph599);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx600[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy600[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx600,Graph_fy600);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001a92");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph600 = new TH1F("Graph_Graph600","Graph",100,0.252,0.468);
   Graph_Graph600->SetMinimum(0.285);
   Graph_Graph600->SetMaximum(0.465);
   Graph_Graph600->SetDirectory(0);
   Graph_Graph600->SetStats(0);
   Graph_Graph600->SetLineWidth(2);
   Graph_Graph600->GetXaxis()->SetNdivisions(506);
   Graph_Graph600->GetXaxis()->SetLabelFont(42);
   Graph_Graph600->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph600->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph600->GetXaxis()->SetTitleFont(42);
   Graph_Graph600->GetYaxis()->SetNdivisions(506);
   Graph_Graph600->GetYaxis()->SetLabelFont(42);
   Graph_Graph600->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph600->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph600->GetYaxis()->SetTitleFont(42);
   Graph_Graph600->GetZaxis()->SetNdivisions(506);
   Graph_Graph600->GetZaxis()->SetLabelFont(42);
   Graph_Graph600->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph600->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph600->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph600);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx601[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy601[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx601,Graph_fy601);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0058b7");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph601 = new TH1F("Graph_Graph601","Graph",100,0.433,0.637);
   Graph_Graph601->SetMinimum(0.285);
   Graph_Graph601->SetMaximum(0.465);
   Graph_Graph601->SetDirectory(0);
   Graph_Graph601->SetStats(0);
   Graph_Graph601->SetLineWidth(2);
   Graph_Graph601->GetXaxis()->SetNdivisions(506);
   Graph_Graph601->GetXaxis()->SetLabelFont(42);
   Graph_Graph601->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph601->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph601->GetXaxis()->SetTitleFont(42);
   Graph_Graph601->GetYaxis()->SetNdivisions(506);
   Graph_Graph601->GetYaxis()->SetLabelFont(42);
   Graph_Graph601->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph601->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph601->GetYaxis()->SetTitleFont(42);
   Graph_Graph601->GetZaxis()->SetNdivisions(506);
   Graph_Graph601->GetZaxis()->SetLabelFont(42);
   Graph_Graph601->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph601->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph601->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph601);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx602[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy602[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx602,Graph_fy602);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002196");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph602 = new TH1F("Graph_Graph602","Graph",100,0.606,0.774);
   Graph_Graph602->SetMinimum(0.285);
   Graph_Graph602->SetMaximum(0.465);
   Graph_Graph602->SetDirectory(0);
   Graph_Graph602->SetStats(0);
   Graph_Graph602->SetLineWidth(2);
   Graph_Graph602->GetXaxis()->SetNdivisions(506);
   Graph_Graph602->GetXaxis()->SetLabelFont(42);
   Graph_Graph602->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph602->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph602->GetXaxis()->SetTitleFont(42);
   Graph_Graph602->GetYaxis()->SetNdivisions(506);
   Graph_Graph602->GetYaxis()->SetLabelFont(42);
   Graph_Graph602->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph602->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph602->GetYaxis()->SetTitleFont(42);
   Graph_Graph602->GetZaxis()->SetNdivisions(506);
   Graph_Graph602->GetZaxis()->SetLabelFont(42);
   Graph_Graph602->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph602->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph602->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph602);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx603[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy603[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx603,Graph_fy603);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph603 = new TH1F("Graph_Graph603","Graph",100,0.75,0.87);
   Graph_Graph603->SetMinimum(0.285);
   Graph_Graph603->SetMaximum(0.465);
   Graph_Graph603->SetDirectory(0);
   Graph_Graph603->SetStats(0);
   Graph_Graph603->SetLineWidth(2);
   Graph_Graph603->GetXaxis()->SetNdivisions(506);
   Graph_Graph603->GetXaxis()->SetLabelFont(42);
   Graph_Graph603->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph603->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph603->GetXaxis()->SetTitleFont(42);
   Graph_Graph603->GetYaxis()->SetNdivisions(506);
   Graph_Graph603->GetYaxis()->SetLabelFont(42);
   Graph_Graph603->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph603->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph603->GetYaxis()->SetTitleFont(42);
   Graph_Graph603->GetZaxis()->SetNdivisions(506);
   Graph_Graph603->GetZaxis()->SetLabelFont(42);
   Graph_Graph603->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph603->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph603->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph603);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx604[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy604[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx604,Graph_fy604);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph604 = new TH1F("Graph_Graph604","Graph",100,0.852,0.948);
   Graph_Graph604->SetMinimum(0.285);
   Graph_Graph604->SetMaximum(0.465);
   Graph_Graph604->SetDirectory(0);
   Graph_Graph604->SetStats(0);
   Graph_Graph604->SetLineWidth(2);
   Graph_Graph604->GetXaxis()->SetNdivisions(506);
   Graph_Graph604->GetXaxis()->SetLabelFont(42);
   Graph_Graph604->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph604->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph604->GetXaxis()->SetTitleFont(42);
   Graph_Graph604->GetYaxis()->SetNdivisions(506);
   Graph_Graph604->GetYaxis()->SetLabelFont(42);
   Graph_Graph604->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph604->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph604->GetYaxis()->SetTitleFont(42);
   Graph_Graph604->GetZaxis()->SetNdivisions(506);
   Graph_Graph604->GetZaxis()->SetLabelFont(42);
   Graph_Graph604->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph604->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph604->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph604);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx605[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy605[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx605,Graph_fy605);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph605 = new TH1F("Graph_Graph605","Graph",100,0.934,1.006);
   Graph_Graph605->SetMinimum(0.285);
   Graph_Graph605->SetMaximum(0.465);
   Graph_Graph605->SetDirectory(0);
   Graph_Graph605->SetStats(0);
   Graph_Graph605->SetLineWidth(2);
   Graph_Graph605->GetXaxis()->SetNdivisions(506);
   Graph_Graph605->GetXaxis()->SetLabelFont(42);
   Graph_Graph605->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph605->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph605->GetXaxis()->SetTitleFont(42);
   Graph_Graph605->GetYaxis()->SetNdivisions(506);
   Graph_Graph605->GetYaxis()->SetLabelFont(42);
   Graph_Graph605->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph605->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph605->GetYaxis()->SetTitleFont(42);
   Graph_Graph605->GetZaxis()->SetNdivisions(506);
   Graph_Graph605->GetZaxis()->SetLabelFont(42);
   Graph_Graph605->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph605->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph605->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph605);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx606[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy606[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx606,Graph_fy606);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph606 = new TH1F("Graph_Graph606","Graph",100,-1.1,0);
   Graph_Graph606->SetMinimum(0.245);
   Graph_Graph606->SetMaximum(2.705);
   Graph_Graph606->SetDirectory(0);
   Graph_Graph606->SetStats(0);
   Graph_Graph606->SetLineWidth(2);
   Graph_Graph606->GetXaxis()->SetNdivisions(506);
   Graph_Graph606->GetXaxis()->SetLabelFont(42);
   Graph_Graph606->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph606->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph606->GetXaxis()->SetTitleFont(42);
   Graph_Graph606->GetYaxis()->SetNdivisions(506);
   Graph_Graph606->GetYaxis()->SetLabelFont(42);
   Graph_Graph606->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph606->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph606->GetYaxis()->SetTitleFont(42);
   Graph_Graph606->GetZaxis()->SetNdivisions(506);
   Graph_Graph606->GetZaxis()->SetLabelFont(42);
   Graph_Graph606->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph606->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph606->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph606);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx607[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy607[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx607,Graph_fy607);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph607 = new TH1F("Graph_Graph607","Graph",100,0,0.297);
   Graph_Graph607->SetMinimum(0.418);
   Graph_Graph607->SetMaximum(0.802);
   Graph_Graph607->SetDirectory(0);
   Graph_Graph607->SetStats(0);
   Graph_Graph607->SetLineWidth(2);
   Graph_Graph607->GetXaxis()->SetNdivisions(506);
   Graph_Graph607->GetXaxis()->SetLabelFont(42);
   Graph_Graph607->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph607->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph607->GetXaxis()->SetTitleFont(42);
   Graph_Graph607->GetYaxis()->SetNdivisions(506);
   Graph_Graph607->GetYaxis()->SetLabelFont(42);
   Graph_Graph607->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph607->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph607->GetYaxis()->SetTitleFont(42);
   Graph_Graph607->GetZaxis()->SetNdivisions(506);
   Graph_Graph607->GetZaxis()->SetLabelFont(42);
   Graph_Graph607->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph607->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph607->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph607);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx608[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy608[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx608,Graph_fy608);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0045ac");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph608 = new TH1F("Graph_Graph608","Graph",100,0.252,0.468);
   Graph_Graph608->SetMinimum(0.418);
   Graph_Graph608->SetMaximum(0.802);
   Graph_Graph608->SetDirectory(0);
   Graph_Graph608->SetStats(0);
   Graph_Graph608->SetLineWidth(2);
   Graph_Graph608->GetXaxis()->SetNdivisions(506);
   Graph_Graph608->GetXaxis()->SetLabelFont(42);
   Graph_Graph608->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph608->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph608->GetXaxis()->SetTitleFont(42);
   Graph_Graph608->GetYaxis()->SetNdivisions(506);
   Graph_Graph608->GetYaxis()->SetLabelFont(42);
   Graph_Graph608->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph608->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph608->GetYaxis()->SetTitleFont(42);
   Graph_Graph608->GetZaxis()->SetNdivisions(506);
   Graph_Graph608->GetZaxis()->SetLabelFont(42);
   Graph_Graph608->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph608->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph608->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph608);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx609[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy609[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx609,Graph_fy609);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph609 = new TH1F("Graph_Graph609","Graph",100,0.433,0.637);
   Graph_Graph609->SetMinimum(0.418);
   Graph_Graph609->SetMaximum(0.802);
   Graph_Graph609->SetDirectory(0);
   Graph_Graph609->SetStats(0);
   Graph_Graph609->SetLineWidth(2);
   Graph_Graph609->GetXaxis()->SetNdivisions(506);
   Graph_Graph609->GetXaxis()->SetLabelFont(42);
   Graph_Graph609->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph609->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph609->GetXaxis()->SetTitleFont(42);
   Graph_Graph609->GetYaxis()->SetNdivisions(506);
   Graph_Graph609->GetYaxis()->SetLabelFont(42);
   Graph_Graph609->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph609->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph609->GetYaxis()->SetTitleFont(42);
   Graph_Graph609->GetZaxis()->SetNdivisions(506);
   Graph_Graph609->GetZaxis()->SetLabelFont(42);
   Graph_Graph609->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph609->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph609->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph609);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx610[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy610[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx610,Graph_fy610);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0088d4");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph610 = new TH1F("Graph_Graph610","Graph",100,0.606,0.774);
   Graph_Graph610->SetMinimum(0.418);
   Graph_Graph610->SetMaximum(0.802);
   Graph_Graph610->SetDirectory(0);
   Graph_Graph610->SetStats(0);
   Graph_Graph610->SetLineWidth(2);
   Graph_Graph610->GetXaxis()->SetNdivisions(506);
   Graph_Graph610->GetXaxis()->SetLabelFont(42);
   Graph_Graph610->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph610->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph610->GetXaxis()->SetTitleFont(42);
   Graph_Graph610->GetYaxis()->SetNdivisions(506);
   Graph_Graph610->GetYaxis()->SetLabelFont(42);
   Graph_Graph610->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph610->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph610->GetYaxis()->SetTitleFont(42);
   Graph_Graph610->GetZaxis()->SetNdivisions(506);
   Graph_Graph610->GetZaxis()->SetLabelFont(42);
   Graph_Graph610->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph610->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph610->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph610);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx611[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy611[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx611,Graph_fy611);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph611 = new TH1F("Graph_Graph611","Graph",100,0.75,0.87);
   Graph_Graph611->SetMinimum(0.418);
   Graph_Graph611->SetMaximum(0.802);
   Graph_Graph611->SetDirectory(0);
   Graph_Graph611->SetStats(0);
   Graph_Graph611->SetLineWidth(2);
   Graph_Graph611->GetXaxis()->SetNdivisions(506);
   Graph_Graph611->GetXaxis()->SetLabelFont(42);
   Graph_Graph611->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph611->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph611->GetXaxis()->SetTitleFont(42);
   Graph_Graph611->GetYaxis()->SetNdivisions(506);
   Graph_Graph611->GetYaxis()->SetLabelFont(42);
   Graph_Graph611->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph611->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph611->GetYaxis()->SetTitleFont(42);
   Graph_Graph611->GetZaxis()->SetNdivisions(506);
   Graph_Graph611->GetZaxis()->SetLabelFont(42);
   Graph_Graph611->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph611->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph611->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph611);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx612[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy612[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx612,Graph_fy612);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph612 = new TH1F("Graph_Graph612","Graph",100,0.852,0.948);
   Graph_Graph612->SetMinimum(0.418);
   Graph_Graph612->SetMaximum(0.802);
   Graph_Graph612->SetDirectory(0);
   Graph_Graph612->SetStats(0);
   Graph_Graph612->SetLineWidth(2);
   Graph_Graph612->GetXaxis()->SetNdivisions(506);
   Graph_Graph612->GetXaxis()->SetLabelFont(42);
   Graph_Graph612->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph612->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph612->GetXaxis()->SetTitleFont(42);
   Graph_Graph612->GetYaxis()->SetNdivisions(506);
   Graph_Graph612->GetYaxis()->SetLabelFont(42);
   Graph_Graph612->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph612->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph612->GetYaxis()->SetTitleFont(42);
   Graph_Graph612->GetZaxis()->SetNdivisions(506);
   Graph_Graph612->GetZaxis()->SetLabelFont(42);
   Graph_Graph612->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph612->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph612->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph612);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx613[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy613[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx613,Graph_fy613);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph613 = new TH1F("Graph_Graph613","Graph",100,0.934,1.006);
   Graph_Graph613->SetMinimum(0.418);
   Graph_Graph613->SetMaximum(0.802);
   Graph_Graph613->SetDirectory(0);
   Graph_Graph613->SetStats(0);
   Graph_Graph613->SetLineWidth(2);
   Graph_Graph613->GetXaxis()->SetNdivisions(506);
   Graph_Graph613->GetXaxis()->SetLabelFont(42);
   Graph_Graph613->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph613->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph613->GetXaxis()->SetTitleFont(42);
   Graph_Graph613->GetYaxis()->SetNdivisions(506);
   Graph_Graph613->GetYaxis()->SetLabelFont(42);
   Graph_Graph613->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph613->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph613->GetYaxis()->SetTitleFont(42);
   Graph_Graph613->GetZaxis()->SetNdivisions(506);
   Graph_Graph613->GetZaxis()->SetLabelFont(42);
   Graph_Graph613->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph613->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph613->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph613);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx614[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy614[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx614,Graph_fy614);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph614 = new TH1F("Graph_Graph614","Graph",100,0,0.297);
   Graph_Graph614->SetMinimum(0.597);
   Graph_Graph614->SetMaximum(2.673);
   Graph_Graph614->SetDirectory(0);
   Graph_Graph614->SetStats(0);
   Graph_Graph614->SetLineWidth(2);
   Graph_Graph614->GetXaxis()->SetNdivisions(506);
   Graph_Graph614->GetXaxis()->SetLabelFont(42);
   Graph_Graph614->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph614->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph614->GetXaxis()->SetTitleFont(42);
   Graph_Graph614->GetYaxis()->SetNdivisions(506);
   Graph_Graph614->GetYaxis()->SetLabelFont(42);
   Graph_Graph614->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph614->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph614->GetYaxis()->SetTitleFont(42);
   Graph_Graph614->GetZaxis()->SetNdivisions(506);
   Graph_Graph614->GetZaxis()->SetLabelFont(42);
   Graph_Graph614->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph614->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph614->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph614);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx615[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy615[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx615,Graph_fy615);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph615 = new TH1F("Graph_Graph615","Graph",100,0.252,0.468);
   Graph_Graph615->SetMinimum(0.597);
   Graph_Graph615->SetMaximum(2.673);
   Graph_Graph615->SetDirectory(0);
   Graph_Graph615->SetStats(0);
   Graph_Graph615->SetLineWidth(2);
   Graph_Graph615->GetXaxis()->SetNdivisions(506);
   Graph_Graph615->GetXaxis()->SetLabelFont(42);
   Graph_Graph615->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph615->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph615->GetXaxis()->SetTitleFont(42);
   Graph_Graph615->GetYaxis()->SetNdivisions(506);
   Graph_Graph615->GetYaxis()->SetLabelFont(42);
   Graph_Graph615->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph615->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph615->GetYaxis()->SetTitleFont(42);
   Graph_Graph615->GetZaxis()->SetNdivisions(506);
   Graph_Graph615->GetZaxis()->SetLabelFont(42);
   Graph_Graph615->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph615->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph615->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph615);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx616[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy616[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx616,Graph_fy616);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0067c0");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph616 = new TH1F("Graph_Graph616","Graph",100,0.433,0.637);
   Graph_Graph616->SetMinimum(0.597);
   Graph_Graph616->SetMaximum(2.673);
   Graph_Graph616->SetDirectory(0);
   Graph_Graph616->SetStats(0);
   Graph_Graph616->SetLineWidth(2);
   Graph_Graph616->GetXaxis()->SetNdivisions(506);
   Graph_Graph616->GetXaxis()->SetLabelFont(42);
   Graph_Graph616->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph616->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph616->GetXaxis()->SetTitleFont(42);
   Graph_Graph616->GetYaxis()->SetNdivisions(506);
   Graph_Graph616->GetYaxis()->SetLabelFont(42);
   Graph_Graph616->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph616->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph616->GetYaxis()->SetTitleFont(42);
   Graph_Graph616->GetZaxis()->SetNdivisions(506);
   Graph_Graph616->GetZaxis()->SetLabelFont(42);
   Graph_Graph616->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph616->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph616->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph616);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx617[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy617[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx617,Graph_fy617);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000e8a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph617 = new TH1F("Graph_Graph617","Graph",100,0.606,0.774);
   Graph_Graph617->SetMinimum(0.597);
   Graph_Graph617->SetMaximum(2.673);
   Graph_Graph617->SetDirectory(0);
   Graph_Graph617->SetStats(0);
   Graph_Graph617->SetLineWidth(2);
   Graph_Graph617->GetXaxis()->SetNdivisions(506);
   Graph_Graph617->GetXaxis()->SetLabelFont(42);
   Graph_Graph617->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph617->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph617->GetXaxis()->SetTitleFont(42);
   Graph_Graph617->GetYaxis()->SetNdivisions(506);
   Graph_Graph617->GetYaxis()->SetLabelFont(42);
   Graph_Graph617->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph617->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph617->GetYaxis()->SetTitleFont(42);
   Graph_Graph617->GetZaxis()->SetNdivisions(506);
   Graph_Graph617->GetZaxis()->SetLabelFont(42);
   Graph_Graph617->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph617->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph617->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph617);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx618[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy618[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx618,Graph_fy618);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph618 = new TH1F("Graph_Graph618","Graph",100,0.75,0.87);
   Graph_Graph618->SetMinimum(0.597);
   Graph_Graph618->SetMaximum(2.673);
   Graph_Graph618->SetDirectory(0);
   Graph_Graph618->SetStats(0);
   Graph_Graph618->SetLineWidth(2);
   Graph_Graph618->GetXaxis()->SetNdivisions(506);
   Graph_Graph618->GetXaxis()->SetLabelFont(42);
   Graph_Graph618->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph618->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph618->GetXaxis()->SetTitleFont(42);
   Graph_Graph618->GetYaxis()->SetNdivisions(506);
   Graph_Graph618->GetYaxis()->SetLabelFont(42);
   Graph_Graph618->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph618->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph618->GetYaxis()->SetTitleFont(42);
   Graph_Graph618->GetZaxis()->SetNdivisions(506);
   Graph_Graph618->GetZaxis()->SetLabelFont(42);
   Graph_Graph618->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph618->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph618->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph618);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx619[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy619[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx619,Graph_fy619);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph619 = new TH1F("Graph_Graph619","Graph",100,0.852,0.948);
   Graph_Graph619->SetMinimum(0.597);
   Graph_Graph619->SetMaximum(2.673);
   Graph_Graph619->SetDirectory(0);
   Graph_Graph619->SetStats(0);
   Graph_Graph619->SetLineWidth(2);
   Graph_Graph619->GetXaxis()->SetNdivisions(506);
   Graph_Graph619->GetXaxis()->SetLabelFont(42);
   Graph_Graph619->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph619->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph619->GetXaxis()->SetTitleFont(42);
   Graph_Graph619->GetYaxis()->SetNdivisions(506);
   Graph_Graph619->GetYaxis()->SetLabelFont(42);
   Graph_Graph619->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph619->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph619->GetYaxis()->SetTitleFont(42);
   Graph_Graph619->GetZaxis()->SetNdivisions(506);
   Graph_Graph619->GetZaxis()->SetLabelFont(42);
   Graph_Graph619->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph619->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph619->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph619);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx620[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy620[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx620,Graph_fy620);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph620 = new TH1F("Graph_Graph620","Graph",100,0.934,1.006);
   Graph_Graph620->SetMinimum(0.597);
   Graph_Graph620->SetMaximum(2.673);
   Graph_Graph620->SetDirectory(0);
   Graph_Graph620->SetStats(0);
   Graph_Graph620->SetLineWidth(2);
   Graph_Graph620->GetXaxis()->SetNdivisions(506);
   Graph_Graph620->GetXaxis()->SetLabelFont(42);
   Graph_Graph620->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph620->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph620->GetXaxis()->SetTitleFont(42);
   Graph_Graph620->GetYaxis()->SetNdivisions(506);
   Graph_Graph620->GetYaxis()->SetLabelFont(42);
   Graph_Graph620->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph620->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph620->GetYaxis()->SetTitleFont(42);
   Graph_Graph620->GetZaxis()->SetNdivisions(506);
   Graph_Graph620->GetZaxis()->SetLabelFont(42);
   Graph_Graph620->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph620->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph620->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph620);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.003527254);
   _reco_per_true->SetBinContent(2,0.001763327);
   _reco_per_true->SetBinContent(3,0.001765537);
   _reco_per_true->SetBinContent(4,0.01226337);
   _reco_per_true->SetBinContent(5,0.001764647);
   _reco_per_true->SetBinContent(9,0.005308447);
   _reco_per_true->SetBinContent(10,0.003534946);
   _reco_per_true->SetBinContent(11,0.02278182);
   _reco_per_true->SetBinContent(12,0.07757893);
   _reco_per_true->SetBinContent(13,0.02994641);
   _reco_per_true->SetBinContent(14,0.003542572);
   _reco_per_true->SetBinContent(16,0.001759184);
   _reco_per_true->SetBinContent(17,0.007072608);
   _reco_per_true->SetBinContent(18,0.003497518);
   _reco_per_true->SetBinContent(19,0.06004107);
   _reco_per_true->SetBinContent(20,0.5207542);
   _reco_per_true->SetBinContent(21,0.1182367);
   _reco_per_true->SetBinContent(22,0.007071796);
   _reco_per_true->SetBinContent(23,0.00353243);
   _reco_per_true->SetBinContent(24,0.00514255);
   _reco_per_true->SetBinContent(26,0.008622516);
   _reco_per_true->SetBinContent(27,0.08812075);
   _reco_per_true->SetBinContent(28,0.01237143);
   _reco_per_true->SetBinError(1,0.00249415);
   _reco_per_true->SetBinError(2,0.001763327);
   _reco_per_true->SetBinError(3,0.001765537);
   _reco_per_true->SetBinError(4,0.004636237);
   _reco_per_true->SetBinError(5,0.001764647);
   _reco_per_true->SetBinError(9,0.00306484);
   _reco_per_true->SetBinError(10,0.002499599);
   _reco_per_true->SetBinError(11,0.006320535);
   _reco_per_true->SetBinError(12,0.01169699);
   _reco_per_true->SetBinError(13,0.007264204);
   _reco_per_true->SetBinError(14,0.002504978);
   _reco_per_true->SetBinError(16,0.001759184);
   _reco_per_true->SetBinError(17,0.003536311);
   _reco_per_true->SetBinError(18,0.002473227);
   _reco_per_true->SetBinError(19,0.01029699);
   _reco_per_true->SetBinError(20,0.03032036);
   _reco_per_true->SetBinError(21,0.0144454);
   _reco_per_true->SetBinError(22,0.003535913);
   _reco_per_true->SetBinError(23,0.00249781);
   _reco_per_true->SetBinError(24,0.002969819);
   _reco_per_true->SetBinError(26,0.003859996);
   _reco_per_true->SetBinError(27,0.0124631);
   _reco_per_true->SetBinError(28,0.004675969);
   _reco_per_true->SetEntries(567);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.002042173);
   _reco_per_true->SetContourLevel(2,0.004084347);
   _reco_per_true->SetContourLevel(3,0.00612652);
   _reco_per_true->SetContourLevel(4,0.008168693);
   _reco_per_true->SetContourLevel(5,0.01021087);
   _reco_per_true->SetContourLevel(6,0.01225304);
   _reco_per_true->SetContourLevel(7,0.01429521);
   _reco_per_true->SetContourLevel(8,0.01633739);
   _reco_per_true->SetContourLevel(9,0.01837956);
   _reco_per_true->SetContourLevel(10,0.02042173);
   _reco_per_true->SetContourLevel(11,0.02246391);
   _reco_per_true->SetContourLevel(12,0.02450608);
   _reco_per_true->SetContourLevel(13,0.02654825);
   _reco_per_true->SetContourLevel(14,0.02859043);
   _reco_per_true->SetContourLevel(15,0.0306326);
   _reco_per_true->SetContourLevel(16,0.03267477);
   _reco_per_true->SetContourLevel(17,0.03471695);
   _reco_per_true->SetContourLevel(18,0.03675912);
   _reco_per_true->SetContourLevel(19,0.03880129);
   _reco_per_true->SetContourLevel(20,0.04084347);
   _reco_per_true->SetContourLevel(21,0.04288564);
   _reco_per_true->SetContourLevel(22,0.04492781);
   _reco_per_true->SetContourLevel(23,0.04696999);
   _reco_per_true->SetContourLevel(24,0.04901216);
   _reco_per_true->SetContourLevel(25,0.05105433);
   _reco_per_true->SetContourLevel(26,0.05309651);
   _reco_per_true->SetContourLevel(27,0.05513868);
   _reco_per_true->SetContourLevel(28,0.05718085);
   _reco_per_true->SetContourLevel(29,0.05922303);
   _reco_per_true->SetContourLevel(30,0.0612652);
   _reco_per_true->SetContourLevel(31,0.06330737);
   _reco_per_true->SetContourLevel(32,0.06534955);
   _reco_per_true->SetContourLevel(33,0.06739172);
   _reco_per_true->SetContourLevel(34,0.06943389);
   _reco_per_true->SetContourLevel(35,0.07147607);
   _reco_per_true->SetContourLevel(36,0.07351824);
   _reco_per_true->SetContourLevel(37,0.07556041);
   _reco_per_true->SetContourLevel(38,0.07760259);
   _reco_per_true->SetContourLevel(39,0.07964476);
   _reco_per_true->SetContourLevel(40,0.08168693);
   _reco_per_true->SetContourLevel(41,0.08372911);
   _reco_per_true->SetContourLevel(42,0.08577128);
   _reco_per_true->SetContourLevel(43,0.08781345);
   _reco_per_true->SetContourLevel(44,0.08985563);
   _reco_per_true->SetContourLevel(45,0.0918978);
   _reco_per_true->SetContourLevel(46,0.09393997);
   _reco_per_true->SetContourLevel(47,0.09598215);
   _reco_per_true->SetContourLevel(48,0.09802432);
   _reco_per_true->SetContourLevel(49,0.1000665);
   _reco_per_true->SetContourLevel(50,0.1021087);
   _reco_per_true->SetContourLevel(51,0.1041508);
   _reco_per_true->SetContourLevel(52,0.106193);
   _reco_per_true->SetContourLevel(53,0.1082352);
   _reco_per_true->SetContourLevel(54,0.1102774);
   _reco_per_true->SetContourLevel(55,0.1123195);
   _reco_per_true->SetContourLevel(56,0.1143617);
   _reco_per_true->SetContourLevel(57,0.1164039);
   _reco_per_true->SetContourLevel(58,0.1184461);
   _reco_per_true->SetContourLevel(59,0.1204882);
   _reco_per_true->SetContourLevel(60,0.1225304);
   _reco_per_true->SetContourLevel(61,0.1245726);
   _reco_per_true->SetContourLevel(62,0.1266147);
   _reco_per_true->SetContourLevel(63,0.1286569);
   _reco_per_true->SetContourLevel(64,0.1306991);
   _reco_per_true->SetContourLevel(65,0.1327413);
   _reco_per_true->SetContourLevel(66,0.1347834);
   _reco_per_true->SetContourLevel(67,0.1368256);
   _reco_per_true->SetContourLevel(68,0.1388678);
   _reco_per_true->SetContourLevel(69,0.14091);
   _reco_per_true->SetContourLevel(70,0.1429521);
   _reco_per_true->SetContourLevel(71,0.1449943);
   _reco_per_true->SetContourLevel(72,0.1470365);
   _reco_per_true->SetContourLevel(73,0.1490787);
   _reco_per_true->SetContourLevel(74,0.1511208);
   _reco_per_true->SetContourLevel(75,0.153163);
   _reco_per_true->SetContourLevel(76,0.1552052);
   _reco_per_true->SetContourLevel(77,0.1572473);
   _reco_per_true->SetContourLevel(78,0.1592895);
   _reco_per_true->SetContourLevel(79,0.1613317);
   _reco_per_true->SetContourLevel(80,0.1633739);
   _reco_per_true->SetContourLevel(81,0.165416);
   _reco_per_true->SetContourLevel(82,0.1674582);
   _reco_per_true->SetContourLevel(83,0.1695004);
   _reco_per_true->SetContourLevel(84,0.1715426);
   _reco_per_true->SetContourLevel(85,0.1735847);
   _reco_per_true->SetContourLevel(86,0.1756269);
   _reco_per_true->SetContourLevel(87,0.1776691);
   _reco_per_true->SetContourLevel(88,0.1797113);
   _reco_per_true->SetContourLevel(89,0.1817534);
   _reco_per_true->SetContourLevel(90,0.1837956);
   _reco_per_true->SetContourLevel(91,0.1858378);
   _reco_per_true->SetContourLevel(92,0.1878799);
   _reco_per_true->SetContourLevel(93,0.1899221);
   _reco_per_true->SetContourLevel(94,0.1919643);
   _reco_per_true->SetContourLevel(95,0.1940065);
   _reco_per_true->SetContourLevel(96,0.1960486);
   _reco_per_true->SetContourLevel(97,0.1980908);
   _reco_per_true->SetContourLevel(98,0.200133);
   _reco_per_true->SetContourLevel(99,0.2021752);
   _reco_per_true->SetContourLevel(100,0.2042173);
   _reco_per_true->SetContourLevel(101,0.2062595);
   _reco_per_true->SetContourLevel(102,0.2083017);
   _reco_per_true->SetContourLevel(103,0.2103439);
   _reco_per_true->SetContourLevel(104,0.212386);
   _reco_per_true->SetContourLevel(105,0.2144282);
   _reco_per_true->SetContourLevel(106,0.2164704);
   _reco_per_true->SetContourLevel(107,0.2185125);
   _reco_per_true->SetContourLevel(108,0.2205547);
   _reco_per_true->SetContourLevel(109,0.2225969);
   _reco_per_true->SetContourLevel(110,0.2246391);
   _reco_per_true->SetContourLevel(111,0.2266812);
   _reco_per_true->SetContourLevel(112,0.2287234);
   _reco_per_true->SetContourLevel(113,0.2307656);
   _reco_per_true->SetContourLevel(114,0.2328078);
   _reco_per_true->SetContourLevel(115,0.2348499);
   _reco_per_true->SetContourLevel(116,0.2368921);
   _reco_per_true->SetContourLevel(117,0.2389343);
   _reco_per_true->SetContourLevel(118,0.2409765);
   _reco_per_true->SetContourLevel(119,0.2430186);
   _reco_per_true->SetContourLevel(120,0.2450608);
   _reco_per_true->SetContourLevel(121,0.247103);
   _reco_per_true->SetContourLevel(122,0.2491451);
   _reco_per_true->SetContourLevel(123,0.2511873);
   _reco_per_true->SetContourLevel(124,0.2532295);
   _reco_per_true->SetContourLevel(125,0.2552717);
   _reco_per_true->SetContourLevel(126,0.2573138);
   _reco_per_true->SetContourLevel(127,0.259356);
   _reco_per_true->SetContourLevel(128,0.2613982);
   _reco_per_true->SetContourLevel(129,0.2634404);
   _reco_per_true->SetContourLevel(130,0.2654825);
   _reco_per_true->SetContourLevel(131,0.2675247);
   _reco_per_true->SetContourLevel(132,0.2695669);
   _reco_per_true->SetContourLevel(133,0.2716091);
   _reco_per_true->SetContourLevel(134,0.2736512);
   _reco_per_true->SetContourLevel(135,0.2756934);
   _reco_per_true->SetContourLevel(136,0.2777356);
   _reco_per_true->SetContourLevel(137,0.2797778);
   _reco_per_true->SetContourLevel(138,0.2818199);
   _reco_per_true->SetContourLevel(139,0.2838621);
   _reco_per_true->SetContourLevel(140,0.2859043);
   _reco_per_true->SetContourLevel(141,0.2879464);
   _reco_per_true->SetContourLevel(142,0.2899886);
   _reco_per_true->SetContourLevel(143,0.2920308);
   _reco_per_true->SetContourLevel(144,0.294073);
   _reco_per_true->SetContourLevel(145,0.2961151);
   _reco_per_true->SetContourLevel(146,0.2981573);
   _reco_per_true->SetContourLevel(147,0.3001995);
   _reco_per_true->SetContourLevel(148,0.3022417);
   _reco_per_true->SetContourLevel(149,0.3042838);
   _reco_per_true->SetContourLevel(150,0.306326);
   _reco_per_true->SetContourLevel(151,0.3083682);
   _reco_per_true->SetContourLevel(152,0.3104104);
   _reco_per_true->SetContourLevel(153,0.3124525);
   _reco_per_true->SetContourLevel(154,0.3144947);
   _reco_per_true->SetContourLevel(155,0.3165369);
   _reco_per_true->SetContourLevel(156,0.318579);
   _reco_per_true->SetContourLevel(157,0.3206212);
   _reco_per_true->SetContourLevel(158,0.3226634);
   _reco_per_true->SetContourLevel(159,0.3247056);
   _reco_per_true->SetContourLevel(160,0.3267477);
   _reco_per_true->SetContourLevel(161,0.3287899);
   _reco_per_true->SetContourLevel(162,0.3308321);
   _reco_per_true->SetContourLevel(163,0.3328743);
   _reco_per_true->SetContourLevel(164,0.3349164);
   _reco_per_true->SetContourLevel(165,0.3369586);
   _reco_per_true->SetContourLevel(166,0.3390008);
   _reco_per_true->SetContourLevel(167,0.341043);
   _reco_per_true->SetContourLevel(168,0.3430851);
   _reco_per_true->SetContourLevel(169,0.3451273);
   _reco_per_true->SetContourLevel(170,0.3471695);
   _reco_per_true->SetContourLevel(171,0.3492116);
   _reco_per_true->SetContourLevel(172,0.3512538);
   _reco_per_true->SetContourLevel(173,0.353296);
   _reco_per_true->SetContourLevel(174,0.3553382);
   _reco_per_true->SetContourLevel(175,0.3573803);
   _reco_per_true->SetContourLevel(176,0.3594225);
   _reco_per_true->SetContourLevel(177,0.3614647);
   _reco_per_true->SetContourLevel(178,0.3635069);
   _reco_per_true->SetContourLevel(179,0.365549);
   _reco_per_true->SetContourLevel(180,0.3675912);
   _reco_per_true->SetContourLevel(181,0.3696334);
   _reco_per_true->SetContourLevel(182,0.3716756);
   _reco_per_true->SetContourLevel(183,0.3737177);
   _reco_per_true->SetContourLevel(184,0.3757599);
   _reco_per_true->SetContourLevel(185,0.3778021);
   _reco_per_true->SetContourLevel(186,0.3798442);
   _reco_per_true->SetContourLevel(187,0.3818864);
   _reco_per_true->SetContourLevel(188,0.3839286);
   _reco_per_true->SetContourLevel(189,0.3859708);
   _reco_per_true->SetContourLevel(190,0.3880129);
   _reco_per_true->SetContourLevel(191,0.3900551);
   _reco_per_true->SetContourLevel(192,0.3920973);
   _reco_per_true->SetContourLevel(193,0.3941395);
   _reco_per_true->SetContourLevel(194,0.3961816);
   _reco_per_true->SetContourLevel(195,0.3982238);
   _reco_per_true->SetContourLevel(196,0.400266);
   _reco_per_true->SetContourLevel(197,0.4023082);
   _reco_per_true->SetContourLevel(198,0.4043503);
   _reco_per_true->SetContourLevel(199,0.4063925);
   _reco_per_true->SetContourLevel(200,0.4084347);
   _reco_per_true->SetContourLevel(201,0.4104768);
   _reco_per_true->SetContourLevel(202,0.412519);
   _reco_per_true->SetContourLevel(203,0.4145612);
   _reco_per_true->SetContourLevel(204,0.4166034);
   _reco_per_true->SetContourLevel(205,0.4186455);
   _reco_per_true->SetContourLevel(206,0.4206877);
   _reco_per_true->SetContourLevel(207,0.4227299);
   _reco_per_true->SetContourLevel(208,0.4247721);
   _reco_per_true->SetContourLevel(209,0.4268142);
   _reco_per_true->SetContourLevel(210,0.4288564);
   _reco_per_true->SetContourLevel(211,0.4308986);
   _reco_per_true->SetContourLevel(212,0.4329408);
   _reco_per_true->SetContourLevel(213,0.4349829);
   _reco_per_true->SetContourLevel(214,0.4370251);
   _reco_per_true->SetContourLevel(215,0.4390673);
   _reco_per_true->SetContourLevel(216,0.4411094);
   _reco_per_true->SetContourLevel(217,0.4431516);
   _reco_per_true->SetContourLevel(218,0.4451938);
   _reco_per_true->SetContourLevel(219,0.447236);
   _reco_per_true->SetContourLevel(220,0.4492781);
   _reco_per_true->SetContourLevel(221,0.4513203);
   _reco_per_true->SetContourLevel(222,0.4533625);
   _reco_per_true->SetContourLevel(223,0.4554047);
   _reco_per_true->SetContourLevel(224,0.4574468);
   _reco_per_true->SetContourLevel(225,0.459489);
   _reco_per_true->SetContourLevel(226,0.4615312);
   _reco_per_true->SetContourLevel(227,0.4635734);
   _reco_per_true->SetContourLevel(228,0.4656155);
   _reco_per_true->SetContourLevel(229,0.4676577);
   _reco_per_true->SetContourLevel(230,0.4696999);
   _reco_per_true->SetContourLevel(231,0.471742);
   _reco_per_true->SetContourLevel(232,0.4737842);
   _reco_per_true->SetContourLevel(233,0.4758264);
   _reco_per_true->SetContourLevel(234,0.4778686);
   _reco_per_true->SetContourLevel(235,0.4799107);
   _reco_per_true->SetContourLevel(236,0.4819529);
   _reco_per_true->SetContourLevel(237,0.4839951);
   _reco_per_true->SetContourLevel(238,0.4860373);
   _reco_per_true->SetContourLevel(239,0.4880794);
   _reco_per_true->SetContourLevel(240,0.4901216);
   _reco_per_true->SetContourLevel(241,0.4921638);
   _reco_per_true->SetContourLevel(242,0.494206);
   _reco_per_true->SetContourLevel(243,0.4962481);
   _reco_per_true->SetContourLevel(244,0.4982903);
   _reco_per_true->SetContourLevel(245,0.5003325);
   _reco_per_true->SetContourLevel(246,0.5023746);
   _reco_per_true->SetContourLevel(247,0.5044168);
   _reco_per_true->SetContourLevel(248,0.506459);
   _reco_per_true->SetContourLevel(249,0.5085012);
   _reco_per_true->SetContourLevel(250,0.5105433);
   _reco_per_true->SetContourLevel(251,0.5125855);
   _reco_per_true->SetContourLevel(252,0.5146277);
   _reco_per_true->SetContourLevel(253,0.5166699);
   _reco_per_true->SetContourLevel(254,0.518712);
   
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
   TText *AText = pt->AddText("True Bin 19");
   pt->Draw();
   c1_n20->Modified();
   c1_n20->cd();
   c1_n20->SetSelected(c1_n20);
}

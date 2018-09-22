void smearing_matrix_true_25()
{
//=========Macro generated from canvas: c1_n26/c1_n26
//=========  (Sat Sep 22 12:03:57 2018) by ROOT version6.06/06
   TCanvas *c1_n26 = new TCanvas("c1_n26", "c1_n26",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n26->SetHighLightColor(2);
   c1_n26->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n26->SetFillColor(10);
   c1_n26->SetBorderMode(0);
   c1_n26->SetBorderSize(2);
   c1_n26->SetFrameLineWidth(2);
   c1_n26->SetFrameBorderMode(0);
   c1_n26->SetFrameLineWidth(2);
   c1_n26->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 25", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx776[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy776[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx776,Graph_fy776);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph776 = new TH1F("Graph_Graph776","Graph",100,-1.1,0);
   Graph_Graph776->SetMinimum(0);
   Graph_Graph776->SetMaximum(0.33);
   Graph_Graph776->SetDirectory(0);
   Graph_Graph776->SetStats(0);
   Graph_Graph776->SetLineWidth(2);
   Graph_Graph776->GetXaxis()->SetNdivisions(506);
   Graph_Graph776->GetXaxis()->SetLabelFont(42);
   Graph_Graph776->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph776->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph776->GetXaxis()->SetTitleFont(42);
   Graph_Graph776->GetYaxis()->SetNdivisions(506);
   Graph_Graph776->GetYaxis()->SetLabelFont(42);
   Graph_Graph776->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph776->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph776->GetYaxis()->SetTitleFont(42);
   Graph_Graph776->GetZaxis()->SetNdivisions(506);
   Graph_Graph776->GetZaxis()->SetLabelFont(42);
   Graph_Graph776->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph776->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph776->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph776);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx777[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy777[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx777,Graph_fy777);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph777 = new TH1F("Graph_Graph777","Graph",100,0,0.297);
   Graph_Graph777->SetMinimum(0);
   Graph_Graph777->SetMaximum(0.33);
   Graph_Graph777->SetDirectory(0);
   Graph_Graph777->SetStats(0);
   Graph_Graph777->SetLineWidth(2);
   Graph_Graph777->GetXaxis()->SetNdivisions(506);
   Graph_Graph777->GetXaxis()->SetLabelFont(42);
   Graph_Graph777->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph777->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph777->GetXaxis()->SetTitleFont(42);
   Graph_Graph777->GetYaxis()->SetNdivisions(506);
   Graph_Graph777->GetYaxis()->SetLabelFont(42);
   Graph_Graph777->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph777->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph777->GetYaxis()->SetTitleFont(42);
   Graph_Graph777->GetZaxis()->SetNdivisions(506);
   Graph_Graph777->GetZaxis()->SetLabelFont(42);
   Graph_Graph777->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph777->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph777->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph777);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx778[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy778[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx778,Graph_fy778);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph778 = new TH1F("Graph_Graph778","Graph",100,0.252,0.468);
   Graph_Graph778->SetMinimum(0);
   Graph_Graph778->SetMaximum(0.33);
   Graph_Graph778->SetDirectory(0);
   Graph_Graph778->SetStats(0);
   Graph_Graph778->SetLineWidth(2);
   Graph_Graph778->GetXaxis()->SetNdivisions(506);
   Graph_Graph778->GetXaxis()->SetLabelFont(42);
   Graph_Graph778->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph778->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph778->GetXaxis()->SetTitleFont(42);
   Graph_Graph778->GetYaxis()->SetNdivisions(506);
   Graph_Graph778->GetYaxis()->SetLabelFont(42);
   Graph_Graph778->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph778->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph778->GetYaxis()->SetTitleFont(42);
   Graph_Graph778->GetZaxis()->SetNdivisions(506);
   Graph_Graph778->GetZaxis()->SetLabelFont(42);
   Graph_Graph778->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph778->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph778->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph778);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx779[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy779[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx779,Graph_fy779);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph779 = new TH1F("Graph_Graph779","Graph",100,0.433,0.637);
   Graph_Graph779->SetMinimum(0);
   Graph_Graph779->SetMaximum(0.33);
   Graph_Graph779->SetDirectory(0);
   Graph_Graph779->SetStats(0);
   Graph_Graph779->SetLineWidth(2);
   Graph_Graph779->GetXaxis()->SetNdivisions(506);
   Graph_Graph779->GetXaxis()->SetLabelFont(42);
   Graph_Graph779->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph779->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph779->GetXaxis()->SetTitleFont(42);
   Graph_Graph779->GetYaxis()->SetNdivisions(506);
   Graph_Graph779->GetYaxis()->SetLabelFont(42);
   Graph_Graph779->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph779->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph779->GetYaxis()->SetTitleFont(42);
   Graph_Graph779->GetZaxis()->SetNdivisions(506);
   Graph_Graph779->GetZaxis()->SetLabelFont(42);
   Graph_Graph779->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph779->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph779->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph779);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx780[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy780[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx780,Graph_fy780);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph780 = new TH1F("Graph_Graph780","Graph",100,0.606,0.774);
   Graph_Graph780->SetMinimum(0);
   Graph_Graph780->SetMaximum(0.33);
   Graph_Graph780->SetDirectory(0);
   Graph_Graph780->SetStats(0);
   Graph_Graph780->SetLineWidth(2);
   Graph_Graph780->GetXaxis()->SetNdivisions(506);
   Graph_Graph780->GetXaxis()->SetLabelFont(42);
   Graph_Graph780->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph780->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph780->GetXaxis()->SetTitleFont(42);
   Graph_Graph780->GetYaxis()->SetNdivisions(506);
   Graph_Graph780->GetYaxis()->SetLabelFont(42);
   Graph_Graph780->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph780->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph780->GetYaxis()->SetTitleFont(42);
   Graph_Graph780->GetZaxis()->SetNdivisions(506);
   Graph_Graph780->GetZaxis()->SetLabelFont(42);
   Graph_Graph780->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph780->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph780->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph780);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx781[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy781[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx781,Graph_fy781);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph781 = new TH1F("Graph_Graph781","Graph",100,0.75,0.87);
   Graph_Graph781->SetMinimum(0);
   Graph_Graph781->SetMaximum(0.33);
   Graph_Graph781->SetDirectory(0);
   Graph_Graph781->SetStats(0);
   Graph_Graph781->SetLineWidth(2);
   Graph_Graph781->GetXaxis()->SetNdivisions(506);
   Graph_Graph781->GetXaxis()->SetLabelFont(42);
   Graph_Graph781->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph781->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph781->GetXaxis()->SetTitleFont(42);
   Graph_Graph781->GetYaxis()->SetNdivisions(506);
   Graph_Graph781->GetYaxis()->SetLabelFont(42);
   Graph_Graph781->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph781->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph781->GetYaxis()->SetTitleFont(42);
   Graph_Graph781->GetZaxis()->SetNdivisions(506);
   Graph_Graph781->GetZaxis()->SetLabelFont(42);
   Graph_Graph781->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph781->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph781->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph781);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx782[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy782[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx782,Graph_fy782);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph782 = new TH1F("Graph_Graph782","Graph",100,0.852,0.948);
   Graph_Graph782->SetMinimum(0);
   Graph_Graph782->SetMaximum(0.33);
   Graph_Graph782->SetDirectory(0);
   Graph_Graph782->SetStats(0);
   Graph_Graph782->SetLineWidth(2);
   Graph_Graph782->GetXaxis()->SetNdivisions(506);
   Graph_Graph782->GetXaxis()->SetLabelFont(42);
   Graph_Graph782->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph782->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph782->GetXaxis()->SetTitleFont(42);
   Graph_Graph782->GetYaxis()->SetNdivisions(506);
   Graph_Graph782->GetYaxis()->SetLabelFont(42);
   Graph_Graph782->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph782->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph782->GetYaxis()->SetTitleFont(42);
   Graph_Graph782->GetZaxis()->SetNdivisions(506);
   Graph_Graph782->GetZaxis()->SetLabelFont(42);
   Graph_Graph782->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph782->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph782->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph782);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx783[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy783[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx783,Graph_fy783);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph783 = new TH1F("Graph_Graph783","Graph",100,0.934,1.006);
   Graph_Graph783->SetMinimum(0);
   Graph_Graph783->SetMaximum(0.33);
   Graph_Graph783->SetDirectory(0);
   Graph_Graph783->SetStats(0);
   Graph_Graph783->SetLineWidth(2);
   Graph_Graph783->GetXaxis()->SetNdivisions(506);
   Graph_Graph783->GetXaxis()->SetLabelFont(42);
   Graph_Graph783->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph783->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph783->GetXaxis()->SetTitleFont(42);
   Graph_Graph783->GetYaxis()->SetNdivisions(506);
   Graph_Graph783->GetYaxis()->SetLabelFont(42);
   Graph_Graph783->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph783->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph783->GetYaxis()->SetTitleFont(42);
   Graph_Graph783->GetZaxis()->SetNdivisions(506);
   Graph_Graph783->GetZaxis()->SetLabelFont(42);
   Graph_Graph783->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph783->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph783->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph783);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx784[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy784[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx784,Graph_fy784);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph784 = new TH1F("Graph_Graph784","Graph",100,-1.1,0);
   Graph_Graph784->SetMinimum(0.285);
   Graph_Graph784->SetMaximum(0.465);
   Graph_Graph784->SetDirectory(0);
   Graph_Graph784->SetStats(0);
   Graph_Graph784->SetLineWidth(2);
   Graph_Graph784->GetXaxis()->SetNdivisions(506);
   Graph_Graph784->GetXaxis()->SetLabelFont(42);
   Graph_Graph784->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph784->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph784->GetXaxis()->SetTitleFont(42);
   Graph_Graph784->GetYaxis()->SetNdivisions(506);
   Graph_Graph784->GetYaxis()->SetLabelFont(42);
   Graph_Graph784->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph784->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph784->GetYaxis()->SetTitleFont(42);
   Graph_Graph784->GetZaxis()->SetNdivisions(506);
   Graph_Graph784->GetZaxis()->SetLabelFont(42);
   Graph_Graph784->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph784->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph784->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph784);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx785[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy785[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx785,Graph_fy785);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph785 = new TH1F("Graph_Graph785","Graph",100,0,0.297);
   Graph_Graph785->SetMinimum(0.285);
   Graph_Graph785->SetMaximum(0.465);
   Graph_Graph785->SetDirectory(0);
   Graph_Graph785->SetStats(0);
   Graph_Graph785->SetLineWidth(2);
   Graph_Graph785->GetXaxis()->SetNdivisions(506);
   Graph_Graph785->GetXaxis()->SetLabelFont(42);
   Graph_Graph785->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph785->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph785->GetXaxis()->SetTitleFont(42);
   Graph_Graph785->GetYaxis()->SetNdivisions(506);
   Graph_Graph785->GetYaxis()->SetLabelFont(42);
   Graph_Graph785->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph785->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph785->GetYaxis()->SetTitleFont(42);
   Graph_Graph785->GetZaxis()->SetNdivisions(506);
   Graph_Graph785->GetZaxis()->SetLabelFont(42);
   Graph_Graph785->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph785->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph785->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph785);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx786[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy786[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx786,Graph_fy786);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph786 = new TH1F("Graph_Graph786","Graph",100,0.252,0.468);
   Graph_Graph786->SetMinimum(0.285);
   Graph_Graph786->SetMaximum(0.465);
   Graph_Graph786->SetDirectory(0);
   Graph_Graph786->SetStats(0);
   Graph_Graph786->SetLineWidth(2);
   Graph_Graph786->GetXaxis()->SetNdivisions(506);
   Graph_Graph786->GetXaxis()->SetLabelFont(42);
   Graph_Graph786->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph786->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph786->GetXaxis()->SetTitleFont(42);
   Graph_Graph786->GetYaxis()->SetNdivisions(506);
   Graph_Graph786->GetYaxis()->SetLabelFont(42);
   Graph_Graph786->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph786->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph786->GetYaxis()->SetTitleFont(42);
   Graph_Graph786->GetZaxis()->SetNdivisions(506);
   Graph_Graph786->GetZaxis()->SetLabelFont(42);
   Graph_Graph786->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph786->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph786->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph786);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx787[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy787[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx787,Graph_fy787);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph787 = new TH1F("Graph_Graph787","Graph",100,0.433,0.637);
   Graph_Graph787->SetMinimum(0.285);
   Graph_Graph787->SetMaximum(0.465);
   Graph_Graph787->SetDirectory(0);
   Graph_Graph787->SetStats(0);
   Graph_Graph787->SetLineWidth(2);
   Graph_Graph787->GetXaxis()->SetNdivisions(506);
   Graph_Graph787->GetXaxis()->SetLabelFont(42);
   Graph_Graph787->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph787->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph787->GetXaxis()->SetTitleFont(42);
   Graph_Graph787->GetYaxis()->SetNdivisions(506);
   Graph_Graph787->GetYaxis()->SetLabelFont(42);
   Graph_Graph787->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph787->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph787->GetYaxis()->SetTitleFont(42);
   Graph_Graph787->GetZaxis()->SetNdivisions(506);
   Graph_Graph787->GetZaxis()->SetLabelFont(42);
   Graph_Graph787->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph787->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph787->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph787);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx788[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy788[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx788,Graph_fy788);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph788 = new TH1F("Graph_Graph788","Graph",100,0.606,0.774);
   Graph_Graph788->SetMinimum(0.285);
   Graph_Graph788->SetMaximum(0.465);
   Graph_Graph788->SetDirectory(0);
   Graph_Graph788->SetStats(0);
   Graph_Graph788->SetLineWidth(2);
   Graph_Graph788->GetXaxis()->SetNdivisions(506);
   Graph_Graph788->GetXaxis()->SetLabelFont(42);
   Graph_Graph788->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph788->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph788->GetXaxis()->SetTitleFont(42);
   Graph_Graph788->GetYaxis()->SetNdivisions(506);
   Graph_Graph788->GetYaxis()->SetLabelFont(42);
   Graph_Graph788->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph788->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph788->GetYaxis()->SetTitleFont(42);
   Graph_Graph788->GetZaxis()->SetNdivisions(506);
   Graph_Graph788->GetZaxis()->SetLabelFont(42);
   Graph_Graph788->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph788->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph788->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph788);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx789[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy789[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx789,Graph_fy789);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0090d9");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph789 = new TH1F("Graph_Graph789","Graph",100,0.75,0.87);
   Graph_Graph789->SetMinimum(0.285);
   Graph_Graph789->SetMaximum(0.465);
   Graph_Graph789->SetDirectory(0);
   Graph_Graph789->SetStats(0);
   Graph_Graph789->SetLineWidth(2);
   Graph_Graph789->GetXaxis()->SetNdivisions(506);
   Graph_Graph789->GetXaxis()->SetLabelFont(42);
   Graph_Graph789->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph789->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph789->GetXaxis()->SetTitleFont(42);
   Graph_Graph789->GetYaxis()->SetNdivisions(506);
   Graph_Graph789->GetYaxis()->SetLabelFont(42);
   Graph_Graph789->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph789->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph789->GetYaxis()->SetTitleFont(42);
   Graph_Graph789->GetZaxis()->SetNdivisions(506);
   Graph_Graph789->GetZaxis()->SetLabelFont(42);
   Graph_Graph789->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph789->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph789->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph789);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx790[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy790[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx790,Graph_fy790);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph790 = new TH1F("Graph_Graph790","Graph",100,0.852,0.948);
   Graph_Graph790->SetMinimum(0.285);
   Graph_Graph790->SetMaximum(0.465);
   Graph_Graph790->SetDirectory(0);
   Graph_Graph790->SetStats(0);
   Graph_Graph790->SetLineWidth(2);
   Graph_Graph790->GetXaxis()->SetNdivisions(506);
   Graph_Graph790->GetXaxis()->SetLabelFont(42);
   Graph_Graph790->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph790->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph790->GetXaxis()->SetTitleFont(42);
   Graph_Graph790->GetYaxis()->SetNdivisions(506);
   Graph_Graph790->GetYaxis()->SetLabelFont(42);
   Graph_Graph790->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph790->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph790->GetYaxis()->SetTitleFont(42);
   Graph_Graph790->GetZaxis()->SetNdivisions(506);
   Graph_Graph790->GetZaxis()->SetLabelFont(42);
   Graph_Graph790->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph790->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph790->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph790);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx791[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy791[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx791,Graph_fy791);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph791 = new TH1F("Graph_Graph791","Graph",100,0.934,1.006);
   Graph_Graph791->SetMinimum(0.285);
   Graph_Graph791->SetMaximum(0.465);
   Graph_Graph791->SetDirectory(0);
   Graph_Graph791->SetStats(0);
   Graph_Graph791->SetLineWidth(2);
   Graph_Graph791->GetXaxis()->SetNdivisions(506);
   Graph_Graph791->GetXaxis()->SetLabelFont(42);
   Graph_Graph791->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph791->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph791->GetXaxis()->SetTitleFont(42);
   Graph_Graph791->GetYaxis()->SetNdivisions(506);
   Graph_Graph791->GetYaxis()->SetLabelFont(42);
   Graph_Graph791->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph791->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph791->GetYaxis()->SetTitleFont(42);
   Graph_Graph791->GetZaxis()->SetNdivisions(506);
   Graph_Graph791->GetZaxis()->SetLabelFont(42);
   Graph_Graph791->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph791->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph791->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph791);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx792[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy792[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx792,Graph_fy792);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph792 = new TH1F("Graph_Graph792","Graph",100,-1.1,0);
   Graph_Graph792->SetMinimum(0.245);
   Graph_Graph792->SetMaximum(2.705);
   Graph_Graph792->SetDirectory(0);
   Graph_Graph792->SetStats(0);
   Graph_Graph792->SetLineWidth(2);
   Graph_Graph792->GetXaxis()->SetNdivisions(506);
   Graph_Graph792->GetXaxis()->SetLabelFont(42);
   Graph_Graph792->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph792->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph792->GetXaxis()->SetTitleFont(42);
   Graph_Graph792->GetYaxis()->SetNdivisions(506);
   Graph_Graph792->GetYaxis()->SetLabelFont(42);
   Graph_Graph792->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph792->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph792->GetYaxis()->SetTitleFont(42);
   Graph_Graph792->GetZaxis()->SetNdivisions(506);
   Graph_Graph792->GetZaxis()->SetLabelFont(42);
   Graph_Graph792->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph792->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph792->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph792);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx793[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy793[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx793,Graph_fy793);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph793 = new TH1F("Graph_Graph793","Graph",100,0,0.297);
   Graph_Graph793->SetMinimum(0.418);
   Graph_Graph793->SetMaximum(0.802);
   Graph_Graph793->SetDirectory(0);
   Graph_Graph793->SetStats(0);
   Graph_Graph793->SetLineWidth(2);
   Graph_Graph793->GetXaxis()->SetNdivisions(506);
   Graph_Graph793->GetXaxis()->SetLabelFont(42);
   Graph_Graph793->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph793->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph793->GetXaxis()->SetTitleFont(42);
   Graph_Graph793->GetYaxis()->SetNdivisions(506);
   Graph_Graph793->GetYaxis()->SetLabelFont(42);
   Graph_Graph793->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph793->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph793->GetYaxis()->SetTitleFont(42);
   Graph_Graph793->GetZaxis()->SetNdivisions(506);
   Graph_Graph793->GetZaxis()->SetLabelFont(42);
   Graph_Graph793->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph793->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph793->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph793);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx794[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy794[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx794,Graph_fy794);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f08c0d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph794 = new TH1F("Graph_Graph794","Graph",100,0.252,0.468);
   Graph_Graph794->SetMinimum(0.418);
   Graph_Graph794->SetMaximum(0.802);
   Graph_Graph794->SetDirectory(0);
   Graph_Graph794->SetStats(0);
   Graph_Graph794->SetLineWidth(2);
   Graph_Graph794->GetXaxis()->SetNdivisions(506);
   Graph_Graph794->GetXaxis()->SetLabelFont(42);
   Graph_Graph794->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph794->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph794->GetXaxis()->SetTitleFont(42);
   Graph_Graph794->GetYaxis()->SetNdivisions(506);
   Graph_Graph794->GetYaxis()->SetLabelFont(42);
   Graph_Graph794->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph794->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph794->GetYaxis()->SetTitleFont(42);
   Graph_Graph794->GetZaxis()->SetNdivisions(506);
   Graph_Graph794->GetZaxis()->SetLabelFont(42);
   Graph_Graph794->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph794->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph794->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph794);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx795[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy795[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx795,Graph_fy795);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#8aec73");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph795 = new TH1F("Graph_Graph795","Graph",100,0.433,0.637);
   Graph_Graph795->SetMinimum(0.418);
   Graph_Graph795->SetMaximum(0.802);
   Graph_Graph795->SetDirectory(0);
   Graph_Graph795->SetStats(0);
   Graph_Graph795->SetLineWidth(2);
   Graph_Graph795->GetXaxis()->SetNdivisions(506);
   Graph_Graph795->GetXaxis()->SetLabelFont(42);
   Graph_Graph795->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph795->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph795->GetXaxis()->SetTitleFont(42);
   Graph_Graph795->GetYaxis()->SetNdivisions(506);
   Graph_Graph795->GetYaxis()->SetLabelFont(42);
   Graph_Graph795->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph795->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph795->GetYaxis()->SetTitleFont(42);
   Graph_Graph795->GetZaxis()->SetNdivisions(506);
   Graph_Graph795->GetZaxis()->SetLabelFont(42);
   Graph_Graph795->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph795->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph795->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph795);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx796[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy796[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx796,Graph_fy796);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph796 = new TH1F("Graph_Graph796","Graph",100,0.606,0.774);
   Graph_Graph796->SetMinimum(0.418);
   Graph_Graph796->SetMaximum(0.802);
   Graph_Graph796->SetDirectory(0);
   Graph_Graph796->SetStats(0);
   Graph_Graph796->SetLineWidth(2);
   Graph_Graph796->GetXaxis()->SetNdivisions(506);
   Graph_Graph796->GetXaxis()->SetLabelFont(42);
   Graph_Graph796->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph796->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph796->GetXaxis()->SetTitleFont(42);
   Graph_Graph796->GetYaxis()->SetNdivisions(506);
   Graph_Graph796->GetYaxis()->SetLabelFont(42);
   Graph_Graph796->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph796->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph796->GetYaxis()->SetTitleFont(42);
   Graph_Graph796->GetZaxis()->SetNdivisions(506);
   Graph_Graph796->GetZaxis()->SetLabelFont(42);
   Graph_Graph796->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph796->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph796->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph796);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx797[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy797[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx797,Graph_fy797);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph797 = new TH1F("Graph_Graph797","Graph",100,0.75,0.87);
   Graph_Graph797->SetMinimum(0.418);
   Graph_Graph797->SetMaximum(0.802);
   Graph_Graph797->SetDirectory(0);
   Graph_Graph797->SetStats(0);
   Graph_Graph797->SetLineWidth(2);
   Graph_Graph797->GetXaxis()->SetNdivisions(506);
   Graph_Graph797->GetXaxis()->SetLabelFont(42);
   Graph_Graph797->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph797->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph797->GetXaxis()->SetTitleFont(42);
   Graph_Graph797->GetYaxis()->SetNdivisions(506);
   Graph_Graph797->GetYaxis()->SetLabelFont(42);
   Graph_Graph797->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph797->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph797->GetYaxis()->SetTitleFont(42);
   Graph_Graph797->GetZaxis()->SetNdivisions(506);
   Graph_Graph797->GetZaxis()->SetLabelFont(42);
   Graph_Graph797->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph797->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph797->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph797);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx798[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy798[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx798,Graph_fy798);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#009ce0");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph798 = new TH1F("Graph_Graph798","Graph",100,0.852,0.948);
   Graph_Graph798->SetMinimum(0.418);
   Graph_Graph798->SetMaximum(0.802);
   Graph_Graph798->SetDirectory(0);
   Graph_Graph798->SetStats(0);
   Graph_Graph798->SetLineWidth(2);
   Graph_Graph798->GetXaxis()->SetNdivisions(506);
   Graph_Graph798->GetXaxis()->SetLabelFont(42);
   Graph_Graph798->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph798->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph798->GetXaxis()->SetTitleFont(42);
   Graph_Graph798->GetYaxis()->SetNdivisions(506);
   Graph_Graph798->GetYaxis()->SetLabelFont(42);
   Graph_Graph798->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph798->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph798->GetYaxis()->SetTitleFont(42);
   Graph_Graph798->GetZaxis()->SetNdivisions(506);
   Graph_Graph798->GetZaxis()->SetLabelFont(42);
   Graph_Graph798->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph798->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph798->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph798);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx799[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy799[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx799,Graph_fy799);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph799 = new TH1F("Graph_Graph799","Graph",100,0.934,1.006);
   Graph_Graph799->SetMinimum(0.418);
   Graph_Graph799->SetMaximum(0.802);
   Graph_Graph799->SetDirectory(0);
   Graph_Graph799->SetStats(0);
   Graph_Graph799->SetLineWidth(2);
   Graph_Graph799->GetXaxis()->SetNdivisions(506);
   Graph_Graph799->GetXaxis()->SetLabelFont(42);
   Graph_Graph799->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph799->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph799->GetXaxis()->SetTitleFont(42);
   Graph_Graph799->GetYaxis()->SetNdivisions(506);
   Graph_Graph799->GetYaxis()->SetLabelFont(42);
   Graph_Graph799->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph799->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph799->GetYaxis()->SetTitleFont(42);
   Graph_Graph799->GetZaxis()->SetNdivisions(506);
   Graph_Graph799->GetZaxis()->SetLabelFont(42);
   Graph_Graph799->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph799->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph799->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph799);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx800[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy800[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx800,Graph_fy800);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph800 = new TH1F("Graph_Graph800","Graph",100,0,0.297);
   Graph_Graph800->SetMinimum(0.597);
   Graph_Graph800->SetMaximum(2.673);
   Graph_Graph800->SetDirectory(0);
   Graph_Graph800->SetStats(0);
   Graph_Graph800->SetLineWidth(2);
   Graph_Graph800->GetXaxis()->SetNdivisions(506);
   Graph_Graph800->GetXaxis()->SetLabelFont(42);
   Graph_Graph800->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph800->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph800->GetXaxis()->SetTitleFont(42);
   Graph_Graph800->GetYaxis()->SetNdivisions(506);
   Graph_Graph800->GetYaxis()->SetLabelFont(42);
   Graph_Graph800->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph800->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph800->GetYaxis()->SetTitleFont(42);
   Graph_Graph800->GetZaxis()->SetNdivisions(506);
   Graph_Graph800->GetZaxis()->SetLabelFont(42);
   Graph_Graph800->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph800->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph800->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph800);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx801[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy801[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx801,Graph_fy801);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#8ded6f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph801 = new TH1F("Graph_Graph801","Graph",100,0.252,0.468);
   Graph_Graph801->SetMinimum(0.597);
   Graph_Graph801->SetMaximum(2.673);
   Graph_Graph801->SetDirectory(0);
   Graph_Graph801->SetStats(0);
   Graph_Graph801->SetLineWidth(2);
   Graph_Graph801->GetXaxis()->SetNdivisions(506);
   Graph_Graph801->GetXaxis()->SetLabelFont(42);
   Graph_Graph801->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph801->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph801->GetXaxis()->SetTitleFont(42);
   Graph_Graph801->GetYaxis()->SetNdivisions(506);
   Graph_Graph801->GetYaxis()->SetLabelFont(42);
   Graph_Graph801->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph801->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph801->GetYaxis()->SetTitleFont(42);
   Graph_Graph801->GetZaxis()->SetNdivisions(506);
   Graph_Graph801->GetZaxis()->SetLabelFont(42);
   Graph_Graph801->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph801->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph801->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph801);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx802[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy802[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx802,Graph_fy802);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph802 = new TH1F("Graph_Graph802","Graph",100,0.433,0.637);
   Graph_Graph802->SetMinimum(0.597);
   Graph_Graph802->SetMaximum(2.673);
   Graph_Graph802->SetDirectory(0);
   Graph_Graph802->SetStats(0);
   Graph_Graph802->SetLineWidth(2);
   Graph_Graph802->GetXaxis()->SetNdivisions(506);
   Graph_Graph802->GetXaxis()->SetLabelFont(42);
   Graph_Graph802->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph802->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph802->GetXaxis()->SetTitleFont(42);
   Graph_Graph802->GetYaxis()->SetNdivisions(506);
   Graph_Graph802->GetYaxis()->SetLabelFont(42);
   Graph_Graph802->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph802->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph802->GetYaxis()->SetTitleFont(42);
   Graph_Graph802->GetZaxis()->SetNdivisions(506);
   Graph_Graph802->GetZaxis()->SetLabelFont(42);
   Graph_Graph802->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph802->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph802->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph802);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx803[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy803[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx803,Graph_fy803);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph803 = new TH1F("Graph_Graph803","Graph",100,0.606,0.774);
   Graph_Graph803->SetMinimum(0.597);
   Graph_Graph803->SetMaximum(2.673);
   Graph_Graph803->SetDirectory(0);
   Graph_Graph803->SetStats(0);
   Graph_Graph803->SetLineWidth(2);
   Graph_Graph803->GetXaxis()->SetNdivisions(506);
   Graph_Graph803->GetXaxis()->SetLabelFont(42);
   Graph_Graph803->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph803->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph803->GetXaxis()->SetTitleFont(42);
   Graph_Graph803->GetYaxis()->SetNdivisions(506);
   Graph_Graph803->GetYaxis()->SetLabelFont(42);
   Graph_Graph803->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph803->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph803->GetYaxis()->SetTitleFont(42);
   Graph_Graph803->GetZaxis()->SetNdivisions(506);
   Graph_Graph803->GetZaxis()->SetLabelFont(42);
   Graph_Graph803->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph803->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph803->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph803);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx804[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy804[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx804,Graph_fy804);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph804 = new TH1F("Graph_Graph804","Graph",100,0.75,0.87);
   Graph_Graph804->SetMinimum(0.597);
   Graph_Graph804->SetMaximum(2.673);
   Graph_Graph804->SetDirectory(0);
   Graph_Graph804->SetStats(0);
   Graph_Graph804->SetLineWidth(2);
   Graph_Graph804->GetXaxis()->SetNdivisions(506);
   Graph_Graph804->GetXaxis()->SetLabelFont(42);
   Graph_Graph804->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph804->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph804->GetXaxis()->SetTitleFont(42);
   Graph_Graph804->GetYaxis()->SetNdivisions(506);
   Graph_Graph804->GetYaxis()->SetLabelFont(42);
   Graph_Graph804->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph804->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph804->GetYaxis()->SetTitleFont(42);
   Graph_Graph804->GetZaxis()->SetNdivisions(506);
   Graph_Graph804->GetZaxis()->SetLabelFont(42);
   Graph_Graph804->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph804->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph804->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph804);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx805[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy805[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx805,Graph_fy805);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph805 = new TH1F("Graph_Graph805","Graph",100,0.852,0.948);
   Graph_Graph805->SetMinimum(0.597);
   Graph_Graph805->SetMaximum(2.673);
   Graph_Graph805->SetDirectory(0);
   Graph_Graph805->SetStats(0);
   Graph_Graph805->SetLineWidth(2);
   Graph_Graph805->GetXaxis()->SetNdivisions(506);
   Graph_Graph805->GetXaxis()->SetLabelFont(42);
   Graph_Graph805->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph805->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph805->GetXaxis()->SetTitleFont(42);
   Graph_Graph805->GetYaxis()->SetNdivisions(506);
   Graph_Graph805->GetYaxis()->SetLabelFont(42);
   Graph_Graph805->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph805->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph805->GetYaxis()->SetTitleFont(42);
   Graph_Graph805->GetZaxis()->SetNdivisions(506);
   Graph_Graph805->GetZaxis()->SetLabelFont(42);
   Graph_Graph805->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph805->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph805->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph805);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx806[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy806[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx806,Graph_fy806);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph806 = new TH1F("Graph_Graph806","Graph",100,0.934,1.006);
   Graph_Graph806->SetMinimum(0.597);
   Graph_Graph806->SetMaximum(2.673);
   Graph_Graph806->SetDirectory(0);
   Graph_Graph806->SetStats(0);
   Graph_Graph806->SetLineWidth(2);
   Graph_Graph806->GetXaxis()->SetNdivisions(506);
   Graph_Graph806->GetXaxis()->SetLabelFont(42);
   Graph_Graph806->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph806->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph806->GetXaxis()->SetTitleFont(42);
   Graph_Graph806->GetYaxis()->SetNdivisions(506);
   Graph_Graph806->GetYaxis()->SetLabelFont(42);
   Graph_Graph806->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph806->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph806->GetYaxis()->SetTitleFont(42);
   Graph_Graph806->GetZaxis()->SetNdivisions(506);
   Graph_Graph806->GetZaxis()->SetLabelFont(42);
   Graph_Graph806->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph806->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph806->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph806);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(14,0.07316723);
   _reco_per_true->SetBinContent(19,0.2268811);
   _reco_per_true->SetBinContent(20,0.1564568);
   _reco_per_true->SetBinContent(23,0.07840494);
   _reco_per_true->SetBinContent(26,0.1575317);
   _reco_per_true->SetBinContent(27,0.3075582);
   _reco_per_true->SetBinError(14,0.07316723);
   _reco_per_true->SetBinError(19,0.1311484);
   _reco_per_true->SetBinError(20,0.1106317);
   _reco_per_true->SetBinError(23,0.07840494);
   _reco_per_true->SetBinError(26,0.1113917);
   _reco_per_true->SetBinError(27,0.1538416);
   _reco_per_true->SetEntries(13);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.001206111);
   _reco_per_true->SetContourLevel(2,0.002412221);
   _reco_per_true->SetContourLevel(3,0.003618332);
   _reco_per_true->SetContourLevel(4,0.004824442);
   _reco_per_true->SetContourLevel(5,0.006030553);
   _reco_per_true->SetContourLevel(6,0.007236664);
   _reco_per_true->SetContourLevel(7,0.008442774);
   _reco_per_true->SetContourLevel(8,0.009648885);
   _reco_per_true->SetContourLevel(9,0.010855);
   _reco_per_true->SetContourLevel(10,0.01206111);
   _reco_per_true->SetContourLevel(11,0.01326722);
   _reco_per_true->SetContourLevel(12,0.01447333);
   _reco_per_true->SetContourLevel(13,0.01567944);
   _reco_per_true->SetContourLevel(14,0.01688555);
   _reco_per_true->SetContourLevel(15,0.01809166);
   _reco_per_true->SetContourLevel(16,0.01929777);
   _reco_per_true->SetContourLevel(17,0.02050388);
   _reco_per_true->SetContourLevel(18,0.02170999);
   _reco_per_true->SetContourLevel(19,0.0229161);
   _reco_per_true->SetContourLevel(20,0.02412221);
   _reco_per_true->SetContourLevel(21,0.02532832);
   _reco_per_true->SetContourLevel(22,0.02653443);
   _reco_per_true->SetContourLevel(23,0.02774054);
   _reco_per_true->SetContourLevel(24,0.02894665);
   _reco_per_true->SetContourLevel(25,0.03015277);
   _reco_per_true->SetContourLevel(26,0.03135888);
   _reco_per_true->SetContourLevel(27,0.03256499);
   _reco_per_true->SetContourLevel(28,0.0337711);
   _reco_per_true->SetContourLevel(29,0.03497721);
   _reco_per_true->SetContourLevel(30,0.03618332);
   _reco_per_true->SetContourLevel(31,0.03738943);
   _reco_per_true->SetContourLevel(32,0.03859554);
   _reco_per_true->SetContourLevel(33,0.03980165);
   _reco_per_true->SetContourLevel(34,0.04100776);
   _reco_per_true->SetContourLevel(35,0.04221387);
   _reco_per_true->SetContourLevel(36,0.04341998);
   _reco_per_true->SetContourLevel(37,0.04462609);
   _reco_per_true->SetContourLevel(38,0.0458322);
   _reco_per_true->SetContourLevel(39,0.04703831);
   _reco_per_true->SetContourLevel(40,0.04824442);
   _reco_per_true->SetContourLevel(41,0.04945054);
   _reco_per_true->SetContourLevel(42,0.05065665);
   _reco_per_true->SetContourLevel(43,0.05186276);
   _reco_per_true->SetContourLevel(44,0.05306887);
   _reco_per_true->SetContourLevel(45,0.05427498);
   _reco_per_true->SetContourLevel(46,0.05548109);
   _reco_per_true->SetContourLevel(47,0.0566872);
   _reco_per_true->SetContourLevel(48,0.05789331);
   _reco_per_true->SetContourLevel(49,0.05909942);
   _reco_per_true->SetContourLevel(50,0.06030553);
   _reco_per_true->SetContourLevel(51,0.06151164);
   _reco_per_true->SetContourLevel(52,0.06271775);
   _reco_per_true->SetContourLevel(53,0.06392386);
   _reco_per_true->SetContourLevel(54,0.06512997);
   _reco_per_true->SetContourLevel(55,0.06633608);
   _reco_per_true->SetContourLevel(56,0.06754219);
   _reco_per_true->SetContourLevel(57,0.06874831);
   _reco_per_true->SetContourLevel(58,0.06995442);
   _reco_per_true->SetContourLevel(59,0.07116053);
   _reco_per_true->SetContourLevel(60,0.07236664);
   _reco_per_true->SetContourLevel(61,0.07357275);
   _reco_per_true->SetContourLevel(62,0.07477886);
   _reco_per_true->SetContourLevel(63,0.07598497);
   _reco_per_true->SetContourLevel(64,0.07719108);
   _reco_per_true->SetContourLevel(65,0.07839719);
   _reco_per_true->SetContourLevel(66,0.0796033);
   _reco_per_true->SetContourLevel(67,0.08080941);
   _reco_per_true->SetContourLevel(68,0.08201552);
   _reco_per_true->SetContourLevel(69,0.08322163);
   _reco_per_true->SetContourLevel(70,0.08442774);
   _reco_per_true->SetContourLevel(71,0.08563385);
   _reco_per_true->SetContourLevel(72,0.08683996);
   _reco_per_true->SetContourLevel(73,0.08804608);
   _reco_per_true->SetContourLevel(74,0.08925219);
   _reco_per_true->SetContourLevel(75,0.0904583);
   _reco_per_true->SetContourLevel(76,0.09166441);
   _reco_per_true->SetContourLevel(77,0.09287052);
   _reco_per_true->SetContourLevel(78,0.09407663);
   _reco_per_true->SetContourLevel(79,0.09528274);
   _reco_per_true->SetContourLevel(80,0.09648885);
   _reco_per_true->SetContourLevel(81,0.09769496);
   _reco_per_true->SetContourLevel(82,0.09890107);
   _reco_per_true->SetContourLevel(83,0.1001072);
   _reco_per_true->SetContourLevel(84,0.1013133);
   _reco_per_true->SetContourLevel(85,0.1025194);
   _reco_per_true->SetContourLevel(86,0.1037255);
   _reco_per_true->SetContourLevel(87,0.1049316);
   _reco_per_true->SetContourLevel(88,0.1061377);
   _reco_per_true->SetContourLevel(89,0.1073438);
   _reco_per_true->SetContourLevel(90,0.10855);
   _reco_per_true->SetContourLevel(91,0.1097561);
   _reco_per_true->SetContourLevel(92,0.1109622);
   _reco_per_true->SetContourLevel(93,0.1121683);
   _reco_per_true->SetContourLevel(94,0.1133744);
   _reco_per_true->SetContourLevel(95,0.1145805);
   _reco_per_true->SetContourLevel(96,0.1157866);
   _reco_per_true->SetContourLevel(97,0.1169927);
   _reco_per_true->SetContourLevel(98,0.1181988);
   _reco_per_true->SetContourLevel(99,0.119405);
   _reco_per_true->SetContourLevel(100,0.1206111);
   _reco_per_true->SetContourLevel(101,0.1218172);
   _reco_per_true->SetContourLevel(102,0.1230233);
   _reco_per_true->SetContourLevel(103,0.1242294);
   _reco_per_true->SetContourLevel(104,0.1254355);
   _reco_per_true->SetContourLevel(105,0.1266416);
   _reco_per_true->SetContourLevel(106,0.1278477);
   _reco_per_true->SetContourLevel(107,0.1290538);
   _reco_per_true->SetContourLevel(108,0.1302599);
   _reco_per_true->SetContourLevel(109,0.1314661);
   _reco_per_true->SetContourLevel(110,0.1326722);
   _reco_per_true->SetContourLevel(111,0.1338783);
   _reco_per_true->SetContourLevel(112,0.1350844);
   _reco_per_true->SetContourLevel(113,0.1362905);
   _reco_per_true->SetContourLevel(114,0.1374966);
   _reco_per_true->SetContourLevel(115,0.1387027);
   _reco_per_true->SetContourLevel(116,0.1399088);
   _reco_per_true->SetContourLevel(117,0.1411149);
   _reco_per_true->SetContourLevel(118,0.1423211);
   _reco_per_true->SetContourLevel(119,0.1435272);
   _reco_per_true->SetContourLevel(120,0.1447333);
   _reco_per_true->SetContourLevel(121,0.1459394);
   _reco_per_true->SetContourLevel(122,0.1471455);
   _reco_per_true->SetContourLevel(123,0.1483516);
   _reco_per_true->SetContourLevel(124,0.1495577);
   _reco_per_true->SetContourLevel(125,0.1507638);
   _reco_per_true->SetContourLevel(126,0.1519699);
   _reco_per_true->SetContourLevel(127,0.153176);
   _reco_per_true->SetContourLevel(128,0.1543822);
   _reco_per_true->SetContourLevel(129,0.1555883);
   _reco_per_true->SetContourLevel(130,0.1567944);
   _reco_per_true->SetContourLevel(131,0.1580005);
   _reco_per_true->SetContourLevel(132,0.1592066);
   _reco_per_true->SetContourLevel(133,0.1604127);
   _reco_per_true->SetContourLevel(134,0.1616188);
   _reco_per_true->SetContourLevel(135,0.1628249);
   _reco_per_true->SetContourLevel(136,0.164031);
   _reco_per_true->SetContourLevel(137,0.1652372);
   _reco_per_true->SetContourLevel(138,0.1664433);
   _reco_per_true->SetContourLevel(139,0.1676494);
   _reco_per_true->SetContourLevel(140,0.1688555);
   _reco_per_true->SetContourLevel(141,0.1700616);
   _reco_per_true->SetContourLevel(142,0.1712677);
   _reco_per_true->SetContourLevel(143,0.1724738);
   _reco_per_true->SetContourLevel(144,0.1736799);
   _reco_per_true->SetContourLevel(145,0.174886);
   _reco_per_true->SetContourLevel(146,0.1760922);
   _reco_per_true->SetContourLevel(147,0.1772983);
   _reco_per_true->SetContourLevel(148,0.1785044);
   _reco_per_true->SetContourLevel(149,0.1797105);
   _reco_per_true->SetContourLevel(150,0.1809166);
   _reco_per_true->SetContourLevel(151,0.1821227);
   _reco_per_true->SetContourLevel(152,0.1833288);
   _reco_per_true->SetContourLevel(153,0.1845349);
   _reco_per_true->SetContourLevel(154,0.185741);
   _reco_per_true->SetContourLevel(155,0.1869471);
   _reco_per_true->SetContourLevel(156,0.1881533);
   _reco_per_true->SetContourLevel(157,0.1893594);
   _reco_per_true->SetContourLevel(158,0.1905655);
   _reco_per_true->SetContourLevel(159,0.1917716);
   _reco_per_true->SetContourLevel(160,0.1929777);
   _reco_per_true->SetContourLevel(161,0.1941838);
   _reco_per_true->SetContourLevel(162,0.1953899);
   _reco_per_true->SetContourLevel(163,0.196596);
   _reco_per_true->SetContourLevel(164,0.1978021);
   _reco_per_true->SetContourLevel(165,0.1990083);
   _reco_per_true->SetContourLevel(166,0.2002144);
   _reco_per_true->SetContourLevel(167,0.2014205);
   _reco_per_true->SetContourLevel(168,0.2026266);
   _reco_per_true->SetContourLevel(169,0.2038327);
   _reco_per_true->SetContourLevel(170,0.2050388);
   _reco_per_true->SetContourLevel(171,0.2062449);
   _reco_per_true->SetContourLevel(172,0.207451);
   _reco_per_true->SetContourLevel(173,0.2086571);
   _reco_per_true->SetContourLevel(174,0.2098632);
   _reco_per_true->SetContourLevel(175,0.2110694);
   _reco_per_true->SetContourLevel(176,0.2122755);
   _reco_per_true->SetContourLevel(177,0.2134816);
   _reco_per_true->SetContourLevel(178,0.2146877);
   _reco_per_true->SetContourLevel(179,0.2158938);
   _reco_per_true->SetContourLevel(180,0.2170999);
   _reco_per_true->SetContourLevel(181,0.218306);
   _reco_per_true->SetContourLevel(182,0.2195121);
   _reco_per_true->SetContourLevel(183,0.2207182);
   _reco_per_true->SetContourLevel(184,0.2219244);
   _reco_per_true->SetContourLevel(185,0.2231305);
   _reco_per_true->SetContourLevel(186,0.2243366);
   _reco_per_true->SetContourLevel(187,0.2255427);
   _reco_per_true->SetContourLevel(188,0.2267488);
   _reco_per_true->SetContourLevel(189,0.2279549);
   _reco_per_true->SetContourLevel(190,0.229161);
   _reco_per_true->SetContourLevel(191,0.2303671);
   _reco_per_true->SetContourLevel(192,0.2315732);
   _reco_per_true->SetContourLevel(193,0.2327794);
   _reco_per_true->SetContourLevel(194,0.2339855);
   _reco_per_true->SetContourLevel(195,0.2351916);
   _reco_per_true->SetContourLevel(196,0.2363977);
   _reco_per_true->SetContourLevel(197,0.2376038);
   _reco_per_true->SetContourLevel(198,0.2388099);
   _reco_per_true->SetContourLevel(199,0.240016);
   _reco_per_true->SetContourLevel(200,0.2412221);
   _reco_per_true->SetContourLevel(201,0.2424282);
   _reco_per_true->SetContourLevel(202,0.2436343);
   _reco_per_true->SetContourLevel(203,0.2448405);
   _reco_per_true->SetContourLevel(204,0.2460466);
   _reco_per_true->SetContourLevel(205,0.2472527);
   _reco_per_true->SetContourLevel(206,0.2484588);
   _reco_per_true->SetContourLevel(207,0.2496649);
   _reco_per_true->SetContourLevel(208,0.250871);
   _reco_per_true->SetContourLevel(209,0.2520771);
   _reco_per_true->SetContourLevel(210,0.2532832);
   _reco_per_true->SetContourLevel(211,0.2544893);
   _reco_per_true->SetContourLevel(212,0.2556955);
   _reco_per_true->SetContourLevel(213,0.2569016);
   _reco_per_true->SetContourLevel(214,0.2581077);
   _reco_per_true->SetContourLevel(215,0.2593138);
   _reco_per_true->SetContourLevel(216,0.2605199);
   _reco_per_true->SetContourLevel(217,0.261726);
   _reco_per_true->SetContourLevel(218,0.2629321);
   _reco_per_true->SetContourLevel(219,0.2641382);
   _reco_per_true->SetContourLevel(220,0.2653443);
   _reco_per_true->SetContourLevel(221,0.2665504);
   _reco_per_true->SetContourLevel(222,0.2677566);
   _reco_per_true->SetContourLevel(223,0.2689627);
   _reco_per_true->SetContourLevel(224,0.2701688);
   _reco_per_true->SetContourLevel(225,0.2713749);
   _reco_per_true->SetContourLevel(226,0.272581);
   _reco_per_true->SetContourLevel(227,0.2737871);
   _reco_per_true->SetContourLevel(228,0.2749932);
   _reco_per_true->SetContourLevel(229,0.2761993);
   _reco_per_true->SetContourLevel(230,0.2774054);
   _reco_per_true->SetContourLevel(231,0.2786116);
   _reco_per_true->SetContourLevel(232,0.2798177);
   _reco_per_true->SetContourLevel(233,0.2810238);
   _reco_per_true->SetContourLevel(234,0.2822299);
   _reco_per_true->SetContourLevel(235,0.283436);
   _reco_per_true->SetContourLevel(236,0.2846421);
   _reco_per_true->SetContourLevel(237,0.2858482);
   _reco_per_true->SetContourLevel(238,0.2870543);
   _reco_per_true->SetContourLevel(239,0.2882604);
   _reco_per_true->SetContourLevel(240,0.2894665);
   _reco_per_true->SetContourLevel(241,0.2906727);
   _reco_per_true->SetContourLevel(242,0.2918788);
   _reco_per_true->SetContourLevel(243,0.2930849);
   _reco_per_true->SetContourLevel(244,0.294291);
   _reco_per_true->SetContourLevel(245,0.2954971);
   _reco_per_true->SetContourLevel(246,0.2967032);
   _reco_per_true->SetContourLevel(247,0.2979093);
   _reco_per_true->SetContourLevel(248,0.2991154);
   _reco_per_true->SetContourLevel(249,0.3003215);
   _reco_per_true->SetContourLevel(250,0.3015277);
   _reco_per_true->SetContourLevel(251,0.3027338);
   _reco_per_true->SetContourLevel(252,0.3039399);
   _reco_per_true->SetContourLevel(253,0.305146);
   _reco_per_true->SetContourLevel(254,0.3063521);
   
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
   TText *AText = pt->AddText("True Bin 25");
   pt->Draw();
   c1_n26->Modified();
   c1_n26->cd();
   c1_n26->SetSelected(c1_n26);
}

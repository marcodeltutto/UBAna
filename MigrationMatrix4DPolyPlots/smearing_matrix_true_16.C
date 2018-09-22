void smearing_matrix_true_16()
{
//=========Macro generated from canvas: c1_n17/c1_n17
//=========  (Sat Sep 22 12:03:56 2018) by ROOT version6.06/06
   TCanvas *c1_n17 = new TCanvas("c1_n17", "c1_n17",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n17->SetHighLightColor(2);
   c1_n17->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n17->SetFillColor(10);
   c1_n17->SetBorderMode(0);
   c1_n17->SetBorderSize(2);
   c1_n17->SetFrameLineWidth(2);
   c1_n17->SetFrameBorderMode(0);
   c1_n17->SetFrameLineWidth(2);
   c1_n17->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 16", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx497[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy497[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx497,Graph_fy497);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph497 = new TH1F("Graph_Graph497","Graph",100,-1.1,0);
   Graph_Graph497->SetMinimum(0);
   Graph_Graph497->SetMaximum(0.33);
   Graph_Graph497->SetDirectory(0);
   Graph_Graph497->SetStats(0);
   Graph_Graph497->SetLineWidth(2);
   Graph_Graph497->GetXaxis()->SetNdivisions(506);
   Graph_Graph497->GetXaxis()->SetLabelFont(42);
   Graph_Graph497->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph497->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph497->GetXaxis()->SetTitleFont(42);
   Graph_Graph497->GetYaxis()->SetNdivisions(506);
   Graph_Graph497->GetYaxis()->SetLabelFont(42);
   Graph_Graph497->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph497->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph497->GetYaxis()->SetTitleFont(42);
   Graph_Graph497->GetZaxis()->SetNdivisions(506);
   Graph_Graph497->GetZaxis()->SetLabelFont(42);
   Graph_Graph497->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph497->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph497->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph497);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx498[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy498[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx498,Graph_fy498);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph498 = new TH1F("Graph_Graph498","Graph",100,0,0.297);
   Graph_Graph498->SetMinimum(0);
   Graph_Graph498->SetMaximum(0.33);
   Graph_Graph498->SetDirectory(0);
   Graph_Graph498->SetStats(0);
   Graph_Graph498->SetLineWidth(2);
   Graph_Graph498->GetXaxis()->SetNdivisions(506);
   Graph_Graph498->GetXaxis()->SetLabelFont(42);
   Graph_Graph498->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph498->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph498->GetXaxis()->SetTitleFont(42);
   Graph_Graph498->GetYaxis()->SetNdivisions(506);
   Graph_Graph498->GetYaxis()->SetLabelFont(42);
   Graph_Graph498->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph498->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph498->GetYaxis()->SetTitleFont(42);
   Graph_Graph498->GetZaxis()->SetNdivisions(506);
   Graph_Graph498->GetZaxis()->SetLabelFont(42);
   Graph_Graph498->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph498->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph498->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph498);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx499[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy499[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx499,Graph_fy499);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph499 = new TH1F("Graph_Graph499","Graph",100,0.252,0.468);
   Graph_Graph499->SetMinimum(0);
   Graph_Graph499->SetMaximum(0.33);
   Graph_Graph499->SetDirectory(0);
   Graph_Graph499->SetStats(0);
   Graph_Graph499->SetLineWidth(2);
   Graph_Graph499->GetXaxis()->SetNdivisions(506);
   Graph_Graph499->GetXaxis()->SetLabelFont(42);
   Graph_Graph499->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph499->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph499->GetXaxis()->SetTitleFont(42);
   Graph_Graph499->GetYaxis()->SetNdivisions(506);
   Graph_Graph499->GetYaxis()->SetLabelFont(42);
   Graph_Graph499->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph499->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph499->GetYaxis()->SetTitleFont(42);
   Graph_Graph499->GetZaxis()->SetNdivisions(506);
   Graph_Graph499->GetZaxis()->SetLabelFont(42);
   Graph_Graph499->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph499->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph499->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph499);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx500[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy500[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx500,Graph_fy500);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph500 = new TH1F("Graph_Graph500","Graph",100,0.433,0.637);
   Graph_Graph500->SetMinimum(0);
   Graph_Graph500->SetMaximum(0.33);
   Graph_Graph500->SetDirectory(0);
   Graph_Graph500->SetStats(0);
   Graph_Graph500->SetLineWidth(2);
   Graph_Graph500->GetXaxis()->SetNdivisions(506);
   Graph_Graph500->GetXaxis()->SetLabelFont(42);
   Graph_Graph500->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph500->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph500->GetXaxis()->SetTitleFont(42);
   Graph_Graph500->GetYaxis()->SetNdivisions(506);
   Graph_Graph500->GetYaxis()->SetLabelFont(42);
   Graph_Graph500->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph500->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph500->GetYaxis()->SetTitleFont(42);
   Graph_Graph500->GetZaxis()->SetNdivisions(506);
   Graph_Graph500->GetZaxis()->SetLabelFont(42);
   Graph_Graph500->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph500->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph500->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph500);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx501[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy501[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx501,Graph_fy501);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph501 = new TH1F("Graph_Graph501","Graph",100,0.606,0.774);
   Graph_Graph501->SetMinimum(0);
   Graph_Graph501->SetMaximum(0.33);
   Graph_Graph501->SetDirectory(0);
   Graph_Graph501->SetStats(0);
   Graph_Graph501->SetLineWidth(2);
   Graph_Graph501->GetXaxis()->SetNdivisions(506);
   Graph_Graph501->GetXaxis()->SetLabelFont(42);
   Graph_Graph501->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph501->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph501->GetXaxis()->SetTitleFont(42);
   Graph_Graph501->GetYaxis()->SetNdivisions(506);
   Graph_Graph501->GetYaxis()->SetLabelFont(42);
   Graph_Graph501->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph501->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph501->GetYaxis()->SetTitleFont(42);
   Graph_Graph501->GetZaxis()->SetNdivisions(506);
   Graph_Graph501->GetZaxis()->SetLabelFont(42);
   Graph_Graph501->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph501->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph501->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph501);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx502[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy502[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx502,Graph_fy502);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph502 = new TH1F("Graph_Graph502","Graph",100,0.75,0.87);
   Graph_Graph502->SetMinimum(0);
   Graph_Graph502->SetMaximum(0.33);
   Graph_Graph502->SetDirectory(0);
   Graph_Graph502->SetStats(0);
   Graph_Graph502->SetLineWidth(2);
   Graph_Graph502->GetXaxis()->SetNdivisions(506);
   Graph_Graph502->GetXaxis()->SetLabelFont(42);
   Graph_Graph502->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph502->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph502->GetXaxis()->SetTitleFont(42);
   Graph_Graph502->GetYaxis()->SetNdivisions(506);
   Graph_Graph502->GetYaxis()->SetLabelFont(42);
   Graph_Graph502->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph502->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph502->GetYaxis()->SetTitleFont(42);
   Graph_Graph502->GetZaxis()->SetNdivisions(506);
   Graph_Graph502->GetZaxis()->SetLabelFont(42);
   Graph_Graph502->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph502->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph502->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph502);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx503[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy503[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx503,Graph_fy503);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph503 = new TH1F("Graph_Graph503","Graph",100,0.852,0.948);
   Graph_Graph503->SetMinimum(0);
   Graph_Graph503->SetMaximum(0.33);
   Graph_Graph503->SetDirectory(0);
   Graph_Graph503->SetStats(0);
   Graph_Graph503->SetLineWidth(2);
   Graph_Graph503->GetXaxis()->SetNdivisions(506);
   Graph_Graph503->GetXaxis()->SetLabelFont(42);
   Graph_Graph503->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph503->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph503->GetXaxis()->SetTitleFont(42);
   Graph_Graph503->GetYaxis()->SetNdivisions(506);
   Graph_Graph503->GetYaxis()->SetLabelFont(42);
   Graph_Graph503->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph503->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph503->GetYaxis()->SetTitleFont(42);
   Graph_Graph503->GetZaxis()->SetNdivisions(506);
   Graph_Graph503->GetZaxis()->SetLabelFont(42);
   Graph_Graph503->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph503->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph503->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph503);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx504[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy504[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx504,Graph_fy504);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph504 = new TH1F("Graph_Graph504","Graph",100,0.934,1.006);
   Graph_Graph504->SetMinimum(0);
   Graph_Graph504->SetMaximum(0.33);
   Graph_Graph504->SetDirectory(0);
   Graph_Graph504->SetStats(0);
   Graph_Graph504->SetLineWidth(2);
   Graph_Graph504->GetXaxis()->SetNdivisions(506);
   Graph_Graph504->GetXaxis()->SetLabelFont(42);
   Graph_Graph504->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph504->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph504->GetXaxis()->SetTitleFont(42);
   Graph_Graph504->GetYaxis()->SetNdivisions(506);
   Graph_Graph504->GetYaxis()->SetLabelFont(42);
   Graph_Graph504->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph504->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph504->GetYaxis()->SetTitleFont(42);
   Graph_Graph504->GetZaxis()->SetNdivisions(506);
   Graph_Graph504->GetZaxis()->SetLabelFont(42);
   Graph_Graph504->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph504->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph504->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph504);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx505[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy505[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx505,Graph_fy505);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#10d2ee");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph505 = new TH1F("Graph_Graph505","Graph",100,-1.1,0);
   Graph_Graph505->SetMinimum(0.285);
   Graph_Graph505->SetMaximum(0.465);
   Graph_Graph505->SetDirectory(0);
   Graph_Graph505->SetStats(0);
   Graph_Graph505->SetLineWidth(2);
   Graph_Graph505->GetXaxis()->SetNdivisions(506);
   Graph_Graph505->GetXaxis()->SetLabelFont(42);
   Graph_Graph505->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph505->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph505->GetXaxis()->SetTitleFont(42);
   Graph_Graph505->GetYaxis()->SetNdivisions(506);
   Graph_Graph505->GetYaxis()->SetLabelFont(42);
   Graph_Graph505->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph505->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph505->GetYaxis()->SetTitleFont(42);
   Graph_Graph505->GetZaxis()->SetNdivisions(506);
   Graph_Graph505->GetZaxis()->SetLabelFont(42);
   Graph_Graph505->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph505->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph505->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph505);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx506[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy506[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx506,Graph_fy506);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0040a9");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph506 = new TH1F("Graph_Graph506","Graph",100,0,0.297);
   Graph_Graph506->SetMinimum(0.285);
   Graph_Graph506->SetMaximum(0.465);
   Graph_Graph506->SetDirectory(0);
   Graph_Graph506->SetStats(0);
   Graph_Graph506->SetLineWidth(2);
   Graph_Graph506->GetXaxis()->SetNdivisions(506);
   Graph_Graph506->GetXaxis()->SetLabelFont(42);
   Graph_Graph506->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph506->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph506->GetXaxis()->SetTitleFont(42);
   Graph_Graph506->GetYaxis()->SetNdivisions(506);
   Graph_Graph506->GetYaxis()->SetLabelFont(42);
   Graph_Graph506->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph506->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph506->GetYaxis()->SetTitleFont(42);
   Graph_Graph506->GetZaxis()->SetNdivisions(506);
   Graph_Graph506->GetZaxis()->SetLabelFont(42);
   Graph_Graph506->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph506->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph506->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph506);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx507[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy507[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx507,Graph_fy507);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph507 = new TH1F("Graph_Graph507","Graph",100,0.252,0.468);
   Graph_Graph507->SetMinimum(0.285);
   Graph_Graph507->SetMaximum(0.465);
   Graph_Graph507->SetDirectory(0);
   Graph_Graph507->SetStats(0);
   Graph_Graph507->SetLineWidth(2);
   Graph_Graph507->GetXaxis()->SetNdivisions(506);
   Graph_Graph507->GetXaxis()->SetLabelFont(42);
   Graph_Graph507->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph507->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph507->GetXaxis()->SetTitleFont(42);
   Graph_Graph507->GetYaxis()->SetNdivisions(506);
   Graph_Graph507->GetYaxis()->SetLabelFont(42);
   Graph_Graph507->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph507->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph507->GetYaxis()->SetTitleFont(42);
   Graph_Graph507->GetZaxis()->SetNdivisions(506);
   Graph_Graph507->GetZaxis()->SetLabelFont(42);
   Graph_Graph507->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph507->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph507->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph507);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx508[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy508[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx508,Graph_fy508);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph508 = new TH1F("Graph_Graph508","Graph",100,0.433,0.637);
   Graph_Graph508->SetMinimum(0.285);
   Graph_Graph508->SetMaximum(0.465);
   Graph_Graph508->SetDirectory(0);
   Graph_Graph508->SetStats(0);
   Graph_Graph508->SetLineWidth(2);
   Graph_Graph508->GetXaxis()->SetNdivisions(506);
   Graph_Graph508->GetXaxis()->SetLabelFont(42);
   Graph_Graph508->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph508->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph508->GetXaxis()->SetTitleFont(42);
   Graph_Graph508->GetYaxis()->SetNdivisions(506);
   Graph_Graph508->GetYaxis()->SetLabelFont(42);
   Graph_Graph508->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph508->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph508->GetYaxis()->SetTitleFont(42);
   Graph_Graph508->GetZaxis()->SetNdivisions(506);
   Graph_Graph508->GetZaxis()->SetLabelFont(42);
   Graph_Graph508->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph508->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph508->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph508);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx509[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy509[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx509,Graph_fy509);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph509 = new TH1F("Graph_Graph509","Graph",100,0.606,0.774);
   Graph_Graph509->SetMinimum(0.285);
   Graph_Graph509->SetMaximum(0.465);
   Graph_Graph509->SetDirectory(0);
   Graph_Graph509->SetStats(0);
   Graph_Graph509->SetLineWidth(2);
   Graph_Graph509->GetXaxis()->SetNdivisions(506);
   Graph_Graph509->GetXaxis()->SetLabelFont(42);
   Graph_Graph509->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph509->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph509->GetXaxis()->SetTitleFont(42);
   Graph_Graph509->GetYaxis()->SetNdivisions(506);
   Graph_Graph509->GetYaxis()->SetLabelFont(42);
   Graph_Graph509->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph509->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph509->GetYaxis()->SetTitleFont(42);
   Graph_Graph509->GetZaxis()->SetNdivisions(506);
   Graph_Graph509->GetZaxis()->SetLabelFont(42);
   Graph_Graph509->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph509->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph509->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph509);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx510[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy510[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx510,Graph_fy510);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph510 = new TH1F("Graph_Graph510","Graph",100,0.75,0.87);
   Graph_Graph510->SetMinimum(0.285);
   Graph_Graph510->SetMaximum(0.465);
   Graph_Graph510->SetDirectory(0);
   Graph_Graph510->SetStats(0);
   Graph_Graph510->SetLineWidth(2);
   Graph_Graph510->GetXaxis()->SetNdivisions(506);
   Graph_Graph510->GetXaxis()->SetLabelFont(42);
   Graph_Graph510->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph510->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph510->GetXaxis()->SetTitleFont(42);
   Graph_Graph510->GetYaxis()->SetNdivisions(506);
   Graph_Graph510->GetYaxis()->SetLabelFont(42);
   Graph_Graph510->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph510->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph510->GetYaxis()->SetTitleFont(42);
   Graph_Graph510->GetZaxis()->SetNdivisions(506);
   Graph_Graph510->GetZaxis()->SetLabelFont(42);
   Graph_Graph510->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph510->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph510->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph510);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx511[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy511[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx511,Graph_fy511);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002b9c");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph511 = new TH1F("Graph_Graph511","Graph",100,0.852,0.948);
   Graph_Graph511->SetMinimum(0.285);
   Graph_Graph511->SetMaximum(0.465);
   Graph_Graph511->SetDirectory(0);
   Graph_Graph511->SetStats(0);
   Graph_Graph511->SetLineWidth(2);
   Graph_Graph511->GetXaxis()->SetNdivisions(506);
   Graph_Graph511->GetXaxis()->SetLabelFont(42);
   Graph_Graph511->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph511->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph511->GetXaxis()->SetTitleFont(42);
   Graph_Graph511->GetYaxis()->SetNdivisions(506);
   Graph_Graph511->GetYaxis()->SetLabelFont(42);
   Graph_Graph511->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph511->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph511->GetYaxis()->SetTitleFont(42);
   Graph_Graph511->GetZaxis()->SetNdivisions(506);
   Graph_Graph511->GetZaxis()->SetLabelFont(42);
   Graph_Graph511->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph511->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph511->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph511);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx512[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy512[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx512,Graph_fy512);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph512 = new TH1F("Graph_Graph512","Graph",100,0.934,1.006);
   Graph_Graph512->SetMinimum(0.285);
   Graph_Graph512->SetMaximum(0.465);
   Graph_Graph512->SetDirectory(0);
   Graph_Graph512->SetStats(0);
   Graph_Graph512->SetLineWidth(2);
   Graph_Graph512->GetXaxis()->SetNdivisions(506);
   Graph_Graph512->GetXaxis()->SetLabelFont(42);
   Graph_Graph512->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph512->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph512->GetXaxis()->SetTitleFont(42);
   Graph_Graph512->GetYaxis()->SetNdivisions(506);
   Graph_Graph512->GetYaxis()->SetLabelFont(42);
   Graph_Graph512->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph512->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph512->GetYaxis()->SetTitleFont(42);
   Graph_Graph512->GetZaxis()->SetNdivisions(506);
   Graph_Graph512->GetZaxis()->SetLabelFont(42);
   Graph_Graph512->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph512->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph512->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph512);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx513[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy513[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx513,Graph_fy513);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph513 = new TH1F("Graph_Graph513","Graph",100,-1.1,0);
   Graph_Graph513->SetMinimum(0.245);
   Graph_Graph513->SetMaximum(2.705);
   Graph_Graph513->SetDirectory(0);
   Graph_Graph513->SetStats(0);
   Graph_Graph513->SetLineWidth(2);
   Graph_Graph513->GetXaxis()->SetNdivisions(506);
   Graph_Graph513->GetXaxis()->SetLabelFont(42);
   Graph_Graph513->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph513->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph513->GetXaxis()->SetTitleFont(42);
   Graph_Graph513->GetYaxis()->SetNdivisions(506);
   Graph_Graph513->GetYaxis()->SetLabelFont(42);
   Graph_Graph513->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph513->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph513->GetYaxis()->SetTitleFont(42);
   Graph_Graph513->GetZaxis()->SetNdivisions(506);
   Graph_Graph513->GetZaxis()->SetLabelFont(42);
   Graph_Graph513->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph513->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph513->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph513);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx514[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy514[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx514,Graph_fy514);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00afec");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph514 = new TH1F("Graph_Graph514","Graph",100,0,0.297);
   Graph_Graph514->SetMinimum(0.418);
   Graph_Graph514->SetMaximum(0.802);
   Graph_Graph514->SetDirectory(0);
   Graph_Graph514->SetStats(0);
   Graph_Graph514->SetLineWidth(2);
   Graph_Graph514->GetXaxis()->SetNdivisions(506);
   Graph_Graph514->GetXaxis()->SetLabelFont(42);
   Graph_Graph514->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph514->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph514->GetXaxis()->SetTitleFont(42);
   Graph_Graph514->GetYaxis()->SetNdivisions(506);
   Graph_Graph514->GetYaxis()->SetLabelFont(42);
   Graph_Graph514->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph514->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph514->GetYaxis()->SetTitleFont(42);
   Graph_Graph514->GetZaxis()->SetNdivisions(506);
   Graph_Graph514->GetZaxis()->SetLabelFont(42);
   Graph_Graph514->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph514->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph514->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph514);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx515[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy515[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx515,Graph_fy515);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph515 = new TH1F("Graph_Graph515","Graph",100,0.252,0.468);
   Graph_Graph515->SetMinimum(0.418);
   Graph_Graph515->SetMaximum(0.802);
   Graph_Graph515->SetDirectory(0);
   Graph_Graph515->SetStats(0);
   Graph_Graph515->SetLineWidth(2);
   Graph_Graph515->GetXaxis()->SetNdivisions(506);
   Graph_Graph515->GetXaxis()->SetLabelFont(42);
   Graph_Graph515->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph515->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph515->GetXaxis()->SetTitleFont(42);
   Graph_Graph515->GetYaxis()->SetNdivisions(506);
   Graph_Graph515->GetYaxis()->SetLabelFont(42);
   Graph_Graph515->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph515->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph515->GetYaxis()->SetTitleFont(42);
   Graph_Graph515->GetZaxis()->SetNdivisions(506);
   Graph_Graph515->GetZaxis()->SetLabelFont(42);
   Graph_Graph515->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph515->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph515->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph515);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx516[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy516[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx516,Graph_fy516);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00289a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph516 = new TH1F("Graph_Graph516","Graph",100,0.433,0.637);
   Graph_Graph516->SetMinimum(0.418);
   Graph_Graph516->SetMaximum(0.802);
   Graph_Graph516->SetDirectory(0);
   Graph_Graph516->SetStats(0);
   Graph_Graph516->SetLineWidth(2);
   Graph_Graph516->GetXaxis()->SetNdivisions(506);
   Graph_Graph516->GetXaxis()->SetLabelFont(42);
   Graph_Graph516->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph516->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph516->GetXaxis()->SetTitleFont(42);
   Graph_Graph516->GetYaxis()->SetNdivisions(506);
   Graph_Graph516->GetYaxis()->SetLabelFont(42);
   Graph_Graph516->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph516->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph516->GetYaxis()->SetTitleFont(42);
   Graph_Graph516->GetZaxis()->SetNdivisions(506);
   Graph_Graph516->GetZaxis()->SetLabelFont(42);
   Graph_Graph516->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph516->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph516->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph516);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx517[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy517[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx517,Graph_fy517);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph517 = new TH1F("Graph_Graph517","Graph",100,0.606,0.774);
   Graph_Graph517->SetMinimum(0.418);
   Graph_Graph517->SetMaximum(0.802);
   Graph_Graph517->SetDirectory(0);
   Graph_Graph517->SetStats(0);
   Graph_Graph517->SetLineWidth(2);
   Graph_Graph517->GetXaxis()->SetNdivisions(506);
   Graph_Graph517->GetXaxis()->SetLabelFont(42);
   Graph_Graph517->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph517->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph517->GetXaxis()->SetTitleFont(42);
   Graph_Graph517->GetYaxis()->SetNdivisions(506);
   Graph_Graph517->GetYaxis()->SetLabelFont(42);
   Graph_Graph517->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph517->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph517->GetYaxis()->SetTitleFont(42);
   Graph_Graph517->GetZaxis()->SetNdivisions(506);
   Graph_Graph517->GetZaxis()->SetLabelFont(42);
   Graph_Graph517->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph517->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph517->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph517);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx518[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy518[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx518,Graph_fy518);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph518 = new TH1F("Graph_Graph518","Graph",100,0.75,0.87);
   Graph_Graph518->SetMinimum(0.418);
   Graph_Graph518->SetMaximum(0.802);
   Graph_Graph518->SetDirectory(0);
   Graph_Graph518->SetStats(0);
   Graph_Graph518->SetLineWidth(2);
   Graph_Graph518->GetXaxis()->SetNdivisions(506);
   Graph_Graph518->GetXaxis()->SetLabelFont(42);
   Graph_Graph518->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph518->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph518->GetXaxis()->SetTitleFont(42);
   Graph_Graph518->GetYaxis()->SetNdivisions(506);
   Graph_Graph518->GetYaxis()->SetLabelFont(42);
   Graph_Graph518->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph518->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph518->GetYaxis()->SetTitleFont(42);
   Graph_Graph518->GetZaxis()->SetNdivisions(506);
   Graph_Graph518->GetZaxis()->SetLabelFont(42);
   Graph_Graph518->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph518->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph518->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph518);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx519[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy519[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx519,Graph_fy519);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00138d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph519 = new TH1F("Graph_Graph519","Graph",100,0.852,0.948);
   Graph_Graph519->SetMinimum(0.418);
   Graph_Graph519->SetMaximum(0.802);
   Graph_Graph519->SetDirectory(0);
   Graph_Graph519->SetStats(0);
   Graph_Graph519->SetLineWidth(2);
   Graph_Graph519->GetXaxis()->SetNdivisions(506);
   Graph_Graph519->GetXaxis()->SetLabelFont(42);
   Graph_Graph519->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph519->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph519->GetXaxis()->SetTitleFont(42);
   Graph_Graph519->GetYaxis()->SetNdivisions(506);
   Graph_Graph519->GetYaxis()->SetLabelFont(42);
   Graph_Graph519->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph519->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph519->GetYaxis()->SetTitleFont(42);
   Graph_Graph519->GetZaxis()->SetNdivisions(506);
   Graph_Graph519->GetZaxis()->SetLabelFont(42);
   Graph_Graph519->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph519->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph519->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph519);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx520[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy520[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx520,Graph_fy520);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph520 = new TH1F("Graph_Graph520","Graph",100,0.934,1.006);
   Graph_Graph520->SetMinimum(0.418);
   Graph_Graph520->SetMaximum(0.802);
   Graph_Graph520->SetDirectory(0);
   Graph_Graph520->SetStats(0);
   Graph_Graph520->SetLineWidth(2);
   Graph_Graph520->GetXaxis()->SetNdivisions(506);
   Graph_Graph520->GetXaxis()->SetLabelFont(42);
   Graph_Graph520->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph520->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph520->GetXaxis()->SetTitleFont(42);
   Graph_Graph520->GetYaxis()->SetNdivisions(506);
   Graph_Graph520->GetYaxis()->SetLabelFont(42);
   Graph_Graph520->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph520->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph520->GetYaxis()->SetTitleFont(42);
   Graph_Graph520->GetZaxis()->SetNdivisions(506);
   Graph_Graph520->GetZaxis()->SetLabelFont(42);
   Graph_Graph520->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph520->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph520->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph520);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx521[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy521[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx521,Graph_fy521);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph521 = new TH1F("Graph_Graph521","Graph",100,0,0.297);
   Graph_Graph521->SetMinimum(0.597);
   Graph_Graph521->SetMaximum(2.673);
   Graph_Graph521->SetDirectory(0);
   Graph_Graph521->SetStats(0);
   Graph_Graph521->SetLineWidth(2);
   Graph_Graph521->GetXaxis()->SetNdivisions(506);
   Graph_Graph521->GetXaxis()->SetLabelFont(42);
   Graph_Graph521->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph521->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph521->GetXaxis()->SetTitleFont(42);
   Graph_Graph521->GetYaxis()->SetNdivisions(506);
   Graph_Graph521->GetYaxis()->SetLabelFont(42);
   Graph_Graph521->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph521->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph521->GetYaxis()->SetTitleFont(42);
   Graph_Graph521->GetZaxis()->SetNdivisions(506);
   Graph_Graph521->GetZaxis()->SetLabelFont(42);
   Graph_Graph521->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph521->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph521->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph521);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx522[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy522[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx522,Graph_fy522);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph522 = new TH1F("Graph_Graph522","Graph",100,0.252,0.468);
   Graph_Graph522->SetMinimum(0.597);
   Graph_Graph522->SetMaximum(2.673);
   Graph_Graph522->SetDirectory(0);
   Graph_Graph522->SetStats(0);
   Graph_Graph522->SetLineWidth(2);
   Graph_Graph522->GetXaxis()->SetNdivisions(506);
   Graph_Graph522->GetXaxis()->SetLabelFont(42);
   Graph_Graph522->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph522->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph522->GetXaxis()->SetTitleFont(42);
   Graph_Graph522->GetYaxis()->SetNdivisions(506);
   Graph_Graph522->GetYaxis()->SetLabelFont(42);
   Graph_Graph522->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph522->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph522->GetYaxis()->SetTitleFont(42);
   Graph_Graph522->GetZaxis()->SetNdivisions(506);
   Graph_Graph522->GetZaxis()->SetLabelFont(42);
   Graph_Graph522->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph522->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph522->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph522);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx523[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy523[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx523,Graph_fy523);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph523 = new TH1F("Graph_Graph523","Graph",100,0.433,0.637);
   Graph_Graph523->SetMinimum(0.597);
   Graph_Graph523->SetMaximum(2.673);
   Graph_Graph523->SetDirectory(0);
   Graph_Graph523->SetStats(0);
   Graph_Graph523->SetLineWidth(2);
   Graph_Graph523->GetXaxis()->SetNdivisions(506);
   Graph_Graph523->GetXaxis()->SetLabelFont(42);
   Graph_Graph523->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph523->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph523->GetXaxis()->SetTitleFont(42);
   Graph_Graph523->GetYaxis()->SetNdivisions(506);
   Graph_Graph523->GetYaxis()->SetLabelFont(42);
   Graph_Graph523->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph523->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph523->GetYaxis()->SetTitleFont(42);
   Graph_Graph523->GetZaxis()->SetNdivisions(506);
   Graph_Graph523->GetZaxis()->SetLabelFont(42);
   Graph_Graph523->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph523->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph523->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph523);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx524[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy524[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx524,Graph_fy524);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00138d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph524 = new TH1F("Graph_Graph524","Graph",100,0.606,0.774);
   Graph_Graph524->SetMinimum(0.597);
   Graph_Graph524->SetMaximum(2.673);
   Graph_Graph524->SetDirectory(0);
   Graph_Graph524->SetStats(0);
   Graph_Graph524->SetLineWidth(2);
   Graph_Graph524->GetXaxis()->SetNdivisions(506);
   Graph_Graph524->GetXaxis()->SetLabelFont(42);
   Graph_Graph524->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph524->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph524->GetXaxis()->SetTitleFont(42);
   Graph_Graph524->GetYaxis()->SetNdivisions(506);
   Graph_Graph524->GetYaxis()->SetLabelFont(42);
   Graph_Graph524->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph524->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph524->GetYaxis()->SetTitleFont(42);
   Graph_Graph524->GetZaxis()->SetNdivisions(506);
   Graph_Graph524->GetZaxis()->SetLabelFont(42);
   Graph_Graph524->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph524->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph524->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph524);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx525[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy525[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx525,Graph_fy525);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph525 = new TH1F("Graph_Graph525","Graph",100,0.75,0.87);
   Graph_Graph525->SetMinimum(0.597);
   Graph_Graph525->SetMaximum(2.673);
   Graph_Graph525->SetDirectory(0);
   Graph_Graph525->SetStats(0);
   Graph_Graph525->SetLineWidth(2);
   Graph_Graph525->GetXaxis()->SetNdivisions(506);
   Graph_Graph525->GetXaxis()->SetLabelFont(42);
   Graph_Graph525->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph525->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph525->GetXaxis()->SetTitleFont(42);
   Graph_Graph525->GetYaxis()->SetNdivisions(506);
   Graph_Graph525->GetYaxis()->SetLabelFont(42);
   Graph_Graph525->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph525->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph525->GetYaxis()->SetTitleFont(42);
   Graph_Graph525->GetZaxis()->SetNdivisions(506);
   Graph_Graph525->GetZaxis()->SetLabelFont(42);
   Graph_Graph525->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph525->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph525->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph525);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx526[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy526[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx526,Graph_fy526);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph526 = new TH1F("Graph_Graph526","Graph",100,0.852,0.948);
   Graph_Graph526->SetMinimum(0.597);
   Graph_Graph526->SetMaximum(2.673);
   Graph_Graph526->SetDirectory(0);
   Graph_Graph526->SetStats(0);
   Graph_Graph526->SetLineWidth(2);
   Graph_Graph526->GetXaxis()->SetNdivisions(506);
   Graph_Graph526->GetXaxis()->SetLabelFont(42);
   Graph_Graph526->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph526->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph526->GetXaxis()->SetTitleFont(42);
   Graph_Graph526->GetYaxis()->SetNdivisions(506);
   Graph_Graph526->GetYaxis()->SetLabelFont(42);
   Graph_Graph526->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph526->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph526->GetYaxis()->SetTitleFont(42);
   Graph_Graph526->GetZaxis()->SetNdivisions(506);
   Graph_Graph526->GetZaxis()->SetLabelFont(42);
   Graph_Graph526->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph526->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph526->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph526);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx527[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy527[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx527,Graph_fy527);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002b9c");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph527 = new TH1F("Graph_Graph527","Graph",100,0.934,1.006);
   Graph_Graph527->SetMinimum(0.597);
   Graph_Graph527->SetMaximum(2.673);
   Graph_Graph527->SetDirectory(0);
   Graph_Graph527->SetStats(0);
   Graph_Graph527->SetLineWidth(2);
   Graph_Graph527->GetXaxis()->SetNdivisions(506);
   Graph_Graph527->GetXaxis()->SetLabelFont(42);
   Graph_Graph527->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph527->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph527->GetXaxis()->SetTitleFont(42);
   Graph_Graph527->GetYaxis()->SetNdivisions(506);
   Graph_Graph527->GetYaxis()->SetLabelFont(42);
   Graph_Graph527->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph527->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph527->GetYaxis()->SetTitleFont(42);
   Graph_Graph527->GetZaxis()->SetNdivisions(506);
   Graph_Graph527->GetZaxis()->SetLabelFont(42);
   Graph_Graph527->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph527->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph527->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph527);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(2,0.01699896);
   _reco_per_true->SetBinContent(9,0.1701361);
   _reco_per_true->SetBinContent(10,0.05103636);
   _reco_per_true->SetBinContent(15,0.03405557);
   _reco_per_true->SetBinContent(17,0.4756915);
   _reco_per_true->SetBinContent(18,0.1362129);
   _reco_per_true->SetBinContent(20,0.03241067);
   _reco_per_true->SetBinContent(23,0.01643325);
   _reco_per_true->SetBinContent(24,0.01694167);
   _reco_per_true->SetBinContent(28,0.01610289);
   _reco_per_true->SetBinContent(31,0.0339802);
   _reco_per_true->SetBinError(2,0.01699896);
   _reco_per_true->SetBinError(9,0.05380227);
   _reco_per_true->SetBinError(10,0.02946588);
   _reco_per_true->SetBinError(15,0.02408103);
   _reco_per_true->SetBinError(17,0.08989768);
   _reco_per_true->SetBinError(18,0.04815858);
   _reco_per_true->SetBinError(20,0.02293458);
   _reco_per_true->SetBinError(23,0.01643325);
   _reco_per_true->SetBinError(24,0.01694167);
   _reco_per_true->SetBinError(28,0.01610289);
   _reco_per_true->SetBinError(31,0.02402773);
   _reco_per_true->SetEntries(59);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.001865457);
   _reco_per_true->SetContourLevel(2,0.003730913);
   _reco_per_true->SetContourLevel(3,0.00559637);
   _reco_per_true->SetContourLevel(4,0.007461827);
   _reco_per_true->SetContourLevel(5,0.009327284);
   _reco_per_true->SetContourLevel(6,0.01119274);
   _reco_per_true->SetContourLevel(7,0.0130582);
   _reco_per_true->SetContourLevel(8,0.01492365);
   _reco_per_true->SetContourLevel(9,0.01678911);
   _reco_per_true->SetContourLevel(10,0.01865457);
   _reco_per_true->SetContourLevel(11,0.02052002);
   _reco_per_true->SetContourLevel(12,0.02238548);
   _reco_per_true->SetContourLevel(13,0.02425094);
   _reco_per_true->SetContourLevel(14,0.02611639);
   _reco_per_true->SetContourLevel(15,0.02798185);
   _reco_per_true->SetContourLevel(16,0.02984731);
   _reco_per_true->SetContourLevel(17,0.03171276);
   _reco_per_true->SetContourLevel(18,0.03357822);
   _reco_per_true->SetContourLevel(19,0.03544368);
   _reco_per_true->SetContourLevel(20,0.03730913);
   _reco_per_true->SetContourLevel(21,0.03917459);
   _reco_per_true->SetContourLevel(22,0.04104005);
   _reco_per_true->SetContourLevel(23,0.04290551);
   _reco_per_true->SetContourLevel(24,0.04477096);
   _reco_per_true->SetContourLevel(25,0.04663642);
   _reco_per_true->SetContourLevel(26,0.04850188);
   _reco_per_true->SetContourLevel(27,0.05036733);
   _reco_per_true->SetContourLevel(28,0.05223279);
   _reco_per_true->SetContourLevel(29,0.05409825);
   _reco_per_true->SetContourLevel(30,0.0559637);
   _reco_per_true->SetContourLevel(31,0.05782916);
   _reco_per_true->SetContourLevel(32,0.05969462);
   _reco_per_true->SetContourLevel(33,0.06156007);
   _reco_per_true->SetContourLevel(34,0.06342553);
   _reco_per_true->SetContourLevel(35,0.06529099);
   _reco_per_true->SetContourLevel(36,0.06715644);
   _reco_per_true->SetContourLevel(37,0.0690219);
   _reco_per_true->SetContourLevel(38,0.07088736);
   _reco_per_true->SetContourLevel(39,0.07275281);
   _reco_per_true->SetContourLevel(40,0.07461827);
   _reco_per_true->SetContourLevel(41,0.07648373);
   _reco_per_true->SetContourLevel(42,0.07834918);
   _reco_per_true->SetContourLevel(43,0.08021464);
   _reco_per_true->SetContourLevel(44,0.0820801);
   _reco_per_true->SetContourLevel(45,0.08394555);
   _reco_per_true->SetContourLevel(46,0.08581101);
   _reco_per_true->SetContourLevel(47,0.08767647);
   _reco_per_true->SetContourLevel(48,0.08954192);
   _reco_per_true->SetContourLevel(49,0.09140738);
   _reco_per_true->SetContourLevel(50,0.09327284);
   _reco_per_true->SetContourLevel(51,0.09513829);
   _reco_per_true->SetContourLevel(52,0.09700375);
   _reco_per_true->SetContourLevel(53,0.09886921);
   _reco_per_true->SetContourLevel(54,0.1007347);
   _reco_per_true->SetContourLevel(55,0.1026001);
   _reco_per_true->SetContourLevel(56,0.1044656);
   _reco_per_true->SetContourLevel(57,0.106331);
   _reco_per_true->SetContourLevel(58,0.1081965);
   _reco_per_true->SetContourLevel(59,0.1100619);
   _reco_per_true->SetContourLevel(60,0.1119274);
   _reco_per_true->SetContourLevel(61,0.1137929);
   _reco_per_true->SetContourLevel(62,0.1156583);
   _reco_per_true->SetContourLevel(63,0.1175238);
   _reco_per_true->SetContourLevel(64,0.1193892);
   _reco_per_true->SetContourLevel(65,0.1212547);
   _reco_per_true->SetContourLevel(66,0.1231201);
   _reco_per_true->SetContourLevel(67,0.1249856);
   _reco_per_true->SetContourLevel(68,0.1268511);
   _reco_per_true->SetContourLevel(69,0.1287165);
   _reco_per_true->SetContourLevel(70,0.130582);
   _reco_per_true->SetContourLevel(71,0.1324474);
   _reco_per_true->SetContourLevel(72,0.1343129);
   _reco_per_true->SetContourLevel(73,0.1361783);
   _reco_per_true->SetContourLevel(74,0.1380438);
   _reco_per_true->SetContourLevel(75,0.1399093);
   _reco_per_true->SetContourLevel(76,0.1417747);
   _reco_per_true->SetContourLevel(77,0.1436402);
   _reco_per_true->SetContourLevel(78,0.1455056);
   _reco_per_true->SetContourLevel(79,0.1473711);
   _reco_per_true->SetContourLevel(80,0.1492365);
   _reco_per_true->SetContourLevel(81,0.151102);
   _reco_per_true->SetContourLevel(82,0.1529675);
   _reco_per_true->SetContourLevel(83,0.1548329);
   _reco_per_true->SetContourLevel(84,0.1566984);
   _reco_per_true->SetContourLevel(85,0.1585638);
   _reco_per_true->SetContourLevel(86,0.1604293);
   _reco_per_true->SetContourLevel(87,0.1622947);
   _reco_per_true->SetContourLevel(88,0.1641602);
   _reco_per_true->SetContourLevel(89,0.1660257);
   _reco_per_true->SetContourLevel(90,0.1678911);
   _reco_per_true->SetContourLevel(91,0.1697566);
   _reco_per_true->SetContourLevel(92,0.171622);
   _reco_per_true->SetContourLevel(93,0.1734875);
   _reco_per_true->SetContourLevel(94,0.1753529);
   _reco_per_true->SetContourLevel(95,0.1772184);
   _reco_per_true->SetContourLevel(96,0.1790838);
   _reco_per_true->SetContourLevel(97,0.1809493);
   _reco_per_true->SetContourLevel(98,0.1828148);
   _reco_per_true->SetContourLevel(99,0.1846802);
   _reco_per_true->SetContourLevel(100,0.1865457);
   _reco_per_true->SetContourLevel(101,0.1884111);
   _reco_per_true->SetContourLevel(102,0.1902766);
   _reco_per_true->SetContourLevel(103,0.192142);
   _reco_per_true->SetContourLevel(104,0.1940075);
   _reco_per_true->SetContourLevel(105,0.195873);
   _reco_per_true->SetContourLevel(106,0.1977384);
   _reco_per_true->SetContourLevel(107,0.1996039);
   _reco_per_true->SetContourLevel(108,0.2014693);
   _reco_per_true->SetContourLevel(109,0.2033348);
   _reco_per_true->SetContourLevel(110,0.2052002);
   _reco_per_true->SetContourLevel(111,0.2070657);
   _reco_per_true->SetContourLevel(112,0.2089312);
   _reco_per_true->SetContourLevel(113,0.2107966);
   _reco_per_true->SetContourLevel(114,0.2126621);
   _reco_per_true->SetContourLevel(115,0.2145275);
   _reco_per_true->SetContourLevel(116,0.216393);
   _reco_per_true->SetContourLevel(117,0.2182584);
   _reco_per_true->SetContourLevel(118,0.2201239);
   _reco_per_true->SetContourLevel(119,0.2219894);
   _reco_per_true->SetContourLevel(120,0.2238548);
   _reco_per_true->SetContourLevel(121,0.2257203);
   _reco_per_true->SetContourLevel(122,0.2275857);
   _reco_per_true->SetContourLevel(123,0.2294512);
   _reco_per_true->SetContourLevel(124,0.2313166);
   _reco_per_true->SetContourLevel(125,0.2331821);
   _reco_per_true->SetContourLevel(126,0.2350475);
   _reco_per_true->SetContourLevel(127,0.236913);
   _reco_per_true->SetContourLevel(128,0.2387785);
   _reco_per_true->SetContourLevel(129,0.2406439);
   _reco_per_true->SetContourLevel(130,0.2425094);
   _reco_per_true->SetContourLevel(131,0.2443748);
   _reco_per_true->SetContourLevel(132,0.2462403);
   _reco_per_true->SetContourLevel(133,0.2481057);
   _reco_per_true->SetContourLevel(134,0.2499712);
   _reco_per_true->SetContourLevel(135,0.2518367);
   _reco_per_true->SetContourLevel(136,0.2537021);
   _reco_per_true->SetContourLevel(137,0.2555676);
   _reco_per_true->SetContourLevel(138,0.257433);
   _reco_per_true->SetContourLevel(139,0.2592985);
   _reco_per_true->SetContourLevel(140,0.2611639);
   _reco_per_true->SetContourLevel(141,0.2630294);
   _reco_per_true->SetContourLevel(142,0.2648949);
   _reco_per_true->SetContourLevel(143,0.2667603);
   _reco_per_true->SetContourLevel(144,0.2686258);
   _reco_per_true->SetContourLevel(145,0.2704912);
   _reco_per_true->SetContourLevel(146,0.2723567);
   _reco_per_true->SetContourLevel(147,0.2742221);
   _reco_per_true->SetContourLevel(148,0.2760876);
   _reco_per_true->SetContourLevel(149,0.2779531);
   _reco_per_true->SetContourLevel(150,0.2798185);
   _reco_per_true->SetContourLevel(151,0.281684);
   _reco_per_true->SetContourLevel(152,0.2835494);
   _reco_per_true->SetContourLevel(153,0.2854149);
   _reco_per_true->SetContourLevel(154,0.2872803);
   _reco_per_true->SetContourLevel(155,0.2891458);
   _reco_per_true->SetContourLevel(156,0.2910113);
   _reco_per_true->SetContourLevel(157,0.2928767);
   _reco_per_true->SetContourLevel(158,0.2947422);
   _reco_per_true->SetContourLevel(159,0.2966076);
   _reco_per_true->SetContourLevel(160,0.2984731);
   _reco_per_true->SetContourLevel(161,0.3003385);
   _reco_per_true->SetContourLevel(162,0.302204);
   _reco_per_true->SetContourLevel(163,0.3040694);
   _reco_per_true->SetContourLevel(164,0.3059349);
   _reco_per_true->SetContourLevel(165,0.3078004);
   _reco_per_true->SetContourLevel(166,0.3096658);
   _reco_per_true->SetContourLevel(167,0.3115313);
   _reco_per_true->SetContourLevel(168,0.3133967);
   _reco_per_true->SetContourLevel(169,0.3152622);
   _reco_per_true->SetContourLevel(170,0.3171276);
   _reco_per_true->SetContourLevel(171,0.3189931);
   _reco_per_true->SetContourLevel(172,0.3208586);
   _reco_per_true->SetContourLevel(173,0.322724);
   _reco_per_true->SetContourLevel(174,0.3245895);
   _reco_per_true->SetContourLevel(175,0.3264549);
   _reco_per_true->SetContourLevel(176,0.3283204);
   _reco_per_true->SetContourLevel(177,0.3301858);
   _reco_per_true->SetContourLevel(178,0.3320513);
   _reco_per_true->SetContourLevel(179,0.3339168);
   _reco_per_true->SetContourLevel(180,0.3357822);
   _reco_per_true->SetContourLevel(181,0.3376477);
   _reco_per_true->SetContourLevel(182,0.3395131);
   _reco_per_true->SetContourLevel(183,0.3413786);
   _reco_per_true->SetContourLevel(184,0.343244);
   _reco_per_true->SetContourLevel(185,0.3451095);
   _reco_per_true->SetContourLevel(186,0.346975);
   _reco_per_true->SetContourLevel(187,0.3488404);
   _reco_per_true->SetContourLevel(188,0.3507059);
   _reco_per_true->SetContourLevel(189,0.3525713);
   _reco_per_true->SetContourLevel(190,0.3544368);
   _reco_per_true->SetContourLevel(191,0.3563022);
   _reco_per_true->SetContourLevel(192,0.3581677);
   _reco_per_true->SetContourLevel(193,0.3600332);
   _reco_per_true->SetContourLevel(194,0.3618986);
   _reco_per_true->SetContourLevel(195,0.3637641);
   _reco_per_true->SetContourLevel(196,0.3656295);
   _reco_per_true->SetContourLevel(197,0.367495);
   _reco_per_true->SetContourLevel(198,0.3693604);
   _reco_per_true->SetContourLevel(199,0.3712259);
   _reco_per_true->SetContourLevel(200,0.3730913);
   _reco_per_true->SetContourLevel(201,0.3749568);
   _reco_per_true->SetContourLevel(202,0.3768223);
   _reco_per_true->SetContourLevel(203,0.3786877);
   _reco_per_true->SetContourLevel(204,0.3805532);
   _reco_per_true->SetContourLevel(205,0.3824186);
   _reco_per_true->SetContourLevel(206,0.3842841);
   _reco_per_true->SetContourLevel(207,0.3861495);
   _reco_per_true->SetContourLevel(208,0.388015);
   _reco_per_true->SetContourLevel(209,0.3898805);
   _reco_per_true->SetContourLevel(210,0.3917459);
   _reco_per_true->SetContourLevel(211,0.3936114);
   _reco_per_true->SetContourLevel(212,0.3954768);
   _reco_per_true->SetContourLevel(213,0.3973423);
   _reco_per_true->SetContourLevel(214,0.3992077);
   _reco_per_true->SetContourLevel(215,0.4010732);
   _reco_per_true->SetContourLevel(216,0.4029387);
   _reco_per_true->SetContourLevel(217,0.4048041);
   _reco_per_true->SetContourLevel(218,0.4066696);
   _reco_per_true->SetContourLevel(219,0.408535);
   _reco_per_true->SetContourLevel(220,0.4104005);
   _reco_per_true->SetContourLevel(221,0.4122659);
   _reco_per_true->SetContourLevel(222,0.4141314);
   _reco_per_true->SetContourLevel(223,0.4159969);
   _reco_per_true->SetContourLevel(224,0.4178623);
   _reco_per_true->SetContourLevel(225,0.4197278);
   _reco_per_true->SetContourLevel(226,0.4215932);
   _reco_per_true->SetContourLevel(227,0.4234587);
   _reco_per_true->SetContourLevel(228,0.4253241);
   _reco_per_true->SetContourLevel(229,0.4271896);
   _reco_per_true->SetContourLevel(230,0.4290551);
   _reco_per_true->SetContourLevel(231,0.4309205);
   _reco_per_true->SetContourLevel(232,0.432786);
   _reco_per_true->SetContourLevel(233,0.4346514);
   _reco_per_true->SetContourLevel(234,0.4365169);
   _reco_per_true->SetContourLevel(235,0.4383823);
   _reco_per_true->SetContourLevel(236,0.4402478);
   _reco_per_true->SetContourLevel(237,0.4421132);
   _reco_per_true->SetContourLevel(238,0.4439787);
   _reco_per_true->SetContourLevel(239,0.4458442);
   _reco_per_true->SetContourLevel(240,0.4477096);
   _reco_per_true->SetContourLevel(241,0.4495751);
   _reco_per_true->SetContourLevel(242,0.4514405);
   _reco_per_true->SetContourLevel(243,0.453306);
   _reco_per_true->SetContourLevel(244,0.4551714);
   _reco_per_true->SetContourLevel(245,0.4570369);
   _reco_per_true->SetContourLevel(246,0.4589024);
   _reco_per_true->SetContourLevel(247,0.4607678);
   _reco_per_true->SetContourLevel(248,0.4626333);
   _reco_per_true->SetContourLevel(249,0.4644987);
   _reco_per_true->SetContourLevel(250,0.4663642);
   _reco_per_true->SetContourLevel(251,0.4682296);
   _reco_per_true->SetContourLevel(252,0.4700951);
   _reco_per_true->SetContourLevel(253,0.4719606);
   _reco_per_true->SetContourLevel(254,0.473826);
   
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
   TText *AText = pt->AddText("True Bin 16");
   pt->Draw();
   c1_n17->Modified();
   c1_n17->cd();
   c1_n17->SetSelected(c1_n17);
}

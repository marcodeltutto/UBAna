void smearing_matrix_true_18()
{
//=========Macro generated from canvas: c1_n19/c1_n19
//=========  (Sat Sep 22 12:03:56 2018) by ROOT version6.06/06
   TCanvas *c1_n19 = new TCanvas("c1_n19", "c1_n19",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n19->SetHighLightColor(2);
   c1_n19->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n19->SetFillColor(10);
   c1_n19->SetBorderMode(0);
   c1_n19->SetBorderSize(2);
   c1_n19->SetFrameLineWidth(2);
   c1_n19->SetFrameBorderMode(0);
   c1_n19->SetFrameLineWidth(2);
   c1_n19->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 18", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx559[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy559[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx559,Graph_fy559);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph559 = new TH1F("Graph_Graph559","Graph",100,-1.1,0);
   Graph_Graph559->SetMinimum(0);
   Graph_Graph559->SetMaximum(0.33);
   Graph_Graph559->SetDirectory(0);
   Graph_Graph559->SetStats(0);
   Graph_Graph559->SetLineWidth(2);
   Graph_Graph559->GetXaxis()->SetNdivisions(506);
   Graph_Graph559->GetXaxis()->SetLabelFont(42);
   Graph_Graph559->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph559->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph559->GetXaxis()->SetTitleFont(42);
   Graph_Graph559->GetYaxis()->SetNdivisions(506);
   Graph_Graph559->GetYaxis()->SetLabelFont(42);
   Graph_Graph559->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph559->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph559->GetYaxis()->SetTitleFont(42);
   Graph_Graph559->GetZaxis()->SetNdivisions(506);
   Graph_Graph559->GetZaxis()->SetLabelFont(42);
   Graph_Graph559->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph559->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph559->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph559);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx560[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy560[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx560,Graph_fy560);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph560 = new TH1F("Graph_Graph560","Graph",100,0,0.297);
   Graph_Graph560->SetMinimum(0);
   Graph_Graph560->SetMaximum(0.33);
   Graph_Graph560->SetDirectory(0);
   Graph_Graph560->SetStats(0);
   Graph_Graph560->SetLineWidth(2);
   Graph_Graph560->GetXaxis()->SetNdivisions(506);
   Graph_Graph560->GetXaxis()->SetLabelFont(42);
   Graph_Graph560->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph560->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph560->GetXaxis()->SetTitleFont(42);
   Graph_Graph560->GetYaxis()->SetNdivisions(506);
   Graph_Graph560->GetYaxis()->SetLabelFont(42);
   Graph_Graph560->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph560->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph560->GetYaxis()->SetTitleFont(42);
   Graph_Graph560->GetZaxis()->SetNdivisions(506);
   Graph_Graph560->GetZaxis()->SetLabelFont(42);
   Graph_Graph560->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph560->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph560->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph560);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx561[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy561[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx561,Graph_fy561);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph561 = new TH1F("Graph_Graph561","Graph",100,0.252,0.468);
   Graph_Graph561->SetMinimum(0);
   Graph_Graph561->SetMaximum(0.33);
   Graph_Graph561->SetDirectory(0);
   Graph_Graph561->SetStats(0);
   Graph_Graph561->SetLineWidth(2);
   Graph_Graph561->GetXaxis()->SetNdivisions(506);
   Graph_Graph561->GetXaxis()->SetLabelFont(42);
   Graph_Graph561->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph561->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph561->GetXaxis()->SetTitleFont(42);
   Graph_Graph561->GetYaxis()->SetNdivisions(506);
   Graph_Graph561->GetYaxis()->SetLabelFont(42);
   Graph_Graph561->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph561->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph561->GetYaxis()->SetTitleFont(42);
   Graph_Graph561->GetZaxis()->SetNdivisions(506);
   Graph_Graph561->GetZaxis()->SetLabelFont(42);
   Graph_Graph561->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph561->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph561->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph561);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx562[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy562[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx562,Graph_fy562);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000e8a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph562 = new TH1F("Graph_Graph562","Graph",100,0.433,0.637);
   Graph_Graph562->SetMinimum(0);
   Graph_Graph562->SetMaximum(0.33);
   Graph_Graph562->SetDirectory(0);
   Graph_Graph562->SetStats(0);
   Graph_Graph562->SetLineWidth(2);
   Graph_Graph562->GetXaxis()->SetNdivisions(506);
   Graph_Graph562->GetXaxis()->SetLabelFont(42);
   Graph_Graph562->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph562->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph562->GetXaxis()->SetTitleFont(42);
   Graph_Graph562->GetYaxis()->SetNdivisions(506);
   Graph_Graph562->GetYaxis()->SetLabelFont(42);
   Graph_Graph562->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph562->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph562->GetYaxis()->SetTitleFont(42);
   Graph_Graph562->GetZaxis()->SetNdivisions(506);
   Graph_Graph562->GetZaxis()->SetLabelFont(42);
   Graph_Graph562->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph562->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph562->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph562);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx563[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy563[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx563,Graph_fy563);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph563 = new TH1F("Graph_Graph563","Graph",100,0.606,0.774);
   Graph_Graph563->SetMinimum(0);
   Graph_Graph563->SetMaximum(0.33);
   Graph_Graph563->SetDirectory(0);
   Graph_Graph563->SetStats(0);
   Graph_Graph563->SetLineWidth(2);
   Graph_Graph563->GetXaxis()->SetNdivisions(506);
   Graph_Graph563->GetXaxis()->SetLabelFont(42);
   Graph_Graph563->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph563->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph563->GetXaxis()->SetTitleFont(42);
   Graph_Graph563->GetYaxis()->SetNdivisions(506);
   Graph_Graph563->GetYaxis()->SetLabelFont(42);
   Graph_Graph563->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph563->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph563->GetYaxis()->SetTitleFont(42);
   Graph_Graph563->GetZaxis()->SetNdivisions(506);
   Graph_Graph563->GetZaxis()->SetLabelFont(42);
   Graph_Graph563->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph563->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph563->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph563);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx564[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy564[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx564,Graph_fy564);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph564 = new TH1F("Graph_Graph564","Graph",100,0.75,0.87);
   Graph_Graph564->SetMinimum(0);
   Graph_Graph564->SetMaximum(0.33);
   Graph_Graph564->SetDirectory(0);
   Graph_Graph564->SetStats(0);
   Graph_Graph564->SetLineWidth(2);
   Graph_Graph564->GetXaxis()->SetNdivisions(506);
   Graph_Graph564->GetXaxis()->SetLabelFont(42);
   Graph_Graph564->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph564->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph564->GetXaxis()->SetTitleFont(42);
   Graph_Graph564->GetYaxis()->SetNdivisions(506);
   Graph_Graph564->GetYaxis()->SetLabelFont(42);
   Graph_Graph564->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph564->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph564->GetYaxis()->SetTitleFont(42);
   Graph_Graph564->GetZaxis()->SetNdivisions(506);
   Graph_Graph564->GetZaxis()->SetLabelFont(42);
   Graph_Graph564->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph564->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph564->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph564);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx565[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy565[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx565,Graph_fy565);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph565 = new TH1F("Graph_Graph565","Graph",100,0.852,0.948);
   Graph_Graph565->SetMinimum(0);
   Graph_Graph565->SetMaximum(0.33);
   Graph_Graph565->SetDirectory(0);
   Graph_Graph565->SetStats(0);
   Graph_Graph565->SetLineWidth(2);
   Graph_Graph565->GetXaxis()->SetNdivisions(506);
   Graph_Graph565->GetXaxis()->SetLabelFont(42);
   Graph_Graph565->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph565->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph565->GetXaxis()->SetTitleFont(42);
   Graph_Graph565->GetYaxis()->SetNdivisions(506);
   Graph_Graph565->GetYaxis()->SetLabelFont(42);
   Graph_Graph565->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph565->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph565->GetYaxis()->SetTitleFont(42);
   Graph_Graph565->GetZaxis()->SetNdivisions(506);
   Graph_Graph565->GetZaxis()->SetLabelFont(42);
   Graph_Graph565->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph565->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph565->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph565);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx566[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy566[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx566,Graph_fy566);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph566 = new TH1F("Graph_Graph566","Graph",100,0.934,1.006);
   Graph_Graph566->SetMinimum(0);
   Graph_Graph566->SetMaximum(0.33);
   Graph_Graph566->SetDirectory(0);
   Graph_Graph566->SetStats(0);
   Graph_Graph566->SetLineWidth(2);
   Graph_Graph566->GetXaxis()->SetNdivisions(506);
   Graph_Graph566->GetXaxis()->SetLabelFont(42);
   Graph_Graph566->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph566->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph566->GetXaxis()->SetTitleFont(42);
   Graph_Graph566->GetYaxis()->SetNdivisions(506);
   Graph_Graph566->GetYaxis()->SetLabelFont(42);
   Graph_Graph566->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph566->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph566->GetYaxis()->SetTitleFont(42);
   Graph_Graph566->GetZaxis()->SetNdivisions(506);
   Graph_Graph566->GetZaxis()->SetLabelFont(42);
   Graph_Graph566->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph566->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph566->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph566);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx567[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy567[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx567,Graph_fy567);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph567 = new TH1F("Graph_Graph567","Graph",100,-1.1,0);
   Graph_Graph567->SetMinimum(0.285);
   Graph_Graph567->SetMaximum(0.465);
   Graph_Graph567->SetDirectory(0);
   Graph_Graph567->SetStats(0);
   Graph_Graph567->SetLineWidth(2);
   Graph_Graph567->GetXaxis()->SetNdivisions(506);
   Graph_Graph567->GetXaxis()->SetLabelFont(42);
   Graph_Graph567->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph567->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph567->GetXaxis()->SetTitleFont(42);
   Graph_Graph567->GetYaxis()->SetNdivisions(506);
   Graph_Graph567->GetYaxis()->SetLabelFont(42);
   Graph_Graph567->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph567->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph567->GetYaxis()->SetTitleFont(42);
   Graph_Graph567->GetZaxis()->SetNdivisions(506);
   Graph_Graph567->GetZaxis()->SetLabelFont(42);
   Graph_Graph567->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph567->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph567->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph567);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx568[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy568[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx568,Graph_fy568);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002497");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph568 = new TH1F("Graph_Graph568","Graph",100,0,0.297);
   Graph_Graph568->SetMinimum(0.285);
   Graph_Graph568->SetMaximum(0.465);
   Graph_Graph568->SetDirectory(0);
   Graph_Graph568->SetStats(0);
   Graph_Graph568->SetLineWidth(2);
   Graph_Graph568->GetXaxis()->SetNdivisions(506);
   Graph_Graph568->GetXaxis()->SetLabelFont(42);
   Graph_Graph568->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph568->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph568->GetXaxis()->SetTitleFont(42);
   Graph_Graph568->GetYaxis()->SetNdivisions(506);
   Graph_Graph568->GetYaxis()->SetLabelFont(42);
   Graph_Graph568->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph568->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph568->GetYaxis()->SetTitleFont(42);
   Graph_Graph568->GetZaxis()->SetNdivisions(506);
   Graph_Graph568->GetZaxis()->SetLabelFont(42);
   Graph_Graph568->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph568->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph568->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph568);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx569[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy569[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx569,Graph_fy569);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#006cc3");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph569 = new TH1F("Graph_Graph569","Graph",100,0.252,0.468);
   Graph_Graph569->SetMinimum(0.285);
   Graph_Graph569->SetMaximum(0.465);
   Graph_Graph569->SetDirectory(0);
   Graph_Graph569->SetStats(0);
   Graph_Graph569->SetLineWidth(2);
   Graph_Graph569->GetXaxis()->SetNdivisions(506);
   Graph_Graph569->GetXaxis()->SetLabelFont(42);
   Graph_Graph569->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph569->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph569->GetXaxis()->SetTitleFont(42);
   Graph_Graph569->GetYaxis()->SetNdivisions(506);
   Graph_Graph569->GetYaxis()->SetLabelFont(42);
   Graph_Graph569->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph569->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph569->GetYaxis()->SetTitleFont(42);
   Graph_Graph569->GetZaxis()->SetNdivisions(506);
   Graph_Graph569->GetZaxis()->SetLabelFont(42);
   Graph_Graph569->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph569->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph569->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph569);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx570[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy570[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx570,Graph_fy570);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00289a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph570 = new TH1F("Graph_Graph570","Graph",100,0.433,0.637);
   Graph_Graph570->SetMinimum(0.285);
   Graph_Graph570->SetMaximum(0.465);
   Graph_Graph570->SetDirectory(0);
   Graph_Graph570->SetStats(0);
   Graph_Graph570->SetLineWidth(2);
   Graph_Graph570->GetXaxis()->SetNdivisions(506);
   Graph_Graph570->GetXaxis()->SetLabelFont(42);
   Graph_Graph570->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph570->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph570->GetXaxis()->SetTitleFont(42);
   Graph_Graph570->GetYaxis()->SetNdivisions(506);
   Graph_Graph570->GetYaxis()->SetLabelFont(42);
   Graph_Graph570->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph570->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph570->GetYaxis()->SetTitleFont(42);
   Graph_Graph570->GetZaxis()->SetNdivisions(506);
   Graph_Graph570->GetZaxis()->SetLabelFont(42);
   Graph_Graph570->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph570->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph570->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph570);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx571[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy571[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx571,Graph_fy571);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph571 = new TH1F("Graph_Graph571","Graph",100,0.606,0.774);
   Graph_Graph571->SetMinimum(0.285);
   Graph_Graph571->SetMaximum(0.465);
   Graph_Graph571->SetDirectory(0);
   Graph_Graph571->SetStats(0);
   Graph_Graph571->SetLineWidth(2);
   Graph_Graph571->GetXaxis()->SetNdivisions(506);
   Graph_Graph571->GetXaxis()->SetLabelFont(42);
   Graph_Graph571->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph571->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph571->GetXaxis()->SetTitleFont(42);
   Graph_Graph571->GetYaxis()->SetNdivisions(506);
   Graph_Graph571->GetYaxis()->SetLabelFont(42);
   Graph_Graph571->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph571->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph571->GetYaxis()->SetTitleFont(42);
   Graph_Graph571->GetZaxis()->SetNdivisions(506);
   Graph_Graph571->GetZaxis()->SetLabelFont(42);
   Graph_Graph571->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph571->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph571->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph571);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx572[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy572[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx572,Graph_fy572);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph572 = new TH1F("Graph_Graph572","Graph",100,0.75,0.87);
   Graph_Graph572->SetMinimum(0.285);
   Graph_Graph572->SetMaximum(0.465);
   Graph_Graph572->SetDirectory(0);
   Graph_Graph572->SetStats(0);
   Graph_Graph572->SetLineWidth(2);
   Graph_Graph572->GetXaxis()->SetNdivisions(506);
   Graph_Graph572->GetXaxis()->SetLabelFont(42);
   Graph_Graph572->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph572->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph572->GetXaxis()->SetTitleFont(42);
   Graph_Graph572->GetYaxis()->SetNdivisions(506);
   Graph_Graph572->GetYaxis()->SetLabelFont(42);
   Graph_Graph572->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph572->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph572->GetYaxis()->SetTitleFont(42);
   Graph_Graph572->GetZaxis()->SetNdivisions(506);
   Graph_Graph572->GetZaxis()->SetLabelFont(42);
   Graph_Graph572->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph572->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph572->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph572);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx573[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy573[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx573,Graph_fy573);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph573 = new TH1F("Graph_Graph573","Graph",100,0.852,0.948);
   Graph_Graph573->SetMinimum(0.285);
   Graph_Graph573->SetMaximum(0.465);
   Graph_Graph573->SetDirectory(0);
   Graph_Graph573->SetStats(0);
   Graph_Graph573->SetLineWidth(2);
   Graph_Graph573->GetXaxis()->SetNdivisions(506);
   Graph_Graph573->GetXaxis()->SetLabelFont(42);
   Graph_Graph573->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph573->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph573->GetXaxis()->SetTitleFont(42);
   Graph_Graph573->GetYaxis()->SetNdivisions(506);
   Graph_Graph573->GetYaxis()->SetLabelFont(42);
   Graph_Graph573->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph573->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph573->GetYaxis()->SetTitleFont(42);
   Graph_Graph573->GetZaxis()->SetNdivisions(506);
   Graph_Graph573->GetZaxis()->SetLabelFont(42);
   Graph_Graph573->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph573->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph573->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph573);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx574[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy574[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx574,Graph_fy574);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph574 = new TH1F("Graph_Graph574","Graph",100,0.934,1.006);
   Graph_Graph574->SetMinimum(0.285);
   Graph_Graph574->SetMaximum(0.465);
   Graph_Graph574->SetDirectory(0);
   Graph_Graph574->SetStats(0);
   Graph_Graph574->SetLineWidth(2);
   Graph_Graph574->GetXaxis()->SetNdivisions(506);
   Graph_Graph574->GetXaxis()->SetLabelFont(42);
   Graph_Graph574->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph574->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph574->GetXaxis()->SetTitleFont(42);
   Graph_Graph574->GetYaxis()->SetNdivisions(506);
   Graph_Graph574->GetYaxis()->SetLabelFont(42);
   Graph_Graph574->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph574->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph574->GetYaxis()->SetTitleFont(42);
   Graph_Graph574->GetZaxis()->SetNdivisions(506);
   Graph_Graph574->GetZaxis()->SetLabelFont(42);
   Graph_Graph574->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph574->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph574->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph574);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx575[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy575[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx575,Graph_fy575);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph575 = new TH1F("Graph_Graph575","Graph",100,-1.1,0);
   Graph_Graph575->SetMinimum(0.245);
   Graph_Graph575->SetMaximum(2.705);
   Graph_Graph575->SetDirectory(0);
   Graph_Graph575->SetStats(0);
   Graph_Graph575->SetLineWidth(2);
   Graph_Graph575->GetXaxis()->SetNdivisions(506);
   Graph_Graph575->GetXaxis()->SetLabelFont(42);
   Graph_Graph575->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph575->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph575->GetXaxis()->SetTitleFont(42);
   Graph_Graph575->GetYaxis()->SetNdivisions(506);
   Graph_Graph575->GetYaxis()->SetLabelFont(42);
   Graph_Graph575->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph575->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph575->GetYaxis()->SetTitleFont(42);
   Graph_Graph575->GetZaxis()->SetNdivisions(506);
   Graph_Graph575->GetZaxis()->SetLabelFont(42);
   Graph_Graph575->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph575->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph575->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph575);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx576[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy576[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx576,Graph_fy576);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#003ea7");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph576 = new TH1F("Graph_Graph576","Graph",100,0,0.297);
   Graph_Graph576->SetMinimum(0.418);
   Graph_Graph576->SetMaximum(0.802);
   Graph_Graph576->SetDirectory(0);
   Graph_Graph576->SetStats(0);
   Graph_Graph576->SetLineWidth(2);
   Graph_Graph576->GetXaxis()->SetNdivisions(506);
   Graph_Graph576->GetXaxis()->SetLabelFont(42);
   Graph_Graph576->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph576->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph576->GetXaxis()->SetTitleFont(42);
   Graph_Graph576->GetYaxis()->SetNdivisions(506);
   Graph_Graph576->GetYaxis()->SetLabelFont(42);
   Graph_Graph576->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph576->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph576->GetYaxis()->SetTitleFont(42);
   Graph_Graph576->GetZaxis()->SetNdivisions(506);
   Graph_Graph576->GetZaxis()->SetLabelFont(42);
   Graph_Graph576->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph576->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph576->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph576);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx577[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy577[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx577,Graph_fy577);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph577 = new TH1F("Graph_Graph577","Graph",100,0.252,0.468);
   Graph_Graph577->SetMinimum(0.418);
   Graph_Graph577->SetMaximum(0.802);
   Graph_Graph577->SetDirectory(0);
   Graph_Graph577->SetStats(0);
   Graph_Graph577->SetLineWidth(2);
   Graph_Graph577->GetXaxis()->SetNdivisions(506);
   Graph_Graph577->GetXaxis()->SetLabelFont(42);
   Graph_Graph577->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph577->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph577->GetXaxis()->SetTitleFont(42);
   Graph_Graph577->GetYaxis()->SetNdivisions(506);
   Graph_Graph577->GetYaxis()->SetLabelFont(42);
   Graph_Graph577->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph577->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph577->GetYaxis()->SetTitleFont(42);
   Graph_Graph577->GetZaxis()->SetNdivisions(506);
   Graph_Graph577->GetZaxis()->SetLabelFont(42);
   Graph_Graph577->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph577->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph577->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph577);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx578[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy578[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx578,Graph_fy578);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0073c7");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph578 = new TH1F("Graph_Graph578","Graph",100,0.433,0.637);
   Graph_Graph578->SetMinimum(0.418);
   Graph_Graph578->SetMaximum(0.802);
   Graph_Graph578->SetDirectory(0);
   Graph_Graph578->SetStats(0);
   Graph_Graph578->SetLineWidth(2);
   Graph_Graph578->GetXaxis()->SetNdivisions(506);
   Graph_Graph578->GetXaxis()->SetLabelFont(42);
   Graph_Graph578->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph578->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph578->GetXaxis()->SetTitleFont(42);
   Graph_Graph578->GetYaxis()->SetNdivisions(506);
   Graph_Graph578->GetYaxis()->SetLabelFont(42);
   Graph_Graph578->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph578->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph578->GetYaxis()->SetTitleFont(42);
   Graph_Graph578->GetZaxis()->SetNdivisions(506);
   Graph_Graph578->GetZaxis()->SetLabelFont(42);
   Graph_Graph578->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph578->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph578->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph578);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx579[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy579[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx579,Graph_fy579);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph579 = new TH1F("Graph_Graph579","Graph",100,0.606,0.774);
   Graph_Graph579->SetMinimum(0.418);
   Graph_Graph579->SetMaximum(0.802);
   Graph_Graph579->SetDirectory(0);
   Graph_Graph579->SetStats(0);
   Graph_Graph579->SetLineWidth(2);
   Graph_Graph579->GetXaxis()->SetNdivisions(506);
   Graph_Graph579->GetXaxis()->SetLabelFont(42);
   Graph_Graph579->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph579->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph579->GetXaxis()->SetTitleFont(42);
   Graph_Graph579->GetYaxis()->SetNdivisions(506);
   Graph_Graph579->GetYaxis()->SetLabelFont(42);
   Graph_Graph579->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph579->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph579->GetYaxis()->SetTitleFont(42);
   Graph_Graph579->GetZaxis()->SetNdivisions(506);
   Graph_Graph579->GetZaxis()->SetLabelFont(42);
   Graph_Graph579->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph579->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph579->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph579);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx580[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy580[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx580,Graph_fy580);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph580 = new TH1F("Graph_Graph580","Graph",100,0.75,0.87);
   Graph_Graph580->SetMinimum(0.418);
   Graph_Graph580->SetMaximum(0.802);
   Graph_Graph580->SetDirectory(0);
   Graph_Graph580->SetStats(0);
   Graph_Graph580->SetLineWidth(2);
   Graph_Graph580->GetXaxis()->SetNdivisions(506);
   Graph_Graph580->GetXaxis()->SetLabelFont(42);
   Graph_Graph580->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph580->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph580->GetXaxis()->SetTitleFont(42);
   Graph_Graph580->GetYaxis()->SetNdivisions(506);
   Graph_Graph580->GetYaxis()->SetLabelFont(42);
   Graph_Graph580->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph580->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph580->GetYaxis()->SetTitleFont(42);
   Graph_Graph580->GetZaxis()->SetNdivisions(506);
   Graph_Graph580->GetZaxis()->SetLabelFont(42);
   Graph_Graph580->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph580->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph580->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph580);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx581[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy581[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx581,Graph_fy581);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph581 = new TH1F("Graph_Graph581","Graph",100,0.852,0.948);
   Graph_Graph581->SetMinimum(0.418);
   Graph_Graph581->SetMaximum(0.802);
   Graph_Graph581->SetDirectory(0);
   Graph_Graph581->SetStats(0);
   Graph_Graph581->SetLineWidth(2);
   Graph_Graph581->GetXaxis()->SetNdivisions(506);
   Graph_Graph581->GetXaxis()->SetLabelFont(42);
   Graph_Graph581->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph581->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph581->GetXaxis()->SetTitleFont(42);
   Graph_Graph581->GetYaxis()->SetNdivisions(506);
   Graph_Graph581->GetYaxis()->SetLabelFont(42);
   Graph_Graph581->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph581->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph581->GetYaxis()->SetTitleFont(42);
   Graph_Graph581->GetZaxis()->SetNdivisions(506);
   Graph_Graph581->GetZaxis()->SetLabelFont(42);
   Graph_Graph581->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph581->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph581->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph581);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx582[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy582[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx582,Graph_fy582);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph582 = new TH1F("Graph_Graph582","Graph",100,0.934,1.006);
   Graph_Graph582->SetMinimum(0.418);
   Graph_Graph582->SetMaximum(0.802);
   Graph_Graph582->SetDirectory(0);
   Graph_Graph582->SetStats(0);
   Graph_Graph582->SetLineWidth(2);
   Graph_Graph582->GetXaxis()->SetNdivisions(506);
   Graph_Graph582->GetXaxis()->SetLabelFont(42);
   Graph_Graph582->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph582->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph582->GetXaxis()->SetTitleFont(42);
   Graph_Graph582->GetYaxis()->SetNdivisions(506);
   Graph_Graph582->GetYaxis()->SetLabelFont(42);
   Graph_Graph582->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph582->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph582->GetYaxis()->SetTitleFont(42);
   Graph_Graph582->GetZaxis()->SetNdivisions(506);
   Graph_Graph582->GetZaxis()->SetLabelFont(42);
   Graph_Graph582->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph582->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph582->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph582);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx583[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy583[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx583,Graph_fy583);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00138d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph583 = new TH1F("Graph_Graph583","Graph",100,0,0.297);
   Graph_Graph583->SetMinimum(0.597);
   Graph_Graph583->SetMaximum(2.673);
   Graph_Graph583->SetDirectory(0);
   Graph_Graph583->SetStats(0);
   Graph_Graph583->SetLineWidth(2);
   Graph_Graph583->GetXaxis()->SetNdivisions(506);
   Graph_Graph583->GetXaxis()->SetLabelFont(42);
   Graph_Graph583->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph583->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph583->GetXaxis()->SetTitleFont(42);
   Graph_Graph583->GetYaxis()->SetNdivisions(506);
   Graph_Graph583->GetYaxis()->SetLabelFont(42);
   Graph_Graph583->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph583->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph583->GetYaxis()->SetTitleFont(42);
   Graph_Graph583->GetZaxis()->SetNdivisions(506);
   Graph_Graph583->GetZaxis()->SetLabelFont(42);
   Graph_Graph583->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph583->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph583->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph583);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx584[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy584[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx584,Graph_fy584);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#005dba");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph584 = new TH1F("Graph_Graph584","Graph",100,0.252,0.468);
   Graph_Graph584->SetMinimum(0.597);
   Graph_Graph584->SetMaximum(2.673);
   Graph_Graph584->SetDirectory(0);
   Graph_Graph584->SetStats(0);
   Graph_Graph584->SetLineWidth(2);
   Graph_Graph584->GetXaxis()->SetNdivisions(506);
   Graph_Graph584->GetXaxis()->SetLabelFont(42);
   Graph_Graph584->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph584->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph584->GetXaxis()->SetTitleFont(42);
   Graph_Graph584->GetYaxis()->SetNdivisions(506);
   Graph_Graph584->GetYaxis()->SetLabelFont(42);
   Graph_Graph584->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph584->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph584->GetYaxis()->SetTitleFont(42);
   Graph_Graph584->GetZaxis()->SetNdivisions(506);
   Graph_Graph584->GetZaxis()->SetLabelFont(42);
   Graph_Graph584->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph584->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph584->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph584);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx585[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy585[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx585,Graph_fy585);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph585 = new TH1F("Graph_Graph585","Graph",100,0.433,0.637);
   Graph_Graph585->SetMinimum(0.597);
   Graph_Graph585->SetMaximum(2.673);
   Graph_Graph585->SetDirectory(0);
   Graph_Graph585->SetStats(0);
   Graph_Graph585->SetLineWidth(2);
   Graph_Graph585->GetXaxis()->SetNdivisions(506);
   Graph_Graph585->GetXaxis()->SetLabelFont(42);
   Graph_Graph585->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph585->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph585->GetXaxis()->SetTitleFont(42);
   Graph_Graph585->GetYaxis()->SetNdivisions(506);
   Graph_Graph585->GetYaxis()->SetLabelFont(42);
   Graph_Graph585->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph585->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph585->GetYaxis()->SetTitleFont(42);
   Graph_Graph585->GetZaxis()->SetNdivisions(506);
   Graph_Graph585->GetZaxis()->SetLabelFont(42);
   Graph_Graph585->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph585->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph585->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph585);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx586[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy586[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx586,Graph_fy586);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph586 = new TH1F("Graph_Graph586","Graph",100,0.606,0.774);
   Graph_Graph586->SetMinimum(0.597);
   Graph_Graph586->SetMaximum(2.673);
   Graph_Graph586->SetDirectory(0);
   Graph_Graph586->SetStats(0);
   Graph_Graph586->SetLineWidth(2);
   Graph_Graph586->GetXaxis()->SetNdivisions(506);
   Graph_Graph586->GetXaxis()->SetLabelFont(42);
   Graph_Graph586->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph586->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph586->GetXaxis()->SetTitleFont(42);
   Graph_Graph586->GetYaxis()->SetNdivisions(506);
   Graph_Graph586->GetYaxis()->SetLabelFont(42);
   Graph_Graph586->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph586->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph586->GetYaxis()->SetTitleFont(42);
   Graph_Graph586->GetZaxis()->SetNdivisions(506);
   Graph_Graph586->GetZaxis()->SetLabelFont(42);
   Graph_Graph586->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph586->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph586->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph586);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx587[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy587[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx587,Graph_fy587);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph587 = new TH1F("Graph_Graph587","Graph",100,0.75,0.87);
   Graph_Graph587->SetMinimum(0.597);
   Graph_Graph587->SetMaximum(2.673);
   Graph_Graph587->SetDirectory(0);
   Graph_Graph587->SetStats(0);
   Graph_Graph587->SetLineWidth(2);
   Graph_Graph587->GetXaxis()->SetNdivisions(506);
   Graph_Graph587->GetXaxis()->SetLabelFont(42);
   Graph_Graph587->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph587->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph587->GetXaxis()->SetTitleFont(42);
   Graph_Graph587->GetYaxis()->SetNdivisions(506);
   Graph_Graph587->GetYaxis()->SetLabelFont(42);
   Graph_Graph587->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph587->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph587->GetYaxis()->SetTitleFont(42);
   Graph_Graph587->GetZaxis()->SetNdivisions(506);
   Graph_Graph587->GetZaxis()->SetLabelFont(42);
   Graph_Graph587->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph587->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph587->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph587);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx588[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy588[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx588,Graph_fy588);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph588 = new TH1F("Graph_Graph588","Graph",100,0.852,0.948);
   Graph_Graph588->SetMinimum(0.597);
   Graph_Graph588->SetMaximum(2.673);
   Graph_Graph588->SetDirectory(0);
   Graph_Graph588->SetStats(0);
   Graph_Graph588->SetLineWidth(2);
   Graph_Graph588->GetXaxis()->SetNdivisions(506);
   Graph_Graph588->GetXaxis()->SetLabelFont(42);
   Graph_Graph588->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph588->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph588->GetXaxis()->SetTitleFont(42);
   Graph_Graph588->GetYaxis()->SetNdivisions(506);
   Graph_Graph588->GetYaxis()->SetLabelFont(42);
   Graph_Graph588->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph588->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph588->GetYaxis()->SetTitleFont(42);
   Graph_Graph588->GetZaxis()->SetNdivisions(506);
   Graph_Graph588->GetZaxis()->SetLabelFont(42);
   Graph_Graph588->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph588->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph588->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph588);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx589[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy589[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx589,Graph_fy589);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph589 = new TH1F("Graph_Graph589","Graph",100,0.934,1.006);
   Graph_Graph589->SetMinimum(0.597);
   Graph_Graph589->SetMaximum(2.673);
   Graph_Graph589->SetDirectory(0);
   Graph_Graph589->SetStats(0);
   Graph_Graph589->SetLineWidth(2);
   Graph_Graph589->GetXaxis()->SetNdivisions(506);
   Graph_Graph589->GetXaxis()->SetLabelFont(42);
   Graph_Graph589->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph589->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph589->GetXaxis()->SetTitleFont(42);
   Graph_Graph589->GetYaxis()->SetNdivisions(506);
   Graph_Graph589->GetYaxis()->SetLabelFont(42);
   Graph_Graph589->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph589->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph589->GetYaxis()->SetTitleFont(42);
   Graph_Graph589->GetZaxis()->SetNdivisions(506);
   Graph_Graph589->GetZaxis()->SetLabelFont(42);
   Graph_Graph589->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph589->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph589->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph589);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.006973214);
   _reco_per_true->SetBinContent(2,0.006958028);
   _reco_per_true->SetBinContent(3,0.006979347);
   _reco_per_true->SetBinContent(4,0.01393659);
   _reco_per_true->SetBinContent(7,0.003496158);
   _reco_per_true->SetBinContent(9,0.00349169);
   _reco_per_true->SetBinContent(10,0.03144454);
   _reco_per_true->SetBinContent(11,0.09072036);
   _reco_per_true->SetBinContent(12,0.03489079);
   _reco_per_true->SetBinContent(13,0.01035374);
   _reco_per_true->SetBinContent(14,0.003484091);
   _reco_per_true->SetBinContent(15,0.003495776);
   _reco_per_true->SetBinContent(17,0.006973597);
   _reco_per_true->SetBinContent(18,0.05236288);
   _reco_per_true->SetBinContent(19,0.5120163);
   _reco_per_true->SetBinContent(20,0.09723119);
   _reco_per_true->SetBinContent(24,0.003484091);
   _reco_per_true->SetBinContent(25,0.01745867);
   _reco_per_true->SetBinContent(26,0.08025692);
   _reco_per_true->SetBinContent(27,0.01050502);
   _reco_per_true->SetBinContent(28,0.003487035);
   _reco_per_true->SetBinError(1,0.004930824);
   _reco_per_true->SetBinError(2,0.004920069);
   _reco_per_true->SetBinError(3,0.004935145);
   _reco_per_true->SetBinError(4,0.006968316);
   _reco_per_true->SetBinError(7,0.003496158);
   _reco_per_true->SetBinError(9,0.00349169);
   _reco_per_true->SetBinError(10,0.01048153);
   _reco_per_true->SetBinError(11,0.01779178);
   _reco_per_true->SetBinError(12,0.01103346);
   _reco_per_true->SetBinError(13,0.005978176);
   _reco_per_true->SetBinError(14,0.003484091);
   _reco_per_true->SetBinError(15,0.003495776);
   _reco_per_true->SetBinError(17,0.004931095);
   _reco_per_true->SetBinError(18,0.01352015);
   _reco_per_true->SetBinError(19,0.04223362);
   _reco_per_true->SetBinError(20,0.01837799);
   _reco_per_true->SetBinError(24,0.003484091);
   _reco_per_true->SetBinError(25,0.007807761);
   _reco_per_true->SetBinError(26,0.01673477);
   _reco_per_true->SetBinError(27,0.006065081);
   _reco_per_true->SetBinError(28,0.003487035);
   _reco_per_true->SetEntries(287);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.002007907);
   _reco_per_true->SetContourLevel(2,0.004015814);
   _reco_per_true->SetContourLevel(3,0.006023721);
   _reco_per_true->SetContourLevel(4,0.008031628);
   _reco_per_true->SetContourLevel(5,0.01003953);
   _reco_per_true->SetContourLevel(6,0.01204744);
   _reco_per_true->SetContourLevel(7,0.01405535);
   _reco_per_true->SetContourLevel(8,0.01606326);
   _reco_per_true->SetContourLevel(9,0.01807116);
   _reco_per_true->SetContourLevel(10,0.02007907);
   _reco_per_true->SetContourLevel(11,0.02208698);
   _reco_per_true->SetContourLevel(12,0.02409488);
   _reco_per_true->SetContourLevel(13,0.02610279);
   _reco_per_true->SetContourLevel(14,0.0281107);
   _reco_per_true->SetContourLevel(15,0.0301186);
   _reco_per_true->SetContourLevel(16,0.03212651);
   _reco_per_true->SetContourLevel(17,0.03413442);
   _reco_per_true->SetContourLevel(18,0.03614232);
   _reco_per_true->SetContourLevel(19,0.03815023);
   _reco_per_true->SetContourLevel(20,0.04015814);
   _reco_per_true->SetContourLevel(21,0.04216605);
   _reco_per_true->SetContourLevel(22,0.04417395);
   _reco_per_true->SetContourLevel(23,0.04618186);
   _reco_per_true->SetContourLevel(24,0.04818977);
   _reco_per_true->SetContourLevel(25,0.05019767);
   _reco_per_true->SetContourLevel(26,0.05220558);
   _reco_per_true->SetContourLevel(27,0.05421349);
   _reco_per_true->SetContourLevel(28,0.05622139);
   _reco_per_true->SetContourLevel(29,0.0582293);
   _reco_per_true->SetContourLevel(30,0.06023721);
   _reco_per_true->SetContourLevel(31,0.06224511);
   _reco_per_true->SetContourLevel(32,0.06425302);
   _reco_per_true->SetContourLevel(33,0.06626093);
   _reco_per_true->SetContourLevel(34,0.06826884);
   _reco_per_true->SetContourLevel(35,0.07027674);
   _reco_per_true->SetContourLevel(36,0.07228465);
   _reco_per_true->SetContourLevel(37,0.07429256);
   _reco_per_true->SetContourLevel(38,0.07630046);
   _reco_per_true->SetContourLevel(39,0.07830837);
   _reco_per_true->SetContourLevel(40,0.08031628);
   _reco_per_true->SetContourLevel(41,0.08232418);
   _reco_per_true->SetContourLevel(42,0.08433209);
   _reco_per_true->SetContourLevel(43,0.08634);
   _reco_per_true->SetContourLevel(44,0.0883479);
   _reco_per_true->SetContourLevel(45,0.09035581);
   _reco_per_true->SetContourLevel(46,0.09236372);
   _reco_per_true->SetContourLevel(47,0.09437163);
   _reco_per_true->SetContourLevel(48,0.09637953);
   _reco_per_true->SetContourLevel(49,0.09838744);
   _reco_per_true->SetContourLevel(50,0.1003953);
   _reco_per_true->SetContourLevel(51,0.1024033);
   _reco_per_true->SetContourLevel(52,0.1044112);
   _reco_per_true->SetContourLevel(53,0.1064191);
   _reco_per_true->SetContourLevel(54,0.108427);
   _reco_per_true->SetContourLevel(55,0.1104349);
   _reco_per_true->SetContourLevel(56,0.1124428);
   _reco_per_true->SetContourLevel(57,0.1144507);
   _reco_per_true->SetContourLevel(58,0.1164586);
   _reco_per_true->SetContourLevel(59,0.1184665);
   _reco_per_true->SetContourLevel(60,0.1204744);
   _reco_per_true->SetContourLevel(61,0.1224823);
   _reco_per_true->SetContourLevel(62,0.1244902);
   _reco_per_true->SetContourLevel(63,0.1264981);
   _reco_per_true->SetContourLevel(64,0.128506);
   _reco_per_true->SetContourLevel(65,0.130514);
   _reco_per_true->SetContourLevel(66,0.1325219);
   _reco_per_true->SetContourLevel(67,0.1345298);
   _reco_per_true->SetContourLevel(68,0.1365377);
   _reco_per_true->SetContourLevel(69,0.1385456);
   _reco_per_true->SetContourLevel(70,0.1405535);
   _reco_per_true->SetContourLevel(71,0.1425614);
   _reco_per_true->SetContourLevel(72,0.1445693);
   _reco_per_true->SetContourLevel(73,0.1465772);
   _reco_per_true->SetContourLevel(74,0.1485851);
   _reco_per_true->SetContourLevel(75,0.150593);
   _reco_per_true->SetContourLevel(76,0.1526009);
   _reco_per_true->SetContourLevel(77,0.1546088);
   _reco_per_true->SetContourLevel(78,0.1566167);
   _reco_per_true->SetContourLevel(79,0.1586246);
   _reco_per_true->SetContourLevel(80,0.1606326);
   _reco_per_true->SetContourLevel(81,0.1626405);
   _reco_per_true->SetContourLevel(82,0.1646484);
   _reco_per_true->SetContourLevel(83,0.1666563);
   _reco_per_true->SetContourLevel(84,0.1686642);
   _reco_per_true->SetContourLevel(85,0.1706721);
   _reco_per_true->SetContourLevel(86,0.17268);
   _reco_per_true->SetContourLevel(87,0.1746879);
   _reco_per_true->SetContourLevel(88,0.1766958);
   _reco_per_true->SetContourLevel(89,0.1787037);
   _reco_per_true->SetContourLevel(90,0.1807116);
   _reco_per_true->SetContourLevel(91,0.1827195);
   _reco_per_true->SetContourLevel(92,0.1847274);
   _reco_per_true->SetContourLevel(93,0.1867353);
   _reco_per_true->SetContourLevel(94,0.1887433);
   _reco_per_true->SetContourLevel(95,0.1907512);
   _reco_per_true->SetContourLevel(96,0.1927591);
   _reco_per_true->SetContourLevel(97,0.194767);
   _reco_per_true->SetContourLevel(98,0.1967749);
   _reco_per_true->SetContourLevel(99,0.1987828);
   _reco_per_true->SetContourLevel(100,0.2007907);
   _reco_per_true->SetContourLevel(101,0.2027986);
   _reco_per_true->SetContourLevel(102,0.2048065);
   _reco_per_true->SetContourLevel(103,0.2068144);
   _reco_per_true->SetContourLevel(104,0.2088223);
   _reco_per_true->SetContourLevel(105,0.2108302);
   _reco_per_true->SetContourLevel(106,0.2128381);
   _reco_per_true->SetContourLevel(107,0.214846);
   _reco_per_true->SetContourLevel(108,0.2168539);
   _reco_per_true->SetContourLevel(109,0.2188619);
   _reco_per_true->SetContourLevel(110,0.2208698);
   _reco_per_true->SetContourLevel(111,0.2228777);
   _reco_per_true->SetContourLevel(112,0.2248856);
   _reco_per_true->SetContourLevel(113,0.2268935);
   _reco_per_true->SetContourLevel(114,0.2289014);
   _reco_per_true->SetContourLevel(115,0.2309093);
   _reco_per_true->SetContourLevel(116,0.2329172);
   _reco_per_true->SetContourLevel(117,0.2349251);
   _reco_per_true->SetContourLevel(118,0.236933);
   _reco_per_true->SetContourLevel(119,0.2389409);
   _reco_per_true->SetContourLevel(120,0.2409488);
   _reco_per_true->SetContourLevel(121,0.2429567);
   _reco_per_true->SetContourLevel(122,0.2449646);
   _reco_per_true->SetContourLevel(123,0.2469726);
   _reco_per_true->SetContourLevel(124,0.2489805);
   _reco_per_true->SetContourLevel(125,0.2509884);
   _reco_per_true->SetContourLevel(126,0.2529963);
   _reco_per_true->SetContourLevel(127,0.2550042);
   _reco_per_true->SetContourLevel(128,0.2570121);
   _reco_per_true->SetContourLevel(129,0.25902);
   _reco_per_true->SetContourLevel(130,0.2610279);
   _reco_per_true->SetContourLevel(131,0.2630358);
   _reco_per_true->SetContourLevel(132,0.2650437);
   _reco_per_true->SetContourLevel(133,0.2670516);
   _reco_per_true->SetContourLevel(134,0.2690595);
   _reco_per_true->SetContourLevel(135,0.2710674);
   _reco_per_true->SetContourLevel(136,0.2730753);
   _reco_per_true->SetContourLevel(137,0.2750832);
   _reco_per_true->SetContourLevel(138,0.2770912);
   _reco_per_true->SetContourLevel(139,0.2790991);
   _reco_per_true->SetContourLevel(140,0.281107);
   _reco_per_true->SetContourLevel(141,0.2831149);
   _reco_per_true->SetContourLevel(142,0.2851228);
   _reco_per_true->SetContourLevel(143,0.2871307);
   _reco_per_true->SetContourLevel(144,0.2891386);
   _reco_per_true->SetContourLevel(145,0.2911465);
   _reco_per_true->SetContourLevel(146,0.2931544);
   _reco_per_true->SetContourLevel(147,0.2951623);
   _reco_per_true->SetContourLevel(148,0.2971702);
   _reco_per_true->SetContourLevel(149,0.2991781);
   _reco_per_true->SetContourLevel(150,0.301186);
   _reco_per_true->SetContourLevel(151,0.3031939);
   _reco_per_true->SetContourLevel(152,0.3052019);
   _reco_per_true->SetContourLevel(153,0.3072098);
   _reco_per_true->SetContourLevel(154,0.3092177);
   _reco_per_true->SetContourLevel(155,0.3112256);
   _reco_per_true->SetContourLevel(156,0.3132335);
   _reco_per_true->SetContourLevel(157,0.3152414);
   _reco_per_true->SetContourLevel(158,0.3172493);
   _reco_per_true->SetContourLevel(159,0.3192572);
   _reco_per_true->SetContourLevel(160,0.3212651);
   _reco_per_true->SetContourLevel(161,0.323273);
   _reco_per_true->SetContourLevel(162,0.3252809);
   _reco_per_true->SetContourLevel(163,0.3272888);
   _reco_per_true->SetContourLevel(164,0.3292967);
   _reco_per_true->SetContourLevel(165,0.3313046);
   _reco_per_true->SetContourLevel(166,0.3333125);
   _reco_per_true->SetContourLevel(167,0.3353205);
   _reco_per_true->SetContourLevel(168,0.3373284);
   _reco_per_true->SetContourLevel(169,0.3393363);
   _reco_per_true->SetContourLevel(170,0.3413442);
   _reco_per_true->SetContourLevel(171,0.3433521);
   _reco_per_true->SetContourLevel(172,0.34536);
   _reco_per_true->SetContourLevel(173,0.3473679);
   _reco_per_true->SetContourLevel(174,0.3493758);
   _reco_per_true->SetContourLevel(175,0.3513837);
   _reco_per_true->SetContourLevel(176,0.3533916);
   _reco_per_true->SetContourLevel(177,0.3553995);
   _reco_per_true->SetContourLevel(178,0.3574074);
   _reco_per_true->SetContourLevel(179,0.3594153);
   _reco_per_true->SetContourLevel(180,0.3614232);
   _reco_per_true->SetContourLevel(181,0.3634312);
   _reco_per_true->SetContourLevel(182,0.3654391);
   _reco_per_true->SetContourLevel(183,0.367447);
   _reco_per_true->SetContourLevel(184,0.3694549);
   _reco_per_true->SetContourLevel(185,0.3714628);
   _reco_per_true->SetContourLevel(186,0.3734707);
   _reco_per_true->SetContourLevel(187,0.3754786);
   _reco_per_true->SetContourLevel(188,0.3774865);
   _reco_per_true->SetContourLevel(189,0.3794944);
   _reco_per_true->SetContourLevel(190,0.3815023);
   _reco_per_true->SetContourLevel(191,0.3835102);
   _reco_per_true->SetContourLevel(192,0.3855181);
   _reco_per_true->SetContourLevel(193,0.387526);
   _reco_per_true->SetContourLevel(194,0.3895339);
   _reco_per_true->SetContourLevel(195,0.3915419);
   _reco_per_true->SetContourLevel(196,0.3935498);
   _reco_per_true->SetContourLevel(197,0.3955577);
   _reco_per_true->SetContourLevel(198,0.3975656);
   _reco_per_true->SetContourLevel(199,0.3995735);
   _reco_per_true->SetContourLevel(200,0.4015814);
   _reco_per_true->SetContourLevel(201,0.4035893);
   _reco_per_true->SetContourLevel(202,0.4055972);
   _reco_per_true->SetContourLevel(203,0.4076051);
   _reco_per_true->SetContourLevel(204,0.409613);
   _reco_per_true->SetContourLevel(205,0.4116209);
   _reco_per_true->SetContourLevel(206,0.4136288);
   _reco_per_true->SetContourLevel(207,0.4156367);
   _reco_per_true->SetContourLevel(208,0.4176446);
   _reco_per_true->SetContourLevel(209,0.4196525);
   _reco_per_true->SetContourLevel(210,0.4216605);
   _reco_per_true->SetContourLevel(211,0.4236684);
   _reco_per_true->SetContourLevel(212,0.4256763);
   _reco_per_true->SetContourLevel(213,0.4276842);
   _reco_per_true->SetContourLevel(214,0.4296921);
   _reco_per_true->SetContourLevel(215,0.4317);
   _reco_per_true->SetContourLevel(216,0.4337079);
   _reco_per_true->SetContourLevel(217,0.4357158);
   _reco_per_true->SetContourLevel(218,0.4377237);
   _reco_per_true->SetContourLevel(219,0.4397316);
   _reco_per_true->SetContourLevel(220,0.4417395);
   _reco_per_true->SetContourLevel(221,0.4437474);
   _reco_per_true->SetContourLevel(222,0.4457553);
   _reco_per_true->SetContourLevel(223,0.4477632);
   _reco_per_true->SetContourLevel(224,0.4497712);
   _reco_per_true->SetContourLevel(225,0.4517791);
   _reco_per_true->SetContourLevel(226,0.453787);
   _reco_per_true->SetContourLevel(227,0.4557949);
   _reco_per_true->SetContourLevel(228,0.4578028);
   _reco_per_true->SetContourLevel(229,0.4598107);
   _reco_per_true->SetContourLevel(230,0.4618186);
   _reco_per_true->SetContourLevel(231,0.4638265);
   _reco_per_true->SetContourLevel(232,0.4658344);
   _reco_per_true->SetContourLevel(233,0.4678423);
   _reco_per_true->SetContourLevel(234,0.4698502);
   _reco_per_true->SetContourLevel(235,0.4718581);
   _reco_per_true->SetContourLevel(236,0.473866);
   _reco_per_true->SetContourLevel(237,0.4758739);
   _reco_per_true->SetContourLevel(238,0.4778818);
   _reco_per_true->SetContourLevel(239,0.4798898);
   _reco_per_true->SetContourLevel(240,0.4818977);
   _reco_per_true->SetContourLevel(241,0.4839056);
   _reco_per_true->SetContourLevel(242,0.4859135);
   _reco_per_true->SetContourLevel(243,0.4879214);
   _reco_per_true->SetContourLevel(244,0.4899293);
   _reco_per_true->SetContourLevel(245,0.4919372);
   _reco_per_true->SetContourLevel(246,0.4939451);
   _reco_per_true->SetContourLevel(247,0.495953);
   _reco_per_true->SetContourLevel(248,0.4979609);
   _reco_per_true->SetContourLevel(249,0.4999688);
   _reco_per_true->SetContourLevel(250,0.5019767);
   _reco_per_true->SetContourLevel(251,0.5039846);
   _reco_per_true->SetContourLevel(252,0.5059925);
   _reco_per_true->SetContourLevel(253,0.5080005);
   _reco_per_true->SetContourLevel(254,0.5100084);
   
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
   TText *AText = pt->AddText("True Bin 18");
   pt->Draw();
   c1_n19->Modified();
   c1_n19->cd();
   c1_n19->SetSelected(c1_n19);
}

void smearing_matrix_true_17()
{
//=========Macro generated from canvas: c1_n18/c1_n18
//=========  (Sat Sep 22 12:03:56 2018) by ROOT version6.06/06
   TCanvas *c1_n18 = new TCanvas("c1_n18", "c1_n18",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n18->SetHighLightColor(2);
   c1_n18->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n18->SetFillColor(10);
   c1_n18->SetBorderMode(0);
   c1_n18->SetBorderSize(2);
   c1_n18->SetFrameLineWidth(2);
   c1_n18->SetFrameBorderMode(0);
   c1_n18->SetFrameLineWidth(2);
   c1_n18->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 17", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx528[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy528[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx528,Graph_fy528);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000e8a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph528 = new TH1F("Graph_Graph528","Graph",100,-1.1,0);
   Graph_Graph528->SetMinimum(0);
   Graph_Graph528->SetMaximum(0.33);
   Graph_Graph528->SetDirectory(0);
   Graph_Graph528->SetStats(0);
   Graph_Graph528->SetLineWidth(2);
   Graph_Graph528->GetXaxis()->SetNdivisions(506);
   Graph_Graph528->GetXaxis()->SetLabelFont(42);
   Graph_Graph528->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph528->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph528->GetXaxis()->SetTitleFont(42);
   Graph_Graph528->GetYaxis()->SetNdivisions(506);
   Graph_Graph528->GetYaxis()->SetLabelFont(42);
   Graph_Graph528->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph528->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph528->GetYaxis()->SetTitleFont(42);
   Graph_Graph528->GetZaxis()->SetNdivisions(506);
   Graph_Graph528->GetZaxis()->SetLabelFont(42);
   Graph_Graph528->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph528->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph528->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph528);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx529[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy529[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx529,Graph_fy529);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000e8a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph529 = new TH1F("Graph_Graph529","Graph",100,0,0.297);
   Graph_Graph529->SetMinimum(0);
   Graph_Graph529->SetMaximum(0.33);
   Graph_Graph529->SetDirectory(0);
   Graph_Graph529->SetStats(0);
   Graph_Graph529->SetLineWidth(2);
   Graph_Graph529->GetXaxis()->SetNdivisions(506);
   Graph_Graph529->GetXaxis()->SetLabelFont(42);
   Graph_Graph529->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph529->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph529->GetXaxis()->SetTitleFont(42);
   Graph_Graph529->GetYaxis()->SetNdivisions(506);
   Graph_Graph529->GetYaxis()->SetLabelFont(42);
   Graph_Graph529->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph529->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph529->GetYaxis()->SetTitleFont(42);
   Graph_Graph529->GetZaxis()->SetNdivisions(506);
   Graph_Graph529->GetZaxis()->SetLabelFont(42);
   Graph_Graph529->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph529->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph529->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph529);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx530[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy530[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx530,Graph_fy530);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph530 = new TH1F("Graph_Graph530","Graph",100,0.252,0.468);
   Graph_Graph530->SetMinimum(0);
   Graph_Graph530->SetMaximum(0.33);
   Graph_Graph530->SetDirectory(0);
   Graph_Graph530->SetStats(0);
   Graph_Graph530->SetLineWidth(2);
   Graph_Graph530->GetXaxis()->SetNdivisions(506);
   Graph_Graph530->GetXaxis()->SetLabelFont(42);
   Graph_Graph530->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph530->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph530->GetXaxis()->SetTitleFont(42);
   Graph_Graph530->GetYaxis()->SetNdivisions(506);
   Graph_Graph530->GetYaxis()->SetLabelFont(42);
   Graph_Graph530->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph530->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph530->GetYaxis()->SetTitleFont(42);
   Graph_Graph530->GetZaxis()->SetNdivisions(506);
   Graph_Graph530->GetZaxis()->SetLabelFont(42);
   Graph_Graph530->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph530->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph530->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph530);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx531[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy531[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx531,Graph_fy531);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph531 = new TH1F("Graph_Graph531","Graph",100,0.433,0.637);
   Graph_Graph531->SetMinimum(0);
   Graph_Graph531->SetMaximum(0.33);
   Graph_Graph531->SetDirectory(0);
   Graph_Graph531->SetStats(0);
   Graph_Graph531->SetLineWidth(2);
   Graph_Graph531->GetXaxis()->SetNdivisions(506);
   Graph_Graph531->GetXaxis()->SetLabelFont(42);
   Graph_Graph531->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph531->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph531->GetXaxis()->SetTitleFont(42);
   Graph_Graph531->GetYaxis()->SetNdivisions(506);
   Graph_Graph531->GetYaxis()->SetLabelFont(42);
   Graph_Graph531->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph531->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph531->GetYaxis()->SetTitleFont(42);
   Graph_Graph531->GetZaxis()->SetNdivisions(506);
   Graph_Graph531->GetZaxis()->SetLabelFont(42);
   Graph_Graph531->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph531->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph531->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph531);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx532[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy532[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx532,Graph_fy532);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph532 = new TH1F("Graph_Graph532","Graph",100,0.606,0.774);
   Graph_Graph532->SetMinimum(0);
   Graph_Graph532->SetMaximum(0.33);
   Graph_Graph532->SetDirectory(0);
   Graph_Graph532->SetStats(0);
   Graph_Graph532->SetLineWidth(2);
   Graph_Graph532->GetXaxis()->SetNdivisions(506);
   Graph_Graph532->GetXaxis()->SetLabelFont(42);
   Graph_Graph532->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph532->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph532->GetXaxis()->SetTitleFont(42);
   Graph_Graph532->GetYaxis()->SetNdivisions(506);
   Graph_Graph532->GetYaxis()->SetLabelFont(42);
   Graph_Graph532->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph532->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph532->GetYaxis()->SetTitleFont(42);
   Graph_Graph532->GetZaxis()->SetNdivisions(506);
   Graph_Graph532->GetZaxis()->SetLabelFont(42);
   Graph_Graph532->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph532->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph532->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph532);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx533[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy533[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx533,Graph_fy533);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph533 = new TH1F("Graph_Graph533","Graph",100,0.75,0.87);
   Graph_Graph533->SetMinimum(0);
   Graph_Graph533->SetMaximum(0.33);
   Graph_Graph533->SetDirectory(0);
   Graph_Graph533->SetStats(0);
   Graph_Graph533->SetLineWidth(2);
   Graph_Graph533->GetXaxis()->SetNdivisions(506);
   Graph_Graph533->GetXaxis()->SetLabelFont(42);
   Graph_Graph533->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph533->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph533->GetXaxis()->SetTitleFont(42);
   Graph_Graph533->GetYaxis()->SetNdivisions(506);
   Graph_Graph533->GetYaxis()->SetLabelFont(42);
   Graph_Graph533->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph533->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph533->GetYaxis()->SetTitleFont(42);
   Graph_Graph533->GetZaxis()->SetNdivisions(506);
   Graph_Graph533->GetZaxis()->SetLabelFont(42);
   Graph_Graph533->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph533->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph533->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph533);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx534[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy534[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx534,Graph_fy534);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph534 = new TH1F("Graph_Graph534","Graph",100,0.852,0.948);
   Graph_Graph534->SetMinimum(0);
   Graph_Graph534->SetMaximum(0.33);
   Graph_Graph534->SetDirectory(0);
   Graph_Graph534->SetStats(0);
   Graph_Graph534->SetLineWidth(2);
   Graph_Graph534->GetXaxis()->SetNdivisions(506);
   Graph_Graph534->GetXaxis()->SetLabelFont(42);
   Graph_Graph534->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph534->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph534->GetXaxis()->SetTitleFont(42);
   Graph_Graph534->GetYaxis()->SetNdivisions(506);
   Graph_Graph534->GetYaxis()->SetLabelFont(42);
   Graph_Graph534->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph534->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph534->GetYaxis()->SetTitleFont(42);
   Graph_Graph534->GetZaxis()->SetNdivisions(506);
   Graph_Graph534->GetZaxis()->SetLabelFont(42);
   Graph_Graph534->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph534->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph534->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph534);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx535[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy535[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx535,Graph_fy535);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph535 = new TH1F("Graph_Graph535","Graph",100,0.934,1.006);
   Graph_Graph535->SetMinimum(0);
   Graph_Graph535->SetMaximum(0.33);
   Graph_Graph535->SetDirectory(0);
   Graph_Graph535->SetStats(0);
   Graph_Graph535->SetLineWidth(2);
   Graph_Graph535->GetXaxis()->SetNdivisions(506);
   Graph_Graph535->GetXaxis()->SetLabelFont(42);
   Graph_Graph535->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph535->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph535->GetXaxis()->SetTitleFont(42);
   Graph_Graph535->GetYaxis()->SetNdivisions(506);
   Graph_Graph535->GetYaxis()->SetLabelFont(42);
   Graph_Graph535->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph535->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph535->GetYaxis()->SetTitleFont(42);
   Graph_Graph535->GetZaxis()->SetNdivisions(506);
   Graph_Graph535->GetZaxis()->SetLabelFont(42);
   Graph_Graph535->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph535->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph535->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph535);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx536[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy536[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx536,Graph_fy536);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001a92");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph536 = new TH1F("Graph_Graph536","Graph",100,-1.1,0);
   Graph_Graph536->SetMinimum(0.285);
   Graph_Graph536->SetMaximum(0.465);
   Graph_Graph536->SetDirectory(0);
   Graph_Graph536->SetStats(0);
   Graph_Graph536->SetLineWidth(2);
   Graph_Graph536->GetXaxis()->SetNdivisions(506);
   Graph_Graph536->GetXaxis()->SetLabelFont(42);
   Graph_Graph536->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph536->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph536->GetXaxis()->SetTitleFont(42);
   Graph_Graph536->GetYaxis()->SetNdivisions(506);
   Graph_Graph536->GetYaxis()->SetLabelFont(42);
   Graph_Graph536->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph536->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph536->GetYaxis()->SetTitleFont(42);
   Graph_Graph536->GetZaxis()->SetNdivisions(506);
   Graph_Graph536->GetZaxis()->SetLabelFont(42);
   Graph_Graph536->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph536->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph536->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph536);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx537[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy537[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx537,Graph_fy537);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00acea");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph537 = new TH1F("Graph_Graph537","Graph",100,0,0.297);
   Graph_Graph537->SetMinimum(0.285);
   Graph_Graph537->SetMaximum(0.465);
   Graph_Graph537->SetDirectory(0);
   Graph_Graph537->SetStats(0);
   Graph_Graph537->SetLineWidth(2);
   Graph_Graph537->GetXaxis()->SetNdivisions(506);
   Graph_Graph537->GetXaxis()->SetLabelFont(42);
   Graph_Graph537->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph537->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph537->GetXaxis()->SetTitleFont(42);
   Graph_Graph537->GetYaxis()->SetNdivisions(506);
   Graph_Graph537->GetYaxis()->SetLabelFont(42);
   Graph_Graph537->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph537->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph537->GetYaxis()->SetTitleFont(42);
   Graph_Graph537->GetZaxis()->SetNdivisions(506);
   Graph_Graph537->GetZaxis()->SetLabelFont(42);
   Graph_Graph537->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph537->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph537->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph537);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx538[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy538[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx538,Graph_fy538);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph538 = new TH1F("Graph_Graph538","Graph",100,0.252,0.468);
   Graph_Graph538->SetMinimum(0.285);
   Graph_Graph538->SetMaximum(0.465);
   Graph_Graph538->SetDirectory(0);
   Graph_Graph538->SetStats(0);
   Graph_Graph538->SetLineWidth(2);
   Graph_Graph538->GetXaxis()->SetNdivisions(506);
   Graph_Graph538->GetXaxis()->SetLabelFont(42);
   Graph_Graph538->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph538->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph538->GetXaxis()->SetTitleFont(42);
   Graph_Graph538->GetYaxis()->SetNdivisions(506);
   Graph_Graph538->GetYaxis()->SetLabelFont(42);
   Graph_Graph538->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph538->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph538->GetYaxis()->SetTitleFont(42);
   Graph_Graph538->GetZaxis()->SetNdivisions(506);
   Graph_Graph538->GetZaxis()->SetLabelFont(42);
   Graph_Graph538->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph538->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph538->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph538);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx539[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy539[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx539,Graph_fy539);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000e8a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph539 = new TH1F("Graph_Graph539","Graph",100,0.433,0.637);
   Graph_Graph539->SetMinimum(0.285);
   Graph_Graph539->SetMaximum(0.465);
   Graph_Graph539->SetDirectory(0);
   Graph_Graph539->SetStats(0);
   Graph_Graph539->SetLineWidth(2);
   Graph_Graph539->GetXaxis()->SetNdivisions(506);
   Graph_Graph539->GetXaxis()->SetLabelFont(42);
   Graph_Graph539->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph539->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph539->GetXaxis()->SetTitleFont(42);
   Graph_Graph539->GetYaxis()->SetNdivisions(506);
   Graph_Graph539->GetYaxis()->SetLabelFont(42);
   Graph_Graph539->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph539->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph539->GetYaxis()->SetTitleFont(42);
   Graph_Graph539->GetZaxis()->SetNdivisions(506);
   Graph_Graph539->GetZaxis()->SetLabelFont(42);
   Graph_Graph539->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph539->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph539->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph539);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx540[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy540[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx540,Graph_fy540);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph540 = new TH1F("Graph_Graph540","Graph",100,0.606,0.774);
   Graph_Graph540->SetMinimum(0.285);
   Graph_Graph540->SetMaximum(0.465);
   Graph_Graph540->SetDirectory(0);
   Graph_Graph540->SetStats(0);
   Graph_Graph540->SetLineWidth(2);
   Graph_Graph540->GetXaxis()->SetNdivisions(506);
   Graph_Graph540->GetXaxis()->SetLabelFont(42);
   Graph_Graph540->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph540->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph540->GetXaxis()->SetTitleFont(42);
   Graph_Graph540->GetYaxis()->SetNdivisions(506);
   Graph_Graph540->GetYaxis()->SetLabelFont(42);
   Graph_Graph540->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph540->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph540->GetYaxis()->SetTitleFont(42);
   Graph_Graph540->GetZaxis()->SetNdivisions(506);
   Graph_Graph540->GetZaxis()->SetLabelFont(42);
   Graph_Graph540->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph540->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph540->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph540);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx541[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy541[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx541,Graph_fy541);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph541 = new TH1F("Graph_Graph541","Graph",100,0.75,0.87);
   Graph_Graph541->SetMinimum(0.285);
   Graph_Graph541->SetMaximum(0.465);
   Graph_Graph541->SetDirectory(0);
   Graph_Graph541->SetStats(0);
   Graph_Graph541->SetLineWidth(2);
   Graph_Graph541->GetXaxis()->SetNdivisions(506);
   Graph_Graph541->GetXaxis()->SetLabelFont(42);
   Graph_Graph541->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph541->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph541->GetXaxis()->SetTitleFont(42);
   Graph_Graph541->GetYaxis()->SetNdivisions(506);
   Graph_Graph541->GetYaxis()->SetLabelFont(42);
   Graph_Graph541->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph541->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph541->GetYaxis()->SetTitleFont(42);
   Graph_Graph541->GetZaxis()->SetNdivisions(506);
   Graph_Graph541->GetZaxis()->SetLabelFont(42);
   Graph_Graph541->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph541->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph541->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph541);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx542[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy542[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx542,Graph_fy542);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph542 = new TH1F("Graph_Graph542","Graph",100,0.852,0.948);
   Graph_Graph542->SetMinimum(0.285);
   Graph_Graph542->SetMaximum(0.465);
   Graph_Graph542->SetDirectory(0);
   Graph_Graph542->SetStats(0);
   Graph_Graph542->SetLineWidth(2);
   Graph_Graph542->GetXaxis()->SetNdivisions(506);
   Graph_Graph542->GetXaxis()->SetLabelFont(42);
   Graph_Graph542->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph542->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph542->GetXaxis()->SetTitleFont(42);
   Graph_Graph542->GetYaxis()->SetNdivisions(506);
   Graph_Graph542->GetYaxis()->SetLabelFont(42);
   Graph_Graph542->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph542->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph542->GetYaxis()->SetTitleFont(42);
   Graph_Graph542->GetZaxis()->SetNdivisions(506);
   Graph_Graph542->GetZaxis()->SetLabelFont(42);
   Graph_Graph542->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph542->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph542->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph542);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx543[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy543[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx543,Graph_fy543);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph543 = new TH1F("Graph_Graph543","Graph",100,0.934,1.006);
   Graph_Graph543->SetMinimum(0.285);
   Graph_Graph543->SetMaximum(0.465);
   Graph_Graph543->SetDirectory(0);
   Graph_Graph543->SetStats(0);
   Graph_Graph543->SetLineWidth(2);
   Graph_Graph543->GetXaxis()->SetNdivisions(506);
   Graph_Graph543->GetXaxis()->SetLabelFont(42);
   Graph_Graph543->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph543->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph543->GetXaxis()->SetTitleFont(42);
   Graph_Graph543->GetYaxis()->SetNdivisions(506);
   Graph_Graph543->GetYaxis()->SetLabelFont(42);
   Graph_Graph543->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph543->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph543->GetYaxis()->SetTitleFont(42);
   Graph_Graph543->GetZaxis()->SetNdivisions(506);
   Graph_Graph543->GetZaxis()->SetLabelFont(42);
   Graph_Graph543->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph543->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph543->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph543);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx544[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy544[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx544,Graph_fy544);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002497");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph544 = new TH1F("Graph_Graph544","Graph",100,-1.1,0);
   Graph_Graph544->SetMinimum(0.245);
   Graph_Graph544->SetMaximum(2.705);
   Graph_Graph544->SetDirectory(0);
   Graph_Graph544->SetStats(0);
   Graph_Graph544->SetLineWidth(2);
   Graph_Graph544->GetXaxis()->SetNdivisions(506);
   Graph_Graph544->GetXaxis()->SetLabelFont(42);
   Graph_Graph544->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph544->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph544->GetXaxis()->SetTitleFont(42);
   Graph_Graph544->GetYaxis()->SetNdivisions(506);
   Graph_Graph544->GetYaxis()->SetLabelFont(42);
   Graph_Graph544->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph544->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph544->GetYaxis()->SetTitleFont(42);
   Graph_Graph544->GetZaxis()->SetNdivisions(506);
   Graph_Graph544->GetZaxis()->SetLabelFont(42);
   Graph_Graph544->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph544->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph544->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph544);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx545[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy545[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx545,Graph_fy545);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph545 = new TH1F("Graph_Graph545","Graph",100,0,0.297);
   Graph_Graph545->SetMinimum(0.418);
   Graph_Graph545->SetMaximum(0.802);
   Graph_Graph545->SetDirectory(0);
   Graph_Graph545->SetStats(0);
   Graph_Graph545->SetLineWidth(2);
   Graph_Graph545->GetXaxis()->SetNdivisions(506);
   Graph_Graph545->GetXaxis()->SetLabelFont(42);
   Graph_Graph545->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph545->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph545->GetXaxis()->SetTitleFont(42);
   Graph_Graph545->GetYaxis()->SetNdivisions(506);
   Graph_Graph545->GetYaxis()->SetLabelFont(42);
   Graph_Graph545->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph545->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph545->GetYaxis()->SetTitleFont(42);
   Graph_Graph545->GetZaxis()->SetNdivisions(506);
   Graph_Graph545->GetZaxis()->SetLabelFont(42);
   Graph_Graph545->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph545->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph545->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph545);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx546[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy546[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx546,Graph_fy546);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#005dba");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph546 = new TH1F("Graph_Graph546","Graph",100,0.252,0.468);
   Graph_Graph546->SetMinimum(0.418);
   Graph_Graph546->SetMaximum(0.802);
   Graph_Graph546->SetDirectory(0);
   Graph_Graph546->SetStats(0);
   Graph_Graph546->SetLineWidth(2);
   Graph_Graph546->GetXaxis()->SetNdivisions(506);
   Graph_Graph546->GetXaxis()->SetLabelFont(42);
   Graph_Graph546->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph546->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph546->GetXaxis()->SetTitleFont(42);
   Graph_Graph546->GetYaxis()->SetNdivisions(506);
   Graph_Graph546->GetYaxis()->SetLabelFont(42);
   Graph_Graph546->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph546->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph546->GetYaxis()->SetTitleFont(42);
   Graph_Graph546->GetZaxis()->SetNdivisions(506);
   Graph_Graph546->GetZaxis()->SetLabelFont(42);
   Graph_Graph546->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph546->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph546->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph546);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx547[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy547[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx547,Graph_fy547);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph547 = new TH1F("Graph_Graph547","Graph",100,0.433,0.637);
   Graph_Graph547->SetMinimum(0.418);
   Graph_Graph547->SetMaximum(0.802);
   Graph_Graph547->SetDirectory(0);
   Graph_Graph547->SetStats(0);
   Graph_Graph547->SetLineWidth(2);
   Graph_Graph547->GetXaxis()->SetNdivisions(506);
   Graph_Graph547->GetXaxis()->SetLabelFont(42);
   Graph_Graph547->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph547->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph547->GetXaxis()->SetTitleFont(42);
   Graph_Graph547->GetYaxis()->SetNdivisions(506);
   Graph_Graph547->GetYaxis()->SetLabelFont(42);
   Graph_Graph547->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph547->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph547->GetYaxis()->SetTitleFont(42);
   Graph_Graph547->GetZaxis()->SetNdivisions(506);
   Graph_Graph547->GetZaxis()->SetLabelFont(42);
   Graph_Graph547->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph547->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph547->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph547);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx548[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy548[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx548,Graph_fy548);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph548 = new TH1F("Graph_Graph548","Graph",100,0.606,0.774);
   Graph_Graph548->SetMinimum(0.418);
   Graph_Graph548->SetMaximum(0.802);
   Graph_Graph548->SetDirectory(0);
   Graph_Graph548->SetStats(0);
   Graph_Graph548->SetLineWidth(2);
   Graph_Graph548->GetXaxis()->SetNdivisions(506);
   Graph_Graph548->GetXaxis()->SetLabelFont(42);
   Graph_Graph548->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph548->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph548->GetXaxis()->SetTitleFont(42);
   Graph_Graph548->GetYaxis()->SetNdivisions(506);
   Graph_Graph548->GetYaxis()->SetLabelFont(42);
   Graph_Graph548->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph548->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph548->GetYaxis()->SetTitleFont(42);
   Graph_Graph548->GetZaxis()->SetNdivisions(506);
   Graph_Graph548->GetZaxis()->SetLabelFont(42);
   Graph_Graph548->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph548->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph548->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph548);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx549[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy549[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx549,Graph_fy549);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph549 = new TH1F("Graph_Graph549","Graph",100,0.75,0.87);
   Graph_Graph549->SetMinimum(0.418);
   Graph_Graph549->SetMaximum(0.802);
   Graph_Graph549->SetDirectory(0);
   Graph_Graph549->SetStats(0);
   Graph_Graph549->SetLineWidth(2);
   Graph_Graph549->GetXaxis()->SetNdivisions(506);
   Graph_Graph549->GetXaxis()->SetLabelFont(42);
   Graph_Graph549->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph549->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph549->GetXaxis()->SetTitleFont(42);
   Graph_Graph549->GetYaxis()->SetNdivisions(506);
   Graph_Graph549->GetYaxis()->SetLabelFont(42);
   Graph_Graph549->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph549->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph549->GetYaxis()->SetTitleFont(42);
   Graph_Graph549->GetZaxis()->SetNdivisions(506);
   Graph_Graph549->GetZaxis()->SetLabelFont(42);
   Graph_Graph549->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph549->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph549->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph549);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx550[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy550[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx550,Graph_fy550);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph550 = new TH1F("Graph_Graph550","Graph",100,0.852,0.948);
   Graph_Graph550->SetMinimum(0.418);
   Graph_Graph550->SetMaximum(0.802);
   Graph_Graph550->SetDirectory(0);
   Graph_Graph550->SetStats(0);
   Graph_Graph550->SetLineWidth(2);
   Graph_Graph550->GetXaxis()->SetNdivisions(506);
   Graph_Graph550->GetXaxis()->SetLabelFont(42);
   Graph_Graph550->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph550->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph550->GetXaxis()->SetTitleFont(42);
   Graph_Graph550->GetYaxis()->SetNdivisions(506);
   Graph_Graph550->GetYaxis()->SetLabelFont(42);
   Graph_Graph550->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph550->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph550->GetYaxis()->SetTitleFont(42);
   Graph_Graph550->GetZaxis()->SetNdivisions(506);
   Graph_Graph550->GetZaxis()->SetLabelFont(42);
   Graph_Graph550->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph550->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph550->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph550);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx551[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy551[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx551,Graph_fy551);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph551 = new TH1F("Graph_Graph551","Graph",100,0.934,1.006);
   Graph_Graph551->SetMinimum(0.418);
   Graph_Graph551->SetMaximum(0.802);
   Graph_Graph551->SetDirectory(0);
   Graph_Graph551->SetStats(0);
   Graph_Graph551->SetLineWidth(2);
   Graph_Graph551->GetXaxis()->SetNdivisions(506);
   Graph_Graph551->GetXaxis()->SetLabelFont(42);
   Graph_Graph551->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph551->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph551->GetXaxis()->SetTitleFont(42);
   Graph_Graph551->GetYaxis()->SetNdivisions(506);
   Graph_Graph551->GetYaxis()->SetLabelFont(42);
   Graph_Graph551->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph551->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph551->GetYaxis()->SetTitleFont(42);
   Graph_Graph551->GetZaxis()->SetNdivisions(506);
   Graph_Graph551->GetZaxis()->SetLabelFont(42);
   Graph_Graph551->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph551->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph551->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph551);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx552[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy552[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx552,Graph_fy552);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#004cb0");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph552 = new TH1F("Graph_Graph552","Graph",100,0,0.297);
   Graph_Graph552->SetMinimum(0.597);
   Graph_Graph552->SetMaximum(2.673);
   Graph_Graph552->SetDirectory(0);
   Graph_Graph552->SetStats(0);
   Graph_Graph552->SetLineWidth(2);
   Graph_Graph552->GetXaxis()->SetNdivisions(506);
   Graph_Graph552->GetXaxis()->SetLabelFont(42);
   Graph_Graph552->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph552->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph552->GetXaxis()->SetTitleFont(42);
   Graph_Graph552->GetYaxis()->SetNdivisions(506);
   Graph_Graph552->GetYaxis()->SetLabelFont(42);
   Graph_Graph552->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph552->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph552->GetYaxis()->SetTitleFont(42);
   Graph_Graph552->GetZaxis()->SetNdivisions(506);
   Graph_Graph552->GetZaxis()->SetLabelFont(42);
   Graph_Graph552->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph552->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph552->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph552);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx553[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy553[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx553,Graph_fy553);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph553 = new TH1F("Graph_Graph553","Graph",100,0.252,0.468);
   Graph_Graph553->SetMinimum(0.597);
   Graph_Graph553->SetMaximum(2.673);
   Graph_Graph553->SetDirectory(0);
   Graph_Graph553->SetStats(0);
   Graph_Graph553->SetLineWidth(2);
   Graph_Graph553->GetXaxis()->SetNdivisions(506);
   Graph_Graph553->GetXaxis()->SetLabelFont(42);
   Graph_Graph553->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph553->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph553->GetXaxis()->SetTitleFont(42);
   Graph_Graph553->GetYaxis()->SetNdivisions(506);
   Graph_Graph553->GetYaxis()->SetLabelFont(42);
   Graph_Graph553->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph553->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph553->GetYaxis()->SetTitleFont(42);
   Graph_Graph553->GetZaxis()->SetNdivisions(506);
   Graph_Graph553->GetZaxis()->SetLabelFont(42);
   Graph_Graph553->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph553->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph553->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph553);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx554[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy554[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx554,Graph_fy554);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph554 = new TH1F("Graph_Graph554","Graph",100,0.433,0.637);
   Graph_Graph554->SetMinimum(0.597);
   Graph_Graph554->SetMaximum(2.673);
   Graph_Graph554->SetDirectory(0);
   Graph_Graph554->SetStats(0);
   Graph_Graph554->SetLineWidth(2);
   Graph_Graph554->GetXaxis()->SetNdivisions(506);
   Graph_Graph554->GetXaxis()->SetLabelFont(42);
   Graph_Graph554->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph554->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph554->GetXaxis()->SetTitleFont(42);
   Graph_Graph554->GetYaxis()->SetNdivisions(506);
   Graph_Graph554->GetYaxis()->SetLabelFont(42);
   Graph_Graph554->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph554->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph554->GetYaxis()->SetTitleFont(42);
   Graph_Graph554->GetZaxis()->SetNdivisions(506);
   Graph_Graph554->GetZaxis()->SetLabelFont(42);
   Graph_Graph554->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph554->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph554->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph554);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx555[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy555[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx555,Graph_fy555);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph555 = new TH1F("Graph_Graph555","Graph",100,0.606,0.774);
   Graph_Graph555->SetMinimum(0.597);
   Graph_Graph555->SetMaximum(2.673);
   Graph_Graph555->SetDirectory(0);
   Graph_Graph555->SetStats(0);
   Graph_Graph555->SetLineWidth(2);
   Graph_Graph555->GetXaxis()->SetNdivisions(506);
   Graph_Graph555->GetXaxis()->SetLabelFont(42);
   Graph_Graph555->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph555->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph555->GetXaxis()->SetTitleFont(42);
   Graph_Graph555->GetYaxis()->SetNdivisions(506);
   Graph_Graph555->GetYaxis()->SetLabelFont(42);
   Graph_Graph555->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph555->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph555->GetYaxis()->SetTitleFont(42);
   Graph_Graph555->GetZaxis()->SetNdivisions(506);
   Graph_Graph555->GetZaxis()->SetLabelFont(42);
   Graph_Graph555->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph555->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph555->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph555);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx556[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy556[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx556,Graph_fy556);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph556 = new TH1F("Graph_Graph556","Graph",100,0.75,0.87);
   Graph_Graph556->SetMinimum(0.597);
   Graph_Graph556->SetMaximum(2.673);
   Graph_Graph556->SetDirectory(0);
   Graph_Graph556->SetStats(0);
   Graph_Graph556->SetLineWidth(2);
   Graph_Graph556->GetXaxis()->SetNdivisions(506);
   Graph_Graph556->GetXaxis()->SetLabelFont(42);
   Graph_Graph556->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph556->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph556->GetXaxis()->SetTitleFont(42);
   Graph_Graph556->GetYaxis()->SetNdivisions(506);
   Graph_Graph556->GetYaxis()->SetLabelFont(42);
   Graph_Graph556->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph556->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph556->GetYaxis()->SetTitleFont(42);
   Graph_Graph556->GetZaxis()->SetNdivisions(506);
   Graph_Graph556->GetZaxis()->SetLabelFont(42);
   Graph_Graph556->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph556->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph556->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph556);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx557[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy557[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx557,Graph_fy557);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph557 = new TH1F("Graph_Graph557","Graph",100,0.852,0.948);
   Graph_Graph557->SetMinimum(0.597);
   Graph_Graph557->SetMaximum(2.673);
   Graph_Graph557->SetDirectory(0);
   Graph_Graph557->SetStats(0);
   Graph_Graph557->SetLineWidth(2);
   Graph_Graph557->GetXaxis()->SetNdivisions(506);
   Graph_Graph557->GetXaxis()->SetLabelFont(42);
   Graph_Graph557->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph557->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph557->GetXaxis()->SetTitleFont(42);
   Graph_Graph557->GetYaxis()->SetNdivisions(506);
   Graph_Graph557->GetYaxis()->SetLabelFont(42);
   Graph_Graph557->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph557->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph557->GetYaxis()->SetTitleFont(42);
   Graph_Graph557->GetZaxis()->SetNdivisions(506);
   Graph_Graph557->GetZaxis()->SetLabelFont(42);
   Graph_Graph557->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph557->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph557->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph557);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx558[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy558[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx558,Graph_fy558);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph558 = new TH1F("Graph_Graph558","Graph",100,0.934,1.006);
   Graph_Graph558->SetMinimum(0.597);
   Graph_Graph558->SetMaximum(2.673);
   Graph_Graph558->SetDirectory(0);
   Graph_Graph558->SetStats(0);
   Graph_Graph558->SetLineWidth(2);
   Graph_Graph558->GetXaxis()->SetNdivisions(506);
   Graph_Graph558->GetXaxis()->SetLabelFont(42);
   Graph_Graph558->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph558->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph558->GetXaxis()->SetTitleFont(42);
   Graph_Graph558->GetYaxis()->SetNdivisions(506);
   Graph_Graph558->GetYaxis()->SetLabelFont(42);
   Graph_Graph558->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph558->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph558->GetYaxis()->SetTitleFont(42);
   Graph_Graph558->GetZaxis()->SetNdivisions(506);
   Graph_Graph558->GetZaxis()->SetLabelFont(42);
   Graph_Graph558->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph558->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph558->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph558);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.01233614);
   _reco_per_true->SetBinContent(2,0.01234478);
   _reco_per_true->SetBinContent(4,0.006199054);
   _reco_per_true->SetBinContent(9,0.02463292);
   _reco_per_true->SetBinContent(10,0.1482933);
   _reco_per_true->SetBinContent(11,0.01853756);
   _reco_per_true->SetBinContent(12,0.01236022);
   _reco_per_true->SetBinContent(13,0.01851635);
   _reco_per_true->SetBinContent(15,0.0123222);
   _reco_per_true->SetBinContent(16,0.006170264);
   _reco_per_true->SetBinContent(17,0.03084755);
   _reco_per_true->SetBinContent(18,0.5246026);
   _reco_per_true->SetBinContent(19,0.08031008);
   _reco_per_true->SetBinContent(24,0.006163072);
   _reco_per_true->SetBinContent(25,0.06786446);
   _reco_per_true->SetBinContent(26,0.006176514);
   _reco_per_true->SetBinContent(28,0.00616828);
   _reco_per_true->SetBinContent(30,0.006154635);
   _reco_per_true->SetBinError(1,0.008723001);
   _reco_per_true->SetBinError(2,0.008729159);
   _reco_per_true->SetBinError(4,0.006199054);
   _reco_per_true->SetBinError(9,0.01231649);
   _reco_per_true->SetBinError(10,0.03027034);
   _reco_per_true->SetBinError(11,0.0107027);
   _reco_per_true->SetBinError(12,0.008739997);
   _reco_per_true->SetBinError(13,0.01069047);
   _reco_per_true->SetBinError(15,0.008713142);
   _reco_per_true->SetBinError(16,0.006170264);
   _reco_per_true->SetBinError(17,0.01379545);
   _reco_per_true->SetBinError(18,0.05690144);
   _reco_per_true->SetBinError(19,0.02227411);
   _reco_per_true->SetBinError(24,0.006163072);
   _reco_per_true->SetBinError(25,0.02046211);
   _reco_per_true->SetBinError(26,0.006176514);
   _reco_per_true->SetBinError(28,0.00616828);
   _reco_per_true->SetBinError(30,0.006154635);
   _reco_per_true->SetEntries(162);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.002057265);
   _reco_per_true->SetContourLevel(2,0.00411453);
   _reco_per_true->SetContourLevel(3,0.006171795);
   _reco_per_true->SetContourLevel(4,0.00822906);
   _reco_per_true->SetContourLevel(5,0.01028633);
   _reco_per_true->SetContourLevel(6,0.01234359);
   _reco_per_true->SetContourLevel(7,0.01440086);
   _reco_per_true->SetContourLevel(8,0.01645812);
   _reco_per_true->SetContourLevel(9,0.01851539);
   _reco_per_true->SetContourLevel(10,0.02057265);
   _reco_per_true->SetContourLevel(11,0.02262992);
   _reco_per_true->SetContourLevel(12,0.02468718);
   _reco_per_true->SetContourLevel(13,0.02674445);
   _reco_per_true->SetContourLevel(14,0.02880171);
   _reco_per_true->SetContourLevel(15,0.03085898);
   _reco_per_true->SetContourLevel(16,0.03291624);
   _reco_per_true->SetContourLevel(17,0.03497351);
   _reco_per_true->SetContourLevel(18,0.03703077);
   _reco_per_true->SetContourLevel(19,0.03908804);
   _reco_per_true->SetContourLevel(20,0.0411453);
   _reco_per_true->SetContourLevel(21,0.04320257);
   _reco_per_true->SetContourLevel(22,0.04525983);
   _reco_per_true->SetContourLevel(23,0.0473171);
   _reco_per_true->SetContourLevel(24,0.04937436);
   _reco_per_true->SetContourLevel(25,0.05143163);
   _reco_per_true->SetContourLevel(26,0.05348889);
   _reco_per_true->SetContourLevel(27,0.05554616);
   _reco_per_true->SetContourLevel(28,0.05760342);
   _reco_per_true->SetContourLevel(29,0.05966069);
   _reco_per_true->SetContourLevel(30,0.06171795);
   _reco_per_true->SetContourLevel(31,0.06377522);
   _reco_per_true->SetContourLevel(32,0.06583248);
   _reco_per_true->SetContourLevel(33,0.06788975);
   _reco_per_true->SetContourLevel(34,0.06994701);
   _reco_per_true->SetContourLevel(35,0.07200428);
   _reco_per_true->SetContourLevel(36,0.07406154);
   _reco_per_true->SetContourLevel(37,0.07611881);
   _reco_per_true->SetContourLevel(38,0.07817607);
   _reco_per_true->SetContourLevel(39,0.08023334);
   _reco_per_true->SetContourLevel(40,0.0822906);
   _reco_per_true->SetContourLevel(41,0.08434787);
   _reco_per_true->SetContourLevel(42,0.08640513);
   _reco_per_true->SetContourLevel(43,0.0884624);
   _reco_per_true->SetContourLevel(44,0.09051966);
   _reco_per_true->SetContourLevel(45,0.09257693);
   _reco_per_true->SetContourLevel(46,0.09463419);
   _reco_per_true->SetContourLevel(47,0.09669146);
   _reco_per_true->SetContourLevel(48,0.09874873);
   _reco_per_true->SetContourLevel(49,0.100806);
   _reco_per_true->SetContourLevel(50,0.1028633);
   _reco_per_true->SetContourLevel(51,0.1049205);
   _reco_per_true->SetContourLevel(52,0.1069778);
   _reco_per_true->SetContourLevel(53,0.1090351);
   _reco_per_true->SetContourLevel(54,0.1110923);
   _reco_per_true->SetContourLevel(55,0.1131496);
   _reco_per_true->SetContourLevel(56,0.1152068);
   _reco_per_true->SetContourLevel(57,0.1172641);
   _reco_per_true->SetContourLevel(58,0.1193214);
   _reco_per_true->SetContourLevel(59,0.1213786);
   _reco_per_true->SetContourLevel(60,0.1234359);
   _reco_per_true->SetContourLevel(61,0.1254932);
   _reco_per_true->SetContourLevel(62,0.1275504);
   _reco_per_true->SetContourLevel(63,0.1296077);
   _reco_per_true->SetContourLevel(64,0.131665);
   _reco_per_true->SetContourLevel(65,0.1337222);
   _reco_per_true->SetContourLevel(66,0.1357795);
   _reco_per_true->SetContourLevel(67,0.1378368);
   _reco_per_true->SetContourLevel(68,0.139894);
   _reco_per_true->SetContourLevel(69,0.1419513);
   _reco_per_true->SetContourLevel(70,0.1440086);
   _reco_per_true->SetContourLevel(71,0.1460658);
   _reco_per_true->SetContourLevel(72,0.1481231);
   _reco_per_true->SetContourLevel(73,0.1501804);
   _reco_per_true->SetContourLevel(74,0.1522376);
   _reco_per_true->SetContourLevel(75,0.1542949);
   _reco_per_true->SetContourLevel(76,0.1563521);
   _reco_per_true->SetContourLevel(77,0.1584094);
   _reco_per_true->SetContourLevel(78,0.1604667);
   _reco_per_true->SetContourLevel(79,0.1625239);
   _reco_per_true->SetContourLevel(80,0.1645812);
   _reco_per_true->SetContourLevel(81,0.1666385);
   _reco_per_true->SetContourLevel(82,0.1686957);
   _reco_per_true->SetContourLevel(83,0.170753);
   _reco_per_true->SetContourLevel(84,0.1728103);
   _reco_per_true->SetContourLevel(85,0.1748675);
   _reco_per_true->SetContourLevel(86,0.1769248);
   _reco_per_true->SetContourLevel(87,0.1789821);
   _reco_per_true->SetContourLevel(88,0.1810393);
   _reco_per_true->SetContourLevel(89,0.1830966);
   _reco_per_true->SetContourLevel(90,0.1851539);
   _reco_per_true->SetContourLevel(91,0.1872111);
   _reco_per_true->SetContourLevel(92,0.1892684);
   _reco_per_true->SetContourLevel(93,0.1913257);
   _reco_per_true->SetContourLevel(94,0.1933829);
   _reco_per_true->SetContourLevel(95,0.1954402);
   _reco_per_true->SetContourLevel(96,0.1974975);
   _reco_per_true->SetContourLevel(97,0.1995547);
   _reco_per_true->SetContourLevel(98,0.201612);
   _reco_per_true->SetContourLevel(99,0.2036692);
   _reco_per_true->SetContourLevel(100,0.2057265);
   _reco_per_true->SetContourLevel(101,0.2077838);
   _reco_per_true->SetContourLevel(102,0.209841);
   _reco_per_true->SetContourLevel(103,0.2118983);
   _reco_per_true->SetContourLevel(104,0.2139556);
   _reco_per_true->SetContourLevel(105,0.2160128);
   _reco_per_true->SetContourLevel(106,0.2180701);
   _reco_per_true->SetContourLevel(107,0.2201274);
   _reco_per_true->SetContourLevel(108,0.2221846);
   _reco_per_true->SetContourLevel(109,0.2242419);
   _reco_per_true->SetContourLevel(110,0.2262992);
   _reco_per_true->SetContourLevel(111,0.2283564);
   _reco_per_true->SetContourLevel(112,0.2304137);
   _reco_per_true->SetContourLevel(113,0.232471);
   _reco_per_true->SetContourLevel(114,0.2345282);
   _reco_per_true->SetContourLevel(115,0.2365855);
   _reco_per_true->SetContourLevel(116,0.2386428);
   _reco_per_true->SetContourLevel(117,0.2407);
   _reco_per_true->SetContourLevel(118,0.2427573);
   _reco_per_true->SetContourLevel(119,0.2448145);
   _reco_per_true->SetContourLevel(120,0.2468718);
   _reco_per_true->SetContourLevel(121,0.2489291);
   _reco_per_true->SetContourLevel(122,0.2509863);
   _reco_per_true->SetContourLevel(123,0.2530436);
   _reco_per_true->SetContourLevel(124,0.2551009);
   _reco_per_true->SetContourLevel(125,0.2571581);
   _reco_per_true->SetContourLevel(126,0.2592154);
   _reco_per_true->SetContourLevel(127,0.2612727);
   _reco_per_true->SetContourLevel(128,0.2633299);
   _reco_per_true->SetContourLevel(129,0.2653872);
   _reco_per_true->SetContourLevel(130,0.2674445);
   _reco_per_true->SetContourLevel(131,0.2695017);
   _reco_per_true->SetContourLevel(132,0.271559);
   _reco_per_true->SetContourLevel(133,0.2736163);
   _reco_per_true->SetContourLevel(134,0.2756735);
   _reco_per_true->SetContourLevel(135,0.2777308);
   _reco_per_true->SetContourLevel(136,0.2797881);
   _reco_per_true->SetContourLevel(137,0.2818453);
   _reco_per_true->SetContourLevel(138,0.2839026);
   _reco_per_true->SetContourLevel(139,0.2859598);
   _reco_per_true->SetContourLevel(140,0.2880171);
   _reco_per_true->SetContourLevel(141,0.2900744);
   _reco_per_true->SetContourLevel(142,0.2921316);
   _reco_per_true->SetContourLevel(143,0.2941889);
   _reco_per_true->SetContourLevel(144,0.2962462);
   _reco_per_true->SetContourLevel(145,0.2983034);
   _reco_per_true->SetContourLevel(146,0.3003607);
   _reco_per_true->SetContourLevel(147,0.302418);
   _reco_per_true->SetContourLevel(148,0.3044752);
   _reco_per_true->SetContourLevel(149,0.3065325);
   _reco_per_true->SetContourLevel(150,0.3085898);
   _reco_per_true->SetContourLevel(151,0.310647);
   _reco_per_true->SetContourLevel(152,0.3127043);
   _reco_per_true->SetContourLevel(153,0.3147616);
   _reco_per_true->SetContourLevel(154,0.3168188);
   _reco_per_true->SetContourLevel(155,0.3188761);
   _reco_per_true->SetContourLevel(156,0.3209334);
   _reco_per_true->SetContourLevel(157,0.3229906);
   _reco_per_true->SetContourLevel(158,0.3250479);
   _reco_per_true->SetContourLevel(159,0.3271052);
   _reco_per_true->SetContourLevel(160,0.3291624);
   _reco_per_true->SetContourLevel(161,0.3312197);
   _reco_per_true->SetContourLevel(162,0.3332769);
   _reco_per_true->SetContourLevel(163,0.3353342);
   _reco_per_true->SetContourLevel(164,0.3373915);
   _reco_per_true->SetContourLevel(165,0.3394487);
   _reco_per_true->SetContourLevel(166,0.341506);
   _reco_per_true->SetContourLevel(167,0.3435633);
   _reco_per_true->SetContourLevel(168,0.3456205);
   _reco_per_true->SetContourLevel(169,0.3476778);
   _reco_per_true->SetContourLevel(170,0.3497351);
   _reco_per_true->SetContourLevel(171,0.3517923);
   _reco_per_true->SetContourLevel(172,0.3538496);
   _reco_per_true->SetContourLevel(173,0.3559069);
   _reco_per_true->SetContourLevel(174,0.3579641);
   _reco_per_true->SetContourLevel(175,0.3600214);
   _reco_per_true->SetContourLevel(176,0.3620787);
   _reco_per_true->SetContourLevel(177,0.3641359);
   _reco_per_true->SetContourLevel(178,0.3661932);
   _reco_per_true->SetContourLevel(179,0.3682505);
   _reco_per_true->SetContourLevel(180,0.3703077);
   _reco_per_true->SetContourLevel(181,0.372365);
   _reco_per_true->SetContourLevel(182,0.3744222);
   _reco_per_true->SetContourLevel(183,0.3764795);
   _reco_per_true->SetContourLevel(184,0.3785368);
   _reco_per_true->SetContourLevel(185,0.380594);
   _reco_per_true->SetContourLevel(186,0.3826513);
   _reco_per_true->SetContourLevel(187,0.3847086);
   _reco_per_true->SetContourLevel(188,0.3867658);
   _reco_per_true->SetContourLevel(189,0.3888231);
   _reco_per_true->SetContourLevel(190,0.3908804);
   _reco_per_true->SetContourLevel(191,0.3929376);
   _reco_per_true->SetContourLevel(192,0.3949949);
   _reco_per_true->SetContourLevel(193,0.3970522);
   _reco_per_true->SetContourLevel(194,0.3991094);
   _reco_per_true->SetContourLevel(195,0.4011667);
   _reco_per_true->SetContourLevel(196,0.403224);
   _reco_per_true->SetContourLevel(197,0.4052812);
   _reco_per_true->SetContourLevel(198,0.4073385);
   _reco_per_true->SetContourLevel(199,0.4093958);
   _reco_per_true->SetContourLevel(200,0.411453);
   _reco_per_true->SetContourLevel(201,0.4135103);
   _reco_per_true->SetContourLevel(202,0.4155676);
   _reco_per_true->SetContourLevel(203,0.4176248);
   _reco_per_true->SetContourLevel(204,0.4196821);
   _reco_per_true->SetContourLevel(205,0.4217393);
   _reco_per_true->SetContourLevel(206,0.4237966);
   _reco_per_true->SetContourLevel(207,0.4258539);
   _reco_per_true->SetContourLevel(208,0.4279111);
   _reco_per_true->SetContourLevel(209,0.4299684);
   _reco_per_true->SetContourLevel(210,0.4320257);
   _reco_per_true->SetContourLevel(211,0.4340829);
   _reco_per_true->SetContourLevel(212,0.4361402);
   _reco_per_true->SetContourLevel(213,0.4381975);
   _reco_per_true->SetContourLevel(214,0.4402547);
   _reco_per_true->SetContourLevel(215,0.442312);
   _reco_per_true->SetContourLevel(216,0.4443693);
   _reco_per_true->SetContourLevel(217,0.4464265);
   _reco_per_true->SetContourLevel(218,0.4484838);
   _reco_per_true->SetContourLevel(219,0.4505411);
   _reco_per_true->SetContourLevel(220,0.4525983);
   _reco_per_true->SetContourLevel(221,0.4546556);
   _reco_per_true->SetContourLevel(222,0.4567129);
   _reco_per_true->SetContourLevel(223,0.4587701);
   _reco_per_true->SetContourLevel(224,0.4608274);
   _reco_per_true->SetContourLevel(225,0.4628846);
   _reco_per_true->SetContourLevel(226,0.4649419);
   _reco_per_true->SetContourLevel(227,0.4669992);
   _reco_per_true->SetContourLevel(228,0.4690564);
   _reco_per_true->SetContourLevel(229,0.4711137);
   _reco_per_true->SetContourLevel(230,0.473171);
   _reco_per_true->SetContourLevel(231,0.4752282);
   _reco_per_true->SetContourLevel(232,0.4772855);
   _reco_per_true->SetContourLevel(233,0.4793428);
   _reco_per_true->SetContourLevel(234,0.4814);
   _reco_per_true->SetContourLevel(235,0.4834573);
   _reco_per_true->SetContourLevel(236,0.4855146);
   _reco_per_true->SetContourLevel(237,0.4875718);
   _reco_per_true->SetContourLevel(238,0.4896291);
   _reco_per_true->SetContourLevel(239,0.4916864);
   _reco_per_true->SetContourLevel(240,0.4937436);
   _reco_per_true->SetContourLevel(241,0.4958009);
   _reco_per_true->SetContourLevel(242,0.4978582);
   _reco_per_true->SetContourLevel(243,0.4999154);
   _reco_per_true->SetContourLevel(244,0.5019727);
   _reco_per_true->SetContourLevel(245,0.50403);
   _reco_per_true->SetContourLevel(246,0.5060872);
   _reco_per_true->SetContourLevel(247,0.5081445);
   _reco_per_true->SetContourLevel(248,0.5102017);
   _reco_per_true->SetContourLevel(249,0.512259);
   _reco_per_true->SetContourLevel(250,0.5143163);
   _reco_per_true->SetContourLevel(251,0.5163735);
   _reco_per_true->SetContourLevel(252,0.5184308);
   _reco_per_true->SetContourLevel(253,0.5204881);
   _reco_per_true->SetContourLevel(254,0.5225453);
   
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
   TText *AText = pt->AddText("True Bin 17");
   pt->Draw();
   c1_n18->Modified();
   c1_n18->cd();
   c1_n18->SetSelected(c1_n18);
}

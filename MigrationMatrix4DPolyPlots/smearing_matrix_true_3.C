void smearing_matrix_true_3()
{
//=========Macro generated from canvas: c1_n4/c1_n4
//=========  (Sat Sep 22 12:03:54 2018) by ROOT version6.06/06
   TCanvas *c1_n4 = new TCanvas("c1_n4", "c1_n4",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n4->SetHighLightColor(2);
   c1_n4->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n4->SetFillColor(10);
   c1_n4->SetBorderMode(0);
   c1_n4->SetBorderSize(2);
   c1_n4->SetFrameLineWidth(2);
   c1_n4->SetFrameBorderMode(0);
   c1_n4->SetFrameLineWidth(2);
   c1_n4->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 3", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx94[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy94[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx94,Graph_fy94);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#009ce0");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph94 = new TH1F("Graph_Graph94","Graph",100,-1.1,0);
   Graph_Graph94->SetMinimum(0);
   Graph_Graph94->SetMaximum(0.33);
   Graph_Graph94->SetDirectory(0);
   Graph_Graph94->SetStats(0);
   Graph_Graph94->SetLineWidth(2);
   Graph_Graph94->GetXaxis()->SetNdivisions(506);
   Graph_Graph94->GetXaxis()->SetLabelFont(42);
   Graph_Graph94->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph94->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph94->GetXaxis()->SetTitleFont(42);
   Graph_Graph94->GetYaxis()->SetNdivisions(506);
   Graph_Graph94->GetYaxis()->SetLabelFont(42);
   Graph_Graph94->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph94->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph94->GetYaxis()->SetTitleFont(42);
   Graph_Graph94->GetZaxis()->SetNdivisions(506);
   Graph_Graph94->GetZaxis()->SetLabelFont(42);
   Graph_Graph94->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph94->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph94->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph94);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx95[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy95[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx95,Graph_fy95);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001890");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph95 = new TH1F("Graph_Graph95","Graph",100,0,0.297);
   Graph_Graph95->SetMinimum(0);
   Graph_Graph95->SetMaximum(0.33);
   Graph_Graph95->SetDirectory(0);
   Graph_Graph95->SetStats(0);
   Graph_Graph95->SetLineWidth(2);
   Graph_Graph95->GetXaxis()->SetNdivisions(506);
   Graph_Graph95->GetXaxis()->SetLabelFont(42);
   Graph_Graph95->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph95->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph95->GetXaxis()->SetTitleFont(42);
   Graph_Graph95->GetYaxis()->SetNdivisions(506);
   Graph_Graph95->GetYaxis()->SetLabelFont(42);
   Graph_Graph95->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph95->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph95->GetYaxis()->SetTitleFont(42);
   Graph_Graph95->GetZaxis()->SetNdivisions(506);
   Graph_Graph95->GetZaxis()->SetLabelFont(42);
   Graph_Graph95->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph95->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph95->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph95);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx96[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy96[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx96,Graph_fy96);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#d4fc28");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph96 = new TH1F("Graph_Graph96","Graph",100,0.252,0.468);
   Graph_Graph96->SetMinimum(0);
   Graph_Graph96->SetMaximum(0.33);
   Graph_Graph96->SetDirectory(0);
   Graph_Graph96->SetStats(0);
   Graph_Graph96->SetLineWidth(2);
   Graph_Graph96->GetXaxis()->SetNdivisions(506);
   Graph_Graph96->GetXaxis()->SetLabelFont(42);
   Graph_Graph96->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph96->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph96->GetXaxis()->SetTitleFont(42);
   Graph_Graph96->GetYaxis()->SetNdivisions(506);
   Graph_Graph96->GetYaxis()->SetLabelFont(42);
   Graph_Graph96->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph96->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph96->GetYaxis()->SetTitleFont(42);
   Graph_Graph96->GetZaxis()->SetNdivisions(506);
   Graph_Graph96->GetZaxis()->SetLabelFont(42);
   Graph_Graph96->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph96->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph96->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph96);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx97[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy97[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx97,Graph_fy97);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph97 = new TH1F("Graph_Graph97","Graph",100,0.433,0.637);
   Graph_Graph97->SetMinimum(0);
   Graph_Graph97->SetMaximum(0.33);
   Graph_Graph97->SetDirectory(0);
   Graph_Graph97->SetStats(0);
   Graph_Graph97->SetLineWidth(2);
   Graph_Graph97->GetXaxis()->SetNdivisions(506);
   Graph_Graph97->GetXaxis()->SetLabelFont(42);
   Graph_Graph97->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph97->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph97->GetXaxis()->SetTitleFont(42);
   Graph_Graph97->GetYaxis()->SetNdivisions(506);
   Graph_Graph97->GetYaxis()->SetLabelFont(42);
   Graph_Graph97->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph97->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph97->GetYaxis()->SetTitleFont(42);
   Graph_Graph97->GetZaxis()->SetNdivisions(506);
   Graph_Graph97->GetZaxis()->SetLabelFont(42);
   Graph_Graph97->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph97->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph97->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph97);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx98[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy98[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx98,Graph_fy98);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#e7c015");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph98 = new TH1F("Graph_Graph98","Graph",100,0.606,0.774);
   Graph_Graph98->SetMinimum(0);
   Graph_Graph98->SetMaximum(0.33);
   Graph_Graph98->SetDirectory(0);
   Graph_Graph98->SetStats(0);
   Graph_Graph98->SetLineWidth(2);
   Graph_Graph98->GetXaxis()->SetNdivisions(506);
   Graph_Graph98->GetXaxis()->SetLabelFont(42);
   Graph_Graph98->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph98->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph98->GetXaxis()->SetTitleFont(42);
   Graph_Graph98->GetYaxis()->SetNdivisions(506);
   Graph_Graph98->GetYaxis()->SetLabelFont(42);
   Graph_Graph98->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph98->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph98->GetYaxis()->SetTitleFont(42);
   Graph_Graph98->GetZaxis()->SetNdivisions(506);
   Graph_Graph98->GetZaxis()->SetLabelFont(42);
   Graph_Graph98->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph98->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph98->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph98);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx99[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy99[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx99,Graph_fy99);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph99 = new TH1F("Graph_Graph99","Graph",100,0.75,0.87);
   Graph_Graph99->SetMinimum(0);
   Graph_Graph99->SetMaximum(0.33);
   Graph_Graph99->SetDirectory(0);
   Graph_Graph99->SetStats(0);
   Graph_Graph99->SetLineWidth(2);
   Graph_Graph99->GetXaxis()->SetNdivisions(506);
   Graph_Graph99->GetXaxis()->SetLabelFont(42);
   Graph_Graph99->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph99->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph99->GetXaxis()->SetTitleFont(42);
   Graph_Graph99->GetYaxis()->SetNdivisions(506);
   Graph_Graph99->GetYaxis()->SetLabelFont(42);
   Graph_Graph99->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph99->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph99->GetYaxis()->SetTitleFont(42);
   Graph_Graph99->GetZaxis()->SetNdivisions(506);
   Graph_Graph99->GetZaxis()->SetLabelFont(42);
   Graph_Graph99->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph99->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph99->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph99);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx100[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy100[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx100,Graph_fy100);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph100 = new TH1F("Graph_Graph100","Graph",100,0.852,0.948);
   Graph_Graph100->SetMinimum(0);
   Graph_Graph100->SetMaximum(0.33);
   Graph_Graph100->SetDirectory(0);
   Graph_Graph100->SetStats(0);
   Graph_Graph100->SetLineWidth(2);
   Graph_Graph100->GetXaxis()->SetNdivisions(506);
   Graph_Graph100->GetXaxis()->SetLabelFont(42);
   Graph_Graph100->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph100->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph100->GetXaxis()->SetTitleFont(42);
   Graph_Graph100->GetYaxis()->SetNdivisions(506);
   Graph_Graph100->GetYaxis()->SetLabelFont(42);
   Graph_Graph100->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph100->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph100->GetYaxis()->SetTitleFont(42);
   Graph_Graph100->GetZaxis()->SetNdivisions(506);
   Graph_Graph100->GetZaxis()->SetLabelFont(42);
   Graph_Graph100->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph100->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph100->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph100);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx101[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy101[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx101,Graph_fy101);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001890");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph101 = new TH1F("Graph_Graph101","Graph",100,0.934,1.006);
   Graph_Graph101->SetMinimum(0);
   Graph_Graph101->SetMaximum(0.33);
   Graph_Graph101->SetDirectory(0);
   Graph_Graph101->SetStats(0);
   Graph_Graph101->SetLineWidth(2);
   Graph_Graph101->GetXaxis()->SetNdivisions(506);
   Graph_Graph101->GetXaxis()->SetLabelFont(42);
   Graph_Graph101->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph101->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph101->GetXaxis()->SetTitleFont(42);
   Graph_Graph101->GetYaxis()->SetNdivisions(506);
   Graph_Graph101->GetYaxis()->SetLabelFont(42);
   Graph_Graph101->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph101->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph101->GetYaxis()->SetTitleFont(42);
   Graph_Graph101->GetZaxis()->SetNdivisions(506);
   Graph_Graph101->GetZaxis()->SetLabelFont(42);
   Graph_Graph101->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph101->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph101->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph101);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx102[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy102[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx102,Graph_fy102);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001890");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph102 = new TH1F("Graph_Graph102","Graph",100,-1.1,0);
   Graph_Graph102->SetMinimum(0.285);
   Graph_Graph102->SetMaximum(0.465);
   Graph_Graph102->SetDirectory(0);
   Graph_Graph102->SetStats(0);
   Graph_Graph102->SetLineWidth(2);
   Graph_Graph102->GetXaxis()->SetNdivisions(506);
   Graph_Graph102->GetXaxis()->SetLabelFont(42);
   Graph_Graph102->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph102->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph102->GetXaxis()->SetTitleFont(42);
   Graph_Graph102->GetYaxis()->SetNdivisions(506);
   Graph_Graph102->GetYaxis()->SetLabelFont(42);
   Graph_Graph102->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph102->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph102->GetYaxis()->SetTitleFont(42);
   Graph_Graph102->GetZaxis()->SetNdivisions(506);
   Graph_Graph102->GetZaxis()->SetLabelFont(42);
   Graph_Graph102->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph102->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph102->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph102);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx103[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy103[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx103,Graph_fy103);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001890");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph103 = new TH1F("Graph_Graph103","Graph",100,0,0.297);
   Graph_Graph103->SetMinimum(0.285);
   Graph_Graph103->SetMaximum(0.465);
   Graph_Graph103->SetDirectory(0);
   Graph_Graph103->SetStats(0);
   Graph_Graph103->SetLineWidth(2);
   Graph_Graph103->GetXaxis()->SetNdivisions(506);
   Graph_Graph103->GetXaxis()->SetLabelFont(42);
   Graph_Graph103->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph103->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph103->GetXaxis()->SetTitleFont(42);
   Graph_Graph103->GetYaxis()->SetNdivisions(506);
   Graph_Graph103->GetYaxis()->SetLabelFont(42);
   Graph_Graph103->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph103->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph103->GetYaxis()->SetTitleFont(42);
   Graph_Graph103->GetZaxis()->SetNdivisions(506);
   Graph_Graph103->GetZaxis()->SetLabelFont(42);
   Graph_Graph103->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph103->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph103->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph103);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx104[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy104[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx104,Graph_fy104);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002699");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph104 = new TH1F("Graph_Graph104","Graph",100,0.252,0.468);
   Graph_Graph104->SetMinimum(0.285);
   Graph_Graph104->SetMaximum(0.465);
   Graph_Graph104->SetDirectory(0);
   Graph_Graph104->SetStats(0);
   Graph_Graph104->SetLineWidth(2);
   Graph_Graph104->GetXaxis()->SetNdivisions(506);
   Graph_Graph104->GetXaxis()->SetLabelFont(42);
   Graph_Graph104->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph104->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph104->GetXaxis()->SetTitleFont(42);
   Graph_Graph104->GetYaxis()->SetNdivisions(506);
   Graph_Graph104->GetYaxis()->SetLabelFont(42);
   Graph_Graph104->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph104->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph104->GetYaxis()->SetTitleFont(42);
   Graph_Graph104->GetZaxis()->SetNdivisions(506);
   Graph_Graph104->GetZaxis()->SetLabelFont(42);
   Graph_Graph104->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph104->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph104->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph104);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx105[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy105[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx105,Graph_fy105);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#9df05f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph105 = new TH1F("Graph_Graph105","Graph",100,0.433,0.637);
   Graph_Graph105->SetMinimum(0.285);
   Graph_Graph105->SetMaximum(0.465);
   Graph_Graph105->SetDirectory(0);
   Graph_Graph105->SetStats(0);
   Graph_Graph105->SetLineWidth(2);
   Graph_Graph105->GetXaxis()->SetNdivisions(506);
   Graph_Graph105->GetXaxis()->SetLabelFont(42);
   Graph_Graph105->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph105->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph105->GetXaxis()->SetTitleFont(42);
   Graph_Graph105->GetYaxis()->SetNdivisions(506);
   Graph_Graph105->GetYaxis()->SetLabelFont(42);
   Graph_Graph105->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph105->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph105->GetYaxis()->SetTitleFont(42);
   Graph_Graph105->GetZaxis()->SetNdivisions(506);
   Graph_Graph105->GetZaxis()->SetLabelFont(42);
   Graph_Graph105->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph105->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph105->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph105);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx106[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy106[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx106,Graph_fy106);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph106 = new TH1F("Graph_Graph106","Graph",100,0.606,0.774);
   Graph_Graph106->SetMinimum(0.285);
   Graph_Graph106->SetMaximum(0.465);
   Graph_Graph106->SetDirectory(0);
   Graph_Graph106->SetStats(0);
   Graph_Graph106->SetLineWidth(2);
   Graph_Graph106->GetXaxis()->SetNdivisions(506);
   Graph_Graph106->GetXaxis()->SetLabelFont(42);
   Graph_Graph106->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph106->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph106->GetXaxis()->SetTitleFont(42);
   Graph_Graph106->GetYaxis()->SetNdivisions(506);
   Graph_Graph106->GetYaxis()->SetLabelFont(42);
   Graph_Graph106->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph106->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph106->GetYaxis()->SetTitleFont(42);
   Graph_Graph106->GetZaxis()->SetNdivisions(506);
   Graph_Graph106->GetZaxis()->SetLabelFont(42);
   Graph_Graph106->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph106->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph106->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph106);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx107[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy107[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx107,Graph_fy107);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001890");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph107 = new TH1F("Graph_Graph107","Graph",100,0.75,0.87);
   Graph_Graph107->SetMinimum(0.285);
   Graph_Graph107->SetMaximum(0.465);
   Graph_Graph107->SetDirectory(0);
   Graph_Graph107->SetStats(0);
   Graph_Graph107->SetLineWidth(2);
   Graph_Graph107->GetXaxis()->SetNdivisions(506);
   Graph_Graph107->GetXaxis()->SetLabelFont(42);
   Graph_Graph107->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph107->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph107->GetXaxis()->SetTitleFont(42);
   Graph_Graph107->GetYaxis()->SetNdivisions(506);
   Graph_Graph107->GetYaxis()->SetLabelFont(42);
   Graph_Graph107->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph107->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph107->GetYaxis()->SetTitleFont(42);
   Graph_Graph107->GetZaxis()->SetNdivisions(506);
   Graph_Graph107->GetZaxis()->SetLabelFont(42);
   Graph_Graph107->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph107->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph107->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph107);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx108[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy108[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx108,Graph_fy108);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002699");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph108 = new TH1F("Graph_Graph108","Graph",100,0.852,0.948);
   Graph_Graph108->SetMinimum(0.285);
   Graph_Graph108->SetMaximum(0.465);
   Graph_Graph108->SetDirectory(0);
   Graph_Graph108->SetStats(0);
   Graph_Graph108->SetLineWidth(2);
   Graph_Graph108->GetXaxis()->SetNdivisions(506);
   Graph_Graph108->GetXaxis()->SetLabelFont(42);
   Graph_Graph108->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph108->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph108->GetXaxis()->SetTitleFont(42);
   Graph_Graph108->GetYaxis()->SetNdivisions(506);
   Graph_Graph108->GetYaxis()->SetLabelFont(42);
   Graph_Graph108->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph108->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph108->GetYaxis()->SetTitleFont(42);
   Graph_Graph108->GetZaxis()->SetNdivisions(506);
   Graph_Graph108->GetZaxis()->SetLabelFont(42);
   Graph_Graph108->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph108->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph108->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph108);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx109[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy109[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx109,Graph_fy109);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002497");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph109 = new TH1F("Graph_Graph109","Graph",100,0.934,1.006);
   Graph_Graph109->SetMinimum(0.285);
   Graph_Graph109->SetMaximum(0.465);
   Graph_Graph109->SetDirectory(0);
   Graph_Graph109->SetStats(0);
   Graph_Graph109->SetLineWidth(2);
   Graph_Graph109->GetXaxis()->SetNdivisions(506);
   Graph_Graph109->GetXaxis()->SetLabelFont(42);
   Graph_Graph109->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph109->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph109->GetXaxis()->SetTitleFont(42);
   Graph_Graph109->GetYaxis()->SetNdivisions(506);
   Graph_Graph109->GetYaxis()->SetLabelFont(42);
   Graph_Graph109->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph109->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph109->GetYaxis()->SetTitleFont(42);
   Graph_Graph109->GetZaxis()->SetNdivisions(506);
   Graph_Graph109->GetZaxis()->SetLabelFont(42);
   Graph_Graph109->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph109->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph109->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph109);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx110[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy110[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx110,Graph_fy110);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001890");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph110 = new TH1F("Graph_Graph110","Graph",100,-1.1,0);
   Graph_Graph110->SetMinimum(0.245);
   Graph_Graph110->SetMaximum(2.705);
   Graph_Graph110->SetDirectory(0);
   Graph_Graph110->SetStats(0);
   Graph_Graph110->SetLineWidth(2);
   Graph_Graph110->GetXaxis()->SetNdivisions(506);
   Graph_Graph110->GetXaxis()->SetLabelFont(42);
   Graph_Graph110->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph110->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph110->GetXaxis()->SetTitleFont(42);
   Graph_Graph110->GetYaxis()->SetNdivisions(506);
   Graph_Graph110->GetYaxis()->SetLabelFont(42);
   Graph_Graph110->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph110->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph110->GetYaxis()->SetTitleFont(42);
   Graph_Graph110->GetZaxis()->SetNdivisions(506);
   Graph_Graph110->GetZaxis()->SetLabelFont(42);
   Graph_Graph110->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph110->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph110->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph110);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx111[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy111[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx111,Graph_fy111);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001890");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph111 = new TH1F("Graph_Graph111","Graph",100,0,0.297);
   Graph_Graph111->SetMinimum(0.418);
   Graph_Graph111->SetMaximum(0.802);
   Graph_Graph111->SetDirectory(0);
   Graph_Graph111->SetStats(0);
   Graph_Graph111->SetLineWidth(2);
   Graph_Graph111->GetXaxis()->SetNdivisions(506);
   Graph_Graph111->GetXaxis()->SetLabelFont(42);
   Graph_Graph111->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph111->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph111->GetXaxis()->SetTitleFont(42);
   Graph_Graph111->GetYaxis()->SetNdivisions(506);
   Graph_Graph111->GetYaxis()->SetLabelFont(42);
   Graph_Graph111->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph111->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph111->GetYaxis()->SetTitleFont(42);
   Graph_Graph111->GetZaxis()->SetNdivisions(506);
   Graph_Graph111->GetZaxis()->SetLabelFont(42);
   Graph_Graph111->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph111->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph111->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph111);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx112[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy112[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx112,Graph_fy112);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph112 = new TH1F("Graph_Graph112","Graph",100,0.252,0.468);
   Graph_Graph112->SetMinimum(0.418);
   Graph_Graph112->SetMaximum(0.802);
   Graph_Graph112->SetDirectory(0);
   Graph_Graph112->SetStats(0);
   Graph_Graph112->SetLineWidth(2);
   Graph_Graph112->GetXaxis()->SetNdivisions(506);
   Graph_Graph112->GetXaxis()->SetLabelFont(42);
   Graph_Graph112->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph112->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph112->GetXaxis()->SetTitleFont(42);
   Graph_Graph112->GetYaxis()->SetNdivisions(506);
   Graph_Graph112->GetYaxis()->SetLabelFont(42);
   Graph_Graph112->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph112->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph112->GetYaxis()->SetTitleFont(42);
   Graph_Graph112->GetZaxis()->SetNdivisions(506);
   Graph_Graph112->GetZaxis()->SetLabelFont(42);
   Graph_Graph112->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph112->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph112->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph112);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx113[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy113[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx113,Graph_fy113);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph113 = new TH1F("Graph_Graph113","Graph",100,0.433,0.637);
   Graph_Graph113->SetMinimum(0.418);
   Graph_Graph113->SetMaximum(0.802);
   Graph_Graph113->SetDirectory(0);
   Graph_Graph113->SetStats(0);
   Graph_Graph113->SetLineWidth(2);
   Graph_Graph113->GetXaxis()->SetNdivisions(506);
   Graph_Graph113->GetXaxis()->SetLabelFont(42);
   Graph_Graph113->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph113->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph113->GetXaxis()->SetTitleFont(42);
   Graph_Graph113->GetYaxis()->SetNdivisions(506);
   Graph_Graph113->GetYaxis()->SetLabelFont(42);
   Graph_Graph113->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph113->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph113->GetYaxis()->SetTitleFont(42);
   Graph_Graph113->GetZaxis()->SetNdivisions(506);
   Graph_Graph113->GetZaxis()->SetLabelFont(42);
   Graph_Graph113->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph113->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph113->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph113);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx114[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy114[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx114,Graph_fy114);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph114 = new TH1F("Graph_Graph114","Graph",100,0.606,0.774);
   Graph_Graph114->SetMinimum(0.418);
   Graph_Graph114->SetMaximum(0.802);
   Graph_Graph114->SetDirectory(0);
   Graph_Graph114->SetStats(0);
   Graph_Graph114->SetLineWidth(2);
   Graph_Graph114->GetXaxis()->SetNdivisions(506);
   Graph_Graph114->GetXaxis()->SetLabelFont(42);
   Graph_Graph114->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph114->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph114->GetXaxis()->SetTitleFont(42);
   Graph_Graph114->GetYaxis()->SetNdivisions(506);
   Graph_Graph114->GetYaxis()->SetLabelFont(42);
   Graph_Graph114->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph114->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph114->GetYaxis()->SetTitleFont(42);
   Graph_Graph114->GetZaxis()->SetNdivisions(506);
   Graph_Graph114->GetZaxis()->SetLabelFont(42);
   Graph_Graph114->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph114->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph114->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph114);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx115[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy115[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx115,Graph_fy115);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph115 = new TH1F("Graph_Graph115","Graph",100,0.75,0.87);
   Graph_Graph115->SetMinimum(0.418);
   Graph_Graph115->SetMaximum(0.802);
   Graph_Graph115->SetDirectory(0);
   Graph_Graph115->SetStats(0);
   Graph_Graph115->SetLineWidth(2);
   Graph_Graph115->GetXaxis()->SetNdivisions(506);
   Graph_Graph115->GetXaxis()->SetLabelFont(42);
   Graph_Graph115->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph115->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph115->GetXaxis()->SetTitleFont(42);
   Graph_Graph115->GetYaxis()->SetNdivisions(506);
   Graph_Graph115->GetYaxis()->SetLabelFont(42);
   Graph_Graph115->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph115->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph115->GetYaxis()->SetTitleFont(42);
   Graph_Graph115->GetZaxis()->SetNdivisions(506);
   Graph_Graph115->GetZaxis()->SetLabelFont(42);
   Graph_Graph115->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph115->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph115->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph115);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx116[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy116[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx116,Graph_fy116);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph116 = new TH1F("Graph_Graph116","Graph",100,0.852,0.948);
   Graph_Graph116->SetMinimum(0.418);
   Graph_Graph116->SetMaximum(0.802);
   Graph_Graph116->SetDirectory(0);
   Graph_Graph116->SetStats(0);
   Graph_Graph116->SetLineWidth(2);
   Graph_Graph116->GetXaxis()->SetNdivisions(506);
   Graph_Graph116->GetXaxis()->SetLabelFont(42);
   Graph_Graph116->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph116->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph116->GetXaxis()->SetTitleFont(42);
   Graph_Graph116->GetYaxis()->SetNdivisions(506);
   Graph_Graph116->GetYaxis()->SetLabelFont(42);
   Graph_Graph116->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph116->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph116->GetYaxis()->SetTitleFont(42);
   Graph_Graph116->GetZaxis()->SetNdivisions(506);
   Graph_Graph116->GetZaxis()->SetLabelFont(42);
   Graph_Graph116->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph116->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph116->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph116);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx117[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy117[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx117,Graph_fy117);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph117 = new TH1F("Graph_Graph117","Graph",100,0.934,1.006);
   Graph_Graph117->SetMinimum(0.418);
   Graph_Graph117->SetMaximum(0.802);
   Graph_Graph117->SetDirectory(0);
   Graph_Graph117->SetStats(0);
   Graph_Graph117->SetLineWidth(2);
   Graph_Graph117->GetXaxis()->SetNdivisions(506);
   Graph_Graph117->GetXaxis()->SetLabelFont(42);
   Graph_Graph117->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph117->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph117->GetXaxis()->SetTitleFont(42);
   Graph_Graph117->GetYaxis()->SetNdivisions(506);
   Graph_Graph117->GetYaxis()->SetLabelFont(42);
   Graph_Graph117->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph117->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph117->GetYaxis()->SetTitleFont(42);
   Graph_Graph117->GetZaxis()->SetNdivisions(506);
   Graph_Graph117->GetZaxis()->SetLabelFont(42);
   Graph_Graph117->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph117->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph117->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph117);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx118[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy118[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx118,Graph_fy118);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph118 = new TH1F("Graph_Graph118","Graph",100,0,0.297);
   Graph_Graph118->SetMinimum(0.597);
   Graph_Graph118->SetMaximum(2.673);
   Graph_Graph118->SetDirectory(0);
   Graph_Graph118->SetStats(0);
   Graph_Graph118->SetLineWidth(2);
   Graph_Graph118->GetXaxis()->SetNdivisions(506);
   Graph_Graph118->GetXaxis()->SetLabelFont(42);
   Graph_Graph118->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph118->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph118->GetXaxis()->SetTitleFont(42);
   Graph_Graph118->GetYaxis()->SetNdivisions(506);
   Graph_Graph118->GetYaxis()->SetLabelFont(42);
   Graph_Graph118->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph118->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph118->GetYaxis()->SetTitleFont(42);
   Graph_Graph118->GetZaxis()->SetNdivisions(506);
   Graph_Graph118->GetZaxis()->SetLabelFont(42);
   Graph_Graph118->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph118->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph118->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph118);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx119[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy119[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx119,Graph_fy119);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph119 = new TH1F("Graph_Graph119","Graph",100,0.252,0.468);
   Graph_Graph119->SetMinimum(0.597);
   Graph_Graph119->SetMaximum(2.673);
   Graph_Graph119->SetDirectory(0);
   Graph_Graph119->SetStats(0);
   Graph_Graph119->SetLineWidth(2);
   Graph_Graph119->GetXaxis()->SetNdivisions(506);
   Graph_Graph119->GetXaxis()->SetLabelFont(42);
   Graph_Graph119->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph119->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph119->GetXaxis()->SetTitleFont(42);
   Graph_Graph119->GetYaxis()->SetNdivisions(506);
   Graph_Graph119->GetYaxis()->SetLabelFont(42);
   Graph_Graph119->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph119->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph119->GetYaxis()->SetTitleFont(42);
   Graph_Graph119->GetZaxis()->SetNdivisions(506);
   Graph_Graph119->GetZaxis()->SetLabelFont(42);
   Graph_Graph119->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph119->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph119->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph119);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx120[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy120[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx120,Graph_fy120);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph120 = new TH1F("Graph_Graph120","Graph",100,0.433,0.637);
   Graph_Graph120->SetMinimum(0.597);
   Graph_Graph120->SetMaximum(2.673);
   Graph_Graph120->SetDirectory(0);
   Graph_Graph120->SetStats(0);
   Graph_Graph120->SetLineWidth(2);
   Graph_Graph120->GetXaxis()->SetNdivisions(506);
   Graph_Graph120->GetXaxis()->SetLabelFont(42);
   Graph_Graph120->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph120->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph120->GetXaxis()->SetTitleFont(42);
   Graph_Graph120->GetYaxis()->SetNdivisions(506);
   Graph_Graph120->GetYaxis()->SetLabelFont(42);
   Graph_Graph120->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph120->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph120->GetYaxis()->SetTitleFont(42);
   Graph_Graph120->GetZaxis()->SetNdivisions(506);
   Graph_Graph120->GetZaxis()->SetLabelFont(42);
   Graph_Graph120->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph120->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph120->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph120);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx121[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy121[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx121,Graph_fy121);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph121 = new TH1F("Graph_Graph121","Graph",100,0.606,0.774);
   Graph_Graph121->SetMinimum(0.597);
   Graph_Graph121->SetMaximum(2.673);
   Graph_Graph121->SetDirectory(0);
   Graph_Graph121->SetStats(0);
   Graph_Graph121->SetLineWidth(2);
   Graph_Graph121->GetXaxis()->SetNdivisions(506);
   Graph_Graph121->GetXaxis()->SetLabelFont(42);
   Graph_Graph121->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph121->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph121->GetXaxis()->SetTitleFont(42);
   Graph_Graph121->GetYaxis()->SetNdivisions(506);
   Graph_Graph121->GetYaxis()->SetLabelFont(42);
   Graph_Graph121->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph121->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph121->GetYaxis()->SetTitleFont(42);
   Graph_Graph121->GetZaxis()->SetNdivisions(506);
   Graph_Graph121->GetZaxis()->SetLabelFont(42);
   Graph_Graph121->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph121->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph121->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph121);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx122[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy122[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx122,Graph_fy122);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph122 = new TH1F("Graph_Graph122","Graph",100,0.75,0.87);
   Graph_Graph122->SetMinimum(0.597);
   Graph_Graph122->SetMaximum(2.673);
   Graph_Graph122->SetDirectory(0);
   Graph_Graph122->SetStats(0);
   Graph_Graph122->SetLineWidth(2);
   Graph_Graph122->GetXaxis()->SetNdivisions(506);
   Graph_Graph122->GetXaxis()->SetLabelFont(42);
   Graph_Graph122->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph122->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph122->GetXaxis()->SetTitleFont(42);
   Graph_Graph122->GetYaxis()->SetNdivisions(506);
   Graph_Graph122->GetYaxis()->SetLabelFont(42);
   Graph_Graph122->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph122->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph122->GetYaxis()->SetTitleFont(42);
   Graph_Graph122->GetZaxis()->SetNdivisions(506);
   Graph_Graph122->GetZaxis()->SetLabelFont(42);
   Graph_Graph122->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph122->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph122->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph122);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx123[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy123[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx123,Graph_fy123);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph123 = new TH1F("Graph_Graph123","Graph",100,0.852,0.948);
   Graph_Graph123->SetMinimum(0.597);
   Graph_Graph123->SetMaximum(2.673);
   Graph_Graph123->SetDirectory(0);
   Graph_Graph123->SetStats(0);
   Graph_Graph123->SetLineWidth(2);
   Graph_Graph123->GetXaxis()->SetNdivisions(506);
   Graph_Graph123->GetXaxis()->SetLabelFont(42);
   Graph_Graph123->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph123->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph123->GetXaxis()->SetTitleFont(42);
   Graph_Graph123->GetYaxis()->SetNdivisions(506);
   Graph_Graph123->GetYaxis()->SetLabelFont(42);
   Graph_Graph123->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph123->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph123->GetYaxis()->SetTitleFont(42);
   Graph_Graph123->GetZaxis()->SetNdivisions(506);
   Graph_Graph123->GetZaxis()->SetLabelFont(42);
   Graph_Graph123->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph123->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph123->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph123);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx124[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy124[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx124,Graph_fy124);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph124 = new TH1F("Graph_Graph124","Graph",100,0.934,1.006);
   Graph_Graph124->SetMinimum(0.597);
   Graph_Graph124->SetMaximum(2.673);
   Graph_Graph124->SetDirectory(0);
   Graph_Graph124->SetStats(0);
   Graph_Graph124->SetLineWidth(2);
   Graph_Graph124->GetXaxis()->SetNdivisions(506);
   Graph_Graph124->GetXaxis()->SetLabelFont(42);
   Graph_Graph124->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph124->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph124->GetXaxis()->SetTitleFont(42);
   Graph_Graph124->GetYaxis()->SetNdivisions(506);
   Graph_Graph124->GetYaxis()->SetLabelFont(42);
   Graph_Graph124->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph124->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph124->GetYaxis()->SetTitleFont(42);
   Graph_Graph124->GetZaxis()->SetNdivisions(506);
   Graph_Graph124->GetZaxis()->SetLabelFont(42);
   Graph_Graph124->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph124->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph124->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph124);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.06862283);
   _reco_per_true->SetBinContent(2,0.01148117);
   _reco_per_true->SetBinContent(3,0.160181);
   _reco_per_true->SetBinContent(4,0.2684606);
   _reco_per_true->SetBinContent(5,0.1831076);
   _reco_per_true->SetBinContent(8,0.01147924);
   _reco_per_true->SetBinContent(9,0.01141405);
   _reco_per_true->SetBinContent(10,0.01141696);
   _reco_per_true->SetBinContent(11,0.01719693);
   _reco_per_true->SetBinContent(12,0.1431232);
   _reco_per_true->SetBinContent(13,0.005728126);
   _reco_per_true->SetBinContent(14,0.01141528);
   _reco_per_true->SetBinContent(15,0.01718465);
   _reco_per_true->SetBinContent(16,0.01637518);
   _reco_per_true->SetBinContent(17,0.0114361);
   _reco_per_true->SetBinContent(18,0.01134581);
   _reco_per_true->SetBinContent(20,0.005721506);
   _reco_per_true->SetBinContent(22,0.005710425);
   _reco_per_true->SetBinContent(23,0.005700996);
   _reco_per_true->SetBinContent(26,0.005727634);
   _reco_per_true->SetBinContent(28,0.005710425);
   _reco_per_true->SetBinContent(30,0.005752784);
   _reco_per_true->SetBinContent(31,0.005707516);
   _reco_per_true->SetBinError(1,0.01980976);
   _reco_per_true->SetBinError(2,0.008118439);
   _reco_per_true->SetBinError(3,0.03027165);
   _reco_per_true->SetBinError(4,0.03916187);
   _reco_per_true->SetBinError(5,0.03236941);
   _reco_per_true->SetBinError(8,0.008117071);
   _reco_per_true->SetBinError(9,0.008070952);
   _reco_per_true->SetBinError(10,0.008073053);
   _reco_per_true->SetBinError(11,0.009928666);
   _reco_per_true->SetBinError(12,0.02862479);
   _reco_per_true->SetBinError(13,0.005728126);
   _reco_per_true->SetBinError(14,0.008071824);
   _reco_per_true->SetBinError(15,0.009921622);
   _reco_per_true->SetBinError(16,0.009468723);
   _reco_per_true->SetBinError(17,0.00808664);
   _reco_per_true->SetBinError(18,0.008023038);
   _reco_per_true->SetBinError(20,0.005721506);
   _reco_per_true->SetBinError(22,0.005710425);
   _reco_per_true->SetBinError(23,0.005700996);
   _reco_per_true->SetBinError(26,0.005727634);
   _reco_per_true->SetBinError(28,0.005710425);
   _reco_per_true->SetBinError(30,0.005752784);
   _reco_per_true->SetBinError(31,0.005707516);
   _reco_per_true->SetEntries(175);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.001052787);
   _reco_per_true->SetContourLevel(2,0.002105574);
   _reco_per_true->SetContourLevel(3,0.00315836);
   _reco_per_true->SetContourLevel(4,0.004211147);
   _reco_per_true->SetContourLevel(5,0.005263934);
   _reco_per_true->SetContourLevel(6,0.006316721);
   _reco_per_true->SetContourLevel(7,0.007369507);
   _reco_per_true->SetContourLevel(8,0.008422294);
   _reco_per_true->SetContourLevel(9,0.009475081);
   _reco_per_true->SetContourLevel(10,0.01052787);
   _reco_per_true->SetContourLevel(11,0.01158065);
   _reco_per_true->SetContourLevel(12,0.01263344);
   _reco_per_true->SetContourLevel(13,0.01368623);
   _reco_per_true->SetContourLevel(14,0.01473901);
   _reco_per_true->SetContourLevel(15,0.0157918);
   _reco_per_true->SetContourLevel(16,0.01684459);
   _reco_per_true->SetContourLevel(17,0.01789737);
   _reco_per_true->SetContourLevel(18,0.01895016);
   _reco_per_true->SetContourLevel(19,0.02000295);
   _reco_per_true->SetContourLevel(20,0.02105574);
   _reco_per_true->SetContourLevel(21,0.02210852);
   _reco_per_true->SetContourLevel(22,0.02316131);
   _reco_per_true->SetContourLevel(23,0.0242141);
   _reco_per_true->SetContourLevel(24,0.02526688);
   _reco_per_true->SetContourLevel(25,0.02631967);
   _reco_per_true->SetContourLevel(26,0.02737246);
   _reco_per_true->SetContourLevel(27,0.02842524);
   _reco_per_true->SetContourLevel(28,0.02947803);
   _reco_per_true->SetContourLevel(29,0.03053082);
   _reco_per_true->SetContourLevel(30,0.0315836);
   _reco_per_true->SetContourLevel(31,0.03263639);
   _reco_per_true->SetContourLevel(32,0.03368918);
   _reco_per_true->SetContourLevel(33,0.03474196);
   _reco_per_true->SetContourLevel(34,0.03579475);
   _reco_per_true->SetContourLevel(35,0.03684754);
   _reco_per_true->SetContourLevel(36,0.03790032);
   _reco_per_true->SetContourLevel(37,0.03895311);
   _reco_per_true->SetContourLevel(38,0.0400059);
   _reco_per_true->SetContourLevel(39,0.04105868);
   _reco_per_true->SetContourLevel(40,0.04211147);
   _reco_per_true->SetContourLevel(41,0.04316426);
   _reco_per_true->SetContourLevel(42,0.04421704);
   _reco_per_true->SetContourLevel(43,0.04526983);
   _reco_per_true->SetContourLevel(44,0.04632262);
   _reco_per_true->SetContourLevel(45,0.0473754);
   _reco_per_true->SetContourLevel(46,0.04842819);
   _reco_per_true->SetContourLevel(47,0.04948098);
   _reco_per_true->SetContourLevel(48,0.05053376);
   _reco_per_true->SetContourLevel(49,0.05158655);
   _reco_per_true->SetContourLevel(50,0.05263934);
   _reco_per_true->SetContourLevel(51,0.05369212);
   _reco_per_true->SetContourLevel(52,0.05474491);
   _reco_per_true->SetContourLevel(53,0.0557977);
   _reco_per_true->SetContourLevel(54,0.05685048);
   _reco_per_true->SetContourLevel(55,0.05790327);
   _reco_per_true->SetContourLevel(56,0.05895606);
   _reco_per_true->SetContourLevel(57,0.06000884);
   _reco_per_true->SetContourLevel(58,0.06106163);
   _reco_per_true->SetContourLevel(59,0.06211442);
   _reco_per_true->SetContourLevel(60,0.06316721);
   _reco_per_true->SetContourLevel(61,0.06421999);
   _reco_per_true->SetContourLevel(62,0.06527278);
   _reco_per_true->SetContourLevel(63,0.06632557);
   _reco_per_true->SetContourLevel(64,0.06737835);
   _reco_per_true->SetContourLevel(65,0.06843114);
   _reco_per_true->SetContourLevel(66,0.06948393);
   _reco_per_true->SetContourLevel(67,0.07053671);
   _reco_per_true->SetContourLevel(68,0.0715895);
   _reco_per_true->SetContourLevel(69,0.07264229);
   _reco_per_true->SetContourLevel(70,0.07369507);
   _reco_per_true->SetContourLevel(71,0.07474786);
   _reco_per_true->SetContourLevel(72,0.07580065);
   _reco_per_true->SetContourLevel(73,0.07685343);
   _reco_per_true->SetContourLevel(74,0.07790622);
   _reco_per_true->SetContourLevel(75,0.07895901);
   _reco_per_true->SetContourLevel(76,0.08001179);
   _reco_per_true->SetContourLevel(77,0.08106458);
   _reco_per_true->SetContourLevel(78,0.08211737);
   _reco_per_true->SetContourLevel(79,0.08317015);
   _reco_per_true->SetContourLevel(80,0.08422294);
   _reco_per_true->SetContourLevel(81,0.08527573);
   _reco_per_true->SetContourLevel(82,0.08632851);
   _reco_per_true->SetContourLevel(83,0.0873813);
   _reco_per_true->SetContourLevel(84,0.08843409);
   _reco_per_true->SetContourLevel(85,0.08948687);
   _reco_per_true->SetContourLevel(86,0.09053966);
   _reco_per_true->SetContourLevel(87,0.09159245);
   _reco_per_true->SetContourLevel(88,0.09264523);
   _reco_per_true->SetContourLevel(89,0.09369802);
   _reco_per_true->SetContourLevel(90,0.09475081);
   _reco_per_true->SetContourLevel(91,0.09580359);
   _reco_per_true->SetContourLevel(92,0.09685638);
   _reco_per_true->SetContourLevel(93,0.09790917);
   _reco_per_true->SetContourLevel(94,0.09896195);
   _reco_per_true->SetContourLevel(95,0.1000147);
   _reco_per_true->SetContourLevel(96,0.1010675);
   _reco_per_true->SetContourLevel(97,0.1021203);
   _reco_per_true->SetContourLevel(98,0.1031731);
   _reco_per_true->SetContourLevel(99,0.1042259);
   _reco_per_true->SetContourLevel(100,0.1052787);
   _reco_per_true->SetContourLevel(101,0.1063315);
   _reco_per_true->SetContourLevel(102,0.1073842);
   _reco_per_true->SetContourLevel(103,0.108437);
   _reco_per_true->SetContourLevel(104,0.1094898);
   _reco_per_true->SetContourLevel(105,0.1105426);
   _reco_per_true->SetContourLevel(106,0.1115954);
   _reco_per_true->SetContourLevel(107,0.1126482);
   _reco_per_true->SetContourLevel(108,0.113701);
   _reco_per_true->SetContourLevel(109,0.1147538);
   _reco_per_true->SetContourLevel(110,0.1158065);
   _reco_per_true->SetContourLevel(111,0.1168593);
   _reco_per_true->SetContourLevel(112,0.1179121);
   _reco_per_true->SetContourLevel(113,0.1189649);
   _reco_per_true->SetContourLevel(114,0.1200177);
   _reco_per_true->SetContourLevel(115,0.1210705);
   _reco_per_true->SetContourLevel(116,0.1221233);
   _reco_per_true->SetContourLevel(117,0.1231761);
   _reco_per_true->SetContourLevel(118,0.1242288);
   _reco_per_true->SetContourLevel(119,0.1252816);
   _reco_per_true->SetContourLevel(120,0.1263344);
   _reco_per_true->SetContourLevel(121,0.1273872);
   _reco_per_true->SetContourLevel(122,0.12844);
   _reco_per_true->SetContourLevel(123,0.1294928);
   _reco_per_true->SetContourLevel(124,0.1305456);
   _reco_per_true->SetContourLevel(125,0.1315983);
   _reco_per_true->SetContourLevel(126,0.1326511);
   _reco_per_true->SetContourLevel(127,0.1337039);
   _reco_per_true->SetContourLevel(128,0.1347567);
   _reco_per_true->SetContourLevel(129,0.1358095);
   _reco_per_true->SetContourLevel(130,0.1368623);
   _reco_per_true->SetContourLevel(131,0.1379151);
   _reco_per_true->SetContourLevel(132,0.1389679);
   _reco_per_true->SetContourLevel(133,0.1400206);
   _reco_per_true->SetContourLevel(134,0.1410734);
   _reco_per_true->SetContourLevel(135,0.1421262);
   _reco_per_true->SetContourLevel(136,0.143179);
   _reco_per_true->SetContourLevel(137,0.1442318);
   _reco_per_true->SetContourLevel(138,0.1452846);
   _reco_per_true->SetContourLevel(139,0.1463374);
   _reco_per_true->SetContourLevel(140,0.1473901);
   _reco_per_true->SetContourLevel(141,0.1484429);
   _reco_per_true->SetContourLevel(142,0.1494957);
   _reco_per_true->SetContourLevel(143,0.1505485);
   _reco_per_true->SetContourLevel(144,0.1516013);
   _reco_per_true->SetContourLevel(145,0.1526541);
   _reco_per_true->SetContourLevel(146,0.1537069);
   _reco_per_true->SetContourLevel(147,0.1547597);
   _reco_per_true->SetContourLevel(148,0.1558124);
   _reco_per_true->SetContourLevel(149,0.1568652);
   _reco_per_true->SetContourLevel(150,0.157918);
   _reco_per_true->SetContourLevel(151,0.1589708);
   _reco_per_true->SetContourLevel(152,0.1600236);
   _reco_per_true->SetContourLevel(153,0.1610764);
   _reco_per_true->SetContourLevel(154,0.1621292);
   _reco_per_true->SetContourLevel(155,0.1631819);
   _reco_per_true->SetContourLevel(156,0.1642347);
   _reco_per_true->SetContourLevel(157,0.1652875);
   _reco_per_true->SetContourLevel(158,0.1663403);
   _reco_per_true->SetContourLevel(159,0.1673931);
   _reco_per_true->SetContourLevel(160,0.1684459);
   _reco_per_true->SetContourLevel(161,0.1694987);
   _reco_per_true->SetContourLevel(162,0.1705515);
   _reco_per_true->SetContourLevel(163,0.1716042);
   _reco_per_true->SetContourLevel(164,0.172657);
   _reco_per_true->SetContourLevel(165,0.1737098);
   _reco_per_true->SetContourLevel(166,0.1747626);
   _reco_per_true->SetContourLevel(167,0.1758154);
   _reco_per_true->SetContourLevel(168,0.1768682);
   _reco_per_true->SetContourLevel(169,0.177921);
   _reco_per_true->SetContourLevel(170,0.1789737);
   _reco_per_true->SetContourLevel(171,0.1800265);
   _reco_per_true->SetContourLevel(172,0.1810793);
   _reco_per_true->SetContourLevel(173,0.1821321);
   _reco_per_true->SetContourLevel(174,0.1831849);
   _reco_per_true->SetContourLevel(175,0.1842377);
   _reco_per_true->SetContourLevel(176,0.1852905);
   _reco_per_true->SetContourLevel(177,0.1863433);
   _reco_per_true->SetContourLevel(178,0.187396);
   _reco_per_true->SetContourLevel(179,0.1884488);
   _reco_per_true->SetContourLevel(180,0.1895016);
   _reco_per_true->SetContourLevel(181,0.1905544);
   _reco_per_true->SetContourLevel(182,0.1916072);
   _reco_per_true->SetContourLevel(183,0.19266);
   _reco_per_true->SetContourLevel(184,0.1937128);
   _reco_per_true->SetContourLevel(185,0.1947655);
   _reco_per_true->SetContourLevel(186,0.1958183);
   _reco_per_true->SetContourLevel(187,0.1968711);
   _reco_per_true->SetContourLevel(188,0.1979239);
   _reco_per_true->SetContourLevel(189,0.1989767);
   _reco_per_true->SetContourLevel(190,0.2000295);
   _reco_per_true->SetContourLevel(191,0.2010823);
   _reco_per_true->SetContourLevel(192,0.2021351);
   _reco_per_true->SetContourLevel(193,0.2031878);
   _reco_per_true->SetContourLevel(194,0.2042406);
   _reco_per_true->SetContourLevel(195,0.2052934);
   _reco_per_true->SetContourLevel(196,0.2063462);
   _reco_per_true->SetContourLevel(197,0.207399);
   _reco_per_true->SetContourLevel(198,0.2084518);
   _reco_per_true->SetContourLevel(199,0.2095046);
   _reco_per_true->SetContourLevel(200,0.2105574);
   _reco_per_true->SetContourLevel(201,0.2116101);
   _reco_per_true->SetContourLevel(202,0.2126629);
   _reco_per_true->SetContourLevel(203,0.2137157);
   _reco_per_true->SetContourLevel(204,0.2147685);
   _reco_per_true->SetContourLevel(205,0.2158213);
   _reco_per_true->SetContourLevel(206,0.2168741);
   _reco_per_true->SetContourLevel(207,0.2179269);
   _reco_per_true->SetContourLevel(208,0.2189796);
   _reco_per_true->SetContourLevel(209,0.2200324);
   _reco_per_true->SetContourLevel(210,0.2210852);
   _reco_per_true->SetContourLevel(211,0.222138);
   _reco_per_true->SetContourLevel(212,0.2231908);
   _reco_per_true->SetContourLevel(213,0.2242436);
   _reco_per_true->SetContourLevel(214,0.2252964);
   _reco_per_true->SetContourLevel(215,0.2263492);
   _reco_per_true->SetContourLevel(216,0.2274019);
   _reco_per_true->SetContourLevel(217,0.2284547);
   _reco_per_true->SetContourLevel(218,0.2295075);
   _reco_per_true->SetContourLevel(219,0.2305603);
   _reco_per_true->SetContourLevel(220,0.2316131);
   _reco_per_true->SetContourLevel(221,0.2326659);
   _reco_per_true->SetContourLevel(222,0.2337187);
   _reco_per_true->SetContourLevel(223,0.2347714);
   _reco_per_true->SetContourLevel(224,0.2358242);
   _reco_per_true->SetContourLevel(225,0.236877);
   _reco_per_true->SetContourLevel(226,0.2379298);
   _reco_per_true->SetContourLevel(227,0.2389826);
   _reco_per_true->SetContourLevel(228,0.2400354);
   _reco_per_true->SetContourLevel(229,0.2410882);
   _reco_per_true->SetContourLevel(230,0.242141);
   _reco_per_true->SetContourLevel(231,0.2431937);
   _reco_per_true->SetContourLevel(232,0.2442465);
   _reco_per_true->SetContourLevel(233,0.2452993);
   _reco_per_true->SetContourLevel(234,0.2463521);
   _reco_per_true->SetContourLevel(235,0.2474049);
   _reco_per_true->SetContourLevel(236,0.2484577);
   _reco_per_true->SetContourLevel(237,0.2495105);
   _reco_per_true->SetContourLevel(238,0.2505632);
   _reco_per_true->SetContourLevel(239,0.251616);
   _reco_per_true->SetContourLevel(240,0.2526688);
   _reco_per_true->SetContourLevel(241,0.2537216);
   _reco_per_true->SetContourLevel(242,0.2547744);
   _reco_per_true->SetContourLevel(243,0.2558272);
   _reco_per_true->SetContourLevel(244,0.25688);
   _reco_per_true->SetContourLevel(245,0.2579328);
   _reco_per_true->SetContourLevel(246,0.2589855);
   _reco_per_true->SetContourLevel(247,0.2600383);
   _reco_per_true->SetContourLevel(248,0.2610911);
   _reco_per_true->SetContourLevel(249,0.2621439);
   _reco_per_true->SetContourLevel(250,0.2631967);
   _reco_per_true->SetContourLevel(251,0.2642495);
   _reco_per_true->SetContourLevel(252,0.2653023);
   _reco_per_true->SetContourLevel(253,0.266355);
   _reco_per_true->SetContourLevel(254,0.2674078);
   
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
   TText *AText = pt->AddText("True Bin 3");
   pt->Draw();
   c1_n4->Modified();
   c1_n4->cd();
   c1_n4->SetSelected(c1_n4);
}

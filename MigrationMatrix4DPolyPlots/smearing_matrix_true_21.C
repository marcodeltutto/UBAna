void smearing_matrix_true_21()
{
//=========Macro generated from canvas: c1_n22/c1_n22
//=========  (Sat Sep 22 12:03:57 2018) by ROOT version6.06/06
   TCanvas *c1_n22 = new TCanvas("c1_n22", "c1_n22",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n22->SetHighLightColor(2);
   c1_n22->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n22->SetFillColor(10);
   c1_n22->SetBorderMode(0);
   c1_n22->SetBorderSize(2);
   c1_n22->SetFrameLineWidth(2);
   c1_n22->SetFrameBorderMode(0);
   c1_n22->SetFrameLineWidth(2);
   c1_n22->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 21", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx652[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy652[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx652,Graph_fy652);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph652 = new TH1F("Graph_Graph652","Graph",100,-1.1,0);
   Graph_Graph652->SetMinimum(0);
   Graph_Graph652->SetMaximum(0.33);
   Graph_Graph652->SetDirectory(0);
   Graph_Graph652->SetStats(0);
   Graph_Graph652->SetLineWidth(2);
   Graph_Graph652->GetXaxis()->SetNdivisions(506);
   Graph_Graph652->GetXaxis()->SetLabelFont(42);
   Graph_Graph652->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph652->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph652->GetXaxis()->SetTitleFont(42);
   Graph_Graph652->GetYaxis()->SetNdivisions(506);
   Graph_Graph652->GetYaxis()->SetLabelFont(42);
   Graph_Graph652->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph652->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph652->GetYaxis()->SetTitleFont(42);
   Graph_Graph652->GetZaxis()->SetNdivisions(506);
   Graph_Graph652->GetZaxis()->SetLabelFont(42);
   Graph_Graph652->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph652->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph652->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph652);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx653[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy653[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx653,Graph_fy653);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph653 = new TH1F("Graph_Graph653","Graph",100,0,0.297);
   Graph_Graph653->SetMinimum(0);
   Graph_Graph653->SetMaximum(0.33);
   Graph_Graph653->SetDirectory(0);
   Graph_Graph653->SetStats(0);
   Graph_Graph653->SetLineWidth(2);
   Graph_Graph653->GetXaxis()->SetNdivisions(506);
   Graph_Graph653->GetXaxis()->SetLabelFont(42);
   Graph_Graph653->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph653->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph653->GetXaxis()->SetTitleFont(42);
   Graph_Graph653->GetYaxis()->SetNdivisions(506);
   Graph_Graph653->GetYaxis()->SetLabelFont(42);
   Graph_Graph653->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph653->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph653->GetYaxis()->SetTitleFont(42);
   Graph_Graph653->GetZaxis()->SetNdivisions(506);
   Graph_Graph653->GetZaxis()->SetLabelFont(42);
   Graph_Graph653->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph653->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph653->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph653);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx654[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy654[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx654,Graph_fy654);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph654 = new TH1F("Graph_Graph654","Graph",100,0.252,0.468);
   Graph_Graph654->SetMinimum(0);
   Graph_Graph654->SetMaximum(0.33);
   Graph_Graph654->SetDirectory(0);
   Graph_Graph654->SetStats(0);
   Graph_Graph654->SetLineWidth(2);
   Graph_Graph654->GetXaxis()->SetNdivisions(506);
   Graph_Graph654->GetXaxis()->SetLabelFont(42);
   Graph_Graph654->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph654->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph654->GetXaxis()->SetTitleFont(42);
   Graph_Graph654->GetYaxis()->SetNdivisions(506);
   Graph_Graph654->GetYaxis()->SetLabelFont(42);
   Graph_Graph654->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph654->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph654->GetYaxis()->SetTitleFont(42);
   Graph_Graph654->GetZaxis()->SetNdivisions(506);
   Graph_Graph654->GetZaxis()->SetLabelFont(42);
   Graph_Graph654->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph654->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph654->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph654);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx655[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy655[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx655,Graph_fy655);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph655 = new TH1F("Graph_Graph655","Graph",100,0.433,0.637);
   Graph_Graph655->SetMinimum(0);
   Graph_Graph655->SetMaximum(0.33);
   Graph_Graph655->SetDirectory(0);
   Graph_Graph655->SetStats(0);
   Graph_Graph655->SetLineWidth(2);
   Graph_Graph655->GetXaxis()->SetNdivisions(506);
   Graph_Graph655->GetXaxis()->SetLabelFont(42);
   Graph_Graph655->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph655->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph655->GetXaxis()->SetTitleFont(42);
   Graph_Graph655->GetYaxis()->SetNdivisions(506);
   Graph_Graph655->GetYaxis()->SetLabelFont(42);
   Graph_Graph655->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph655->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph655->GetYaxis()->SetTitleFont(42);
   Graph_Graph655->GetZaxis()->SetNdivisions(506);
   Graph_Graph655->GetZaxis()->SetLabelFont(42);
   Graph_Graph655->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph655->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph655->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph655);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx656[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy656[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx656,Graph_fy656);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph656 = new TH1F("Graph_Graph656","Graph",100,0.606,0.774);
   Graph_Graph656->SetMinimum(0);
   Graph_Graph656->SetMaximum(0.33);
   Graph_Graph656->SetDirectory(0);
   Graph_Graph656->SetStats(0);
   Graph_Graph656->SetLineWidth(2);
   Graph_Graph656->GetXaxis()->SetNdivisions(506);
   Graph_Graph656->GetXaxis()->SetLabelFont(42);
   Graph_Graph656->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph656->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph656->GetXaxis()->SetTitleFont(42);
   Graph_Graph656->GetYaxis()->SetNdivisions(506);
   Graph_Graph656->GetYaxis()->SetLabelFont(42);
   Graph_Graph656->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph656->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph656->GetYaxis()->SetTitleFont(42);
   Graph_Graph656->GetZaxis()->SetNdivisions(506);
   Graph_Graph656->GetZaxis()->SetLabelFont(42);
   Graph_Graph656->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph656->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph656->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph656);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx657[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy657[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx657,Graph_fy657);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph657 = new TH1F("Graph_Graph657","Graph",100,0.75,0.87);
   Graph_Graph657->SetMinimum(0);
   Graph_Graph657->SetMaximum(0.33);
   Graph_Graph657->SetDirectory(0);
   Graph_Graph657->SetStats(0);
   Graph_Graph657->SetLineWidth(2);
   Graph_Graph657->GetXaxis()->SetNdivisions(506);
   Graph_Graph657->GetXaxis()->SetLabelFont(42);
   Graph_Graph657->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph657->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph657->GetXaxis()->SetTitleFont(42);
   Graph_Graph657->GetYaxis()->SetNdivisions(506);
   Graph_Graph657->GetYaxis()->SetLabelFont(42);
   Graph_Graph657->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph657->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph657->GetYaxis()->SetTitleFont(42);
   Graph_Graph657->GetZaxis()->SetNdivisions(506);
   Graph_Graph657->GetZaxis()->SetLabelFont(42);
   Graph_Graph657->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph657->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph657->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph657);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx658[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy658[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx658,Graph_fy658);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph658 = new TH1F("Graph_Graph658","Graph",100,0.852,0.948);
   Graph_Graph658->SetMinimum(0);
   Graph_Graph658->SetMaximum(0.33);
   Graph_Graph658->SetDirectory(0);
   Graph_Graph658->SetStats(0);
   Graph_Graph658->SetLineWidth(2);
   Graph_Graph658->GetXaxis()->SetNdivisions(506);
   Graph_Graph658->GetXaxis()->SetLabelFont(42);
   Graph_Graph658->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph658->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph658->GetXaxis()->SetTitleFont(42);
   Graph_Graph658->GetYaxis()->SetNdivisions(506);
   Graph_Graph658->GetYaxis()->SetLabelFont(42);
   Graph_Graph658->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph658->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph658->GetYaxis()->SetTitleFont(42);
   Graph_Graph658->GetZaxis()->SetNdivisions(506);
   Graph_Graph658->GetZaxis()->SetLabelFont(42);
   Graph_Graph658->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph658->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph658->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph658);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx659[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy659[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx659,Graph_fy659);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph659 = new TH1F("Graph_Graph659","Graph",100,0.934,1.006);
   Graph_Graph659->SetMinimum(0);
   Graph_Graph659->SetMaximum(0.33);
   Graph_Graph659->SetDirectory(0);
   Graph_Graph659->SetStats(0);
   Graph_Graph659->SetLineWidth(2);
   Graph_Graph659->GetXaxis()->SetNdivisions(506);
   Graph_Graph659->GetXaxis()->SetLabelFont(42);
   Graph_Graph659->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph659->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph659->GetXaxis()->SetTitleFont(42);
   Graph_Graph659->GetYaxis()->SetNdivisions(506);
   Graph_Graph659->GetYaxis()->SetLabelFont(42);
   Graph_Graph659->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph659->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph659->GetYaxis()->SetTitleFont(42);
   Graph_Graph659->GetZaxis()->SetNdivisions(506);
   Graph_Graph659->GetZaxis()->SetLabelFont(42);
   Graph_Graph659->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph659->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph659->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph659);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx660[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy660[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx660,Graph_fy660);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph660 = new TH1F("Graph_Graph660","Graph",100,-1.1,0);
   Graph_Graph660->SetMinimum(0.285);
   Graph_Graph660->SetMaximum(0.465);
   Graph_Graph660->SetDirectory(0);
   Graph_Graph660->SetStats(0);
   Graph_Graph660->SetLineWidth(2);
   Graph_Graph660->GetXaxis()->SetNdivisions(506);
   Graph_Graph660->GetXaxis()->SetLabelFont(42);
   Graph_Graph660->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph660->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph660->GetXaxis()->SetTitleFont(42);
   Graph_Graph660->GetYaxis()->SetNdivisions(506);
   Graph_Graph660->GetYaxis()->SetLabelFont(42);
   Graph_Graph660->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph660->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph660->GetYaxis()->SetTitleFont(42);
   Graph_Graph660->GetZaxis()->SetNdivisions(506);
   Graph_Graph660->GetZaxis()->SetLabelFont(42);
   Graph_Graph660->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph660->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph660->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph660);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx661[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy661[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx661,Graph_fy661);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph661 = new TH1F("Graph_Graph661","Graph",100,0,0.297);
   Graph_Graph661->SetMinimum(0.285);
   Graph_Graph661->SetMaximum(0.465);
   Graph_Graph661->SetDirectory(0);
   Graph_Graph661->SetStats(0);
   Graph_Graph661->SetLineWidth(2);
   Graph_Graph661->GetXaxis()->SetNdivisions(506);
   Graph_Graph661->GetXaxis()->SetLabelFont(42);
   Graph_Graph661->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph661->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph661->GetXaxis()->SetTitleFont(42);
   Graph_Graph661->GetYaxis()->SetNdivisions(506);
   Graph_Graph661->GetYaxis()->SetLabelFont(42);
   Graph_Graph661->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph661->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph661->GetYaxis()->SetTitleFont(42);
   Graph_Graph661->GetZaxis()->SetNdivisions(506);
   Graph_Graph661->GetZaxis()->SetLabelFont(42);
   Graph_Graph661->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph661->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph661->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph661);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx662[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy662[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx662,Graph_fy662);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph662 = new TH1F("Graph_Graph662","Graph",100,0.252,0.468);
   Graph_Graph662->SetMinimum(0.285);
   Graph_Graph662->SetMaximum(0.465);
   Graph_Graph662->SetDirectory(0);
   Graph_Graph662->SetStats(0);
   Graph_Graph662->SetLineWidth(2);
   Graph_Graph662->GetXaxis()->SetNdivisions(506);
   Graph_Graph662->GetXaxis()->SetLabelFont(42);
   Graph_Graph662->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph662->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph662->GetXaxis()->SetTitleFont(42);
   Graph_Graph662->GetYaxis()->SetNdivisions(506);
   Graph_Graph662->GetYaxis()->SetLabelFont(42);
   Graph_Graph662->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph662->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph662->GetYaxis()->SetTitleFont(42);
   Graph_Graph662->GetZaxis()->SetNdivisions(506);
   Graph_Graph662->GetZaxis()->SetLabelFont(42);
   Graph_Graph662->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph662->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph662->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph662);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx663[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy663[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx663,Graph_fy663);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph663 = new TH1F("Graph_Graph663","Graph",100,0.433,0.637);
   Graph_Graph663->SetMinimum(0.285);
   Graph_Graph663->SetMaximum(0.465);
   Graph_Graph663->SetDirectory(0);
   Graph_Graph663->SetStats(0);
   Graph_Graph663->SetLineWidth(2);
   Graph_Graph663->GetXaxis()->SetNdivisions(506);
   Graph_Graph663->GetXaxis()->SetLabelFont(42);
   Graph_Graph663->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph663->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph663->GetXaxis()->SetTitleFont(42);
   Graph_Graph663->GetYaxis()->SetNdivisions(506);
   Graph_Graph663->GetYaxis()->SetLabelFont(42);
   Graph_Graph663->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph663->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph663->GetYaxis()->SetTitleFont(42);
   Graph_Graph663->GetZaxis()->SetNdivisions(506);
   Graph_Graph663->GetZaxis()->SetLabelFont(42);
   Graph_Graph663->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph663->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph663->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph663);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx664[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy664[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx664,Graph_fy664);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00138d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph664 = new TH1F("Graph_Graph664","Graph",100,0.606,0.774);
   Graph_Graph664->SetMinimum(0.285);
   Graph_Graph664->SetMaximum(0.465);
   Graph_Graph664->SetDirectory(0);
   Graph_Graph664->SetStats(0);
   Graph_Graph664->SetLineWidth(2);
   Graph_Graph664->GetXaxis()->SetNdivisions(506);
   Graph_Graph664->GetXaxis()->SetLabelFont(42);
   Graph_Graph664->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph664->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph664->GetXaxis()->SetTitleFont(42);
   Graph_Graph664->GetYaxis()->SetNdivisions(506);
   Graph_Graph664->GetYaxis()->SetLabelFont(42);
   Graph_Graph664->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph664->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph664->GetYaxis()->SetTitleFont(42);
   Graph_Graph664->GetZaxis()->SetNdivisions(506);
   Graph_Graph664->GetZaxis()->SetLabelFont(42);
   Graph_Graph664->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph664->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph664->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph664);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx665[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy665[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx665,Graph_fy665);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0037a3");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph665 = new TH1F("Graph_Graph665","Graph",100,0.75,0.87);
   Graph_Graph665->SetMinimum(0.285);
   Graph_Graph665->SetMaximum(0.465);
   Graph_Graph665->SetDirectory(0);
   Graph_Graph665->SetStats(0);
   Graph_Graph665->SetLineWidth(2);
   Graph_Graph665->GetXaxis()->SetNdivisions(506);
   Graph_Graph665->GetXaxis()->SetLabelFont(42);
   Graph_Graph665->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph665->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph665->GetXaxis()->SetTitleFont(42);
   Graph_Graph665->GetYaxis()->SetNdivisions(506);
   Graph_Graph665->GetYaxis()->SetLabelFont(42);
   Graph_Graph665->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph665->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph665->GetYaxis()->SetTitleFont(42);
   Graph_Graph665->GetZaxis()->SetNdivisions(506);
   Graph_Graph665->GetZaxis()->SetLabelFont(42);
   Graph_Graph665->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph665->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph665->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph665);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx666[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy666[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx666,Graph_fy666);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001890");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph666 = new TH1F("Graph_Graph666","Graph",100,0.852,0.948);
   Graph_Graph666->SetMinimum(0.285);
   Graph_Graph666->SetMaximum(0.465);
   Graph_Graph666->SetDirectory(0);
   Graph_Graph666->SetStats(0);
   Graph_Graph666->SetLineWidth(2);
   Graph_Graph666->GetXaxis()->SetNdivisions(506);
   Graph_Graph666->GetXaxis()->SetLabelFont(42);
   Graph_Graph666->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph666->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph666->GetXaxis()->SetTitleFont(42);
   Graph_Graph666->GetYaxis()->SetNdivisions(506);
   Graph_Graph666->GetYaxis()->SetLabelFont(42);
   Graph_Graph666->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph666->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph666->GetYaxis()->SetTitleFont(42);
   Graph_Graph666->GetZaxis()->SetNdivisions(506);
   Graph_Graph666->GetZaxis()->SetLabelFont(42);
   Graph_Graph666->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph666->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph666->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph666);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx667[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy667[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx667,Graph_fy667);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph667 = new TH1F("Graph_Graph667","Graph",100,0.934,1.006);
   Graph_Graph667->SetMinimum(0.285);
   Graph_Graph667->SetMaximum(0.465);
   Graph_Graph667->SetDirectory(0);
   Graph_Graph667->SetStats(0);
   Graph_Graph667->SetLineWidth(2);
   Graph_Graph667->GetXaxis()->SetNdivisions(506);
   Graph_Graph667->GetXaxis()->SetLabelFont(42);
   Graph_Graph667->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph667->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph667->GetXaxis()->SetTitleFont(42);
   Graph_Graph667->GetYaxis()->SetNdivisions(506);
   Graph_Graph667->GetYaxis()->SetLabelFont(42);
   Graph_Graph667->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph667->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph667->GetYaxis()->SetTitleFont(42);
   Graph_Graph667->GetZaxis()->SetNdivisions(506);
   Graph_Graph667->GetZaxis()->SetLabelFont(42);
   Graph_Graph667->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph667->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph667->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph667);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx668[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy668[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx668,Graph_fy668);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph668 = new TH1F("Graph_Graph668","Graph",100,-1.1,0);
   Graph_Graph668->SetMinimum(0.245);
   Graph_Graph668->SetMaximum(2.705);
   Graph_Graph668->SetDirectory(0);
   Graph_Graph668->SetStats(0);
   Graph_Graph668->SetLineWidth(2);
   Graph_Graph668->GetXaxis()->SetNdivisions(506);
   Graph_Graph668->GetXaxis()->SetLabelFont(42);
   Graph_Graph668->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph668->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph668->GetXaxis()->SetTitleFont(42);
   Graph_Graph668->GetYaxis()->SetNdivisions(506);
   Graph_Graph668->GetYaxis()->SetLabelFont(42);
   Graph_Graph668->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph668->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph668->GetYaxis()->SetTitleFont(42);
   Graph_Graph668->GetZaxis()->SetNdivisions(506);
   Graph_Graph668->GetZaxis()->SetLabelFont(42);
   Graph_Graph668->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph668->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph668->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph668);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx669[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy669[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx669,Graph_fy669);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph669 = new TH1F("Graph_Graph669","Graph",100,0,0.297);
   Graph_Graph669->SetMinimum(0.418);
   Graph_Graph669->SetMaximum(0.802);
   Graph_Graph669->SetDirectory(0);
   Graph_Graph669->SetStats(0);
   Graph_Graph669->SetLineWidth(2);
   Graph_Graph669->GetXaxis()->SetNdivisions(506);
   Graph_Graph669->GetXaxis()->SetLabelFont(42);
   Graph_Graph669->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph669->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph669->GetXaxis()->SetTitleFont(42);
   Graph_Graph669->GetYaxis()->SetNdivisions(506);
   Graph_Graph669->GetYaxis()->SetLabelFont(42);
   Graph_Graph669->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph669->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph669->GetYaxis()->SetTitleFont(42);
   Graph_Graph669->GetZaxis()->SetNdivisions(506);
   Graph_Graph669->GetZaxis()->SetLabelFont(42);
   Graph_Graph669->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph669->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph669->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph669);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx670[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy670[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx670,Graph_fy670);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph670 = new TH1F("Graph_Graph670","Graph",100,0.252,0.468);
   Graph_Graph670->SetMinimum(0.418);
   Graph_Graph670->SetMaximum(0.802);
   Graph_Graph670->SetDirectory(0);
   Graph_Graph670->SetStats(0);
   Graph_Graph670->SetLineWidth(2);
   Graph_Graph670->GetXaxis()->SetNdivisions(506);
   Graph_Graph670->GetXaxis()->SetLabelFont(42);
   Graph_Graph670->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph670->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph670->GetXaxis()->SetTitleFont(42);
   Graph_Graph670->GetYaxis()->SetNdivisions(506);
   Graph_Graph670->GetYaxis()->SetLabelFont(42);
   Graph_Graph670->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph670->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph670->GetYaxis()->SetTitleFont(42);
   Graph_Graph670->GetZaxis()->SetNdivisions(506);
   Graph_Graph670->GetZaxis()->SetLabelFont(42);
   Graph_Graph670->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph670->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph670->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph670);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx671[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy671[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx671,Graph_fy671);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph671 = new TH1F("Graph_Graph671","Graph",100,0.433,0.637);
   Graph_Graph671->SetMinimum(0.418);
   Graph_Graph671->SetMaximum(0.802);
   Graph_Graph671->SetDirectory(0);
   Graph_Graph671->SetStats(0);
   Graph_Graph671->SetLineWidth(2);
   Graph_Graph671->GetXaxis()->SetNdivisions(506);
   Graph_Graph671->GetXaxis()->SetLabelFont(42);
   Graph_Graph671->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph671->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph671->GetXaxis()->SetTitleFont(42);
   Graph_Graph671->GetYaxis()->SetNdivisions(506);
   Graph_Graph671->GetYaxis()->SetLabelFont(42);
   Graph_Graph671->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph671->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph671->GetYaxis()->SetTitleFont(42);
   Graph_Graph671->GetZaxis()->SetNdivisions(506);
   Graph_Graph671->GetZaxis()->SetLabelFont(42);
   Graph_Graph671->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph671->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph671->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph671);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx672[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy672[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx672,Graph_fy672);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0075c9");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph672 = new TH1F("Graph_Graph672","Graph",100,0.606,0.774);
   Graph_Graph672->SetMinimum(0.418);
   Graph_Graph672->SetMaximum(0.802);
   Graph_Graph672->SetDirectory(0);
   Graph_Graph672->SetStats(0);
   Graph_Graph672->SetLineWidth(2);
   Graph_Graph672->GetXaxis()->SetNdivisions(506);
   Graph_Graph672->GetXaxis()->SetLabelFont(42);
   Graph_Graph672->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph672->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph672->GetXaxis()->SetTitleFont(42);
   Graph_Graph672->GetYaxis()->SetNdivisions(506);
   Graph_Graph672->GetYaxis()->SetLabelFont(42);
   Graph_Graph672->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph672->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph672->GetYaxis()->SetTitleFont(42);
   Graph_Graph672->GetZaxis()->SetNdivisions(506);
   Graph_Graph672->GetZaxis()->SetLabelFont(42);
   Graph_Graph672->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph672->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph672->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph672);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx673[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy673[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx673,Graph_fy673);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph673 = new TH1F("Graph_Graph673","Graph",100,0.75,0.87);
   Graph_Graph673->SetMinimum(0.418);
   Graph_Graph673->SetMaximum(0.802);
   Graph_Graph673->SetDirectory(0);
   Graph_Graph673->SetStats(0);
   Graph_Graph673->SetLineWidth(2);
   Graph_Graph673->GetXaxis()->SetNdivisions(506);
   Graph_Graph673->GetXaxis()->SetLabelFont(42);
   Graph_Graph673->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph673->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph673->GetXaxis()->SetTitleFont(42);
   Graph_Graph673->GetYaxis()->SetNdivisions(506);
   Graph_Graph673->GetYaxis()->SetLabelFont(42);
   Graph_Graph673->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph673->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph673->GetYaxis()->SetTitleFont(42);
   Graph_Graph673->GetZaxis()->SetNdivisions(506);
   Graph_Graph673->GetZaxis()->SetLabelFont(42);
   Graph_Graph673->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph673->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph673->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph673);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx674[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy674[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx674,Graph_fy674);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00a5e6");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph674 = new TH1F("Graph_Graph674","Graph",100,0.852,0.948);
   Graph_Graph674->SetMinimum(0.418);
   Graph_Graph674->SetMaximum(0.802);
   Graph_Graph674->SetDirectory(0);
   Graph_Graph674->SetStats(0);
   Graph_Graph674->SetLineWidth(2);
   Graph_Graph674->GetXaxis()->SetNdivisions(506);
   Graph_Graph674->GetXaxis()->SetLabelFont(42);
   Graph_Graph674->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph674->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph674->GetXaxis()->SetTitleFont(42);
   Graph_Graph674->GetYaxis()->SetNdivisions(506);
   Graph_Graph674->GetYaxis()->SetLabelFont(42);
   Graph_Graph674->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph674->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph674->GetYaxis()->SetTitleFont(42);
   Graph_Graph674->GetZaxis()->SetNdivisions(506);
   Graph_Graph674->GetZaxis()->SetLabelFont(42);
   Graph_Graph674->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph674->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph674->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph674);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx675[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy675[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx675,Graph_fy675);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph675 = new TH1F("Graph_Graph675","Graph",100,0.934,1.006);
   Graph_Graph675->SetMinimum(0.418);
   Graph_Graph675->SetMaximum(0.802);
   Graph_Graph675->SetDirectory(0);
   Graph_Graph675->SetStats(0);
   Graph_Graph675->SetLineWidth(2);
   Graph_Graph675->GetXaxis()->SetNdivisions(506);
   Graph_Graph675->GetXaxis()->SetLabelFont(42);
   Graph_Graph675->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph675->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph675->GetXaxis()->SetTitleFont(42);
   Graph_Graph675->GetYaxis()->SetNdivisions(506);
   Graph_Graph675->GetYaxis()->SetLabelFont(42);
   Graph_Graph675->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph675->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph675->GetYaxis()->SetTitleFont(42);
   Graph_Graph675->GetZaxis()->SetNdivisions(506);
   Graph_Graph675->GetZaxis()->SetLabelFont(42);
   Graph_Graph675->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph675->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph675->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph675);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx676[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy676[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx676,Graph_fy676);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph676 = new TH1F("Graph_Graph676","Graph",100,0,0.297);
   Graph_Graph676->SetMinimum(0.597);
   Graph_Graph676->SetMaximum(2.673);
   Graph_Graph676->SetDirectory(0);
   Graph_Graph676->SetStats(0);
   Graph_Graph676->SetLineWidth(2);
   Graph_Graph676->GetXaxis()->SetNdivisions(506);
   Graph_Graph676->GetXaxis()->SetLabelFont(42);
   Graph_Graph676->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph676->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph676->GetXaxis()->SetTitleFont(42);
   Graph_Graph676->GetYaxis()->SetNdivisions(506);
   Graph_Graph676->GetYaxis()->SetLabelFont(42);
   Graph_Graph676->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph676->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph676->GetYaxis()->SetTitleFont(42);
   Graph_Graph676->GetZaxis()->SetNdivisions(506);
   Graph_Graph676->GetZaxis()->SetLabelFont(42);
   Graph_Graph676->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph676->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph676->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph676);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx677[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy677[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx677,Graph_fy677);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph677 = new TH1F("Graph_Graph677","Graph",100,0.252,0.468);
   Graph_Graph677->SetMinimum(0.597);
   Graph_Graph677->SetMaximum(2.673);
   Graph_Graph677->SetDirectory(0);
   Graph_Graph677->SetStats(0);
   Graph_Graph677->SetLineWidth(2);
   Graph_Graph677->GetXaxis()->SetNdivisions(506);
   Graph_Graph677->GetXaxis()->SetLabelFont(42);
   Graph_Graph677->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph677->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph677->GetXaxis()->SetTitleFont(42);
   Graph_Graph677->GetYaxis()->SetNdivisions(506);
   Graph_Graph677->GetYaxis()->SetLabelFont(42);
   Graph_Graph677->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph677->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph677->GetYaxis()->SetTitleFont(42);
   Graph_Graph677->GetZaxis()->SetNdivisions(506);
   Graph_Graph677->GetZaxis()->SetLabelFont(42);
   Graph_Graph677->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph677->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph677->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph677);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx678[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy678[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx678,Graph_fy678);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph678 = new TH1F("Graph_Graph678","Graph",100,0.433,0.637);
   Graph_Graph678->SetMinimum(0.597);
   Graph_Graph678->SetMaximum(2.673);
   Graph_Graph678->SetDirectory(0);
   Graph_Graph678->SetStats(0);
   Graph_Graph678->SetLineWidth(2);
   Graph_Graph678->GetXaxis()->SetNdivisions(506);
   Graph_Graph678->GetXaxis()->SetLabelFont(42);
   Graph_Graph678->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph678->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph678->GetXaxis()->SetTitleFont(42);
   Graph_Graph678->GetYaxis()->SetNdivisions(506);
   Graph_Graph678->GetYaxis()->SetLabelFont(42);
   Graph_Graph678->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph678->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph678->GetYaxis()->SetTitleFont(42);
   Graph_Graph678->GetZaxis()->SetNdivisions(506);
   Graph_Graph678->GetZaxis()->SetLabelFont(42);
   Graph_Graph678->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph678->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph678->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph678);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx679[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy679[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx679,Graph_fy679);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph679 = new TH1F("Graph_Graph679","Graph",100,0.606,0.774);
   Graph_Graph679->SetMinimum(0.597);
   Graph_Graph679->SetMaximum(2.673);
   Graph_Graph679->SetDirectory(0);
   Graph_Graph679->SetStats(0);
   Graph_Graph679->SetLineWidth(2);
   Graph_Graph679->GetXaxis()->SetNdivisions(506);
   Graph_Graph679->GetXaxis()->SetLabelFont(42);
   Graph_Graph679->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph679->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph679->GetXaxis()->SetTitleFont(42);
   Graph_Graph679->GetYaxis()->SetNdivisions(506);
   Graph_Graph679->GetYaxis()->SetLabelFont(42);
   Graph_Graph679->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph679->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph679->GetYaxis()->SetTitleFont(42);
   Graph_Graph679->GetZaxis()->SetNdivisions(506);
   Graph_Graph679->GetZaxis()->SetLabelFont(42);
   Graph_Graph679->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph679->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph679->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph679);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx680[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy680[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx680,Graph_fy680);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#006ec4");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph680 = new TH1F("Graph_Graph680","Graph",100,0.75,0.87);
   Graph_Graph680->SetMinimum(0.597);
   Graph_Graph680->SetMaximum(2.673);
   Graph_Graph680->SetDirectory(0);
   Graph_Graph680->SetStats(0);
   Graph_Graph680->SetLineWidth(2);
   Graph_Graph680->GetXaxis()->SetNdivisions(506);
   Graph_Graph680->GetXaxis()->SetLabelFont(42);
   Graph_Graph680->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph680->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph680->GetXaxis()->SetTitleFont(42);
   Graph_Graph680->GetYaxis()->SetNdivisions(506);
   Graph_Graph680->GetYaxis()->SetLabelFont(42);
   Graph_Graph680->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph680->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph680->GetYaxis()->SetTitleFont(42);
   Graph_Graph680->GetZaxis()->SetNdivisions(506);
   Graph_Graph680->GetZaxis()->SetLabelFont(42);
   Graph_Graph680->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph680->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph680->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph680);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx681[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy681[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx681,Graph_fy681);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00108c");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph681 = new TH1F("Graph_Graph681","Graph",100,0.852,0.948);
   Graph_Graph681->SetMinimum(0.597);
   Graph_Graph681->SetMaximum(2.673);
   Graph_Graph681->SetDirectory(0);
   Graph_Graph681->SetStats(0);
   Graph_Graph681->SetLineWidth(2);
   Graph_Graph681->GetXaxis()->SetNdivisions(506);
   Graph_Graph681->GetXaxis()->SetLabelFont(42);
   Graph_Graph681->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph681->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph681->GetXaxis()->SetTitleFont(42);
   Graph_Graph681->GetYaxis()->SetNdivisions(506);
   Graph_Graph681->GetYaxis()->SetLabelFont(42);
   Graph_Graph681->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph681->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph681->GetYaxis()->SetTitleFont(42);
   Graph_Graph681->GetZaxis()->SetNdivisions(506);
   Graph_Graph681->GetZaxis()->SetLabelFont(42);
   Graph_Graph681->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph681->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph681->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph681);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx682[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy682[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx682,Graph_fy682);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph682 = new TH1F("Graph_Graph682","Graph",100,0.934,1.006);
   Graph_Graph682->SetMinimum(0.597);
   Graph_Graph682->SetMaximum(2.673);
   Graph_Graph682->SetDirectory(0);
   Graph_Graph682->SetStats(0);
   Graph_Graph682->SetLineWidth(2);
   Graph_Graph682->GetXaxis()->SetNdivisions(506);
   Graph_Graph682->GetXaxis()->SetLabelFont(42);
   Graph_Graph682->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph682->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph682->GetXaxis()->SetTitleFont(42);
   Graph_Graph682->GetYaxis()->SetNdivisions(506);
   Graph_Graph682->GetYaxis()->SetLabelFont(42);
   Graph_Graph682->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph682->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph682->GetYaxis()->SetTitleFont(42);
   Graph_Graph682->GetZaxis()->SetNdivisions(506);
   Graph_Graph682->GetZaxis()->SetLabelFont(42);
   Graph_Graph682->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph682->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph682->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph682);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(2,0.001318374);
   _reco_per_true->SetBinContent(3,0.001309286);
   _reco_per_true->SetBinContent(5,0.001315478);
   _reco_per_true->SetBinContent(6,0.007869294);
   _reco_per_true->SetBinContent(7,0.003934054);
   _reco_per_true->SetBinContent(8,0.002628363);
   _reco_per_true->SetBinContent(9,0.001315478);
   _reco_per_true->SetBinContent(11,0.001308667);
   _reco_per_true->SetBinContent(13,0.01708564);
   _reco_per_true->SetBinContent(14,0.04728412);
   _reco_per_true->SetBinContent(15,0.02102275);
   _reco_per_true->SetBinContent(17,0.01051981);
   _reco_per_true->SetBinContent(18,0.001318735);
   _reco_per_true->SetBinContent(21,0.1011707);
   _reco_per_true->SetBinContent(22,0.5170824);
   _reco_per_true->SetBinContent(23,0.141548);
   _reco_per_true->SetBinContent(26,0.002621474);
   _reco_per_true->SetBinContent(27,0.001312189);
   _reco_per_true->SetBinContent(28,0.009212915);
   _reco_per_true->SetBinContent(29,0.09450263);
   _reco_per_true->SetBinContent(30,0.01431961);
   _reco_per_true->SetBinError(2,0.001318374);
   _reco_per_true->SetBinError(3,0.001309286);
   _reco_per_true->SetBinError(5,0.001315478);
   _reco_per_true->SetBinError(6,0.003212641);
   _reco_per_true->SetBinError(7,0.002271332);
   _reco_per_true->SetBinError(8,0.001858535);
   _reco_per_true->SetBinError(9,0.001315478);
   _reco_per_true->SetBinError(11,0.001308667);
   _reco_per_true->SetBinError(13,0.00473872);
   _reco_per_true->SetBinError(14,0.00788071);
   _reco_per_true->SetBinError(15,0.005255698);
   _reco_per_true->SetBinError(17,0.003719327);
   _reco_per_true->SetBinError(18,0.001318735);
   _reco_per_true->SetBinError(21,0.01152951);
   _reco_per_true->SetBinError(22,0.02605117);
   _reco_per_true->SetBinError(23,0.01362197);
   _reco_per_true->SetBinError(26,0.001853663);
   _reco_per_true->SetBinError(27,0.001312189);
   _reco_per_true->SetBinError(28,0.003482163);
   _reco_per_true->SetBinError(29,0.0111377);
   _reco_per_true->SetBinError(30,0.004319367);
   _reco_per_true->SetEntries(762);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.002027774);
   _reco_per_true->SetContourLevel(2,0.004055548);
   _reco_per_true->SetContourLevel(3,0.006083323);
   _reco_per_true->SetContourLevel(4,0.008111097);
   _reco_per_true->SetContourLevel(5,0.01013887);
   _reco_per_true->SetContourLevel(6,0.01216665);
   _reco_per_true->SetContourLevel(7,0.01419442);
   _reco_per_true->SetContourLevel(8,0.01622219);
   _reco_per_true->SetContourLevel(9,0.01824997);
   _reco_per_true->SetContourLevel(10,0.02027774);
   _reco_per_true->SetContourLevel(11,0.02230552);
   _reco_per_true->SetContourLevel(12,0.02433329);
   _reco_per_true->SetContourLevel(13,0.02636107);
   _reco_per_true->SetContourLevel(14,0.02838884);
   _reco_per_true->SetContourLevel(15,0.03041661);
   _reco_per_true->SetContourLevel(16,0.03244439);
   _reco_per_true->SetContourLevel(17,0.03447216);
   _reco_per_true->SetContourLevel(18,0.03649994);
   _reco_per_true->SetContourLevel(19,0.03852771);
   _reco_per_true->SetContourLevel(20,0.04055548);
   _reco_per_true->SetContourLevel(21,0.04258326);
   _reco_per_true->SetContourLevel(22,0.04461103);
   _reco_per_true->SetContourLevel(23,0.04663881);
   _reco_per_true->SetContourLevel(24,0.04866658);
   _reco_per_true->SetContourLevel(25,0.05069436);
   _reco_per_true->SetContourLevel(26,0.05272213);
   _reco_per_true->SetContourLevel(27,0.0547499);
   _reco_per_true->SetContourLevel(28,0.05677768);
   _reco_per_true->SetContourLevel(29,0.05880545);
   _reco_per_true->SetContourLevel(30,0.06083323);
   _reco_per_true->SetContourLevel(31,0.062861);
   _reco_per_true->SetContourLevel(32,0.06488878);
   _reco_per_true->SetContourLevel(33,0.06691655);
   _reco_per_true->SetContourLevel(34,0.06894432);
   _reco_per_true->SetContourLevel(35,0.0709721);
   _reco_per_true->SetContourLevel(36,0.07299987);
   _reco_per_true->SetContourLevel(37,0.07502765);
   _reco_per_true->SetContourLevel(38,0.07705542);
   _reco_per_true->SetContourLevel(39,0.0790832);
   _reco_per_true->SetContourLevel(40,0.08111097);
   _reco_per_true->SetContourLevel(41,0.08313874);
   _reco_per_true->SetContourLevel(42,0.08516652);
   _reco_per_true->SetContourLevel(43,0.08719429);
   _reco_per_true->SetContourLevel(44,0.08922207);
   _reco_per_true->SetContourLevel(45,0.09124984);
   _reco_per_true->SetContourLevel(46,0.09327761);
   _reco_per_true->SetContourLevel(47,0.09530539);
   _reco_per_true->SetContourLevel(48,0.09733316);
   _reco_per_true->SetContourLevel(49,0.09936094);
   _reco_per_true->SetContourLevel(50,0.1013887);
   _reco_per_true->SetContourLevel(51,0.1034165);
   _reco_per_true->SetContourLevel(52,0.1054443);
   _reco_per_true->SetContourLevel(53,0.107472);
   _reco_per_true->SetContourLevel(54,0.1094998);
   _reco_per_true->SetContourLevel(55,0.1115276);
   _reco_per_true->SetContourLevel(56,0.1135554);
   _reco_per_true->SetContourLevel(57,0.1155831);
   _reco_per_true->SetContourLevel(58,0.1176109);
   _reco_per_true->SetContourLevel(59,0.1196387);
   _reco_per_true->SetContourLevel(60,0.1216665);
   _reco_per_true->SetContourLevel(61,0.1236942);
   _reco_per_true->SetContourLevel(62,0.125722);
   _reco_per_true->SetContourLevel(63,0.1277498);
   _reco_per_true->SetContourLevel(64,0.1297776);
   _reco_per_true->SetContourLevel(65,0.1318053);
   _reco_per_true->SetContourLevel(66,0.1338331);
   _reco_per_true->SetContourLevel(67,0.1358609);
   _reco_per_true->SetContourLevel(68,0.1378886);
   _reco_per_true->SetContourLevel(69,0.1399164);
   _reco_per_true->SetContourLevel(70,0.1419442);
   _reco_per_true->SetContourLevel(71,0.143972);
   _reco_per_true->SetContourLevel(72,0.1459997);
   _reco_per_true->SetContourLevel(73,0.1480275);
   _reco_per_true->SetContourLevel(74,0.1500553);
   _reco_per_true->SetContourLevel(75,0.1520831);
   _reco_per_true->SetContourLevel(76,0.1541108);
   _reco_per_true->SetContourLevel(77,0.1561386);
   _reco_per_true->SetContourLevel(78,0.1581664);
   _reco_per_true->SetContourLevel(79,0.1601942);
   _reco_per_true->SetContourLevel(80,0.1622219);
   _reco_per_true->SetContourLevel(81,0.1642497);
   _reco_per_true->SetContourLevel(82,0.1662775);
   _reco_per_true->SetContourLevel(83,0.1683053);
   _reco_per_true->SetContourLevel(84,0.170333);
   _reco_per_true->SetContourLevel(85,0.1723608);
   _reco_per_true->SetContourLevel(86,0.1743886);
   _reco_per_true->SetContourLevel(87,0.1764164);
   _reco_per_true->SetContourLevel(88,0.1784441);
   _reco_per_true->SetContourLevel(89,0.1804719);
   _reco_per_true->SetContourLevel(90,0.1824997);
   _reco_per_true->SetContourLevel(91,0.1845275);
   _reco_per_true->SetContourLevel(92,0.1865552);
   _reco_per_true->SetContourLevel(93,0.188583);
   _reco_per_true->SetContourLevel(94,0.1906108);
   _reco_per_true->SetContourLevel(95,0.1926386);
   _reco_per_true->SetContourLevel(96,0.1946663);
   _reco_per_true->SetContourLevel(97,0.1966941);
   _reco_per_true->SetContourLevel(98,0.1987219);
   _reco_per_true->SetContourLevel(99,0.2007496);
   _reco_per_true->SetContourLevel(100,0.2027774);
   _reco_per_true->SetContourLevel(101,0.2048052);
   _reco_per_true->SetContourLevel(102,0.206833);
   _reco_per_true->SetContourLevel(103,0.2088607);
   _reco_per_true->SetContourLevel(104,0.2108885);
   _reco_per_true->SetContourLevel(105,0.2129163);
   _reco_per_true->SetContourLevel(106,0.2149441);
   _reco_per_true->SetContourLevel(107,0.2169718);
   _reco_per_true->SetContourLevel(108,0.2189996);
   _reco_per_true->SetContourLevel(109,0.2210274);
   _reco_per_true->SetContourLevel(110,0.2230552);
   _reco_per_true->SetContourLevel(111,0.2250829);
   _reco_per_true->SetContourLevel(112,0.2271107);
   _reco_per_true->SetContourLevel(113,0.2291385);
   _reco_per_true->SetContourLevel(114,0.2311663);
   _reco_per_true->SetContourLevel(115,0.233194);
   _reco_per_true->SetContourLevel(116,0.2352218);
   _reco_per_true->SetContourLevel(117,0.2372496);
   _reco_per_true->SetContourLevel(118,0.2392774);
   _reco_per_true->SetContourLevel(119,0.2413051);
   _reco_per_true->SetContourLevel(120,0.2433329);
   _reco_per_true->SetContourLevel(121,0.2453607);
   _reco_per_true->SetContourLevel(122,0.2473885);
   _reco_per_true->SetContourLevel(123,0.2494162);
   _reco_per_true->SetContourLevel(124,0.251444);
   _reco_per_true->SetContourLevel(125,0.2534718);
   _reco_per_true->SetContourLevel(126,0.2554996);
   _reco_per_true->SetContourLevel(127,0.2575273);
   _reco_per_true->SetContourLevel(128,0.2595551);
   _reco_per_true->SetContourLevel(129,0.2615829);
   _reco_per_true->SetContourLevel(130,0.2636107);
   _reco_per_true->SetContourLevel(131,0.2656384);
   _reco_per_true->SetContourLevel(132,0.2676662);
   _reco_per_true->SetContourLevel(133,0.269694);
   _reco_per_true->SetContourLevel(134,0.2717217);
   _reco_per_true->SetContourLevel(135,0.2737495);
   _reco_per_true->SetContourLevel(136,0.2757773);
   _reco_per_true->SetContourLevel(137,0.2778051);
   _reco_per_true->SetContourLevel(138,0.2798328);
   _reco_per_true->SetContourLevel(139,0.2818606);
   _reco_per_true->SetContourLevel(140,0.2838884);
   _reco_per_true->SetContourLevel(141,0.2859162);
   _reco_per_true->SetContourLevel(142,0.2879439);
   _reco_per_true->SetContourLevel(143,0.2899717);
   _reco_per_true->SetContourLevel(144,0.2919995);
   _reco_per_true->SetContourLevel(145,0.2940273);
   _reco_per_true->SetContourLevel(146,0.296055);
   _reco_per_true->SetContourLevel(147,0.2980828);
   _reco_per_true->SetContourLevel(148,0.3001106);
   _reco_per_true->SetContourLevel(149,0.3021384);
   _reco_per_true->SetContourLevel(150,0.3041661);
   _reco_per_true->SetContourLevel(151,0.3061939);
   _reco_per_true->SetContourLevel(152,0.3082217);
   _reco_per_true->SetContourLevel(153,0.3102495);
   _reco_per_true->SetContourLevel(154,0.3122772);
   _reco_per_true->SetContourLevel(155,0.314305);
   _reco_per_true->SetContourLevel(156,0.3163328);
   _reco_per_true->SetContourLevel(157,0.3183606);
   _reco_per_true->SetContourLevel(158,0.3203883);
   _reco_per_true->SetContourLevel(159,0.3224161);
   _reco_per_true->SetContourLevel(160,0.3244439);
   _reco_per_true->SetContourLevel(161,0.3264717);
   _reco_per_true->SetContourLevel(162,0.3284994);
   _reco_per_true->SetContourLevel(163,0.3305272);
   _reco_per_true->SetContourLevel(164,0.332555);
   _reco_per_true->SetContourLevel(165,0.3345827);
   _reco_per_true->SetContourLevel(166,0.3366105);
   _reco_per_true->SetContourLevel(167,0.3386383);
   _reco_per_true->SetContourLevel(168,0.3406661);
   _reco_per_true->SetContourLevel(169,0.3426938);
   _reco_per_true->SetContourLevel(170,0.3447216);
   _reco_per_true->SetContourLevel(171,0.3467494);
   _reco_per_true->SetContourLevel(172,0.3487772);
   _reco_per_true->SetContourLevel(173,0.3508049);
   _reco_per_true->SetContourLevel(174,0.3528327);
   _reco_per_true->SetContourLevel(175,0.3548605);
   _reco_per_true->SetContourLevel(176,0.3568883);
   _reco_per_true->SetContourLevel(177,0.358916);
   _reco_per_true->SetContourLevel(178,0.3609438);
   _reco_per_true->SetContourLevel(179,0.3629716);
   _reco_per_true->SetContourLevel(180,0.3649994);
   _reco_per_true->SetContourLevel(181,0.3670271);
   _reco_per_true->SetContourLevel(182,0.3690549);
   _reco_per_true->SetContourLevel(183,0.3710827);
   _reco_per_true->SetContourLevel(184,0.3731105);
   _reco_per_true->SetContourLevel(185,0.3751382);
   _reco_per_true->SetContourLevel(186,0.377166);
   _reco_per_true->SetContourLevel(187,0.3791938);
   _reco_per_true->SetContourLevel(188,0.3812216);
   _reco_per_true->SetContourLevel(189,0.3832493);
   _reco_per_true->SetContourLevel(190,0.3852771);
   _reco_per_true->SetContourLevel(191,0.3873049);
   _reco_per_true->SetContourLevel(192,0.3893327);
   _reco_per_true->SetContourLevel(193,0.3913604);
   _reco_per_true->SetContourLevel(194,0.3933882);
   _reco_per_true->SetContourLevel(195,0.395416);
   _reco_per_true->SetContourLevel(196,0.3974438);
   _reco_per_true->SetContourLevel(197,0.3994715);
   _reco_per_true->SetContourLevel(198,0.4014993);
   _reco_per_true->SetContourLevel(199,0.4035271);
   _reco_per_true->SetContourLevel(200,0.4055548);
   _reco_per_true->SetContourLevel(201,0.4075826);
   _reco_per_true->SetContourLevel(202,0.4096104);
   _reco_per_true->SetContourLevel(203,0.4116382);
   _reco_per_true->SetContourLevel(204,0.4136659);
   _reco_per_true->SetContourLevel(205,0.4156937);
   _reco_per_true->SetContourLevel(206,0.4177215);
   _reco_per_true->SetContourLevel(207,0.4197493);
   _reco_per_true->SetContourLevel(208,0.421777);
   _reco_per_true->SetContourLevel(209,0.4238048);
   _reco_per_true->SetContourLevel(210,0.4258326);
   _reco_per_true->SetContourLevel(211,0.4278604);
   _reco_per_true->SetContourLevel(212,0.4298881);
   _reco_per_true->SetContourLevel(213,0.4319159);
   _reco_per_true->SetContourLevel(214,0.4339437);
   _reco_per_true->SetContourLevel(215,0.4359715);
   _reco_per_true->SetContourLevel(216,0.4379992);
   _reco_per_true->SetContourLevel(217,0.440027);
   _reco_per_true->SetContourLevel(218,0.4420548);
   _reco_per_true->SetContourLevel(219,0.4440826);
   _reco_per_true->SetContourLevel(220,0.4461103);
   _reco_per_true->SetContourLevel(221,0.4481381);
   _reco_per_true->SetContourLevel(222,0.4501659);
   _reco_per_true->SetContourLevel(223,0.4521937);
   _reco_per_true->SetContourLevel(224,0.4542214);
   _reco_per_true->SetContourLevel(225,0.4562492);
   _reco_per_true->SetContourLevel(226,0.458277);
   _reco_per_true->SetContourLevel(227,0.4603048);
   _reco_per_true->SetContourLevel(228,0.4623325);
   _reco_per_true->SetContourLevel(229,0.4643603);
   _reco_per_true->SetContourLevel(230,0.4663881);
   _reco_per_true->SetContourLevel(231,0.4684158);
   _reco_per_true->SetContourLevel(232,0.4704436);
   _reco_per_true->SetContourLevel(233,0.4724714);
   _reco_per_true->SetContourLevel(234,0.4744992);
   _reco_per_true->SetContourLevel(235,0.4765269);
   _reco_per_true->SetContourLevel(236,0.4785547);
   _reco_per_true->SetContourLevel(237,0.4805825);
   _reco_per_true->SetContourLevel(238,0.4826103);
   _reco_per_true->SetContourLevel(239,0.484638);
   _reco_per_true->SetContourLevel(240,0.4866658);
   _reco_per_true->SetContourLevel(241,0.4886936);
   _reco_per_true->SetContourLevel(242,0.4907214);
   _reco_per_true->SetContourLevel(243,0.4927491);
   _reco_per_true->SetContourLevel(244,0.4947769);
   _reco_per_true->SetContourLevel(245,0.4968047);
   _reco_per_true->SetContourLevel(246,0.4988325);
   _reco_per_true->SetContourLevel(247,0.5008602);
   _reco_per_true->SetContourLevel(248,0.502888);
   _reco_per_true->SetContourLevel(249,0.5049158);
   _reco_per_true->SetContourLevel(250,0.5069436);
   _reco_per_true->SetContourLevel(251,0.5089713);
   _reco_per_true->SetContourLevel(252,0.5109991);
   _reco_per_true->SetContourLevel(253,0.5130269);
   _reco_per_true->SetContourLevel(254,0.5150547);
   
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
   TText *AText = pt->AddText("True Bin 21");
   pt->Draw();
   c1_n22->Modified();
   c1_n22->cd();
   c1_n22->SetSelected(c1_n22);
}

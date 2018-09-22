void smearing_matrix_true_0()
{
//=========Macro generated from canvas: c1/c1
//=========  (Sat Sep 22 12:03:53 2018) by ROOT version6.06/06
   TCanvas *c1 = new TCanvas("c1", "c1",10,45,700,500);
   gStyle->SetOptStat(0);
   c1->SetHighLightColor(2);
   c1->Range(-1.25,-0.3125,1.25,2.8125);
   c1->SetFillColor(10);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameLineWidth(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameLineWidth(2);
   c1->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 0", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx1[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy1[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx1,Graph_fy1);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,-1.1,0);
   Graph_Graph1->SetMinimum(0);
   Graph_Graph1->SetMaximum(0.33);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);
   Graph_Graph1->SetLineWidth(2);
   Graph_Graph1->GetXaxis()->SetNdivisions(506);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph1->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetNdivisions(506);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph1->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetNdivisions(506);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph1->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx2[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy2[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx2,Graph_fy2);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#006ec4");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,0,0.297);
   Graph_Graph2->SetMinimum(0);
   Graph_Graph2->SetMaximum(0.33);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);
   Graph_Graph2->SetLineWidth(2);
   Graph_Graph2->GetXaxis()->SetNdivisions(506);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph2->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetNdivisions(506);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph2->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetNdivisions(506);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph2->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx3[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy3[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx3,Graph_fy3);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0051b3");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","Graph",100,0.252,0.468);
   Graph_Graph3->SetMinimum(0);
   Graph_Graph3->SetMaximum(0.33);
   Graph_Graph3->SetDirectory(0);
   Graph_Graph3->SetStats(0);
   Graph_Graph3->SetLineWidth(2);
   Graph_Graph3->GetXaxis()->SetNdivisions(506);
   Graph_Graph3->GetXaxis()->SetLabelFont(42);
   Graph_Graph3->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph3->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph3->GetXaxis()->SetTitleFont(42);
   Graph_Graph3->GetYaxis()->SetNdivisions(506);
   Graph_Graph3->GetYaxis()->SetLabelFont(42);
   Graph_Graph3->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph3->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph3->GetYaxis()->SetTitleFont(42);
   Graph_Graph3->GetZaxis()->SetNdivisions(506);
   Graph_Graph3->GetZaxis()->SetLabelFont(42);
   Graph_Graph3->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph3->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph3);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx4[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy4[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx4,Graph_fy4);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0034a2");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph4 = new TH1F("Graph_Graph4","Graph",100,0.433,0.637);
   Graph_Graph4->SetMinimum(0);
   Graph_Graph4->SetMaximum(0.33);
   Graph_Graph4->SetDirectory(0);
   Graph_Graph4->SetStats(0);
   Graph_Graph4->SetLineWidth(2);
   Graph_Graph4->GetXaxis()->SetNdivisions(506);
   Graph_Graph4->GetXaxis()->SetLabelFont(42);
   Graph_Graph4->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph4->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph4->GetXaxis()->SetTitleFont(42);
   Graph_Graph4->GetYaxis()->SetNdivisions(506);
   Graph_Graph4->GetYaxis()->SetLabelFont(42);
   Graph_Graph4->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph4->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph4->GetYaxis()->SetTitleFont(42);
   Graph_Graph4->GetZaxis()->SetNdivisions(506);
   Graph_Graph4->GetZaxis()->SetLabelFont(42);
   Graph_Graph4->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph4->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph4);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx5[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy5[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx5,Graph_fy5);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0039a4");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph5 = new TH1F("Graph_Graph5","Graph",100,0.606,0.774);
   Graph_Graph5->SetMinimum(0);
   Graph_Graph5->SetMaximum(0.33);
   Graph_Graph5->SetDirectory(0);
   Graph_Graph5->SetStats(0);
   Graph_Graph5->SetLineWidth(2);
   Graph_Graph5->GetXaxis()->SetNdivisions(506);
   Graph_Graph5->GetXaxis()->SetLabelFont(42);
   Graph_Graph5->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph5->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph5->GetXaxis()->SetTitleFont(42);
   Graph_Graph5->GetYaxis()->SetNdivisions(506);
   Graph_Graph5->GetYaxis()->SetLabelFont(42);
   Graph_Graph5->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph5->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph5->GetYaxis()->SetTitleFont(42);
   Graph_Graph5->GetZaxis()->SetNdivisions(506);
   Graph_Graph5->GetZaxis()->SetLabelFont(42);
   Graph_Graph5->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph5->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph5->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph5);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx6[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy6[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx6,Graph_fy6);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00309f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","Graph",100,0.75,0.87);
   Graph_Graph6->SetMinimum(0);
   Graph_Graph6->SetMaximum(0.33);
   Graph_Graph6->SetDirectory(0);
   Graph_Graph6->SetStats(0);
   Graph_Graph6->SetLineWidth(2);
   Graph_Graph6->GetXaxis()->SetNdivisions(506);
   Graph_Graph6->GetXaxis()->SetLabelFont(42);
   Graph_Graph6->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph6->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph6->GetXaxis()->SetTitleFont(42);
   Graph_Graph6->GetYaxis()->SetNdivisions(506);
   Graph_Graph6->GetYaxis()->SetLabelFont(42);
   Graph_Graph6->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph6->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph6->GetYaxis()->SetTitleFont(42);
   Graph_Graph6->GetZaxis()->SetNdivisions(506);
   Graph_Graph6->GetZaxis()->SetLabelFont(42);
   Graph_Graph6->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph6->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph6->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph6);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx7[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy7[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx7,Graph_fy7);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001c93");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph7 = new TH1F("Graph_Graph7","Graph",100,0.852,0.948);
   Graph_Graph7->SetMinimum(0);
   Graph_Graph7->SetMaximum(0.33);
   Graph_Graph7->SetDirectory(0);
   Graph_Graph7->SetStats(0);
   Graph_Graph7->SetLineWidth(2);
   Graph_Graph7->GetXaxis()->SetNdivisions(506);
   Graph_Graph7->GetXaxis()->SetLabelFont(42);
   Graph_Graph7->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph7->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph7->GetXaxis()->SetTitleFont(42);
   Graph_Graph7->GetYaxis()->SetNdivisions(506);
   Graph_Graph7->GetYaxis()->SetLabelFont(42);
   Graph_Graph7->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph7->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph7->GetYaxis()->SetTitleFont(42);
   Graph_Graph7->GetZaxis()->SetNdivisions(506);
   Graph_Graph7->GetZaxis()->SetLabelFont(42);
   Graph_Graph7->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph7->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph7->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph7);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx8[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy8[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx8,Graph_fy8);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001c93");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph8 = new TH1F("Graph_Graph8","Graph",100,0.934,1.006);
   Graph_Graph8->SetMinimum(0);
   Graph_Graph8->SetMaximum(0.33);
   Graph_Graph8->SetDirectory(0);
   Graph_Graph8->SetStats(0);
   Graph_Graph8->SetLineWidth(2);
   Graph_Graph8->GetXaxis()->SetNdivisions(506);
   Graph_Graph8->GetXaxis()->SetLabelFont(42);
   Graph_Graph8->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph8->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph8->GetXaxis()->SetTitleFont(42);
   Graph_Graph8->GetYaxis()->SetNdivisions(506);
   Graph_Graph8->GetYaxis()->SetLabelFont(42);
   Graph_Graph8->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph8->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph8->GetYaxis()->SetTitleFont(42);
   Graph_Graph8->GetZaxis()->SetNdivisions(506);
   Graph_Graph8->GetZaxis()->SetLabelFont(42);
   Graph_Graph8->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph8->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph8->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph8);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx9[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy9[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx9,Graph_fy9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00b8f1");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph9 = new TH1F("Graph_Graph9","Graph",100,-1.1,0);
   Graph_Graph9->SetMinimum(0.285);
   Graph_Graph9->SetMaximum(0.465);
   Graph_Graph9->SetDirectory(0);
   Graph_Graph9->SetStats(0);
   Graph_Graph9->SetLineWidth(2);
   Graph_Graph9->GetXaxis()->SetNdivisions(506);
   Graph_Graph9->GetXaxis()->SetLabelFont(42);
   Graph_Graph9->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph9->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph9->GetXaxis()->SetTitleFont(42);
   Graph_Graph9->GetYaxis()->SetNdivisions(506);
   Graph_Graph9->GetYaxis()->SetLabelFont(42);
   Graph_Graph9->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph9->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph9->GetYaxis()->SetTitleFont(42);
   Graph_Graph9->GetZaxis()->SetNdivisions(506);
   Graph_Graph9->GetZaxis()->SetLabelFont(42);
   Graph_Graph9->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph9->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph9->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph9);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx10[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy10[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx10,Graph_fy10);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph10 = new TH1F("Graph_Graph10","Graph",100,0,0.297);
   Graph_Graph10->SetMinimum(0.285);
   Graph_Graph10->SetMaximum(0.465);
   Graph_Graph10->SetDirectory(0);
   Graph_Graph10->SetStats(0);
   Graph_Graph10->SetLineWidth(2);
   Graph_Graph10->GetXaxis()->SetNdivisions(506);
   Graph_Graph10->GetXaxis()->SetLabelFont(42);
   Graph_Graph10->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph10->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph10->GetXaxis()->SetTitleFont(42);
   Graph_Graph10->GetYaxis()->SetNdivisions(506);
   Graph_Graph10->GetYaxis()->SetLabelFont(42);
   Graph_Graph10->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph10->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph10->GetYaxis()->SetTitleFont(42);
   Graph_Graph10->GetZaxis()->SetNdivisions(506);
   Graph_Graph10->GetZaxis()->SetLabelFont(42);
   Graph_Graph10->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph10->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph10->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph10);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx11[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy11[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx11,Graph_fy11);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001a92");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph11 = new TH1F("Graph_Graph11","Graph",100,0.252,0.468);
   Graph_Graph11->SetMinimum(0.285);
   Graph_Graph11->SetMaximum(0.465);
   Graph_Graph11->SetDirectory(0);
   Graph_Graph11->SetStats(0);
   Graph_Graph11->SetLineWidth(2);
   Graph_Graph11->GetXaxis()->SetNdivisions(506);
   Graph_Graph11->GetXaxis()->SetLabelFont(42);
   Graph_Graph11->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph11->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph11->GetXaxis()->SetTitleFont(42);
   Graph_Graph11->GetYaxis()->SetNdivisions(506);
   Graph_Graph11->GetYaxis()->SetLabelFont(42);
   Graph_Graph11->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph11->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph11->GetYaxis()->SetTitleFont(42);
   Graph_Graph11->GetZaxis()->SetNdivisions(506);
   Graph_Graph11->GetZaxis()->SetLabelFont(42);
   Graph_Graph11->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph11->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph11->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph11);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx12[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy12[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx12,Graph_fy12);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000e8a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph12 = new TH1F("Graph_Graph12","Graph",100,0.433,0.637);
   Graph_Graph12->SetMinimum(0.285);
   Graph_Graph12->SetMaximum(0.465);
   Graph_Graph12->SetDirectory(0);
   Graph_Graph12->SetStats(0);
   Graph_Graph12->SetLineWidth(2);
   Graph_Graph12->GetXaxis()->SetNdivisions(506);
   Graph_Graph12->GetXaxis()->SetLabelFont(42);
   Graph_Graph12->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph12->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph12->GetXaxis()->SetTitleFont(42);
   Graph_Graph12->GetYaxis()->SetNdivisions(506);
   Graph_Graph12->GetYaxis()->SetLabelFont(42);
   Graph_Graph12->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph12->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph12->GetYaxis()->SetTitleFont(42);
   Graph_Graph12->GetZaxis()->SetNdivisions(506);
   Graph_Graph12->GetZaxis()->SetLabelFont(42);
   Graph_Graph12->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph12->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph12->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph12);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx13[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy13[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx13,Graph_fy13);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001a92");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph13 = new TH1F("Graph_Graph13","Graph",100,0.606,0.774);
   Graph_Graph13->SetMinimum(0.285);
   Graph_Graph13->SetMaximum(0.465);
   Graph_Graph13->SetDirectory(0);
   Graph_Graph13->SetStats(0);
   Graph_Graph13->SetLineWidth(2);
   Graph_Graph13->GetXaxis()->SetNdivisions(506);
   Graph_Graph13->GetXaxis()->SetLabelFont(42);
   Graph_Graph13->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph13->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph13->GetXaxis()->SetTitleFont(42);
   Graph_Graph13->GetYaxis()->SetNdivisions(506);
   Graph_Graph13->GetYaxis()->SetLabelFont(42);
   Graph_Graph13->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph13->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph13->GetYaxis()->SetTitleFont(42);
   Graph_Graph13->GetZaxis()->SetNdivisions(506);
   Graph_Graph13->GetZaxis()->SetLabelFont(42);
   Graph_Graph13->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph13->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph13->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph13);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx14[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy14[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx14,Graph_fy14);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002196");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph14 = new TH1F("Graph_Graph14","Graph",100,0.75,0.87);
   Graph_Graph14->SetMinimum(0.285);
   Graph_Graph14->SetMaximum(0.465);
   Graph_Graph14->SetDirectory(0);
   Graph_Graph14->SetStats(0);
   Graph_Graph14->SetLineWidth(2);
   Graph_Graph14->GetXaxis()->SetNdivisions(506);
   Graph_Graph14->GetXaxis()->SetLabelFont(42);
   Graph_Graph14->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph14->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph14->GetXaxis()->SetTitleFont(42);
   Graph_Graph14->GetYaxis()->SetNdivisions(506);
   Graph_Graph14->GetYaxis()->SetLabelFont(42);
   Graph_Graph14->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph14->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph14->GetYaxis()->SetTitleFont(42);
   Graph_Graph14->GetZaxis()->SetNdivisions(506);
   Graph_Graph14->GetZaxis()->SetLabelFont(42);
   Graph_Graph14->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph14->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph14->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph14);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx15[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy15[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx15,Graph_fy15);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph15 = new TH1F("Graph_Graph15","Graph",100,0.852,0.948);
   Graph_Graph15->SetMinimum(0.285);
   Graph_Graph15->SetMaximum(0.465);
   Graph_Graph15->SetDirectory(0);
   Graph_Graph15->SetStats(0);
   Graph_Graph15->SetLineWidth(2);
   Graph_Graph15->GetXaxis()->SetNdivisions(506);
   Graph_Graph15->GetXaxis()->SetLabelFont(42);
   Graph_Graph15->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph15->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph15->GetXaxis()->SetTitleFont(42);
   Graph_Graph15->GetYaxis()->SetNdivisions(506);
   Graph_Graph15->GetYaxis()->SetLabelFont(42);
   Graph_Graph15->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph15->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph15->GetYaxis()->SetTitleFont(42);
   Graph_Graph15->GetZaxis()->SetNdivisions(506);
   Graph_Graph15->GetZaxis()->SetLabelFont(42);
   Graph_Graph15->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph15->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph15->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph15);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx16[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy16[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx16,Graph_fy16);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001f94");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph16 = new TH1F("Graph_Graph16","Graph",100,0.934,1.006);
   Graph_Graph16->SetMinimum(0.285);
   Graph_Graph16->SetMaximum(0.465);
   Graph_Graph16->SetDirectory(0);
   Graph_Graph16->SetStats(0);
   Graph_Graph16->SetLineWidth(2);
   Graph_Graph16->GetXaxis()->SetNdivisions(506);
   Graph_Graph16->GetXaxis()->SetLabelFont(42);
   Graph_Graph16->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph16->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph16->GetXaxis()->SetTitleFont(42);
   Graph_Graph16->GetYaxis()->SetNdivisions(506);
   Graph_Graph16->GetYaxis()->SetLabelFont(42);
   Graph_Graph16->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph16->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph16->GetYaxis()->SetTitleFont(42);
   Graph_Graph16->GetZaxis()->SetNdivisions(506);
   Graph_Graph16->GetZaxis()->SetLabelFont(42);
   Graph_Graph16->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph16->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph16->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph16);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx17[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy17[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx17,Graph_fy17);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001c93");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph17 = new TH1F("Graph_Graph17","Graph",100,-1.1,0);
   Graph_Graph17->SetMinimum(0.245);
   Graph_Graph17->SetMaximum(2.705);
   Graph_Graph17->SetDirectory(0);
   Graph_Graph17->SetStats(0);
   Graph_Graph17->SetLineWidth(2);
   Graph_Graph17->GetXaxis()->SetNdivisions(506);
   Graph_Graph17->GetXaxis()->SetLabelFont(42);
   Graph_Graph17->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph17->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph17->GetXaxis()->SetTitleFont(42);
   Graph_Graph17->GetYaxis()->SetNdivisions(506);
   Graph_Graph17->GetYaxis()->SetLabelFont(42);
   Graph_Graph17->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph17->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph17->GetYaxis()->SetTitleFont(42);
   Graph_Graph17->GetZaxis()->SetNdivisions(506);
   Graph_Graph17->GetZaxis()->SetLabelFont(42);
   Graph_Graph17->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph17->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph17->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph17);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx18[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy18[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx18,Graph_fy18);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph18 = new TH1F("Graph_Graph18","Graph",100,0,0.297);
   Graph_Graph18->SetMinimum(0.418);
   Graph_Graph18->SetMaximum(0.802);
   Graph_Graph18->SetDirectory(0);
   Graph_Graph18->SetStats(0);
   Graph_Graph18->SetLineWidth(2);
   Graph_Graph18->GetXaxis()->SetNdivisions(506);
   Graph_Graph18->GetXaxis()->SetLabelFont(42);
   Graph_Graph18->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph18->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph18->GetXaxis()->SetTitleFont(42);
   Graph_Graph18->GetYaxis()->SetNdivisions(506);
   Graph_Graph18->GetYaxis()->SetLabelFont(42);
   Graph_Graph18->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph18->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph18->GetYaxis()->SetTitleFont(42);
   Graph_Graph18->GetZaxis()->SetNdivisions(506);
   Graph_Graph18->GetZaxis()->SetLabelFont(42);
   Graph_Graph18->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph18->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph18->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph18);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx19[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy19[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx19,Graph_fy19);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph19 = new TH1F("Graph_Graph19","Graph",100,0.252,0.468);
   Graph_Graph19->SetMinimum(0.418);
   Graph_Graph19->SetMaximum(0.802);
   Graph_Graph19->SetDirectory(0);
   Graph_Graph19->SetStats(0);
   Graph_Graph19->SetLineWidth(2);
   Graph_Graph19->GetXaxis()->SetNdivisions(506);
   Graph_Graph19->GetXaxis()->SetLabelFont(42);
   Graph_Graph19->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph19->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph19->GetXaxis()->SetTitleFont(42);
   Graph_Graph19->GetYaxis()->SetNdivisions(506);
   Graph_Graph19->GetYaxis()->SetLabelFont(42);
   Graph_Graph19->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph19->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph19->GetYaxis()->SetTitleFont(42);
   Graph_Graph19->GetZaxis()->SetNdivisions(506);
   Graph_Graph19->GetZaxis()->SetLabelFont(42);
   Graph_Graph19->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph19->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph19->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph19);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx20[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy20[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx20,Graph_fy20);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph20 = new TH1F("Graph_Graph20","Graph",100,0.433,0.637);
   Graph_Graph20->SetMinimum(0.418);
   Graph_Graph20->SetMaximum(0.802);
   Graph_Graph20->SetDirectory(0);
   Graph_Graph20->SetStats(0);
   Graph_Graph20->SetLineWidth(2);
   Graph_Graph20->GetXaxis()->SetNdivisions(506);
   Graph_Graph20->GetXaxis()->SetLabelFont(42);
   Graph_Graph20->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph20->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph20->GetXaxis()->SetTitleFont(42);
   Graph_Graph20->GetYaxis()->SetNdivisions(506);
   Graph_Graph20->GetYaxis()->SetLabelFont(42);
   Graph_Graph20->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph20->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph20->GetYaxis()->SetTitleFont(42);
   Graph_Graph20->GetZaxis()->SetNdivisions(506);
   Graph_Graph20->GetZaxis()->SetLabelFont(42);
   Graph_Graph20->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph20->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph20->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph20);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx21[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy21[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx21,Graph_fy21);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph21 = new TH1F("Graph_Graph21","Graph",100,0.606,0.774);
   Graph_Graph21->SetMinimum(0.418);
   Graph_Graph21->SetMaximum(0.802);
   Graph_Graph21->SetDirectory(0);
   Graph_Graph21->SetStats(0);
   Graph_Graph21->SetLineWidth(2);
   Graph_Graph21->GetXaxis()->SetNdivisions(506);
   Graph_Graph21->GetXaxis()->SetLabelFont(42);
   Graph_Graph21->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph21->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph21->GetXaxis()->SetTitleFont(42);
   Graph_Graph21->GetYaxis()->SetNdivisions(506);
   Graph_Graph21->GetYaxis()->SetLabelFont(42);
   Graph_Graph21->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph21->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph21->GetYaxis()->SetTitleFont(42);
   Graph_Graph21->GetZaxis()->SetNdivisions(506);
   Graph_Graph21->GetZaxis()->SetLabelFont(42);
   Graph_Graph21->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph21->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph21->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph21);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx22[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy22[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx22,Graph_fy22);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph22 = new TH1F("Graph_Graph22","Graph",100,0.75,0.87);
   Graph_Graph22->SetMinimum(0.418);
   Graph_Graph22->SetMaximum(0.802);
   Graph_Graph22->SetDirectory(0);
   Graph_Graph22->SetStats(0);
   Graph_Graph22->SetLineWidth(2);
   Graph_Graph22->GetXaxis()->SetNdivisions(506);
   Graph_Graph22->GetXaxis()->SetLabelFont(42);
   Graph_Graph22->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph22->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph22->GetXaxis()->SetTitleFont(42);
   Graph_Graph22->GetYaxis()->SetNdivisions(506);
   Graph_Graph22->GetYaxis()->SetLabelFont(42);
   Graph_Graph22->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph22->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph22->GetYaxis()->SetTitleFont(42);
   Graph_Graph22->GetZaxis()->SetNdivisions(506);
   Graph_Graph22->GetZaxis()->SetLabelFont(42);
   Graph_Graph22->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph22->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph22->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph22);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx23[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy23[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx23,Graph_fy23);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00108c");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph23 = new TH1F("Graph_Graph23","Graph",100,0.852,0.948);
   Graph_Graph23->SetMinimum(0.418);
   Graph_Graph23->SetMaximum(0.802);
   Graph_Graph23->SetDirectory(0);
   Graph_Graph23->SetStats(0);
   Graph_Graph23->SetLineWidth(2);
   Graph_Graph23->GetXaxis()->SetNdivisions(506);
   Graph_Graph23->GetXaxis()->SetLabelFont(42);
   Graph_Graph23->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph23->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph23->GetXaxis()->SetTitleFont(42);
   Graph_Graph23->GetYaxis()->SetNdivisions(506);
   Graph_Graph23->GetYaxis()->SetLabelFont(42);
   Graph_Graph23->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph23->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph23->GetYaxis()->SetTitleFont(42);
   Graph_Graph23->GetZaxis()->SetNdivisions(506);
   Graph_Graph23->GetZaxis()->SetLabelFont(42);
   Graph_Graph23->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph23->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph23->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph23);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx24[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy24[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx24,Graph_fy24);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000e8a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph24 = new TH1F("Graph_Graph24","Graph",100,0.934,1.006);
   Graph_Graph24->SetMinimum(0.418);
   Graph_Graph24->SetMaximum(0.802);
   Graph_Graph24->SetDirectory(0);
   Graph_Graph24->SetStats(0);
   Graph_Graph24->SetLineWidth(2);
   Graph_Graph24->GetXaxis()->SetNdivisions(506);
   Graph_Graph24->GetXaxis()->SetLabelFont(42);
   Graph_Graph24->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph24->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph24->GetXaxis()->SetTitleFont(42);
   Graph_Graph24->GetYaxis()->SetNdivisions(506);
   Graph_Graph24->GetYaxis()->SetLabelFont(42);
   Graph_Graph24->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph24->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph24->GetYaxis()->SetTitleFont(42);
   Graph_Graph24->GetZaxis()->SetNdivisions(506);
   Graph_Graph24->GetZaxis()->SetLabelFont(42);
   Graph_Graph24->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph24->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph24->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph24);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx25[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy25[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx25,Graph_fy25);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph25 = new TH1F("Graph_Graph25","Graph",100,0,0.297);
   Graph_Graph25->SetMinimum(0.597);
   Graph_Graph25->SetMaximum(2.673);
   Graph_Graph25->SetDirectory(0);
   Graph_Graph25->SetStats(0);
   Graph_Graph25->SetLineWidth(2);
   Graph_Graph25->GetXaxis()->SetNdivisions(506);
   Graph_Graph25->GetXaxis()->SetLabelFont(42);
   Graph_Graph25->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph25->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph25->GetXaxis()->SetTitleFont(42);
   Graph_Graph25->GetYaxis()->SetNdivisions(506);
   Graph_Graph25->GetYaxis()->SetLabelFont(42);
   Graph_Graph25->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph25->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph25->GetYaxis()->SetTitleFont(42);
   Graph_Graph25->GetZaxis()->SetNdivisions(506);
   Graph_Graph25->GetZaxis()->SetLabelFont(42);
   Graph_Graph25->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph25->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph25->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph25);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx26[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy26[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx26,Graph_fy26);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph26 = new TH1F("Graph_Graph26","Graph",100,0.252,0.468);
   Graph_Graph26->SetMinimum(0.597);
   Graph_Graph26->SetMaximum(2.673);
   Graph_Graph26->SetDirectory(0);
   Graph_Graph26->SetStats(0);
   Graph_Graph26->SetLineWidth(2);
   Graph_Graph26->GetXaxis()->SetNdivisions(506);
   Graph_Graph26->GetXaxis()->SetLabelFont(42);
   Graph_Graph26->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph26->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph26->GetXaxis()->SetTitleFont(42);
   Graph_Graph26->GetYaxis()->SetNdivisions(506);
   Graph_Graph26->GetYaxis()->SetLabelFont(42);
   Graph_Graph26->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph26->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph26->GetYaxis()->SetTitleFont(42);
   Graph_Graph26->GetZaxis()->SetNdivisions(506);
   Graph_Graph26->GetZaxis()->SetLabelFont(42);
   Graph_Graph26->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph26->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph26->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph26);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx27[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy27[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx27,Graph_fy27);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph27 = new TH1F("Graph_Graph27","Graph",100,0.433,0.637);
   Graph_Graph27->SetMinimum(0.597);
   Graph_Graph27->SetMaximum(2.673);
   Graph_Graph27->SetDirectory(0);
   Graph_Graph27->SetStats(0);
   Graph_Graph27->SetLineWidth(2);
   Graph_Graph27->GetXaxis()->SetNdivisions(506);
   Graph_Graph27->GetXaxis()->SetLabelFont(42);
   Graph_Graph27->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph27->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph27->GetXaxis()->SetTitleFont(42);
   Graph_Graph27->GetYaxis()->SetNdivisions(506);
   Graph_Graph27->GetYaxis()->SetLabelFont(42);
   Graph_Graph27->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph27->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph27->GetYaxis()->SetTitleFont(42);
   Graph_Graph27->GetZaxis()->SetNdivisions(506);
   Graph_Graph27->GetZaxis()->SetLabelFont(42);
   Graph_Graph27->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph27->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph27->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph27);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx28[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy28[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx28,Graph_fy28);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph28 = new TH1F("Graph_Graph28","Graph",100,0.606,0.774);
   Graph_Graph28->SetMinimum(0.597);
   Graph_Graph28->SetMaximum(2.673);
   Graph_Graph28->SetDirectory(0);
   Graph_Graph28->SetStats(0);
   Graph_Graph28->SetLineWidth(2);
   Graph_Graph28->GetXaxis()->SetNdivisions(506);
   Graph_Graph28->GetXaxis()->SetLabelFont(42);
   Graph_Graph28->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph28->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph28->GetXaxis()->SetTitleFont(42);
   Graph_Graph28->GetYaxis()->SetNdivisions(506);
   Graph_Graph28->GetYaxis()->SetLabelFont(42);
   Graph_Graph28->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph28->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph28->GetYaxis()->SetTitleFont(42);
   Graph_Graph28->GetZaxis()->SetNdivisions(506);
   Graph_Graph28->GetZaxis()->SetLabelFont(42);
   Graph_Graph28->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph28->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph28->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph28);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx29[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy29[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx29,Graph_fy29);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph29 = new TH1F("Graph_Graph29","Graph",100,0.75,0.87);
   Graph_Graph29->SetMinimum(0.597);
   Graph_Graph29->SetMaximum(2.673);
   Graph_Graph29->SetDirectory(0);
   Graph_Graph29->SetStats(0);
   Graph_Graph29->SetLineWidth(2);
   Graph_Graph29->GetXaxis()->SetNdivisions(506);
   Graph_Graph29->GetXaxis()->SetLabelFont(42);
   Graph_Graph29->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph29->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph29->GetXaxis()->SetTitleFont(42);
   Graph_Graph29->GetYaxis()->SetNdivisions(506);
   Graph_Graph29->GetYaxis()->SetLabelFont(42);
   Graph_Graph29->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph29->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph29->GetYaxis()->SetTitleFont(42);
   Graph_Graph29->GetZaxis()->SetNdivisions(506);
   Graph_Graph29->GetZaxis()->SetLabelFont(42);
   Graph_Graph29->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph29->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph29->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph29);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx30[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy30[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx30,Graph_fy30);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph30 = new TH1F("Graph_Graph30","Graph",100,0.852,0.948);
   Graph_Graph30->SetMinimum(0.597);
   Graph_Graph30->SetMaximum(2.673);
   Graph_Graph30->SetDirectory(0);
   Graph_Graph30->SetStats(0);
   Graph_Graph30->SetLineWidth(2);
   Graph_Graph30->GetXaxis()->SetNdivisions(506);
   Graph_Graph30->GetXaxis()->SetLabelFont(42);
   Graph_Graph30->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph30->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph30->GetXaxis()->SetTitleFont(42);
   Graph_Graph30->GetYaxis()->SetNdivisions(506);
   Graph_Graph30->GetYaxis()->SetLabelFont(42);
   Graph_Graph30->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph30->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph30->GetYaxis()->SetTitleFont(42);
   Graph_Graph30->GetZaxis()->SetNdivisions(506);
   Graph_Graph30->GetZaxis()->SetLabelFont(42);
   Graph_Graph30->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph30->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph30->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph30);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx31[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy31[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx31,Graph_fy31);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph31 = new TH1F("Graph_Graph31","Graph",100,0.934,1.006);
   Graph_Graph31->SetMinimum(0.597);
   Graph_Graph31->SetMaximum(2.673);
   Graph_Graph31->SetDirectory(0);
   Graph_Graph31->SetStats(0);
   Graph_Graph31->SetLineWidth(2);
   Graph_Graph31->GetXaxis()->SetNdivisions(506);
   Graph_Graph31->GetXaxis()->SetLabelFont(42);
   Graph_Graph31->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph31->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph31->GetXaxis()->SetTitleFont(42);
   Graph_Graph31->GetYaxis()->SetNdivisions(506);
   Graph_Graph31->GetYaxis()->SetLabelFont(42);
   Graph_Graph31->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph31->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph31->GetYaxis()->SetTitleFont(42);
   Graph_Graph31->GetZaxis()->SetNdivisions(506);
   Graph_Graph31->GetZaxis()->SetLabelFont(42);
   Graph_Graph31->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph31->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph31->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph31);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.401626);
   _reco_per_true->SetBinContent(2,0.07281658);
   _reco_per_true->SetBinContent(3,0.05421278);
   _reco_per_true->SetBinContent(4,0.0355832);
   _reco_per_true->SetBinContent(5,0.03874055);
   _reco_per_true->SetBinContent(6,0.03253341);
   _reco_per_true->SetBinContent(7,0.02014409);
   _reco_per_true->SetBinContent(8,0.02018293);
   _reco_per_true->SetBinContent(9,0.1226065);
   _reco_per_true->SetBinContent(10,0.015518);
   _reco_per_true->SetBinContent(11,0.01861927);
   _reco_per_true->SetBinContent(12,0.01087087);
   _reco_per_true->SetBinContent(13,0.01858989);
   _reco_per_true->SetBinContent(14,0.02326756);
   _reco_per_true->SetBinContent(15,0.006207465);
   _reco_per_true->SetBinContent(16,0.02169977);
   _reco_per_true->SetBinContent(17,0.02015986);
   _reco_per_true->SetBinContent(18,0.003103131);
   _reco_per_true->SetBinContent(19,0.007778088);
   _reco_per_true->SetBinContent(20,0.006185661);
   _reco_per_true->SetBinContent(21,0.003107908);
   _reco_per_true->SetBinContent(22,0.003110838);
   _reco_per_true->SetBinContent(23,0.01242148);
   _reco_per_true->SetBinContent(24,0.01085312);
   _reco_per_true->SetBinContent(25,0.003095063);
   _reco_per_true->SetBinContent(26,0.006202104);
   _reco_per_true->SetBinContent(27,0.003097565);
   _reco_per_true->SetBinContent(28,0.001558638);
   _reco_per_true->SetBinContent(30,0.001551871);
   _reco_per_true->SetBinContent(31,0.004555842);
   _reco_per_true->SetBinError(1,0.02495653);
   _reco_per_true->SetBinError(2,0.01062156);
   _reco_per_true->SetBinError(3,0.009163695);
   _reco_per_true->SetBinError(4,0.007419658);
   _reco_per_true->SetBinError(5,0.007748173);
   _reco_per_true->SetBinError(6,0.007099428);
   _reco_per_true->SetBinError(7,0.005587027);
   _reco_per_true->SetBinError(8,0.005597778);
   _reco_per_true->SetBinError(9,0.01379436);
   _reco_per_true->SetBinError(10,0.004907244);
   _reco_per_true->SetBinError(11,0.005374947);
   _reco_per_true->SetBinError(12,0.004108834);
   _reco_per_true->SetBinError(13,0.005366526);
   _reco_per_true->SetBinError(14,0.006007708);
   _reco_per_true->SetBinError(15,0.003103745);
   _reco_per_true->SetBinError(16,0.005799585);
   _reco_per_true->SetBinError(17,0.00559138);
   _reco_per_true->SetBinError(18,0.002194245);
   _reco_per_true->SetBinError(19,0.003478473);
   _reco_per_true->SetBinError(20,0.003092859);
   _reco_per_true->SetBinError(21,0.002197625);
   _reco_per_true->SetBinError(22,0.0021997);
   _reco_per_true->SetBinError(23,0.004391689);
   _reco_per_true->SetBinError(24,0.004102104);
   _reco_per_true->SetBinError(25,0.002188556);
   _reco_per_true->SetBinError(26,0.003101061);
   _reco_per_true->SetBinError(27,0.002190312);
   _reco_per_true->SetBinError(28,0.001558638);
   _reco_per_true->SetBinError(30,0.001551871);
   _reco_per_true->SetBinError(31,0.002631785);
   _reco_per_true->SetEntries(645);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.001575004);
   _reco_per_true->SetContourLevel(2,0.003150008);
   _reco_per_true->SetContourLevel(3,0.004725012);
   _reco_per_true->SetContourLevel(4,0.006300015);
   _reco_per_true->SetContourLevel(5,0.007875019);
   _reco_per_true->SetContourLevel(6,0.009450023);
   _reco_per_true->SetContourLevel(7,0.01102503);
   _reco_per_true->SetContourLevel(8,0.01260003);
   _reco_per_true->SetContourLevel(9,0.01417503);
   _reco_per_true->SetContourLevel(10,0.01575004);
   _reco_per_true->SetContourLevel(11,0.01732504);
   _reco_per_true->SetContourLevel(12,0.01890005);
   _reco_per_true->SetContourLevel(13,0.02047505);
   _reco_per_true->SetContourLevel(14,0.02205005);
   _reco_per_true->SetContourLevel(15,0.02362506);
   _reco_per_true->SetContourLevel(16,0.02520006);
   _reco_per_true->SetContourLevel(17,0.02677507);
   _reco_per_true->SetContourLevel(18,0.02835007);
   _reco_per_true->SetContourLevel(19,0.02992507);
   _reco_per_true->SetContourLevel(20,0.03150008);
   _reco_per_true->SetContourLevel(21,0.03307508);
   _reco_per_true->SetContourLevel(22,0.03465008);
   _reco_per_true->SetContourLevel(23,0.03622509);
   _reco_per_true->SetContourLevel(24,0.03780009);
   _reco_per_true->SetContourLevel(25,0.0393751);
   _reco_per_true->SetContourLevel(26,0.0409501);
   _reco_per_true->SetContourLevel(27,0.0425251);
   _reco_per_true->SetContourLevel(28,0.04410011);
   _reco_per_true->SetContourLevel(29,0.04567511);
   _reco_per_true->SetContourLevel(30,0.04725012);
   _reco_per_true->SetContourLevel(31,0.04882512);
   _reco_per_true->SetContourLevel(32,0.05040012);
   _reco_per_true->SetContourLevel(33,0.05197513);
   _reco_per_true->SetContourLevel(34,0.05355013);
   _reco_per_true->SetContourLevel(35,0.05512513);
   _reco_per_true->SetContourLevel(36,0.05670014);
   _reco_per_true->SetContourLevel(37,0.05827514);
   _reco_per_true->SetContourLevel(38,0.05985015);
   _reco_per_true->SetContourLevel(39,0.06142515);
   _reco_per_true->SetContourLevel(40,0.06300015);
   _reco_per_true->SetContourLevel(41,0.06457516);
   _reco_per_true->SetContourLevel(42,0.06615016);
   _reco_per_true->SetContourLevel(43,0.06772516);
   _reco_per_true->SetContourLevel(44,0.06930017);
   _reco_per_true->SetContourLevel(45,0.07087517);
   _reco_per_true->SetContourLevel(46,0.07245018);
   _reco_per_true->SetContourLevel(47,0.07402518);
   _reco_per_true->SetContourLevel(48,0.07560018);
   _reco_per_true->SetContourLevel(49,0.07717519);
   _reco_per_true->SetContourLevel(50,0.07875019);
   _reco_per_true->SetContourLevel(51,0.0803252);
   _reco_per_true->SetContourLevel(52,0.0819002);
   _reco_per_true->SetContourLevel(53,0.0834752);
   _reco_per_true->SetContourLevel(54,0.08505021);
   _reco_per_true->SetContourLevel(55,0.08662521);
   _reco_per_true->SetContourLevel(56,0.08820021);
   _reco_per_true->SetContourLevel(57,0.08977522);
   _reco_per_true->SetContourLevel(58,0.09135022);
   _reco_per_true->SetContourLevel(59,0.09292523);
   _reco_per_true->SetContourLevel(60,0.09450023);
   _reco_per_true->SetContourLevel(61,0.09607523);
   _reco_per_true->SetContourLevel(62,0.09765024);
   _reco_per_true->SetContourLevel(63,0.09922524);
   _reco_per_true->SetContourLevel(64,0.1008002);
   _reco_per_true->SetContourLevel(65,0.1023752);
   _reco_per_true->SetContourLevel(66,0.1039503);
   _reco_per_true->SetContourLevel(67,0.1055253);
   _reco_per_true->SetContourLevel(68,0.1071003);
   _reco_per_true->SetContourLevel(69,0.1086753);
   _reco_per_true->SetContourLevel(70,0.1102503);
   _reco_per_true->SetContourLevel(71,0.1118253);
   _reco_per_true->SetContourLevel(72,0.1134003);
   _reco_per_true->SetContourLevel(73,0.1149753);
   _reco_per_true->SetContourLevel(74,0.1165503);
   _reco_per_true->SetContourLevel(75,0.1181253);
   _reco_per_true->SetContourLevel(76,0.1197003);
   _reco_per_true->SetContourLevel(77,0.1212753);
   _reco_per_true->SetContourLevel(78,0.1228503);
   _reco_per_true->SetContourLevel(79,0.1244253);
   _reco_per_true->SetContourLevel(80,0.1260003);
   _reco_per_true->SetContourLevel(81,0.1275753);
   _reco_per_true->SetContourLevel(82,0.1291503);
   _reco_per_true->SetContourLevel(83,0.1307253);
   _reco_per_true->SetContourLevel(84,0.1323003);
   _reco_per_true->SetContourLevel(85,0.1338753);
   _reco_per_true->SetContourLevel(86,0.1354503);
   _reco_per_true->SetContourLevel(87,0.1370253);
   _reco_per_true->SetContourLevel(88,0.1386003);
   _reco_per_true->SetContourLevel(89,0.1401753);
   _reco_per_true->SetContourLevel(90,0.1417503);
   _reco_per_true->SetContourLevel(91,0.1433253);
   _reco_per_true->SetContourLevel(92,0.1449004);
   _reco_per_true->SetContourLevel(93,0.1464754);
   _reco_per_true->SetContourLevel(94,0.1480504);
   _reco_per_true->SetContourLevel(95,0.1496254);
   _reco_per_true->SetContourLevel(96,0.1512004);
   _reco_per_true->SetContourLevel(97,0.1527754);
   _reco_per_true->SetContourLevel(98,0.1543504);
   _reco_per_true->SetContourLevel(99,0.1559254);
   _reco_per_true->SetContourLevel(100,0.1575004);
   _reco_per_true->SetContourLevel(101,0.1590754);
   _reco_per_true->SetContourLevel(102,0.1606504);
   _reco_per_true->SetContourLevel(103,0.1622254);
   _reco_per_true->SetContourLevel(104,0.1638004);
   _reco_per_true->SetContourLevel(105,0.1653754);
   _reco_per_true->SetContourLevel(106,0.1669504);
   _reco_per_true->SetContourLevel(107,0.1685254);
   _reco_per_true->SetContourLevel(108,0.1701004);
   _reco_per_true->SetContourLevel(109,0.1716754);
   _reco_per_true->SetContourLevel(110,0.1732504);
   _reco_per_true->SetContourLevel(111,0.1748254);
   _reco_per_true->SetContourLevel(112,0.1764004);
   _reco_per_true->SetContourLevel(113,0.1779754);
   _reco_per_true->SetContourLevel(114,0.1795504);
   _reco_per_true->SetContourLevel(115,0.1811254);
   _reco_per_true->SetContourLevel(116,0.1827004);
   _reco_per_true->SetContourLevel(117,0.1842754);
   _reco_per_true->SetContourLevel(118,0.1858505);
   _reco_per_true->SetContourLevel(119,0.1874255);
   _reco_per_true->SetContourLevel(120,0.1890005);
   _reco_per_true->SetContourLevel(121,0.1905755);
   _reco_per_true->SetContourLevel(122,0.1921505);
   _reco_per_true->SetContourLevel(123,0.1937255);
   _reco_per_true->SetContourLevel(124,0.1953005);
   _reco_per_true->SetContourLevel(125,0.1968755);
   _reco_per_true->SetContourLevel(126,0.1984505);
   _reco_per_true->SetContourLevel(127,0.2000255);
   _reco_per_true->SetContourLevel(128,0.2016005);
   _reco_per_true->SetContourLevel(129,0.2031755);
   _reco_per_true->SetContourLevel(130,0.2047505);
   _reco_per_true->SetContourLevel(131,0.2063255);
   _reco_per_true->SetContourLevel(132,0.2079005);
   _reco_per_true->SetContourLevel(133,0.2094755);
   _reco_per_true->SetContourLevel(134,0.2110505);
   _reco_per_true->SetContourLevel(135,0.2126255);
   _reco_per_true->SetContourLevel(136,0.2142005);
   _reco_per_true->SetContourLevel(137,0.2157755);
   _reco_per_true->SetContourLevel(138,0.2173505);
   _reco_per_true->SetContourLevel(139,0.2189255);
   _reco_per_true->SetContourLevel(140,0.2205005);
   _reco_per_true->SetContourLevel(141,0.2220755);
   _reco_per_true->SetContourLevel(142,0.2236505);
   _reco_per_true->SetContourLevel(143,0.2252255);
   _reco_per_true->SetContourLevel(144,0.2268006);
   _reco_per_true->SetContourLevel(145,0.2283756);
   _reco_per_true->SetContourLevel(146,0.2299506);
   _reco_per_true->SetContourLevel(147,0.2315256);
   _reco_per_true->SetContourLevel(148,0.2331006);
   _reco_per_true->SetContourLevel(149,0.2346756);
   _reco_per_true->SetContourLevel(150,0.2362506);
   _reco_per_true->SetContourLevel(151,0.2378256);
   _reco_per_true->SetContourLevel(152,0.2394006);
   _reco_per_true->SetContourLevel(153,0.2409756);
   _reco_per_true->SetContourLevel(154,0.2425506);
   _reco_per_true->SetContourLevel(155,0.2441256);
   _reco_per_true->SetContourLevel(156,0.2457006);
   _reco_per_true->SetContourLevel(157,0.2472756);
   _reco_per_true->SetContourLevel(158,0.2488506);
   _reco_per_true->SetContourLevel(159,0.2504256);
   _reco_per_true->SetContourLevel(160,0.2520006);
   _reco_per_true->SetContourLevel(161,0.2535756);
   _reco_per_true->SetContourLevel(162,0.2551506);
   _reco_per_true->SetContourLevel(163,0.2567256);
   _reco_per_true->SetContourLevel(164,0.2583006);
   _reco_per_true->SetContourLevel(165,0.2598756);
   _reco_per_true->SetContourLevel(166,0.2614506);
   _reco_per_true->SetContourLevel(167,0.2630256);
   _reco_per_true->SetContourLevel(168,0.2646006);
   _reco_per_true->SetContourLevel(169,0.2661756);
   _reco_per_true->SetContourLevel(170,0.2677507);
   _reco_per_true->SetContourLevel(171,0.2693257);
   _reco_per_true->SetContourLevel(172,0.2709007);
   _reco_per_true->SetContourLevel(173,0.2724757);
   _reco_per_true->SetContourLevel(174,0.2740507);
   _reco_per_true->SetContourLevel(175,0.2756257);
   _reco_per_true->SetContourLevel(176,0.2772007);
   _reco_per_true->SetContourLevel(177,0.2787757);
   _reco_per_true->SetContourLevel(178,0.2803507);
   _reco_per_true->SetContourLevel(179,0.2819257);
   _reco_per_true->SetContourLevel(180,0.2835007);
   _reco_per_true->SetContourLevel(181,0.2850757);
   _reco_per_true->SetContourLevel(182,0.2866507);
   _reco_per_true->SetContourLevel(183,0.2882257);
   _reco_per_true->SetContourLevel(184,0.2898007);
   _reco_per_true->SetContourLevel(185,0.2913757);
   _reco_per_true->SetContourLevel(186,0.2929507);
   _reco_per_true->SetContourLevel(187,0.2945257);
   _reco_per_true->SetContourLevel(188,0.2961007);
   _reco_per_true->SetContourLevel(189,0.2976757);
   _reco_per_true->SetContourLevel(190,0.2992507);
   _reco_per_true->SetContourLevel(191,0.3008257);
   _reco_per_true->SetContourLevel(192,0.3024007);
   _reco_per_true->SetContourLevel(193,0.3039757);
   _reco_per_true->SetContourLevel(194,0.3055507);
   _reco_per_true->SetContourLevel(195,0.3071257);
   _reco_per_true->SetContourLevel(196,0.3087008);
   _reco_per_true->SetContourLevel(197,0.3102758);
   _reco_per_true->SetContourLevel(198,0.3118508);
   _reco_per_true->SetContourLevel(199,0.3134258);
   _reco_per_true->SetContourLevel(200,0.3150008);
   _reco_per_true->SetContourLevel(201,0.3165758);
   _reco_per_true->SetContourLevel(202,0.3181508);
   _reco_per_true->SetContourLevel(203,0.3197258);
   _reco_per_true->SetContourLevel(204,0.3213008);
   _reco_per_true->SetContourLevel(205,0.3228758);
   _reco_per_true->SetContourLevel(206,0.3244508);
   _reco_per_true->SetContourLevel(207,0.3260258);
   _reco_per_true->SetContourLevel(208,0.3276008);
   _reco_per_true->SetContourLevel(209,0.3291758);
   _reco_per_true->SetContourLevel(210,0.3307508);
   _reco_per_true->SetContourLevel(211,0.3323258);
   _reco_per_true->SetContourLevel(212,0.3339008);
   _reco_per_true->SetContourLevel(213,0.3354758);
   _reco_per_true->SetContourLevel(214,0.3370508);
   _reco_per_true->SetContourLevel(215,0.3386258);
   _reco_per_true->SetContourLevel(216,0.3402008);
   _reco_per_true->SetContourLevel(217,0.3417758);
   _reco_per_true->SetContourLevel(218,0.3433508);
   _reco_per_true->SetContourLevel(219,0.3449258);
   _reco_per_true->SetContourLevel(220,0.3465008);
   _reco_per_true->SetContourLevel(221,0.3480758);
   _reco_per_true->SetContourLevel(222,0.3496509);
   _reco_per_true->SetContourLevel(223,0.3512259);
   _reco_per_true->SetContourLevel(224,0.3528009);
   _reco_per_true->SetContourLevel(225,0.3543759);
   _reco_per_true->SetContourLevel(226,0.3559509);
   _reco_per_true->SetContourLevel(227,0.3575259);
   _reco_per_true->SetContourLevel(228,0.3591009);
   _reco_per_true->SetContourLevel(229,0.3606759);
   _reco_per_true->SetContourLevel(230,0.3622509);
   _reco_per_true->SetContourLevel(231,0.3638259);
   _reco_per_true->SetContourLevel(232,0.3654009);
   _reco_per_true->SetContourLevel(233,0.3669759);
   _reco_per_true->SetContourLevel(234,0.3685509);
   _reco_per_true->SetContourLevel(235,0.3701259);
   _reco_per_true->SetContourLevel(236,0.3717009);
   _reco_per_true->SetContourLevel(237,0.3732759);
   _reco_per_true->SetContourLevel(238,0.3748509);
   _reco_per_true->SetContourLevel(239,0.3764259);
   _reco_per_true->SetContourLevel(240,0.3780009);
   _reco_per_true->SetContourLevel(241,0.3795759);
   _reco_per_true->SetContourLevel(242,0.3811509);
   _reco_per_true->SetContourLevel(243,0.3827259);
   _reco_per_true->SetContourLevel(244,0.3843009);
   _reco_per_true->SetContourLevel(245,0.3858759);
   _reco_per_true->SetContourLevel(246,0.3874509);
   _reco_per_true->SetContourLevel(247,0.3890259);
   _reco_per_true->SetContourLevel(248,0.390601);
   _reco_per_true->SetContourLevel(249,0.392176);
   _reco_per_true->SetContourLevel(250,0.393751);
   _reco_per_true->SetContourLevel(251,0.395326);
   _reco_per_true->SetContourLevel(252,0.396901);
   _reco_per_true->SetContourLevel(253,0.398476);
   _reco_per_true->SetContourLevel(254,0.400051);
   
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
   TText *AText = pt->AddText("True Bin 0");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}

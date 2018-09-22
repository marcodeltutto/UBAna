void smearing_matrix_true_20()
{
//=========Macro generated from canvas: c1_n21/c1_n21
//=========  (Sat Sep 22 12:03:57 2018) by ROOT version6.06/06
   TCanvas *c1_n21 = new TCanvas("c1_n21", "c1_n21",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n21->SetHighLightColor(2);
   c1_n21->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n21->SetFillColor(10);
   c1_n21->SetBorderMode(0);
   c1_n21->SetBorderSize(2);
   c1_n21->SetFrameLineWidth(2);
   c1_n21->SetFrameBorderMode(0);
   c1_n21->SetFrameLineWidth(2);
   c1_n21->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 20", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx621[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy621[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx621,Graph_fy621);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph621 = new TH1F("Graph_Graph621","Graph",100,-1.1,0);
   Graph_Graph621->SetMinimum(0);
   Graph_Graph621->SetMaximum(0.33);
   Graph_Graph621->SetDirectory(0);
   Graph_Graph621->SetStats(0);
   Graph_Graph621->SetLineWidth(2);
   Graph_Graph621->GetXaxis()->SetNdivisions(506);
   Graph_Graph621->GetXaxis()->SetLabelFont(42);
   Graph_Graph621->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph621->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph621->GetXaxis()->SetTitleFont(42);
   Graph_Graph621->GetYaxis()->SetNdivisions(506);
   Graph_Graph621->GetYaxis()->SetLabelFont(42);
   Graph_Graph621->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph621->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph621->GetYaxis()->SetTitleFont(42);
   Graph_Graph621->GetZaxis()->SetNdivisions(506);
   Graph_Graph621->GetZaxis()->SetLabelFont(42);
   Graph_Graph621->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph621->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph621->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph621);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx622[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy622[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx622,Graph_fy622);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph622 = new TH1F("Graph_Graph622","Graph",100,0,0.297);
   Graph_Graph622->SetMinimum(0);
   Graph_Graph622->SetMaximum(0.33);
   Graph_Graph622->SetDirectory(0);
   Graph_Graph622->SetStats(0);
   Graph_Graph622->SetLineWidth(2);
   Graph_Graph622->GetXaxis()->SetNdivisions(506);
   Graph_Graph622->GetXaxis()->SetLabelFont(42);
   Graph_Graph622->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph622->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph622->GetXaxis()->SetTitleFont(42);
   Graph_Graph622->GetYaxis()->SetNdivisions(506);
   Graph_Graph622->GetYaxis()->SetLabelFont(42);
   Graph_Graph622->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph622->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph622->GetYaxis()->SetTitleFont(42);
   Graph_Graph622->GetZaxis()->SetNdivisions(506);
   Graph_Graph622->GetZaxis()->SetLabelFont(42);
   Graph_Graph622->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph622->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph622->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph622);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx623[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy623[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx623,Graph_fy623);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph623 = new TH1F("Graph_Graph623","Graph",100,0.252,0.468);
   Graph_Graph623->SetMinimum(0);
   Graph_Graph623->SetMaximum(0.33);
   Graph_Graph623->SetDirectory(0);
   Graph_Graph623->SetStats(0);
   Graph_Graph623->SetLineWidth(2);
   Graph_Graph623->GetXaxis()->SetNdivisions(506);
   Graph_Graph623->GetXaxis()->SetLabelFont(42);
   Graph_Graph623->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph623->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph623->GetXaxis()->SetTitleFont(42);
   Graph_Graph623->GetYaxis()->SetNdivisions(506);
   Graph_Graph623->GetYaxis()->SetLabelFont(42);
   Graph_Graph623->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph623->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph623->GetYaxis()->SetTitleFont(42);
   Graph_Graph623->GetZaxis()->SetNdivisions(506);
   Graph_Graph623->GetZaxis()->SetLabelFont(42);
   Graph_Graph623->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph623->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph623->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph623);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx624[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy624[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx624,Graph_fy624);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph624 = new TH1F("Graph_Graph624","Graph",100,0.433,0.637);
   Graph_Graph624->SetMinimum(0);
   Graph_Graph624->SetMaximum(0.33);
   Graph_Graph624->SetDirectory(0);
   Graph_Graph624->SetStats(0);
   Graph_Graph624->SetLineWidth(2);
   Graph_Graph624->GetXaxis()->SetNdivisions(506);
   Graph_Graph624->GetXaxis()->SetLabelFont(42);
   Graph_Graph624->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph624->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph624->GetXaxis()->SetTitleFont(42);
   Graph_Graph624->GetYaxis()->SetNdivisions(506);
   Graph_Graph624->GetYaxis()->SetLabelFont(42);
   Graph_Graph624->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph624->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph624->GetYaxis()->SetTitleFont(42);
   Graph_Graph624->GetZaxis()->SetNdivisions(506);
   Graph_Graph624->GetZaxis()->SetLabelFont(42);
   Graph_Graph624->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph624->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph624->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph624);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx625[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy625[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx625,Graph_fy625);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph625 = new TH1F("Graph_Graph625","Graph",100,0.606,0.774);
   Graph_Graph625->SetMinimum(0);
   Graph_Graph625->SetMaximum(0.33);
   Graph_Graph625->SetDirectory(0);
   Graph_Graph625->SetStats(0);
   Graph_Graph625->SetLineWidth(2);
   Graph_Graph625->GetXaxis()->SetNdivisions(506);
   Graph_Graph625->GetXaxis()->SetLabelFont(42);
   Graph_Graph625->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph625->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph625->GetXaxis()->SetTitleFont(42);
   Graph_Graph625->GetYaxis()->SetNdivisions(506);
   Graph_Graph625->GetYaxis()->SetLabelFont(42);
   Graph_Graph625->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph625->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph625->GetYaxis()->SetTitleFont(42);
   Graph_Graph625->GetZaxis()->SetNdivisions(506);
   Graph_Graph625->GetZaxis()->SetLabelFont(42);
   Graph_Graph625->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph625->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph625->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph625);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx626[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy626[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx626,Graph_fy626);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph626 = new TH1F("Graph_Graph626","Graph",100,0.75,0.87);
   Graph_Graph626->SetMinimum(0);
   Graph_Graph626->SetMaximum(0.33);
   Graph_Graph626->SetDirectory(0);
   Graph_Graph626->SetStats(0);
   Graph_Graph626->SetLineWidth(2);
   Graph_Graph626->GetXaxis()->SetNdivisions(506);
   Graph_Graph626->GetXaxis()->SetLabelFont(42);
   Graph_Graph626->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph626->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph626->GetXaxis()->SetTitleFont(42);
   Graph_Graph626->GetYaxis()->SetNdivisions(506);
   Graph_Graph626->GetYaxis()->SetLabelFont(42);
   Graph_Graph626->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph626->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph626->GetYaxis()->SetTitleFont(42);
   Graph_Graph626->GetZaxis()->SetNdivisions(506);
   Graph_Graph626->GetZaxis()->SetLabelFont(42);
   Graph_Graph626->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph626->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph626->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph626);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx627[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy627[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx627,Graph_fy627);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph627 = new TH1F("Graph_Graph627","Graph",100,0.852,0.948);
   Graph_Graph627->SetMinimum(0);
   Graph_Graph627->SetMaximum(0.33);
   Graph_Graph627->SetDirectory(0);
   Graph_Graph627->SetStats(0);
   Graph_Graph627->SetLineWidth(2);
   Graph_Graph627->GetXaxis()->SetNdivisions(506);
   Graph_Graph627->GetXaxis()->SetLabelFont(42);
   Graph_Graph627->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph627->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph627->GetXaxis()->SetTitleFont(42);
   Graph_Graph627->GetYaxis()->SetNdivisions(506);
   Graph_Graph627->GetYaxis()->SetLabelFont(42);
   Graph_Graph627->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph627->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph627->GetYaxis()->SetTitleFont(42);
   Graph_Graph627->GetZaxis()->SetNdivisions(506);
   Graph_Graph627->GetZaxis()->SetLabelFont(42);
   Graph_Graph627->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph627->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph627->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph627);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx628[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy628[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx628,Graph_fy628);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph628 = new TH1F("Graph_Graph628","Graph",100,0.934,1.006);
   Graph_Graph628->SetMinimum(0);
   Graph_Graph628->SetMaximum(0.33);
   Graph_Graph628->SetDirectory(0);
   Graph_Graph628->SetStats(0);
   Graph_Graph628->SetLineWidth(2);
   Graph_Graph628->GetXaxis()->SetNdivisions(506);
   Graph_Graph628->GetXaxis()->SetLabelFont(42);
   Graph_Graph628->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph628->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph628->GetXaxis()->SetTitleFont(42);
   Graph_Graph628->GetYaxis()->SetNdivisions(506);
   Graph_Graph628->GetYaxis()->SetLabelFont(42);
   Graph_Graph628->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph628->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph628->GetYaxis()->SetTitleFont(42);
   Graph_Graph628->GetZaxis()->SetNdivisions(506);
   Graph_Graph628->GetZaxis()->SetLabelFont(42);
   Graph_Graph628->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph628->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph628->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph628);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx629[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy629[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx629,Graph_fy629);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph629 = new TH1F("Graph_Graph629","Graph",100,-1.1,0);
   Graph_Graph629->SetMinimum(0.285);
   Graph_Graph629->SetMaximum(0.465);
   Graph_Graph629->SetDirectory(0);
   Graph_Graph629->SetStats(0);
   Graph_Graph629->SetLineWidth(2);
   Graph_Graph629->GetXaxis()->SetNdivisions(506);
   Graph_Graph629->GetXaxis()->SetLabelFont(42);
   Graph_Graph629->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph629->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph629->GetXaxis()->SetTitleFont(42);
   Graph_Graph629->GetYaxis()->SetNdivisions(506);
   Graph_Graph629->GetYaxis()->SetLabelFont(42);
   Graph_Graph629->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph629->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph629->GetYaxis()->SetTitleFont(42);
   Graph_Graph629->GetZaxis()->SetNdivisions(506);
   Graph_Graph629->GetZaxis()->SetLabelFont(42);
   Graph_Graph629->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph629->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph629->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph629);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx630[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy630[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx630,Graph_fy630);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph630 = new TH1F("Graph_Graph630","Graph",100,0,0.297);
   Graph_Graph630->SetMinimum(0.285);
   Graph_Graph630->SetMaximum(0.465);
   Graph_Graph630->SetDirectory(0);
   Graph_Graph630->SetStats(0);
   Graph_Graph630->SetLineWidth(2);
   Graph_Graph630->GetXaxis()->SetNdivisions(506);
   Graph_Graph630->GetXaxis()->SetLabelFont(42);
   Graph_Graph630->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph630->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph630->GetXaxis()->SetTitleFont(42);
   Graph_Graph630->GetYaxis()->SetNdivisions(506);
   Graph_Graph630->GetYaxis()->SetLabelFont(42);
   Graph_Graph630->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph630->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph630->GetYaxis()->SetTitleFont(42);
   Graph_Graph630->GetZaxis()->SetNdivisions(506);
   Graph_Graph630->GetZaxis()->SetLabelFont(42);
   Graph_Graph630->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph630->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph630->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph630);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx631[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy631[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx631,Graph_fy631);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph631 = new TH1F("Graph_Graph631","Graph",100,0.252,0.468);
   Graph_Graph631->SetMinimum(0.285);
   Graph_Graph631->SetMaximum(0.465);
   Graph_Graph631->SetDirectory(0);
   Graph_Graph631->SetStats(0);
   Graph_Graph631->SetLineWidth(2);
   Graph_Graph631->GetXaxis()->SetNdivisions(506);
   Graph_Graph631->GetXaxis()->SetLabelFont(42);
   Graph_Graph631->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph631->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph631->GetXaxis()->SetTitleFont(42);
   Graph_Graph631->GetYaxis()->SetNdivisions(506);
   Graph_Graph631->GetYaxis()->SetLabelFont(42);
   Graph_Graph631->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph631->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph631->GetYaxis()->SetTitleFont(42);
   Graph_Graph631->GetZaxis()->SetNdivisions(506);
   Graph_Graph631->GetZaxis()->SetLabelFont(42);
   Graph_Graph631->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph631->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph631->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph631);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx632[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy632[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx632,Graph_fy632);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00158f");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph632 = new TH1F("Graph_Graph632","Graph",100,0.433,0.637);
   Graph_Graph632->SetMinimum(0.285);
   Graph_Graph632->SetMaximum(0.465);
   Graph_Graph632->SetDirectory(0);
   Graph_Graph632->SetStats(0);
   Graph_Graph632->SetLineWidth(2);
   Graph_Graph632->GetXaxis()->SetNdivisions(506);
   Graph_Graph632->GetXaxis()->SetLabelFont(42);
   Graph_Graph632->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph632->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph632->GetXaxis()->SetTitleFont(42);
   Graph_Graph632->GetYaxis()->SetNdivisions(506);
   Graph_Graph632->GetYaxis()->SetLabelFont(42);
   Graph_Graph632->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph632->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph632->GetYaxis()->SetTitleFont(42);
   Graph_Graph632->GetZaxis()->SetNdivisions(506);
   Graph_Graph632->GetZaxis()->SetLabelFont(42);
   Graph_Graph632->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph632->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph632->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph632);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx633[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy633[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx633,Graph_fy633);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0058b7");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph633 = new TH1F("Graph_Graph633","Graph",100,0.606,0.774);
   Graph_Graph633->SetMinimum(0.285);
   Graph_Graph633->SetMaximum(0.465);
   Graph_Graph633->SetDirectory(0);
   Graph_Graph633->SetStats(0);
   Graph_Graph633->SetLineWidth(2);
   Graph_Graph633->GetXaxis()->SetNdivisions(506);
   Graph_Graph633->GetXaxis()->SetLabelFont(42);
   Graph_Graph633->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph633->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph633->GetXaxis()->SetTitleFont(42);
   Graph_Graph633->GetYaxis()->SetNdivisions(506);
   Graph_Graph633->GetYaxis()->SetLabelFont(42);
   Graph_Graph633->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph633->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph633->GetYaxis()->SetTitleFont(42);
   Graph_Graph633->GetZaxis()->SetNdivisions(506);
   Graph_Graph633->GetZaxis()->SetLabelFont(42);
   Graph_Graph633->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph633->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph633->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph633);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx634[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy634[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx634,Graph_fy634);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001a92");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph634 = new TH1F("Graph_Graph634","Graph",100,0.75,0.87);
   Graph_Graph634->SetMinimum(0.285);
   Graph_Graph634->SetMaximum(0.465);
   Graph_Graph634->SetDirectory(0);
   Graph_Graph634->SetStats(0);
   Graph_Graph634->SetLineWidth(2);
   Graph_Graph634->GetXaxis()->SetNdivisions(506);
   Graph_Graph634->GetXaxis()->SetLabelFont(42);
   Graph_Graph634->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph634->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph634->GetXaxis()->SetTitleFont(42);
   Graph_Graph634->GetYaxis()->SetNdivisions(506);
   Graph_Graph634->GetYaxis()->SetLabelFont(42);
   Graph_Graph634->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph634->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph634->GetYaxis()->SetTitleFont(42);
   Graph_Graph634->GetZaxis()->SetNdivisions(506);
   Graph_Graph634->GetZaxis()->SetLabelFont(42);
   Graph_Graph634->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph634->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph634->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph634);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx635[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy635[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx635,Graph_fy635);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph635 = new TH1F("Graph_Graph635","Graph",100,0.852,0.948);
   Graph_Graph635->SetMinimum(0.285);
   Graph_Graph635->SetMaximum(0.465);
   Graph_Graph635->SetDirectory(0);
   Graph_Graph635->SetStats(0);
   Graph_Graph635->SetLineWidth(2);
   Graph_Graph635->GetXaxis()->SetNdivisions(506);
   Graph_Graph635->GetXaxis()->SetLabelFont(42);
   Graph_Graph635->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph635->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph635->GetXaxis()->SetTitleFont(42);
   Graph_Graph635->GetYaxis()->SetNdivisions(506);
   Graph_Graph635->GetYaxis()->SetLabelFont(42);
   Graph_Graph635->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph635->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph635->GetYaxis()->SetTitleFont(42);
   Graph_Graph635->GetZaxis()->SetNdivisions(506);
   Graph_Graph635->GetZaxis()->SetLabelFont(42);
   Graph_Graph635->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph635->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph635->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph635);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx636[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy636[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx636,Graph_fy636);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph636 = new TH1F("Graph_Graph636","Graph",100,0.934,1.006);
   Graph_Graph636->SetMinimum(0.285);
   Graph_Graph636->SetMaximum(0.465);
   Graph_Graph636->SetDirectory(0);
   Graph_Graph636->SetStats(0);
   Graph_Graph636->SetLineWidth(2);
   Graph_Graph636->GetXaxis()->SetNdivisions(506);
   Graph_Graph636->GetXaxis()->SetLabelFont(42);
   Graph_Graph636->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph636->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph636->GetXaxis()->SetTitleFont(42);
   Graph_Graph636->GetYaxis()->SetNdivisions(506);
   Graph_Graph636->GetYaxis()->SetLabelFont(42);
   Graph_Graph636->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph636->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph636->GetYaxis()->SetTitleFont(42);
   Graph_Graph636->GetZaxis()->SetNdivisions(506);
   Graph_Graph636->GetZaxis()->SetLabelFont(42);
   Graph_Graph636->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph636->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph636->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph636);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx637[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy637[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx637,Graph_fy637);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph637 = new TH1F("Graph_Graph637","Graph",100,-1.1,0);
   Graph_Graph637->SetMinimum(0.245);
   Graph_Graph637->SetMaximum(2.705);
   Graph_Graph637->SetDirectory(0);
   Graph_Graph637->SetStats(0);
   Graph_Graph637->SetLineWidth(2);
   Graph_Graph637->GetXaxis()->SetNdivisions(506);
   Graph_Graph637->GetXaxis()->SetLabelFont(42);
   Graph_Graph637->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph637->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph637->GetXaxis()->SetTitleFont(42);
   Graph_Graph637->GetYaxis()->SetNdivisions(506);
   Graph_Graph637->GetYaxis()->SetLabelFont(42);
   Graph_Graph637->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph637->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph637->GetYaxis()->SetTitleFont(42);
   Graph_Graph637->GetZaxis()->SetNdivisions(506);
   Graph_Graph637->GetZaxis()->SetLabelFont(42);
   Graph_Graph637->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph637->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph637->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph637);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx638[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy638[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx638,Graph_fy638);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph638 = new TH1F("Graph_Graph638","Graph",100,0,0.297);
   Graph_Graph638->SetMinimum(0.418);
   Graph_Graph638->SetMaximum(0.802);
   Graph_Graph638->SetDirectory(0);
   Graph_Graph638->SetStats(0);
   Graph_Graph638->SetLineWidth(2);
   Graph_Graph638->GetXaxis()->SetNdivisions(506);
   Graph_Graph638->GetXaxis()->SetLabelFont(42);
   Graph_Graph638->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph638->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph638->GetXaxis()->SetTitleFont(42);
   Graph_Graph638->GetYaxis()->SetNdivisions(506);
   Graph_Graph638->GetYaxis()->SetLabelFont(42);
   Graph_Graph638->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph638->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph638->GetYaxis()->SetTitleFont(42);
   Graph_Graph638->GetZaxis()->SetNdivisions(506);
   Graph_Graph638->GetZaxis()->SetLabelFont(42);
   Graph_Graph638->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph638->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph638->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph638);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx639[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy639[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx639,Graph_fy639);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph639 = new TH1F("Graph_Graph639","Graph",100,0.252,0.468);
   Graph_Graph639->SetMinimum(0.418);
   Graph_Graph639->SetMaximum(0.802);
   Graph_Graph639->SetDirectory(0);
   Graph_Graph639->SetStats(0);
   Graph_Graph639->SetLineWidth(2);
   Graph_Graph639->GetXaxis()->SetNdivisions(506);
   Graph_Graph639->GetXaxis()->SetLabelFont(42);
   Graph_Graph639->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph639->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph639->GetXaxis()->SetTitleFont(42);
   Graph_Graph639->GetYaxis()->SetNdivisions(506);
   Graph_Graph639->GetYaxis()->SetLabelFont(42);
   Graph_Graph639->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph639->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph639->GetYaxis()->SetTitleFont(42);
   Graph_Graph639->GetZaxis()->SetNdivisions(506);
   Graph_Graph639->GetZaxis()->SetLabelFont(42);
   Graph_Graph639->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph639->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph639->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph639);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx640[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy640[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx640,Graph_fy640);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#004aaf");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph640 = new TH1F("Graph_Graph640","Graph",100,0.433,0.637);
   Graph_Graph640->SetMinimum(0.418);
   Graph_Graph640->SetMaximum(0.802);
   Graph_Graph640->SetDirectory(0);
   Graph_Graph640->SetStats(0);
   Graph_Graph640->SetLineWidth(2);
   Graph_Graph640->GetXaxis()->SetNdivisions(506);
   Graph_Graph640->GetXaxis()->SetLabelFont(42);
   Graph_Graph640->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph640->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph640->GetXaxis()->SetTitleFont(42);
   Graph_Graph640->GetYaxis()->SetNdivisions(506);
   Graph_Graph640->GetYaxis()->SetLabelFont(42);
   Graph_Graph640->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph640->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph640->GetYaxis()->SetTitleFont(42);
   Graph_Graph640->GetZaxis()->SetNdivisions(506);
   Graph_Graph640->GetZaxis()->SetLabelFont(42);
   Graph_Graph640->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph640->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph640->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph640);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx641[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy641[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx641,Graph_fy641);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph641 = new TH1F("Graph_Graph641","Graph",100,0.606,0.774);
   Graph_Graph641->SetMinimum(0.418);
   Graph_Graph641->SetMaximum(0.802);
   Graph_Graph641->SetDirectory(0);
   Graph_Graph641->SetStats(0);
   Graph_Graph641->SetLineWidth(2);
   Graph_Graph641->GetXaxis()->SetNdivisions(506);
   Graph_Graph641->GetXaxis()->SetLabelFont(42);
   Graph_Graph641->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph641->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph641->GetXaxis()->SetTitleFont(42);
   Graph_Graph641->GetYaxis()->SetNdivisions(506);
   Graph_Graph641->GetYaxis()->SetLabelFont(42);
   Graph_Graph641->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph641->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph641->GetYaxis()->SetTitleFont(42);
   Graph_Graph641->GetZaxis()->SetNdivisions(506);
   Graph_Graph641->GetZaxis()->SetLabelFont(42);
   Graph_Graph641->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph641->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph641->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph641);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx642[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy642[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx642,Graph_fy642);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0067c0");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph642 = new TH1F("Graph_Graph642","Graph",100,0.75,0.87);
   Graph_Graph642->SetMinimum(0.418);
   Graph_Graph642->SetMaximum(0.802);
   Graph_Graph642->SetDirectory(0);
   Graph_Graph642->SetStats(0);
   Graph_Graph642->SetLineWidth(2);
   Graph_Graph642->GetXaxis()->SetNdivisions(506);
   Graph_Graph642->GetXaxis()->SetLabelFont(42);
   Graph_Graph642->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph642->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph642->GetXaxis()->SetTitleFont(42);
   Graph_Graph642->GetYaxis()->SetNdivisions(506);
   Graph_Graph642->GetYaxis()->SetLabelFont(42);
   Graph_Graph642->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph642->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph642->GetYaxis()->SetTitleFont(42);
   Graph_Graph642->GetZaxis()->SetNdivisions(506);
   Graph_Graph642->GetZaxis()->SetLabelFont(42);
   Graph_Graph642->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph642->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph642->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph642);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx643[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy643[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx643,Graph_fy643);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph643 = new TH1F("Graph_Graph643","Graph",100,0.852,0.948);
   Graph_Graph643->SetMinimum(0.418);
   Graph_Graph643->SetMaximum(0.802);
   Graph_Graph643->SetDirectory(0);
   Graph_Graph643->SetStats(0);
   Graph_Graph643->SetLineWidth(2);
   Graph_Graph643->GetXaxis()->SetNdivisions(506);
   Graph_Graph643->GetXaxis()->SetLabelFont(42);
   Graph_Graph643->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph643->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph643->GetXaxis()->SetTitleFont(42);
   Graph_Graph643->GetYaxis()->SetNdivisions(506);
   Graph_Graph643->GetYaxis()->SetLabelFont(42);
   Graph_Graph643->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph643->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph643->GetYaxis()->SetTitleFont(42);
   Graph_Graph643->GetZaxis()->SetNdivisions(506);
   Graph_Graph643->GetZaxis()->SetLabelFont(42);
   Graph_Graph643->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph643->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph643->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph643);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx644[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy644[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx644,Graph_fy644);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph644 = new TH1F("Graph_Graph644","Graph",100,0.934,1.006);
   Graph_Graph644->SetMinimum(0.418);
   Graph_Graph644->SetMaximum(0.802);
   Graph_Graph644->SetDirectory(0);
   Graph_Graph644->SetStats(0);
   Graph_Graph644->SetLineWidth(2);
   Graph_Graph644->GetXaxis()->SetNdivisions(506);
   Graph_Graph644->GetXaxis()->SetLabelFont(42);
   Graph_Graph644->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph644->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph644->GetXaxis()->SetTitleFont(42);
   Graph_Graph644->GetYaxis()->SetNdivisions(506);
   Graph_Graph644->GetYaxis()->SetLabelFont(42);
   Graph_Graph644->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph644->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph644->GetYaxis()->SetTitleFont(42);
   Graph_Graph644->GetZaxis()->SetNdivisions(506);
   Graph_Graph644->GetZaxis()->SetLabelFont(42);
   Graph_Graph644->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph644->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph644->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph644);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx645[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy645[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx645,Graph_fy645);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph645 = new TH1F("Graph_Graph645","Graph",100,0,0.297);
   Graph_Graph645->SetMinimum(0.597);
   Graph_Graph645->SetMaximum(2.673);
   Graph_Graph645->SetDirectory(0);
   Graph_Graph645->SetStats(0);
   Graph_Graph645->SetLineWidth(2);
   Graph_Graph645->GetXaxis()->SetNdivisions(506);
   Graph_Graph645->GetXaxis()->SetLabelFont(42);
   Graph_Graph645->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph645->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph645->GetXaxis()->SetTitleFont(42);
   Graph_Graph645->GetYaxis()->SetNdivisions(506);
   Graph_Graph645->GetYaxis()->SetLabelFont(42);
   Graph_Graph645->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph645->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph645->GetYaxis()->SetTitleFont(42);
   Graph_Graph645->GetZaxis()->SetNdivisions(506);
   Graph_Graph645->GetZaxis()->SetLabelFont(42);
   Graph_Graph645->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph645->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph645->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph645);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx646[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy646[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx646,Graph_fy646);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph646 = new TH1F("Graph_Graph646","Graph",100,0.252,0.468);
   Graph_Graph646->SetMinimum(0.597);
   Graph_Graph646->SetMaximum(2.673);
   Graph_Graph646->SetDirectory(0);
   Graph_Graph646->SetStats(0);
   Graph_Graph646->SetLineWidth(2);
   Graph_Graph646->GetXaxis()->SetNdivisions(506);
   Graph_Graph646->GetXaxis()->SetLabelFont(42);
   Graph_Graph646->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph646->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph646->GetXaxis()->SetTitleFont(42);
   Graph_Graph646->GetYaxis()->SetNdivisions(506);
   Graph_Graph646->GetYaxis()->SetLabelFont(42);
   Graph_Graph646->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph646->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph646->GetYaxis()->SetTitleFont(42);
   Graph_Graph646->GetZaxis()->SetNdivisions(506);
   Graph_Graph646->GetZaxis()->SetLabelFont(42);
   Graph_Graph646->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph646->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph646->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph646);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx647[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy647[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx647,Graph_fy647);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph647 = new TH1F("Graph_Graph647","Graph",100,0.433,0.637);
   Graph_Graph647->SetMinimum(0.597);
   Graph_Graph647->SetMaximum(2.673);
   Graph_Graph647->SetDirectory(0);
   Graph_Graph647->SetStats(0);
   Graph_Graph647->SetLineWidth(2);
   Graph_Graph647->GetXaxis()->SetNdivisions(506);
   Graph_Graph647->GetXaxis()->SetLabelFont(42);
   Graph_Graph647->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph647->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph647->GetXaxis()->SetTitleFont(42);
   Graph_Graph647->GetYaxis()->SetNdivisions(506);
   Graph_Graph647->GetYaxis()->SetLabelFont(42);
   Graph_Graph647->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph647->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph647->GetYaxis()->SetTitleFont(42);
   Graph_Graph647->GetZaxis()->SetNdivisions(506);
   Graph_Graph647->GetZaxis()->SetLabelFont(42);
   Graph_Graph647->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph647->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph647->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph647);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx648[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy648[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx648,Graph_fy648);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0084d1");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph648 = new TH1F("Graph_Graph648","Graph",100,0.606,0.774);
   Graph_Graph648->SetMinimum(0.597);
   Graph_Graph648->SetMaximum(2.673);
   Graph_Graph648->SetDirectory(0);
   Graph_Graph648->SetStats(0);
   Graph_Graph648->SetLineWidth(2);
   Graph_Graph648->GetXaxis()->SetNdivisions(506);
   Graph_Graph648->GetXaxis()->SetLabelFont(42);
   Graph_Graph648->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph648->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph648->GetXaxis()->SetTitleFont(42);
   Graph_Graph648->GetYaxis()->SetNdivisions(506);
   Graph_Graph648->GetYaxis()->SetLabelFont(42);
   Graph_Graph648->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph648->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph648->GetYaxis()->SetTitleFont(42);
   Graph_Graph648->GetZaxis()->SetNdivisions(506);
   Graph_Graph648->GetZaxis()->SetLabelFont(42);
   Graph_Graph648->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph648->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph648->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph648);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx649[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy649[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx649,Graph_fy649);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph649 = new TH1F("Graph_Graph649","Graph",100,0.75,0.87);
   Graph_Graph649->SetMinimum(0.597);
   Graph_Graph649->SetMaximum(2.673);
   Graph_Graph649->SetDirectory(0);
   Graph_Graph649->SetStats(0);
   Graph_Graph649->SetLineWidth(2);
   Graph_Graph649->GetXaxis()->SetNdivisions(506);
   Graph_Graph649->GetXaxis()->SetLabelFont(42);
   Graph_Graph649->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph649->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph649->GetXaxis()->SetTitleFont(42);
   Graph_Graph649->GetYaxis()->SetNdivisions(506);
   Graph_Graph649->GetYaxis()->SetLabelFont(42);
   Graph_Graph649->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph649->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph649->GetYaxis()->SetTitleFont(42);
   Graph_Graph649->GetZaxis()->SetNdivisions(506);
   Graph_Graph649->GetZaxis()->SetLabelFont(42);
   Graph_Graph649->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph649->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph649->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph649);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx650[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy650[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx650,Graph_fy650);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph650 = new TH1F("Graph_Graph650","Graph",100,0.852,0.948);
   Graph_Graph650->SetMinimum(0.597);
   Graph_Graph650->SetMaximum(2.673);
   Graph_Graph650->SetDirectory(0);
   Graph_Graph650->SetStats(0);
   Graph_Graph650->SetLineWidth(2);
   Graph_Graph650->GetXaxis()->SetNdivisions(506);
   Graph_Graph650->GetXaxis()->SetLabelFont(42);
   Graph_Graph650->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph650->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph650->GetXaxis()->SetTitleFont(42);
   Graph_Graph650->GetYaxis()->SetNdivisions(506);
   Graph_Graph650->GetYaxis()->SetLabelFont(42);
   Graph_Graph650->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph650->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph650->GetYaxis()->SetTitleFont(42);
   Graph_Graph650->GetZaxis()->SetNdivisions(506);
   Graph_Graph650->GetZaxis()->SetLabelFont(42);
   Graph_Graph650->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph650->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph650->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph650);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx651[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy651[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx651,Graph_fy651);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph651 = new TH1F("Graph_Graph651","Graph",100,0.934,1.006);
   Graph_Graph651->SetMinimum(0.597);
   Graph_Graph651->SetMaximum(2.673);
   Graph_Graph651->SetDirectory(0);
   Graph_Graph651->SetStats(0);
   Graph_Graph651->SetLineWidth(2);
   Graph_Graph651->GetXaxis()->SetNdivisions(506);
   Graph_Graph651->GetXaxis()->SetLabelFont(42);
   Graph_Graph651->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph651->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph651->GetXaxis()->SetTitleFont(42);
   Graph_Graph651->GetYaxis()->SetNdivisions(506);
   Graph_Graph651->GetYaxis()->SetLabelFont(42);
   Graph_Graph651->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph651->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph651->GetYaxis()->SetTitleFont(42);
   Graph_Graph651->GetZaxis()->SetNdivisions(506);
   Graph_Graph651->GetZaxis()->SetLabelFont(42);
   Graph_Graph651->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph651->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph651->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph651);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.001221245);
   _reco_per_true->SetBinContent(5,0.008587723);
   _reco_per_true->SetBinContent(8,0.001229982);
   _reco_per_true->SetBinContent(9,0.007348097);
   _reco_per_true->SetBinContent(10,0.001220667);
   _reco_per_true->SetBinContent(12,0.02078014);
   _reco_per_true->SetBinContent(13,0.07938224);
   _reco_per_true->SetBinContent(14,0.024476);
   _reco_per_true->SetBinContent(15,0.00122767);
   _reco_per_true->SetBinContent(17,0.006138146);
   _reco_per_true->SetBinContent(18,0.001227155);
   _reco_per_true->SetBinContent(19,0.003586251);
   _reco_per_true->SetBinContent(20,0.06611749);
   _reco_per_true->SetBinContent(21,0.5428836);
   _reco_per_true->SetBinContent(22,0.09271486);
   _reco_per_true->SetBinContent(23,0.003681047);
   _reco_per_true->SetBinContent(24,0.00124422);
   _reco_per_true->SetBinContent(27,0.008580073);
   _reco_per_true->SetBinContent(28,0.1185718);
   _reco_per_true->SetBinContent(29,0.00978159);
   _reco_per_true->SetBinError(1,0.001221245);
   _reco_per_true->SetBinError(5,0.003245864);
   _reco_per_true->SetBinError(8,0.001229982);
   _reco_per_true->SetBinError(9,0.002999859);
   _reco_per_true->SetBinError(10,0.001220667);
   _reco_per_true->SetBinError(12,0.005040114);
   _reco_per_true->SetBinError(13,0.009847593);
   _reco_per_true->SetBinError(14,0.00547303);
   _reco_per_true->SetBinError(15,0.00122767);
   _reco_per_true->SetBinError(17,0.002745076);
   _reco_per_true->SetBinError(18,0.001227155);
   _reco_per_true->SetBinError(19,0.002071703);
   _reco_per_true->SetBinError(20,0.008997953);
   _reco_per_true->SetBinError(21,0.02576625);
   _reco_per_true->SetBinError(22,0.01063799);
   _reco_per_true->SetBinError(23,0.002125257);
   _reco_per_true->SetBinError(24,0.00124422);
   _reco_per_true->SetBinError(27,0.003242977);
   _reco_per_true->SetBinError(28,0.01204049);
   _reco_per_true->SetBinError(29,0.003458344);
   _reco_per_true->SetEntries(818);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.002128955);
   _reco_per_true->SetContourLevel(2,0.004257911);
   _reco_per_true->SetContourLevel(3,0.006386866);
   _reco_per_true->SetContourLevel(4,0.008515822);
   _reco_per_true->SetContourLevel(5,0.01064478);
   _reco_per_true->SetContourLevel(6,0.01277373);
   _reco_per_true->SetContourLevel(7,0.01490269);
   _reco_per_true->SetContourLevel(8,0.01703164);
   _reco_per_true->SetContourLevel(9,0.0191606);
   _reco_per_true->SetContourLevel(10,0.02128955);
   _reco_per_true->SetContourLevel(11,0.02341851);
   _reco_per_true->SetContourLevel(12,0.02554747);
   _reco_per_true->SetContourLevel(13,0.02767642);
   _reco_per_true->SetContourLevel(14,0.02980538);
   _reco_per_true->SetContourLevel(15,0.03193433);
   _reco_per_true->SetContourLevel(16,0.03406329);
   _reco_per_true->SetContourLevel(17,0.03619224);
   _reco_per_true->SetContourLevel(18,0.0383212);
   _reco_per_true->SetContourLevel(19,0.04045015);
   _reco_per_true->SetContourLevel(20,0.04257911);
   _reco_per_true->SetContourLevel(21,0.04470807);
   _reco_per_true->SetContourLevel(22,0.04683702);
   _reco_per_true->SetContourLevel(23,0.04896598);
   _reco_per_true->SetContourLevel(24,0.05109493);
   _reco_per_true->SetContourLevel(25,0.05322389);
   _reco_per_true->SetContourLevel(26,0.05535284);
   _reco_per_true->SetContourLevel(27,0.0574818);
   _reco_per_true->SetContourLevel(28,0.05961075);
   _reco_per_true->SetContourLevel(29,0.06173971);
   _reco_per_true->SetContourLevel(30,0.06386866);
   _reco_per_true->SetContourLevel(31,0.06599762);
   _reco_per_true->SetContourLevel(32,0.06812658);
   _reco_per_true->SetContourLevel(33,0.07025553);
   _reco_per_true->SetContourLevel(34,0.07238449);
   _reco_per_true->SetContourLevel(35,0.07451344);
   _reco_per_true->SetContourLevel(36,0.0766424);
   _reco_per_true->SetContourLevel(37,0.07877135);
   _reco_per_true->SetContourLevel(38,0.08090031);
   _reco_per_true->SetContourLevel(39,0.08302926);
   _reco_per_true->SetContourLevel(40,0.08515822);
   _reco_per_true->SetContourLevel(41,0.08728717);
   _reco_per_true->SetContourLevel(42,0.08941613);
   _reco_per_true->SetContourLevel(43,0.09154509);
   _reco_per_true->SetContourLevel(44,0.09367404);
   _reco_per_true->SetContourLevel(45,0.095803);
   _reco_per_true->SetContourLevel(46,0.09793195);
   _reco_per_true->SetContourLevel(47,0.1000609);
   _reco_per_true->SetContourLevel(48,0.1021899);
   _reco_per_true->SetContourLevel(49,0.1043188);
   _reco_per_true->SetContourLevel(50,0.1064478);
   _reco_per_true->SetContourLevel(51,0.1085767);
   _reco_per_true->SetContourLevel(52,0.1107057);
   _reco_per_true->SetContourLevel(53,0.1128346);
   _reco_per_true->SetContourLevel(54,0.1149636);
   _reco_per_true->SetContourLevel(55,0.1170926);
   _reco_per_true->SetContourLevel(56,0.1192215);
   _reco_per_true->SetContourLevel(57,0.1213505);
   _reco_per_true->SetContourLevel(58,0.1234794);
   _reco_per_true->SetContourLevel(59,0.1256084);
   _reco_per_true->SetContourLevel(60,0.1277373);
   _reco_per_true->SetContourLevel(61,0.1298663);
   _reco_per_true->SetContourLevel(62,0.1319952);
   _reco_per_true->SetContourLevel(63,0.1341242);
   _reco_per_true->SetContourLevel(64,0.1362532);
   _reco_per_true->SetContourLevel(65,0.1383821);
   _reco_per_true->SetContourLevel(66,0.1405111);
   _reco_per_true->SetContourLevel(67,0.14264);
   _reco_per_true->SetContourLevel(68,0.144769);
   _reco_per_true->SetContourLevel(69,0.1468979);
   _reco_per_true->SetContourLevel(70,0.1490269);
   _reco_per_true->SetContourLevel(71,0.1511558);
   _reco_per_true->SetContourLevel(72,0.1532848);
   _reco_per_true->SetContourLevel(73,0.1554138);
   _reco_per_true->SetContourLevel(74,0.1575427);
   _reco_per_true->SetContourLevel(75,0.1596717);
   _reco_per_true->SetContourLevel(76,0.1618006);
   _reco_per_true->SetContourLevel(77,0.1639296);
   _reco_per_true->SetContourLevel(78,0.1660585);
   _reco_per_true->SetContourLevel(79,0.1681875);
   _reco_per_true->SetContourLevel(80,0.1703164);
   _reco_per_true->SetContourLevel(81,0.1724454);
   _reco_per_true->SetContourLevel(82,0.1745743);
   _reco_per_true->SetContourLevel(83,0.1767033);
   _reco_per_true->SetContourLevel(84,0.1788323);
   _reco_per_true->SetContourLevel(85,0.1809612);
   _reco_per_true->SetContourLevel(86,0.1830902);
   _reco_per_true->SetContourLevel(87,0.1852191);
   _reco_per_true->SetContourLevel(88,0.1873481);
   _reco_per_true->SetContourLevel(89,0.189477);
   _reco_per_true->SetContourLevel(90,0.191606);
   _reco_per_true->SetContourLevel(91,0.1937349);
   _reco_per_true->SetContourLevel(92,0.1958639);
   _reco_per_true->SetContourLevel(93,0.1979929);
   _reco_per_true->SetContourLevel(94,0.2001218);
   _reco_per_true->SetContourLevel(95,0.2022508);
   _reco_per_true->SetContourLevel(96,0.2043797);
   _reco_per_true->SetContourLevel(97,0.2065087);
   _reco_per_true->SetContourLevel(98,0.2086376);
   _reco_per_true->SetContourLevel(99,0.2107666);
   _reco_per_true->SetContourLevel(100,0.2128955);
   _reco_per_true->SetContourLevel(101,0.2150245);
   _reco_per_true->SetContourLevel(102,0.2171535);
   _reco_per_true->SetContourLevel(103,0.2192824);
   _reco_per_true->SetContourLevel(104,0.2214114);
   _reco_per_true->SetContourLevel(105,0.2235403);
   _reco_per_true->SetContourLevel(106,0.2256693);
   _reco_per_true->SetContourLevel(107,0.2277982);
   _reco_per_true->SetContourLevel(108,0.2299272);
   _reco_per_true->SetContourLevel(109,0.2320561);
   _reco_per_true->SetContourLevel(110,0.2341851);
   _reco_per_true->SetContourLevel(111,0.2363141);
   _reco_per_true->SetContourLevel(112,0.238443);
   _reco_per_true->SetContourLevel(113,0.240572);
   _reco_per_true->SetContourLevel(114,0.2427009);
   _reco_per_true->SetContourLevel(115,0.2448299);
   _reco_per_true->SetContourLevel(116,0.2469588);
   _reco_per_true->SetContourLevel(117,0.2490878);
   _reco_per_true->SetContourLevel(118,0.2512167);
   _reco_per_true->SetContourLevel(119,0.2533457);
   _reco_per_true->SetContourLevel(120,0.2554747);
   _reco_per_true->SetContourLevel(121,0.2576036);
   _reco_per_true->SetContourLevel(122,0.2597326);
   _reco_per_true->SetContourLevel(123,0.2618615);
   _reco_per_true->SetContourLevel(124,0.2639905);
   _reco_per_true->SetContourLevel(125,0.2661194);
   _reco_per_true->SetContourLevel(126,0.2682484);
   _reco_per_true->SetContourLevel(127,0.2703773);
   _reco_per_true->SetContourLevel(128,0.2725063);
   _reco_per_true->SetContourLevel(129,0.2746353);
   _reco_per_true->SetContourLevel(130,0.2767642);
   _reco_per_true->SetContourLevel(131,0.2788932);
   _reco_per_true->SetContourLevel(132,0.2810221);
   _reco_per_true->SetContourLevel(133,0.2831511);
   _reco_per_true->SetContourLevel(134,0.28528);
   _reco_per_true->SetContourLevel(135,0.287409);
   _reco_per_true->SetContourLevel(136,0.2895379);
   _reco_per_true->SetContourLevel(137,0.2916669);
   _reco_per_true->SetContourLevel(138,0.2937959);
   _reco_per_true->SetContourLevel(139,0.2959248);
   _reco_per_true->SetContourLevel(140,0.2980538);
   _reco_per_true->SetContourLevel(141,0.3001827);
   _reco_per_true->SetContourLevel(142,0.3023117);
   _reco_per_true->SetContourLevel(143,0.3044406);
   _reco_per_true->SetContourLevel(144,0.3065696);
   _reco_per_true->SetContourLevel(145,0.3086985);
   _reco_per_true->SetContourLevel(146,0.3108275);
   _reco_per_true->SetContourLevel(147,0.3129565);
   _reco_per_true->SetContourLevel(148,0.3150854);
   _reco_per_true->SetContourLevel(149,0.3172144);
   _reco_per_true->SetContourLevel(150,0.3193433);
   _reco_per_true->SetContourLevel(151,0.3214723);
   _reco_per_true->SetContourLevel(152,0.3236012);
   _reco_per_true->SetContourLevel(153,0.3257302);
   _reco_per_true->SetContourLevel(154,0.3278591);
   _reco_per_true->SetContourLevel(155,0.3299881);
   _reco_per_true->SetContourLevel(156,0.3321171);
   _reco_per_true->SetContourLevel(157,0.334246);
   _reco_per_true->SetContourLevel(158,0.336375);
   _reco_per_true->SetContourLevel(159,0.3385039);
   _reco_per_true->SetContourLevel(160,0.3406329);
   _reco_per_true->SetContourLevel(161,0.3427618);
   _reco_per_true->SetContourLevel(162,0.3448908);
   _reco_per_true->SetContourLevel(163,0.3470197);
   _reco_per_true->SetContourLevel(164,0.3491487);
   _reco_per_true->SetContourLevel(165,0.3512777);
   _reco_per_true->SetContourLevel(166,0.3534066);
   _reco_per_true->SetContourLevel(167,0.3555356);
   _reco_per_true->SetContourLevel(168,0.3576645);
   _reco_per_true->SetContourLevel(169,0.3597935);
   _reco_per_true->SetContourLevel(170,0.3619224);
   _reco_per_true->SetContourLevel(171,0.3640514);
   _reco_per_true->SetContourLevel(172,0.3661803);
   _reco_per_true->SetContourLevel(173,0.3683093);
   _reco_per_true->SetContourLevel(174,0.3704383);
   _reco_per_true->SetContourLevel(175,0.3725672);
   _reco_per_true->SetContourLevel(176,0.3746962);
   _reco_per_true->SetContourLevel(177,0.3768251);
   _reco_per_true->SetContourLevel(178,0.3789541);
   _reco_per_true->SetContourLevel(179,0.381083);
   _reco_per_true->SetContourLevel(180,0.383212);
   _reco_per_true->SetContourLevel(181,0.3853409);
   _reco_per_true->SetContourLevel(182,0.3874699);
   _reco_per_true->SetContourLevel(183,0.3895989);
   _reco_per_true->SetContourLevel(184,0.3917278);
   _reco_per_true->SetContourLevel(185,0.3938568);
   _reco_per_true->SetContourLevel(186,0.3959857);
   _reco_per_true->SetContourLevel(187,0.3981147);
   _reco_per_true->SetContourLevel(188,0.4002436);
   _reco_per_true->SetContourLevel(189,0.4023726);
   _reco_per_true->SetContourLevel(190,0.4045015);
   _reco_per_true->SetContourLevel(191,0.4066305);
   _reco_per_true->SetContourLevel(192,0.4087595);
   _reco_per_true->SetContourLevel(193,0.4108884);
   _reco_per_true->SetContourLevel(194,0.4130174);
   _reco_per_true->SetContourLevel(195,0.4151463);
   _reco_per_true->SetContourLevel(196,0.4172753);
   _reco_per_true->SetContourLevel(197,0.4194042);
   _reco_per_true->SetContourLevel(198,0.4215332);
   _reco_per_true->SetContourLevel(199,0.4236621);
   _reco_per_true->SetContourLevel(200,0.4257911);
   _reco_per_true->SetContourLevel(201,0.4279201);
   _reco_per_true->SetContourLevel(202,0.430049);
   _reco_per_true->SetContourLevel(203,0.432178);
   _reco_per_true->SetContourLevel(204,0.4343069);
   _reco_per_true->SetContourLevel(205,0.4364359);
   _reco_per_true->SetContourLevel(206,0.4385648);
   _reco_per_true->SetContourLevel(207,0.4406938);
   _reco_per_true->SetContourLevel(208,0.4428227);
   _reco_per_true->SetContourLevel(209,0.4449517);
   _reco_per_true->SetContourLevel(210,0.4470807);
   _reco_per_true->SetContourLevel(211,0.4492096);
   _reco_per_true->SetContourLevel(212,0.4513386);
   _reco_per_true->SetContourLevel(213,0.4534675);
   _reco_per_true->SetContourLevel(214,0.4555965);
   _reco_per_true->SetContourLevel(215,0.4577254);
   _reco_per_true->SetContourLevel(216,0.4598544);
   _reco_per_true->SetContourLevel(217,0.4619833);
   _reco_per_true->SetContourLevel(218,0.4641123);
   _reco_per_true->SetContourLevel(219,0.4662413);
   _reco_per_true->SetContourLevel(220,0.4683702);
   _reco_per_true->SetContourLevel(221,0.4704992);
   _reco_per_true->SetContourLevel(222,0.4726281);
   _reco_per_true->SetContourLevel(223,0.4747571);
   _reco_per_true->SetContourLevel(224,0.476886);
   _reco_per_true->SetContourLevel(225,0.479015);
   _reco_per_true->SetContourLevel(226,0.4811439);
   _reco_per_true->SetContourLevel(227,0.4832729);
   _reco_per_true->SetContourLevel(228,0.4854019);
   _reco_per_true->SetContourLevel(229,0.4875308);
   _reco_per_true->SetContourLevel(230,0.4896598);
   _reco_per_true->SetContourLevel(231,0.4917887);
   _reco_per_true->SetContourLevel(232,0.4939177);
   _reco_per_true->SetContourLevel(233,0.4960466);
   _reco_per_true->SetContourLevel(234,0.4981756);
   _reco_per_true->SetContourLevel(235,0.5003045);
   _reco_per_true->SetContourLevel(236,0.5024335);
   _reco_per_true->SetContourLevel(237,0.5045625);
   _reco_per_true->SetContourLevel(238,0.5066914);
   _reco_per_true->SetContourLevel(239,0.5088204);
   _reco_per_true->SetContourLevel(240,0.5109493);
   _reco_per_true->SetContourLevel(241,0.5130783);
   _reco_per_true->SetContourLevel(242,0.5152072);
   _reco_per_true->SetContourLevel(243,0.5173362);
   _reco_per_true->SetContourLevel(244,0.5194651);
   _reco_per_true->SetContourLevel(245,0.5215941);
   _reco_per_true->SetContourLevel(246,0.523723);
   _reco_per_true->SetContourLevel(247,0.525852);
   _reco_per_true->SetContourLevel(248,0.527981);
   _reco_per_true->SetContourLevel(249,0.5301099);
   _reco_per_true->SetContourLevel(250,0.5322389);
   _reco_per_true->SetContourLevel(251,0.5343678);
   _reco_per_true->SetContourLevel(252,0.5364968);
   _reco_per_true->SetContourLevel(253,0.5386257);
   _reco_per_true->SetContourLevel(254,0.5407547);
   
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
   TText *AText = pt->AddText("True Bin 20");
   pt->Draw();
   c1_n21->Modified();
   c1_n21->cd();
   c1_n21->SetSelected(c1_n21);
}

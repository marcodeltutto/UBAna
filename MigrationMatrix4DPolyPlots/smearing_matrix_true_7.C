void smearing_matrix_true_7()
{
//=========Macro generated from canvas: c1_n8/c1_n8
//=========  (Sat Sep 22 12:03:54 2018) by ROOT version6.06/06
   TCanvas *c1_n8 = new TCanvas("c1_n8", "c1_n8",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n8->SetHighLightColor(2);
   c1_n8->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n8->SetFillColor(10);
   c1_n8->SetBorderMode(0);
   c1_n8->SetBorderSize(2);
   c1_n8->SetFrameLineWidth(2);
   c1_n8->SetFrameBorderMode(0);
   c1_n8->SetFrameLineWidth(2);
   c1_n8->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 7", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx218[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy218[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx218,Graph_fy218);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#002196");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph218 = new TH1F("Graph_Graph218","Graph",100,-1.1,0);
   Graph_Graph218->SetMinimum(0);
   Graph_Graph218->SetMaximum(0.33);
   Graph_Graph218->SetDirectory(0);
   Graph_Graph218->SetStats(0);
   Graph_Graph218->SetLineWidth(2);
   Graph_Graph218->GetXaxis()->SetNdivisions(506);
   Graph_Graph218->GetXaxis()->SetLabelFont(42);
   Graph_Graph218->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph218->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph218->GetXaxis()->SetTitleFont(42);
   Graph_Graph218->GetYaxis()->SetNdivisions(506);
   Graph_Graph218->GetYaxis()->SetLabelFont(42);
   Graph_Graph218->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph218->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph218->GetYaxis()->SetTitleFont(42);
   Graph_Graph218->GetZaxis()->SetNdivisions(506);
   Graph_Graph218->GetZaxis()->SetLabelFont(42);
   Graph_Graph218->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph218->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph218->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph218);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx219[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy219[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx219,Graph_fy219);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0043aa");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph219 = new TH1F("Graph_Graph219","Graph",100,0,0.297);
   Graph_Graph219->SetMinimum(0);
   Graph_Graph219->SetMaximum(0.33);
   Graph_Graph219->SetDirectory(0);
   Graph_Graph219->SetStats(0);
   Graph_Graph219->SetLineWidth(2);
   Graph_Graph219->GetXaxis()->SetNdivisions(506);
   Graph_Graph219->GetXaxis()->SetLabelFont(42);
   Graph_Graph219->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph219->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph219->GetXaxis()->SetTitleFont(42);
   Graph_Graph219->GetYaxis()->SetNdivisions(506);
   Graph_Graph219->GetYaxis()->SetLabelFont(42);
   Graph_Graph219->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph219->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph219->GetYaxis()->SetTitleFont(42);
   Graph_Graph219->GetZaxis()->SetNdivisions(506);
   Graph_Graph219->GetZaxis()->SetLabelFont(42);
   Graph_Graph219->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph219->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph219->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph219);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx220[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy220[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx220,Graph_fy220);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph220 = new TH1F("Graph_Graph220","Graph",100,0.252,0.468);
   Graph_Graph220->SetMinimum(0);
   Graph_Graph220->SetMaximum(0.33);
   Graph_Graph220->SetDirectory(0);
   Graph_Graph220->SetStats(0);
   Graph_Graph220->SetLineWidth(2);
   Graph_Graph220->GetXaxis()->SetNdivisions(506);
   Graph_Graph220->GetXaxis()->SetLabelFont(42);
   Graph_Graph220->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph220->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph220->GetXaxis()->SetTitleFont(42);
   Graph_Graph220->GetYaxis()->SetNdivisions(506);
   Graph_Graph220->GetYaxis()->SetLabelFont(42);
   Graph_Graph220->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph220->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph220->GetYaxis()->SetTitleFont(42);
   Graph_Graph220->GetZaxis()->SetNdivisions(506);
   Graph_Graph220->GetZaxis()->SetLabelFont(42);
   Graph_Graph220->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph220->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph220->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph220);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx221[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy221[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx221,Graph_fy221);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph221 = new TH1F("Graph_Graph221","Graph",100,0.433,0.637);
   Graph_Graph221->SetMinimum(0);
   Graph_Graph221->SetMaximum(0.33);
   Graph_Graph221->SetDirectory(0);
   Graph_Graph221->SetStats(0);
   Graph_Graph221->SetLineWidth(2);
   Graph_Graph221->GetXaxis()->SetNdivisions(506);
   Graph_Graph221->GetXaxis()->SetLabelFont(42);
   Graph_Graph221->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph221->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph221->GetXaxis()->SetTitleFont(42);
   Graph_Graph221->GetYaxis()->SetNdivisions(506);
   Graph_Graph221->GetYaxis()->SetLabelFont(42);
   Graph_Graph221->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph221->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph221->GetYaxis()->SetTitleFont(42);
   Graph_Graph221->GetZaxis()->SetNdivisions(506);
   Graph_Graph221->GetZaxis()->SetLabelFont(42);
   Graph_Graph221->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph221->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph221->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph221);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx222[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy222[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx222,Graph_fy222);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002196");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph222 = new TH1F("Graph_Graph222","Graph",100,0.606,0.774);
   Graph_Graph222->SetMinimum(0);
   Graph_Graph222->SetMaximum(0.33);
   Graph_Graph222->SetDirectory(0);
   Graph_Graph222->SetStats(0);
   Graph_Graph222->SetLineWidth(2);
   Graph_Graph222->GetXaxis()->SetNdivisions(506);
   Graph_Graph222->GetXaxis()->SetLabelFont(42);
   Graph_Graph222->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph222->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph222->GetXaxis()->SetTitleFont(42);
   Graph_Graph222->GetYaxis()->SetNdivisions(506);
   Graph_Graph222->GetYaxis()->SetLabelFont(42);
   Graph_Graph222->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph222->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph222->GetYaxis()->SetTitleFont(42);
   Graph_Graph222->GetZaxis()->SetNdivisions(506);
   Graph_Graph222->GetZaxis()->SetLabelFont(42);
   Graph_Graph222->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph222->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph222->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph222);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx223[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy223[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx223,Graph_fy223);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0043aa");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph223 = new TH1F("Graph_Graph223","Graph",100,0.75,0.87);
   Graph_Graph223->SetMinimum(0);
   Graph_Graph223->SetMaximum(0.33);
   Graph_Graph223->SetDirectory(0);
   Graph_Graph223->SetStats(0);
   Graph_Graph223->SetLineWidth(2);
   Graph_Graph223->GetXaxis()->SetNdivisions(506);
   Graph_Graph223->GetXaxis()->SetLabelFont(42);
   Graph_Graph223->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph223->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph223->GetXaxis()->SetTitleFont(42);
   Graph_Graph223->GetYaxis()->SetNdivisions(506);
   Graph_Graph223->GetYaxis()->SetLabelFont(42);
   Graph_Graph223->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph223->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph223->GetYaxis()->SetTitleFont(42);
   Graph_Graph223->GetZaxis()->SetNdivisions(506);
   Graph_Graph223->GetZaxis()->SetLabelFont(42);
   Graph_Graph223->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph223->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph223->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph223);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx224[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy224[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx224,Graph_fy224);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00ccfd");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph224 = new TH1F("Graph_Graph224","Graph",100,0.852,0.948);
   Graph_Graph224->SetMinimum(0);
   Graph_Graph224->SetMaximum(0.33);
   Graph_Graph224->SetDirectory(0);
   Graph_Graph224->SetStats(0);
   Graph_Graph224->SetLineWidth(2);
   Graph_Graph224->GetXaxis()->SetNdivisions(506);
   Graph_Graph224->GetXaxis()->SetLabelFont(42);
   Graph_Graph224->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph224->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph224->GetXaxis()->SetTitleFont(42);
   Graph_Graph224->GetYaxis()->SetNdivisions(506);
   Graph_Graph224->GetYaxis()->SetLabelFont(42);
   Graph_Graph224->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph224->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph224->GetYaxis()->SetTitleFont(42);
   Graph_Graph224->GetZaxis()->SetNdivisions(506);
   Graph_Graph224->GetZaxis()->SetLabelFont(42);
   Graph_Graph224->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph224->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph224->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph224);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx225[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy225[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx225,Graph_fy225);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph225 = new TH1F("Graph_Graph225","Graph",100,0.934,1.006);
   Graph_Graph225->SetMinimum(0);
   Graph_Graph225->SetMaximum(0.33);
   Graph_Graph225->SetDirectory(0);
   Graph_Graph225->SetStats(0);
   Graph_Graph225->SetLineWidth(2);
   Graph_Graph225->GetXaxis()->SetNdivisions(506);
   Graph_Graph225->GetXaxis()->SetLabelFont(42);
   Graph_Graph225->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph225->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph225->GetXaxis()->SetTitleFont(42);
   Graph_Graph225->GetYaxis()->SetNdivisions(506);
   Graph_Graph225->GetYaxis()->SetLabelFont(42);
   Graph_Graph225->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph225->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph225->GetYaxis()->SetTitleFont(42);
   Graph_Graph225->GetZaxis()->SetNdivisions(506);
   Graph_Graph225->GetZaxis()->SetLabelFont(42);
   Graph_Graph225->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph225->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph225->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph225);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx226[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy226[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx226,Graph_fy226);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0043aa");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph226 = new TH1F("Graph_Graph226","Graph",100,-1.1,0);
   Graph_Graph226->SetMinimum(0.285);
   Graph_Graph226->SetMaximum(0.465);
   Graph_Graph226->SetDirectory(0);
   Graph_Graph226->SetStats(0);
   Graph_Graph226->SetLineWidth(2);
   Graph_Graph226->GetXaxis()->SetNdivisions(506);
   Graph_Graph226->GetXaxis()->SetLabelFont(42);
   Graph_Graph226->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph226->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph226->GetXaxis()->SetTitleFont(42);
   Graph_Graph226->GetYaxis()->SetNdivisions(506);
   Graph_Graph226->GetYaxis()->SetLabelFont(42);
   Graph_Graph226->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph226->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph226->GetYaxis()->SetTitleFont(42);
   Graph_Graph226->GetZaxis()->SetNdivisions(506);
   Graph_Graph226->GetZaxis()->SetLabelFont(42);
   Graph_Graph226->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph226->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph226->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph226);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx227[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy227[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx227,Graph_fy227);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0064bf");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph227 = new TH1F("Graph_Graph227","Graph",100,0,0.297);
   Graph_Graph227->SetMinimum(0.285);
   Graph_Graph227->SetMaximum(0.465);
   Graph_Graph227->SetDirectory(0);
   Graph_Graph227->SetStats(0);
   Graph_Graph227->SetLineWidth(2);
   Graph_Graph227->GetXaxis()->SetNdivisions(506);
   Graph_Graph227->GetXaxis()->SetLabelFont(42);
   Graph_Graph227->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph227->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph227->GetXaxis()->SetTitleFont(42);
   Graph_Graph227->GetYaxis()->SetNdivisions(506);
   Graph_Graph227->GetYaxis()->SetLabelFont(42);
   Graph_Graph227->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph227->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph227->GetYaxis()->SetTitleFont(42);
   Graph_Graph227->GetZaxis()->SetNdivisions(506);
   Graph_Graph227->GetZaxis()->SetLabelFont(42);
   Graph_Graph227->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph227->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph227->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph227);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx228[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy228[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx228,Graph_fy228);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002196");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph228 = new TH1F("Graph_Graph228","Graph",100,0.252,0.468);
   Graph_Graph228->SetMinimum(0.285);
   Graph_Graph228->SetMaximum(0.465);
   Graph_Graph228->SetDirectory(0);
   Graph_Graph228->SetStats(0);
   Graph_Graph228->SetLineWidth(2);
   Graph_Graph228->GetXaxis()->SetNdivisions(506);
   Graph_Graph228->GetXaxis()->SetLabelFont(42);
   Graph_Graph228->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph228->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph228->GetXaxis()->SetTitleFont(42);
   Graph_Graph228->GetYaxis()->SetNdivisions(506);
   Graph_Graph228->GetYaxis()->SetLabelFont(42);
   Graph_Graph228->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph228->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph228->GetYaxis()->SetTitleFont(42);
   Graph_Graph228->GetZaxis()->SetNdivisions(506);
   Graph_Graph228->GetZaxis()->SetLabelFont(42);
   Graph_Graph228->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph228->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph228->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph228);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx229[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy229[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx229,Graph_fy229);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph229 = new TH1F("Graph_Graph229","Graph",100,0.433,0.637);
   Graph_Graph229->SetMinimum(0.285);
   Graph_Graph229->SetMaximum(0.465);
   Graph_Graph229->SetDirectory(0);
   Graph_Graph229->SetStats(0);
   Graph_Graph229->SetLineWidth(2);
   Graph_Graph229->GetXaxis()->SetNdivisions(506);
   Graph_Graph229->GetXaxis()->SetLabelFont(42);
   Graph_Graph229->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph229->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph229->GetXaxis()->SetTitleFont(42);
   Graph_Graph229->GetYaxis()->SetNdivisions(506);
   Graph_Graph229->GetYaxis()->SetLabelFont(42);
   Graph_Graph229->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph229->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph229->GetYaxis()->SetTitleFont(42);
   Graph_Graph229->GetZaxis()->SetNdivisions(506);
   Graph_Graph229->GetZaxis()->SetLabelFont(42);
   Graph_Graph229->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph229->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph229->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph229);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx230[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy230[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx230,Graph_fy230);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph230 = new TH1F("Graph_Graph230","Graph",100,0.606,0.774);
   Graph_Graph230->SetMinimum(0.285);
   Graph_Graph230->SetMaximum(0.465);
   Graph_Graph230->SetDirectory(0);
   Graph_Graph230->SetStats(0);
   Graph_Graph230->SetLineWidth(2);
   Graph_Graph230->GetXaxis()->SetNdivisions(506);
   Graph_Graph230->GetXaxis()->SetLabelFont(42);
   Graph_Graph230->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph230->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph230->GetXaxis()->SetTitleFont(42);
   Graph_Graph230->GetYaxis()->SetNdivisions(506);
   Graph_Graph230->GetYaxis()->SetLabelFont(42);
   Graph_Graph230->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph230->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph230->GetYaxis()->SetTitleFont(42);
   Graph_Graph230->GetZaxis()->SetNdivisions(506);
   Graph_Graph230->GetZaxis()->SetLabelFont(42);
   Graph_Graph230->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph230->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph230->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph230);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx231[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy231[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx231,Graph_fy231);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph231 = new TH1F("Graph_Graph231","Graph",100,0.75,0.87);
   Graph_Graph231->SetMinimum(0.285);
   Graph_Graph231->SetMaximum(0.465);
   Graph_Graph231->SetDirectory(0);
   Graph_Graph231->SetStats(0);
   Graph_Graph231->SetLineWidth(2);
   Graph_Graph231->GetXaxis()->SetNdivisions(506);
   Graph_Graph231->GetXaxis()->SetLabelFont(42);
   Graph_Graph231->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph231->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph231->GetXaxis()->SetTitleFont(42);
   Graph_Graph231->GetYaxis()->SetNdivisions(506);
   Graph_Graph231->GetYaxis()->SetLabelFont(42);
   Graph_Graph231->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph231->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph231->GetYaxis()->SetTitleFont(42);
   Graph_Graph231->GetZaxis()->SetNdivisions(506);
   Graph_Graph231->GetZaxis()->SetLabelFont(42);
   Graph_Graph231->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph231->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph231->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph231);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx232[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy232[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx232,Graph_fy232);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0043aa");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph232 = new TH1F("Graph_Graph232","Graph",100,0.852,0.948);
   Graph_Graph232->SetMinimum(0.285);
   Graph_Graph232->SetMaximum(0.465);
   Graph_Graph232->SetDirectory(0);
   Graph_Graph232->SetStats(0);
   Graph_Graph232->SetLineWidth(2);
   Graph_Graph232->GetXaxis()->SetNdivisions(506);
   Graph_Graph232->GetXaxis()->SetLabelFont(42);
   Graph_Graph232->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph232->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph232->GetXaxis()->SetTitleFont(42);
   Graph_Graph232->GetYaxis()->SetNdivisions(506);
   Graph_Graph232->GetYaxis()->SetLabelFont(42);
   Graph_Graph232->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph232->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph232->GetYaxis()->SetTitleFont(42);
   Graph_Graph232->GetZaxis()->SetNdivisions(506);
   Graph_Graph232->GetZaxis()->SetLabelFont(42);
   Graph_Graph232->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph232->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph232->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph232);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx233[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy233[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx233,Graph_fy233);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00a8e7");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph233 = new TH1F("Graph_Graph233","Graph",100,0.934,1.006);
   Graph_Graph233->SetMinimum(0.285);
   Graph_Graph233->SetMaximum(0.465);
   Graph_Graph233->SetDirectory(0);
   Graph_Graph233->SetStats(0);
   Graph_Graph233->SetLineWidth(2);
   Graph_Graph233->GetXaxis()->SetNdivisions(506);
   Graph_Graph233->GetXaxis()->SetLabelFont(42);
   Graph_Graph233->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph233->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph233->GetXaxis()->SetTitleFont(42);
   Graph_Graph233->GetYaxis()->SetNdivisions(506);
   Graph_Graph233->GetYaxis()->SetLabelFont(42);
   Graph_Graph233->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph233->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph233->GetYaxis()->SetTitleFont(42);
   Graph_Graph233->GetZaxis()->SetNdivisions(506);
   Graph_Graph233->GetZaxis()->SetLabelFont(42);
   Graph_Graph233->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph233->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph233->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph233);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx234[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy234[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx234,Graph_fy234);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph234 = new TH1F("Graph_Graph234","Graph",100,-1.1,0);
   Graph_Graph234->SetMinimum(0.245);
   Graph_Graph234->SetMaximum(2.705);
   Graph_Graph234->SetDirectory(0);
   Graph_Graph234->SetStats(0);
   Graph_Graph234->SetLineWidth(2);
   Graph_Graph234->GetXaxis()->SetNdivisions(506);
   Graph_Graph234->GetXaxis()->SetLabelFont(42);
   Graph_Graph234->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph234->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph234->GetXaxis()->SetTitleFont(42);
   Graph_Graph234->GetYaxis()->SetNdivisions(506);
   Graph_Graph234->GetYaxis()->SetLabelFont(42);
   Graph_Graph234->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph234->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph234->GetYaxis()->SetTitleFont(42);
   Graph_Graph234->GetZaxis()->SetNdivisions(506);
   Graph_Graph234->GetZaxis()->SetLabelFont(42);
   Graph_Graph234->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph234->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph234->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph234);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx235[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy235[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx235,Graph_fy235);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph235 = new TH1F("Graph_Graph235","Graph",100,0,0.297);
   Graph_Graph235->SetMinimum(0.418);
   Graph_Graph235->SetMaximum(0.802);
   Graph_Graph235->SetDirectory(0);
   Graph_Graph235->SetStats(0);
   Graph_Graph235->SetLineWidth(2);
   Graph_Graph235->GetXaxis()->SetNdivisions(506);
   Graph_Graph235->GetXaxis()->SetLabelFont(42);
   Graph_Graph235->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph235->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph235->GetXaxis()->SetTitleFont(42);
   Graph_Graph235->GetYaxis()->SetNdivisions(506);
   Graph_Graph235->GetYaxis()->SetLabelFont(42);
   Graph_Graph235->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph235->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph235->GetYaxis()->SetTitleFont(42);
   Graph_Graph235->GetZaxis()->SetNdivisions(506);
   Graph_Graph235->GetZaxis()->SetLabelFont(42);
   Graph_Graph235->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph235->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph235->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph235);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx236[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy236[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx236,Graph_fy236);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph236 = new TH1F("Graph_Graph236","Graph",100,0.252,0.468);
   Graph_Graph236->SetMinimum(0.418);
   Graph_Graph236->SetMaximum(0.802);
   Graph_Graph236->SetDirectory(0);
   Graph_Graph236->SetStats(0);
   Graph_Graph236->SetLineWidth(2);
   Graph_Graph236->GetXaxis()->SetNdivisions(506);
   Graph_Graph236->GetXaxis()->SetLabelFont(42);
   Graph_Graph236->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph236->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph236->GetXaxis()->SetTitleFont(42);
   Graph_Graph236->GetYaxis()->SetNdivisions(506);
   Graph_Graph236->GetYaxis()->SetLabelFont(42);
   Graph_Graph236->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph236->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph236->GetYaxis()->SetTitleFont(42);
   Graph_Graph236->GetZaxis()->SetNdivisions(506);
   Graph_Graph236->GetZaxis()->SetLabelFont(42);
   Graph_Graph236->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph236->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph236->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph236);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx237[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy237[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx237,Graph_fy237);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph237 = new TH1F("Graph_Graph237","Graph",100,0.433,0.637);
   Graph_Graph237->SetMinimum(0.418);
   Graph_Graph237->SetMaximum(0.802);
   Graph_Graph237->SetDirectory(0);
   Graph_Graph237->SetStats(0);
   Graph_Graph237->SetLineWidth(2);
   Graph_Graph237->GetXaxis()->SetNdivisions(506);
   Graph_Graph237->GetXaxis()->SetLabelFont(42);
   Graph_Graph237->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph237->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph237->GetXaxis()->SetTitleFont(42);
   Graph_Graph237->GetYaxis()->SetNdivisions(506);
   Graph_Graph237->GetYaxis()->SetLabelFont(42);
   Graph_Graph237->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph237->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph237->GetYaxis()->SetTitleFont(42);
   Graph_Graph237->GetZaxis()->SetNdivisions(506);
   Graph_Graph237->GetZaxis()->SetLabelFont(42);
   Graph_Graph237->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph237->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph237->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph237);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx238[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy238[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx238,Graph_fy238);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph238 = new TH1F("Graph_Graph238","Graph",100,0.606,0.774);
   Graph_Graph238->SetMinimum(0.418);
   Graph_Graph238->SetMaximum(0.802);
   Graph_Graph238->SetDirectory(0);
   Graph_Graph238->SetStats(0);
   Graph_Graph238->SetLineWidth(2);
   Graph_Graph238->GetXaxis()->SetNdivisions(506);
   Graph_Graph238->GetXaxis()->SetLabelFont(42);
   Graph_Graph238->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph238->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph238->GetXaxis()->SetTitleFont(42);
   Graph_Graph238->GetYaxis()->SetNdivisions(506);
   Graph_Graph238->GetYaxis()->SetLabelFont(42);
   Graph_Graph238->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph238->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph238->GetYaxis()->SetTitleFont(42);
   Graph_Graph238->GetZaxis()->SetNdivisions(506);
   Graph_Graph238->GetZaxis()->SetLabelFont(42);
   Graph_Graph238->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph238->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph238->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph238);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx239[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy239[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx239,Graph_fy239);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph239 = new TH1F("Graph_Graph239","Graph",100,0.75,0.87);
   Graph_Graph239->SetMinimum(0.418);
   Graph_Graph239->SetMaximum(0.802);
   Graph_Graph239->SetDirectory(0);
   Graph_Graph239->SetStats(0);
   Graph_Graph239->SetLineWidth(2);
   Graph_Graph239->GetXaxis()->SetNdivisions(506);
   Graph_Graph239->GetXaxis()->SetLabelFont(42);
   Graph_Graph239->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph239->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph239->GetXaxis()->SetTitleFont(42);
   Graph_Graph239->GetYaxis()->SetNdivisions(506);
   Graph_Graph239->GetYaxis()->SetLabelFont(42);
   Graph_Graph239->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph239->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph239->GetYaxis()->SetTitleFont(42);
   Graph_Graph239->GetZaxis()->SetNdivisions(506);
   Graph_Graph239->GetZaxis()->SetLabelFont(42);
   Graph_Graph239->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph239->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph239->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph239);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx240[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy240[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx240,Graph_fy240);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph240 = new TH1F("Graph_Graph240","Graph",100,0.852,0.948);
   Graph_Graph240->SetMinimum(0.418);
   Graph_Graph240->SetMaximum(0.802);
   Graph_Graph240->SetDirectory(0);
   Graph_Graph240->SetStats(0);
   Graph_Graph240->SetLineWidth(2);
   Graph_Graph240->GetXaxis()->SetNdivisions(506);
   Graph_Graph240->GetXaxis()->SetLabelFont(42);
   Graph_Graph240->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph240->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph240->GetXaxis()->SetTitleFont(42);
   Graph_Graph240->GetYaxis()->SetNdivisions(506);
   Graph_Graph240->GetYaxis()->SetLabelFont(42);
   Graph_Graph240->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph240->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph240->GetYaxis()->SetTitleFont(42);
   Graph_Graph240->GetZaxis()->SetNdivisions(506);
   Graph_Graph240->GetZaxis()->SetLabelFont(42);
   Graph_Graph240->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph240->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph240->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph240);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx241[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy241[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx241,Graph_fy241);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph241 = new TH1F("Graph_Graph241","Graph",100,0.934,1.006);
   Graph_Graph241->SetMinimum(0.418);
   Graph_Graph241->SetMaximum(0.802);
   Graph_Graph241->SetDirectory(0);
   Graph_Graph241->SetStats(0);
   Graph_Graph241->SetLineWidth(2);
   Graph_Graph241->GetXaxis()->SetNdivisions(506);
   Graph_Graph241->GetXaxis()->SetLabelFont(42);
   Graph_Graph241->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph241->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph241->GetXaxis()->SetTitleFont(42);
   Graph_Graph241->GetYaxis()->SetNdivisions(506);
   Graph_Graph241->GetYaxis()->SetLabelFont(42);
   Graph_Graph241->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph241->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph241->GetYaxis()->SetTitleFont(42);
   Graph_Graph241->GetZaxis()->SetNdivisions(506);
   Graph_Graph241->GetZaxis()->SetLabelFont(42);
   Graph_Graph241->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph241->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph241->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph241);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx242[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy242[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx242,Graph_fy242);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph242 = new TH1F("Graph_Graph242","Graph",100,0,0.297);
   Graph_Graph242->SetMinimum(0.597);
   Graph_Graph242->SetMaximum(2.673);
   Graph_Graph242->SetDirectory(0);
   Graph_Graph242->SetStats(0);
   Graph_Graph242->SetLineWidth(2);
   Graph_Graph242->GetXaxis()->SetNdivisions(506);
   Graph_Graph242->GetXaxis()->SetLabelFont(42);
   Graph_Graph242->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph242->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph242->GetXaxis()->SetTitleFont(42);
   Graph_Graph242->GetYaxis()->SetNdivisions(506);
   Graph_Graph242->GetYaxis()->SetLabelFont(42);
   Graph_Graph242->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph242->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph242->GetYaxis()->SetTitleFont(42);
   Graph_Graph242->GetZaxis()->SetNdivisions(506);
   Graph_Graph242->GetZaxis()->SetLabelFont(42);
   Graph_Graph242->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph242->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph242->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph242);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx243[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy243[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx243,Graph_fy243);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph243 = new TH1F("Graph_Graph243","Graph",100,0.252,0.468);
   Graph_Graph243->SetMinimum(0.597);
   Graph_Graph243->SetMaximum(2.673);
   Graph_Graph243->SetDirectory(0);
   Graph_Graph243->SetStats(0);
   Graph_Graph243->SetLineWidth(2);
   Graph_Graph243->GetXaxis()->SetNdivisions(506);
   Graph_Graph243->GetXaxis()->SetLabelFont(42);
   Graph_Graph243->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph243->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph243->GetXaxis()->SetTitleFont(42);
   Graph_Graph243->GetYaxis()->SetNdivisions(506);
   Graph_Graph243->GetYaxis()->SetLabelFont(42);
   Graph_Graph243->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph243->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph243->GetYaxis()->SetTitleFont(42);
   Graph_Graph243->GetZaxis()->SetNdivisions(506);
   Graph_Graph243->GetZaxis()->SetLabelFont(42);
   Graph_Graph243->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph243->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph243->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph243);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx244[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy244[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx244,Graph_fy244);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph244 = new TH1F("Graph_Graph244","Graph",100,0.433,0.637);
   Graph_Graph244->SetMinimum(0.597);
   Graph_Graph244->SetMaximum(2.673);
   Graph_Graph244->SetDirectory(0);
   Graph_Graph244->SetStats(0);
   Graph_Graph244->SetLineWidth(2);
   Graph_Graph244->GetXaxis()->SetNdivisions(506);
   Graph_Graph244->GetXaxis()->SetLabelFont(42);
   Graph_Graph244->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph244->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph244->GetXaxis()->SetTitleFont(42);
   Graph_Graph244->GetYaxis()->SetNdivisions(506);
   Graph_Graph244->GetYaxis()->SetLabelFont(42);
   Graph_Graph244->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph244->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph244->GetYaxis()->SetTitleFont(42);
   Graph_Graph244->GetZaxis()->SetNdivisions(506);
   Graph_Graph244->GetZaxis()->SetLabelFont(42);
   Graph_Graph244->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph244->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph244->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph244);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx245[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy245[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx245,Graph_fy245);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph245 = new TH1F("Graph_Graph245","Graph",100,0.606,0.774);
   Graph_Graph245->SetMinimum(0.597);
   Graph_Graph245->SetMaximum(2.673);
   Graph_Graph245->SetDirectory(0);
   Graph_Graph245->SetStats(0);
   Graph_Graph245->SetLineWidth(2);
   Graph_Graph245->GetXaxis()->SetNdivisions(506);
   Graph_Graph245->GetXaxis()->SetLabelFont(42);
   Graph_Graph245->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph245->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph245->GetXaxis()->SetTitleFont(42);
   Graph_Graph245->GetYaxis()->SetNdivisions(506);
   Graph_Graph245->GetYaxis()->SetLabelFont(42);
   Graph_Graph245->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph245->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph245->GetYaxis()->SetTitleFont(42);
   Graph_Graph245->GetZaxis()->SetNdivisions(506);
   Graph_Graph245->GetZaxis()->SetLabelFont(42);
   Graph_Graph245->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph245->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph245->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph245);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx246[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy246[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx246,Graph_fy246);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph246 = new TH1F("Graph_Graph246","Graph",100,0.75,0.87);
   Graph_Graph246->SetMinimum(0.597);
   Graph_Graph246->SetMaximum(2.673);
   Graph_Graph246->SetDirectory(0);
   Graph_Graph246->SetStats(0);
   Graph_Graph246->SetLineWidth(2);
   Graph_Graph246->GetXaxis()->SetNdivisions(506);
   Graph_Graph246->GetXaxis()->SetLabelFont(42);
   Graph_Graph246->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph246->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph246->GetXaxis()->SetTitleFont(42);
   Graph_Graph246->GetYaxis()->SetNdivisions(506);
   Graph_Graph246->GetYaxis()->SetLabelFont(42);
   Graph_Graph246->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph246->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph246->GetYaxis()->SetTitleFont(42);
   Graph_Graph246->GetZaxis()->SetNdivisions(506);
   Graph_Graph246->GetZaxis()->SetLabelFont(42);
   Graph_Graph246->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph246->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph246->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph246);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx247[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy247[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx247,Graph_fy247);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph247 = new TH1F("Graph_Graph247","Graph",100,0.852,0.948);
   Graph_Graph247->SetMinimum(0.597);
   Graph_Graph247->SetMaximum(2.673);
   Graph_Graph247->SetDirectory(0);
   Graph_Graph247->SetStats(0);
   Graph_Graph247->SetLineWidth(2);
   Graph_Graph247->GetXaxis()->SetNdivisions(506);
   Graph_Graph247->GetXaxis()->SetLabelFont(42);
   Graph_Graph247->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph247->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph247->GetXaxis()->SetTitleFont(42);
   Graph_Graph247->GetYaxis()->SetNdivisions(506);
   Graph_Graph247->GetYaxis()->SetLabelFont(42);
   Graph_Graph247->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph247->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph247->GetYaxis()->SetTitleFont(42);
   Graph_Graph247->GetZaxis()->SetNdivisions(506);
   Graph_Graph247->GetZaxis()->SetLabelFont(42);
   Graph_Graph247->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph247->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph247->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph247);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx248[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy248[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx248,Graph_fy248);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph248 = new TH1F("Graph_Graph248","Graph",100,0.934,1.006);
   Graph_Graph248->SetMinimum(0.597);
   Graph_Graph248->SetMaximum(2.673);
   Graph_Graph248->SetDirectory(0);
   Graph_Graph248->SetStats(0);
   Graph_Graph248->SetLineWidth(2);
   Graph_Graph248->GetXaxis()->SetNdivisions(506);
   Graph_Graph248->GetXaxis()->SetLabelFont(42);
   Graph_Graph248->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph248->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph248->GetXaxis()->SetTitleFont(42);
   Graph_Graph248->GetYaxis()->SetNdivisions(506);
   Graph_Graph248->GetYaxis()->SetLabelFont(42);
   Graph_Graph248->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph248->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph248->GetYaxis()->SetTitleFont(42);
   Graph_Graph248->GetZaxis()->SetNdivisions(506);
   Graph_Graph248->GetZaxis()->SetLabelFont(42);
   Graph_Graph248->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph248->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph248->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph248);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.02321156);
   _reco_per_true->SetBinContent(2,0.04667684);
   _reco_per_true->SetBinContent(5,0.02334632);
   _reco_per_true->SetBinContent(6,0.04636173);
   _reco_per_true->SetBinContent(7,0.1396178);
   _reco_per_true->SetBinContent(8,0.4188096);
   _reco_per_true->SetBinContent(9,0.04634228);
   _reco_per_true->SetBinContent(10,0.0697647);
   _reco_per_true->SetBinContent(11,0.02327977);
   _reco_per_true->SetBinContent(15,0.04642471);
   _reco_per_true->SetBinContent(16,0.1161647);
   _reco_per_true->SetBinError(1,0.02321156);
   _reco_per_true->SetBinError(2,0.0330056);
   _reco_per_true->SetBinError(5,0.02334632);
   _reco_per_true->SetBinError(6,0.03278277);
   _reco_per_true->SetBinError(7,0.05699897);
   _reco_per_true->SetBinError(8,0.09871475);
   _reco_per_true->SetBinError(9,0.03276899);
   _reco_per_true->SetBinError(10,0.0402787);
   _reco_per_true->SetBinError(11,0.02327977);
   _reco_per_true->SetBinError(15,0.03282723);
   _reco_per_true->SetBinError(16,0.05195084);
   _reco_per_true->SetEntries(43);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.001642391);
   _reco_per_true->SetContourLevel(2,0.003284781);
   _reco_per_true->SetContourLevel(3,0.004927172);
   _reco_per_true->SetContourLevel(4,0.006569563);
   _reco_per_true->SetContourLevel(5,0.008211953);
   _reco_per_true->SetContourLevel(6,0.009854344);
   _reco_per_true->SetContourLevel(7,0.01149673);
   _reco_per_true->SetContourLevel(8,0.01313913);
   _reco_per_true->SetContourLevel(9,0.01478152);
   _reco_per_true->SetContourLevel(10,0.01642391);
   _reco_per_true->SetContourLevel(11,0.0180663);
   _reco_per_true->SetContourLevel(12,0.01970869);
   _reco_per_true->SetContourLevel(13,0.02135108);
   _reco_per_true->SetContourLevel(14,0.02299347);
   _reco_per_true->SetContourLevel(15,0.02463586);
   _reco_per_true->SetContourLevel(16,0.02627825);
   _reco_per_true->SetContourLevel(17,0.02792064);
   _reco_per_true->SetContourLevel(18,0.02956303);
   _reco_per_true->SetContourLevel(19,0.03120542);
   _reco_per_true->SetContourLevel(20,0.03284781);
   _reco_per_true->SetContourLevel(21,0.0344902);
   _reco_per_true->SetContourLevel(22,0.03613259);
   _reco_per_true->SetContourLevel(23,0.03777498);
   _reco_per_true->SetContourLevel(24,0.03941738);
   _reco_per_true->SetContourLevel(25,0.04105977);
   _reco_per_true->SetContourLevel(26,0.04270216);
   _reco_per_true->SetContourLevel(27,0.04434455);
   _reco_per_true->SetContourLevel(28,0.04598694);
   _reco_per_true->SetContourLevel(29,0.04762933);
   _reco_per_true->SetContourLevel(30,0.04927172);
   _reco_per_true->SetContourLevel(31,0.05091411);
   _reco_per_true->SetContourLevel(32,0.0525565);
   _reco_per_true->SetContourLevel(33,0.05419889);
   _reco_per_true->SetContourLevel(34,0.05584128);
   _reco_per_true->SetContourLevel(35,0.05748367);
   _reco_per_true->SetContourLevel(36,0.05912606);
   _reco_per_true->SetContourLevel(37,0.06076845);
   _reco_per_true->SetContourLevel(38,0.06241084);
   _reco_per_true->SetContourLevel(39,0.06405323);
   _reco_per_true->SetContourLevel(40,0.06569563);
   _reco_per_true->SetContourLevel(41,0.06733802);
   _reco_per_true->SetContourLevel(42,0.06898041);
   _reco_per_true->SetContourLevel(43,0.0706228);
   _reco_per_true->SetContourLevel(44,0.07226519);
   _reco_per_true->SetContourLevel(45,0.07390758);
   _reco_per_true->SetContourLevel(46,0.07554997);
   _reco_per_true->SetContourLevel(47,0.07719236);
   _reco_per_true->SetContourLevel(48,0.07883475);
   _reco_per_true->SetContourLevel(49,0.08047714);
   _reco_per_true->SetContourLevel(50,0.08211953);
   _reco_per_true->SetContourLevel(51,0.08376192);
   _reco_per_true->SetContourLevel(52,0.08540431);
   _reco_per_true->SetContourLevel(53,0.0870467);
   _reco_per_true->SetContourLevel(54,0.08868909);
   _reco_per_true->SetContourLevel(55,0.09033148);
   _reco_per_true->SetContourLevel(56,0.09197388);
   _reco_per_true->SetContourLevel(57,0.09361627);
   _reco_per_true->SetContourLevel(58,0.09525866);
   _reco_per_true->SetContourLevel(59,0.09690105);
   _reco_per_true->SetContourLevel(60,0.09854344);
   _reco_per_true->SetContourLevel(61,0.1001858);
   _reco_per_true->SetContourLevel(62,0.1018282);
   _reco_per_true->SetContourLevel(63,0.1034706);
   _reco_per_true->SetContourLevel(64,0.105113);
   _reco_per_true->SetContourLevel(65,0.1067554);
   _reco_per_true->SetContourLevel(66,0.1083978);
   _reco_per_true->SetContourLevel(67,0.1100402);
   _reco_per_true->SetContourLevel(68,0.1116826);
   _reco_per_true->SetContourLevel(69,0.113325);
   _reco_per_true->SetContourLevel(70,0.1149673);
   _reco_per_true->SetContourLevel(71,0.1166097);
   _reco_per_true->SetContourLevel(72,0.1182521);
   _reco_per_true->SetContourLevel(73,0.1198945);
   _reco_per_true->SetContourLevel(74,0.1215369);
   _reco_per_true->SetContourLevel(75,0.1231793);
   _reco_per_true->SetContourLevel(76,0.1248217);
   _reco_per_true->SetContourLevel(77,0.1264641);
   _reco_per_true->SetContourLevel(78,0.1281065);
   _reco_per_true->SetContourLevel(79,0.1297489);
   _reco_per_true->SetContourLevel(80,0.1313913);
   _reco_per_true->SetContourLevel(81,0.1330336);
   _reco_per_true->SetContourLevel(82,0.134676);
   _reco_per_true->SetContourLevel(83,0.1363184);
   _reco_per_true->SetContourLevel(84,0.1379608);
   _reco_per_true->SetContourLevel(85,0.1396032);
   _reco_per_true->SetContourLevel(86,0.1412456);
   _reco_per_true->SetContourLevel(87,0.142888);
   _reco_per_true->SetContourLevel(88,0.1445304);
   _reco_per_true->SetContourLevel(89,0.1461728);
   _reco_per_true->SetContourLevel(90,0.1478152);
   _reco_per_true->SetContourLevel(91,0.1494575);
   _reco_per_true->SetContourLevel(92,0.1510999);
   _reco_per_true->SetContourLevel(93,0.1527423);
   _reco_per_true->SetContourLevel(94,0.1543847);
   _reco_per_true->SetContourLevel(95,0.1560271);
   _reco_per_true->SetContourLevel(96,0.1576695);
   _reco_per_true->SetContourLevel(97,0.1593119);
   _reco_per_true->SetContourLevel(98,0.1609543);
   _reco_per_true->SetContourLevel(99,0.1625967);
   _reco_per_true->SetContourLevel(100,0.1642391);
   _reco_per_true->SetContourLevel(101,0.1658815);
   _reco_per_true->SetContourLevel(102,0.1675238);
   _reco_per_true->SetContourLevel(103,0.1691662);
   _reco_per_true->SetContourLevel(104,0.1708086);
   _reco_per_true->SetContourLevel(105,0.172451);
   _reco_per_true->SetContourLevel(106,0.1740934);
   _reco_per_true->SetContourLevel(107,0.1757358);
   _reco_per_true->SetContourLevel(108,0.1773782);
   _reco_per_true->SetContourLevel(109,0.1790206);
   _reco_per_true->SetContourLevel(110,0.180663);
   _reco_per_true->SetContourLevel(111,0.1823054);
   _reco_per_true->SetContourLevel(112,0.1839478);
   _reco_per_true->SetContourLevel(113,0.1855901);
   _reco_per_true->SetContourLevel(114,0.1872325);
   _reco_per_true->SetContourLevel(115,0.1888749);
   _reco_per_true->SetContourLevel(116,0.1905173);
   _reco_per_true->SetContourLevel(117,0.1921597);
   _reco_per_true->SetContourLevel(118,0.1938021);
   _reco_per_true->SetContourLevel(119,0.1954445);
   _reco_per_true->SetContourLevel(120,0.1970869);
   _reco_per_true->SetContourLevel(121,0.1987293);
   _reco_per_true->SetContourLevel(122,0.2003717);
   _reco_per_true->SetContourLevel(123,0.202014);
   _reco_per_true->SetContourLevel(124,0.2036564);
   _reco_per_true->SetContourLevel(125,0.2052988);
   _reco_per_true->SetContourLevel(126,0.2069412);
   _reco_per_true->SetContourLevel(127,0.2085836);
   _reco_per_true->SetContourLevel(128,0.210226);
   _reco_per_true->SetContourLevel(129,0.2118684);
   _reco_per_true->SetContourLevel(130,0.2135108);
   _reco_per_true->SetContourLevel(131,0.2151532);
   _reco_per_true->SetContourLevel(132,0.2167956);
   _reco_per_true->SetContourLevel(133,0.218438);
   _reco_per_true->SetContourLevel(134,0.2200803);
   _reco_per_true->SetContourLevel(135,0.2217227);
   _reco_per_true->SetContourLevel(136,0.2233651);
   _reco_per_true->SetContourLevel(137,0.2250075);
   _reco_per_true->SetContourLevel(138,0.2266499);
   _reco_per_true->SetContourLevel(139,0.2282923);
   _reco_per_true->SetContourLevel(140,0.2299347);
   _reco_per_true->SetContourLevel(141,0.2315771);
   _reco_per_true->SetContourLevel(142,0.2332195);
   _reco_per_true->SetContourLevel(143,0.2348619);
   _reco_per_true->SetContourLevel(144,0.2365043);
   _reco_per_true->SetContourLevel(145,0.2381466);
   _reco_per_true->SetContourLevel(146,0.239789);
   _reco_per_true->SetContourLevel(147,0.2414314);
   _reco_per_true->SetContourLevel(148,0.2430738);
   _reco_per_true->SetContourLevel(149,0.2447162);
   _reco_per_true->SetContourLevel(150,0.2463586);
   _reco_per_true->SetContourLevel(151,0.248001);
   _reco_per_true->SetContourLevel(152,0.2496434);
   _reco_per_true->SetContourLevel(153,0.2512858);
   _reco_per_true->SetContourLevel(154,0.2529282);
   _reco_per_true->SetContourLevel(155,0.2545705);
   _reco_per_true->SetContourLevel(156,0.2562129);
   _reco_per_true->SetContourLevel(157,0.2578553);
   _reco_per_true->SetContourLevel(158,0.2594977);
   _reco_per_true->SetContourLevel(159,0.2611401);
   _reco_per_true->SetContourLevel(160,0.2627825);
   _reco_per_true->SetContourLevel(161,0.2644249);
   _reco_per_true->SetContourLevel(162,0.2660673);
   _reco_per_true->SetContourLevel(163,0.2677097);
   _reco_per_true->SetContourLevel(164,0.2693521);
   _reco_per_true->SetContourLevel(165,0.2709945);
   _reco_per_true->SetContourLevel(166,0.2726368);
   _reco_per_true->SetContourLevel(167,0.2742792);
   _reco_per_true->SetContourLevel(168,0.2759216);
   _reco_per_true->SetContourLevel(169,0.277564);
   _reco_per_true->SetContourLevel(170,0.2792064);
   _reco_per_true->SetContourLevel(171,0.2808488);
   _reco_per_true->SetContourLevel(172,0.2824912);
   _reco_per_true->SetContourLevel(173,0.2841336);
   _reco_per_true->SetContourLevel(174,0.285776);
   _reco_per_true->SetContourLevel(175,0.2874184);
   _reco_per_true->SetContourLevel(176,0.2890608);
   _reco_per_true->SetContourLevel(177,0.2907031);
   _reco_per_true->SetContourLevel(178,0.2923455);
   _reco_per_true->SetContourLevel(179,0.2939879);
   _reco_per_true->SetContourLevel(180,0.2956303);
   _reco_per_true->SetContourLevel(181,0.2972727);
   _reco_per_true->SetContourLevel(182,0.2989151);
   _reco_per_true->SetContourLevel(183,0.3005575);
   _reco_per_true->SetContourLevel(184,0.3021999);
   _reco_per_true->SetContourLevel(185,0.3038423);
   _reco_per_true->SetContourLevel(186,0.3054847);
   _reco_per_true->SetContourLevel(187,0.307127);
   _reco_per_true->SetContourLevel(188,0.3087694);
   _reco_per_true->SetContourLevel(189,0.3104118);
   _reco_per_true->SetContourLevel(190,0.3120542);
   _reco_per_true->SetContourLevel(191,0.3136966);
   _reco_per_true->SetContourLevel(192,0.315339);
   _reco_per_true->SetContourLevel(193,0.3169814);
   _reco_per_true->SetContourLevel(194,0.3186238);
   _reco_per_true->SetContourLevel(195,0.3202662);
   _reco_per_true->SetContourLevel(196,0.3219086);
   _reco_per_true->SetContourLevel(197,0.323551);
   _reco_per_true->SetContourLevel(198,0.3251933);
   _reco_per_true->SetContourLevel(199,0.3268357);
   _reco_per_true->SetContourLevel(200,0.3284781);
   _reco_per_true->SetContourLevel(201,0.3301205);
   _reco_per_true->SetContourLevel(202,0.3317629);
   _reco_per_true->SetContourLevel(203,0.3334053);
   _reco_per_true->SetContourLevel(204,0.3350477);
   _reco_per_true->SetContourLevel(205,0.3366901);
   _reco_per_true->SetContourLevel(206,0.3383325);
   _reco_per_true->SetContourLevel(207,0.3399749);
   _reco_per_true->SetContourLevel(208,0.3416173);
   _reco_per_true->SetContourLevel(209,0.3432596);
   _reco_per_true->SetContourLevel(210,0.344902);
   _reco_per_true->SetContourLevel(211,0.3465444);
   _reco_per_true->SetContourLevel(212,0.3481868);
   _reco_per_true->SetContourLevel(213,0.3498292);
   _reco_per_true->SetContourLevel(214,0.3514716);
   _reco_per_true->SetContourLevel(215,0.353114);
   _reco_per_true->SetContourLevel(216,0.3547564);
   _reco_per_true->SetContourLevel(217,0.3563988);
   _reco_per_true->SetContourLevel(218,0.3580412);
   _reco_per_true->SetContourLevel(219,0.3596835);
   _reco_per_true->SetContourLevel(220,0.3613259);
   _reco_per_true->SetContourLevel(221,0.3629683);
   _reco_per_true->SetContourLevel(222,0.3646107);
   _reco_per_true->SetContourLevel(223,0.3662531);
   _reco_per_true->SetContourLevel(224,0.3678955);
   _reco_per_true->SetContourLevel(225,0.3695379);
   _reco_per_true->SetContourLevel(226,0.3711803);
   _reco_per_true->SetContourLevel(227,0.3728227);
   _reco_per_true->SetContourLevel(228,0.3744651);
   _reco_per_true->SetContourLevel(229,0.3761075);
   _reco_per_true->SetContourLevel(230,0.3777498);
   _reco_per_true->SetContourLevel(231,0.3793922);
   _reco_per_true->SetContourLevel(232,0.3810346);
   _reco_per_true->SetContourLevel(233,0.382677);
   _reco_per_true->SetContourLevel(234,0.3843194);
   _reco_per_true->SetContourLevel(235,0.3859618);
   _reco_per_true->SetContourLevel(236,0.3876042);
   _reco_per_true->SetContourLevel(237,0.3892466);
   _reco_per_true->SetContourLevel(238,0.390889);
   _reco_per_true->SetContourLevel(239,0.3925314);
   _reco_per_true->SetContourLevel(240,0.3941738);
   _reco_per_true->SetContourLevel(241,0.3958161);
   _reco_per_true->SetContourLevel(242,0.3974585);
   _reco_per_true->SetContourLevel(243,0.3991009);
   _reco_per_true->SetContourLevel(244,0.4007433);
   _reco_per_true->SetContourLevel(245,0.4023857);
   _reco_per_true->SetContourLevel(246,0.4040281);
   _reco_per_true->SetContourLevel(247,0.4056705);
   _reco_per_true->SetContourLevel(248,0.4073129);
   _reco_per_true->SetContourLevel(249,0.4089553);
   _reco_per_true->SetContourLevel(250,0.4105977);
   _reco_per_true->SetContourLevel(251,0.41224);
   _reco_per_true->SetContourLevel(252,0.4138824);
   _reco_per_true->SetContourLevel(253,0.4155248);
   _reco_per_true->SetContourLevel(254,0.4171672);
   
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
   TText *AText = pt->AddText("True Bin 7");
   pt->Draw();
   c1_n8->Modified();
   c1_n8->cd();
   c1_n8->SetSelected(c1_n8);
}

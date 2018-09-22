void smearing_matrix_true_1()
{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Sat Sep 22 12:03:53 2018) by ROOT version6.06/06
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n2->SetHighLightColor(2);
   c1_n2->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n2->SetFillColor(10);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameLineWidth(2);
   c1_n2->SetFrameBorderMode(0);
   c1_n2->SetFrameLineWidth(2);
   c1_n2->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 1", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx32[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy32[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx32,Graph_fy32);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00a3e4");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph32 = new TH1F("Graph_Graph32","Graph",100,-1.1,0);
   Graph_Graph32->SetMinimum(0);
   Graph_Graph32->SetMaximum(0.33);
   Graph_Graph32->SetDirectory(0);
   Graph_Graph32->SetStats(0);
   Graph_Graph32->SetLineWidth(2);
   Graph_Graph32->GetXaxis()->SetNdivisions(506);
   Graph_Graph32->GetXaxis()->SetLabelFont(42);
   Graph_Graph32->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph32->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph32->GetXaxis()->SetTitleFont(42);
   Graph_Graph32->GetYaxis()->SetNdivisions(506);
   Graph_Graph32->GetYaxis()->SetLabelFont(42);
   Graph_Graph32->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph32->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph32->GetYaxis()->SetTitleFont(42);
   Graph_Graph32->GetZaxis()->SetNdivisions(506);
   Graph_Graph32->GetZaxis()->SetLabelFont(42);
   Graph_Graph32->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph32->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph32->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph32);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx33[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy33[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx33,Graph_fy33);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph33 = new TH1F("Graph_Graph33","Graph",100,0,0.297);
   Graph_Graph33->SetMinimum(0);
   Graph_Graph33->SetMaximum(0.33);
   Graph_Graph33->SetDirectory(0);
   Graph_Graph33->SetStats(0);
   Graph_Graph33->SetLineWidth(2);
   Graph_Graph33->GetXaxis()->SetNdivisions(506);
   Graph_Graph33->GetXaxis()->SetLabelFont(42);
   Graph_Graph33->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph33->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph33->GetXaxis()->SetTitleFont(42);
   Graph_Graph33->GetYaxis()->SetNdivisions(506);
   Graph_Graph33->GetYaxis()->SetLabelFont(42);
   Graph_Graph33->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph33->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph33->GetYaxis()->SetTitleFont(42);
   Graph_Graph33->GetZaxis()->SetNdivisions(506);
   Graph_Graph33->GetZaxis()->SetLabelFont(42);
   Graph_Graph33->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph33->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph33->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph33);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx34[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy34[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx34,Graph_fy34);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0097dd");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph34 = new TH1F("Graph_Graph34","Graph",100,0.252,0.468);
   Graph_Graph34->SetMinimum(0);
   Graph_Graph34->SetMaximum(0.33);
   Graph_Graph34->SetDirectory(0);
   Graph_Graph34->SetStats(0);
   Graph_Graph34->SetLineWidth(2);
   Graph_Graph34->GetXaxis()->SetNdivisions(506);
   Graph_Graph34->GetXaxis()->SetLabelFont(42);
   Graph_Graph34->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph34->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph34->GetXaxis()->SetTitleFont(42);
   Graph_Graph34->GetYaxis()->SetNdivisions(506);
   Graph_Graph34->GetYaxis()->SetLabelFont(42);
   Graph_Graph34->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph34->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph34->GetYaxis()->SetTitleFont(42);
   Graph_Graph34->GetZaxis()->SetNdivisions(506);
   Graph_Graph34->GetZaxis()->SetLabelFont(42);
   Graph_Graph34->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph34->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph34->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph34);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx35[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy35[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx35,Graph_fy35);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00138d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph35 = new TH1F("Graph_Graph35","Graph",100,0.433,0.637);
   Graph_Graph35->SetMinimum(0);
   Graph_Graph35->SetMaximum(0.33);
   Graph_Graph35->SetDirectory(0);
   Graph_Graph35->SetStats(0);
   Graph_Graph35->SetLineWidth(2);
   Graph_Graph35->GetXaxis()->SetNdivisions(506);
   Graph_Graph35->GetXaxis()->SetLabelFont(42);
   Graph_Graph35->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph35->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph35->GetXaxis()->SetTitleFont(42);
   Graph_Graph35->GetYaxis()->SetNdivisions(506);
   Graph_Graph35->GetYaxis()->SetLabelFont(42);
   Graph_Graph35->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph35->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph35->GetYaxis()->SetTitleFont(42);
   Graph_Graph35->GetZaxis()->SetNdivisions(506);
   Graph_Graph35->GetZaxis()->SetLabelFont(42);
   Graph_Graph35->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph35->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph35->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph35);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx36[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy36[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx36,Graph_fy36);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph36 = new TH1F("Graph_Graph36","Graph",100,0.606,0.774);
   Graph_Graph36->SetMinimum(0);
   Graph_Graph36->SetMaximum(0.33);
   Graph_Graph36->SetDirectory(0);
   Graph_Graph36->SetStats(0);
   Graph_Graph36->SetLineWidth(2);
   Graph_Graph36->GetXaxis()->SetNdivisions(506);
   Graph_Graph36->GetXaxis()->SetLabelFont(42);
   Graph_Graph36->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph36->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph36->GetXaxis()->SetTitleFont(42);
   Graph_Graph36->GetYaxis()->SetNdivisions(506);
   Graph_Graph36->GetYaxis()->SetLabelFont(42);
   Graph_Graph36->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph36->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph36->GetYaxis()->SetTitleFont(42);
   Graph_Graph36->GetZaxis()->SetNdivisions(506);
   Graph_Graph36->GetZaxis()->SetLabelFont(42);
   Graph_Graph36->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph36->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph36->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph36);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx37[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy37[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx37,Graph_fy37);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001f94");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph37 = new TH1F("Graph_Graph37","Graph",100,0.75,0.87);
   Graph_Graph37->SetMinimum(0);
   Graph_Graph37->SetMaximum(0.33);
   Graph_Graph37->SetDirectory(0);
   Graph_Graph37->SetStats(0);
   Graph_Graph37->SetLineWidth(2);
   Graph_Graph37->GetXaxis()->SetNdivisions(506);
   Graph_Graph37->GetXaxis()->SetLabelFont(42);
   Graph_Graph37->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph37->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph37->GetXaxis()->SetTitleFont(42);
   Graph_Graph37->GetYaxis()->SetNdivisions(506);
   Graph_Graph37->GetYaxis()->SetLabelFont(42);
   Graph_Graph37->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph37->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph37->GetYaxis()->SetTitleFont(42);
   Graph_Graph37->GetZaxis()->SetNdivisions(506);
   Graph_Graph37->GetZaxis()->SetLabelFont(42);
   Graph_Graph37->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph37->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph37->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph37);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx38[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy38[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx38,Graph_fy38);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph38 = new TH1F("Graph_Graph38","Graph",100,0.852,0.948);
   Graph_Graph38->SetMinimum(0);
   Graph_Graph38->SetMaximum(0.33);
   Graph_Graph38->SetDirectory(0);
   Graph_Graph38->SetStats(0);
   Graph_Graph38->SetLineWidth(2);
   Graph_Graph38->GetXaxis()->SetNdivisions(506);
   Graph_Graph38->GetXaxis()->SetLabelFont(42);
   Graph_Graph38->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph38->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph38->GetXaxis()->SetTitleFont(42);
   Graph_Graph38->GetYaxis()->SetNdivisions(506);
   Graph_Graph38->GetYaxis()->SetLabelFont(42);
   Graph_Graph38->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph38->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph38->GetYaxis()->SetTitleFont(42);
   Graph_Graph38->GetZaxis()->SetNdivisions(506);
   Graph_Graph38->GetZaxis()->SetLabelFont(42);
   Graph_Graph38->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph38->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph38->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph38);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx39[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy39[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx39,Graph_fy39);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph39 = new TH1F("Graph_Graph39","Graph",100,0.934,1.006);
   Graph_Graph39->SetMinimum(0);
   Graph_Graph39->SetMaximum(0.33);
   Graph_Graph39->SetDirectory(0);
   Graph_Graph39->SetStats(0);
   Graph_Graph39->SetLineWidth(2);
   Graph_Graph39->GetXaxis()->SetNdivisions(506);
   Graph_Graph39->GetXaxis()->SetLabelFont(42);
   Graph_Graph39->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph39->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph39->GetXaxis()->SetTitleFont(42);
   Graph_Graph39->GetYaxis()->SetNdivisions(506);
   Graph_Graph39->GetYaxis()->SetLabelFont(42);
   Graph_Graph39->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph39->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph39->GetYaxis()->SetTitleFont(42);
   Graph_Graph39->GetZaxis()->SetNdivisions(506);
   Graph_Graph39->GetZaxis()->SetLabelFont(42);
   Graph_Graph39->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph39->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph39->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph39);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx40[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy40[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx40,Graph_fy40);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002d9d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph40 = new TH1F("Graph_Graph40","Graph",100,-1.1,0);
   Graph_Graph40->SetMinimum(0.285);
   Graph_Graph40->SetMaximum(0.465);
   Graph_Graph40->SetDirectory(0);
   Graph_Graph40->SetStats(0);
   Graph_Graph40->SetLineWidth(2);
   Graph_Graph40->GetXaxis()->SetNdivisions(506);
   Graph_Graph40->GetXaxis()->SetLabelFont(42);
   Graph_Graph40->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph40->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph40->GetXaxis()->SetTitleFont(42);
   Graph_Graph40->GetYaxis()->SetNdivisions(506);
   Graph_Graph40->GetYaxis()->SetLabelFont(42);
   Graph_Graph40->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph40->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph40->GetYaxis()->SetTitleFont(42);
   Graph_Graph40->GetZaxis()->SetNdivisions(506);
   Graph_Graph40->GetZaxis()->SetLabelFont(42);
   Graph_Graph40->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph40->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph40->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph40);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx41[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy41[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx41,Graph_fy41);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#16d3e8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph41 = new TH1F("Graph_Graph41","Graph",100,0,0.297);
   Graph_Graph41->SetMinimum(0.285);
   Graph_Graph41->SetMaximum(0.465);
   Graph_Graph41->SetDirectory(0);
   Graph_Graph41->SetStats(0);
   Graph_Graph41->SetLineWidth(2);
   Graph_Graph41->GetXaxis()->SetNdivisions(506);
   Graph_Graph41->GetXaxis()->SetLabelFont(42);
   Graph_Graph41->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph41->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph41->GetXaxis()->SetTitleFont(42);
   Graph_Graph41->GetYaxis()->SetNdivisions(506);
   Graph_Graph41->GetYaxis()->SetLabelFont(42);
   Graph_Graph41->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph41->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph41->GetYaxis()->SetTitleFont(42);
   Graph_Graph41->GetZaxis()->SetNdivisions(506);
   Graph_Graph41->GetZaxis()->SetLabelFont(42);
   Graph_Graph41->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph41->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph41->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph41);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx42[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy42[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx42,Graph_fy42);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001890");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph42 = new TH1F("Graph_Graph42","Graph",100,0.252,0.468);
   Graph_Graph42->SetMinimum(0.285);
   Graph_Graph42->SetMaximum(0.465);
   Graph_Graph42->SetDirectory(0);
   Graph_Graph42->SetStats(0);
   Graph_Graph42->SetLineWidth(2);
   Graph_Graph42->GetXaxis()->SetNdivisions(506);
   Graph_Graph42->GetXaxis()->SetLabelFont(42);
   Graph_Graph42->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph42->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph42->GetXaxis()->SetTitleFont(42);
   Graph_Graph42->GetYaxis()->SetNdivisions(506);
   Graph_Graph42->GetYaxis()->SetLabelFont(42);
   Graph_Graph42->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph42->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph42->GetYaxis()->SetTitleFont(42);
   Graph_Graph42->GetZaxis()->SetNdivisions(506);
   Graph_Graph42->GetZaxis()->SetLabelFont(42);
   Graph_Graph42->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph42->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph42->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph42);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx43[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy43[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx43,Graph_fy43);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002699");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph43 = new TH1F("Graph_Graph43","Graph",100,0.433,0.637);
   Graph_Graph43->SetMinimum(0.285);
   Graph_Graph43->SetMaximum(0.465);
   Graph_Graph43->SetDirectory(0);
   Graph_Graph43->SetStats(0);
   Graph_Graph43->SetLineWidth(2);
   Graph_Graph43->GetXaxis()->SetNdivisions(506);
   Graph_Graph43->GetXaxis()->SetLabelFont(42);
   Graph_Graph43->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph43->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph43->GetXaxis()->SetTitleFont(42);
   Graph_Graph43->GetYaxis()->SetNdivisions(506);
   Graph_Graph43->GetYaxis()->SetLabelFont(42);
   Graph_Graph43->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph43->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph43->GetYaxis()->SetTitleFont(42);
   Graph_Graph43->GetZaxis()->SetNdivisions(506);
   Graph_Graph43->GetZaxis()->SetLabelFont(42);
   Graph_Graph43->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph43->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph43->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph43);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx44[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy44[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx44,Graph_fy44);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph44 = new TH1F("Graph_Graph44","Graph",100,0.606,0.774);
   Graph_Graph44->SetMinimum(0.285);
   Graph_Graph44->SetMaximum(0.465);
   Graph_Graph44->SetDirectory(0);
   Graph_Graph44->SetStats(0);
   Graph_Graph44->SetLineWidth(2);
   Graph_Graph44->GetXaxis()->SetNdivisions(506);
   Graph_Graph44->GetXaxis()->SetLabelFont(42);
   Graph_Graph44->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph44->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph44->GetXaxis()->SetTitleFont(42);
   Graph_Graph44->GetYaxis()->SetNdivisions(506);
   Graph_Graph44->GetYaxis()->SetLabelFont(42);
   Graph_Graph44->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph44->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph44->GetYaxis()->SetTitleFont(42);
   Graph_Graph44->GetZaxis()->SetNdivisions(506);
   Graph_Graph44->GetZaxis()->SetLabelFont(42);
   Graph_Graph44->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph44->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph44->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph44);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx45[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy45[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx45,Graph_fy45);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph45 = new TH1F("Graph_Graph45","Graph",100,0.75,0.87);
   Graph_Graph45->SetMinimum(0.285);
   Graph_Graph45->SetMaximum(0.465);
   Graph_Graph45->SetDirectory(0);
   Graph_Graph45->SetStats(0);
   Graph_Graph45->SetLineWidth(2);
   Graph_Graph45->GetXaxis()->SetNdivisions(506);
   Graph_Graph45->GetXaxis()->SetLabelFont(42);
   Graph_Graph45->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph45->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph45->GetXaxis()->SetTitleFont(42);
   Graph_Graph45->GetYaxis()->SetNdivisions(506);
   Graph_Graph45->GetYaxis()->SetLabelFont(42);
   Graph_Graph45->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph45->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph45->GetYaxis()->SetTitleFont(42);
   Graph_Graph45->GetZaxis()->SetNdivisions(506);
   Graph_Graph45->GetZaxis()->SetLabelFont(42);
   Graph_Graph45->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph45->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph45->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph45);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx46[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy46[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx46,Graph_fy46);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph46 = new TH1F("Graph_Graph46","Graph",100,0.852,0.948);
   Graph_Graph46->SetMinimum(0.285);
   Graph_Graph46->SetMaximum(0.465);
   Graph_Graph46->SetDirectory(0);
   Graph_Graph46->SetStats(0);
   Graph_Graph46->SetLineWidth(2);
   Graph_Graph46->GetXaxis()->SetNdivisions(506);
   Graph_Graph46->GetXaxis()->SetLabelFont(42);
   Graph_Graph46->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph46->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph46->GetXaxis()->SetTitleFont(42);
   Graph_Graph46->GetYaxis()->SetNdivisions(506);
   Graph_Graph46->GetYaxis()->SetLabelFont(42);
   Graph_Graph46->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph46->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph46->GetYaxis()->SetTitleFont(42);
   Graph_Graph46->GetZaxis()->SetNdivisions(506);
   Graph_Graph46->GetZaxis()->SetLabelFont(42);
   Graph_Graph46->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph46->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph46->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph46);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx47[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy47[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx47,Graph_fy47);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00138d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph47 = new TH1F("Graph_Graph47","Graph",100,0.934,1.006);
   Graph_Graph47->SetMinimum(0.285);
   Graph_Graph47->SetMaximum(0.465);
   Graph_Graph47->SetDirectory(0);
   Graph_Graph47->SetStats(0);
   Graph_Graph47->SetLineWidth(2);
   Graph_Graph47->GetXaxis()->SetNdivisions(506);
   Graph_Graph47->GetXaxis()->SetLabelFont(42);
   Graph_Graph47->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph47->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph47->GetXaxis()->SetTitleFont(42);
   Graph_Graph47->GetYaxis()->SetNdivisions(506);
   Graph_Graph47->GetYaxis()->SetLabelFont(42);
   Graph_Graph47->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph47->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph47->GetYaxis()->SetTitleFont(42);
   Graph_Graph47->GetZaxis()->SetNdivisions(506);
   Graph_Graph47->GetZaxis()->SetLabelFont(42);
   Graph_Graph47->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph47->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph47->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph47);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx48[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy48[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx48,Graph_fy48);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph48 = new TH1F("Graph_Graph48","Graph",100,-1.1,0);
   Graph_Graph48->SetMinimum(0.245);
   Graph_Graph48->SetMaximum(2.705);
   Graph_Graph48->SetDirectory(0);
   Graph_Graph48->SetStats(0);
   Graph_Graph48->SetLineWidth(2);
   Graph_Graph48->GetXaxis()->SetNdivisions(506);
   Graph_Graph48->GetXaxis()->SetLabelFont(42);
   Graph_Graph48->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph48->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph48->GetXaxis()->SetTitleFont(42);
   Graph_Graph48->GetYaxis()->SetNdivisions(506);
   Graph_Graph48->GetYaxis()->SetLabelFont(42);
   Graph_Graph48->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph48->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph48->GetYaxis()->SetTitleFont(42);
   Graph_Graph48->GetZaxis()->SetNdivisions(506);
   Graph_Graph48->GetZaxis()->SetLabelFont(42);
   Graph_Graph48->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph48->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph48->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph48);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx49[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy49[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx49,Graph_fy49);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001f94");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph49 = new TH1F("Graph_Graph49","Graph",100,0,0.297);
   Graph_Graph49->SetMinimum(0.418);
   Graph_Graph49->SetMaximum(0.802);
   Graph_Graph49->SetDirectory(0);
   Graph_Graph49->SetStats(0);
   Graph_Graph49->SetLineWidth(2);
   Graph_Graph49->GetXaxis()->SetNdivisions(506);
   Graph_Graph49->GetXaxis()->SetLabelFont(42);
   Graph_Graph49->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph49->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph49->GetXaxis()->SetTitleFont(42);
   Graph_Graph49->GetYaxis()->SetNdivisions(506);
   Graph_Graph49->GetYaxis()->SetLabelFont(42);
   Graph_Graph49->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph49->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph49->GetYaxis()->SetTitleFont(42);
   Graph_Graph49->GetZaxis()->SetNdivisions(506);
   Graph_Graph49->GetZaxis()->SetLabelFont(42);
   Graph_Graph49->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph49->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph49->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph49);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx50[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy50[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx50,Graph_fy50);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph50 = new TH1F("Graph_Graph50","Graph",100,0.252,0.468);
   Graph_Graph50->SetMinimum(0.418);
   Graph_Graph50->SetMaximum(0.802);
   Graph_Graph50->SetDirectory(0);
   Graph_Graph50->SetStats(0);
   Graph_Graph50->SetLineWidth(2);
   Graph_Graph50->GetXaxis()->SetNdivisions(506);
   Graph_Graph50->GetXaxis()->SetLabelFont(42);
   Graph_Graph50->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph50->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph50->GetXaxis()->SetTitleFont(42);
   Graph_Graph50->GetYaxis()->SetNdivisions(506);
   Graph_Graph50->GetYaxis()->SetLabelFont(42);
   Graph_Graph50->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph50->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph50->GetYaxis()->SetTitleFont(42);
   Graph_Graph50->GetZaxis()->SetNdivisions(506);
   Graph_Graph50->GetZaxis()->SetLabelFont(42);
   Graph_Graph50->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph50->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph50->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph50);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx51[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy51[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx51,Graph_fy51);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00138d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph51 = new TH1F("Graph_Graph51","Graph",100,0.433,0.637);
   Graph_Graph51->SetMinimum(0.418);
   Graph_Graph51->SetMaximum(0.802);
   Graph_Graph51->SetDirectory(0);
   Graph_Graph51->SetStats(0);
   Graph_Graph51->SetLineWidth(2);
   Graph_Graph51->GetXaxis()->SetNdivisions(506);
   Graph_Graph51->GetXaxis()->SetLabelFont(42);
   Graph_Graph51->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph51->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph51->GetXaxis()->SetTitleFont(42);
   Graph_Graph51->GetYaxis()->SetNdivisions(506);
   Graph_Graph51->GetYaxis()->SetLabelFont(42);
   Graph_Graph51->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph51->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph51->GetYaxis()->SetTitleFont(42);
   Graph_Graph51->GetZaxis()->SetNdivisions(506);
   Graph_Graph51->GetZaxis()->SetLabelFont(42);
   Graph_Graph51->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph51->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph51->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph51);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx52[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy52[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx52,Graph_fy52);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph52 = new TH1F("Graph_Graph52","Graph",100,0.606,0.774);
   Graph_Graph52->SetMinimum(0.418);
   Graph_Graph52->SetMaximum(0.802);
   Graph_Graph52->SetDirectory(0);
   Graph_Graph52->SetStats(0);
   Graph_Graph52->SetLineWidth(2);
   Graph_Graph52->GetXaxis()->SetNdivisions(506);
   Graph_Graph52->GetXaxis()->SetLabelFont(42);
   Graph_Graph52->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph52->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph52->GetXaxis()->SetTitleFont(42);
   Graph_Graph52->GetYaxis()->SetNdivisions(506);
   Graph_Graph52->GetYaxis()->SetLabelFont(42);
   Graph_Graph52->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph52->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph52->GetYaxis()->SetTitleFont(42);
   Graph_Graph52->GetZaxis()->SetNdivisions(506);
   Graph_Graph52->GetZaxis()->SetLabelFont(42);
   Graph_Graph52->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph52->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph52->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph52);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx53[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy53[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx53,Graph_fy53);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph53 = new TH1F("Graph_Graph53","Graph",100,0.75,0.87);
   Graph_Graph53->SetMinimum(0.418);
   Graph_Graph53->SetMaximum(0.802);
   Graph_Graph53->SetDirectory(0);
   Graph_Graph53->SetStats(0);
   Graph_Graph53->SetLineWidth(2);
   Graph_Graph53->GetXaxis()->SetNdivisions(506);
   Graph_Graph53->GetXaxis()->SetLabelFont(42);
   Graph_Graph53->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph53->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph53->GetXaxis()->SetTitleFont(42);
   Graph_Graph53->GetYaxis()->SetNdivisions(506);
   Graph_Graph53->GetYaxis()->SetLabelFont(42);
   Graph_Graph53->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph53->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph53->GetYaxis()->SetTitleFont(42);
   Graph_Graph53->GetZaxis()->SetNdivisions(506);
   Graph_Graph53->GetZaxis()->SetLabelFont(42);
   Graph_Graph53->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph53->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph53->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph53);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx54[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy54[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx54,Graph_fy54);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph54 = new TH1F("Graph_Graph54","Graph",100,0.852,0.948);
   Graph_Graph54->SetMinimum(0.418);
   Graph_Graph54->SetMaximum(0.802);
   Graph_Graph54->SetDirectory(0);
   Graph_Graph54->SetStats(0);
   Graph_Graph54->SetLineWidth(2);
   Graph_Graph54->GetXaxis()->SetNdivisions(506);
   Graph_Graph54->GetXaxis()->SetLabelFont(42);
   Graph_Graph54->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph54->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph54->GetXaxis()->SetTitleFont(42);
   Graph_Graph54->GetYaxis()->SetNdivisions(506);
   Graph_Graph54->GetYaxis()->SetLabelFont(42);
   Graph_Graph54->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph54->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph54->GetYaxis()->SetTitleFont(42);
   Graph_Graph54->GetZaxis()->SetNdivisions(506);
   Graph_Graph54->GetZaxis()->SetLabelFont(42);
   Graph_Graph54->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph54->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph54->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph54);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx55[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy55[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx55,Graph_fy55);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph55 = new TH1F("Graph_Graph55","Graph",100,0.934,1.006);
   Graph_Graph55->SetMinimum(0.418);
   Graph_Graph55->SetMaximum(0.802);
   Graph_Graph55->SetDirectory(0);
   Graph_Graph55->SetStats(0);
   Graph_Graph55->SetLineWidth(2);
   Graph_Graph55->GetXaxis()->SetNdivisions(506);
   Graph_Graph55->GetXaxis()->SetLabelFont(42);
   Graph_Graph55->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph55->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph55->GetXaxis()->SetTitleFont(42);
   Graph_Graph55->GetYaxis()->SetNdivisions(506);
   Graph_Graph55->GetYaxis()->SetLabelFont(42);
   Graph_Graph55->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph55->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph55->GetYaxis()->SetTitleFont(42);
   Graph_Graph55->GetZaxis()->SetNdivisions(506);
   Graph_Graph55->GetZaxis()->SetLabelFont(42);
   Graph_Graph55->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph55->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph55->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph55);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx56[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy56[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx56,Graph_fy56);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00138d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph56 = new TH1F("Graph_Graph56","Graph",100,0,0.297);
   Graph_Graph56->SetMinimum(0.597);
   Graph_Graph56->SetMaximum(2.673);
   Graph_Graph56->SetDirectory(0);
   Graph_Graph56->SetStats(0);
   Graph_Graph56->SetLineWidth(2);
   Graph_Graph56->GetXaxis()->SetNdivisions(506);
   Graph_Graph56->GetXaxis()->SetLabelFont(42);
   Graph_Graph56->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph56->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph56->GetXaxis()->SetTitleFont(42);
   Graph_Graph56->GetYaxis()->SetNdivisions(506);
   Graph_Graph56->GetYaxis()->SetLabelFont(42);
   Graph_Graph56->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph56->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph56->GetYaxis()->SetTitleFont(42);
   Graph_Graph56->GetZaxis()->SetNdivisions(506);
   Graph_Graph56->GetZaxis()->SetLabelFont(42);
   Graph_Graph56->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph56->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph56->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph56);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx57[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy57[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx57,Graph_fy57);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000484");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph57 = new TH1F("Graph_Graph57","Graph",100,0.252,0.468);
   Graph_Graph57->SetMinimum(0.597);
   Graph_Graph57->SetMaximum(2.673);
   Graph_Graph57->SetDirectory(0);
   Graph_Graph57->SetStats(0);
   Graph_Graph57->SetLineWidth(2);
   Graph_Graph57->GetXaxis()->SetNdivisions(506);
   Graph_Graph57->GetXaxis()->SetLabelFont(42);
   Graph_Graph57->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph57->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph57->GetXaxis()->SetTitleFont(42);
   Graph_Graph57->GetYaxis()->SetNdivisions(506);
   Graph_Graph57->GetYaxis()->SetLabelFont(42);
   Graph_Graph57->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph57->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph57->GetYaxis()->SetTitleFont(42);
   Graph_Graph57->GetZaxis()->SetNdivisions(506);
   Graph_Graph57->GetZaxis()->SetLabelFont(42);
   Graph_Graph57->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph57->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph57->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph57);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx58[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy58[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx58,Graph_fy58);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph58 = new TH1F("Graph_Graph58","Graph",100,0.433,0.637);
   Graph_Graph58->SetMinimum(0.597);
   Graph_Graph58->SetMaximum(2.673);
   Graph_Graph58->SetDirectory(0);
   Graph_Graph58->SetStats(0);
   Graph_Graph58->SetLineWidth(2);
   Graph_Graph58->GetXaxis()->SetNdivisions(506);
   Graph_Graph58->GetXaxis()->SetLabelFont(42);
   Graph_Graph58->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph58->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph58->GetXaxis()->SetTitleFont(42);
   Graph_Graph58->GetYaxis()->SetNdivisions(506);
   Graph_Graph58->GetYaxis()->SetLabelFont(42);
   Graph_Graph58->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph58->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph58->GetYaxis()->SetTitleFont(42);
   Graph_Graph58->GetZaxis()->SetNdivisions(506);
   Graph_Graph58->GetZaxis()->SetLabelFont(42);
   Graph_Graph58->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph58->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph58->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph58);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx59[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy59[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx59,Graph_fy59);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph59 = new TH1F("Graph_Graph59","Graph",100,0.606,0.774);
   Graph_Graph59->SetMinimum(0.597);
   Graph_Graph59->SetMaximum(2.673);
   Graph_Graph59->SetDirectory(0);
   Graph_Graph59->SetStats(0);
   Graph_Graph59->SetLineWidth(2);
   Graph_Graph59->GetXaxis()->SetNdivisions(506);
   Graph_Graph59->GetXaxis()->SetLabelFont(42);
   Graph_Graph59->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph59->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph59->GetXaxis()->SetTitleFont(42);
   Graph_Graph59->GetYaxis()->SetNdivisions(506);
   Graph_Graph59->GetYaxis()->SetLabelFont(42);
   Graph_Graph59->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph59->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph59->GetYaxis()->SetTitleFont(42);
   Graph_Graph59->GetZaxis()->SetNdivisions(506);
   Graph_Graph59->GetZaxis()->SetLabelFont(42);
   Graph_Graph59->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph59->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph59->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph59);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx60[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy60[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx60,Graph_fy60);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph60 = new TH1F("Graph_Graph60","Graph",100,0.75,0.87);
   Graph_Graph60->SetMinimum(0.597);
   Graph_Graph60->SetMaximum(2.673);
   Graph_Graph60->SetDirectory(0);
   Graph_Graph60->SetStats(0);
   Graph_Graph60->SetLineWidth(2);
   Graph_Graph60->GetXaxis()->SetNdivisions(506);
   Graph_Graph60->GetXaxis()->SetLabelFont(42);
   Graph_Graph60->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph60->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph60->GetXaxis()->SetTitleFont(42);
   Graph_Graph60->GetYaxis()->SetNdivisions(506);
   Graph_Graph60->GetYaxis()->SetLabelFont(42);
   Graph_Graph60->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph60->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph60->GetYaxis()->SetTitleFont(42);
   Graph_Graph60->GetZaxis()->SetNdivisions(506);
   Graph_Graph60->GetZaxis()->SetLabelFont(42);
   Graph_Graph60->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph60->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph60->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph60);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx61[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy61[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx61,Graph_fy61);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph61 = new TH1F("Graph_Graph61","Graph",100,0.852,0.948);
   Graph_Graph61->SetMinimum(0.597);
   Graph_Graph61->SetMaximum(2.673);
   Graph_Graph61->SetDirectory(0);
   Graph_Graph61->SetStats(0);
   Graph_Graph61->SetLineWidth(2);
   Graph_Graph61->GetXaxis()->SetNdivisions(506);
   Graph_Graph61->GetXaxis()->SetLabelFont(42);
   Graph_Graph61->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph61->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph61->GetXaxis()->SetTitleFont(42);
   Graph_Graph61->GetYaxis()->SetNdivisions(506);
   Graph_Graph61->GetYaxis()->SetLabelFont(42);
   Graph_Graph61->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph61->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph61->GetYaxis()->SetTitleFont(42);
   Graph_Graph61->GetZaxis()->SetNdivisions(506);
   Graph_Graph61->GetZaxis()->SetLabelFont(42);
   Graph_Graph61->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph61->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph61->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph61);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx62[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy62[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx62,Graph_fy62);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph62 = new TH1F("Graph_Graph62","Graph",100,0.934,1.006);
   Graph_Graph62->SetMinimum(0.597);
   Graph_Graph62->SetMaximum(2.673);
   Graph_Graph62->SetDirectory(0);
   Graph_Graph62->SetStats(0);
   Graph_Graph62->SetLineWidth(2);
   Graph_Graph62->GetXaxis()->SetNdivisions(506);
   Graph_Graph62->GetXaxis()->SetLabelFont(42);
   Graph_Graph62->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph62->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph62->GetXaxis()->SetTitleFont(42);
   Graph_Graph62->GetYaxis()->SetNdivisions(506);
   Graph_Graph62->GetYaxis()->SetLabelFont(42);
   Graph_Graph62->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph62->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph62->GetYaxis()->SetTitleFont(42);
   Graph_Graph62->GetZaxis()->SetNdivisions(506);
   Graph_Graph62->GetZaxis()->SetLabelFont(42);
   Graph_Graph62->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph62->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph62->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph62);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.1091585);
   _reco_per_true->SetBinContent(2,0.4059759);
   _reco_per_true->SetBinContent(3,0.1006106);
   _reco_per_true->SetBinContent(4,0.0130799);
   _reco_per_true->SetBinContent(5,0.004361398);
   _reco_per_true->SetBinContent(6,0.02189335);
   _reco_per_true->SetBinContent(7,0.004368317);
   _reco_per_true->SetBinContent(8,0.008743597);
   _reco_per_true->SetBinContent(9,0.0305634);
   _reco_per_true->SetBinContent(10,0.14849);
   _reco_per_true->SetBinContent(11,0.01744517);
   _reco_per_true->SetBinContent(12,0.02623455);
   _reco_per_true->SetBinContent(13,0.008755364);
   _reco_per_true->SetBinContent(15,0.004387121);
   _reco_per_true->SetBinContent(16,0.01312316);
   _reco_per_true->SetBinContent(17,0.00432765);
   _reco_per_true->SetBinContent(18,0.02183073);
   _reco_per_true->SetBinContent(19,0.008738789);
   _reco_per_true->SetBinContent(20,0.01306417);
   _reco_per_true->SetBinContent(21,0.004358169);
   _reco_per_true->SetBinContent(22,0.004356878);
   _reco_per_true->SetBinContent(23,0.004368076);
   _reco_per_true->SetBinContent(24,0.004310856);
   _reco_per_true->SetBinContent(25,0.01309988);
   _reco_per_true->SetBinContent(26,0.00435452);
   _reco_per_true->SetBinError(1,0.02183183);
   _reco_per_true->SetBinError(2,0.04209797);
   _reco_per_true->SetBinError(3,0.02097883);
   _reco_per_true->SetBinError(4,0.00755177);
   _reco_per_true->SetBinError(5,0.004361398);
   _reco_per_true->SetBinError(6,0.009791013);
   _reco_per_true->SetBinError(7,0.004368317);
   _reco_per_true->SetBinError(8,0.006182662);
   _reco_per_true->SetBinError(9,0.0115519);
   _reco_per_true->SetBinError(10,0.025466);
   _reco_per_true->SetBinError(11,0.008722702);
   _reco_per_true->SetBinError(12,0.01071024);
   _reco_per_true->SetBinError(13,0.006190994);
   _reco_per_true->SetBinError(15,0.004387121);
   _reco_per_true->SetBinError(16,0.007576695);
   _reco_per_true->SetBinError(17,0.00432765);
   _reco_per_true->SetBinError(18,0.009763001);
   _reco_per_true->SetBinError(19,0.006179282);
   _reco_per_true->SetBinError(20,0.007542632);
   _reco_per_true->SetBinError(21,0.004358169);
   _reco_per_true->SetBinError(22,0.004356878);
   _reco_per_true->SetBinError(23,0.004368076);
   _reco_per_true->SetBinError(24,0.004310856);
   _reco_per_true->SetBinError(25,0.007563222);
   _reco_per_true->SetBinError(26,0.00435452);
   _reco_per_true->SetEntries(229);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.001592062);
   _reco_per_true->SetContourLevel(2,0.003184124);
   _reco_per_true->SetContourLevel(3,0.004776187);
   _reco_per_true->SetContourLevel(4,0.006368249);
   _reco_per_true->SetContourLevel(5,0.007960311);
   _reco_per_true->SetContourLevel(6,0.009552373);
   _reco_per_true->SetContourLevel(7,0.01114444);
   _reco_per_true->SetContourLevel(8,0.0127365);
   _reco_per_true->SetContourLevel(9,0.01432856);
   _reco_per_true->SetContourLevel(10,0.01592062);
   _reco_per_true->SetContourLevel(11,0.01751268);
   _reco_per_true->SetContourLevel(12,0.01910475);
   _reco_per_true->SetContourLevel(13,0.02069681);
   _reco_per_true->SetContourLevel(14,0.02228887);
   _reco_per_true->SetContourLevel(15,0.02388093);
   _reco_per_true->SetContourLevel(16,0.025473);
   _reco_per_true->SetContourLevel(17,0.02706506);
   _reco_per_true->SetContourLevel(18,0.02865712);
   _reco_per_true->SetContourLevel(19,0.03024918);
   _reco_per_true->SetContourLevel(20,0.03184124);
   _reco_per_true->SetContourLevel(21,0.03343331);
   _reco_per_true->SetContourLevel(22,0.03502537);
   _reco_per_true->SetContourLevel(23,0.03661743);
   _reco_per_true->SetContourLevel(24,0.03820949);
   _reco_per_true->SetContourLevel(25,0.03980156);
   _reco_per_true->SetContourLevel(26,0.04139362);
   _reco_per_true->SetContourLevel(27,0.04298568);
   _reco_per_true->SetContourLevel(28,0.04457774);
   _reco_per_true->SetContourLevel(29,0.04616981);
   _reco_per_true->SetContourLevel(30,0.04776187);
   _reco_per_true->SetContourLevel(31,0.04935393);
   _reco_per_true->SetContourLevel(32,0.05094599);
   _reco_per_true->SetContourLevel(33,0.05253805);
   _reco_per_true->SetContourLevel(34,0.05413012);
   _reco_per_true->SetContourLevel(35,0.05572218);
   _reco_per_true->SetContourLevel(36,0.05731424);
   _reco_per_true->SetContourLevel(37,0.0589063);
   _reco_per_true->SetContourLevel(38,0.06049837);
   _reco_per_true->SetContourLevel(39,0.06209043);
   _reco_per_true->SetContourLevel(40,0.06368249);
   _reco_per_true->SetContourLevel(41,0.06527455);
   _reco_per_true->SetContourLevel(42,0.06686661);
   _reco_per_true->SetContourLevel(43,0.06845868);
   _reco_per_true->SetContourLevel(44,0.07005074);
   _reco_per_true->SetContourLevel(45,0.0716428);
   _reco_per_true->SetContourLevel(46,0.07323486);
   _reco_per_true->SetContourLevel(47,0.07482693);
   _reco_per_true->SetContourLevel(48,0.07641899);
   _reco_per_true->SetContourLevel(49,0.07801105);
   _reco_per_true->SetContourLevel(50,0.07960311);
   _reco_per_true->SetContourLevel(51,0.08119517);
   _reco_per_true->SetContourLevel(52,0.08278724);
   _reco_per_true->SetContourLevel(53,0.0843793);
   _reco_per_true->SetContourLevel(54,0.08597136);
   _reco_per_true->SetContourLevel(55,0.08756342);
   _reco_per_true->SetContourLevel(56,0.08915549);
   _reco_per_true->SetContourLevel(57,0.09074755);
   _reco_per_true->SetContourLevel(58,0.09233961);
   _reco_per_true->SetContourLevel(59,0.09393167);
   _reco_per_true->SetContourLevel(60,0.09552373);
   _reco_per_true->SetContourLevel(61,0.0971158);
   _reco_per_true->SetContourLevel(62,0.09870786);
   _reco_per_true->SetContourLevel(63,0.1002999);
   _reco_per_true->SetContourLevel(64,0.101892);
   _reco_per_true->SetContourLevel(65,0.103484);
   _reco_per_true->SetContourLevel(66,0.1050761);
   _reco_per_true->SetContourLevel(67,0.1066682);
   _reco_per_true->SetContourLevel(68,0.1082602);
   _reco_per_true->SetContourLevel(69,0.1098523);
   _reco_per_true->SetContourLevel(70,0.1114444);
   _reco_per_true->SetContourLevel(71,0.1130364);
   _reco_per_true->SetContourLevel(72,0.1146285);
   _reco_per_true->SetContourLevel(73,0.1162205);
   _reco_per_true->SetContourLevel(74,0.1178126);
   _reco_per_true->SetContourLevel(75,0.1194047);
   _reco_per_true->SetContourLevel(76,0.1209967);
   _reco_per_true->SetContourLevel(77,0.1225888);
   _reco_per_true->SetContourLevel(78,0.1241809);
   _reco_per_true->SetContourLevel(79,0.1257729);
   _reco_per_true->SetContourLevel(80,0.127365);
   _reco_per_true->SetContourLevel(81,0.128957);
   _reco_per_true->SetContourLevel(82,0.1305491);
   _reco_per_true->SetContourLevel(83,0.1321412);
   _reco_per_true->SetContourLevel(84,0.1337332);
   _reco_per_true->SetContourLevel(85,0.1353253);
   _reco_per_true->SetContourLevel(86,0.1369174);
   _reco_per_true->SetContourLevel(87,0.1385094);
   _reco_per_true->SetContourLevel(88,0.1401015);
   _reco_per_true->SetContourLevel(89,0.1416935);
   _reco_per_true->SetContourLevel(90,0.1432856);
   _reco_per_true->SetContourLevel(91,0.1448777);
   _reco_per_true->SetContourLevel(92,0.1464697);
   _reco_per_true->SetContourLevel(93,0.1480618);
   _reco_per_true->SetContourLevel(94,0.1496539);
   _reco_per_true->SetContourLevel(95,0.1512459);
   _reco_per_true->SetContourLevel(96,0.152838);
   _reco_per_true->SetContourLevel(97,0.15443);
   _reco_per_true->SetContourLevel(98,0.1560221);
   _reco_per_true->SetContourLevel(99,0.1576142);
   _reco_per_true->SetContourLevel(100,0.1592062);
   _reco_per_true->SetContourLevel(101,0.1607983);
   _reco_per_true->SetContourLevel(102,0.1623903);
   _reco_per_true->SetContourLevel(103,0.1639824);
   _reco_per_true->SetContourLevel(104,0.1655745);
   _reco_per_true->SetContourLevel(105,0.1671665);
   _reco_per_true->SetContourLevel(106,0.1687586);
   _reco_per_true->SetContourLevel(107,0.1703507);
   _reco_per_true->SetContourLevel(108,0.1719427);
   _reco_per_true->SetContourLevel(109,0.1735348);
   _reco_per_true->SetContourLevel(110,0.1751268);
   _reco_per_true->SetContourLevel(111,0.1767189);
   _reco_per_true->SetContourLevel(112,0.178311);
   _reco_per_true->SetContourLevel(113,0.179903);
   _reco_per_true->SetContourLevel(114,0.1814951);
   _reco_per_true->SetContourLevel(115,0.1830872);
   _reco_per_true->SetContourLevel(116,0.1846792);
   _reco_per_true->SetContourLevel(117,0.1862713);
   _reco_per_true->SetContourLevel(118,0.1878633);
   _reco_per_true->SetContourLevel(119,0.1894554);
   _reco_per_true->SetContourLevel(120,0.1910475);
   _reco_per_true->SetContourLevel(121,0.1926395);
   _reco_per_true->SetContourLevel(122,0.1942316);
   _reco_per_true->SetContourLevel(123,0.1958237);
   _reco_per_true->SetContourLevel(124,0.1974157);
   _reco_per_true->SetContourLevel(125,0.1990078);
   _reco_per_true->SetContourLevel(126,0.2005998);
   _reco_per_true->SetContourLevel(127,0.2021919);
   _reco_per_true->SetContourLevel(128,0.203784);
   _reco_per_true->SetContourLevel(129,0.205376);
   _reco_per_true->SetContourLevel(130,0.2069681);
   _reco_per_true->SetContourLevel(131,0.2085602);
   _reco_per_true->SetContourLevel(132,0.2101522);
   _reco_per_true->SetContourLevel(133,0.2117443);
   _reco_per_true->SetContourLevel(134,0.2133363);
   _reco_per_true->SetContourLevel(135,0.2149284);
   _reco_per_true->SetContourLevel(136,0.2165205);
   _reco_per_true->SetContourLevel(137,0.2181125);
   _reco_per_true->SetContourLevel(138,0.2197046);
   _reco_per_true->SetContourLevel(139,0.2212967);
   _reco_per_true->SetContourLevel(140,0.2228887);
   _reco_per_true->SetContourLevel(141,0.2244808);
   _reco_per_true->SetContourLevel(142,0.2260728);
   _reco_per_true->SetContourLevel(143,0.2276649);
   _reco_per_true->SetContourLevel(144,0.229257);
   _reco_per_true->SetContourLevel(145,0.230849);
   _reco_per_true->SetContourLevel(146,0.2324411);
   _reco_per_true->SetContourLevel(147,0.2340331);
   _reco_per_true->SetContourLevel(148,0.2356252);
   _reco_per_true->SetContourLevel(149,0.2372173);
   _reco_per_true->SetContourLevel(150,0.2388093);
   _reco_per_true->SetContourLevel(151,0.2404014);
   _reco_per_true->SetContourLevel(152,0.2419935);
   _reco_per_true->SetContourLevel(153,0.2435855);
   _reco_per_true->SetContourLevel(154,0.2451776);
   _reco_per_true->SetContourLevel(155,0.2467696);
   _reco_per_true->SetContourLevel(156,0.2483617);
   _reco_per_true->SetContourLevel(157,0.2499538);
   _reco_per_true->SetContourLevel(158,0.2515458);
   _reco_per_true->SetContourLevel(159,0.2531379);
   _reco_per_true->SetContourLevel(160,0.25473);
   _reco_per_true->SetContourLevel(161,0.256322);
   _reco_per_true->SetContourLevel(162,0.2579141);
   _reco_per_true->SetContourLevel(163,0.2595061);
   _reco_per_true->SetContourLevel(164,0.2610982);
   _reco_per_true->SetContourLevel(165,0.2626903);
   _reco_per_true->SetContourLevel(166,0.2642823);
   _reco_per_true->SetContourLevel(167,0.2658744);
   _reco_per_true->SetContourLevel(168,0.2674665);
   _reco_per_true->SetContourLevel(169,0.2690585);
   _reco_per_true->SetContourLevel(170,0.2706506);
   _reco_per_true->SetContourLevel(171,0.2722426);
   _reco_per_true->SetContourLevel(172,0.2738347);
   _reco_per_true->SetContourLevel(173,0.2754268);
   _reco_per_true->SetContourLevel(174,0.2770188);
   _reco_per_true->SetContourLevel(175,0.2786109);
   _reco_per_true->SetContourLevel(176,0.280203);
   _reco_per_true->SetContourLevel(177,0.281795);
   _reco_per_true->SetContourLevel(178,0.2833871);
   _reco_per_true->SetContourLevel(179,0.2849791);
   _reco_per_true->SetContourLevel(180,0.2865712);
   _reco_per_true->SetContourLevel(181,0.2881633);
   _reco_per_true->SetContourLevel(182,0.2897553);
   _reco_per_true->SetContourLevel(183,0.2913474);
   _reco_per_true->SetContourLevel(184,0.2929395);
   _reco_per_true->SetContourLevel(185,0.2945315);
   _reco_per_true->SetContourLevel(186,0.2961236);
   _reco_per_true->SetContourLevel(187,0.2977156);
   _reco_per_true->SetContourLevel(188,0.2993077);
   _reco_per_true->SetContourLevel(189,0.3008998);
   _reco_per_true->SetContourLevel(190,0.3024918);
   _reco_per_true->SetContourLevel(191,0.3040839);
   _reco_per_true->SetContourLevel(192,0.305676);
   _reco_per_true->SetContourLevel(193,0.307268);
   _reco_per_true->SetContourLevel(194,0.3088601);
   _reco_per_true->SetContourLevel(195,0.3104521);
   _reco_per_true->SetContourLevel(196,0.3120442);
   _reco_per_true->SetContourLevel(197,0.3136363);
   _reco_per_true->SetContourLevel(198,0.3152283);
   _reco_per_true->SetContourLevel(199,0.3168204);
   _reco_per_true->SetContourLevel(200,0.3184124);
   _reco_per_true->SetContourLevel(201,0.3200045);
   _reco_per_true->SetContourLevel(202,0.3215966);
   _reco_per_true->SetContourLevel(203,0.3231886);
   _reco_per_true->SetContourLevel(204,0.3247807);
   _reco_per_true->SetContourLevel(205,0.3263728);
   _reco_per_true->SetContourLevel(206,0.3279648);
   _reco_per_true->SetContourLevel(207,0.3295569);
   _reco_per_true->SetContourLevel(208,0.3311489);
   _reco_per_true->SetContourLevel(209,0.332741);
   _reco_per_true->SetContourLevel(210,0.3343331);
   _reco_per_true->SetContourLevel(211,0.3359251);
   _reco_per_true->SetContourLevel(212,0.3375172);
   _reco_per_true->SetContourLevel(213,0.3391093);
   _reco_per_true->SetContourLevel(214,0.3407013);
   _reco_per_true->SetContourLevel(215,0.3422934);
   _reco_per_true->SetContourLevel(216,0.3438854);
   _reco_per_true->SetContourLevel(217,0.3454775);
   _reco_per_true->SetContourLevel(218,0.3470696);
   _reco_per_true->SetContourLevel(219,0.3486616);
   _reco_per_true->SetContourLevel(220,0.3502537);
   _reco_per_true->SetContourLevel(221,0.3518458);
   _reco_per_true->SetContourLevel(222,0.3534378);
   _reco_per_true->SetContourLevel(223,0.3550299);
   _reco_per_true->SetContourLevel(224,0.3566219);
   _reco_per_true->SetContourLevel(225,0.358214);
   _reco_per_true->SetContourLevel(226,0.3598061);
   _reco_per_true->SetContourLevel(227,0.3613981);
   _reco_per_true->SetContourLevel(228,0.3629902);
   _reco_per_true->SetContourLevel(229,0.3645823);
   _reco_per_true->SetContourLevel(230,0.3661743);
   _reco_per_true->SetContourLevel(231,0.3677664);
   _reco_per_true->SetContourLevel(232,0.3693584);
   _reco_per_true->SetContourLevel(233,0.3709505);
   _reco_per_true->SetContourLevel(234,0.3725426);
   _reco_per_true->SetContourLevel(235,0.3741346);
   _reco_per_true->SetContourLevel(236,0.3757267);
   _reco_per_true->SetContourLevel(237,0.3773188);
   _reco_per_true->SetContourLevel(238,0.3789108);
   _reco_per_true->SetContourLevel(239,0.3805029);
   _reco_per_true->SetContourLevel(240,0.3820949);
   _reco_per_true->SetContourLevel(241,0.383687);
   _reco_per_true->SetContourLevel(242,0.3852791);
   _reco_per_true->SetContourLevel(243,0.3868711);
   _reco_per_true->SetContourLevel(244,0.3884632);
   _reco_per_true->SetContourLevel(245,0.3900552);
   _reco_per_true->SetContourLevel(246,0.3916473);
   _reco_per_true->SetContourLevel(247,0.3932394);
   _reco_per_true->SetContourLevel(248,0.3948314);
   _reco_per_true->SetContourLevel(249,0.3964235);
   _reco_per_true->SetContourLevel(250,0.3980156);
   _reco_per_true->SetContourLevel(251,0.3996076);
   _reco_per_true->SetContourLevel(252,0.4011997);
   _reco_per_true->SetContourLevel(253,0.4027917);
   _reco_per_true->SetContourLevel(254,0.4043838);
   
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
   TText *AText = pt->AddText("True Bin 1");
   pt->Draw();
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}

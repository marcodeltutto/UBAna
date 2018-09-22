void smearing_matrix_true_22()
{
//=========Macro generated from canvas: c1_n23/c1_n23
//=========  (Sat Sep 22 12:03:57 2018) by ROOT version6.06/06
   TCanvas *c1_n23 = new TCanvas("c1_n23", "c1_n23",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n23->SetHighLightColor(2);
   c1_n23->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n23->SetFillColor(10);
   c1_n23->SetBorderMode(0);
   c1_n23->SetBorderSize(2);
   c1_n23->SetFrameLineWidth(2);
   c1_n23->SetFrameBorderMode(0);
   c1_n23->SetFrameLineWidth(2);
   c1_n23->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 22", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx683[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy683[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx683,Graph_fy683);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph683 = new TH1F("Graph_Graph683","Graph",100,-1.1,0);
   Graph_Graph683->SetMinimum(0);
   Graph_Graph683->SetMaximum(0.33);
   Graph_Graph683->SetDirectory(0);
   Graph_Graph683->SetStats(0);
   Graph_Graph683->SetLineWidth(2);
   Graph_Graph683->GetXaxis()->SetNdivisions(506);
   Graph_Graph683->GetXaxis()->SetLabelFont(42);
   Graph_Graph683->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph683->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph683->GetXaxis()->SetTitleFont(42);
   Graph_Graph683->GetYaxis()->SetNdivisions(506);
   Graph_Graph683->GetYaxis()->SetLabelFont(42);
   Graph_Graph683->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph683->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph683->GetYaxis()->SetTitleFont(42);
   Graph_Graph683->GetZaxis()->SetNdivisions(506);
   Graph_Graph683->GetZaxis()->SetLabelFont(42);
   Graph_Graph683->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph683->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph683->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph683);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx684[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy684[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx684,Graph_fy684);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph684 = new TH1F("Graph_Graph684","Graph",100,0,0.297);
   Graph_Graph684->SetMinimum(0);
   Graph_Graph684->SetMaximum(0.33);
   Graph_Graph684->SetDirectory(0);
   Graph_Graph684->SetStats(0);
   Graph_Graph684->SetLineWidth(2);
   Graph_Graph684->GetXaxis()->SetNdivisions(506);
   Graph_Graph684->GetXaxis()->SetLabelFont(42);
   Graph_Graph684->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph684->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph684->GetXaxis()->SetTitleFont(42);
   Graph_Graph684->GetYaxis()->SetNdivisions(506);
   Graph_Graph684->GetYaxis()->SetLabelFont(42);
   Graph_Graph684->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph684->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph684->GetYaxis()->SetTitleFont(42);
   Graph_Graph684->GetZaxis()->SetNdivisions(506);
   Graph_Graph684->GetZaxis()->SetLabelFont(42);
   Graph_Graph684->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph684->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph684->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph684);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx685[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy685[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx685,Graph_fy685);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph685 = new TH1F("Graph_Graph685","Graph",100,0.252,0.468);
   Graph_Graph685->SetMinimum(0);
   Graph_Graph685->SetMaximum(0.33);
   Graph_Graph685->SetDirectory(0);
   Graph_Graph685->SetStats(0);
   Graph_Graph685->SetLineWidth(2);
   Graph_Graph685->GetXaxis()->SetNdivisions(506);
   Graph_Graph685->GetXaxis()->SetLabelFont(42);
   Graph_Graph685->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph685->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph685->GetXaxis()->SetTitleFont(42);
   Graph_Graph685->GetYaxis()->SetNdivisions(506);
   Graph_Graph685->GetYaxis()->SetLabelFont(42);
   Graph_Graph685->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph685->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph685->GetYaxis()->SetTitleFont(42);
   Graph_Graph685->GetZaxis()->SetNdivisions(506);
   Graph_Graph685->GetZaxis()->SetLabelFont(42);
   Graph_Graph685->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph685->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph685->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph685);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx686[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy686[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx686,Graph_fy686);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph686 = new TH1F("Graph_Graph686","Graph",100,0.433,0.637);
   Graph_Graph686->SetMinimum(0);
   Graph_Graph686->SetMaximum(0.33);
   Graph_Graph686->SetDirectory(0);
   Graph_Graph686->SetStats(0);
   Graph_Graph686->SetLineWidth(2);
   Graph_Graph686->GetXaxis()->SetNdivisions(506);
   Graph_Graph686->GetXaxis()->SetLabelFont(42);
   Graph_Graph686->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph686->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph686->GetXaxis()->SetTitleFont(42);
   Graph_Graph686->GetYaxis()->SetNdivisions(506);
   Graph_Graph686->GetYaxis()->SetLabelFont(42);
   Graph_Graph686->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph686->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph686->GetYaxis()->SetTitleFont(42);
   Graph_Graph686->GetZaxis()->SetNdivisions(506);
   Graph_Graph686->GetZaxis()->SetLabelFont(42);
   Graph_Graph686->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph686->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph686->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph686);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx687[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy687[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx687,Graph_fy687);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph687 = new TH1F("Graph_Graph687","Graph",100,0.606,0.774);
   Graph_Graph687->SetMinimum(0);
   Graph_Graph687->SetMaximum(0.33);
   Graph_Graph687->SetDirectory(0);
   Graph_Graph687->SetStats(0);
   Graph_Graph687->SetLineWidth(2);
   Graph_Graph687->GetXaxis()->SetNdivisions(506);
   Graph_Graph687->GetXaxis()->SetLabelFont(42);
   Graph_Graph687->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph687->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph687->GetXaxis()->SetTitleFont(42);
   Graph_Graph687->GetYaxis()->SetNdivisions(506);
   Graph_Graph687->GetYaxis()->SetLabelFont(42);
   Graph_Graph687->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph687->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph687->GetYaxis()->SetTitleFont(42);
   Graph_Graph687->GetZaxis()->SetNdivisions(506);
   Graph_Graph687->GetZaxis()->SetLabelFont(42);
   Graph_Graph687->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph687->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph687->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph687);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx688[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy688[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx688,Graph_fy688);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph688 = new TH1F("Graph_Graph688","Graph",100,0.75,0.87);
   Graph_Graph688->SetMinimum(0);
   Graph_Graph688->SetMaximum(0.33);
   Graph_Graph688->SetDirectory(0);
   Graph_Graph688->SetStats(0);
   Graph_Graph688->SetLineWidth(2);
   Graph_Graph688->GetXaxis()->SetNdivisions(506);
   Graph_Graph688->GetXaxis()->SetLabelFont(42);
   Graph_Graph688->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph688->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph688->GetXaxis()->SetTitleFont(42);
   Graph_Graph688->GetYaxis()->SetNdivisions(506);
   Graph_Graph688->GetYaxis()->SetLabelFont(42);
   Graph_Graph688->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph688->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph688->GetYaxis()->SetTitleFont(42);
   Graph_Graph688->GetZaxis()->SetNdivisions(506);
   Graph_Graph688->GetZaxis()->SetLabelFont(42);
   Graph_Graph688->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph688->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph688->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph688);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx689[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy689[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx689,Graph_fy689);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph689 = new TH1F("Graph_Graph689","Graph",100,0.852,0.948);
   Graph_Graph689->SetMinimum(0);
   Graph_Graph689->SetMaximum(0.33);
   Graph_Graph689->SetDirectory(0);
   Graph_Graph689->SetStats(0);
   Graph_Graph689->SetLineWidth(2);
   Graph_Graph689->GetXaxis()->SetNdivisions(506);
   Graph_Graph689->GetXaxis()->SetLabelFont(42);
   Graph_Graph689->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph689->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph689->GetXaxis()->SetTitleFont(42);
   Graph_Graph689->GetYaxis()->SetNdivisions(506);
   Graph_Graph689->GetYaxis()->SetLabelFont(42);
   Graph_Graph689->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph689->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph689->GetYaxis()->SetTitleFont(42);
   Graph_Graph689->GetZaxis()->SetNdivisions(506);
   Graph_Graph689->GetZaxis()->SetLabelFont(42);
   Graph_Graph689->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph689->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph689->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph689);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx690[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy690[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx690,Graph_fy690);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph690 = new TH1F("Graph_Graph690","Graph",100,0.934,1.006);
   Graph_Graph690->SetMinimum(0);
   Graph_Graph690->SetMaximum(0.33);
   Graph_Graph690->SetDirectory(0);
   Graph_Graph690->SetStats(0);
   Graph_Graph690->SetLineWidth(2);
   Graph_Graph690->GetXaxis()->SetNdivisions(506);
   Graph_Graph690->GetXaxis()->SetLabelFont(42);
   Graph_Graph690->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph690->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph690->GetXaxis()->SetTitleFont(42);
   Graph_Graph690->GetYaxis()->SetNdivisions(506);
   Graph_Graph690->GetYaxis()->SetLabelFont(42);
   Graph_Graph690->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph690->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph690->GetYaxis()->SetTitleFont(42);
   Graph_Graph690->GetZaxis()->SetNdivisions(506);
   Graph_Graph690->GetZaxis()->SetLabelFont(42);
   Graph_Graph690->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph690->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph690->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph690);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx691[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy691[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx691,Graph_fy691);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph691 = new TH1F("Graph_Graph691","Graph",100,-1.1,0);
   Graph_Graph691->SetMinimum(0.285);
   Graph_Graph691->SetMaximum(0.465);
   Graph_Graph691->SetDirectory(0);
   Graph_Graph691->SetStats(0);
   Graph_Graph691->SetLineWidth(2);
   Graph_Graph691->GetXaxis()->SetNdivisions(506);
   Graph_Graph691->GetXaxis()->SetLabelFont(42);
   Graph_Graph691->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph691->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph691->GetXaxis()->SetTitleFont(42);
   Graph_Graph691->GetYaxis()->SetNdivisions(506);
   Graph_Graph691->GetYaxis()->SetLabelFont(42);
   Graph_Graph691->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph691->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph691->GetYaxis()->SetTitleFont(42);
   Graph_Graph691->GetZaxis()->SetNdivisions(506);
   Graph_Graph691->GetZaxis()->SetLabelFont(42);
   Graph_Graph691->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph691->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph691->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph691);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx692[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy692[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx692,Graph_fy692);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph692 = new TH1F("Graph_Graph692","Graph",100,0,0.297);
   Graph_Graph692->SetMinimum(0.285);
   Graph_Graph692->SetMaximum(0.465);
   Graph_Graph692->SetDirectory(0);
   Graph_Graph692->SetStats(0);
   Graph_Graph692->SetLineWidth(2);
   Graph_Graph692->GetXaxis()->SetNdivisions(506);
   Graph_Graph692->GetXaxis()->SetLabelFont(42);
   Graph_Graph692->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph692->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph692->GetXaxis()->SetTitleFont(42);
   Graph_Graph692->GetYaxis()->SetNdivisions(506);
   Graph_Graph692->GetYaxis()->SetLabelFont(42);
   Graph_Graph692->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph692->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph692->GetYaxis()->SetTitleFont(42);
   Graph_Graph692->GetZaxis()->SetNdivisions(506);
   Graph_Graph692->GetZaxis()->SetLabelFont(42);
   Graph_Graph692->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph692->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph692->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph692);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx693[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy693[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx693,Graph_fy693);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph693 = new TH1F("Graph_Graph693","Graph",100,0.252,0.468);
   Graph_Graph693->SetMinimum(0.285);
   Graph_Graph693->SetMaximum(0.465);
   Graph_Graph693->SetDirectory(0);
   Graph_Graph693->SetStats(0);
   Graph_Graph693->SetLineWidth(2);
   Graph_Graph693->GetXaxis()->SetNdivisions(506);
   Graph_Graph693->GetXaxis()->SetLabelFont(42);
   Graph_Graph693->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph693->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph693->GetXaxis()->SetTitleFont(42);
   Graph_Graph693->GetYaxis()->SetNdivisions(506);
   Graph_Graph693->GetYaxis()->SetLabelFont(42);
   Graph_Graph693->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph693->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph693->GetYaxis()->SetTitleFont(42);
   Graph_Graph693->GetZaxis()->SetNdivisions(506);
   Graph_Graph693->GetZaxis()->SetLabelFont(42);
   Graph_Graph693->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph693->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph693->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph693);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx694[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy694[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx694,Graph_fy694);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph694 = new TH1F("Graph_Graph694","Graph",100,0.433,0.637);
   Graph_Graph694->SetMinimum(0.285);
   Graph_Graph694->SetMaximum(0.465);
   Graph_Graph694->SetDirectory(0);
   Graph_Graph694->SetStats(0);
   Graph_Graph694->SetLineWidth(2);
   Graph_Graph694->GetXaxis()->SetNdivisions(506);
   Graph_Graph694->GetXaxis()->SetLabelFont(42);
   Graph_Graph694->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph694->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph694->GetXaxis()->SetTitleFont(42);
   Graph_Graph694->GetYaxis()->SetNdivisions(506);
   Graph_Graph694->GetYaxis()->SetLabelFont(42);
   Graph_Graph694->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph694->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph694->GetYaxis()->SetTitleFont(42);
   Graph_Graph694->GetZaxis()->SetNdivisions(506);
   Graph_Graph694->GetZaxis()->SetLabelFont(42);
   Graph_Graph694->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph694->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph694->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph694);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx695[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy695[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx695,Graph_fy695);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph695 = new TH1F("Graph_Graph695","Graph",100,0.606,0.774);
   Graph_Graph695->SetMinimum(0.285);
   Graph_Graph695->SetMaximum(0.465);
   Graph_Graph695->SetDirectory(0);
   Graph_Graph695->SetStats(0);
   Graph_Graph695->SetLineWidth(2);
   Graph_Graph695->GetXaxis()->SetNdivisions(506);
   Graph_Graph695->GetXaxis()->SetLabelFont(42);
   Graph_Graph695->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph695->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph695->GetXaxis()->SetTitleFont(42);
   Graph_Graph695->GetYaxis()->SetNdivisions(506);
   Graph_Graph695->GetYaxis()->SetLabelFont(42);
   Graph_Graph695->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph695->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph695->GetYaxis()->SetTitleFont(42);
   Graph_Graph695->GetZaxis()->SetNdivisions(506);
   Graph_Graph695->GetZaxis()->SetLabelFont(42);
   Graph_Graph695->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph695->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph695->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph695);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx696[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy696[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx696,Graph_fy696);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001a92");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph696 = new TH1F("Graph_Graph696","Graph",100,0.75,0.87);
   Graph_Graph696->SetMinimum(0.285);
   Graph_Graph696->SetMaximum(0.465);
   Graph_Graph696->SetDirectory(0);
   Graph_Graph696->SetStats(0);
   Graph_Graph696->SetLineWidth(2);
   Graph_Graph696->GetXaxis()->SetNdivisions(506);
   Graph_Graph696->GetXaxis()->SetLabelFont(42);
   Graph_Graph696->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph696->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph696->GetXaxis()->SetTitleFont(42);
   Graph_Graph696->GetYaxis()->SetNdivisions(506);
   Graph_Graph696->GetYaxis()->SetLabelFont(42);
   Graph_Graph696->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph696->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph696->GetYaxis()->SetTitleFont(42);
   Graph_Graph696->GetZaxis()->SetNdivisions(506);
   Graph_Graph696->GetZaxis()->SetLabelFont(42);
   Graph_Graph696->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph696->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph696->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph696);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx697[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy697[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx697,Graph_fy697);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#004cb0");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph697 = new TH1F("Graph_Graph697","Graph",100,0.852,0.948);
   Graph_Graph697->SetMinimum(0.285);
   Graph_Graph697->SetMaximum(0.465);
   Graph_Graph697->SetDirectory(0);
   Graph_Graph697->SetStats(0);
   Graph_Graph697->SetLineWidth(2);
   Graph_Graph697->GetXaxis()->SetNdivisions(506);
   Graph_Graph697->GetXaxis()->SetLabelFont(42);
   Graph_Graph697->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph697->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph697->GetXaxis()->SetTitleFont(42);
   Graph_Graph697->GetYaxis()->SetNdivisions(506);
   Graph_Graph697->GetYaxis()->SetLabelFont(42);
   Graph_Graph697->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph697->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph697->GetYaxis()->SetTitleFont(42);
   Graph_Graph697->GetZaxis()->SetNdivisions(506);
   Graph_Graph697->GetZaxis()->SetLabelFont(42);
   Graph_Graph697->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph697->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph697->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph697);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx698[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy698[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx698,Graph_fy698);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00138d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph698 = new TH1F("Graph_Graph698","Graph",100,0.934,1.006);
   Graph_Graph698->SetMinimum(0.285);
   Graph_Graph698->SetMaximum(0.465);
   Graph_Graph698->SetDirectory(0);
   Graph_Graph698->SetStats(0);
   Graph_Graph698->SetLineWidth(2);
   Graph_Graph698->GetXaxis()->SetNdivisions(506);
   Graph_Graph698->GetXaxis()->SetLabelFont(42);
   Graph_Graph698->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph698->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph698->GetXaxis()->SetTitleFont(42);
   Graph_Graph698->GetYaxis()->SetNdivisions(506);
   Graph_Graph698->GetYaxis()->SetLabelFont(42);
   Graph_Graph698->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph698->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph698->GetYaxis()->SetTitleFont(42);
   Graph_Graph698->GetZaxis()->SetNdivisions(506);
   Graph_Graph698->GetZaxis()->SetLabelFont(42);
   Graph_Graph698->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph698->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph698->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph698);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx699[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy699[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx699,Graph_fy699);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph699 = new TH1F("Graph_Graph699","Graph",100,-1.1,0);
   Graph_Graph699->SetMinimum(0.245);
   Graph_Graph699->SetMaximum(2.705);
   Graph_Graph699->SetDirectory(0);
   Graph_Graph699->SetStats(0);
   Graph_Graph699->SetLineWidth(2);
   Graph_Graph699->GetXaxis()->SetNdivisions(506);
   Graph_Graph699->GetXaxis()->SetLabelFont(42);
   Graph_Graph699->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph699->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph699->GetXaxis()->SetTitleFont(42);
   Graph_Graph699->GetYaxis()->SetNdivisions(506);
   Graph_Graph699->GetYaxis()->SetLabelFont(42);
   Graph_Graph699->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph699->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph699->GetYaxis()->SetTitleFont(42);
   Graph_Graph699->GetZaxis()->SetNdivisions(506);
   Graph_Graph699->GetZaxis()->SetLabelFont(42);
   Graph_Graph699->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph699->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph699->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph699);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx700[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy700[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx700,Graph_fy700);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph700 = new TH1F("Graph_Graph700","Graph",100,0,0.297);
   Graph_Graph700->SetMinimum(0.418);
   Graph_Graph700->SetMaximum(0.802);
   Graph_Graph700->SetDirectory(0);
   Graph_Graph700->SetStats(0);
   Graph_Graph700->SetLineWidth(2);
   Graph_Graph700->GetXaxis()->SetNdivisions(506);
   Graph_Graph700->GetXaxis()->SetLabelFont(42);
   Graph_Graph700->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph700->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph700->GetXaxis()->SetTitleFont(42);
   Graph_Graph700->GetYaxis()->SetNdivisions(506);
   Graph_Graph700->GetYaxis()->SetLabelFont(42);
   Graph_Graph700->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph700->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph700->GetYaxis()->SetTitleFont(42);
   Graph_Graph700->GetZaxis()->SetNdivisions(506);
   Graph_Graph700->GetZaxis()->SetLabelFont(42);
   Graph_Graph700->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph700->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph700->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph700);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx701[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy701[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx701,Graph_fy701);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph701 = new TH1F("Graph_Graph701","Graph",100,0.252,0.468);
   Graph_Graph701->SetMinimum(0.418);
   Graph_Graph701->SetMaximum(0.802);
   Graph_Graph701->SetDirectory(0);
   Graph_Graph701->SetStats(0);
   Graph_Graph701->SetLineWidth(2);
   Graph_Graph701->GetXaxis()->SetNdivisions(506);
   Graph_Graph701->GetXaxis()->SetLabelFont(42);
   Graph_Graph701->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph701->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph701->GetXaxis()->SetTitleFont(42);
   Graph_Graph701->GetYaxis()->SetNdivisions(506);
   Graph_Graph701->GetYaxis()->SetLabelFont(42);
   Graph_Graph701->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph701->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph701->GetYaxis()->SetTitleFont(42);
   Graph_Graph701->GetZaxis()->SetNdivisions(506);
   Graph_Graph701->GetZaxis()->SetLabelFont(42);
   Graph_Graph701->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph701->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph701->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph701);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx702[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy702[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx702,Graph_fy702);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph702 = new TH1F("Graph_Graph702","Graph",100,0.433,0.637);
   Graph_Graph702->SetMinimum(0.418);
   Graph_Graph702->SetMaximum(0.802);
   Graph_Graph702->SetDirectory(0);
   Graph_Graph702->SetStats(0);
   Graph_Graph702->SetLineWidth(2);
   Graph_Graph702->GetXaxis()->SetNdivisions(506);
   Graph_Graph702->GetXaxis()->SetLabelFont(42);
   Graph_Graph702->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph702->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph702->GetXaxis()->SetTitleFont(42);
   Graph_Graph702->GetYaxis()->SetNdivisions(506);
   Graph_Graph702->GetYaxis()->SetLabelFont(42);
   Graph_Graph702->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph702->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph702->GetYaxis()->SetTitleFont(42);
   Graph_Graph702->GetZaxis()->SetNdivisions(506);
   Graph_Graph702->GetZaxis()->SetLabelFont(42);
   Graph_Graph702->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph702->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph702->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph702);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx703[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy703[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx703,Graph_fy703);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph703 = new TH1F("Graph_Graph703","Graph",100,0.606,0.774);
   Graph_Graph703->SetMinimum(0.418);
   Graph_Graph703->SetMaximum(0.802);
   Graph_Graph703->SetDirectory(0);
   Graph_Graph703->SetStats(0);
   Graph_Graph703->SetLineWidth(2);
   Graph_Graph703->GetXaxis()->SetNdivisions(506);
   Graph_Graph703->GetXaxis()->SetLabelFont(42);
   Graph_Graph703->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph703->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph703->GetXaxis()->SetTitleFont(42);
   Graph_Graph703->GetYaxis()->SetNdivisions(506);
   Graph_Graph703->GetYaxis()->SetLabelFont(42);
   Graph_Graph703->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph703->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph703->GetYaxis()->SetTitleFont(42);
   Graph_Graph703->GetZaxis()->SetNdivisions(506);
   Graph_Graph703->GetZaxis()->SetLabelFont(42);
   Graph_Graph703->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph703->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph703->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph703);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx704[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy704[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx704,Graph_fy704);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#008bd6");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph704 = new TH1F("Graph_Graph704","Graph",100,0.75,0.87);
   Graph_Graph704->SetMinimum(0.418);
   Graph_Graph704->SetMaximum(0.802);
   Graph_Graph704->SetDirectory(0);
   Graph_Graph704->SetStats(0);
   Graph_Graph704->SetLineWidth(2);
   Graph_Graph704->GetXaxis()->SetNdivisions(506);
   Graph_Graph704->GetXaxis()->SetLabelFont(42);
   Graph_Graph704->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph704->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph704->GetXaxis()->SetTitleFont(42);
   Graph_Graph704->GetYaxis()->SetNdivisions(506);
   Graph_Graph704->GetYaxis()->SetLabelFont(42);
   Graph_Graph704->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph704->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph704->GetYaxis()->SetTitleFont(42);
   Graph_Graph704->GetZaxis()->SetNdivisions(506);
   Graph_Graph704->GetZaxis()->SetLabelFont(42);
   Graph_Graph704->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph704->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph704->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph704);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx705[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy705[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx705,Graph_fy705);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph705 = new TH1F("Graph_Graph705","Graph",100,0.852,0.948);
   Graph_Graph705->SetMinimum(0.418);
   Graph_Graph705->SetMaximum(0.802);
   Graph_Graph705->SetDirectory(0);
   Graph_Graph705->SetStats(0);
   Graph_Graph705->SetLineWidth(2);
   Graph_Graph705->GetXaxis()->SetNdivisions(506);
   Graph_Graph705->GetXaxis()->SetLabelFont(42);
   Graph_Graph705->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph705->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph705->GetXaxis()->SetTitleFont(42);
   Graph_Graph705->GetYaxis()->SetNdivisions(506);
   Graph_Graph705->GetYaxis()->SetLabelFont(42);
   Graph_Graph705->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph705->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph705->GetYaxis()->SetTitleFont(42);
   Graph_Graph705->GetZaxis()->SetNdivisions(506);
   Graph_Graph705->GetZaxis()->SetLabelFont(42);
   Graph_Graph705->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph705->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph705->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph705);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx706[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy706[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx706,Graph_fy706);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0067c0");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph706 = new TH1F("Graph_Graph706","Graph",100,0.934,1.006);
   Graph_Graph706->SetMinimum(0.418);
   Graph_Graph706->SetMaximum(0.802);
   Graph_Graph706->SetDirectory(0);
   Graph_Graph706->SetStats(0);
   Graph_Graph706->SetLineWidth(2);
   Graph_Graph706->GetXaxis()->SetNdivisions(506);
   Graph_Graph706->GetXaxis()->SetLabelFont(42);
   Graph_Graph706->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph706->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph706->GetXaxis()->SetTitleFont(42);
   Graph_Graph706->GetYaxis()->SetNdivisions(506);
   Graph_Graph706->GetYaxis()->SetLabelFont(42);
   Graph_Graph706->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph706->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph706->GetYaxis()->SetTitleFont(42);
   Graph_Graph706->GetZaxis()->SetNdivisions(506);
   Graph_Graph706->GetZaxis()->SetLabelFont(42);
   Graph_Graph706->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph706->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph706->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph706);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx707[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy707[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx707,Graph_fy707);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph707 = new TH1F("Graph_Graph707","Graph",100,0,0.297);
   Graph_Graph707->SetMinimum(0.597);
   Graph_Graph707->SetMaximum(2.673);
   Graph_Graph707->SetDirectory(0);
   Graph_Graph707->SetStats(0);
   Graph_Graph707->SetLineWidth(2);
   Graph_Graph707->GetXaxis()->SetNdivisions(506);
   Graph_Graph707->GetXaxis()->SetLabelFont(42);
   Graph_Graph707->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph707->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph707->GetXaxis()->SetTitleFont(42);
   Graph_Graph707->GetYaxis()->SetNdivisions(506);
   Graph_Graph707->GetYaxis()->SetLabelFont(42);
   Graph_Graph707->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph707->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph707->GetYaxis()->SetTitleFont(42);
   Graph_Graph707->GetZaxis()->SetNdivisions(506);
   Graph_Graph707->GetZaxis()->SetLabelFont(42);
   Graph_Graph707->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph707->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph707->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph707);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx708[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy708[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx708,Graph_fy708);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph708 = new TH1F("Graph_Graph708","Graph",100,0.252,0.468);
   Graph_Graph708->SetMinimum(0.597);
   Graph_Graph708->SetMaximum(2.673);
   Graph_Graph708->SetDirectory(0);
   Graph_Graph708->SetStats(0);
   Graph_Graph708->SetLineWidth(2);
   Graph_Graph708->GetXaxis()->SetNdivisions(506);
   Graph_Graph708->GetXaxis()->SetLabelFont(42);
   Graph_Graph708->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph708->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph708->GetXaxis()->SetTitleFont(42);
   Graph_Graph708->GetYaxis()->SetNdivisions(506);
   Graph_Graph708->GetYaxis()->SetLabelFont(42);
   Graph_Graph708->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph708->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph708->GetYaxis()->SetTitleFont(42);
   Graph_Graph708->GetZaxis()->SetNdivisions(506);
   Graph_Graph708->GetZaxis()->SetLabelFont(42);
   Graph_Graph708->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph708->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph708->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph708);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx709[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy709[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx709,Graph_fy709);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph709 = new TH1F("Graph_Graph709","Graph",100,0.433,0.637);
   Graph_Graph709->SetMinimum(0.597);
   Graph_Graph709->SetMaximum(2.673);
   Graph_Graph709->SetDirectory(0);
   Graph_Graph709->SetStats(0);
   Graph_Graph709->SetLineWidth(2);
   Graph_Graph709->GetXaxis()->SetNdivisions(506);
   Graph_Graph709->GetXaxis()->SetLabelFont(42);
   Graph_Graph709->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph709->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph709->GetXaxis()->SetTitleFont(42);
   Graph_Graph709->GetYaxis()->SetNdivisions(506);
   Graph_Graph709->GetYaxis()->SetLabelFont(42);
   Graph_Graph709->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph709->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph709->GetYaxis()->SetTitleFont(42);
   Graph_Graph709->GetZaxis()->SetNdivisions(506);
   Graph_Graph709->GetZaxis()->SetLabelFont(42);
   Graph_Graph709->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph709->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph709->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph709);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx710[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy710[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx710,Graph_fy710);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph710 = new TH1F("Graph_Graph710","Graph",100,0.606,0.774);
   Graph_Graph710->SetMinimum(0.597);
   Graph_Graph710->SetMaximum(2.673);
   Graph_Graph710->SetDirectory(0);
   Graph_Graph710->SetStats(0);
   Graph_Graph710->SetLineWidth(2);
   Graph_Graph710->GetXaxis()->SetNdivisions(506);
   Graph_Graph710->GetXaxis()->SetLabelFont(42);
   Graph_Graph710->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph710->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph710->GetXaxis()->SetTitleFont(42);
   Graph_Graph710->GetYaxis()->SetNdivisions(506);
   Graph_Graph710->GetYaxis()->SetLabelFont(42);
   Graph_Graph710->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph710->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph710->GetYaxis()->SetTitleFont(42);
   Graph_Graph710->GetZaxis()->SetNdivisions(506);
   Graph_Graph710->GetZaxis()->SetLabelFont(42);
   Graph_Graph710->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph710->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph710->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph710);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx711[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy711[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx711,Graph_fy711);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001890");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph711 = new TH1F("Graph_Graph711","Graph",100,0.75,0.87);
   Graph_Graph711->SetMinimum(0.597);
   Graph_Graph711->SetMaximum(2.673);
   Graph_Graph711->SetDirectory(0);
   Graph_Graph711->SetStats(0);
   Graph_Graph711->SetLineWidth(2);
   Graph_Graph711->GetXaxis()->SetNdivisions(506);
   Graph_Graph711->GetXaxis()->SetLabelFont(42);
   Graph_Graph711->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph711->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph711->GetXaxis()->SetTitleFont(42);
   Graph_Graph711->GetYaxis()->SetNdivisions(506);
   Graph_Graph711->GetYaxis()->SetLabelFont(42);
   Graph_Graph711->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph711->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph711->GetYaxis()->SetTitleFont(42);
   Graph_Graph711->GetZaxis()->SetNdivisions(506);
   Graph_Graph711->GetZaxis()->SetLabelFont(42);
   Graph_Graph711->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph711->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph711->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph711);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx712[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy712[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx712,Graph_fy712);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0073c7");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph712 = new TH1F("Graph_Graph712","Graph",100,0.852,0.948);
   Graph_Graph712->SetMinimum(0.597);
   Graph_Graph712->SetMaximum(2.673);
   Graph_Graph712->SetDirectory(0);
   Graph_Graph712->SetStats(0);
   Graph_Graph712->SetLineWidth(2);
   Graph_Graph712->GetXaxis()->SetNdivisions(506);
   Graph_Graph712->GetXaxis()->SetLabelFont(42);
   Graph_Graph712->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph712->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph712->GetXaxis()->SetTitleFont(42);
   Graph_Graph712->GetYaxis()->SetNdivisions(506);
   Graph_Graph712->GetYaxis()->SetLabelFont(42);
   Graph_Graph712->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph712->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph712->GetYaxis()->SetTitleFont(42);
   Graph_Graph712->GetZaxis()->SetNdivisions(506);
   Graph_Graph712->GetZaxis()->SetLabelFont(42);
   Graph_Graph712->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph712->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph712->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph712);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx713[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy713[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx713,Graph_fy713);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph713 = new TH1F("Graph_Graph713","Graph",100,0.934,1.006);
   Graph_Graph713->SetMinimum(0.597);
   Graph_Graph713->SetMaximum(2.673);
   Graph_Graph713->SetDirectory(0);
   Graph_Graph713->SetStats(0);
   Graph_Graph713->SetLineWidth(2);
   Graph_Graph713->GetXaxis()->SetNdivisions(506);
   Graph_Graph713->GetXaxis()->SetLabelFont(42);
   Graph_Graph713->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph713->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph713->GetXaxis()->SetTitleFont(42);
   Graph_Graph713->GetYaxis()->SetNdivisions(506);
   Graph_Graph713->GetYaxis()->SetLabelFont(42);
   Graph_Graph713->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph713->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph713->GetYaxis()->SetTitleFont(42);
   Graph_Graph713->GetZaxis()->SetNdivisions(506);
   Graph_Graph713->GetZaxis()->SetLabelFont(42);
   Graph_Graph713->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph713->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph713->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph713);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.001464946);
   _reco_per_true->SetBinContent(3,0.001464288);
   _reco_per_true->SetBinContent(7,0.008817254);
   _reco_per_true->SetBinContent(9,0.001469586);
   _reco_per_true->SetBinContent(11,0.001464288);
   _reco_per_true->SetBinContent(13,0.001464691);
   _reco_per_true->SetBinContent(14,0.02337582);
   _reco_per_true->SetBinContent(15,0.0660187);
   _reco_per_true->SetBinContent(16,0.01759786);
   _reco_per_true->SetBinContent(17,0.007319598);
   _reco_per_true->SetBinContent(19,0.001464691);
   _reco_per_true->SetBinContent(22,0.1198826);
   _reco_per_true->SetBinContent(23,0.5238141);
   _reco_per_true->SetBinContent(24,0.08941109);
   _reco_per_true->SetBinContent(25,0.002929121);
   _reco_per_true->SetBinContent(27,0.001471333);
   _reco_per_true->SetBinContent(29,0.02054541);
   _reco_per_true->SetBinContent(30,0.09973871);
   _reco_per_true->SetBinContent(31,0.01028592);
   _reco_per_true->SetBinError(1,0.001464946);
   _reco_per_true->SetBinError(3,0.001464288);
   _reco_per_true->SetBinError(7,0.003599636);
   _reco_per_true->SetBinError(9,0.001469586);
   _reco_per_true->SetBinError(11,0.001464288);
   _reco_per_true->SetBinError(13,0.001464691);
   _reco_per_true->SetBinError(14,0.005844588);
   _reco_per_true->SetBinError(15,0.009841513);
   _reco_per_true->SetBinError(16,0.005080075);
   _reco_per_true->SetBinError(17,0.003273429);
   _reco_per_true->SetBinError(19,0.001464691);
   _reco_per_true->SetBinError(22,0.01323982);
   _reco_per_true->SetBinError(23,0.02768706);
   _reco_per_true->SetBinError(24,0.01144799);
   _reco_per_true->SetBinError(25,0.002071201);
   _reco_per_true->SetBinError(27,0.001471333);
   _reco_per_true->SetBinError(29,0.005491007);
   _reco_per_true->SetBinError(30,0.01209516);
   _reco_per_true->SetBinError(31,0.003887722);
   _reco_per_true->SetEntries(683);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.002054173);
   _reco_per_true->SetContourLevel(2,0.004108346);
   _reco_per_true->SetContourLevel(3,0.006162519);
   _reco_per_true->SetContourLevel(4,0.008216692);
   _reco_per_true->SetContourLevel(5,0.01027086);
   _reco_per_true->SetContourLevel(6,0.01232504);
   _reco_per_true->SetContourLevel(7,0.01437921);
   _reco_per_true->SetContourLevel(8,0.01643338);
   _reco_per_true->SetContourLevel(9,0.01848756);
   _reco_per_true->SetContourLevel(10,0.02054173);
   _reco_per_true->SetContourLevel(11,0.0225959);
   _reco_per_true->SetContourLevel(12,0.02465008);
   _reco_per_true->SetContourLevel(13,0.02670425);
   _reco_per_true->SetContourLevel(14,0.02875842);
   _reco_per_true->SetContourLevel(15,0.03081259);
   _reco_per_true->SetContourLevel(16,0.03286677);
   _reco_per_true->SetContourLevel(17,0.03492094);
   _reco_per_true->SetContourLevel(18,0.03697511);
   _reco_per_true->SetContourLevel(19,0.03902929);
   _reco_per_true->SetContourLevel(20,0.04108346);
   _reco_per_true->SetContourLevel(21,0.04313763);
   _reco_per_true->SetContourLevel(22,0.04519181);
   _reco_per_true->SetContourLevel(23,0.04724598);
   _reco_per_true->SetContourLevel(24,0.04930015);
   _reco_per_true->SetContourLevel(25,0.05135432);
   _reco_per_true->SetContourLevel(26,0.0534085);
   _reco_per_true->SetContourLevel(27,0.05546267);
   _reco_per_true->SetContourLevel(28,0.05751684);
   _reco_per_true->SetContourLevel(29,0.05957102);
   _reco_per_true->SetContourLevel(30,0.06162519);
   _reco_per_true->SetContourLevel(31,0.06367936);
   _reco_per_true->SetContourLevel(32,0.06573353);
   _reco_per_true->SetContourLevel(33,0.06778771);
   _reco_per_true->SetContourLevel(34,0.06984188);
   _reco_per_true->SetContourLevel(35,0.07189605);
   _reco_per_true->SetContourLevel(36,0.07395023);
   _reco_per_true->SetContourLevel(37,0.0760044);
   _reco_per_true->SetContourLevel(38,0.07805857);
   _reco_per_true->SetContourLevel(39,0.08011275);
   _reco_per_true->SetContourLevel(40,0.08216692);
   _reco_per_true->SetContourLevel(41,0.08422109);
   _reco_per_true->SetContourLevel(42,0.08627526);
   _reco_per_true->SetContourLevel(43,0.08832944);
   _reco_per_true->SetContourLevel(44,0.09038361);
   _reco_per_true->SetContourLevel(45,0.09243778);
   _reco_per_true->SetContourLevel(46,0.09449196);
   _reco_per_true->SetContourLevel(47,0.09654613);
   _reco_per_true->SetContourLevel(48,0.0986003);
   _reco_per_true->SetContourLevel(49,0.1006545);
   _reco_per_true->SetContourLevel(50,0.1027086);
   _reco_per_true->SetContourLevel(51,0.1047628);
   _reco_per_true->SetContourLevel(52,0.106817);
   _reco_per_true->SetContourLevel(53,0.1088712);
   _reco_per_true->SetContourLevel(54,0.1109253);
   _reco_per_true->SetContourLevel(55,0.1129795);
   _reco_per_true->SetContourLevel(56,0.1150337);
   _reco_per_true->SetContourLevel(57,0.1170879);
   _reco_per_true->SetContourLevel(58,0.119142);
   _reco_per_true->SetContourLevel(59,0.1211962);
   _reco_per_true->SetContourLevel(60,0.1232504);
   _reco_per_true->SetContourLevel(61,0.1253046);
   _reco_per_true->SetContourLevel(62,0.1273587);
   _reco_per_true->SetContourLevel(63,0.1294129);
   _reco_per_true->SetContourLevel(64,0.1314671);
   _reco_per_true->SetContourLevel(65,0.1335212);
   _reco_per_true->SetContourLevel(66,0.1355754);
   _reco_per_true->SetContourLevel(67,0.1376296);
   _reco_per_true->SetContourLevel(68,0.1396838);
   _reco_per_true->SetContourLevel(69,0.1417379);
   _reco_per_true->SetContourLevel(70,0.1437921);
   _reco_per_true->SetContourLevel(71,0.1458463);
   _reco_per_true->SetContourLevel(72,0.1479005);
   _reco_per_true->SetContourLevel(73,0.1499546);
   _reco_per_true->SetContourLevel(74,0.1520088);
   _reco_per_true->SetContourLevel(75,0.154063);
   _reco_per_true->SetContourLevel(76,0.1561171);
   _reco_per_true->SetContourLevel(77,0.1581713);
   _reco_per_true->SetContourLevel(78,0.1602255);
   _reco_per_true->SetContourLevel(79,0.1622797);
   _reco_per_true->SetContourLevel(80,0.1643338);
   _reco_per_true->SetContourLevel(81,0.166388);
   _reco_per_true->SetContourLevel(82,0.1684422);
   _reco_per_true->SetContourLevel(83,0.1704964);
   _reco_per_true->SetContourLevel(84,0.1725505);
   _reco_per_true->SetContourLevel(85,0.1746047);
   _reco_per_true->SetContourLevel(86,0.1766589);
   _reco_per_true->SetContourLevel(87,0.178713);
   _reco_per_true->SetContourLevel(88,0.1807672);
   _reco_per_true->SetContourLevel(89,0.1828214);
   _reco_per_true->SetContourLevel(90,0.1848756);
   _reco_per_true->SetContourLevel(91,0.1869297);
   _reco_per_true->SetContourLevel(92,0.1889839);
   _reco_per_true->SetContourLevel(93,0.1910381);
   _reco_per_true->SetContourLevel(94,0.1930923);
   _reco_per_true->SetContourLevel(95,0.1951464);
   _reco_per_true->SetContourLevel(96,0.1972006);
   _reco_per_true->SetContourLevel(97,0.1992548);
   _reco_per_true->SetContourLevel(98,0.201309);
   _reco_per_true->SetContourLevel(99,0.2033631);
   _reco_per_true->SetContourLevel(100,0.2054173);
   _reco_per_true->SetContourLevel(101,0.2074715);
   _reco_per_true->SetContourLevel(102,0.2095256);
   _reco_per_true->SetContourLevel(103,0.2115798);
   _reco_per_true->SetContourLevel(104,0.213634);
   _reco_per_true->SetContourLevel(105,0.2156882);
   _reco_per_true->SetContourLevel(106,0.2177423);
   _reco_per_true->SetContourLevel(107,0.2197965);
   _reco_per_true->SetContourLevel(108,0.2218507);
   _reco_per_true->SetContourLevel(109,0.2239049);
   _reco_per_true->SetContourLevel(110,0.225959);
   _reco_per_true->SetContourLevel(111,0.2280132);
   _reco_per_true->SetContourLevel(112,0.2300674);
   _reco_per_true->SetContourLevel(113,0.2321215);
   _reco_per_true->SetContourLevel(114,0.2341757);
   _reco_per_true->SetContourLevel(115,0.2362299);
   _reco_per_true->SetContourLevel(116,0.2382841);
   _reco_per_true->SetContourLevel(117,0.2403382);
   _reco_per_true->SetContourLevel(118,0.2423924);
   _reco_per_true->SetContourLevel(119,0.2444466);
   _reco_per_true->SetContourLevel(120,0.2465008);
   _reco_per_true->SetContourLevel(121,0.2485549);
   _reco_per_true->SetContourLevel(122,0.2506091);
   _reco_per_true->SetContourLevel(123,0.2526633);
   _reco_per_true->SetContourLevel(124,0.2547174);
   _reco_per_true->SetContourLevel(125,0.2567716);
   _reco_per_true->SetContourLevel(126,0.2588258);
   _reco_per_true->SetContourLevel(127,0.26088);
   _reco_per_true->SetContourLevel(128,0.2629341);
   _reco_per_true->SetContourLevel(129,0.2649883);
   _reco_per_true->SetContourLevel(130,0.2670425);
   _reco_per_true->SetContourLevel(131,0.2690967);
   _reco_per_true->SetContourLevel(132,0.2711508);
   _reco_per_true->SetContourLevel(133,0.273205);
   _reco_per_true->SetContourLevel(134,0.2752592);
   _reco_per_true->SetContourLevel(135,0.2773134);
   _reco_per_true->SetContourLevel(136,0.2793675);
   _reco_per_true->SetContourLevel(137,0.2814217);
   _reco_per_true->SetContourLevel(138,0.2834759);
   _reco_per_true->SetContourLevel(139,0.28553);
   _reco_per_true->SetContourLevel(140,0.2875842);
   _reco_per_true->SetContourLevel(141,0.2896384);
   _reco_per_true->SetContourLevel(142,0.2916926);
   _reco_per_true->SetContourLevel(143,0.2937467);
   _reco_per_true->SetContourLevel(144,0.2958009);
   _reco_per_true->SetContourLevel(145,0.2978551);
   _reco_per_true->SetContourLevel(146,0.2999093);
   _reco_per_true->SetContourLevel(147,0.3019634);
   _reco_per_true->SetContourLevel(148,0.3040176);
   _reco_per_true->SetContourLevel(149,0.3060718);
   _reco_per_true->SetContourLevel(150,0.3081259);
   _reco_per_true->SetContourLevel(151,0.3101801);
   _reco_per_true->SetContourLevel(152,0.3122343);
   _reco_per_true->SetContourLevel(153,0.3142885);
   _reco_per_true->SetContourLevel(154,0.3163426);
   _reco_per_true->SetContourLevel(155,0.3183968);
   _reco_per_true->SetContourLevel(156,0.320451);
   _reco_per_true->SetContourLevel(157,0.3225052);
   _reco_per_true->SetContourLevel(158,0.3245593);
   _reco_per_true->SetContourLevel(159,0.3266135);
   _reco_per_true->SetContourLevel(160,0.3286677);
   _reco_per_true->SetContourLevel(161,0.3307218);
   _reco_per_true->SetContourLevel(162,0.332776);
   _reco_per_true->SetContourLevel(163,0.3348302);
   _reco_per_true->SetContourLevel(164,0.3368844);
   _reco_per_true->SetContourLevel(165,0.3389385);
   _reco_per_true->SetContourLevel(166,0.3409927);
   _reco_per_true->SetContourLevel(167,0.3430469);
   _reco_per_true->SetContourLevel(168,0.3451011);
   _reco_per_true->SetContourLevel(169,0.3471552);
   _reco_per_true->SetContourLevel(170,0.3492094);
   _reco_per_true->SetContourLevel(171,0.3512636);
   _reco_per_true->SetContourLevel(172,0.3533177);
   _reco_per_true->SetContourLevel(173,0.3553719);
   _reco_per_true->SetContourLevel(174,0.3574261);
   _reco_per_true->SetContourLevel(175,0.3594803);
   _reco_per_true->SetContourLevel(176,0.3615344);
   _reco_per_true->SetContourLevel(177,0.3635886);
   _reco_per_true->SetContourLevel(178,0.3656428);
   _reco_per_true->SetContourLevel(179,0.367697);
   _reco_per_true->SetContourLevel(180,0.3697511);
   _reco_per_true->SetContourLevel(181,0.3718053);
   _reco_per_true->SetContourLevel(182,0.3738595);
   _reco_per_true->SetContourLevel(183,0.3759137);
   _reco_per_true->SetContourLevel(184,0.3779678);
   _reco_per_true->SetContourLevel(185,0.380022);
   _reco_per_true->SetContourLevel(186,0.3820762);
   _reco_per_true->SetContourLevel(187,0.3841303);
   _reco_per_true->SetContourLevel(188,0.3861845);
   _reco_per_true->SetContourLevel(189,0.3882387);
   _reco_per_true->SetContourLevel(190,0.3902929);
   _reco_per_true->SetContourLevel(191,0.392347);
   _reco_per_true->SetContourLevel(192,0.3944012);
   _reco_per_true->SetContourLevel(193,0.3964554);
   _reco_per_true->SetContourLevel(194,0.3985096);
   _reco_per_true->SetContourLevel(195,0.4005637);
   _reco_per_true->SetContourLevel(196,0.4026179);
   _reco_per_true->SetContourLevel(197,0.4046721);
   _reco_per_true->SetContourLevel(198,0.4067262);
   _reco_per_true->SetContourLevel(199,0.4087804);
   _reco_per_true->SetContourLevel(200,0.4108346);
   _reco_per_true->SetContourLevel(201,0.4128888);
   _reco_per_true->SetContourLevel(202,0.4149429);
   _reco_per_true->SetContourLevel(203,0.4169971);
   _reco_per_true->SetContourLevel(204,0.4190513);
   _reco_per_true->SetContourLevel(205,0.4211055);
   _reco_per_true->SetContourLevel(206,0.4231596);
   _reco_per_true->SetContourLevel(207,0.4252138);
   _reco_per_true->SetContourLevel(208,0.427268);
   _reco_per_true->SetContourLevel(209,0.4293221);
   _reco_per_true->SetContourLevel(210,0.4313763);
   _reco_per_true->SetContourLevel(211,0.4334305);
   _reco_per_true->SetContourLevel(212,0.4354847);
   _reco_per_true->SetContourLevel(213,0.4375388);
   _reco_per_true->SetContourLevel(214,0.439593);
   _reco_per_true->SetContourLevel(215,0.4416472);
   _reco_per_true->SetContourLevel(216,0.4437014);
   _reco_per_true->SetContourLevel(217,0.4457555);
   _reco_per_true->SetContourLevel(218,0.4478097);
   _reco_per_true->SetContourLevel(219,0.4498639);
   _reco_per_true->SetContourLevel(220,0.4519181);
   _reco_per_true->SetContourLevel(221,0.4539722);
   _reco_per_true->SetContourLevel(222,0.4560264);
   _reco_per_true->SetContourLevel(223,0.4580806);
   _reco_per_true->SetContourLevel(224,0.4601347);
   _reco_per_true->SetContourLevel(225,0.4621889);
   _reco_per_true->SetContourLevel(226,0.4642431);
   _reco_per_true->SetContourLevel(227,0.4662973);
   _reco_per_true->SetContourLevel(228,0.4683514);
   _reco_per_true->SetContourLevel(229,0.4704056);
   _reco_per_true->SetContourLevel(230,0.4724598);
   _reco_per_true->SetContourLevel(231,0.474514);
   _reco_per_true->SetContourLevel(232,0.4765681);
   _reco_per_true->SetContourLevel(233,0.4786223);
   _reco_per_true->SetContourLevel(234,0.4806765);
   _reco_per_true->SetContourLevel(235,0.4827306);
   _reco_per_true->SetContourLevel(236,0.4847848);
   _reco_per_true->SetContourLevel(237,0.486839);
   _reco_per_true->SetContourLevel(238,0.4888932);
   _reco_per_true->SetContourLevel(239,0.4909473);
   _reco_per_true->SetContourLevel(240,0.4930015);
   _reco_per_true->SetContourLevel(241,0.4950557);
   _reco_per_true->SetContourLevel(242,0.4971099);
   _reco_per_true->SetContourLevel(243,0.499164);
   _reco_per_true->SetContourLevel(244,0.5012182);
   _reco_per_true->SetContourLevel(245,0.5032724);
   _reco_per_true->SetContourLevel(246,0.5053265);
   _reco_per_true->SetContourLevel(247,0.5073807);
   _reco_per_true->SetContourLevel(248,0.5094349);
   _reco_per_true->SetContourLevel(249,0.5114891);
   _reco_per_true->SetContourLevel(250,0.5135432);
   _reco_per_true->SetContourLevel(251,0.5155974);
   _reco_per_true->SetContourLevel(252,0.5176516);
   _reco_per_true->SetContourLevel(253,0.5197058);
   _reco_per_true->SetContourLevel(254,0.5217599);
   
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
   TText *AText = pt->AddText("True Bin 22");
   pt->Draw();
   c1_n23->Modified();
   c1_n23->cd();
   c1_n23->SetSelected(c1_n23);
}

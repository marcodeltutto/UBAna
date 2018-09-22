void smearing_matrix_true_27()
{
//=========Macro generated from canvas: c1_n28/c1_n28
//=========  (Sat Sep 22 12:03:58 2018) by ROOT version6.06/06
   TCanvas *c1_n28 = new TCanvas("c1_n28", "c1_n28",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n28->SetHighLightColor(2);
   c1_n28->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n28->SetFillColor(10);
   c1_n28->SetBorderMode(0);
   c1_n28->SetBorderSize(2);
   c1_n28->SetFrameLineWidth(2);
   c1_n28->SetFrameBorderMode(0);
   c1_n28->SetFrameLineWidth(2);
   c1_n28->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 27", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx838[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy838[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx838,Graph_fy838);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph838 = new TH1F("Graph_Graph838","Graph",100,-1.1,0);
   Graph_Graph838->SetMinimum(0);
   Graph_Graph838->SetMaximum(0.33);
   Graph_Graph838->SetDirectory(0);
   Graph_Graph838->SetStats(0);
   Graph_Graph838->SetLineWidth(2);
   Graph_Graph838->GetXaxis()->SetNdivisions(506);
   Graph_Graph838->GetXaxis()->SetLabelFont(42);
   Graph_Graph838->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph838->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph838->GetXaxis()->SetTitleFont(42);
   Graph_Graph838->GetYaxis()->SetNdivisions(506);
   Graph_Graph838->GetYaxis()->SetLabelFont(42);
   Graph_Graph838->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph838->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph838->GetYaxis()->SetTitleFont(42);
   Graph_Graph838->GetZaxis()->SetNdivisions(506);
   Graph_Graph838->GetZaxis()->SetLabelFont(42);
   Graph_Graph838->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph838->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph838->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph838);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx839[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy839[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx839,Graph_fy839);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph839 = new TH1F("Graph_Graph839","Graph",100,0,0.297);
   Graph_Graph839->SetMinimum(0);
   Graph_Graph839->SetMaximum(0.33);
   Graph_Graph839->SetDirectory(0);
   Graph_Graph839->SetStats(0);
   Graph_Graph839->SetLineWidth(2);
   Graph_Graph839->GetXaxis()->SetNdivisions(506);
   Graph_Graph839->GetXaxis()->SetLabelFont(42);
   Graph_Graph839->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph839->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph839->GetXaxis()->SetTitleFont(42);
   Graph_Graph839->GetYaxis()->SetNdivisions(506);
   Graph_Graph839->GetYaxis()->SetLabelFont(42);
   Graph_Graph839->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph839->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph839->GetYaxis()->SetTitleFont(42);
   Graph_Graph839->GetZaxis()->SetNdivisions(506);
   Graph_Graph839->GetZaxis()->SetLabelFont(42);
   Graph_Graph839->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph839->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph839->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph839);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx840[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy840[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx840,Graph_fy840);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph840 = new TH1F("Graph_Graph840","Graph",100,0.252,0.468);
   Graph_Graph840->SetMinimum(0);
   Graph_Graph840->SetMaximum(0.33);
   Graph_Graph840->SetDirectory(0);
   Graph_Graph840->SetStats(0);
   Graph_Graph840->SetLineWidth(2);
   Graph_Graph840->GetXaxis()->SetNdivisions(506);
   Graph_Graph840->GetXaxis()->SetLabelFont(42);
   Graph_Graph840->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph840->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph840->GetXaxis()->SetTitleFont(42);
   Graph_Graph840->GetYaxis()->SetNdivisions(506);
   Graph_Graph840->GetYaxis()->SetLabelFont(42);
   Graph_Graph840->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph840->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph840->GetYaxis()->SetTitleFont(42);
   Graph_Graph840->GetZaxis()->SetNdivisions(506);
   Graph_Graph840->GetZaxis()->SetLabelFont(42);
   Graph_Graph840->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph840->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph840->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph840);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx841[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy841[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx841,Graph_fy841);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph841 = new TH1F("Graph_Graph841","Graph",100,0.433,0.637);
   Graph_Graph841->SetMinimum(0);
   Graph_Graph841->SetMaximum(0.33);
   Graph_Graph841->SetDirectory(0);
   Graph_Graph841->SetStats(0);
   Graph_Graph841->SetLineWidth(2);
   Graph_Graph841->GetXaxis()->SetNdivisions(506);
   Graph_Graph841->GetXaxis()->SetLabelFont(42);
   Graph_Graph841->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph841->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph841->GetXaxis()->SetTitleFont(42);
   Graph_Graph841->GetYaxis()->SetNdivisions(506);
   Graph_Graph841->GetYaxis()->SetLabelFont(42);
   Graph_Graph841->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph841->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph841->GetYaxis()->SetTitleFont(42);
   Graph_Graph841->GetZaxis()->SetNdivisions(506);
   Graph_Graph841->GetZaxis()->SetLabelFont(42);
   Graph_Graph841->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph841->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph841->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph841);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx842[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy842[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx842,Graph_fy842);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph842 = new TH1F("Graph_Graph842","Graph",100,0.606,0.774);
   Graph_Graph842->SetMinimum(0);
   Graph_Graph842->SetMaximum(0.33);
   Graph_Graph842->SetDirectory(0);
   Graph_Graph842->SetStats(0);
   Graph_Graph842->SetLineWidth(2);
   Graph_Graph842->GetXaxis()->SetNdivisions(506);
   Graph_Graph842->GetXaxis()->SetLabelFont(42);
   Graph_Graph842->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph842->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph842->GetXaxis()->SetTitleFont(42);
   Graph_Graph842->GetYaxis()->SetNdivisions(506);
   Graph_Graph842->GetYaxis()->SetLabelFont(42);
   Graph_Graph842->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph842->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph842->GetYaxis()->SetTitleFont(42);
   Graph_Graph842->GetZaxis()->SetNdivisions(506);
   Graph_Graph842->GetZaxis()->SetLabelFont(42);
   Graph_Graph842->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph842->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph842->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph842);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx843[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy843[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx843,Graph_fy843);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph843 = new TH1F("Graph_Graph843","Graph",100,0.75,0.87);
   Graph_Graph843->SetMinimum(0);
   Graph_Graph843->SetMaximum(0.33);
   Graph_Graph843->SetDirectory(0);
   Graph_Graph843->SetStats(0);
   Graph_Graph843->SetLineWidth(2);
   Graph_Graph843->GetXaxis()->SetNdivisions(506);
   Graph_Graph843->GetXaxis()->SetLabelFont(42);
   Graph_Graph843->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph843->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph843->GetXaxis()->SetTitleFont(42);
   Graph_Graph843->GetYaxis()->SetNdivisions(506);
   Graph_Graph843->GetYaxis()->SetLabelFont(42);
   Graph_Graph843->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph843->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph843->GetYaxis()->SetTitleFont(42);
   Graph_Graph843->GetZaxis()->SetNdivisions(506);
   Graph_Graph843->GetZaxis()->SetLabelFont(42);
   Graph_Graph843->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph843->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph843->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph843);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx844[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy844[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx844,Graph_fy844);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph844 = new TH1F("Graph_Graph844","Graph",100,0.852,0.948);
   Graph_Graph844->SetMinimum(0);
   Graph_Graph844->SetMaximum(0.33);
   Graph_Graph844->SetDirectory(0);
   Graph_Graph844->SetStats(0);
   Graph_Graph844->SetLineWidth(2);
   Graph_Graph844->GetXaxis()->SetNdivisions(506);
   Graph_Graph844->GetXaxis()->SetLabelFont(42);
   Graph_Graph844->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph844->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph844->GetXaxis()->SetTitleFont(42);
   Graph_Graph844->GetYaxis()->SetNdivisions(506);
   Graph_Graph844->GetYaxis()->SetLabelFont(42);
   Graph_Graph844->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph844->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph844->GetYaxis()->SetTitleFont(42);
   Graph_Graph844->GetZaxis()->SetNdivisions(506);
   Graph_Graph844->GetZaxis()->SetLabelFont(42);
   Graph_Graph844->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph844->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph844->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph844);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx845[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy845[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx845,Graph_fy845);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph845 = new TH1F("Graph_Graph845","Graph",100,0.934,1.006);
   Graph_Graph845->SetMinimum(0);
   Graph_Graph845->SetMaximum(0.33);
   Graph_Graph845->SetDirectory(0);
   Graph_Graph845->SetStats(0);
   Graph_Graph845->SetLineWidth(2);
   Graph_Graph845->GetXaxis()->SetNdivisions(506);
   Graph_Graph845->GetXaxis()->SetLabelFont(42);
   Graph_Graph845->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph845->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph845->GetXaxis()->SetTitleFont(42);
   Graph_Graph845->GetYaxis()->SetNdivisions(506);
   Graph_Graph845->GetYaxis()->SetLabelFont(42);
   Graph_Graph845->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph845->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph845->GetYaxis()->SetTitleFont(42);
   Graph_Graph845->GetZaxis()->SetNdivisions(506);
   Graph_Graph845->GetZaxis()->SetLabelFont(42);
   Graph_Graph845->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph845->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph845->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph845);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx846[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy846[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx846,Graph_fy846);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph846 = new TH1F("Graph_Graph846","Graph",100,-1.1,0);
   Graph_Graph846->SetMinimum(0.285);
   Graph_Graph846->SetMaximum(0.465);
   Graph_Graph846->SetDirectory(0);
   Graph_Graph846->SetStats(0);
   Graph_Graph846->SetLineWidth(2);
   Graph_Graph846->GetXaxis()->SetNdivisions(506);
   Graph_Graph846->GetXaxis()->SetLabelFont(42);
   Graph_Graph846->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph846->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph846->GetXaxis()->SetTitleFont(42);
   Graph_Graph846->GetYaxis()->SetNdivisions(506);
   Graph_Graph846->GetYaxis()->SetLabelFont(42);
   Graph_Graph846->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph846->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph846->GetYaxis()->SetTitleFont(42);
   Graph_Graph846->GetZaxis()->SetNdivisions(506);
   Graph_Graph846->GetZaxis()->SetLabelFont(42);
   Graph_Graph846->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph846->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph846->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph846);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx847[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy847[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx847,Graph_fy847);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph847 = new TH1F("Graph_Graph847","Graph",100,0,0.297);
   Graph_Graph847->SetMinimum(0.285);
   Graph_Graph847->SetMaximum(0.465);
   Graph_Graph847->SetDirectory(0);
   Graph_Graph847->SetStats(0);
   Graph_Graph847->SetLineWidth(2);
   Graph_Graph847->GetXaxis()->SetNdivisions(506);
   Graph_Graph847->GetXaxis()->SetLabelFont(42);
   Graph_Graph847->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph847->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph847->GetXaxis()->SetTitleFont(42);
   Graph_Graph847->GetYaxis()->SetNdivisions(506);
   Graph_Graph847->GetYaxis()->SetLabelFont(42);
   Graph_Graph847->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph847->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph847->GetYaxis()->SetTitleFont(42);
   Graph_Graph847->GetZaxis()->SetNdivisions(506);
   Graph_Graph847->GetZaxis()->SetLabelFont(42);
   Graph_Graph847->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph847->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph847->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph847);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx848[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy848[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx848,Graph_fy848);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph848 = new TH1F("Graph_Graph848","Graph",100,0.252,0.468);
   Graph_Graph848->SetMinimum(0.285);
   Graph_Graph848->SetMaximum(0.465);
   Graph_Graph848->SetDirectory(0);
   Graph_Graph848->SetStats(0);
   Graph_Graph848->SetLineWidth(2);
   Graph_Graph848->GetXaxis()->SetNdivisions(506);
   Graph_Graph848->GetXaxis()->SetLabelFont(42);
   Graph_Graph848->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph848->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph848->GetXaxis()->SetTitleFont(42);
   Graph_Graph848->GetYaxis()->SetNdivisions(506);
   Graph_Graph848->GetYaxis()->SetLabelFont(42);
   Graph_Graph848->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph848->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph848->GetYaxis()->SetTitleFont(42);
   Graph_Graph848->GetZaxis()->SetNdivisions(506);
   Graph_Graph848->GetZaxis()->SetLabelFont(42);
   Graph_Graph848->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph848->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph848->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph848);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx849[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy849[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx849,Graph_fy849);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph849 = new TH1F("Graph_Graph849","Graph",100,0.433,0.637);
   Graph_Graph849->SetMinimum(0.285);
   Graph_Graph849->SetMaximum(0.465);
   Graph_Graph849->SetDirectory(0);
   Graph_Graph849->SetStats(0);
   Graph_Graph849->SetLineWidth(2);
   Graph_Graph849->GetXaxis()->SetNdivisions(506);
   Graph_Graph849->GetXaxis()->SetLabelFont(42);
   Graph_Graph849->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph849->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph849->GetXaxis()->SetTitleFont(42);
   Graph_Graph849->GetYaxis()->SetNdivisions(506);
   Graph_Graph849->GetYaxis()->SetLabelFont(42);
   Graph_Graph849->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph849->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph849->GetYaxis()->SetTitleFont(42);
   Graph_Graph849->GetZaxis()->SetNdivisions(506);
   Graph_Graph849->GetZaxis()->SetLabelFont(42);
   Graph_Graph849->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph849->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph849->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph849);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx850[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy850[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx850,Graph_fy850);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00108c");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph850 = new TH1F("Graph_Graph850","Graph",100,0.606,0.774);
   Graph_Graph850->SetMinimum(0.285);
   Graph_Graph850->SetMaximum(0.465);
   Graph_Graph850->SetDirectory(0);
   Graph_Graph850->SetStats(0);
   Graph_Graph850->SetLineWidth(2);
   Graph_Graph850->GetXaxis()->SetNdivisions(506);
   Graph_Graph850->GetXaxis()->SetLabelFont(42);
   Graph_Graph850->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph850->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph850->GetXaxis()->SetTitleFont(42);
   Graph_Graph850->GetYaxis()->SetNdivisions(506);
   Graph_Graph850->GetYaxis()->SetLabelFont(42);
   Graph_Graph850->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph850->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph850->GetYaxis()->SetTitleFont(42);
   Graph_Graph850->GetZaxis()->SetNdivisions(506);
   Graph_Graph850->GetZaxis()->SetLabelFont(42);
   Graph_Graph850->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph850->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph850->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph850);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx851[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy851[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx851,Graph_fy851);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph851 = new TH1F("Graph_Graph851","Graph",100,0.75,0.87);
   Graph_Graph851->SetMinimum(0.285);
   Graph_Graph851->SetMaximum(0.465);
   Graph_Graph851->SetDirectory(0);
   Graph_Graph851->SetStats(0);
   Graph_Graph851->SetLineWidth(2);
   Graph_Graph851->GetXaxis()->SetNdivisions(506);
   Graph_Graph851->GetXaxis()->SetLabelFont(42);
   Graph_Graph851->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph851->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph851->GetXaxis()->SetTitleFont(42);
   Graph_Graph851->GetYaxis()->SetNdivisions(506);
   Graph_Graph851->GetYaxis()->SetLabelFont(42);
   Graph_Graph851->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph851->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph851->GetYaxis()->SetTitleFont(42);
   Graph_Graph851->GetZaxis()->SetNdivisions(506);
   Graph_Graph851->GetZaxis()->SetLabelFont(42);
   Graph_Graph851->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph851->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph851->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph851);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx852[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy852[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx852,Graph_fy852);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph852 = new TH1F("Graph_Graph852","Graph",100,0.852,0.948);
   Graph_Graph852->SetMinimum(0.285);
   Graph_Graph852->SetMaximum(0.465);
   Graph_Graph852->SetDirectory(0);
   Graph_Graph852->SetStats(0);
   Graph_Graph852->SetLineWidth(2);
   Graph_Graph852->GetXaxis()->SetNdivisions(506);
   Graph_Graph852->GetXaxis()->SetLabelFont(42);
   Graph_Graph852->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph852->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph852->GetXaxis()->SetTitleFont(42);
   Graph_Graph852->GetYaxis()->SetNdivisions(506);
   Graph_Graph852->GetYaxis()->SetLabelFont(42);
   Graph_Graph852->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph852->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph852->GetYaxis()->SetTitleFont(42);
   Graph_Graph852->GetZaxis()->SetNdivisions(506);
   Graph_Graph852->GetZaxis()->SetLabelFont(42);
   Graph_Graph852->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph852->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph852->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph852);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx853[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy853[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx853,Graph_fy853);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph853 = new TH1F("Graph_Graph853","Graph",100,0.934,1.006);
   Graph_Graph853->SetMinimum(0.285);
   Graph_Graph853->SetMaximum(0.465);
   Graph_Graph853->SetDirectory(0);
   Graph_Graph853->SetStats(0);
   Graph_Graph853->SetLineWidth(2);
   Graph_Graph853->GetXaxis()->SetNdivisions(506);
   Graph_Graph853->GetXaxis()->SetLabelFont(42);
   Graph_Graph853->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph853->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph853->GetXaxis()->SetTitleFont(42);
   Graph_Graph853->GetYaxis()->SetNdivisions(506);
   Graph_Graph853->GetYaxis()->SetLabelFont(42);
   Graph_Graph853->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph853->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph853->GetYaxis()->SetTitleFont(42);
   Graph_Graph853->GetZaxis()->SetNdivisions(506);
   Graph_Graph853->GetZaxis()->SetLabelFont(42);
   Graph_Graph853->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph853->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph853->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph853);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx854[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy854[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx854,Graph_fy854);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph854 = new TH1F("Graph_Graph854","Graph",100,-1.1,0);
   Graph_Graph854->SetMinimum(0.245);
   Graph_Graph854->SetMaximum(2.705);
   Graph_Graph854->SetDirectory(0);
   Graph_Graph854->SetStats(0);
   Graph_Graph854->SetLineWidth(2);
   Graph_Graph854->GetXaxis()->SetNdivisions(506);
   Graph_Graph854->GetXaxis()->SetLabelFont(42);
   Graph_Graph854->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph854->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph854->GetXaxis()->SetTitleFont(42);
   Graph_Graph854->GetYaxis()->SetNdivisions(506);
   Graph_Graph854->GetYaxis()->SetLabelFont(42);
   Graph_Graph854->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph854->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph854->GetYaxis()->SetTitleFont(42);
   Graph_Graph854->GetZaxis()->SetNdivisions(506);
   Graph_Graph854->GetZaxis()->SetLabelFont(42);
   Graph_Graph854->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph854->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph854->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph854);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx855[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy855[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx855,Graph_fy855);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph855 = new TH1F("Graph_Graph855","Graph",100,0,0.297);
   Graph_Graph855->SetMinimum(0.418);
   Graph_Graph855->SetMaximum(0.802);
   Graph_Graph855->SetDirectory(0);
   Graph_Graph855->SetStats(0);
   Graph_Graph855->SetLineWidth(2);
   Graph_Graph855->GetXaxis()->SetNdivisions(506);
   Graph_Graph855->GetXaxis()->SetLabelFont(42);
   Graph_Graph855->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph855->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph855->GetXaxis()->SetTitleFont(42);
   Graph_Graph855->GetYaxis()->SetNdivisions(506);
   Graph_Graph855->GetYaxis()->SetLabelFont(42);
   Graph_Graph855->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph855->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph855->GetYaxis()->SetTitleFont(42);
   Graph_Graph855->GetZaxis()->SetNdivisions(506);
   Graph_Graph855->GetZaxis()->SetLabelFont(42);
   Graph_Graph855->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph855->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph855->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph855);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx856[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy856[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx856,Graph_fy856);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph856 = new TH1F("Graph_Graph856","Graph",100,0.252,0.468);
   Graph_Graph856->SetMinimum(0.418);
   Graph_Graph856->SetMaximum(0.802);
   Graph_Graph856->SetDirectory(0);
   Graph_Graph856->SetStats(0);
   Graph_Graph856->SetLineWidth(2);
   Graph_Graph856->GetXaxis()->SetNdivisions(506);
   Graph_Graph856->GetXaxis()->SetLabelFont(42);
   Graph_Graph856->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph856->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph856->GetXaxis()->SetTitleFont(42);
   Graph_Graph856->GetYaxis()->SetNdivisions(506);
   Graph_Graph856->GetYaxis()->SetLabelFont(42);
   Graph_Graph856->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph856->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph856->GetYaxis()->SetTitleFont(42);
   Graph_Graph856->GetZaxis()->SetNdivisions(506);
   Graph_Graph856->GetZaxis()->SetLabelFont(42);
   Graph_Graph856->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph856->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph856->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph856);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx857[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy857[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx857,Graph_fy857);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#002196");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph857 = new TH1F("Graph_Graph857","Graph",100,0.433,0.637);
   Graph_Graph857->SetMinimum(0.418);
   Graph_Graph857->SetMaximum(0.802);
   Graph_Graph857->SetDirectory(0);
   Graph_Graph857->SetStats(0);
   Graph_Graph857->SetLineWidth(2);
   Graph_Graph857->GetXaxis()->SetNdivisions(506);
   Graph_Graph857->GetXaxis()->SetLabelFont(42);
   Graph_Graph857->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph857->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph857->GetXaxis()->SetTitleFont(42);
   Graph_Graph857->GetYaxis()->SetNdivisions(506);
   Graph_Graph857->GetYaxis()->SetLabelFont(42);
   Graph_Graph857->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph857->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph857->GetYaxis()->SetTitleFont(42);
   Graph_Graph857->GetZaxis()->SetNdivisions(506);
   Graph_Graph857->GetZaxis()->SetLabelFont(42);
   Graph_Graph857->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph857->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph857->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph857);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx858[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy858[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx858,Graph_fy858);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#3ddbc1");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph858 = new TH1F("Graph_Graph858","Graph",100,0.606,0.774);
   Graph_Graph858->SetMinimum(0.418);
   Graph_Graph858->SetMaximum(0.802);
   Graph_Graph858->SetDirectory(0);
   Graph_Graph858->SetStats(0);
   Graph_Graph858->SetLineWidth(2);
   Graph_Graph858->GetXaxis()->SetNdivisions(506);
   Graph_Graph858->GetXaxis()->SetLabelFont(42);
   Graph_Graph858->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph858->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph858->GetXaxis()->SetTitleFont(42);
   Graph_Graph858->GetYaxis()->SetNdivisions(506);
   Graph_Graph858->GetYaxis()->SetLabelFont(42);
   Graph_Graph858->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph858->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph858->GetYaxis()->SetTitleFont(42);
   Graph_Graph858->GetZaxis()->SetNdivisions(506);
   Graph_Graph858->GetZaxis()->SetLabelFont(42);
   Graph_Graph858->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph858->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph858->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph858);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx859[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy859[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx859,Graph_fy859);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0043aa");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph859 = new TH1F("Graph_Graph859","Graph",100,0.75,0.87);
   Graph_Graph859->SetMinimum(0.418);
   Graph_Graph859->SetMaximum(0.802);
   Graph_Graph859->SetDirectory(0);
   Graph_Graph859->SetStats(0);
   Graph_Graph859->SetLineWidth(2);
   Graph_Graph859->GetXaxis()->SetNdivisions(506);
   Graph_Graph859->GetXaxis()->SetLabelFont(42);
   Graph_Graph859->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph859->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph859->GetXaxis()->SetTitleFont(42);
   Graph_Graph859->GetYaxis()->SetNdivisions(506);
   Graph_Graph859->GetYaxis()->SetLabelFont(42);
   Graph_Graph859->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph859->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph859->GetYaxis()->SetTitleFont(42);
   Graph_Graph859->GetZaxis()->SetNdivisions(506);
   Graph_Graph859->GetZaxis()->SetLabelFont(42);
   Graph_Graph859->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph859->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph859->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph859);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx860[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy860[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx860,Graph_fy860);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph860 = new TH1F("Graph_Graph860","Graph",100,0.852,0.948);
   Graph_Graph860->SetMinimum(0.418);
   Graph_Graph860->SetMaximum(0.802);
   Graph_Graph860->SetDirectory(0);
   Graph_Graph860->SetStats(0);
   Graph_Graph860->SetLineWidth(2);
   Graph_Graph860->GetXaxis()->SetNdivisions(506);
   Graph_Graph860->GetXaxis()->SetLabelFont(42);
   Graph_Graph860->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph860->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph860->GetXaxis()->SetTitleFont(42);
   Graph_Graph860->GetYaxis()->SetNdivisions(506);
   Graph_Graph860->GetYaxis()->SetLabelFont(42);
   Graph_Graph860->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph860->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph860->GetYaxis()->SetTitleFont(42);
   Graph_Graph860->GetZaxis()->SetNdivisions(506);
   Graph_Graph860->GetZaxis()->SetLabelFont(42);
   Graph_Graph860->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph860->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph860->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph860);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx861[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy861[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx861,Graph_fy861);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph861 = new TH1F("Graph_Graph861","Graph",100,0.934,1.006);
   Graph_Graph861->SetMinimum(0.418);
   Graph_Graph861->SetMaximum(0.802);
   Graph_Graph861->SetDirectory(0);
   Graph_Graph861->SetStats(0);
   Graph_Graph861->SetLineWidth(2);
   Graph_Graph861->GetXaxis()->SetNdivisions(506);
   Graph_Graph861->GetXaxis()->SetLabelFont(42);
   Graph_Graph861->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph861->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph861->GetXaxis()->SetTitleFont(42);
   Graph_Graph861->GetYaxis()->SetNdivisions(506);
   Graph_Graph861->GetYaxis()->SetLabelFont(42);
   Graph_Graph861->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph861->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph861->GetYaxis()->SetTitleFont(42);
   Graph_Graph861->GetZaxis()->SetNdivisions(506);
   Graph_Graph861->GetZaxis()->SetLabelFont(42);
   Graph_Graph861->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph861->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph861->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph861);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx862[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy862[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx862,Graph_fy862);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph862 = new TH1F("Graph_Graph862","Graph",100,0,0.297);
   Graph_Graph862->SetMinimum(0.597);
   Graph_Graph862->SetMaximum(2.673);
   Graph_Graph862->SetDirectory(0);
   Graph_Graph862->SetStats(0);
   Graph_Graph862->SetLineWidth(2);
   Graph_Graph862->GetXaxis()->SetNdivisions(506);
   Graph_Graph862->GetXaxis()->SetLabelFont(42);
   Graph_Graph862->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph862->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph862->GetXaxis()->SetTitleFont(42);
   Graph_Graph862->GetYaxis()->SetNdivisions(506);
   Graph_Graph862->GetYaxis()->SetLabelFont(42);
   Graph_Graph862->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph862->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph862->GetYaxis()->SetTitleFont(42);
   Graph_Graph862->GetZaxis()->SetNdivisions(506);
   Graph_Graph862->GetZaxis()->SetLabelFont(42);
   Graph_Graph862->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph862->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph862->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph862);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx863[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy863[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx863,Graph_fy863);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000786");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph863 = new TH1F("Graph_Graph863","Graph",100,0.252,0.468);
   Graph_Graph863->SetMinimum(0.597);
   Graph_Graph863->SetMaximum(2.673);
   Graph_Graph863->SetDirectory(0);
   Graph_Graph863->SetStats(0);
   Graph_Graph863->SetLineWidth(2);
   Graph_Graph863->GetXaxis()->SetNdivisions(506);
   Graph_Graph863->GetXaxis()->SetLabelFont(42);
   Graph_Graph863->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph863->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph863->GetXaxis()->SetTitleFont(42);
   Graph_Graph863->GetYaxis()->SetNdivisions(506);
   Graph_Graph863->GetYaxis()->SetLabelFont(42);
   Graph_Graph863->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph863->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph863->GetYaxis()->SetTitleFont(42);
   Graph_Graph863->GetZaxis()->SetNdivisions(506);
   Graph_Graph863->GetZaxis()->SetLabelFont(42);
   Graph_Graph863->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph863->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph863->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph863);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx864[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy864[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx864,Graph_fy864);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00289a");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph864 = new TH1F("Graph_Graph864","Graph",100,0.433,0.637);
   Graph_Graph864->SetMinimum(0.597);
   Graph_Graph864->SetMaximum(2.673);
   Graph_Graph864->SetDirectory(0);
   Graph_Graph864->SetStats(0);
   Graph_Graph864->SetLineWidth(2);
   Graph_Graph864->GetXaxis()->SetNdivisions(506);
   Graph_Graph864->GetXaxis()->SetLabelFont(42);
   Graph_Graph864->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph864->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph864->GetXaxis()->SetTitleFont(42);
   Graph_Graph864->GetYaxis()->SetNdivisions(506);
   Graph_Graph864->GetYaxis()->SetLabelFont(42);
   Graph_Graph864->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph864->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph864->GetYaxis()->SetTitleFont(42);
   Graph_Graph864->GetZaxis()->SetNdivisions(506);
   Graph_Graph864->GetZaxis()->SetLabelFont(42);
   Graph_Graph864->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph864->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph864->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph864);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx865[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy865[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx865,Graph_fy865);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph865 = new TH1F("Graph_Graph865","Graph",100,0.606,0.774);
   Graph_Graph865->SetMinimum(0.597);
   Graph_Graph865->SetMaximum(2.673);
   Graph_Graph865->SetDirectory(0);
   Graph_Graph865->SetStats(0);
   Graph_Graph865->SetLineWidth(2);
   Graph_Graph865->GetXaxis()->SetNdivisions(506);
   Graph_Graph865->GetXaxis()->SetLabelFont(42);
   Graph_Graph865->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph865->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph865->GetXaxis()->SetTitleFont(42);
   Graph_Graph865->GetYaxis()->SetNdivisions(506);
   Graph_Graph865->GetYaxis()->SetLabelFont(42);
   Graph_Graph865->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph865->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph865->GetYaxis()->SetTitleFont(42);
   Graph_Graph865->GetZaxis()->SetNdivisions(506);
   Graph_Graph865->GetZaxis()->SetLabelFont(42);
   Graph_Graph865->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph865->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph865->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph865);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx866[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy866[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx866,Graph_fy866);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00acea");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph866 = new TH1F("Graph_Graph866","Graph",100,0.75,0.87);
   Graph_Graph866->SetMinimum(0.597);
   Graph_Graph866->SetMaximum(2.673);
   Graph_Graph866->SetDirectory(0);
   Graph_Graph866->SetStats(0);
   Graph_Graph866->SetLineWidth(2);
   Graph_Graph866->GetXaxis()->SetNdivisions(506);
   Graph_Graph866->GetXaxis()->SetLabelFont(42);
   Graph_Graph866->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph866->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph866->GetXaxis()->SetTitleFont(42);
   Graph_Graph866->GetYaxis()->SetNdivisions(506);
   Graph_Graph866->GetYaxis()->SetLabelFont(42);
   Graph_Graph866->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph866->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph866->GetYaxis()->SetTitleFont(42);
   Graph_Graph866->GetZaxis()->SetNdivisions(506);
   Graph_Graph866->GetZaxis()->SetLabelFont(42);
   Graph_Graph866->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph866->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph866->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph866);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx867[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy867[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx867,Graph_fy867);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph867 = new TH1F("Graph_Graph867","Graph",100,0.852,0.948);
   Graph_Graph867->SetMinimum(0.597);
   Graph_Graph867->SetMaximum(2.673);
   Graph_Graph867->SetDirectory(0);
   Graph_Graph867->SetStats(0);
   Graph_Graph867->SetLineWidth(2);
   Graph_Graph867->GetXaxis()->SetNdivisions(506);
   Graph_Graph867->GetXaxis()->SetLabelFont(42);
   Graph_Graph867->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph867->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph867->GetXaxis()->SetTitleFont(42);
   Graph_Graph867->GetYaxis()->SetNdivisions(506);
   Graph_Graph867->GetYaxis()->SetLabelFont(42);
   Graph_Graph867->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph867->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph867->GetYaxis()->SetTitleFont(42);
   Graph_Graph867->GetZaxis()->SetNdivisions(506);
   Graph_Graph867->GetZaxis()->SetLabelFont(42);
   Graph_Graph867->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph867->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph867->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph867);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx868[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy868[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx868,Graph_fy868);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph868 = new TH1F("Graph_Graph868","Graph",100,0.934,1.006);
   Graph_Graph868->SetMinimum(0.597);
   Graph_Graph868->SetMaximum(2.673);
   Graph_Graph868->SetDirectory(0);
   Graph_Graph868->SetStats(0);
   Graph_Graph868->SetLineWidth(2);
   Graph_Graph868->GetXaxis()->SetNdivisions(506);
   Graph_Graph868->GetXaxis()->SetLabelFont(42);
   Graph_Graph868->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph868->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph868->GetXaxis()->SetTitleFont(42);
   Graph_Graph868->GetYaxis()->SetNdivisions(506);
   Graph_Graph868->GetYaxis()->SetLabelFont(42);
   Graph_Graph868->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph868->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph868->GetYaxis()->SetTitleFont(42);
   Graph_Graph868->GetZaxis()->SetNdivisions(506);
   Graph_Graph868->GetZaxis()->SetLabelFont(42);
   Graph_Graph868->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph868->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph868->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph868);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(2,0.002968877);
   _reco_per_true->SetBinContent(4,0.005992309);
   _reco_per_true->SetBinContent(5,0.002990899);
   _reco_per_true->SetBinContent(6,0.0029932);
   _reco_per_true->SetBinContent(13,0.01459215);
   _reco_per_true->SetBinContent(14,0.002992314);
   _reco_per_true->SetBinContent(16,0.002968877);
   _reco_per_true->SetBinContent(17,0.003000004);
   _reco_per_true->SetBinContent(20,0.02697088);
   _reco_per_true->SetBinContent(21,0.2007277);
   _reco_per_true->SetBinContent(22,0.05388761);
   _reco_per_true->SetBinContent(23,0.002816487);
   _reco_per_true->SetBinContent(24,0.008454959);
   _reco_per_true->SetBinContent(25,0.002989375);
   _reco_per_true->SetBinContent(26,0.006013259);
   _reco_per_true->SetBinContent(27,0.03285941);
   _reco_per_true->SetBinContent(28,0.4865937);
   _reco_per_true->SetBinContent(29,0.1375837);
   _reco_per_true->SetBinContent(31,0.002604275);
   _reco_per_true->SetBinError(2,0.002968877);
   _reco_per_true->SetBinError(4,0.004237213);
   _reco_per_true->SetBinError(5,0.002990899);
   _reco_per_true->SetBinError(6,0.0029932);
   _reco_per_true->SetBinError(13,0.006533503);
   _reco_per_true->SetBinError(14,0.002992314);
   _reco_per_true->SetBinError(16,0.002968877);
   _reco_per_true->SetBinError(17,0.003000004);
   _reco_per_true->SetBinError(20,0.008990372);
   _reco_per_true->SetBinError(21,0.02452317);
   _reco_per_true->SetBinError(22,0.01270162);
   _reco_per_true->SetBinError(23,0.002816487);
   _reco_per_true->SetBinError(24,0.004885395);
   _reco_per_true->SetBinError(25,0.002989375);
   _reco_per_true->SetBinError(26,0.004252016);
   _reco_per_true->SetBinError(27,0.009907734);
   _reco_per_true->SetBinError(28,0.03826911);
   _reco_per_true->SetBinError(29,0.02028767);
   _reco_per_true->SetBinError(31,0.002604275);
   _reco_per_true->SetEntries(334);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.001908211);
   _reco_per_true->SetContourLevel(2,0.003816421);
   _reco_per_true->SetContourLevel(3,0.005724632);
   _reco_per_true->SetContourLevel(4,0.007632842);
   _reco_per_true->SetContourLevel(5,0.009541053);
   _reco_per_true->SetContourLevel(6,0.01144926);
   _reco_per_true->SetContourLevel(7,0.01335747);
   _reco_per_true->SetContourLevel(8,0.01526568);
   _reco_per_true->SetContourLevel(9,0.0171739);
   _reco_per_true->SetContourLevel(10,0.01908211);
   _reco_per_true->SetContourLevel(11,0.02099032);
   _reco_per_true->SetContourLevel(12,0.02289853);
   _reco_per_true->SetContourLevel(13,0.02480674);
   _reco_per_true->SetContourLevel(14,0.02671495);
   _reco_per_true->SetContourLevel(15,0.02862316);
   _reco_per_true->SetContourLevel(16,0.03053137);
   _reco_per_true->SetContourLevel(17,0.03243958);
   _reco_per_true->SetContourLevel(18,0.03434779);
   _reco_per_true->SetContourLevel(19,0.036256);
   _reco_per_true->SetContourLevel(20,0.03816421);
   _reco_per_true->SetContourLevel(21,0.04007242);
   _reco_per_true->SetContourLevel(22,0.04198063);
   _reco_per_true->SetContourLevel(23,0.04388884);
   _reco_per_true->SetContourLevel(24,0.04579705);
   _reco_per_true->SetContourLevel(25,0.04770526);
   _reco_per_true->SetContourLevel(26,0.04961347);
   _reco_per_true->SetContourLevel(27,0.05152169);
   _reco_per_true->SetContourLevel(28,0.0534299);
   _reco_per_true->SetContourLevel(29,0.05533811);
   _reco_per_true->SetContourLevel(30,0.05724632);
   _reco_per_true->SetContourLevel(31,0.05915453);
   _reco_per_true->SetContourLevel(32,0.06106274);
   _reco_per_true->SetContourLevel(33,0.06297095);
   _reco_per_true->SetContourLevel(34,0.06487916);
   _reco_per_true->SetContourLevel(35,0.06678737);
   _reco_per_true->SetContourLevel(36,0.06869558);
   _reco_per_true->SetContourLevel(37,0.07060379);
   _reco_per_true->SetContourLevel(38,0.072512);
   _reco_per_true->SetContourLevel(39,0.07442021);
   _reco_per_true->SetContourLevel(40,0.07632842);
   _reco_per_true->SetContourLevel(41,0.07823663);
   _reco_per_true->SetContourLevel(42,0.08014484);
   _reco_per_true->SetContourLevel(43,0.08205305);
   _reco_per_true->SetContourLevel(44,0.08396126);
   _reco_per_true->SetContourLevel(45,0.08586948);
   _reco_per_true->SetContourLevel(46,0.08777769);
   _reco_per_true->SetContourLevel(47,0.0896859);
   _reco_per_true->SetContourLevel(48,0.09159411);
   _reco_per_true->SetContourLevel(49,0.09350232);
   _reco_per_true->SetContourLevel(50,0.09541053);
   _reco_per_true->SetContourLevel(51,0.09731874);
   _reco_per_true->SetContourLevel(52,0.09922695);
   _reco_per_true->SetContourLevel(53,0.1011352);
   _reco_per_true->SetContourLevel(54,0.1030434);
   _reco_per_true->SetContourLevel(55,0.1049516);
   _reco_per_true->SetContourLevel(56,0.1068598);
   _reco_per_true->SetContourLevel(57,0.108768);
   _reco_per_true->SetContourLevel(58,0.1106762);
   _reco_per_true->SetContourLevel(59,0.1125844);
   _reco_per_true->SetContourLevel(60,0.1144926);
   _reco_per_true->SetContourLevel(61,0.1164008);
   _reco_per_true->SetContourLevel(62,0.1183091);
   _reco_per_true->SetContourLevel(63,0.1202173);
   _reco_per_true->SetContourLevel(64,0.1221255);
   _reco_per_true->SetContourLevel(65,0.1240337);
   _reco_per_true->SetContourLevel(66,0.1259419);
   _reco_per_true->SetContourLevel(67,0.1278501);
   _reco_per_true->SetContourLevel(68,0.1297583);
   _reco_per_true->SetContourLevel(69,0.1316665);
   _reco_per_true->SetContourLevel(70,0.1335747);
   _reco_per_true->SetContourLevel(71,0.135483);
   _reco_per_true->SetContourLevel(72,0.1373912);
   _reco_per_true->SetContourLevel(73,0.1392994);
   _reco_per_true->SetContourLevel(74,0.1412076);
   _reco_per_true->SetContourLevel(75,0.1431158);
   _reco_per_true->SetContourLevel(76,0.145024);
   _reco_per_true->SetContourLevel(77,0.1469322);
   _reco_per_true->SetContourLevel(78,0.1488404);
   _reco_per_true->SetContourLevel(79,0.1507486);
   _reco_per_true->SetContourLevel(80,0.1526568);
   _reco_per_true->SetContourLevel(81,0.1545651);
   _reco_per_true->SetContourLevel(82,0.1564733);
   _reco_per_true->SetContourLevel(83,0.1583815);
   _reco_per_true->SetContourLevel(84,0.1602897);
   _reco_per_true->SetContourLevel(85,0.1621979);
   _reco_per_true->SetContourLevel(86,0.1641061);
   _reco_per_true->SetContourLevel(87,0.1660143);
   _reco_per_true->SetContourLevel(88,0.1679225);
   _reco_per_true->SetContourLevel(89,0.1698307);
   _reco_per_true->SetContourLevel(90,0.171739);
   _reco_per_true->SetContourLevel(91,0.1736472);
   _reco_per_true->SetContourLevel(92,0.1755554);
   _reco_per_true->SetContourLevel(93,0.1774636);
   _reco_per_true->SetContourLevel(94,0.1793718);
   _reco_per_true->SetContourLevel(95,0.18128);
   _reco_per_true->SetContourLevel(96,0.1831882);
   _reco_per_true->SetContourLevel(97,0.1850964);
   _reco_per_true->SetContourLevel(98,0.1870046);
   _reco_per_true->SetContourLevel(99,0.1889128);
   _reco_per_true->SetContourLevel(100,0.1908211);
   _reco_per_true->SetContourLevel(101,0.1927293);
   _reco_per_true->SetContourLevel(102,0.1946375);
   _reco_per_true->SetContourLevel(103,0.1965457);
   _reco_per_true->SetContourLevel(104,0.1984539);
   _reco_per_true->SetContourLevel(105,0.2003621);
   _reco_per_true->SetContourLevel(106,0.2022703);
   _reco_per_true->SetContourLevel(107,0.2041785);
   _reco_per_true->SetContourLevel(108,0.2060867);
   _reco_per_true->SetContourLevel(109,0.207995);
   _reco_per_true->SetContourLevel(110,0.2099032);
   _reco_per_true->SetContourLevel(111,0.2118114);
   _reco_per_true->SetContourLevel(112,0.2137196);
   _reco_per_true->SetContourLevel(113,0.2156278);
   _reco_per_true->SetContourLevel(114,0.217536);
   _reco_per_true->SetContourLevel(115,0.2194442);
   _reco_per_true->SetContourLevel(116,0.2213524);
   _reco_per_true->SetContourLevel(117,0.2232606);
   _reco_per_true->SetContourLevel(118,0.2251688);
   _reco_per_true->SetContourLevel(119,0.2270771);
   _reco_per_true->SetContourLevel(120,0.2289853);
   _reco_per_true->SetContourLevel(121,0.2308935);
   _reco_per_true->SetContourLevel(122,0.2328017);
   _reco_per_true->SetContourLevel(123,0.2347099);
   _reco_per_true->SetContourLevel(124,0.2366181);
   _reco_per_true->SetContourLevel(125,0.2385263);
   _reco_per_true->SetContourLevel(126,0.2404345);
   _reco_per_true->SetContourLevel(127,0.2423427);
   _reco_per_true->SetContourLevel(128,0.244251);
   _reco_per_true->SetContourLevel(129,0.2461592);
   _reco_per_true->SetContourLevel(130,0.2480674);
   _reco_per_true->SetContourLevel(131,0.2499756);
   _reco_per_true->SetContourLevel(132,0.2518838);
   _reco_per_true->SetContourLevel(133,0.253792);
   _reco_per_true->SetContourLevel(134,0.2557002);
   _reco_per_true->SetContourLevel(135,0.2576084);
   _reco_per_true->SetContourLevel(136,0.2595166);
   _reco_per_true->SetContourLevel(137,0.2614248);
   _reco_per_true->SetContourLevel(138,0.2633331);
   _reco_per_true->SetContourLevel(139,0.2652413);
   _reco_per_true->SetContourLevel(140,0.2671495);
   _reco_per_true->SetContourLevel(141,0.2690577);
   _reco_per_true->SetContourLevel(142,0.2709659);
   _reco_per_true->SetContourLevel(143,0.2728741);
   _reco_per_true->SetContourLevel(144,0.2747823);
   _reco_per_true->SetContourLevel(145,0.2766905);
   _reco_per_true->SetContourLevel(146,0.2785987);
   _reco_per_true->SetContourLevel(147,0.280507);
   _reco_per_true->SetContourLevel(148,0.2824152);
   _reco_per_true->SetContourLevel(149,0.2843234);
   _reco_per_true->SetContourLevel(150,0.2862316);
   _reco_per_true->SetContourLevel(151,0.2881398);
   _reco_per_true->SetContourLevel(152,0.290048);
   _reco_per_true->SetContourLevel(153,0.2919562);
   _reco_per_true->SetContourLevel(154,0.2938644);
   _reco_per_true->SetContourLevel(155,0.2957726);
   _reco_per_true->SetContourLevel(156,0.2976808);
   _reco_per_true->SetContourLevel(157,0.2995891);
   _reco_per_true->SetContourLevel(158,0.3014973);
   _reco_per_true->SetContourLevel(159,0.3034055);
   _reco_per_true->SetContourLevel(160,0.3053137);
   _reco_per_true->SetContourLevel(161,0.3072219);
   _reco_per_true->SetContourLevel(162,0.3091301);
   _reco_per_true->SetContourLevel(163,0.3110383);
   _reco_per_true->SetContourLevel(164,0.3129465);
   _reco_per_true->SetContourLevel(165,0.3148547);
   _reco_per_true->SetContourLevel(166,0.316763);
   _reco_per_true->SetContourLevel(167,0.3186712);
   _reco_per_true->SetContourLevel(168,0.3205794);
   _reco_per_true->SetContourLevel(169,0.3224876);
   _reco_per_true->SetContourLevel(170,0.3243958);
   _reco_per_true->SetContourLevel(171,0.326304);
   _reco_per_true->SetContourLevel(172,0.3282122);
   _reco_per_true->SetContourLevel(173,0.3301204);
   _reco_per_true->SetContourLevel(174,0.3320286);
   _reco_per_true->SetContourLevel(175,0.3339368);
   _reco_per_true->SetContourLevel(176,0.3358451);
   _reco_per_true->SetContourLevel(177,0.3377533);
   _reco_per_true->SetContourLevel(178,0.3396615);
   _reco_per_true->SetContourLevel(179,0.3415697);
   _reco_per_true->SetContourLevel(180,0.3434779);
   _reco_per_true->SetContourLevel(181,0.3453861);
   _reco_per_true->SetContourLevel(182,0.3472943);
   _reco_per_true->SetContourLevel(183,0.3492025);
   _reco_per_true->SetContourLevel(184,0.3511107);
   _reco_per_true->SetContourLevel(185,0.353019);
   _reco_per_true->SetContourLevel(186,0.3549272);
   _reco_per_true->SetContourLevel(187,0.3568354);
   _reco_per_true->SetContourLevel(188,0.3587436);
   _reco_per_true->SetContourLevel(189,0.3606518);
   _reco_per_true->SetContourLevel(190,0.36256);
   _reco_per_true->SetContourLevel(191,0.3644682);
   _reco_per_true->SetContourLevel(192,0.3663764);
   _reco_per_true->SetContourLevel(193,0.3682846);
   _reco_per_true->SetContourLevel(194,0.3701928);
   _reco_per_true->SetContourLevel(195,0.3721011);
   _reco_per_true->SetContourLevel(196,0.3740093);
   _reco_per_true->SetContourLevel(197,0.3759175);
   _reco_per_true->SetContourLevel(198,0.3778257);
   _reco_per_true->SetContourLevel(199,0.3797339);
   _reco_per_true->SetContourLevel(200,0.3816421);
   _reco_per_true->SetContourLevel(201,0.3835503);
   _reco_per_true->SetContourLevel(202,0.3854585);
   _reco_per_true->SetContourLevel(203,0.3873667);
   _reco_per_true->SetContourLevel(204,0.389275);
   _reco_per_true->SetContourLevel(205,0.3911832);
   _reco_per_true->SetContourLevel(206,0.3930914);
   _reco_per_true->SetContourLevel(207,0.3949996);
   _reco_per_true->SetContourLevel(208,0.3969078);
   _reco_per_true->SetContourLevel(209,0.398816);
   _reco_per_true->SetContourLevel(210,0.4007242);
   _reco_per_true->SetContourLevel(211,0.4026324);
   _reco_per_true->SetContourLevel(212,0.4045406);
   _reco_per_true->SetContourLevel(213,0.4064489);
   _reco_per_true->SetContourLevel(214,0.4083571);
   _reco_per_true->SetContourLevel(215,0.4102653);
   _reco_per_true->SetContourLevel(216,0.4121735);
   _reco_per_true->SetContourLevel(217,0.4140817);
   _reco_per_true->SetContourLevel(218,0.4159899);
   _reco_per_true->SetContourLevel(219,0.4178981);
   _reco_per_true->SetContourLevel(220,0.4198063);
   _reco_per_true->SetContourLevel(221,0.4217145);
   _reco_per_true->SetContourLevel(222,0.4236227);
   _reco_per_true->SetContourLevel(223,0.425531);
   _reco_per_true->SetContourLevel(224,0.4274392);
   _reco_per_true->SetContourLevel(225,0.4293474);
   _reco_per_true->SetContourLevel(226,0.4312556);
   _reco_per_true->SetContourLevel(227,0.4331638);
   _reco_per_true->SetContourLevel(228,0.435072);
   _reco_per_true->SetContourLevel(229,0.4369802);
   _reco_per_true->SetContourLevel(230,0.4388884);
   _reco_per_true->SetContourLevel(231,0.4407966);
   _reco_per_true->SetContourLevel(232,0.4427049);
   _reco_per_true->SetContourLevel(233,0.4446131);
   _reco_per_true->SetContourLevel(234,0.4465213);
   _reco_per_true->SetContourLevel(235,0.4484295);
   _reco_per_true->SetContourLevel(236,0.4503377);
   _reco_per_true->SetContourLevel(237,0.4522459);
   _reco_per_true->SetContourLevel(238,0.4541541);
   _reco_per_true->SetContourLevel(239,0.4560623);
   _reco_per_true->SetContourLevel(240,0.4579705);
   _reco_per_true->SetContourLevel(241,0.4598787);
   _reco_per_true->SetContourLevel(242,0.461787);
   _reco_per_true->SetContourLevel(243,0.4636952);
   _reco_per_true->SetContourLevel(244,0.4656034);
   _reco_per_true->SetContourLevel(245,0.4675116);
   _reco_per_true->SetContourLevel(246,0.4694198);
   _reco_per_true->SetContourLevel(247,0.471328);
   _reco_per_true->SetContourLevel(248,0.4732362);
   _reco_per_true->SetContourLevel(249,0.4751444);
   _reco_per_true->SetContourLevel(250,0.4770526);
   _reco_per_true->SetContourLevel(251,0.4789609);
   _reco_per_true->SetContourLevel(252,0.4808691);
   _reco_per_true->SetContourLevel(253,0.4827773);
   _reco_per_true->SetContourLevel(254,0.4846855);
   
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
   TText *AText = pt->AddText("True Bin 27");
   pt->Draw();
   c1_n28->Modified();
   c1_n28->cd();
   c1_n28->SetSelected(c1_n28);
}

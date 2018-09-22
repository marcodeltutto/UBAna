void smearing_matrix_true_24()
{
//=========Macro generated from canvas: c1_n25/c1_n25
//=========  (Sat Sep 22 12:03:57 2018) by ROOT version6.06/06
   TCanvas *c1_n25 = new TCanvas("c1_n25", "c1_n25",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n25->SetHighLightColor(2);
   c1_n25->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n25->SetFillColor(10);
   c1_n25->SetBorderMode(0);
   c1_n25->SetBorderSize(2);
   c1_n25->SetFrameLineWidth(2);
   c1_n25->SetFrameBorderMode(0);
   c1_n25->SetFrameLineWidth(2);
   c1_n25->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 24", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx745[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy745[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx745,Graph_fy745);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph745 = new TH1F("Graph_Graph745","Graph",100,-1.1,0);
   Graph_Graph745->SetMinimum(0);
   Graph_Graph745->SetMaximum(0.33);
   Graph_Graph745->SetDirectory(0);
   Graph_Graph745->SetStats(0);
   Graph_Graph745->SetLineWidth(2);
   Graph_Graph745->GetXaxis()->SetNdivisions(506);
   Graph_Graph745->GetXaxis()->SetLabelFont(42);
   Graph_Graph745->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph745->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph745->GetXaxis()->SetTitleFont(42);
   Graph_Graph745->GetYaxis()->SetNdivisions(506);
   Graph_Graph745->GetYaxis()->SetLabelFont(42);
   Graph_Graph745->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph745->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph745->GetYaxis()->SetTitleFont(42);
   Graph_Graph745->GetZaxis()->SetNdivisions(506);
   Graph_Graph745->GetZaxis()->SetLabelFont(42);
   Graph_Graph745->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph745->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph745->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph745);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx746[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy746[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx746,Graph_fy746);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph746 = new TH1F("Graph_Graph746","Graph",100,0,0.297);
   Graph_Graph746->SetMinimum(0);
   Graph_Graph746->SetMaximum(0.33);
   Graph_Graph746->SetDirectory(0);
   Graph_Graph746->SetStats(0);
   Graph_Graph746->SetLineWidth(2);
   Graph_Graph746->GetXaxis()->SetNdivisions(506);
   Graph_Graph746->GetXaxis()->SetLabelFont(42);
   Graph_Graph746->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph746->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph746->GetXaxis()->SetTitleFont(42);
   Graph_Graph746->GetYaxis()->SetNdivisions(506);
   Graph_Graph746->GetYaxis()->SetLabelFont(42);
   Graph_Graph746->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph746->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph746->GetYaxis()->SetTitleFont(42);
   Graph_Graph746->GetZaxis()->SetNdivisions(506);
   Graph_Graph746->GetZaxis()->SetLabelFont(42);
   Graph_Graph746->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph746->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph746->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph746);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx747[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy747[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx747,Graph_fy747);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph747 = new TH1F("Graph_Graph747","Graph",100,0.252,0.468);
   Graph_Graph747->SetMinimum(0);
   Graph_Graph747->SetMaximum(0.33);
   Graph_Graph747->SetDirectory(0);
   Graph_Graph747->SetStats(0);
   Graph_Graph747->SetLineWidth(2);
   Graph_Graph747->GetXaxis()->SetNdivisions(506);
   Graph_Graph747->GetXaxis()->SetLabelFont(42);
   Graph_Graph747->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph747->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph747->GetXaxis()->SetTitleFont(42);
   Graph_Graph747->GetYaxis()->SetNdivisions(506);
   Graph_Graph747->GetYaxis()->SetLabelFont(42);
   Graph_Graph747->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph747->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph747->GetYaxis()->SetTitleFont(42);
   Graph_Graph747->GetZaxis()->SetNdivisions(506);
   Graph_Graph747->GetZaxis()->SetLabelFont(42);
   Graph_Graph747->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph747->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph747->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph747);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx748[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy748[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx748,Graph_fy748);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph748 = new TH1F("Graph_Graph748","Graph",100,0.433,0.637);
   Graph_Graph748->SetMinimum(0);
   Graph_Graph748->SetMaximum(0.33);
   Graph_Graph748->SetDirectory(0);
   Graph_Graph748->SetStats(0);
   Graph_Graph748->SetLineWidth(2);
   Graph_Graph748->GetXaxis()->SetNdivisions(506);
   Graph_Graph748->GetXaxis()->SetLabelFont(42);
   Graph_Graph748->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph748->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph748->GetXaxis()->SetTitleFont(42);
   Graph_Graph748->GetYaxis()->SetNdivisions(506);
   Graph_Graph748->GetYaxis()->SetLabelFont(42);
   Graph_Graph748->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph748->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph748->GetYaxis()->SetTitleFont(42);
   Graph_Graph748->GetZaxis()->SetNdivisions(506);
   Graph_Graph748->GetZaxis()->SetLabelFont(42);
   Graph_Graph748->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph748->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph748->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph748);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx749[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy749[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx749,Graph_fy749);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph749 = new TH1F("Graph_Graph749","Graph",100,0.606,0.774);
   Graph_Graph749->SetMinimum(0);
   Graph_Graph749->SetMaximum(0.33);
   Graph_Graph749->SetDirectory(0);
   Graph_Graph749->SetStats(0);
   Graph_Graph749->SetLineWidth(2);
   Graph_Graph749->GetXaxis()->SetNdivisions(506);
   Graph_Graph749->GetXaxis()->SetLabelFont(42);
   Graph_Graph749->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph749->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph749->GetXaxis()->SetTitleFont(42);
   Graph_Graph749->GetYaxis()->SetNdivisions(506);
   Graph_Graph749->GetYaxis()->SetLabelFont(42);
   Graph_Graph749->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph749->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph749->GetYaxis()->SetTitleFont(42);
   Graph_Graph749->GetZaxis()->SetNdivisions(506);
   Graph_Graph749->GetZaxis()->SetLabelFont(42);
   Graph_Graph749->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph749->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph749->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph749);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx750[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy750[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx750,Graph_fy750);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph750 = new TH1F("Graph_Graph750","Graph",100,0.75,0.87);
   Graph_Graph750->SetMinimum(0);
   Graph_Graph750->SetMaximum(0.33);
   Graph_Graph750->SetDirectory(0);
   Graph_Graph750->SetStats(0);
   Graph_Graph750->SetLineWidth(2);
   Graph_Graph750->GetXaxis()->SetNdivisions(506);
   Graph_Graph750->GetXaxis()->SetLabelFont(42);
   Graph_Graph750->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph750->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph750->GetXaxis()->SetTitleFont(42);
   Graph_Graph750->GetYaxis()->SetNdivisions(506);
   Graph_Graph750->GetYaxis()->SetLabelFont(42);
   Graph_Graph750->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph750->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph750->GetYaxis()->SetTitleFont(42);
   Graph_Graph750->GetZaxis()->SetNdivisions(506);
   Graph_Graph750->GetZaxis()->SetLabelFont(42);
   Graph_Graph750->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph750->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph750->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph750);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx751[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy751[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx751,Graph_fy751);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph751 = new TH1F("Graph_Graph751","Graph",100,0.852,0.948);
   Graph_Graph751->SetMinimum(0);
   Graph_Graph751->SetMaximum(0.33);
   Graph_Graph751->SetDirectory(0);
   Graph_Graph751->SetStats(0);
   Graph_Graph751->SetLineWidth(2);
   Graph_Graph751->GetXaxis()->SetNdivisions(506);
   Graph_Graph751->GetXaxis()->SetLabelFont(42);
   Graph_Graph751->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph751->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph751->GetXaxis()->SetTitleFont(42);
   Graph_Graph751->GetYaxis()->SetNdivisions(506);
   Graph_Graph751->GetYaxis()->SetLabelFont(42);
   Graph_Graph751->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph751->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph751->GetYaxis()->SetTitleFont(42);
   Graph_Graph751->GetZaxis()->SetNdivisions(506);
   Graph_Graph751->GetZaxis()->SetLabelFont(42);
   Graph_Graph751->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph751->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph751->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph751);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx752[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy752[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx752,Graph_fy752);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph752 = new TH1F("Graph_Graph752","Graph",100,0.934,1.006);
   Graph_Graph752->SetMinimum(0);
   Graph_Graph752->SetMaximum(0.33);
   Graph_Graph752->SetDirectory(0);
   Graph_Graph752->SetStats(0);
   Graph_Graph752->SetLineWidth(2);
   Graph_Graph752->GetXaxis()->SetNdivisions(506);
   Graph_Graph752->GetXaxis()->SetLabelFont(42);
   Graph_Graph752->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph752->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph752->GetXaxis()->SetTitleFont(42);
   Graph_Graph752->GetYaxis()->SetNdivisions(506);
   Graph_Graph752->GetYaxis()->SetLabelFont(42);
   Graph_Graph752->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph752->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph752->GetYaxis()->SetTitleFont(42);
   Graph_Graph752->GetZaxis()->SetNdivisions(506);
   Graph_Graph752->GetZaxis()->SetLabelFont(42);
   Graph_Graph752->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph752->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph752->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph752);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx753[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy753[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx753,Graph_fy753);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph753 = new TH1F("Graph_Graph753","Graph",100,-1.1,0);
   Graph_Graph753->SetMinimum(0.285);
   Graph_Graph753->SetMaximum(0.465);
   Graph_Graph753->SetDirectory(0);
   Graph_Graph753->SetStats(0);
   Graph_Graph753->SetLineWidth(2);
   Graph_Graph753->GetXaxis()->SetNdivisions(506);
   Graph_Graph753->GetXaxis()->SetLabelFont(42);
   Graph_Graph753->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph753->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph753->GetXaxis()->SetTitleFont(42);
   Graph_Graph753->GetYaxis()->SetNdivisions(506);
   Graph_Graph753->GetYaxis()->SetLabelFont(42);
   Graph_Graph753->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph753->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph753->GetYaxis()->SetTitleFont(42);
   Graph_Graph753->GetZaxis()->SetNdivisions(506);
   Graph_Graph753->GetZaxis()->SetLabelFont(42);
   Graph_Graph753->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph753->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph753->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph753);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx754[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy754[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx754,Graph_fy754);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph754 = new TH1F("Graph_Graph754","Graph",100,0,0.297);
   Graph_Graph754->SetMinimum(0.285);
   Graph_Graph754->SetMaximum(0.465);
   Graph_Graph754->SetDirectory(0);
   Graph_Graph754->SetStats(0);
   Graph_Graph754->SetLineWidth(2);
   Graph_Graph754->GetXaxis()->SetNdivisions(506);
   Graph_Graph754->GetXaxis()->SetLabelFont(42);
   Graph_Graph754->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph754->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph754->GetXaxis()->SetTitleFont(42);
   Graph_Graph754->GetYaxis()->SetNdivisions(506);
   Graph_Graph754->GetYaxis()->SetLabelFont(42);
   Graph_Graph754->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph754->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph754->GetYaxis()->SetTitleFont(42);
   Graph_Graph754->GetZaxis()->SetNdivisions(506);
   Graph_Graph754->GetZaxis()->SetLabelFont(42);
   Graph_Graph754->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph754->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph754->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph754);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx755[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy755[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx755,Graph_fy755);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph755 = new TH1F("Graph_Graph755","Graph",100,0.252,0.468);
   Graph_Graph755->SetMinimum(0.285);
   Graph_Graph755->SetMaximum(0.465);
   Graph_Graph755->SetDirectory(0);
   Graph_Graph755->SetStats(0);
   Graph_Graph755->SetLineWidth(2);
   Graph_Graph755->GetXaxis()->SetNdivisions(506);
   Graph_Graph755->GetXaxis()->SetLabelFont(42);
   Graph_Graph755->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph755->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph755->GetXaxis()->SetTitleFont(42);
   Graph_Graph755->GetYaxis()->SetNdivisions(506);
   Graph_Graph755->GetYaxis()->SetLabelFont(42);
   Graph_Graph755->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph755->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph755->GetYaxis()->SetTitleFont(42);
   Graph_Graph755->GetZaxis()->SetNdivisions(506);
   Graph_Graph755->GetZaxis()->SetLabelFont(42);
   Graph_Graph755->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph755->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph755->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph755);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx756[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy756[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx756,Graph_fy756);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph756 = new TH1F("Graph_Graph756","Graph",100,0.433,0.637);
   Graph_Graph756->SetMinimum(0.285);
   Graph_Graph756->SetMaximum(0.465);
   Graph_Graph756->SetDirectory(0);
   Graph_Graph756->SetStats(0);
   Graph_Graph756->SetLineWidth(2);
   Graph_Graph756->GetXaxis()->SetNdivisions(506);
   Graph_Graph756->GetXaxis()->SetLabelFont(42);
   Graph_Graph756->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph756->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph756->GetXaxis()->SetTitleFont(42);
   Graph_Graph756->GetYaxis()->SetNdivisions(506);
   Graph_Graph756->GetYaxis()->SetLabelFont(42);
   Graph_Graph756->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph756->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph756->GetYaxis()->SetTitleFont(42);
   Graph_Graph756->GetZaxis()->SetNdivisions(506);
   Graph_Graph756->GetZaxis()->SetLabelFont(42);
   Graph_Graph756->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph756->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph756->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph756);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx757[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy757[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx757,Graph_fy757);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph757 = new TH1F("Graph_Graph757","Graph",100,0.606,0.774);
   Graph_Graph757->SetMinimum(0.285);
   Graph_Graph757->SetMaximum(0.465);
   Graph_Graph757->SetDirectory(0);
   Graph_Graph757->SetStats(0);
   Graph_Graph757->SetLineWidth(2);
   Graph_Graph757->GetXaxis()->SetNdivisions(506);
   Graph_Graph757->GetXaxis()->SetLabelFont(42);
   Graph_Graph757->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph757->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph757->GetXaxis()->SetTitleFont(42);
   Graph_Graph757->GetYaxis()->SetNdivisions(506);
   Graph_Graph757->GetYaxis()->SetLabelFont(42);
   Graph_Graph757->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph757->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph757->GetYaxis()->SetTitleFont(42);
   Graph_Graph757->GetZaxis()->SetNdivisions(506);
   Graph_Graph757->GetZaxis()->SetLabelFont(42);
   Graph_Graph757->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph757->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph757->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph757);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx758[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy758[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx758,Graph_fy758);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph758 = new TH1F("Graph_Graph758","Graph",100,0.75,0.87);
   Graph_Graph758->SetMinimum(0.285);
   Graph_Graph758->SetMaximum(0.465);
   Graph_Graph758->SetDirectory(0);
   Graph_Graph758->SetStats(0);
   Graph_Graph758->SetLineWidth(2);
   Graph_Graph758->GetXaxis()->SetNdivisions(506);
   Graph_Graph758->GetXaxis()->SetLabelFont(42);
   Graph_Graph758->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph758->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph758->GetXaxis()->SetTitleFont(42);
   Graph_Graph758->GetYaxis()->SetNdivisions(506);
   Graph_Graph758->GetYaxis()->SetLabelFont(42);
   Graph_Graph758->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph758->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph758->GetYaxis()->SetTitleFont(42);
   Graph_Graph758->GetZaxis()->SetNdivisions(506);
   Graph_Graph758->GetZaxis()->SetLabelFont(42);
   Graph_Graph758->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph758->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph758->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph758);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx759[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy759[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx759,Graph_fy759);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph759 = new TH1F("Graph_Graph759","Graph",100,0.852,0.948);
   Graph_Graph759->SetMinimum(0.285);
   Graph_Graph759->SetMaximum(0.465);
   Graph_Graph759->SetDirectory(0);
   Graph_Graph759->SetStats(0);
   Graph_Graph759->SetLineWidth(2);
   Graph_Graph759->GetXaxis()->SetNdivisions(506);
   Graph_Graph759->GetXaxis()->SetLabelFont(42);
   Graph_Graph759->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph759->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph759->GetXaxis()->SetTitleFont(42);
   Graph_Graph759->GetYaxis()->SetNdivisions(506);
   Graph_Graph759->GetYaxis()->SetLabelFont(42);
   Graph_Graph759->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph759->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph759->GetYaxis()->SetTitleFont(42);
   Graph_Graph759->GetZaxis()->SetNdivisions(506);
   Graph_Graph759->GetZaxis()->SetLabelFont(42);
   Graph_Graph759->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph759->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph759->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph759);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx760[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy760[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx760,Graph_fy760);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph760 = new TH1F("Graph_Graph760","Graph",100,0.934,1.006);
   Graph_Graph760->SetMinimum(0.285);
   Graph_Graph760->SetMaximum(0.465);
   Graph_Graph760->SetDirectory(0);
   Graph_Graph760->SetStats(0);
   Graph_Graph760->SetLineWidth(2);
   Graph_Graph760->GetXaxis()->SetNdivisions(506);
   Graph_Graph760->GetXaxis()->SetLabelFont(42);
   Graph_Graph760->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph760->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph760->GetXaxis()->SetTitleFont(42);
   Graph_Graph760->GetYaxis()->SetNdivisions(506);
   Graph_Graph760->GetYaxis()->SetLabelFont(42);
   Graph_Graph760->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph760->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph760->GetYaxis()->SetTitleFont(42);
   Graph_Graph760->GetZaxis()->SetNdivisions(506);
   Graph_Graph760->GetZaxis()->SetLabelFont(42);
   Graph_Graph760->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph760->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph760->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph760);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx761[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy761[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx761,Graph_fy761);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph761 = new TH1F("Graph_Graph761","Graph",100,-1.1,0);
   Graph_Graph761->SetMinimum(0.245);
   Graph_Graph761->SetMaximum(2.705);
   Graph_Graph761->SetDirectory(0);
   Graph_Graph761->SetStats(0);
   Graph_Graph761->SetLineWidth(2);
   Graph_Graph761->GetXaxis()->SetNdivisions(506);
   Graph_Graph761->GetXaxis()->SetLabelFont(42);
   Graph_Graph761->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph761->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph761->GetXaxis()->SetTitleFont(42);
   Graph_Graph761->GetYaxis()->SetNdivisions(506);
   Graph_Graph761->GetYaxis()->SetLabelFont(42);
   Graph_Graph761->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph761->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph761->GetYaxis()->SetTitleFont(42);
   Graph_Graph761->GetZaxis()->SetNdivisions(506);
   Graph_Graph761->GetZaxis()->SetLabelFont(42);
   Graph_Graph761->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph761->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph761->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph761);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx762[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy762[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx762,Graph_fy762);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph762 = new TH1F("Graph_Graph762","Graph",100,0,0.297);
   Graph_Graph762->SetMinimum(0.418);
   Graph_Graph762->SetMaximum(0.802);
   Graph_Graph762->SetDirectory(0);
   Graph_Graph762->SetStats(0);
   Graph_Graph762->SetLineWidth(2);
   Graph_Graph762->GetXaxis()->SetNdivisions(506);
   Graph_Graph762->GetXaxis()->SetLabelFont(42);
   Graph_Graph762->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph762->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph762->GetXaxis()->SetTitleFont(42);
   Graph_Graph762->GetYaxis()->SetNdivisions(506);
   Graph_Graph762->GetYaxis()->SetLabelFont(42);
   Graph_Graph762->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph762->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph762->GetYaxis()->SetTitleFont(42);
   Graph_Graph762->GetZaxis()->SetNdivisions(506);
   Graph_Graph762->GetZaxis()->SetLabelFont(42);
   Graph_Graph762->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph762->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph762->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph762);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx763[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy763[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx763,Graph_fy763);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph763 = new TH1F("Graph_Graph763","Graph",100,0.252,0.468);
   Graph_Graph763->SetMinimum(0.418);
   Graph_Graph763->SetMaximum(0.802);
   Graph_Graph763->SetDirectory(0);
   Graph_Graph763->SetStats(0);
   Graph_Graph763->SetLineWidth(2);
   Graph_Graph763->GetXaxis()->SetNdivisions(506);
   Graph_Graph763->GetXaxis()->SetLabelFont(42);
   Graph_Graph763->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph763->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph763->GetXaxis()->SetTitleFont(42);
   Graph_Graph763->GetYaxis()->SetNdivisions(506);
   Graph_Graph763->GetYaxis()->SetLabelFont(42);
   Graph_Graph763->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph763->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph763->GetYaxis()->SetTitleFont(42);
   Graph_Graph763->GetZaxis()->SetNdivisions(506);
   Graph_Graph763->GetZaxis()->SetLabelFont(42);
   Graph_Graph763->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph763->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph763->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph763);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx764[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy764[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx764,Graph_fy764);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph764 = new TH1F("Graph_Graph764","Graph",100,0.433,0.637);
   Graph_Graph764->SetMinimum(0.418);
   Graph_Graph764->SetMaximum(0.802);
   Graph_Graph764->SetDirectory(0);
   Graph_Graph764->SetStats(0);
   Graph_Graph764->SetLineWidth(2);
   Graph_Graph764->GetXaxis()->SetNdivisions(506);
   Graph_Graph764->GetXaxis()->SetLabelFont(42);
   Graph_Graph764->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph764->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph764->GetXaxis()->SetTitleFont(42);
   Graph_Graph764->GetYaxis()->SetNdivisions(506);
   Graph_Graph764->GetYaxis()->SetLabelFont(42);
   Graph_Graph764->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph764->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph764->GetYaxis()->SetTitleFont(42);
   Graph_Graph764->GetZaxis()->SetNdivisions(506);
   Graph_Graph764->GetZaxis()->SetLabelFont(42);
   Graph_Graph764->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph764->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph764->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph764);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx765[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy765[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx765,Graph_fy765);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph765 = new TH1F("Graph_Graph765","Graph",100,0.606,0.774);
   Graph_Graph765->SetMinimum(0.418);
   Graph_Graph765->SetMaximum(0.802);
   Graph_Graph765->SetDirectory(0);
   Graph_Graph765->SetStats(0);
   Graph_Graph765->SetLineWidth(2);
   Graph_Graph765->GetXaxis()->SetNdivisions(506);
   Graph_Graph765->GetXaxis()->SetLabelFont(42);
   Graph_Graph765->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph765->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph765->GetXaxis()->SetTitleFont(42);
   Graph_Graph765->GetYaxis()->SetNdivisions(506);
   Graph_Graph765->GetYaxis()->SetLabelFont(42);
   Graph_Graph765->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph765->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph765->GetYaxis()->SetTitleFont(42);
   Graph_Graph765->GetZaxis()->SetNdivisions(506);
   Graph_Graph765->GetZaxis()->SetLabelFont(42);
   Graph_Graph765->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph765->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph765->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph765);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx766[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy766[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx766,Graph_fy766);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph766 = new TH1F("Graph_Graph766","Graph",100,0.75,0.87);
   Graph_Graph766->SetMinimum(0.418);
   Graph_Graph766->SetMaximum(0.802);
   Graph_Graph766->SetDirectory(0);
   Graph_Graph766->SetStats(0);
   Graph_Graph766->SetLineWidth(2);
   Graph_Graph766->GetXaxis()->SetNdivisions(506);
   Graph_Graph766->GetXaxis()->SetLabelFont(42);
   Graph_Graph766->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph766->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph766->GetXaxis()->SetTitleFont(42);
   Graph_Graph766->GetYaxis()->SetNdivisions(506);
   Graph_Graph766->GetYaxis()->SetLabelFont(42);
   Graph_Graph766->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph766->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph766->GetYaxis()->SetTitleFont(42);
   Graph_Graph766->GetZaxis()->SetNdivisions(506);
   Graph_Graph766->GetZaxis()->SetLabelFont(42);
   Graph_Graph766->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph766->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph766->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph766);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx767[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy767[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx767,Graph_fy767);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph767 = new TH1F("Graph_Graph767","Graph",100,0.852,0.948);
   Graph_Graph767->SetMinimum(0.418);
   Graph_Graph767->SetMaximum(0.802);
   Graph_Graph767->SetDirectory(0);
   Graph_Graph767->SetStats(0);
   Graph_Graph767->SetLineWidth(2);
   Graph_Graph767->GetXaxis()->SetNdivisions(506);
   Graph_Graph767->GetXaxis()->SetLabelFont(42);
   Graph_Graph767->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph767->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph767->GetXaxis()->SetTitleFont(42);
   Graph_Graph767->GetYaxis()->SetNdivisions(506);
   Graph_Graph767->GetYaxis()->SetLabelFont(42);
   Graph_Graph767->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph767->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph767->GetYaxis()->SetTitleFont(42);
   Graph_Graph767->GetZaxis()->SetNdivisions(506);
   Graph_Graph767->GetZaxis()->SetLabelFont(42);
   Graph_Graph767->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph767->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph767->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph767);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx768[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy768[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx768,Graph_fy768);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph768 = new TH1F("Graph_Graph768","Graph",100,0.934,1.006);
   Graph_Graph768->SetMinimum(0.418);
   Graph_Graph768->SetMaximum(0.802);
   Graph_Graph768->SetDirectory(0);
   Graph_Graph768->SetStats(0);
   Graph_Graph768->SetLineWidth(2);
   Graph_Graph768->GetXaxis()->SetNdivisions(506);
   Graph_Graph768->GetXaxis()->SetLabelFont(42);
   Graph_Graph768->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph768->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph768->GetXaxis()->SetTitleFont(42);
   Graph_Graph768->GetYaxis()->SetNdivisions(506);
   Graph_Graph768->GetYaxis()->SetLabelFont(42);
   Graph_Graph768->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph768->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph768->GetYaxis()->SetTitleFont(42);
   Graph_Graph768->GetZaxis()->SetNdivisions(506);
   Graph_Graph768->GetZaxis()->SetLabelFont(42);
   Graph_Graph768->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph768->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph768->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph768);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx769[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy769[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx769,Graph_fy769);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph769 = new TH1F("Graph_Graph769","Graph",100,0,0.297);
   Graph_Graph769->SetMinimum(0.597);
   Graph_Graph769->SetMaximum(2.673);
   Graph_Graph769->SetDirectory(0);
   Graph_Graph769->SetStats(0);
   Graph_Graph769->SetLineWidth(2);
   Graph_Graph769->GetXaxis()->SetNdivisions(506);
   Graph_Graph769->GetXaxis()->SetLabelFont(42);
   Graph_Graph769->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph769->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph769->GetXaxis()->SetTitleFont(42);
   Graph_Graph769->GetYaxis()->SetNdivisions(506);
   Graph_Graph769->GetYaxis()->SetLabelFont(42);
   Graph_Graph769->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph769->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph769->GetYaxis()->SetTitleFont(42);
   Graph_Graph769->GetZaxis()->SetNdivisions(506);
   Graph_Graph769->GetZaxis()->SetLabelFont(42);
   Graph_Graph769->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph769->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph769->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph769);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx770[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy770[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx770,Graph_fy770);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph770 = new TH1F("Graph_Graph770","Graph",100,0.252,0.468);
   Graph_Graph770->SetMinimum(0.597);
   Graph_Graph770->SetMaximum(2.673);
   Graph_Graph770->SetDirectory(0);
   Graph_Graph770->SetStats(0);
   Graph_Graph770->SetLineWidth(2);
   Graph_Graph770->GetXaxis()->SetNdivisions(506);
   Graph_Graph770->GetXaxis()->SetLabelFont(42);
   Graph_Graph770->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph770->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph770->GetXaxis()->SetTitleFont(42);
   Graph_Graph770->GetYaxis()->SetNdivisions(506);
   Graph_Graph770->GetYaxis()->SetLabelFont(42);
   Graph_Graph770->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph770->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph770->GetYaxis()->SetTitleFont(42);
   Graph_Graph770->GetZaxis()->SetNdivisions(506);
   Graph_Graph770->GetZaxis()->SetLabelFont(42);
   Graph_Graph770->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph770->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph770->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph770);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx771[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy771[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx771,Graph_fy771);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph771 = new TH1F("Graph_Graph771","Graph",100,0.433,0.637);
   Graph_Graph771->SetMinimum(0.597);
   Graph_Graph771->SetMaximum(2.673);
   Graph_Graph771->SetDirectory(0);
   Graph_Graph771->SetStats(0);
   Graph_Graph771->SetLineWidth(2);
   Graph_Graph771->GetXaxis()->SetNdivisions(506);
   Graph_Graph771->GetXaxis()->SetLabelFont(42);
   Graph_Graph771->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph771->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph771->GetXaxis()->SetTitleFont(42);
   Graph_Graph771->GetYaxis()->SetNdivisions(506);
   Graph_Graph771->GetYaxis()->SetLabelFont(42);
   Graph_Graph771->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph771->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph771->GetYaxis()->SetTitleFont(42);
   Graph_Graph771->GetZaxis()->SetNdivisions(506);
   Graph_Graph771->GetZaxis()->SetLabelFont(42);
   Graph_Graph771->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph771->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph771->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph771);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx772[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy772[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx772,Graph_fy772);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph772 = new TH1F("Graph_Graph772","Graph",100,0.606,0.774);
   Graph_Graph772->SetMinimum(0.597);
   Graph_Graph772->SetMaximum(2.673);
   Graph_Graph772->SetDirectory(0);
   Graph_Graph772->SetStats(0);
   Graph_Graph772->SetLineWidth(2);
   Graph_Graph772->GetXaxis()->SetNdivisions(506);
   Graph_Graph772->GetXaxis()->SetLabelFont(42);
   Graph_Graph772->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph772->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph772->GetXaxis()->SetTitleFont(42);
   Graph_Graph772->GetYaxis()->SetNdivisions(506);
   Graph_Graph772->GetYaxis()->SetLabelFont(42);
   Graph_Graph772->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph772->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph772->GetYaxis()->SetTitleFont(42);
   Graph_Graph772->GetZaxis()->SetNdivisions(506);
   Graph_Graph772->GetZaxis()->SetLabelFont(42);
   Graph_Graph772->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph772->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph772->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph772);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx773[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy773[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx773,Graph_fy773);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph773 = new TH1F("Graph_Graph773","Graph",100,0.75,0.87);
   Graph_Graph773->SetMinimum(0.597);
   Graph_Graph773->SetMaximum(2.673);
   Graph_Graph773->SetDirectory(0);
   Graph_Graph773->SetStats(0);
   Graph_Graph773->SetLineWidth(2);
   Graph_Graph773->GetXaxis()->SetNdivisions(506);
   Graph_Graph773->GetXaxis()->SetLabelFont(42);
   Graph_Graph773->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph773->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph773->GetXaxis()->SetTitleFont(42);
   Graph_Graph773->GetYaxis()->SetNdivisions(506);
   Graph_Graph773->GetYaxis()->SetLabelFont(42);
   Graph_Graph773->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph773->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph773->GetYaxis()->SetTitleFont(42);
   Graph_Graph773->GetZaxis()->SetNdivisions(506);
   Graph_Graph773->GetZaxis()->SetLabelFont(42);
   Graph_Graph773->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph773->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph773->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph773);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx774[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy774[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx774,Graph_fy774);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph774 = new TH1F("Graph_Graph774","Graph",100,0.852,0.948);
   Graph_Graph774->SetMinimum(0.597);
   Graph_Graph774->SetMaximum(2.673);
   Graph_Graph774->SetDirectory(0);
   Graph_Graph774->SetStats(0);
   Graph_Graph774->SetLineWidth(2);
   Graph_Graph774->GetXaxis()->SetNdivisions(506);
   Graph_Graph774->GetXaxis()->SetLabelFont(42);
   Graph_Graph774->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph774->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph774->GetXaxis()->SetTitleFont(42);
   Graph_Graph774->GetYaxis()->SetNdivisions(506);
   Graph_Graph774->GetYaxis()->SetLabelFont(42);
   Graph_Graph774->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph774->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph774->GetYaxis()->SetTitleFont(42);
   Graph_Graph774->GetZaxis()->SetNdivisions(506);
   Graph_Graph774->GetZaxis()->SetLabelFont(42);
   Graph_Graph774->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph774->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph774->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph774);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx775[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy775[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx775,Graph_fy775);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph775 = new TH1F("Graph_Graph775","Graph",100,0.934,1.006);
   Graph_Graph775->SetMinimum(0.597);
   Graph_Graph775->SetMaximum(2.673);
   Graph_Graph775->SetDirectory(0);
   Graph_Graph775->SetStats(0);
   Graph_Graph775->SetLineWidth(2);
   Graph_Graph775->GetXaxis()->SetNdivisions(506);
   Graph_Graph775->GetXaxis()->SetLabelFont(42);
   Graph_Graph775->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph775->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph775->GetXaxis()->SetTitleFont(42);
   Graph_Graph775->GetYaxis()->SetNdivisions(506);
   Graph_Graph775->GetYaxis()->SetLabelFont(42);
   Graph_Graph775->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph775->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph775->GetYaxis()->SetTitleFont(42);
   Graph_Graph775->GetZaxis()->SetNdivisions(506);
   Graph_Graph775->GetZaxis()->SetLabelFont(42);
   Graph_Graph775->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph775->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph775->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph775);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,nan);
   _reco_per_true->SetBinContent(2,nan);
   _reco_per_true->SetBinContent(3,nan);
   _reco_per_true->SetBinContent(4,nan);
   _reco_per_true->SetBinContent(5,nan);
   _reco_per_true->SetBinContent(6,nan);
   _reco_per_true->SetBinContent(7,nan);
   _reco_per_true->SetBinContent(8,nan);
   _reco_per_true->SetBinContent(9,nan);
   _reco_per_true->SetBinContent(10,nan);
   _reco_per_true->SetBinContent(11,nan);
   _reco_per_true->SetBinContent(12,nan);
   _reco_per_true->SetBinContent(13,nan);
   _reco_per_true->SetBinContent(14,nan);
   _reco_per_true->SetBinContent(15,nan);
   _reco_per_true->SetBinContent(16,nan);
   _reco_per_true->SetBinContent(17,nan);
   _reco_per_true->SetBinContent(18,nan);
   _reco_per_true->SetBinContent(19,nan);
   _reco_per_true->SetBinContent(20,nan);
   _reco_per_true->SetBinContent(21,nan);
   _reco_per_true->SetBinContent(22,nan);
   _reco_per_true->SetBinContent(23,nan);
   _reco_per_true->SetBinContent(24,nan);
   _reco_per_true->SetBinContent(25,nan);
   _reco_per_true->SetBinContent(26,nan);
   _reco_per_true->SetBinContent(27,nan);
   _reco_per_true->SetBinContent(28,nan);
   _reco_per_true->SetBinContent(29,nan);
   _reco_per_true->SetBinContent(30,nan);
   _reco_per_true->SetBinContent(31,nan);
   _reco_per_true->SetBinError(1,nan);
   _reco_per_true->SetBinError(2,nan);
   _reco_per_true->SetBinError(3,nan);
   _reco_per_true->SetBinError(4,nan);
   _reco_per_true->SetBinError(5,nan);
   _reco_per_true->SetBinError(6,nan);
   _reco_per_true->SetBinError(7,nan);
   _reco_per_true->SetBinError(8,nan);
   _reco_per_true->SetBinError(9,nan);
   _reco_per_true->SetBinError(10,nan);
   _reco_per_true->SetBinError(11,nan);
   _reco_per_true->SetBinError(12,nan);
   _reco_per_true->SetBinError(13,nan);
   _reco_per_true->SetBinError(14,nan);
   _reco_per_true->SetBinError(15,nan);
   _reco_per_true->SetBinError(16,nan);
   _reco_per_true->SetBinError(17,nan);
   _reco_per_true->SetBinError(18,nan);
   _reco_per_true->SetBinError(19,nan);
   _reco_per_true->SetBinError(20,nan);
   _reco_per_true->SetBinError(21,nan);
   _reco_per_true->SetBinError(22,nan);
   _reco_per_true->SetBinError(23,nan);
   _reco_per_true->SetBinError(24,nan);
   _reco_per_true->SetBinError(25,nan);
   _reco_per_true->SetBinError(26,nan);
   _reco_per_true->SetBinError(27,nan);
   _reco_per_true->SetBinError(28,nan);
   _reco_per_true->SetBinError(29,nan);
   _reco_per_true->SetBinError(30,nan);
   _reco_per_true->SetBinError(31,nan);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,nan);
   _reco_per_true->SetContourLevel(1,nan);
   _reco_per_true->SetContourLevel(2,nan);
   _reco_per_true->SetContourLevel(3,nan);
   _reco_per_true->SetContourLevel(4,nan);
   _reco_per_true->SetContourLevel(5,nan);
   _reco_per_true->SetContourLevel(6,nan);
   _reco_per_true->SetContourLevel(7,nan);
   _reco_per_true->SetContourLevel(8,nan);
   _reco_per_true->SetContourLevel(9,nan);
   _reco_per_true->SetContourLevel(10,nan);
   _reco_per_true->SetContourLevel(11,nan);
   _reco_per_true->SetContourLevel(12,nan);
   _reco_per_true->SetContourLevel(13,nan);
   _reco_per_true->SetContourLevel(14,nan);
   _reco_per_true->SetContourLevel(15,nan);
   _reco_per_true->SetContourLevel(16,nan);
   _reco_per_true->SetContourLevel(17,nan);
   _reco_per_true->SetContourLevel(18,nan);
   _reco_per_true->SetContourLevel(19,nan);
   _reco_per_true->SetContourLevel(20,nan);
   _reco_per_true->SetContourLevel(21,nan);
   _reco_per_true->SetContourLevel(22,nan);
   _reco_per_true->SetContourLevel(23,nan);
   _reco_per_true->SetContourLevel(24,nan);
   _reco_per_true->SetContourLevel(25,nan);
   _reco_per_true->SetContourLevel(26,nan);
   _reco_per_true->SetContourLevel(27,nan);
   _reco_per_true->SetContourLevel(28,nan);
   _reco_per_true->SetContourLevel(29,nan);
   _reco_per_true->SetContourLevel(30,nan);
   _reco_per_true->SetContourLevel(31,nan);
   _reco_per_true->SetContourLevel(32,nan);
   _reco_per_true->SetContourLevel(33,nan);
   _reco_per_true->SetContourLevel(34,nan);
   _reco_per_true->SetContourLevel(35,nan);
   _reco_per_true->SetContourLevel(36,nan);
   _reco_per_true->SetContourLevel(37,nan);
   _reco_per_true->SetContourLevel(38,nan);
   _reco_per_true->SetContourLevel(39,nan);
   _reco_per_true->SetContourLevel(40,nan);
   _reco_per_true->SetContourLevel(41,nan);
   _reco_per_true->SetContourLevel(42,nan);
   _reco_per_true->SetContourLevel(43,nan);
   _reco_per_true->SetContourLevel(44,nan);
   _reco_per_true->SetContourLevel(45,nan);
   _reco_per_true->SetContourLevel(46,nan);
   _reco_per_true->SetContourLevel(47,nan);
   _reco_per_true->SetContourLevel(48,nan);
   _reco_per_true->SetContourLevel(49,nan);
   _reco_per_true->SetContourLevel(50,nan);
   _reco_per_true->SetContourLevel(51,nan);
   _reco_per_true->SetContourLevel(52,nan);
   _reco_per_true->SetContourLevel(53,nan);
   _reco_per_true->SetContourLevel(54,nan);
   _reco_per_true->SetContourLevel(55,nan);
   _reco_per_true->SetContourLevel(56,nan);
   _reco_per_true->SetContourLevel(57,nan);
   _reco_per_true->SetContourLevel(58,nan);
   _reco_per_true->SetContourLevel(59,nan);
   _reco_per_true->SetContourLevel(60,nan);
   _reco_per_true->SetContourLevel(61,nan);
   _reco_per_true->SetContourLevel(62,nan);
   _reco_per_true->SetContourLevel(63,nan);
   _reco_per_true->SetContourLevel(64,nan);
   _reco_per_true->SetContourLevel(65,nan);
   _reco_per_true->SetContourLevel(66,nan);
   _reco_per_true->SetContourLevel(67,nan);
   _reco_per_true->SetContourLevel(68,nan);
   _reco_per_true->SetContourLevel(69,nan);
   _reco_per_true->SetContourLevel(70,nan);
   _reco_per_true->SetContourLevel(71,nan);
   _reco_per_true->SetContourLevel(72,nan);
   _reco_per_true->SetContourLevel(73,nan);
   _reco_per_true->SetContourLevel(74,nan);
   _reco_per_true->SetContourLevel(75,nan);
   _reco_per_true->SetContourLevel(76,nan);
   _reco_per_true->SetContourLevel(77,nan);
   _reco_per_true->SetContourLevel(78,nan);
   _reco_per_true->SetContourLevel(79,nan);
   _reco_per_true->SetContourLevel(80,nan);
   _reco_per_true->SetContourLevel(81,nan);
   _reco_per_true->SetContourLevel(82,nan);
   _reco_per_true->SetContourLevel(83,nan);
   _reco_per_true->SetContourLevel(84,nan);
   _reco_per_true->SetContourLevel(85,nan);
   _reco_per_true->SetContourLevel(86,nan);
   _reco_per_true->SetContourLevel(87,nan);
   _reco_per_true->SetContourLevel(88,nan);
   _reco_per_true->SetContourLevel(89,nan);
   _reco_per_true->SetContourLevel(90,nan);
   _reco_per_true->SetContourLevel(91,nan);
   _reco_per_true->SetContourLevel(92,nan);
   _reco_per_true->SetContourLevel(93,nan);
   _reco_per_true->SetContourLevel(94,nan);
   _reco_per_true->SetContourLevel(95,nan);
   _reco_per_true->SetContourLevel(96,nan);
   _reco_per_true->SetContourLevel(97,nan);
   _reco_per_true->SetContourLevel(98,nan);
   _reco_per_true->SetContourLevel(99,nan);
   _reco_per_true->SetContourLevel(100,nan);
   _reco_per_true->SetContourLevel(101,nan);
   _reco_per_true->SetContourLevel(102,nan);
   _reco_per_true->SetContourLevel(103,nan);
   _reco_per_true->SetContourLevel(104,nan);
   _reco_per_true->SetContourLevel(105,nan);
   _reco_per_true->SetContourLevel(106,nan);
   _reco_per_true->SetContourLevel(107,nan);
   _reco_per_true->SetContourLevel(108,nan);
   _reco_per_true->SetContourLevel(109,nan);
   _reco_per_true->SetContourLevel(110,nan);
   _reco_per_true->SetContourLevel(111,nan);
   _reco_per_true->SetContourLevel(112,nan);
   _reco_per_true->SetContourLevel(113,nan);
   _reco_per_true->SetContourLevel(114,nan);
   _reco_per_true->SetContourLevel(115,nan);
   _reco_per_true->SetContourLevel(116,nan);
   _reco_per_true->SetContourLevel(117,nan);
   _reco_per_true->SetContourLevel(118,nan);
   _reco_per_true->SetContourLevel(119,nan);
   _reco_per_true->SetContourLevel(120,nan);
   _reco_per_true->SetContourLevel(121,nan);
   _reco_per_true->SetContourLevel(122,nan);
   _reco_per_true->SetContourLevel(123,nan);
   _reco_per_true->SetContourLevel(124,nan);
   _reco_per_true->SetContourLevel(125,nan);
   _reco_per_true->SetContourLevel(126,nan);
   _reco_per_true->SetContourLevel(127,nan);
   _reco_per_true->SetContourLevel(128,nan);
   _reco_per_true->SetContourLevel(129,nan);
   _reco_per_true->SetContourLevel(130,nan);
   _reco_per_true->SetContourLevel(131,nan);
   _reco_per_true->SetContourLevel(132,nan);
   _reco_per_true->SetContourLevel(133,nan);
   _reco_per_true->SetContourLevel(134,nan);
   _reco_per_true->SetContourLevel(135,nan);
   _reco_per_true->SetContourLevel(136,nan);
   _reco_per_true->SetContourLevel(137,nan);
   _reco_per_true->SetContourLevel(138,nan);
   _reco_per_true->SetContourLevel(139,nan);
   _reco_per_true->SetContourLevel(140,nan);
   _reco_per_true->SetContourLevel(141,nan);
   _reco_per_true->SetContourLevel(142,nan);
   _reco_per_true->SetContourLevel(143,nan);
   _reco_per_true->SetContourLevel(144,nan);
   _reco_per_true->SetContourLevel(145,nan);
   _reco_per_true->SetContourLevel(146,nan);
   _reco_per_true->SetContourLevel(147,nan);
   _reco_per_true->SetContourLevel(148,nan);
   _reco_per_true->SetContourLevel(149,nan);
   _reco_per_true->SetContourLevel(150,nan);
   _reco_per_true->SetContourLevel(151,nan);
   _reco_per_true->SetContourLevel(152,nan);
   _reco_per_true->SetContourLevel(153,nan);
   _reco_per_true->SetContourLevel(154,nan);
   _reco_per_true->SetContourLevel(155,nan);
   _reco_per_true->SetContourLevel(156,nan);
   _reco_per_true->SetContourLevel(157,nan);
   _reco_per_true->SetContourLevel(158,nan);
   _reco_per_true->SetContourLevel(159,nan);
   _reco_per_true->SetContourLevel(160,nan);
   _reco_per_true->SetContourLevel(161,nan);
   _reco_per_true->SetContourLevel(162,nan);
   _reco_per_true->SetContourLevel(163,nan);
   _reco_per_true->SetContourLevel(164,nan);
   _reco_per_true->SetContourLevel(165,nan);
   _reco_per_true->SetContourLevel(166,nan);
   _reco_per_true->SetContourLevel(167,nan);
   _reco_per_true->SetContourLevel(168,nan);
   _reco_per_true->SetContourLevel(169,nan);
   _reco_per_true->SetContourLevel(170,nan);
   _reco_per_true->SetContourLevel(171,nan);
   _reco_per_true->SetContourLevel(172,nan);
   _reco_per_true->SetContourLevel(173,nan);
   _reco_per_true->SetContourLevel(174,nan);
   _reco_per_true->SetContourLevel(175,nan);
   _reco_per_true->SetContourLevel(176,nan);
   _reco_per_true->SetContourLevel(177,nan);
   _reco_per_true->SetContourLevel(178,nan);
   _reco_per_true->SetContourLevel(179,nan);
   _reco_per_true->SetContourLevel(180,nan);
   _reco_per_true->SetContourLevel(181,nan);
   _reco_per_true->SetContourLevel(182,nan);
   _reco_per_true->SetContourLevel(183,nan);
   _reco_per_true->SetContourLevel(184,nan);
   _reco_per_true->SetContourLevel(185,nan);
   _reco_per_true->SetContourLevel(186,nan);
   _reco_per_true->SetContourLevel(187,nan);
   _reco_per_true->SetContourLevel(188,nan);
   _reco_per_true->SetContourLevel(189,nan);
   _reco_per_true->SetContourLevel(190,nan);
   _reco_per_true->SetContourLevel(191,nan);
   _reco_per_true->SetContourLevel(192,nan);
   _reco_per_true->SetContourLevel(193,nan);
   _reco_per_true->SetContourLevel(194,nan);
   _reco_per_true->SetContourLevel(195,nan);
   _reco_per_true->SetContourLevel(196,nan);
   _reco_per_true->SetContourLevel(197,nan);
   _reco_per_true->SetContourLevel(198,nan);
   _reco_per_true->SetContourLevel(199,nan);
   _reco_per_true->SetContourLevel(200,nan);
   _reco_per_true->SetContourLevel(201,nan);
   _reco_per_true->SetContourLevel(202,nan);
   _reco_per_true->SetContourLevel(203,nan);
   _reco_per_true->SetContourLevel(204,nan);
   _reco_per_true->SetContourLevel(205,nan);
   _reco_per_true->SetContourLevel(206,nan);
   _reco_per_true->SetContourLevel(207,nan);
   _reco_per_true->SetContourLevel(208,nan);
   _reco_per_true->SetContourLevel(209,nan);
   _reco_per_true->SetContourLevel(210,nan);
   _reco_per_true->SetContourLevel(211,nan);
   _reco_per_true->SetContourLevel(212,nan);
   _reco_per_true->SetContourLevel(213,nan);
   _reco_per_true->SetContourLevel(214,nan);
   _reco_per_true->SetContourLevel(215,nan);
   _reco_per_true->SetContourLevel(216,nan);
   _reco_per_true->SetContourLevel(217,nan);
   _reco_per_true->SetContourLevel(218,nan);
   _reco_per_true->SetContourLevel(219,nan);
   _reco_per_true->SetContourLevel(220,nan);
   _reco_per_true->SetContourLevel(221,nan);
   _reco_per_true->SetContourLevel(222,nan);
   _reco_per_true->SetContourLevel(223,nan);
   _reco_per_true->SetContourLevel(224,nan);
   _reco_per_true->SetContourLevel(225,nan);
   _reco_per_true->SetContourLevel(226,nan);
   _reco_per_true->SetContourLevel(227,nan);
   _reco_per_true->SetContourLevel(228,nan);
   _reco_per_true->SetContourLevel(229,nan);
   _reco_per_true->SetContourLevel(230,nan);
   _reco_per_true->SetContourLevel(231,nan);
   _reco_per_true->SetContourLevel(232,nan);
   _reco_per_true->SetContourLevel(233,nan);
   _reco_per_true->SetContourLevel(234,nan);
   _reco_per_true->SetContourLevel(235,nan);
   _reco_per_true->SetContourLevel(236,nan);
   _reco_per_true->SetContourLevel(237,nan);
   _reco_per_true->SetContourLevel(238,nan);
   _reco_per_true->SetContourLevel(239,nan);
   _reco_per_true->SetContourLevel(240,nan);
   _reco_per_true->SetContourLevel(241,nan);
   _reco_per_true->SetContourLevel(242,nan);
   _reco_per_true->SetContourLevel(243,nan);
   _reco_per_true->SetContourLevel(244,nan);
   _reco_per_true->SetContourLevel(245,nan);
   _reco_per_true->SetContourLevel(246,nan);
   _reco_per_true->SetContourLevel(247,nan);
   _reco_per_true->SetContourLevel(248,nan);
   _reco_per_true->SetContourLevel(249,nan);
   _reco_per_true->SetContourLevel(250,nan);
   _reco_per_true->SetContourLevel(251,nan);
   _reco_per_true->SetContourLevel(252,nan);
   _reco_per_true->SetContourLevel(253,nan);
   _reco_per_true->SetContourLevel(254,nan);
   
   TPaletteAxis *palette = new TPaletteAxis(1.0125,0,1.125,2.5,_reco_per_true);
palette->SetLabelColor(1);
palette->SetLabelFont(42);
palette->SetLabelOffset(0.005);
palette->SetLabelSize(0.04);
palette->SetTitleOffset(0.8);
palette->SetTitleSize(0.055);

   ci = TColor::GetColor("#000082");
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
   TText *AText = pt->AddText("True Bin 24");
   pt->Draw();
   c1_n25->Modified();
   c1_n25->cd();
   c1_n25->SetSelected(c1_n25);
}

void smearing_matrix_true_30()
{
//=========Macro generated from canvas: c1_n31/c1_n31
//=========  (Sat Sep 22 12:03:58 2018) by ROOT version6.06/06
   TCanvas *c1_n31 = new TCanvas("c1_n31", "c1_n31",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n31->SetHighLightColor(2);
   c1_n31->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n31->SetFillColor(10);
   c1_n31->SetBorderMode(0);
   c1_n31->SetBorderSize(2);
   c1_n31->SetFrameLineWidth(2);
   c1_n31->SetFrameBorderMode(0);
   c1_n31->SetFrameLineWidth(2);
   c1_n31->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 30", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx931[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy931[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx931,Graph_fy931);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph931 = new TH1F("Graph_Graph931","Graph",100,-1.1,0);
   Graph_Graph931->SetMinimum(0);
   Graph_Graph931->SetMaximum(0.33);
   Graph_Graph931->SetDirectory(0);
   Graph_Graph931->SetStats(0);
   Graph_Graph931->SetLineWidth(2);
   Graph_Graph931->GetXaxis()->SetNdivisions(506);
   Graph_Graph931->GetXaxis()->SetLabelFont(42);
   Graph_Graph931->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph931->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph931->GetXaxis()->SetTitleFont(42);
   Graph_Graph931->GetYaxis()->SetNdivisions(506);
   Graph_Graph931->GetYaxis()->SetLabelFont(42);
   Graph_Graph931->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph931->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph931->GetYaxis()->SetTitleFont(42);
   Graph_Graph931->GetZaxis()->SetNdivisions(506);
   Graph_Graph931->GetZaxis()->SetLabelFont(42);
   Graph_Graph931->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph931->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph931->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph931);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx932[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy932[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx932,Graph_fy932);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph932 = new TH1F("Graph_Graph932","Graph",100,0,0.297);
   Graph_Graph932->SetMinimum(0);
   Graph_Graph932->SetMaximum(0.33);
   Graph_Graph932->SetDirectory(0);
   Graph_Graph932->SetStats(0);
   Graph_Graph932->SetLineWidth(2);
   Graph_Graph932->GetXaxis()->SetNdivisions(506);
   Graph_Graph932->GetXaxis()->SetLabelFont(42);
   Graph_Graph932->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph932->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph932->GetXaxis()->SetTitleFont(42);
   Graph_Graph932->GetYaxis()->SetNdivisions(506);
   Graph_Graph932->GetYaxis()->SetLabelFont(42);
   Graph_Graph932->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph932->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph932->GetYaxis()->SetTitleFont(42);
   Graph_Graph932->GetZaxis()->SetNdivisions(506);
   Graph_Graph932->GetZaxis()->SetLabelFont(42);
   Graph_Graph932->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph932->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph932->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph932);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx933[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy933[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx933,Graph_fy933);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph933 = new TH1F("Graph_Graph933","Graph",100,0.252,0.468);
   Graph_Graph933->SetMinimum(0);
   Graph_Graph933->SetMaximum(0.33);
   Graph_Graph933->SetDirectory(0);
   Graph_Graph933->SetStats(0);
   Graph_Graph933->SetLineWidth(2);
   Graph_Graph933->GetXaxis()->SetNdivisions(506);
   Graph_Graph933->GetXaxis()->SetLabelFont(42);
   Graph_Graph933->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph933->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph933->GetXaxis()->SetTitleFont(42);
   Graph_Graph933->GetYaxis()->SetNdivisions(506);
   Graph_Graph933->GetYaxis()->SetLabelFont(42);
   Graph_Graph933->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph933->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph933->GetYaxis()->SetTitleFont(42);
   Graph_Graph933->GetZaxis()->SetNdivisions(506);
   Graph_Graph933->GetZaxis()->SetLabelFont(42);
   Graph_Graph933->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph933->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph933->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph933);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx934[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy934[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx934,Graph_fy934);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph934 = new TH1F("Graph_Graph934","Graph",100,0.433,0.637);
   Graph_Graph934->SetMinimum(0);
   Graph_Graph934->SetMaximum(0.33);
   Graph_Graph934->SetDirectory(0);
   Graph_Graph934->SetStats(0);
   Graph_Graph934->SetLineWidth(2);
   Graph_Graph934->GetXaxis()->SetNdivisions(506);
   Graph_Graph934->GetXaxis()->SetLabelFont(42);
   Graph_Graph934->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph934->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph934->GetXaxis()->SetTitleFont(42);
   Graph_Graph934->GetYaxis()->SetNdivisions(506);
   Graph_Graph934->GetYaxis()->SetLabelFont(42);
   Graph_Graph934->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph934->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph934->GetYaxis()->SetTitleFont(42);
   Graph_Graph934->GetZaxis()->SetNdivisions(506);
   Graph_Graph934->GetZaxis()->SetLabelFont(42);
   Graph_Graph934->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph934->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph934->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph934);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx935[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy935[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx935,Graph_fy935);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph935 = new TH1F("Graph_Graph935","Graph",100,0.606,0.774);
   Graph_Graph935->SetMinimum(0);
   Graph_Graph935->SetMaximum(0.33);
   Graph_Graph935->SetDirectory(0);
   Graph_Graph935->SetStats(0);
   Graph_Graph935->SetLineWidth(2);
   Graph_Graph935->GetXaxis()->SetNdivisions(506);
   Graph_Graph935->GetXaxis()->SetLabelFont(42);
   Graph_Graph935->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph935->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph935->GetXaxis()->SetTitleFont(42);
   Graph_Graph935->GetYaxis()->SetNdivisions(506);
   Graph_Graph935->GetYaxis()->SetLabelFont(42);
   Graph_Graph935->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph935->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph935->GetYaxis()->SetTitleFont(42);
   Graph_Graph935->GetZaxis()->SetNdivisions(506);
   Graph_Graph935->GetZaxis()->SetLabelFont(42);
   Graph_Graph935->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph935->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph935->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph935);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx936[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy936[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx936,Graph_fy936);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph936 = new TH1F("Graph_Graph936","Graph",100,0.75,0.87);
   Graph_Graph936->SetMinimum(0);
   Graph_Graph936->SetMaximum(0.33);
   Graph_Graph936->SetDirectory(0);
   Graph_Graph936->SetStats(0);
   Graph_Graph936->SetLineWidth(2);
   Graph_Graph936->GetXaxis()->SetNdivisions(506);
   Graph_Graph936->GetXaxis()->SetLabelFont(42);
   Graph_Graph936->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph936->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph936->GetXaxis()->SetTitleFont(42);
   Graph_Graph936->GetYaxis()->SetNdivisions(506);
   Graph_Graph936->GetYaxis()->SetLabelFont(42);
   Graph_Graph936->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph936->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph936->GetYaxis()->SetTitleFont(42);
   Graph_Graph936->GetZaxis()->SetNdivisions(506);
   Graph_Graph936->GetZaxis()->SetLabelFont(42);
   Graph_Graph936->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph936->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph936->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph936);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx937[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy937[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx937,Graph_fy937);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph937 = new TH1F("Graph_Graph937","Graph",100,0.852,0.948);
   Graph_Graph937->SetMinimum(0);
   Graph_Graph937->SetMaximum(0.33);
   Graph_Graph937->SetDirectory(0);
   Graph_Graph937->SetStats(0);
   Graph_Graph937->SetLineWidth(2);
   Graph_Graph937->GetXaxis()->SetNdivisions(506);
   Graph_Graph937->GetXaxis()->SetLabelFont(42);
   Graph_Graph937->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph937->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph937->GetXaxis()->SetTitleFont(42);
   Graph_Graph937->GetYaxis()->SetNdivisions(506);
   Graph_Graph937->GetYaxis()->SetLabelFont(42);
   Graph_Graph937->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph937->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph937->GetYaxis()->SetTitleFont(42);
   Graph_Graph937->GetZaxis()->SetNdivisions(506);
   Graph_Graph937->GetZaxis()->SetLabelFont(42);
   Graph_Graph937->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph937->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph937->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph937);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx938[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy938[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx938,Graph_fy938);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph938 = new TH1F("Graph_Graph938","Graph",100,0.934,1.006);
   Graph_Graph938->SetMinimum(0);
   Graph_Graph938->SetMaximum(0.33);
   Graph_Graph938->SetDirectory(0);
   Graph_Graph938->SetStats(0);
   Graph_Graph938->SetLineWidth(2);
   Graph_Graph938->GetXaxis()->SetNdivisions(506);
   Graph_Graph938->GetXaxis()->SetLabelFont(42);
   Graph_Graph938->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph938->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph938->GetXaxis()->SetTitleFont(42);
   Graph_Graph938->GetYaxis()->SetNdivisions(506);
   Graph_Graph938->GetYaxis()->SetLabelFont(42);
   Graph_Graph938->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph938->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph938->GetYaxis()->SetTitleFont(42);
   Graph_Graph938->GetZaxis()->SetNdivisions(506);
   Graph_Graph938->GetZaxis()->SetLabelFont(42);
   Graph_Graph938->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph938->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph938->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph938);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx939[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy939[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx939,Graph_fy939);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph939 = new TH1F("Graph_Graph939","Graph",100,-1.1,0);
   Graph_Graph939->SetMinimum(0.285);
   Graph_Graph939->SetMaximum(0.465);
   Graph_Graph939->SetDirectory(0);
   Graph_Graph939->SetStats(0);
   Graph_Graph939->SetLineWidth(2);
   Graph_Graph939->GetXaxis()->SetNdivisions(506);
   Graph_Graph939->GetXaxis()->SetLabelFont(42);
   Graph_Graph939->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph939->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph939->GetXaxis()->SetTitleFont(42);
   Graph_Graph939->GetYaxis()->SetNdivisions(506);
   Graph_Graph939->GetYaxis()->SetLabelFont(42);
   Graph_Graph939->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph939->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph939->GetYaxis()->SetTitleFont(42);
   Graph_Graph939->GetZaxis()->SetNdivisions(506);
   Graph_Graph939->GetZaxis()->SetLabelFont(42);
   Graph_Graph939->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph939->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph939->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph939);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx940[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy940[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx940,Graph_fy940);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph940 = new TH1F("Graph_Graph940","Graph",100,0,0.297);
   Graph_Graph940->SetMinimum(0.285);
   Graph_Graph940->SetMaximum(0.465);
   Graph_Graph940->SetDirectory(0);
   Graph_Graph940->SetStats(0);
   Graph_Graph940->SetLineWidth(2);
   Graph_Graph940->GetXaxis()->SetNdivisions(506);
   Graph_Graph940->GetXaxis()->SetLabelFont(42);
   Graph_Graph940->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph940->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph940->GetXaxis()->SetTitleFont(42);
   Graph_Graph940->GetYaxis()->SetNdivisions(506);
   Graph_Graph940->GetYaxis()->SetLabelFont(42);
   Graph_Graph940->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph940->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph940->GetYaxis()->SetTitleFont(42);
   Graph_Graph940->GetZaxis()->SetNdivisions(506);
   Graph_Graph940->GetZaxis()->SetLabelFont(42);
   Graph_Graph940->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph940->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph940->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph940);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx941[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy941[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx941,Graph_fy941);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph941 = new TH1F("Graph_Graph941","Graph",100,0.252,0.468);
   Graph_Graph941->SetMinimum(0.285);
   Graph_Graph941->SetMaximum(0.465);
   Graph_Graph941->SetDirectory(0);
   Graph_Graph941->SetStats(0);
   Graph_Graph941->SetLineWidth(2);
   Graph_Graph941->GetXaxis()->SetNdivisions(506);
   Graph_Graph941->GetXaxis()->SetLabelFont(42);
   Graph_Graph941->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph941->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph941->GetXaxis()->SetTitleFont(42);
   Graph_Graph941->GetYaxis()->SetNdivisions(506);
   Graph_Graph941->GetYaxis()->SetLabelFont(42);
   Graph_Graph941->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph941->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph941->GetYaxis()->SetTitleFont(42);
   Graph_Graph941->GetZaxis()->SetNdivisions(506);
   Graph_Graph941->GetZaxis()->SetLabelFont(42);
   Graph_Graph941->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph941->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph941->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph941);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx942[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy942[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx942,Graph_fy942);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph942 = new TH1F("Graph_Graph942","Graph",100,0.433,0.637);
   Graph_Graph942->SetMinimum(0.285);
   Graph_Graph942->SetMaximum(0.465);
   Graph_Graph942->SetDirectory(0);
   Graph_Graph942->SetStats(0);
   Graph_Graph942->SetLineWidth(2);
   Graph_Graph942->GetXaxis()->SetNdivisions(506);
   Graph_Graph942->GetXaxis()->SetLabelFont(42);
   Graph_Graph942->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph942->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph942->GetXaxis()->SetTitleFont(42);
   Graph_Graph942->GetYaxis()->SetNdivisions(506);
   Graph_Graph942->GetYaxis()->SetLabelFont(42);
   Graph_Graph942->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph942->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph942->GetYaxis()->SetTitleFont(42);
   Graph_Graph942->GetZaxis()->SetNdivisions(506);
   Graph_Graph942->GetZaxis()->SetLabelFont(42);
   Graph_Graph942->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph942->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph942->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph942);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx943[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy943[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx943,Graph_fy943);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph943 = new TH1F("Graph_Graph943","Graph",100,0.606,0.774);
   Graph_Graph943->SetMinimum(0.285);
   Graph_Graph943->SetMaximum(0.465);
   Graph_Graph943->SetDirectory(0);
   Graph_Graph943->SetStats(0);
   Graph_Graph943->SetLineWidth(2);
   Graph_Graph943->GetXaxis()->SetNdivisions(506);
   Graph_Graph943->GetXaxis()->SetLabelFont(42);
   Graph_Graph943->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph943->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph943->GetXaxis()->SetTitleFont(42);
   Graph_Graph943->GetYaxis()->SetNdivisions(506);
   Graph_Graph943->GetYaxis()->SetLabelFont(42);
   Graph_Graph943->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph943->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph943->GetYaxis()->SetTitleFont(42);
   Graph_Graph943->GetZaxis()->SetNdivisions(506);
   Graph_Graph943->GetZaxis()->SetLabelFont(42);
   Graph_Graph943->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph943->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph943->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph943);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx944[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy944[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx944,Graph_fy944);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph944 = new TH1F("Graph_Graph944","Graph",100,0.75,0.87);
   Graph_Graph944->SetMinimum(0.285);
   Graph_Graph944->SetMaximum(0.465);
   Graph_Graph944->SetDirectory(0);
   Graph_Graph944->SetStats(0);
   Graph_Graph944->SetLineWidth(2);
   Graph_Graph944->GetXaxis()->SetNdivisions(506);
   Graph_Graph944->GetXaxis()->SetLabelFont(42);
   Graph_Graph944->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph944->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph944->GetXaxis()->SetTitleFont(42);
   Graph_Graph944->GetYaxis()->SetNdivisions(506);
   Graph_Graph944->GetYaxis()->SetLabelFont(42);
   Graph_Graph944->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph944->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph944->GetYaxis()->SetTitleFont(42);
   Graph_Graph944->GetZaxis()->SetNdivisions(506);
   Graph_Graph944->GetZaxis()->SetLabelFont(42);
   Graph_Graph944->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph944->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph944->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph944);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx945[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy945[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx945,Graph_fy945);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph945 = new TH1F("Graph_Graph945","Graph",100,0.852,0.948);
   Graph_Graph945->SetMinimum(0.285);
   Graph_Graph945->SetMaximum(0.465);
   Graph_Graph945->SetDirectory(0);
   Graph_Graph945->SetStats(0);
   Graph_Graph945->SetLineWidth(2);
   Graph_Graph945->GetXaxis()->SetNdivisions(506);
   Graph_Graph945->GetXaxis()->SetLabelFont(42);
   Graph_Graph945->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph945->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph945->GetXaxis()->SetTitleFont(42);
   Graph_Graph945->GetYaxis()->SetNdivisions(506);
   Graph_Graph945->GetYaxis()->SetLabelFont(42);
   Graph_Graph945->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph945->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph945->GetYaxis()->SetTitleFont(42);
   Graph_Graph945->GetZaxis()->SetNdivisions(506);
   Graph_Graph945->GetZaxis()->SetLabelFont(42);
   Graph_Graph945->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph945->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph945->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph945);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx946[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy946[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx946,Graph_fy946);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000987");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph946 = new TH1F("Graph_Graph946","Graph",100,0.934,1.006);
   Graph_Graph946->SetMinimum(0.285);
   Graph_Graph946->SetMaximum(0.465);
   Graph_Graph946->SetDirectory(0);
   Graph_Graph946->SetStats(0);
   Graph_Graph946->SetLineWidth(2);
   Graph_Graph946->GetXaxis()->SetNdivisions(506);
   Graph_Graph946->GetXaxis()->SetLabelFont(42);
   Graph_Graph946->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph946->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph946->GetXaxis()->SetTitleFont(42);
   Graph_Graph946->GetYaxis()->SetNdivisions(506);
   Graph_Graph946->GetYaxis()->SetLabelFont(42);
   Graph_Graph946->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph946->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph946->GetYaxis()->SetTitleFont(42);
   Graph_Graph946->GetZaxis()->SetNdivisions(506);
   Graph_Graph946->GetZaxis()->SetLabelFont(42);
   Graph_Graph946->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph946->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph946->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph946);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx947[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy947[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx947,Graph_fy947);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000283");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph947 = new TH1F("Graph_Graph947","Graph",100,-1.1,0);
   Graph_Graph947->SetMinimum(0.245);
   Graph_Graph947->SetMaximum(2.705);
   Graph_Graph947->SetDirectory(0);
   Graph_Graph947->SetStats(0);
   Graph_Graph947->SetLineWidth(2);
   Graph_Graph947->GetXaxis()->SetNdivisions(506);
   Graph_Graph947->GetXaxis()->SetLabelFont(42);
   Graph_Graph947->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph947->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph947->GetXaxis()->SetTitleFont(42);
   Graph_Graph947->GetYaxis()->SetNdivisions(506);
   Graph_Graph947->GetYaxis()->SetLabelFont(42);
   Graph_Graph947->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph947->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph947->GetYaxis()->SetTitleFont(42);
   Graph_Graph947->GetZaxis()->SetNdivisions(506);
   Graph_Graph947->GetZaxis()->SetLabelFont(42);
   Graph_Graph947->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph947->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph947->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph947);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx948[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy948[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx948,Graph_fy948);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph948 = new TH1F("Graph_Graph948","Graph",100,0,0.297);
   Graph_Graph948->SetMinimum(0.418);
   Graph_Graph948->SetMaximum(0.802);
   Graph_Graph948->SetDirectory(0);
   Graph_Graph948->SetStats(0);
   Graph_Graph948->SetLineWidth(2);
   Graph_Graph948->GetXaxis()->SetNdivisions(506);
   Graph_Graph948->GetXaxis()->SetLabelFont(42);
   Graph_Graph948->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph948->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph948->GetXaxis()->SetTitleFont(42);
   Graph_Graph948->GetYaxis()->SetNdivisions(506);
   Graph_Graph948->GetYaxis()->SetLabelFont(42);
   Graph_Graph948->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph948->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph948->GetYaxis()->SetTitleFont(42);
   Graph_Graph948->GetZaxis()->SetNdivisions(506);
   Graph_Graph948->GetZaxis()->SetLabelFont(42);
   Graph_Graph948->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph948->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph948->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph948);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx949[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy949[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx949,Graph_fy949);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph949 = new TH1F("Graph_Graph949","Graph",100,0.252,0.468);
   Graph_Graph949->SetMinimum(0.418);
   Graph_Graph949->SetMaximum(0.802);
   Graph_Graph949->SetDirectory(0);
   Graph_Graph949->SetStats(0);
   Graph_Graph949->SetLineWidth(2);
   Graph_Graph949->GetXaxis()->SetNdivisions(506);
   Graph_Graph949->GetXaxis()->SetLabelFont(42);
   Graph_Graph949->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph949->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph949->GetXaxis()->SetTitleFont(42);
   Graph_Graph949->GetYaxis()->SetNdivisions(506);
   Graph_Graph949->GetYaxis()->SetLabelFont(42);
   Graph_Graph949->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph949->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph949->GetYaxis()->SetTitleFont(42);
   Graph_Graph949->GetZaxis()->SetNdivisions(506);
   Graph_Graph949->GetZaxis()->SetLabelFont(42);
   Graph_Graph949->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph949->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph949->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph949);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx950[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy950[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx950,Graph_fy950);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph950 = new TH1F("Graph_Graph950","Graph",100,0.433,0.637);
   Graph_Graph950->SetMinimum(0.418);
   Graph_Graph950->SetMaximum(0.802);
   Graph_Graph950->SetDirectory(0);
   Graph_Graph950->SetStats(0);
   Graph_Graph950->SetLineWidth(2);
   Graph_Graph950->GetXaxis()->SetNdivisions(506);
   Graph_Graph950->GetXaxis()->SetLabelFont(42);
   Graph_Graph950->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph950->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph950->GetXaxis()->SetTitleFont(42);
   Graph_Graph950->GetYaxis()->SetNdivisions(506);
   Graph_Graph950->GetYaxis()->SetLabelFont(42);
   Graph_Graph950->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph950->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph950->GetYaxis()->SetTitleFont(42);
   Graph_Graph950->GetZaxis()->SetNdivisions(506);
   Graph_Graph950->GetZaxis()->SetLabelFont(42);
   Graph_Graph950->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph950->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph950->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph950);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx951[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy951[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx951,Graph_fy951);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph951 = new TH1F("Graph_Graph951","Graph",100,0.606,0.774);
   Graph_Graph951->SetMinimum(0.418);
   Graph_Graph951->SetMaximum(0.802);
   Graph_Graph951->SetDirectory(0);
   Graph_Graph951->SetStats(0);
   Graph_Graph951->SetLineWidth(2);
   Graph_Graph951->GetXaxis()->SetNdivisions(506);
   Graph_Graph951->GetXaxis()->SetLabelFont(42);
   Graph_Graph951->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph951->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph951->GetXaxis()->SetTitleFont(42);
   Graph_Graph951->GetYaxis()->SetNdivisions(506);
   Graph_Graph951->GetYaxis()->SetLabelFont(42);
   Graph_Graph951->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph951->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph951->GetYaxis()->SetTitleFont(42);
   Graph_Graph951->GetZaxis()->SetNdivisions(506);
   Graph_Graph951->GetZaxis()->SetLabelFont(42);
   Graph_Graph951->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph951->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph951->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph951);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx952[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy952[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx952,Graph_fy952);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph952 = new TH1F("Graph_Graph952","Graph",100,0.75,0.87);
   Graph_Graph952->SetMinimum(0.418);
   Graph_Graph952->SetMaximum(0.802);
   Graph_Graph952->SetDirectory(0);
   Graph_Graph952->SetStats(0);
   Graph_Graph952->SetLineWidth(2);
   Graph_Graph952->GetXaxis()->SetNdivisions(506);
   Graph_Graph952->GetXaxis()->SetLabelFont(42);
   Graph_Graph952->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph952->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph952->GetXaxis()->SetTitleFont(42);
   Graph_Graph952->GetYaxis()->SetNdivisions(506);
   Graph_Graph952->GetYaxis()->SetLabelFont(42);
   Graph_Graph952->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph952->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph952->GetYaxis()->SetTitleFont(42);
   Graph_Graph952->GetZaxis()->SetNdivisions(506);
   Graph_Graph952->GetZaxis()->SetLabelFont(42);
   Graph_Graph952->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph952->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph952->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph952);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx953[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy953[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx953,Graph_fy953);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000c89");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph953 = new TH1F("Graph_Graph953","Graph",100,0.852,0.948);
   Graph_Graph953->SetMinimum(0.418);
   Graph_Graph953->SetMaximum(0.802);
   Graph_Graph953->SetDirectory(0);
   Graph_Graph953->SetStats(0);
   Graph_Graph953->SetLineWidth(2);
   Graph_Graph953->GetXaxis()->SetNdivisions(506);
   Graph_Graph953->GetXaxis()->SetLabelFont(42);
   Graph_Graph953->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph953->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph953->GetXaxis()->SetTitleFont(42);
   Graph_Graph953->GetYaxis()->SetNdivisions(506);
   Graph_Graph953->GetYaxis()->SetLabelFont(42);
   Graph_Graph953->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph953->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph953->GetYaxis()->SetTitleFont(42);
   Graph_Graph953->GetZaxis()->SetNdivisions(506);
   Graph_Graph953->GetZaxis()->SetLabelFont(42);
   Graph_Graph953->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph953->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph953->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph953);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx954[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy954[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx954,Graph_fy954);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#007fcf");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph954 = new TH1F("Graph_Graph954","Graph",100,0.934,1.006);
   Graph_Graph954->SetMinimum(0.418);
   Graph_Graph954->SetMaximum(0.802);
   Graph_Graph954->SetDirectory(0);
   Graph_Graph954->SetStats(0);
   Graph_Graph954->SetLineWidth(2);
   Graph_Graph954->GetXaxis()->SetNdivisions(506);
   Graph_Graph954->GetXaxis()->SetLabelFont(42);
   Graph_Graph954->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph954->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph954->GetXaxis()->SetTitleFont(42);
   Graph_Graph954->GetYaxis()->SetNdivisions(506);
   Graph_Graph954->GetYaxis()->SetLabelFont(42);
   Graph_Graph954->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph954->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph954->GetYaxis()->SetTitleFont(42);
   Graph_Graph954->GetZaxis()->SetNdivisions(506);
   Graph_Graph954->GetZaxis()->SetLabelFont(42);
   Graph_Graph954->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph954->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph954->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph954);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx955[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy955[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx955,Graph_fy955);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph955 = new TH1F("Graph_Graph955","Graph",100,0,0.297);
   Graph_Graph955->SetMinimum(0.597);
   Graph_Graph955->SetMaximum(2.673);
   Graph_Graph955->SetDirectory(0);
   Graph_Graph955->SetStats(0);
   Graph_Graph955->SetLineWidth(2);
   Graph_Graph955->GetXaxis()->SetNdivisions(506);
   Graph_Graph955->GetXaxis()->SetLabelFont(42);
   Graph_Graph955->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph955->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph955->GetXaxis()->SetTitleFont(42);
   Graph_Graph955->GetYaxis()->SetNdivisions(506);
   Graph_Graph955->GetYaxis()->SetLabelFont(42);
   Graph_Graph955->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph955->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph955->GetYaxis()->SetTitleFont(42);
   Graph_Graph955->GetZaxis()->SetNdivisions(506);
   Graph_Graph955->GetZaxis()->SetLabelFont(42);
   Graph_Graph955->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph955->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph955->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph955);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx956[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy956[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx956,Graph_fy956);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph956 = new TH1F("Graph_Graph956","Graph",100,0.252,0.468);
   Graph_Graph956->SetMinimum(0.597);
   Graph_Graph956->SetMaximum(2.673);
   Graph_Graph956->SetDirectory(0);
   Graph_Graph956->SetStats(0);
   Graph_Graph956->SetLineWidth(2);
   Graph_Graph956->GetXaxis()->SetNdivisions(506);
   Graph_Graph956->GetXaxis()->SetLabelFont(42);
   Graph_Graph956->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph956->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph956->GetXaxis()->SetTitleFont(42);
   Graph_Graph956->GetYaxis()->SetNdivisions(506);
   Graph_Graph956->GetYaxis()->SetLabelFont(42);
   Graph_Graph956->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph956->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph956->GetYaxis()->SetTitleFont(42);
   Graph_Graph956->GetZaxis()->SetNdivisions(506);
   Graph_Graph956->GetZaxis()->SetLabelFont(42);
   Graph_Graph956->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph956->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph956->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph956);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx957[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy957[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx957,Graph_fy957);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph957 = new TH1F("Graph_Graph957","Graph",100,0.433,0.637);
   Graph_Graph957->SetMinimum(0.597);
   Graph_Graph957->SetMaximum(2.673);
   Graph_Graph957->SetDirectory(0);
   Graph_Graph957->SetStats(0);
   Graph_Graph957->SetLineWidth(2);
   Graph_Graph957->GetXaxis()->SetNdivisions(506);
   Graph_Graph957->GetXaxis()->SetLabelFont(42);
   Graph_Graph957->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph957->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph957->GetXaxis()->SetTitleFont(42);
   Graph_Graph957->GetYaxis()->SetNdivisions(506);
   Graph_Graph957->GetYaxis()->SetLabelFont(42);
   Graph_Graph957->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph957->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph957->GetYaxis()->SetTitleFont(42);
   Graph_Graph957->GetZaxis()->SetNdivisions(506);
   Graph_Graph957->GetZaxis()->SetLabelFont(42);
   Graph_Graph957->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph957->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph957->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph957);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx958[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy958[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx958,Graph_fy958);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph958 = new TH1F("Graph_Graph958","Graph",100,0.606,0.774);
   Graph_Graph958->SetMinimum(0.597);
   Graph_Graph958->SetMaximum(2.673);
   Graph_Graph958->SetDirectory(0);
   Graph_Graph958->SetStats(0);
   Graph_Graph958->SetLineWidth(2);
   Graph_Graph958->GetXaxis()->SetNdivisions(506);
   Graph_Graph958->GetXaxis()->SetLabelFont(42);
   Graph_Graph958->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph958->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph958->GetXaxis()->SetTitleFont(42);
   Graph_Graph958->GetYaxis()->SetNdivisions(506);
   Graph_Graph958->GetYaxis()->SetLabelFont(42);
   Graph_Graph958->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph958->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph958->GetYaxis()->SetTitleFont(42);
   Graph_Graph958->GetZaxis()->SetNdivisions(506);
   Graph_Graph958->GetZaxis()->SetLabelFont(42);
   Graph_Graph958->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph958->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph958->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph958);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx959[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy959[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx959,Graph_fy959);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph959 = new TH1F("Graph_Graph959","Graph",100,0.75,0.87);
   Graph_Graph959->SetMinimum(0.597);
   Graph_Graph959->SetMaximum(2.673);
   Graph_Graph959->SetDirectory(0);
   Graph_Graph959->SetStats(0);
   Graph_Graph959->SetLineWidth(2);
   Graph_Graph959->GetXaxis()->SetNdivisions(506);
   Graph_Graph959->GetXaxis()->SetLabelFont(42);
   Graph_Graph959->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph959->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph959->GetXaxis()->SetTitleFont(42);
   Graph_Graph959->GetYaxis()->SetNdivisions(506);
   Graph_Graph959->GetYaxis()->SetLabelFont(42);
   Graph_Graph959->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph959->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph959->GetYaxis()->SetTitleFont(42);
   Graph_Graph959->GetZaxis()->SetNdivisions(506);
   Graph_Graph959->GetZaxis()->SetLabelFont(42);
   Graph_Graph959->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph959->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph959->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph959);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx960[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy960[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx960,Graph_fy960);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0037a3");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph960 = new TH1F("Graph_Graph960","Graph",100,0.852,0.948);
   Graph_Graph960->SetMinimum(0.597);
   Graph_Graph960->SetMaximum(2.673);
   Graph_Graph960->SetDirectory(0);
   Graph_Graph960->SetStats(0);
   Graph_Graph960->SetLineWidth(2);
   Graph_Graph960->GetXaxis()->SetNdivisions(506);
   Graph_Graph960->GetXaxis()->SetLabelFont(42);
   Graph_Graph960->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph960->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph960->GetXaxis()->SetTitleFont(42);
   Graph_Graph960->GetYaxis()->SetNdivisions(506);
   Graph_Graph960->GetYaxis()->SetLabelFont(42);
   Graph_Graph960->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph960->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph960->GetYaxis()->SetTitleFont(42);
   Graph_Graph960->GetZaxis()->SetNdivisions(506);
   Graph_Graph960->GetZaxis()->SetLabelFont(42);
   Graph_Graph960->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph960->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph960->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph960);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx961[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy961[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx961,Graph_fy961);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph961 = new TH1F("Graph_Graph961","Graph",100,0.934,1.006);
   Graph_Graph961->SetMinimum(0.597);
   Graph_Graph961->SetMaximum(2.673);
   Graph_Graph961->SetDirectory(0);
   Graph_Graph961->SetStats(0);
   Graph_Graph961->SetLineWidth(2);
   Graph_Graph961->GetXaxis()->SetNdivisions(506);
   Graph_Graph961->GetXaxis()->SetLabelFont(42);
   Graph_Graph961->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph961->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph961->GetXaxis()->SetTitleFont(42);
   Graph_Graph961->GetYaxis()->SetNdivisions(506);
   Graph_Graph961->GetYaxis()->SetLabelFont(42);
   Graph_Graph961->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph961->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph961->GetYaxis()->SetTitleFont(42);
   Graph_Graph961->GetZaxis()->SetNdivisions(506);
   Graph_Graph961->GetZaxis()->SetLabelFont(42);
   Graph_Graph961->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph961->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph961->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph961);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.0006804294);
   _reco_per_true->SetBinContent(2,0.0006625267);
   _reco_per_true->SetBinContent(7,0.0006779021);
   _reco_per_true->SetBinContent(8,0.001341357);
   _reco_per_true->SetBinContent(10,0.001361426);
   _reco_per_true->SetBinContent(13,0.0006812235);
   _reco_per_true->SetBinContent(15,0.0006810045);
   _reco_per_true->SetBinContent(16,0.01278865);
   _reco_per_true->SetBinContent(17,0.004096341);
   _reco_per_true->SetBinContent(20,0.0006326627);
   _reco_per_true->SetBinContent(22,0.0006827862);
   _reco_per_true->SetBinContent(23,0.01563039);
   _reco_per_true->SetBinContent(24,0.1545546);
   _reco_per_true->SetBinContent(25,0.001356086);
   _reco_per_true->SetBinContent(26,0.001365583);
   _reco_per_true->SetBinContent(27,0.0006728457);
   _reco_per_true->SetBinContent(29,0.001317733);
   _reco_per_true->SetBinContent(30,0.06752792);
   _reco_per_true->SetBinContent(31,0.7332885);
   _reco_per_true->SetBinError(1,0.0006804294);
   _reco_per_true->SetBinError(2,0.0006625267);
   _reco_per_true->SetBinError(7,0.0006779021);
   _reco_per_true->SetBinError(8,0.0009485529);
   _reco_per_true->SetBinError(10,0.000962674);
   _reco_per_true->SetBinError(13,0.0006812235);
   _reco_per_true->SetBinError(15,0.0006810045);
   _reco_per_true->SetBinError(16,0.002935563);
   _reco_per_true->SetBinError(17,0.001672325);
   _reco_per_true->SetBinError(20,0.0006326627);
   _reco_per_true->SetBinError(22,0.0006827862);
   _reco_per_true->SetBinError(23,0.003259304);
   _reco_per_true->SetBinError(24,0.01023757);
   _reco_per_true->SetBinError(25,0.0009589129);
   _reco_per_true->SetBinError(26,0.0009656152);
   _reco_per_true->SetBinError(27,0.0006728457);
   _reco_per_true->SetBinError(29,0.000932475);
   _reco_per_true->SetBinError(30,0.006754456);
   _reco_per_true->SetBinError(31,0.02223798);
   _reco_per_true->SetEntries(1482);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.002875641);
   _reco_per_true->SetContourLevel(2,0.005751282);
   _reco_per_true->SetContourLevel(3,0.008626923);
   _reco_per_true->SetContourLevel(4,0.01150256);
   _reco_per_true->SetContourLevel(5,0.01437821);
   _reco_per_true->SetContourLevel(6,0.01725385);
   _reco_per_true->SetContourLevel(7,0.02012949);
   _reco_per_true->SetContourLevel(8,0.02300513);
   _reco_per_true->SetContourLevel(9,0.02588077);
   _reco_per_true->SetContourLevel(10,0.02875641);
   _reco_per_true->SetContourLevel(11,0.03163205);
   _reco_per_true->SetContourLevel(12,0.03450769);
   _reco_per_true->SetContourLevel(13,0.03738333);
   _reco_per_true->SetContourLevel(14,0.04025898);
   _reco_per_true->SetContourLevel(15,0.04313462);
   _reco_per_true->SetContourLevel(16,0.04601026);
   _reco_per_true->SetContourLevel(17,0.0488859);
   _reco_per_true->SetContourLevel(18,0.05176154);
   _reco_per_true->SetContourLevel(19,0.05463718);
   _reco_per_true->SetContourLevel(20,0.05751282);
   _reco_per_true->SetContourLevel(21,0.06038846);
   _reco_per_true->SetContourLevel(22,0.06326411);
   _reco_per_true->SetContourLevel(23,0.06613975);
   _reco_per_true->SetContourLevel(24,0.06901539);
   _reco_per_true->SetContourLevel(25,0.07189103);
   _reco_per_true->SetContourLevel(26,0.07476667);
   _reco_per_true->SetContourLevel(27,0.07764231);
   _reco_per_true->SetContourLevel(28,0.08051795);
   _reco_per_true->SetContourLevel(29,0.08339359);
   _reco_per_true->SetContourLevel(30,0.08626923);
   _reco_per_true->SetContourLevel(31,0.08914488);
   _reco_per_true->SetContourLevel(32,0.09202052);
   _reco_per_true->SetContourLevel(33,0.09489616);
   _reco_per_true->SetContourLevel(34,0.0977718);
   _reco_per_true->SetContourLevel(35,0.1006474);
   _reco_per_true->SetContourLevel(36,0.1035231);
   _reco_per_true->SetContourLevel(37,0.1063987);
   _reco_per_true->SetContourLevel(38,0.1092744);
   _reco_per_true->SetContourLevel(39,0.11215);
   _reco_per_true->SetContourLevel(40,0.1150256);
   _reco_per_true->SetContourLevel(41,0.1179013);
   _reco_per_true->SetContourLevel(42,0.1207769);
   _reco_per_true->SetContourLevel(43,0.1236526);
   _reco_per_true->SetContourLevel(44,0.1265282);
   _reco_per_true->SetContourLevel(45,0.1294039);
   _reco_per_true->SetContourLevel(46,0.1322795);
   _reco_per_true->SetContourLevel(47,0.1351551);
   _reco_per_true->SetContourLevel(48,0.1380308);
   _reco_per_true->SetContourLevel(49,0.1409064);
   _reco_per_true->SetContourLevel(50,0.1437821);
   _reco_per_true->SetContourLevel(51,0.1466577);
   _reco_per_true->SetContourLevel(52,0.1495333);
   _reco_per_true->SetContourLevel(53,0.152409);
   _reco_per_true->SetContourLevel(54,0.1552846);
   _reco_per_true->SetContourLevel(55,0.1581603);
   _reco_per_true->SetContourLevel(56,0.1610359);
   _reco_per_true->SetContourLevel(57,0.1639115);
   _reco_per_true->SetContourLevel(58,0.1667872);
   _reco_per_true->SetContourLevel(59,0.1696628);
   _reco_per_true->SetContourLevel(60,0.1725385);
   _reco_per_true->SetContourLevel(61,0.1754141);
   _reco_per_true->SetContourLevel(62,0.1782898);
   _reco_per_true->SetContourLevel(63,0.1811654);
   _reco_per_true->SetContourLevel(64,0.184041);
   _reco_per_true->SetContourLevel(65,0.1869167);
   _reco_per_true->SetContourLevel(66,0.1897923);
   _reco_per_true->SetContourLevel(67,0.192668);
   _reco_per_true->SetContourLevel(68,0.1955436);
   _reco_per_true->SetContourLevel(69,0.1984192);
   _reco_per_true->SetContourLevel(70,0.2012949);
   _reco_per_true->SetContourLevel(71,0.2041705);
   _reco_per_true->SetContourLevel(72,0.2070462);
   _reco_per_true->SetContourLevel(73,0.2099218);
   _reco_per_true->SetContourLevel(74,0.2127974);
   _reco_per_true->SetContourLevel(75,0.2156731);
   _reco_per_true->SetContourLevel(76,0.2185487);
   _reco_per_true->SetContourLevel(77,0.2214244);
   _reco_per_true->SetContourLevel(78,0.2243);
   _reco_per_true->SetContourLevel(79,0.2271756);
   _reco_per_true->SetContourLevel(80,0.2300513);
   _reco_per_true->SetContourLevel(81,0.2329269);
   _reco_per_true->SetContourLevel(82,0.2358026);
   _reco_per_true->SetContourLevel(83,0.2386782);
   _reco_per_true->SetContourLevel(84,0.2415539);
   _reco_per_true->SetContourLevel(85,0.2444295);
   _reco_per_true->SetContourLevel(86,0.2473051);
   _reco_per_true->SetContourLevel(87,0.2501808);
   _reco_per_true->SetContourLevel(88,0.2530564);
   _reco_per_true->SetContourLevel(89,0.2559321);
   _reco_per_true->SetContourLevel(90,0.2588077);
   _reco_per_true->SetContourLevel(91,0.2616833);
   _reco_per_true->SetContourLevel(92,0.264559);
   _reco_per_true->SetContourLevel(93,0.2674346);
   _reco_per_true->SetContourLevel(94,0.2703103);
   _reco_per_true->SetContourLevel(95,0.2731859);
   _reco_per_true->SetContourLevel(96,0.2760615);
   _reco_per_true->SetContourLevel(97,0.2789372);
   _reco_per_true->SetContourLevel(98,0.2818128);
   _reco_per_true->SetContourLevel(99,0.2846885);
   _reco_per_true->SetContourLevel(100,0.2875641);
   _reco_per_true->SetContourLevel(101,0.2904398);
   _reco_per_true->SetContourLevel(102,0.2933154);
   _reco_per_true->SetContourLevel(103,0.296191);
   _reco_per_true->SetContourLevel(104,0.2990667);
   _reco_per_true->SetContourLevel(105,0.3019423);
   _reco_per_true->SetContourLevel(106,0.304818);
   _reco_per_true->SetContourLevel(107,0.3076936);
   _reco_per_true->SetContourLevel(108,0.3105692);
   _reco_per_true->SetContourLevel(109,0.3134449);
   _reco_per_true->SetContourLevel(110,0.3163205);
   _reco_per_true->SetContourLevel(111,0.3191962);
   _reco_per_true->SetContourLevel(112,0.3220718);
   _reco_per_true->SetContourLevel(113,0.3249474);
   _reco_per_true->SetContourLevel(114,0.3278231);
   _reco_per_true->SetContourLevel(115,0.3306987);
   _reco_per_true->SetContourLevel(116,0.3335744);
   _reco_per_true->SetContourLevel(117,0.33645);
   _reco_per_true->SetContourLevel(118,0.3393257);
   _reco_per_true->SetContourLevel(119,0.3422013);
   _reco_per_true->SetContourLevel(120,0.3450769);
   _reco_per_true->SetContourLevel(121,0.3479526);
   _reco_per_true->SetContourLevel(122,0.3508282);
   _reco_per_true->SetContourLevel(123,0.3537039);
   _reco_per_true->SetContourLevel(124,0.3565795);
   _reco_per_true->SetContourLevel(125,0.3594551);
   _reco_per_true->SetContourLevel(126,0.3623308);
   _reco_per_true->SetContourLevel(127,0.3652064);
   _reco_per_true->SetContourLevel(128,0.3680821);
   _reco_per_true->SetContourLevel(129,0.3709577);
   _reco_per_true->SetContourLevel(130,0.3738333);
   _reco_per_true->SetContourLevel(131,0.376709);
   _reco_per_true->SetContourLevel(132,0.3795846);
   _reco_per_true->SetContourLevel(133,0.3824603);
   _reco_per_true->SetContourLevel(134,0.3853359);
   _reco_per_true->SetContourLevel(135,0.3882116);
   _reco_per_true->SetContourLevel(136,0.3910872);
   _reco_per_true->SetContourLevel(137,0.3939628);
   _reco_per_true->SetContourLevel(138,0.3968385);
   _reco_per_true->SetContourLevel(139,0.3997141);
   _reco_per_true->SetContourLevel(140,0.4025898);
   _reco_per_true->SetContourLevel(141,0.4054654);
   _reco_per_true->SetContourLevel(142,0.408341);
   _reco_per_true->SetContourLevel(143,0.4112167);
   _reco_per_true->SetContourLevel(144,0.4140923);
   _reco_per_true->SetContourLevel(145,0.416968);
   _reco_per_true->SetContourLevel(146,0.4198436);
   _reco_per_true->SetContourLevel(147,0.4227192);
   _reco_per_true->SetContourLevel(148,0.4255949);
   _reco_per_true->SetContourLevel(149,0.4284705);
   _reco_per_true->SetContourLevel(150,0.4313462);
   _reco_per_true->SetContourLevel(151,0.4342218);
   _reco_per_true->SetContourLevel(152,0.4370975);
   _reco_per_true->SetContourLevel(153,0.4399731);
   _reco_per_true->SetContourLevel(154,0.4428487);
   _reco_per_true->SetContourLevel(155,0.4457244);
   _reco_per_true->SetContourLevel(156,0.4486);
   _reco_per_true->SetContourLevel(157,0.4514757);
   _reco_per_true->SetContourLevel(158,0.4543513);
   _reco_per_true->SetContourLevel(159,0.4572269);
   _reco_per_true->SetContourLevel(160,0.4601026);
   _reco_per_true->SetContourLevel(161,0.4629782);
   _reco_per_true->SetContourLevel(162,0.4658539);
   _reco_per_true->SetContourLevel(163,0.4687295);
   _reco_per_true->SetContourLevel(164,0.4716051);
   _reco_per_true->SetContourLevel(165,0.4744808);
   _reco_per_true->SetContourLevel(166,0.4773564);
   _reco_per_true->SetContourLevel(167,0.4802321);
   _reco_per_true->SetContourLevel(168,0.4831077);
   _reco_per_true->SetContourLevel(169,0.4859834);
   _reco_per_true->SetContourLevel(170,0.488859);
   _reco_per_true->SetContourLevel(171,0.4917346);
   _reco_per_true->SetContourLevel(172,0.4946103);
   _reco_per_true->SetContourLevel(173,0.4974859);
   _reco_per_true->SetContourLevel(174,0.5003616);
   _reco_per_true->SetContourLevel(175,0.5032372);
   _reco_per_true->SetContourLevel(176,0.5061128);
   _reco_per_true->SetContourLevel(177,0.5089885);
   _reco_per_true->SetContourLevel(178,0.5118641);
   _reco_per_true->SetContourLevel(179,0.5147398);
   _reco_per_true->SetContourLevel(180,0.5176154);
   _reco_per_true->SetContourLevel(181,0.520491);
   _reco_per_true->SetContourLevel(182,0.5233667);
   _reco_per_true->SetContourLevel(183,0.5262423);
   _reco_per_true->SetContourLevel(184,0.529118);
   _reco_per_true->SetContourLevel(185,0.5319936);
   _reco_per_true->SetContourLevel(186,0.5348693);
   _reco_per_true->SetContourLevel(187,0.5377449);
   _reco_per_true->SetContourLevel(188,0.5406205);
   _reco_per_true->SetContourLevel(189,0.5434962);
   _reco_per_true->SetContourLevel(190,0.5463718);
   _reco_per_true->SetContourLevel(191,0.5492475);
   _reco_per_true->SetContourLevel(192,0.5521231);
   _reco_per_true->SetContourLevel(193,0.5549987);
   _reco_per_true->SetContourLevel(194,0.5578744);
   _reco_per_true->SetContourLevel(195,0.56075);
   _reco_per_true->SetContourLevel(196,0.5636257);
   _reco_per_true->SetContourLevel(197,0.5665013);
   _reco_per_true->SetContourLevel(198,0.5693769);
   _reco_per_true->SetContourLevel(199,0.5722526);
   _reco_per_true->SetContourLevel(200,0.5751282);
   _reco_per_true->SetContourLevel(201,0.5780039);
   _reco_per_true->SetContourLevel(202,0.5808795);
   _reco_per_true->SetContourLevel(203,0.5837552);
   _reco_per_true->SetContourLevel(204,0.5866308);
   _reco_per_true->SetContourLevel(205,0.5895064);
   _reco_per_true->SetContourLevel(206,0.5923821);
   _reco_per_true->SetContourLevel(207,0.5952577);
   _reco_per_true->SetContourLevel(208,0.5981334);
   _reco_per_true->SetContourLevel(209,0.601009);
   _reco_per_true->SetContourLevel(210,0.6038846);
   _reco_per_true->SetContourLevel(211,0.6067603);
   _reco_per_true->SetContourLevel(212,0.6096359);
   _reco_per_true->SetContourLevel(213,0.6125116);
   _reco_per_true->SetContourLevel(214,0.6153872);
   _reco_per_true->SetContourLevel(215,0.6182628);
   _reco_per_true->SetContourLevel(216,0.6211385);
   _reco_per_true->SetContourLevel(217,0.6240141);
   _reco_per_true->SetContourLevel(218,0.6268898);
   _reco_per_true->SetContourLevel(219,0.6297654);
   _reco_per_true->SetContourLevel(220,0.6326411);
   _reco_per_true->SetContourLevel(221,0.6355167);
   _reco_per_true->SetContourLevel(222,0.6383923);
   _reco_per_true->SetContourLevel(223,0.641268);
   _reco_per_true->SetContourLevel(224,0.6441436);
   _reco_per_true->SetContourLevel(225,0.6470193);
   _reco_per_true->SetContourLevel(226,0.6498949);
   _reco_per_true->SetContourLevel(227,0.6527705);
   _reco_per_true->SetContourLevel(228,0.6556462);
   _reco_per_true->SetContourLevel(229,0.6585218);
   _reco_per_true->SetContourLevel(230,0.6613975);
   _reco_per_true->SetContourLevel(231,0.6642731);
   _reco_per_true->SetContourLevel(232,0.6671487);
   _reco_per_true->SetContourLevel(233,0.6700244);
   _reco_per_true->SetContourLevel(234,0.6729);
   _reco_per_true->SetContourLevel(235,0.6757757);
   _reco_per_true->SetContourLevel(236,0.6786513);
   _reco_per_true->SetContourLevel(237,0.6815269);
   _reco_per_true->SetContourLevel(238,0.6844026);
   _reco_per_true->SetContourLevel(239,0.6872782);
   _reco_per_true->SetContourLevel(240,0.6901539);
   _reco_per_true->SetContourLevel(241,0.6930295);
   _reco_per_true->SetContourLevel(242,0.6959052);
   _reco_per_true->SetContourLevel(243,0.6987808);
   _reco_per_true->SetContourLevel(244,0.7016564);
   _reco_per_true->SetContourLevel(245,0.7045321);
   _reco_per_true->SetContourLevel(246,0.7074077);
   _reco_per_true->SetContourLevel(247,0.7102834);
   _reco_per_true->SetContourLevel(248,0.713159);
   _reco_per_true->SetContourLevel(249,0.7160346);
   _reco_per_true->SetContourLevel(250,0.7189103);
   _reco_per_true->SetContourLevel(251,0.7217859);
   _reco_per_true->SetContourLevel(252,0.7246616);
   _reco_per_true->SetContourLevel(253,0.7275372);
   _reco_per_true->SetContourLevel(254,0.7304128);
   
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
   TText *AText = pt->AddText("True Bin 30");
   pt->Draw();
   c1_n31->Modified();
   c1_n31->cd();
   c1_n31->SetSelected(c1_n31);
}

void smearing_matrix_true_6()
{
//=========Macro generated from canvas: c1_n7/c1_n7
//=========  (Sat Sep 22 12:03:54 2018) by ROOT version6.06/06
   TCanvas *c1_n7 = new TCanvas("c1_n7", "c1_n7",10,45,700,500);
   gStyle->SetOptStat(0);
   c1_n7->SetHighLightColor(2);
   c1_n7->Range(-1.25,-0.3125,1.25,2.8125);
   c1_n7->SetFillColor(10);
   c1_n7->SetBorderMode(0);
   c1_n7->SetBorderSize(2);
   c1_n7->SetFrameLineWidth(2);
   c1_n7->SetFrameBorderMode(0);
   c1_n7->SetFrameLineWidth(2);
   c1_n7->SetFrameBorderMode(0);
   
   DataTypes::UBTH2Poly *_reco_per_true = new DataTypes::UBTH2Poly("_reco_per_true", "True Bin 6", 25, -1, 1, 25, 0, 2.5);
   
   Double_t Graph_fx187[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy187[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   TGraph *graph = new TGraph(5,Graph_fx187,Graph_fy187);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0051b3");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph187 = new TH1F("Graph_Graph187","Graph",100,-1.1,0);
   Graph_Graph187->SetMinimum(0);
   Graph_Graph187->SetMaximum(0.33);
   Graph_Graph187->SetDirectory(0);
   Graph_Graph187->SetStats(0);
   Graph_Graph187->SetLineWidth(2);
   Graph_Graph187->GetXaxis()->SetNdivisions(506);
   Graph_Graph187->GetXaxis()->SetLabelFont(42);
   Graph_Graph187->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph187->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph187->GetXaxis()->SetTitleFont(42);
   Graph_Graph187->GetYaxis()->SetNdivisions(506);
   Graph_Graph187->GetYaxis()->SetLabelFont(42);
   Graph_Graph187->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph187->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph187->GetYaxis()->SetTitleFont(42);
   Graph_Graph187->GetZaxis()->SetNdivisions(506);
   Graph_Graph187->GetZaxis()->SetLabelFont(42);
   Graph_Graph187->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph187->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph187->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph187);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx188[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy188[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx188,Graph_fy188);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph188 = new TH1F("Graph_Graph188","Graph",100,0,0.297);
   Graph_Graph188->SetMinimum(0);
   Graph_Graph188->SetMaximum(0.33);
   Graph_Graph188->SetDirectory(0);
   Graph_Graph188->SetStats(0);
   Graph_Graph188->SetLineWidth(2);
   Graph_Graph188->GetXaxis()->SetNdivisions(506);
   Graph_Graph188->GetXaxis()->SetLabelFont(42);
   Graph_Graph188->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph188->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph188->GetXaxis()->SetTitleFont(42);
   Graph_Graph188->GetYaxis()->SetNdivisions(506);
   Graph_Graph188->GetYaxis()->SetLabelFont(42);
   Graph_Graph188->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph188->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph188->GetYaxis()->SetTitleFont(42);
   Graph_Graph188->GetZaxis()->SetNdivisions(506);
   Graph_Graph188->GetZaxis()->SetLabelFont(42);
   Graph_Graph188->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph188->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph188->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph188);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx189[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy189[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx189,Graph_fy189);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph189 = new TH1F("Graph_Graph189","Graph",100,0.252,0.468);
   Graph_Graph189->SetMinimum(0);
   Graph_Graph189->SetMaximum(0.33);
   Graph_Graph189->SetDirectory(0);
   Graph_Graph189->SetStats(0);
   Graph_Graph189->SetLineWidth(2);
   Graph_Graph189->GetXaxis()->SetNdivisions(506);
   Graph_Graph189->GetXaxis()->SetLabelFont(42);
   Graph_Graph189->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph189->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph189->GetXaxis()->SetTitleFont(42);
   Graph_Graph189->GetYaxis()->SetNdivisions(506);
   Graph_Graph189->GetYaxis()->SetLabelFont(42);
   Graph_Graph189->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph189->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph189->GetYaxis()->SetTitleFont(42);
   Graph_Graph189->GetZaxis()->SetNdivisions(506);
   Graph_Graph189->GetZaxis()->SetLabelFont(42);
   Graph_Graph189->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph189->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph189->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph189);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx190[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy190[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx190,Graph_fy190);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0037a3");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph190 = new TH1F("Graph_Graph190","Graph",100,0.433,0.637);
   Graph_Graph190->SetMinimum(0);
   Graph_Graph190->SetMaximum(0.33);
   Graph_Graph190->SetDirectory(0);
   Graph_Graph190->SetStats(0);
   Graph_Graph190->SetLineWidth(2);
   Graph_Graph190->GetXaxis()->SetNdivisions(506);
   Graph_Graph190->GetXaxis()->SetLabelFont(42);
   Graph_Graph190->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph190->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph190->GetXaxis()->SetTitleFont(42);
   Graph_Graph190->GetYaxis()->SetNdivisions(506);
   Graph_Graph190->GetYaxis()->SetLabelFont(42);
   Graph_Graph190->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph190->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph190->GetYaxis()->SetTitleFont(42);
   Graph_Graph190->GetZaxis()->SetNdivisions(506);
   Graph_Graph190->GetZaxis()->SetLabelFont(42);
   Graph_Graph190->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph190->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph190->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph190);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx191[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy191[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx191,Graph_fy191);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001a92");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph191 = new TH1F("Graph_Graph191","Graph",100,0.606,0.774);
   Graph_Graph191->SetMinimum(0);
   Graph_Graph191->SetMaximum(0.33);
   Graph_Graph191->SetDirectory(0);
   Graph_Graph191->SetStats(0);
   Graph_Graph191->SetLineWidth(2);
   Graph_Graph191->GetXaxis()->SetNdivisions(506);
   Graph_Graph191->GetXaxis()->SetLabelFont(42);
   Graph_Graph191->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph191->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph191->GetXaxis()->SetTitleFont(42);
   Graph_Graph191->GetYaxis()->SetNdivisions(506);
   Graph_Graph191->GetYaxis()->SetLabelFont(42);
   Graph_Graph191->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph191->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph191->GetYaxis()->SetTitleFont(42);
   Graph_Graph191->GetZaxis()->SetNdivisions(506);
   Graph_Graph191->GetZaxis()->SetLabelFont(42);
   Graph_Graph191->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph191->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph191->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph191);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx192[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy192[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx192,Graph_fy192);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#60e39d");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph192 = new TH1F("Graph_Graph192","Graph",100,0.75,0.87);
   Graph_Graph192->SetMinimum(0);
   Graph_Graph192->SetMaximum(0.33);
   Graph_Graph192->SetDirectory(0);
   Graph_Graph192->SetStats(0);
   Graph_Graph192->SetLineWidth(2);
   Graph_Graph192->GetXaxis()->SetNdivisions(506);
   Graph_Graph192->GetXaxis()->SetLabelFont(42);
   Graph_Graph192->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph192->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph192->GetXaxis()->SetTitleFont(42);
   Graph_Graph192->GetYaxis()->SetNdivisions(506);
   Graph_Graph192->GetYaxis()->SetLabelFont(42);
   Graph_Graph192->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph192->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph192->GetYaxis()->SetTitleFont(42);
   Graph_Graph192->GetZaxis()->SetNdivisions(506);
   Graph_Graph192->GetZaxis()->SetLabelFont(42);
   Graph_Graph192->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph192->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph192->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph192);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx193[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy193[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx193,Graph_fy193);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#850100");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph193 = new TH1F("Graph_Graph193","Graph",100,0.852,0.948);
   Graph_Graph193->SetMinimum(0);
   Graph_Graph193->SetMaximum(0.33);
   Graph_Graph193->SetDirectory(0);
   Graph_Graph193->SetStats(0);
   Graph_Graph193->SetLineWidth(2);
   Graph_Graph193->GetXaxis()->SetNdivisions(506);
   Graph_Graph193->GetXaxis()->SetLabelFont(42);
   Graph_Graph193->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph193->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph193->GetXaxis()->SetTitleFont(42);
   Graph_Graph193->GetYaxis()->SetNdivisions(506);
   Graph_Graph193->GetYaxis()->SetLabelFont(42);
   Graph_Graph193->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph193->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph193->GetYaxis()->SetTitleFont(42);
   Graph_Graph193->GetZaxis()->SetNdivisions(506);
   Graph_Graph193->GetZaxis()->SetLabelFont(42);
   Graph_Graph193->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph193->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph193->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph193);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx194[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy194[5] = {
   0,
   0.3,
   0.3,
   0,
   0};
   graph = new TGraph(5,Graph_fx194,Graph_fy194);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0037a3");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph194 = new TH1F("Graph_Graph194","Graph",100,0.934,1.006);
   Graph_Graph194->SetMinimum(0);
   Graph_Graph194->SetMaximum(0.33);
   Graph_Graph194->SetDirectory(0);
   Graph_Graph194->SetStats(0);
   Graph_Graph194->SetLineWidth(2);
   Graph_Graph194->GetXaxis()->SetNdivisions(506);
   Graph_Graph194->GetXaxis()->SetLabelFont(42);
   Graph_Graph194->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph194->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph194->GetXaxis()->SetTitleFont(42);
   Graph_Graph194->GetYaxis()->SetNdivisions(506);
   Graph_Graph194->GetYaxis()->SetLabelFont(42);
   Graph_Graph194->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph194->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph194->GetYaxis()->SetTitleFont(42);
   Graph_Graph194->GetZaxis()->SetNdivisions(506);
   Graph_Graph194->GetZaxis()->SetLabelFont(42);
   Graph_Graph194->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph194->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph194->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph194);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx195[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy195[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx195,Graph_fy195);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0037a3");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph195 = new TH1F("Graph_Graph195","Graph",100,-1.1,0);
   Graph_Graph195->SetMinimum(0.285);
   Graph_Graph195->SetMaximum(0.465);
   Graph_Graph195->SetDirectory(0);
   Graph_Graph195->SetStats(0);
   Graph_Graph195->SetLineWidth(2);
   Graph_Graph195->GetXaxis()->SetNdivisions(506);
   Graph_Graph195->GetXaxis()->SetLabelFont(42);
   Graph_Graph195->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph195->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph195->GetXaxis()->SetTitleFont(42);
   Graph_Graph195->GetYaxis()->SetNdivisions(506);
   Graph_Graph195->GetYaxis()->SetLabelFont(42);
   Graph_Graph195->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph195->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph195->GetYaxis()->SetTitleFont(42);
   Graph_Graph195->GetZaxis()->SetNdivisions(506);
   Graph_Graph195->GetZaxis()->SetLabelFont(42);
   Graph_Graph195->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph195->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph195->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph195);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx196[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy196[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx196,Graph_fy196);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph196 = new TH1F("Graph_Graph196","Graph",100,0,0.297);
   Graph_Graph196->SetMinimum(0.285);
   Graph_Graph196->SetMaximum(0.465);
   Graph_Graph196->SetDirectory(0);
   Graph_Graph196->SetStats(0);
   Graph_Graph196->SetLineWidth(2);
   Graph_Graph196->GetXaxis()->SetNdivisions(506);
   Graph_Graph196->GetXaxis()->SetLabelFont(42);
   Graph_Graph196->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph196->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph196->GetXaxis()->SetTitleFont(42);
   Graph_Graph196->GetYaxis()->SetNdivisions(506);
   Graph_Graph196->GetYaxis()->SetLabelFont(42);
   Graph_Graph196->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph196->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph196->GetYaxis()->SetTitleFont(42);
   Graph_Graph196->GetZaxis()->SetNdivisions(506);
   Graph_Graph196->GetZaxis()->SetLabelFont(42);
   Graph_Graph196->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph196->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph196->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph196);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx197[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy197[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx197,Graph_fy197);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph197 = new TH1F("Graph_Graph197","Graph",100,0.252,0.468);
   Graph_Graph197->SetMinimum(0.285);
   Graph_Graph197->SetMaximum(0.465);
   Graph_Graph197->SetDirectory(0);
   Graph_Graph197->SetStats(0);
   Graph_Graph197->SetLineWidth(2);
   Graph_Graph197->GetXaxis()->SetNdivisions(506);
   Graph_Graph197->GetXaxis()->SetLabelFont(42);
   Graph_Graph197->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph197->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph197->GetXaxis()->SetTitleFont(42);
   Graph_Graph197->GetYaxis()->SetNdivisions(506);
   Graph_Graph197->GetYaxis()->SetLabelFont(42);
   Graph_Graph197->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph197->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph197->GetYaxis()->SetTitleFont(42);
   Graph_Graph197->GetZaxis()->SetNdivisions(506);
   Graph_Graph197->GetZaxis()->SetLabelFont(42);
   Graph_Graph197->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph197->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph197->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph197);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx198[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy198[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx198,Graph_fy198);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0037a3");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph198 = new TH1F("Graph_Graph198","Graph",100,0.433,0.637);
   Graph_Graph198->SetMinimum(0.285);
   Graph_Graph198->SetMaximum(0.465);
   Graph_Graph198->SetDirectory(0);
   Graph_Graph198->SetStats(0);
   Graph_Graph198->SetLineWidth(2);
   Graph_Graph198->GetXaxis()->SetNdivisions(506);
   Graph_Graph198->GetXaxis()->SetLabelFont(42);
   Graph_Graph198->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph198->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph198->GetXaxis()->SetTitleFont(42);
   Graph_Graph198->GetYaxis()->SetNdivisions(506);
   Graph_Graph198->GetYaxis()->SetLabelFont(42);
   Graph_Graph198->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph198->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph198->GetYaxis()->SetTitleFont(42);
   Graph_Graph198->GetZaxis()->SetNdivisions(506);
   Graph_Graph198->GetZaxis()->SetLabelFont(42);
   Graph_Graph198->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph198->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph198->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph198);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx199[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy199[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx199,Graph_fy199);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph199 = new TH1F("Graph_Graph199","Graph",100,0.606,0.774);
   Graph_Graph199->SetMinimum(0.285);
   Graph_Graph199->SetMaximum(0.465);
   Graph_Graph199->SetDirectory(0);
   Graph_Graph199->SetStats(0);
   Graph_Graph199->SetLineWidth(2);
   Graph_Graph199->GetXaxis()->SetNdivisions(506);
   Graph_Graph199->GetXaxis()->SetLabelFont(42);
   Graph_Graph199->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph199->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph199->GetXaxis()->SetTitleFont(42);
   Graph_Graph199->GetYaxis()->SetNdivisions(506);
   Graph_Graph199->GetYaxis()->SetLabelFont(42);
   Graph_Graph199->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph199->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph199->GetYaxis()->SetTitleFont(42);
   Graph_Graph199->GetZaxis()->SetNdivisions(506);
   Graph_Graph199->GetZaxis()->SetLabelFont(42);
   Graph_Graph199->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph199->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph199->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph199);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx200[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy200[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx200,Graph_fy200);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0037a3");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph200 = new TH1F("Graph_Graph200","Graph",100,0.75,0.87);
   Graph_Graph200->SetMinimum(0.285);
   Graph_Graph200->SetMaximum(0.465);
   Graph_Graph200->SetDirectory(0);
   Graph_Graph200->SetStats(0);
   Graph_Graph200->SetLineWidth(2);
   Graph_Graph200->GetXaxis()->SetNdivisions(506);
   Graph_Graph200->GetXaxis()->SetLabelFont(42);
   Graph_Graph200->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph200->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph200->GetXaxis()->SetTitleFont(42);
   Graph_Graph200->GetYaxis()->SetNdivisions(506);
   Graph_Graph200->GetYaxis()->SetLabelFont(42);
   Graph_Graph200->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph200->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph200->GetYaxis()->SetTitleFont(42);
   Graph_Graph200->GetZaxis()->SetNdivisions(506);
   Graph_Graph200->GetZaxis()->SetLabelFont(42);
   Graph_Graph200->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph200->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph200->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph200);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx201[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy201[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx201,Graph_fy201);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#aaf352");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph201 = new TH1F("Graph_Graph201","Graph",100,0.852,0.948);
   Graph_Graph201->SetMinimum(0.285);
   Graph_Graph201->SetMaximum(0.465);
   Graph_Graph201->SetDirectory(0);
   Graph_Graph201->SetStats(0);
   Graph_Graph201->SetLineWidth(2);
   Graph_Graph201->GetXaxis()->SetNdivisions(506);
   Graph_Graph201->GetXaxis()->SetLabelFont(42);
   Graph_Graph201->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph201->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph201->GetXaxis()->SetTitleFont(42);
   Graph_Graph201->GetYaxis()->SetNdivisions(506);
   Graph_Graph201->GetYaxis()->SetLabelFont(42);
   Graph_Graph201->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph201->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph201->GetYaxis()->SetTitleFont(42);
   Graph_Graph201->GetZaxis()->SetNdivisions(506);
   Graph_Graph201->GetZaxis()->SetLabelFont(42);
   Graph_Graph201->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph201->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph201->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph201);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx202[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy202[5] = {
   0.3,
   0.45,
   0.45,
   0.3,
   0.3};
   graph = new TGraph(5,Graph_fx202,Graph_fy202);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0051b3");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph202 = new TH1F("Graph_Graph202","Graph",100,0.934,1.006);
   Graph_Graph202->SetMinimum(0.285);
   Graph_Graph202->SetMaximum(0.465);
   Graph_Graph202->SetDirectory(0);
   Graph_Graph202->SetStats(0);
   Graph_Graph202->SetLineWidth(2);
   Graph_Graph202->GetXaxis()->SetNdivisions(506);
   Graph_Graph202->GetXaxis()->SetLabelFont(42);
   Graph_Graph202->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph202->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph202->GetXaxis()->SetTitleFont(42);
   Graph_Graph202->GetYaxis()->SetNdivisions(506);
   Graph_Graph202->GetYaxis()->SetLabelFont(42);
   Graph_Graph202->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph202->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph202->GetYaxis()->SetTitleFont(42);
   Graph_Graph202->GetZaxis()->SetNdivisions(506);
   Graph_Graph202->GetZaxis()->SetLabelFont(42);
   Graph_Graph202->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph202->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph202->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph202);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx203[5] = {
   -1,
   -1,
   0,
   0,
   -1};
   Double_t Graph_fy203[5] = {
   0.45,
   2.5,
   2.5,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx203,Graph_fy203);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001a92");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph203 = new TH1F("Graph_Graph203","Graph",100,-1.1,0);
   Graph_Graph203->SetMinimum(0.245);
   Graph_Graph203->SetMaximum(2.705);
   Graph_Graph203->SetDirectory(0);
   Graph_Graph203->SetStats(0);
   Graph_Graph203->SetLineWidth(2);
   Graph_Graph203->GetXaxis()->SetNdivisions(506);
   Graph_Graph203->GetXaxis()->SetLabelFont(42);
   Graph_Graph203->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph203->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph203->GetXaxis()->SetTitleFont(42);
   Graph_Graph203->GetYaxis()->SetNdivisions(506);
   Graph_Graph203->GetYaxis()->SetLabelFont(42);
   Graph_Graph203->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph203->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph203->GetYaxis()->SetTitleFont(42);
   Graph_Graph203->GetZaxis()->SetNdivisions(506);
   Graph_Graph203->GetZaxis()->SetLabelFont(42);
   Graph_Graph203->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph203->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph203->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph203);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx204[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy204[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx204,Graph_fy204);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph204 = new TH1F("Graph_Graph204","Graph",100,0,0.297);
   Graph_Graph204->SetMinimum(0.418);
   Graph_Graph204->SetMaximum(0.802);
   Graph_Graph204->SetDirectory(0);
   Graph_Graph204->SetStats(0);
   Graph_Graph204->SetLineWidth(2);
   Graph_Graph204->GetXaxis()->SetNdivisions(506);
   Graph_Graph204->GetXaxis()->SetLabelFont(42);
   Graph_Graph204->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph204->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph204->GetXaxis()->SetTitleFont(42);
   Graph_Graph204->GetYaxis()->SetNdivisions(506);
   Graph_Graph204->GetYaxis()->SetLabelFont(42);
   Graph_Graph204->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph204->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph204->GetYaxis()->SetTitleFont(42);
   Graph_Graph204->GetZaxis()->SetNdivisions(506);
   Graph_Graph204->GetZaxis()->SetLabelFont(42);
   Graph_Graph204->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph204->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph204->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph204);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx205[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy205[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx205,Graph_fy205);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph205 = new TH1F("Graph_Graph205","Graph",100,0.252,0.468);
   Graph_Graph205->SetMinimum(0.418);
   Graph_Graph205->SetMaximum(0.802);
   Graph_Graph205->SetDirectory(0);
   Graph_Graph205->SetStats(0);
   Graph_Graph205->SetLineWidth(2);
   Graph_Graph205->GetXaxis()->SetNdivisions(506);
   Graph_Graph205->GetXaxis()->SetLabelFont(42);
   Graph_Graph205->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph205->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph205->GetXaxis()->SetTitleFont(42);
   Graph_Graph205->GetYaxis()->SetNdivisions(506);
   Graph_Graph205->GetYaxis()->SetLabelFont(42);
   Graph_Graph205->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph205->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph205->GetYaxis()->SetTitleFont(42);
   Graph_Graph205->GetZaxis()->SetNdivisions(506);
   Graph_Graph205->GetZaxis()->SetLabelFont(42);
   Graph_Graph205->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph205->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph205->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph205);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx206[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy206[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx206,Graph_fy206);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph206 = new TH1F("Graph_Graph206","Graph",100,0.433,0.637);
   Graph_Graph206->SetMinimum(0.418);
   Graph_Graph206->SetMaximum(0.802);
   Graph_Graph206->SetDirectory(0);
   Graph_Graph206->SetStats(0);
   Graph_Graph206->SetLineWidth(2);
   Graph_Graph206->GetXaxis()->SetNdivisions(506);
   Graph_Graph206->GetXaxis()->SetLabelFont(42);
   Graph_Graph206->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph206->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph206->GetXaxis()->SetTitleFont(42);
   Graph_Graph206->GetYaxis()->SetNdivisions(506);
   Graph_Graph206->GetYaxis()->SetLabelFont(42);
   Graph_Graph206->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph206->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph206->GetYaxis()->SetTitleFont(42);
   Graph_Graph206->GetZaxis()->SetNdivisions(506);
   Graph_Graph206->GetZaxis()->SetLabelFont(42);
   Graph_Graph206->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph206->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph206->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph206);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx207[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy207[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx207,Graph_fy207);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph207 = new TH1F("Graph_Graph207","Graph",100,0.606,0.774);
   Graph_Graph207->SetMinimum(0.418);
   Graph_Graph207->SetMaximum(0.802);
   Graph_Graph207->SetDirectory(0);
   Graph_Graph207->SetStats(0);
   Graph_Graph207->SetLineWidth(2);
   Graph_Graph207->GetXaxis()->SetNdivisions(506);
   Graph_Graph207->GetXaxis()->SetLabelFont(42);
   Graph_Graph207->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph207->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph207->GetXaxis()->SetTitleFont(42);
   Graph_Graph207->GetYaxis()->SetNdivisions(506);
   Graph_Graph207->GetYaxis()->SetLabelFont(42);
   Graph_Graph207->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph207->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph207->GetYaxis()->SetTitleFont(42);
   Graph_Graph207->GetZaxis()->SetNdivisions(506);
   Graph_Graph207->GetZaxis()->SetLabelFont(42);
   Graph_Graph207->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph207->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph207->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph207);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx208[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy208[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx208,Graph_fy208);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph208 = new TH1F("Graph_Graph208","Graph",100,0.75,0.87);
   Graph_Graph208->SetMinimum(0.418);
   Graph_Graph208->SetMaximum(0.802);
   Graph_Graph208->SetDirectory(0);
   Graph_Graph208->SetStats(0);
   Graph_Graph208->SetLineWidth(2);
   Graph_Graph208->GetXaxis()->SetNdivisions(506);
   Graph_Graph208->GetXaxis()->SetLabelFont(42);
   Graph_Graph208->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph208->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph208->GetXaxis()->SetTitleFont(42);
   Graph_Graph208->GetYaxis()->SetNdivisions(506);
   Graph_Graph208->GetYaxis()->SetLabelFont(42);
   Graph_Graph208->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph208->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph208->GetYaxis()->SetTitleFont(42);
   Graph_Graph208->GetZaxis()->SetNdivisions(506);
   Graph_Graph208->GetZaxis()->SetLabelFont(42);
   Graph_Graph208->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph208->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph208->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph208);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx209[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy209[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx209,Graph_fy209);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#001a92");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph209 = new TH1F("Graph_Graph209","Graph",100,0.852,0.948);
   Graph_Graph209->SetMinimum(0.418);
   Graph_Graph209->SetMaximum(0.802);
   Graph_Graph209->SetDirectory(0);
   Graph_Graph209->SetStats(0);
   Graph_Graph209->SetLineWidth(2);
   Graph_Graph209->GetXaxis()->SetNdivisions(506);
   Graph_Graph209->GetXaxis()->SetLabelFont(42);
   Graph_Graph209->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph209->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph209->GetXaxis()->SetTitleFont(42);
   Graph_Graph209->GetYaxis()->SetNdivisions(506);
   Graph_Graph209->GetYaxis()->SetLabelFont(42);
   Graph_Graph209->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph209->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph209->GetYaxis()->SetTitleFont(42);
   Graph_Graph209->GetZaxis()->SetNdivisions(506);
   Graph_Graph209->GetZaxis()->SetLabelFont(42);
   Graph_Graph209->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph209->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph209->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph209);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx210[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy210[5] = {
   0.45,
   0.77,
   0.77,
   0.45,
   0.45};
   graph = new TGraph(5,Graph_fx210,Graph_fy210);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph210 = new TH1F("Graph_Graph210","Graph",100,0.934,1.006);
   Graph_Graph210->SetMinimum(0.418);
   Graph_Graph210->SetMaximum(0.802);
   Graph_Graph210->SetDirectory(0);
   Graph_Graph210->SetStats(0);
   Graph_Graph210->SetLineWidth(2);
   Graph_Graph210->GetXaxis()->SetNdivisions(506);
   Graph_Graph210->GetXaxis()->SetLabelFont(42);
   Graph_Graph210->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph210->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph210->GetXaxis()->SetTitleFont(42);
   Graph_Graph210->GetYaxis()->SetNdivisions(506);
   Graph_Graph210->GetYaxis()->SetLabelFont(42);
   Graph_Graph210->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph210->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph210->GetYaxis()->SetTitleFont(42);
   Graph_Graph210->GetZaxis()->SetNdivisions(506);
   Graph_Graph210->GetZaxis()->SetLabelFont(42);
   Graph_Graph210->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph210->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph210->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph210);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx211[5] = {
   0,
   0,
   0.27,
   0.27,
   0};
   Double_t Graph_fy211[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx211,Graph_fy211);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph211 = new TH1F("Graph_Graph211","Graph",100,0,0.297);
   Graph_Graph211->SetMinimum(0.597);
   Graph_Graph211->SetMaximum(2.673);
   Graph_Graph211->SetDirectory(0);
   Graph_Graph211->SetStats(0);
   Graph_Graph211->SetLineWidth(2);
   Graph_Graph211->GetXaxis()->SetNdivisions(506);
   Graph_Graph211->GetXaxis()->SetLabelFont(42);
   Graph_Graph211->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph211->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph211->GetXaxis()->SetTitleFont(42);
   Graph_Graph211->GetYaxis()->SetNdivisions(506);
   Graph_Graph211->GetYaxis()->SetLabelFont(42);
   Graph_Graph211->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph211->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph211->GetYaxis()->SetTitleFont(42);
   Graph_Graph211->GetZaxis()->SetNdivisions(506);
   Graph_Graph211->GetZaxis()->SetLabelFont(42);
   Graph_Graph211->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph211->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph211->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph211);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx212[5] = {
   0.27,
   0.27,
   0.45,
   0.45,
   0.27};
   Double_t Graph_fy212[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx212,Graph_fy212);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph212 = new TH1F("Graph_Graph212","Graph",100,0.252,0.468);
   Graph_Graph212->SetMinimum(0.597);
   Graph_Graph212->SetMaximum(2.673);
   Graph_Graph212->SetDirectory(0);
   Graph_Graph212->SetStats(0);
   Graph_Graph212->SetLineWidth(2);
   Graph_Graph212->GetXaxis()->SetNdivisions(506);
   Graph_Graph212->GetXaxis()->SetLabelFont(42);
   Graph_Graph212->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph212->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph212->GetXaxis()->SetTitleFont(42);
   Graph_Graph212->GetYaxis()->SetNdivisions(506);
   Graph_Graph212->GetYaxis()->SetLabelFont(42);
   Graph_Graph212->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph212->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph212->GetYaxis()->SetTitleFont(42);
   Graph_Graph212->GetZaxis()->SetNdivisions(506);
   Graph_Graph212->GetZaxis()->SetLabelFont(42);
   Graph_Graph212->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph212->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph212->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph212);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx213[5] = {
   0.45,
   0.45,
   0.62,
   0.62,
   0.45};
   Double_t Graph_fy213[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx213,Graph_fy213);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph213 = new TH1F("Graph_Graph213","Graph",100,0.433,0.637);
   Graph_Graph213->SetMinimum(0.597);
   Graph_Graph213->SetMaximum(2.673);
   Graph_Graph213->SetDirectory(0);
   Graph_Graph213->SetStats(0);
   Graph_Graph213->SetLineWidth(2);
   Graph_Graph213->GetXaxis()->SetNdivisions(506);
   Graph_Graph213->GetXaxis()->SetLabelFont(42);
   Graph_Graph213->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph213->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph213->GetXaxis()->SetTitleFont(42);
   Graph_Graph213->GetYaxis()->SetNdivisions(506);
   Graph_Graph213->GetYaxis()->SetLabelFont(42);
   Graph_Graph213->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph213->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph213->GetYaxis()->SetTitleFont(42);
   Graph_Graph213->GetZaxis()->SetNdivisions(506);
   Graph_Graph213->GetZaxis()->SetLabelFont(42);
   Graph_Graph213->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph213->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph213->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph213);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx214[5] = {
   0.62,
   0.62,
   0.76,
   0.76,
   0.62};
   Double_t Graph_fy214[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx214,Graph_fy214);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph214 = new TH1F("Graph_Graph214","Graph",100,0.606,0.774);
   Graph_Graph214->SetMinimum(0.597);
   Graph_Graph214->SetMaximum(2.673);
   Graph_Graph214->SetDirectory(0);
   Graph_Graph214->SetStats(0);
   Graph_Graph214->SetLineWidth(2);
   Graph_Graph214->GetXaxis()->SetNdivisions(506);
   Graph_Graph214->GetXaxis()->SetLabelFont(42);
   Graph_Graph214->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph214->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph214->GetXaxis()->SetTitleFont(42);
   Graph_Graph214->GetYaxis()->SetNdivisions(506);
   Graph_Graph214->GetYaxis()->SetLabelFont(42);
   Graph_Graph214->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph214->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph214->GetYaxis()->SetTitleFont(42);
   Graph_Graph214->GetZaxis()->SetNdivisions(506);
   Graph_Graph214->GetZaxis()->SetLabelFont(42);
   Graph_Graph214->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph214->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph214->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph214);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx215[5] = {
   0.76,
   0.76,
   0.86,
   0.86,
   0.76};
   Double_t Graph_fy215[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx215,Graph_fy215);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph215 = new TH1F("Graph_Graph215","Graph",100,0.75,0.87);
   Graph_Graph215->SetMinimum(0.597);
   Graph_Graph215->SetMaximum(2.673);
   Graph_Graph215->SetDirectory(0);
   Graph_Graph215->SetStats(0);
   Graph_Graph215->SetLineWidth(2);
   Graph_Graph215->GetXaxis()->SetNdivisions(506);
   Graph_Graph215->GetXaxis()->SetLabelFont(42);
   Graph_Graph215->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph215->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph215->GetXaxis()->SetTitleFont(42);
   Graph_Graph215->GetYaxis()->SetNdivisions(506);
   Graph_Graph215->GetYaxis()->SetLabelFont(42);
   Graph_Graph215->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph215->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph215->GetYaxis()->SetTitleFont(42);
   Graph_Graph215->GetZaxis()->SetNdivisions(506);
   Graph_Graph215->GetZaxis()->SetLabelFont(42);
   Graph_Graph215->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph215->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph215->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph215);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx216[5] = {
   0.86,
   0.86,
   0.94,
   0.94,
   0.86};
   Double_t Graph_fy216[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx216,Graph_fy216);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph216 = new TH1F("Graph_Graph216","Graph",100,0.852,0.948);
   Graph_Graph216->SetMinimum(0.597);
   Graph_Graph216->SetMaximum(2.673);
   Graph_Graph216->SetDirectory(0);
   Graph_Graph216->SetStats(0);
   Graph_Graph216->SetLineWidth(2);
   Graph_Graph216->GetXaxis()->SetNdivisions(506);
   Graph_Graph216->GetXaxis()->SetLabelFont(42);
   Graph_Graph216->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph216->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph216->GetXaxis()->SetTitleFont(42);
   Graph_Graph216->GetYaxis()->SetNdivisions(506);
   Graph_Graph216->GetYaxis()->SetLabelFont(42);
   Graph_Graph216->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph216->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph216->GetYaxis()->SetTitleFont(42);
   Graph_Graph216->GetZaxis()->SetNdivisions(506);
   Graph_Graph216->GetZaxis()->SetLabelFont(42);
   Graph_Graph216->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph216->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph216->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph216);
   
   _reco_per_true->AddBin(graph);
   
   Double_t Graph_fx217[5] = {
   0.94,
   0.94,
   1,
   1,
   0.94};
   Double_t Graph_fy217[5] = {
   0.77,
   2.5,
   2.5,
   0.77,
   0.77};
   graph = new TGraph(5,Graph_fx217,Graph_fy217);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#000082");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph217 = new TH1F("Graph_Graph217","Graph",100,0.934,1.006);
   Graph_Graph217->SetMinimum(0.597);
   Graph_Graph217->SetMaximum(2.673);
   Graph_Graph217->SetDirectory(0);
   Graph_Graph217->SetStats(0);
   Graph_Graph217->SetLineWidth(2);
   Graph_Graph217->GetXaxis()->SetNdivisions(506);
   Graph_Graph217->GetXaxis()->SetLabelFont(42);
   Graph_Graph217->GetXaxis()->SetTitleSize(0.055);
   Graph_Graph217->GetXaxis()->SetTitleOffset(0.8);
   Graph_Graph217->GetXaxis()->SetTitleFont(42);
   Graph_Graph217->GetYaxis()->SetNdivisions(506);
   Graph_Graph217->GetYaxis()->SetLabelFont(42);
   Graph_Graph217->GetYaxis()->SetTitleSize(0.055);
   Graph_Graph217->GetYaxis()->SetTitleOffset(0.9);
   Graph_Graph217->GetYaxis()->SetTitleFont(42);
   Graph_Graph217->GetZaxis()->SetNdivisions(506);
   Graph_Graph217->GetZaxis()->SetLabelFont(42);
   Graph_Graph217->GetZaxis()->SetTitleSize(0.055);
   Graph_Graph217->GetZaxis()->SetTitleOffset(0.8);
   Graph_Graph217->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph217);
   
   _reco_per_true->AddBin(graph);
   
   _reco_per_true->SetBinContent(1,0.04780456);
   _reco_per_true->SetBinContent(4,0.03168503);
   _reco_per_true->SetBinContent(5,0.01589312);
   _reco_per_true->SetBinContent(6,0.1587999);
   _reco_per_true->SetBinContent(7,0.348987);
   _reco_per_true->SetBinContent(8,0.0317836);
   _reco_per_true->SetBinContent(9,0.03186739);
   _reco_per_true->SetBinContent(12,0.03169361);
   _reco_per_true->SetBinContent(14,0.0318181);
   _reco_per_true->SetBinContent(15,0.1904202);
   _reco_per_true->SetBinContent(16,0.04766139);
   _reco_per_true->SetBinContent(17,0.01584197);
   _reco_per_true->SetBinContent(23,0.01574422);
   _reco_per_true->SetBinError(1,0.02759997);
   _reco_per_true->SetBinError(4,0.0224047);
   _reco_per_true->SetBinError(5,0.01589312);
   _reco_per_true->SetBinError(6,0.05021712);
   _reco_per_true->SetBinError(7,0.07440491);
   _reco_per_true->SetBinError(8,0.02247451);
   _reco_per_true->SetBinError(9,0.02253368);
   _reco_per_true->SetBinError(12,0.02241092);
   _reco_per_true->SetBinError(14,0.02249882);
   _reco_per_true->SetBinError(15,0.05496987);
   _reco_per_true->SetBinError(16,0.02751739);
   _reco_per_true->SetBinError(17,0.01584197);
   _reco_per_true->SetBinError(23,0.01574422);
   _reco_per_true->SetEntries(63);
   _reco_per_true->SetStats(0);
   _reco_per_true->SetContour(255);
   _reco_per_true->SetContourLevel(0,0);
   _reco_per_true->SetContourLevel(1,0.001368576);
   _reco_per_true->SetContourLevel(2,0.002737153);
   _reco_per_true->SetContourLevel(3,0.004105729);
   _reco_per_true->SetContourLevel(4,0.005474305);
   _reco_per_true->SetContourLevel(5,0.006842882);
   _reco_per_true->SetContourLevel(6,0.008211458);
   _reco_per_true->SetContourLevel(7,0.009580034);
   _reco_per_true->SetContourLevel(8,0.01094861);
   _reco_per_true->SetContourLevel(9,0.01231719);
   _reco_per_true->SetContourLevel(10,0.01368576);
   _reco_per_true->SetContourLevel(11,0.01505434);
   _reco_per_true->SetContourLevel(12,0.01642292);
   _reco_per_true->SetContourLevel(13,0.01779149);
   _reco_per_true->SetContourLevel(14,0.01916007);
   _reco_per_true->SetContourLevel(15,0.02052864);
   _reco_per_true->SetContourLevel(16,0.02189722);
   _reco_per_true->SetContourLevel(17,0.0232658);
   _reco_per_true->SetContourLevel(18,0.02463437);
   _reco_per_true->SetContourLevel(19,0.02600295);
   _reco_per_true->SetContourLevel(20,0.02737153);
   _reco_per_true->SetContourLevel(21,0.0287401);
   _reco_per_true->SetContourLevel(22,0.03010868);
   _reco_per_true->SetContourLevel(23,0.03147726);
   _reco_per_true->SetContourLevel(24,0.03284583);
   _reco_per_true->SetContourLevel(25,0.03421441);
   _reco_per_true->SetContourLevel(26,0.03558298);
   _reco_per_true->SetContourLevel(27,0.03695156);
   _reco_per_true->SetContourLevel(28,0.03832014);
   _reco_per_true->SetContourLevel(29,0.03968871);
   _reco_per_true->SetContourLevel(30,0.04105729);
   _reco_per_true->SetContourLevel(31,0.04242587);
   _reco_per_true->SetContourLevel(32,0.04379444);
   _reco_per_true->SetContourLevel(33,0.04516302);
   _reco_per_true->SetContourLevel(34,0.0465316);
   _reco_per_true->SetContourLevel(35,0.04790017);
   _reco_per_true->SetContourLevel(36,0.04926875);
   _reco_per_true->SetContourLevel(37,0.05063732);
   _reco_per_true->SetContourLevel(38,0.0520059);
   _reco_per_true->SetContourLevel(39,0.05337448);
   _reco_per_true->SetContourLevel(40,0.05474305);
   _reco_per_true->SetContourLevel(41,0.05611163);
   _reco_per_true->SetContourLevel(42,0.05748021);
   _reco_per_true->SetContourLevel(43,0.05884878);
   _reco_per_true->SetContourLevel(44,0.06021736);
   _reco_per_true->SetContourLevel(45,0.06158593);
   _reco_per_true->SetContourLevel(46,0.06295451);
   _reco_per_true->SetContourLevel(47,0.06432309);
   _reco_per_true->SetContourLevel(48,0.06569166);
   _reco_per_true->SetContourLevel(49,0.06706024);
   _reco_per_true->SetContourLevel(50,0.06842882);
   _reco_per_true->SetContourLevel(51,0.06979739);
   _reco_per_true->SetContourLevel(52,0.07116597);
   _reco_per_true->SetContourLevel(53,0.07253455);
   _reco_per_true->SetContourLevel(54,0.07390312);
   _reco_per_true->SetContourLevel(55,0.0752717);
   _reco_per_true->SetContourLevel(56,0.07664027);
   _reco_per_true->SetContourLevel(57,0.07800885);
   _reco_per_true->SetContourLevel(58,0.07937743);
   _reco_per_true->SetContourLevel(59,0.080746);
   _reco_per_true->SetContourLevel(60,0.08211458);
   _reco_per_true->SetContourLevel(61,0.08348316);
   _reco_per_true->SetContourLevel(62,0.08485173);
   _reco_per_true->SetContourLevel(63,0.08622031);
   _reco_per_true->SetContourLevel(64,0.08758888);
   _reco_per_true->SetContourLevel(65,0.08895746);
   _reco_per_true->SetContourLevel(66,0.09032604);
   _reco_per_true->SetContourLevel(67,0.09169461);
   _reco_per_true->SetContourLevel(68,0.09306319);
   _reco_per_true->SetContourLevel(69,0.09443177);
   _reco_per_true->SetContourLevel(70,0.09580034);
   _reco_per_true->SetContourLevel(71,0.09716892);
   _reco_per_true->SetContourLevel(72,0.0985375);
   _reco_per_true->SetContourLevel(73,0.09990607);
   _reco_per_true->SetContourLevel(74,0.1012746);
   _reco_per_true->SetContourLevel(75,0.1026432);
   _reco_per_true->SetContourLevel(76,0.1040118);
   _reco_per_true->SetContourLevel(77,0.1053804);
   _reco_per_true->SetContourLevel(78,0.106749);
   _reco_per_true->SetContourLevel(79,0.1081175);
   _reco_per_true->SetContourLevel(80,0.1094861);
   _reco_per_true->SetContourLevel(81,0.1108547);
   _reco_per_true->SetContourLevel(82,0.1122233);
   _reco_per_true->SetContourLevel(83,0.1135918);
   _reco_per_true->SetContourLevel(84,0.1149604);
   _reco_per_true->SetContourLevel(85,0.116329);
   _reco_per_true->SetContourLevel(86,0.1176976);
   _reco_per_true->SetContourLevel(87,0.1190661);
   _reco_per_true->SetContourLevel(88,0.1204347);
   _reco_per_true->SetContourLevel(89,0.1218033);
   _reco_per_true->SetContourLevel(90,0.1231719);
   _reco_per_true->SetContourLevel(91,0.1245404);
   _reco_per_true->SetContourLevel(92,0.125909);
   _reco_per_true->SetContourLevel(93,0.1272776);
   _reco_per_true->SetContourLevel(94,0.1286462);
   _reco_per_true->SetContourLevel(95,0.1300148);
   _reco_per_true->SetContourLevel(96,0.1313833);
   _reco_per_true->SetContourLevel(97,0.1327519);
   _reco_per_true->SetContourLevel(98,0.1341205);
   _reco_per_true->SetContourLevel(99,0.1354891);
   _reco_per_true->SetContourLevel(100,0.1368576);
   _reco_per_true->SetContourLevel(101,0.1382262);
   _reco_per_true->SetContourLevel(102,0.1395948);
   _reco_per_true->SetContourLevel(103,0.1409634);
   _reco_per_true->SetContourLevel(104,0.1423319);
   _reco_per_true->SetContourLevel(105,0.1437005);
   _reco_per_true->SetContourLevel(106,0.1450691);
   _reco_per_true->SetContourLevel(107,0.1464377);
   _reco_per_true->SetContourLevel(108,0.1478062);
   _reco_per_true->SetContourLevel(109,0.1491748);
   _reco_per_true->SetContourLevel(110,0.1505434);
   _reco_per_true->SetContourLevel(111,0.151912);
   _reco_per_true->SetContourLevel(112,0.1532805);
   _reco_per_true->SetContourLevel(113,0.1546491);
   _reco_per_true->SetContourLevel(114,0.1560177);
   _reco_per_true->SetContourLevel(115,0.1573863);
   _reco_per_true->SetContourLevel(116,0.1587549);
   _reco_per_true->SetContourLevel(117,0.1601234);
   _reco_per_true->SetContourLevel(118,0.161492);
   _reco_per_true->SetContourLevel(119,0.1628606);
   _reco_per_true->SetContourLevel(120,0.1642292);
   _reco_per_true->SetContourLevel(121,0.1655977);
   _reco_per_true->SetContourLevel(122,0.1669663);
   _reco_per_true->SetContourLevel(123,0.1683349);
   _reco_per_true->SetContourLevel(124,0.1697035);
   _reco_per_true->SetContourLevel(125,0.171072);
   _reco_per_true->SetContourLevel(126,0.1724406);
   _reco_per_true->SetContourLevel(127,0.1738092);
   _reco_per_true->SetContourLevel(128,0.1751778);
   _reco_per_true->SetContourLevel(129,0.1765463);
   _reco_per_true->SetContourLevel(130,0.1779149);
   _reco_per_true->SetContourLevel(131,0.1792835);
   _reco_per_true->SetContourLevel(132,0.1806521);
   _reco_per_true->SetContourLevel(133,0.1820207);
   _reco_per_true->SetContourLevel(134,0.1833892);
   _reco_per_true->SetContourLevel(135,0.1847578);
   _reco_per_true->SetContourLevel(136,0.1861264);
   _reco_per_true->SetContourLevel(137,0.187495);
   _reco_per_true->SetContourLevel(138,0.1888635);
   _reco_per_true->SetContourLevel(139,0.1902321);
   _reco_per_true->SetContourLevel(140,0.1916007);
   _reco_per_true->SetContourLevel(141,0.1929693);
   _reco_per_true->SetContourLevel(142,0.1943378);
   _reco_per_true->SetContourLevel(143,0.1957064);
   _reco_per_true->SetContourLevel(144,0.197075);
   _reco_per_true->SetContourLevel(145,0.1984436);
   _reco_per_true->SetContourLevel(146,0.1998121);
   _reco_per_true->SetContourLevel(147,0.2011807);
   _reco_per_true->SetContourLevel(148,0.2025493);
   _reco_per_true->SetContourLevel(149,0.2039179);
   _reco_per_true->SetContourLevel(150,0.2052864);
   _reco_per_true->SetContourLevel(151,0.206655);
   _reco_per_true->SetContourLevel(152,0.2080236);
   _reco_per_true->SetContourLevel(153,0.2093922);
   _reco_per_true->SetContourLevel(154,0.2107608);
   _reco_per_true->SetContourLevel(155,0.2121293);
   _reco_per_true->SetContourLevel(156,0.2134979);
   _reco_per_true->SetContourLevel(157,0.2148665);
   _reco_per_true->SetContourLevel(158,0.2162351);
   _reco_per_true->SetContourLevel(159,0.2176036);
   _reco_per_true->SetContourLevel(160,0.2189722);
   _reco_per_true->SetContourLevel(161,0.2203408);
   _reco_per_true->SetContourLevel(162,0.2217094);
   _reco_per_true->SetContourLevel(163,0.2230779);
   _reco_per_true->SetContourLevel(164,0.2244465);
   _reco_per_true->SetContourLevel(165,0.2258151);
   _reco_per_true->SetContourLevel(166,0.2271837);
   _reco_per_true->SetContourLevel(167,0.2285522);
   _reco_per_true->SetContourLevel(168,0.2299208);
   _reco_per_true->SetContourLevel(169,0.2312894);
   _reco_per_true->SetContourLevel(170,0.232658);
   _reco_per_true->SetContourLevel(171,0.2340266);
   _reco_per_true->SetContourLevel(172,0.2353951);
   _reco_per_true->SetContourLevel(173,0.2367637);
   _reco_per_true->SetContourLevel(174,0.2381323);
   _reco_per_true->SetContourLevel(175,0.2395009);
   _reco_per_true->SetContourLevel(176,0.2408694);
   _reco_per_true->SetContourLevel(177,0.242238);
   _reco_per_true->SetContourLevel(178,0.2436066);
   _reco_per_true->SetContourLevel(179,0.2449752);
   _reco_per_true->SetContourLevel(180,0.2463437);
   _reco_per_true->SetContourLevel(181,0.2477123);
   _reco_per_true->SetContourLevel(182,0.2490809);
   _reco_per_true->SetContourLevel(183,0.2504495);
   _reco_per_true->SetContourLevel(184,0.251818);
   _reco_per_true->SetContourLevel(185,0.2531866);
   _reco_per_true->SetContourLevel(186,0.2545552);
   _reco_per_true->SetContourLevel(187,0.2559238);
   _reco_per_true->SetContourLevel(188,0.2572923);
   _reco_per_true->SetContourLevel(189,0.2586609);
   _reco_per_true->SetContourLevel(190,0.2600295);
   _reco_per_true->SetContourLevel(191,0.2613981);
   _reco_per_true->SetContourLevel(192,0.2627667);
   _reco_per_true->SetContourLevel(193,0.2641352);
   _reco_per_true->SetContourLevel(194,0.2655038);
   _reco_per_true->SetContourLevel(195,0.2668724);
   _reco_per_true->SetContourLevel(196,0.268241);
   _reco_per_true->SetContourLevel(197,0.2696095);
   _reco_per_true->SetContourLevel(198,0.2709781);
   _reco_per_true->SetContourLevel(199,0.2723467);
   _reco_per_true->SetContourLevel(200,0.2737153);
   _reco_per_true->SetContourLevel(201,0.2750838);
   _reco_per_true->SetContourLevel(202,0.2764524);
   _reco_per_true->SetContourLevel(203,0.277821);
   _reco_per_true->SetContourLevel(204,0.2791896);
   _reco_per_true->SetContourLevel(205,0.2805581);
   _reco_per_true->SetContourLevel(206,0.2819267);
   _reco_per_true->SetContourLevel(207,0.2832953);
   _reco_per_true->SetContourLevel(208,0.2846639);
   _reco_per_true->SetContourLevel(209,0.2860325);
   _reco_per_true->SetContourLevel(210,0.287401);
   _reco_per_true->SetContourLevel(211,0.2887696);
   _reco_per_true->SetContourLevel(212,0.2901382);
   _reco_per_true->SetContourLevel(213,0.2915068);
   _reco_per_true->SetContourLevel(214,0.2928753);
   _reco_per_true->SetContourLevel(215,0.2942439);
   _reco_per_true->SetContourLevel(216,0.2956125);
   _reco_per_true->SetContourLevel(217,0.2969811);
   _reco_per_true->SetContourLevel(218,0.2983496);
   _reco_per_true->SetContourLevel(219,0.2997182);
   _reco_per_true->SetContourLevel(220,0.3010868);
   _reco_per_true->SetContourLevel(221,0.3024554);
   _reco_per_true->SetContourLevel(222,0.3038239);
   _reco_per_true->SetContourLevel(223,0.3051925);
   _reco_per_true->SetContourLevel(224,0.3065611);
   _reco_per_true->SetContourLevel(225,0.3079297);
   _reco_per_true->SetContourLevel(226,0.3092982);
   _reco_per_true->SetContourLevel(227,0.3106668);
   _reco_per_true->SetContourLevel(228,0.3120354);
   _reco_per_true->SetContourLevel(229,0.313404);
   _reco_per_true->SetContourLevel(230,0.3147726);
   _reco_per_true->SetContourLevel(231,0.3161411);
   _reco_per_true->SetContourLevel(232,0.3175097);
   _reco_per_true->SetContourLevel(233,0.3188783);
   _reco_per_true->SetContourLevel(234,0.3202469);
   _reco_per_true->SetContourLevel(235,0.3216154);
   _reco_per_true->SetContourLevel(236,0.322984);
   _reco_per_true->SetContourLevel(237,0.3243526);
   _reco_per_true->SetContourLevel(238,0.3257212);
   _reco_per_true->SetContourLevel(239,0.3270897);
   _reco_per_true->SetContourLevel(240,0.3284583);
   _reco_per_true->SetContourLevel(241,0.3298269);
   _reco_per_true->SetContourLevel(242,0.3311955);
   _reco_per_true->SetContourLevel(243,0.332564);
   _reco_per_true->SetContourLevel(244,0.3339326);
   _reco_per_true->SetContourLevel(245,0.3353012);
   _reco_per_true->SetContourLevel(246,0.3366698);
   _reco_per_true->SetContourLevel(247,0.3380384);
   _reco_per_true->SetContourLevel(248,0.3394069);
   _reco_per_true->SetContourLevel(249,0.3407755);
   _reco_per_true->SetContourLevel(250,0.3421441);
   _reco_per_true->SetContourLevel(251,0.3435127);
   _reco_per_true->SetContourLevel(252,0.3448812);
   _reco_per_true->SetContourLevel(253,0.3462498);
   _reco_per_true->SetContourLevel(254,0.3476184);
   
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
   TText *AText = pt->AddText("True Bin 6");
   pt->Draw();
   c1_n7->Modified();
   c1_n7->cd();
   c1_n7->SetSelected(c1_n7);
}

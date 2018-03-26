void nue_flash()
{
//=========Macro generated from canvas: c1_n48/c1_n48
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n48 = new TCanvas("c1_n48", "c1_n48",0,0,700,500);
   c1_n48->SetHighLightColor(2);
   c1_n48->Range(-0.375,-0.2625,3.375,2.3625);
   c1_n48->SetFillColor(0);
   c1_n48->SetBorderMode(0);
   c1_n48->SetBorderSize(2);
   c1_n48->SetFrameBorderMode(0);
   c1_n48->SetFrameBorderMode(0);
   
   TH1D *h_true_nu_eng_beforesel__10 = new TH1D("h_true_nu_eng_beforesel__10","",200,0,3);
   h_true_nu_eng_beforesel__10->SetBinContent(31,1);
   h_true_nu_eng_beforesel__10->SetBinContent(45,1);
   h_true_nu_eng_beforesel__10->SetBinContent(46,2);
   h_true_nu_eng_beforesel__10->SetBinContent(49,2);
   h_true_nu_eng_beforesel__10->SetBinContent(59,1);
   h_true_nu_eng_beforesel__10->SetBinContent(80,1);
   h_true_nu_eng_beforesel__10->SetBinContent(83,1);
   h_true_nu_eng_beforesel__10->SetBinContent(88,1);
   h_true_nu_eng_beforesel__10->SetBinContent(102,1);
   h_true_nu_eng_beforesel__10->SetBinContent(104,1);
   h_true_nu_eng_beforesel__10->SetBinContent(109,1);
   h_true_nu_eng_beforesel__10->SetBinContent(139,1);
   h_true_nu_eng_beforesel__10->SetBinContent(140,1);
   h_true_nu_eng_beforesel__10->SetBinContent(167,1);
   h_true_nu_eng_beforesel__10->SetEntries(16);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("h_true_nu_eng_beforesel");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 16     ");
   AText = ptstats->AddText("Mean  =  1.245");
   AText = ptstats->AddText("Std Dev   = 0.5907");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_true_nu_eng_beforesel__10->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_true_nu_eng_beforesel__10);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h_true_nu_eng_beforesel__10->SetLineColor(ci);
   h_true_nu_eng_beforesel__10->GetXaxis()->SetTitle("True Neutrino Energy [GeV]");
   h_true_nu_eng_beforesel__10->GetXaxis()->SetLabelFont(42);
   h_true_nu_eng_beforesel__10->GetXaxis()->SetLabelSize(0.035);
   h_true_nu_eng_beforesel__10->GetXaxis()->SetTitleSize(0.035);
   h_true_nu_eng_beforesel__10->GetXaxis()->SetTitleFont(42);
   h_true_nu_eng_beforesel__10->GetYaxis()->SetTitle("Events");
   h_true_nu_eng_beforesel__10->GetYaxis()->SetLabelFont(42);
   h_true_nu_eng_beforesel__10->GetYaxis()->SetLabelSize(0.035);
   h_true_nu_eng_beforesel__10->GetYaxis()->SetTitleSize(0.035);
   h_true_nu_eng_beforesel__10->GetYaxis()->SetTitleFont(42);
   h_true_nu_eng_beforesel__10->GetZaxis()->SetLabelFont(42);
   h_true_nu_eng_beforesel__10->GetZaxis()->SetLabelSize(0.035);
   h_true_nu_eng_beforesel__10->GetZaxis()->SetTitleSize(0.035);
   h_true_nu_eng_beforesel__10->GetZaxis()->SetTitleFont(42);
   h_true_nu_eng_beforesel__10->Draw("");
   
   TH1D *h_true_nu_eng_afterflash__11 = new TH1D("h_true_nu_eng_afterflash__11","",200,0,3);
   h_true_nu_eng_afterflash__11->SetBinContent(31,1);
   h_true_nu_eng_afterflash__11->SetBinContent(45,1);
   h_true_nu_eng_afterflash__11->SetBinContent(46,2);
   h_true_nu_eng_afterflash__11->SetBinContent(49,2);
   h_true_nu_eng_afterflash__11->SetBinContent(59,1);
   h_true_nu_eng_afterflash__11->SetBinContent(80,1);
   h_true_nu_eng_afterflash__11->SetBinContent(83,1);
   h_true_nu_eng_afterflash__11->SetBinContent(88,1);
   h_true_nu_eng_afterflash__11->SetBinContent(102,1);
   h_true_nu_eng_afterflash__11->SetBinContent(104,1);
   h_true_nu_eng_afterflash__11->SetBinContent(109,1);
   h_true_nu_eng_afterflash__11->SetBinContent(139,1);
   h_true_nu_eng_afterflash__11->SetBinContent(140,1);
   h_true_nu_eng_afterflash__11->SetBinContent(167,1);
   h_true_nu_eng_afterflash__11->SetEntries(16);

   ci = TColor::GetColor("#990000");
   h_true_nu_eng_afterflash__11->SetLineColor(ci);
   h_true_nu_eng_afterflash__11->GetXaxis()->SetTitle("True Neutrino Energy [GeV]");
   h_true_nu_eng_afterflash__11->GetXaxis()->SetLabelFont(42);
   h_true_nu_eng_afterflash__11->GetXaxis()->SetLabelSize(0.035);
   h_true_nu_eng_afterflash__11->GetXaxis()->SetTitleSize(0.035);
   h_true_nu_eng_afterflash__11->GetXaxis()->SetTitleFont(42);
   h_true_nu_eng_afterflash__11->GetYaxis()->SetTitle("Events");
   h_true_nu_eng_afterflash__11->GetYaxis()->SetLabelFont(42);
   h_true_nu_eng_afterflash__11->GetYaxis()->SetLabelSize(0.035);
   h_true_nu_eng_afterflash__11->GetYaxis()->SetTitleSize(0.035);
   h_true_nu_eng_afterflash__11->GetYaxis()->SetTitleFont(42);
   h_true_nu_eng_afterflash__11->GetZaxis()->SetLabelFont(42);
   h_true_nu_eng_afterflash__11->GetZaxis()->SetLabelSize(0.035);
   h_true_nu_eng_afterflash__11->GetZaxis()->SetTitleSize(0.035);
   h_true_nu_eng_afterflash__11->GetZaxis()->SetTitleFont(42);
   h_true_nu_eng_afterflash__11->Draw("same");
   
   TH1D *h_true_nu_eng_aftersel__12 = new TH1D("h_true_nu_eng_aftersel__12","",200,0,3);
   h_true_nu_eng_aftersel__12->SetBinContent(31,1);
   h_true_nu_eng_aftersel__12->SetBinContent(46,1);
   h_true_nu_eng_aftersel__12->SetBinContent(80,1);
   h_true_nu_eng_aftersel__12->SetBinContent(83,1);
   h_true_nu_eng_aftersel__12->SetBinContent(140,1);
   h_true_nu_eng_aftersel__12->SetEntries(5);

   ci = TColor::GetColor("#009900");
   h_true_nu_eng_aftersel__12->SetLineColor(ci);
   h_true_nu_eng_aftersel__12->GetXaxis()->SetTitle("True Neutrino Energy [GeV]");
   h_true_nu_eng_aftersel__12->GetXaxis()->SetLabelFont(42);
   h_true_nu_eng_aftersel__12->GetXaxis()->SetLabelSize(0.035);
   h_true_nu_eng_aftersel__12->GetXaxis()->SetTitleSize(0.035);
   h_true_nu_eng_aftersel__12->GetXaxis()->SetTitleFont(42);
   h_true_nu_eng_aftersel__12->GetYaxis()->SetTitle("Events");
   h_true_nu_eng_aftersel__12->GetYaxis()->SetLabelFont(42);
   h_true_nu_eng_aftersel__12->GetYaxis()->SetLabelSize(0.035);
   h_true_nu_eng_aftersel__12->GetYaxis()->SetTitleSize(0.035);
   h_true_nu_eng_aftersel__12->GetYaxis()->SetTitleFont(42);
   h_true_nu_eng_aftersel__12->GetZaxis()->SetLabelFont(42);
   h_true_nu_eng_aftersel__12->GetZaxis()->SetLabelSize(0.035);
   h_true_nu_eng_aftersel__12->GetZaxis()->SetTitleSize(0.035);
   h_true_nu_eng_aftersel__12->GetZaxis()->SetTitleFont(42);
   h_true_nu_eng_aftersel__12->Draw("same");
   
   TLegend *leg = new TLegend(0.1,0.7,0.48,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("h_true_nu_eng_beforesel","Generated CC #nu_{#mu} events in FV","l");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_true_nu_eng_afterflash","CC #nu_{#mu} Passing Flash Finding","l");

   ci = TColor::GetColor("#990000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_true_nu_eng_aftersel","Selected CC #nu_{#mu} events","l");

   ci = TColor::GetColor("#009900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c1_n48->Modified();
   c1_n48->cd();
   c1_n48->SetSelected(c1_n48);
}

void flsTime()
{
//=========Macro generated from canvas: c1_n12/c1_n12
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n12 = new TCanvas("c1_n12", "c1_n12",0,0,700,500);
   c1_n12->SetHighLightColor(2);
   c1_n12->Range(-3.125,-2.1,28.125,18.9);
   c1_n12->SetFillColor(0);
   c1_n12->SetBorderMode(0);
   c1_n12->SetBorderSize(2);
   c1_n12->SetFrameBorderMode(0);
   c1_n12->SetFrameBorderMode(0);
   
   TH1D *h_flsTime__2 = new TH1D("h_flsTime__2","",125,0,25);
   h_flsTime__2->SetBinContent(17,9);
   h_flsTime__2->SetBinContent(18,10);
   h_flsTime__2->SetBinContent(19,5);
   h_flsTime__2->SetBinContent(20,9);
   h_flsTime__2->SetBinContent(21,12);
   h_flsTime__2->SetBinContent(22,6);
   h_flsTime__2->SetBinContent(23,16);
   h_flsTime__2->SetBinContent(24,10);
   h_flsTime__2->SetBinContent(25,1);
   h_flsTime__2->SetBinContent(33,1);
   h_flsTime__2->SetBinContent(41,1);
   h_flsTime__2->SetBinContent(52,1);
   h_flsTime__2->SetBinContent(56,1);
   h_flsTime__2->SetBinContent(63,2);
   h_flsTime__2->SetBinContent(64,1);
   h_flsTime__2->SetBinContent(69,3);
   h_flsTime__2->SetBinContent(81,1);
   h_flsTime__2->SetBinContent(86,1);
   h_flsTime__2->SetBinContent(88,1);
   h_flsTime__2->SetBinContent(91,1);
   h_flsTime__2->SetBinContent(97,1);
   h_flsTime__2->SetBinContent(101,1);
   h_flsTime__2->SetBinContent(102,1);
   h_flsTime__2->SetBinContent(106,1);
   h_flsTime__2->SetBinError(17,3);
   h_flsTime__2->SetBinError(18,3.162278);
   h_flsTime__2->SetBinError(19,2.236068);
   h_flsTime__2->SetBinError(20,3);
   h_flsTime__2->SetBinError(21,3.464102);
   h_flsTime__2->SetBinError(22,2.44949);
   h_flsTime__2->SetBinError(23,4);
   h_flsTime__2->SetBinError(24,3.162278);
   h_flsTime__2->SetBinError(25,1);
   h_flsTime__2->SetBinError(33,1);
   h_flsTime__2->SetBinError(41,1);
   h_flsTime__2->SetBinError(52,1);
   h_flsTime__2->SetBinError(56,1);
   h_flsTime__2->SetBinError(63,1.414214);
   h_flsTime__2->SetBinError(64,1);
   h_flsTime__2->SetBinError(69,1.732051);
   h_flsTime__2->SetBinError(81,1);
   h_flsTime__2->SetBinError(86,1);
   h_flsTime__2->SetBinError(88,1);
   h_flsTime__2->SetBinError(91,1);
   h_flsTime__2->SetBinError(97,1);
   h_flsTime__2->SetBinError(101,1);
   h_flsTime__2->SetBinError(102,1);
   h_flsTime__2->SetBinError(106,1);
   h_flsTime__2->SetEntries(96);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("h_flsTime");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 96     ");
   AText = ptstats->AddText("Mean  =   6.05");
   AText = ptstats->AddText("Std Dev   =  4.538");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_flsTime__2->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_flsTime__2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h_flsTime__2->SetLineColor(ci);
   h_flsTime__2->GetXaxis()->SetTitle("Flash time w.r.t. trigger [#mus]");
   h_flsTime__2->GetXaxis()->SetLabelFont(42);
   h_flsTime__2->GetXaxis()->SetLabelSize(0.035);
   h_flsTime__2->GetXaxis()->SetTitleSize(0.035);
   h_flsTime__2->GetXaxis()->SetTitleFont(42);
   h_flsTime__2->GetYaxis()->SetTitle("Flashes");
   h_flsTime__2->GetYaxis()->SetLabelFont(42);
   h_flsTime__2->GetYaxis()->SetLabelSize(0.035);
   h_flsTime__2->GetYaxis()->SetTitleSize(0.035);
   h_flsTime__2->GetYaxis()->SetTitleFont(42);
   h_flsTime__2->GetZaxis()->SetLabelFont(42);
   h_flsTime__2->GetZaxis()->SetLabelSize(0.035);
   h_flsTime__2->GetZaxis()->SetTitleSize(0.035);
   h_flsTime__2->GetZaxis()->SetTitleFont(42);
   h_flsTime__2->Draw("histo");
   c1_n12->Modified();
   c1_n12->cd();
   c1_n12->SetSelected(c1_n12);
}

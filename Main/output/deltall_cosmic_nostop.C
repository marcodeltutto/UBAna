void deltall_cosmic_nostop()
{
//=========Macro generated from canvas: c1_n43/c1_n43
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n43 = new TCanvas("c1_n43", "c1_n43",0,0,700,500);
   c1_n43->SetHighLightColor(2);
   c1_n43->Range(-37.5,-0.13125,37.5,1.18125);
   c1_n43->SetFillColor(0);
   c1_n43->SetBorderMode(0);
   c1_n43->SetBorderSize(2);
   c1_n43->SetFrameBorderMode(0);
   c1_n43->SetFrameBorderMode(0);
   
   TH1D *h_deltall_cosmic_nostop__8 = new TH1D("h_deltall_cosmic_nostop__8","Cosmic non-stopping Muons",400,-30,30);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("h_deltall_cosmic_nostop");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 0      ");
   AText = ptstats->AddText("Mean  =      0");
   AText = ptstats->AddText("Std Dev   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_deltall_cosmic_nostop__8->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_deltall_cosmic_nostop__8);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h_deltall_cosmic_nostop__8->SetLineColor(ci);
   h_deltall_cosmic_nostop__8->GetXaxis()->SetTitle("MCS Delta LL");
   h_deltall_cosmic_nostop__8->GetXaxis()->SetLabelFont(42);
   h_deltall_cosmic_nostop__8->GetXaxis()->SetLabelSize(0.035);
   h_deltall_cosmic_nostop__8->GetXaxis()->SetTitleSize(0.035);
   h_deltall_cosmic_nostop__8->GetXaxis()->SetTitleFont(42);
   h_deltall_cosmic_nostop__8->GetYaxis()->SetLabelFont(42);
   h_deltall_cosmic_nostop__8->GetYaxis()->SetLabelSize(0.035);
   h_deltall_cosmic_nostop__8->GetYaxis()->SetTitleSize(0.035);
   h_deltall_cosmic_nostop__8->GetYaxis()->SetTitleFont(42);
   h_deltall_cosmic_nostop__8->GetZaxis()->SetLabelFont(42);
   h_deltall_cosmic_nostop__8->GetZaxis()->SetLabelSize(0.035);
   h_deltall_cosmic_nostop__8->GetZaxis()->SetTitleSize(0.035);
   h_deltall_cosmic_nostop__8->GetZaxis()->SetTitleFont(42);
   h_deltall_cosmic_nostop__8->Draw("");
   
   TPaveText *pt = new TPaveText(0.252931,0.9339831,0.747069,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("Cosmic non-stopping Muons");
   pt->Draw();
   c1_n43->Modified();
   c1_n43->cd();
   c1_n43->SetSelected(c1_n43);
}

void deltall_cosmic_nostop_length()
{
//=========Macro generated from canvas: c1_n46/c1_n46
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n46 = new TCanvas("c1_n46", "c1_n46",0,0,700,500);
   c1_n46->SetHighLightColor(2);
   c1_n46->Range(-37.5,-87.50001,37.5,787.5);
   c1_n46->SetFillColor(0);
   c1_n46->SetBorderMode(0);
   c1_n46->SetBorderSize(2);
   c1_n46->SetFrameBorderMode(0);
   c1_n46->SetFrameBorderMode(0);
   
   TH2D *h_deltall_length_cosmic_nostop = new TH2D("h_deltall_length_cosmic_nostop","Cosmic non-stopping Muons",70,-30,30,70,0,700);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("h_deltall_length_cosmic_nostop");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 0      ");
   AText = ptstats->AddText("Mean x =      0");
   AText = ptstats->AddText("Mean y =      0");
   AText = ptstats->AddText("Std Dev x =      0");
   AText = ptstats->AddText("Std Dev y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_deltall_length_cosmic_nostop->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_deltall_length_cosmic_nostop);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h_deltall_length_cosmic_nostop->SetLineColor(ci);
   h_deltall_length_cosmic_nostop->GetXaxis()->SetTitle("MCS Delta LL");
   h_deltall_length_cosmic_nostop->GetXaxis()->SetLabelFont(42);
   h_deltall_length_cosmic_nostop->GetXaxis()->SetLabelSize(0.035);
   h_deltall_length_cosmic_nostop->GetXaxis()->SetTitleSize(0.035);
   h_deltall_length_cosmic_nostop->GetXaxis()->SetTitleFont(42);
   h_deltall_length_cosmic_nostop->GetYaxis()->SetTitle("Track Length [cm]");
   h_deltall_length_cosmic_nostop->GetYaxis()->SetLabelFont(42);
   h_deltall_length_cosmic_nostop->GetYaxis()->SetLabelSize(0.035);
   h_deltall_length_cosmic_nostop->GetYaxis()->SetTitleSize(0.035);
   h_deltall_length_cosmic_nostop->GetYaxis()->SetTitleFont(42);
   h_deltall_length_cosmic_nostop->GetZaxis()->SetLabelFont(42);
   h_deltall_length_cosmic_nostop->GetZaxis()->SetLabelSize(0.035);
   h_deltall_length_cosmic_nostop->GetZaxis()->SetTitleSize(0.035);
   h_deltall_length_cosmic_nostop->GetZaxis()->SetTitleFont(42);
   h_deltall_length_cosmic_nostop->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.252931,0.9339831,0.747069,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("Cosmic non-stopping Muons");
   pt->Draw();
   c1_n46->Modified();
   c1_n46->cd();
   c1_n46->SetSelected(c1_n46);
}

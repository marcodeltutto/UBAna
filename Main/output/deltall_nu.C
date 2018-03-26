void deltall_nu()
{
//=========Macro generated from canvas: c1_n44/c1_n44
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n44 = new TCanvas("c1_n44", "c1_n44",0,0,700,500);
   c1_n44->SetHighLightColor(2);
   c1_n44->Range(-37.5,-0.13125,37.5,1.18125);
   c1_n44->SetFillColor(0);
   c1_n44->SetBorderMode(0);
   c1_n44->SetBorderSize(2);
   c1_n44->SetFrameBorderMode(0);
   c1_n44->SetFrameBorderMode(0);
   
   TH1D *h_deltall_nu__9 = new TH1D("h_deltall_nu__9","Neutrino origin",400,-30,30);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("h_deltall_nu");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 0      ");
   AText = ptstats->AddText("Mean  =      0");
   AText = ptstats->AddText("Std Dev   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_deltall_nu__9->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_deltall_nu__9);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h_deltall_nu__9->SetLineColor(ci);
   h_deltall_nu__9->GetXaxis()->SetTitle("MCS Delta LL");
   h_deltall_nu__9->GetXaxis()->SetLabelFont(42);
   h_deltall_nu__9->GetXaxis()->SetLabelSize(0.035);
   h_deltall_nu__9->GetXaxis()->SetTitleSize(0.035);
   h_deltall_nu__9->GetXaxis()->SetTitleFont(42);
   h_deltall_nu__9->GetYaxis()->SetLabelFont(42);
   h_deltall_nu__9->GetYaxis()->SetLabelSize(0.035);
   h_deltall_nu__9->GetYaxis()->SetTitleSize(0.035);
   h_deltall_nu__9->GetYaxis()->SetTitleFont(42);
   h_deltall_nu__9->GetZaxis()->SetLabelFont(42);
   h_deltall_nu__9->GetZaxis()->SetLabelSize(0.035);
   h_deltall_nu__9->GetZaxis()->SetTitleSize(0.035);
   h_deltall_nu__9->GetZaxis()->SetTitleFont(42);
   h_deltall_nu__9->Draw("");
   
   TPaveText *pt = new TPaveText(0.3671552,0.9339831,0.6328448,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("Neutrino origin");
   pt->Draw();
   c1_n44->Modified();
   c1_n44->cd();
   c1_n44->SetSelected(c1_n44);
}

void efficiency()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->SetHighLightColor(2);
   c1->Range(-0.15,-0.125,3.15,1.125);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TEfficiency * h_eff_den_clone1 = new TEfficiency("h_eff_den_clone","",15,0,3);
   
   h_eff_den_clone1->SetConfidenceLevel(0.6826895);
   h_eff_den_clone1->SetBetaAlpha(1);
   h_eff_den_clone1->SetBetaBeta(1);
   h_eff_den_clone1->SetWeight(1);
   h_eff_den_clone1->SetStatisticOption(0);
   h_eff_den_clone1->SetPosteriorMode(0);
   h_eff_den_clone1->SetShortestInterval(0);
   h_eff_den_clone1->SetTotalEvents(0,0);
   h_eff_den_clone1->SetPassedEvents(0,0);
   h_eff_den_clone1->SetTotalEvents(1,0);
   h_eff_den_clone1->SetPassedEvents(1,0);
   h_eff_den_clone1->SetTotalEvents(2,0);
   h_eff_den_clone1->SetPassedEvents(2,0);
   h_eff_den_clone1->SetTotalEvents(3,1);
   h_eff_den_clone1->SetPassedEvents(3,1);
   h_eff_den_clone1->SetTotalEvents(4,5);
   h_eff_den_clone1->SetPassedEvents(4,1);
   h_eff_den_clone1->SetTotalEvents(5,1);
   h_eff_den_clone1->SetPassedEvents(5,0);
   h_eff_den_clone1->SetTotalEvents(6,1);
   h_eff_den_clone1->SetPassedEvents(6,1);
   h_eff_den_clone1->SetTotalEvents(7,2);
   h_eff_den_clone1->SetPassedEvents(7,1);
   h_eff_den_clone1->SetTotalEvents(8,2);
   h_eff_den_clone1->SetPassedEvents(8,0);
   h_eff_den_clone1->SetTotalEvents(9,1);
   h_eff_den_clone1->SetPassedEvents(9,0);
   h_eff_den_clone1->SetTotalEvents(10,0);
   h_eff_den_clone1->SetPassedEvents(10,0);
   h_eff_den_clone1->SetTotalEvents(11,2);
   h_eff_den_clone1->SetPassedEvents(11,0);
   h_eff_den_clone1->SetTotalEvents(12,0);
   h_eff_den_clone1->SetPassedEvents(12,0);
   h_eff_den_clone1->SetTotalEvents(13,1);
   h_eff_den_clone1->SetPassedEvents(13,0);
   h_eff_den_clone1->SetTotalEvents(14,0);
   h_eff_den_clone1->SetPassedEvents(14,0);
   h_eff_den_clone1->SetTotalEvents(15,0);
   h_eff_den_clone1->SetPassedEvents(15,0);
   h_eff_den_clone1->SetTotalEvents(16,0);
   h_eff_den_clone1->SetPassedEvents(16,0);
   h_eff_den_clone1->SetFillColor(19);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#006600");
   h_eff_den_clone1->SetLineColor(ci);

   ci = TColor::GetColor("#006600");
   h_eff_den_clone1->SetMarkerColor(ci);
   h_eff_den_clone1->SetMarkerStyle(20);
   h_eff_den_clone1->SetMarkerSize(0.5);
   h_eff_den_clone1->Draw("ap");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}

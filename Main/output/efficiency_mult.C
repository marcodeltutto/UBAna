void efficiency_mult()
{
//=========Macro generated from canvas: c1_n8/c1_n8
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n8 = new TCanvas("c1_n8", "c1_n8",0,0,700,500);
   c1_n8->SetHighLightColor(2);
   c1_n8->Range(-0.5000002,-0.1375,20.5,1.2375);
   c1_n8->SetFillColor(0);
   c1_n8->SetBorderMode(0);
   c1_n8->SetBorderSize(2);
   c1_n8->SetFrameBorderMode(0);
   c1_n8->SetFrameBorderMode(0);
   
   TEfficiency * h_eff_mult_den_clone8 = new TEfficiency("h_eff_mult_den_clone","",20,0,20);
   
   h_eff_mult_den_clone8->SetConfidenceLevel(0.6826895);
   h_eff_mult_den_clone8->SetBetaAlpha(1);
   h_eff_mult_den_clone8->SetBetaBeta(1);
   h_eff_mult_den_clone8->SetWeight(1);
   h_eff_mult_den_clone8->SetStatisticOption(0);
   h_eff_mult_den_clone8->SetPosteriorMode(0);
   h_eff_mult_den_clone8->SetShortestInterval(0);
   h_eff_mult_den_clone8->SetTotalEvents(0,0);
   h_eff_mult_den_clone8->SetPassedEvents(0,0);
   h_eff_mult_den_clone8->SetTotalEvents(1,0);
   h_eff_mult_den_clone8->SetPassedEvents(1,0);
   h_eff_mult_den_clone8->SetTotalEvents(2,0);
   h_eff_mult_den_clone8->SetPassedEvents(2,0);
   h_eff_mult_den_clone8->SetTotalEvents(3,0);
   h_eff_mult_den_clone8->SetPassedEvents(3,0);
   h_eff_mult_den_clone8->SetTotalEvents(4,5);
   h_eff_mult_den_clone8->SetPassedEvents(4,1);
   h_eff_mult_den_clone8->SetTotalEvents(5,3);
   h_eff_mult_den_clone8->SetPassedEvents(5,0);
   h_eff_mult_den_clone8->SetTotalEvents(6,2);
   h_eff_mult_den_clone8->SetPassedEvents(6,1);
   h_eff_mult_den_clone8->SetTotalEvents(7,0);
   h_eff_mult_den_clone8->SetPassedEvents(7,0);
   h_eff_mult_den_clone8->SetTotalEvents(8,0);
   h_eff_mult_den_clone8->SetPassedEvents(8,0);
   h_eff_mult_den_clone8->SetTotalEvents(9,1);
   h_eff_mult_den_clone8->SetPassedEvents(9,0);
   h_eff_mult_den_clone8->SetTotalEvents(10,0);
   h_eff_mult_den_clone8->SetPassedEvents(10,0);
   h_eff_mult_den_clone8->SetTotalEvents(11,0);
   h_eff_mult_den_clone8->SetPassedEvents(11,0);
   h_eff_mult_den_clone8->SetTotalEvents(12,0);
   h_eff_mult_den_clone8->SetPassedEvents(12,0);
   h_eff_mult_den_clone8->SetTotalEvents(13,1);
   h_eff_mult_den_clone8->SetPassedEvents(13,1);
   h_eff_mult_den_clone8->SetTotalEvents(14,0);
   h_eff_mult_den_clone8->SetPassedEvents(14,0);
   h_eff_mult_den_clone8->SetTotalEvents(15,1);
   h_eff_mult_den_clone8->SetPassedEvents(15,0);
   h_eff_mult_den_clone8->SetTotalEvents(16,0);
   h_eff_mult_den_clone8->SetPassedEvents(16,0);
   h_eff_mult_den_clone8->SetTotalEvents(17,1);
   h_eff_mult_den_clone8->SetPassedEvents(17,0);
   h_eff_mult_den_clone8->SetTotalEvents(18,0);
   h_eff_mult_den_clone8->SetPassedEvents(18,0);
   h_eff_mult_den_clone8->SetTotalEvents(19,0);
   h_eff_mult_den_clone8->SetPassedEvents(19,0);
   h_eff_mult_den_clone8->SetTotalEvents(20,0);
   h_eff_mult_den_clone8->SetPassedEvents(20,0);
   h_eff_mult_den_clone8->SetTotalEvents(21,2);
   h_eff_mult_den_clone8->SetPassedEvents(21,1);
   h_eff_mult_den_clone8->SetFillColor(19);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#006600");
   h_eff_mult_den_clone8->SetLineColor(ci);

   ci = TColor::GetColor("#006600");
   h_eff_mult_den_clone8->SetMarkerColor(ci);
   h_eff_mult_den_clone8->SetMarkerStyle(20);
   h_eff_mult_den_clone8->SetMarkerSize(0.5);
   h_eff_mult_den_clone8->Draw("ap");
   c1_n8->Modified();
   c1_n8->cd();
   c1_n8->SetSelected(c1_n8);
}

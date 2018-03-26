void efficiency_mult_ch()
{
//=========Macro generated from canvas: c1_n9/c1_n9
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n9 = new TCanvas("c1_n9", "c1_n9",0,0,700,500);
   c1_n9->SetHighLightColor(2);
   c1_n9->Range(-1.125,-0.1375,14.625,1.2375);
   c1_n9->SetFillColor(0);
   c1_n9->SetBorderMode(0);
   c1_n9->SetBorderSize(2);
   c1_n9->SetFrameBorderMode(0);
   c1_n9->SetFrameBorderMode(0);
   
   TEfficiency * h_eff_mult_ch_den_clone9 = new TEfficiency("h_eff_mult_ch_den_clone","",10,0,15);
   
   h_eff_mult_ch_den_clone9->SetConfidenceLevel(0.6826895);
   h_eff_mult_ch_den_clone9->SetBetaAlpha(1);
   h_eff_mult_ch_den_clone9->SetBetaBeta(1);
   h_eff_mult_ch_den_clone9->SetWeight(1);
   h_eff_mult_ch_den_clone9->SetStatisticOption(0);
   h_eff_mult_ch_den_clone9->SetPosteriorMode(0);
   h_eff_mult_ch_den_clone9->SetShortestInterval(0);
   h_eff_mult_ch_den_clone9->SetTotalEvents(0,0);
   h_eff_mult_ch_den_clone9->SetPassedEvents(0,0);
   h_eff_mult_ch_den_clone9->SetTotalEvents(1,0);
   h_eff_mult_ch_den_clone9->SetPassedEvents(1,0);
   h_eff_mult_ch_den_clone9->SetTotalEvents(2,5);
   h_eff_mult_ch_den_clone9->SetPassedEvents(2,1);
   h_eff_mult_ch_den_clone9->SetTotalEvents(3,5);
   h_eff_mult_ch_den_clone9->SetPassedEvents(3,1);
   h_eff_mult_ch_den_clone9->SetTotalEvents(4,1);
   h_eff_mult_ch_den_clone9->SetPassedEvents(4,0);
   h_eff_mult_ch_den_clone9->SetTotalEvents(5,1);
   h_eff_mult_ch_den_clone9->SetPassedEvents(5,0);
   h_eff_mult_ch_den_clone9->SetTotalEvents(6,1);
   h_eff_mult_ch_den_clone9->SetPassedEvents(6,1);
   h_eff_mult_ch_den_clone9->SetTotalEvents(7,1);
   h_eff_mult_ch_den_clone9->SetPassedEvents(7,0);
   h_eff_mult_ch_den_clone9->SetTotalEvents(8,1);
   h_eff_mult_ch_den_clone9->SetPassedEvents(8,0);
   h_eff_mult_ch_den_clone9->SetTotalEvents(9,0);
   h_eff_mult_ch_den_clone9->SetPassedEvents(9,0);
   h_eff_mult_ch_den_clone9->SetTotalEvents(10,0);
   h_eff_mult_ch_den_clone9->SetPassedEvents(10,0);
   h_eff_mult_ch_den_clone9->SetTotalEvents(11,1);
   h_eff_mult_ch_den_clone9->SetPassedEvents(11,1);
   h_eff_mult_ch_den_clone9->SetFillColor(19);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#006600");
   h_eff_mult_ch_den_clone9->SetLineColor(ci);

   ci = TColor::GetColor("#006600");
   h_eff_mult_ch_den_clone9->SetMarkerColor(ci);
   h_eff_mult_ch_den_clone9->SetMarkerStyle(20);
   h_eff_mult_ch_den_clone9->SetMarkerSize(0.5);
   h_eff_mult_ch_den_clone9->Draw("ap");
   c1_n9->Modified();
   c1_n9->cd();
   c1_n9->SetSelected(c1_n9);
}

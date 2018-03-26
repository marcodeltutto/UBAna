void efficiency_muphi()
{
//=========Macro generated from canvas: c1_n7/c1_n7
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n7 = new TCanvas("c1_n7", "c1_n7",0,0,700,500);
   c1_n7->SetHighLightColor(2);
   c1_n7->Range(-3.665083,-0.1375,4.502817,1.2375);
   c1_n7->SetFillColor(0);
   c1_n7->SetBorderMode(0);
   c1_n7->SetBorderSize(2);
   c1_n7->SetFrameBorderMode(0);
   c1_n7->SetFrameBorderMode(0);
   
   TEfficiency * h_eff_muphi_den_clone7 = new TEfficiency("h_eff_muphi_den_clone","",15,-3.1415,3.1415);
   
   h_eff_muphi_den_clone7->SetConfidenceLevel(0.6826895);
   h_eff_muphi_den_clone7->SetBetaAlpha(1);
   h_eff_muphi_den_clone7->SetBetaBeta(1);
   h_eff_muphi_den_clone7->SetWeight(1);
   h_eff_muphi_den_clone7->SetStatisticOption(0);
   h_eff_muphi_den_clone7->SetPosteriorMode(0);
   h_eff_muphi_den_clone7->SetShortestInterval(0);
   h_eff_muphi_den_clone7->SetTotalEvents(0,0);
   h_eff_muphi_den_clone7->SetPassedEvents(0,0);
   h_eff_muphi_den_clone7->SetTotalEvents(1,0);
   h_eff_muphi_den_clone7->SetPassedEvents(1,0);
   h_eff_muphi_den_clone7->SetTotalEvents(2,0);
   h_eff_muphi_den_clone7->SetPassedEvents(2,0);
   h_eff_muphi_den_clone7->SetTotalEvents(3,2);
   h_eff_muphi_den_clone7->SetPassedEvents(3,1);
   h_eff_muphi_den_clone7->SetTotalEvents(4,0);
   h_eff_muphi_den_clone7->SetPassedEvents(4,0);
   h_eff_muphi_den_clone7->SetTotalEvents(5,2);
   h_eff_muphi_den_clone7->SetPassedEvents(5,2);
   h_eff_muphi_den_clone7->SetTotalEvents(6,0);
   h_eff_muphi_den_clone7->SetPassedEvents(6,0);
   h_eff_muphi_den_clone7->SetTotalEvents(7,1);
   h_eff_muphi_den_clone7->SetPassedEvents(7,0);
   h_eff_muphi_den_clone7->SetTotalEvents(8,1);
   h_eff_muphi_den_clone7->SetPassedEvents(8,0);
   h_eff_muphi_den_clone7->SetTotalEvents(9,1);
   h_eff_muphi_den_clone7->SetPassedEvents(9,0);
   h_eff_muphi_den_clone7->SetTotalEvents(10,1);
   h_eff_muphi_den_clone7->SetPassedEvents(10,0);
   h_eff_muphi_den_clone7->SetTotalEvents(11,0);
   h_eff_muphi_den_clone7->SetPassedEvents(11,0);
   h_eff_muphi_den_clone7->SetTotalEvents(12,4);
   h_eff_muphi_den_clone7->SetPassedEvents(12,1);
   h_eff_muphi_den_clone7->SetTotalEvents(13,2);
   h_eff_muphi_den_clone7->SetPassedEvents(13,0);
   h_eff_muphi_den_clone7->SetTotalEvents(14,1);
   h_eff_muphi_den_clone7->SetPassedEvents(14,0);
   h_eff_muphi_den_clone7->SetTotalEvents(15,1);
   h_eff_muphi_den_clone7->SetPassedEvents(15,0);
   h_eff_muphi_den_clone7->SetTotalEvents(16,0);
   h_eff_muphi_den_clone7->SetPassedEvents(16,0);
   h_eff_muphi_den_clone7->SetFillColor(19);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#006600");
   h_eff_muphi_den_clone7->SetLineColor(ci);

   ci = TColor::GetColor("#006600");
   h_eff_muphi_den_clone7->SetMarkerColor(ci);
   h_eff_muphi_den_clone7->SetMarkerStyle(20);
   h_eff_muphi_den_clone7->SetMarkerSize(0.5);
   h_eff_muphi_den_clone7->Draw("ap");
   c1_n7->Modified();
   c1_n7->cd();
   c1_n7->SetSelected(c1_n7);
}

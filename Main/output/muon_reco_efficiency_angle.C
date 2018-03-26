void muon_reco_efficiency_angle()
{
//=========Macro generated from canvas: c1_n3/c1_n3
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n3 = new TCanvas("c1_n3", "c1_n3",0,0,700,500);
   c1_n3->SetHighLightColor(2);
   c1_n3->Range(-0.1366667,-0.125,1.23,1.125);
   c1_n3->SetFillColor(0);
   c1_n3->SetBorderMode(0);
   c1_n3->SetBorderSize(2);
   c1_n3->SetFrameBorderMode(0);
   c1_n3->SetFrameBorderMode(0);
   
   TEfficiency * h_mueff_angle_den_clone3 = new TEfficiency("h_mueff_angle_den_clone","",15,-1,1);
   
   h_mueff_angle_den_clone3->SetConfidenceLevel(0.6826895);
   h_mueff_angle_den_clone3->SetBetaAlpha(1);
   h_mueff_angle_den_clone3->SetBetaBeta(1);
   h_mueff_angle_den_clone3->SetWeight(1);
   h_mueff_angle_den_clone3->SetStatisticOption(0);
   h_mueff_angle_den_clone3->SetPosteriorMode(0);
   h_mueff_angle_den_clone3->SetShortestInterval(0);
   h_mueff_angle_den_clone3->SetTotalEvents(0,0);
   h_mueff_angle_den_clone3->SetPassedEvents(0,0);
   h_mueff_angle_den_clone3->SetTotalEvents(1,0);
   h_mueff_angle_den_clone3->SetPassedEvents(1,0);
   h_mueff_angle_den_clone3->SetTotalEvents(2,0);
   h_mueff_angle_den_clone3->SetPassedEvents(2,0);
   h_mueff_angle_den_clone3->SetTotalEvents(3,0);
   h_mueff_angle_den_clone3->SetPassedEvents(3,0);
   h_mueff_angle_den_clone3->SetTotalEvents(4,0);
   h_mueff_angle_den_clone3->SetPassedEvents(4,0);
   h_mueff_angle_den_clone3->SetTotalEvents(5,0);
   h_mueff_angle_den_clone3->SetPassedEvents(5,0);
   h_mueff_angle_den_clone3->SetTotalEvents(6,0);
   h_mueff_angle_den_clone3->SetPassedEvents(6,0);
   h_mueff_angle_den_clone3->SetTotalEvents(7,0);
   h_mueff_angle_den_clone3->SetPassedEvents(7,0);
   h_mueff_angle_den_clone3->SetTotalEvents(8,0);
   h_mueff_angle_den_clone3->SetPassedEvents(8,0);
   h_mueff_angle_den_clone3->SetTotalEvents(9,2);
   h_mueff_angle_den_clone3->SetPassedEvents(9,2);
   h_mueff_angle_den_clone3->SetTotalEvents(10,1);
   h_mueff_angle_den_clone3->SetPassedEvents(10,1);
   h_mueff_angle_den_clone3->SetTotalEvents(11,3);
   h_mueff_angle_den_clone3->SetPassedEvents(11,3);
   h_mueff_angle_den_clone3->SetTotalEvents(12,1);
   h_mueff_angle_den_clone3->SetPassedEvents(12,0);
   h_mueff_angle_den_clone3->SetTotalEvents(13,1);
   h_mueff_angle_den_clone3->SetPassedEvents(13,1);
   h_mueff_angle_den_clone3->SetTotalEvents(14,3);
   h_mueff_angle_den_clone3->SetPassedEvents(14,2);
   h_mueff_angle_den_clone3->SetTotalEvents(15,5);
   h_mueff_angle_den_clone3->SetPassedEvents(15,4);
   h_mueff_angle_den_clone3->SetTotalEvents(16,0);
   h_mueff_angle_den_clone3->SetPassedEvents(16,0);
   h_mueff_angle_den_clone3->SetFillColor(19);
   h_mueff_angle_den_clone3->Draw("ap");
   c1_n3->Modified();
   c1_n3->cd();
   c1_n3->SetSelected(c1_n3);
}

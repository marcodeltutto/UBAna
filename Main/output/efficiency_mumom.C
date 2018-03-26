void efficiency_mumom()
{
//=========Macro generated from canvas: c1_n4/c1_n4
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n4 = new TCanvas("c1_n4", "c1_n4",0,0,700,500);
   c1_n4->SetHighLightColor(2);
   c1_n4->Range(-0.34375,-0.1375,3.09375,1.2375);
   c1_n4->SetFillColor(0);
   c1_n4->SetBorderMode(0);
   c1_n4->SetBorderSize(2);
   c1_n4->SetFrameBorderMode(0);
   c1_n4->SetFrameBorderMode(0);
   Double_t xAxis1[7] = {0, 0.18, 0.3, 0.45, 0.77, 1.28, 2.5}; 
   
   TEfficiency * h_eff_mumom_den_clone4 = new TEfficiency("h_eff_mumom_den_clone","",6,xAxis1);
   
   h_eff_mumom_den_clone4->SetConfidenceLevel(0.6826895);
   h_eff_mumom_den_clone4->SetBetaAlpha(1);
   h_eff_mumom_den_clone4->SetBetaBeta(1);
   h_eff_mumom_den_clone4->SetWeight(1);
   h_eff_mumom_den_clone4->SetStatisticOption(0);
   h_eff_mumom_den_clone4->SetPosteriorMode(0);
   h_eff_mumom_den_clone4->SetShortestInterval(0);
   h_eff_mumom_den_clone4->SetTotalEvents(0,0);
   h_eff_mumom_den_clone4->SetPassedEvents(0,0);
   h_eff_mumom_den_clone4->SetTotalEvents(1,1);
   h_eff_mumom_den_clone4->SetPassedEvents(1,1);
   h_eff_mumom_den_clone4->SetTotalEvents(2,3);
   h_eff_mumom_den_clone4->SetPassedEvents(2,1);
   h_eff_mumom_den_clone4->SetTotalEvents(3,3);
   h_eff_mumom_den_clone4->SetPassedEvents(3,1);
   h_eff_mumom_den_clone4->SetTotalEvents(4,3);
   h_eff_mumom_den_clone4->SetPassedEvents(4,0);
   h_eff_mumom_den_clone4->SetTotalEvents(5,4);
   h_eff_mumom_den_clone4->SetPassedEvents(5,1);
   h_eff_mumom_den_clone4->SetTotalEvents(6,2);
   h_eff_mumom_den_clone4->SetPassedEvents(6,0);
   h_eff_mumom_den_clone4->SetTotalEvents(7,0);
   h_eff_mumom_den_clone4->SetPassedEvents(7,0);
   h_eff_mumom_den_clone4->SetFillColor(19);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#006600");
   h_eff_mumom_den_clone4->SetLineColor(ci);

   ci = TColor::GetColor("#006600");
   h_eff_mumom_den_clone4->SetMarkerColor(ci);
   h_eff_mumom_den_clone4->SetMarkerStyle(20);
   h_eff_mumom_den_clone4->SetMarkerSize(0.5);
   h_eff_mumom_den_clone4->Draw("ap");
   c1_n4->Modified();
   c1_n4->cd();
   c1_n4->SetSelected(c1_n4);
}

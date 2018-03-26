void efficiency_muangle()
{
//=========Macro generated from canvas: c1_n5/c1_n5
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n5 = new TCanvas("c1_n5", "c1_n5",0,0,700,500);
   c1_n5->SetHighLightColor(2);
   c1_n5->Range(-0.1375,-0.1375,1.2375,1.2375);
   c1_n5->SetFillColor(0);
   c1_n5->SetBorderMode(0);
   c1_n5->SetBorderSize(2);
   c1_n5->SetFrameBorderMode(0);
   c1_n5->SetFrameBorderMode(0);
   Double_t xAxis2[10] = {-1, -0.5, 0, 0.27, 0.45, 0.62, 0.76, 0.86, 0.94, 1}; 
   
   TEfficiency * h_eff_muangle_den_clone5 = new TEfficiency("h_eff_muangle_den_clone","",9,xAxis2);
   
   h_eff_muangle_den_clone5->SetConfidenceLevel(0.6826895);
   h_eff_muangle_den_clone5->SetBetaAlpha(1);
   h_eff_muangle_den_clone5->SetBetaBeta(1);
   h_eff_muangle_den_clone5->SetWeight(1);
   h_eff_muangle_den_clone5->SetStatisticOption(0);
   h_eff_muangle_den_clone5->SetPosteriorMode(0);
   h_eff_muangle_den_clone5->SetShortestInterval(0);
   h_eff_muangle_den_clone5->SetTotalEvents(0,0);
   h_eff_muangle_den_clone5->SetPassedEvents(0,0);
   h_eff_muangle_den_clone5->SetTotalEvents(1,0);
   h_eff_muangle_den_clone5->SetPassedEvents(1,0);
   h_eff_muangle_den_clone5->SetTotalEvents(2,0);
   h_eff_muangle_den_clone5->SetPassedEvents(2,0);
   h_eff_muangle_den_clone5->SetTotalEvents(3,3);
   h_eff_muangle_den_clone5->SetPassedEvents(3,1);
   h_eff_muangle_den_clone5->SetTotalEvents(4,3);
   h_eff_muangle_den_clone5->SetPassedEvents(4,2);
   h_eff_muangle_den_clone5->SetTotalEvents(5,1);
   h_eff_muangle_den_clone5->SetPassedEvents(5,0);
   h_eff_muangle_den_clone5->SetTotalEvents(6,1);
   h_eff_muangle_den_clone5->SetPassedEvents(6,0);
   h_eff_muangle_den_clone5->SetTotalEvents(7,3);
   h_eff_muangle_den_clone5->SetPassedEvents(7,0);
   h_eff_muangle_den_clone5->SetTotalEvents(8,1);
   h_eff_muangle_den_clone5->SetPassedEvents(8,1);
   h_eff_muangle_den_clone5->SetTotalEvents(9,4);
   h_eff_muangle_den_clone5->SetPassedEvents(9,0);
   h_eff_muangle_den_clone5->SetTotalEvents(10,0);
   h_eff_muangle_den_clone5->SetPassedEvents(10,0);
   h_eff_muangle_den_clone5->SetFillColor(19);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#006600");
   h_eff_muangle_den_clone5->SetLineColor(ci);

   ci = TColor::GetColor("#006600");
   h_eff_muangle_den_clone5->SetMarkerColor(ci);
   h_eff_muangle_den_clone5->SetMarkerStyle(20);
   h_eff_muangle_den_clone5->SetMarkerSize(0.5);
   h_eff_muangle_den_clone5->Draw("ap");
   c1_n5->Modified();
   c1_n5->cd();
   c1_n5->SetSelected(c1_n5);
}

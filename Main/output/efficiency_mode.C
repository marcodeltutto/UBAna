void efficiency_mode()
{
//=========Macro generated from canvas: c1_n10/c1_n10
//=========  (Mon Mar 26 10:42:02 2018) by ROOT version6.06/06
   TCanvas *c1_n10 = new TCanvas("c1_n10", "c1_n10",0,0,700,500);
   c1_n10->SetHighLightColor(2);
   c1_n10->Range(0.3,-0.125,2.1,1.125);
   c1_n10->SetFillColor(0);
   c1_n10->SetBorderMode(0);
   c1_n10->SetBorderSize(2);
   c1_n10->SetFrameBorderMode(0);
   c1_n10->SetFrameBorderMode(0);
   
   TEfficiency * h_eff_qe_den_clone10 = new TEfficiency("h_eff_qe_den_clone","",15,0,3);
   
   h_eff_qe_den_clone10->SetConfidenceLevel(0.6826895);
   h_eff_qe_den_clone10->SetBetaAlpha(1);
   h_eff_qe_den_clone10->SetBetaBeta(1);
   h_eff_qe_den_clone10->SetWeight(1);
   h_eff_qe_den_clone10->SetStatisticOption(0);
   h_eff_qe_den_clone10->SetPosteriorMode(0);
   h_eff_qe_den_clone10->SetShortestInterval(0);
   h_eff_qe_den_clone10->SetTotalEvents(0,0);
   h_eff_qe_den_clone10->SetPassedEvents(0,0);
   h_eff_qe_den_clone10->SetTotalEvents(1,0);
   h_eff_qe_den_clone10->SetPassedEvents(1,0);
   h_eff_qe_den_clone10->SetTotalEvents(2,0);
   h_eff_qe_den_clone10->SetPassedEvents(2,0);
   h_eff_qe_den_clone10->SetTotalEvents(3,0);
   h_eff_qe_den_clone10->SetPassedEvents(3,0);
   h_eff_qe_den_clone10->SetTotalEvents(4,1);
   h_eff_qe_den_clone10->SetPassedEvents(4,0);
   h_eff_qe_den_clone10->SetTotalEvents(5,0);
   h_eff_qe_den_clone10->SetPassedEvents(5,0);
   h_eff_qe_den_clone10->SetTotalEvents(6,1);
   h_eff_qe_den_clone10->SetPassedEvents(6,1);
   h_eff_qe_den_clone10->SetTotalEvents(7,0);
   h_eff_qe_den_clone10->SetPassedEvents(7,0);
   h_eff_qe_den_clone10->SetTotalEvents(8,1);
   h_eff_qe_den_clone10->SetPassedEvents(8,0);
   h_eff_qe_den_clone10->SetTotalEvents(9,1);
   h_eff_qe_den_clone10->SetPassedEvents(9,0);
   h_eff_qe_den_clone10->SetTotalEvents(10,0);
   h_eff_qe_den_clone10->SetPassedEvents(10,0);
   h_eff_qe_den_clone10->SetTotalEvents(11,0);
   h_eff_qe_den_clone10->SetPassedEvents(11,0);
   h_eff_qe_den_clone10->SetTotalEvents(12,0);
   h_eff_qe_den_clone10->SetPassedEvents(12,0);
   h_eff_qe_den_clone10->SetTotalEvents(13,0);
   h_eff_qe_den_clone10->SetPassedEvents(13,0);
   h_eff_qe_den_clone10->SetTotalEvents(14,0);
   h_eff_qe_den_clone10->SetPassedEvents(14,0);
   h_eff_qe_den_clone10->SetTotalEvents(15,0);
   h_eff_qe_den_clone10->SetPassedEvents(15,0);
   h_eff_qe_den_clone10->SetTotalEvents(16,0);
   h_eff_qe_den_clone10->SetPassedEvents(16,0);
   h_eff_qe_den_clone10->SetFillColor(19);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#006600");
   h_eff_qe_den_clone10->SetLineColor(ci);

   ci = TColor::GetColor("#006600");
   h_eff_qe_den_clone10->SetMarkerColor(ci);
   h_eff_qe_den_clone10->SetMarkerStyle(20);
   h_eff_qe_den_clone10->SetMarkerSize(0.5);
   h_eff_qe_den_clone10->Draw("alp");
   
   TEfficiency * h_eff_res_den_clone11 = new TEfficiency("h_eff_res_den_clone","",15,0,3);
   
   h_eff_res_den_clone11->SetConfidenceLevel(0.6826895);
   h_eff_res_den_clone11->SetBetaAlpha(1);
   h_eff_res_den_clone11->SetBetaBeta(1);
   h_eff_res_den_clone11->SetWeight(1);
   h_eff_res_den_clone11->SetStatisticOption(0);
   h_eff_res_den_clone11->SetPosteriorMode(0);
   h_eff_res_den_clone11->SetShortestInterval(0);
   h_eff_res_den_clone11->SetTotalEvents(0,0);
   h_eff_res_den_clone11->SetPassedEvents(0,0);
   h_eff_res_den_clone11->SetTotalEvents(1,0);
   h_eff_res_den_clone11->SetPassedEvents(1,0);
   h_eff_res_den_clone11->SetTotalEvents(2,0);
   h_eff_res_den_clone11->SetPassedEvents(2,0);
   h_eff_res_den_clone11->SetTotalEvents(3,0);
   h_eff_res_den_clone11->SetPassedEvents(3,0);
   h_eff_res_den_clone11->SetTotalEvents(4,2);
   h_eff_res_den_clone11->SetPassedEvents(4,1);
   h_eff_res_den_clone11->SetTotalEvents(5,0);
   h_eff_res_den_clone11->SetPassedEvents(5,0);
   h_eff_res_den_clone11->SetTotalEvents(6,0);
   h_eff_res_den_clone11->SetPassedEvents(6,0);
   h_eff_res_den_clone11->SetTotalEvents(7,1);
   h_eff_res_den_clone11->SetPassedEvents(7,1);
   h_eff_res_den_clone11->SetTotalEvents(8,0);
   h_eff_res_den_clone11->SetPassedEvents(8,0);
   h_eff_res_den_clone11->SetTotalEvents(9,0);
   h_eff_res_den_clone11->SetPassedEvents(9,0);
   h_eff_res_den_clone11->SetTotalEvents(10,0);
   h_eff_res_den_clone11->SetPassedEvents(10,0);
   h_eff_res_den_clone11->SetTotalEvents(11,1);
   h_eff_res_den_clone11->SetPassedEvents(11,0);
   h_eff_res_den_clone11->SetTotalEvents(12,0);
   h_eff_res_den_clone11->SetPassedEvents(12,0);
   h_eff_res_den_clone11->SetTotalEvents(13,1);
   h_eff_res_den_clone11->SetPassedEvents(13,0);
   h_eff_res_den_clone11->SetTotalEvents(14,0);
   h_eff_res_den_clone11->SetPassedEvents(14,0);
   h_eff_res_den_clone11->SetTotalEvents(15,0);
   h_eff_res_den_clone11->SetPassedEvents(15,0);
   h_eff_res_den_clone11->SetTotalEvents(16,0);
   h_eff_res_den_clone11->SetPassedEvents(16,0);
   h_eff_res_den_clone11->SetFillColor(19);

   ci = TColor::GetColor("#660000");
   h_eff_res_den_clone11->SetLineColor(ci);

   ci = TColor::GetColor("#660000");
   h_eff_res_den_clone11->SetMarkerColor(ci);
   h_eff_res_den_clone11->SetMarkerStyle(20);
   h_eff_res_den_clone11->SetMarkerSize(0.5);
   h_eff_res_den_clone11->Draw("lp same");
   
   TEfficiency * h_eff_dis_den_clone12 = new TEfficiency("h_eff_dis_den_clone","",15,0,3);
   
   h_eff_dis_den_clone12->SetConfidenceLevel(0.6826895);
   h_eff_dis_den_clone12->SetBetaAlpha(1);
   h_eff_dis_den_clone12->SetBetaBeta(1);
   h_eff_dis_den_clone12->SetWeight(1);
   h_eff_dis_den_clone12->SetStatisticOption(0);
   h_eff_dis_den_clone12->SetPosteriorMode(0);
   h_eff_dis_den_clone12->SetShortestInterval(0);
   h_eff_dis_den_clone12->SetTotalEvents(0,0);
   h_eff_dis_den_clone12->SetPassedEvents(0,0);
   h_eff_dis_den_clone12->SetTotalEvents(1,0);
   h_eff_dis_den_clone12->SetPassedEvents(1,0);
   h_eff_dis_den_clone12->SetTotalEvents(2,0);
   h_eff_dis_den_clone12->SetPassedEvents(2,0);
   h_eff_dis_den_clone12->SetTotalEvents(3,0);
   h_eff_dis_den_clone12->SetPassedEvents(3,0);
   h_eff_dis_den_clone12->SetTotalEvents(4,0);
   h_eff_dis_den_clone12->SetPassedEvents(4,0);
   h_eff_dis_den_clone12->SetTotalEvents(5,1);
   h_eff_dis_den_clone12->SetPassedEvents(5,0);
   h_eff_dis_den_clone12->SetTotalEvents(6,0);
   h_eff_dis_den_clone12->SetPassedEvents(6,0);
   h_eff_dis_den_clone12->SetTotalEvents(7,0);
   h_eff_dis_den_clone12->SetPassedEvents(7,0);
   h_eff_dis_den_clone12->SetTotalEvents(8,1);
   h_eff_dis_den_clone12->SetPassedEvents(8,0);
   h_eff_dis_den_clone12->SetTotalEvents(9,0);
   h_eff_dis_den_clone12->SetPassedEvents(9,0);
   h_eff_dis_den_clone12->SetTotalEvents(10,0);
   h_eff_dis_den_clone12->SetPassedEvents(10,0);
   h_eff_dis_den_clone12->SetTotalEvents(11,0);
   h_eff_dis_den_clone12->SetPassedEvents(11,0);
   h_eff_dis_den_clone12->SetTotalEvents(12,0);
   h_eff_dis_den_clone12->SetPassedEvents(12,0);
   h_eff_dis_den_clone12->SetTotalEvents(13,0);
   h_eff_dis_den_clone12->SetPassedEvents(13,0);
   h_eff_dis_den_clone12->SetTotalEvents(14,0);
   h_eff_dis_den_clone12->SetPassedEvents(14,0);
   h_eff_dis_den_clone12->SetTotalEvents(15,0);
   h_eff_dis_den_clone12->SetPassedEvents(15,0);
   h_eff_dis_den_clone12->SetTotalEvents(16,0);
   h_eff_dis_den_clone12->SetPassedEvents(16,0);
   h_eff_dis_den_clone12->SetFillColor(19);

   ci = TColor::GetColor("#000066");
   h_eff_dis_den_clone12->SetLineColor(ci);

   ci = TColor::GetColor("#000066");
   h_eff_dis_den_clone12->SetMarkerColor(ci);
   h_eff_dis_den_clone12->SetMarkerStyle(20);
   h_eff_dis_den_clone12->SetMarkerSize(0.5);
   h_eff_dis_den_clone12->Draw("lp same");
   
   TEfficiency * h_eff_coh_den_clone13 = new TEfficiency("h_eff_coh_den_clone","",15,0,3);
   
   h_eff_coh_den_clone13->SetConfidenceLevel(0.6826895);
   h_eff_coh_den_clone13->SetBetaAlpha(1);
   h_eff_coh_den_clone13->SetBetaBeta(1);
   h_eff_coh_den_clone13->SetWeight(1);
   h_eff_coh_den_clone13->SetStatisticOption(0);
   h_eff_coh_den_clone13->SetPosteriorMode(0);
   h_eff_coh_den_clone13->SetShortestInterval(0);
   h_eff_coh_den_clone13->SetTotalEvents(0,0);
   h_eff_coh_den_clone13->SetPassedEvents(0,0);
   h_eff_coh_den_clone13->SetTotalEvents(1,0);
   h_eff_coh_den_clone13->SetPassedEvents(1,0);
   h_eff_coh_den_clone13->SetTotalEvents(2,0);
   h_eff_coh_den_clone13->SetPassedEvents(2,0);
   h_eff_coh_den_clone13->SetTotalEvents(3,0);
   h_eff_coh_den_clone13->SetPassedEvents(3,0);
   h_eff_coh_den_clone13->SetTotalEvents(4,0);
   h_eff_coh_den_clone13->SetPassedEvents(4,0);
   h_eff_coh_den_clone13->SetTotalEvents(5,0);
   h_eff_coh_den_clone13->SetPassedEvents(5,0);
   h_eff_coh_den_clone13->SetTotalEvents(6,0);
   h_eff_coh_den_clone13->SetPassedEvents(6,0);
   h_eff_coh_den_clone13->SetTotalEvents(7,0);
   h_eff_coh_den_clone13->SetPassedEvents(7,0);
   h_eff_coh_den_clone13->SetTotalEvents(8,0);
   h_eff_coh_den_clone13->SetPassedEvents(8,0);
   h_eff_coh_den_clone13->SetTotalEvents(9,0);
   h_eff_coh_den_clone13->SetPassedEvents(9,0);
   h_eff_coh_den_clone13->SetTotalEvents(10,0);
   h_eff_coh_den_clone13->SetPassedEvents(10,0);
   h_eff_coh_den_clone13->SetTotalEvents(11,0);
   h_eff_coh_den_clone13->SetPassedEvents(11,0);
   h_eff_coh_den_clone13->SetTotalEvents(12,0);
   h_eff_coh_den_clone13->SetPassedEvents(12,0);
   h_eff_coh_den_clone13->SetTotalEvents(13,0);
   h_eff_coh_den_clone13->SetPassedEvents(13,0);
   h_eff_coh_den_clone13->SetTotalEvents(14,0);
   h_eff_coh_den_clone13->SetPassedEvents(14,0);
   h_eff_coh_den_clone13->SetTotalEvents(15,0);
   h_eff_coh_den_clone13->SetPassedEvents(15,0);
   h_eff_coh_den_clone13->SetTotalEvents(16,0);
   h_eff_coh_den_clone13->SetPassedEvents(16,0);
   h_eff_coh_den_clone13->SetFillColor(19);

   ci = TColor::GetColor("#ff9900");
   h_eff_coh_den_clone13->SetLineColor(ci);

   ci = TColor::GetColor("#ff9900");
   h_eff_coh_den_clone13->SetMarkerColor(ci);
   h_eff_coh_den_clone13->SetMarkerStyle(20);
   h_eff_coh_den_clone13->SetMarkerSize(0.5);
   h_eff_coh_den_clone13->Draw("lp same");
   
   TEfficiency * h_eff_mec_den_clone14 = new TEfficiency("h_eff_mec_den_clone","",15,0,3);
   
   h_eff_mec_den_clone14->SetConfidenceLevel(0.6826895);
   h_eff_mec_den_clone14->SetBetaAlpha(1);
   h_eff_mec_den_clone14->SetBetaBeta(1);
   h_eff_mec_den_clone14->SetWeight(1);
   h_eff_mec_den_clone14->SetStatisticOption(0);
   h_eff_mec_den_clone14->SetPosteriorMode(0);
   h_eff_mec_den_clone14->SetShortestInterval(0);
   h_eff_mec_den_clone14->SetTotalEvents(0,0);
   h_eff_mec_den_clone14->SetPassedEvents(0,0);
   h_eff_mec_den_clone14->SetTotalEvents(1,0);
   h_eff_mec_den_clone14->SetPassedEvents(1,0);
   h_eff_mec_den_clone14->SetTotalEvents(2,0);
   h_eff_mec_den_clone14->SetPassedEvents(2,0);
   h_eff_mec_den_clone14->SetTotalEvents(3,1);
   h_eff_mec_den_clone14->SetPassedEvents(3,1);
   h_eff_mec_den_clone14->SetTotalEvents(4,2);
   h_eff_mec_den_clone14->SetPassedEvents(4,0);
   h_eff_mec_den_clone14->SetTotalEvents(5,0);
   h_eff_mec_den_clone14->SetPassedEvents(5,0);
   h_eff_mec_den_clone14->SetTotalEvents(6,0);
   h_eff_mec_den_clone14->SetPassedEvents(6,0);
   h_eff_mec_den_clone14->SetTotalEvents(7,1);
   h_eff_mec_den_clone14->SetPassedEvents(7,0);
   h_eff_mec_den_clone14->SetTotalEvents(8,0);
   h_eff_mec_den_clone14->SetPassedEvents(8,0);
   h_eff_mec_den_clone14->SetTotalEvents(9,0);
   h_eff_mec_den_clone14->SetPassedEvents(9,0);
   h_eff_mec_den_clone14->SetTotalEvents(10,0);
   h_eff_mec_den_clone14->SetPassedEvents(10,0);
   h_eff_mec_den_clone14->SetTotalEvents(11,1);
   h_eff_mec_den_clone14->SetPassedEvents(11,0);
   h_eff_mec_den_clone14->SetTotalEvents(12,0);
   h_eff_mec_den_clone14->SetPassedEvents(12,0);
   h_eff_mec_den_clone14->SetTotalEvents(13,0);
   h_eff_mec_den_clone14->SetPassedEvents(13,0);
   h_eff_mec_den_clone14->SetTotalEvents(14,0);
   h_eff_mec_den_clone14->SetPassedEvents(14,0);
   h_eff_mec_den_clone14->SetTotalEvents(15,0);
   h_eff_mec_den_clone14->SetPassedEvents(15,0);
   h_eff_mec_den_clone14->SetTotalEvents(16,0);
   h_eff_mec_den_clone14->SetPassedEvents(16,0);
   h_eff_mec_den_clone14->SetFillColor(19);

   ci = TColor::GetColor("#cc00cc");
   h_eff_mec_den_clone14->SetLineColor(ci);

   ci = TColor::GetColor("#cc00cc");
   h_eff_mec_den_clone14->SetMarkerColor(ci);
   h_eff_mec_den_clone14->SetMarkerStyle(20);
   h_eff_mec_den_clone14->SetMarkerSize(0.5);
   h_eff_mec_den_clone14->Draw("lp same");
   
   TLegend *leg = new TLegend(0.1,0.7,0.48,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("h_eff_qe_den_clone","GENIE QE","lep");

   ci = TColor::GetColor("#006600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#006600");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_eff_res_den_clone","GENIE RES","lep");

   ci = TColor::GetColor("#660000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#660000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_eff_dis_den_clone","GENIE DIS","lep");

   ci = TColor::GetColor("#000066");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#000066");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_eff_coh_den_clone","GENIE COH","lep");

   ci = TColor::GetColor("#ff9900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff9900");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h_eff_mec_den_clone","GENIE MEC","lep");

   ci = TColor::GetColor("#cc00cc");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#cc00cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.5);
   entry->SetTextFont(42);
   leg->Draw();
   c1_n10->Modified();
   c1_n10->cd();
   c1_n10->SetSelected(c1_n10);
}

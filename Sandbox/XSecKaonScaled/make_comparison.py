import sys, os
import math
import ROOT
from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")



# Get the stuff
file_nominal = TFile("xsec_file_cv.root")
xsec_mumom_nominal = file_nominal.Get("xsec_mumom_cv")
xsec_mumom_mc_nominal = file_nominal.Get("xsec_mumom_mc_cv")
xsec_muangle_nominal = file_nominal.Get("xsec_muangle_cv")
xsec_muangle_mc_nominal = file_nominal.Get("xsec_muangle_mc_cv")
cov_mumom_nominal = file_nominal.Get("covariance_matrix_mumom_cv")
cov_muangle_nominal = file_nominal.Get("covariance_matrix_muangle_cv")

xsec_muangle_mumom_nominal = []
xsec_muangle_mumom_nominal.append(file_nominal.Get("xsec_poly_muangle_mumom_cv_bin_0"))
xsec_muangle_mumom_nominal.append(file_nominal.Get("xsec_poly_muangle_mumom_cv_bin_1"))
xsec_muangle_mumom_nominal.append(file_nominal.Get("xsec_poly_muangle_mumom_cv_bin_2"))
xsec_muangle_mumom_nominal.append(file_nominal.Get("xsec_poly_muangle_mumom_cv_bin_3"))
xsec_muangle_mumom_nominal.append(file_nominal.Get("xsec_poly_muangle_mumom_cv_bin_4"))
xsec_muangle_mumom_nominal.append(file_nominal.Get("xsec_poly_muangle_mumom_cv_bin_5"))
xsec_muangle_mumom_nominal.append(file_nominal.Get("xsec_poly_muangle_mumom_cv_bin_6"))
xsec_muangle_mumom_nominal.append(file_nominal.Get("xsec_poly_muangle_mumom_cv_bin_7"))
xsec_muangle_mumom_nominal.append(file_nominal.Get("xsec_poly_muangle_mumom_cv_bin_8"))

xsec_muangle_mumom_nominal_unc = []
xsec_muangle_mumom_nominal_unc.append(file_nominal.Get("xsec_unc_poly_muangle_mumom_cv_bin_0"))
xsec_muangle_mumom_nominal_unc.append(file_nominal.Get("xsec_unc_poly_muangle_mumom_cv_bin_1"))
xsec_muangle_mumom_nominal_unc.append(file_nominal.Get("xsec_unc_poly_muangle_mumom_cv_bin_2"))
xsec_muangle_mumom_nominal_unc.append(file_nominal.Get("xsec_unc_poly_muangle_mumom_cv_bin_3"))
xsec_muangle_mumom_nominal_unc.append(file_nominal.Get("xsec_unc_poly_muangle_mumom_cv_bin_4"))
xsec_muangle_mumom_nominal_unc.append(file_nominal.Get("xsec_unc_poly_muangle_mumom_cv_bin_5"))
xsec_muangle_mumom_nominal_unc.append(file_nominal.Get("xsec_unc_poly_muangle_mumom_cv_bin_6"))
xsec_muangle_mumom_nominal_unc.append(file_nominal.Get("xsec_unc_poly_muangle_mumom_cv_bin_7"))
xsec_muangle_mumom_nominal_unc.append(file_nominal.Get("xsec_unc_poly_muangle_mumom_cv_bin_8"))

xsec_muangle_mumom_nominal_mc = []
xsec_muangle_mumom_nominal_mc.append(file_nominal.Get("xsec_mc_poly_muangle_mumom_cv_bin_0"))
xsec_muangle_mumom_nominal_mc.append(file_nominal.Get("xsec_mc_poly_muangle_mumom_cv_bin_1"))
xsec_muangle_mumom_nominal_mc.append(file_nominal.Get("xsec_mc_poly_muangle_mumom_cv_bin_2"))
xsec_muangle_mumom_nominal_mc.append(file_nominal.Get("xsec_mc_poly_muangle_mumom_cv_bin_3"))
xsec_muangle_mumom_nominal_mc.append(file_nominal.Get("xsec_mc_poly_muangle_mumom_cv_bin_4"))
xsec_muangle_mumom_nominal_mc.append(file_nominal.Get("xsec_mc_poly_muangle_mumom_cv_bin_5"))
xsec_muangle_mumom_nominal_mc.append(file_nominal.Get("xsec_mc_poly_muangle_mumom_cv_bin_6"))
xsec_muangle_mumom_nominal_mc.append(file_nominal.Get("xsec_mc_poly_muangle_mumom_cv_bin_7"))
xsec_muangle_mumom_nominal_mc.append(file_nominal.Get("xsec_mc_poly_muangle_mumom_cv_bin_8"))



file_kaonup = TFile("xsec_file_kaonup.root")
xsec_mumom_kaonup = file_kaonup.Get("xsec_mumom_kaonup")
xsec_mumom_mc_kaonup = file_kaonup.Get("xsec_mumom_mc_kaonup")
xsec_muangle_kaonup = file_kaonup.Get("xsec_muangle_kaonup")
xsec_muangle_mc_kaonup = file_kaonup.Get("xsec_muangle_mc_kaonup")

xsec_muangle_mumom_kaonup = []
xsec_muangle_mumom_kaonup.append(file_kaonup.Get("xsec_mc_poly_muangle_mumom_kaonup_bin_0"))
xsec_muangle_mumom_kaonup.append(file_kaonup.Get("xsec_mc_poly_muangle_mumom_kaonup_bin_1"))
xsec_muangle_mumom_kaonup.append(file_kaonup.Get("xsec_mc_poly_muangle_mumom_kaonup_bin_2"))
xsec_muangle_mumom_kaonup.append(file_kaonup.Get("xsec_mc_poly_muangle_mumom_kaonup_bin_3"))
xsec_muangle_mumom_kaonup.append(file_kaonup.Get("xsec_mc_poly_muangle_mumom_kaonup_bin_4"))
xsec_muangle_mumom_kaonup.append(file_kaonup.Get("xsec_mc_poly_muangle_mumom_kaonup_bin_5"))
xsec_muangle_mumom_kaonup.append(file_kaonup.Get("xsec_mc_poly_muangle_mumom_kaonup_bin_6"))
xsec_muangle_mumom_kaonup.append(file_kaonup.Get("xsec_mc_poly_muangle_mumom_kaonup_bin_7"))
xsec_muangle_mumom_kaonup.append(file_kaonup.Get("xsec_mc_poly_muangle_mumom_kaonup_bin_8"))



file_kaondown = TFile("xsec_file_kaondown.root")
xsec_mumom_kaondown = file_kaondown.Get("xsec_mumom_kaondown")
xsec_mumom_mc_kaondown = file_kaondown.Get("xsec_mumom_mc_kaondown")
xsec_muangle_kaondown = file_kaondown.Get("xsec_muangle_kaondown")
xsec_muangle_mc_kaondown = file_kaondown.Get("xsec_muangle_mc_kaondown")

xsec_muangle_mumom_kaondown = []
xsec_muangle_mumom_kaondown.append(file_kaondown.Get("xsec_mc_poly_muangle_mumom_kaondown_bin_0"))
xsec_muangle_mumom_kaondown.append(file_kaondown.Get("xsec_mc_poly_muangle_mumom_kaondown_bin_1"))
xsec_muangle_mumom_kaondown.append(file_kaondown.Get("xsec_mc_poly_muangle_mumom_kaondown_bin_2"))
xsec_muangle_mumom_kaondown.append(file_kaondown.Get("xsec_mc_poly_muangle_mumom_kaondown_bin_3"))
xsec_muangle_mumom_kaondown.append(file_kaondown.Get("xsec_mc_poly_muangle_mumom_kaondown_bin_4"))
xsec_muangle_mumom_kaondown.append(file_kaondown.Get("xsec_mc_poly_muangle_mumom_kaondown_bin_5"))
xsec_muangle_mumom_kaondown.append(file_kaondown.Get("xsec_mc_poly_muangle_mumom_kaondown_bin_6"))
xsec_muangle_mumom_kaondown.append(file_kaondown.Get("xsec_mc_poly_muangle_mumom_kaondown_bin_7"))
xsec_muangle_mumom_kaondown.append(file_kaondown.Get("xsec_mc_poly_muangle_mumom_kaondown_bin_8"))


file_tune3 = TFile("xsec_file_tune3.root")
xsec_mumom_mc_tune3 = file_tune3.Get("xsec_mumom_mc_tune3")
xsec_muangle_mc_tune3 = file_tune3.Get("xsec_muangle_mc_tune3")

xsec_muangle_mumom_mc_tune3_0 = file_kaondown.Get("xsec_poly_muangle_mumom_cv_tune3_bin_0")
xsec_muangle_mumom_mc_tune3_1 = file_kaondown.Get("xsec_poly_muangle_mumom_cv_tune3_bin_1")
xsec_muangle_mumom_mc_tune3_2 = file_kaondown.Get("xsec_poly_muangle_mumom_cv_tune3_bin_2")
xsec_muangle_mumom_mc_tune3_3 = file_kaondown.Get("xsec_poly_muangle_mumom_cv_tune3_bin_3")
xsec_muangle_mumom_mc_tune3_4 = file_kaondown.Get("xsec_poly_muangle_mumom_cv_tune3_bin_4")
xsec_muangle_mumom_mc_tune3_5 = file_kaondown.Get("xsec_poly_muangle_mumom_cv_tune3_bin_5")
xsec_muangle_mumom_mc_tune3_6 = file_kaondown.Get("xsec_poly_muangle_mumom_cv_tune3_bin_6")
xsec_muangle_mumom_mc_tune3_7 = file_kaondown.Get("xsec_poly_muangle_mumom_cv_tune3_bin_7")
xsec_muangle_mumom_mc_tune3_8 = file_kaondown.Get("xsec_poly_muangle_mumom_cv_tune3_bin_8")



# xsec_mumom_nominal_error = xsec_mumom_nominal.Clone("xsec_mumom_nominal_error")
# xsec_muangle_nominal_error = xsec_muangle_nominal.Clone("xsec_muangle_nominal_error")

# for i in xrange(0, xsec_mumom_nominal_error.GetNbinsX()):
# 	xsec_mumom_nominal_error.SetBinError(i+1, math.sqrt(cov_mumom_nominal.GetBinContent(i+1, i+1)))
# for i in xrange(0, xsec_muangle_nominal_error.GetNbinsX()):
# 	xsec_muangle_nominal_error.SetBinError(i+1, math.sqrt(cov_muangle_nominal.GetBinContent(i+1, i+1)))







c_double = TCanvas("c_xsec_split", "multipads",0,45,1006,1150)

c_double.Divide(2, 5, 0.02, 0.01)

for i in xrange(0, 9):
  c_double.cd(i+1)
  gPad.SetBottomMargin(0.15);
  gPad.SetLeftMargin(0.18);
  gPad.SetRightMargin(0.14);
  gPad.SetTopMargin(0.13);

  gStyle.SetTitleFontSize(0.07);
  gStyle.SetTitleStyle(0);


  xsec_muangle_mumom_nominal_mc[i].SetTitle("");
  xsec_muangle_mumom_nominal_mc[i].GetXaxis().SetTitle("p_{#mu}^{reco} [GeV]");
  xsec_muangle_mumom_nominal_mc[i].GetYaxis().SetTitle("Events in Arbitrary Units");
  xsec_muangle_mumom_nominal_mc[i].GetXaxis().CenterTitle();
  xsec_muangle_mumom_nominal_mc[i].GetYaxis().CenterTitle();
  xsec_muangle_mumom_nominal_mc[i].SetLineColor(ROOT.kGreen+2);
  # xsec_muangle_mumom_nominal_mc[i].SetFillColor(29);

  xsec_muangle_mumom_nominal_mc[i].GetXaxis().SetTitleOffset(0.92);
  xsec_muangle_mumom_nominal_mc[i].GetXaxis().SetTitleSize(0.08);
  xsec_muangle_mumom_nominal_mc[i].GetXaxis().SetLabelSize(0.06);

  xsec_muangle_mumom_nominal_mc[i].GetYaxis().SetTitleOffset(0.90);
  xsec_muangle_mumom_nominal_mc[i].GetYaxis().SetTitleSize(0.09);
  xsec_muangle_mumom_nominal_mc[i].GetYaxis().SetLabelSize(0.06);

  xsec_muangle_mumom_nominal_mc[i].Draw("histo same");



  xsec_muangle_mumom_kaonup[i].SetLineColor(ROOT.kRed+1)
  xsec_muangle_mumom_kaondown[i].SetLineColor(ROOT.kRed+1)
  xsec_muangle_mumom_kaondown[i].SetLineStyle(7)
  xsec_muangle_mumom_kaonup[i].Draw("histo same");
  xsec_muangle_mumom_kaondown[i].Draw("histo same");


  xsec_muangle_mumom_nominal_unc[i].SetMarkerStyle(20);
  xsec_muangle_mumom_nominal_unc[i].SetMarkerSize(0.1);
  xsec_muangle_mumom_nominal_unc[i].Draw("E1 X0 same");
  xsec_muangle_mumom_nominal[i].SetMarkerStyle(20);
  xsec_muangle_mumom_nominal[i].SetMarkerSize(0.5);
  xsec_muangle_mumom_nominal[i].Draw("E1 X0 same")
  


c_double.cd(10)
leg = TLegend(.73,.32,.97,.53)
leg.SetBorderSize(0)
leg.SetFillColor(0)
leg.SetFillStyle(0)
leg.SetTextFont(42)
leg.SetTextSize(0.035)
leg.AddEntry(xsec_muangle_mumom_nominal_mc[0],"Tune 1 - Nominal","l")
leg.AddEntry(xsec_muangle_mumom_kaonup[0],"Tune 1 - Kaon + 50%","l")
leg.AddEntry(xsec_muangle_mumom_kaondown[0],"Tune 1 - Kaon - 50%","l")
# leg.AddEntry(xsec_mumom_mc_tune3,"Tune 3 - Nominal","l")
leg.AddEntry(xsec_muangle_mumom_nominal[0],"Data","lep")
leg.Draw()

# c_mumom = TCanvas()
# xsec_mumom_nominal_error.Draw("E1")
# xsec_mumom_nominal_error.GetXaxis().SetTitle("p_{#mu}^{reco} [GeV]")
# # xsec_mumom_nominal_error.GetYaxis().SetTitle("d#sigma/dp_{#mu} [10^{-38} cm^{2}/GeV]")
# xsec_mumom_nominal_error.GetYaxis().SetTitle("Events in Arbitrary Units")
# xsec_mumom_mc_kaondown.Draw("histo same")
# xsec_mumom_mc_kaondown.SetLineColor(kRed-3)
# xsec_mumom_mc_kaondown.SetLineStyle(9)
# xsec_mumom_mc_kaonup.Draw("histo same")
# xsec_mumom_mc_kaonup.SetLineColor(kRed-3)
# xsec_mumom_mc_kaonup.SetLineStyle(2)
# xsec_mumom_mc_nominal.Draw("histo same")
# xsec_mumom_mc_nominal.SetLineColor(kRed-3)
# xsec_mumom_mc_tune3.Draw("histo same")
# xsec_mumom_mc_tune3.SetLineColor(kGreen+2)

# leg = TLegend(.73,.32,.97,.53)
# leg.SetBorderSize(0)
# leg.SetFillColor(0)
# leg.SetFillStyle(0)
# leg.SetTextFont(42)
# leg.SetTextSize(0.035)
# leg.AddEntry(xsec_mumom_mc_nominal,"Tune 1 - Nominal","l")
# leg.AddEntry(xsec_mumom_mc_kaonup,"Tune 1 - Kaon + 50%","l")
# leg.AddEntry(xsec_mumom_mc_kaondown,"Tune 1 - Kaon - 50%","l")
# leg.AddEntry(xsec_mumom_mc_tune3,"Tune 3 - Nominal","l")
# leg.AddEntry(xsec_mumom_nominal_error,"Data","lep")
# leg.Draw()


# c_muangle = TCanvas()
# xsec_muangle_nominal_error.Draw("E1")
# xsec_muangle_nominal_error.GetXaxis().SetTitle("cos(#theta_{#mu}^{reco})")
# # xsec_muangle_nominal_error.GetYaxis().SetTitle("d#sigma/dcos(#theta_{#mu}) [10^{-38} cm^{2}]")
# xsec_muangle_nominal_error.GetYaxis().SetTitle("Events in Arbitrary Units")
# xsec_muangle_mc_kaondown.Draw("histo same")
# xsec_muangle_mc_kaondown.SetLineColor(kRed-3)
# xsec_muangle_mc_kaondown.SetLineStyle(9)
# xsec_muangle_mc_kaonup.Draw("histo same")
# xsec_muangle_mc_kaonup.SetLineColor(kRed-3)
# xsec_muangle_mc_kaonup.SetLineStyle(2)
# xsec_muangle_mc_nominal.Draw("histo same")
# xsec_muangle_mc_nominal.SetLineColor(kRed-3)
# xsec_muangle_mc_tune3.Draw("histo same")
# xsec_muangle_mc_tune3.SetLineColor(kGreen+2)

# leg.Draw()


# c_muangle = TCanvas()
# xsec_muangle_nominal_error.Draw("E1")
# xsec_muangle_nominal_error.GetXaxis().SetTitle("cos(#theta_{#mu})")
# xsec_muangle_nominal_error.GetYaxis().SetTitle("#sigma/dcos(#theta_{#mu}) [10^{-38} cm^{2}]")
# xsec_muangle_contained.Draw("histo same")
# xsec_muangle_contained.SetLineColor(kRed-3)
# leg.Draw()

raw_input("Please press enter to exit.")

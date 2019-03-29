import sys, os
import math

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

file_kaonup = TFile("xsec_file_kaonup.root")
xsec_mumom_kaonup = file_kaonup.Get("xsec_mumom_kaonup")
xsec_mumom_mc_kaonup = file_kaonup.Get("xsec_mumom_mc_kaonup")
xsec_muangle_kaonup = file_kaonup.Get("xsec_muangle_kaonup")
xsec_muangle_mc_kaonup = file_kaonup.Get("xsec_muangle_mc_kaonup")
# cov_mumom_contained = file_contained.Get("covariance_matrix_mumom_cv")
# cov_muangle_contained = file_contained.Get("covariance_matrix_muangle_cv")

file_kaondown = TFile("xsec_file_kaondown.root")
xsec_mumom_kaondown = file_kaondown.Get("xsec_mumom_kaondown")
xsec_mumom_mc_kaondown = file_kaondown.Get("xsec_mumom_mc_kaondown")
xsec_muangle_kaondown = file_kaondown.Get("xsec_muangle_kaondown")
xsec_muangle_mc_kaondown = file_kaondown.Get("xsec_muangle_mc_kaondown")

file_tune3 = TFile("xsec_file_tune3.root")
xsec_mumom_mc_tune3 = file_tune3.Get("xsec_mumom_mc_tune3")
xsec_muangle_mc_tune3 = file_tune3.Get("xsec_muangle_mc_tune3")

xsec_mumom_nominal_error = xsec_mumom_nominal.Clone("xsec_mumom_nominal_error")
xsec_muangle_nominal_error = xsec_muangle_nominal.Clone("xsec_muangle_nominal_error")

for i in xrange(0, xsec_mumom_nominal_error.GetNbinsX()):
	xsec_mumom_nominal_error.SetBinError(i+1, math.sqrt(cov_mumom_nominal.GetBinContent(i+1, i+1)))
for i in xrange(0, xsec_muangle_nominal_error.GetNbinsX()):
	xsec_muangle_nominal_error.SetBinError(i+1, math.sqrt(cov_muangle_nominal.GetBinContent(i+1, i+1)))





c_mumom = TCanvas()
xsec_mumom_nominal_error.Draw("E1")
xsec_mumom_nominal_error.GetXaxis().SetTitle("p_{#mu}^{reco} [GeV]")
# xsec_mumom_nominal_error.GetYaxis().SetTitle("d#sigma/dp_{#mu} [10^{-38} cm^{2}/GeV]")
xsec_mumom_nominal_error.GetYaxis().SetTitle("Events in Arbitrary Units")
xsec_mumom_mc_kaondown.Draw("histo same")
xsec_mumom_mc_kaondown.SetLineColor(kRed-3)
xsec_mumom_mc_kaondown.SetLineStyle(9)
xsec_mumom_mc_kaonup.Draw("histo same")
xsec_mumom_mc_kaonup.SetLineColor(kRed-3)
xsec_mumom_mc_kaonup.SetLineStyle(2)
xsec_mumom_mc_nominal.Draw("histo same")
xsec_mumom_mc_nominal.SetLineColor(kRed-3)
xsec_mumom_mc_tune3.Draw("histo same")
xsec_mumom_mc_tune3.SetLineColor(kGreen+2)

leg = TLegend(.73,.32,.97,.53)
leg.SetBorderSize(0)
leg.SetFillColor(0)
leg.SetFillStyle(0)
leg.SetTextFont(42)
leg.SetTextSize(0.035)
leg.AddEntry(xsec_mumom_mc_nominal,"Tune 1 - Nominal","l")
leg.AddEntry(xsec_mumom_mc_kaonup,"Tune 1 - Kaon + 50%","l")
leg.AddEntry(xsec_mumom_mc_kaondown,"Tune 1 - Kaon - 50%","l")
leg.AddEntry(xsec_mumom_mc_tune3,"Tune 3 - Nominal","l")
leg.AddEntry(xsec_mumom_nominal_error,"Data","lep")
leg.Draw()


c_muangle = TCanvas()
xsec_muangle_nominal_error.Draw("E1")
xsec_muangle_nominal_error.GetXaxis().SetTitle("cos(#theta_{#mu}^{reco})")
# xsec_muangle_nominal_error.GetYaxis().SetTitle("d#sigma/dcos(#theta_{#mu}) [10^{-38} cm^{2}]")
xsec_muangle_nominal_error.GetYaxis().SetTitle("Events in Arbitrary Units")
xsec_muangle_mc_kaondown.Draw("histo same")
xsec_muangle_mc_kaondown.SetLineColor(kRed-3)
xsec_muangle_mc_kaondown.SetLineStyle(9)
xsec_muangle_mc_kaonup.Draw("histo same")
xsec_muangle_mc_kaonup.SetLineColor(kRed-3)
xsec_muangle_mc_kaonup.SetLineStyle(2)
xsec_muangle_mc_nominal.Draw("histo same")
xsec_muangle_mc_nominal.SetLineColor(kRed-3)
xsec_muangle_mc_tune3.Draw("histo same")
xsec_muangle_mc_tune3.SetLineColor(kGreen+2)

leg.Draw()


# c_muangle = TCanvas()
# xsec_muangle_nominal_error.Draw("E1")
# xsec_muangle_nominal_error.GetXaxis().SetTitle("cos(#theta_{#mu})")
# xsec_muangle_nominal_error.GetYaxis().SetTitle("#sigma/dcos(#theta_{#mu}) [10^{-38} cm^{2}]")
# xsec_muangle_contained.Draw("histo same")
# xsec_muangle_contained.SetLineColor(kRed-3)
# leg.Draw()

raw_input("Please press enter to exit.")

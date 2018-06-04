import sys, os
import math

from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")



# Get the stuff
file_nominal = TFile("xsec_file_cv.root");
xsec_mumom_nominal = file_nominal.Get("xsec_mumom_cv")
xsec_muangle_nominal = file_nominal.Get("xsec_muangle_cv")
cov_mumom_nominal = file_nominal.Get("covariance_matrix_mumom_cv")
cov_muangle_nominal = file_nominal.Get("covariance_matrix_muangle_cv")

file_contained = TFile("xsec_file_contained.root");
xsec_mumom_contained = file_contained.Get("xsec_mumom_cv")
xsec_muangle_contained = file_contained.Get("xsec_muangle_cv")
cov_mumom_contained = file_contained.Get("covariance_matrix_mumom_cv")
cov_muangle_contained = file_contained.Get("covariance_matrix_muangle_cv")

file_uncontained = TFile("xsec_file_uncontained.root");
xsec_mumom_uncontained = file_uncontained.Get("xsec_mumom_cv")
xsec_muangle_uncontained = file_uncontained.Get("xsec_muangle_cv")
cov_mumom_uncontained = file_uncontained.Get("covariance_matrix_mumom_cv")
cov_muangle_uncontained = file_uncontained.Get("covariance_matrix_muangle_cv")



xsec_mumom_nominal_error = xsec_mumom_nominal.Clone("xsec_mumom_nominal_error")
xsec_muangle_nominal_error = xsec_muangle_nominal.Clone("xsec_muangle_nominal_error")

for i in xrange(0, xsec_mumom_nominal_error.GetNbinsX()):
	xsec_mumom_nominal_error.SetBinError(i+1, math.sqrt(cov_mumom_nominal.GetBinContent(i+1, i+1)))
for i in xrange(0, xsec_muangle_nominal_error.GetNbinsX()):
	xsec_muangle_nominal_error.SetBinError(i+1, math.sqrt(cov_muangle_nominal.GetBinContent(i+1, i+1)))





c_mumom = TCanvas()
xsec_mumom_nominal_error.Draw("E1")
xsec_mumom_nominal_error.GetXaxis().SetTitle("p_{#mu}^{reco} [GeV]")
xsec_mumom_nominal_error.GetYaxis().SetTitle("d#sigma/dp_{#mu} [10^{-38} cm^{2}/GeV]")
xsec_mumom_contained.Draw("histo same")
xsec_mumom_contained.SetLineColor(kRed-3)
xsec_mumom_uncontained.Draw("histo same")
xsec_mumom_uncontained.SetLineColor(kBlue-3)

leg = TLegend(.73,.32,.97,.53)
leg.SetBorderSize(0)
leg.SetFillColor(0)
leg.SetFillStyle(0)
leg.SetTextFont(42)
leg.SetTextSize(0.035)
leg.AddEntry(xsec_mumom_nominal_error,"All","lep")
leg.AddEntry(xsec_mumom_contained,"Contained","l")
leg.AddEntry(xsec_mumom_uncontained,"Exiting","l")
leg.Draw()

c_muangle = TCanvas()
xsec_muangle_nominal_error.Draw("E1")
xsec_muangle_nominal_error.GetXaxis().SetTitle("cos(#theta_{#mu})")
xsec_muangle_nominal_error.GetYaxis().SetTitle("#sigma/dcos(#theta_{#mu}) [10^{-38} cm^{2}]")
xsec_muangle_contained.Draw("histo same")
xsec_muangle_contained.SetLineColor(kRed-3)
xsec_muangle_uncontained.Draw("histo same")
xsec_muangle_uncontained.SetLineColor(kBlue-3)
leg.Draw()

raw_input("Please press enter to exit.")

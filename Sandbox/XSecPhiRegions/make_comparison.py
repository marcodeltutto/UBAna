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

file_anode = TFile("xsec_file_phicut_anode.root");
xsec_mumom_anode = file_anode.Get("xsec_mumom_phicut_anode")
xsec_muangle_anode = file_anode.Get("xsec_muangle_phicut_anode")
# cov_mumom_contained = file_contained.Get("covariance_matrix_mumom_cv")
# cov_muangle_contained = file_contained.Get("covariance_matrix_muangle_cv")

file_cathode = TFile("xsec_file_phicut_cathode.root");
xsec_mumom_cathode = file_cathode.Get("xsec_mumom_phicut_cathode")
xsec_muangle_cathode = file_cathode.Get("xsec_muangle_phicut_cathode")

file_up = TFile("xsec_file_phicut_up.root");
xsec_mumom_up = file_up.Get("xsec_mumom_phicut_up")
xsec_muangle_up = file_up.Get("xsec_muangle_phicut_up")

file_down = TFile("xsec_file_phicut_down.root");
xsec_mumom_down = file_down.Get("xsec_mumom_phicut_down")
xsec_muangle_down = file_down.Get("xsec_muangle_phicut_down")


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
xsec_mumom_up.Draw("histo same")
xsec_mumom_up.SetLineColor(kGreen-3)
xsec_mumom_cathode.Draw("histo same")
xsec_mumom_cathode.SetLineColor(kRed-3)
xsec_mumom_down.Draw("histo same")
xsec_mumom_down.SetLineColor(kBlue-3)
xsec_mumom_anode.Draw("histo same")
xsec_mumom_anode.SetLineColor(kOrange-3)

leg = TLegend(.73,.32,.97,.53)
leg.SetBorderSize(0)
leg.SetFillColor(0)
leg.SetFillStyle(0)
leg.SetTextFont(42)
leg.SetTextSize(0.035)
leg.AddEntry(xsec_mumom_nominal_error,"All","lep")
leg.AddEntry(xsec_mumom_up,"Up","l")
leg.AddEntry(xsec_mumom_cathode,"Cathode","l")
leg.AddEntry(xsec_mumom_down,"Down","l")
leg.AddEntry(xsec_mumom_anode,"Anode","l")
leg.Draw()


c_muangle = TCanvas()
xsec_muangle_nominal_error.Draw("E1")
xsec_muangle_nominal_error.GetXaxis().SetTitle("cos(#theta_{#mu}^{reco})")
xsec_muangle_nominal_error.GetYaxis().SetTitle("d#sigma/dcos(#theta_{#mu}) [10^{-38} cm^{2}]")
xsec_muangle_up.Draw("histo same")
xsec_muangle_up.SetLineColor(kGreen-3)
xsec_muangle_cathode.Draw("histo same")
xsec_muangle_cathode.SetLineColor(kRed-3)
xsec_muangle_down.Draw("histo same")
xsec_muangle_down.SetLineColor(kBlue-3)
xsec_muangle_anode.Draw("histo same")
xsec_muangle_anode.SetLineColor(kOrange-3)
leg.Draw()


# c_muangle = TCanvas()
# xsec_muangle_nominal_error.Draw("E1")
# xsec_muangle_nominal_error.GetXaxis().SetTitle("cos(#theta_{#mu})")
# xsec_muangle_nominal_error.GetYaxis().SetTitle("#sigma/dcos(#theta_{#mu}) [10^{-38} cm^{2}]")
# xsec_muangle_contained.Draw("histo same")
# xsec_muangle_contained.SetLineColor(kRed-3)
# leg.Draw()

raw_input("Please press enter to exit.")


import sys, os
import math

from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")




# pot_scale = 1.627e20/2.14249e+19
# file_cv = TFile("ubxsecana_output_mc_dirt.root")

pot_scale = 1.627e20/3.99011e+19
file_cv = TFile("ubxsecana_output_mc_bnbcosmic_dirt_ox_v1.root")



print "pot_scale is ", pot_scale

c_trktheta_classic = TCanvas()

h_trktheta_classic_total = file_cv.Get("h_trktheta_classic_total")
h_trktheta_classic_cosmic = file_cv.Get("h_trktheta_classic_cosmic")
h_trktheta_classic_outfv = file_cv.Get("h_trktheta_classic_outfv")

h_trktheta_classic_total.Scale(pot_scale)
h_trktheta_classic_cosmic.Scale(pot_scale)
h_trktheta_classic_outfv.Scale(pot_scale)

h_trktheta_classic_cosmic.SetFillColor(kBlue-3)
h_trktheta_classic_cosmic.SetLineColor(kBlue-3)

h_trktheta_classic_outfv.SetFillColor(kGreen+2)
h_trktheta_classic_outfv.SetLineColor(kGreen+2)

hs_trktheta_classic_mc = THStack("hs_trktheta_classic",";cos(#theta_{#mu}^{reco}); Selected Events")

hs_trktheta_classic_mc.Add(h_trktheta_classic_cosmic)
hs_trktheta_classic_mc.Add(h_trktheta_classic_outfv)

hs_trktheta_classic_mc.Draw("hist")

h_trktheta_classic_total.SetFillColor(kBlack)
h_trktheta_classic_total.SetFillStyle(3005)
h_trktheta_classic_total.Draw("E1 X0 same")

leg = TLegend(.73,.32,.97,.53)
leg.SetBorderSize(0)
leg.SetFillColor(0)
leg.SetFillStyle(0)
leg.SetTextFont(42)
leg.SetTextSize(0.035)
leg.AddEntry(h_trktheta_classic_outfv, "OUTFV","f")
leg.AddEntry(h_trktheta_classic_cosmic, "Cosmic in BNB","f")
leg.AddEntry(h_trktheta_classic_total, "Stat Unc.","f")
leg.Draw()






c_vtxz = TCanvas()

h_vtxz_total = file_cv.Get("h_vtxz_total")


h_vtxz_total.Scale(pot_scale)

h_vtxz_total.GetXaxis().SetTitle("Candidate Neutrino Vertex Z [cm]")
h_vtxz_total.GetYaxis().SetTitle("Selected Events")


h_vtxz_total.Draw("histo E1")





raw_input("Please press enter to exit.")


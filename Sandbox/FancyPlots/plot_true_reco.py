import sys, os, math
import ROOT
from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

f_ubana = ROOT.TFile("./xsec_file_cv.root")


f = ROOT.TFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_all.root")
t = f.Get("true_reco_tree")

gStyle.SetPalette(kBird)



c_mumom = ROOT.TCanvas("c_mumom", "c_mumom", 1024, 1024)

gPad.SetBottomMargin(0.15);
gPad.SetLeftMargin(0.15);
gPad.SetRightMargin(0.15);
gPad.SetTopMargin(0.15);

h_mumom= TH2F("h_mumom",";Muon Momentum (Truth) [GeV];Muon Momentum (MCS) [GeV]", 100, 0, 2.5, 100, 0, 2.5);

h_mumom.GetXaxis().SetTitleSize(0.05)
h_mumom.GetXaxis().SetTitleOffset(0.9)
h_mumom.GetXaxis().CenterTitle(True)
h_mumom.GetYaxis().SetTitleSize(0.05)
h_mumom.GetYaxis().SetTitleOffset(1.3)
h_mumom.GetYaxis().CenterTitle(True)

t.Draw("mom_mcs:mom_true>>h_mumom", "mom_true>0&&mom_true<2.5&&mom_mcs>0&&mom_mcs<2.5", "colz")

# h_mumom.Scale(1/h_mumom.Integral())
line = TLine(0,0,2.5,2.5);
line.SetLineColor(kRed);
line.Draw();

c_mumom.SaveAs("true_reco_mumom.pdf")






c_muangle = ROOT.TCanvas("c_muangle", "c_muangle", 1024, 1024)

gPad.SetBottomMargin(0.15);
gPad.SetLeftMargin(0.15);
gPad.SetRightMargin(0.15);
gPad.SetTopMargin(0.15);

h_muangle= TH2F("h_muangle",";Muon cos(#theta) (Truth);Muon cos(#theta) (Reco)", 100, -1, 1, 100, -1, 1);

h_muangle.GetXaxis().SetTitleSize(0.05)
h_muangle.GetXaxis().SetTitleOffset(0.9)
h_muangle.GetXaxis().CenterTitle(True)
h_muangle.GetYaxis().SetTitleSize(0.05)
h_muangle.GetYaxis().SetTitleOffset(1.3)
h_muangle.GetYaxis().CenterTitle(True)

t.Draw("angle_reco:angle_true>>h_muangle", "", "colz")



# h_muangle.Scale(1/h_muangle.Integral())
line2 = TLine(-1,-1,1,1);
line2.SetLineColor(kRed);
line2.Draw();

c_muangle.SaveAs("true_reco_muangle.pdf")





raw_input("Please press enter to exit.")

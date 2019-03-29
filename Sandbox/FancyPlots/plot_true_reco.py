import sys, os, math
from array import array
import ROOT
from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

f_ubana = ROOT.TFile("./xsec_file_cv.root")


total_signal_events = 15348

forward_res = True


f = ROOT.TFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_all.root")
t = f.Get("true_reco_tree")

gStyle.SetPalette(kBird)

simul = TLatex(0.8003914,0.8228228, "MicroBooNE #bf{Simulation}");
simul.SetTextFont(62);
simul.SetTextColor(kGray+2);
simul.SetNDC();
simul.SetTextSize(1/30.);
simul.SetTextAlign(32);
# simul.SetTextSize(0.04631579);


padding = 0.20


c_mumom = ROOT.TCanvas("c_mumom", "c_mumom", 1024, 1024)

gPad.SetBottomMargin(padding);
gPad.SetLeftMargin(padding);
gPad.SetRightMargin(padding);
gPad.SetTopMargin(padding);

pbins = array("d",[0.00, 0.18, 0.30, 0.45, 0.77, 1.28, 2.50])
# h_mumom = TH2F("h_mumom",";Generated Muon Momentum [GeV];Measured Muon Momentum [GeV]", 100, 0, 2.5, 100, 0, 2.5);
h_mumom = TH2F("h_mumom",";Generated Muon Momentum [GeV];Measured Muon Momentum [GeV];Selected #nu_{#mu} CC Events / 1.6 x 10^{20} POT", 6, pbins, 6, pbins);
if forward_res:
  h_mumom = TH1F("h_mumom",";(Generated Muon Momentum) - (Measured Muon Momentum) [GeV]", 100, -2, 2);
  

h_mumom.GetXaxis().SetTitleSize(0.04)
h_mumom.GetXaxis().SetTitleOffset(1.0)
h_mumom.GetXaxis().CenterTitle(True)
h_mumom.GetYaxis().SetTitleSize(0.04)
h_mumom.GetYaxis().SetTitleOffset(1.4)
h_mumom.GetYaxis().CenterTitle(True)
h_mumom.GetZaxis().SetTitleSize(0.04)
h_mumom.GetZaxis().SetTitleOffset(1.8)
h_mumom.GetZaxis().CenterTitle(True)


if forward_res:
  # t.Draw("mom_mcs-mom_true>>h_mumom", "mom_true>0&&mom_true<2.5&&mom_mcs>0&&mom_mcs<2.5&&angle_true>0.94&&angle_true<1.00", "histo")
  t.Draw("mom_mcs-mom_true>>h_mumom", "mom_true>0&&mom_true<2.5&&mom_mcs>0&&mom_mcs<2.5&&angle_true>0.86&&angle_true<0.94", "histo")
  print 'mumom RMS', h_mumom.GetRMS()
else:
  t.Draw("mom_mcs:mom_true>>h_mumom", "mom_true>0&&mom_true<2.5&&mom_mcs>0&&mom_mcs<2.5", "colz")

h_mumom.Scale(total_signal_events/h_mumom.Integral())

simul.Draw();

# h_mumom.Scale(1/h_mumom.Integral())
if forward_res:
  line = TLine(0,0,0,h_mumom.GetMaximum());
else:
  line = TLine(0,0,2.5,2.5);
line.SetLineColor(kRed);
line.Draw();

c_mumom.SaveAs("true_reco_mumom.pdf")






c_muangle = ROOT.TCanvas("c_muangle", "c_muangle", 1024, 1024)

gPad.SetBottomMargin(padding);
gPad.SetLeftMargin(padding);
gPad.SetRightMargin(padding);
gPad.SetTopMargin(padding);

ctbins = array("d",[-1.00, -0.50, 0.00, 0.27, 0.45, 0.62, 0.76, 0.86, 0.94, 1.00])
h_muangle = TH2F("h_muangle",";Generated Muon cos(#theta);Measured Muon cos(#theta);Selected #nu_{#mu} CC Events / 1.6 x 10^{20} POT", 9, ctbins, 9, ctbins);
# h_muangle = TH2F("h_muangle",";Generated Muon cos(#theta);Measured Muon cos(#theta)", 100, -1, 1, 100, -1, 1);
if forward_res:
  h_muangle = TH1F("h_muangle",";(Generated Muon cos(#theta)) - (Measured Muon cos(#theta))", 100, -0.1, 0.1);

h_muangle.GetXaxis().SetTitleSize(0.04)
h_muangle.GetXaxis().SetTitleOffset(1.0)
h_muangle.GetXaxis().CenterTitle(True)
h_muangle.GetYaxis().SetTitleSize(0.04)
h_muangle.GetYaxis().SetTitleOffset(1.4)
h_muangle.GetYaxis().CenterTitle(True)
h_muangle.GetZaxis().SetTitleSize(0.04)
h_muangle.GetZaxis().SetTitleOffset(1.8)
h_muangle.GetZaxis().CenterTitle(True)

if forward_res:
  t.Draw("angle_reco-angle_true>>h_muangle", "angle_true>0.86&&angle_true<0.94", "histo")
  print 'mumom RMS', h_muangle.GetRMS()
else:
  t.Draw("angle_reco:angle_true>>h_muangle", "", "colz")


h_muangle.Scale(total_signal_events/h_muangle.Integral())

simul.Draw();


# h_muangle.Scale(1/h_muangle.Integral())
if forward_res:
  line2 = TLine(0,0,0,h_muangle.GetMaximum());
else:
  line2 = TLine(-1,-1,1,1);
line2.SetLineColor(kRed);
line2.Draw();

if forward_res:
  # label = TLatex(0.7886497,0.7602906, '#splitline{0.94 #leq cos(#theta_{#mu}^{reco}) #leq 1.00}{Resolution = 1.5%}');
  label = TLatex(0.7886497,0.7602906, '#splitline{0.86 #leq cos(#theta_{#mu}^{reco}) < 0.94}{Resolution = 2.8%}');
  label.SetNDC();
  label.SetTextSize(0.03333334);
  label.SetTextAlign(32);
  label.SetLineWidth(2);
  label.SetTextFont(42);
  label.Draw();

c_muangle.SaveAs("true_reco_muangle.pdf")





raw_input("Please press enter to exit.")

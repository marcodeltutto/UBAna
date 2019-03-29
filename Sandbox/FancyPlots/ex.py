import sys, os, math
import ROOT
from ROOT import *
# gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")


h = TH1D('h', 'h', 10, -2, 2)
h.FillRandom('gaus', 100)



# c_xsec_split = TCanvas("c_xsec_split", "multipads", 0, 0, 2800, 2000)
c_xsec_split = TCanvas()
# c_xsec_split.Divide(3, 3, 0.01, 0.01)

x_bins = 9
costhetamu_ranges = ["-1.00 #leq cos(#theta_{#mu}^{reco}) < -0.50", "-0.50 #leq cos(#theta_{#mu}^{reco}) < 0.00", "0.00 #leq cos(#theta_{#mu}^{reco}) < 0.27",  "0.27 #leq cos(#theta_{#mu}^{reco}) < 0.45", "0.45 #leq cos(#theta_{#mu}^{reco}) < 0.62", "0.62 #leq cos(#theta_{#mu}^{reco}) < 0.76", "0.76 #leq cos(#theta_{#mu}^{reco}) < 0.86", "0.86 #leq cos(#theta_{#mu}^{reco}) < 0.94", "0.94 #leq cos(#theta_{#mu}^{reco}) #leq 1.00"]

labels = []

# for i in xrange(1, x_bins+1):
for i in xrange(1, 2):
  # c_xsec_split.cd(i)
  gPad.SetBottomMargin(0.16);
  gPad.SetLeftMargin(0.18);
  gPad.SetRightMargin(0.03);
  gPad.SetTopMargin(0.06);

  h.SetTitle("")
  h.GetXaxis().SetTitle("p_{#mu}^{reco} (GeV)")
  h.GetYaxis().SetTitle("#frac{d^{2}#sigma}{dp_{#mu}^{reco}dcos(#theta_{#mu}^{reco})} #(){10^{-38} #frac{cm^{2}}{GeV n}}")
  h.GetXaxis().CenterTitle()
  h.GetYaxis().CenterTitle()
  h.GetXaxis().SetTitleOffset(1)
  h.GetXaxis().SetTitleSize(0.07)
  h.GetXaxis().SetLabelSize(0.06)
  h.GetYaxis().SetTitleOffset(1.0)
  h.GetYaxis().SetTitleSize(0.07)
  h.GetYaxis().SetLabelSize(0.06)

  # gStyle.SetTitleFontSize(0.07)
  # gStyle.SetTitleStyle(0)
  # gStyle.SetEndErrorSize(5)

  # xsec_tune1[i-1].SetLineColor(ROOT.kGreen+2)
  # xsec_tune1[i-1].SetFillColor(0)
  # xsec_tune3[i-1].SetLineColor(ROOT.kBlue+1)
  # xsec_tune3[i-1].SetFillColor(0)

  h.SetMarkerStyle(20)
  h.SetMarkerSize(0.5)
  h.SetLineWidth(2)


  # # genie_xsec[i-1].Draw("E2");
  # # genie_xsec_main =  genie_xsec[i-1].Clone("genie_xsec_main");
  # # genie_xsec_main.SetLineColor(kGreen+2);
  # # genie_xsec_main.SetFillColor(0);
  # # genie_xsec_main.Draw("histo same");

  h.Draw("E1 X0 same")



  costheta_label = TLatex(0.9500818,0.8657913, costhetamu_ranges[i-1]);
  costheta_label.SetNDC();
  # costheta_label.SetTextColor(kGray+2);
  costheta_label.SetTextSize(0.07);
  costheta_label.SetTextAlign(32);
  costheta_label.SetLineWidth(2);
  costheta_label.SetTextFont(42);
  costheta_label.Draw();
  labels.append(costheta_label)

  if i == 1:
    leg = TLegend(0.3987489,0.3993355,0.6900191,0.6037953);
    leg.SetBorderSize(0);
    leg.SetTextSize(0.06389368);
    leg.SetLineColor(1);
    leg.SetLineStyle(1);
    leg.SetLineWidth(1);
    leg.SetFillColor(0);
    leg.SetFillStyle(0);
    leg.AddEntry(h, "Histo")
    # leg.AddEntry(xsec_tune3[0], "GENIE Alternative")
    # leg.AddEntry(xsec_data[0],  "MicroBooNE (Stat. #oplus Syst.)", "ep")
    leg.Draw()

    ub_label = TLatex(0.9,0.69, "MicroBooNE #bf{1.6e20 POT}");
    ub_label.SetNDC();
    ub_label.SetTextColor(kGray+2);
    ub_label.SetTextSize(0.07);
    ub_label.SetTextAlign(32);
    ub_label.SetLineWidth(2);
    ub_label.SetTextFont(62);
    ub_label.Draw();


c_xsec_split.SaveAs('test.pdf')
c_xsec_split.SaveAs('test.png')

raw_input("Please press enter to exit.")

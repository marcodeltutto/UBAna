import sys, os, math
from array import array
import ROOT
from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

f_flux = ROOT.TFile("../../Flux/MCC8_FluxHistograms_Uncertainties.root")
flux_h = f_flux.Get("numu/numu_CV_AV_TPC")

f_xsec = ROOT.TFile("../../Flux/xsec_graphs.root")
xsec_h = f_xsec.Get("nu_mu_Ar40/tot_cc")
for i in xrange(0, xsec_h.GetN()):
  xsec_h.GetY()[i] *= 1/40.

f_xsec_tune3 = ROOT.TFile("../../Flux/xsec_graphs_tune3.root")
xsec_h_tune3 = f_xsec_tune3.Get("nu_mu_Ar40/tot_cc")
for i in xrange(0, xsec_h_tune3.GetN()):
  xsec_h_tune3.GetY()[i] *= 1/40.

proxy = TH1D('proxy', '', 1, -10, -9)
proxy.SetBinContent(1, -999)

c = TCanvas()

flux_h.Scale(100./flux_h.Integral())
# flux_h.SetFillColor(50)
flux_h.SetFillColorAlpha(50,0.5);
flux_h.SetLineColor(50)
flux_h.GetXaxis().SetTitle('Neutrino Energy [GeV]')
flux_h.GetYaxis().SetTitle('#sigma(E_{#nu}) [10^{-38} cm^{2}/n]')
flux_h.GetXaxis().CenterTitle(True)
flux_h.GetYaxis().CenterTitle(True)
flux_h.GetYaxis().SetTitleOffset(0.8)
flux_h.Draw('histo')
flux_h.GetXaxis().SetRangeUser(0, 3.)

xsec_h.SetLineColor(30)
xsec_h.SetLineWidth(4)
xsec_h.Draw('L')

xsec_h_tune3.SetLineColor(9)
xsec_h_tune3.SetLineWidth(4)
xsec_h_tune3.Draw('L')

proxy.Draw('E1 X0 same')

ub_label = TLatex(0.7722063,0.8505263, "MicroBooNE #bf{1.6e20 POT}");
ub_label.SetNDC();
ub_label.SetTextColor(kGray+2);
ub_label.SetTextSize(0.05);
ub_label.SetTextAlign(32);
ub_label.SetLineWidth(2);
ub_label.SetTextFont(62);
ub_label.Draw();

leg = TLegend(0.3896848,0.6063158,0.8825215,0.8105263);
leg.SetBorderSize(0);
leg.SetTextSize(0.04631579);
leg.SetLineColor(1);
leg.SetLineStyle(1);
leg.SetLineWidth(1);
leg.SetFillColor(0);
leg.SetFillStyle(0);
leg.AddEntry(flux_h, "Flux (arbitrary)")
leg.AddEntry(xsec_h, "GENIE Default + Emp. MEC")
leg.AddEntry(xsec_h_tune3, "GENIE Alternative")
leg.AddEntry(proxy, "Measured (Stat. #oplus Syst. Unc.)", 'ep')
leg.Draw()


c.SaveAs('flux_xsec_plot.pdf')




raw_input("Please press enter to exit.")

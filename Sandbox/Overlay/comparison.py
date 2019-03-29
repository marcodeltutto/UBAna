import ROOT
import array
from ROOT import *
import sys, os, math

gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

# Tune 3
f_cv = ROOT.TFile("xsec_file_cv.root")
xsec_cv = f_cv.Get("xsec_poly_muangle_mumom_cv")
frac_covariance_data_muangle_mumom_h = f_cv.Get("frac_covariance_matrix_poly_muangle_mumom_cv") # this is frac, next version will be have correct name

# xsec_mumom.Scale( 1.0 / xsec_mumom.Integral("width") )

# Tune 3 - No RPA
f_cosmicscaled = ROOT.TFile("xsec_file_cv_cosmicscaled_overlay_test.root")
xsec_cosmicscaled = f_cosmicscaled.Get("xsec_poly_muangle_mumom_cv_cosmicscaled_overlay_test")



costhetamu_ranges = ["-1.00 #leq cos(#theta_{#mu}^{reco}) < -0.50", "-0.50 #leq cos(#theta_{#mu}^{reco}) < 0.00", "0.00 #leq cos(#theta_{#mu}^{reco}) < 0.27",  "0.27 #leq cos(#theta_{#mu}^{reco}) < 0.45", "0.45 #leq cos(#theta_{#mu}^{reco}) < 0.62", "0.62 #leq cos(#theta_{#mu}^{reco}) < 0.76", "0.76 #leq cos(#theta_{#mu}^{reco}) < 0.86", "0.86 #leq cos(#theta_{#mu}^{reco}) < 0.94", "0.94 #leq cos(#theta_{#mu}^{reco}) < 1.00"]

labels = []

x_bins = xsec_cv.GetNBinsX()
horizontal_division = 2
vertical_division = math.floor(x_bins / 2.)
if (x_bins / 2. != math.floor(x_bins / 2.)): 
  vertical_division = vertical_division + 1

# c_xsec_split = TCanvas("c_xsec_split", "multipads", 0, 45, 1006, 1150)
# c_xsec_split.Divide(2, 5, 0.02, 0.01)

# c_xsec_split = TCanvas("c_xsec_split", "multipads", 0, 0, 1144,746)
# c_xsec_split.Divide(3, 3, 0.01, 0.01)

c_xsec_split = TCanvas()

data_xsec = []
data_xsec_c = []

uncertainty_data = []

bin_numbers = ROOT.vector('int')()
for i in xrange(1, x_bins+1):
  data_xsec.append(xsec_cv.ProjectionY("data_bs" + str(i), i, bin_numbers))
  data_xsec_c.append(xsec_cosmicscaled.ProjectionY("genie_bs" + str(i), i, bin_numbers))

  h_unc = data_xsec[i-1].Clone("h_unc" + str(i))
  for j in xrange(0, bin_numbers.size()): 
    # print 'bin number is', bin_numbers[j], '  - covariance is', math.sqrt(frac_covariance_data_muangle_mumom_h.GetBinContent(bin_numbers[j], bin_numbers[j]))
    h_unc.SetBinError(j+1, h_unc.GetBinContent(j+1) * math.sqrt(frac_covariance_data_muangle_mumom_h.GetBinContent(bin_numbers[j], bin_numbers[j])))
  uncertainty_data.append(h_unc)
  
for i in xrange(1, x_bins+1):
  # c_xsec_split.cd(i)
  # gPad.SetBottomMargin(0.15);
  # gPad.SetLeftMargin(0.18);
  # gPad.SetRightMargin(0.14);
  # gPad.SetTopMargin(0.13);

  gPad.SetBottomMargin(0.16);
  gPad.SetLeftMargin(0.18);
  gPad.SetRightMargin(0.03);
  gPad.SetTopMargin(0.06);

  # genie_xsec[i-1].SetTitle(costhetamu_ranges[i-1])
  data_xsec_c[i-1].GetXaxis().SetTitle("p_{#mu}^{reco} [GeV]")
  data_xsec_c[i-1].GetYaxis().SetTitle("#frac{d^{2}#sigma}{dp_{#mu}^{reco}dcos(#theta_{#mu}^{reco})} [10^{-38} #frac{cm^{2}}{GeV n}]")
  data_xsec_c[i-1].GetXaxis().CenterTitle()
  data_xsec_c[i-1].GetYaxis().CenterTitle()
  data_xsec_c[i-1].GetXaxis().SetTitleOffset(0.92)
  data_xsec_c[i-1].GetXaxis().SetTitleSize(0.07)
  data_xsec_c[i-1].GetXaxis().SetLabelSize(0.06)
  data_xsec_c[i-1].GetYaxis().SetTitleOffset(1.0)
  data_xsec_c[i-1].GetYaxis().SetTitleSize(0.06)
  data_xsec_c[i-1].GetYaxis().SetLabelSize(0.06)

  # if i == 1:
  #   genie_xsec[i-1].SetMinimum(-0.01)
  #   genie_xsec[i-1].SetMaximum(0.45)
  # if i == 2:
  #   genie_xsec[i-1].SetMinimum(-0.03)
  #   genie_xsec[i-1].SetMaximum(0.45)
  # if i == 3:
  #   genie_xsec[i-1].SetMinimum(-0.15)
  #   # xsec_tune1[i-1].SetMaximum(0.5)
  # if i == 6:
  #   genie_xsec[i-1].SetMinimum(-0.05)
  #   xsec_tune1[i-1].SetMaximum(0.5)
  # if i == 7:
  #   genie_xsec[i-1].SetMinimum(0)
  #   xsec_tune1[i-1].SetMaximum(2.5)
  # if i == 8:
  #   genie_xsec[i-1].SetMinimum(0)
  #   xsec_tune1[i-1].SetMaximum(3)
  # if i == 9:
  #   genie_xsec[i-1].SetMinimum(0)
  #   xsec_tune1[i-1].SetMaximum(3)

  gStyle.SetTitleFontSize(0.07)
  gStyle.SetTitleStyle(0)

  data_xsec[i-1].SetLineColor(ROOT.kGreen+2)
  data_xsec[i-1].SetFillColor(0)
  data_xsec_c[i-1].SetLineColor(ROOT.kBlue+1)
  data_xsec_c[i-1].SetFillColor(0)

  uncertainty_data[i-1].SetMarkerStyle(20);
  uncertainty_data[i-1].SetMarkerSize(0.1);
  uncertainty_data[i-1].SetLineColor(ROOT.kGreen+2);
  
  # genie_xsec[i-1].Draw("E2");
  # genie_xsec_main =  genie_xsec[i-1].Clone("genie_xsec_main");
  # genie_xsec_main.SetLineColor(kGreen+2);
  # genie_xsec_main.SetFillColor(0);
  # genie_xsec_main.Draw("histo same");

  data_xsec_c[i-1].Draw("histo ")
  data_xsec[i-1].Draw("histo same")
  
  uncertainty_data[i-1].Draw("E1 X0 same")

  the_min = min(data_xsec[i-1].GetMinimum(), data_xsec_c[i-1].GetMinimum());
  the_max = max(data_xsec[i-1].GetMaximum(), data_xsec_c[i-1].GetMaximum());

  data_xsec_c[i-1].SetMinimum(the_min - abs(the_min) * 0.4);
  data_xsec_c[i-1].SetMaximum(the_max * 1.5);

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
    leg = TLegend(0.3705146,0.3828902,0.733819,0.6617582);
    leg.SetBorderSize(0);
    leg.SetTextSize(0.06389368);
    leg.SetLineColor(1);
    leg.SetLineStyle(1);
    leg.SetLineWidth(1);
    leg.SetFillColor(0);
    leg.SetFillStyle(0);
    leg.AddEntry(data_xsec[0], "Data Cross Section (Nominal)")
    leg.AddEntry(data_xsec_c[0], "Data Cross Section with Corsika Scaled to Overlay")
    leg.Draw()    

    ub_label = TLatex(0.92,0.71, "MicroBooNE #bf{1.6e20 POT}");
    ub_label.SetNDC();
    ub_label.SetTextColor(kGray+2);
    ub_label.SetTextSize(0.07);
    ub_label.SetTextAlign(32);
    ub_label.SetLineWidth(2);
    ub_label.SetTextFont(62);
    ub_label.Draw();

  c_xsec_split.Modified();
  c_xsec_split.cd();
  c_xsec_split.Draw()
  c_xsec_split.SaveAs('double_diff_' + str(i) +'.pdf')

raw_input("Please press enter to exit. ")

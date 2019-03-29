import sys, os, math
import ROOT
from ROOT import *
# gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

def smear_double(xsec_true_h, smearing_m):
  # print 'nrows', smearing_m.GetNrows()
  # print 'ncols', smearing_m.GetNcols()
  # print 'NbinsX', xsec_true_h.GetNbinsX()
  xsec_true_v = TMatrix()
  xsec_true_v.Clear()
  xsec_true_v.ResizeTo(xsec_true_h.GetNumberOfBins(), 1)

  for i in xrange(1, xsec_true_h.GetNumberOfBins()+1):
    xsec_true_h.SetBinContent(i, xsec_true_h.GetBinContent(i) * xsec_true_h.GetBinWidth(i))

  for i in xrange(1, xsec_true_h.GetNumberOfBins()+1):
    xsec_true_v[i-1][0] = xsec_true_h.GetBinContent(i);

  xsec_reco_v  = TMatrix()
  xsec_reco_v.Clear()
  xsec_reco_v.ResizeTo(xsec_true_h.GetNumberOfBins(), 1)


  for i in xrange(0, xsec_true_h.GetNumberOfBins()):
    xsec_reco_v[i][0] = 0
    for j in xrange(0, xsec_true_h.GetNumberOfBins()):
      # print 'i =', i ,', j =', j, ' => S =', smearing_m[i][j]
      xsec_reco_v[i][0] += smearing_m[i][j] * xsec_true_v[j][0]


  xsec_reco_h = xsec_true_h.Clone("xsec_reco_h")
  for i in xrange(1, xsec_true_h.GetNumberOfBins()+1):
    xsec_reco_h.SetBinContent(i, xsec_reco_v[i-1][0])
    xsec_reco_h.SetBinError(i, xsec_true_h.GetBinError(i) * xsec_true_h.GetBinWidth(i)) # FIXME just copy stat uncertainties for now

  # Restore bin widths
  xsec_true_h.Scale(1.0, "width");
  xsec_reco_h.Scale(1.0, "width");

  return xsec_reco_h

f_ubana = ROOT.TFile("./xsec_file_cv.root")

xsec_data = []
xsec_data.append(f_ubana.Get("xsec_poly_muangle_mumom_cv_bin_0"))
xsec_data.append(f_ubana.Get("xsec_poly_muangle_mumom_cv_bin_1"))
xsec_data.append(f_ubana.Get("xsec_poly_muangle_mumom_cv_bin_2"))
xsec_data.append(f_ubana.Get("xsec_poly_muangle_mumom_cv_bin_3"))
xsec_data.append(f_ubana.Get("xsec_poly_muangle_mumom_cv_bin_4"))
xsec_data.append(f_ubana.Get("xsec_poly_muangle_mumom_cv_bin_5"))
xsec_data.append(f_ubana.Get("xsec_poly_muangle_mumom_cv_bin_6"))
xsec_data.append(f_ubana.Get("xsec_poly_muangle_mumom_cv_bin_7"))
xsec_data.append(f_ubana.Get("xsec_poly_muangle_mumom_cv_bin_8"))

xsec_data_unc = []
xsec_data_unc.append(f_ubana.Get("xsec_unc_poly_muangle_mumom_cv_bin_0"))
xsec_data_unc.append(f_ubana.Get("xsec_unc_poly_muangle_mumom_cv_bin_1"))
xsec_data_unc.append(f_ubana.Get("xsec_unc_poly_muangle_mumom_cv_bin_2"))
xsec_data_unc.append(f_ubana.Get("xsec_unc_poly_muangle_mumom_cv_bin_3"))
xsec_data_unc.append(f_ubana.Get("xsec_unc_poly_muangle_mumom_cv_bin_4"))
xsec_data_unc.append(f_ubana.Get("xsec_unc_poly_muangle_mumom_cv_bin_5"))
xsec_data_unc.append(f_ubana.Get("xsec_unc_poly_muangle_mumom_cv_bin_6"))
xsec_data_unc.append(f_ubana.Get("xsec_unc_poly_muangle_mumom_cv_bin_7"))
xsec_data_unc.append(f_ubana.Get("xsec_unc_poly_muangle_mumom_cv_bin_8"))

xsec_tune1 = []
xsec_tune1.append(f_ubana.Get("xsec_mc_poly_muangle_mumom_cv_bin_0"))
xsec_tune1.append(f_ubana.Get("xsec_mc_poly_muangle_mumom_cv_bin_1"))
xsec_tune1.append(f_ubana.Get("xsec_mc_poly_muangle_mumom_cv_bin_2"))
xsec_tune1.append(f_ubana.Get("xsec_mc_poly_muangle_mumom_cv_bin_3"))
xsec_tune1.append(f_ubana.Get("xsec_mc_poly_muangle_mumom_cv_bin_4"))
xsec_tune1.append(f_ubana.Get("xsec_mc_poly_muangle_mumom_cv_bin_5"))
xsec_tune1.append(f_ubana.Get("xsec_mc_poly_muangle_mumom_cv_bin_6"))
xsec_tune1.append(f_ubana.Get("xsec_mc_poly_muangle_mumom_cv_bin_7"))
xsec_tune1.append(f_ubana.Get("xsec_mc_poly_muangle_mumom_cv_bin_8"))

xsec_tune3 = []
xsec_tune3.append(f_ubana.Get("xsec_mc_alt_poly_muangle_mumom_cv_bin_0"))
xsec_tune3.append(f_ubana.Get("xsec_mc_alt_poly_muangle_mumom_cv_bin_1"))
xsec_tune3.append(f_ubana.Get("xsec_mc_alt_poly_muangle_mumom_cv_bin_2"))
xsec_tune3.append(f_ubana.Get("xsec_mc_alt_poly_muangle_mumom_cv_bin_3"))
xsec_tune3.append(f_ubana.Get("xsec_mc_alt_poly_muangle_mumom_cv_bin_4"))
xsec_tune3.append(f_ubana.Get("xsec_mc_alt_poly_muangle_mumom_cv_bin_5"))
xsec_tune3.append(f_ubana.Get("xsec_mc_alt_poly_muangle_mumom_cv_bin_6"))
xsec_tune3.append(f_ubana.Get("xsec_mc_alt_poly_muangle_mumom_cv_bin_7"))
xsec_tune3.append(f_ubana.Get("xsec_mc_alt_poly_muangle_mumom_cv_bin_8"))

muangle_mumom_smearing_m = f_ubana.Get("smearing_matrix_muangle_mumom_poly_cv");

# Get GENIE Tune 3 bug fixed true xsec
f_genie_tune3f = ROOT.TFile("./genie_histograms_tune3_bugfix.root")
xsec_muangle_mumom_true_tune3f_h = f_genie_tune3f.Get("xsec_muangle_mumom_true_genie_h")

xsec_muangle_mumom_reco_tune3f_h = smear_double(xsec_muangle_mumom_true_tune3f_h, muangle_mumom_smearing_m)

tune3f_xsec = []
bin_numbers = ROOT.vector('int')()
for i in xrange(1, xsec_muangle_mumom_true_tune3f_h.GetNBinsX()+1):
  tune3f_xsec.append(xsec_muangle_mumom_reco_tune3f_h.ProjectionY("tune3f_bs" + str(i), i, bin_numbers))






# c_xsec_split = TCanvas("c_xsec_split", "multipads", 0, 0, 2800, 2000)
# c_xsec_split = TCanvas("c_xsec_split", "multipads", 0, 0, 1144,746)
c_xsec_split = TCanvas()
# c_xsec_split.Divide(3, 3, 0.01, 0.01)

x_bins = 9
costhetamu_ranges = ["-1.00 #leq cos(#theta_{#mu}^{reco}) < -0.50", "-0.50 #leq cos(#theta_{#mu}^{reco}) < 0.00", "0.00 #leq cos(#theta_{#mu}^{reco}) < 0.27",  "0.27 #leq cos(#theta_{#mu}^{reco}) < 0.45", "0.45 #leq cos(#theta_{#mu}^{reco}) < 0.62", "0.62 #leq cos(#theta_{#mu}^{reco}) < 0.76", "0.76 #leq cos(#theta_{#mu}^{reco}) < 0.86", "0.86 #leq cos(#theta_{#mu}^{reco}) < 0.94", "0.94 #leq cos(#theta_{#mu}^{reco}) #leq 1.00"]

labels = []

for i in xrange(1, x_bins+1):
# for i in xrange(1, 2):
  # c_xsec_split.cd(i)
  gPad.SetBottomMargin(0.16);
  gPad.SetLeftMargin(0.18);
  gPad.SetRightMargin(0.03);
  gPad.SetTopMargin(0.06);

  if i == 1:
    xsec_tune1[i-1].SetMinimum(-0.01)
    xsec_tune1[i-1].SetMaximum(0.45)
  if i == 2:
    xsec_tune1[i-1].SetMinimum(-0.03)
    xsec_tune1[i-1].SetMaximum(0.45)
  if i == 3:
    xsec_tune1[i-1].SetMinimum(-0.15)
    # xsec_tune1[i-1].SetMaximum(0.5)
  if i == 6:
    xsec_tune1[i-1].SetMinimum(-0.05)
    # xsec_tune1[i-1].SetMaximum(0.5)
  if i == 9:
    xsec_tune1[i-1].SetMinimum(0)
    # xsec_tune1[i-1].SetMaximum(0.5)

  xsec_tune1[i-1].SetTitle("")
  xsec_tune1[i-1].GetXaxis().SetTitle("p_{#mu}^{reco} (GeV)")
  xsec_tune1[i-1].GetYaxis().SetTitle("#frac{d^{2}#sigma}{dp_{#mu}^{reco}dcos(#theta_{#mu}^{reco})} [10^{-38} #frac{cm^{2}}{GeV n}]")
  xsec_tune1[i-1].GetXaxis().CenterTitle()
  xsec_tune1[i-1].GetYaxis().CenterTitle()
  xsec_tune1[i-1].GetXaxis().SetTitleOffset(1)
  xsec_tune1[i-1].GetXaxis().SetTitleSize(0.07)
  xsec_tune1[i-1].GetXaxis().SetLabelSize(0.06)
  xsec_tune1[i-1].GetYaxis().SetTitleOffset(1.0)
  xsec_tune1[i-1].GetYaxis().SetTitleSize(0.07)
  xsec_tune1[i-1].GetYaxis().SetLabelSize(0.06)

  gStyle.SetTitleFontSize(0.07)
  gStyle.SetTitleStyle(0)
  gStyle.SetEndErrorSize(5)

  xsec_tune1[i-1].SetLineColor(ROOT.kGreen+2)
  xsec_tune1[i-1].SetFillColor(0)
  xsec_tune3[i-1].SetLineColor(ROOT.kBlue+1)
  xsec_tune3[i-1].SetFillColor(0)
  xsec_tune3[i-1].SetLineStyle(9)

  tune3f_xsec[i-1].SetLineColor(ROOT.kGreen+2)
  tune3f_xsec[i-1].SetFillColor(0)
  tune3f_xsec[i-1].SetLineColor(ROOT.kBlue+1)
  tune3f_xsec[i-1].SetFillColor(0)
  tune3f_xsec[i-1].SetLineStyle(9)
  
  xsec_data[i-1].SetMarkerStyle(20)
  # xsec_data[i-1].SetMarkerSize(1.3)
  xsec_data[i-1].SetMarkerSize(1.2)
  xsec_data[i-1].SetLineWidth(2)
  xsec_data_unc[i-1].SetMarkerStyle(20)
  xsec_data_unc[i-1].SetMarkerSize(0.1)
  xsec_data_unc[i-1].SetLineWidth(2)



  xsec_tune1[i-1].Draw("histo")
  # xsec_tune3[i-1].Draw("histo same")
  tune3f_xsec[i-1].Draw("histo same")

  xsec_data[i-1].Draw("E1 X0 same")
  xsec_data_unc[i-1].Draw("E1 X0 same")

#   the_min = min(xsec_tune1[i-1].GetMinimum(), xsec_data[i-1].GetMinimum())
#   the_max = max(xsec_tune1[i-1].GetMaximum(), xsec_data[i-1].GetMaximum())

#   xsec_tune1[i-1].SetMinimum(the_min - abs(the_min) * 0.4);
#   xsec_tune1[i-1].SetMaximum(the_max * 1.5);


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
    leg.AddEntry(xsec_tune1[0], "GENIE Default + Emp. MEC")
    leg.AddEntry(xsec_tune3[0], "GENIE Alternative")
    leg.AddEntry(xsec_data[0],  "MicroBooNE (Stat. #oplus Syst.)", "ep")
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
  c_xsec_split.SaveAs('double_diff_prl' + str(i) +'.pdf')


c_xsec_split.Modified();
c_xsec_split.cd();


c_xsec_split.Draw()
# ROOT.disableJSVis()
c_xsec_split.SaveAs('double_diff_prl.pdf')
c_xsec_split.SaveAs('double_diff_prl.png')

raw_input("Please press enter to exit.")

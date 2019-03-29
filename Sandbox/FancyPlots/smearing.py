import ROOT
import array
from ROOT import *
import sys, os, math

def smear(xsec_true_h, smearing_m):
  print 'nrows', smearing_m.GetNrows()
  print 'ncols', smearing_m.GetNcols()
  print 'NbinsX', xsec_true_h.GetNbinsX()
  xsec_true_v = TMatrix()
  xsec_true_v.Clear()
  xsec_true_v.ResizeTo(xsec_true_h.GetNbinsX(), 1)

  # Remove bin widths normalisation before smearing
  for i in xrange(1, xsec_true_h.GetNbinsX()+1):
    xsec_true_h.SetBinContent(i, xsec_true_h.GetBinContent(i) * xsec_true_h.GetBinWidth(i))

  # Construct a vector (TMatrix) with the true cross section values
  for i in xrange(1, xsec_true_h.GetNbinsX()+1):
    xsec_true_v[i-1][0] = xsec_true_h.GetBinContent(i);

  # Define a vector (TMatrix) that will store the reco cross section values
  xsec_reco_v = TMatrix()
  xsec_reco_v.Clear()
  xsec_reco_v.ResizeTo(xsec_true_h.GetNbinsX(), 1)

  # Fill the vector (TMatrix) with the reco cross section values
  for i in xrange(0, xsec_true_h.GetNbinsX()):
    xsec_reco_v[i][0] = 0
    for j in xrange(0, xsec_true_h.GetNbinsX()):
      # print 'i =', i ,', j =', j, ' => S =', smearing_m[i][j]
      xsec_reco_v[i][0] += smearing_m[i][j] * xsec_true_v[j][0] 

  # Transform the vector in histogram
  xsec_reco_h = xsec_true_h.Clone("xsec_reco_h")
  for i in xrange(1, xsec_true_h.GetNbinsX()+1):
    xsec_reco_h.SetBinContent(i, xsec_reco_v[i-1][0])

  # Restore bin widths
  for i in xrange(1, xsec_reco_h.GetNbinsX()+1):
    xsec_true_h.SetBinContent(i, xsec_true_h.GetBinContent(i) / xsec_true_h.GetBinWidth(i))
    xsec_reco_h.SetBinContent(i, xsec_reco_h.GetBinContent(i) / xsec_reco_h.GetBinWidth(i))

  return xsec_reco_h









# Get data xsec, smearing matrices and frac cov matrices
f_ubana = ROOT.TFile("./xsec_file_cv.root")
xsec_data_mumom_h = f_ubana.Get("xsec_mumom_cv")
xsec_data_muangle_h = f_ubana.Get("xsec_muangle_cv")
mumom_smearing_m = f_ubana.Get("smearing_matrix_mumom_cv")
muangle_smearing_m = f_ubana.Get("smearing_matrix_muangle_cv")
frac_covariance_data_mumom_h = f_ubana.Get("frac_covariance_matrix_mumom_cv")
frac_covariance_data_muangle_h = f_ubana.Get("frac_covariance_matrix_muangle_cv")

# Get GiBUU true xsec
f_gibuu = ROOT.TFile("../GiBUU/gibuu_histograms.root")
xsec_mumom_true_gibuu_h = f_gibuu.Get("xsec_mumom_true_gibuu_h")
xsec_muangle_true_gibuu_h = f_gibuu.Get("xsec_muangle_true_gibuu_h")

# Smear GiBUU xsec
xsec_mumom_reco_gibuu_h = smear(xsec_mumom_true_gibuu_h, mumom_smearing_m)
xsec_muangle_reco_gibuu_h = smear(xsec_muangle_true_gibuu_h, muangle_smearing_m)

# Construct syst histo mumom
uncertanties_mumom_h = xsec_data_mumom_h.Clone("uncertanties_mumom_h")
for i in xrange(0, uncertanties_mumom_h.GetNbinsX()):
  uncertanties_mumom_h.SetBinError(i+1, uncertanties_mumom_h.GetBinContent(i+1) * math.sqrt(frac_covariance_data_mumom_h.GetBinContent(i+1, i+1)))

# Construct syst histo muangle
uncertanties_muangle_h = xsec_data_muangle_h.Clone("uncertanties_muangle_h")
for i in xrange(0, uncertanties_muangle_h.GetNbinsX()):
  uncertanties_muangle_h.SetBinError(i+1, uncertanties_muangle_h.GetBinContent(i+1) * math.sqrt(frac_covariance_data_muangle_h.GetBinContent(i+1, i+1)))



# Plot
c2 = TCanvas()
c2.SetBottomMargin(0.12)
c2.SetLeftMargin(0.12)
xsec_mumom_reco_gibuu_h.SetLineColor(8)
xsec_mumom_reco_gibuu_h.SetLineWidth(2)
xsec_mumom_reco_gibuu_h.GetXaxis().SetTitle("p^{reco}_{#mu} [GeV]")
xsec_mumom_reco_gibuu_h.GetYaxis().SetTitle("d#sigma/dp^{reco}_{#mu} [10^{-38} cm^{2}/GeV]")
xsec_mumom_reco_gibuu_h.Draw("histo same")
xsec_data_mumom_h.SetMarkerStyle(kFullCircle)
xsec_data_mumom_h.SetMarkerSize(0.6)
xsec_data_mumom_h.Draw("E1 X0 same")
uncertanties_mumom_h.SetMarkerStyle(kFullCircle)
uncertanties_mumom_h.SetMarkerSize(0.2)
uncertanties_mumom_h.Draw("E1 X0 same")

leg_mumom = TLegend(0.52149,0.5263158,0.7320917,0.7368421)
leg_mumom.SetBorderSize(0);
leg_mumom.SetTextSize(0.04631579);
leg_mumom.SetLineColor(1);
leg_mumom.SetLineStyle(1);
leg_mumom.SetLineWidth(1);
leg_mumom.SetFillColor(0);
leg_mumom.SetFillStyle(0);
leg_mumom.AddEntry(xsec_mumom_reco_gibuu_h, "GiBUU"      )
leg_mumom.AddEntry(xsec_data_mumom_h,       "Data (Stat. #oplus Syst. Unc.)", "ep")
leg_mumom.Draw()

ub_label_mumom = TLatex(0.525788,0.7621053,"MicroBooNE #bf{Preliminary}");
ub_label_mumom.SetNDC();
ub_label_mumom.SetTextColor(kGray+2);
ub_label_mumom.SetTextSize(0.04631579);
ub_label_mumom.SetLineWidth(2);
ub_label_mumom.SetTextFont(62);
ub_label_mumom.Draw();
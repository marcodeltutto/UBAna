import sys, os
import math

from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")





file_1 = TFile("covariance_detector_firstround.root");
covariance_mumom_1 = file_1.Get("covariance_matrix_detector_mumom")
covariance_muangle_1 = file_1.Get("covariance_matrix_detector_muangle")
covariance_muangle_mumom_1 = file_1.Get("covariance_matrix_detector_muangle_mumom")


file_2 = TFile("covariance_detector_secondround.root");
covariance_mumom_2 = file_2.Get("covariance_matrix_detector_mumom")
covariance_muangle_2 = file_2.Get("covariance_matrix_detector_muangle")
covariance_muangle_mumom_2 = file_2.Get("covariance_matrix_detector_muangle_mumom")

n_mumom_bins = covariance_mumom_1.GetNbinsX()
n_muangle_bins = covariance_muangle_1.GetNbinsX()

n_mumom_bins_double = covariance_muangle_mumom_1.GetNbinsY()
n_muangle_bins_double = covariance_muangle_mumom_1.GetNbinsX()
n_total_bins_double = n_muangle_bins_double * n_mumom_bins_double

cov_matrix_mumom = TH2D("cov_matrix_mumom", "", n_mumom_bins, 0, n_mumom_bins, n_mumom_bins, 0, n_mumom_bins)
cov_matrix_mumom_frac = TH2D("cov_matrix_mumom_frac", "", n_mumom_bins, 0, n_mumom_bins, n_mumom_bins, 0, n_mumom_bins)
cov_matrix_muangle = TH2D("cov_matrix_muangle", "", n_muangle_bins, 0, n_muangle_bins, n_muangle_bins, 0, n_muangle_bins)
cov_matrix_muangle_frac = TH2D("cov_matrix_muangle_frac", "", n_muangle_bins, 0, n_muangle_bins, n_muangle_bins, 0, n_muangle_bins)
cov_matrix_muangle_mumom = TH2D("cov_matrix_muangle_mumom", "", n_total_bins_double, 0, n_total_bins_double, n_total_bins_double, 0, n_total_bins_double)
cov_matrix_muangle_mumom_frac = TH2D("cov_matrix_muangle_mumom_frac", "", n_total_bins_double, 0, n_total_bins_double, n_total_bins_double, 0, n_total_bins_double)


for i in xrange(0, n_mumom_bins):
	for j in xrange(0, n_mumom_bins):
		cov_matrix_mumom.SetBinContent(i+1, j+1, covariance_mumom_1.GetBinContent(i+1, j+1) + covariance_mumom_2.GetBinContent(i+1, j+1))

for i in xrange(0, n_muangle_bins):
	for j in xrange(0, n_muangle_bins):
		cov_matrix_muangle.SetBinContent(i+1, j+1, covariance_muangle_1.GetBinContent(i+1, j+1) + covariance_muangle_2.GetBinContent(i+1, j+1))

for i in xrange(0, n_muangle_bins_double):
  for j in xrange(0, n_mumom_bins_double):
    for m in xrange(0, n_muangle_bins_double):
      for n in xrange(0, n_mumom_bins_double):
        a = j + i * n_mumom_bins_double + 1;
        b = n + m * n_mumom_bins_double + 1;
        cov_matrix_muangle_mumom.SetBinContent(a, b, covariance_muangle_mumom_1.GetBinContent(a, b) + covariance_muangle_mumom_2.GetBinContent(a, b))


cov_file = TFile("covariance_detector.root", "RECREATE");
cov_file.cd();
cov_matrix_mumom.Write("covariance_matrix_detector_mumom");
cov_matrix_muangle.Write("covariance_matrix_detector_muangle");
cov_matrix_muangle_mumom.Write("covariance_matrix_detector_muangle_mumom");
cov_file.Close();

# c_mumom = TCanvas()
# cov_matrix_mumom_frac.SetMarkerColor(kWhite);
# cov_matrix_mumom_frac.SetMarkerSize(1.6);
# cov_matrix_mumom_frac.GetXaxis().SetTitle("Bin i");
# cov_matrix_mumom_frac.GetYaxis().SetTitle("Bin j");
# cov_matrix_mumom_frac.GetXaxis().CenterTitle();
# cov_matrix_mumom_frac.GetYaxis().CenterTitle();
# cov_matrix_mumom_frac.Draw("colz TEXT")

# c_muangle = TCanvas()
# cov_matrix_muangle_frac.SetMarkerColor(kWhite);
# cov_matrix_muangle_frac.SetMarkerSize(1.6);
# cov_matrix_muangle_frac.GetXaxis().SetTitle("Bin i");
# cov_matrix_muangle_frac.GetYaxis().SetTitle("Bin j");
# cov_matrix_muangle_frac.GetXaxis().CenterTitle();
# cov_matrix_muangle_frac.GetYaxis().CenterTitle();
# cov_matrix_muangle_frac.Draw("colz TEXT")

c_mumom = TCanvas()
cov_matrix_mumom.SetMarkerColor(kWhite);
cov_matrix_mumom.SetMarkerSize(1.6);
cov_matrix_mumom.GetXaxis().SetTitle("Bin i");
cov_matrix_mumom.GetYaxis().SetTitle("Bin j");
cov_matrix_mumom.GetXaxis().CenterTitle();
cov_matrix_mumom.GetYaxis().CenterTitle();
cov_matrix_mumom.Draw("colz TEXT")

c_muangle = TCanvas()
cov_matrix_muangle.SetMarkerColor(kWhite);
cov_matrix_muangle.SetMarkerSize(1.6);
cov_matrix_muangle.GetXaxis().SetTitle("Bin i");
cov_matrix_muangle.GetYaxis().SetTitle("Bin j");
cov_matrix_muangle.GetXaxis().CenterTitle();
cov_matrix_muangle.GetYaxis().CenterTitle();
cov_matrix_muangle.Draw("colz TEXT")

c_muangle_mumom = TCanvas()
cov_matrix_muangle_mumom.SetMarkerColor(kWhite);
cov_matrix_muangle_mumom.SetMarkerSize(1.6);
cov_matrix_muangle_mumom.GetXaxis().SetTitle("Bin i");
cov_matrix_muangle_mumom.GetYaxis().SetTitle("Bin j");
cov_matrix_muangle_mumom.GetXaxis().CenterTitle();
cov_matrix_muangle_mumom.GetYaxis().CenterTitle();
cov_matrix_muangle_mumom.Draw("colz TEXT")

raw_input("Please press enter to exit.")











import sys, os
import math

from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")



cov_matrix_mumom = TH2D("cov_matrix_mumom", "", 6, 0, 6, 6, 0, 6)
cov_matrix_mumom_frac = TH2D("cov_matrix_mumom_frac", "", 6, 0, 6, 6, 0, 6)
cov_matrix_muangle = TH2D("cov_matrix_muangle", "", 9, 0, 9, 9, 0, 9)
cov_matrix_muangle_frac = TH2D("cov_matrix_muangle_frac", "", 9, 0, 9, 9, 0, 9)


file_1 = TFile("covariance_detector_firstround.root");
covariance_mumom_1 = file_1.Get("covariance_matrix_detector_mumom")
covariance_muangle_1 = file_1.Get("covariance_matrix_detector_muangle")


file_2 = TFile("covariance_detector_secondround.root");
covariance_mumom_2 = file_2.Get("covariance_matrix_detector_mumom")
covariance_muangle_2 = file_2.Get("covariance_matrix_detector_muangle")


for i in xrange(0, covariance_mumom_1.GetNbinsX()):
	for j in xrange(0, covariance_mumom_1.GetNbinsY()):
		cov_matrix_mumom.SetBinContent(i+1, j+1, covariance_mumom_1.GetBinContent(i+1, j+1) + covariance_mumom_2.GetBinContent(i+1, j+1))

for i in xrange(0, covariance_muangle_1.GetNbinsX()):
	for j in xrange(0, covariance_muangle_1.GetNbinsY()):
		cov_matrix_muangle.SetBinContent(i+1, j+1, covariance_muangle_1.GetBinContent(i+1, j+1) + covariance_muangle_2.GetBinContent(i+1, j+1))



cov_file = TFile("covariance_detector.root", "RECREATE");
cov_file.cd();
cov_matrix_mumom.Write("covariance_matrix_detector_mumom");
cov_matrix_muangle.Write("covariance_matrix_detector_muangle");
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

raw_input("Please press enter to exit.")











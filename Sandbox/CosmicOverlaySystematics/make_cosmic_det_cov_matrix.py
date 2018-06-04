import sys, os
import math

from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")


# The cov matrix
cov_matrix_mumom = TH2D("cov_matrix_mumom", "", 6, 0, 6, 6, 0, 6)
cov_matrix_mumom_frac = TH2D("cov_matrix_mumom_frac", "", 6, 0, 6, 6, 0, 6)
cov_matrix_muangle = TH2D("cov_matrix_muangle", "", 9, 0, 9, 9, 0, 9)
cov_matrix_muangle_frac = TH2D("cov_matrix_muangle_frac", "", 9, 0, 9, 9, 0, 9)

# Get the central value xsec
file_cv = TFile("xsec_file_cv.root");
xsec_onebin_cv = file_cv.Get("xsec_onebin_cv")
xsec_mumom_cv = file_cv.Get("xsec_mumom_cv")
xsec_muangle_cv = file_cv.Get("xsec_muangle_cv")

print "CV cross section", xsec_onebin_cv.GetBinContent(1)

print "Systematic parameter & Cross section & Total xsec perc difference \\\\"

print "cv & ", xsec_onebin_cv.GetBinContent(1), " &  0.0  \\\\"



for i in xrange(0, xsec_mumom_cv.GetNbinsX()):
	for j in xrange(0, xsec_mumom_cv.GetNbinsX()):
		cov_matrix_mumom.SetBinContent(i+1, j+1, 0) 
		cov_matrix_mumom_frac.SetBinContent(i+1, j+1, 0)

for i in xrange(0, xsec_muangle_cv.GetNbinsX()):
	for j in xrange(0, xsec_muangle_cv.GetNbinsX()):
		cov_matrix_muangle.SetBinContent(i+1, j+1, 0) 
		cov_matrix_muangle_frac.SetBinContent(i+1, j+1, 0)





file_name = "xsec_file_cv_cosmicscaled_overlay.root"
file = TFile(file_name);

xsec_onebin = file.Get("xsec_onebin_cv_cosmicscaled_overlay")
xsec_mumom = file.Get("xsec_mumom_cv_cosmicscaled_overlay")
xsec_muangle = file.Get("xsec_muangle_cv_cosmicscaled_overlay")

if file.IsOpen():
	print "Good to go!"

syst_total_xsec = abs(xsec_onebin_cv.GetBinContent(1) - xsec_onebin.GetBinContent(1))**2

print "Total onebin syst err:", math.sqrt(syst_total_xsec)
print "Total onebin syst err (relative):", math.sqrt(syst_total_xsec) / xsec_onebin_cv.GetBinContent(1) 








for i in xrange(0, xsec_mumom.GetNbinsX()):
	for j in xrange(0, xsec_mumom.GetNbinsX()):
		d0 = (xsec_mumom.GetBinContent(i+1) - xsec_mumom_cv.GetBinContent(i+1))*(xsec_mumom.GetBinContent(j+1) - xsec_mumom_cv.GetBinContent(j+1))
		d0_frac = d0 / ((xsec_mumom_cv.GetBinContent(i+1))*(xsec_mumom_cv.GetBinContent(j+1)))
		cov_matrix_mumom.SetBinContent(i+1, j+1, cov_matrix_mumom.GetBinContent(i+1, j+1) + d0)
		cov_matrix_mumom_frac.SetBinContent(i+1, j+1, cov_matrix_mumom_frac.GetBinContent(i+1, j+1) + d0_frac)



for i in xrange(0, xsec_muangle.GetNbinsX()):
	for j in xrange(0, xsec_muangle.GetNbinsX()):
		d0 = (xsec_muangle.GetBinContent(i+1) - xsec_muangle_cv.GetBinContent(i+1))*(xsec_muangle.GetBinContent(j+1) - xsec_muangle_cv.GetBinContent(j+1))
		d0_frac = d0 / ((xsec_muangle_cv.GetBinContent(i+1))*(xsec_muangle_cv.GetBinContent(j+1)))
		cov_matrix_muangle.SetBinContent(i+1, j+1, cov_matrix_muangle.GetBinContent(i+1, j+1) + d0)
		cov_matrix_muangle_frac.SetBinContent(i+1, j+1, cov_matrix_muangle_frac.GetBinContent(i+1, j+1) + d0_frac)









gStyle.SetPaintTextFormat("4.5f");
gStyle.SetPalette(kDeepSea);


cov_file = TFile("covariance_cosmic.root", "RECREATE");
cov_file.cd();
cov_matrix_mumom.Write("covariance_matrix_cosmic_mumom");
cov_matrix_muangle.Write("covariance_matrix_cosmic_muangle");
cov_file.Close();

c_mumom = TCanvas()
cov_matrix_mumom_frac.SetMarkerColor(kWhite);
cov_matrix_mumom_frac.SetMarkerSize(1.6);
cov_matrix_mumom_frac.GetXaxis().SetTitle("Bin i");
cov_matrix_mumom_frac.GetYaxis().SetTitle("Bin j");
cov_matrix_mumom_frac.GetXaxis().CenterTitle();
cov_matrix_mumom_frac.GetYaxis().CenterTitle();
cov_matrix_mumom_frac.Draw("colz TEXT")

c_muangle = TCanvas()
cov_matrix_muangle_frac.SetMarkerColor(kWhite);
cov_matrix_muangle_frac.SetMarkerSize(1.6);
cov_matrix_muangle_frac.GetXaxis().SetTitle("Bin i");
cov_matrix_muangle_frac.GetYaxis().SetTitle("Bin j");
cov_matrix_muangle_frac.GetXaxis().CenterTitle();
cov_matrix_muangle_frac.GetYaxis().CenterTitle();
cov_matrix_muangle_frac.Draw("colz TEXT")

# c_mumom = TCanvas()
# cov_matrix_mumom.SetMarkerColor(kWhite);
# cov_matrix_mumom.SetMarkerSize(1.6);
# cov_matrix_mumom.GetXaxis().SetTitle("Bin i");
# cov_matrix_mumom.GetYaxis().SetTitle("Bin j");
# cov_matrix_mumom.GetXaxis().CenterTitle();
# cov_matrix_mumom.GetYaxis().CenterTitle();
# cov_matrix_mumom.Draw("colz TEXT")

# c_muangle = TCanvas()
# cov_matrix_muangle.SetMarkerColor(kWhite);
# cov_matrix_muangle.SetMarkerSize(1.6);
# cov_matrix_muangle.GetXaxis().SetTitle("Bin i");
# cov_matrix_muangle.GetYaxis().SetTitle("Bin j");
# cov_matrix_muangle.GetXaxis().CenterTitle();
# cov_matrix_muangle.GetYaxis().CenterTitle();
# cov_matrix_muangle.Draw("colz TEXT")

raw_input("Please press enter to exit.")











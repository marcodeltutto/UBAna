import sys, os
import math

from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")


# Get the central value xsec
file_cv = TFile("xsec_file_cv.root");
xsec_onebin_cv = file_cv.Get("xsec_onebin_cv")
xsec_mumom_cv = file_cv.Get("xsec_mumom_cv")
xsec_muangle_cv = file_cv.Get("xsec_muangle_cv")
xsec_muangle_mumom_cv = file_cv.Get("xsec_muangle_mumom_cv")




# The cov matrix
cov_matrix_mumom = TH2D("cov_matrix_mumom", "", 6, 0, 6, 6, 0, 6)
cov_matrix_mumom_frac = TH2D("cov_matrix_mumom_frac", "", 6, 0, 6, 6, 0, 6)
cov_matrix_muangle = TH2D("cov_matrix_muangle", "", 9, 0, 9, 9, 0, 9)
cov_matrix_muangle_frac = TH2D("cov_matrix_muangle_frac", "", 9, 0, 9, 9, 0, 9)

n_bins_mumom = xsec_muangle_mumom_cv.GetNbinsY()
n_bins_muangle = xsec_muangle_mumom_cv.GetNbinsX()

cov_matrix_muangle_mumom = TH2D("cov_matrix_muangle_mumom", "", n_bins_mumom*n_bins_muangle, 0, n_bins_mumom*n_bins_muangle, n_bins_mumom*n_bins_muangle, 0, n_bins_mumom*n_bins_muangle)
cov_matrix_muangle_mumom_frac = TH2D("cov_matrix_muangle_mumom_frac", "", n_bins_mumom*n_bins_muangle, 0, n_bins_mumom*n_bins_muangle, n_bins_mumom*n_bins_muangle, 0, n_bins_mumom*n_bins_muangle)




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

for i in xrange(0, n_bins_muangle):
	for j in xrange(0, n_bins_mumom):
		for m in xrange(0, n_bins_muangle):
			for n in xrange(0, n_bins_mumom):

				a = j + i * n_bins_mumom + 1;
				b = n + m * n_bins_mumom + 1;

				cov_matrix_muangle_mumom.SetBinContent(a, b, 0)
				cov_matrix_muangle_mumom_frac.SetBinContent(a, b, 0)





file_name = "xsec_file_nodirt.root"
file = TFile(file_name);

xsec_onebin = file.Get("xsec_onebin_cv")
xsec_mumom = file.Get("xsec_mumom_cv")
xsec_muangle = file.Get("xsec_muangle_cv")
xsec_muangle_mumom = file.Get("xsec_muangle_mumom_cv")

if file.IsOpen():
	print "Good to go!"

syst_total_xsec = abs(xsec_onebin_cv.GetBinContent(1) - xsec_onebin.GetBinContent(1))**2
import math

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


for i in xrange(0, n_bins_muangle):
	for j in xrange(0, n_bins_mumom):
		for m in xrange(0, n_bins_muangle):
			for n in xrange(0, n_bins_mumom):
				a = j + i * n_bins_mumom + 1;
				b = n + m * n_bins_mumom + 1;
				d0 = (xsec_muangle_mumom.GetBinContent(i+1, j+1) - xsec_muangle_mumom_cv.GetBinContent(i+1, j+1))*(xsec_muangle_mumom.GetBinContent(m+1, n+1) - xsec_muangle_mumom_cv.GetBinContent(m+1, n+1))
				den = ((xsec_muangle_mumom_cv.GetBinContent(i+1, j+1))*xsec_muangle_mumom_cv.GetBinContent(m+1, n+1))
				cov_matrix_muangle_mumom.SetBinContent(a, b, cov_matrix_muangle_mumom.GetBinContent(a, b) + d0)
				if (den != 0):
					d0_frac = d0 / den
					cov_matrix_muangle_mumom_frac.SetBinContent(a, b, cov_matrix_muangle_mumom_frac.GetBinContent(a, b) + d0_frac)






gStyle.SetPaintTextFormat("4.5f");
gStyle.SetPalette(kDeepSea);


cov_file = TFile("covariance_dirt.root", "RECREATE");
cov_file.cd();
cov_matrix_mumom.Write("covariance_matrix_dirt_mumom");
cov_matrix_muangle.Write("covariance_matrix_dirt_muangle");
cov_matrix_muangle_mumom.Write("covariance_matrix_cosmic_muangle_mumom");
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

c_muangle_mumom = TCanvas()
cov_matrix_muangle_mumom_frac.SetMarkerSize(1.1);
cov_matrix_muangle_mumom_frac.GetXaxis().SetTitle("Bin ij");
cov_matrix_muangle_mumom_frac.GetYaxis().SetTitle("Bin mn");
cov_matrix_muangle_mumom_frac.GetXaxis().CenterTitle();
cov_matrix_muangle_mumom_frac.GetYaxis().CenterTitle();
cov_matrix_muangle_mumom_frac.Draw("colz TEXT")

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

# c_muangle_mumom = TCanvas()
# cov_matrix_muangle_mumom.SetMarkerColor(kWhite);
# cov_matrix_muangle_mumom.SetMarkerSize(1.1);
# cov_matrix_muangle_mumom.GetXaxis().SetTitle("Bin ij");
# cov_matrix_muangle_mumom.GetYaxis().SetTitle("Bin mn");
# cov_matrix_muangle_mumom.GetXaxis().CenterTitle();
# cov_matrix_muangle_mumom.GetYaxis().CenterTitle();
# cov_matrix_muangle_mumom.Draw("colz")

raw_input("Please press enter to exit.")











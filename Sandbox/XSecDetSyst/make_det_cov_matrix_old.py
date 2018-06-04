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


det_syst_list = ["nospacecharge", "dicharge", "lightyeild", "nodeltaray", "stretchRes", "altDeadChannels", "deadSaturatedChannels", "noPEnoise", "noShortedResp", "whitenoise", "enhancedexttpcvis", "lifetime10ms", "dl0", "dt0", "birksrecomb", "nohadronic"]

stat_err_perbin_mumom = [0.0041, 0.013, 0.010, 0.0048, 0.0028, 0.00067]
stat_err_perbin_muangle = [0.0034, 0.0026, 0.0060, 0.0038, 0.0055, 0.0087, 0.0080, 0.011, 0.018]
stat_err_perbin_onebin = 0.0091

stat_err_perbin_mumom = [0, 0, 0, 0, 0, 0]
stat_err_perbin_muangle = [0, 0, 0, 0, 0, 0, 0, 0, 0]
stat_err_perbin_onebin = 0

syst_total_xsec = 0
syst_mumom = [0, 0, 0, 0, 0, 0]

for syst_name in det_syst_list:

	if syst_name == "nodeltaray" or syst_name == "nospacecharge" or syst_name == "stretchRes" or syst_name == "noShortedResp":
		continue

	file_name = "xsec_file_" + syst_name + ".root"
	file = TFile(file_name);
	# if (file.IsOpen()):
	# 	print "File with name", file_name, "is opened"
	# else:
	# 	print "Cannot find file", file_name
	# 	exit(0)

 	xsec_onebin = file.Get("xsec_onebin_" + syst_name)
 	xsec_mumom = file.Get("xsec_mumom_" + syst_name)
 	xsec_muangle = file.Get("xsec_muangle_" + syst_name)

	perc_diff = (xsec_onebin_cv.GetBinContent(1) - xsec_onebin.GetBinContent(1)) / xsec_onebin_cv.GetBinContent(1)
	# print syst_name, " & ", xsec_onebin.GetBinContent(1), " & ", perc_diff*100, "  \\\\"
	syst_total_xsec = syst_total_xsec + abs(xsec_onebin_cv.GetBinContent(1) - xsec_onebin.GetBinContent(1))**2
	#print "diff is ", abs(xsec_onebin_cv.GetBinContent(1) - xsec_onebin.GetBinContent(1))

	

	

	# Loop over bins to calculate D0

	for i in xrange(0, xsec_mumom.GetNbinsX()):
		d0 = (xsec_mumom.GetBinContent(i+1) - xsec_mumom_cv.GetBinContent(i+1))**2
		d0_frac = (xsec_mumom.GetBinContent(i+1) - xsec_mumom_cv.GetBinContent(i+1))**2 / (xsec_mumom_cv.GetBinContent(i+1))**2
		cov_matrix_mumom.SetBinContent(i+1, i+1, cov_matrix_mumom.GetBinContent(i+1, i+1) + d0)
		cov_matrix_mumom_frac.SetBinContent(i+1, i+1, cov_matrix_mumom_frac.GetBinContent(i+1, i+1) + d0_frac)
		syst_mumom[i] = syst_mumom[i] + d0_frac

		if i == 0:
			# print "syst_mumom[0]", syst_mumom[0]
			print syst_name, "d0", d0, "d0_frac", d0_frac, "sqrt_d0_frac", math.sqrt(d0_frac), "xsec", xsec_mumom.GetBinContent(i+1), "nominal_xsec", xsec_mumom_cv.GetBinContent(i+1)
		# print "systematic", syst_name, "d0", d0, "---", cov_matrix_mumom.GetBinContent(i+1, i+1)
		# print "systematic", syst_name, "nominal", xsec_mumom_cv.GetBinContent(i+1), "variation", xsec_mumom.GetBinContent(i+1) 

  
	for i in xrange(0, xsec_muangle.GetNbinsX()):
		d0 = (xsec_muangle.GetBinContent(i+1) - xsec_muangle_cv.GetBinContent(i+1))**2
		d0_frac = (xsec_muangle.GetBinContent(i+1) - xsec_muangle_cv.GetBinContent(i+1))**2 / (xsec_muangle_cv.GetBinContent(i+1))**2
		cov_matrix_muangle.SetBinContent(i+1, i+1, cov_matrix_muangle.GetBinContent(i+1, i+1) + d0)
		cov_matrix_muangle_frac.SetBinContent(i+1, i+1, cov_matrix_muangle_frac.GetBinContent(i+1, i+1) + d0_frac)


print "Total onebin syst err:", math.sqrt(syst_total_xsec)
print "Total onebin syst err (relative):", math.sqrt(syst_total_xsec) / xsec_onebin_cv.GetBinContent(1)

for i in xrange(0, xsec_mumom_cv.GetNbinsX()):
	print "bin", i+1, "sqrt of d0_frac", math.sqrt(syst_mumom[i]) 

gStyle.SetPaintTextFormat("4.3f");
gStyle.SetPalette(kDeepSea);

# cov_matrix_mumom.SetMarkerColor(kWhite);
# cov_matrix_mumom.SetMarkerSize(1.6);
# cov_matrix_mumom.GetXaxis().SetTitle("Bin i");
# cov_matrix_mumom.GetXaxis().SetTitle("Bin j");
# cov_matrix_mumom.GetXaxis().CenterTitle();
# cov_matrix_mumom.GetYaxis().CenterTitle();
# cov_matrix_mumom
# cov_matrix_mumom
# cov_matrix_mumom.Draw("colz TEXT")

cov_file = TFile("covariance_detector.root", "UPDATE");
cov_file.cd();
cov_matrix_mumom.Write("covariance_matrix_detector_mumom");
cov_matrix_muangle.Write("covariance_matrix_detector_muangle");
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











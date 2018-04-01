import sys, os

from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")


# The cov matrix
cov_matrix = TH2D("cov_matrix", "", 6, 0, 6, 6, 0, 6)
cov_matrix_frac = TH2D("cov_matrix", "", 6, 0, 6, 6, 0, 6)


# Get the central value xsec
file_cv = TFile("xsec_file_cv.root");
xsec_onebin_cv = file_cv.Get("xsec_onebin_cv")
xsec_mumom_cv = file_cv.Get("xsec_mumom_cv")


for i in xrange(0, xsec_mumom_cv.GetNbinsX()):
	for j in xrange(0, xsec_mumom_cv.GetNbinsX()):
		cov_matrix.SetBinContent(i+1, j+1, 0) 
		cov_matrix_frac.SetBinContent(i+1, j+1, 0)


det_syst_list = ["nospacecharge", "dicharge", "lightyeild", "nodeltaray", "stretchRes", "altDeadChannels", "deadSaturatedChannels", "noPEnoise", "noShortedResp", "whitenoise", "enhancedexttpcvis", "lifetime10ms", "dl0", "birksrecomb", "nohadronic"]

stat_err_perbin_mumom = [0.0041, 0.013, 0.010, 0.0048, 0.0028, 0.00067]
stat_err_perbin_muangle = [0.0034, 0.0026, 0.0060, 0.0038, 0.0055, 0.0087, 0.0080, 0.011, 0.018]
stat_err_perbin_onebin = 0.0091

syst_total_xsec = 0

for syst_name in det_syst_list:

	if syst_name == "nodeltaray": # or syst_name == "dicharge" or syst_name == "stretchRes" or syst_name == "noShortedResp":
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



	perc_diff = (xsec_onebin_cv.GetBinContent(1) - xsec_onebin.GetBinContent(1)) / xsec_onebin_cv.GetBinContent(1)
	print "Systematic", syst_name, "=> Total xsec perc difference", perc_diff, "-", perc_diff*100
	syst_total_xsec = syst_total_xsec + abs(xsec_onebin_cv.GetBinContent(1) - xsec_onebin.GetBinContent(1))
	print "diff is ", abs(xsec_onebin_cv.GetBinContent(1) - xsec_onebin.GetBinContent(1))

	

	

	# Loop over bins to calculate D0

	for i in xrange(0, xsec_mumom.GetNbinsX()):
		d0 = (xsec_mumom.GetBinContent(i+1) - xsec_mumom_cv.GetBinContent(i+1) + stat_err_perbin_mumom[i])**2
		d0_frac = (xsec_mumom.GetBinContent(i+1) - xsec_mumom_cv.GetBinContent(i+1) + stat_err_perbin_mumom[i])**2 / (xsec_mumom_cv.GetBinContent(i+1))**2
		cov_matrix.SetBinContent(i+1, i+1, cov_matrix.GetBinContent(i+1, i+1) + d0_frac)
		cov_matrix_frac.SetBinContent(i+1, i+1, cov_matrix.GetBinContent(i+1, i+1) + d0)
		# print "systematic", syst_name, "d0", d0, "---", cov_matrix.GetBinContent(i+1, i+1)
		# print "systematic", syst_name, "nominal", xsec_mumom_cv.GetBinContent(i+1), "variation", xsec_mumom.GetBinContent(i+1) 



print "Total onebin syst err:", syst_total_xsec
print "Total onebin syst err (relative):", syst_total_xsec / xsec_onebin.GetBinContent(1)

gStyle.SetPaintTextFormat("4.2f");
gStyle.SetPalette(kDeepSea);

# cov_matrix.SetMarkerColor(kWhite);
# cov_matrix.SetMarkerSize(1.6);
# cov_matrix.GetXaxis().SetTitle("Bin i");
# cov_matrix.GetXaxis().SetTitle("Bin j");
# cov_matrix.GetXaxis().CenterTitle();
# cov_matrix.GetYaxis().CenterTitle();
# cov_matrix
# cov_matrix
# cov_matrix.Draw("colz TEXT")

cov_matrix_frac.SetMarkerColor(kWhite);
cov_matrix_frac.SetMarkerSize(1.6);
cov_matrix_frac.GetXaxis().SetTitle("Bin i");
cov_matrix_frac.GetXaxis().SetTitle("Bin j");
cov_matrix_frac.GetXaxis().CenterTitle();
cov_matrix_frac.GetYaxis().CenterTitle();
cov_matrix_frac
cov_matrix_frac
cov_matrix_frac.Draw("colz TEXT")

raw_input("Please press enter to exit.")











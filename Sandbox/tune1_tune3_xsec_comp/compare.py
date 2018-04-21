import sys, os
import math

from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")





file_1 = TFile("xsec_tune1.root");
xsec_mumom_1 = file_1.Get("xsec_mumom_cv")
cov_mumom_tune_1 = file_1.Get("covariance_matrix_mumom_cv")
xsec_muangle_1 = file_1.Get("xsec_muangle_cv")
cov_muangle_tune_1 = file_1.Get("covariance_matrix_muangle_cv")

file_3 = TFile("xsec_tune3.root");
xsec_mumom_3 = file_3.Get("xsec_mumom_cv")
# cov_tune_3 = file_3.Get("covariance_matrix_mumom_cv")
xsec_muangle_3 = file_3.Get("xsec_muangle_cv")

h_cov_mumom_tune1 = xsec_mumom_1.Clone("h_cov_mumom_tune1")
for i in xrange(cov_mumom_tune_1.GetNbinsX()):
	unc_syst = math.sqrt(cov_mumom_tune_1.GetBinContent(i+1, i+1));
	h_cov_mumom_tune1.SetBinError(i+1, unc_syst);

h_cov_muangle_tune1 = xsec_muangle_1.Clone("h_cov_mumom_tune1")
for i in xrange(cov_muangle_tune_1.GetNbinsX()):
	unc_syst = math.sqrt(cov_muangle_tune_1.GetBinContent(i+1, i+1));
	h_cov_muangle_tune1.SetBinError(i+1, unc_syst);


c = TCanvas("c1", "c1")

xsec_mumom_1.SetLineColor(kBlack)
xsec_mumom_3.SetLineColor(50)

xsec_mumom_1.GetXaxis().SetTitle("p_{#mu} [GeV]")
xsec_mumom_1.GetYaxis().SetTitle("d#sigma/dp_{#mu} [10^{-38} cm^{2}/GeV]")

xsec_mumom_1.SetMaximum(1.5)

xsec_mumom_1.Draw("histo")
h_cov_mumom_tune1.Draw("E1 same")
xsec_mumom_3.Draw("histo same")

l = TLegend(0.42,0.71, 0.87,0.85);
l.AddEntry(xsec_muangle_1, "Tune 1 (GENIE Syst Uncertainty)", "le");
l.AddEntry(xsec_muangle_3, "Tune 3", "l");
l.Draw()

c1 = TCanvas("c", "c")

xsec_muangle_1.SetLineColor(kBlack)
xsec_muangle_3.SetLineColor(50)

xsec_muangle_1.GetXaxis().SetTitle("cos(#theta_{#mu})")
xsec_muangle_1.GetYaxis().SetTitle("d#sigma/dcos(#theta_{#mu}) [10^{-38} cm^{2}]")

xsec_muangle_1.SetMaximum(2.8)

xsec_muangle_1.Draw("histo")
h_cov_muangle_tune1.Draw("E1 same")
xsec_muangle_3.Draw("histo same")

l.Draw()


# print "CV cross section", xsec_onebin_cv.GetBinContent(1)

# print "Systematic parameter & Cross section & Total xsec perc difference \\\\"

# print "cv & ", xsec_onebin_cv.GetBinContent(1), " &  0.0  \\\\"



# for i in xrange(0, xsec_mumom_cv.GetNbinsX()):
# 	for j in xrange(0, xsec_mumom_cv.GetNbinsX()):
# 		cov_matrix.SetBinContent(i+1, j+1, 0) 
# 		cov_matrix_frac.SetBinContent(i+1, j+1, 0)


# det_syst_list = ["nospacecharge", "dicharge", "lightyeild", "nodeltaray", "stretchRes", "altDeadChannels", "deadSaturatedChannels", "noPEnoise", "noShortedResp", "whitenoise", "enhancedexttpcvis", "lifetime10ms", "dl0", "dt0", "birksrecomb", "nohadronic"]

# stat_err_perbin_mumom = [0.0041, 0.013, 0.010, 0.0048, 0.0028, 0.00067]
# stat_err_perbin_muangle = [0.0034, 0.0026, 0.0060, 0.0038, 0.0055, 0.0087, 0.0080, 0.011, 0.018]
# stat_err_perbin_onebin = 0.0091

# syst_total_xsec = 0

# for syst_name in det_syst_list:

# 	if syst_name == "nodeltaray": # or syst_name == "dicharge" or syst_name == "stretchRes" or syst_name == "noShortedResp":
# 		continue

# 	file_name = "xsec_file_" + syst_name + ".root"
# 	file = TFile(file_name);
# 	# if (file.IsOpen()):
# 	# 	print "File with name", file_name, "is opened"
# 	# else:
# 	# 	print "Cannot find file", file_name
# 	# 	exit(0)

#  	xsec_onebin = file.Get("xsec_onebin_" + syst_name)
#  	xsec_mumom = file.Get("xsec_mumom_" + syst_name)



# 	perc_diff = (xsec_onebin_cv.GetBinContent(1) - xsec_onebin.GetBinContent(1)) / xsec_onebin_cv.GetBinContent(1)
# 	print syst_name, " & ", xsec_onebin.GetBinContent(1), " & ", perc_diff*100, "  \\\\"
# 	syst_total_xsec = syst_total_xsec + abs(xsec_onebin_cv.GetBinContent(1) - xsec_onebin.GetBinContent(1))
# 	#print "diff is ", abs(xsec_onebin_cv.GetBinContent(1) - xsec_onebin.GetBinContent(1))

	

	

# 	# Loop over bins to calculate D0

# 	for i in xrange(0, xsec_mumom.GetNbinsX()):
# 		d0 = (xsec_mumom.GetBinContent(i+1) - xsec_mumom_cv.GetBinContent(i+1) + stat_err_perbin_mumom[i])**2
# 		d0_frac = (xsec_mumom.GetBinContent(i+1) - xsec_mumom_cv.GetBinContent(i+1) + stat_err_perbin_mumom[i])**2 / (xsec_mumom_cv.GetBinContent(i+1))**2
# 		cov_matrix.SetBinContent(i+1, i+1, cov_matrix.GetBinContent(i+1, i+1) + d0_frac)
# 		cov_matrix_frac.SetBinContent(i+1, i+1, cov_matrix.GetBinContent(i+1, i+1) + d0)
# 		# print "systematic", syst_name, "d0", d0, "---", cov_matrix.GetBinContent(i+1, i+1)
# 		# print "systematic", syst_name, "nominal", xsec_mumom_cv.GetBinContent(i+1), "variation", xsec_mumom.GetBinContent(i+1) 



# print "Total onebin syst err:", syst_total_xsec
# print "Total onebin syst err (relative):", syst_total_xsec / xsec_onebin.GetBinContent(1)

# gStyle.SetPaintTextFormat("4.2f");
# gStyle.SetPalette(kDeepSea);

# # cov_matrix.SetMarkerColor(kWhite);
# # cov_matrix.SetMarkerSize(1.6);
# # cov_matrix.GetXaxis().SetTitle("Bin i");
# # cov_matrix.GetXaxis().SetTitle("Bin j");
# # cov_matrix.GetXaxis().CenterTitle();
# # cov_matrix.GetYaxis().CenterTitle();
# # cov_matrix
# # cov_matrix
# # cov_matrix.Draw("colz TEXT")

# cov_matrix_frac.SetMarkerColor(kWhite);
# cov_matrix_frac.SetMarkerSize(1.6);
# cov_matrix_frac.GetXaxis().SetTitle("Bin i");
# cov_matrix_frac.GetXaxis().SetTitle("Bin j");
# cov_matrix_frac.GetXaxis().CenterTitle();
# cov_matrix_frac.GetYaxis().CenterTitle();
# cov_matrix_frac
# cov_matrix_frac
# cov_matrix_frac.Draw("colz TEXT")

raw_input("Please press enter to exit.")











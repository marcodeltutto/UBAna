import sys, os, math
from array import array

from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Base
from ROOT import vector as vector


label = "xsec_poly_muangle_mumom_"
# label = "efficiency_poly_muangle_mumom_"
# label = "background_poly_muangle_mumom_"


unc_plotter = Base.UncertaintyPlotter()
unc_plotter.SetXaxisTitle("p_{#mu}^{reco} [GeV]")

# Get the central value xsec
file_cv = TFile("xsec_file_CV.root");
xsec_poly_muangle_mumom_cv = file_cv.Get(label + "CV")
eff_cv = file_cv.Get("efficiency_poly_muangle_mumom_CV")
bkg_cv = file_cv.Get("background_poly_muangle_mumom_CV")

n_bins_poly = xsec_poly_muangle_mumom_cv.GetNumberOfBins()
print "Number of poly bins:", n_bins_poly
cov_matrix_poly_muangle_mumom = TH2D("cov_matrix_poly_muangle_mumom", "", n_bins_poly, 0, n_bins_poly, n_bins_poly, 0, n_bins_poly)
cov_matrix_poly_muangle_mumom_frac = TH2D("cov_matrix_poly_muangle_mumom_frac", "", n_bins_poly, 0, n_bins_poly, n_bins_poly, 0, n_bins_poly)
cov_matrix_poly_muangle_mumom_frac_total = TH2D("cov_matrix_poly_muangle_mumom_frac_total", "", n_bins_poly, 0, n_bins_poly, n_bins_poly, 0, n_bins_poly)


#
# Reset matrices to zero
#

for i in xrange(0, n_bins_poly):
	for j in xrange(0, n_bins_poly):
		cov_matrix_poly_muangle_mumom.SetBinContent(i+1, j+1, 0) 
		cov_matrix_poly_muangle_mumom_frac.SetBinContent(i+1, j+1, 0)
		cov_matrix_poly_muangle_mumom_frac_total.SetBinContent(i+1, j+1, 0)





det_syst_list = ["CV", "dataSCE", "withDIC", "squeezeResp", "stretchResp", "DLdown", "DLup", "DTdown", "DTup", "LArG4BugFix", "downPEnoise", "upPEnoise", "noiseAmpDown", "noiseAmpUp", "enhancedexttpcvis", "lifetime10ms", "birksrecomb" ,"deadSaturatedChannels", "altDeadChannels"]
det_syst_list = ["CV", "dataSCE", "withDIC", "squeezeResp", "DLdown", "DTdown", "LArG4BugFix", "downPEnoise", "noiseAmpDown", "enhancedexttpcvis", "lifetime10ms", "birksrecomb" ,"deadSaturatedChannels", "altDeadChannels"]



syst_total_xsec = 0
syst_mumom = [0, 0, 0, 0, 0, 0]

for syst_name in det_syst_list:

	# if syst_name == "nodeltaray" or syst_name == "nospacecharge" or syst_name == "stretchRes" or syst_name == "stretchResp" or syst_name == "noShortedResp":
	# 	continue

	file_name = "xsec_file_" + syst_name + ".root"
	file = TFile(file_name);
	if (file.IsOpen()):
		print "File with name", file_name, "is open"
	else:
		print "Cannot find file", file_name
		exit(0)

 	xsec_poly_muangle_mumom = file.Get(label + syst_name)

	for i in xrange(0, n_bins_poly):
		for j in xrange(0, n_bins_poly):
			d0 = (xsec_poly_muangle_mumom.GetBinContent(i+1) - xsec_poly_muangle_mumom_cv.GetBinContent(i+1))*(xsec_poly_muangle_mumom.GetBinContent(j+1) - xsec_poly_muangle_mumom_cv.GetBinContent(j+1))
			d0_frac = d0 / (xsec_poly_muangle_mumom_cv.GetBinContent(i+1)*xsec_poly_muangle_mumom_cv.GetBinContent(j+1))
			cov_matrix_poly_muangle_mumom.SetBinContent(i+1, j+1, cov_matrix_poly_muangle_mumom.GetBinContent(i+1, j+1) + d0) 
			cov_matrix_poly_muangle_mumom_frac.SetBinContent(i+1, j+1, cov_matrix_poly_muangle_mumom_frac.GetBinContent(i+1, j+1) + d0_frac)

	cov_matrix_poly_muangle_mumom_frac_total.Add(cov_matrix_poly_muangle_mumom_frac)

	if (syst_name is not 'CV'): unc_plotter.AddFracCovarianceMatrix(syst_name, cov_matrix_poly_muangle_mumom_frac)

	for i in xrange(0, n_bins_poly):
		for j in xrange(0, n_bins_poly):
			cov_matrix_poly_muangle_mumom.SetBinContent(i+1, j+1, 0) 
			cov_matrix_poly_muangle_mumom_frac.SetBinContent(i+1, j+1, 0)

unc_plotter.AddFracCovarianceMatrix("TOTAL - DETECTOR", cov_matrix_poly_muangle_mumom_frac_total)

unc_plotter.SetCrossSection(xsec_poly_muangle_mumom_cv);

unc_plotter.MakePlot("relative_uncertainty_detector_muangle_mumom", True);


import math

for i in xrange(0, n_bins_poly):
	# print 'Bin ', i, ', bkg unc =', math.sqrt(cov_matrix_poly_muangle_mumom_frac_total.GetBinContent(i+1, i+1))
	print math.sqrt(cov_matrix_poly_muangle_mumom_frac_total.GetBinContent(i+1, i+1)), ', '

# gStyle.SetPalette(kDeepSea);




NRGBs = 5
NCont = 100
mainColour = [ 1.00, 1.00, 1.00, 1.00, 1.00 ]
otherColour = [ 0.99,0.80, 0.60, 0.40, 0.20 ]
#otherOtherColour = [ 0.9,0.80, 0.80, 0.80, 0.80 ]
stops = [ 0.00, 0.05, 0.1, 0.4, 1.00 ]
mainColourArray = array('d', mainColour)
otherColourArray = array('d', otherColour)
# otherOtherColourArray = array('d', otherOtherColour)
stopsArray = array('d', stops)
TColor.CreateGradientColorTable(NRGBs, stopsArray, mainColourArray, otherColourArray, otherColourArray, NCont)
gStyle.SetNumberContours(NCont)



# TH2F h = cov_matrix_muangle_mumom_frac.Clone("h");

# i_label_number = 0;
# j_label_number = 0;

# for i in xrange (0, n_bins_muangle+1):

#     for (int i = 0; i <  cov_matrix_histo->GetNbinsX()+1; i++) {
#       std::ostringstream oss;
#       oss << i_label_number << "," << j_label_number;
#       if (j_label_number % _bs.GetNbinsY() == 0) {
#         i_label_number ++;
#         j_label_number = 0;
#       }
#       j_label_number++;
#       std::string label = oss.str();
#       h->GetXaxis()->SetBinLabel(i,label.c_str());
#       h->GetYaxis()->SetBinLabel(i,label.c_str());
#     }



# cov_matrix_mumom.SetMarkerColor(kWhite);
# cov_matrix_mumom.SetMarkerSize(1.6);
# cov_matrix_mumom.GetXaxis().SetTitle("Bin i");
# cov_matrix_mumom.GetXaxis().SetTitle("Bin j");
# cov_matrix_mumom.GetXaxis().CenterTitle();
# cov_matrix_mumom.GetYaxis().CenterTitle();
# cov_matrix_mumom
# cov_matrix_mumom
# cov_matrix_mumom.Draw("colz TEXT")

# cov_file = TFile("covariance_detector.root", "RECREATE");
# cov_file.cd();
# cov_matrix_onebin.Write("covariance_matrix_detector_onebin");
# cov_matrix_mumom.Write("covariance_matrix_detector_mumom");
# cov_matrix_muangle.Write("covariance_matrix_detector_muangle");
# cov_matrix_muangle_mumom.Write("covariance_matrix_detector_muangle_mumom");
# cov_matrix_poly_muangle_mumom.Write("covariance_matrix_poly_detector_muangle_mumom");
# cov_matrix_onebin_frac.Write("frac_covariance_matrix_detector_onebin");
# cov_matrix_mumom_frac.Write("frac_covariance_matrix_detector_mumom");
# cov_matrix_muangle_frac.Write("frac_covariance_matrix_detector_muangle");
# cov_matrix_muangle_mumom_frac.Write("frac_covariance_matrix_detector_muangle_mumom");
# cov_matrix_poly_muangle_mumom_frac.Write("frac_covariance_matrix_poly_detector_muangle_mumom");
# cov_file.Close();



# gStyle.SetPaintTextFormat("4.2f");
# c_muangle_mumom_poly = TCanvas()
# # cov_matrix_muangle_mumom_frac.SetMarkerColor(kWhite);
# cov_matrix_poly_muangle_mumom_frac.SetMarkerSize(1.1);
# cov_matrix_poly_muangle_mumom_frac.GetXaxis().SetTitle("Bin i");
# cov_matrix_poly_muangle_mumom_frac.GetYaxis().SetTitle("Bin j");
# cov_matrix_poly_muangle_mumom_frac.GetXaxis().CenterTitle();
# cov_matrix_poly_muangle_mumom_frac.GetYaxis().CenterTitle();
# cov_matrix_poly_muangle_mumom_frac.SetMaximum(2)
# cov_matrix_poly_muangle_mumom_frac.SetMinimum(-2)
# cov_matrix_poly_muangle_mumom_frac.Draw("colz TEXT")

# gStyle.SetPaintTextFormat("4.3f");
# c_mumom = TCanvas()
# cov_matrix_mumom.SetMarkerColor(kWhite);
# cov_matrix_mumom.SetMarkerSize(1.6);
# cov_matrix_mumom.GetXaxis().SetTitle("Bin i");
# cov_matrix_mumom.GetYaxis().SetTitle("Bin j");
# cov_matrix_mumom.GetXaxis().CenterTitle();
# cov_matrix_mumom.GetYaxis().CenterTitle();
# cov_matrix_mumom.Draw("colz TEXT")

# gStyle.SetPaintTextFormat("4.3f");
# c_muangle = TCanvas()
# cov_matrix_muangle.SetMarkerColor(kWhite);
# cov_matrix_muangle.SetMarkerSize(1.6);
# cov_matrix_muangle.GetXaxis().SetTitle("Bin i");
# cov_matrix_muangle.GetYaxis().SetTitle("Bin j");
# cov_matrix_muangle.GetXaxis().CenterTitle();
# cov_matrix_muangle.GetYaxis().CenterTitle();
# cov_matrix_muangle.Draw("colz TEXT")

# gStyle.SetPaintTextFormat("4.2f");
# c_muangle_mumom = TCanvas()
# cov_matrix_muangle_mumom.SetMarkerColor(kWhite);
# cov_matrix_muangle_mumom.SetMarkerSize(1.1);
# cov_matrix_muangle_mumom.GetXaxis().SetTitle("Bin ij");
# cov_matrix_muangle_mumom.GetYaxis().SetTitle("Bin mn");
# cov_matrix_muangle_mumom.GetXaxis().CenterTitle();
# cov_matrix_muangle_mumom.GetYaxis().CenterTitle();
# cov_matrix_muangle_mumom.Draw("colz")


double_diff_single_plot = True



costhetamu_ranges = ["-1.00 #leq cos(#theta_{#mu}^{reco}) < -0.50", "-0.50 #leq cos(#theta_{#mu}^{reco}) < 0.00", "0.00 #leq cos(#theta_{#mu}^{reco}) < 0.27",  "0.27 #leq cos(#theta_{#mu}^{reco}) < 0.45", "0.45 #leq cos(#theta_{#mu}^{reco}) < 0.62", "0.62 #leq cos(#theta_{#mu}^{reco}) < 0.76", "0.76 #leq cos(#theta_{#mu}^{reco}) < 0.86", "0.86 #leq cos(#theta_{#mu}^{reco}) < 0.94", "0.94 #leq cos(#theta_{#mu}^{reco}) < 1.00"]

labels = []

x_bins = eff_cv.GetNBinsX()
# horizontal_division = 2
# vertical_division = math.floor(x_bins / 2.)
# if (x_bins / 2. != math.floor(x_bins / 2.)): 
#   vertical_division = vertical_division + 1

# c_xsec_split = TCanvas("c_xsec_split", "multipads", 0, 45, 1006, 1150)
# c_xsec_split.Divide(2, 5, 0.02, 0.01)

c_xsec_split = TCanvas()

if double_diff_single_plot:
  c_xsec_split = TCanvas("c_xsec_split", "multipads", 0, 0, 1144,746)
  c_xsec_split.Divide(3, 3, 0.01, 0.01)

data_xsec = []
bkg = []
eff = []


uncertainty_data = []

bin_numbers = vector('int')()
for i in xrange(1, x_bins+1):
  eff.append(eff_cv.ProjectionY("eff_bs" + str(i), i, bin_numbers))
  bkg.append(bkg_cv.ProjectionY("bkg_bs" + str(i), i, bin_numbers))

  # h_unc = data_xsec[i-1].Clone("h_unc" + str(i))
  # for j in xrange(0, bin_numbers.size()): 
  #   h_unc.SetBinError(j+1, h_unc.GetBinContent(j+1) * math.sqrt(frac_covariance_data_muangle_mumom_h.GetBinContent(bin_numbers[j], bin_numbers[j])))
  # uncertainty_data.append(h_unc)

for i in xrange(1, x_bins+1):
  if double_diff_single_plot: 
    c_xsec_split.cd(i)

  gPad.SetBottomMargin(0.16);
  gPad.SetLeftMargin(0.18);
  gPad.SetRightMargin(0.03);
  gPad.SetTopMargin(0.06);

  # genie_xsec[i-1].SetTitle(costhetamu_ranges[i-1])
  eff[i-1].GetXaxis().SetTitle("p_{#mu}^{reco} [GeV]")
  eff[i-1].GetYaxis().SetTitle("#frac{d^{2}#sigma}{dp_{#mu}^{reco}dcos(#theta_{#mu}^{reco})} [10^{-38} #frac{cm^{2}}{GeV n}]")
  eff[i-1].GetXaxis().CenterTitle()
  eff[i-1].GetYaxis().CenterTitle()
  eff[i-1].GetXaxis().SetTitleOffset(0.92)
  eff[i-1].GetXaxis().SetTitleSize(0.07)
  eff[i-1].GetXaxis().SetLabelSize(0.06)
  eff[i-1].GetYaxis().SetTitleOffset(1.0)
  eff[i-1].GetYaxis().SetTitleSize(0.06)
  eff[i-1].GetYaxis().SetLabelSize(0.06)

  # if i == 1:
  #   genie_xsec[i-1].SetMinimum(-0.01)
  #   # genie_xsec[i-1].SetMaximum(0.45)
  # if i == 2:
  #   genie_xsec[i-1].SetMinimum(-0.03)
  #   # genie_xsec[i-1].SetMaximum(0.45)
  # if i == 3:
  #   genie_xsec[i-1].SetMinimum(-0.15)
  #   # xsec_tune1[i-1].SetMaximum(0.5)
  # if i == 4:
  #   genie_xsec[i-1].SetMinimum(-0.05)
  #   # xsec_tune1[i-1].SetMaximum(0.5)
  # if i == 6:
  #   genie_xsec[i-1].SetMinimum(-0.05)
  #   # xsec_tune1[i-1].SetMaximum(0.5)
  # if i == 7:
  #   genie_xsec[i-1].SetMinimum(0)
  #   # xsec_tune1[i-1].SetMaximum(2.5)
  # if i == 8:
  #   genie_xsec[i-1].SetMinimum(0)
  #   # xsec_tune1[i-1].SetMaximum(3)
  # if i == 9:
  #   genie_xsec[i-1].SetMinimum(0)
  #   # xsec_tune1[i-1].SetMaximum(3)

  # # genie_xsec[i-1].SetMinimum(-0.05)
  # genie_xsec[i-1].SetMaximum(genie_xsec[i-1].GetMaximum() * 1.6)
  # if i == 1:
  #   genie_xsec[i-1].SetMaximum(0.42)

  gStyle.SetTitleFontSize(0.07)
  gStyle.SetTitleStyle(0)

  line_size = 4

  eff[i-1].SetLineColor(kGreen+2)
  eff[i-1].SetFillColor(0)
  eff[i-1].SetLineWidth(line_size)

  bkg[i-1].SetLineColor(kBlue+1)
  bkg[i-1].SetFillColor(0)
  bkg[i-1].SetLineWidth(line_size)

  
  
  # eff[i-1].Draw("histo same")
  bkg[i-1].Draw("histo same")
  
  


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
    leg = TLegend(0.3424069,0.3726316,0.7063037,0.6926316);
    leg.SetBorderSize(0);
    leg.SetTextSize(0.05894737);
    leg.SetLineColor(1);
    leg.SetLineStyle(1);
    leg.SetLineWidth(1);
    leg.SetFillColor(0);
    leg.SetFillStyle(0);
    leg.AddEntry(eff[0],            "GENIE v2.12.2 + Emp. MEC"             )
    leg.AddEntry(bkg[0],         "GENIE v2.12.2 Alt."                   )
    
    leg.Draw()    


    # ub_label = plotting.get_mumangle_mumom_label(label_text)
    # ub_label.Draw();


  if not double_diff_single_plot:
    c_xsec_split.Modified();
    c_xsec_split.cd();
    c_xsec_split.Draw()
    c_xsec_split.SaveAs('Plots/bkg_eff_doublediff_' + str(i) +'.pdf')
    c_xsec_split.SaveAs('Plots/bkg_eff_doublediff_' + str(i) +'.C')


if double_diff_single_plot:
  c_xsec_split.cd(x_bins+1)
  leg = TLegend(0.1275766,0.3250297,0.7966395,0.6759589);
  leg.SetBorderSize(0);
  leg.SetTextSize(0.05894737);
  leg.SetLineColor(1);
  leg.SetLineStyle(1);
  leg.SetLineWidth(1);
  leg.SetFillColor(0);
  leg.SetFillStyle(0);
  leg.AddEntry(eff[0], "GENIE Default + Emp. MEC")
  leg.AddEntry(bkg[0], "GENIE Alt.")
  leg.Draw()  

  ub_label = TLatex(0.154, 0.73, "MicroBooNE #bf{Preliminary}");
  ub_label.SetNDC();
  ub_label.SetTextColor(kGray+2);
  ub_label.SetTextSize(0.10);
  ub_label.SetLineWidth(2);
  ub_label.SetTextFont(62);
  ub_label.Draw();  

  c_xsec_split.SaveAs("Plots/bkg_eff_doublediff.pdf")

raw_input("Please press enter to exit.")











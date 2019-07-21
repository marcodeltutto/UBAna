import sys, os
import math
import ROOT
from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")


all_files = []

def get_unpacked_xsec (name, mc=False):
  f_ubana = TFile('xsec_file_' + name + '.root')
  all_files.append(f_ubana)
  xsec_data_muangle_mumom_h = f_ubana.Get('xsec_poly_muangle_mumom_' + name)
  frac_covariance_data_muangle_mumom_h = f_ubana.Get('frac_covariance_matrix_poly_muangle_mumom_' + name)
  if mc:
    xsec_data_muangle_mumom_h = f_ubana.Get('xsec_poly_muangle_mumom_mc_' + name)
    # for i in xrange(0, 42):
    #   print xsec_data_muangle_mumom_h.GetBinContent(i+1)
    # print '-'


  x_bins = xsec_data_muangle_mumom_h.GetNBinsX()

  data_xsec = []
  uncertainty_data = []

  
  bin_numbers = ROOT.vector('int')()
  for i in xrange(1, x_bins+1):
    data_xsec.append(xsec_data_muangle_mumom_h.ProjectionY("data_bs" + str(i), i, bin_numbers))

    h_unc = data_xsec[i-1].Clone("h_unc" + str(i))
    for j in xrange(0, bin_numbers.size()): 
      # print 'bin number is', bin_numbers[j], '  - covariance is', math.sqrt(frac_covariance_data_muangle_mumom_h.GetBinContent(bin_numbers[j], bin_numbers[j]))
      h_unc.SetBinError(j+1, h_unc.GetBinContent(j+1) * math.sqrt(frac_covariance_data_muangle_mumom_h.GetBinContent(bin_numbers[j], bin_numbers[j])))
    uncertainty_data.append(h_unc)

  return data_xsec, uncertainty_data




def get_xsec_muangle (name, mc=False):
  f_ubana = TFile('xsec_file_' + name + '.root')
  all_files.append(f_ubana)
  xsec_data_muangle_h = f_ubana.Get('xsec_muangle_' + name)
  frac_covariance_data_muangle_h = f_ubana.Get('frac_covariance_matrix_muangle_' + name)
  if mc:
    xsec_data_muangle_h = f_ubana.Get('xsec_muangle_mc_' + name)

  
  # Construct syst histo muangle
  uncertanties_muangle_h = xsec_data_muangle_h.Clone("uncertanties_muangle_h")
  for i in xrange(0, uncertanties_muangle_h.GetNbinsX()):
    uncertanties_muangle_h.SetBinError(i+1, uncertanties_muangle_h.GetBinContent(i+1) * math.sqrt(frac_covariance_data_muangle_h.GetBinContent(i+1, i+1)))
  

  return xsec_data_muangle_h, uncertanties_muangle_h





def get_chi2 (name):

  f_ubana = TFile('xsec_file_' + name + '.root')
  all_files.append(f_ubana)
  xsec_data_muangle_mumom_h = f_ubana.Get('xsec_poly_muangle_mumom_' + name)
  xsec_muangle_mumom_reco_genie_h = f_ubana.Get('xsec_poly_muangle_mumom_mc_' + name)

  # Tune 3 prediction comes from tune3 file
  f_ubana_t3 = ROOT.TFile("xsec_file_cv_tune3.root");
  xsec_muangle_mumom_reco_genie_tune3_h = f_ubana_t3.Get('xsec_poly_muangle_mumom_mc_cv_tune3')

  # Coveriance matrix always comes from cv file
  f_ubana_cv = TFile('xsec_file_' + 'cv' + '.root')
  tot_covariance_data_muangle_mumom_h = f_ubana_cv.Get('tot_covariance_matrix_poly_muangle_mumom_' + 'cv') 
  
  covariance_data_muangle_mumom_m = TMatrix()
  covariance_data_muangle_mumom_m.Clear()
  covariance_data_muangle_mumom_m.ResizeTo(tot_covariance_data_muangle_mumom_h.GetNbinsX(), tot_covariance_data_muangle_mumom_h.GetNbinsX())
  for i in xrange(0, tot_covariance_data_muangle_mumom_h.GetNbinsX()):
    for j in xrange(0, tot_covariance_data_muangle_mumom_h.GetNbinsY()):
      covariance_data_muangle_mumom_m[i][j] = tot_covariance_data_muangle_mumom_h.GetBinContent(i+1, j+1)
      # if i != j:  covariance_data_muangle_mumom_m[i][j] = 0
      # print 'i', i, ', j', j, ', cov ', covariance_data_muangle_mumom_m[i][j]


  covariance_data_muangle_mumom_m_inverse = covariance_data_muangle_mumom_m.Invert()

  chi2_genie = 0.
  chi2_genie_t3 = 0. 

  for i in xrange(0, tot_covariance_data_muangle_mumom_h.GetNbinsX()):
    for j in xrange(0, tot_covariance_data_muangle_mumom_h.GetNbinsY()):
      chi2_genie = chi2_genie +  (xsec_data_muangle_mumom_h.GetBinContent(i+1) - xsec_muangle_mumom_reco_genie_h.GetBinContent(i+1)) * covariance_data_muangle_mumom_m_inverse[i][j] * (xsec_data_muangle_mumom_h.GetBinContent(j+1) - xsec_muangle_mumom_reco_genie_h.GetBinContent(j+1))
      chi2_genie_t3 = chi2_genie_t3 +  (xsec_data_muangle_mumom_h.GetBinContent(i+1) - xsec_muangle_mumom_reco_genie_tune3_h.GetBinContent(i+1)) * covariance_data_muangle_mumom_m_inverse[i][j] * (xsec_data_muangle_mumom_h.GetBinContent(j+1) - xsec_muangle_mumom_reco_genie_tune3_h.GetBinContent(j+1))
      
  print 'Chi2 (tune1) for ', name, 'is', chi2_genie 
  print 'Chi2 (tune3) for ', name, 'is', chi2_genie_t3




# def get_histo(name):
#   f_ubana = TFile('xsec_file_' + name + '.root')
#   xsec_muangle_mumom_mc_h = f_ubana.Get('xsec_poly_muangle_mumom_mc_' + name)
#   return xsec_muangle_mumom_mc_h





samples = ['cv', # central value
           # 'split_sample_anode_anodevtx',  # Vertex in the anode side, pointing at the anode, 0
           # 'split_sample_up_anodevtx', # Vertex in the anode side, pointing up, 1
           # 'split_sample_down_anodevtx', # Vertex in the anode side, pointing down, 2
           # 'split_sample_cathode_anodevtx', # Vertex in the anode side, pointing at the acathode, 3
           'split_sample_anode_cathodevtx', # Vertex in the cathode side, pointing at the anode, 4
           'split_sample_up_cathodevtx', # Vertex in the cathode side, pointing up, 5
           'split_sample_down_cathodevtx', # Vertex in the cathode side, pointing down, 6
           'split_sample_cathode_cathodevtx', # Vertex in the cathode side, pointing at the cathode, 7
           # 'split_sample_anodevtx', # Vertex in the anode side, 8
           # 'split_sample_cathodevtx', # Vertex in the cathode side, 9
           # 'split_sample_anode', # Pointing at the anode, 10
           # 'split_sample_cathode', # Pointing at the cathode, 11
           # 'split_sample_right', # pointing right (to anode), 12
           # 'split_sample_left', # poining left (to cathode), 13
           # 'model0', # 0.95 QE, 0.85 MEC, 0.75 RES, 0.85 DIS, 12
           # 'model1', # 0.90 QE, 1.00 MEC, 0.00 RES, 0.85 DIS, 13
           # 'model2' # 1.00 QE, 0.00 MEC, 1.50 RES, 1.00 DIS, 14
           ] 

# samples = ['split_sample_anode_anodevtx'] # Pointing at the cathode, 11

all_xsec = []
all_xsec.append(get_unpacked_xsec('cv', mc=True)[0])
all_xsec.append(get_unpacked_xsec('cv_tune3', mc=True)[0])
for name in samples:
  all_xsec.append(get_unpacked_xsec(name)[0])
  get_chi2(name)

unc = get_unpacked_xsec('cv')[1]



costhetamu_ranges = ["-1.00 #leq cos(#theta_{#mu}^{reco}) < -0.50", "-0.50 #leq cos(#theta_{#mu}^{reco}) < 0.00", "0.00 #leq cos(#theta_{#mu}^{reco}) < 0.27",  "0.27 #leq cos(#theta_{#mu}^{reco}) < 0.45", "0.45 #leq cos(#theta_{#mu}^{reco}) < 0.62", "0.62 #leq cos(#theta_{#mu}^{reco}) < 0.76", "0.76 #leq cos(#theta_{#mu}^{reco}) < 0.86", "0.86 #leq cos(#theta_{#mu}^{reco}) < 0.94", "0.94 #leq cos(#theta_{#mu}^{reco}) < 1.00"]
colors = [kGreen +2, kBlue, kBlack, kRed+2, kOrange+2, 6, 29]
counter = -1

labels = []
histo_list = []

x_bins = 9
horizontal_division = 2
vertical_division = math.floor(x_bins / 2.)
if (x_bins / 2. != math.floor(x_bins / 2.)): 
  vertical_division = vertical_division + 1

# c_xsec_split = TCanvas("c_xsec_split", "multipads", 0, 45, 1006, 1150)
# c_xsec_split.Divide(2, 5, 0.02, 0.01)

c_xsec_split = TCanvas("c_xsec_split", "multipads", 0, 0, 1144,746)
c_xsec_split.Divide(3, 3, 0.01, 0.01)



for i in xrange(1, x_bins+1):
  c_xsec_split.cd(i)
  
  # gPad.SetBottomMargin(0.15);
  # gPad.SetLeftMargin(0.18);
  # gPad.SetRightMargin(0.14);
  # gPad.SetTopMargin(0.13);

  gPad.SetBottomMargin(0.16);
  gPad.SetLeftMargin(0.18);
  gPad.SetRightMargin(0.03);
  gPad.SetTopMargin(0.06);


  counter = -1
  for j, h in enumerate(all_xsec):
    counter += 1
    # h.SetTitle(costhetamu_ranges[i-1])
    h[i-1].GetXaxis().SetTitle("p_{#mu}^{reco} [GeV]")
    h[i-1].GetYaxis().SetTitle("#frac{d^{2}#sigma}{dp_{#mu}^{reco}dcos(#theta_{#mu}^{reco})} [10^{-38} #frac{cm^{2}}{GeV n}]")
    h[i-1].GetXaxis().CenterTitle()
    h[i-1].GetYaxis().CenterTitle()
    h[i-1].GetXaxis().SetTitleOffset(0.92)
    h[i-1].GetXaxis().SetTitleSize(0.07)
    h[i-1].GetXaxis().SetLabelSize(0.06)
    h[i-1].GetYaxis().SetTitleOffset(1.0)
    h[i-1].GetYaxis().SetTitleSize(0.06)
    h[i-1].GetYaxis().SetLabelSize(0.06)  

    h[i-1].SetMinimum(-0.05)
    h[i-1].SetMaximum(h[i-1].GetMaximum() * 1.6)

    if j == 0 or j == 1:
      h[i-1].SetLineStyle(7)

    
    # if i == 1:
    #   h[i-1].SetMinimum(-0.01)
    #   h[i-1].SetMaximum(0.45)
    # if i == 2:
    #   h[i-1].SetMinimum(-0.03)
    #   h[i-1].SetMaximum(0.45)
    # if i == 3:
    #   h[i-1].SetMinimum(-0.15)
    #   # h[i-1].SetMaximum(0.5)
    # if i == 6:
    #   h[i-1].SetMinimum(-0.05)
    #   h[i-1].SetMaximum(0.5)
    # if i == 7:
    #   h[i-1].SetMinimum(0)
    #   h[i-1].SetMaximum(2.5)
    # if i == 8:
    #   h[i-1].SetMinimum(0)
    #   h[i-1].SetMaximum(3)
    # if i == 9:
    #   h[i-1].SetMinimum(0)
    #   h[i-1].SetMaximum(3)  

    gStyle.SetTitleFontSize(0.07)
    gStyle.SetTitleStyle(0)  

    h[i-1].SetLineColor(colors[counter])
    h[i-1].SetFillColorAlpha(colors[counter], 0.3)  

    # genie_t3_xsec[i-1].SetLineColor(ROOT.kBlue+1)
    # genie_t3_xsec[i-1].SetFillColor(0)
    # gibuu_xsec[i-1].SetLineColor(ROOT.kOrange+1)
    # gibuu_xsec[i-1].SetFillColor(0)
    # gibuu_xsec[i-1].SetLineStyle(9)
    # nuwro_xsec[i-1].SetLineColor(46)
    # nuwro_xsec[i-1].SetFillColor(0)
    # data_xsec[i-1].SetMarkerStyle(20);
    # data_xsec[i-1].SetMarkerSize(1.2);
    unc[i-1].SetMarkerStyle(20);
    unc[i-1].SetMarkerSize(0.1);
    
    # all_xsec[i-1].Draw("E2");
    # genie_xsec_main =  all_xsec[i-1].Clone("genie_xsec_main");
    # genie_xsec_main.SetLineColor(kGreen+2);
    # genie_xsec_main.SetFillColor(0);
    # genie_xsec_main.Draw("histo same");  

    # h[i-1].Draw("histo E1 same")
    if j!=0 or j!=1: 
      h[i-1].Draw("E2 same")
    main = h[i-1].Clone("bullshit")
    main.SetFillColor(0)
    main.SetLineColor(colors[counter])
    main.Draw('histo same')
    histo_list.append(main)


    # genie_t3_xsec[i-1].Draw("histo same")
    # gibuu_xsec[i-1].Draw("histo same")
    # nuwro_xsec[i-1].Draw("histo same")
    # data_xsec[i-1].Draw("E1 X0 same")
    unc[i-1].Draw("E1 X0 same")  

    # the_min = min(all_xsec[i-1].GetMinimum(), gibuu_xsec[i-1].GetMinimum());
    # the_max = max(all_xsec[i-1].GetMaximum(), gibuu_xsec[i-1].GetMaximum());  

    # all_xsec[i-1].SetMinimum(the_min - abs(the_min) * 0.4);
    # all_xsec[i-1].SetMaximum(the_max * 1.5);



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
    for i, h in enumerate(all_xsec):
      if i == 0:
        leg.AddEntry(h[0], 'GENIE Default')
      elif i == 1:
        leg.AddEntry(h[0], 'GENIE Alternative')
      else:
        leg.AddEntry(h[0], samples[i-2])
    
    leg.Draw()    

    ub_label = TLatex(0.92,0.71, "MicroBooNE #bf{1.6e20 POT}");
    ub_label.SetNDC();
    ub_label.SetTextColor(kGray+2);
    ub_label.SetTextSize(0.07);
    ub_label.SetTextAlign(32);
    ub_label.SetLineWidth(2);
    ub_label.SetTextFont(62);
    ub_label.Draw();

  # c_xsec_split.Modified();
  # c_xsec_split.cd();
  # c_xsec_split.Draw()
  # c_xsec_split.SaveAs('double_diff_' + str(i) +'.pdf')


# c_xsec_split.cd(x_bins+1)
# leg = TLegend(0.1275766,0.3250297,0.7966395,0.6759589);
# leg.SetBorderSize(0);
# leg.SetTextSize(0.08402531);
# leg.SetLineColor(1);
# leg.SetLineStyle(1);
# leg.SetLineWidth(1);
# leg.SetFillColor(0);
# leg.SetFillStyle(0);
# leg.AddEntry(genie_xsec[0], "GENIE Default + Emp. MEC")
# leg.AddEntry(genie_t3_xsec[0], "GENIE Alternative")
# leg.AddEntry(gibuu_xsec[0], "GiBUU 2019")
# leg.AddEntry(nuwro_xsec[0], "NuWro 18.02.1")
# leg.AddEntry(data_xsec[0],  "MicroBooNE Data (Stat. #oplus Syst. Unc.)", "ep")
# leg.Draw()

# ub_label = TLatex(0.154, 0.73, "MicroBooNE #bf{Preliminary}");
# ub_label.SetNDC();
# ub_label.SetTextColor(kGray+2);
# ub_label.SetTextSize(0.10);
# ub_label.SetLineWidth(2);
# ub_label.SetTextFont(62);
# ub_label.Draw();

# c_xsec_split.SaveAs("test.pdf")











all_xsec_muangle = []
all_xsec_muangle.append(get_xsec_muangle('cv', mc=True)[0])
all_xsec_muangle.append(get_xsec_muangle('cv_tune3', mc=True)[0])
for name in samples:
  all_xsec_muangle.append(get_xsec_muangle(name)[0])

unc_muangle = get_xsec_muangle('cv')[1]


c3 = TCanvas()
c3.SetBottomMargin(0.12)
c3.SetLeftMargin(0.12)


for j, h in enumerate(all_xsec_muangle):

  h.SetLineColor(colors[j])
  h.SetFillColorAlpha(colors[j], 0.3)
  h.SetLineWidth(2)
  h.GetXaxis().SetTitle("cos(#theta^{reco}_{#mu})")
  h.GetYaxis().SetTitle("d#sigma/dcos(#theta^{reco}_{#mu}) [10^{-38} cm^{2}]")

  h.SetMinimum(0)
  h.SetMaximum(2.9)

  if j == 0 or j == 1:
    h.SetLineStyle(7)

  if j!=0 or j!=1: 
      h.Draw("E2 same")
  main = h.Clone("bullshit")
  main.SetFillColor(0)
  main.SetLineColor(colors[j])
  main.Draw('histo same')
  histo_list.append(main)

  # h.Draw("histo same")

# xsec_muangle_reco_genie_tune3_h.SetLineColor(ROOT.kBlue+1)
# xsec_muangle_reco_genie_tune3_h.SetLineWidth(2)
# xsec_muangle_reco_genie_tune3_h.Draw("histo same")
# xsec_muangle_reco_gibuu_h.SetLineColor(ROOT.kOrange+1)
# xsec_muangle_reco_gibuu_h.SetLineWidth(2)
# xsec_muangle_reco_gibuu_h.SetLineStyle(9)
# xsec_muangle_reco_gibuu_h.Draw("histo same")
# xsec_muangle_reco_nuwro_h.SetLineColor(46)
# xsec_muangle_reco_nuwro_h.SetLineWidth(2)
# xsec_muangle_reco_nuwro_h.Draw("histo same")
# xsec_data_muangle_h.SetMarkerStyle(kFullCircle)
# xsec_data_muangle_h.SetMarkerSize(0.6)
# xsec_data_muangle_h.Draw("E1 X0 same")
unc_muangle.SetMarkerStyle(kFullCircle)
unc_muangle.SetMarkerSize(0.2)
unc_muangle.Draw("E1 X0 same")

leg_mangle = TLegend(0.2048711,0.4968421,0.4154728,0.7073684)
leg_mangle.SetBorderSize(0);
leg_mangle.SetTextSize(0.04631579);
leg_mangle.SetLineColor(1);
leg_mangle.SetLineStyle(1);
leg_mangle.SetLineWidth(1);
leg_mangle.SetFillColor(0);
leg_mangle.SetFillStyle(0);
for i, h in enumerate(all_xsec_muangle):
  if i == 0:
    leg_mangle.AddEntry(h, 'GENIE Default')
  elif i == 1:
    leg_mangle.AddEntry(h, 'GENIE Alternative')
  else:
    leg_mangle.AddEntry(h, samples[i-2])
leg_mangle.Draw()



ub_label_muangle = TLatex(0.2077364,0.7368421,"MicroBooNE #bf{Preliminary}");
ub_label_muangle.SetNDC();
ub_label_muangle.SetTextColor(kGray+2);
ub_label_muangle.SetTextSize(0.04631579);
ub_label_muangle.SetLineWidth(2);
ub_label_muangle.SetTextFont(62);
ub_label_muangle.Draw();

c3.SaveAs("xsec_muangle.pdf")









raw_input("Please press enter to exit.")

import sys, os, math
import ROOT
from ROOT import *
from prettytable import PrettyTable
from prettytable import from_csv
# gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from tools import smearing, chi2, plotting

def generate_simple_txt_file(matrix, name = "smearing_matrix.txt", n_bins = 42):
  f = open(name,"w+")

  # f.write(' -, ')

  # for i in range(1, n_bins + 1):
  #   f.write('\"%d\"' % i)
  #   if i != n_bins:
  #     f.write(', ')
  # f.write('\n')

  for i in range(1, n_bins + 1):
    # f.write('\"%d\", ' % i)
    for j in range(1, n_bins + 1):
      f.write('%.4E' % matrix.GetBinContent(i, j))
      if j != n_bins:
        f.write(' ')
    f.write('\n')

  f.close()

  print 'Generated file with name', name

def generate_txt_file(matrix, name = "smearing_matrix.csv", n_bins = 42):
  f = open(name,"w+")

  f.write(' -, ')

  for i in range(1, n_bins + 1):
    f.write('\"%d\"' % i)
    if i != n_bins:
      f.write(', ')
  f.write('\n')

  for i in range(1, n_bins + 1):
    f.write('\"%d\", ' % i)
    for j in range(1, n_bins + 1):
      f.write('%.4E' % matrix.GetBinContent(i, j))
      if j != n_bins:
        f.write(', ')
    f.write('\n')

  f.close()


  x = PrettyTable()

  with open(name, "r") as fp: 
      x = from_csv(fp)


  w = open(name + '.txt',"w+")
  w.write(str(x))
  w.close()

  print 'Generated file with name', name



def make_simple_histo(h, name, n_bins=42):

  simple_h = TH1D(name, name+';Bin Number;#frac{d^{2}#sigma}{dp_{#mu}^{reco}dcos(#theta_{#mu}^{reco})} [10^{-38} #frac{cm^{2}}{GeV n}]', n_bins, 0, n_bins)

  for i in xrange(1, n_bins+1):
    simple_h.SetBinContent(i, h.GetBinContent(i))
    simple_h.SetBinError(i, h.GetBinError(i))

  return simple_h


def save_xsec_to_txt(h, name, n_bins=42):

  f = open(name,"w+")
  for i in xrange(1, n_bins+1):
    f.write('%.4E ' % h.GetBinContent(i))




f_ubana = ROOT.TFile("./xsec_file_cv.root")

xsec = f_ubana.Get("xsec_poly_muangle_mumom_cv")
xsec_tune1 = f_ubana.Get("xsec_poly_muangle_mumom_mc_cv")
# xsec_tune3 = f_ubana.Get("xsec_poly_muangle_mumom_alt_mc_cv")
cov_tot = f_ubana.Get("tot_covariance_matrix_poly_muangle_mumom_cv")
smearing_m = f_ubana.Get("smearing_matrix_muangle_mumom_poly_cv")

f_tune3f = ROOT.TFile("../../../XSecCompare/GENIE/genie_histograms_tune3bugfix.root")
f_gibuu  = ROOT.TFile("../../../XSecCompare/GiBUU/gibuu_histograms.root")
f_nuwro  = ROOT.TFile("../../../XSecCompare/NuWro/nuwro_histograms_19.02.1.root")
tune3f_true = f_tune3f.Get("xsec_muangle_mumom_true_genie_h")
gibuu_true = f_gibuu.Get("xsec_muangle_mumom_true_gibuu_h")
nuwro_true = f_nuwro.Get("xsec_muangle_mumom_true_nuwro_h")


xsec_tune3f = smearing.smear_double(tune3f_true, smearing_m)
xsec_gibuu  = smearing.smear_double(gibuu_true, smearing_m)
xsec_nuwro  = smearing.smear_double(nuwro_true, smearing_m)


# print smearing_m[1][1] 
smearing_h = TH2D('smearing_h', '', 43, 0, 43, 43, 0, 43)
for i in range(0, 43): 
  for j in range(0, 43): 
    smearing_h.SetBinContent(i+1, j+1, smearing_m[i][j])

# generate_txt_file(cov_tot, 'covariance_matrix.csv', 42)
# generate_txt_file(smearing_h, 'smearing_matrix.csv', 43)
generate_simple_txt_file(cov_tot, 'microboone_cc_inclusive_covariance_matrix.txt', 42)
generate_simple_txt_file(smearing_h, 'microboone_cc_inclusive_smearing_matrix.txt', 43)

h_data = make_simple_histo(xsec, 'Data Cross Section')
h_tune1 = make_simple_histo(xsec_tune1, 'GENIE v2.12.2 + Emp. MEC Cross Section')
# h_tune3 = make_simple_histo(xsec_tune3, 'GENIE Alternative Cross Section')
h_tune3f = make_simple_histo(xsec_tune3f, 'GENIE v3.00.04 G1810a0211a Cross Section')
h_gibuu = make_simple_histo(xsec_gibuu, 'GiBUU 2019 Cross Section')
h_nuwro = make_simple_histo(xsec_nuwro, 'NuWro 19.02.1 Cross Section')

save_xsec_to_txt(xsec, 'xsec_data.txt')
save_xsec_to_txt(xsec_tune1, 'xsec_tune1.txt')
save_xsec_to_txt(xsec_tune3f, 'xsec_tune3.txt')


f_out = TFile('microboone_numu_cc_inclusive.root', 'recreate' )
cov_tot.Write('covariance_matrix')
smearing_h.Write('smearing_matrix')
h_data.Write('xsec_data')
h_tune1.Write('xsec_genie_v2')
# h_tune3.Write('xsec_genie_alternative')
h_tune3f.Write('xsec_genie_v3')
h_gibuu.Write('xsec_gibuu')
h_nuwro.Write('xsec_nuwro')

print 'Done.'


c = TCanvas()
h_data.Draw('histo')
h_tune1.Draw('histo same')
h_tune3f.Draw('histo same')

raw_input("Please press enter to exit.")

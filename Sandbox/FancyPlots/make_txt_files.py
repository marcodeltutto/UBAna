import sys, os, math
import ROOT
from ROOT import *
from prettytable import PrettyTable
from prettytable import from_csv
# gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")



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


  w = open(name,"w+")
  w.write(str(x))
  w.close()

  print 'Generated file with name', name







f_ubana = ROOT.TFile("./xsec_file_cv.root")

xsec = f_ubana.Get("xsec_poly_muangle_mumom_cv")
cov_tot = f_ubana.Get("tot_covariance_matrix_poly_muangle_mumom_cv")
smearing_m = f_ubana.Get("smearing_matrix_muangle_mumom_poly_cv")

# print smearing_m[1][1] 
smearing_h = TH2D('smearing_h', '', 43, 0, 43, 43, 0, 43)
for i in range(0, 43): 
  for j in range(0, 43): 
    smearing_h.SetBinContent(i+1, j+1, smearing_m[i][j])

generate_txt_file(cov_tot, 'covariance_matrix.csv', 42)
generate_txt_file(smearing_h, 'smearing_matrix.csv', 43)


f_out = TFile( 'microboone_numu_cc_inclusive.root', 'recreate' )
cov_tot.Write('covariance_matrix')
smearing_h.Write('smearing_matrix')


print 'Done.'



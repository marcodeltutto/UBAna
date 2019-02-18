import sys, os, math
import ROOT
from ROOT import *
from prettytable import PrettyTable
from prettytable import from_csv
# gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

f_ubana = ROOT.TFile("./xsec_file_cv.root")

xsec = f_ubana.Get("xsec_poly_muangle_mumom_cv")
cov_tot = f_ubana.Get("tot_covariance_matrix_poly_muangle_mumom_cv")


f = open("smearing_matrix.csv","w+")

f.write(' -, ')

n_bins = 42

for i in range(1, n_bins + 1):
  f.write('\"%d\"' % i)
  if i != n_bins:
    f.write(', ')
f.write('\n')

for i in range(1, n_bins + 1):
  f.write('\"%d\", ' % i)
  for j in range(1, n_bins + 1):
    f.write('%.4E' % cov_tot.GetBinContent(i, j))
    if j != n_bins:
      f.write(', ')
  f.write('\n')

f.close()


x = PrettyTable()

with open("smearing_matrix.csv", "r") as fp: 
    x = from_csv(fp)

# print(x)

w = open("smearing_matrix.txt","w+")
w.write(str(x))
w.close()

print 'Done.'



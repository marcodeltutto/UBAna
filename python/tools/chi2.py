import ROOT
import array
from ROOT import *
import sys, os, math


def get_chi2(xsec_data, xsec_mc, cov_matrix_h, without_n=-1, up_to_n=-1, without_corr=False):
  
  chi2 = 0.

  cov_matrix_m = TMatrix()
  cov_matrix_m.Clear()
  cov_matrix_m.ResizeTo(cov_matrix_h.GetNbinsX(), cov_matrix_h.GetNbinsX())
  for i in xrange(0, cov_matrix_h.GetNbinsX()):
    for j in xrange(0, cov_matrix_h.GetNbinsY()):
      cov_matrix_m[i][j] = cov_matrix_h.GetBinContent(i+1, j+1)
      if without_corr and i != j:  cov_matrix_m[i][j] = 0
      # print 'i', i, ', j', j, ', cov ', cov_matrix_m[i][j]

  inverse_cov_matrix = cov_matrix_m.Invert()

  test_37 = 0
  test_42 = 0
  test_both = 0
  for i in xrange(0, cov_matrix_h.GetNbinsX()):
    for j in xrange(0, cov_matrix_h.GetNbinsY()):
      chi2_contribution = (xsec_data.GetBinContent(i+1) - xsec_mc.GetBinContent(i+1)) * inverse_cov_matrix[i][j] * (xsec_data.GetBinContent(j+1) - xsec_mc.GetBinContent(j+1))

      # print i+1, j+1
      # if i+1 == 37 or j+1 == 37 or i+1 == 42 or j+1 == 42:
      #   # continue
      #   print '[both] adding', chi2_contribution
      #   test_both += chi2_contribution
      # if i+1 == 42 or j+1 == 42:
      #   print '[42] adding', chi2_contribution
      #   test_42 += chi2_contribution
      # if i+1 == 37 or j+1 == 37:
      #   # print i+1, j+1, 'chi2 =', chi2_contribution
      #   print '[37] adding', chi2_contribution
      #   test_37 += chi2_contribution

      if without_n != -1 and (i+1 == without_n or j+1 == without_n):
        continue
      if up_to_n != -1 and (i+1 > up_to_n or j+1 > up_to_n):
        continue

      chi2 += chi2_contribution
    
  # print 'test_37', test_37
  # print 'test_42', test_42
  # print 'test_both', test_both
  return chi2


def get_chi2_stat(xsec_data, xsec_mc, without_n=-1, up_to_n=-1, without_corr=False):

  cov_matrix_h = TH2D('cov_matrix_h', '', xsec_data.GetNumberOfBins(), 0, xsec_data.GetNumberOfBins(), xsec_data.GetNumberOfBins(), 0, xsec_data.GetNumberOfBins())

  for i in xrange(0, xsec_data.GetNumberOfBins()):
    cov_matrix_h.SetBinContent(i+1, i+1, xsec_data.GetBinError(i+1)*xsec_data.GetBinError(i+1))

  return get_chi2(xsec_data, xsec_mc, cov_matrix_h, without_n, up_to_n, without_corr)



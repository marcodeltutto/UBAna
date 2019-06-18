import ROOT
import array
from ROOT import *
import sys, os, math


def smear(xsec_true_h, smearing_m):
  # print 'nrows', smearing_m.GetNrows()
  # print 'ncols', smearing_m.GetNcols()
  # print 'NbinsX', xsec_true_h.GetNbinsX()
  xsec_true_v = TMatrix()
  xsec_true_v.Clear()
  xsec_true_v.ResizeTo(xsec_true_h.GetNbinsX(), 1)

  for i in xrange(1, xsec_true_h.GetNbinsX()+1):
    xsec_true_h.SetBinContent(i, xsec_true_h.GetBinContent(i) * xsec_true_h.GetBinWidth(i))

  for i in xrange(1, xsec_true_h.GetNbinsX()+1):
    xsec_true_v[i-1][0] = xsec_true_h.GetBinContent(i);

  xsec_reco_v  = TMatrix()
  xsec_reco_v.Clear()
  xsec_reco_v.ResizeTo(xsec_true_h.GetNbinsX(), 1)


  for i in xrange(0, xsec_true_h.GetNbinsX()):
    xsec_reco_v[i][0] = 0
    for j in xrange(0, xsec_true_h.GetNbinsX()):
      # print 'i =', i ,', j =', j, ' => S =', smearing_m[i][j]
      xsec_reco_v[i][0] += smearing_m[i][j] * xsec_true_v[j][0] 


  xsec_reco_h = xsec_true_h.Clone("xsec_reco_h")
  for i in xrange(1, xsec_true_h.GetNbinsX()+1):
    xsec_reco_h.SetBinContent(i, xsec_reco_v[i-1][0])
    xsec_reco_h.SetBinError(i, xsec_true_h.GetBinError(i)) # FIXME just copy stat uncertainties for now

  # Restore bin widths
  for i in xrange(1, xsec_reco_h.GetNbinsX()+1):
    xsec_true_h.SetBinContent(i, xsec_true_h.GetBinContent(i) / xsec_true_h.GetBinWidth(i))
    xsec_reco_h.SetBinContent(i, xsec_reco_h.GetBinContent(i) / xsec_reco_h.GetBinWidth(i))

  return xsec_reco_h



def smear_double(xsec_true_h, smearing_m):
  # print 'nrows', smearing_m.GetNrows()
  # print 'ncols', smearing_m.GetNcols()
  # print 'NbinsX', xsec_true_h.GetNbinsX()
  xsec_true_v = TMatrix()
  xsec_true_v.Clear()
  xsec_true_v.ResizeTo(xsec_true_h.GetNumberOfBins(), 1)

  for i in xrange(1, xsec_true_h.GetNumberOfBins()+1):
    xsec_true_h.SetBinContent(i, xsec_true_h.GetBinContent(i) * xsec_true_h.GetBinWidth(i))
    # print xsec_true_h.GetBinWidth(i), ', '
    
  # print '---------------'

  for i in xrange(1, xsec_true_h.GetNumberOfBins()+1):
    xsec_true_v[i-1][0] = xsec_true_h.GetBinContent(i);

  xsec_reco_v  = TMatrix()
  xsec_reco_v.Clear()
  xsec_reco_v.ResizeTo(xsec_true_h.GetNumberOfBins(), 1)


  for i in xrange(0, xsec_true_h.GetNumberOfBins()):
    xsec_reco_v[i][0] = 0
    for j in xrange(0, xsec_true_h.GetNumberOfBins()):
      # print 'i =', i ,', j =', j, ' => S =', smearing_m[i][j]
      xsec_reco_v[i][0] += smearing_m[i][j] * xsec_true_v[j][0]


  xsec_reco_h = xsec_true_h.Clone("xsec_reco_h")
  for i in xrange(1, xsec_true_h.GetNumberOfBins()+1):
    xsec_reco_h.SetBinContent(i, xsec_reco_v[i-1][0])
    xsec_reco_h.SetBinError(i, xsec_true_h.GetBinError(i) * xsec_true_h.GetBinWidth(i)) # FIXME just copy stat uncertainties for now

  # Restore bin widths
  xsec_true_h.Scale(1.0, "width");
  xsec_reco_h.Scale(1.0, "width");

  return xsec_reco_h
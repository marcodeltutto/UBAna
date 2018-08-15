#!/usr/bin/env python


import os,sys,string, time
import ROOT
from math import *
from ROOT import TTree, TObject, TFile, gDirectory, TH1D, TH2D, TH3D, TCanvas, gROOT, TGaxis, gStyle, TColor, TLegend, THStack, TChain
#from ROOT import *
from array import array
from glob import glob
import numpy

# Importing rootlogon.C
ROOT.gROOT.SetMacroPath('/Users/deltutto/');
ROOT.gROOT.Macro( os.path.expanduser( 'rootlogon.C' ) )

# Opening root file
fname = glob("/Users/deltutto/CCInclusiveFiles/Input/DetSyst/ubxsec_output_mc_bnbcosmic_cherenkov_ubcodev06_26_01__v3.root") # Dirt (in cryo only, no MCParticle filter, no Photon filter)
#print "Input file: ", fname

# outfile = "dirt_analysed_dirt_onlyincryo_nophotonfilter.root"

# Creating TChain
chain    = TChain("NeutrinoMCFlash/tree")
for f in fname: 
  chain.Add(f)
           
# Printing the number of entries
entries    = chain.GetEntries()
print "Number of entries in the tree: ", entries

pe_sc = TH1D("pe_sc", ";Total MCFlash PE;Entries", 600, 0, 5000)
pe_ch = TH1D("pe_ch", ";Total MCFlash PE;Entries", 600, 0, 5000)
pe_ratio = TH1D("pe_ratio", ";Total MCFlash PE (Ch/Sc);Entries", 100, 0, 1)

time_sc = TH1D("time_sc", ";G4 Photon Time [ns];Entries", 600, 0, 10000)
time_ch = TH1D("time_ch", ";G4 Photon Time [ns];Entries", 600, 0, 10000)


# entries = 1000

for jentry in xrange( entries ):
  entry = chain.GetEntry( jentry )

  if chain.pe_scintillation == 0:
    continue

  pe_sc.Fill(chain.pe_scintillation)
  pe_ch.Fill(chain.pe_cherenkov)

  pe_ratio.Fill(float(chain.pe_cherenkov) / float(chain.pe_scintillation))
  # print "ratio:", float(c) / float(s)

  # length =  chain.scintillation_time_v.size()
  # for i in xrange(0, len(chain.scintillation_time_v.size())):
  #   time_sc.Fill(chain.scintillation_time_v[i]

  min_t = numpy.min(chain.scintillation_time_v)
  for t in chain.scintillation_time_v:
    time_sc.Fill(t - min_t)

  if (chain.cherenkov_time_v.size() != 0):
    min_t = numpy.min(chain.cherenkov_time_v)
    for t in chain.cherenkov_time_v:
      time_ch.Fill(t - min_t)


c1 = TCanvas()
pe_sc.SetLineColor(ROOT.kGreen+2)
# pe_sc.SetFillColor(ROOT.kGreen+2)
pe_ch.SetLineColor(ROOT.kBlue+2)
# pe_ch.SetFillColor(ROOT.kBlue+2)

pe_sc.DrawNormalized("histo")
pe_ch.DrawNormalized("histo same")


c2 = TCanvas()
pe_ratio.Draw()


c3 = TCanvas()
time_sc.SetLineColor(ROOT.kGreen+2)
time_ch.SetLineColor(ROOT.kBlue+2)
time_sc.DrawNormalized("histo")
time_ch.DrawNormalized("histo same")









raw_input("Please press enter to exit.")





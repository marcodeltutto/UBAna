#!/usr/bin/env python
#
# read a root anatree using Pyroot
#
# run with python pyrootMacroTPCActive.py 14 -1
# 14 is the nu flavour (nu-mu in this case)
# -1 means loop over all the entries

import os,sys,string, time
import ROOT
from math import *
from ROOT import TTree, TObject, TFile, gDirectory, TH1D, TH2D, TH3D, TCanvas, gROOT, TGaxis, gStyle, TColor, TLegend, THStack, TChain
#from ROOT import *
from array import array
from glob import glob

# Importing rootlogon.C
ROOT.gROOT.SetMacroPath('/Users/deltutto/');
ROOT.gROOT.Macro( os.path.expanduser( 'rootlogon.C' ) )

# Opening root file
# fname = glob("./ana_hist_bnb_nu_cosmic_dirt_uboone_MCC8_incryo.root") # Dirt
# fname = glob("./ana_hist_bnb_nu_cosmic_dirt_uboone_MCC8_onlyincryo.root") # Dirt (in cryo only, no MCParticle filter)
fname = glob("./ana_hist_bnb_nu_cosmic_dirt_uboone_MCC8_onlyincryo_nophotonfilter.root") # Dirt (in cryo only, no MCParticle filter, no Photon filter)
# fname = glob("./ana_hist_bnb_nu_cosmic_uboone_MCC8.root") # Standard
#fname = glob("./ana_hist_bnb_nu_cosmic_uboone_MCC8_2.root") # Standard, second set
#print "Input file: ", fname

outfile = "dirt_analysed_dirt_onlyincryo_nophotonfilter.root"

# Creating TChain
chain    = TChain("analysistree/anatree")
chainPOT = TChain("analysistree/pottree")
for f in fname: 
  chain.Add(f)
  chainPOT.Add(f)
           
# Printing the number of entries
entries    = chain.GetEntries()
entriesPOT = chainPOT.GetEntries()
print "Number of entries in the ANA tree: ", entries
print "Number of entries in the POT tree: ", entriesPOT

# Getting POT number
NominalPOT = 6.6e20
TotalPOT = 0
for jentry in xrange( entriesPOT ):
  entry = chainPOT.GetEntry( jentry )
  #print '{:e}'.format(float(chainPOT.pot))
  TotalPOT += chainPOT.pot 
print "Accumulated POT: ", '{:e}'.format(float(TotalPOT))
print "Nominal POT:     ", '{:e}'.format(float(NominalPOT))


# Analyzing ANAtree
CC     = 0
CC_QES = 0 
CC_RES = 0
CC_DIS = 0
CC_COH = 0
NC     = 0
NC_QES = 0
NC_RES = 0
NC_DIS = 0
NC_COH = 0

NeutrinoID = sys.argv[1]
print "Neutrino ID:      ", NeutrinoID

CCNC = sys.argv[2]
print "CCNC:      ", CCNC

MaxEntries = int(sys.argv[3])
print "MaxEntries:       ", MaxEntries

totEnergy = TH1D("totEnergy", ";Energy [GeV]; CC events / 6.6 x 10^{20} POT", 600, 0, 6)
numuEnergy = TH1D("numuEnergy", ";Energy [GeV];#nu_{#mu} CC events / 6.6 x 10^{20} POT", 600, 0, 6)
anumuEnergy = TH1D("anumuEnergy", ";Energy [GeV];#bar{#nu}_{#mu} CC events / 6.6 x 10^{20} POT", 600, 0, 6)
nueEnergy = TH1D("nueEnergy", ";Energy [GeV];#nu_{e} CC events / 6.6 x 10^{20} POT", 600, 0, 6)
anueEnergy = TH1D("anueEnergy", ";Energy [GeV];#bar{#nu}_{e} CC events / 6.6 x 10^{20} POT", 600, 0, 6)

numuAngleX = TH1D("numuAngleX", ";p_{x}/p;#nu_{#mu} CC events / 6.6 x 10^{20} POT", 600, 0, 6)
numuAngleY = TH1D("numuAngleY", ";p_{y}/p;#nu_{#mu} CC events / 6.6 x 10^{20} POT", 600, 0, 6)
numuAngleZ = TH1D("numuAngleZ", ";p_{z}/p;#nu_{#mu} CC events / 6.6 x 10^{20} POT", 600, 0, 6)

numuQ2 = TH1D("numuQ2", ";Q^{2} [GeV^{2}];CC events / 6.6 x 10^{20} POT", 600, 0, 6)

numuEnergyPiP = TH1D("numuEnergyPiP", ";Energy [GeV];#nu_{#mu} CC events / 6.6 x 10^{20} POT", 600, 0, 6)
numuEnergyKP = TH1D("numuEnergyKP", ";Energy [GeV];#nu_{#mu} CC events / 6.6 x 10^{20} POT", 600, 0, 6)
numuEnergyK0L = TH1D("numuEnergyK0L", ";Energy [GeV];#nu_{#mu} CC events / 6.6 x 10^{20} POT", 600, 0, 6)
numuEnergyMuP = TH1D("numuEnergyMuP", ";Energy [GeV];#nu_{#mu} CC events / 6.6 x 10^{20} POT", 600, 0, 6)
numuEnergyElse = TH1D("numuEnergyElse", ";Energy [GeV];#nu_{#mu} CC events / 6.6 x 10^{20} POT", 600, 0, 6)
numuVertexXY = TH2D("numuVertexXY", "#nu_{#mu};V_{x} [cm];V_{y} [cm]", 700, -30, 300, 700, -165, 165)
numuVertexZX = TH2D("numuVertexZX", "#nu_{#mu};V_{z} [cm];V_{x} [cm]", 2600, -30, 1200, 700, -30, 300)
numuVertexZY = TH2D("numuVertexZY", "#nu_{#mu};V_{z} [cm];V_{y} [cm]", 2600, -30, 1200, 700, -165, 165)
numuVertexX = TH1D("numuVertexX", ";V_{x} [cm];Events", 70, -30, 300)
numuVertexY = TH1D("numuVertexY", ";V_{y} [cm];Events", 70, -165, 165)
numuVertexZ = TH1D("numuVertexZ", ";V_{z} [cm];Events", 200, -30, 1200)
nueVertexXY = TH2D("nueVertexXY", "#nu_{e};V_{x} [cm];V_{y} [cm]", 70, -30, 300, 70, -165, 165)
numuEnergyDistance = TH2D("numuEnergyDistance", ";Energy [GeV];d [cm]", 600, 0, 6, 500, 0, 80000)
numuCreationZ = TH1D("numuCreationZ", ";z [cm];Events", 1000, -140, 100000)

#numuVertex3D = TH3D("numuVertex3D", ";V_{x} [cm];V_{y} [cm];V_{z} [cm]", 100, -10, 260, 100, -145, 145, 300, -30, 1100)
numuVertex3D = TH3D("numuVertex3D", ";V_{x} [cm];V_{y} [cm];V_{z} [cm]", 50, 50, 60, 50, -105, -95, 300, -30, 1100)

numuVertexXY1 = TH2D("numuVertexXY1", "#nu_{#mu}   z < 208 cm;V_{x} [cm];V_{y} [cm]", 70, -30, 300, 70, -165, 165)
numuVertexXY2 = TH2D("numuVertexXY2", "#nu_{#mu}   208 < z < 416 cm;V_{x} [cm];V_{y} [cm]", 70, -30, 300, 70, -165, 165)
numuVertexXY3 = TH2D("numuVertexXY3", "#nu_{#mu}   416 < z < 624 cm;V_{x} [cm];V_{y} [cm]", 70, -30, 300, 70, -165, 165)
numuVertexXY4 = TH2D("numuVertexXY4", "#nu_{#mu}   624 < z < 832 cm;V_{x} [cm];V_{y} [cm]", 70, -30, 300, 70, -165, 165)
numuVertexXY5 = TH2D("numuVertexXY5", "#nu_{#mu}   z > 832 cm;V_{x} [cm];V_{y} [cm]", 70, -30, 300, 70, -165, 165)


numuProdXY = TH2D("numuProdXY", "#nu_{#mu} prod;V_{x} [cm];V_{y} [cm]", 600, -10, 10, 600, -10, 10)

parentType = TH2D("parentType", ";Parent Type (pdg code);V_{z} [cm]", 1000, -500, 500, 2600, -30, 1200)

if MaxEntries > 0: 
  entries = int(MaxEntries)
  
print "Running over ", entries, " entries."

for jentry in xrange( entries ):                   # loop over the entries
  entry = chain.GetEntry( jentry )

  if (jentry % 10000 == 0):
    print "At entry", jentry

  for k in xrange( chain.mcevts_truth ):            # loop over the events in the spill

    in_tpcactive = False
    if (chain.nuvtxx_truth[k] > 0. and chain.nuvtxx_truth[k] < 256.35 and chain.nuvtxy_truth[k] > -116.5 and chain.nuvtxy_truth[k] < 116.5 and chain.nuvtxz_truth[k] > 0. and chain.nuvtxz_truth[k] < 1036.8):
      in_tpcactive = True

    if chain.ccnc_truth[k] == 0 and in_tpcactive: # if it's CC in TPCActive
      totEnergy.Fill(chain.enu_truth[k])
      if chain.nuPDG_truth[k] == 14: #int(NeutrinoID):    # if it's a muon neutrino
        numuEnergy.Fill(chain.enu_truth[k])
        numuAngleX.Fill(chain.nu_dcosx_truth[k])
        numuAngleY.Fill(chain.nu_dcosy_truth[k])
        numuAngleZ.Fill(chain.nu_dcosz_truth[k])
        numuQ2.Fill(chain.Q2_truth[k])

        if chain.nuvtxx_truth[k] > 50 and chain.nuvtxx_truth[k] < 58 and chain.nuvtxy_truth[k] > -100 and chain.nuvtxy_truth[k] < -95:
          parentType.Fill(chain.ptype_flux[k], chain.nuvtxz_truth[k])
        numuVertex3D.Fill(chain.nuvtxx_truth[k],chain.nuvtxy_truth[k],chain.nuvtxz_truth[k])
        numuVertexXY.Fill(chain.nuvtxx_truth[k],chain.nuvtxy_truth[k])
        numuVertexZX.Fill(chain.nuvtxz_truth[k],chain.nuvtxx_truth[k])
        numuVertexZY.Fill(chain.nuvtxz_truth[k],chain.nuvtxy_truth[k])
        numuVertexX.Fill(chain.nuvtxx_truth[k])
        numuVertexY.Fill(chain.nuvtxy_truth[k])
        numuVertexZ.Fill(chain.nuvtxz_truth[k])
        numuProdXY.Fill(chain.vx_flux[k], chain.vy_flux[k])
        if chain.nuvtxz_truth[k] <= 208:
          numuVertexXY1.Fill(chain.nuvtxx_truth[k],chain.nuvtxy_truth[k])
        elif (chain.nuvtxz_truth[k] > 208 and chain.nuvtxz_truth[k] <= 208*2):
          numuVertexXY2.Fill(chain.nuvtxx_truth[k],chain.nuvtxy_truth[k])
        elif (chain.nuvtxz_truth[k] > 208*2 and chain.nuvtxz_truth[k] <= 208*3):
          numuVertexXY3.Fill(chain.nuvtxx_truth[k],chain.nuvtxy_truth[k])
        elif (chain.nuvtxz_truth[k] > 208*3 and chain.nuvtxz_truth[k] <= 208*4):
          numuVertexXY4.Fill(chain.nuvtxx_truth[k],chain.nuvtxy_truth[k])
        elif chain.nuvtxz_truth[k] > 208*4:
          numuVertexXY5.Fill(chain.nuvtxx_truth[k],chain.nuvtxy_truth[k])

      if chain.nuPDG_truth[k] == -14: #int(NeutrinoID):   # if it's an anti muon neutrino
        anumuEnergy.Fill(chain.enu_truth[k])
      if chain.nuPDG_truth[k] == 12: #int(NeutrinoID):    # if it's an electron neutrino
        nueEnergy.Fill(chain.enu_truth[k])
        nueVertexXY.Fill(chain.nuvtxx_truth[k],chain.nuvtxy_truth[k])
      if chain.nuPDG_truth[k] == -12: #int(NeutrinoID):   # if it's an anti electron neutrino
        anueEnergy.Fill(chain.enu_truth[k])

    if chain.nuPDG_truth[k] == int(NeutrinoID) and in_tpcactive:     # if it's a muon neutrino
      if chain.ccnc_truth[k] == 0:                  # if it's a CC interaction   
        CC += 1
        numuCreationZ.Fill(chain.vz_flux[k])
        if chain.ptype_flux[k] == 211:
          numuEnergyPiP.Fill(chain.enu_truth[k])
        elif chain.ptype_flux[k] == 321:
          numuEnergyKP.Fill(chain.enu_truth[k]) 
        elif chain.ptype_flux[k] == 130:
          numuEnergyK0L.Fill(chain.enu_truth[k])
        elif chain.ptype_flux[k] == -13:
          numuEnergyMuP.Fill(chain.enu_truth[k])
        else:
          numuEnergyElse.Fill(chain.enu_truth[k])
          #print chain.ptype_flux[k]
        if chain.mode_truth[k] == 0:                # if it's a quasi-elastic interaction
          CC_QES += 1
        elif chain.mode_truth[k] == 1:
          CC_RES += 1
        elif chain.mode_truth[k] == 2:
          CC_DIS += 1
        elif chain.mode_truth[k] == 3:
          CC_COH += 1
        #else:
          #print "Error. chain.mode_truth[k] is ", chain.mode_truth[k] 
      if chain.ccnc_truth[k] == 1:                  # if it's a NC interaction 
        NC += 1
        if chain.mode_truth[k] == 0:                # if it's a quasi-elastic interaction
          NC_QES += 1
        if chain.mode_truth[k] == 1:
          NC_RES += 1
        if chain.mode_truth[k] == 2:
          NC_DIS += 1
        if chain.mode_truth[k] == 3:
          NC_COH += 1



print
print "Scale factor:", NominalPOT, "/", TotalPOT, ":", NominalPOT/TotalPOT
print
print "CC Interactions: ", CC*NominalPOT/TotalPOT, " +- ", sqrt(CC) * NominalPOT/TotalPOT
print "   QES: ", CC_QES*NominalPOT/TotalPOT, " +- ", sqrt(CC_QES) * NominalPOT/TotalPOT
print "   RES: ", CC_RES*NominalPOT/TotalPOT, " +- ", sqrt(CC_RES) * NominalPOT/TotalPOT
print "   DIS: ", CC_DIS*NominalPOT/TotalPOT, " +- ", sqrt(CC_DIS) * NominalPOT/TotalPOT
print "   COH: ", CC_COH*NominalPOT/TotalPOT, " +- ", sqrt(CC_COH) * NominalPOT/TotalPOT
print
print "NC Interactions: ", NC*NominalPOT/TotalPOT, " +- ", sqrt(NC) * NominalPOT/TotalPOT
print "   QES: ", NC_QES*NominalPOT/TotalPOT, " +- ", sqrt(CC_QES) * NominalPOT/TotalPOT
print "   RES: ", NC_RES*NominalPOT/TotalPOT, " +- ", sqrt(NC_RES) * NominalPOT/TotalPOT
print "   DIS: ", NC_DIS*NominalPOT/TotalPOT, " +- ", sqrt(NC_DIS) * NominalPOT/TotalPOT
print "   COH: ", NC_COH*NominalPOT/TotalPOT, " +- ", sqrt(NC_COH) * NominalPOT/TotalPOT



# **********************************************
#
# Saving to .root file
#
# **********************************************

f = ROOT.TFile(outfile, "RECREATE");


# Draw 1
totEnergy.Scale(NominalPOT/TotalPOT)
numuEnergy.Scale(NominalPOT/TotalPOT)
anumuEnergy.Scale(NominalPOT/TotalPOT)
nueEnergy.Scale(NominalPOT/TotalPOT)
anueEnergy.Scale(NominalPOT/TotalPOT)
totEnergy.SetLineColor(ROOT.kBlack)
numuEnergy.SetLineColor(ROOT.kBlue)
anumuEnergy.SetLineColor(ROOT.kBlue)
anumuEnergy.SetLineStyle(7)
nueEnergy.SetLineColor(ROOT.kRed)
anueEnergy.SetLineColor(ROOT.kRed)
anueEnergy.SetLineStyle(7)
totEnergy.Write()
numuEnergy.Write()
anumuEnergy.Write()
nueEnergy.Write()
anueEnergy.Write()


# numuAngleX.Scale(NominalPOT/TotalPOT)
# numuAngleY.Scale(NominalPOT/TotalPOT)
# numuAngleZ.Scale(NominalPOT/TotalPOT)
# numuAngleX.

numuQ2.Scale(NominalPOT/TotalPOT)
numuQ2.Write()

'''
leg = TLegend(.5, .55, .9, .85)
leg.SetFillStyle(0);
leg.AddEntry(totEnergy,   "Total CC",        "l");
leg.AddEntry(numuEnergy,  "#nu_{#mu}",       "l");
leg.AddEntry(anumuEnergy, "#bar{#nu}_{#mu}", "l");
leg.AddEntry(nueEnergy,   "#nu_{e}",         "l");
leg.AddEntry(anueEnergy,  "#bar{#nu}_{e}",   "l");
leg.Draw(); 
'''


# Draw 2
numuEnergyPiP.Scale(NominalPOT/TotalPOT)
numuEnergyKP.Scale(NominalPOT/TotalPOT)
numuEnergyK0L.Scale(NominalPOT/TotalPOT)
numuEnergyMuP.Scale(NominalPOT/TotalPOT)
numuEnergyElse.Scale(NominalPOT/TotalPOT)
numuEnergyPiP.SetLineColor(ROOT.kBlue)
numuEnergyKP.SetLineColor(ROOT.kRed)
numuEnergyK0L.SetLineColor(ROOT.kGreen)
numuEnergyElse.SetLineColor(ROOT.kCyan)
numuEnergy.Write()
numuEnergyPiP.Write()
numuEnergyKP.Write()
numuEnergyK0L.Write()
numuEnergyMuP.Write()
numuEnergyElse.Write()

'''
leg2 = TLegend(.5, .55, .9, .85)
leg2.SetFillStyle(0);
leg2.AddEntry(numuEnergy,     "Total #nu_{#mu} CC",       "l");
leg2.AddEntry(numuEnergyPiP,  "#nu_{#mu} form #pi^{+}",   "l");
leg2.AddEntry(numuEnergyKP,   "#nu_{#mu} form K^{+}",     "l");
leg2.AddEntry(numuEnergyK0L,  "#nu_{#mu} form K^{0}_{L}", "l");
leg2.AddEntry(numuEnergyElse, "#nu_{#mu} form others",    "l");
leg2.Draw();
'''


numuVertexXY.Scale(NominalPOT/TotalPOT)
numuVertexXY.Write()

numuVertexX.Scale(NominalPOT/TotalPOT)
numuVertexX.Write()

numuVertexY.Scale(NominalPOT/TotalPOT)
numuVertexY.Write()

numuVertexZ.Scale(NominalPOT/TotalPOT)
numuVertexZ.Write()

numuEnergyDistance.Scale(NominalPOT/TotalPOT)
numuEnergyDistance.Write()

numuCreationZ.Scale(NominalPOT/TotalPOT)
numuCreationZ.Write()

nueVertexXY.Scale(NominalPOT/TotalPOT)
nueVertexXY.Write()


numuVertexXY1.Scale(NominalPOT/TotalPOT)
numuVertexXY1.Write()
numuVertexXY2.Scale(NominalPOT/TotalPOT)
numuVertexXY2.Write()
numuVertexXY3.Scale(NominalPOT/TotalPOT)
numuVertexXY3.Write()
numuVertexXY4.Scale(NominalPOT/TotalPOT)
numuVertexXY4.Write()
numuVertexXY5.Scale(NominalPOT/TotalPOT)
numuVertexXY5.Write()

numuProdXY.Scale(NominalPOT/TotalPOT)
numuProdXY.Write()

numuVertexZX.Scale(NominalPOT/TotalPOT)
numuVertexZX.Write()

numuVertexZY.Scale(NominalPOT/TotalPOT)
numuVertexZY.Write()

numuVertexZX.Write();
numuVertexZY.Write();

numuVertex3D.Scale(NominalPOT/TotalPOT)

parentType.Scale(NominalPOT/TotalPOT)
parentType.Write()

f.Close();


f2 = ROOT.TFile("dirt_analysed_3d.root", "RECREATE");
numuVertex3D.Write()

f2.Close();


raw_input("Please press enter to exit.")
#time.sleep(30)




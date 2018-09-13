import sys, os
import math
import numpy as np

from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

RIndexEnergies = [1.9,2.934,3.592,5.566,6.694,7.54,8.574,9.044,9.232,9.42,9.514,9.608,9.702,9.796,9.89,9.984,1.008e1,1.027e1,1.045e1,1.074e1,1.092e1]

RIndexSpectrum = [1.232,1.236,1.24,1.261,1.282,1.306,1.353,1.387,1.404,1.423,1.434,1.446,1.459,1.473,1.488,1.505,1.524,1.569,1.627,1.751,1.879]

RIndexWavelength = [1.2398/element*1000 for element in RIndexEnergies]

print RIndexWavelength

wl = np.asarray(RIndexWavelength)
ri = np.asarray(RIndexSpectrum)

gr = TGraph( len(RIndexWavelength), wl, ri )

gr.GetXaxis().SetTitle("Wavelenght [nm]")
gr.GetYaxis().SetTitle("Index of Refraction")

gr.Draw()








RayleighEnergies = [2.8,3,3.5,4,5,6,7,8,8.5,9,9.2,9.4,9.5,9.6,9.7,9.8,9.9,10,1.02e1,1.04e1,1.06e1,1.08e1]

RayleighSpectrum = [47923,35981,18825,10653,3972,1681,7.509e2,3.347e2,2.168e2,135,1.097e2,8.806e1,7.832e1,6.934e1,6.106e1,5.346e1,4.65e1,4.013e1,2.891e1,1.981e1,1.261e1,7.2]

RayleighWavelength = [1.2398/element*1000 for element in RayleighEnergies]

wl = np.asarray(RayleighWavelength)
ra = np.asarray(RayleighSpectrum)

gr2 = TGraph( len(RayleighWavelength), wl, ra )

gr2.GetXaxis().SetTitle("Wavelenght [nm]")
gr2.GetYaxis().SetTitle("Attenuation Length [cm]")

gr2.Draw()








My_Wavelength = [100,    300.,   301., 700]

My_QE         = [0.0093, 0.0093, 0.09, 0.09]


wl = np.asarray(My_Wavelength)
qe = np.asarray(My_QE)

gr3 = TGraph( len(My_Wavelength), wl, qe )

gr3.GetXaxis().SetTitle("Wavelenght [nm]")
gr3.GetYaxis().SetTitle("QE")

gr3.Draw()





raw_input("Please press enter to exit.")


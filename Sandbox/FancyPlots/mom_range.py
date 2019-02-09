import sys, os, math
from array import array
import ROOT
from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

n_points = 16 #29

density = 1.4 #g/cm3

Range_grampercm = [9.833E-1, 1.786E0, 3.321E0,
       6.598E0, 1.058E1, 3.084E1, 4.250E1, 6.732E1, 1.063E2, 1.725E2,
       2.385E2, 4.934E2, 6.163E2, 8.552E2, 1.202E3, 1.758E3, 2.297E3,
       4.359E3, 5.354E3, 7.298E3, 1.013E4, 1.469E4, 1.910E4, 3.558E4,
       4.326E4, 5.768E4, 7.734E4, 1.060E5, 1.307E5]

KE_MeV = [10, 14,
       20, 30, 40, 80, 100, 140, 200, 300, 400, 800, 1000, 1400, 2000, 3000,
       4000, 8000, 10000, 14000, 20000, 30000, 40000, 80000, 100000, 140000,
       200000, 300000, 400000]

Range = []
KE_GeV = []

for i in xrange(0, n_points):
  # print Range_grampercm[i] / density
  Range.append(Range_grampercm[i] / density)
  KE_GeV.append(KE_MeV[i] / 1000.)

gr = TGraph(n_points, array('d', Range), array('d', KE_GeV))

gr.GetXaxis().SetTitle('Range in LAr [cm]')
gr.GetYaxis().SetTitle('Muon Kinetic Energy [GeV]')
gr.SetTitle('')

KEvsR_spline3 = TSpline3 ("KEvsRS", gr, "", 0, 1300)
KEvsR_spline3.SetLineColor(kRed)
# f = new TF1("f","[0]*x*[1]*x*x*[2]*x*x*x*[3]*x*x*x*x",0,200);

# f.SetParameter(0,10);
# f.SetParameter(1,10);
# f.SetParameter(2,10);
# f.SetParameter(3,10);


gr.SetMarkerStyle(20)
gr.SetMarkerSize(1)
gr.Draw("AP")

KEvsR_spline3.Draw('same')


leg = TLegend(0.3896848,0.6063158,0.8825215,0.8105263);
leg.SetBorderSize(0);
leg.SetTextSize(0.04631579);
leg.SetLineColor(1);
leg.SetLineStyle(1);
leg.SetLineWidth(1);
leg.SetFillColor(0);
leg.SetFillStyle(0);
leg.AddEntry(gr, "PDG CSDA Data", 'p')
leg.AddEntry(KEvsR_spline3, "Interpolation")
leg.Draw()



raw_input("Please press enter to exit.")

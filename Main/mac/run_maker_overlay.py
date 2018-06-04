import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

maker = Main.Maker()



# Overlay

maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/ubxsec_output_data_overlay_mcc8.9_test10.root") # Overlay
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_data_overlay_mcc8.9_test10.root"); # Overlay

maker.SetEntries(-1)
maker.SetInitialEntry(0)
maker.SetBeamSpillStart(3.6)    
maker.SetBeamSpillEnd(5.2)
maker.SetFlashShift(0.)    
maker.SetGainCalibration(243)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)
# maker.SetExtraWeight(1.028); # Flux correction

maker.SetMaUpMECOff(False)

maker.SetTargetFluxSystematic("total")



maker.PrintConfig()

maker.MakeFile()


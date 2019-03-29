import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

maker = Main.Maker()



# Overlay

maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_overlay_ubcodev06_26_01_22__v4.root") # Overlay
maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_overlay_ubcodev06_26_01_22__v4.root"); # Overlay

maker.SetEntries(-1)
maker.SetInitialEntry(0)
maker.SetBeamSpillStart(3.5) #3.6    
maker.SetBeamSpillEnd(5.3) #5.2
maker.SetFlashShift(0.)    
maker.SetGainCalibration(243)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)
# maker.SetExtraWeight(1.028); # Flux correction

maker.SetMaUpMECOff(False)

maker.SetTargetFluxSystematic("total")



maker.PrintConfig()

maker.MakeFile()


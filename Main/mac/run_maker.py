import sys

from ROOT import Main

maker = Main.Maker()

maker.SetInputFile("../../ubxsecana/Files/ubxsec_output_mc_bnbcosmic_mcc8.7_test6.root")
  
maker.SetEntries(100)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)

maker.PrintConfig()

maker.MakeFile()

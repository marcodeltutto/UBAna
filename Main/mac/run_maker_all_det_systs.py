import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

maker = Main.Maker()



# BNBComisc

maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_nospacecharge.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_nospacecharge.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)

maker.SetTargetFluxSystematic("total"); # not needed here

maker.PrintConfig()

maker.MakeFile()



maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_altDeadChannels.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_altDeadChannels.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)

maker.SetTargetFluxSystematic("total"); # not needed here

maker.PrintConfig()

maker.MakeFile()



maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_deadSaturatedChannels.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_deadSaturatedChannels.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)

maker.SetTargetFluxSystematic("total"); # not needed here

maker.PrintConfig()

maker.MakeFile()



maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_enhancedexttpcvis.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_enhancedexttpcvis.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)

maker.SetTargetFluxSystematic("total"); # not needed here

maker.PrintConfig()

maker.MakeFile()



maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_noPEnoise.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_noPEnoise.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)

maker.SetTargetFluxSystematic("total"); # not needed here

maker.PrintConfig()

maker.MakeFile()




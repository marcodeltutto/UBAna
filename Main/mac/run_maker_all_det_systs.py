import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

maker = Main.Maker()



# BNBComisc

maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_cv.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_cv.root");
  
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



maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_dicharge.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_dicharge.root");
  
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


maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_lightyeild.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_lightyeild.root");
  
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


maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_nodeltaray.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_nodeltaray.root");
  
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


maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_stretchRes.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_stretchRes.root");
  
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


maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_noShortedResp.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_noShortedResp.root");
  
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


maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_whitenoise.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_whitenoise.root");
  
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


maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_lifetime10ms.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_lifetime10ms.root");
  
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


maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_dl0.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_dl0.root");
  
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



maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_dt0.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_dt0.root");
  
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


maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_birksrecomb.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_birksrecomb.root");
  
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


maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/DetSyst/ubxsec_output_mc_bnbcosmic_mcc8.9_detsyst_nohadronic.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_nohadronic.root");
  
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



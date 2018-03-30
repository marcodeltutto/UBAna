import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

maker = Main.Maker()



# BNBComisc

maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/ubxsec_output_mc_bnbcosmic_mcc8.9_500k.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_500k.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)

#maker.SetTargetFluxSystematic("FluxUnisim");
#maker.SetTargetFluxSystematic("kminus_PrimaryHadronNormalizat");
#maker.SetTargetFluxSystematic("kplus_PrimaryHadronFeynmanScal");
#maker.SetTargetFluxSystematic("kzero_PrimaryHadronSanfordWang");
#maker.SetTargetFluxSystematic("piminus_PrimaryHadronSWCentral");
#maker.SetTargetFluxSystematic("piplus_PrimaryHadronSWCentralS");
maker.SetTargetFluxSystematic("total");



maker.PrintConfig()

maker.MakeFile()



# BNBON

maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/ubxsec_output_data_bnbon_mcc8.7_test6.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbon_mcc8.7_test6.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.3)    
maker.SetBeamSpillEnd(4.9)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(243)    
maker.SetCalculatePOT(False)    
maker.SetIsData(True)

maker.PrintConfig()

maker.MakeFile()



# EXTBNB

maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/ubxsec_output_data_extbnb_mcc8.7_test6.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_extbnb_mcc8.7_test6.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.65)    
maker.SetBeamSpillEnd(5.25)    
maker.SetFlashShift(0.406)    
maker.SetGainCalibration(243)    
maker.SetCalculatePOT(False)    
maker.SetIsData(True)

maker.PrintConfig()

maker.MakeFile()



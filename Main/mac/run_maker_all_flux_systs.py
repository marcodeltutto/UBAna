import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

maker = Main.Maker()




# BNBComisc - Flux Unisim

maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/ubxsec_output_mc_bnbcosmic_mcc8.7_test6.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_fluxunisim.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)

maker.SetTargetFluxSystematic("FluxUnisim");

maker.PrintConfig()

maker.MakeFile()



# BNBComisc - Flux K-

maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/ubxsec_output_mc_bnbcosmic_mcc8.7_test6.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_kminus.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)

maker.SetTargetFluxSystematic("kminus");

maker.PrintConfig()

maker.MakeFile()



# BNBComisc - Flux K+

maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/ubxsec_output_mc_bnbcosmic_mcc8.7_test6.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_kplus.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)

maker.SetTargetFluxSystematic("kplus");

maker.PrintConfig()

maker.MakeFile()



# BNBComisc - Flux K0

maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/ubxsec_output_mc_bnbcosmic_mcc8.7_test6.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_kzero.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)

maker.SetTargetFluxSystematic("kzero");

maker.PrintConfig()

maker.MakeFile()



# BNBComisc - Flux Pi-

maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/ubxsec_output_mc_bnbcosmic_mcc8.7_test6.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_piminus.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)

maker.SetTargetFluxSystematic("piminus");

maker.PrintConfig()

maker.MakeFile()



# BNBComisc - Flux Pi+

maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/ubxsec_output_mc_bnbcosmic_mcc8.7_test6.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_piplus.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)

maker.SetTargetFluxSystematic("piplus");

maker.PrintConfig()

maker.MakeFile()




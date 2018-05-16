import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

maker = Main.Maker()

# BNBComisc

maker.SetInputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Input/ubxsec_output_mc_bnbcosmic_mcc8.7_test6.root")
maker.SetOutputFile("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_fluxunisim.root");
  
maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(4.8)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)
maker.SetExtraWeight(1.028); # Flux correction


flux_syst_list = ["FluxUnisim", "kminus", "kplus", "kzero", "piminus", "piplus", "total"]
# flux_syst_list = ["total"]

for systname in flux_syst_list:
  file_name = "/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_" + systname + ".root"
  maker.SetOutputFile(file_name)
  maker.SetTargetFluxSystematic(systname);
  maker.PrintConfig()
  maker.MakeFile()



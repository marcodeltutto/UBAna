import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

maker = Main.Maker()


det_syst_list = ["CV", "withDIC", "dataSCE", "squeezeResp", "stretchResp", "DLdown", "DLup", "DTdown", "DTup", "LArG4BugFix", "downPEnoise", "upPEnoise", "noiseAmpDown", "noiseAmpUp", "enhancedexttpcvis", "altDeadChannels", "birksrecomb", "deadSaturatedChannels", "lifetime10ms"]


for systname in det_syst_list:
  
  maker.SetInputFile("/uboone/data/users/mdeltutt/ubxsec_static/v06_26_01_22/detsyst/ubxsec_output_mc_bnbcosmic_detsyst_" + systname + "_ubcodev06_26_01_22.root")
  maker.SetOutputFile("/uboone/data/users/mdeltutt/ubxsec_static/v06_26_01_22/detsyst/ubxsecana_output_mc_bnbcosmic_detsyst_" + systname + "_ubcodev06_26_01_22.root");

  maker.SetEntries(-1)
  maker.SetBeamSpillStart(3.1)    
  maker.SetBeamSpillEnd(4.9)    
  maker.SetFlashShift(0.)    
  maker.SetGainCalibration(198)    
  maker.SetCalculatePOT(True)    
  maker.SetIsData(False)
  maker.SetExtraWeight(1.028); # Flux correction

  maker.SetTargetFluxSystematic("total"); # not needed here

  maker.PrintConfig()

  maker.MakeFile()



# systname = "cherenkov"
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/DetSyst/ubxsec_output_mc_bnbcosmic_ubcodev06_26_01_18__v8_syst_cherenkov.root")
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_prod_v06_26_11_" + systname + ".root");

# maker.SetEntries(-1)
# maker.SetBeamSpillStart(3.2)    
# maker.SetBeamSpillEnd(4.8)    
# maker.SetFlashShift(0.)    
# maker.SetGainCalibration(198)    
# maker.SetCalculatePOT(True)    
# maker.SetIsData(False)
# maker.SetExtraWeight(1.028); # Flux correction

# maker.SetTargetFluxSystematic("total"); # not needed here

# maker.PrintConfig()

# maker.MakeFile()






# systname = "cherenkov2"
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/DetSyst/ubxsec_output_mc_bnbcosmic_cherenkov_ubcodev06_26_01__v1.root")
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_prod_v06_26_11_" + systname + ".root");

# maker.SetEntries(-1)
# maker.SetBeamSpillStart(3.2)    
# maker.SetBeamSpillEnd(4.8)    
# maker.SetFlashShift(0.)    
# maker.SetGainCalibration(198)    
# maker.SetCalculatePOT(True)    
# maker.SetIsData(False)
# maker.SetExtraWeight(1.028); # Flux correction

# maker.SetTargetFluxSystematic("total"); # not needed here

# maker.PrintConfig()

# maker.MakeFile()




# systname = "cherenkov3"
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/DetSyst/ubxsec_output_mc_bnbcosmic_cherenkov_ubcodev06_26_01__v3.root")
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_prod_v06_26_11_" + systname + ".root");

# maker.SetEntries(-1)
# maker.SetBeamSpillStart(3.2)    
# maker.SetBeamSpillEnd(4.8)    
# maker.SetFlashShift(0.)    
# maker.SetGainCalibration(198)    
# maker.SetCalculatePOT(True)    
# maker.SetIsData(False)
# maker.SetExtraWeight(1.028); # Flux correction

# maker.SetTargetFluxSystematic("total"); # not needed here

# maker.PrintConfig()

# maker.MakeFile()





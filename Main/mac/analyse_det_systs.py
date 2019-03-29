import sys, os, math

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


analyser.SetInTimeCosmicFile  ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder
analyser.SetDirtFile          ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_22__v3.root")

analyser.SetBNBONFile         ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_run1_ubcodev06_26_01_22__v4.root")    
analyser.SetEXTBNBFile        ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_run1_ubcodev06_26_01_22__v4.root")
analyser.SetBNBPOT(1.592e+20)    
analyser.SetBNBONTriggers(35388924.0)   
analyser.SetEXTBNBTriggers(72299264.0)

analyser.SetFluxCorrectionWeight(1.028)

det_syst_list = ["CV", "dataSCE", "withDIC", "squeezeResp", "stretchResp", "DLdown", "DLup", "DTdown", "DTup", "LArG4BugFix", "downPEnoise", "upPEnoise", "noiseAmpDown", "noiseAmpUp", "enhancedexttpcvis", "lifetime10ms", "birksrecomb" ,"deadSaturatedChannels", "altDeadChannels"]
det_syst_list = ["withDIC"]


for systname in det_syst_list:
  file_name = "/Users/deltutto/CCInclusiveFiles/Output/DetSyst/ubxsecana_output_mc_bnbcosmic_detsyst_" + systname + "_ubcodev06_26_01_22.root"
  print file_name
  analyser.SetBNBCosmicFile(file_name)
  analyser.SetPrefix(systname)
  analyser.DoAnalise()


raw_input("Please press enter to exit.")
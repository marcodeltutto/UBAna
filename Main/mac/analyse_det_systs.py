import sys, os, math

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


#analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.9_500k.root");
analyser.SetInTimeCosmicFile  ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder
analyser.SetDirtFile          ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_20__v15.root") # dirt v15 (used for nuint)

# analyser.SetBNBONFile         ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbon_mcc8.7_test6.root")   
# analyser.SetEXTBNBFile        ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_extbnb_mcc8.7_test6.root")
# analyser.SetBNBPOT(4.852e+19)
# analyser.SetBNBONTriggers(10820589)
# analyser.SetEXTBNBTriggers(15482261)

analyser.SetBNBONFile         ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbon_a_mcc8.9_test4.root")    
analyser.SetEXTBNBFile        ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_extbnb_a_mcc8.9_test4.root")
analyser.SetBNBPOT(1.627e+20)    
analyser.SetBNBONTriggers(36177265)    
analyser.SetEXTBNBTriggers(33320382)

# analyser.SetBNBONFile         ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_ubcodev06_26_01_18__v11.root") # After Neutrino    
# analyser.SetEXTBNBFile        ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_ubcodev06_26_01_18__v11.root") # After Neutrino
# analyser.SetBNBPOT(4.238e+19)    
# analyser.SetBNBONTriggers(9394515)
# analyser.SetEXTBNBTriggers(60329062)


analyser.SetFluxCorrectionWeight(1.028)

extra_unc = math.sqrt(0.02*0.02 + 0.06*0.06) # POT counting, beam window
# analyser.SetExtraUncertainty(extra_unc)

analyser.SetTargetFluxSystematic("total")
analyser.DoFluxSystematics(False)
analyser.ImportFluxSystematics(False)
analyser.DoGenieSystematics(False)
analyser.DoGenieModelsSystematics(False)
analyser.ImportGenieModelsSystematics(False)
analyser.ImportFluxSystematics(False)
analyser.SetExtraFluxUncertainty(0.)


#det_syst_list = ["nospacecharge", "dicharge", "lightyeild", "nodeltaray", "stretchRes", "altDeadChannels", "deadSaturatedChannels", "noPEnoise", "noShortedResp", "whitenoise", "enhancedexttpcvis", "lifetime10ms", "dl0", "birksrecomb", "nohadronic"]
det_syst_list = ["cv", "nospacecharge", "dicharge", "lightyeild", "stretchRes", "altDeadChannels", "deadSaturatedChannels", "noPEnoise", "noShortedResp", "whitenoise", "enhancedexttpcvis", "lifetime10ms", "dl0", "dt0", "birksrecomb"] #, "nohadronic"]
# det_syst_list = ["CV", "dataSCE", "withDIC", "squeezeResp", "DLdown", "DLup", "DTdown", "DTup", "LArG4BugFix", "downPEnoise", "upPEnoise", "noiseAmpDown", "noiseAmpUp"]


# det_syst_list = ["altDeadChannels"]
# det_syst_list = ["cherenkov"]
# det_syst_list = ["cherenkov2"]
# det_syst_list = ["cherenkov3"]

for systname in det_syst_list:
  file_name = "/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.9_detsyst_" + systname + ".root"
  # file_name = "/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_prod_v06_26_11_" + systname + ".root"
  print file_name
  analyser.SetBNBCosmicFile(file_name)
  analyser.SetPrefix(systname)
  analyser.DoAnalise()



# analyser.SetBNBCosmicFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_prod_v06_26_11_CV.root")
# analyser.SetPrefix("CV")
# analyser.DoAnalise()

# analyser.SetBNBCosmicFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_prod_v06_26_11_dataSCE.root")
# analyser.SetPrefix("dataSCE")
# analyser.DoAnalise()

# analyser.SetBNBCosmicFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_prod_v06_26_11_stretchResp.root")
# analyser.SetPrefix("stretchResp")
# analyser.DoAnalise()

# analyser.SetBNBCosmicFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_prod_v06_26_11_squeezeResp.root")
# analyser.SetPrefix("squeezeResp")
# analyser.DoAnalise()

raw_input("Please press enter to exit.")
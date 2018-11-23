import sys, os, math

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4.root") # tune 1

analyser.SetInTimeCosmicFile  ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder
analyser.SetBNBONFile         ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_overlay_ubcodev06_26_01_22__v4.root") # fake data! Overlay
analyser.SetEXTBNBFile        ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_run1_ubcodev06_26_01_22__v4.root") 
analyser.SetBNBPOT(9.6181e+20)    #88601  1.65319e+20 #9.6181e+20
analyser.SetBNBONTriggers(213802895.68115577)   #36749130.19319 #213802895.68115577
analyser.SetEXTBNBTriggers(72299264)
# 35388924 bnbon triggers corrspond to 1.592e+20 POT
# and for bnbext we have 72299264, bnbext stays the same
# for bnbon we have to increase the triggers to 35388924/1.592e+20*9.6181e+20 = 213802895.68115577

analyser.SetFakeDataMode(False)
analyser.SetOverlayMode(True) # <---

analyser.SetPrefix("overlay")
analyser.SetFluxCorrectionWeight(1.028)


analyser.DoAnalise();


raw_input("Please press enter to exit.")
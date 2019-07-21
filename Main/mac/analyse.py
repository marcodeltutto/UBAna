import sys, os, math

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v2_nosyst.root") # Tune 1
analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_all.root") # Tune 1 - full stat - full syst

# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_new.root") # Tune 1 - full stat - no syst - with 2d efficiency per channel

# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_ccqe_ccmec.root") # Tune 1 - ccqe & ccmec syst only
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_reint.root") # Tune 1 - reinteraction syst only
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v5.root") # Tune 1 - dev - full syst
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v5_kaonup.root") # Tune 1 - dev - Kaon Scaled Up
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v5_kaondown.root") # Tune 1 - dev - Kaon Scaled Down

# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_tune3_full_ubcodev06_26_01_22__v3.root") # Tune 3 (full)

# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_cosmicscaled.root") # Tune 1 - full - Cosmics scaled by 0.6

analyser.SetDirtFile          ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_22__v3.root")

analyser.SetInTimeCosmicFile  ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder

analyser.SetBNBONFile         ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_run1_ubcodev06_26_01_22__v4.root")    
analyser.SetEXTBNBFile        ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_run1_ubcodev06_26_01_22__v4.root")
analyser.SetBNBPOT(1.592e+20)    
analyser.SetBNBONTriggers(35388924.0)   
analyser.SetEXTBNBTriggers(72299264.0)
analyser.SetPrefix("cv")
# analyser.SetPrefix("cv_tune3")
# analyser.SetPrefix("cv_cosmicscaled_overlay_test")
# analyser.SetPrefix("cv_nodirt")
# analyser.SetPrefix("kaonup")
# analyser.SetPrefix("kaondown")
analyser.SetFluxCorrectionWeight(1.028)

analyser.ImportAlternativeMC("xsec_file_cv_tune3.root")

analyser.SetBeamOffSubtraction(False)
analyser.SetBreakdownPlots(False)

extra_unc = math.sqrt(0.02*0.02) # POT counting
analyser.SetExtraUncertainty(extra_unc)

analyser.ImportDetectorSystematics(True)

analyser.ImportCosmicSystematics(True)

analyser.ImportDirtSystematics(True)

analyser.DoGenieSystematics(False)
analyser.ImportGenieSystematics(True)

analyser.DoExtraSystematics(False)
analyser.ImportExtraSystematics(True)

analyser.DoMCStatSystematics(False)
analyser.ImportMCStatSystematics(True)


analyser.DoFluxSystematics(False)
analyser.ImportFluxSystematics(True)
analyser.SetExtraFluxUncertainty(0.)
analyser.SetTargetFluxSystematic("total"); # Other options: "FluxUnisim", "kminus", "kplus", "kzero", "piminus", "piplus"

analyser.DoAnalise();

raw_input("Please press enter to exit.")
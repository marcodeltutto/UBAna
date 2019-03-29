import sys, os, math

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4.root") # Tune 1 - full stat - truth cut on flipped tracks

# analyser.SetDirtFile          ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_22__v3.root")

analyser.SetInTimeCosmicFile  ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder

analyser.SetBNBONFile         ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_truth_noflip.root")    
analyser.SetEXTBNBFile        ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_run1_ubcodev06_26_01_22__v4.root")
analyser.SetBNBPOT(2.17345e+21)   # 2.17345e+21/1.592e+20 = 13.6523
analyser.SetBNBONTriggers(0)   
analyser.SetEXTBNBTriggers(987051241.9072)
analyser.SetPrefix("cv")
# analyser.SetPrefix("cv_tune3")
# analyser.SetPrefix("cv_cosmicscaled_overlay")
# analyser.SetPrefix("cv_nodirt")
# analyser.SetPrefix("kaonup")
# analyser.SetPrefix("kaondown")
analyser.SetFluxCorrectionWeight(1.028)

# analyser.ImportAlternativeMC("xsec_file_cv_tune3.root")

analyser.SetBeamOffSubtraction(False)
analyser.SetBreakdownPlots(True)

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
import sys, os, math

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v2_nosyst.root")
analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v2.root")

analyser.SetDirtFile          ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_22__v3.root")

analyser.SetInTimeCosmicFile  ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder

analyser.SetBNBONFile         ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_run1_ubcodev06_26_01_22__v1.root")    
analyser.SetEXTBNBFile        ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_run1_ubcodev06_26_01_22__v1.root")
analyser.SetBNBPOT(1.159e+20)    
analyser.SetBNBONTriggers(25848208.0)   
analyser.SetEXTBNBTriggers(28745873)
analyser.SetPrefix("cv")
# analyser.SetPrefix("cv_tune3")
# analyser.SetPrefix("cv_cosmicscaled_overlay")
analyser.SetFluxCorrectionWeight(1.028)

# analyser.ImportAlternativeMC("xsec_file_cv_tune3.root")

analyser.SetBeamOffSubtraction(False)
analyser.SetBreakdownPlots(True)

extra_unc = math.sqrt(0.02*0.02 + 0.04*0.04) # POT counting, beam window
# analyser.SetExtraUncertainty(extra_unc)

analyser.ImportDetectorSystematics(False)

analyser.ImportCosmicSystematics(False)

analyser.ImportDirtSystematics(False)

analyser.DoGenieSystematics(True)
analyser.ImportGenieSystematics(False)

analyser.DoExtraSystematics(False)
analyser.ImportExtraSystematics(False)

analyser.DoMCStatSystematics(False)
analyser.ImportMCStatSystematics(False)


analyser.DoFluxSystematics(False)
analyser.ImportFluxSystematics(False)
analyser.SetExtraFluxUncertainty(0.)
analyser.SetTargetFluxSystematic("total"); # Other options: "FluxUnisim", "kminus", "kplus", "kzero", "piminus", "piplus"

analyser.DoAnalise();

raw_input("Please press enter to exit.")
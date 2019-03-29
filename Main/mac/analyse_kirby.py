import sys, os, math

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/kirby_test_ntuples_Nov26_bnbcosmic.root") # Tune 1 - full stat - full syst

# analyser.SetDirtFile          ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_22__v3.root")

analyser.SetInTimeCosmicFile  ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder

analyser.SetBNBONFile         ("/Users/deltutto/CCInclusiveFiles/Output/kirby_test_ntuples_Nov26_bnbon.root")    
analyser.SetEXTBNBFile        ("/Users/deltutto/CCInclusiveFiles/Output/kirby_test_ntuples_Nov26_extbnb.root")
analyser.SetBNBPOT(4.006e+20)    
analyser.SetBNBONTriggers(8877272.0)   
analyser.SetEXTBNBTriggers(69849437.0)
analyser.SetPrefix("cv")

analyser.SetFluxCorrectionWeight(1.028)

# analyser.ImportAlternativeMC("xsec_file_cv_tune3.root")

analyser.SetBeamOffSubtraction(False)
analyser.SetBreakdownPlots(True)

extra_unc = math.sqrt(0.02*0.02) # POT counting
# analyser.SetExtraUncertainty(extra_unc)

analyser.ImportDetectorSystematics(False)

analyser.ImportCosmicSystematics(False)

analyser.ImportDirtSystematics(False)

analyser.DoGenieSystematics(False)
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
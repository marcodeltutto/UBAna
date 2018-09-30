import sys, os, math

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v2_ccqe_ccmec.root")

# analyser.SetDirtFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_20__v15.root") # dirt v15 (used for nuint)

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

analyser.DoGenieSystematics(False)
analyser.ImportGenieSystematics(False)

analyser.DoExtraSystematics(True)
analyser.ImportExtraSystematics(False)

analyser.DoMCStatSystematics(False)
analyser.ImportMCStatSystematics(False)


analyser.DoFluxSystematics(False)
analyser.ImportFluxSystematics(False)
analyser.SetExtraFluxUncertainty(0.)
#analyser.SetTargetFluxSystematic("FluxUnisim");
#analyser.SetTargetFluxSystematic("kminus_PrimaryHadronNormalizat");
#analyser.SetTargetFluxSystematic("kplus_PrimaryHadronFeynmanScal");
#analyser.SetTargetFluxSystematic("kzero_PrimaryHadronSanfordWang");
#analyser.SetTargetFluxSystematic("piminus_PrimaryHadronSWCentral");
#analyser.SetTargetFluxSystematic("piplus_PrimaryHadronSWCentralS");
analyser.SetTargetFluxSystematic("total");

#analyser.SetBNBCosmicFile     ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_piplus.root");
#analyser.SetTargetFluxSystematic("piplus");

#analyser.SetBNBCosmicFile     ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_piminus.root");
#analyser.SetTargetFluxSystematic("piminus");

#analyser.SetBNBCosmicFile     ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_kzero.root");
#analyser.SetTargetFluxSystematic("kzero");

#analyser.SetBNBCosmicFile     ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_kplus.root");
#analyser.SetTargetFluxSystematic("kplus");

#analyser.SetBNBCosmicFile     ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_kminus.root");
#analyser.SetTargetFluxSystematic("kminus");

#analyser.SetBNBCosmicFile     ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_fluxunisim.root");
#analyser.SetTargetFluxSystematic("FluxUnisim");

analyser.DoAnalise();

raw_input("Please press enter to exit.")
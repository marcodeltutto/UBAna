import sys, os, math

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.9_500k.root") # tune 1
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_mcc8.9_test6.root") # tune 1 high stat - genie and flux styst (from uboonegpvm)
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_mcc8.9_test6_fluxscaled.root") # tune 1 high stat - genie and flux styst (from uboonegpvm) (with bnb_weight increased by 3%)
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_mcc8.9_test6_fluxscaled_cosmicscaled.root") # tune 1 high stat - genie and flux styst (from uboonegpvm) (with bnb_weight increased by 3%) (with comisc blue bkg scaled by 0.54548, from the overlay)
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_tune3_mcc8.9_test5.root") # tune 3
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_mcc8.9_test6_tune3.root") # tune 3 - genie and flux styst (from uboonegpvm)
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_mcc8.9_test6_tune3_fluxscaled.root") # tune 3 - genie and flux styst (from uboonegpvm) (with bnb_weight increased by 3%)
analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # tune 1 - genie and flux styst (no high stat)
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_mcc8.9_test6_maup_mecoff.root") # tune 1 - ma up, mec off
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_mcc8.9_test6_tune3_maup_mecoff.root ") # tune 3 - ma up, mec off

# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_kaondown.root")

# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v6.root") # tune 1 - genie models syst only (stolen from Andy's area) (after neutrino, but same selection as before)
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v7.root") # tune 1 - genie models syst only (from Andy's uboonedata branch) (after neutrino, but same selection as before)
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v9_models_ccqe.root") # tune 1 - genie models syst only (from Andy's uboonedata branch, and with the q0, q3 fix) (after neutrino, but same selection as before)
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v9_models_ccmec.root") # tune 1 - genie models syst only (from Andy's uboonedata branch, and with the q0, q3 fix) (after neutrino, but same selection as before)
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v9_models_total.root") # tune 1 - genie models syst only (from Andy's uboonedata branch, and with the q0, q3 fix) (after neutrino, but same selection as before)

analyser.SetDirtFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_18__v9.root") # dirt

analyser.SetInTimeCosmicFile  ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder
analyser.SetBNBONFile         ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbon_a_mcc8.9_test4.root")    
analyser.SetEXTBNBFile        ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_extbnb_a_mcc8.9_test4.root")
analyser.SetBNBPOT(1.627e+20)    
analyser.SetBNBONTriggers(36177265)   
analyser.SetEXTBNBTriggers(33320382)
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

analyser.DoGenieSystematics(False)
analyser.ImportGenieSystematics(False)

analyser.DoGenieModelsSystematics(False)
analyser.ImportGenieModelsSystematics(False)

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
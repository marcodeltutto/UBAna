import sys, os, math

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v2_nosyst.root") # tune 1
# analyser.SetBNBCosmicFile     ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_mc_bnbcosmic_mcc8.9_test6_fluxscaled_cosmicscaled.root") # tune 1 high stat - genie and flux styst (from uboonegpvm) (with bnb_weight increased by 3%) (with comisc blue bkg scaled by 0.54548, from the overlay)

# analyser.SetBNBCosmicFile     ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_mc_bnbcosmic_mcc8.9_test6.root") # tune 1 high stat - genie and flux styst (from uboonegpvm)
# analyser.SetBNBCosmicFile     ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # tune 1- genie and flux styst (no high stat)

# analyser.SetDirtFile          ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_22__v3.root")

analyser.SetInTimeCosmicFile  ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder
analyser.SetBNBONFile         ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_overlay_ubcodev06_26_01_22__v4.root") # fake data! Overlay
analyser.SetEXTBNBFile        ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_run1_ubcodev06_26_01_22__v4.root") 
analyser.SetBNBPOT(1.65319e+20)    #88601
analyser.SetBNBONTriggers(36749130.19319)    
analyser.SetEXTBNBTriggers(72299264)
analyser.SetFakeDataMode(False)
analyser.SetOverlayMode(True)
# 35388924 bnbon triggers corrspond to 1.592e+20 POT
# and for bnbext we have 72299264, bnbext stays the same
# for bnbon we have to increase the triggers to 35388924/1.592e+20*1.65319e+20 = 36749130.19319
analyser.SetPrefix("cv")
analyser.SetFluxCorrectionWeight(1.028)

extra_unc = math.sqrt(0.02*0.02 + 0.06*0.06 + 0.0699*0.0699) # POT counting, beam window, cosmics (overlay)
analyser.SetExtraUncertainty(extra_unc)

analyser.DoGenieSystematics(False)
analyser.ImportGenieSystematics(False)

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
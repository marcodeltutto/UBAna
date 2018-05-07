import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


# analyser.SetBNBCosmicFile     ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_500k.root") # tune 1
analyser.SetBNBCosmicFile     ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_mc_bnbcosmic_mcc8.9_test6.root") # tune 1 high stat - genie and flux styst (from uboonegpvm)
# analyser.SetBNBCosmicFile     ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # tune 1- genie and flux styst (no high stat)

analyser.SetInTimeCosmicFile  ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder
analyser.SetBNBONFile         ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_mc_bnbcosmic_tune3_mcc8.9_test5.root") # fake data! Tune 3
analyser.SetEXTBNBFile        ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_extbnb_a_mcc8.9_test4.root") 
analyser.SetBNBPOT(3.37162e+20)    
analyser.SetBNBONTriggers(74969877.21)    
analyser.SetEXTBNBTriggers(33320382)
analyser.SetFakeDataMode(True)
# 36177265 bnbon triggers corrspond to 1.627e+20 POT
# and for bnbext we have 33320382, bnbext stays the same
# for bnbon we have to increase the triggers to 36177265/1.627e+20*3.37162e+20 = 74969877.21
analyser.SetPrefix("cv");
analyser.SetFluxCorrectionWeight(1.028)


analyser.DoGenieSystematics(False)
analyser.ImportGenieSystematics(True)

analyser.DoFluxSystematics(False)
analyser.ImportFluxSystematics(False)
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
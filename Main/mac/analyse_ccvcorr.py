import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


analyser.SetBNBCosmicFile     ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.9_500k.root") # tune 1

analyser.SetInTimeCosmicFile  ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder
analyser.SetBNBONFile         ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_data_bnbon_mcc8.9_test11.root")    
analyser.SetEXTBNBFile        ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_data_extbnb_mcc8.9_test11.root")
analyser.SetBNBPOT(3.205e+19);    
analyser.SetBNBONTriggers(7105849)
analyser.SetEXTBNBTriggers(55023644)
analyser.SetPrefix("cv");
# analyser.SetFluxCorrectionWeight(1.028)

analyser.DoGenieSystematics(False)
analyser.ImportGenieSystematics(False)

analyser.DoFluxSystematics(False)
analyser.ImportFluxSystematics(False)
#analyser.SetTargetFluxSystematic("FluxUnisim");
#analyser.SetTargetFluxSystematic("kminus_PrimaryHadronNormalizat");
#analyser.SetTargetFluxSystematic("kplus_PrimaryHadronFeynmanScal");
#analyser.SetTargetFluxSystematic("kzero_PrimaryHadronSanfordWang");
#analyser.SetTargetFluxSystematic("piminus_PrimaryHadronSWCentral");
#analyser.SetTargetFluxSystematic("piplus_PrimaryHadronSWCentralS");
analyser.SetTargetFluxSystematic("total");

analyser.DoAnalise();

raw_input("Please press enter to exit.")
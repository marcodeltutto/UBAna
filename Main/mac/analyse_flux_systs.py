import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


analyser.SetInTimeCosmicFile  ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder
analyser.SetBNBONFile         ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbon_mcc8.7_test6.root")    
analyser.SetEXTBNBFile        ("/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_extbnb_mcc8.7_test6.root")
analyser.SetBNBPOT(4.852e+19);    
analyser.SetBNBONTriggers(10820589);    
analyser.SetEXTBNBTriggers(15482261);
analyser.DoFluxSystematics(True)
analyser.ImportFluxSystematics(False)



# flux_syst_list = ["FluxUnisim", "kminus", "kplus", "kzero", "piminus", "piplus"]
flux_syst_list = ["total"]

for systname in flux_syst_list:
  file_name = "/Users/deltutto/RealWork/CCInclusiveEventSelection/Files/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6_" + systname + ".root"
  analyser.SetBNBCosmicFile(file_name)
  analyser.SetPrefix(systname);
  analyser.SetTargetFluxSystematic(systname)
  analyser.DoAnalise()


raw_input("Please press enter to exit.")
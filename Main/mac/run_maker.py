import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

maker = Main.Maker()



# BNBComisc

# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_mcc8.9_500k.root") # tune 1
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.9_500k.root"); # tune 1
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_tune3_mcc8.9_test5.root") # tune 3
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_tune3_mcc8.9_test5.root"); # tune 3
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_mcc8.7_test6.root"); # tune 1 - genie flux (not high stat)
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root"); # tune 1 - genie flux (not high stat)

# maker.SetInputFile("/uboone/data/users/mdeltutt/ubxsec_static/mcc8.9/ubxsec_output_mc_bnbcosmic_mcc8.9_test6.root") # tune 1 high stat weights (genie syst DIS bugged)
# maker.SetOutputFile("/uboone/data/users/mdeltutt/ubxsec_static/mcc8.9/ubxsecana_output_mc_bnbcosmic_mcc8.9_test6_fluxscaled_new4.root"); # tune 1 high stat weights (genie syst DIS bugged)
# maker.SetOutputFile("/uboone/data/users/mdeltutt/ubxsec_static/mcc8.9/ubxsecana_output_mc_bnbcosmic_mcc8.9_test6_maup_mecoff.root"); # tune 1 high stat weights

# maker.SetInputFile("/uboone/data/users/mdeltutt/ubxsec_static/mcc8.9/ubxsec_output_mc_bnbcosmic_mcc8.9_test6_tune3.root"); # tune 3 with flux syst
# maker.SetOutputFile("/uboone/data/users/mdeltutt/ubxsec_static/mcc8.9/ubxsecana_output_mc_bnbcosmic_mcc8.9_test6_tune3.root"); # tune 3 with flux syst

# maker.SetInputFile("/uboone/data/users/wketchum/det_var_files_Apr19/ubxsec_output_mc_bnbcosmic.root") # wes test
# maker.SetOutputFile("./ubxsecanatemp_output_mc_bnbcosmic.root")
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_mcc8.9_test7.root") # tune 1 mcs symm
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.9_test7.root"); # tune 1 mcs symm

# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_ubcodev06_26_01_18__v2.root"); # After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v2.root"); # After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_ubcodev06_26_01_18__v3.root"); # After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v3.root"); # After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_ubcodev06_26_01_18__v4.root"); # After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v4.root"); # After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_ubcodev06_26_01_18__v5.root"); # After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v5.root"); # After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_ubcodev06_26_01_18__v6.root"); # After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v6.root"); # After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_ubcodev06_26_01_18__v7.root"); # After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v7.root"); # After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_ubcodev06_26_01_18__v9.root"); # After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v9.root"); # After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_ubcodev06_26_01_18__v11.root"); # After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v11.root"); # After Neutrino

maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_ubcodev06_26_01_22__v1.root"); # After Neutrino
maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v1.root"); # After Neutrino

# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbnuecosmic_ubcodev06_26_01_18__v10.root"); # After Neutrino (nue)
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbnuecosmic_ubcodev06_26_01_18__v10.root"); # After Neutrino (nue)

# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_dirt_ox_v1.root"); # Dirt OX v1
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_dirt_ox_v1.root"); # Dirt OX v1

# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_dirt_ubcodev06_26_01_18__v9.root"); # Dirt OX v2
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_18__v9.root"); # Dirt OX v2

# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/Adam/ubxsec_nom.root") # Adam test file nominal
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/Adam/ubxsecana_nom.root") # Adam test file nominal
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/Adam/ubxsec_truthfiltered.root") # Adam test file truthfiltered
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/Adam/ubxsecana_truthfiltered.root") # Adam test file truthfiltered
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_bnbcosmic_ubcodev06_26_01_18__v12.root") # Adam test file truthfiltered
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_18__v12.root") # Adam test file truthfiltered

# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_mc_dirt_ubcodev06_26_01_20__v15.root") # Dirt v15
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_20__v15.root") # Dirt v15

maker.SetEntries(-1)
maker.SetInitialEntry(0)
maker.SetBeamSpillStart(3.1)    
maker.SetBeamSpillEnd(4.9)
# maker.SetBeamSpillStart(3.2)    
# maker.SetBeamSpillEnd(4.8)
maker.SetFlashShift(0.)    
maker.SetGainCalibration(198)    
maker.SetCalculatePOT(True)    
maker.SetIsData(False)
maker.SetExtraWeight(1.028); # Flux correction

# maker.OverrideWithPoissonWeights(True)

maker.SetMaUpMECOff(False)
# maker.ScaleCosmics(0.54548) # For overlay systematics

maker.FillBootstrapGenie(True)

maker.FillBootstrapExtraSyst(False)
maker.SetTargetExtraSystematic("model_q0q3_ccmec_HistogramWeight")
# maker.SetTargetExtraSystematic("model_q0q3_ccqe_HistogramWeight")
# maker.SetTargetExtraSystematic("total")

maker.FillBootstrapFlux(True)
#maker.SetTargetFluxSystematic("FluxUnisim");
#maker.SetTargetFluxSystematic("kminus_PrimaryHadronNormalizat");
#maker.SetTargetFluxSystematic("kplus_PrimaryHadronFeynmanScal");
#maker.SetTargetFluxSystematic("kzero_PrimaryHadronSanfordWang");
#maker.SetTargetFluxSystematic("piminus_PrimaryHadronSWCentral");
#maker.SetTargetFluxSystematic("piplus_PrimaryHadronSWCentralS");
maker.SetTargetFluxSystematic("total")



maker.PrintConfig()

maker.MakeFile()



# BNBON

# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_bnbon_mcc8.7_test6.root") # 5e19
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbon_mcc8.7_test6.root") # 5e19
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_bnbon_a_mcc8.9_test4.root") # 1.6e20
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbon_a_mcc8.9_test4.root") # 1.6e20
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_bnbon_mcc8.9_test8.root") # 1.6e20, 2
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbon_mcc8.9_test8.root") # 1.6e20, 2
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_bnbon_mcc8.9_test7.root")
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbon_mcc8.9_test7.root")
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_bnbon_mcc8.9_test11.root") # 5e19, ccv corr
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_mcc8.9_test11.root") # 5e19, ccv corr

# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_bnbon_ubcodev06_26_01_18__v2.root") # 5e19 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_ubcodev06_26_01_18__v2.root") # 5e19 After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_bnbon_ubcodev06_26_01_18__v3.root") # 5e19 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_ubcodev06_26_01_18__v3.root") # 5e19 After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_bnbon_ubcodev06_26_01_18__v4.root") # 5e19 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_ubcodev06_26_01_18__v4.root") # 5e19 After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_bnbon_ubcodev06_26_01_18__v5.root") # 5e19 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_ubcodev06_26_01_18__v5.root") # 5e19 After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_bnbon_ubcodev06_26_01_18__v11.root") # 5e19 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_ubcodev06_26_01_18__v11.root") # 5e19 After Neutrino

maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_bnbon_run1_ubcodev06_26_01_22__v1.root") # Run1 After Neutrino
maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_run1_ubcodev06_26_01_22__v1.root") # Run1 After Neutrino

maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(5.0) 
# maker.SetBeamSpillStart(3.3)    
# maker.SetBeamSpillEnd(4.9)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(243)    
maker.SetCalculatePOT(False)    
maker.SetIsData(True)

maker.PrintConfig()

maker.MakeFile()



# EXTBNB

# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_mcc8.7_test6.root") # 5e19
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_extbnb_mcc8.7_test6.root") # 5e19
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_a_mcc8.9_test4.root") # 1.6e20
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_extbnb_a_mcc8.9_test4.root") # 1.6e20
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_mcc8.9_test8.root") # 1.6e20, 2
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_extbnb_mcc8.9_test8.root") # 1.6e20, 2
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_mcc8.9_test7.root")
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_extbnb_mcc8.9_test7.root")
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_mcc8.9_test11.root") # 5e19, ccv corr
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_mcc8.9_test11.root") # 5e19, ccv corr

# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_ubcodev06_26_01_18__v2.root") # 5e19 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_ubcodev06_26_01_18__v2.root") # 5e19 After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_ubcodev06_26_01_18__v3.root") # 5e19 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_ubcodev06_26_01_18__v3.root") # 5e19 After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_ubcodev06_26_01_18__v4.root") # 5e19 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_ubcodev06_26_01_18__v4.root") # 5e19 After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_ubcodev06_26_01_18__v5.root") # 5e19 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_ubcodev06_26_01_18__v5.root") # 5e19 After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_ubcodev06_26_01_18__v11.root") # 5e19 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_ubcodev06_26_01_18__v11.root") # 5e19 After Neutrino

maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_run1_ubcodev06_26_01_22__v1.root") # Run1 After Neutrino
maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_run1_ubcodev06_26_01_22__v1.root") # Run1 After Neutrino

# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_ubcodev06_26_01_18__v12.root") 
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_ubcodev06_26_01_18__v12.root") 

maker.SetEntries(-1)
maker.SetBeamSpillStart(3.6)    
maker.SetBeamSpillEnd(5.4) 
# maker.SetBeamSpillStart(3.65)    
# maker.SetBeamSpillEnd(5.25)   
maker.SetFlashShift(0.406)    
maker.SetGainCalibration(243)    
maker.SetCalculatePOT(False)    
maker.SetIsData(True)

maker.PrintConfig()

maker.MakeFile()



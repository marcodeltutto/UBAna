import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

maker = Main.Maker()



# BNBComisc

# maker.SetInputFile("/uboone/data/users/mdeltutt/ubxsec_static/v06_26_01_22/ubxsec_output_mc_bnbcosmic_ubcodev06_26_01_22__v4.root"); # After Neutrino (run on gpvm)
# maker.SetOutputFile("/uboone/data/users/mdeltutt/ubxsec_static/v06_26_01_22/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4.root"); # After Neutrino (run on gpvm)

# maker.SetInputFile("/uboone/data/users/mdeltutt/ubxsec_static/v06_26_01_22/ubxsec_output_mc_dirt_ubcodev06_26_01_22__v3.root"); # After Neutrino - Dirt (run on gpvm)
# maker.SetOutputFile("/uboone/data/users/mdeltutt/ubxsec_static/v06_26_01_22/ubxsecana_output_mc_dirt_ubcodev06_26_01_22__v3.root"); # After Neutrino - Dirt (run on gpvm)

# maker.SetInputFile("/uboone/data/users/mdeltutt/ubxsec_static/v06_26_01_22/ubxsec_output_mc_bnbcosmic_tune3_full_ubcodev06_26_01_22__v3.root"); # After Neutrino - Tune3 (run on gpvm)
# maker.SetOutputFile("/uboone/data/users/mdeltutt/ubxsec_static/v06_26_01_22/ubxsecana_output_mc_bnbcosmic_tune3_full_ubcodev06_26_01_22__v3.root"); # After Neutrino - Tune3 (run on gpvm)

# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_overlay_ubcodev06_26_01_22__v4.root"); # After Neutrino - Overlay
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_overlay_ubcodev06_26_01_22__v4.root"); # After Neutrino - Overlay

# maker.SetEntries(-1)
# maker.SetInitialEntry(0)
# maker.SetBeamSpillStart(3.1)    
# maker.SetBeamSpillEnd(4.9)
# maker.SetFlashShift(0.)    
# maker.SetGainCalibration(198)    
# maker.SetCalculatePOT(True)    
# maker.SetIsData(False)
# maker.SetExtraWeight(1.028); # Flux correction


# maker.SetMaUpMECOff(False)
# maker.ReweighKaons(False)
# # maker.ScaleCosmics(0.54548) # For overlay systematics

# maker.FillBootstrapGenie(False)

# maker.FillBootstrapExtraSyst(False)
# maker.SetTargetExtraSystematic("model_q0q3_ccmec_HistogramWeight")
# # maker.SetTargetExtraSystematic("model_q0q3_ccqe_HistogramWeight")
# # maker.SetTargetExtraSystematic("model_q0q3")
# # maker.SetTargetExtraSystematic("reinteractions_proton")
# # maker.SetTargetExtraSystematic("reinteractions_piplus")
# # maker.SetTargetExtraSystematic("reinteractions_piminus")
# # maker.SetTargetExtraSystematic("total")

# maker.FillBootstrapFlux(False)
# #maker.SetTargetFluxSystematic("FluxUnisim");
# #maker.SetTargetFluxSystematic("kminus_PrimaryHadronNormalizat");
# #maker.SetTargetFluxSystematic("kplus_PrimaryHadronFeynmanScal");
# #maker.SetTargetFluxSystematic("kzero_PrimaryHadronSanfordWang");
# #maker.SetTargetFluxSystematic("piminus_PrimaryHadronSWCentral");
# #maker.SetTargetFluxSystematic("piplus_PrimaryHadronSWCentralS");
# maker.SetTargetFluxSystematic("total")

# maker.FillBootstrapMCStat(False)
# maker.SetNUniversesMCStat(1000)

# maker.PrintConfig()

# maker.MakeFile()



# BNBON

maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_bnbon_run1_ubcodev06_26_01_22__v4.root") # Run1 After Neutrino
maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_run1_ubcodev06_26_01_22__v4.root") # Run1 After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_bnbon_ubcodev06_26_01_22__v4.root") # 5e19 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_ubcodev06_26_01_22__v4.root") # 5e19 After Neutrino

maker.SetEntries(-1)
maker.SetBeamSpillStart(3.2)    
maker.SetBeamSpillEnd(5.0)    
maker.SetFlashShift(0.)    
maker.SetGainCalibration(243)    
maker.SetCalculatePOT(False)    
maker.SetIsData(True)

maker.PrintConfig()

maker.MakeFile()



# EXTBNB

maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_run1_ubcodev06_26_01_22__v4.root") # Run1 After Neutrino
maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_run1_ubcodev06_26_01_22__v4.root") # Run1 After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_ubcodev06_26_01_22__v4.root") # 5e19 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_ubcodev06_26_01_22__v4.root") # 5e19 After Neutrino
 
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_afterAug2_ubcodev06_26_01_22__v4.root") # afterAug2 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_afterAug2_ubcodev06_26_01_22__v4.root") # afterAug2 After Neutrino
# maker.SetInputFile("/Users/deltutto/CCInclusiveFiles/Input/ubxsec_output_data_extbnb_beforeAug2_ubcodev06_26_01_22__v4.root") # beforeAug2 After Neutrino
# maker.SetOutputFile("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_beforeAug2_ubcodev06_26_01_22__v4.root") # beforeAug2 After Neutrino

maker.SetEntries(-1)
maker.SetBeamSpillStart(3.6)    
maker.SetBeamSpillEnd(5.4)    
maker.SetFlashShift(0.406)    
maker.SetGainCalibration(243)    
maker.SetCalculatePOT(False)    
maker.SetIsData(True)

maker.PrintConfig()

maker.MakeFile()



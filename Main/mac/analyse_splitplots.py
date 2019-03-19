import sys, os, math

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v2_nosyst.root") # Tune 1
analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_all.root") # Tune 1 - full stat - full syst



samples = ['anode_anodevtx',  # Vertex in the anode side, pointing at the anode, 0
           'up_anodevtx', # Vertex in the anode side, pointing up, 1
           'down_anodevtx', # Vertex in the anode side, pointing down, 2
           'cathode_anodevtx', # Vertex in the anode side, pointing at the acathode, 3
           'anode_cathodevtx', # Vertex in the cathode side, pointing at the anode, 4
           'up_cathodevtx', # Vertex in the cathode side, pointing up, 5
           'down_cathodevtx', # Vertex in the cathode side, pointing down, 6
           'cathode_cathodevtx', # Vertex in the cathode side, pointing at the cathode, 7
           'anodevtx', # Vertex in the anode side, 8
           'cathodevtx', # Vertex in the cathode side, 9
           'anode', # Pointing at the anode, 10
           'cathode'] # Pointing at the cathode, 11

sample_id = 11


analyser.SetBNBCosmicFile     ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_' + samples[sample_id] + '.root') # Vertex in the anode side, pointing at the anode


# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_anode_anodevtx.root") # Vertex in the anode side, pointing at the anode
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_up_anodevtx.root") # Vertex in the anode side, pointing at up
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_down_anodevtx.root") # Vertex in the anode side, pointing at down
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_cathode_anodevtx.root") # Vertex in the anode side, pointing at the acathode

# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_anode_cathodevtx.root") # Vertex in the cathode side, pointing at the anode
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_up_cathodevtx.root") # Vertex in the cathode side, pointing at up
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_down_cathodevtx.root") # Vertex in the cathode side, pointing at down
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_cathode_cathodevtx.root") # Vertex in the cathode side, pointing at the cathode

# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_anodevtx.root") # Vertex in the anode side
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_cathodevtx.root") # Vertex in the cathode side

# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_anode.root") # Pointing at the anode 
# analyser.SetBNBCosmicFile     ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_cathode.root") # Pointing the cathode 



analyser.SetDirtFile          ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_22__v3_' + samples[sample_id] + '.root')

analyser.SetInTimeCosmicFile  ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder

analyser.SetBNBONFile         ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_run1_ubcodev06_26_01_22__v4_' + samples[sample_id] + '.root')    
analyser.SetEXTBNBFile        ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_run1_ubcodev06_26_01_22__v4_' + samples[sample_id] + '.root')


analyser.SetBNBPOT(1.592e+20)    
analyser.SetBNBONTriggers(35388924.0)   
analyser.SetEXTBNBTriggers(72299264.0)
analyser.SetPrefix("cv")
# analyser.SetPrefix("cv_tune3")
# analyser.SetPrefix("cv_cosmicscaled_overlay_test")
# analyser.SetPrefix("cv_nodirt")
# analyser.SetPrefix("kaonup")
# analyser.SetPrefix("kaondown")
analyser.SetFluxCorrectionWeight(1.028)

analyser.ImportAlternativeMC("xsec_file_cv_tune3.root")

analyser.SetBeamOffSubtraction(False)
analyser.SetBreakdownPlots(False)

extra_unc = math.sqrt(0.02*0.02) # POT counting
analyser.SetExtraUncertainty(extra_unc)

analyser.ImportDetectorSystematics(True)

analyser.ImportCosmicSystematics(True)

analyser.ImportDirtSystematics(True)

analyser.DoGenieSystematics(False)
analyser.ImportGenieSystematics(True)

analyser.DoExtraSystematics(False)
analyser.ImportExtraSystematics(True)

analyser.DoMCStatSystematics(False)
analyser.ImportMCStatSystematics(True)


analyser.DoFluxSystematics(False)
analyser.ImportFluxSystematics(True)
analyser.SetExtraFluxUncertainty(0.)
analyser.SetTargetFluxSystematic("total"); # Other options: "FluxUnisim", "kminus", "kplus", "kzero", "piminus", "piplus"

analyser.DoAnalise();

raw_input("Please press enter to exit.")
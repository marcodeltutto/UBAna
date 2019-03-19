import sys, os, math

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


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

model0 = True
model1 = False
model2 = False



analyser.SetPrefix('split_sample' + samples[sample_id])

analyser.SetBNBCosmicFile     ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_' + samples[sample_id] + '.root') # Vertex in the anode side, pointing at the anode

analyser.SetDirtFile          ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_22__v3_' + samples[sample_id] + '.root')

analyser.SetBNBONFile         ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_run1_ubcodev06_26_01_22__v4_' + samples[sample_id] + '.root')    
analyser.SetEXTBNBFile        ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_run1_ubcodev06_26_01_22__v4_' + samples[sample_id] + '.root')


if model0:
  analyser.SetPrefix("model0")
  analyser.SetBNBCosmicFile     ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_model0.root') # Vertex in the anode side, pointing at the anode
  analyser.SetDirtFile          ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_22__v3_model0.root')
  analyser.SetBNBONFile         ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_run1_ubcodev06_26_01_22__v4.root')    
  analyser.SetEXTBNBFile        ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_run1_ubcodev06_26_01_22__v4.root')

if model1:
  analyser.SetPrefix("model1")
  analyser.SetBNBCosmicFile     ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_model1.root') # Vertex in the anode side, pointing at the anode
  analyser.SetDirtFile          ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_22__v3_model1.root')
  analyser.SetBNBONFile         ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_run1_ubcodev06_26_01_22__v4.root')    
  analyser.SetEXTBNBFile        ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_run1_ubcodev06_26_01_22__v4.root')

if model2:
  analyser.SetPrefix("model2")
  analyser.SetBNBCosmicFile     ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_bnbcosmic_ubcodev06_26_01_22__v4_model2.root') # Vertex in the anode side, pointing at the anode
  analyser.SetDirtFile          ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_mc_dirt_ubcodev06_26_01_22__v3_model2.root')
  analyser.SetBNBONFile         ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_bnbon_run1_ubcodev06_26_01_22__v4.root')    
  analyser.SetEXTBNBFile        ('/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_data_extbnb_run1_ubcodev06_26_01_22__v4.root')



analyser.SetInTimeCosmicFile  ("/Users/deltutto/CCInclusiveFiles/Output/ubxsecana_output_bnbcosmic_mcc8.7_test6.root") # Just a placeholder

analyser.SetBNBPOT(1.592e+20)    
analyser.SetBNBONTriggers(35388924.0)   
analyser.SetEXTBNBTriggers(72299264.0)

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
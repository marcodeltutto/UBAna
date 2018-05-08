/**
 * \file Analyse.h
 *
 * \ingroup Main
 * 
 * \brief Class def header for a class Analyse
 *
 * @author deltutto
 */

/** \addtogroup Main

    @{*/
#ifndef __MAIN_ANALYSE_H__
#define __MAIN_ANALYSE_H__

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <fstream>
#include <math.h>

#include <TRandom1.h>
#include <TSystem.h>
#include <TBrowser.h>
#include <TApplication.h>
#include <TChain.h>
#include "TThread.h"
#include "THStack.h"
#include "TLegend.h"
#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include "TGraph.h"
#include <TString.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TLatex.h>
#include <TCanvas.h>

#include "UBXSecEvent.h"
#include "ubana/Base/BootstrapTH1D.h"
#include "ubana/Base/BootstrapTH2D.h"
#include "ubana/Base/PlottingTools.h"
#include "ubana/Base/CrossSectionCalculator1D.h"
#include "ubana/Base/MigrationMatrix2D.h"
#include "ubana/Base/MigrationMatrix4D.h"
#include "ubana/Base/CrossSectionCalculator2D.h"
#include "ubana/Base/ReweightingPlotter.h"
#include "ubana/Base/CovarianceCalculator2D.h"
#include "ubana/Base/CrossSectionBootstrapCalculator1D.h"

using namespace Base;

namespace Main {

  /**
     \class Analyse
     User defined class Analyse ... these comments are used to generate
     doxygen documentation!
  */
  class Analyse{
    
  public:
    
    /// Default constructor
    Analyse(){}
    
    /// Default destructor
    ~Analyse(){}

    ///
    void SetBNBCosmicFile(std::string f);
   
    ///
    void SetInTimeCosmicFile(std::string f);

    ///
    void SetBNBONFile(std::string f);

    ///
    void SetEXTBNBFile(std::string f);
 
    ///
    void SetBNBPOT(double v);

    ///
    void SetBNBONTriggers(double v);

    ///
    void SetEXTBNBTriggers(double v);

    ///
    void SetTargetFluxSystematic(std::string);

    ///
    void SetPrefix(std::string);

    /// Calculates the flux covariance matrix and saves it to a file for a particular flux syst
    void DoFluxSystematics(bool option) {_do_flux_systs = option;}

    /// Imports all the flux systs from files (previously calculated via DoFluxSystematics, and adds them togheter)
    void ImportFluxSystematics(bool option, std::string file = "file.root") {_import_flux_systs = option; _flux_syst_file = file;}

    /// Imports all the detector systs from files (previously calculated via external macro, and adds them togheter)
    void ImportDetectorSystematics(bool option, std::string file = "file.root") {_import_detector_systs = option; _detector_syst_file = file;}

    /// Calculates the genie covariance matrix and saves it to a file for a particular flux syst
    void DoGenieSystematics(bool option) {_do_genie_systs = option;}

    /// Imports all the genie systs from files (previously calculated via DoFluxSystematics, and adds them togheter)
    void ImportGenieSystematics(bool option, std::string file = "file.root") {_import_genie_systs = option; _genie_syst_file = file;}

    ///
    void DrawDataMC(TCanvas *c, THStack *hs_mc, double scale_factor_mc_bnbcosmic, bool breakdown_plots, std::map<std::string,TH1D*> hmap_mc, TH1D* h_data_bnbon, double bnbon_pot_meas);

    ///
    void PlotMCTHStack(THStack *hs_trklen, std::map<std::string,TH1D*> themap, double scale_factor_mc_bnbcosmic);

    ///
    void SetFakeDataMode(bool option = false) {_fake_data_mode = option;};

    ///
    void SetOverlayMode(bool option = false) {_overlay_mode = option;};

    ///
    void SetFluxCorrectionWeight(double w) {_flux_correction_weight = w;};

    ///
    void PrintFakeDataMessage();

    ///
    void SetBeamOffSubtraction(bool option = false) {_beamoff_sub = option;};

    ///
    void DoAnalise();

  private:

    bool _calculate_xsec = true;
    bool _do_pm1sigma_plots = false;
    bool _do_reweighting_plots = true;

    std::string mc_bnbcosmic_file_name     = "ubxsecana_output.root";
    std::string mc_intimecosmic_file_name  = "ubxsecana_output.root";
    std::string bnbon_file_name            = "ubxsecana_output.root";
    std::string extbnb_file_name           = "ubxsecana_output.root";
    double bnbon_pot_meas        = -1;
    double bnbon_triggers        = -1;
    double extbnb_triggers       = -1;

    bool _do_flux_systs = false;
    std::string _target_flux_syst = "";
    bool _import_flux_systs = false;
    std::string _flux_syst_file = "";
    bool _import_detector_systs = false;
    std::string _detector_syst_file = "";

    bool _do_genie_systs = false;
    bool _import_genie_systs = false;
    std::string _genie_syst_file;

    bool _fake_data_mode = false;
    bool _overlay_mode = false;

    bool _beamoff_sub = false;

    std::string _prefix = "";

    double _flux_correction_weight = 1.; ///< Flux correction weight
    
  };
}

#endif
/** @} */ // end of doxygen group 


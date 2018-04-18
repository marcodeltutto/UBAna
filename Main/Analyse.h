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
    void ImportFluxSystematics(bool option) {_import_flux_systs = option;}

    /// Calculates the flux covariance matrix and saves it to a file for a particular flux syst
    void DoGenieSystematics(bool option) {_do_genie_systs = option;}

    ///
    void DrawDataMC(TCanvas *c, THStack *hs_mc, double scale_factor_mc_bnbcosmic, bool breakdown_plots, std::map<std::string,TH1D*> hmap_mc, TH1D* h_data_bnbon, double bnbon_pot_meas);

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

    bool _do_flux_systs = true;
    std::string _target_flux_syst = "";
    bool _import_flux_systs = false;

    bool _do_genie_systs = false;

    std::string _prefix = "";
    
  };
}

#endif
/** @} */ // end of doxygen group 


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
#include "ubana/Base/CrossSectionBootstrapCalculator2D.h"

#include "ubana/Base/LoggerFeature.h"

using namespace Base;

namespace Main {

  /**
     \class Analyse
     User defined class Analyse ... these comments are used to generate
     doxygen documentation!
  */
  class Analyse : public LoggerFeature{
    
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
    void SetDirtFile(std::string f);

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

    /// Calculates the genie multisim covariance matrix and saves it to a file for a particular flux syst
    void DoGenieSystematics(bool option) {_do_genie_systs = option;}

    /// Calculates the genie models covariance matrix and saves it to a file for a particular flux syst
    void DoGenieModelsSystematics(bool option) {_do_genie_models_systs = option;}

    /// Imports all the genie multisim systs from files (previously calculated via DoFluxSystematics, and adds them togheter)
    void ImportGenieSystematics(bool option, std::string file = "file.root") {_import_genie_systs = option; _genie_syst_file = file;}

    /// Imports all the genie models systs from files (previously calculated via DoFluxSystematics, and adds them togheter)
    void ImportGenieModelsSystematics(bool option, std::string file = "file.root") {_import_genie_models_systs = option; _genie_models_syst_file = file;}

    /// Imports the cosmic systs from files (previously calculated via external macro, and adds them togheter)
    void ImportCosmicSystematics(bool option, std::string file = "file.root") {_import_cosmic_systs = option; _cosmic_syst_file = file;}

    /// Imports the dirt systs from files (previously calculated via external macro, and adds them togheter)
    void ImportDirtSystematics(bool option, std::string file = "file.root") {_import_dirt_systs = option; _dirt_syst_file = file;}

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
    void SetBreakdownPlots(bool option = false) {_breakdown_plots = option;};

    ///
    void ImportAlternativeMC(std::string filen = "xsec_file_cv_tune3.root") {_import_alternative_mc = true; _alternative_mc_file = filen;};

    /// Sets an extra uncertainty on the diagonal of the flux covariance matrix
    void SetExtraFluxUncertainty(double unc) {_extra_flux_fractional_uncertainty = unc;};

    /// Sets an extra uncertainty on the diagonal of the total covariance matrix
    void SetExtraUncertainty(double unc) {_extra_fractional_uncertainty = unc;};

    ///
    void DoAnalise();

  private:

    bool _calculate_xsec = true;
    bool _do_pm1sigma_plots = false;
    bool _do_reweighting_plots = true;

    std::string mc_bnbcosmic_file_name     = "ubxsecana_output.root";
    std::string mc_intimecosmic_file_name  = "ubxsecana_output.root";
    std::string mc_dirt_file_name          = "ubxsecana_output.root";
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

    bool _import_cosmic_systs = false;
    std::string _cosmic_syst_file = "";

    bool _import_dirt_systs = false;
    std::string _dirt_syst_file = "";

    bool _do_genie_systs = false;
    bool _import_genie_systs = false;
    std::string _genie_syst_file;

    bool _do_genie_models_systs = false;
    bool _import_genie_models_systs = false;
    std::string _genie_models_syst_file;

    bool _fake_data_mode = false;
    bool _overlay_mode = false;

    bool _beamoff_sub = false;

    bool _breakdown_plots = true;

    std::string _prefix = "";

    double _flux_correction_weight = 1.; ///< Flux correction weight

    bool _import_alternative_mc = false;
    std::string _alternative_mc_file = ""; ///< The name of the root file that contains the alternative MC 

    double _extra_flux_fractional_uncertainty = 0.; ///< Adds an extra uncertainty on the diagonal of the flux covariance matrix
    double _extra_fractional_uncertainty = 0.; ///< Adds an extra uncertainty on the diagonal of the total covariance matrix



  std::map<std::string,TH1D*> hmap_trklen_mc_dirt;
  std::map<std::string,TH1D*> hmap_onebin_mc_dirt;
  std::map<std::string,TH1D*> hmap_trkmom_mc_dirt;
  std::map<std::string,TH1D*> hmap_trkmom_classic_mc_dirt;
  std::map<std::string,TH1D*> hmap_trktheta_mc_dirt;
  std::map<std::string,TH1D*> hmap_trktheta_classic_mc_dirt;
  std::map<std::string,TH1D*> hmap_trkphi_mc_dirt;
  std::map<std::string,TH1D*> hmap_multpfp_mc_dirt;
  std::map<std::string,TH1D*> hmap_multtracktol_mc_dirt;
  std::map<std::string,TH1D*> hmap_xdiff_b_mc_dirt;
  std::map<std::string,TH1D*> hmap_zdiff_b_mc_dirt;
  std::map<std::string,TH1D*> hmap_xdiff_mc_dirt;
  std::map<std::string,TH1D*> hmap_zdiff_mc_dirt;
  std::map<std::string,TH1D*> hmap_vtxx_mc_dirt;
  std::map<std::string,TH1D*> hmap_vtxy_mc_dirt;
  std::map<std::string,TH1D*> hmap_vtxz_mc_dirt;
  std::map<std::string,TH1D*> hmap_vtxz_upborder_mc_dirt;
  std::map<std::string,TH1D*> hmap_vtxx_upborder_mc_dirt;
  std::map<std::string,TH1D*> hmap_flsmatch_score_mc_dirt;
  std::map<std::string,TH1D*> hmap_flsmatch_score_second_mc_dirt;
  std::map<std::string,TH1D*> hmap_flsmatch_score_difference_mc_dirt;
  std::map<std::string,TH1D*> hmap_ntpcobj_mc_dirt;
  std::map<std::string,TH1D*> hmap_vtxcheck_angle_mc_dirt;
  std::map<std::string,TH1D*> hmap_residuals_std_mc_dirt;
  std::map<std::string,TH1D*> hmap_residuals_mean_mc_dirt;
  std::map<std::string,TH1D*> hmap_perc_used_hits_mc_dirt;
  std::map<std::string,TH1D*> hmap_mom_mcs_length_mc_dirt;
  std::map<std::string,TH1D*> hmap_mctruth_nuenergy_mc_dirt;
  std::map<std::string,TH1D*> hmap_mctruth_mumom_mc_dirt;
  std::map<std::string,TH1D*> hmap_mctruth_mucostheta_mc_dirt;
  std::map<std::string,TH1D*> hmap_mctruth_muphi_mc_dirt;
  std::map<std::string,TH1D*> hmap_mctruth_nuenergy_gen_mc_dirt;
  std::map<std::string,TH1D*> hmap_mctruth_mumom_gen_mc_dirt;
  std::map<std::string,TH1D*> hmap_mctruth_mucostheta_gen_mc_dirt;
  std::map<std::string,TH1D*> hmap_mctruth_muphi_gen_mc_dirt;
    
  };
}

#endif
/** @} */ // end of doxygen group 


/**
 * \file Maker.h
 *
 * \ingroup Main
 * 
 * \brief Class def header for a class Maker
 *
 * @author deltutto
 */

/** \addtogroup Main

    @{*/
#ifndef __MAIN_MAKER_H__
#define __MAIN_MAKER_H__

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
#include <algorithm>

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
#include "TMath.h"

#include "UBXSecEvent.h"
#include "ubana/Base/BootstrapTH1D.h"
#include "ubana/Base/BootstrapTH2D.h"
#include "ubana/Base/PlottingTools.h"

namespace Main {

  /**
     \class Maker
     User defined class Maker ... these comments are used to generate
     doxygen documentation!
  */
  class Maker{
    
  public:
    
    /// Default constructor
    Maker(){}
    
    /// Default destructor
    ~Maker(){}

    ///
    void MakeFile();

    ///
    void SetInputFile(std::string);

    ///
    void SetOutputFile(std::string);

    /// Sets the number of entries to loop over (-1: all entries)
    void SetEntries(int);

    /// Sets the first entry that will be used in the tree loop (default is 0)
    void SetInitialEntry(int);

    ///
    void SetBeamSpillStart(double);

    ///
    void SetBeamSpillEnd(double);

    ///
    void SetFlashShift(double);

    ///
    void SetGainCalibration(double);

    ///
    void SetCalculatePOT(bool);

    ///
    void SetIsData(bool);

    ///
    void SetTargetFluxSystematic(std::string);

    ///
    void SetMaUpMECOff(bool option) {_maup_mecoff = option;};

    ///
    void PrintMaUpMECOff();

    ///
    void PrintConfig();

    /// 
    void SetExtraWeight(double w) {_extra_weight = w;};

    ///
    void ScaleCosmics(double w) {_scale_cosmics = true; _scale_factor_cosmic = w;};

    ///
    void FillBootstrapFlux(bool option) {_fill_bootstrap_flux = option;}

    ///
    void FillBootstrapGenie(bool option) {_fill_bootstrap_genie = option;}


  private:

    void DrawProgressBar(double progress, double barWidth);

    void DrawPOT2(double pot, double target = 6.6e20);

    double eff_uncertainty(int _n, int _N);

    void FillBootstrap(double fill_value,
                   double evt_wgt,
                   std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_genie_pm1_bs, 
                   std::string channel_namel, 
                   std::vector<std::string> fname, 
                   std::vector<double> wgts_genie);

    void FillBootstrap(double fill_value1,
                   double fill_value2,
                   double evt_wgt,
                   std::map<std::string,std::map<std::string,TH2D*>> hmap_trkmom_genie_pm1_bs, 
                   std::string channel_namel, 
                   std::vector<std::string> fname, 
                   std::vector<double> wgts_genie);

    // void FillBootstrap(double fill_value,
    //                std::map<std::string,TH1D*> hmap_trkmom_genie_pm1_bs, 
    //                std::vector<std::string> fname, 
    //                std::vector<double> wgts_genie);

    void FillBootstrap(double fill_value1,
                   double fill_value2,
                   double evt_wgt,
                   std::map<std::string,TH2D*> hmap_trkmom_genie_pm1_bs, 
                   std::vector<std::string> fname, 
                   std::vector<double> wgts_genie);

    bool _maup_mecoff = false;

    const bool _breakdownPlots = true;
    const bool _makePlots = false;

    //const bool _fill_bootstrap = true;
    bool _fill_bootstrap_flux = false;
    bool _fill_bootstrap_genie = false;

    std::string _target_flux_syst = "";

    const bool _check_duplicate_events = false;

    double _beamSpillStarts = 3.2;  // us
    double _beamSpillEnds   = 4.8;  // us
    double _flashShift      = 0.;   //4.06; //us
    double _gainCalib       = 198;  // e-/ADC

    std::string filen     = "ubxsec_output.root";
    std::string fileoutn  = "ubxsecana_output.root";
    bool evalPOT          = false;
    int maxEntries        = -1;
    int _initial_entry    = 0; ///< Entry in Tree to begin with
    bool isdata           = false;

    double _extra_weight = 1.; ///Extra weight to be applied to the events

    const double _pe_cut = 50;

    const double targetPOT = 4.95e19;

    double bins_mumom[7] = {0.00, 0.18, 0.30, 0.45, 0.77, 1.28, 2.50};
    double bins_mucostheta[10] = {-1.00, -0.50, 0.00, 0.27, 0.45, 0.62, 0.76, 0.86, 0.94, 1.00};
    // double bins_mumom[21] = {0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1, 1.125, 1.25, 1.375, 1.5, 1.625, 1.75, 1.875, 2, 2.125, 2.25, 2.375, 2.5};
    // double bins_mucostheta[26] = {-1, -0.92, -0.84, -0.76, -0.68, -0.6, -0.52, -0.44, -0.36, -0.28, -0.2, -0.12, -0.04, 0.04, 0.12, 0.2, 0.28, 0.36, 0.44, 0.52, 0.6, 0.68, 0.76, 0.84, 0.92, 1};

    int n_bins_mumom = 6;
    int n_bins_mucostheta = 9;
    // int n_bins_mumom = 20;
    // int n_bins_mucostheta = 25;

    bool _scale_cosmics = false; ///< If true scales the cosmic background by _scale_factor_cosmic
    double _scale_factor_cosmic = 1.; ///< Factor used to scale the cosmic background (used only if _scale_cosmics is true)


    // These variables are filled in the reco-true TTree in the code
    double _mom_true, _mom_mcs;
    bool _contained, _selected;
    double _angle_true, _angle_reco;
    std::vector<std::string> _wgtsnames_genie_multisim;
    std::vector<double> _wgts_genie_multisim;
    std::vector<std::string> _wgtsnames_flux_multisim;
    std::vector<double> _wgts_flux_multisim;
    
  };
}

#endif
/** @} */ // end of doxygen group 


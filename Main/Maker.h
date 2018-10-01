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
#include "TH2Poly.h"

#include "ubana/DataTypes/UBTH2Poly.h"
#include "ubana/DataTypes/BootstrapTH2DPoly.h"
#include "ubana/DataTypes/UBXSecEventHisto.h"

#include "UBXSecEvent.h"
#include "ubana/DataTypes/BootstrapTH1D.h"
#include "ubana/DataTypes/BootstrapTH2D.h"
#include "ubana/Base/PlottingTools.h"

#include "ubana/Base/LoggerFeature.h"

using namespace DataTypes;
using namespace Base;

namespace Main{

  /**
     \class Maker
     User defined class Maker ... these comments are used to generate
     doxygen documentation!
  */
  class Maker : public LoggerFeature {
    
  public:
    
    /// Default constructor
    Maker(std::string name = "Maker") 
    : LoggerFeature(name) {}
    
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

    ///
    void FillBootstrapExtraSyst(bool option) {_fill_bootstrap_extra_syst = option;}

    ///
    void FillBootstrapMCStat(bool option) {_fill_bootstrap_mc_stat = option;}

    ///
    void SetTargetFluxSystematic(std::string s) { _target_flux_syst = s; }

    ///
    void SetTargetExtraSystematic(std::string s) { _extra_syst_target_syst = s; }


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

    void FillBootstrap(double fill_value1, // reco value x (costheta)
                       double fill_value2, // reco value y (momentum)
                       int m, // true bin m (costheta)
                       int n, // true bin n (momentum)
                       double evt_wgt,
                       std::map<std::string,std::vector<std::vector<TH2D*>>> bs_reco_per_true, 
                       std::vector<std::string> fname, 
                       std::vector<double> wgts);

    void FillBootstrap(double fill_value1, // reco value x (costheta)
                       double fill_value2, // reco value y (momentum)
                       int n, // true bin n (1 number, unrolled)
                       double evt_wgt,
                       std::map<std::string,std::vector<UBTH2Poly*>> bs_poly_reco_per_true, 
                       std::vector<std::string> fname, 
                       std::vector<double> wgts);
    
    // void FillBootstrap(double fill_value1, // reco value x (costheta)
    //                    double fill_value2, // reco value y (momentum)
    //                    int n, // true bin n (1 number, unrolled)
    //                    double evt_wgt,
    //                    std::vector<std::vector<UBTH2Poly*>> bs_poly_reco_per_true, 
    //                    std::vector<std::string> fname, 
    //                    std::vector<double> wgts);

    void FillBootstrap(int m, // true bin m (1 number, unrolled)
                                int j, // reco bin i (1 number, unrolled)
                                double evt_wgt,
                                std::map<std::string,std::vector<std::vector<double>>> &bs_poly_reco_per_true, 
                                std::vector<std::string> fname, 
                                std::vector<double> wgts);

    void FillBootstrap(double fill_value1,
                       double fill_value2,
                       double evt_wgt,
                       std::map<std::string,std::map<std::string,UBTH2Poly*>> hmap, 
                       std::string channel_namel, 
                       std::vector<std::string> fname, 
                       std::vector<double> wgts_genie);

    void AddPolyBins(UBTH2Poly * h);

    void AddPolyBins(BootstrapTH2DPoly h);

    UBXSecEventHisto * _event_histo;



    bool _maup_mecoff = false;

    const bool _breakdownPlots = true;
    const bool _makePlots = false;

    //const bool _fill_bootstrap = true;
    bool _fill_bootstrap_flux = false;
    bool _fill_bootstrap_genie = false;
    bool _fill_bootstrap_extra_syst = false;

    std::string _target_flux_syst = "";
    std::string _extra_syst_target_syst = "";

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

    int n_bins_mumom = 6;
    int n_bins_mucostheta = 9;

    // int n_bins_double_mumom = 4; ///< Number of momentum bins for double differential
    // double bins_double_mumom[5] = {0.00, 0.25, 0.50, 1.0, 2.50}; ///< Momentum bins for double differential
    int n_bins_double_mumom = 6; ///< Number of momentum bins for double differential
    double bins_double_mumom[7] = {0.00, 0.18, 0.30, 0.45, 0.77, 1.28, 2.50}; ///< Momentum bins for double differential
    // int n_bins_double_mumom = 4; ///< Number of momentum bins for double differential
    // double bins_double_mumom[7] = {0.00, 0.30, 0.45, 0.77, 2.50}; ///< Momentum bins for double differential
    // int n_bins_double_mumom = 5; ///< Number of momentum bins for double differential
    // double bins_double_mumom[6] = {0.00, 0.25, 0.50, 0.85, 1.40, 2.50}; ///< Momentum bins for double differential

    // int n_bins_double_mucostheta = 6; ///< Number of costheta bins for double differential
    // double bins_double_mucostheta[7] = {-1.00, -0.50, 0.00, 0.25, 0.50, 0.75, 1.00}; ///< costheta bins for double differential
    // int n_bins_double_mucostheta = 8; ///< Number of costheta bins for double differential
    // double bins_double_mucostheta[10] = {-1.00, 0.00, 0.27, 0.45, 0.62, 0.76, 0.86, 0.94, 1.00}; ///< costheta bins for double differential
    int n_bins_double_mucostheta = 9; ///< Number of costheta bins for double differential
    double bins_double_mucostheta[10] = {-1.00, -0.50, 0.00, 0.27, 0.45, 0.62, 0.76, 0.86, 0.94, 1.00}; ///< costheta bins for double differential

    int _n_poly_bins = 53;
    std::map<int, std::pair<int, int>> _exclusion_map = { {0, std::make_pair(4, 5)},
                                                          {1, std::make_pair(4, 5)}, };

    bool _scale_cosmics = false; ///< If true scales the cosmic background by _scale_factor_cosmic
    double _scale_factor_cosmic = 1.; ///< Factor used to scale the cosmic background (used only if _scale_cosmics is true)


    // These variables are filled in the reco-true TTree in the code
    double _mom_true, _mom_mcs;
    bool _contained, _selected;
    double _angle_true, _angle_reco;
    double _event_weight_fortree;
    std::vector<std::string> _wgtsnames_genie_multisim;
    std::vector<double> _wgts_genie_multisim;
    std::vector<std::string> _wgtsnames_extra_syst;
    std::vector<double> _wgts_extra_syst;
    std::vector<std::string> _wgtsnames_flux_multisim;
    std::vector<double> _wgts_flux_multisim;


    bool _fill_bootstrap_mc_stat = false; ///< If true, fills bootstrap with poisson weights
    int _mc_stat_n_events = 100;

    TRandom _random_engine; ///< The engine to generate random numbers
    
  };
}

#endif
/** @} */ // end of doxygen group 


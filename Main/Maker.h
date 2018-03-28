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

    ///
    void SetEntries(int);

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
    void PrintConfig();


  private:

    void DrawProgressBar(double progress, double barWidth);

    void DrawPOT2(double pot, double target = 6.6e20);

    double eff_uncertainty(int _n, int _N);

    void FillBootstrap(double fill_value,
                   std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_genie_pm1_bs, 
                   std::string channel_namel, 
                   std::vector<std::string> fname, 
                   std::vector<double> wgts_genie);

    void FillBootstrap(double fill_value,
                   std::map<std::string,TH1D*> hmap_trkmom_genie_pm1_bs, 
                   std::vector<std::string> fname, 
                   std::vector<double> wgts_genie);

    void FillBootstrap(double fill_value1,
                   double fill_value2,
                   std::map<std::string,TH2D*> hmap_trkmom_genie_pm1_bs, 
                   std::vector<std::string> fname, 
                   std::vector<double> wgts_genie);

    const bool _breakdownPlots = true;
    const bool _makePlots = false;
    const bool _fill_bootstrap = true;
    const bool  _fill_bootstrap_flux = false;
    const bool _check_duplicate_events = false;

    double _beamSpillStarts = 3.2;  // us
    double _beamSpillEnds   = 4.8;  // us
    double _flashShift      = 0.;   //4.06; //us
    double _gainCalib       = 198;  // e-/ADC

    std::string filen     = "ubxsec_output.root";
    std::string fileoutn  = "ubxsecana_output.root";
    bool evalPOT          = false;
    int maxEntries        = -1;
    bool isdata           = false;

    const double _pe_cut = 50;

    const double targetPOT = 4.95e19;
    
  };
}

#endif
/** @} */ // end of doxygen group 


/**
 * \file PlottingTools.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class PlottingTools
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_PLOTTINGTOOLS_H__
#define __BASE_PLOTTINGTOOLS_H__



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
#include <iomanip>

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




namespace Base {

  /**
     \class PlottingTools
     User defined class PlottingTools ... these comments are used to generate
     doxygen documentation!
  */
  class PlottingTools{
    
  public:
    
    /// Default constructor
    PlottingTools(){}
    
    /// Default destructor
    ~PlottingTools(){}

    ///
    static void DrawPreliminary();

    ///
    static void DrawPreliminaryXSec();

    ///
    static void DrawSimulation();

    ///
    static void DrawSimulationXSec();

    ///
    static void DrawOverlay();

    ///
    static void DrawPOT(double pot);

    ///
    static void DrawSimPOT(double pot, double target);

    ///
    static void DrawPOTRatio(double pot);

    ///
    static void DrawProgressBar(double progress, double barWidth, std::string message);

    ///
    static TLegend* DrawTHStack(THStack *hs_trklen,
                   double pot_scaling,
                   bool _breakdownPlots,
                   std::map<std::string,TH1D*> themap);

    ///
    static TLegend* DrawTHStack2D(THStack *hs_trklen,
                   double pot_scaling,
                   bool _breakdownPlots,
                   std::map<std::string,TH2D*> themap);

    ///
    static TLegend* DrawTHStack2(THStack *hs_trklen,
                  double pot_scaling,
                  bool _breakdownPlots,
                  std::map<std::string,TH1D*> themap);

    ///
    static TLegend* DrawTHStack3(THStack *hs_trklen,
                      double pot_scaling,
                      bool _breakdownPlots,
                      std::map<std::string,TH1D*> themap);

    ///
    static void PlotMCTHStack(THStack *hs_trklen, std::map<std::string,TH1D*> themap);

    ///
    static void DrawDataHisto(TH1D* histo);

    ///
    static void DrawDataHisto2D(TH2D* histo);
    
  };
}

#endif
/** @} */ // end of doxygen group 


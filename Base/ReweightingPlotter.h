/**
 * \file ReweightingPlotter.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class ReweightingPlotter
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_REWEIGHTINGPLOTTER_H__
#define __BASE_REWEIGHTINGPLOTTER_H__

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <map>
#include <time.h>
#include <iomanip>
#include <fstream>

#include <TSystem.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TLatex.h>
#include <TRandom1.h>
#include <TSystem.h>
#include <TBrowser.h>
#include <TApplication.h>
#include <TChain.h>
#include "TThread.h"
#include "THStack.h"
#include "TLegend.h"
#include "TEfficiency.h"
#include "TGraph.h"
#include <TString.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TMath.h>
#include "Math/SMatrix.h"
#include "TMatrix.h"
#include "TGraphAsymmErrors.h"
#include "TRandom.h"
#include "TRotation.h"
#include "TPad.h"
#include "TGaxis.h"
#include "TLine.h"

#include "ubana/DataTypes/BootstrapTH1D.h"

using namespace DataTypes;

namespace Base {

  /**
     \class ReweightingPlotter
     User defined class ReweightingPlotter ... these comments are used to generate
     doxygen documentation!
  */
  class ReweightingPlotter{
    
  public:
    
    /// Default constructor
    ReweightingPlotter(){}
    
    /// Default destructor
    ~ReweightingPlotter(){}

    ///
    void SetEventBootstrapMap(std::map<std::string, BootstrapTH1D>);

    ///
    void SetEfficiencyBootstraps(BootstrapTH1D, BootstrapTH1D);

    ///
    void SetXSecBootstrap(BootstrapTH1D);

    ///
    void MakePlots(int option = 2, bool normalised = false, bool makeLatex = false);

    ///
    void MakeBackgroundPlots(int variable = 0, bool normalised = false, bool makeLatex = false);

    ///
    void MakeXsecDiffPlots(bool makeLaTeX = false);

  private:

    std::string _name = "[ReweightingPlotter] ";

    bool _configured = false;

    std::map<std::string, BootstrapTH1D> _map_bs;
    BootstrapTH1D _bs_eff_num;
    BootstrapTH1D _bs_eff_den;
    BootstrapTH1D _bs_xsec;

    ///
    TString GetLegendName(std::string fName);
    
  };
}

#endif
/** @} */ // end of doxygen group 


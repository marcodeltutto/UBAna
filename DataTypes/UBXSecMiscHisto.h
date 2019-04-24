/**
 * \file UBXSecMiscHisto.h
 *
 * \ingroup DataTypes
 * 
 * \brief Class def header for a class UBXSecMiscHisto
 *
 * @author deltutto
 */

/** \addtogroup DataTypes

    @{*/
#ifndef __DATATYPES_UBXSECMISCHISTO_H__
#define __DATATYPES_UBXSECMISCHISTO_H__

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

#include <TChain.h>
#include "THStack.h"
#include "TLegend.h"
#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include "TGraph.h"
#include <TString.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TLatex.h>
#include <TCanvas.h>
#include <TFile.h>
#include "TH2Poly.h"

#include "UBTH2Poly.h"
#include "BootstrapTH1D.h"
#include "BootstrapTH2D.h"
#include "BootstrapTH2DPoly.h"

namespace DataTypes {

  /**
     \class UBXSecMiscHisto
     User defined class UBXSecMiscHisto ... these comments are used to generate
     doxygen documentation!
  */
  class UBXSecMiscHisto{
    
  public:
    
    /// Default constructor
    UBXSecMiscHisto() {}
    
    /// Default destructor
    ~UBXSecMiscHisto(){}

    ///
    void Initialize();


    //
    // Truth histograms stacked in interaction type - Selected
    //
    std::map<std::string,TH1D*> hmap_mctruth_nuenergy;
    std::map<std::string,TH1D*> hmap_mctruth_mumom;
    std::map<std::string,TH1D*> hmap_mctruth_mucostheta;
    std::map<std::string,TH1D*> hmap_mctruth_muphi;
  

    //
    // Truth histograms stacked in interaction type - Generated
    //
    std::map<std::string,TH1D*> hmap_mctruth_nuenergy_gen;
    std::map<std::string,TH1D*> hmap_mctruth_mumom_gen;
    std::map<std::string,TH1D*> hmap_mctruth_mucostheta_gen;
    std::map<std::string,TH1D*> hmap_mctruth_muphi_gen;
 




   

  protected:


    
  };
}

#endif
/** @} */ // end of doxygen group 


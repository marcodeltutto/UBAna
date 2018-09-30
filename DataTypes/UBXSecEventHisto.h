/**
 * \file UBXSecEventHisto.h
 *
 * \ingroup DataTypes
 * 
 * \brief Class def header for a class UBXSecEventHisto
 *
 * @author deltutto
 */

/** \addtogroup DataTypes

    @{*/
#ifndef __DATATYPES_UBXSECEVENTHISTO_H__
#define __DATATYPES_UBXSECEVENTHISTO_H__

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
#include "BootstrapTH2DPoly.h"

namespace DataTypes {

  /**
     \class UBXSecEventHisto
     User defined class UBXSecEventHisto ... these comments are used to generate
     doxygen documentation!
  */
  class UBXSecEventHisto{
    
  public:
    
    /// Default constructor
    UBXSecEventHisto() {}
    
    /// Default destructor
    ~UBXSecEventHisto(){}

    ///
    void InitializeBootstraps();

    ///
    void OpenFile(std::string name);

    ///
    void SaveToFile();

    ///
    void AddPolyBins();




    int _n_bins_double_mumom = 6; ///< Number of momentum bins for double differential
    int _n_bins_double_mucostheta = 9; ///< Number of costheta bins for double differential

    // double _bins_double_mumom[7] = {0.00, 0.18, 0.30, 0.45, 0.77, 1.28, 2.50}; ///< Momentum bins for double differential
    // double _bins_double_mucostheta[10] = {-1.00, -0.50, 0.00, 0.27, 0.45, 0.62, 0.76, 0.86, 0.94, 1.00}; ///< costheta bins for double differential

    double _bins_double_mumom[7] = {0.00, 0.18, 0.30, 0.45, 0.77, 1.28, 2.50}; //!
    double _bins_double_mucostheta[10] = {-1.00, -0.50, 0.00, 0.27, 0.45, 0.62, 0.76, 0.86, 0.94, 1.00}; //!

    int _n_poly_bins = 53;
    std::map<int, std::pair<int, int>> _exclusion_map = { {0, std::make_pair(4, 5)},
                                                          {1, std::make_pair(4, 5)}, }; //!


    BootstrapTH2DPoly * bs_genie_multisim_eff_poly_muangle_mumom_num = 0; ///< Efficiency Numerator - Double Differential PolyBins - Genie Multisim
    BootstrapTH2DPoly * bs_genie_multisim_eff_poly_muangle_mumom_den = 0; ///< Efficiency Denominator - Double Differential PolyBins - Genie Multisim
    BootstrapTH2DPoly * bs_flux_multisim_eff_poly_muangle_mumom_num = 0; ///< Efficiency Numerator - Double Differential PolyBins - Flux Multisim
    BootstrapTH2DPoly * bs_flux_multisim_eff_poly_muangle_mumom_den = 0; ///< Efficiency Denominator - Double Differential PolyBins - Flux Multisim
    BootstrapTH2DPoly * bs_extra_syst_multisim_eff_poly_muangle_mumom_num = 0; ///< Efficiency Numerator - Double Differential PolyBins - Extra Syst
    BootstrapTH2DPoly * bs_extra_syst_multisim_eff_poly_muangle_mumom_den = 0; ///< Efficiency Denominator - Double Differential PolyBins - Extra Syst

    std::map<std::string,std::map<std::string,UBTH2Poly*>> hmap_trktheta_trkmom_poly_genie_multisim_bs; ///< Number of events per channel and universe - Double Differential PolyBins - Genie Multisim
    std::map<std::string,std::map<std::string,UBTH2Poly*>> hmap_trktheta_trkmom_poly_flux_multisim_bs; ///< Number of events per channel and universe - Double Differential PolyBins - Flux Multisim
    std::map<std::string,std::map<std::string,UBTH2Poly*>> hmap_trktheta_trkmom_poly_extra_syst_multisim_bs; ///< Number of events per channel and universe - Double Differential PolyBins - Extra Syst

    std::map<std::string,std::vector<UBTH2Poly*>> bs_genie_multisim_poly_reco_per_true; ///< Reco per true histograms per universe - Double Differential PolyBins - Genie Multisim
    std::map<std::string,std::vector<UBTH2Poly*>> bs_flux_multisim_poly_reco_per_true; ///< Reco per true histograms per universe - Double Differential PolyBins - Flux Multisim
    std::map<std::string,std::vector<UBTH2Poly*>> bs_extra_syst_multisim_poly_reco_per_true; ///< Reco per true histograms per universe - Double Differential PolyBins - Extra Syst




  protected:

    TFile *_file;

    ///
    void _AddPolyBins_(UBTH2Poly * h);

    ///
    void _AddPolyBins_(BootstrapTH2DPoly * h);

    ///
    void _AddPolyBins_(std::map<std::string,std::vector<UBTH2Poly*>> h);

    ///
    void _AddPolyBins_(std::map<std::string,std::map<std::string,UBTH2Poly*>> h);

    
  };
}

#endif
/** @} */ // end of doxygen group 


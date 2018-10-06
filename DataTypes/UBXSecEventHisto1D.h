/**
 * \file UBXSecEventHisto1D.h
 *
 * \ingroup DataTypes
 * 
 * \brief Class def header for a class UBXSecEventHisto1D
 *
 * @author deltutto
 */

/** \addtogroup DataTypes

    @{*/
#ifndef __DATATYPES_UBXSECEVENTHISTO1D_H__
#define __DATATYPES_UBXSECEVENTHISTO1D_H__

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
     \class UBXSecEventHisto1D
     User defined class UBXSecEventHisto1D ... these comments are used to generate
     doxygen documentation!
  */
  class UBXSecEventHisto1D{
    
  public:
    
    /// Default constructor
    UBXSecEventHisto1D() {}
    
    /// Default destructor
    ~UBXSecEventHisto1D(){}

    ///
    void InitializeBootstraps();



    double bins_mumom[7] = {0.00, 0.18, 0.30, 0.45, 0.77, 1.28, 2.50};
    double bins_mucostheta[10] = {-1.00, -0.50, 0.00, 0.27, 0.45, 0.62, 0.76, 0.86, 0.94, 1.00};
    int n_bins_mumom = 6;
    int n_bins_mucostheta = 9;




    //
    // Total Cross Section
    //

    std::map<std::string,TH1D*> hmap_onebin; ///< Number of events per channel - Total Cross Section
    TH1D * h_eff_onebin_num = 0; ///< Efficiency Numerator - Total Cross Section
    TH1D * h_eff_onebin_den = 0; ///< Efficiency Denominator - Total Cross Section

    BootstrapTH1D * bs_genie_multisim_eff_onebin_num = 0; ///< Efficiency Numerator - Total Cross Section - Genie Multisim
    BootstrapTH1D * bs_genie_multisim_eff_onebin_den = 0; ///< Efficiency Denominator - Total Cross Section - Genie Multisim
    BootstrapTH1D * bs_flux_multisim_eff_onebin_num = 0; ///< Efficiency Numerator - Total Cross Section - Flux Multisim
    BootstrapTH1D * bs_flux_multisim_eff_onebin_den = 0; ///< Efficiency Denominator - Total Cross Section - Flux Multisim
    BootstrapTH1D * bs_extra_syst_multisim_eff_onebin_num = 0; ///< Efficiency Numerator - Total Cross Section - Extra Syst
    BootstrapTH1D * bs_extra_syst_multisim_eff_onebin_den = 0; ///< Efficiency Denominator - Total Cross Section - Extra Syst
    BootstrapTH1D * bs_mc_stat_multisim_eff_onebin_num = 0; ///< Efficiency Numerator - Total Cross Section - MC Stat
    BootstrapTH1D * bs_mc_stat_multisim_eff_onebin_den = 0; ///< Efficiency Denominator - Total Cross Section - MC Stat

    std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_genie_multisim_bs; ///< Number of events per channel and universe - Total Cross Section - Genie Multisim
    std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_flux_multisim_bs; ///< Number of events per channel and universe - Total Cross Section - Flux Multisim
    std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_extra_syst_multisim_bs; ///< Number of events per channel and universe - Total Cross Section - Extra Syst
    std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_mc_stat_multisim_bs; ///< Number of events per channel and universe - Total Cross Section - MC Stat


    //
    // Single differential (mumom)
    //

    std::map<std::string,TH1D*> hmap_trkmom; ///< Number of events per channel - Single Differential (mumom)
    TH1D* h_eff_mumom_num = 0; ///< Efficiency Numerator - Single Differential (mumom)
    TH1D* h_eff_mumom_den = 0; ///< Efficiency Denominator - Single Differential (mumom)
    TH2D * h_true_reco_mom = 0; ///< Reco to true histogram - Single Differential (mumom)

    BootstrapTH1D * bs_genie_multisim_eff_mumom_num = 0; ///< Efficiency Numerator - Single Differential (mumom) - Genie Multisim
    BootstrapTH1D * bs_genie_multisim_eff_mumom_den = 0; ///< Efficiency Denominator - Single Differential (mumom) - Genie Multisim
    BootstrapTH1D * bs_flux_multisim_eff_mumom_num = 0; ///< Efficiency Numerator - Single Differential (mumom) - Flux Multisim
    BootstrapTH1D * bs_flux_multisim_eff_mumom_den = 0; ///< Efficiency Denominator - Single Differential (mumom) - Flux Multisim
    BootstrapTH1D * bs_extra_syst_multisim_eff_mumom_num = 0; ///< Efficiency Numerator - Single Differential (mumom) - Extra Syst
    BootstrapTH1D * bs_extra_syst_multisim_eff_mumom_den = 0; ///< Efficiency Denominator - Single Differential (mumom) - Extra Syst
    BootstrapTH1D * bs_mc_stat_multisim_eff_mumom_num = 0; ///< Efficiency Numerator - Single Differential (mumom) - MC Stat
    BootstrapTH1D * bs_mc_stat_multisim_eff_mumom_den = 0; ///< Efficiency Denominator - Single Differential (mumom) - MC Stat

    std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_genie_multisim_bs; ///< Number of events per channel and universe - Single Differential (mumom) - Genie Multisim
    std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_flux_multisim_bs; ///< Number of events per channel and universe - Single Differential (mumom) - Flux Multisim
    std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_extra_syst_multisim_bs; ///< Number of events per channel and universe - Single Differential (mumom) - Extra Syst
    std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_mc_stat_multisim_bs; ///< Number of events per channel and universe - Single Differential (mumom) - MC Stat

    BootstrapTH2D * bs_genie_multisim_true_reco_mumom = 0; ///< Reco to true histograms for every universe - Single Differential (mumom) - Genie Multisim
    BootstrapTH2D * bs_flux_multisim_true_reco_mumom = 0; ///< Reco to true histograms for every universe - Single Differential (mumom) - Flux Multisim
    BootstrapTH2D * bs_extra_syst_true_reco_mumom = 0; ///< Reco to true histograms for every universe - Single Differential (mumom) - Extra Syst
    BootstrapTH2D * bs_mc_stat_multisim_true_reco_mumom = 0; ///< Reco to true histograms for every universe - Single Differential (mumom) - MC Stat



    //
    // Single differential (muangle)
    //

    std::map<std::string,TH1D*> hmap_trktheta; ///< Number of events per channel - Single Differential (mumom)
    TH1D* h_eff_muangle_num = 0; ///< Efficiency Numerator - Single Differential (mumom)
    TH1D* h_eff_muangle_den = 0; ///< Efficiency Denominator - Single Differential (mumom)
    TH2D * h_true_reco_costheta = 0; ///< Reco to true histogram - Single Differential (mumom)

    BootstrapTH1D * bs_genie_multisim_eff_muangle_num = 0; ///< Efficiency Numerator - Single Differential (muangle) - Genie Multisim
    BootstrapTH1D * bs_genie_multisim_eff_muangle_den = 0; ///< Efficiency Denominator - Single Differential (muangle) - Genie Multisim
    BootstrapTH1D * bs_flux_multisim_eff_muangle_num = 0; ///< Efficiency Numerator - Single Differential (muangle) - Flux Multisim
    BootstrapTH1D * bs_flux_multisim_eff_muangle_den = 0; ///< Efficiency Denominator - Single Differential (muangle) - Flux Multisim
    BootstrapTH1D * bs_extra_syst_multisim_eff_muangle_num = 0; ///< Efficiency Numerator - Single Differential (muangle) - Extra Syst
    BootstrapTH1D * bs_extra_syst_multisim_eff_muangle_den = 0; ///< Efficiency Denominator - Single Differential (muangle) - Extra Syst
    BootstrapTH1D * bs_mc_stat_multisim_eff_muangle_num = 0; ///< Efficiency Numerator - Single Differential (mumangle - MC Stat
    BootstrapTH1D * bs_mc_stat_multisim_eff_muangle_den = 0; ///< Efficiency Denominator - Single Differential (muangle) - MC Stat

    std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_genie_multisim_bs; ///< Number of events per channel and universe - Single Differential (muangle) - Genie Multisim
    std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_flux_multisim_bs; ///< Number of events per channel and universe - Single Differential (muangle) - Flux Multisim
    std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_extra_syst_multisim_bs; ///< Number of events per channel and universe - Single Differential (muangle) - Extra Syst
    std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_mc_stat_multisim_bs; ///< Number of events per channel and universe - Single Differential (muangle) - MC Stat

    BootstrapTH2D * bs_genie_multisim_true_reco_muangle = 0; ///< Reco to true histograms for every universe - Single Differential (muangle) - Genie Multisim
    BootstrapTH2D * bs_flux_multisim_true_reco_muangle = 0; ///< Reco to true histograms for every universe - Single Differential (muangle) - Flux Multisim
    BootstrapTH2D * bs_extra_syst_true_reco_muangle = 0; ///< Reco to true histograms for every universe - Single Differential (muangle) - Extra Syst
    BootstrapTH2D * bs_mc_stat_multisim_true_reco_muangle = 0; ///< Reco to true histograms for every universe - Single Differential (muangle) - MC Stat

    

  protected:


    
  };
}

#endif
/** @} */ // end of doxygen group 


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
#include "BootstrapTH1D.h"
#include "BootstrapTH2D.h"
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
    void AddPolyBins();


    // double bins_mumom[7] = {0.00, 0.18, 0.30, 0.45, 0.77, 1.28, 2.50};
    // double bins_mucostheta[10] = {-1.00, -0.50, 0.00, 0.27, 0.45, 0.62, 0.76, 0.86, 0.94, 1.00};
    // int n_bins_mumom = 6;
    // int n_bins_mucostheta = 9;

    int _n_bins_double_mumom = 6; ///< Number of momentum bins for double differential
    int _n_bins_double_mucostheta = 9; ///< Number of costheta bins for double differential

    double _bins_double_mumom[7] = {0.00, 0.18, 0.30, 0.45, 0.77, 1.28, 2.50}; //!
    double _bins_double_mucostheta[10] = {-1.00, -0.50, 0.00, 0.27, 0.45, 0.62, 0.76, 0.86, 0.94, 1.00}; //!

    int _n_poly_bins = 53;
    std::map<int, std::pair<int, int>> _exclusion_map = { {0, std::make_pair(4, 5)},
                                                          {1, std::make_pair(4, 5)}, }; //!



    // //
    // // Total Cross Section
    // //

    // std::map<std::string,TH1D*> hmap_onebin; ///< Number of events per channel - Total Cross Section
    // TH1D * h_eff_onebin_num = 0; ///< Efficiency Numerator - Total Cross Section
    // TH1D * h_eff_onebin_den = 0; ///< Efficiency Denominator - Total Cross Section

    // BootstrapTH1D * bs_genie_multisim_eff_onebin_num = 0; ///< Efficiency Numerator - Total Cross Section - Genie Multisim
    // BootstrapTH1D * bs_genie_multisim_eff_onebin_den = 0; ///< Efficiency Denominator - Total Cross Section - Genie Multisim
    // BootstrapTH1D * bs_flux_multisim_eff_onebin_num = 0; ///< Efficiency Numerator - Total Cross Section - Flux Multisim
    // BootstrapTH1D * bs_flux_multisim_eff_onebin_den = 0; ///< Efficiency Denominator - Total Cross Section - Flux Multisim
    // BootstrapTH1D * bs_extra_syst_multisim_eff_onebin_num = 0; ///< Efficiency Numerator - Total Cross Section - Extra Syst
    // BootstrapTH1D * bs_extra_syst_multisim_eff_onebin_den = 0; ///< Efficiency Denominator - Total Cross Section - Extra Syst
    // BootstrapTH1D * bs_mc_stat_multisim_eff_onebin_num = 0; ///< Efficiency Numerator - Total Cross Section - MC Stat
    // BootstrapTH1D * bs_mc_stat_multisim_eff_onebin_den = 0; ///< Efficiency Denominator - Total Cross Section - MC Stat

    // std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_genie_multisim_bs; ///< Number of events per channel and universe - Total Cross Section - Genie Multisim
    // std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_flux_multisim_bs; ///< Number of events per channel and universe - Total Cross Section - Flux Multisim
    // std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_extra_syst_multisim_bs; ///< Number of events per channel and universe - Total Cross Section - Extra Syst
    // std::map<std::string,std::map<std::string,TH1D*>> hmap_onebin_mc_stat_multisim_bs; ///< Number of events per channel and universe - Total Cross Section - MC Stat


    // //
    // // Single differential (mumom)
    // //

    // std::map<std::string,TH1D*> hmap_trkmom; ///< Number of events per channel - Single Differential (mumom)
    // TH1D* h_eff_mumom_num = 0; ///< Efficiency Numerator - Single Differential (mumom)
    // TH1D* h_eff_mumom_den = 0; ///< Efficiency Denominator - Single Differential (mumom)
    // TH2D * h_true_reco_mom = 0; ///< Reco to true histogram - Single Differential (mumom)

    // BootstrapTH1D * bs_genie_multisim_eff_mumom_num = 0; ///< Efficiency Numerator - Single Differential (mumom) - Genie Multisim
    // BootstrapTH1D * bs_genie_multisim_eff_mumom_den = 0; ///< Efficiency Denominator - Single Differential (mumom) - Genie Multisim
    // BootstrapTH1D * bs_flux_multisim_eff_mumom_num = 0; ///< Efficiency Numerator - Single Differential (mumom) - Flux Multisim
    // BootstrapTH1D * bs_flux_multisim_eff_mumom_den = 0; ///< Efficiency Denominator - Single Differential (mumom) - Flux Multisim
    // BootstrapTH1D * bs_extra_syst_multisim_eff_mumom_num = 0; ///< Efficiency Numerator - Single Differential (mumom) - Extra Syst
    // BootstrapTH1D * bs_extra_syst_multisim_eff_mumom_den = 0; ///< Efficiency Denominator - Single Differential (mumom) - Extra Syst
    // BootstrapTH1D * bs_mc_stat_multisim_eff_mumom_num = 0; ///< Efficiency Numerator - Single Differential (mumom) - MC Stat
    // BootstrapTH1D * bs_mc_stat_multisim_eff_mumom_den = 0; ///< Efficiency Denominator - Single Differential (mumom) - MC Stat

    // std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_genie_multisim_bs; ///< Number of events per channel and universe - Single Differential (mumom) - Genie Multisim
    // std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_flux_multisim_bs; ///< Number of events per channel and universe - Single Differential (mumom) - Flux Multisim
    // std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_extra_syst_multisim_bs; ///< Number of events per channel and universe - Single Differential (mumom) - Extra Syst
    // std::map<std::string,std::map<std::string,TH1D*>> hmap_trkmom_mc_stat_multisim_bs; ///< Number of events per channel and universe - Single Differential (mumom) - MC Stat

    // BootstrapTH2D * bs_genie_multisim_true_reco_mumom = 0; ///< Reco to true histograms for every universe - Single Differential (mumom) - Genie Multisim
    // BootstrapTH2D * bs_flux_multisim_true_reco_mumom = 0; ///< Reco to true histograms for every universe - Single Differential (mumom) - Flux Multisim
    // BootstrapTH2D * bs_extra_syst_true_reco_mumom = 0; ///< Reco to true histograms for every universe - Single Differential (mumom) - Extra Syst
    // BootstrapTH2D * bs_mc_stat_multisim_true_reco_mumom = 0; ///< Reco to true histograms for every universe - Single Differential (mumom) - MC Stat



    // //
    // // Single differential (muangle)
    // //

    // std::map<std::string,TH1D*> hmap_trktheta; ///< Number of events per channel - Single Differential (mumom)
    // TH1D* h_eff_muangle_num = 0; ///< Efficiency Numerator - Single Differential (mumom)
    // TH1D* h_eff_muangle_den = 0; ///< Efficiency Denominator - Single Differential (mumom)
    // TH2D * h_true_reco_costheta = 0; ///< Reco to true histogram - Single Differential (mumom)

    // BootstrapTH1D * bs_genie_multisim_eff_muangle_num = 0; ///< Efficiency Numerator - Single Differential (muangle) - Genie Multisim
    // BootstrapTH1D * bs_genie_multisim_eff_muangle_den = 0; ///< Efficiency Denominator - Single Differential (muangle) - Genie Multisim
    // BootstrapTH1D * bs_flux_multisim_eff_muangle_num = 0; ///< Efficiency Numerator - Single Differential (muangle) - Flux Multisim
    // BootstrapTH1D * bs_flux_multisim_eff_muangle_den = 0; ///< Efficiency Denominator - Single Differential (muangle) - Flux Multisim
    // BootstrapTH1D * bs_extra_syst_multisim_eff_muangle_num = 0; ///< Efficiency Numerator - Single Differential (muangle) - Extra Syst
    // BootstrapTH1D * bs_extra_syst_multisim_eff_muangle_den = 0; ///< Efficiency Denominator - Single Differential (muangle) - Extra Syst
    // BootstrapTH1D * bs_mc_stat_multisim_eff_muangle_num = 0; ///< Efficiency Numerator - Single Differential (mumangle - MC Stat
    // BootstrapTH1D * bs_mc_stat_multisim_eff_muangle_den = 0; ///< Efficiency Denominator - Single Differential (muangle) - MC Stat

    // std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_genie_multisim_bs; ///< Number of events per channel and universe - Single Differential (muangle) - Genie Multisim
    // std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_flux_multisim_bs; ///< Number of events per channel and universe - Single Differential (muangle) - Flux Multisim
    // std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_extra_syst_multisim_bs; ///< Number of events per channel and universe - Single Differential (muangle) - Extra Syst
    // std::map<std::string,std::map<std::string,TH1D*>> hmap_trkangle_mc_stat_multisim_bs; ///< Number of events per channel and universe - Single Differential (muangle) - MC Stat

    // BootstrapTH2D * bs_genie_multisim_true_reco_muangle = 0; ///< Reco to true histograms for every universe - Single Differential (muangle) - Genie Multisim
    // BootstrapTH2D * bs_flux_multisim_true_reco_muangle = 0; ///< Reco to true histograms for every universe - Single Differential (muangle) - Flux Multisim
    // BootstrapTH2D * bs_extra_syst_true_reco_muangle = 0; ///< Reco to true histograms for every universe - Single Differential (muangle) - Extra Syst
    // BootstrapTH2D * bs_mc_stat_multisim_true_reco_muangle = 0; ///< Reco to true histograms for every universe - Single Differential (muangle) - MC Stat

    //
    // Double differential 
    //

    std::map<std::string,TH2D*> hmap_trktheta_trkmom; ///< Number of events per channel - Double Differential
    TH2D* h_eff_muangle_mumom_num = 0; ///< Efficiency Numerator - Double Differential
    TH2D* h_eff_muangle_mumom_den = 0; ///< Efficiency Denominator - Double Differential
    std::vector<std::vector<TH2D*>> h_reco_per_true; ///< Per true bins m,n, it contains the distribution of the reco quantity


    BootstrapTH2D * bs_genie_multisim_eff_muangle_mumom_num = 0; ///< Efficiency Numerator - Double Differential - Genie Multisim
    BootstrapTH2D * bs_genie_multisim_eff_muangle_mumom_den = 0; ///< Efficiency Denominator - Double Differential - Genie Multisim
    BootstrapTH2D * bs_flux_multisim_eff_muangle_mumom_num = 0; ///< Efficiency Numerator - Double Differential - Flux Multisim
    BootstrapTH2D * bs_flux_multisim_eff_muangle_mumom_den = 0; ///< Efficiency Denominator - Double Differential - Flux Multisim
    BootstrapTH2D * bs_extra_syst_multisim_eff_muangle_mumom_num = 0; ///< Efficiency Numerator - Double Differential - Extra Syst
    BootstrapTH2D * bs_extra_syst_multisim_eff_muangle_mumom_den = 0; ///< Efficiency Denominator - Double Differential - Extra Syst
    BootstrapTH2D * bs_mc_stat_multisim_eff_muangle_mumom_num = 0; ///< Efficiency Numerator - Double Differential - MC Stat
    BootstrapTH2D * bs_mc_stat_multisim_eff_muangle_mumom_den = 0; ///< Efficiency Denominator - Double Differential - MC Stat

    std::map<std::string,std::map<std::string,TH2D*>> hmap_trktheta_trkmom_genie_multisim_bs; ///< Number of events per channel and universe - Double Differential - Genie Multisim
    std::map<std::string,std::map<std::string,TH2D*>> hmap_trktheta_trkmom_flux_multisim_bs; ///< Number of events per channel and universe - Double Differential - Flux Multisim
    std::map<std::string,std::map<std::string,TH2D*>> hmap_trktheta_trkmom_extra_syst_multisim_bs; ///< Number of events per channel and universe - Double Differential - Extra Syst
    std::map<std::string,std::map<std::string,TH2D*>> hmap_trktheta_trkmom_mc_stat_multisim_bs; ///< Number of events per channel and universe - Double Differential - MC Stat

    std::map<std::string,std::vector<std::vector<TH2D*>>> bs_genie_multisim_reco_per_true; ///< Reco per true histograms per universe - Double Differential - Genie Multisim
    std::map<std::string,std::vector<std::vector<TH2D*>>> bs_flux_multisim_reco_per_true; ///< Reco per true histograms per universe - Double Differential - Flux Multisim
    std::map<std::string,std::vector<std::vector<TH2D*>>> bs_extra_syst_multisim_reco_per_true; ///< Reco per true histograms per universe - Double Differential - Extra Syst
    std::map<std::string,std::vector<std::vector<TH2D*>>> bs_mc_stat_multisim_reco_per_true; ///< Reco per true histograms per universe - Double Differential - MC Stat


    //
    // Double differential (polybin)
    //
    std::map<std::string,UBTH2Poly*> hmap_trktheta_trkmom_poly; ///< Number of events per channel - Double Differential (polybin)
    UBTH2Poly * h_eff_muangle_mumom_poly_num = 0; ///< Efficiency Numerator - Double Differential (polybin)
    UBTH2Poly * h_eff_muangle_mumom_poly_den = 0; ///< Efficiency Denominator - Double Differential (polybin)
    std::vector<UBTH2Poly*> h_poly_reco_per_true; ///< Per true bins m (unrolled) it contains the distribution of the reco quantity


    BootstrapTH2DPoly * bs_genie_multisim_eff_poly_muangle_mumom_num = 0; ///< Efficiency Numerator - Double Differential PolyBins - Genie Multisim
    BootstrapTH2DPoly * bs_genie_multisim_eff_poly_muangle_mumom_den = 0; ///< Efficiency Denominator - Double Differential PolyBins - Genie Multisim
    BootstrapTH2DPoly * bs_flux_multisim_eff_poly_muangle_mumom_num = 0; ///< Efficiency Numerator - Double Differential PolyBins - Flux Multisim
    BootstrapTH2DPoly * bs_flux_multisim_eff_poly_muangle_mumom_den = 0; ///< Efficiency Denominator - Double Differential PolyBins - Flux Multisim
    BootstrapTH2DPoly * bs_extra_syst_multisim_eff_poly_muangle_mumom_num = 0; ///< Efficiency Numerator - Double Differential PolyBins - Extra Syst
    BootstrapTH2DPoly * bs_extra_syst_multisim_eff_poly_muangle_mumom_den = 0; ///< Efficiency Denominator - Double Differential PolyBins - Extra Syst
    BootstrapTH2DPoly * bs_mc_stat_multisim_eff_poly_muangle_mumom_num = 0; ///< Efficiency Numerator - Double Differential PolyBins - MC Stat
    BootstrapTH2DPoly * bs_mc_stat_multisim_eff_poly_muangle_mumom_den = 0; ///< Efficiency Denominator - Double Differential PolyBins - MC Stat

    std::map<std::string,std::map<std::string,UBTH2Poly*>> hmap_trktheta_trkmom_poly_genie_multisim_bs; ///< Number of events per channel and universe - Double Differential PolyBins - Genie Multisim
    std::map<std::string,std::map<std::string,UBTH2Poly*>> hmap_trktheta_trkmom_poly_flux_multisim_bs; ///< Number of events per channel and universe - Double Differential PolyBins - Flux Multisim
    std::map<std::string,std::map<std::string,UBTH2Poly*>> hmap_trktheta_trkmom_poly_extra_syst_multisim_bs; ///< Number of events per channel and universe - Double Differential PolyBins - Extra Syst
    std::map<std::string,std::map<std::string,UBTH2Poly*>> hmap_trktheta_trkmom_poly_mc_stat_multisim_bs; ///< Number of events per channel and universe - Double Differential PolyBins - MC Stat

    std::map<std::string,std::vector<std::vector<double>>> bs_genie_multisim_poly_reco_per_true; ///< Reco per true histograms per universe - Double Differential PolyBins - Genie Multisim
    std::map<std::string,std::vector<std::vector<double>>> bs_flux_multisim_poly_reco_per_true; ///< Reco per true histograms per universe - Double Differential PolyBins - Flux Multisim
    std::map<std::string,std::vector<std::vector<double>>> bs_extra_syst_multisim_poly_reco_per_true; ///< Reco per true histograms per universe - Double Differential PolyBins - Extra Syst
    std::map<std::string,std::vector<std::vector<double>>> bs_mc_stat_multisim_poly_reco_per_true; ///< Reco per true histograms per universe - Double Differential PolyBins - MC Stat




  protected:

    // TFile *_file = 0;

    ///
    void _AddPolyBins_(UBTH2Poly * h);

    ///
    void _AddPolyBins_(BootstrapTH2DPoly * h);

    ///
    void _AddPolyBins_(std::map<std::string,std::vector<UBTH2Poly*>> h);

    ///
    void _AddPolyBins_(std::vector<std::vector<UBTH2Poly*>> h);

    ///
    void _AddPolyBins_(std::map<std::string,std::map<std::string,UBTH2Poly*>> h);

    ///
    void _AddPolyBins_(std::map<std::string,UBTH2Poly*> h);

    ///
    void _AddPolyBins_(std::vector<UBTH2Poly*> h);

    
  };
}

#endif
/** @} */ // end of doxygen group 


/**
 * \file CrossSectionBootstrapCalculator2DPoly.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class CrossSectionBootstrapCalculator2DPoly
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_CROSSSECTIONBOOTSTRAPCALCULATOR2DPOLY_H__
#define __BASE_CROSSSECTIONBOOTSTRAPCALCULATOR2DPOLY_H__

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

#include "CrossSectionCalculator2DPoly.h"
#include "MigrationMatrix4DPoly.h"
#include "CovarianceCalculator4D.h"

#include "ubana/DataTypes/UBTH2Poly.h"
#include "ubana/DataTypes/BootstrapTH2DPoly.h"

#include "LoggerFeature.h"


using namespace DataTypes;


namespace Base{

  /**
     \class CrossSectionBootstrapCalculator2DPoly
     User defined class CrossSectionBootstrapCalculator2DPoly ... these comments are used to generate
     doxygen documentation!
  */
  class CrossSectionBootstrapCalculator2DPoly : public LoggerFeature {
    
  public:
    
    /// Default constructor
    CrossSectionBootstrapCalculator2DPoly(std::string name = "CrossSectionBootstrapCalculator2DPoly") 
    : LoggerFeature(name) {}
    
    /// Default destructor
    ~CrossSectionBootstrapCalculator2DPoly(){}

    ///
    void Run();

    /// Configure function parameters
    void SetScaleFactors(double bnbcosmic, double bnbon, double extbnb, double dirt = 0, double intimecosmic = 0);

    /// Sets the POT number
    void SetPOT(double pot);

    /// Set the names of the backreounds to subtract
    void SetBkgToSubtract(std::vector<std::string> bkg_names);

    /// Set the plot name for saving and the label for the axis
    void SetNameAndLabel(std::string name, std::string label);

    /// Sets all the histograms
    void SetHistograms(std::map<std::string,std::map<std::string,UBTH2Poly*>>/*std::map<std::string,BootstrapTH1D>*/ bnbcosmic, UBTH2Poly* bnbon, UBTH2Poly* extbnb, std::map<std::string,UBTH2Poly*> dirt = std::map<std::string,UBTH2Poly*>(), UBTH2Poly* intimecosmic = 0);

    /// Sets num and dem histograms for the efficiency and the reco per true 2D histos
    void SetTruthHistograms(BootstrapTH2DPoly*, BootstrapTH2DPoly*, std::map<std::string,std::vector<std::vector<double>>>);

    /// Sets num and dem histograms for the efficiency
    void SetTruthHistograms(BootstrapTH2DPoly*, BootstrapTH2DPoly*);

    /// Sets truth XSec
    void SetTruthXSec(UBTH2Poly* xsec);

    ///
    void SetMigrationMatrixDimensions(int n, int m);

    ///
    void DoNotSmear();

    /// If rwgt_flux is true also reweights the flux, flux_unc_type is the type reweighting (total, FluxUnisim, ...)
    void SetFluxHistogramType(bool rwgt_flux = false, std::string flux_unc_type = "total");

    ///
    void Reset();
 
    /// Sets the output directory
    void SetSavePrefix(std::string s, std::string folder = "output_covariance_plots");

    ///
    void DrawProgressBar(double progress, double barWidth);

    ///
    void SetUpperLabel(std::string s) {_upper_label = s;}

    ///
    void GetCovarianceMatrix(TH2D &);

    ///
    void GetFractionalCovarianceMatrix(TH2D &);

    ///
    void SaveCovarianceMatrix(std::string file_name, std::string name);

    ///
    void SaveFractionalCovarianceMatrix(std::string file_name, std::string name);

    /// Not squared
    void AddExtraDiagonalUncertainty(double value) {_extra_relative_uncertainty = value;};

    ///
    void SetFluxCorrectionWeight(double w) {_flux_correction_weight = w;};

    ///
    void DrawXSec(std::map<std::string, UBTH2Poly*> xsec_mumom_per_universe);
  

  private:

    std::string _prefix = "[CrossSectionBootstrapCalculator2DPoly] ";

    bool _configured = false;

    double _scale_factor_mc_bnbcosmic;
    double _scale_factor_bnbon;
    double _scale_factor_extbnb;
    double _scale_factor_mc_dirt;
    double _scale_factor_mc_intimecosmic;

    double _pot;
    double _flux;

    double _n_target = 2.64218e31;

    std::string _name = "trklen"; 
    std::string _label = ";Test [cm]; Selected Events";

    std::string _outdir;
    std::string _folder;

    CrossSectionCalculator2DPoly _xsec_calc; ///< The cross section calculator

    //std::map<std::string,BootstrapTH2D> _hmap_bnbcosmic;
    std::map<std::string,std::map<std::string,UBTH2Poly*>> _hmap_bnbcosmic;
    std::map<std::string,UBTH2Poly*> _hmap_dirt;
    UBTH2Poly* _h_bnbon = nullptr;
    UBTH2Poly* _h_extbnb = nullptr;
    UBTH2Poly* _h_intimecosmic = nullptr;

    BootstrapTH2DPoly* _h_eff_mumom_num; ///< The efficiency numerator
    BootstrapTH2DPoly* _h_eff_mumom_den; ///< The efficiency denominator

    TTree * _t_true_reco; ///< The TTree containing the mapping true to reco (no longer used)
    std::map<std::string,std::vector<std::vector<double>>> _bs_reco_per_true; ///< The Bootstrap containing the reco per true histos for every universe (universe, true bin, reco bin)

    TTree* true_reco_tree = nullptr; ///< The tree that containes the true to reco mapping

    bool _true_to_reco_is_set = false; ///< Is set to true when SetTruthHistograms() is called with three arguments

    TH1D* _truth_xsec;

    TH1D* _h_data_sub;

    TEfficiency* _eff = nullptr;

    TMatrix _S;

    int _n, _m;
    bool _do_smear = true;

    std::vector<std::string> _bkg_names; ///< List of bkg names used to subtract backgrounds for the cross section

    std::string _save_prefix = "PREFIX_"; ///< Prefix name used to save output plots
    std::string _upper_label = "NOT SET"; ///< The label that will happer in the upper plot of the reweighted cross sections

    bool _rwgt_flux = false; ///< If true the flux is also reweighted
    std::string _flux_unc_type = "total"; ///< Specifies what flux rewegthing to pick

    TH2D _cov_matrix; ///< The 2d histo representing the covariance matrix, available after calling Run()
    TH2D _frac_cov_matrix; ///< The 2d histo representing the fractional covariance matrix, available after calling Run()

    double _extra_relative_uncertainty = 0.; ///< Extra uncertainty to be added to the diagonal

    double _flux_correction_weight = 1.; ///< Flux correction weight
        
  };
}

#endif
/** @} */ // end of doxygen group 


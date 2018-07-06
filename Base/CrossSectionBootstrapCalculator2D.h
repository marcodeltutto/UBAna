/**
 * \file CrossSectionBootstrapCalculator2D.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class CrossSectionBootstrapCalculator2D
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_CROSSSECTIONBOOTSTRAPCALCULATOR2D_H__
#define __BASE_CROSSSECTIONBOOTSTRAPCALCULATOR2D_H__

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


#include "BootstrapTH1D.h"
#include "BootstrapTH2D.h"
#include "CrossSectionCalculator2D.h"
#include "MigrationMatrix4D.h"
#include "CovarianceCalculator4D.h"


namespace Base {

  /**
     \class CrossSectionBootstrapCalculator2D
     User defined class CrossSectionBootstrapCalculator2D ... these comments are used to generate
     doxygen documentation!
  */
  class CrossSectionBootstrapCalculator2D{
    
  public:
    
    /// Default constructor
    CrossSectionBootstrapCalculator2D(){}
    
    /// Default destructor
    ~CrossSectionBootstrapCalculator2D(){}

    ///
    void Run(std::string weight_type = "genie_multisim");

    /// Configure function parameters
    void SetScaleFactors(double bnbcosmic, double bnbon, double extbnb, double intimecosmic = 0);

    /// Sets the POT number
    void SetPOT(double pot);

    /// Set the plot name for saving and the label for the axis
    void SetNameAndLabel(std::string name, std::string label);

    /// Sets the outputdirectory
    void SetOutDir(std::string dir);

    /// Sets all the histograms
    void SetHistograms(std::map<std::string,std::map<std::string,TH2D*>>/*std::map<std::string,BootstrapTH1D>*/ bnbcosmic, TH2D* bnbon, TH2D* extbnb, TH2D* intimecosmic = 0);

    /// Sets num and dem histograms for the efficiency and the reco vs true 2d histo
    void SetTruthHistograms(BootstrapTH2D, BootstrapTH2D, TTree*);

    /// Sets num and dem histograms for the efficiency
    void SetTruthHistograms(BootstrapTH2D, BootstrapTH2D);

    /// Sets truth XSec
    void SetTruthXSec(TH2D* xsec);

    ///
    void SetMigrationMatrixDimensions(int n, int m);

    ///
    void DoNotSmear();

    /// If rwgt_flux is true also reweights the flux, flux_unc_type is the type reweighting (total, FluxUnisim, ...)
    void SetFluxHistogramType(bool rwgt_flux = false, std::string flux_unc_type = "total");

    ///
    void Reset();
 
    ///
    void SetSavePrefix(std::string s, std::string folder = "output_covariance_plots");

    ///
    void DrawProgressBar(double progress, double barWidth);

    ///
    void SetUpperLabel(std::string s) {_upper_label = s;}

    ///
    void GetCovarianceMatrix(TH2D &);

    ///
    void SaveCovarianceMatrix(std::string file_name, std::string name);

    /// Not squared
    void AddExtraDiagonalUncertainty(double value) {_extra_relative_uncertainty = value;};

    ///
    void SetFluxCorrectionWeight(double w) {_flux_correction_weight = w;};

    ///
    void DrawXSec(std::map<std::string, TH2D*> xsec_mumom_per_universe);
  

  private:

    std::string _prefix = "[CrossSectionBootstrapCalculator2D] ";

    bool _configured = false;

    double _scale_factor_mc_bnbcosmic;
    double _scale_factor_bnbon;
    double _scale_factor_extbnb;
    double _scale_factor_mc_intimecosmic;

    double _pot;
    double _flux;

    double _n_target = 2.64218e31;

    std::string _name = "trklen"; 
    std::string _label = ";Test [cm]; Selected Events";

    std::string _outdir;
    std::string _folder;

    //std::map<std::string,BootstrapTH2D> _hmap_bnbcosmic;
    std::map<std::string,std::map<std::string,TH2D*>> _hmap_bnbcosmic;
    TH2D* _h_bnbon = nullptr;
    TH2D* _h_extbnb = nullptr;
    TH2D* _h_intimecosmic = nullptr;

    BootstrapTH2D _h_eff_mumom_num; ///< The efficiency numerator
    BootstrapTH2D _h_eff_mumom_den; ///< The efficiency denominator

    TTree * _t_true_reco; ///< The TTree containing the mapping true to reco

    TTree* true_reco_tree = nullptr; ///< The tree that containes the true to reco mapping

    bool _true_to_reco_is_set = false; ///< Is set to true when SetTruthHistograms() is called with three arguments

    TH1D* _truth_xsec;

    TH1D* _h_data_sub;

    TEfficiency* _eff = nullptr;

    TMatrix _S;

    int _n, _m;
    bool _do_smear = true;

    std::string _save_prefix = "PREFIX_"; ///< Prefix name used to save output plots
    std::string _upper_label = "NOT SET"; ///< The label that will happer in the upper plot of the reweighted cross sections

    bool _rwgt_flux = false; ///< If true the flux is also reweighted
    std::string _flux_unc_type = "total"; ///< Specifies what flux rewegthing to pick

    TH2D _cov_matrix; ///< The 2d histo representing the covariance matrix, available after calling Run()

    double _extra_relative_uncertainty = 0.; ///< Extra uncertainty to be added to the diagonal

    double _flux_correction_weight = 1.; ///< Flux correction weight
        
  };
}

#endif
/** @} */ // end of doxygen group 


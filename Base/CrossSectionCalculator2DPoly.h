/**
 * \file CrossSectionCalculator2DPoly.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class CrossSectionCalculator2DPoly
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_CROSSSECTIONCALCULATOR2DPOLY_H__
#define __BASE_CROSSSECTIONCALCULATOR2DPOLY_H__

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
#include "TMatrixD.h"
#include "TGraphAsymmErrors.h"
#include "TLine.h"
#include "Math/DistFunc.h" // for quantile

#include "Types.h"
#include "ubana/DataTypes/UBTH2Poly.h"
#include "PlottingTools.h"
#include "LoggerFeature.h"

using namespace DataTypes;


namespace Base {

  /**
     \class CrossSectionCalculator2DPoly
     User defined class CrossSectionCalculator2DPoly ... these comments are used to generate
     doxygen documentation!
  */
  class CrossSectionCalculator2DPoly : public LoggerFeature {
    
  public:
    
    /// Default constructor
    CrossSectionCalculator2DPoly(std::string name = "CrossSectionCalculator2DPoly") 
    : LoggerFeature(name) {}
    
    /// Default destructor
    ~CrossSectionCalculator2DPoly(){}

    /// Configure function parameters
    void SetScaleFactors(double bnbcosmic, double bnbon, double extbnb, double dirt = 0, double intimecosmic = 0);

    /// Sets the POT number
    void SetPOT(double pot);

    /// Set the plot name for saving and the label for the axis
    void SetNameAndLabel(std::string name, std::string label);

    /// Sets the outputdirectory
    void SetOutDir(std::string dir);

    /// Sets all the histograms
    void SetHistograms(std::map<std::string,UBTH2Poly*> bnbcosmic, UBTH2Poly* bnbon, UBTH2Poly* extbnb, std::map<std::string,UBTH2Poly*> dirt = std::map<std::string, UBTH2Poly*>(), UBTH2Poly* intimecosmic = 0);

    /// Sets num and dem histograms for the efficiency and the reco vs true 2d histo
    void SetTruthHistograms(UBTH2Poly*, UBTH2Poly*);

    /// Sets truth XSec
    void SetTruthXSec(UBTH2Poly* xsec);

    /// Printd the current configuration
    void PrintConfig();

    ///
    void ProcessPlots();

    ///
    void Draw();

    ///
    void Draw(std::vector<std::string> histos_to_subtract);

    ///   
    void DrawInProjections(UBTH2Poly* h_data, std::map<std::string,UBTH2Poly*> mc, TString save_path, bool scale_bin_width = false); 

    /// 
    double EstimateFlux(std::string flux_file_prefix = "MCC8_FluxHistograms_Uncertainties.root", std::string histogram_file_prefix = "numu/numu_CV_AV_TPC");

    ///
    void SaveEventNumbers(std::string);

    ///
    void SaveToLatexFile();
    
    ///
    THStack * ProcessTHStack(std::map<std::string,UBTH2Poly*> themap, TLegend*, std::vector<std::string>);

    ///
    UBTH2Poly* ProcessDataHisto(UBTH2Poly* histo);

    /// Extracts the cross section, provide a vector of background names to be subtracted in the first argument
    UBTH2Poly* ExtractCrossSection(std::vector<std::string> bkg_prefixs, std::string, std::string, std::string, bool make_plots = true);
    
    /// Makes all the cross section plots (must be called after ExtractCrossSection)
    void MakeAllCrossSectionPlots(std::string, std::string, std::string);

    /// Returns the extracted MC cross section (must be called after ExtractCrossSection)
    UBTH2Poly* GetMCCrossSection() { return _h_mc; }

    /// Returns the extracted alternative MC cross section (must be called after ExtractCrossSection)
    UBTH2Poly* GetAlternativeMCCrossSection() { return _h_alt_mc_xsec; }

    /// Returns a vector (one entry per cos(theta) bin) of TH1D* containing the data cross section
    std::vector<TH1D> GetUnpackedDataCrossSection() { return _xsec_data_histos; }

    /// Returns a vector (one entry per cos(theta) bin) of TH1D* containing the MC cross section
    std::vector<TH1D> GetUnpackedMCCrossSection() { return _xsec_mc_histos; }

    /// Returns a vector (one entry per cos(theta) bin) of TH1D* containing the data cross section uncertainties
    std::vector<TH1D> GetUnpackedDataCrossSectionUncertainty() { return _xsec_data_unc_histos; }

    /// Returns a vector (one entry per cos(theta) bin) of TH1D* containing the MC alternative cross section
    std::vector<TH1D> GetUnpackedMCAlternativeCrossSection() { return _xsec_mc_alt_histos; }

    /// Returns the total covariance matrix (stat + syst)
    TH2D GetTotalCovarianceMatrix() {return *_tot_cov_matrix_total;}

    /// Sets the smearing matrix
    void SetSmearingMatrix(TMatrix);
 
    /// Sets the covariance matrix
    void SetCovarianceMatrix(TH2D);

    ///
    void SetFractionalCovarianceMatrix(TH2D);

    ///
    void Smear();

    ///
    TLatex* GetPOTLatex(double pot); 

    ///
    void Reset();

    ///
    void SetFluxCorrectionWeight(double w) {_flux_correction_weight = w;};

    /// Draw a TH1 on the current pad with MC style
    void DrawMC(TCanvas * c, int c_number, TH1D h);

    ///
    void SetVerbosity(bool verbosity) {_verbose = verbosity;}

    ///
    void AddExtraDiagonalUncertainty(double v) {_extra_fractional_uncertainty = v;};

    ///
    void ImportAlternativeMC(UBTH2Poly* h) {_add_alt_mc_xsec = true; _h_alt_mc_xsec = h;};

    ///
    void SetNTargetData(double n = 2.6123744020373e+31) {_n_target_data = n;}

    ///
    void SetNTargetMC(double n = 2.634653975573033e31) {_n_target_mc = n;}

    ///
    void DoChi2(bool option = true) {_do_chi2 = option;}

  private:

    /// Calculates the chi2 between data and MC cross sections
    void CalculateChi2(); 

    std::string _prefixbase = "[CrossSectionCalculator2DPoly] ";
    
    bool _configured = false;

    double _scale_factor_mc_bnbcosmic;
    double _scale_factor_bnbon;
    double _scale_factor_extbnb;
    double _scale_factor_mc_dirt;
    double _scale_factor_mc_intimecosmic;

    bool _dirt_is_set = false;

    double _pot;
    double _flux;

    double _n_target_data = 2.6123744020373e+31;
    double _n_target_mc = 2.634653975573033e31;

    std::string _prefix = "trklen"; 
    std::string _label = ";Test [cm]; Selected Events";

    std::string _outdir;
    std::string _folder;

    std::map<std::string,UBTH2Poly*> _hmap_bnbcosmic;
    std::map<std::string,UBTH2Poly*> _hmap_dirt;
    UBTH2Poly* _h_bnbon;
    UBTH2Poly* _h_extbnb;
    UBTH2Poly* _h_intimecosmic;

    UBTH2Poly* _h_eff_mumom_num;
    UBTH2Poly* _h_eff_mumom_den;

    UBTH2Poly* _truth_xsec;

    UBTH2Poly* _h_data_sub;

    UBTH2Poly* _eff;

    UBTH2Poly* _h_mc = NULL; ///< The to-be extracted MC cross section
    UBTH2Poly* _h_data = NULL; ///< The to-be extracted data cross section
    UBTH2Poly* _h_syst_unc = NULL; ///< The to-be calculated syst uncertainties on data cross section

    TMatrix _S; ///< The migration matrix (to be set externally)

    double _flux_correction_weight = 1.; ///< Flux correction weight

    bool _verbose = true;
    bool _do_chi2 = false; ///< If true calculated the chi2 between data and MC cross section

    double _extra_fractional_uncertainty = 0.; ///< Adds an extra uncertainty on the diagonal

    TH2D _covariance_matrix; ///< 2D Histogram representing the covariance matrix (to be set externally)
    bool _covariance_matrix_is_set = false; ///< Flag that remembers if the covariance matrix was set for this cross section calculation (if not, no syst will be added)

    TH2D _frac_covariance_matrix; ///< 2D Histogram representing the fractional covariance matrix (to be set externally)
    bool _frac_covariance_matrix_is_set = false; ///< Flag that remembers if the fractional covariance matrix was set for this cross section calculation (if not, no syst will be added)

    TH2D *_syst_frac_cov_matrix_total = NULL; ///< Systematics fractional covariance matrix
    TH2D *_syst_cov_matrix_total = NULL; ///< Systematics covariance matrix
    TH2D *_syst_corr_matrix_total = NULL; ///< Systematics correlation matrix

    TH2D *_stat_frac_cov_matrix_total = NULL; ///< Statistics fractional covariance matrix
    TH2D *_stat_cov_matrix_total = NULL; ///< Statistics covariance matrix

    TH2D *_tot_frac_cov_matrix_total = NULL; ///< Total fractional covariance matrix
    TH2D *_tot_cov_matrix_total = NULL; ///< Total covariance matrix
    TH2D *_tot_corr_matrix_total = NULL; ///< Total correlation matrix

    bool _add_alt_mc_xsec = false; ///< If true draws an alternative MC cross section from ImportAlternativeMC
    UBTH2Poly* _h_alt_mc_xsec; ///< Stores an alternative MC cross section (from Tune3, or theory, in the latter has to be smeared)

    std::vector<TH1D> _xsec_data_histos; ///< Data extracted cross section unpacked per every cos(theta) bin
    std::vector<TH1D> _xsec_mc_histos; ///< MC cross section unpacked per every cos(theta) bin
    std::vector<TH1D> _xsec_mc_alt_histos; ///< MC alternative cross section unpacked per every cos(theta) bin
    std::vector<TH1D> _xsec_data_unc_histos; ///< Data cross section uncertainties unpacked per every cos(theta) bin

  };
}

#endif
/** @} */ // end of doxygen group 


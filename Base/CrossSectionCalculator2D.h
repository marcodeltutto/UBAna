/**
 * \file CrossSectionCalculator2D.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class CrossSectionCalculator2D
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_CROSSSECTIONCALCULATOR2D_H__
#define __BASE_CROSSSECTIONCALCULATOR2D_H__

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
#include "TLine.h"

#include "Types.h"
#include "PlottingTools.h"

namespace Base {

  /**
     \class CrossSectionCalculator2D
     User defined class CrossSectionCalculator2D ... these comments are used to generate
     doxygen documentation!
  */
  class CrossSectionCalculator2D{
    
  public:
    
    /// Default constructor
    CrossSectionCalculator2D(){}
    
    /// Default destructor
    ~CrossSectionCalculator2D(){}

    /// Configure function parameters
    void SetScaleFactors(double bnbcosmic, double bnbon, double extbnb, double dirt = 0, double intimecosmic = 0);

    /// Sets the POT number
    void SetPOT(double pot);

    /// Set the plot name for saving and the label for the axis
    void SetNameAndLabel(std::string name, std::string label);

    /// Sets the outputdirectory
    void SetOutDir(std::string dir);

    /// Sets all the histograms
    void SetHistograms(std::map<std::string,TH2D*> bnbcosmic, TH2D* bnbon, TH2D* extbnb, std::map<std::string,TH2D*> dirt = std::map<std::string, TH2D*>(), TH2D* intimecosmic = 0);

    /// Sets num and dem histograms for the efficiency and the reco vs true 2d histo
    void SetTruthHistograms(TH2D*, TH2D*/*, TH2D**/);

    /// Sets truth XSec
    void SetTruthXSec(TH1D* xsec);

    /// Printd the current configuration
    void PrintConfig();

    ///
    void ProcessPlots();

    ///
    void Draw();

    ///
    void Draw(std::vector<std::string> histos_to_subtract);

    /// 
    double EstimateFlux(std::string flux_file_name = "MCC8_FluxHistograms_Uncertainties.root", std::string histogram_file_name = "numu/numu_CV_AV_TPC");

    ///
    THStack * ProcessTHStack(std::map<std::string,TH2D*> themap, TLegend*, std::vector<std::string>);

    ///
    TH2D* ProcessDataHisto(TH2D* histo);

    /// Extracts the cross section, provide a vector of background names to be subtracted in the first argument
    TH2D* ExtractCrossSection(std::vector<std::string> bkg_names, std::string, std::string, std::string);

    /// Returns the extracted MC cross section (must be called after ExtractCrossSection)
    TH2D* GetMCCrossSection() {return _h_mc;}

    ///
    void SetSmearingMatrix(std::vector<std::vector<std::vector<std::vector<double>>>>);

    ///
    void SetCovarianceMatrix(TH2D);

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

  private:

    std::string _namebase = "[CrossSectionCalculator2D] ";
    
    bool _configured = false;

    double _scale_factor_mc_bnbcosmic;
    double _scale_factor_bnbon;
    double _scale_factor_extbnb;
    double _scale_factor_mc_dirt;
    double _scale_factor_mc_intimecosmic;

    bool _dirt_is_set = false;

    double _pot;
    double _flux;

    double _n_target = 2.64218e31;

    std::string _name = "trklen"; 
    std::string _label = ";Test [cm]; Selected Events";

    std::string _outdir;
    std::string _folder;

    std::map<std::string,TH2D*> _hmap_bnbcosmic;
    std::map<std::string,TH2D*> _hmap_dirt;
    TH2D* _h_bnbon;
    TH2D* _h_extbnb;
    TH2D* _h_intimecosmic;

    TH2D* _h_eff_mumom_num;
    TH2D* _h_eff_mumom_den;
    //TH2D* _h_true_reco_mom;

    TH1D* _truth_xsec;

    TH2D* _h_data_sub;

    TEfficiency* _eff;

    TH2D* _h_mc = NULL; ///< The to-be extracted MC cross section
    TH2D* _h_data = NULL; ///< The to-be extracted data cross section

    std::vector<std::vector<std::vector<std::vector<double>>>> _S;

    double _flux_correction_weight = 1.; ///< Flux correction weight

    bool _verbose = true;

    double _extra_fractional_uncertainty = 0.; ///< Adds an extra uncertainty on the diagonal

    TH2D _covariance_matrix; ///< 2D Histogram representing the covariance matrix (to be set externally)
    bool _covariance_matrix_is_set = false; ///< Flag that remembers if the covariance matrix was set for this cross section calculation (if not, no syst will be added)

    TH2D *_frac_cov_matrix_total = NULL; ///< Total fractional covariance matrix
    TH2D *_cov_matrix_total = NULL; ///< Total  covariance matrix
    TH2D *_corr_matrix_total = NULL; ///< Total correlation matrix

  };
}

#endif
/** @} */ // end of doxygen group 


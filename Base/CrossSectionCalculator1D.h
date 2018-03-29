/**
 * \file CrossSectionCalculator1D.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class CrossSectionCalculator1D
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_CROSSSECTIONCALCULATOR1D_H__
#define __BASE_CROSSSECTIONCALCULATOR1D_H__

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

namespace Base {

  /**
     \class CrossSectionCalculator1D
     User defined class CrossSectionCalculator1D ... these comments are used to generate
     doxygen documentation!
  */
  class CrossSectionCalculator1D{
    
  public:
    
    /// Default constructor
    CrossSectionCalculator1D(){}
    
    /// Default destructor
    ~CrossSectionCalculator1D(){}

    /// Configure function parameters
    void SetScaleFactors(double bnbcosmic, double bnbon, double extbnb, double intimecosmic = 0);

    /// Sets the POT number
    void SetPOT(double pot);

    /// Set the plot name for saving and the label for the axis
    void SetNameAndLabel(std::string name, std::string label);

    /// Sets the outputdirectory
    void SetOutDir(std::string dir);

    /// Sets all the histograms
    void SetHistograms(std::map<std::string,TH1D*> bnbcosmic, TH1D* bnbon, TH1D* extbnb, TH1D* intimecosmic = 0);

    /// Sets num and dem histograms for the efficiency and the reco vs true 2d histo
    void SetTruthHistograms(TH1D*, TH1D*, TH2D*);

    /// Sets num and dem histograms for the efficiency
    void SetTruthHistograms(TH1D*, TH1D*);

    /// Sets truth XSec
    void SetTruthXSec(TH1D* xsec);

    ///
    void SetMigrationMatrix(TMatrix);

    ///
    void SetCovarianceMatrix(TH2D);

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
    THStack * ProcessTHStack(std::map<std::string,TH1D*> themap, TLegend*, std::vector<std::string>);

    ///
    TH1D* ProcessDataHisto(TH1D* histo);

    ///
    TH1D* ExtractCrossSection(std::string, std::string);

    ///
    void Smear(int n, int m);

    ///
    void DoNotSmear();

    ///
    TLatex* GetPOTLatex(double pot); 

    ///
    void Reset();

  private:
    
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

    std::map<std::string,TH1D*> _hmap_bnbcosmic;
    TH1D* _h_bnbon;
    TH1D* _h_extbnb;
    TH1D* _h_intimecosmic;

    TH1D* _h_eff_mumom_num;
    TH1D* _h_eff_mumom_den;
    TH2D* _h_true_reco_mom;

    TH1D* _truth_xsec;

    TH1D* _h_data_sub;

    TEfficiency* _eff;

    TMatrix _S; ///< The migration matrix (to be set externally)

    TH2D _covariance_matrix; ///< 2D Histogram representing the covariance matrix (to be set externally)
    bool _covariance_matrix_is_set = false; ///< Flag that remembers if the covariance matrix was set for this cross section calculation (if not, no syst will be added)
    
  };
}

#endif
/** @} */ // end of doxygen group 


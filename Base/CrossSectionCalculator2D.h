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
    void SetScaleFactors(double bnbcosmic, double bnbon, double extbnb, double intimecosmic = 0);

    /// Sets the POT number
    void SetPOT(double pot);

    /// Set the plot name for saving and the label for the axis
    void SetNameAndLabel(std::string name, std::string label);

    /// Sets the outputdirectory
    void SetOutDir(std::string dir);

    /// Sets all the histograms
    void SetHistograms(std::map<std::string,TH2D*> bnbcosmic, TH2D* bnbon, TH2D* extbnb, TH2D* intimecosmic = 0);

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

    ///
    TH2D* ExtractCrossSection(std::string, std::string, std::string);

    ///
    void SetSmearingMatrix(std::vector<std::vector<std::vector<std::vector<double>>>>);

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

    /// Draw a TH1 on the current pad with Data style
    void DrawData(TH1D h);

    ///
    void SetVerbosity(bool verbosity) {_verbose = verbosity;}

  private:

    std::string _namebase = "CrossSectionCalculator2D] ";
    
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

    std::map<std::string,TH2D*> _hmap_bnbcosmic;
    TH2D* _h_bnbon;
    TH2D* _h_extbnb;
    TH2D* _h_intimecosmic;

    TH2D* _h_eff_mumom_num;
    TH2D* _h_eff_mumom_den;
    //TH2D* _h_true_reco_mom;

    TH1D* _truth_xsec;

    TH2D* _h_data_sub;

    TEfficiency* _eff;

    std::vector<std::vector<std::vector<std::vector<double>>>> _S;

    double _flux_correction_weight = 1.; ///< Flux correction weight

    bool _verbose = false;

    
  };
}

#endif
/** @} */ // end of doxygen group 


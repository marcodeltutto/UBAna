/**
 * \file MigrationMatrix4D.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class MigrationMatrix4D
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_MIGRATIONMATRIX4D_H__
#define __BASE_MIGRATIONMATRIX4D_H__

#include <iostream>
#include <sstream>
#include <fstream>
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
#include "TLine.h"
#include "TGaxis.h"

#include "Types.h"

namespace Base {

  /**
     \class MigrationMatrix4D
     User defined class MigrationMatrix4D ... these comments are used to generate
     doxygen documentation!
  */
  class MigrationMatrix4D{
    
  public:
    
    /// Default constructor
    MigrationMatrix4D(){}
    
    /// Default destructor
    ~MigrationMatrix4D(){}

    ///
    Mat4D CalculateMigrationMatrix(); 

    /// Sets the TTree for all signal selected events, to construct S (no longer used)
    void SetTTree(TTree*);

    /// Set 2D reco histogram for every true bin m,n
    void SetRecoPerTrueHistos(std::vector<std::vector<TH2D*>>);

    ///
    void SetBins(const double *, int, const double *, int);

    ///
    void SetOutputFileName(std::string name);

    /// Sets the output directory
    void SetOutDir(std::string dir = "migration_matrix_4D_plots");

    ///
    void PrintSmearingMatrixLatex();

    ///
    void PrintSmearingMatrixLatex(int true_m, int true_n);

    ///
    void PlotMatrix();

    /// If called uses the weights with name specified
    void UseWeights(std::string weight_name = "universe0", std::string weight_type = "genie_multisim");


  private:

    std::string _prefix = "[MigrationMatrix4D] ";

    TTree *_tree;
    std::vector<std::vector<TH2D*>> _h_reco_per_true; ///< 2D reco histogram for every true bin m,n

    std::vector<std::pair<double, double>> _var1_bins;
    std::vector<std::pair<double, double>> _var2_bins;

    TH2D *_reco_per_true;

    Mat4D _S; ///< The smearing matrix

    std::ofstream _f_out; ///< The output file

    bool _verbose = false;

    std::string _outdir;
    std::string _folder = "MigrationMatrix4DPlots/";

    bool _use_weights = false; ///< If true uses additional wights (usually for multisim)
    std::string _weight_name = "not_set";
    std::string _weight_type = "not_set";
    
  };
}

#endif
/** @} */ // end of doxygen group 


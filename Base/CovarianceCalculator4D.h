/**
 * \file CovarianceCalculator4D.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class CovarianceCalculator4D
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_COVARIANCECALCULATOR4D_H__
#define __BASE_COVARIANCECALCULATOR4D_H__


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
#include <TLegend.h>
#include <TStyle.h>
#include <TString.h>
#include <TMatrix.h>
#include <TLine.h>

#include "ubana/DataTypes/BootstrapTH2D.h"
#include "ubana/DataTypes/BootstrapTH2DPoly.h"
#include "Types.h"
#include "PlottingTools.h"

#include "LoggerFeature.h"


using namespace DataTypes;

namespace Base {

  /**
     \class CovarianceCalculator4D
     User defined class CovarianceCalculator4D ... these comments are used to generate
     doxygen documentation!
  */
  class CovarianceCalculator4D : public LoggerFeature {
    
  public:
    
    /// Default constructor
    CovarianceCalculator4D(std::string name = "CovarianceCalculator4D") 
    : LoggerFeature(name) {}
    
    /// Default destructor
    ~CovarianceCalculator4D(){}

    ///
    void SetBootstrap(BootstrapTH2D);

    ///
    void SetBootstrap(BootstrapTH2DPoly);

    /// Runs the covariance matrix calculator
    void CalculateCovarianceMatrix();

    /// Not squared
    void AddExtraDiagonalUncertainty(double);

    /// 
    void GetCovarianceMatrix(TH2D &);

    /// 
    void GetFractionalCovarianceMatrix(TH2D &);

    ///
    void PlotMatrices();

    ///
    void SetPrefix(std::string);

  private:

    void CalculateCovarianceMatrixNormal();
    void CalculateCovarianceMatrixPoly();

    void PlotMatricesBase(TH2D *, TH2D *, TH2D *);
    void PlotMatricesNormal();
    void PlotMatricesPoly();




    std::string _name = "[CovarianceCalculator4D] ";

    BootstrapTH2D _bs; ///< The Bootstrap containing the cross sections for every universe
    BootstrapTH2DPoly _bs_poly; ///< The Bootstrap containing the cross sections for every universe (polybin)

    std::string _prefix;

    Mat4D _M;      ///< The covariance matrix
    Mat4D _M_frac; ///< The fractional covariance matrix
    Mat4D _RHO;    ///< The correlation matrix

    TMatrix _M_p;      ///< The covariance matrix (polybin)
    TMatrix _M_frac_p; ///< The fractional covariance matrix (polybin)
    TMatrix _RHO_p;    ///< The correlation matrix (polybin)
 
    TH2D _M_h;       ///< The covariance matrix in histogram form
    TH2D _M_frac_h;  ///< The fractional covariance matrix in histogram form
    TH2D _RHO_h;     ///< The correlation matrix in histogram form

    // bool _verbose = true;

    double _extra_relative_uncertainty = 0.; ///< Extra uncertainty to be added to the diagonal

    bool _polybin_mode = false;
    
  };
}

#endif
/** @} */ // end of doxygen group 


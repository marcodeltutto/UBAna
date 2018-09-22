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

#include "BootstrapTH2D.h"
#include "Types.h"
#include "PlottingTools.h"

namespace Base {

  /**
     \class CovarianceCalculator4D
     User defined class CovarianceCalculator4D ... these comments are used to generate
     doxygen documentation!
  */
  class CovarianceCalculator4D{
    
  public:
    
    /// Default constructor
    CovarianceCalculator4D(){}
    
    /// Default destructor
    ~CovarianceCalculator4D(){}

     ///
    void SetBootstrap(BootstrapTH2D);

    ///
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

    std::string _name = "[CovarianceCalculator4D] ";

    BootstrapTH2D _bs;

    std::string _prefix;

    Mat4D _M;      ///< The covariance matrix
    Mat4D _M_frac; ///< The fractional covariance matrix
    Mat4D _RHO;    ///< The correlation matrix
 
    TH2D _M_h;       ///< The covariance matrix in histogram form
    TH2D _M_frac_h;  ///< The fractional covariance matrix in histogram form
    TH2D _RHO_h;     ///< The correlation matrix in histogram form

    // bool _verbose = true;

    double _extra_relative_uncertainty = 0.; ///< Extra uncertainty to be added to the diagonal
    
  };
}

#endif
/** @} */ // end of doxygen group 


/**
 * \file CovarianceCalculator2D.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class CovarianceCalculator2D
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_COVARIANCECALCULATOR2D_H__
#define __BASE_COVARIANCECALCULATOR2D_H__


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
#include <TObject.h>



#include "BootstrapTH1D.h"

namespace Base {

  /**
     \class CovarianceCalculator2D
     User defined class CovarianceCalculator2D ... these comments are used to generate
     doxygen documentation!
  */
  class CovarianceCalculator2D{
    
  public:
    
    /// Default constructor
    CovarianceCalculator2D(){}
    
    /// Default destructor
    ~CovarianceCalculator2D(){}

     ///
    void SetBootstrap(BootstrapTH1D);

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

    std::string _name = "[CovarianceCalculator2D] ";

    BootstrapTH1D _bs;

    std::string _prefix;

    TMatrix _M;      ///< The covariance matrix
    TMatrix _M_frac; ///< The fractional covariance matrix
    TMatrix _RHO;    ///< The correlation matrix
 
    TH2D _M_h;       ///< The covariance matrix in histogram form
    TH2D _M_frac_h;  ///< The fractional covariance matrix in histogram form
    TH2D _RHO_h;     ///< The correlation matrix in histogram form

    bool _verbose = true;

    double _extra_relative_uncertainty = 0.; ///< Extra uncertainty to be added to the diagonal
    
  };
}

#endif
/** @} */ // end of doxygen group 


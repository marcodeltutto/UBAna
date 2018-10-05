/**
 * \file UncertaintyPlotter.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class UncertaintyPlotter
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_UNCERTAINTYPLOTTER_H__
#define __BASE_UNCERTAINTYPLOTTER_H__

#include <iostream>
#include <string>
#include <vector>
#include <TCanvas.h>
#include <TLegend.h>
#include <TH1D.h>
#include <TH2D.h>


namespace Base {

  /**
     \class UncertaintyPlotter
     User defined class UncertaintyPlotter ... these comments are used to generate
     doxygen documentation!
  */
  class UncertaintyPlotter{
    
  public:
    
    /// Default constructor
    UncertaintyPlotter(){}
    
    /// Default destructor
    ~UncertaintyPlotter(){}

    /// Add a fraction covariance matrix with a name
    void AddFracCovarianceMatrix(std::string, TH2D);

    /// Set the cross section
    void SetCrossSection(TH1D xsec) {_xsec_1d = xsec;}

    /// Constructs and saved the plot
    void MakePlot(std::string file_name);

    /// Sets the title of the x axis for the plot
    void SetXaxisTitle(std::string title) { _xaxis_title = title;}

    /// Resets current settings
    void Reset();

    

  protected:

    std::vector<std::string> _cov_names; ///< The names of the covariance matrices
    std::vector<TH2D> _frac_cov_v; ///< The fractional covariance matrices
    TH1D _xsec_1d; ///< The cross section

    std::vector<Int_t> _line_colors = {kRed+1, kBlue+1, kGreen+1, 10, 11, 12, 13, 14, 15, 16, 17};
    std::string _xaxis_title;
    
  };
}

#endif
/** @} */ // end of doxygen group 


/**
 * \file BootstrapTH2DPoly.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class BootstrapTH2DPoly
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __DATATYPES_BOOTSTRAPTH2DPOLY_H__
#define __DATATYPES_BOOTSTRAPTH2DPOLY_H__

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
#include <algorithm>

#include <TH2D.h>
#include "UBTH2Poly.h"


namespace DataTypes {

  /**
     \class BootstrapTH2DPoly
     User defined class BootstrapTH2DPoly ... these comments are used to generate
     doxygen documentation!
  */
  class BootstrapTH2DPoly{
    
  public:
    
    /// Default constructor
    BootstrapTH2DPoly(){}

    /// Constructor
    BootstrapTH2DPoly(std::string name,std::string title, Double_t xlow, Double_t xup, Double_t ylow, Double_t yup, Int_t n_bins_x);
    
    /// Default destructor
    ~BootstrapTH2DPoly(){}

    /// Add a rectangular bin
    void AddBin(Double_t x1, Double_t y1, Double_t x2, Double_t y2);

    /// Sets the number of bins along x
    void SetNBinsX(Int_t n);

    /// Sets a vector containing the boundaris for Y variable
    void SetSeparators(std::vector<int> v);

    ///
    void PrintConfig(){std::cout << "_hname is " << _hname << std::endl;
    /*std::cout << "map size is " << _hmap.size() << std::endl;*/}

    ///
    void SetWeightNames(std::vector<std::string>);

    /// Emplaces all histograms on the fly
    void SetAllHistograms(std::map<std::string,UBTH2Poly*>);

    /// Returns the number of bins along x
    int GetNbinsX();

    /// Returns the total number of bins
    int GetNumberOfBins();

    /// Returns the number of universes
    int GetNUniverses();

    /// Returns the number of weigths (should be the same as the number of universes)
    size_t GetNWeights();

    /// Returns a vector with the names of the universes
    std::vector<std::string> GetUniverseNames();

    /// Sets the iterator to the first universe, use this at the beginning of a loop over universes
    void ResetIterator();

    /// Returns the histogram for the next universe
    const UBTH2Poly & NextUniverse();

    /// Returns the histogram for the current universe (has to be called after a NextUniverse())
    const UBTH2Poly & SameUniverse();

    ///
    // std::map<std::string, std::vector<UBTH2Poly>> UnpackPMHisto();

    /// Fill the value bin with a general weight and the vector of weights
    void Fill(double, double, double, std::vector<double>);

    /// Returns the nominal histogram
    UBTH2Poly * GetNominal();

    /// Returns the histogram for a particular universe
    UBTH2Poly * GetUniverseHisto(std::string);

    /// Returns the histogram for a particular universe, w/o checking if that universe exists (may crash)
    // void GetUniverseHistoFast(std::string, UBTH2Poly &);

  protected:

    std::string _name = "[BootstrapTH2DPoly] ";

    std::string _hname; ///< Histogram name
    std::string _title; ///< Histogram title
    int _nbins_x; ///< Histogram n bins X
    double _xlow; ///< Histogram boundaries
    double _xup; ///< Histogram boundaries
    double _ylow; ///< Histogram boundaries
    double _yup; ///< Histogram boundaries

    // std::map<std::string, UBTH2Poly> _hmap; ///< Histogram map ("nominal", "universe1"...)
    std::vector<UBTH2Poly*> _h_v; ///< The vector of histograms 
    std::vector<std::string> _name_v; ///< The name of the above histograms ("nominal", "universe1"...)

    size_t _n_weights = 0; ///< Number of weigths to use
    std::vector<double> _weights; ///< Weigths to use
    std::vector<std::string> _wnames; ///< Weight names

    //std::map<std::string, TH1D*>::iterator _current_iterator = _hmap.begin();
    // std::map<std::string, UBTH2Poly>::iterator _current_iterator; //!
    int _current_vector_index = 0;

  };
}

#endif
/** @} */ // end of doxygen group 


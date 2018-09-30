/**
 * \file BootstrapTH1D.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class BootstrapTH1D
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_BOOTSTRAPTH1D_H__
#define __BASE_BOOTSTRAPTH1D_H__

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

#include <TH1D.h>

namespace Base {

  /**
     \class BootstrapTH1D
     User defined class BootstrapTH1D ... these comments are used to generate
     doxygen documentation!
  */
  class BootstrapTH1D{
    
  public:
    
    /// Default constructor
    BootstrapTH1D(){}

    /// Constructor
    BootstrapTH1D(std::string, std::string, int, double*);

    /// Constructor
    BootstrapTH1D(std::string, std::string, int, double, double);
    
    /// Default destructor
    ~BootstrapTH1D(){}

    ///
    void PrintConfig(){std::cout << "_hname is " << _hname << std::endl;
    /*std::cout << "map size is " << _hmap.size() << std::endl;*/}

    ///
    void SetWeightNames(std::vector<std::string>);

    /// Emplaces all histograms on the fly
    void SetAllHistograms(std::map<std::string,TH1D*>);

    /// Returns the number of bins along x
    int GetNbinsX();

    /// Returns the number of universes
    int GetNUniverses();

    /// Returns the number of weigths (should be the same as the number of universes)
    size_t GetNWeights();

    /// Returns a vector with the names of the universes
    std::vector<std::string> GetUniverseNames();

    /// Sets the iterator to the first universe, use this at the beginning of a loop over universes
    void ResetIterator();

    /// Returns the hitogram for the next universe
    const TH1D & NextUniverse();

    /// Returns the hitogram for the current universe (has to be called after a NextUniverse())
    const TH1D & SameUniverse();

    ///
    std::map<std::string, std::vector<TH1D>> UnpackPMHisto();

    /// Fill the value bin with a general weight and the vector of weights
    void Fill(double, double, std::vector<double>);

    /// Returns the nominal histogram
    const TH1D& GetNominal();

    /// Returns the histogram for a particular universe
    void GetUniverseHisto(std::string, TH1D &);

    /// Returns the histogram for a particular universe, w/o checking if that universe exists (may crash)
    void GetUniverseHistoFast(std::string, TH1D &);

  protected:

    std::string _name = "[BootstrapTH1D] ";

    std::string _hname; ///< Histogram name
    std::string _title; ///< Histogram title
    int _nbins; ///< Histogram n bins
    std::vector<double> _bins; ///< Histogram bins array

    std::map<std::string, TH1D> _hmap; ///< Histogram map ("nominal", "universe1"...)
    std::vector<TH1D> _h_v; ///< The vector of histograms 
    std::vector<std::string> _name_v; ///< The name of the above histograms ("nominal", "universe1"...)

    size_t _n_weights = 0; ///< Number of weigths to use
    std::vector<double> _weights; ///< Weigths to use
    std::vector<std::string> _wnames; ///< Weight names

    //std::map<std::string, TH1D*>::iterator _current_iterator = _hmap.begin();
    std::map<std::string, TH1D>::iterator _current_iterator; //!
    int _current_vector_index = 0;

  };
}

#endif
/** @} */ // end of doxygen group 


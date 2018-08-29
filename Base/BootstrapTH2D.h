/**
 * \file BootstrapTH2D.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class BootstrapTH2D
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_BOOTSTRAPTH2D_H__
#define __BASE_BOOTSTRAPTH2D_H__

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

namespace Base {

  /**
     \class BootstrapTH2D
     User defined class BootstrapTH2D ... these comments are used to generate
     doxygen documentation!
  */
  class BootstrapTH2D{
    
  public:
    
    /// Default constructor
    BootstrapTH2D(){}

    /// Constructor
    BootstrapTH2D(std::string, std::string, int, double*, int, double*);

    /// Constructor
    // BootstrapTH2D(std::string, std::string, int, double, double);
    
    /// Default destructor
    ~BootstrapTH2D(){}

    ///
    void PrintConfig(){std::cout << "_hname is " << _hname << std::endl;
    /*std::cout << "map size is " << _hmap.size() << std::endl;*/}

    ///
    void SetWeightNames(std::vector<std::string>);

    /// Emplaces all histograms on the fly
    void SetAllHistograms(std::map<std::string,TH2D*>);

    /// Returns the number of bins along x
    int GetNbinsX();

    /// Returns the number of bins along y
    int GetNbinsY();

    /// Returns the number of universes
    int GetNUniverses();

    /// Returns the number of weigths (should be the same as the number of universes)
    size_t GetNWeights();

    /// Returns a vector with the names of the universes
    std::vector<std::string> GetUniverseNames();

    /// Sets the iterator to the first universe, use this at the beginning of a loop over universes
    void ResetIterator();

    /// Returns the hitogram for the next universe
    const TH2D & NextUniverse();

    /// Returns the hitogram for the current universe (has to be called after a NextUniverse())
    const TH2D & SameUniverse();

    ///
    std::map<std::string, std::vector<TH2D>> UnpackPMHisto();

    /// Fill the value bin with a general weight and the vector of weights
    void Fill(double, double, double, std::vector<double>);

    /// Returns the nominal histogram
    const TH2D& GetNominal();

    /// Returns the histogram for a particular universe
    void GetUniverseHisto(std::string, TH2D &);

    /// Returns the histogram for a particular universe, w/o checking if that universe exists (may crash)
    void GetUniverseHistoFast(std::string, TH2D &);

  protected:

    std::string _name = "[BootstrapTH2D] ";

    std::string _hname; ///< Histogram name
    std::string _title; ///< Histogram title
    int _nbins_x; ///< Histogram n bins X
    std::vector<double> _bins_x; ///< Histogram bins array X
    int _nbins_y; ///< Histogram n bins Y
    std::vector<double> _bins_y; ///< Histogram bins array Y

    std::map<std::string, TH2D> _hmap; ///< Histogram map ("nominal", "universe1"...)
    std::vector<TH2D> _h_v; ///< The vector of histograms 
    std::vector<std::string> _name_v; ///< The name of the above histograms ("nominal", "universe1"...)

    size_t _n_weights; ///< Number of weigths to use
    std::vector<double> _weights; ///< Weigths to use
    std::vector<std::string> _wnames; ///< Weight names

    //std::map<std::string, TH1D*>::iterator _current_iterator = _hmap.begin();
    std::map<std::string, TH2D>::iterator _current_iterator; //!
    int _current_vector_index = 0;

  };
}

#endif
/** @} */ // end of doxygen group 


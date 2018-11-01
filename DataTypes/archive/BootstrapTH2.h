/**
 * \file BootstrapTH2.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class BootstrapTH2
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_BOOTSTRAPTH2_H__
#define __BASE_BOOTSTRAPTH2_H__

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
     \class BootstrapTH2
     User defined class BootstrapTH2 ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  class BootstrapTH2{

  static_assert( std::is_same< T, TH2D >::value ||
                 std::is_same< T, UBTH2Poly>::value,
                 "BootstrapTH2 only defined for TH2D and UBTH2Poly" );
    
  public:
    
    /// Default constructor
    BootstrapTH2(){}

    /// Constructor (TH2)
    BootstrapTH2(std::string name, std::string title, int nbinsX, double *binsX, int nbinsY, double *binsY) /*: TObject()*/
  {

    _h_v.clear();
    _name_v.clear();

    T temp((name+"nominal").c_str(), title.c_str(), nbinsX, binsX, nbinsY, binsY);
    _hmap["nominal"] = temp;
    _hname = name;
    _title = title;

    _h_v.emplace_back(temp);
    _name_v.push_back("nominal");

    _nbins_x = nbinsX;
    _bins_x.resize(nbinsX+1);
    for (size_t i = 0; i < _bins_x.size(); i++) {
      _bins_x.at(i) = binsX[i];
    }

    _nbins_y = nbinsY;
    _bins_y.resize(nbinsY+1);
    for (size_t i = 0; i < _bins_y.size(); i++) {
      _bins_y.at(i) = binsY[i];
    }

  }




    /// Constructor
    // BootstrapTH2(std::string, std::string, int, double, double);
    
    /// Default destructor
    ~BootstrapTH2(){}

    ///
    void PrintConfig(){std::cout << "_hname is " << _hname << std::endl;
    /*std::cout << "map size is " << _hmap.size() << std::endl;*/}

    ///
    void SetWeightNames(std::vector<std::string> names)
  {

    _n_weights = names.size() + 1;
    std::cout << "Bootstrap " << _hname << " set up with " << _n_weights << " weights." << std::endl;
    _wnames = names;
    _wnames.push_back("nominal");
    double* bins_x = &_bins_x[0];
    double* bins_y = &_bins_y[0];
    for (size_t i = 0; i < _n_weights - 1; i++) {
        T temp((_hname+names.at(i)).c_str(), _title.c_str(), _nbins_x, bins_x, _nbins_y, bins_y);
      _hmap[names.at(i)] = temp;
      _h_v.emplace_back(temp);
      _name_v.push_back(names.at(i));
    }
    
  }

    /// Emplaces all histograms on the fly
    void SetAllHistograms(std::map<std::string,T*>);

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
    const T & NextUniverse();

    /// Returns the hitogram for the current universe (has to be called after a NextUniverse())
    const T & SameUniverse();

    ///
    std::map<std::string, std::vector<T>> UnpackPMHisto();

    /// Fill the value bin with a general weight and the vector of weights
    void Fill(double value1, double value2, double weight, std::vector<double> weights)
  {

    if (weights.size() != _n_weights-1) {
      std::cout << __PRETTY_FUNCTION__ << " Size mismatch, this weight vector has size " << weights.size() 
                << ", but " << _n_weights-1 << " is expected. This is Bootstrap " << _hname << "::" << _title << std::endl;
      throw std::exception();
    }

    _hmap["nominal"].Fill(value1, value2, weight);
    _h_v.at(0).Fill(value1, value2, weight); // The nominal histogram


    for (size_t i = 1; i < _n_weights; i++) {

     _h_v.at(i).Fill(value1, value2, weight * weights.at(i-1));

   }

  }

    /// Returns the nominal histogram
    const T& GetNominal();

    /// Returns the histogram for a particular universe
    void GetUniverseHisto(std::string, T &);

    /// Returns the histogram for a particular universe, w/o checking if that universe exists (may crash)
    void GetUniverseHistoFast(std::string, T &);

  protected:

    std::string _name = "[BootstrapTH2] ";

    std::string _hname; ///< Histogram name
    std::string _title; ///< Histogram title
    int _nbins_x; ///< Histogram n bins X
    std::vector<double> _bins_x; ///< Histogram bins array X
    int _nbins_y; ///< Histogram n bins Y
    std::vector<double> _bins_y; ///< Histogram bins array Y

    std::map<std::string, T> _hmap; ///< Histogram map ("nominal", "universe1"...)
    std::vector<T> _h_v; ///< The vector of histograms 
    std::vector<std::string> _name_v; ///< The name of the above histograms ("nominal", "universe1"...)

    size_t _n_weights; ///< Number of weigths to use
    std::vector<double> _weights; ///< Weigths to use
    std::vector<std::string> _wnames; ///< Weight names

    //std::map<std::string, TH1D*>::iterator _current_iterator = _hmap.begin();
    typename std::map<std::string, T>::iterator _current_iterator; //!
    int _current_vector_index = 0;

  };
}

#endif
/** @} */ // end of doxygen group 


#ifndef __BASE_BOOTSTRAPTH2_CXX__
#define __BASE_BOOTSTRAPTH2_CXX__

#include "BootstrapTH2.h"

namespace DataTypes {

 
  // template <class T>
  // BootstrapTH2<T>::BootstrapTH2(std::string name, std::string title, int nbinsX, double *binsX, int nbinsY, double *binsY) /*: TObject()*/
  // {

  //   _h_v.clear();
  //   _name_v.clear();

  //   T temp((name+"nominal").c_str(), title.c_str(), nbinsX, binsX, nbinsY, binsY);
  //   _hmap["nominal"] = temp;
  //   _hname = name;
  //   _title = title;

  //   _h_v.emplace_back(temp);
  //   _name_v.push_back("nominal");

  //   _nbins_x = nbinsX;
  //   _bins_x.resize(nbinsX+1);
  //   for (size_t i = 0; i < _bins_x.size(); i++) {
  //     _bins_x.at(i) = binsX[i];
  //   }

  //   _nbins_y = nbinsY;
  //   _bins_y.resize(nbinsY+1);
  //   for (size_t i = 0; i < _bins_y.size(); i++) {
  //     _bins_y.at(i) = binsY[i];
  //   }

  // }


  // template <class T>
  // void BootstrapTH2<T>::SetWeightNames(std::vector<std::string> names)
  // {

  //   _n_weights = names.size() + 1;
  //   std::cout << "Bootstrap " << _hname << " set up with " << _n_weights << " weights." << std::endl;
  //   _wnames = names;
  //   _wnames.push_back("nominal");
  //   double* bins_x = &_bins_x[0];
  //   double* bins_y = &_bins_y[0];
  //   for (size_t i = 0; i < _n_weights - 1; i++) {
  //   	T temp((_hname+names.at(i)).c_str(), _title.c_str(), _nbins_x, bins_x, _nbins_y, bins_y);
  //     _hmap[names.at(i)] = temp;
  //     _h_v.emplace_back(temp);
  //     _name_v.push_back(names.at(i));
  //   }
    
  // }

  template <class T>
  void BootstrapTH2<T>::SetAllHistograms(std::map<std::string,T*> input_map) 
  {

    for (auto it : input_map) {
      _h_v.push_back(*it.second);
      _name_v.push_back(it.first);
    }

    _nbins_x = _h_v.at(0).GetNbinsX();
    _nbins_y = _h_v.at(0).GetNbinsY();

    _n_weights = _h_v.size();

    _wnames.clear();

    for (auto n : _name_v) {
      _wnames.push_back(n);
    }

    _hname = _h_v.at(0).GetTitle();
    _title = _h_v.at(0).GetTitle();

  }

  template <class T>
  int BootstrapTH2<T>::GetNbinsX()
  {
    return _nbins_x;
  }

  template <class T>
  int BootstrapTH2<T>::GetNbinsY()
  {
    return _nbins_y;
  }

  template <class T>
  int BootstrapTH2<T>::GetNUniverses()
  {

    if (_h_v.size() != _name_v.size()) {
      std::cout << _name << "Histo vector and name vector do not have the same number of entries" << std::endl;
      throw std::exception();
    }

    return _h_v.size();
  }

  template <class T>
  size_t BootstrapTH2<T>::GetNWeights()
  {
    std::cout << "This is Bootstrap " << _hname << "::" << _title << std::endl;
    return _n_weights;
  }

  template <class T>
  std::vector<std::string> BootstrapTH2<T>::GetUniverseNames()
  {
    std::cout << "This is Bootstrap " << _hname << "::" << _title << std::endl;
    return _name_v;
  }

  template <class T>
  void BootstrapTH2<T>::ResetIterator()
  {
    _current_iterator = _hmap.begin();
    _current_vector_index = -1;
  }

  template <class T>
  const T & BootstrapTH2<T>::NextUniverse() {

    _current_vector_index++;

    if (_current_vector_index >= (int)_h_v.size()) {
      std::cout << "BootstrapTH2::NextUniverse() error index from " << _name << std::endl;
      throw std::exception();
    }

    if (_name_v.at(_current_vector_index) == "nominal") {
      _current_vector_index++;

      if (_current_vector_index >= (int)_h_v.size()) {
        std::cout << "BootstrapTH2::NextUniverse() error index from " << _name << std::endl;
        throw std::exception();
      }
    }
    
    return _h_v.at(_current_vector_index);
  } 


  template <class T>
  const T & BootstrapTH2<T>::SameUniverse() {

    if (_current_vector_index < 0 || _current_vector_index > (int)_h_v.size()) {
      std::cout << "BootstrapTH2::SameUniverse() error index from " << _name << std::endl;
      throw std::exception();
    }
    
    return _h_v.at(_current_vector_index);
  }


  template <class T>
  std::map<std::string, std::vector<T>> BootstrapTH2<T>::UnpackPMHisto()
  {

    std::map<std::string, std::vector<T>> output_map;

    for (size_t i = 0; i < _name_v.size(); i++) {

      if (_name_v.at(i) == "nominal") continue;

      // Minus 1 sigma
      std::size_t pos = _name_v.at(i).find("_m1");
      if (pos != std::string::npos) {  
        std::string function_name = _name_v.at(i).substr (0, pos);

        //std::cout << "Minus 1, substrig is " << function_name << std::endl;

        std::vector<T> vec;
        vec.resize(2);
        vec.at(0) = _h_v.at(i);

        output_map[function_name] = vec;

      }

      // Plus 1 sigma
      pos = _name_v.at(i).find("_p1");
      if (pos != std::string::npos) {  
        std::string function_name = _name_v.at(i).substr (0, pos);

        //std::cout << "Plus 1, substrig is " << function_name << std::endl;

        output_map[function_name].at(1) =  _h_v.at(i);
      }
    }

    return output_map;
  }


  // template <class T>
  // void BootstrapTH2<T>::Fill(double value1, double value2, double weight, std::vector<double> weights)
  // {

  //   if (weights.size() != _n_weights-1) {
  //     std::cout << __PRETTY_FUNCTION__ << " Size mismatch, this weight vector has size " << weights.size() 
  //               << ", but " << _n_weights-1 << " is expected. This is Bootstrap " << _hname << "::" << _title << std::endl;
  //     throw std::exception();
  //   }

  //   _hmap["nominal"].Fill(value1, value2, weight);
  //   _h_v.at(0).Fill(value1, value2, weight); // The nominal histogram


  //   for (size_t i = 1; i < _n_weights; i++) {

  //    _h_v.at(i).Fill(value1, value2, weight * weights.at(i-1));

  //  }

  // }


  template <class T>
  const T& BootstrapTH2<T>::GetNominal()
  {
    return _h_v.at(0);
  }


  template <class T>
  void BootstrapTH2<T>::GetUniverseHisto(std::string uni_name, T & histo)
  {

    auto iter = std::find(_name_v.begin(), _name_v.end(), uni_name);
    if (iter == _name_v.end()) {
      std::cout << __PRETTY_FUNCTION__ << " :: Histomgram for universe " << uni_name << " not found! This is Bootstrap " << _hname << "::" << _title << std::endl;
      throw std::exception();
    }

    int position = iter - _name_v.begin();

    histo = _h_v.at(position);

    return;
  }


  template <class T>
  void BootstrapTH2<T>::GetUniverseHistoFast(std::string uni_name, T & histo)
  {

    histo = _hmap[uni_name];

    return;
  }




  


}

#endif

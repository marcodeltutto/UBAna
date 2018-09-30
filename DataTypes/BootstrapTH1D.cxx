#ifndef __DATATYPES_BOOTSTRAPTH1D_CXX__
#define __DATATYPES_BOOTSTRAPTH1D_CXX__

#include "BootstrapTH1D.h"

namespace DataTypes {

 

  BootstrapTH1D::BootstrapTH1D(std::string name, std::string title, int nbins, double *bins) /*: TObject()*/
  {

    _h_v.clear();
    _name_v.clear();

  	TH1D temp((name+"nominal").c_str(), title.c_str(), nbins, bins);
    _h_v.emplace_back(temp);
    _name_v.push_back("nominal");
    _hname = name;
    _title = title;
    _nbins = nbins;
    _bins.resize(nbins+1);
    for (size_t i = 0; i < _bins.size(); i++) {
      _bins.at(i) = bins[i];
    }
  }

  BootstrapTH1D::BootstrapTH1D(std::string name, std::string title, int nbins, double bin_start, double bin_end) 
  {
    _h_v.clear();
    _name_v.clear();

    TH1D temp((name+"nominal").c_str(), title.c_str(), nbins, bin_start, bin_end);
    _h_v.emplace_back(temp);
    _name_v.push_back("nominal");
    _hname = name;
    _title = title;
    _nbins = nbins;
    _bins.resize(nbins+1);
    double bin_size = (bin_end - bin_start) / (double) nbins;

    for (double i = bin_start; i < bin_end; i++) {
      _bins.at(i) = i;
      i+= bin_size;
    }

    _bins.at(nbins) = bin_end;

  }



  void BootstrapTH1D::SetWeightNames(std::vector<std::string> names)
  {

    _n_weights = names.size() + 1;
    std::cout << "Bootstrap " << _hname << " set up with " << _n_weights << " weights." << std::endl;
    _wnames = names;
    _wnames.push_back("nominal");
    double* bins = &_bins[0];
    for (size_t i = 0; i < _n_weights - 1; i++) {
    	TH1D temp((_hname+names.at(i)).c_str(), _title.c_str(), _nbins, bins);
      _h_v.emplace_back(temp);
      _name_v.push_back(names.at(i));
    }
    
  }

  void BootstrapTH1D::SetAllHistograms(std::map<std::string,TH1D*> input_map) 
  {

    for (auto it : input_map) {
      _h_v.push_back(*it.second);
      _name_v.push_back(it.first);
    }

    _nbins = _h_v.at(0).GetNbinsX();

    _n_weights = _h_v.size();

    _wnames.clear();

    for (auto n : _name_v) {
      _wnames.push_back(n);
    }

    _hname = _h_v.at(0).GetTitle();
    _title = _h_v.at(0).GetTitle();

  }

  int BootstrapTH1D::GetNbinsX()
  {
    return _nbins;
  }

  int BootstrapTH1D::GetNUniverses()
  {

    if (_h_v.size() != _name_v.size()) {
      std::cout << _name << "Histo vector and name vector do not have the same number of entries" << std::endl;
      throw std::exception();
    }

    return _h_v.size();
  }

  size_t BootstrapTH1D::GetNWeights()
  {
    std::cout << "This is Bootstrap " << _hname << "::" << _title << std::endl;
    return _n_weights;
  }

  std::vector<std::string> BootstrapTH1D::GetUniverseNames()
  {
    std::cout << "This is Bootstrap " << _hname << "::" << _title << std::endl;
    return _name_v;
  }

  void BootstrapTH1D::ResetIterator()
  {
    _current_vector_index = -1;
  }

  const TH1D & BootstrapTH1D::NextUniverse() {

    _current_vector_index++;

    if (_current_vector_index >= (int)_h_v.size()) {
      std::cout << "BootstrapTH1D::NextUniverse() error index from " << _name << std::endl;
      throw std::exception();
    }

    if (_name_v.at(_current_vector_index) == "nominal") {
      _current_vector_index++;

      if (_current_vector_index >= (int)_h_v.size()) {
        std::cout << "BootstrapTH1D::NextUniverse() error index from " << _name << std::endl;
        throw std::exception();
      }
    }

    return _h_v.at(_current_vector_index);

  } 



  const TH1D & BootstrapTH1D::SameUniverse() {

    if (_current_vector_index < 0 || _current_vector_index > (int)_h_v.size()) {
      std::cout << "BootstrapTH1D::SameUniverse() error index from " << _name << std::endl;
      throw std::exception();
    }
        
    return _h_v.at(_current_vector_index);
  }



  std::map<std::string, std::vector<TH1D>> BootstrapTH1D::UnpackPMHisto()
  {

    std::map<std::string, std::vector<TH1D>> output_map;

    for (size_t i = 0; i < _name_v.size(); i++) {

      if (_name_v.at(i) == "nominal") continue;

      // Minus 1 sigma
      std::size_t pos = _name_v.at(i).find("_m1");
      if (pos != std::string::npos) {  
        std::string function_name = _name_v.at(i).substr (0, pos);

        std::vector<TH1D> vec;
        vec.resize(2);
        vec.at(0) = _h_v.at(i);

        output_map[function_name] = vec;

      }

      // Plus 1 sigma
      pos = _name_v.at(i).find("_p1");
      if (pos != std::string::npos) {  
        std::string function_name = _name_v.at(i).substr (0, pos);

        output_map[function_name].at(1) =  _h_v.at(i);
      }
    }

    return output_map;
  }

  void BootstrapTH1D::Fill(double value, double weight, std::vector<double> weights)
  {

    if (weights.size() != _n_weights-1) {
      std::cout << __PRETTY_FUNCTION__ << " Size mismatch, this weight vector has size " << weights.size() 
                << ", but " << _n_weights-1 << " is expected. This is Bootstrap " << _hname << "::" << _title << std::endl;
      throw std::exception();
    }

    _h_v.at(0).Fill(value, weight); // The nominal histogram


    for (size_t i = 1; i < _n_weights; i++) {

     _h_v.at(i).Fill(value, weight * weights.at(i-1));

   }

  }

  const TH1D& BootstrapTH1D::GetNominal()
  {
    return _h_v.at(0);
  }

  void BootstrapTH1D::GetUniverseHisto(std::string uni_name, TH1D & histo)
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

 




  


}

#endif

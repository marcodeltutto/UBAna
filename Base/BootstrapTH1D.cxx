#ifndef __BASE_BOOTSTRAPTH1D_CXX__
#define __BASE_BOOTSTRAPTH1D_CXX__

#include "BootstrapTH1D.h"

namespace Base {

 

  BootstrapTH1D::BootstrapTH1D(std::string name, std::string title, int nbins, double *bins) /*: TObject()*/
  {
  	TH1D temp((name+"nominal").c_str(), title.c_str(), nbins, bins);
    _hmap["nominal"] = temp;
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
    TH1D temp((name+"nominal").c_str(), title.c_str(), nbins, bin_start, bin_end);
    _hmap["nominal"] = temp;
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
    //std::cout << "Bootstrap set up with " << _n_weights << " weights." << std::endl;
    _wnames = names;
    _wnames.push_back("nominal");
    double* bins = &_bins[0];
    for (size_t i = 0; i < _n_weights - 1; i++) {
    	TH1D temp((_hname+names.at(i)).c_str(), _title.c_str(), _nbins, bins);
      _hmap[names.at(i)] = temp;
    }
    
  }

  void BootstrapTH1D::SetAllHistograms(std::map<std::string,TH1D*> input_map) 
  {


  	for (auto it : input_map) {
  		_hmap[it.first] = *it.second;
      std::cout << "[BootstrapTH1D] Setting up histogram " << it.first << std::endl;
  	}

    _nbins = _hmap.begin()->second.GetNbinsX();

    _n_weights = _hmap.size();

    _wnames.clear();

    for (auto i : _hmap) {
      _wnames.push_back(i.first);
    }
    //_wnames.push_back("nominal");

  }

  int BootstrapTH1D::GetNbinsX()
  {
    return _nbins;
  }

  int BootstrapTH1D::GetNUniverses()
  {
    return _hmap.size();
  }

  size_t BootstrapTH1D::GetNWeights()
  {
    return _n_weights;
  }

  std::vector<std::string> BootstrapTH1D::GetUniverseNames()
  {
    return _wnames;
  }

  void BootstrapTH1D::ResetIterator()
  {
    _current_iterator = _hmap.begin();
  }

  bool BootstrapTH1D::NextUniverse(std::string & uni_name, TH1D & uni_histo) {

    if (_current_iterator == _hmap.end()) {
      std::cout << "NextUniverse false" << std::endl;
      return false;
    }

    if (_current_iterator->first == "nominal") {
      _current_iterator++;
    }

    uni_name = _current_iterator->first;
    uni_histo = _current_iterator->second;

    _current_iterator++;
    
    return true;
  } 

  std::map<std::string, std::vector<TH1D>> BootstrapTH1D::UnpackPMHisto()
  {

    std::map<std::string, std::vector<TH1D>> output_map;

    for (auto iter : _hmap) {
      if (iter.first == "nominal") continue;
      //std::cout << "iter.first = " << iter.first << std::endl;

      // Minus 1 sigma
      std::size_t pos = iter.first.find("_m1");
      if (pos != std::string::npos) {  
        std::string function_name = iter.first.substr (0, pos);

        //std::cout << "Minus 1, substrig is " << function_name << std::endl;

        std::vector<TH1D> vec;
        vec.resize(2);
        vec.at(0) = iter.second;

        output_map[function_name] = vec;
      }

      // Plus 1 sigma
      pos = iter.first.find("_p1");
      if (pos != std::string::npos) {  
        std::string function_name = iter.first.substr (0, pos);

        //std::cout << "Plus 1, substrig is " << function_name << std::endl;

        output_map[function_name].at(1) = iter.second;
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

    _hmap["nominal"].Fill(value, weight);

    for (size_t i = 0; i < _n_weights - 1; i++) {

     _hmap[_wnames.at(i)].Fill(value, weight * weights.at(i));

   }
    
  }

  TH1D BootstrapTH1D::GetNominal()
  {
    return _hmap["nominal"];
  }

  void BootstrapTH1D::GetUniverseHisto(std::string uni_name, TH1D & histo)
  {
    auto iter = _hmap.find(uni_name);
    if (iter == _hmap.end()) {
      std::cout << __PRETTY_FUNCTION__ << " :: Histomgram for universe " << uni_name << " not found!" << std::endl;
      throw std::exception();
    }

    histo = iter->second;

    return;
  }

  void BootstrapTH1D::GetUniverseHistoFast(std::string uni_name, TH1D & histo)
  {

    histo = _hmap[uni_name];

    return;
  }




  


}

#endif

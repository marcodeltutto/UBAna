#ifndef __BASE_BOOTSTRAPTH2D_CXX__
#define __BASE_BOOTSTRAPTH2D_CXX__

#include "BootstrapTH2D.h"

namespace Base {

 

  BootstrapTH2D::BootstrapTH2D(std::string name, std::string title, int nbinsX, double *binsX, int nbinsY, double *binsY) 
  {
  	TH2D temp((name+"nominal").c_str(), title.c_str(), nbinsX, binsX, nbinsY, binsY);
    _hmap["nominal"] = temp;
    _hname = name;
    _title = title;

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



  void BootstrapTH2D::SetWeightNames(std::vector<std::string> names)
  {

    _n_weights = names.size();
    //std::cout << "Bootstrap set up with " << _n_weights << " weights." << std::endl;
    _wnames = names;
    double* bins_x = &_bins_x[0];
    double* bins_y = &_bins_y[0];
    for (size_t i = 0; i < _n_weights; i++) {
    	TH2D temp((_hname+names.at(i)).c_str(), _title.c_str(), _nbins_x, bins_x, _nbins_y, bins_y);
      _hmap[names.at(i)] = temp;
    }
    
  }

  void BootstrapTH2D::SetAllHistograms(std::map<std::string,TH2D*> input_map) 
  {


  	for (auto it : input_map) {
  		_hmap[it.first] = *it.second;
  	}

    _nbins_x = _hmap["nominal"].GetNbinsX();
    _nbins_y = _hmap["nominal"].GetNbinsY();

  }

  int BootstrapTH2D::GetNbinsX()
  {
    return _nbins_x;
  }

  int BootstrapTH2D::GetNbinsY()
  {
    return _nbins_y;
  }

  int BootstrapTH2D::GetNUniverses()
  {
    return _hmap.size() - 1;
  }

  size_t BootstrapTH2D::GetNWeights()
  {
    return _n_weights;
  }

  std::vector<std::string> BootstrapTH2D::GetUniverseNames()
  {
    return _wnames;
  }

  void BootstrapTH2D::ResetIterator()
  {
    _current_iterator = _hmap.begin();
  }

  bool BootstrapTH2D::NextUniverse(std::string & uni_name, TH2D & uni_histo) {

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

  std::map<std::string, std::vector<TH2D>> BootstrapTH2D::UnpackPMHisto()
  {

    std::map<std::string, std::vector<TH2D>> output_map;

    for (auto iter : _hmap) {
      if (iter.first == "nominal") continue;
      //std::cout << "iter.first = " << iter.first << std::endl;

      // Minus 1 sigma
      std::size_t pos = iter.first.find("_m1");
      if (pos != std::string::npos) {  
        std::string function_name = iter.first.substr (0, pos);

        //std::cout << "Minus 1, substrig is " << function_name << std::endl;

        std::vector<TH2D> vec;
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

  void BootstrapTH2D::Fill(double value1, double value2, double weight, std::vector<double> weights)
  {

    if (weights.size() != _n_weights) {
      std::cout << __PRETTY_FUNCTION__ << " Size mismatch, this weight vector has size " << weights.size() 
                << ", but " << _n_weights << " is expected. This is Bootstrap " << _hname << "::" << _title << std::endl;
      throw std::exception();
    }

    _hmap["nominal"].Fill(value1, value2, weight);

    for (size_t i = 0; i < _n_weights; i++) {

     _hmap[_wnames.at(i)].Fill(value1, value2, weight * weights.at(i));

   }
    
  }

  TH2D BootstrapTH2D::GetNominal()
  {
    return _hmap["nominal"];
  }

  void BootstrapTH2D::GetUniverseHisto(std::string uni_name, TH2D & histo)
  {
    auto iter = _hmap.find(uni_name);
    if (iter == _hmap.end()) {
      std::cout << __PRETTY_FUNCTION__ << " :: Histomgram for universe " << uni_name << " not found!" << std::endl;
      throw std::exception();
    }

    histo = iter->second;

    return;
  }

  void BootstrapTH2D::GetUniverseHistoFast(std::string uni_name, TH2D & histo)
  {

    histo = _hmap[uni_name];

    return;
  }




  


}

#endif

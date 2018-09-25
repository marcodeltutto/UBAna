#ifndef __BASE_BOOTSTRAPTH2DPOLY_CXX__
#define __BASE_BOOTSTRAPTH2DPOLY_CXX__

#include "BootstrapTH2DPoly.h"

namespace DataTypes {

 

  BootstrapTH2DPoly::BootstrapTH2DPoly(std::string name,std::string title, Double_t xlow, Double_t xup, Double_t ylow, Double_t yup, Int_t n_bins_x) /*: TObject()*/
  {

    _h_v.clear();
    _name_v.clear();

    UBTH2Poly *temp = new UBTH2Poly((name+"nominal").c_str(), title.c_str(), xlow, xup, ylow, yup);
    // _hmap["nominal"] = temp;
    _hname = name;
    _title = title;

    _h_v.emplace_back(temp);
    _name_v.push_back("nominal");

    _nbins_x = n_bins_x;
    _xlow = xlow;
    _xup = xup;
    _ylow = ylow;
    _yup = yup;

  }


  void BootstrapTH2DPoly::SetWeightNames(std::vector<std::string> names)
  {

    _n_weights = names.size() + 1;
    std::cout << "Bootstrap " << _hname << " set up with " << _n_weights << " weights." << std::endl;
    _wnames = names;
    _wnames.push_back("nominal");

    for (size_t i = 0; i < _n_weights - 1; i++) {
    	UBTH2Poly *temp = new UBTH2Poly((_hname+names.at(i)).c_str(), _title.c_str(), _xlow, _xup, _ylow, _yup);
      // _hmap[names.at(i)] = temp;
      _h_v.emplace_back(temp);
      _name_v.push_back(names.at(i));
    }
    
  }


  void BootstrapTH2DPoly::AddBin(Double_t x1, Double_t y1, Double_t x2, Double_t y2)
  {

    for (size_t i = 0; i < _h_v.size(); i++) {
      _h_v.at(i)->AddBin(x1, y1, x2, y2);
    }

  }


  void BootstrapTH2DPoly::SetAllHistograms(std::map<std::string,UBTH2Poly*> input_map) 
  {

    for (auto it : input_map) {
      _h_v.push_back(it.second);
      _name_v.push_back(it.first);
    }

    _nbins_x = _h_v.at(0)->GetNBinsX();

    _n_weights = _h_v.size();

    _wnames.clear();

    for (auto n : _name_v) {
      _wnames.push_back(n);
    }

    _hname = _h_v.at(0)->GetTitle();
    _title = _h_v.at(0)->GetTitle();

  }

  int BootstrapTH2DPoly::GetNbinsX()
  {
    return _nbins_x;
  }

  int BootstrapTH2DPoly::GetNumberOfBins()
  {
    if (_h_v.at(0)) {
      return _h_v.at(0)->GetNumberOfBins();
    }
    else {
      return -1;
    }
  }

  

  int BootstrapTH2DPoly::GetNUniverses()
  {

    if (_h_v.size() != _name_v.size()) {
      std::cout << _name << "Histo vector and name vector do not have the same number of entries" << std::endl;
      throw std::exception();
    }

    return _h_v.size();
  }

  size_t BootstrapTH2DPoly::GetNWeights()
  {
    std::cout << "This is Bootstrap " << _hname << "::" << _title << std::endl;
    return _n_weights;
  }

  std::vector<std::string> BootstrapTH2DPoly::GetUniverseNames()
  {
    std::cout << "This is Bootstrap " << _hname << "::" << _title << std::endl;
    return _name_v;
  }

  void BootstrapTH2DPoly::ResetIterator()
  {
    // _current_iterator = _hmap.begin();
    _current_vector_index = -1;
  }

  const UBTH2Poly & BootstrapTH2DPoly::NextUniverse() {

    _current_vector_index++;

    if (_current_vector_index >= (int)_h_v.size()) {
      std::cout << "BootstrapTH2DPoly::NextUniverse() error index from " << _name << std::endl;
      throw std::exception();
    }

    if (_name_v.at(_current_vector_index) == "nominal") {
      _current_vector_index++;

      if (_current_vector_index >= (int)_h_v.size()) {
        std::cout << "BootstrapTH2DPoly::NextUniverse() error index from " << _name << std::endl;
        throw std::exception();
      }
    }
    
    return *_h_v.at(_current_vector_index);
  } 


  const UBTH2Poly & BootstrapTH2DPoly::SameUniverse() {

    if (_current_vector_index < 0 || _current_vector_index > (int)_h_v.size()) {
      std::cout << "BootstrapTH2DPoly::SameUniverse() error index from " << _name << std::endl;
      throw std::exception();
    }
    
    return *_h_v.at(_current_vector_index);
  }


  // std::map<std::string, std::vector<UBTH2Poly>> BootstrapTH2DPoly::UnpackPMHisto()
  // {

  //   std::map<std::string, std::vector<UBTH2Poly>> output_map;

  //   for (size_t i = 0; i < _name_v.size(); i++) {

  //     if (_name_v.at(i) == "nominal") continue;

  //     // Minus 1 sigma
  //     std::size_t pos = _name_v.at(i).find("_m1");
  //     if (pos != std::string::npos) {  
  //       std::string function_name = _name_v.at(i).substr (0, pos);

  //       //std::cout << "Minus 1, substrig is " << function_name << std::endl;

  //       std::vector<UBTH2Poly> vec;
  //       vec.resize(2);
  //       vec.at(0) = *_h_v.at(i);

  //       output_map[function_name] = vec;

  //     }

  //     // Plus 1 sigma
  //     pos = _name_v.at(i).find("_p1");
  //     if (pos != std::string::npos) {  
  //       std::string function_name = _name_v.at(i).substr (0, pos);

  //       //std::cout << "Plus 1, substrig is " << function_name << std::endl;

  //       output_map[function_name].at(1) =  *_h_v.at(i);
  //     }
  //   }

  //   return output_map;
  // }

  void BootstrapTH2DPoly::Fill(double value1, double value2, double weight, std::vector<double> weights)
  {

    if (weights.size() != _n_weights-1) {
      std::cout << __PRETTY_FUNCTION__ << " Size mismatch, this weight vector has size " << weights.size() 
                << ", but " << _n_weights-1 << " is expected. This is Bootstrap " << _hname << "::" << _title << std::endl;
      throw std::exception();
    }

    // _hmap["nominal"].Fill(value1, value2, weight);
    _h_v.at(0)->Fill(value1, value2, weight); // The nominal histogram


    for (size_t i = 1; i < _n_weights; i++) {

     _h_v.at(i)->Fill(value1, value2, weight * weights.at(i-1));

   }

  }

  UBTH2Poly * BootstrapTH2DPoly::GetNominal()
  {
    return _h_v.at(0);
  }

  UBTH2Poly * BootstrapTH2DPoly::GetUniverseHisto(std::string uni_name)
  {

    auto iter = std::find(_name_v.begin(), _name_v.end(), uni_name);
    if (iter == _name_v.end()) {
      std::cout << __PRETTY_FUNCTION__ << " :: Histomgram for universe " << uni_name << " not found! This is Bootstrap " << _hname << "::" << _title << std::endl;
      throw std::exception();
    }

    int position = iter - _name_v.begin();

    return _h_v.at(position);

  }

  // void BootstrapTH2DPoly::GetUniverseHistoFast(std::string uni_name, UBTH2Poly & histo)
  // {

  //   histo = _hmap[uni_name];

  //   return;
  // }




  


}

#endif

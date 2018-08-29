#ifndef __BASE_BOOTSTRAPTH2D_CXX__
#define __BASE_BOOTSTRAPTH2D_CXX__

#include "BootstrapTH2D.h"

namespace Base {

 

  BootstrapTH2D::BootstrapTH2D(std::string name, std::string title, int nbinsX, double *binsX, int nbinsY, double *binsY) /*: TObject()*/
  {

    _h_v.clear();
    _name_v.clear();

    TH2D temp((name+"nominal").c_str(), title.c_str(), nbinsX, binsX, nbinsY, binsY);
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

  // BootstrapTH2D::BootstrapTH2D(std::string name, std::string title, int nbins, double bin_start, double bin_end) 
  // {
  //   _h_v.clear();
  //   _name_v.clear();

  //   TH1D temp((name+"nominal").c_str(), title.c_str(), nbins, bin_start, bin_end);
  //   _hmap["nominal"] = temp;
  //   _h_v.emplace_back(temp);
  //   _name_v.push_back("nominal");
  //   _hname = name;
  //   _title = title;
  //   _nbins = nbins;
  //   _bins.resize(nbins+1);
  //   double bin_size = (bin_end - bin_start) / (double) nbins;

  //   for (double i = bin_start; i < bin_end; i++) {
  //     _bins.at(i) = i;
  //     i+= bin_size;
  //   }

  //   _bins.at(nbins) = bin_end;

  // }



  void BootstrapTH2D::SetWeightNames(std::vector<std::string> names)
  {

    _n_weights = names.size() + 1;
    std::cout << "Bootstrap " << _hname << " set up with " << _n_weights << " weights." << std::endl;
    _wnames = names;
    _wnames.push_back("nominal");
    double* bins_x = &_bins_x[0];
    double* bins_y = &_bins_y[0];
    for (size_t i = 0; i < _n_weights - 1; i++) {
    	TH2D temp((_hname+names.at(i)).c_str(), _title.c_str(), _nbins_x, bins_x, _nbins_y, bins_y);
      _hmap[names.at(i)] = temp;
      _h_v.emplace_back(temp);
      _name_v.push_back(names.at(i));
    }
    
  }

  void BootstrapTH2D::SetAllHistograms(std::map<std::string,TH2D*> input_map) 
  {


  	// for (auto it : input_map) {
  	// 	_hmap[it.first] = *it.second;
   //    //std::cout << "[BootstrapTH2D] Setting up histogram " << it.first << std::endl;
  	// }

    for (auto it : input_map) {
      _h_v.push_back(*it.second);
      _name_v.push_back(it.first);
      //std::cout << "[BootstrapTH2D] Setting up histogram " << it.first << std::endl;
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
    //_wnames.push_back("nominal");

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
    // return _hmap.size(); // To be removed

    if (_h_v.size() != _name_v.size()) {
      std::cout << _name << "Histo vector and name vector do not have the same number of entries" << std::endl;
      throw std::exception();
    }

    return _h_v.size();
  }

  size_t BootstrapTH2D::GetNWeights()
  {
    std::cout << "This is Bootstrap " << _hname << "::" << _title << std::endl;
    return _n_weights;
  }

  std::vector<std::string> BootstrapTH2D::GetUniverseNames()
  {
    // return _wnames; // To be removed
    std::cout << "This is Bootstrap " << _hname << "::" << _title << std::endl;
    return _name_v;
  }

  void BootstrapTH2D::ResetIterator()
  {
    _current_iterator = _hmap.begin();
    _current_vector_index = -1;
  }

  const TH2D & BootstrapTH2D::NextUniverse() {

    // if (_current_iterator->first == "nominal") {
    //   _current_iterator++;
    // }

    _current_vector_index++;

    if (_current_vector_index >= _h_v.size()) {
      std::cout << "BootstrapTH2D::NextUniverse() error index from " << _name << std::endl;
      throw std::exception();
    }

    if (_name_v.at(_current_vector_index) == "nominal") {
      _current_vector_index++;

      if (_current_vector_index >= _h_v.size()) {
        std::cout << "BootstrapTH2D::NextUniverse() error index from " << _name << std::endl;
        throw std::exception();
      }
    }


    // uni_name = _name_v.at(_current_vector_index);
    // uni_histo = _h_v.at(_current_vector_index);

    // _current_iterator++;
    // _current_vector_index++;

    // std::cout << "next _current_vector_index " << _current_vector_index << std::endl;
    
    return _h_v.at(_current_vector_index);
  } 


  const TH2D & BootstrapTH2D::SameUniverse() {

    // std::cout << "same _current_vector_index " << _current_vector_index << std::endl;


    if (_current_vector_index < 0 || _current_vector_index > _h_v.size()) {
      std::cout << "BootstrapTH2D::SameUniverse() error index from " << _name << std::endl;
      throw std::exception();
    }
    
    return _h_v.at(_current_vector_index);
  }


  std::map<std::string, std::vector<TH2D>> BootstrapTH2D::UnpackPMHisto()
  {

    std::map<std::string, std::vector<TH2D>> output_map;

    for (size_t i = 0; i < _name_v.size(); i++) {

      if (_name_v.at(i) == "nominal") continue;

      // Minus 1 sigma
      std::size_t pos = _name_v.at(i).find("_m1");
      if (pos != std::string::npos) {  
        std::string function_name = _name_v.at(i).substr (0, pos);

        //std::cout << "Minus 1, substrig is " << function_name << std::endl;

        std::vector<TH2D> vec;
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



    // for (auto iter : _hmap) {
    //   if (iter.first == "nominal") continue;
    //   //std::cout << "iter.first = " << iter.first << std::endl;

    //   // Minus 1 sigma
    //   std::size_t pos = iter.first.find("_m1");
    //   if (pos != std::string::npos) {  
    //     std::string function_name = iter.first.substr (0, pos);

    //     //std::cout << "Minus 1, substrig is " << function_name << std::endl;

    //     std::vector<TH1D> vec;
    //     vec.resize(2);
    //     vec.at(0) = iter.second;

    //     output_map[function_name] = vec;
    //   }

    //   // Plus 1 sigma
    //   pos = iter.first.find("_p1");
    //   if (pos != std::string::npos) {  
    //     std::string function_name = iter.first.substr (0, pos);

    //     //std::cout << "Plus 1, substrig is " << function_name << std::endl;

    //     output_map[function_name].at(1) = iter.second;
    //   }
    // }

    return output_map;
  }

  void BootstrapTH2D::Fill(double value1, double value2, double weight, std::vector<double> weights)
  {

    if (weights.size() != _n_weights-1) {
      std::cout << __PRETTY_FUNCTION__ << " Size mismatch, this weight vector has size " << weights.size() 
                << ", but " << _n_weights-1 << " is expected. This is Bootstrap " << _hname << "::" << _title << std::endl;
      throw std::exception();
    }

    _hmap["nominal"].Fill(value1, value2, weight);
    _h_v.at(0).Fill(value1, value2, weight); // The nominal histogram

   //  for (size_t i = 0; i < _n_weights - 1; i++) {

   //   _hmap[_wnames.at(i)].Fill(value, weight * weights.at(i));

   // }


    for (size_t i = 1; i < _n_weights; i++) {

     _h_v.at(i).Fill(value1, value2, weight * weights.at(i-1));

   }

  }

  const TH2D& BootstrapTH2D::GetNominal()
  {
    // return _hmap["nominal"];
    return _h_v.at(0);
  }

  void BootstrapTH2D::GetUniverseHisto(std::string uni_name, TH2D & histo)
  {
    // auto iter = _hmap.find(uni_name);
    // if (iter == _hmap.end()) {
    //   std::cout << __PRETTY_FUNCTION__ << " :: Histomgram for universe " << uni_name << " not found! This is Bootstrap " << _hname << "::" << _title << std::endl;
    //   throw std::exception();
    // }

    auto iter = std::find(_name_v.begin(), _name_v.end(), uni_name);
    if (iter == _name_v.end()) {
      std::cout << __PRETTY_FUNCTION__ << " :: Histomgram for universe " << uni_name << " not found! This is Bootstrap " << _hname << "::" << _title << std::endl;
      throw std::exception();
    }

    int position = iter - _name_v.begin();

    histo = _h_v.at(position);

    return;
  }

  void BootstrapTH2D::GetUniverseHistoFast(std::string uni_name, TH2D & histo)
  {

    histo = _hmap[uni_name];

    return;
  }




  


}

#endif

#ifndef __BASE_BOOTSTRAPTH1D_CXX__
#define __BASE_BOOTSTRAPTH1D_CXX__

#include "BootstrapTH1D.h"

namespace Base {

 

  BootstrapTH1D::BootstrapTH1D(std::string name, std::string title, int nbins, double *bins) /*: TObject()*/
  {

    _h_v.clear();
    _name_v.clear();

  	TH1D temp((name+"nominal").c_str(), title.c_str(), nbins, bins);
    _hmap["nominal"] = temp;
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
    _hmap["nominal"] = temp;
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
      _hmap[names.at(i)] = temp;
      _h_v.emplace_back(temp);
      _name_v.push_back(names.at(i));
    }
    
  }

  void BootstrapTH1D::SetAllHistograms(std::map<std::string,TH1D*> input_map) 
  {


  	// for (auto it : input_map) {
  	// 	_hmap[it.first] = *it.second;
   //    //std::cout << "[BootstrapTH1D] Setting up histogram " << it.first << std::endl;
  	// }

    for (auto it : input_map) {
      _h_v.push_back(*it.second);
      _name_v.push_back(it.first);
      //std::cout << "[BootstrapTH1D] Setting up histogram " << it.first << std::endl;
    }



    _nbins = _h_v.at(0).GetNbinsX();

    _n_weights = _h_v.size();

    _wnames.clear();

    for (auto n : _name_v) {
      _wnames.push_back(n);
    }

    _hname = _h_v.at(0).GetTitle();
    _title = _h_v.at(0).GetTitle();
    //_wnames.push_back("nominal");

  }

  int BootstrapTH1D::GetNbinsX()
  {
    return _nbins;
  }

  int BootstrapTH1D::GetNUniverses()
  {
    // return _hmap.size(); // To be removed

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
    // return _wnames; // To be removed
    std::cout << "This is Bootstrap " << _hname << "::" << _title << std::endl;
    return _name_v;
  }

  void BootstrapTH1D::ResetIterator()
  {
    _current_iterator = _hmap.begin();
    _current_vector_index = 0;
  }

  bool BootstrapTH1D::NextUniverse(std::string & uni_name, TH1D & uni_histo) {

    // if (_current_iterator->first == "nominal") {
    //   _current_iterator++;
    // }

    if (_name_v.at(_current_vector_index) == "nominal") {
      _current_vector_index++;
    }

    // if (_current_iterator == _hmap.end()) {
    //   std::cout << "NextUniverse false" << std::endl;
    //   return false;
    // }

    if ((size_t)_current_vector_index >= _h_v.size()) {
      std::cout << "NextUniverse false" << std::endl;
      return false;
    }

    // uni_name = _current_iterator->first;
    // uni_histo = _current_iterator->second;

    uni_name = _name_v.at(_current_vector_index);
    uni_histo = _h_v.at(_current_vector_index);

    // _current_iterator++;
    _current_vector_index++;
    
    return true;
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

        //std::cout << "Minus 1, substrig is " << function_name << std::endl;

        std::vector<TH1D> vec;
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

  void BootstrapTH1D::Fill(double value, double weight, std::vector<double> weights)
  {

    if (weights.size() != _n_weights-1) {
      std::cout << __PRETTY_FUNCTION__ << " Size mismatch, this weight vector has size " << weights.size() 
                << ", but " << _n_weights-1 << " is expected. This is Bootstrap " << _hname << "::" << _title << std::endl;
      throw std::exception();
    }

    _hmap["nominal"].Fill(value, weight);
    _h_v.at(0).Fill(value, weight); // The nominal histogram

   //  for (size_t i = 0; i < _n_weights - 1; i++) {

   //   _hmap[_wnames.at(i)].Fill(value, weight * weights.at(i));

   // }


    for (size_t i = 1; i < _n_weights; i++) {

     _h_v.at(i).Fill(value, weight * weights.at(i-1));

   }

  }

  TH1D BootstrapTH1D::GetNominal()
  {
    // return _hmap["nominal"];
    return _h_v.at(0);
  }

  void BootstrapTH1D::GetUniverseHisto(std::string uni_name, TH1D & histo)
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

  void BootstrapTH1D::GetUniverseHistoFast(std::string uni_name, TH1D & histo)
  {

    histo = _hmap[uni_name];

    return;
  }




  


}

#endif

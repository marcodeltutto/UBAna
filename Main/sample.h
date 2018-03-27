/**
 * \file sample.h
 *
 * \ingroup Main
 * 
 * \brief Class def header for a class sample
 *
 * @author deltutto
 */

/** \addtogroup Main

    @{*/
#ifndef MAIN_SAMPLE_H
#define MAIN_SAMPLE_H

#include <iostream>
#include <TFile.h>
#include "ubana/Base/BootstrapTH1D.h"

namespace Main {

/**
   \class sample
   User defined class Main ... these comments are used to generate
   doxygen documentation!
*/
  class sample{

  public:

    /// Default constructor
    sample(){
      TFile * f_in = TFile::Open("mac/ubxsecana_output.root","READ");
      Base::BootstrapTH1D * mybs;
      f_in->GetObject("h_eff_mumom_num_bs", mybs);
      std::cout << "just before printing" << std::endl;
      mybs->PrintConfig();
    }

    /// Default destructor
    virtual ~sample(){};

  };
}
#endif
/** @} */ // end of doxygen group 


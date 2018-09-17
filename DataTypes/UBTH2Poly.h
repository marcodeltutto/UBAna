/**
 * \file UBTH2Poly.h
 *
 * \ingroup DataTypes
 * 
 * \brief Class def header for a class UBTH2Poly
 *
 * @author deltutto
 */

/** \addtogroup DataTypes

    @{*/
#ifndef __DATATYPES_UBTH2POLY_H__
#define __DATATYPES_UBTH2POLY_H__


#include <TSystem.h>
#include <TString.h>
#include <TROOT.h>


#include <TH2Poly.h>

#include <iostream>
#include <map>


namespace DataTypes {

  /**
     \class UBTH2Poly
     User defined class UBTH2Poly ... these comments are used to generate
     doxygen documentation!
  */
  class UBTH2Poly : public TH2Poly {
    
  public:
    
    /// Default constructor
    UBTH2Poly(){}

    /// Ctor
    UBTH2Poly(const char *name,const char *title, Double_t xlow, Double_t xup, Double_t ylow, Double_t yup) 
    : TH2Poly(name, title, xlow, xup, ylow, yup) {}

    /// Ctor
    UBTH2Poly(const char *name,const char *title, Int_t nX, Double_t xlow, Double_t xup,  Int_t nY, Double_t ylow, Double_t yup)
    : TH2Poly(name, title, nX, xlow, xup, nY, ylow, yup) {}
    
    /// Default destructor
    ~UBTH2Poly(){}

    /// Projects in Y slices
    TH1D* ProjectionY(const char *name, Int_t firstxbin/*, Int_t lastxbin, Option_t *option*/) const;

    /// Creates a UBTH2Poly with bin numbers in place of bin content
    UBTH2Poly* GetCopyWithBinNumbers(const char *name) const;


    ClassDef(DataTypes::UBTH2Poly, 1) // TH2 with polygonal bins (extended for MicroBooNE)
    
  };
}

#endif
/** @} */ // end of doxygen group 


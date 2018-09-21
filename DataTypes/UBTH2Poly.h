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
    : TH2Poly(name, title, xlow, xup, ylow, yup) {if (fgDefaultSumw2) Sumw2();}

    /// Ctor
    UBTH2Poly(const char *name,const char *title, Int_t nX, Double_t xlow, Double_t xup,  Int_t nY, Double_t ylow, Double_t yup)
    : TH2Poly(name, title, nX, xlow, xup, nY, ylow, yup) {if (fgDefaultSumw2) Sumw2();}
    
    /// Default destructor
    ~UBTH2Poly(){}

    /// Projects in Y slices
    TH1D* ProjectionY(const char *name, Int_t firstxbin/*, Int_t lastxbin, Option_t *option*/) const;

    /// Creates a UBTH2Poly with bin numbers in place of bin content
    UBTH2Poly* GetCopyWithBinNumbers(const char *name) const;

    /// Add another UBTH2Poly, multiplied by c1: this = this + c1 * h1
    Bool_t Add(const TH1 *h1, Double_t c1 = 1.0);

    /// Add another UBTH2Poly, multiplied by c1: this = this + c1 * h1
    Bool_t Divide(const TH1 *h1);// {fNcells++; Bool_t status = TH2Poly::Divide(h1); fNcells--; return status;}

    /// Multiply this histogram by a constant c1. Divides by bin width is "width" is specified in option
    void Scale (Double_t c1, Option_t* option);

    ///
    Int_t Fill(Double_t x, Double_t y, Double_t w) {if (!fSumw2.fN && w != 1.0 && !TestBit(TH1::kIsNotW)) Sumw2(); return TH2Poly::Fill(x, y, w);}

    /// Operator =
    UBTH2Poly & operator= (const UBTH2Poly &h1);


    ClassDef(DataTypes::UBTH2Poly, 1) // TH2 with polygonal bins (extended for MicroBooNE)
    
  };
}

#endif
/** @} */ // end of doxygen group 


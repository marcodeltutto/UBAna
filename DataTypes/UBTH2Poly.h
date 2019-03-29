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
#include <TMath.h>
#include <TGraph.h>



#include <TH2Poly.h>

#include <iostream>
#include <map>
#include <vector>

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
    : TH2Poly(name, title, xlow, xup, ylow, yup) {if (fgDefaultSumw2) Sumw2(); fNcells = kNOverflow; /*Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility*/}

    /// Ctor
    UBTH2Poly(const char *name,const char *title, Int_t nX, Double_t xlow, Double_t xup,  Int_t nY, Double_t ylow, Double_t yup)
    : TH2Poly(name, title, nX, xlow, xup, nY, ylow, yup) {if (fgDefaultSumw2) Sumw2(); fNcells = kNOverflow; /*Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility*/}
    
    /// Default destructor
    ~UBTH2Poly(){}

    /// Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility
    Int_t        AddBin(TObject *poly);

    /// Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility
    Int_t        AddBin(Double_t x1, Double_t y1, Double_t x2, Double_t  y2);

    /// Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility
    Int_t        Fill(Double_t x,Double_t y, Double_t w);

    /// Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility
    void         SetBinContent(Int_t bin, Double_t content);

    /// Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility
    void         SetBinError(Int_t bin, Double_t content);

    /// Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility
    Double_t     GetBinError(Int_t bin) const;

    /// Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility
    Double_t     GetBinContent(Int_t bin) const;

    /// Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility
    Int_t GetNumberOfBins() const{return fNcells-kNOverflow;}

    /// Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility
    virtual Double_t RetrieveBinContent(Int_t bin) const {
        return (bin>=kNOverflow) ? GetBinContent(bin-kNOverflow+1) : GetBinContent(-kNOverflow+bin);
        std::cout << "-------->RetrieveBinContent called" << std::endl;
    }

    /// Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility
    virtual void UpdateBinContent(Int_t bin, Double_t content) {
       return (bin>=kNOverflow) ? SetBinContent(bin-kNOverflow+1,content) : SetBinContent(-bin-1,content);
    }

    /// Returns the bin width (area) for bin
    Double_t GetBinWidth(Int_t bin) const;

    /// Projects in Y slices, firstxbin is the X bin you want to select, bin_numbersis a returned vectors with the corresponding bin numbers
    TH1D* ProjectionY(const char *name, Int_t firstxbin, std::vector<int> & bin_numbers) const;

    /// Creates a UBTH2Poly with bin numbers in place of bin content
    UBTH2Poly* GetCopyWithBinNumbers(const char *name) const;

    /// Add another UBTH2Poly, multiplied by c1: this = this + c1 * h1
    Bool_t Add(const TH1 *h1, Double_t c1 = 1.0);

    /// Add another UBTH2Poly, multiplied by c1: this = this + c1 * h1
    Bool_t Divide(const TH1 *h1);

    /// Multiply this histogram by a constant c1. Divides by bin width if "width" is specified in option
    void Scale (Double_t c1, Option_t* option = "");

    // ///
    // Int_t Fill(Double_t x, Double_t y, Double_t w) {if (!fSumw2.fN && w != 1.0 && !TestBit(TH1::kIsNotW)) Sumw2(); std::cout << "y = " << y << " (min = " << fYaxis.GetXmin() << "max = " << fYaxis.GetXmax() << ")" << "     x = " << x << " (min = " << fXaxis.GetXmin() << "max = " << fXaxis.GetXmax() << ")"<< std::endl; return TH2Poly::Fill(x, y, w);}

    /// Calculates sum of bin content (multiplied by bin width is "width" or "area" is passed as option)
    Double_t Integral(Option_t* option = "") const;

    /// Operator =
    UBTH2Poly & operator= (const UBTH2Poly &h1);

    /// Reset this histogram: contents, errors, etc.
    void Reset(Option_t *opt = "") {for (int i=0; i<kNOverflow; i++) fOverflow[i] = 0.; TH2Poly::Reset(opt);}

    /// Sets the number of bins along x
    void SetNBinsX(Int_t n);

    /// Returns the number of bins along x
    Int_t GetNBinsX();

    ///
    void GetStats(Double_t *stats) const;

    ///
    void PutStats(Double_t *stats);

    /// Sets a vector containing the boundaris for Y variable
    void SetSeparators(std::vector<int> v) {_separator_length = 0; for (size_t i = 0; i < v.size(); i++) {_separators_v[i] = v.at(i); _separator_length++;}; } 

    /// Gets a vector containing the boundaris for Y variable
    Int_t * GetSeparators() {return _separators_v;}

    /// Gets a vector containing the boundaris for Y variable
    Int_t GetSeparatorsLength() {return _separator_length;}


    ClassDef(DataTypes::UBTH2Poly, 1) // TH2 with polygonal bins (extended for MicroBooNE)

  protected:

    enum {
       kNOverflow       = 9  //  number of overflows bins
    };

    Double_t fOverflow[kNOverflow] = {0}; 

    Int_t _n_bins_x = 100;

    Int_t _separators_v[50];
    Int_t _separator_length = 0;
    
  };
}

#endif
/** @} */ // end of doxygen group 


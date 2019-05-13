// @(#)root/hist:$Id$
// Author: Olivier Couet, Deniz Gunceler

/*************************************************************************
 * Copyright (C) 1995-2000, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_UBTH2Poly
#define ROOT_UBTH2Poly

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// UBTH2Poly                                                              //
//                                                                      //
// 2-Dim histogram with polygon bins                                    //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#ifndef ROOT_TH2
#include "TH2.h"
#endif

#include "TList.h"

#include <TH2Poly.h> // needed for TH2PolyBin

class TList;
class TGraph;
class TMultiGraph;
class TPad;

namespace DataTypes {


class UBTH2Poly : public TH2 {

public:
   UBTH2Poly();
   UBTH2Poly(const char *name,const char *title, Double_t xlow, Double_t xup, Double_t ylow, Double_t yup);
   UBTH2Poly(const char *name,const char *title, Int_t nX, Double_t xlow, Double_t xup,  Int_t nY, Double_t ylow, Double_t yup);
   virtual ~UBTH2Poly();
   // UBTH2Poly(const UBTH2Poly&); // new, copy constructor declaration

   Int_t        AddBin(TObject *poly);
   Int_t        AddBin(Int_t n, const Double_t *x, const Double_t *y);
   Int_t        AddBin(Double_t x1, Double_t y1, Double_t x2, Double_t  y2);
   virtual Bool_t Add(const TH1 *h1, Double_t c1=1.0); //new
   virtual Bool_t Add(const TH1 *h1, const TH1 *h2, Double_t c1=1, Double_t c2=1);
   virtual Bool_t Add(TF1 *h1, Double_t c1=1, Option_t *option="");
   void         ClearBinContents();                 // Clears the content of all bins
   TObject     *Clone(const char* newname = "") const;
   void         ChangePartition(Int_t n, Int_t m);  // Sets the number of partition cells to another value
   Int_t        Fill(Double_t x,Double_t y);
   Int_t        Fill(Double_t x,Double_t y, Double_t w);
   Int_t        Fill(const char* name, Double_t w);
   void         FillN(Int_t ntimes, const Double_t* x, const Double_t* y, const Double_t* w, Int_t stride = 1);
   Int_t        Fill(Double_t){return -1;}                              //MayNotUse
   Int_t        Fill(Double_t , const char *, Double_t){return -1;}     //MayNotUse
   Int_t        Fill(const char *, Double_t , Double_t ){return -1;}    //MayNotUse
   Int_t        Fill(const char *, const char *, Double_t ){return -1;} //MayNotUse
   void         FillN(Int_t, const Double_t*, const Double_t*, Int_t){return;}  //MayNotUse
   Int_t        FindBin(Double_t x, Double_t y, Double_t z = 0);
   TList       *GetBins(){return fBins;}                                // Returns the TList of all bins in the histogram
   Double_t     GetBinContent(Int_t bin) const;
   Double_t     GetBinContent(Int_t, Int_t) const {return 0;}           //MayNotUse
   Double_t     GetBinContent(Int_t, Int_t, Int_t) const {return 0;}    //MayNotUse
   Bool_t       GetBinContentChanged() const{return fBinContentChanged;}
   Double_t     GetBinError(Int_t bin) const;
   Double_t     GetBinError(Int_t , Int_t) const {return 0;}            //MayNotUse
   Double_t     GetBinError(Int_t , Int_t , Int_t) const {return 0;}    //MayNotUse
   const char  *GetBinName(Int_t bin) const;
   const char  *GetBinTitle(Int_t bin) const;
   Bool_t       GetFloat(){return fFloat;}
   Double_t     GetMaximum() const;
   Double_t     GetMaximum(Double_t maxval) const;
   Double_t     GetMinimum() const;
   Double_t     GetMinimum(Double_t minval) const;
   Bool_t       GetNewBinAdded() const{return fNewBinAdded;}
   Int_t        GetNumberOfBins() const{return fNcells;}
   void         Honeycomb(Double_t xstart, Double_t ystart, Double_t a, Int_t k, Int_t s);   // Bins the histogram using a honeycomb structure
   Double_t     Integral(Option_t* option = "") const;
   Double_t     Integral(Int_t, Int_t, const Option_t*) const{return 0;}                             //MayNotUse
   Double_t     Integral(Int_t, Int_t, Int_t, Int_t, const Option_t*) const{return 0;}               //MayNotUse
   Double_t     Integral(Int_t, Int_t, Int_t, Int_t, Int_t, Int_t, const Option_t*) const{return 0;} //MayNotUse
   Long64_t     Merge(TCollection *);
   void         Reset(Option_t *option= "");
   void         SavePrimitive(std::ostream& out, Option_t* option = "");
   virtual void Scale(Double_t c1 = 1, Option_t* option = "");
   void         SetBinContent(Int_t bin, Double_t content);
   void         SetBinContent(Int_t, Int_t, Double_t){return;}           //MayNotUse
   void         SetBinContent(Int_t, Int_t, Int_t, Double_t){return;}    //MayNotUse
   void         SetBinContentChanged(Bool_t flag){fBinContentChanged = flag;}
   void         SetFloat(Bool_t flag = true);
   void         SetNewBinAdded(Bool_t flag){fNewBinAdded = flag;}


   /// Sets the number of bins along x
    void SetNBinsX(Int_t n);

    /// Returns the number of bins along x
    Int_t GetNBinsX();

    /// Add another UBTH2Poly, multiplied by c1: this = this + c1 * h1
    Bool_t Divide(const TH1 *h1);

    /// Creates a UBTH2Poly with bin numbers in place of bin content
    UBTH2Poly* GetCopyWithBinNumbers(const char *name) const;

   /// Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility
   void         SetBinError(Int_t bin, Double_t content);

   /// Returns the bin width (area) for bin
   Double_t GetBinWidth(Int_t bin) const;

   /// Sets a vector containing the boundaris for Y variable NEW
   void SetSeparators(std::vector<int> v) {_separator_length = 0; for (size_t i = 0; i < v.size(); i++) {_separators_v[i] = v.at(i); _separator_length++;}; } 

   /// Gets a vector containing the boundaris for Y variable NEW
   Int_t * GetSeparators() {return _separators_v;}

   /// Gets a vector containing the boundaris for Y variable NEW
   Int_t GetSeparatorsLength() {return _separator_length;}

   /// Projects in Y slices, firstxbin is the X bin you want to select, bin_numbersis a returned vectors with the corresponding bin numbers
    TH1D* ProjectionY(const char *name, Int_t firstxbin, std::vector<int> & bin_numbers) const;


protected:

   enum {
       kNOverflow       = 9  //  number of overflows bins // new
    };

   TList   *fBins;              //List of bins. The list owns the contained objects
   Double_t fOverflow[kNOverflow];       //Overflow bins // new
   Int_t    fCellX;             //Number of partition cells in the x-direction of the histogram
   Int_t    fCellY;             //Number of partition cells in the y-direction of the histogram
   Int_t    fNCells;            //Number of partition cells: fCellX*fCellY
   TList   *fCells;             //[fNCells] The array of TLists that store the bins that intersect with each cell. List do not own the contained objects
   Double_t fStepX, fStepY;     //Dimensions of a partition cell
   Bool_t  *fIsEmpty;           //[fNCells] The array that returns true if the cell at the given coordinate is empty
   Bool_t  *fCompletelyInside;  //[fNCells] The array that returns true if the cell at the given coordinate is completely inside a bin
   Bool_t   fFloat;             //When set to kTRUE, allows the histogram to expand if a bin outside the limits is added.
   Bool_t   fNewBinAdded;       //!For the 3D Painter
   Bool_t   fBinContentChanged; //!For the 3D Painter

   Int_t _n_bins_x = 100; // new

    Int_t _separators_v[50]; // new
    Int_t _separator_length = 0; // new

   void   AddBinToPartition(TH2PolyBin *bin);  // Adds the input bin into the partition matrix
   void   Initialize(Double_t xlow, Double_t xup, Double_t ylow, Double_t yup, Int_t n, Int_t m);
   Bool_t IsIntersecting(TH2PolyBin *bin, Double_t xclipl, Double_t xclipr, Double_t yclipb, Double_t yclipt);
   Bool_t IsIntersectingPolygon(Int_t bn, Double_t *x, Double_t *y, Double_t xclipl, Double_t xclipr, Double_t yclipb, Double_t yclipt);  
   // needed by TH1 - no need to have a separate implementation
   virtual Double_t RetrieveBinContent(Int_t bin) const { return (bin>=kNOverflow) ? GetBinContent(bin-kNOverflow+1) : GetBinContent(-kNOverflow+bin); } // new
   virtual void     UpdateBinContent(Int_t bin, Double_t content) { return (bin>=kNOverflow) ? SetBinContent(bin-kNOverflow+1,content) : SetBinContent(-bin-1,content); } // new

   ClassDef(DataTypes::UBTH2Poly,1)  //2-Dim histogram with polygon bins
};
}

#endif

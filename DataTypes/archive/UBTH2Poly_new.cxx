// @(#)root/hist:$Id$
// UBTH2Poly v2.1
// Author: Olivier Couet, Deniz Gunceler

/*************************************************************************
 * Copyright (C) 1995-2000, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#include "TROOT.h"
#include "TClass.h"
#include "UBTH2Poly.h"
#include "TCutG.h"
#include "TList.h"
#include "TMath.h"
#include "TMultiGraph.h"
#include "TGraph.h"
#include "TStyle.h"
#include "TCanvas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Riostream.h"

ClassImp(DataTypes::UBTH2Poly)

namespace DataTypes {
/** \class UBTH2Poly
    \ingroup Hist
2D Histogram with Polygonal Bins

## Overview
`UBTH2Poly` is a 2D Histogram class (TH2) allowing to define polygonal
bins of arbitrary shape.

Each bin in the `UBTH2Poly` histogram is a `TH2PolyBin` object.
`TH2PolyBin` is a very simple class containing the vertices (stored
as `TGraph`s or `TMultiGraph`s ) and contents of the polygonal
bin as well as several related functions.

Essentially, a `UBTH2Poly` is a TList of `TH2PolyBin` objects
with methods to manipulate them.

Bins are defined using one of the `AddBin()` methods. The bin definition
should be done before filling.

The histogram can be filled with `Fill(Double_t x, Double_t y, Double_t w)
`. `w` is the weight.
If no weight is specified, it is assumed to be 1.

Not all histogram's area need to be binned. Filling an area without bins,
will falls into the overflows. Adding a bin is not retroactive; it doesn't
affect previous fillings. A `Fill()` call, that
was previously ignored due to the lack of a bin at the specified location, is
not reconsidered when that location is binned later.

If there are two overlapping bins, the first one in the list will be incremented
by `Fill()`.

The histogram may automatically extends its limits if a bin outside the
histogram limits is added. This is done when the default constructor (with no
arguments) is used. It generates a histogram with no limits along the X and Y
axis. Adding bins to it will extend it up to a proper size.

`UBTH2Poly` implements a partitioning algorithm to speed up bins' filling.
The partitioning algorithm divides the histogram into regions called cells.
The bins that each cell intersects are recorded in an array of `TList`s.
When a coordinate in the histogram is to be filled; the method (quickly) finds
which cell the coordinate belongs.  It then only loops over the bins
intersecting that cell to find the bin the input coordinate corresponds to.
The partitioning of the histogram is updated continuously as each bin is added.
The default number of cells on each axis is 25. This number could be set to
another value in the constructor or adjusted later by calling the
`ChangePartition(Int_t, Int_t)` method. The partitioning algorithm is
considerably faster than the brute force algorithm (i.e. checking if each bin
contains the input coordinates), especially if the histogram is to be filled
many times.

The following very simple macro shows how to build and fill a `UBTH2Poly`:
~~~ {.cpp]
{
    UBTH2Poly *h2p = new UBTH2Poly();

    Double_t x1[] = {0, 5, 6};
    Double_t y1[] = {0, 0, 5};
    Double_t x2[] = {0, -1, -1, 0};
    Double_t y2[] = {0, 0, -1, 3};
    Double_t x3[] = {4, 3, 0, 1, 2.4};
    Double_t y3[] = {4, 3.7, 1, 3.7, 2.5};

    h2p->AddBin(3, x1, y1);
    h2p->AddBin(4, x2, y2);
    h2p->AddBin(5, x3, y3);

    h2p->Fill(0.1, 0.01, 3);
    h2p->Fill(-0.5, -0.5, 7);
    h2p->Fill(-0.7, -0.5, 1);
    h2p->Fill(1, 3, 1.5);
}
~~~

More examples can bin found in `$ROOTSYS/tutorials/hist/th2poly*.C`

## Partitioning Algorithm
The partitioning algorithm forms an essential part of the `UBTH2Poly`
class. It is implemented to speed up the filling of bins.

With the brute force approach, the filling is done in the following way:  An
iterator loops over all bins in the `UBTH2Poly` and invokes the
method `IsInside()` for each of them.
This method checks if the input location is in that bin. If the filling
coordinate is inside, the bin is filled. Looping over all the bin is
very slow.

The alternative is to divide the histogram into virtual rectangular regions
called "cells". Each cell stores the pointers of the bins intersecting it.
When a coordinate is to be filled, the method finds which cell the coordinate
falls into. Since the cells are rectangular, this can be done very quickly.
It then only loops over the bins associated with that cell.

The addition of bins to the appropriate cells is done when the bin is added
to the histogram. To do this, `AddBin()` calls the
`AddBinToPartition()` method.
This method adds the input bin to the partitioning matrix.

The number of partition cells per axis can be specified in the constructor.
If it is not specified, the default value of 25 along each axis will be
assigned. This value was chosen because it is small enough to avoid slowing
down AddBin(), while being large enough to enhance Fill() by a considerable
amount. Regardless of how it is initialized at construction time, it can be
changed later with the `ChangePartition()` method.
`ChangePartition()` deletes the
old partition matrix and generates a new one with the specified number of cells
on each axis.

The optimum number of partition cells per axis changes with the number of
times `Fill()` will be called.  Although partitioning greatly speeds up
filling, it also adds a constant time delay into the code. When `Fill()`
is to be called many times, it is more efficient to divide the histogram into
a large number cells. However, if the histogram is to be filled only a few
times, it is better to divide into a small number of cells.
*/

////////////////////////////////////////////////////////////////////////////////
/// Default Constructor. No boundaries specified.

UBTH2Poly::UBTH2Poly()
{
   Initialize(0., 0., 0., 0., 25, 25);
   SetName("NoName");
   SetTitle("NoTitle");
   SetFloat();
}

////////////////////////////////////////////////////////////////////////////////
/// Constructor with specified name and boundaries,
/// but no partition cell number.

UBTH2Poly::UBTH2Poly(const char *name,const char *title, Double_t xlow,Double_t xup
                                             , Double_t ylow,Double_t yup)
{
   Initialize(xlow, xup, ylow, yup, 25, 25);
   SetName(name);
   SetTitle(title);
   SetFloat(kFALSE);
   if (fgDefaultSumw2) Sumw2(); fNcells = kNOverflow; // new
}

////////////////////////////////////////////////////////////////////////////////
/// Constructor with specified name and boundaries and partition cell number.

UBTH2Poly::UBTH2Poly(const char *name,const char *title,
           Int_t nX, Double_t xlow, Double_t xup,
           Int_t nY, Double_t ylow, Double_t yup)
{
   Initialize(xlow, xup, ylow, yup, nX, nY);
   SetName(name);
   SetTitle(title);
   SetFloat(kFALSE);
   if (fgDefaultSumw2) Sumw2(); fNcells = kNOverflow; // new
}

////////////////////////////////////////////////////////////////////////////////
/// Destructor.

UBTH2Poly::~UBTH2Poly()
{
   delete[] fCells;
   delete[] fIsEmpty;
   delete[] fCompletelyInside;
   // delete at the end the bin List since it owns the objects
   delete fBins;
}

  // UBTH2Poly& UBTH2Poly::operator=(UBTH2Poly &h1) // NEW
  // {
  //   Warning("operator=","Assignemet operator called, but lacks full implementation.");    
  //   if (this != &h1)  ((UBTH2Poly&)h1).Copy(*this);
  //   return *this;
  // }

////////////////////////////////////////////////////////////////////////////////
/// Adds a new bin to the histogram. It can be any object having the method
/// IsInside(). It returns the bin number in the histogram. It returns 0 if
/// it failed to add. To allow the histogram limits to expand when a bin
/// outside the limits is added, call SetFloat() before adding the bin.

Int_t UBTH2Poly::AddBin(TObject *poly) // new
{
   if (!poly) return 0;

    if (fBins == 0) {
      fBins = new TList();
      fBins->SetOwner();
    }

    fNcells++;
    Int_t ibin = fNcells-kNOverflow; // Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility
    TH2PolyBin *bin = new TH2PolyBin(poly, ibin); // Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility

    // If the bin lies outside histogram boundaries, then extends the boundaries.
    // Also changes the partition information accordingly
    Bool_t flag = kFALSE;
    if (fFloat) {
      if (fXaxis.GetXmin() > bin->GetXMin()) {
        fXaxis.Set(100, bin->GetXMin(), fXaxis.GetXmax());
        flag = kTRUE;
      }
      if (fXaxis.GetXmax() < bin->GetXMax()) {
        fXaxis.Set(100, fXaxis.GetXmin(), bin->GetXMax());
        flag = kTRUE;
      }
      if (fYaxis.GetXmin() > bin->GetYMin()) {
        fYaxis.Set(100, bin->GetYMin(), fYaxis.GetXmax());
        flag = kTRUE;
      }
      if (fYaxis.GetXmax() < bin->GetYMax()) {
        fYaxis.Set(100, fYaxis.GetXmin(), bin->GetYMax());
        flag = kTRUE;
      }
      if (flag) ChangePartition(fCellX, fCellY);
    } else {
      /*Implement polygon clipping code here*/
    }

    fBins->Add((TObject*) bin);
    SetNewBinAdded(kTRUE);

    // Adds the bin to the partition matrix
    AddBinToPartition(bin);

    return ibin; // Commit c86fa4200b0c50f3990cdfb6b7c4eeb90abd1df3 combatibility
}

////////////////////////////////////////////////////////////////////////////////
/// Adds a new bin to the histogram. The number of vertices and their (x,y)
/// coordinates are required as input. It returns the bin number in the
/// histogram.

Int_t UBTH2Poly::AddBin(Int_t n, const Double_t *x, const Double_t *y)
{
   TGraph *g = new TGraph(n, x, y);
   Int_t bin = AddBin(g);
   return bin;
}

////////////////////////////////////////////////////////////////////////////////
/// Add a new bin to the histogram. The bin shape is a rectangle.
/// It returns the bin number of the bin in the histogram.

Int_t UBTH2Poly::AddBin(Double_t x1, Double_t y1, Double_t x2, Double_t  y2) // new
{
   Double_t x[] = {x1, x1, x2, x2, x1};
   Double_t y[] = {y1, y2, y2, y1, y1};
   TGraph *g = new TGraph(5, x, y);
   Int_t bin = AddBin(g);
   return bin;
}

////////////////////////////////////////////////////////////////////////////////
/// Performs the operation: this = this + c1*h1.

Bool_t UBTH2Poly::Add(const TH1 *h1, Double_t c1) // NEW
{
    Int_t bin;
  
     UBTH2Poly *h1p = (UBTH2Poly *)h1;
  
     // Check if number of bins is the same.
     if (h1p->GetNumberOfBins() != GetNumberOfBins()) {
        Error("Add", "Attempt to add histograms with different number of bins");
        return kFALSE;
     }
  
     // Check if the bins are the same.
     TList *h1pBins = h1p->GetBins();
     TH2PolyBin *thisBin, *h1pBin;
     for (bin = 1; bin <= GetNumberOfBins(); bin++) {
        thisBin = (TH2PolyBin *)fBins->At(bin - 1);
        h1pBin  = (TH2PolyBin *)h1pBins->At(bin - 1);
        if (thisBin->GetXMin() != h1pBin->GetXMin() ||
              thisBin->GetXMax() != h1pBin->GetXMax() ||
              thisBin->GetYMin() != h1pBin->GetYMin() ||
              thisBin->GetYMax() != h1pBin->GetYMax()) {
           Error("Add", "Attempt to add histograms with different bin limits");
           return kFALSE;
        }
        if ( thisBin->GetBinNumber() != h1pBin->GetBinNumber() ) {
           Error("Add", "Attempt to add histograms with different bin numbers. Have you called AddBin() in the same order for both histograms?");
           return kFALSE;
        }
     }
  
     // Create Sumw2 if h1p has Sumw2 set
     if (fSumw2.fN == 0 && h1p->GetSumw2N() != 0) Sumw2();
  
     // statistics can be preserved only in case of positive coefficients
     // otherwise with negative c1 (histogram subtraction) one risks to get negative variances
     Bool_t resetStats = (c1 < 0);
     Double_t s1[kNstat] = {0};
     Double_t s2[kNstat] = {0};
     if (!resetStats) {
        // need to initialize to zero s1 and s2 since
        // GetStats fills only used elements depending on dimension and type
        GetStats(s1);
        h1->GetStats(s2);
     }
  
    // Perform the Add.
    Double_t factor = 1;
    if (h1p->GetNormFactor() != 0) {
      factor = h1p->GetNormFactor() / h1p->GetSumOfWeights();
    }
           

     for (bin = -kNOverflow; bin <= GetNumberOfBins(); bin++) {
        Double_t y = this->GetBinContent(bin) + c1 * h1p->GetBinContent(bin);
        SetBinContent(bin, y);

        if (fSumw2.fN) {
           Double_t e1 = factor * h1p->GetBinError(bin);
           int idx = bin+kNOverflow;
           if (bin==0) continue;
           if (bin>0) idx -= 1;
           fSumw2.fArray[idx] += c1 * c1 * e1 * e1;
        }
     }
  
     // update statistics (do here to avoid changes by SetBinContent)
     if (resetStats)  {
        // statistics need to be reset in case coefficient are negative
        // ResetStats();
      // std::cout << "kNstat = " << kNstat << std::endl;
        Double_t stats[kNstat] = {0};
        fTsumw = 0;
        fEntries = 1; // to force re-calculation of the statistics in TH1::GetStats
      // std::cout << "Before GetStats" << std::endl;
        GetStats(stats);
      // std::cout << "Before PutStats" << std::endl;
        PutStats(stats);
        fEntries = TMath::Abs(fTsumw);
        // use effective entries for weighted histograms:  (sum_w) ^2 / sum_w2
        if (fSumw2.fN > 0 && fTsumw > 0 && stats[1] > 0 ) fEntries = stats[0]*stats[0]/ stats[1];

      } else {
        for (Int_t i = 0; i < kNstat; i++) {
           if (i == 1) s1[i] += c1 * c1 * s2[i];
           else        s1[i] += c1 * s2[i];
        }
        PutStats(s1);
        SetEntries(std::abs(GetEntries() + c1 * h1->GetEntries()));
     }
     return kTRUE;
}

////////////////////////////////////////////////////////////////////////////////
/// Performs the operation: this = this + c1*f1.

Bool_t UBTH2Poly::Add(TF1 *, Double_t, Option_t *)
{
   Warning("Add","Not implement for UBTH2Poly");
   return kFALSE;
}

////////////////////////////////////////////////////////////////////////////////
/// Replace contents of this histogram by the addition of h1 and h2.

Bool_t UBTH2Poly::Add(const TH1 *, const TH1 *, Double_t, Double_t)
{
   Warning("Add","Not implement for UBTH2Poly");
   return kFALSE;
}

////////////////////////////////////////////////////////////////////////////////
/// Adds the input bin into the partition cell matrix. This method is called
/// in AddBin() and ChangePartition().

void UBTH2Poly::AddBinToPartition(TH2PolyBin *bin)
{
   // Cell Info
   Int_t nl, nr, mb, mt; // Max/min indices of the cells that contain the bin
   Double_t xclipl, xclipr, yclipb, yclipt; // x and y coordinates of a cell
   Double_t binXmax, binXmin, binYmax, binYmin; // The max/min bin coordinates

   binXmax = bin->GetXMax();
   binXmin = bin->GetXMin();
   binYmax = bin->GetYMax();
   binYmin = bin->GetYMin();
   nl = (Int_t)(floor((binXmin - fXaxis.GetXmin())/fStepX));
   nr = (Int_t)(floor((binXmax - fXaxis.GetXmin())/fStepX));
   mb = (Int_t)(floor((binYmin - fYaxis.GetXmin())/fStepY));
   mt = (Int_t)(floor((binYmax - fYaxis.GetXmin())/fStepY));

   // Make sure the array indices are correct.
   if (nr>=fCellX) nr = fCellX-1;
   if (mt>=fCellY) mt = fCellY-1;
   if (nl<0)       nl = 0;
   if (mb<0)       mb = 0;

   // number of cells in the grid
   //N.B. not to be confused with fNcells (the number of bins) !
   fNCells = fCellX*fCellY;

   // Loop over all cells
   for (int i = nl; i <= nr; i++) {
      xclipl = fXaxis.GetXmin() + i*fStepX;
      xclipr = xclipl + fStepX;
      for (int j = mb; j <= mt; j++) {
         yclipb = fYaxis.GetXmin() + j*fStepY;
         yclipt = yclipb + fStepY;

         // If the bin is completely inside the cell,
         // add that bin to the cell then return
         if ((binXmin >= xclipl) && (binXmax <= xclipr) &&
             (binYmax <= yclipt) && (binYmin >= yclipb)){
            fCells[i + j*fCellX].Add((TObject*) bin);
            fIsEmpty[i + j*fCellX] = kFALSE;  // Makes the cell non-empty
            return;
         }

         // If any of the sides of the cell intersect with any side of the bin,
         // add that bin then continue
         if (IsIntersecting(bin, xclipl, xclipr, yclipb, yclipt)) {
            fCells[i + j*fCellX].Add((TObject*) bin);
            fIsEmpty[i + j*fCellX] = kFALSE;  // Makes the cell non-empty
            continue;
         }
         // If a corner of the cell is inside the bin and since there is no
         // intersection, then that cell completely inside the bin.
         if((bin->IsInside(xclipl,yclipb)) || (bin->IsInside(xclipl,yclipt))){
            fCells[i + j*fCellX].Add((TObject*) bin);
            fIsEmpty[i + j*fCellX] = kFALSE;  // Makes the cell non-empty
            fCompletelyInside[i + fCellX*j] = kTRUE;
            continue;
         }
         if((bin->IsInside(xclipr,yclipb)) || (bin->IsInside(xclipr,yclipt))){
            fCells[i + j*fCellX].Add((TObject*) bin);
            fIsEmpty[i + j*fCellX] = kFALSE;  // Makes the cell non-empty
            fCompletelyInside[i + fCellX*j] = kTRUE;
            continue;
         }
      }
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Changes the number of partition cells in the histogram.
/// Deletes the old partition and constructs a new one.

void UBTH2Poly::ChangePartition(Int_t n, Int_t m)
{
   fCellX = n;                          // Set the number of cells
   fCellY = m;                          // Set the number of cells

   delete [] fCells;                    // Deletes the old partition

   // number of cells in the grid
   //N.B. not to be confused with fNcells (the number of bins) !
   fNCells = fCellX*fCellY;
   fCells  = new TList [fNCells];  // Sets an empty partition

   fStepX = (fXaxis.GetXmax() - fXaxis.GetXmin())/fCellX;
   fStepY = (fYaxis.GetXmax() - fYaxis.GetXmin())/fCellY;

   delete [] fIsEmpty;
   delete [] fCompletelyInside;
   fIsEmpty = new Bool_t [fNCells];
   fCompletelyInside = new Bool_t [fNCells];

   // Initializes the flags
   for (int i = 0; i<fNCells; i++) {
      fIsEmpty[i]          = kTRUE;
      fCompletelyInside[i] = kFALSE;
   }

   // TList iterator
   TIter    next(fBins);
   TObject  *obj;

   while((obj = next())){   // Loop over bins and add them to the partition
      AddBinToPartition((TH2PolyBin*) obj);
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Make a complete copy of the underlying object.  If 'newname' is set,
/// the copy's name will be set to that name.

TObject* UBTH2Poly::Clone(const char* newname) const
{
   // TH1::Clone relies on ::Copy to implemented by the derived class.
   // Until this is implemented, revert to the much slower default version
   // (and possibly non-thread safe).

   return TNamed::Clone(newname);
}

////////////////////////////////////////////////////////////////////////////////
/// Clears the contents of all bins in the histogram.

void UBTH2Poly::ClearBinContents()
{
   TIter next(fBins);
   TObject *obj;
   TH2PolyBin *bin;

   // Clears the bin contents
   while ((obj = next())) {
      bin = (TH2PolyBin*) obj;
      bin->ClearContent();
   }

   // Clears the statistics
   fTsumw   = 0;
   fTsumwx  = 0;
   fTsumwx2 = 0;
   fTsumwy  = 0;
   fTsumwy2 = 0;
   fEntries = 0;
}

////////////////////////////////////////////////////////////////////////////////
/// Reset this histogram: contents, errors, etc.

void UBTH2Poly::Reset(Option_t *opt)
{
   for (int i=0; i<kNOverflow; i++) fOverflow[i] = 0.; // new

   TIter next(fBins);
   TObject *obj;
   TH2PolyBin *bin;

   // Clears the bin contents
   while ((obj = next())) {
      bin = (TH2PolyBin*) obj;
      bin->ClearContent();
   }

   TH2::Reset(opt);
}

////////////////////////////////////////////////////////////////////////////////
/// Returns the bin number of the bin at the given coordinate. -1 to -9 are
/// the overflow and underflow bins.  overflow bin -5 is the unbinned areas in
/// the histogram (also called "the sea"). The third parameter can be left
/// blank.
/// The overflow/underflow bins are:
///~~~ {.cpp}
/// -1 | -2 | -3
/// -------------
/// -4 | -5 | -6
/// -------------
/// -7 | -8 | -9
///~~~
/// where -5 means is the "sea" bin (i.e. unbinned areas)

Int_t UBTH2Poly::FindBin(Double_t x, Double_t y, Double_t)
{

   // Checks for overflow/underflow
   Int_t overflow = 0;
   if      (y > fYaxis.GetXmax()) overflow += -1;
   else if (y > fYaxis.GetXmin()) overflow += -4;
   else                           overflow += -7;
   if      (x > fXaxis.GetXmax()) overflow += -2;
   else if (x > fXaxis.GetXmin()) overflow += -1;
   if (overflow != -5) return overflow;

   // Finds the cell (x,y) coordinates belong to
   Int_t n = (Int_t)(floor((x-fXaxis.GetXmin())/fStepX));
   Int_t m = (Int_t)(floor((y-fYaxis.GetXmin())/fStepY));

   // Make sure the array indices are correct.
   if (n>=fCellX) n = fCellX-1;
   if (m>=fCellY) m = fCellY-1;
   if (n<0)       n = 0;
   if (m<0)       m = 0;

   if (fIsEmpty[n+fCellX*m]) return -5;

   TH2PolyBin *bin;

   TIter next(&fCells[n+fCellX*m]);
   TObject *obj;

   // Search for the bin in the cell
   while ((obj=next())) {
      bin  = (TH2PolyBin*)obj;
      if (bin->IsInside(x,y)) return bin->GetBinNumber();
   }

   // If the search has not returned a bin, the point must be on "the sea"
   return -5;
}

////////////////////////////////////////////////////////////////////////////////
/// Increment the bin containing (x,y) by 1.
/// Uses the partitioning algorithm.

Int_t UBTH2Poly::Fill(Double_t x, Double_t y)
{
   return Fill(x, y, 1.0);
}

////////////////////////////////////////////////////////////////////////////////
/// Increment the bin containing (x,y) by w.
/// Uses the partitioning algorithm.

Int_t UBTH2Poly::Fill(Double_t x, Double_t y, Double_t w) // NEW
{
   if (!fSumw2.fN && w != 1.0 && !TestBit(TH1::kIsNotW)) Sumw2();

   if (fNcells <= kNOverflow) return 0;
   Int_t overflow = 0;
   if      (y > fYaxis.GetXmax()) overflow += -1;
   else if (y > fYaxis.GetXmin()) overflow += -4;
   else                           overflow += -7;
   if      (x > fXaxis.GetXmax()) overflow += -2;
   else if (x > fXaxis.GetXmin()) overflow += -1;
   if (overflow != -5) {
      fOverflow[-overflow - 1] += w;
      if (fSumw2.fN) fSumw2.fArray[-overflow - 1] += w*w;
      return overflow;
   }

   // Finds the cell (x,y) coordinates belong to
   Int_t n = (Int_t)(floor((x-fXaxis.GetXmin())/fStepX));
   Int_t m = (Int_t)(floor((y-fYaxis.GetXmin())/fStepY));

   // Make sure the array indices are correct.
   if (n>=fCellX) n = fCellX-1;
   if (m>=fCellY) m = fCellY-1;
   if (n<0)       n = 0;
   if (m<0)       m = 0;

   if (fIsEmpty[n+fCellX*m]) {
      fOverflow[4]+= w;
      if (fSumw2.fN) fSumw2.fArray[4] += w*w;
      return -5;
   }

   TH2PolyBin *bin;
   Int_t bi;

   TIter next(&fCells[n+fCellX*m]);
   TObject *obj;

   while ((obj=next())) {
      bin  = (TH2PolyBin*)obj;
      bi = bin->GetBinNumber()-1+kNOverflow;
      if (bin->IsInside(x,y)) {
         bin->Fill(w);

         // Statistics
         fTsumw   = fTsumw + w;
         fTsumwx  = fTsumwx + w*x;
         fTsumwx2 = fTsumwx2 + w*x*x;
         fTsumwy  = fTsumwy + w*y;
         fTsumwy2 = fTsumwy2 + w*y*y;
         if (fSumw2.fN) fSumw2.fArray[bi] += w*w;
         fEntries++;

         SetBinContentChanged(kTRUE);

         return bin->GetBinNumber();
      }
   }

   fOverflow[4]+= w;
   if (fSumw2.fN) fSumw2.fArray[4] += w*w;
   return -5;
}

////////////////////////////////////////////////////////////////////////////////
/// Increment the bin named "name" by w.

Int_t UBTH2Poly::Fill(const char* name, Double_t w)
{
   TString sname(name);

   TIter    next(fBins);
   TObject  *obj;
   TH2PolyBin *bin;

   while ((obj = next())) {
      bin = (TH2PolyBin*) obj;
      if (!sname.CompareTo(bin->GetPolygon()->GetName())) {
         bin->Fill(w);
         fEntries++;
         SetBinContentChanged(kTRUE);
         return bin->GetBinNumber();
      }
   }

   return 0;
}

////////////////////////////////////////////////////////////////////////////////
/// Fills a 2-D histogram with an array of values and weights.
///
/// \param [in] ntimes:  number of entries in arrays x and w
///                      (array size must be ntimes*stride)
/// \param [in] x:       array of x values to be histogrammed
/// \param [in] y:       array of y values to be histogrammed
/// \param [in] w:       array of weights
/// \param [in] stride:  step size through arrays x, y and w

void UBTH2Poly::FillN(Int_t ntimes, const Double_t* x, const Double_t* y,
                               const Double_t* w, Int_t stride)
{
   for (int i = 0; i < ntimes; i += stride) {
      Fill(x[i], y[i], w[i]);
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Returns the integral of bin contents.
/// By default the integral is computed as the sum of bin contents.
/// If option "width" or "area" is specified, the integral is the sum of
/// the bin contents multiplied by the area of the bin.

Double_t UBTH2Poly::Integral(Option_t* option) const // NEW
{
   TString opt = option;
    opt.ToLower();

    Bool_t width = kFALSE;
    if ((opt.Contains("width")) || (opt.Contains("area"))) {
      width = kTRUE;
    }

    Double_t w;
    Double_t integral = 0.;

    TIter    next(fBins);
    TObject *obj;
    TH2PolyBin *bin;
    while ((obj=next())) {
      bin = (TH2PolyBin*) obj;
      w = bin->GetArea();
      if (width) integral += w * bin->GetContent();
      else integral += bin->GetContent();
    }

    if (opt.Contains("overflow")) {
      for (int i = 0; i < kNOverflow; i++) {
        if (width) {
          Warning("Integral","width (area) not fully supported together with overflow option.");    
        }
        else integral += fOverflow[i]; 
      }
    }

    return integral;
}

////////////////////////////////////////////////////////////////////////////////
/// Returns the content of the input bin
/// For the overflow/underflow/sea bins:
///~~~ {.cpp}
/// -1 | -2 | -3
/// ---+----+----
/// -4 | -5 | -6
/// ---+----+----
/// -7 | -8 | -9
///~~~
/// where -5 is the "sea" bin (i.e. unbinned areas)

Double_t UBTH2Poly::GetBinContent(Int_t bin) const // NEW
{
   if (bin > GetNumberOfBins() || bin == 0 || bin < -kNOverflow) return 0;
   if (bin<0) return fOverflow[-bin - 1];
   return ((TH2PolyBin*) fBins->At(bin-1))->GetContent();
}

////////////////////////////////////////////////////////////////////////////////
/// Returns the value of error associated to bin number bin.
/// If the sum of squares of weights has been defined (via Sumw2),
/// this function returns the sqrt(sum of w2).
/// otherwise it returns the sqrt(contents) for this bin.

Double_t UBTH2Poly::GetBinError(Int_t bin) const // NEW
{
   if (bin == 0 || bin > GetNumberOfBins() || bin < - kNOverflow) return 0;
   // if (bin > (fNcells)) return 0;
   if (fBuffer) ((TH1*)this)->BufferEmpty();
   if (fSumw2.fN) {
      Int_t binIndex = (bin > 0) ? bin+kNOverflow-1 : kNOverflow+bin;
      Double_t err2 = fSumw2.fArray[binIndex];
      return TMath::Sqrt(err2);
   }
   Double_t error2 = TMath::Abs(GetBinContent(bin));
   return TMath::Sqrt(error2);
}

////////////////////////////////////////////////////////////////////////////////
/// Returns the bin name.

const char *UBTH2Poly::GetBinName(Int_t bin) const
{
   if (bin > (fNcells))  return "";
   if (bin < 0)          return "";
   return ((TH2PolyBin*) fBins->At(bin-1))->GetPolygon()->GetName();
}

////////////////////////////////////////////////////////////////////////////////
/// Returns the bin title.

const char *UBTH2Poly::GetBinTitle(Int_t bin) const
{
   if (bin > (fNcells))  return "";
   if (bin < 0)          return "";
   return ((TH2PolyBin*) fBins->At(bin-1))->GetPolygon()->GetTitle();
}

////////////////////////////////////////////////////////////////////////////////
/// Returns the maximum value of the histogram.

Double_t UBTH2Poly::GetMaximum() const
{
   if (fNcells==0) return 0;
   if (fMaximum != -1111) return fMaximum;

   TH2PolyBin  *b;

   TIter next(fBins);
   TObject *obj;
   Double_t max,c;

   max = ((TH2PolyBin*) next())->GetContent();

   while ((obj=next())) {
      b = (TH2PolyBin*)obj;
      c = b->GetContent();
      if (c>max) max = c;
   }
   return max;
}

////////////////////////////////////////////////////////////////////////////////
/// Returns the maximum value of the histogram that is less than maxval.

Double_t UBTH2Poly::GetMaximum(Double_t maxval) const
{
   if (fNcells==0) return 0;
   if (fMaximum != -1111) return fMaximum;

   TH2PolyBin  *b;

   TIter next(fBins);
   TObject *obj;
   Double_t max,c;

   max = ((TH2PolyBin*) next())->GetContent();

   while ((obj=next())) {
      b = (TH2PolyBin*)obj;
      c = b->GetContent();
      if (c>max && c<maxval) max=c;
   }
   return max;
}

////////////////////////////////////////////////////////////////////////////////
/// Returns the minimum value of the histogram.

Double_t UBTH2Poly::GetMinimum() const
{
   if (fNcells==0) return 0;
   if (fMinimum != -1111) return fMinimum;

   TH2PolyBin  *b;

   TIter next(fBins);
   TObject *obj;
   Double_t min,c;

   min = ((TH2PolyBin*) next())->GetContent();

   while ((obj=next())) {
      b = (TH2PolyBin*)obj;
      c = b->GetContent();
      if (c<min) min=c;
   }
   return min;
}

////////////////////////////////////////////////////////////////////////////////
/// Returns the minimum value of the histogram that is greater than minval.

Double_t UBTH2Poly::GetMinimum(Double_t minval) const
{
   if (fNcells==0) return 0;
   if (fMinimum != -1111) return fMinimum;

   TH2PolyBin  *b;

   TIter next(fBins);
   TObject *obj;
   Double_t min,c;

   min = ((TH2PolyBin*) next())->GetContent();

   while ((obj=next())) {
      b = (TH2PolyBin*)obj;
      c = b->GetContent();
      if (c<min && c>minval) min=c;
   }
   return min;
}

////////////////////////////////////////////////////////////////////////////////
/// Bins the histogram using a honeycomb structure

void UBTH2Poly::Honeycomb(Double_t xstart, Double_t ystart, Double_t a,
                     Int_t k, Int_t s)
{
   // Add the bins
   Double_t numberOfHexagonsInTheRow;
   Double_t x[6], y[6];
   Double_t xloop, yloop, xtemp;
   xloop = xstart; yloop = ystart + a/2.0;
   for (int sCounter = 0; sCounter < s; sCounter++) {

      xtemp = xloop; // Resets the temp variable

      // Determine the number of hexagons in that row
      if(sCounter%2 == 0){numberOfHexagonsInTheRow = k;}
      else{numberOfHexagonsInTheRow = k - 1;}

      for (int kCounter = 0; kCounter <  numberOfHexagonsInTheRow; kCounter++) {

         // Go around the hexagon
         x[0] = xtemp;
         y[0] = yloop;
         x[1] = x[0];
         y[1] = y[0] + a;
         x[2] = x[1] + a*TMath::Sqrt(3)/2.0;
         y[2] = y[1] + a/2.0;
         x[3] = x[2] + a*TMath::Sqrt(3)/2.0;
         y[3] = y[1];
         x[4] = x[3];
         y[4] = y[0];
         x[5] = x[2];
         y[5] = y[4] - a/2.0;

         this->AddBin(6, x, y);

         // Go right
         xtemp += a*TMath::Sqrt(3);
      }

      // Increment the starting position
      if (sCounter%2 == 0) xloop += a*TMath::Sqrt(3)/2.0;
      else                 xloop -= a*TMath::Sqrt(3)/2.0;
      yloop += 1.5*a;
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Initializes the UBTH2Poly object.  This method is called by the constructor.

void UBTH2Poly::Initialize(Double_t xlow, Double_t xup,
                      Double_t ylow, Double_t yup, Int_t n, Int_t m)
{
   Int_t i;
   fDimension = 2;  //The dimension of the histogram

   fBins   = 0;
   fNcells = 0;

   // Sets the boundaries of the histogram
   fXaxis.Set(100, xlow, xup);
   fYaxis.Set(100, ylow, yup);

   for (i=0; i<9; i++) fOverflow[i] = 0.;

   // Statistics
   fEntries = 0;   // The total number of entries
   fTsumw   = 0.;  // Total amount of content in the histogram
   fTsumwx  = 0.;  // Weighted sum of x coordinates
   fTsumwx2 = 0.;  // Weighted sum of the squares of x coordinates
   fTsumwy2 = 0.;  // Weighted sum of the squares of y coordinates
   fTsumwy  = 0.;  // Weighted sum of y coordinates

   fCellX = n; // Set the number of cells to default
   fCellY = m; // Set the number of cells to default

   // number of cells in the grid
   //N.B. not to be confused with fNcells (the number of bins) !
   fNCells = fCellX*fCellY;
   fCells  = new TList [fNCells];  // Sets an empty partition
   fStepX  = (fXaxis.GetXmax() - fXaxis.GetXmin())/fCellX; // Cell width
   fStepY  = (fYaxis.GetXmax() - fYaxis.GetXmin())/fCellY; // Cell height

   fIsEmpty = new Bool_t [fNCells]; // Empty partition
   fCompletelyInside = new Bool_t [fNCells]; // Cell is completely inside bin

   for (i = 0; i<fNCells; i++) {   // Initializes the flags
      fIsEmpty[i] = kTRUE;
      fCompletelyInside[i] = kFALSE;
   }

   // 3D Painter flags
   SetNewBinAdded(kFALSE);
   SetBinContentChanged(kFALSE);
}

////////////////////////////////////////////////////////////////////////////////
/// Returns kTRUE if the input bin is intersecting with the
/// input rectangle (xclipl, xclipr, yclipb, yclipt)

Bool_t UBTH2Poly::IsIntersecting(TH2PolyBin *bin,
                               Double_t xclipl, Double_t xclipr,
                               Double_t yclipb, Double_t yclipt)
{
   Int_t     gn;
   Double_t *gx;
   Double_t *gy;
   Bool_t inter = kFALSE;
   TObject *poly = bin->GetPolygon();

   if (poly->IsA() == TGraph::Class()) {
      TGraph *g = (TGraph*)poly;
      gx = g->GetX();
      gy = g->GetY();
      gn = g->GetN();
      inter = IsIntersectingPolygon(gn, gx, gy, xclipl, xclipr, yclipb, yclipt);
   }

   if (poly->IsA() == TMultiGraph::Class()) {
      TMultiGraph *mg = (TMultiGraph*)poly;
      TList *gl = mg->GetListOfGraphs();
      if (!gl) return inter;
      TGraph *g;
      TIter next(gl);
      while ((g = (TGraph*) next())) {
         gx = g->GetX();
         gy = g->GetY();
         gn = g->GetN();
         inter = IsIntersectingPolygon(gn, gx, gy, xclipl, xclipr,
                                                   yclipb, yclipt);
         if (inter) return inter;
      }
   }

   return inter;
}

////////////////////////////////////////////////////////////////////////////////
/// Returns kTRUE if the input polygon (bn, x, y) is intersecting with the
/// input rectangle (xclipl, xclipr, yclipb, yclipt)

Bool_t UBTH2Poly::IsIntersectingPolygon(Int_t bn, Double_t *x, Double_t *y,
                                      Double_t xclipl, Double_t xclipr,
                                      Double_t yclipb, Double_t yclipt)
{
   Bool_t p0R, p0L, p0T, p0B, p0xM, p0yM, p1R, p1L, p1T;
   Bool_t p1B, p1xM, p1yM, p0In, p1In;

   for (int counter = 0; counter < (bn-1); counter++) {
      // If both are on the same side, return kFALSE
      p0L = x[counter]     <= xclipl; // Point 0 is on the left
      p1L = x[counter + 1] <= xclipl; // Point 1 is on the left
      if (p0L && p1L) continue;
      p0R = x[counter]     >= xclipr; // Point 0 is on the right
      p1R = x[counter + 1] >= xclipr; // Point 1 is on the right
      if (p0R && p1R) continue;
      p0T = y[counter]     >= yclipt; // Point 0 is at the top
      p1T = y[counter + 1] >= yclipt; // Point 1 is at the top
      if (p0T && p1T) continue;
      p0B = y[counter]     <= yclipb; // Point 0 is at the bottom
      p1B = y[counter + 1] <= yclipb; // Point 1 is at the bottom
      if (p0B && p1B) continue;

      // Checks to see if any are inside
      p0xM = !p0R && !p0L; // Point 0 is inside along x
      p0yM = !p0T && !p0B; // Point 1 is inside along x
      p1xM = !p1R && !p1L; // Point 0 is inside along y
      p1yM = !p1T && !p1B; // Point 1 is inside along y
      p0In = p0xM && p0yM; // Point 0 is inside
      p1In = p1xM && p1yM; // Point 1 is inside
      if (p0In) {
         if (p1In) continue;
         return kTRUE;
      } else {
         if (p1In) return kTRUE;
      }

      // We know by now that the points are not in the same side and not inside.

      // Checks to see if they are opposite

      if (p0xM && p1xM) return kTRUE;
      if (p0yM && p1yM) return kTRUE;

      // We now know that the points are in different x and y indices

      Double_t xcoord[3], ycoord[3];
      xcoord[0] = x[counter];
      xcoord[1] = x[counter + 1];
      ycoord[0] = y[counter];
      ycoord[1] = y[counter + 1];

      if (p0L) {
         if(p1T){
            xcoord[2] = xclipl;
            ycoord[2] = yclipb;
            if((TMath::IsInside(xclipl, yclipt, 3, xcoord, ycoord)) ||
               (TMath::IsInside(xclipr, yclipb, 3, xcoord, ycoord))) continue;
            else return kTRUE;
         } else if (p1B) {
            xcoord[2] = xclipl;
            ycoord[2] = yclipt;
            if((TMath::IsInside(xclipl, yclipb, 3, xcoord, ycoord)) ||
               (TMath::IsInside(xclipr, yclipt, 3, xcoord, ycoord))) continue;
            else return kTRUE;
         } else { // p1yM
            if (p0T) {
               xcoord[2] = xclipl;
               ycoord[2] = yclipb;
               if (TMath::IsInside(xclipr, yclipt, 3, xcoord, ycoord)) continue;
               else return kTRUE;
            }
            if (p0B) {
               xcoord[2] = xclipl;
               ycoord[2] = yclipt;
               if (TMath::IsInside(xclipr, yclipb, 3, xcoord, ycoord)) continue;
               else return kTRUE;
            }
         }
      } else if (p0R) {
         if (p1T) {
            xcoord[2] = xclipl;
            ycoord[2] = yclipb;
            if ((TMath::IsInside(xclipr, yclipb, 3, xcoord, ycoord)) ||
                (TMath::IsInside(xclipl, yclipt, 3, xcoord, ycoord))) continue;
            else return kTRUE;
         } else if (p1B) {
            xcoord[2] = xclipl;
            ycoord[2] = yclipt;
            if ((TMath::IsInside(xclipl, yclipb, 3, xcoord, ycoord)) ||
                (TMath::IsInside(xclipr, yclipt, 3, xcoord, ycoord))) continue;
            else return kTRUE;
         } else{ // p1yM
            if (p0T) {
               xcoord[2] = xclipr;
               ycoord[2] = yclipb;
               if (TMath::IsInside(xclipl, yclipt, 3, xcoord, ycoord)) continue;
               else return kTRUE;
            }
            if (p0B) {
               xcoord[2] = xclipr;
               ycoord[2] = yclipt;
               if (TMath::IsInside(xclipl, yclipb, 3, xcoord, ycoord)) continue;
               else return kTRUE;
            }
         }
      }
   }
   return kFALSE;
}

////////////////////////////////////////////////////////////////////////////////
/// UBTH2Poly cannot be merged.

Long64_t UBTH2Poly::Merge(TCollection *)
{
   Error("Merge","Cannot merge UBTH2Poly");
   return 0;
}

////////////////////////////////////////////////////////////////////////////////
/// Save primitive as a C++ statement(s) on output stream out

void UBTH2Poly::SavePrimitive(std::ostream &out, Option_t *option)
{
   out <<"   "<<std::endl;
   out <<"   "<< ClassName() <<" *";

   //histogram pointer has by default the histogram name.
   //however, in case histogram has no directory, it is safer to add a
   //incremental suffix
   static Int_t hcounter = 0;
   TString histName = GetName();
   if (!fDirectory && !histName.Contains("Graph")) {
      hcounter++;
      histName += "__";
      histName += hcounter;
   }
   const char *hname = histName.Data();

   //Construct the class initialization
   out << hname << " = new " << ClassName() << "(\"" << hname << "\", \""
       << GetTitle() << "\", " << fCellX << ", " << fXaxis.GetXmin()
       << ", " << fXaxis.GetXmax()
       << ", " << fCellY << ", " << fYaxis.GetXmin() << ", "
       << fYaxis.GetXmax() << ");" << std::endl;

   // Save Bins
   TIter       next(fBins);
   TObject    *obj;
   TH2PolyBin *th2pBin;

   while((obj = next())){
      th2pBin = (TH2PolyBin*) obj;
      th2pBin->GetPolygon()->SavePrimitive(out,
                                           Form("th2poly%s",histName.Data()));
   }

   // save bin contents
   out<<"   "<<std::endl;
   Int_t bin;
   for (bin=1;bin<=fNcells;bin++) {
      Double_t bc = GetBinContent(bin);
      if (bc) {
         out<<"   "<<hname<<"->SetBinContent("<<bin<<","<<bc<<");"<<std::endl;
      }
   }

   // save bin errors
   if (fSumw2.fN) {
      for (bin=1;bin<=fNcells;bin++) {
         Double_t be = GetBinError(bin);
         if (be) {
            out<<"   "<<hname<<"->SetBinError("<<bin<<","<<be<<");"<<std::endl;
         }
      }
   }
   TH1::SavePrimitiveHelp(out, hname, option);
}

////////////////////////////////////////////////////////////////////////////////
/// Multiply this histogram by a constant c1.

void UBTH2Poly::Scale(Double_t c1, Option_t*option) // NEW
{
  Bool_t normaliseWidth = kFALSE;
    TString opt = option; opt.ToLower();
    
    // store bin errors when scaling since cannot anymore be computed as sqrt(N)
    if (!opt.Contains("nosw2") && GetSumw2N() == 0) Sumw2();

    if (opt.Contains("width")) {
      normaliseWidth = kTRUE;
    }
    else {

      for (int bin = -kNOverflow; bin <= GetNumberOfBins(); bin++) {
        SetBinContent(bin, c1 * GetBinContent(bin));

        if (fSumw2.fN) {
          int idx = bin+kNOverflow;
          if (bin==0) continue;
          if (bin>0) idx -= 1;
          fSumw2.fArray[idx] *= (c1 * c1); // update errors
        }
      }
    }

    if (normaliseWidth) {


      for (int bin = -kNOverflow; bin <= GetNumberOfBins(); bin++) {
        Double_t w = GetBinWidth(bin);
        SetBinContent(bin, c1 * GetBinContent(bin) / w);

        if (fSumw2.fN) {
          Double_t e1 = GetBinError(bin) / w;
          int idx = bin+kNOverflow;
          if (bin==0) continue;
          if (bin>0) idx -= 1;
          fSumw2.fArray[idx] = c1 * c1 * e1 * e1;
        }

      }
    }
}

////////////////////////////////////////////////////////////////////////////////
/// Sets the contents of the input bin to the input content
/// Negative values between -1 and -9 are for the overflows and the sea

void UBTH2Poly::SetBinContent(Int_t bin, Double_t content) // NEW
{
   if (bin > (fNcells) || bin == 0 || bin < -kNOverflow ) return;
   if (bin > 0)
      ((TH2PolyBin*) fBins->At(bin-1))->SetContent(content);
   else
      fOverflow[-bin - 1] = content;
   SetBinContentChanged(kTRUE);
}

void UBTH2Poly::SetBinError(Int_t bin, Double_t error) // NEW
{
  if (!fSumw2.fN) Sumw2();
   if (bin > (fNcells) || bin == 0 || bin < -kNOverflow ) return;

   Int_t binIndex = (bin > 0) ? bin+kNOverflow-1 : kNOverflow+bin;
   fSumw2.fArray[binIndex] = error * error;
}


  Double_t UBTH2Poly::GetBinWidth(Int_t bin) const // NEW
{
   Int_t bin_idx = 0;
   if (bin > GetNumberOfBins() || bin <= 0) bin_idx = 0;
   else bin_idx = bin - 1;

   TH2PolyBin *thisBin = (TH2PolyBin *) fBins->At(bin_idx);
   Double_t w = thisBin->GetArea();
   return w;
}

////////////////////////////////////////////////////////////////////////////////
/// When set to kTRUE, allows the histogram to expand if a bin outside the
/// limits is added.

void UBTH2Poly::SetFloat(Bool_t flag)
{
   fFloat = flag;
}





  void UBTH2Poly::SetNBinsX(Int_t n) {

    _n_bins_x = n;

  }

  Int_t UBTH2Poly::GetNBinsX() {

    return _n_bins_x;

  }

  UBTH2Poly* UBTH2Poly::GetCopyWithBinNumbers(const char *name) const {

    UBTH2Poly* h = (UBTH2Poly*) this->Clone(name);
    h->Reset();

    TH2PolyBin *thisBin;

    for (Int_t bin = 1; bin <= GetNumberOfBins(); bin++) {
      thisBin = (TH2PolyBin *)fBins->At(bin - 1);
      h->SetBinContent(thisBin->GetBinNumber(), thisBin->GetBinNumber());
    }

    h->GetYaxis()->CenterTitle();;
    h->GetXaxis()->CenterTitle();;
    h->GetYaxis()->SetTitleOffset(0.80);

    return h;

  }

  Bool_t UBTH2Poly::Divide(const TH1 *h1)
  {

     Int_t bin;
  
     UBTH2Poly *h1p = (UBTH2Poly *)h1;
  
     // Check if number of bins is the same.
     if (h1p->GetNumberOfBins() != GetNumberOfBins()) {
        Error("Add", "Attempt to divide histograms with different number of bins");
        return kFALSE;
     }
  
     // Check if the bins are the same.
     TList *h1pBins = h1p->GetBins();
     TH2PolyBin *thisBin, *h1pBin;
     for (bin = 1; bin <= GetNumberOfBins(); bin++) {
        thisBin = (TH2PolyBin *)fBins->At(bin - 1);
        h1pBin  = (TH2PolyBin *)h1pBins->At(bin - 1);
        if (thisBin->GetXMin() != h1pBin->GetXMin() ||
              thisBin->GetXMax() != h1pBin->GetXMax() ||
              thisBin->GetYMin() != h1pBin->GetYMin() ||
              thisBin->GetYMax() != h1pBin->GetYMax()) {
           Error("Add", "Attempt to add histograms with different bin limits");
           return kFALSE;
        }
        if ( thisBin->GetBinNumber() != h1pBin->GetBinNumber() ) {
           Error("Add", "Attempt to add histograms with different bin numbers. Have you called AddBin() in the same order for both histograms?");
           return kFALSE;
        }
     }
  
     // Create Sumw2 if h1p has Sumw2 set
     if (fSumw2.fN == 0 && h1p->GetSumw2N() != 0) Sumw2();
  
    
           


     for (bin = -kNOverflow; bin <= GetNumberOfBins(); bin++) {

        Double_t c0 = GetBinContent(bin);
        Double_t c1 = h1p->GetBinContent(bin);

        if (c1) SetBinContent(bin, c0 / c1);
        else SetBinContent(bin, 0.0);

        if (fSumw2.fN) {
           int idx = bin+kNOverflow;
           if (bin==0) continue;
           if (bin>0) idx -= 1;
           if (c1 == 0) { fSumw2.fArray[idx] = 0; continue; }

           Double_t c1sq = c1 * c1;
           fSumw2.fArray[idx] = (GetBinError(bin) * GetBinError(bin) * c1sq + h1p->GetBinError(bin) * h1p->GetBinError(bin) * c0 * c0) / (c1sq * c1sq);
        }
     }
  
     ResetStats();
     return kTRUE;
  }

  TH1D* UBTH2Poly::ProjectionY(const char *name, Int_t firstxbin, std::vector<int> & bin_numbers) const
  {

    bin_numbers.clear();

    std::vector<double> boundaries;
    boundaries.reserve(GetNumberOfBins() * 2);
    TH2PolyBin *thisBin;

    for (Int_t bin = 1; bin <= GetNumberOfBins(); bin++) {
      thisBin = (TH2PolyBin *)fBins->At(bin - 1);
      if (thisBin->GetYMin() != fYaxis.GetXmin()) continue;
      boundaries.push_back(thisBin->GetXMin());
    }
    boundaries.push_back(fXaxis.GetXmax());

    // for (auto b : boundaries) {
    //   std::cout << "boundary: " << b << std::endl;
    // }

    Int_t index = (firstxbin - 1);
    double boundary_low = boundaries.at(index);
    double boundary_up  = boundaries.at(index + 1);

    std::map<double, TH2PolyBin *> loweredge_to_bin; // automatically sorts

    for (Int_t bin = 1; bin <= GetNumberOfBins(); bin++) {
      thisBin = (TH2PolyBin *)fBins->At(bin - 1);
      if (thisBin->GetXMin() != boundary_low) continue;
      if (thisBin->GetXMax() != boundary_up) continue;
      loweredge_to_bin[thisBin->GetYMin()] = thisBin;
      bin_numbers.push_back(thisBin->GetBinNumber());
    }

    std::vector<double> bins_v;
    bins_v.reserve(loweredge_to_bin.size() + 1);
    for (auto it : loweredge_to_bin) {
      bins_v.push_back(it.first);
    }
    bins_v.push_back(loweredge_to_bin.rbegin()->second->GetYMax());

    // for (auto b : bins_v) {
    //   std::cout << "bins_v: " << b << std::endl;
    // }


    TH1D *h1 = 0;
    // if (opt.Contains("e") || GetSumw2N() ) h1->Sumw2();

    int bin_counter = 1;

    h1 = new TH1D(name, GetTitle(), bins_v.size()-1, &bins_v[0]);

    if (GetSumw2N()) h1->Sumw2();

    for (auto it : loweredge_to_bin) {
      h1->SetBinContent(bin_counter, GetBinContent(it.second->GetBinNumber()));
      h1->SetBinError(bin_counter, GetBinError(it.second->GetBinNumber()));
      bin_counter++;
    }

    
    // const char *expectedName = 0;
    // Int_t inNbin;
    const TAxis* outAxis;
    // const TAxis* inAxis;
 
    // TString opt = option;
    // TString cut;
    // Int_t i1 = opt.Index("[");
    // if (i1>=0) {
    //    Int_t i2 = opt.Index("]");
    //    cut = opt(i1,i2-i1+1);
    // }
    // opt.ToLower();  //must be called after having parsed the cut name
    // bool originalRange = opt.Contains("o");
 
    // if ( onX )
    // {
    //    expectedName = "_px";
    //    inNbin = fYaxis.GetNbins();
    //    outAxis = GetXaxis();
    //    inAxis = GetYaxis();
    // }
    // else
    // {
       // expectedName = "_py";
       // inNbin = fXaxis.GetNbins();
       outAxis = GetYaxis();
       // inAxis = GetXaxis();
    // }
 
    // // outer axis cannot be outside original axis (this fixes ROOT-8781)
    // // and firstOutBin and lastOutBin cannot be both equal to zero
    // Int_t firstOutBin = std::max(outAxis->GetFirst(),1);
    // Int_t lastOutBin = std::min(outAxis->GetLast(),outAxis->GetNbins() ) ;
 
    // if ( lastbin < firstbin && inAxis->TestBit(TAxis::kAxisRange) ) {
    //    firstbin = inAxis->GetFirst();
    //    lastbin = inAxis->GetLast();
    //    // For special case of TAxis::SetRange, when first == 1 and last
    //    // = N and the range bit has been set, the TAxis will return 0
    //    // for both.
    //    if (firstbin == 0 && lastbin == 0)
    //    {
    //       firstbin = 1;
    //       lastbin = inAxis->GetNbins();
    //    }
    // }
    // if (firstbin < 0) firstbin = 0;
    // if (lastbin  < 0) lastbin  = inNbin + 1;
    // if (lastbin  > inNbin+1) lastbin  = inNbin + 1;
 
    // Create the projection histogram
    // char *pname = (char*)name;
    // if (name && strcmp(name,expectedName) == 0) {
    //    Int_t nch = strlen(GetName()) + 4;
    //    pname = new char[nch];
    //    snprintf(pname,nch,"%s%s",GetName(),name);
    // }


    // //check if histogram with identical name exist
    // // if compatible reset and re-use previous histogram
    // // (see https://savannah.cern.ch/bugs/?54340)
    // TObject *h1obj = gROOT->FindObject(pname);
    // if (h1obj && h1obj->InheritsFrom(TH1::Class())) {
    //    if (h1obj->IsA() != TH1D::Class() ) {
    //       Error("DoProjection","Histogram with name %s must be a TH1D and is a %s",name,h1obj->ClassName());
    //       return 0;
    //    }
    //    h1 = (TH1D*)h1obj;
    //    // reset the existing histogram and set always the new binning for the axis
    //    // This avoid problems when the histogram already exists and the histograms is rebinned or its range has changed
    //    // (see https://savannah.cern.ch/bugs/?94101 or https://savannah.cern.ch/bugs/?95808 )
    //    h1->Reset();
    //    const TArrayD *xbins = outAxis->GetXbins();
    //    if (xbins->fN == 0) {
    //       if ( originalRange )
    //          h1->SetBins(outAxis->GetNbins(),outAxis->GetXmin(),outAxis->GetXmax());
    //       else
    //          h1->SetBins(lastOutBin-firstOutBin+1,outAxis->GetBinLowEdge(firstOutBin),outAxis->GetBinUpEdge(lastOutBin));
    //    } else {
    //       // case variable bins
    //       if (originalRange )
    //          h1->SetBins(outAxis->GetNbins(),xbins->fArray);
    //       else
    //          h1->SetBins(lastOutBin-firstOutBin+1,&xbins->fArray[firstOutBin-1]);
    //    }
    // }
 
    // Int_t ncuts = 0;
    // if (opt.Contains("[")) {
    //    ((TH2 *)this)->GetPainter();
    //    if (fPainter) ncuts = fPainter->MakeCuts((char*)cut.Data());
    // }
 
    // if (!h1) {
    //    const TArrayD *bins = outAxis->GetXbins();
    //    if (bins->fN == 0) {
    //       if ( originalRange )
    //          h1 = new TH1D(pname,GetTitle(),outAxis->GetNbins(),outAxis->GetXmin(),outAxis->GetXmax());
    //       else
    //          h1 = new TH1D(pname,GetTitle(),lastOutBin-firstOutBin+1,
    //                        outAxis->GetBinLowEdge(firstOutBin),outAxis->GetBinUpEdge(lastOutBin));
    //    } else {
    //       // case variable bins
    //       if (originalRange )
    //          h1 = new TH1D(pname,GetTitle(),outAxis->GetNbins(),bins->fArray);
    //       else
    //          h1 = new TH1D(pname,GetTitle(),lastOutBin-firstOutBin+1,&bins->fArray[firstOutBin-1]);
    //    }
    //    if (opt.Contains("e") || GetSumw2N() ) h1->Sumw2();
    // }
    // if (pname != name)  delete [] pname;
 
    // Copy the axis attributes and the axis labels if needed.
    h1->GetXaxis()->ImportAttributes(outAxis);
    // THashList* labels=outAxis->GetLabels();
    // if (labels) {
    //    TIter iL(labels);
    //    TObjString* lb;
    //    Int_t i = 1;
    //    while ((lb=(TObjString*)iL())) {
    //       h1->GetXaxis()->SetBinLabel(i,lb->String().Data());
    //       i++;
    //    }
    // }
 
    h1->SetLineColor(this->GetLineColor());
    h1->SetFillColor(this->GetFillColor());
    h1->SetMarkerColor(this->GetMarkerColor());
    h1->SetMarkerStyle(this->GetMarkerStyle());
 
    // // Fill the projected histogram
    // Double_t cont,err2;
    // Double_t totcont = 0;
    // Bool_t  computeErrors = h1->GetSumw2N();
 
    // // implement filling of projected histogram
    // // outbin is bin number of outAxis (the projected axis). Loop is done on all bin of TH2 histograms
    // // inbin is the axis being integrated. Loop is done only on the selected bins
    // for ( Int_t outbin = 0; outbin <= outAxis->GetNbins() + 1;  ++outbin) {
    //    err2 = 0;
    //    cont = 0;
    //    if (outAxis->TestBit(TAxis::kAxisRange) && ( outbin < firstOutBin || outbin > lastOutBin )) continue;
 
    //    for (Int_t inbin = firstbin ; inbin <= lastbin ; ++inbin) {
    //       Int_t binx, biny;
    //       if (onX) { binx = outbin; biny=inbin; }
    //       else     { binx = inbin;  biny=outbin; }
 
    //       if (ncuts) {
    //          if (!fPainter->IsInside(binx,biny)) continue;
    //       }
    //       // sum bin content and error if needed
    //       cont  += GetBinContent(binx,biny);
    //       if (computeErrors) {
    //          Double_t exy = GetBinError(binx,biny);
    //          err2  += exy*exy;
    //       }
    //    }
    //    // find corresponding bin number in h1 for outbin
    //    Int_t binOut = h1->GetXaxis()->FindBin( outAxis->GetBinCenter(outbin) );
    //    h1->SetBinContent(binOut ,cont);
    //    if (computeErrors) h1->SetBinError(binOut,TMath::Sqrt(err2));
    //    // sum  all content
    //    totcont += cont;
    // }
 
    // // check if we can re-use the original statistics from  the previous histogram
    // bool reuseStats = false;
    // if ( ( GetStatOverflowsBehaviour() == false && firstbin == 1 && lastbin == inNbin     ) ||
    //      ( GetStatOverflowsBehaviour() == true  && firstbin == 0 && lastbin == inNbin + 1 ) )
    //    reuseStats = true;
    // else {
    //    // also if total content match we can re-use
    //    double eps = 1.E-12;
    //    if (IsA() == TH2F::Class() ) eps = 1.E-6;
    //    if (fTsumw != 0 && TMath::Abs( fTsumw - totcont) <  TMath::Abs(fTsumw) * eps)
    //       reuseStats = true;
    // }
    // if (ncuts) reuseStats = false;
    // // retrieve  the statistics and set in projected histogram if we can re-use it
    // bool reuseEntries = reuseStats;
    // // can re-use entries if underflow/overflow are included
    // reuseEntries &= (firstbin==0 && lastbin == inNbin+1);
    // if (reuseStats) {
    //    Double_t stats[kNstat];
    //    GetStats(stats);
    //    if (!onX) {  // case of projection on Y
    //       stats[2] = stats[4];
    //       stats[3] = stats[5];
    //    }
    //    h1->PutStats(stats);
    // }
    // else {
    //    // the statistics is automatically recalculated since it is reset by the call to SetBinContent
    //    // we just need to set the entries since they have not been correctly calculated during the projection
    //    // we can only set them to the effective entries
    //    h1->SetEntries( h1->GetEffectiveEntries() );
    // }
    // if (reuseEntries) {
    //    h1->SetEntries(fEntries);
    // }
    // else {
    //    // re-compute the entries
    //    // in case of error calculation (i.e. when Sumw2() is set)
    //    // use the effective entries for the entries
    //    // since this  is the only way to estimate them
    //    Double_t entries =  TMath::Floor( totcont + 0.5); // to avoid numerical rounding
    //    if (h1->GetSumw2N()) entries = h1->GetEffectiveEntries();
    //    h1->SetEntries( entries );
    // }
 
    
 
    return h1;

  }

}

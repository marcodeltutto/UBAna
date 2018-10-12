#ifndef __DATATYPES_UBTH2POLY_CXX__
#define __DATATYPES_UBTH2POLY_CXX__

#include "UBTH2Poly.h"

ClassImp(DataTypes::UBTH2Poly)

namespace DataTypes {

  UBTH2Poly& UBTH2Poly::operator=(const UBTH2Poly &h1)
  {
    Warning("operator=","Assignemet operator called, but lacks full implementation.");    
    if (this != &h1)  ((UBTH2Poly&)h1).Copy(*this);
    return *this;
  }

  void UBTH2Poly::SetNBinsX(Int_t n) {

    _n_bins_x = n;

  }

  Int_t UBTH2Poly::GetNBinsX() {

    return _n_bins_x;

  }



  UBTH2Poly* UBTH2Poly::GetCopyWithBinNumbers(const char *name) const {

    UBTH2Poly* h = (UBTH2Poly*) this->Clone(name);

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


  Bool_t UBTH2Poly::Add(const TH1 *h1, Double_t c1)
  {

     Int_t bin;
  
     TH2Poly *h1p = (TH2Poly *)h1;
  
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
           

     Int_t bi;
     // Int_t NOverflow = 9; // has to be hardcoded for older ROOT versions

     for (bin = 1; bin <= GetNumberOfBins(); bin++) {
        thisBin = (TH2PolyBin *)fBins->At(bin - 1);
        h1pBin  = (TH2PolyBin *)h1pBins->At(bin - 1);
        bi = thisBin->GetBinNumber() - 1;
        thisBin->SetContent(thisBin->GetContent() + c1 * h1pBin->GetContent());
        if (fSumw2.fN) {
           Double_t e1 = factor * h1p->GetBinError(bin);

           fSumw2.fArray[bi] += c1 * c1 * e1 * e1;
        }
     }
  
     // update statistics (do here to avoid changes by SetBinContent)
     if (resetStats)  {
        // statistics need to be reset in case coefficient are negative
        // ResetStats();
      std::cout << "kNstat = " << kNstat << std::endl;
        Double_t stats[kNstat] = {0};
        fTsumw = 0;
        fEntries = 1; // to force re-calculation of the statistics in TH1::GetStats
      std::cout << "Before GetStats" << std::endl;
        GetStats(stats);
      std::cout << "Before PutStats" << std::endl;
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

  void UBTH2Poly::GetStats(Double_t *stats) const
  {
     std::cout << "Start UBTH2Poly::GetStats" << std::endl;
    stats[0] = fTsumw;
    stats[1] = fTsumw2;
    stats[2] = fTsumwx;
    stats[3] = fTsumwx2;
    stats[4] = fTsumwy;
    stats[5] = fTsumwy2;
    stats[6] = fTsumwxy;
     std::cout << "End UBTH2Poly::GetStats" << std::endl;
  }

  void UBTH2Poly::PutStats(Double_t *stats)
  {
     std::cout << "Before TH1::PutStats" << std::endl;
     TH1::PutStats(stats);
     std::cout << "After TH1::PutStats" << std::endl;
     fTsumwy  = stats[4];
     fTsumwy2 = stats[5];
     fTsumwxy = stats[6];
  }


  Bool_t UBTH2Poly::Divide(const TH1 *h1)
  {

     Int_t bin;
  
     TH2Poly *h1p = (TH2Poly *)h1;
  
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
  
    
           

     Int_t bi;
     // Int_t NOverflow = 9; // has to be hardcoded for older ROOT versions

     for (bin = 1; bin <= GetNumberOfBins(); bin++) {
        thisBin = (TH2PolyBin *)fBins->At(bin - 1);
        h1pBin  = (TH2PolyBin *)h1pBins->At(bin - 1);

        bi = thisBin->GetBinNumber() - 1;

        Double_t c0 = thisBin->GetContent();
        Double_t c1 = h1pBin->GetContent();

        if (c1) thisBin->SetContent(c0 / c1);
        else thisBin->SetContent(0.0);

        if (fSumw2.fN) {
           if (c1 == 0) { fSumw2.fArray[bi] = 0; continue; }
           Double_t c1sq = c1 * c1;
           fSumw2.fArray[bi] = (GetBinError(bin) * GetBinError(bin) * c1sq + h1p->GetBinError(bin) * h1p->GetBinError(bin) * c0 * c0) / (c1sq * c1sq);
        }
     }
  
     ResetStats();
     return kTRUE;
  }




  void UBTH2Poly::Scale(Double_t c1, Option_t* option) {

    Bool_t normaliseWidth = kFALSE;
    TString opt = option; opt.ToLower();
    
    // store bin errors when scaling since cannot anymore be computed as sqrt(N)
    if (!opt.Contains("nosw2") && GetSumw2N() == 0) Sumw2();

    if (opt.Contains("width")) {
      normaliseWidth = kTRUE;
    }
    else {
      for( int i = 0; i < this->GetNumberOfBins(); i++ ) {
        this->SetBinContent(i+1, c1 * this->GetBinContent(i+1));
      }
      if (fSumw2.fN) {
        for(Int_t i = 0; i < this->GetNumberOfBins(); ++i) fSumw2.fArray[i] *= (c1 * c1); // update errors
      }
    }

    if (normaliseWidth) {

      TH2PolyBin *thisBin;
      for (Int_t bin = 1; bin <= GetNumberOfBins(); bin++) {
        thisBin = (TH2PolyBin *)fBins->At(bin - 1);

        Double_t w = thisBin->GetArea();
        SetBinContent(bin, c1 * GetBinContent(bin) / w);
        if (fSumw2.fN) {
          Double_t e1 = GetBinError(bin) / w;
          fSumw2.fArray[bin - 1] = c1 * c1 * e1 * e1;
        }
      }
    }

  }




  Double_t UBTH2Poly::Integral(Option_t* option) const
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

    return integral;
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
      h1->SetBinContent(bin_counter, RetrieveBinContent(it.second->GetBinNumber()));
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

#endif

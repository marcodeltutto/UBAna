#ifndef __DATATYPES_UBTH2POLY_CXX__
#define __DATATYPES_UBTH2POLY_CXX__

#include "UBTH2Poly.h"

ClassImp(DataTypes::UBTH2Poly)

namespace DataTypes {


  UBTH2Poly* UBTH2Poly::GetCopyWithBinNumbers(const char *name) const {

    UBTH2Poly* h = (UBTH2Poly*) this->Clone(name);

    TH2PolyBin *thisBin;

    for (Int_t bin = 1; bin <= GetNumberOfBins(); bin++) {
      thisBin = (TH2PolyBin *)fBins->At(bin - 1);
      h->SetBinContent(thisBin->GetBinNumber(), thisBin->GetBinNumber());
    }
    
    return h;

  }



  TH1D* UBTH2Poly::ProjectionY(const char *name, Int_t firstxbin/*, Int_t lastxbin, Option_t *option*/) const
  {

    // fXaxis.GetXmin()

    std::vector<double> boundaries;
    boundaries.reserve(GetNumberOfBins() * 2);
    TH2PolyBin *thisBin;

    for (Int_t bin = 1; bin <= GetNumberOfBins(); bin++) {
      thisBin = (TH2PolyBin *)fBins->At(bin - 1);
      if (thisBin->GetYMin() != fYaxis.GetXmin()) continue;
      boundaries.push_back(thisBin->GetXMin());
    }
    boundaries.push_back(fXaxis.GetXmax());

    for (auto b : boundaries) {
      std::cout << "boundary: " << b << std::endl;
    }

    Int_t index = (firstxbin - 1) * 2;
    double boundary_low = boundaries.at(index);
    double boundary_up  = boundaries.at(index + 1);

    std::map<double, TH2PolyBin *> loweredge_to_bin; // automatically sorts

    for (Int_t bin = 1; bin <= GetNumberOfBins(); bin++) {
      thisBin = (TH2PolyBin *)fBins->At(bin - 1);
      if (thisBin->GetXMin() != boundary_low) continue;
      if (thisBin->GetXMax() != boundary_up) continue;
      loweredge_to_bin[thisBin->GetYMin()] = thisBin;
    }


    TH1D *h1 = 0;

    // if (opt.Contains("e") || GetSumw2N() ) h1->Sumw2();
    if (GetSumw2N()) h1->Sumw2();

    int bin_counter = 1;

    h1 = new TH1D(name, GetTitle(), loweredge_to_bin.size(), fYaxis.GetXmin(), fYaxis.GetXmax());
    for (auto it : loweredge_to_bin) {
      h1->SetBinContent(bin_counter, RetrieveBinContent(it.second->GetBinNumber()));
      h1->SetBinError(bin_counter, GetBinError(it.second->GetBinNumber()));
      bin_counter++;
    }

    
    const char *expectedName = 0;
    Int_t inNbin;
    const TAxis* outAxis;
    const TAxis* inAxis;
 
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
       expectedName = "_py";
       inNbin = fXaxis.GetNbins();
       outAxis = GetYaxis();
       inAxis = GetXaxis();
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

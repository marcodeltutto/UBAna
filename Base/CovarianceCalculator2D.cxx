#ifndef __BASE_COVARIANCECALCULATOR2D_CXX__
#define __BASE_COVARIANCECALCULATOR2D_CXX__

#include "CovarianceCalculator2D.h"

namespace Base {
  

  void CovarianceCalculator2D::SetBootstrap(BootstrapTH1D bs)
  {

    _bs = bs;
    
  }

  void CovarianceCalculator2D::SetPrefix(std::string prefix) 
  {
    _prefix = prefix;
  }

  void CovarianceCalculator2D::GetCovarianceMatrix(TH2D &h)
  {
    h = _M_h;
  }

  void CovarianceCalculator2D::AddExtraDiagonalUncertainty(double value) 
  {
    _extra_relative_uncertainty = value;
  }

  void CovarianceCalculator2D::CalculateCovarianceMatrix() 
  {

    _M.Clear();
    _M.ResizeTo(_bs.GetNbinsX(), _bs.GetNbinsX());

    _M_frac.Clear();
    _M_frac.ResizeTo(_bs.GetNbinsX(), _bs.GetNbinsX());

    _RHO.Clear();
    _RHO.ResizeTo(_bs.GetNbinsX(), _bs.GetNbinsX());

    for (int i = 0; i < _bs.GetNbinsX(); i++) {
      for (int j = 0; j < _bs.GetNbinsX(); j++) {
       _M[i][j] = 0.;
       _M_frac[i][j] = 0.;
       _RHO[i][j] = 0.;
      }
    }


    _bs.ResetIterator();
    std::cout << _name << " Calculating Cov Matrix with " << _bs.GetNUniverses() << " universes. Nominal histogram is excluded." << std::endl;

    double number_of_universes = (double)_bs.GetNUniverses() - 1;

    for (int i = 0; i < _bs.GetNbinsX(); i++) {

      for (int j = 0; j < _bs.GetNbinsX(); j++) {

        // Nominal cross section for bin i and j 
        double N_i_cv = _bs.GetNominal().GetBinContent(i+1);
        double N_j_cv = _bs.GetNominal().GetBinContent(j+1);

        //if (_verbose) std::cout << "Nominal cross section in i " << i << ": " << N_i_cv << " and j " << j << ": " << N_j_cv << std::endl;

        _bs.ResetIterator();

        for (int s = 0; s < number_of_universes; s++) {

          std::string uni_name;
          TH1D uni_histo;
          _bs.NextUniverse(uni_name, uni_histo);

          //std::cout << "************************()()()()() this is universe " << uni_name << std::endl;

          double N_i_s = uni_histo.GetBinContent(i+1);
          double N_j_s = uni_histo.GetBinContent(j+1);
          

          _M[i][j] += (N_i_s - N_i_cv) * (N_j_s - N_j_cv) / number_of_universes;

          //std::cout << "N_i_s = " << N_i_s << ", N_j_s = " << N_j_s << std::endl;          

        } // universe loop

        //_M_frac[i][j] += (N_i_s - N_i_cv) * (N_j_s - N_j_cv) / (number_of_universes * N_i_cv * N_j_cv);
        _M_frac[i][j] = _M[i][j] / (N_i_cv * N_j_cv);

        if (i == j) {
          _M_frac[i][j] += _extra_relative_uncertainty * _extra_relative_uncertainty;
          _M[i][j] += (N_i_cv * _extra_relative_uncertainty) * (N_j_cv * _extra_relative_uncertainty);
        }

        //if (_verbose) std::cout << "_M[" << i << "][" << j << "] = " << _M[i][j] << std::endl;
        //if (_verbose) std::cout << "_M_frac[" << i << "][" << j << "] = " << _M_frac[i][j] << std::endl;

      } // bin j loop
    } // bin i loop



    for (int i = 0; i < _bs.GetNbinsX(); i++) {

      for (int j = 0; j < _bs.GetNbinsX(); j++) {

        _RHO[i][j] += _M[i][j] / (std::sqrt(_M[i][i]) * std::sqrt(_M[j][j]));

        if (_RHO[i][j] < -1 || _RHO[i][j] > 1) {
          std::cout << "WARNING!!! Corraltion Matrix rho is smaller than -1 or greater than +1, value: " << _RHO[i][j] << std::endl;
        }

      } // bin i loop
    } // bin i loop


    if (_verbose) {
      std::cout << _name << "Printing Covariance Matrix M = " << std::endl;
      _M.Print();
      std::cout << _name << "Printing Fractional Covariance Matrix M = " << std::endl;
      _M_frac.Print();
    }

  }


  void CovarianceCalculator2D::PlotMatrices()
  {

    TH2D * cov_matrix_histo = new TH2D("cov_matrix_histo", "", _bs.GetNbinsX(), 0, _bs.GetNbinsX(), _bs.GetNbinsX(), 0, _bs.GetNbinsX());
    TH2D * frac_cov_matrix_histo = new TH2D("frac_cov_matrix_histo", "", _bs.GetNbinsX(), 0, _bs.GetNbinsX(), _bs.GetNbinsX(), 0, _bs.GetNbinsX());
    TH2D * corr_matrix_histo = new TH2D("corr_matrix_histo", "", _bs.GetNbinsX(), 0, _bs.GetNbinsX(), _bs.GetNbinsX(), 0, _bs.GetNbinsX());

    for (int i = 0; i < _bs.GetNbinsX(); i++) { 
      for (int j = 0; j < _bs.GetNbinsX(); j++) {
        cov_matrix_histo->SetBinContent(i+1, j+1, _M[i][j]);
        frac_cov_matrix_histo->SetBinContent(i+1, j+1, _M_frac[i][j]);
        corr_matrix_histo->SetBinContent(i+1, j+1, _RHO[i][j]);
      }
    } 

    

    gStyle->SetPalette(kDeepSea);

    gStyle->SetPaintTextFormat("4.5f");

    TString name;

    TCanvas * cov_matrix = new TCanvas;
    cov_matrix_histo->SetMarkerColor(kWhite);
    cov_matrix_histo->SetMarkerSize(1.6);
    cov_matrix_histo->GetXaxis()->CenterTitle();
    cov_matrix_histo->GetYaxis()->CenterTitle();
    cov_matrix_histo->GetXaxis()->SetTitle("Bin i");
    cov_matrix_histo->GetYaxis()->SetTitle("Bin j");

    cov_matrix_histo->Draw("colz TEXT");
    cov_matrix->SetRightMargin(0.13);
    name = _prefix + "_cov_matrix_2d";
    cov_matrix->SaveAs(name + ".pdf");
    cov_matrix->SaveAs(name + ".C");

    TCanvas * frac_cov_matrix = new TCanvas;
    frac_cov_matrix_histo->SetMarkerColor(kWhite);
    frac_cov_matrix_histo->SetMarkerSize(1.6);
    frac_cov_matrix_histo->GetXaxis()->CenterTitle();
    frac_cov_matrix_histo->GetYaxis()->CenterTitle();
    frac_cov_matrix_histo->GetXaxis()->SetTitle("Bin i");
    frac_cov_matrix_histo->GetYaxis()->SetTitle("Bin j");

    frac_cov_matrix_histo->Draw("colz TEXT");
    frac_cov_matrix->SetRightMargin(0.13);
    name = _prefix + "_cov_frac_matrix_2d";
    frac_cov_matrix->SaveAs(name + ".pdf");
    frac_cov_matrix->SaveAs(name + ".C");

    gStyle->SetPaintTextFormat("4.2f");

    TCanvas * corr_matrix = new TCanvas;
    corr_matrix_histo->SetMarkerColor(kWhite);
    corr_matrix_histo->SetMarkerSize(1.6);
    corr_matrix_histo->GetXaxis()->CenterTitle();
    corr_matrix_histo->GetYaxis()->CenterTitle();
    corr_matrix_histo->GetXaxis()->SetTitle("Bin i");
    corr_matrix_histo->GetYaxis()->SetTitle("Bin j");

    corr_matrix_histo->Draw("colz TEXT");
    corr_matrix->SetRightMargin(0.13);
    name = _prefix + "_corr_matrix_2d";
    corr_matrix->SaveAs(name + ".pdf");
    corr_matrix->SaveAs(name + ".C");

    gStyle->SetPalette(kRainBow);



    _M_h = *cov_matrix_histo;
    _M_frac_h = *frac_cov_matrix_histo;
    _RHO_h = *corr_matrix_histo;

  }
}

#endif

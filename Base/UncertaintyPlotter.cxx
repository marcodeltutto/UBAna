#ifndef __BASE_UNCERTAINTYPLOTTER_CXX__
#define __BASE_UNCERTAINTYPLOTTER_CXX__

#include "UncertaintyPlotter.h"

namespace Base {

  void UncertaintyPlotter::Reset()
  {
    _cov_names.clear();
    _frac_cov_v.clear();
  }

  void UncertaintyPlotter::AddFracCovarianceMatrix(std::string name, TH2D cov)
  {
    _cov_names.push_back(name);
    _frac_cov_v.push_back(cov);
  }

  void UncertaintyPlotter::MakePlot(std::string file_name)
  {
    

    std::vector<TH1D> histos;
    histos.resize(_cov_names.size());

    for (size_t i = 0; i < _cov_names.size(); i++)
    {
      histos.at(i) = * (TH1D*)_xsec_1d.Clone((_cov_names.at(i) + "_h").c_str());
      histos.at(i).Reset();

      for (int j = 1; j <= _xsec_1d.GetNbinsX(); j++)
      {
        histos.at(i).SetBinContent(j, std::sqrt(_frac_cov_v.at(i).GetBinContent(j, j)) * 100.);
      }
    }


    TCanvas * c = new TCanvas();

    c->SetBottomMargin(0.12);

    TLegend *l = new TLegend(0.3825215,0.65,0.7363897,0.8547368,NULL,"brNDC");
    l->SetFillColor(0);
    l->SetFillStyle(0);
    l->SetTextSize(0.03578947);


    for (size_t i = 0; i < _cov_names.size(); i++) 
    {
      if (i == 0) {
        histos.at(i).SetMinimum(0);
        histos.at(i).SetMaximum(80);
      }
      histos.at(i).SetLineColor(_line_colors.at(i));
      histos.at(i).GetXaxis()->SetTitle(_xaxis_title.c_str());
      histos.at(i).GetYaxis()->SetTitle("Relative Uncertainty [%]");
      histos.at(i).Draw("same");

      l->AddEntry(&histos.at(i), _cov_names.at(i).c_str(), "l");
    }

    l->Draw();

    PlottingTools::DrawSimulationXSec();

    c->SaveAs((file_name + ".pdf").c_str());
    c->SaveAs((file_name + ".C").c_str());

  }


}

#endif

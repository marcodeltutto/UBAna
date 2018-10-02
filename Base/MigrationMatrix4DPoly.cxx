#ifndef __BASE_MIGRATIONMATRIX4DPOLY_CXX__
#define __BASE_MIGRATIONMATRIX4DPOLY_CXX__

#include "MigrationMatrix4DPoly.h"

namespace Base {

  void MigrationMatrix4DPoly::SetOutputFileName(std::string name) 
  {
    _f_out.open(name, std::ios::out | std::ios::trunc);
  }

  void MigrationMatrix4DPoly::SetOutDir(std::string dir)
  {
    std::string out_folder_base = std::getenv("MYSW_OUTDIR");

    _outdir = out_folder_base + dir;

    auto now = std::time(nullptr);
    char buf[sizeof("YYYY-MM-DD_HH-MM-SS")];
    std::string timestamp = std::string(buf,buf + std::strftime(buf,sizeof(buf),"%F_%H-%M-%S",std::gmtime(&now)));

    _folder = _outdir + "_" + timestamp + "/";

    system(("mkdir -p " + _folder).c_str());

  }

  void MigrationMatrix4DPoly::SetTTree(TTree *t)
  {
    _tree = t;
  }

  void MigrationMatrix4DPoly::SetRecoPerTrueHistos(std::vector<UBTH2Poly*> h_reco_per_true)
  {
    _h_reco_per_true = h_reco_per_true;
  }

  void MigrationMatrix4DPoly::SetRecoPerTrueVectors(std::vector<std::vector<double>> v_reco_per_true)
  {
    _v_reco_per_true = v_reco_per_true;
  }

  void MigrationMatrix4DPoly::UseWeights(std::string weight_name, std::string weight_type)
  {
    _use_weights = true;
    _weight_name = weight_name;
    _weight_type = weight_type;
  }

  void MigrationMatrix4DPoly::SetBins(int n_bins)
  {

    // for (int i = 0; i < n_var1_bins; i++) 
    // {
    //   _var1_bins.push_back(std::make_pair(var1_b[i], var1_b[i+1]));
    // }

    // for (int i = 0; i < n_var2_bins; i++) 
    // {
    //   _var2_bins.push_back(std::make_pair(var2_b[i], var2_b[i+1]));
    // }

    // // std::cout << _prefix << "Number of var1 bins: " << _var1_bins.size() << std::endl;
    // // std::cout << _prefix << "Number of var2 bins: " << _var2_bins.size() << std::endl;

    // _reco_per_true = new TH2D("reco_per_true", "reco_per_true", n_var1_bins, var1_b, n_var2_bins, var2_b);
    _n_bins = n_bins;
    
  }


  TMatrix MigrationMatrix4DPoly::CalculateMigrationMatrix() 
  {
    
    // Resize the smearing matrix
    _S.Clear(); _S.ResizeTo(_n_bins, _n_bins);

    for (int m = 0; m < _n_bins; m++) {

      if (_h_reco_per_true.size()) {
        // Case 1, we have set a set of UBTH2Poly per every true bin
        _reco_per_true = (UBTH2Poly*) _h_reco_per_true[m]->Clone("_reco_per_true");
      } else {
        // Case 2, we have set a set a vector of lenght _n_bins (reco bins) per every true bin
        _reco_per_true = (UBTH2Poly*) _th2poly_template->Clone("_reco_per_true");
        for (int i = 0; i < _n_bins; i++) {
          _reco_per_true->SetBinContent(i+1, _v_reco_per_true[m][i]);
        }
      }


      // for (int i = 0; i < _n_bins; i++) {
      //   LOG_CRITICAL() << "before scale - bin " << i+1 << ", _reco_per_true is " << _reco_per_true->GetBinContent(i+1) << std::endl;
      // }

      // Normalize to get a probability
      _reco_per_true->Scale(1./_reco_per_true->Integral());

      LOG_DEBUG() << "\tIntegral is " << _reco_per_true->Integral() << std::endl;

      bool make_plot = false;
      if (_reco_per_true->Integral() != 0) make_plot = true;

      // Set values to matrix
      TCanvas *c = new TCanvas();
       _reco_per_true->Draw("colz text");
      for (int i = 0; i < _n_bins; i++) {

        double value = _reco_per_true->GetBinContent(i+1);
        // LOG_CRITICAL() << "after scale - bin " << i+1 << ", _reco_per_true is " << _reco_per_true->GetBinContent(i+1) << std::endl;

        if (std::isnan(value))
          value = 0.;
  
        _S[i][m] = value;
        
       }

      // Saving the plot
      if (make_plot && _do_make_plots) {  

        // Saving the plot
        std::stringstream sstm;
        sstm << "True Bin " << m;
        std::string str = sstm.str();
        _reco_per_true->SetTitle(str.c_str());
        _reco_per_true->GetXaxis()->SetTitle("cos(#theta_{#mu}) [Reco Bin i]");
        _reco_per_true->GetYaxis()->SetTitle("p_{#mu} (GeV) [Reco Bin j]");
        _reco_per_true->GetYaxis()->SetTitleOffset(0.8);
  
        sstm.str("");
        sstm << "smearing_matrix_true_" << m;

        TString name = _folder + sstm.str();
        c->SaveAs(name + ".pdf");
        c->SaveAs(name + ".C","C");
      }
    }


    // if(_verbose) {
    //   for (int i = 0; i < _n_bins; i++) {
    //     for (int m = 0; m < _n_bins; m++) {
    //       std::cout << "(" << i << ", " << m << ") => " << _S[i][m] << std::endl;
    //     }
    //   }
    // }


    return _S;

  }

  void MigrationMatrix4DPoly::PlotMatrix()
  {

    TH2D *h_sm = new TH2D("h_sm", "", _n_bins, 0, _n_bins, _n_bins, 0, _n_bins);

    for (size_t m = 0; m < _n_bins; m++) {  // true
      for (size_t i = 0; i < _n_bins; i++) {  // reco
        
        h_sm->SetBinContent(m +1, i +1, _S[i][m]);

      }
    }

    std::vector<std::string> bin_labels;

    for (size_t i = 0; i < _n_bins; i++) {  

      std::stringstream sstm;
      sstm << i + 1;
      std::string str = sstm.str();

      bin_labels.emplace_back(str);

    }

    for (int i = 0; i < _n_bins; i++) {
      h_sm->GetXaxis()->SetBinLabel(i+1, bin_labels.at(i).c_str());
      h_sm->GetYaxis()->SetBinLabel(i+1, bin_labels.at(i).c_str());
    }

    // std::vector<TLine*> lines;

    // for (size_t i = 1; i < _var2_bins.size(); i++) {
    //   TLine *line = new TLine(_var1_bins.size() * i, 0, _var1_bins.size() * i, n_bins);
    //   line->SetLineColor(kRed);
    //   line->SetLineWidth(2);
    //   lines.emplace_back(line);
    // }

    // for (size_t i = 1; i < _var2_bins.size(); i++) {
    //   TLine *line = new TLine(0, _var1_bins.size() * i, n_bins, _var1_bins.size() * i);
    //   line->SetLineColor(kRed);
    //   line->SetLineWidth(2);
    //   lines.emplace_back(line);
    // }


    TCanvas *c_sm = new TCanvas();
    h_sm->Draw("colz");
 
    // for (auto l : lines)
    //  l->Draw();


    TString name = _folder + "full_migration_matrix_4d_poly";
    c_sm->SaveAs(name + ".pdf");
    c_sm->SaveAs(name + ".C","C");

  }






  void MigrationMatrix4DPoly::PrintSmearingMatrixLatex()
  {

    if (!_f_out.is_open()) {
      LOG_WARNING() << "File not opened." << std::endl;
      return;
    }

    _f_out << "\\begin{equation}" << std::endl;
    _f_out << "S_{ij} =" << std::endl;
    _f_out << "\\begin{bmatrix}" << std::endl;

    for (size_t m = 0; m < _n_bins; m++) {
      for (size_t i = 0; i < _n_bins; i++) {

        _f_out << _S[m][i] << "  &  ";

      }

      _f_out << " \\\\" << std::endl;
    }

    _f_out << "\\end{bmatrix}" << std::endl;
    _f_out << "\\end{equation}" << std::endl << std::endl;

  }
}

#endif

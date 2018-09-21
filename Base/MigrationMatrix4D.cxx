#ifndef __BASE_MIGRATIONMATRIX4D_CXX__
#define __BASE_MIGRATIONMATRIX4D_CXX__

#include "MigrationMatrix4D.h"

namespace Base {

  void MigrationMatrix4D::SetOutputFileName(std::string name) 
  {
    _f_out.open(name, std::ios::out | std::ios::trunc);
  }

  void MigrationMatrix4D::SetOutDir(std::string dir)
  {
    std::string out_folder_base = std::getenv("MYSW_OUTDIR");

    _outdir = out_folder_base + dir;

    auto now = std::time(nullptr);
    char buf[sizeof("YYYY-MM-DD_HH-MM-SS")];
    std::string timestamp = std::string(buf,buf + std::strftime(buf,sizeof(buf),"%F_%H-%M-%S",std::gmtime(&now)));

    _folder = _outdir + "_" + timestamp + "/";

    system(("mkdir " + _folder).c_str());

  }

  void MigrationMatrix4D::SetTTree(TTree *t)
  {
    _tree = t;
  }

  void MigrationMatrix4D::SetRecoPerTrueHistos(std::vector<std::vector<TH2D*>> h_reco_per_true)
  {
    _h_reco_per_true = h_reco_per_true;
  }

  void MigrationMatrix4D::UseWeights(std::string weight_name, std::string weight_type)
  {
    _use_weights = true;
    _weight_name = weight_name;
    _weight_type = weight_type;
  }

  void MigrationMatrix4D::SetBins(const double *var1_b, int n_var1_bins, const double *var2_b, int n_var2_bins)
  {

    for (int i = 0; i < n_var1_bins; i++) 
    {
      _var1_bins.push_back(std::make_pair(var1_b[i], var1_b[i+1]));
    }

    for (int i = 0; i < n_var2_bins; i++) 
    {
      _var2_bins.push_back(std::make_pair(var2_b[i], var2_b[i+1]));
    }

    // std::cout << _prefix << "Number of var1 bins: " << _var1_bins.size() << std::endl;
    // std::cout << _prefix << "Number of var2 bins: " << _var2_bins.size() << std::endl;

    _reco_per_true = new TH2D("reco_per_true", "reco_per_true", n_var1_bins, var1_b, n_var2_bins, var2_b);
    
  }


  Mat4D MigrationMatrix4D::CalculateMigrationMatrix() 
  {
    
    // Resize the smearing matrix
    _S.resize( _var1_bins.size(), 
              std::vector<std::vector<std::vector<double>>> (_var2_bins.size(),
                                                             std::vector<std::vector<double>>(_var1_bins.size(),
                                                                                             std::vector<double> (_var2_bins.size(), 0.
                                                                                                                 )
                                                                                            )
                                                            )
              );

    int counter = 0;

    for (size_t i = 0; i < _var1_bins.size(); i++) {
      for (size_t j = 0; j < _var2_bins.size(); j++) {
        for (size_t m = 0; m < _var1_bins.size(); m++) {
          for (size_t n = 0; n < _var2_bins.size(); n++) { 
            if(_verbose) std::cout << "(" << i << ", " << j << ", " << m << ", " << n << ") => " << _S[i][j][m][n] << std::endl;
            counter++;
          }
        }
      }
    }

    // std::cout << _prefix << "Total migration matrix entries: " << counter << std::endl;


    // True bin m, n
    //int m = 0, n = 0;

    for (size_t m = 0; m < _var1_bins.size(); m++) {
      for (size_t n = 0; n < _var2_bins.size(); n++) {

        // std::cout << _prefix << "m = " << m << ", n = " << n << std::endl;

        // auto v1_bin = _var1_bins.at(m);
        // auto v2_bin = _var2_bins.at(n);

        // std::cout << "Done 1" << std::endl;

        // if(_verbose) std::cout << _prefix << "b1: " << v1_bin.first << " - " << v1_bin.second << std::endl;
        // if(_verbose) std::cout << _prefix << "b2: " << v2_bin.first << " - " << v2_bin.second << std::endl;


        _reco_per_true = (TH2D*) _h_reco_per_true[m][n]->Clone("_reco_per_true");


        // Normalize to get a probability
        _reco_per_true->Scale(1./_reco_per_true->Integral());

        // Set values to matrix
        TCanvas *c = new TCanvas();
        _reco_per_true->Draw("colz text");
        for (size_t i = 0; i < _var1_bins.size(); i++) {
          for (size_t j = 0; j < _var2_bins.size(); j++) {
            if(_verbose) std::cout << "(" << i << ", " << j << ")" << _reco_per_true->GetBinContent(i+1, j+1) << std::endl;

            double value = _reco_per_true->GetBinContent(i+1, j+1);
            if (std::isnan(value))
              value = 0.;
  
            _S[i][j][m][n] = value;
          }
        }

        // Saving the plot
        std::stringstream sstm;
        sstm << "True Bin (" << m << ", " << n << ")";
        std::string str = sstm.str();
        _reco_per_true->SetTitle(str.c_str());
        _reco_per_true->GetXaxis()->SetTitle("cos(#theta_{#mu}) [Reco Bin i]");
        _reco_per_true->GetYaxis()->SetTitle("p_{#mu} (GeV) [Reco Bin j]");
        _reco_per_true->GetYaxis()->SetTitleOffset(0.8);

        sstm.str("");
        sstm << "smearing_matrix_true_" << m << "_" << n;

        TString name = _folder + sstm.str();
        c->SaveAs(name + ".pdf");
        c->SaveAs(name + ".C","C");

      }
    }


    if(_verbose) {
      for (size_t i = 0; i < _var1_bins.size(); i++) {
        for (size_t j = 0; j < _var2_bins.size(); j++) {
          for (size_t m = 0; m < _var1_bins.size(); m++) {
            for (size_t n = 0; n < _var2_bins.size(); n++) { 
              std::cout << "(" << i << ", " << j << ", " << m << ", " << n << ") => " << _S[i][j][m][n] << std::endl;
            }
          }
        }
      }
    }

    return _S;

  }

  void MigrationMatrix4D::PlotMatrix()
  {

    int n_bins = _var1_bins.size() * _var2_bins.size();
    TH2D *h_sm = new TH2D("h_sm", "", n_bins, 0, n_bins, n_bins, 0, n_bins);


    for (size_t n = 0; n < _var2_bins.size(); n++) {   // pmu true
      for (size_t m = 0; m < _var1_bins.size(); m++) {  // theta true
        for (size_t j = 0; j < _var2_bins.size(); j++) {  // pmu reco
          for (size_t i = 0; i < _var1_bins.size(); i++) {  // theta reco
        
            int reco_bin = i + j * _var1_bins.size() + 1;
            int true_bin = m + n * _var1_bins.size() + 1;
            h_sm->SetBinContent(reco_bin, true_bin, _S[i][j][m][n]);
            if(_verbose) std::cout << "(i, j, m, n) = (" << i << ", " << j << ", " << m << ", " << n << "   reco_bin: " << reco_bin << ", true_bin: " << true_bin << ", S: " << _S[i][j][m][n] << std::endl;

          }
        }
      }
    }

    std::vector<std::string> bin_labels;

    for (size_t j = 0; j < _var2_bins.size(); j++) {  
      for (size_t i = 0; i < _var1_bins.size(); i++) {  

        //int bin = i + j * _var1_bins.size() + 1;

        std::stringstream sstm;
        sstm << i;
        std::string str = sstm.str();

        bin_labels.emplace_back(str);

      }
    }

    for (int i = 0; i < n_bins; i++) {
      h_sm->GetXaxis()->SetBinLabel(i+1, bin_labels.at(i).c_str());
      h_sm->GetYaxis()->SetBinLabel(i+1, bin_labels.at(i).c_str());
    }

    std::vector<TLine*> lines;

    for (size_t i = 1; i < _var2_bins.size(); i++) {
      TLine *line = new TLine(_var1_bins.size() * i, 0, _var1_bins.size() * i, n_bins);
      line->SetLineColor(kRed);
      line->SetLineWidth(2);
      lines.emplace_back(line);
    }

    for (size_t i = 1; i < _var2_bins.size(); i++) {
      TLine *line = new TLine(0, _var1_bins.size() * i, n_bins, _var1_bins.size() * i);
      line->SetLineColor(kRed);
      line->SetLineWidth(2);
      lines.emplace_back(line);
    }


    TCanvas *c_sm = new TCanvas();
    h_sm->Draw("colz");
 
    for (auto l : lines)
     l->Draw();


/*
    // Other axis
    gPad->Update();
    Double_t xmin = gPad->GetUxmin();
    Double_t ymin = 0;
    Double_t xmax = gPad->GetUxmax();
    Double_t ymax = 5;

    TGaxis *axis = new TGaxis(gPad->GetUxmin(),gPad->GetUymin()-1,gPad->GetUxmax(),gPad->GetUymin()-1,ymin,ymax,506,"+L");
    axis->SetLineColor(kRed+1);
    axis->SetLabelColor(kRed+1);
    axis->SetTextFont(42);
    axis->SetLabelSize(.04);
    axis->SetLabelOffset(.005);


    axis->Draw();
    */


    TString name = _folder + "full_migration_matrix_4d";
    c_sm->SaveAs(name + ".pdf");
    c_sm->SaveAs(name + ".C","C");

  }


  void MigrationMatrix4D::PrintSmearingMatrixLatex()
  {

    for (size_t m = 0; m < _var1_bins.size(); m++) {
      for (size_t n = 0; n < _var2_bins.size(); n++) {
        this->PrintSmearingMatrixLatex(m, n);
      }
    }

  }



  void MigrationMatrix4D::PrintSmearingMatrixLatex(int true_m, int true_n)
  {


    if (!_f_out.is_open()) {
      std::cout << "File not opened." << std::endl;
      return;
    }

    _f_out << "\\begin{equation}" << std::endl;
    _f_out << "S_{ij" << true_m << true_n << "} =" << std::endl;
    _f_out << "\\begin{bmatrix}" << std::endl;

    for (size_t i = 0; i < _var1_bins.size(); i++) {
      for (size_t j = 0; j < _var2_bins.size(); j++) {

        _f_out << _S[i][j][true_m][true_n] << "  &  ";

      }

      _f_out << " \\\\" << std::endl;
    }

    _f_out << "\\end{bmatrix}" << std::endl;
    _f_out << "\\end{equation}" << std::endl << std::endl;

  }
}

#endif

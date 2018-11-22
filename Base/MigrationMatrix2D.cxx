#ifndef __BASE_MIGRATIONMATRIX2D_CXX__
#define __BASE_MIGRATIONMATRIX2D_CXX__

#include "MigrationMatrix2D.h"

namespace Base {

	void MigrationMatrix2D::SetOutputFileName(std::string name) 
  {
    if (_f_out.is_open()) {
      _f_out.close();
    }
    _f_out.open(_folder+name, std::ios::out | std::ios::trunc);
  }

  void MigrationMatrix2D::SetOutDir(std::string dir)
  {

    std::string out_folder_base = std::getenv("MYSW_OUTDIR");

    _outdir = out_folder_base + dir;

    auto now = std::time(nullptr);
    char buf[sizeof("YYYY-MM-DD_HH-MM-SS")];
    std::string timestamp = std::string(buf,buf + std::strftime(buf,sizeof(buf),"%F_%H-%M-%S",std::gmtime(&now)));

    _folder = _outdir + "_" + timestamp + "/";

    system(("mkdir " + _folder).c_str());

  }

  void MigrationMatrix2D::SetTrueRecoHistogram(TH2D *h)
  {
    _h_true_reco_mom = h;
  }

  void MigrationMatrix2D::SetNBins(int n_var1_bins, int n_var2_bins)
  {

     _n = n_var1_bins;
     _m = n_var2_bins;
    
  }


  TMatrix MigrationMatrix2D::CalculateMigrationMatrix() 
  {
   
    // n x m matrix
    // n = number of rows
    // m = number of columns


    //std::vector<double> data_v;
    //data_v.resize(_n * _m);

    //TMatrix S;
    _S.Clear();
    _S.ResizeTo(_n + 1, _m + 1);

    // this->set_verbosity(Base::msg::kDEBUG);

    for (int j = 0; j < _m + 2; j++) {    // True bin

      int true_idx = j-1;
      if (j == 0)    true_idx = _m;
      if (j == _m+1) true_idx = _m;

      LOG_DEBUG() << "\tThis is true bin " << j << " with true index " << true_idx << std::endl;

      std::vector<double> p_v;
      p_v.resize(_n + 2);

      double sum = 0;

      for (int i = 0; i < _n + 2; i++) {      // Reco bin

        LOG_DEBUG() << "This is reco bin " << i << std::endl;

        p_v.at(i) = _h_true_reco_mom->GetBinContent(j, i);
        sum += p_v.at(i);

        LOG_DEBUG() << "\tValue is " << p_v.at(i) << std::endl;


      } // reco bin

      LOG_DEBUG() << "\t>>> Sum is " << sum << std::endl;

      double tot_prob = 0;

      for (int i = 1; i < _n + 1; i++) {

        if (sum == 0 || std::isnan(sum))
          p_v.at(i) = 0;
        else
          p_v.at(i) /= sum;

        LOG_DEBUG() << "\t\tProbability at " << i << " is " << p_v.at(i) << std::endl;
        tot_prob += p_v.at(i);

        _S[i - 1][true_idx] += p_v.at(i);
      }
      // Add over/under-flow
      _S[_n][true_idx] = p_v.at(0) / sum + p_v.at(_n + 1) / sum;

      LOG_DEBUG() << "\t\t> Total Probability is " << tot_prob << std::endl;

    } // true bin
    

    LOG_DEBUG() << _name << "Migration Matrix: " << std::endl;
    if(_verbose) _S.Print();

    return _S;

  }

  void MigrationMatrix2D::PlotMatrix()
  {

    int bins_x = _m + 1;
    int bins_y = _n + 1;

    // Do not show overlflow for cos(theta) (they are zero)
    std::size_t found = _outdir.find("trkcostheta");
    if (found != std::string::npos) {
      std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
      bins_x = _m;
      bins_y = _n;
    } 

    TH2D * smearing_matrix_histo = new TH2D("smearing_matrix_histo", "", bins_x, 0, bins_x, bins_y, 0, bins_y);

    for (int i = 0; i < _n + 1; i++) { 
      for (int j = 0; j < _m + 1; j++) {
        smearing_matrix_histo->SetBinContent(j+1, i+1, _S[i][j]);
      }
    } 

    TH2F *h = new TH2F("h", "", smearing_matrix_histo->GetNbinsX(), 0, smearing_matrix_histo->GetNbinsX(),
      smearing_matrix_histo->GetNbinsY(), 0, smearing_matrix_histo->GetNbinsY());
    

    for (int i = 0; i < smearing_matrix_histo->GetNbinsX(); i++) {
      std::ostringstream oss;
      if (i == smearing_matrix_histo->GetNbinsX() - 1 && found == std::string::npos) 
        oss << "OF";
      else
        oss << i + 1;
      std::string label = oss.str();
      h->GetXaxis()->SetBinLabel(i+1,label.c_str());
      h->GetYaxis()->SetBinLabel(i+1,label.c_str());
    }

    h->GetXaxis()->SetLabelOffset(0.004);
    h->GetXaxis()->SetLabelSize(0.07);
    h->GetYaxis()->SetLabelOffset(0.004);
    h->GetYaxis()->SetLabelSize(0.07);
    h->GetXaxis()->SetTitle("True Bin");
    h->GetYaxis()->SetTitle("Reco Bin");
    h->GetXaxis()->CenterTitle();
    h->GetYaxis()->CenterTitle();

    


    // double overlow = 0;
    // overflow += 

    gStyle->SetPaintTextFormat("4.2f");

    TCanvas * c_smatrix = new TCanvas;
    smearing_matrix_histo->SetMarkerColor(kWhite);
    smearing_matrix_histo->SetMarkerSize(2.0);
    smearing_matrix_histo->GetXaxis()->CenterTitle();
    smearing_matrix_histo->GetYaxis()->CenterTitle();
    smearing_matrix_histo->GetXaxis()->SetTitle("True Bin j");
    smearing_matrix_histo->GetYaxis()->SetTitle("Reco Bin i");

    h->Draw();
    smearing_matrix_histo->Draw("col same TEXT");
    TString name = _folder + "migration_matrix_2d";
    c_smatrix->SaveAs(name + ".pdf");
    c_smatrix->SaveAs(name + ".C");

  }



  void MigrationMatrix2D::PrintSmearingMatrixLatex()
  {


    if (!_f_out.is_open()) {
      std::cout << "File not opened." << std::endl;
      return;
    }

    _f_out << "Last entry is the overflow bin." << std::endl;
    _f_out << "\\begin{equation}" << std::endl;
    _f_out << "S_{ij} =" << std::endl;
    _f_out << "\\begin{bmatrix}" << std::endl;

    for (int i = 0; i < _n + 1; i++) {
      for (int j = 0; j < _m + 1; j++) {

        _f_out << std::setprecision(3) << _S[i][j] << "  &  ";

      }

      _f_out << " \\\\" << std::endl;
    }

    _f_out << "\\end{bmatrix}" << std::endl;
    _f_out << "\\end{equation}" << std::endl << std::endl;

  }


}

#endif

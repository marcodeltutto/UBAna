#ifndef __BASE_MIGRATIONMATRIX4DPOLY_CXX__
#define __BASE_MIGRATIONMATRIX4DPOLY_CXX__

#include "MigrationMatrix4DPoly.h"

namespace Base {

  void MigrationMatrix4DPoly::SetLaTeXOutputFileName(std::string name) 
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
    _n_bins = n_bins;    
  }

  void MigrationMatrix4DPoly::CheckEntries(UBTH2Poly* h, int bin_number) 
  {
    if (h->GetEntries() < 5) {
      LOG_WARNING() << "Few events simulated in true bin " << bin_number << ", migration matrix will be forced to be diagonal for this bin." << std::endl;

      for (int a = -9; a < h->GetNumberOfBins() + 1; a++) {
        h->SetBinContent(a, 0.);
        if (a == bin_number) {
          h->SetBinContent(a, 1.);
        }
      }

    }

  }

  TMatrix MigrationMatrix4DPoly::CalculateMigrationMatrix() 
  {
    
    // Resize the smearing matrix (+1 for overflows)
    _S.Clear(); _S.ResizeTo(_n_bins + 1, _n_bins + 1);

    for (int m = 0; m < _n_bins + 1; m++) { // True bin

      int true_idx = m - 1;
      if (true_idx < 0) true_idx = _n_bins;

      if (_h_reco_per_true.size()) {
        // Case 1, we have set a set of UBTH2Poly per every true bin
        _reco_per_true = (UBTH2Poly*) _h_reco_per_true[m]->Clone("_reco_per_true");
        // if (true_idx == 10) LOG_CRITICAL() << "entries = " <<_h_reco_per_true[m]->GetEntries() << ", integral = " << _h_reco_per_true[m]->Integral() << std::endl;
      } else {
        // Case 2, we have set a set a vector of lenght _n_bins (reco bins) per every true bin
        _reco_per_true = (UBTH2Poly*) _th2poly_template->Clone("_reco_per_true");
        for (int i = 1; i < _n_bins + 1; i++) {
          _reco_per_true->SetBinContent(i, _v_reco_per_true[m][i]);
        }
        _reco_per_true->SetBinContent(-2, _v_reco_per_true[m][0]); // Set overflows to bin number -2 (just convention)
      }

      // Put diagonal only if small events in this true bin
      CheckEntries(_reco_per_true, m);

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

        if (std::isnan(value))
          value = 0.;
  
        _S[i][true_idx] = value;
        
      }

      // Add overflows
      double overflow = 0.;
      for (int i = -9; i < 0; i++) {
        overflow += _reco_per_true->GetBinContent(i);
      }
      if (std::isnan(overflow)) overflow = 0.;
      _S[_n_bins][true_idx] = overflow;


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


    return _S;

  }


  void MigrationMatrix4DPoly::PlotMatrix()
  {

    TH2D *h_sm = new TH2D("h_sm", "", _n_bins + 1, 0, _n_bins + 1, _n_bins + 1, 0, _n_bins + 1);

    for (int m = 0; m < _n_bins + 1; m++) {  // true
      for (int i = 0; i < _n_bins + 1; i++) {  // reco
        
        h_sm->SetBinContent(m + 1, i + 1, _S[i][m]);

      }
    }

    std::vector<std::string> bin_labels;

    for (int i = 0; i < _n_bins; i++) {  

      std::stringstream sstm;
      sstm << i + 1;
      std::string str = sstm.str();

      bin_labels.emplace_back(str);

    }

    for (int i = 0; i < _n_bins; i++) {
      h_sm->GetXaxis()->SetBinLabel(i+1, bin_labels.at(i).c_str());
      h_sm->GetYaxis()->SetBinLabel(i+1, bin_labels.at(i).c_str());
    }
    h_sm->GetXaxis()->SetBinLabel(_n_bins + 1, "OF");
    h_sm->GetYaxis()->SetBinLabel(_n_bins + 1, "OF");

    h_sm->GetXaxis()->SetTickLength(0);
    h_sm->GetYaxis()->SetTickLength(0);
    h_sm->GetXaxis()->SetLabelSize(0.03);
    h_sm->GetYaxis()->SetLabelSize(0.03);
    h_sm->GetXaxis()->SetTitle("True Bin Number");
    h_sm->GetYaxis()->SetTitle("Reconstructed Bin Number");
    h_sm->GetZaxis()->SetTitle("Probability");




    Int_t * separators = _th2poly_template->GetSeparators();
    Int_t separators_length = _th2poly_template->GetSeparatorsLength();

    if (separators_length > 50) separators_length = 0;

    std::vector<TLine*> lines;

    // Vertical lines
    Int_t sum = 0;
    for (Int_t s = 0; s < separators_length - 1; s++) {
      TLine *line = new TLine(separators[s] + sum, 0, separators[s] + sum, _n_bins + 1);
      line->SetLineColor(kRed);
      line->SetLineWidth(2);
      lines.emplace_back(line);
      sum += separators[s];
    }

    // Horizontal lines
    sum = 0;
    for (Int_t s = 0; s < separators_length - 1; s++) {
      TLine *line = new TLine(0, separators[s] + sum, _n_bins + 1, separators[s] + sum);
      line->SetLineColor(kRed);
      line->SetLineWidth(2);
      lines.emplace_back(line);
      sum += separators[s];
    }

    // Last two lines for overflows
    TLine *line_of_v = new TLine(_n_bins, 0, _n_bins, _n_bins + 1);
    line_of_v->SetLineColor(kRed);
    line_of_v->SetLineWidth(2);
    lines.emplace_back(line_of_v);

    TLine *line_of_h = new TLine(0, _n_bins, _n_bins + 1, _n_bins);
    line_of_h->SetLineColor(kRed);
    line_of_h->SetLineWidth(2);
    lines.emplace_back(line_of_h);



    TCanvas *c_sm = new TCanvas();
    c_sm->SetRightMargin(0.14);
    h_sm->Draw("colz");
 
    for (auto l : lines)
      l->Draw();


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

    for (int m = 0; m < _n_bins; m++) {
      for (int i = 0; i < _n_bins; i++) {

        _f_out << _S[m][i] << "  &  ";

      }

      _f_out << " \\\\" << std::endl;
    }

    _f_out << "\\end{bmatrix}" << std::endl;
    _f_out << "\\end{equation}" << std::endl << std::endl;

  }
}

#endif

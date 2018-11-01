#ifndef __BASE_CROSSSECTIONCALCULATOR2D_CXX__
#define __BASE_CROSSSECTIONCALCULATOR2D_CXX__

#include "CrossSectionCalculator2D.h"

namespace Base {

  void CrossSectionCalculator2D::Reset() 
  {

    _configured = false;

    //_scale_factor_mc_bnbcosmic = -999;
    //_scale_factor_bnbon = -999;
    //_scale_factor_extbnb = -999;
    //_scale_factor_mc_intimecosmic = -999;

    //_pot = -1;

    _name = "Not configured!";
    _label = "Not configured!";

    //_outdir = "NotConfigured";

    _hmap_bnbcosmic.clear();
    _h_bnbon = NULL;
    _h_extbnb = NULL;
    _h_intimecosmic = NULL;

    _h_eff_mumom_num = NULL;
    _h_eff_mumom_den = NULL;

    //_h_true_reco_mom = NULL;

    _covariance_matrix_is_set = false;
    _frac_covariance_matrix_is_set = false;
  }

  void CrossSectionCalculator2D::SetScaleFactors(double bnbcosmic, double bnbon, double extbnb, double dirt, double intimecosmic)
  {
    _scale_factor_mc_bnbcosmic = bnbcosmic;
    _scale_factor_bnbon = bnbon;
    _scale_factor_extbnb = extbnb;
    _scale_factor_mc_dirt = dirt;
    _scale_factor_mc_intimecosmic = intimecosmic;

    _configured = true;
  }

  void CrossSectionCalculator2D::SetPOT(double pot)
  {
    _pot = pot;
  }

  void CrossSectionCalculator2D::SetNameAndLabel(std::string name, std::string label)
  {
    _name = name;
    _label = label;
  }

  void CrossSectionCalculator2D::SetOutDir(std::string dir)
  {
    std::string out_folder_base = std::getenv("MYSW_OUTDIR");

    _outdir = out_folder_base + dir;

    auto now = std::time(nullptr);
    char buf[sizeof("YYYY-MM-DD_HH-MM-SS")];
    std::string timestamp = std::string(buf,buf + std::strftime(buf,sizeof(buf),"%F_%H-%M-%S",std::gmtime(&now)));

    _folder = _outdir + "_" + timestamp + "/";

    system(("mkdir " + _folder).c_str());

  }

  void CrossSectionCalculator2D::SetCovarianceMatrix(TH2D h)
  {
    _covariance_matrix = h;
    _covariance_matrix_is_set = true;

    if (_frac_covariance_matrix_is_set) {
      LOG_CRITICAL() << "You have set both a covariance and a fractional covariance matrix. Only one is allowed." << std::endl;
      throw std::exception();
    }
  }

  void CrossSectionCalculator2D::SetFractionalCovarianceMatrix(TH2D h)
  {
    _frac_covariance_matrix = h;
    _frac_covariance_matrix_is_set = true;

    if (_covariance_matrix_is_set) {
      LOG_CRITICAL() << "You have set both a covariance and a fractional covariance matrix. Only one is allowed." << std::endl;
      throw std::exception();
    }
  }

  void CrossSectionCalculator2D::PrintConfig() {

    std::cout << "--- CrossSectionCalculator2D:" << std::endl;
    std::cout << "---   _scale_factor_mc_bnbcosmic     = " << _scale_factor_mc_bnbcosmic << std::endl;
    std::cout << "---   _scale_factor_bnbon            = " << _scale_factor_bnbon << std::endl;
    std::cout << "---   _scale_factor_extbnb           = " << _scale_factor_extbnb << std::endl;
    std::cout << "---   _scale_factor_mc_intimecosmic  = " << _scale_factor_mc_intimecosmic << std::endl;
    std::cout << "---   _pot                           = " << _pot << std::endl;

  }

  void CrossSectionCalculator2D::SetHistograms(std::map<std::string,TH2D*> bnbcosmic, TH2D* bnbon, TH2D* extbnb, std::map<std::string,TH2D*> dirt, TH2D* intimecosmic) 
  {

    // _hmap_bnbcosmic = bnbcosmic;
    // _hmap_dirt = dirt;
    // _h_bnbon = bnbon;
    // _h_extbnb = extbnb;
    // _h_intimecosmic = intimecosmic;


    for (auto it : bnbcosmic) {
      std::string this_name = it.second->GetName();
      _hmap_bnbcosmic[it.first] = (TH2D*)it.second->Clone((this_name + it.first + "_xsec_int_bnbcosmic").c_str());
    }

    for (auto it : dirt) {
      std::string this_name = it.second->GetName();
      _hmap_dirt[it.first] = (TH2D*)it.second->Clone((this_name + it.first + "_xsec_int_dirt").c_str());
    }

    _dirt_is_set = false;
    if (dirt.size() != 0) {
      LOG_INFO() << "Dirt Histograms Set Up" << std::endl;
      _dirt_is_set = true;
    }
    
    if (bnbon != NULL) {
      _h_bnbon = (TH2D*)bnbon->Clone("_h_bnbon");
    }
    if (extbnb != NULL) {
      _h_extbnb = (TH2D*)extbnb->Clone("_h_extbnb");
    }
    if (intimecosmic != NULL) {
      _h_intimecosmic = (TH2D*)intimecosmic->Clone("_h_intimecosmic");
    }

  }

  void CrossSectionCalculator2D::SetTruthHistograms(TH2D* num, TH2D* den/*, TH2D* h*/)
  {
    _h_eff_mumom_num = num;
    _h_eff_mumom_den = den;
  }

  void CrossSectionCalculator2D::SetTruthXSec(TH1D* xsec) 
  {
    _truth_xsec = xsec;
  }

  double CrossSectionCalculator2D::EstimateFlux(std::string flux_file_name, std::string histogram_file_name) 
  {
    std::string flux_file = std::getenv("MYSW_DIR");
    //flux_file += "/Flux/numode_bnb_470m_r200.root";
    flux_file += "/Flux/";
    flux_file += flux_file_name;
    LOG_DEBUG() << "Using flux file: " << flux_file << std::endl;

    LOG_DEBUG() << "Flux correction weight: " << _flux_correction_weight << std::endl;

    TFile * f = TFile::Open(flux_file.c_str());
    f->cd();
    TH1D * h_flux_numu = (TH1D*) f->Get(histogram_file_name.c_str());//f->Get("numu");    //h_flux_numu->Scale(_pot/1.e20);
    double scale_factor = _pot;
    scale_factor /= 2.43e11 * 256.35 * 233.;
    scale_factor *= _flux_correction_weight;
    h_flux_numu->Scale(scale_factor);


    TCanvas * c_flux = new TCanvas();

    std::stringstream sstm2;
    sstm2 << "##nu / " << _pot << " POT / cm^{2}";
    std::string str = sstm2.str();
    h_flux_numu->GetYaxis()->SetTitle(str.c_str());
    h_flux_numu->GetXaxis()->SetTitle("E_{#nu} [GeV]");

    h_flux_numu->Draw("histo");

    double mean = h_flux_numu-> GetMean();
    LOG_DEBUG() << "The mean energy is: " << mean << std::endl;
    int binmean = h_flux_numu -> FindBin(mean);
    LOG_DEBUG() << "The bin of the mean is: " << binmean << std::endl;

    int n = h_flux_numu -> GetNbinsX();

    double lowerint = h_flux_numu -> Integral(1, binmean);
    LOG_DEBUG() << "Lower Integral: " << lowerint << std::endl;
    double lowerborder = lowerint * 0.32;
    LOG_DEBUG() << "Lower Border: " << lowerborder << std::endl;
    double lowersum = 0;
    int i = 0;
    while (lowersum < lowerborder) {
      i++;
      lowersum += h_flux_numu -> GetBinContent(i);
      LOG_DEBUG() << i << "\t" << lowersum << std::endl;
    }

    double low = h_flux_numu -> GetBinCenter(i-1);

    LOG_DEBUG() << "Lower Sum: " << lowersum << std::endl;
    LOG_DEBUG() << "The lower edge bin is: " << i-1 << std::endl;
    LOG_DEBUG() << "The lower edge center energy is: " << low << std::endl;
    LOG_DEBUG() << "The lower energy error is: " << mean - low << std::endl;

    double upperint = h_flux_numu -> Integral(binmean, n);
    LOG_DEBUG() << upperint << std::endl;
    double upperborder = upperint * 0.32;
    double uppersum = 0;
    i = 0;
    while (uppersum < upperborder) {
      uppersum += h_flux_numu -> GetBinContent(n+1 - i);
      i++;
    }

    double up = h_flux_numu -> GetBinCenter(n+1 - (i-1));
    LOG_DEBUG() << "The upper edge bin is: " << i-1 << std::endl;
    LOG_DEBUG() << "The upper edge center energy is: " << up << std::endl;
    LOG_DEBUG() << "The upper energy error is: " << up - mean << std::endl;

    TGraph *gmean = new TGraph();
    gmean -> SetPoint(0, mean, 0);
    gmean -> SetPoint(1, mean, 1e10);
    gmean -> SetLineWidth(2);
    gmean -> SetLineColor(kOrange+1);
    gmean -> Draw("same");

    TGraph *glow = new TGraph();
    glow -> SetPoint(0, low, 0);
    glow -> SetPoint(1, low, 1e10);
    glow -> SetLineWidth(2);
    glow -> SetLineColor(kOrange+1);
    glow -> SetLineStyle(7);
    glow -> Draw("same");

    TGraph *gup = new TGraph();
    gup -> SetPoint(0, up, 0);
    gup -> SetPoint(1, up, 1e10);
    gup -> SetLineWidth(2);
    gup -> SetLineColor(kOrange+1);
    gup -> SetLineStyle(7);
    gup -> Draw("same");

    TLegend *l = new TLegend(0.6, 0.7, 0.89, 0.89);
    l -> AddEntry(h_flux_numu, "BNB #nu_{#mu} flux, #nu-mode", "l");
    l -> AddEntry(gmean, "<E_{#nu}>", "l");
    l -> AddEntry(glow, "1#sigma Energy Range", "l");
    l -> Draw();

    h_flux_numu->GetXaxis()->SetRangeUser(0, 4);
    gPad->Update();

    PlottingTools::DrawSimulationXSec();

    TString name = _folder + "_flux";
    c_flux->SaveAs(name + ".pdf");
    c_flux->SaveAs(name + ".C","C");
    
    _flux = h_flux_numu->Integral();

    f->Close();

    return _flux;
  }

  void CrossSectionCalculator2D::SetSmearingMatrix(Mat4D s)
  {
    _S = s;

    LOG_DEBUG() << "Smearing matrix has been set." << std::endl;

  }


  void CrossSectionCalculator2D::Smear()
  {

    Mat2D matrix_angle_mom_den_truth;
    matrix_angle_mom_den_truth.resize(_h_eff_mumom_den->GetNbinsX(), std::vector<double>(_h_eff_mumom_den->GetNbinsY(), 0));

    Mat2D matrix_angle_mom_num_truth;
    matrix_angle_mom_num_truth.resize(_h_eff_mumom_num->GetNbinsX(), std::vector<double>(_h_eff_mumom_num->GetNbinsY(), 0));

    for (int m = 0; m < _h_eff_mumom_den->GetNbinsX(); m++) {
      for (int n = 0; n < _h_eff_mumom_den->GetNbinsY(); n++) {
        matrix_angle_mom_den_truth[m][n] = _h_eff_mumom_den->GetBinContent(m+1, n+1);
        matrix_angle_mom_num_truth[m][n] = _h_eff_mumom_num->GetBinContent(m+1, n+1);
        //std::cout << "den (" << m << ", " << n << ") = " << matrix_angle_mom_den_truth[m][n] << std::endl;
        //std::cout << "num (" << m << ", " << n << ") = " << matrix_angle_mom_num_truth[m][n] << std::endl;
      }
    }

    TCanvas * c_truth_den = new TCanvas;
    _h_eff_mumom_den->SetMarkerColor(kWhite);
    _h_eff_mumom_den->SetMarkerSize(1.6);
    _h_eff_mumom_den->SetTitle("Generated");
    _h_eff_mumom_den->GetXaxis()->SetTitle("cos(#theta_{#mu}^{truth})");
    _h_eff_mumom_den->GetYaxis()->SetTitle("p_{#mu}^{truth}");
    _h_eff_mumom_den->Draw("colz text");

    TString name = _folder +_name + "all";
    c_truth_den->SaveAs(name + ".pdf");

    TCanvas * c_truth_num = new TCanvas;
    _h_eff_mumom_num->SetMarkerColor(kWhite);
    _h_eff_mumom_num->SetMarkerSize(1.6);
    _h_eff_mumom_num->SetTitle("Selected");
    _h_eff_mumom_num->GetXaxis()->SetTitle("cos(#theta_{#mu}^{truth})");
    _h_eff_mumom_num->GetYaxis()->SetTitle("p_{#mu}^{truth}");
    _h_eff_mumom_num->Draw("colz text");

    name = _folder +_name + "selected";
    c_truth_num->SaveAs(name + ".pdf");


    //
    // Smearing 
    //

    Mat2D matrix_angle_mom_den_smear;
    matrix_angle_mom_den_smear.resize(_h_eff_mumom_den->GetNbinsX(), std::vector<double>(_h_eff_mumom_den->GetNbinsY(), 0));

    Mat2D matrix_angle_mom_num_smear;
    matrix_angle_mom_num_smear.resize(_h_eff_mumom_num->GetNbinsX(), std::vector<double>(_h_eff_mumom_num->GetNbinsY(), 0));



    // Reco bins i, j
    for (int i = 0; i < _h_eff_mumom_den->GetNbinsX(); i++) {
      for (int j = 0; j < _h_eff_mumom_den->GetNbinsY(); j++) {  

        // Truth bins m, n
        for (int m = 0; m < _h_eff_mumom_den->GetNbinsX(); m++) {
          for (int n = 0; n < _h_eff_mumom_den->GetNbinsY(); n++) {

            matrix_angle_mom_den_smear[i][j] +=  _S[i][j][m][n] * matrix_angle_mom_den_truth[m][n];
            matrix_angle_mom_num_smear[i][j] +=  _S[i][j][m][n] * matrix_angle_mom_num_truth[m][n];

          }
        }
      }
    }


    //
    // Make a plottable histo of the smeared distributions
    //
    TH2D * h_eff_den_smear = (TH2D*) _h_eff_mumom_den->Clone("h_eff_den_smear");
    TH2D * h_eff_num_smear = (TH2D*) _h_eff_mumom_num->Clone("h_eff_num_smear");
    for (int i = 0; i < _h_eff_mumom_den->GetNbinsX(); i++) {
      for (int j = 0; j < _h_eff_mumom_den->GetNbinsY(); j++) {
        h_eff_den_smear->SetBinContent(i+1, j+1, matrix_angle_mom_den_smear[i][j]);
        h_eff_num_smear->SetBinContent(i+1, j+1, matrix_angle_mom_num_smear[i][j]);
      } 
    }



    TCanvas * c_smear_den = new TCanvas;
    h_eff_den_smear->SetMarkerColor(kWhite);
    h_eff_den_smear->SetMarkerSize(1.6);
    h_eff_den_smear->SetTitle("Generated");
    h_eff_den_smear->GetXaxis()->SetTitle("cos(#theta_{#mu}^{reco})");
    h_eff_den_smear->GetYaxis()->SetTitle("p_{#mu}^{reco}");
    h_eff_den_smear->Draw("colz text");

    name = _folder +_name + "all_smear";
    c_smear_den->SaveAs(name + ".pdf");

    TCanvas * c_smear_num = new TCanvas;
    h_eff_num_smear->SetMarkerColor(kWhite);
    h_eff_num_smear->SetMarkerSize(1.6);
    h_eff_num_smear->SetTitle("Selected");
    h_eff_num_smear->GetXaxis()->SetTitle("cos(#theta_{#mu}^{reco})");
    h_eff_num_smear->GetYaxis()->SetTitle("p_{#mu}^{reco}");
    h_eff_num_smear->Draw("colz text");

    name = _folder +_name + "selected_smear";
    c_smear_num->SaveAs(name + ".pdf");


    //
    // Efficiency (true)
    //

    TEfficiency* teff_true = new TEfficiency(*_h_eff_mumom_num,*_h_eff_mumom_den);

    TCanvas * c_eff_true = new TCanvas;
    teff_true->SetMarkerColor(kWhite);
    teff_true->SetMarkerSize(1.6);
    teff_true->SetTitle("Efficiency;cos(#theta_{#mu}^{true});p_{#mu}^{true}");
    teff_true->Draw("colz text");
    gPad->Update(); 
    auto graph_t = teff_true->GetPaintedHistogram(); 
    graph_t->SetMinimum(0);
    graph_t->SetMaximum(1); 
    gPad->Update();

    name = _folder +_name + "efficiency_true";
    c_eff_true->SaveAs(name + ".pdf");
    c_eff_true->SaveAs(name + ".C");


    //
    // Efficiency (reco)
    //

    TEfficiency* teff_reco = new TEfficiency(*h_eff_num_smear,*h_eff_den_smear);

    TCanvas * c_eff_reco = new TCanvas;
    teff_reco->SetMarkerColor(kWhite);
    teff_reco->SetMarkerSize(1.6);
    teff_reco->SetTitle("Efficiency;cos(#theta_{#mu}^{reco});p_{#mu}^{reco}");
    teff_reco->Draw("colz text");
    gPad->Update(); 
    auto graph = teff_reco->GetPaintedHistogram(); 
    graph->SetMinimum(0);
    graph->SetMaximum(1); 
    gPad->Update();

    name = _folder +_name + "_efficiency_reco";
    c_eff_reco->SaveAs(name + ".pdf");
    c_eff_reco->SaveAs(name + ".C");

    

    _eff = teff_reco;

    LOG_DEBUG() << "Smearing done." << std::endl;


  }



  void CrossSectionCalculator2D::ProcessPlots() 
  {

    LOG_DEBUG() << "Start plot processing." << std::endl;


    // Scale mc histograms (bnbcosmic)
    for (auto iter : _hmap_bnbcosmic) {
      if ( iter.second == NULL || iter.first == "intimecosmic" || iter.first == "beam-off"
        || iter.first == "dirt" || iter.first == "dirt_outfv"   || iter.first == "dirt_cosmic") continue;
      iter.second->Sumw2();
      iter.second->Scale(_scale_factor_mc_bnbcosmic);
    }

    // Scale mc histograms (dirt)
    if (_dirt_is_set) {
      for (auto iter : _hmap_dirt) {
        iter.second->Sumw2();
        iter.second->Scale(_scale_factor_mc_dirt);
      }
    }

    // Scale data histograms
    _h_extbnb->Sumw2();
    _h_bnbon->Sumw2();
    _h_extbnb->Scale(_scale_factor_extbnb);
    _h_bnbon->Scale(_scale_factor_bnbon);

    // Get the beam-on - beam-off histogram
    _h_data_sub = (TH2D*)_h_bnbon->Clone("_h_data_sub");
    _h_data_sub->Sumw2();
    _h_data_sub->Add(_h_extbnb, -1.);


    // Save beam off in the MC backgrounds ...
    _hmap_bnbcosmic["beam-off"] = _h_extbnb;

    // ... and update the total histogram
    _hmap_bnbcosmic["total"]->Add(_h_extbnb);


    if (_dirt_is_set) {
      // Save dirt in the MC backgrounds ...
      _hmap_bnbcosmic["dirt"] = _hmap_dirt["total"];
      _hmap_bnbcosmic["dirt_outfv"] = _hmap_dirt["outfv"];
      _hmap_bnbcosmic["dirt_cosmic"] = _hmap_dirt["cosmic"];

      // ... and update the total histogram
      _hmap_bnbcosmic["total"]->Add(_hmap_dirt["total"]);
    } else {
      TH2D * h_empty = (TH2D*) _hmap_bnbcosmic["total"]->Clone("empty");
      h_empty->Reset();

      _hmap_bnbcosmic["dirt"] = h_empty;
      _hmap_bnbcosmic["outfv_dirt"] = h_empty;
      _hmap_bnbcosmic["cosmic_dirt"] = h_empty;
    }


    LOG_DEBUG() << "Plot processing ends." << std::endl;
  }


  TH2D* CrossSectionCalculator2D::ExtractCrossSection(std::vector<std::string> bkg_names, std::string xaxis_label, std::string yaxis_label, std::string zaxis_label, bool make_plots) 
  {

    //
    // The two histograms we acually need: MC and data (bkg subtracted)
    //

    TH2D* h_mc = _hmap_bnbcosmic["signal"];
    TH2D* h_data = (TH2D*)_h_bnbon->Clone("h_data");
    h_mc->SetTitle(_label.c_str());
    h_data->Sumw2();

    LOG_INFO() << "Initial - Cross section in bin (5, 2) is " << h_data->GetBinContent(5, 2) << std::endl;

    if (h_mc->GetSumw2N() == 0) { 
      LOG_WARNING() << "MC cross section histogram does not have Sum2w active." << std::endl;
    }


    // LOG_INFO() << "Subtracting backgrouds: ";
    for (auto name : bkg_names) 
    {
      // std::cout << name << ", ";

      h_data->Add(_hmap_bnbcosmic[name], -1.);

      if (_hmap_bnbcosmic[name]->GetSumw2N() == 0) {
        LOG_WARNING() << "Bkg " << name << " does not have Sum2w active." << std::endl;
      }
    }
    // std::cout << std::endl;


    LOG_INFO() << "Subtraction - Cross section in bin (5, 2) is " << h_data->GetBinContent(5, 2) << std::endl;




    //
    // Create efficiency histogram
    //
    TH2D * h_eff = (TH2D*)h_mc->Clone("h_eff");
    h_eff->Sumw2();
    for (int i = 1; i < h_mc->GetNbinsX() + 1; i++) {
      for (int j = 1; j < h_mc->GetNbinsY() + 1; j++) {
    
        h_eff->SetBinContent(i, j, _eff->GetEfficiency(_eff->GetGlobalBin(i, j)));
        double unc = 0.;
        unc += _eff->GetEfficiencyErrorLow(_eff->GetGlobalBin(i, j));
        unc += _eff->GetEfficiencyErrorUp(_eff->GetGlobalBin(i, j));
        unc /= 2.;
        h_eff->SetBinError(i, j, unc);

        //std::cout << "Efficiency at bin " << i << ", " << j << ": " << h_eff->GetBinContent(i, j) << " =- " << unc << std::endl;
      }
    }



    //
    // Divide by efficiency
    //

    h_mc->Divide(h_eff);
    h_data->Divide(h_eff);

    LOG_INFO() << "Efficiency in bin (5, 2) is " << h_eff->GetBinContent(5, 2) << std::endl;
    LOG_INFO() << "Efficiency - Cross section in bin (5, 2) is " << h_data->GetBinContent(5, 2) << std::endl;



    //
    // Divide by flux, and N_target and bin width
    //

    // LOG_INFO() << "FLUX: " << _flux << ", N_target: " << _n_target << ", FLUX x N_target: " << _flux*_n_target << std::endl;

    double den_data = _flux * _n_target_data * 1e-38;
    double den_mc   = _flux * _n_target_mc   * 1e-38;

    h_mc->Scale(1. / den_mc, "width");
    h_data->Scale(1. / den_data, "width");

    LOG_INFO() << "Cross section in bin (5, 2) is " << h_data->GetBinContent(5, 2) << std::endl;



    for (int bin_i = 1; bin_i < h_data->GetNbinsX()+1; bin_i++) {
      for (int bin_j = 1; bin_j < h_data->GetNbinsY()+1; bin_j++) {
        if (h_data->GetBinContent(bin_i, bin_j) <= 0.) {
          LOG_INFO() << "******************************************" << std::endl;
          LOG_INFO() << "Cross Section in bin " << bin_i-1 << ", " << bin_j-1 << " is <= 0, value: " << h_data->GetBinContent(bin_i, bin_j) << std::endl;
          LOG_INFO() << "******************************************" << std::endl;
        }
      }
    }





    // Do it also for the truth xsec
    //_truth_xsec->Scale(1. / den, "width");

    LOG_INFO() << "MC Integral: " << h_mc->Integral() << std::endl;
    LOG_INFO() << "Data Integral: " << h_data->Integral() << std::endl;


    if (h_data->GetBinContent(9, 5) < 0.5) {
      LOG_CRITICAL() << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> cross section in bin 9, 5 is " << h_data->GetBinContent(9, 5) << std::endl;
    }


    //
    // Add systs uncertainties (if cov. matrix is set)
    //

    if (_extra_fractional_uncertainty != 0) {
      std::cout << "Adding an extra uncertainty of " << _extra_fractional_uncertainty * 100 << "%" << std::endl;
    }

    TH2D * h_syst_unc = (TH2D*) h_data->Clone("h_syst_unc");

    if (_frac_covariance_matrix_is_set) {

      _covariance_matrix = * ( (TH2D*)_frac_covariance_matrix.Clone("_covariance_matrix") );
      _covariance_matrix.Reset();

      // Loop over the bins and multiply this fractional covariance matrix by the xsec
      // so to obtain a covariance matrix
      int i = 0, j = 0, m = 0, n = 0;
 
      for (int a = 0; a < _frac_covariance_matrix.GetNbinsX(); a++) {

        for (int b = 0; b < _frac_covariance_matrix.GetNbinsX(); b++) {

          // Unroll a and b labels into a = i,j and b = m,n
          if (a % h_data->GetNbinsY() == 0){
              i = a / h_data->GetNbinsY();
          }
          j = a % h_data->GetNbinsY();

          if (b % h_data->GetNbinsY() == 0){
              m = b / h_data->GetNbinsY();
          }
          n = b % h_data->GetNbinsY();

          _covariance_matrix.SetBinContent(a+1, b+1, _frac_covariance_matrix.GetBinContent(a+1, b+1) * (h_data->GetBinContent(i+1, j+1) * h_data->GetBinContent(m+1, n+1)) );
        }
      }

      _covariance_matrix_is_set = true;
    }

    if (_covariance_matrix_is_set) {

      // Just to set the right bins:
      _cov_matrix_total = (TH2D*)_covariance_matrix.Clone("_cov_matrix_total");
      _frac_cov_matrix_total = (TH2D*)_covariance_matrix.Clone("_frac_cov_matrix_total");
      _corr_matrix_total = (TH2D*)_covariance_matrix.Clone("_corr_matrix_total");

      int i = 0, j = 0, m = 0, n = 0;
 
      for (int a = 0; a < _covariance_matrix.GetNbinsX(); a++) {

        for (int b = 0; b < _covariance_matrix.GetNbinsX(); b++) {

          // Unroll a and b labels into a = i,j and b = m,n
          if (a % h_data->GetNbinsY() == 0){
              i = a / h_data->GetNbinsY();
          }
          j = a % h_data->GetNbinsY();

          if (b % h_data->GetNbinsY() == 0){
              m = b / h_data->GetNbinsY();
          }
          n = b % h_data->GetNbinsY();

          // std::cout << "a = " << a << ", i = " << i << ", j = " << j << std::endl;
          // std::cout << "b = " << b << ", m = " << m << ", n = " << n << std::endl;


          // The statictial uncertainty squared
          double unc_stat_2 = h_data->GetBinError(i+1, j+1) * h_data->GetBinError(m+1, n+1);

          // The systematic uncertainty squared
          double unc_syst_2 = _covariance_matrix.GetBinContent(a+1, b+1);

          // The extra systematic uncertainty squared (POT normalisation, ...)
          double extra_unc_2 = _extra_fractional_uncertainty * h_data->GetBinContent(i+1, j+1)   *    _extra_fractional_uncertainty * h_data->GetBinContent(m+1, n+1);

          // The total uncertainty (quadrature sum)
          double unc_tot = std::sqrt(unc_stat_2 + unc_syst_2 + extra_unc_2);

          if (a == b) {
            std::cout << "Bin " << a << " (aka i = " << i << ", j = " << j << ")" << " - stat: " << std::sqrt(unc_stat_2) << ", syst: " << std::sqrt(unc_syst_2) << ", tot: " << unc_tot << std::endl;
            h_syst_unc->SetBinError(i+1, j+1, unc_tot); 
          }

          // Also construct the total syst covariance matrix
          double total_syst_unc_2 = unc_syst_2 + extra_unc_2;

          _cov_matrix_total->SetBinContent(a+1, b+1, total_syst_unc_2);
          if (h_data->GetBinContent(i+1, j+1) != 0. && h_data->GetBinContent(m+1, n+1) != 0.) {
            _frac_cov_matrix_total->SetBinContent(a+1, b+1, (total_syst_unc_2) / (h_data->GetBinContent(i+1, j+1) * h_data->GetBinContent(m+1, n+1)));
          } else {
            _frac_cov_matrix_total->SetBinContent(a+1, b+1, 0.);
          }

        } // j
      } // i

      // And also the correlation matrix
      for (int a = 0; a < _covariance_matrix.GetNbinsX(); a++) {
        for (int b = 0; b < _covariance_matrix.GetNbinsX(); b++) {
          if (_cov_matrix_total->GetBinContent(a+1, a+1) != 0. && _cov_matrix_total->GetBinContent(b+1, b+1) != 0.) {
            _corr_matrix_total->SetBinContent(a+1, b+1, _cov_matrix_total->GetBinContent(a+1, b+1) / (std::sqrt(_cov_matrix_total->GetBinContent(a+1, a+1)) * std::sqrt(_cov_matrix_total->GetBinContent(b+1, b+1))));
          } else {
            _corr_matrix_total->SetBinContent(a+1, b+1, 0.);
          }
        }
      }
    }

    _h_data = h_data;
    _h_mc = h_mc;
    _h_syst_unc = h_syst_unc;

    if (make_plots) MakeAllCrossSectionPlots(xaxis_label, yaxis_label, zaxis_label);

    return _h_data;

  }

  void CrossSectionCalculator2D::MakeAllCrossSectionPlots(std::string xaxis_label, std::string yaxis_label, std::string zaxis_label)
  {



    //
    // General for plotting
    //

    TLatex* prelim = new TLatex(0.982808,0.9494737, "MicroBooNE Preliminary"); //0.9, 0.93
    prelim->SetTextColor(kGray+1);
    prelim->SetNDC();
    prelim->SetTextSize(2/30.);
    prelim->SetTextAlign(32);
    prelim->SetTextSize(0.04631579);
    //prelim->Draw();

    TLatex* sim = new TLatex(0.982808,0.9494737, "MicroBooNE Simulation");
    sim->SetTextColor(kGray+1);
    sim->SetNDC();
    sim->SetTextSize(2/30.);
    sim->SetTextAlign(32);
    sim->SetTextSize(0.04631579);
    //sim->Draw();


    TLatex* xsec_label = new TLatex(0.4297994,0.8863158, "#frac{d^{2}#sigma}{dp_{#mu}dcos(#theta_{#mu})} [10^{-38}cm^{2}/GeV]");
    xsec_label->SetTextColor(kBlack);
    xsec_label->SetNDC();
    xsec_label->SetTextSize(.055);
    xsec_label->SetTextAlign(32);
    //xsec_label->SetTextSize(0.04631579);
    xsec_label->SetTextFont(42);
    //xsec_label->Draw();


    //
    // Plot the cross section for MC
    //

    TCanvas * c_xsec_mc = new TCanvas();
    _h_mc->GetXaxis()->SetTitle(xaxis_label.c_str());
    _h_mc->GetYaxis()->SetTitle(yaxis_label.c_str());
    _h_mc->GetYaxis()->SetTitleOffset(0.77);
    _h_mc->Draw("lego1");

    sim->Draw();

    xsec_label->Draw();

    TString name = _folder +_name + "_xsec_mc";
    c_xsec_mc->SaveAs(name + ".pdf");
    c_xsec_mc->SaveAs(name + ".C","C");




    double central_size = 0.02;
    TH2D* h_mc_empty_bottom = (TH2D*)_h_mc->Clone("h_mc_empty_bottom");
    TH2D* h_mc_error_low = (TH2D*)_h_mc->Clone("h_mc_error_low");
    TH2D* h_mc_error_up = (TH2D*)_h_mc->Clone("h_mc_error_up");
    TH2D* h_mc_central = (TH2D*)_h_mc->Clone("h_mc_central");

    for (int i = 1; i < _h_mc->GetNbinsX()+1; i++) {
      for (int j = 1; j < _h_mc->GetNbinsY()+1; j++) {

        double content = _h_mc->GetBinContent(i, j);
        double unc = _h_mc->GetBinError(i, j);

        //std::cout << "bin (" << i << ", " << j << "): content is " << content  << ", unc is " << unc << std::endl;

        if (content != 0) {
          h_mc_empty_bottom->SetBinContent(i, j, content - unc);
          h_mc_error_low->SetBinContent(i, j, unc);
          h_mc_error_up->SetBinContent(i, j, unc);
          h_mc_central->SetBinContent(i, j, central_size);
        } else {
          h_mc_empty_bottom->SetBinContent(i, j, 0.);
          h_mc_error_low->SetBinContent(i, j, 0.);
          h_mc_error_up->SetBinContent(i, j, 0.);
          h_mc_central->SetBinContent(i, j, 0.);
        }

      }
    }



    h_mc_empty_bottom->SetFillColor(kWhite);
    h_mc_empty_bottom->SetLineWidth(1);
    h_mc_error_low->SetFillColor(29);
    h_mc_error_low->SetLineWidth(1);
    h_mc_central->SetFillColor(kGreen+2);
    h_mc_central->SetLineWidth(1);
    h_mc_error_up->SetFillColor(29);
    h_mc_error_up->SetLineWidth(1);

    THStack *hs_mc = new THStack("hs_mc", "");
    hs_mc->Add(h_mc_empty_bottom);
    hs_mc->Add(h_mc_error_low);
    hs_mc->Add(h_mc_central);
    hs_mc->Add(h_mc_error_up);

    TCanvas * c_xsec_mc2 = new TCanvas();
    //hs_mc->GetXaxis()->SetTitle(xaxis_label.c_str());
    //hs_mc->GetYaxis()->SetTitle(yaxis_label.c_str());
    //hs_mc->GetYaxis()->SetTitleOffset(0.77);
    
    hs_mc->Draw("lego4");
    hs_mc->GetXaxis()->SetTitle(xaxis_label.c_str());
    hs_mc->GetXaxis()->SetTitleOffset(1.45);
    hs_mc->GetYaxis()->SetTitleOffset(1.45);
    hs_mc->GetYaxis()->SetTitle(yaxis_label.c_str());
    c_xsec_mc2->Modified();

    sim->Draw();

    xsec_label->Draw();

    TLegend *ll = new TLegend(0.722063,0.8210526,0.9971347,0.92,NULL,"brNDC");
    TH1D * dummymc = new TH1D("dummymc", "dummymc", 1, 0, 1);
    dummymc->SetLineColor(kGreen+2);
    ll->AddEntry(dummymc, "MC", "l");
    ll->AddEntry(h_mc_error_low, "Stat. Uncertainty", "f");
    ll->Draw();

    name = _folder +_name + "_xsec_mc2";
    c_xsec_mc2->SaveAs(name + ".pdf");
    c_xsec_mc2->SaveAs(name + ".C","C");



    
    

    //
    // Plot the cross section for DATA
    //

    // Prepare 2d hist with error bars
    TH2D* h_data_empty_bottom = (TH2D*)_h_data->Clone("h_data_empty_bottom");
    TH2D* h_data_error_low = (TH2D*)_h_data->Clone("h_data_error_low");
    TH2D* h_data_error_up = (TH2D*)_h_data->Clone("h_data_error_up");
    TH2D* h_data_central = (TH2D*)_h_data->Clone("h_data_central");

    for (int i = 1; i < _h_data->GetNbinsX()+1; i++) {
      for (int j = 1; j < _h_data->GetNbinsY()+1; j++) {

        double content = _h_data->GetBinContent(i, j);
        double unc = _h_data->GetBinError(i, j);

        //std::cout << "bin (" << i << ", " << j << "): content is " << content  << ", unc is " << unc << std::endl;

        if (content != 0) {
          h_data_empty_bottom->SetBinContent(i, j, content - unc);
          h_data_error_low->SetBinContent(i, j, unc);
          h_data_error_up->SetBinContent(i, j, unc);
          h_data_central->SetBinContent(i, j, central_size);
        } else {
          h_data_empty_bottom->SetBinContent(i, j, 0.);
          h_data_error_low->SetBinContent(i, j, 0.);
          h_data_error_up->SetBinContent(i, j, 0.);
          h_data_central->SetBinContent(i, j, 0.);
        }

      }
    }

    h_data_empty_bottom->GetXaxis()->SetTitle(xaxis_label.c_str());
    h_data_empty_bottom->GetYaxis()->SetTitle(yaxis_label.c_str());
    h_data_empty_bottom->GetZaxis()->SetTitle(zaxis_label.c_str());

    h_data_empty_bottom->SetFillColor(kWhite);
    h_data_empty_bottom->SetLineWidth(1);
    h_data_error_low->SetFillColor(kRed-10);
    h_data_error_low->SetLineWidth(1);
    h_data_central->SetFillColor(kRed);
    h_data_central->SetLineWidth(1);
    h_data_error_up->SetFillColor(kRed-10);
    h_data_error_up->SetLineWidth(1);

    THStack *hs_data = new THStack("hs_data", "");
    hs_data->Add(h_data_empty_bottom);
    hs_data->Add(h_data_error_low);
    hs_data->Add(h_data_central);
    hs_data->Add(h_data_error_up);


    TCanvas * c_xsec_data = new TCanvas();
    //h_data->SetMarkerStyle(kFullCircle);
    //h_data->SetMarkerSize(0.6);
    _h_data->SetFillColor(kGreen+2);
    _h_data->SetLineColor(kBlack);
    _h_data->GetXaxis()->SetTitle(xaxis_label.c_str());
    _h_data->GetYaxis()->SetTitle(yaxis_label.c_str());
    _h_data->GetZaxis()->SetTitle(zaxis_label.c_str());
    _h_data->GetYaxis()->SetTitleOffset(0.77);

    xsec_label->Draw();
    prelim->Draw();

    _h_data->Draw("e2");
    

    




    name = _folder +_name + "_xsec_data";
    c_xsec_data->SaveAs(name + ".pdf");
    c_xsec_data->SaveAs(name + ".C","C");


    TCanvas * c_xsec_data2 = new TCanvas();

    //hs_data->GetYaxis()->SetTitleOffset(0.77);
    hs_data->Draw("lego4");
    hs_data->GetXaxis()->SetTitle(xaxis_label.c_str());
    hs_data->GetXaxis()->SetTitleOffset(1.45);
    hs_data->GetYaxis()->SetTitleOffset(1.45);
    hs_data->GetYaxis()->SetTitle(yaxis_label.c_str());
    c_xsec_data2->Modified();

    xsec_label->Draw();
    prelim->Draw();

    TLegend *l = new TLegend(0.722063,0.8210526,0.9971347,0.92,NULL,"brNDC");
    TH1D * dummy = new TH1D("dummy", "dummy", 1, 0, 1);
    dummy->SetLineColor(kRed);
    l->AddEntry(dummy, "Data", "l");
    l->AddEntry(h_data_error_low, "Stat. Uncertainty", "f");
    l->Draw();

    name = _folder +_name + "_xsec_dat2";
    c_xsec_data2->SaveAs(name + ".pdf");
    c_xsec_data2->SaveAs(name + ".C","C");












    //
    // Project in cos(theta) bins
    //

    std::vector<TH1D> xsec_data_histos;
    std::vector<TH1D> xsec_mc_histos;
    std::vector<TH1D> xsec_data_unc_histos;
    // std::vector<std::string> costhetamu_ranges = {"-1.00 #leq cos(#theta_{#mu}^{reco}) < -0.50",
    //                                               "-0.50 #leq cos(#theta_{#mu}^{reco}) < 0.00",
    //                                               "0.00 #leq cos(#theta_{#mu}^{reco}) < 0.25",
    //                                               "0.25 #leq cos(#theta_{#mu}^{reco}) < 0.50",
    //                                               "0.50 #leq cos(#theta_{#mu}^{reco}) < 0.75",
    //                                               "1.75 #leq cos(#theta_{#mu}^{reco}) < 1.00"};

    // std::vector<std::string> costhetamu_ranges = {"-1.00 #leq cos(#theta_{#mu}^{reco}) < -0.50",
    //                                               "-0.50 #leq cos(#theta_{#mu}^{reco}) < 0.00",
    //                                               "0.00 #leq cos(#theta_{#mu}^{reco}) < 0.27",
    //                                               "0.27 #leq cos(#theta_{#mu}^{reco}) < 0.45",
    //                                               "0.45 #leq cos(#theta_{#mu}^{reco}) < 0.62",
    //                                               "0.62 #leq cos(#theta_{#mu}^{reco}) < 0.76",
    //                                               "0.76 #leq cos(#theta_{#mu}^{reco}) < 0.86",
    //                                               "0.86 #leq cos(#theta_{#mu}^{reco}) < 0.94",
    //                                               "0.94 #leq cos(#theta_{#mu}^{reco}) < 1.00",
    //                                               "nan #leq cos(#theta_{#mu}^{reco}) < nan",
    //                                               "nan #leq cos(#theta_{#mu}^{reco}) < nan",};

    // std::vector<std::string> costhetamu_ranges = {"-1.00 #leq cos(#theta_{#mu}^{reco}) < -0.00",
    //                                               "0.00 #leq cos(#theta_{#mu}^{reco}) < 0.27",
    //                                               "0.27 #leq cos(#theta_{#mu}^{reco}) < 0.45",
    //                                               "0.45 #leq cos(#theta_{#mu}^{reco}) < 0.62",
    //                                               "0.62 #leq cos(#theta_{#mu}^{reco}) < 0.76",
    //                                               "0.76 #leq cos(#theta_{#mu}^{reco}) < 0.86",
    //                                               "0.86 #leq cos(#theta_{#mu}^{reco}) < 0.94",
    //                                               "0.94 #leq cos(#theta_{#mu}^{reco}) < 1.00",
    //                                               "nan #leq cos(#theta_{#mu}^{reco}) < nan",
    //                                               "nan #leq cos(#theta_{#mu}^{reco}) < nan",};

    std::vector<std::string> costhetamu_ranges = {"-1.00 #leq cos(#theta_{#mu}^{reco}) < 0.00",
                                                  "0.00 #leq cos(#theta_{#mu}^{reco}) < 0.45",
                                                  "0.45 #leq cos(#theta_{#mu}^{reco}) < 0.62",
                                                  "0.62 #leq cos(#theta_{#mu}^{reco}) < 0.76",
                                                  "0.76 #leq cos(#theta_{#mu}^{reco}) < 0.86",
                                                  "0.86 #leq cos(#theta_{#mu}^{reco}) < 0.94",
                                                  "0.94 #leq cos(#theta_{#mu}^{reco}) < 1.00",
                                                  "nan #leq cos(#theta_{#mu}^{reco}) < nan",
                                                  "nan #leq cos(#theta_{#mu}^{reco}) < nan",};


    LOG_INFO() << "n bins x " << _h_data->GetNbinsX() << std::endl;
    LOG_INFO() << "n bins y " << _h_data->GetNbinsY() << std::endl;

    int horizontal_division = 2;
    int vertical_division = floor(_h_data->GetNbinsX() / 2.);
    
    if ( _h_data->GetNbinsX() / 2. != floor(_h_data->GetNbinsX() / 2.) ) vertical_division++;

    LOG_INFO() << "Horizontal divisions " << horizontal_division << std::endl;
    LOG_INFO() << "Vertical divisions " << vertical_division << std::endl;

    // TCanvas *c_test = new TCanvas("c_test","multipads",900,700);
    TCanvas *c_test = new TCanvas("c_test", "multipads",0,45,1006,1150);
    c_test->SetBottomMargin(0.15);
    // gStyle->SetOptStat(0);
    c_test->Divide(horizontal_division, vertical_division, 0.01, 0.01);

    for (int i = 0; i < _h_data->GetNbinsX(); i++) {
      xsec_data_histos.emplace_back(*_h_data->ProjectionY("fuck", i+1, i+1));
      xsec_mc_histos.emplace_back(*_h_mc->ProjectionY("fuck", i+1, i+1));
      xsec_data_unc_histos.emplace_back(*_h_syst_unc->ProjectionY("fuck", i+1, i+1));
    }


    for (size_t i = 0; i < xsec_mc_histos.size(); i++) {

      c_test->cd(i+1);

      gPad->SetBottomMargin(0.15);
      gPad->SetLeftMargin(0.15);
      gPad->SetTopMargin(0.1128947);

      xsec_mc_histos.at(i).SetTitle(costhetamu_ranges.at(i).c_str());
      xsec_mc_histos.at(i).GetXaxis()->SetTitle("p_{#mu}^{reco} [GeV]");
      xsec_mc_histos.at(i).GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{#mu}^{reco}dcos(#theta_{#mu}^{reco})} [10^{-38} cm^{2}/GeV/n]");
      xsec_mc_histos.at(i).GetXaxis()->CenterTitle();
      xsec_mc_histos.at(i).GetYaxis()->CenterTitle();
      xsec_mc_histos.at(i).SetLineColor(kGreen+2);
      xsec_mc_histos.at(i).SetFillColor(29);
      xsec_mc_histos.at(i).GetXaxis()->SetTitleOffset(0.92);
      xsec_mc_histos.at(i).GetYaxis()->SetTitleOffset(1.11);
      xsec_mc_histos.at(i).Draw("E2");
      TH1D* h_main = (TH1D*) xsec_mc_histos.at(i).Clone("h_main");
      h_main->SetLineColor(kGreen+2);
      h_main->SetFillColor(0); // fully transparent
      h_main->Draw("histo same");

      xsec_mc_histos.at(i).SetMinimum(0.);
      if (i == 0) xsec_mc_histos.at(i).SetMinimum( -0.0006);
      if (i == 1) xsec_mc_histos.at(i).SetMinimum( -0.007);
      // if (i == 0) {
      //   xsec_mc_histos.at(i).SetMaximum(0.4);
      // } else if (i == 1) {
      //   xsec_mc_histos.at(i).SetMaximum(0.4);
      // } 

      // if (i == 0) xsec_mc_histos.at(i).SetMaximum(0.40);
      // if (i == 1) xsec_mc_histos.at(i).SetMaximum(0.40);
      // if (i == 2) xsec_mc_histos.at(i).SetMaximum(0.60);
      // if (i == 3) xsec_mc_histos.at(i).SetMaximum(0.80);
      // if (i == 4) xsec_mc_histos.at(i).SetMaximum(1.25);
      // if (i == 5) xsec_mc_histos.at(i).SetMaximum(1.90);

      // if (i == 0) xsec_mc_histos.at(i).SetMaximum(0.50);
      // if (i == 1) xsec_mc_histos.at(i).SetMaximum(0.45);
      // if (i == 2) xsec_mc_histos.at(i).SetMaximum(0.80);
      // if (i == 3) xsec_mc_histos.at(i).SetMaximum(1.00);
      // // if (i == 3) xsec_mc_histos.at(i).SetMinimum(-0.3);
      // if (i == 4) xsec_mc_histos.at(i).SetMaximum(1.25);
      // if (i == 5) xsec_mc_histos.at(i).SetMaximum(1.90);

      // if (i == 0) xsec_mc_histos.at(i).SetMaximum(0.35);
      // if (i == 1) xsec_mc_histos.at(i).SetMaximum(0.70);
      // if (i == 2) xsec_mc_histos.at(i).SetMaximum(1.00);
      // if (i == 3) xsec_mc_histos.at(i).SetMaximum(1.25);
      // if (i == 4) xsec_mc_histos.at(i).SetMaximum(1.40);
      // if (i == 5) xsec_mc_histos.at(i).SetMaximum(1.90);

      if (i == 0) xsec_mc_histos.at(i).SetMaximum(0.50);
      if (i == 1) xsec_mc_histos.at(i).SetMaximum(1.00);
      if (i == 2) xsec_mc_histos.at(i).SetMaximum(1.50);
      if (i == 3) xsec_mc_histos.at(i).SetMaximum(1.60);
      if (i == 4) xsec_mc_histos.at(i).SetMaximum(1.90);



      // The outer uncertainty bar
      xsec_data_unc_histos.at(i).SetMarkerStyle(20);
      xsec_data_unc_histos.at(i).SetMarkerSize(0.1);
      xsec_data_unc_histos.at(i).Draw("E1 X0 same");

      // The proper data points
      xsec_data_histos.at(i).SetMarkerStyle(20);
      xsec_data_histos.at(i).SetMarkerSize(0.5);
      xsec_data_histos.at(i).Draw("E1 X0 same");

      if (i == 0) {
        TLegend *l;
        l = new TLegend(0.3671979,0.67415,0.7178785,0.8019232,NULL,"brNDC");
        l->SetFillColor(0);
        l->SetFillStyle(0);
        l->SetTextSize(0.03407284);
        l->AddEntry(&xsec_mc_histos.at(i), "GENIE Default + Emp. MEC (Stat. Unc.)");
        l->AddEntry(&xsec_data_histos.at(i), "Measured (Stat. Unc.)", "ep");
        l->Draw();
      }
    }
    // PlottingTools::DrawPreliminaryXSec();


    name = _folder +_name + "_xsec_anglesplit";
    c_test->SaveAs(name + ".pdf");
    c_test->SaveAs(name + ".C","C");







    //
    // Now plot the covariance matrices
    //

    if (_covariance_matrix_is_set) {

      gStyle->SetPalette(kDeepSea);
      gStyle->SetPaintTextFormat("4.2f");

      const Int_t NCont = 100;
      const Int_t NRGBs = 5;
      Double_t mainColour[NRGBs]   = { 1.00, 1.00, 1.00, 1.00, 1.00 };
      Double_t otherColour[NRGBs]   = { 0.99,0.80, 0.60, 0.40, 0.20 };
      //Double_t otherOtherColour[NRGBs]   = { 0.9,0.80, 0.80, 0.80, 0.80 };
      Double_t stops[NRGBs] = { 0.00, 0.05, 0.1, 0.4, 1.00 };

      TColor::CreateGradientColorTable(NRGBs, stops, mainColour, otherColour, otherColour, NCont);
      gStyle->SetNumberContours(NCont);


      TH2F *h = new TH2F("h", "", _covariance_matrix.GetNbinsX(), 0, _covariance_matrix.GetNbinsX(),
        _covariance_matrix.GetNbinsY(), 0, _covariance_matrix.GetNbinsY());

      // h->SetMaximum(1);

      int i_label_number = 0;
      int j_label_number = 0;
      for (int i = 0; i <  _covariance_matrix.GetNbinsX()+1; i++) {
        std::ostringstream oss;
        oss << i_label_number << "," << j_label_number;
        if (j_label_number % _h_data->GetNbinsY() == 0) {
          i_label_number ++;
          j_label_number = 0;
        }
        j_label_number++;
        std::string label = oss.str();
        if (i == 0) continue;
        h->GetXaxis()->SetBinLabel(i,label.c_str());
        h->GetYaxis()->SetBinLabel(i,label.c_str());
      }

      h->GetXaxis()->SetLabelOffset(0.004);
      h->GetXaxis()->SetLabelSize(0.03);
      h->GetYaxis()->SetLabelOffset(0.004);
      h->GetYaxis()->SetLabelSize(0.03);
      h->GetXaxis()->SetTitle("Bin i,j");
      h->GetYaxis()->SetTitle("Bin m,n");
      h->GetXaxis()->CenterTitle();
      h->GetYaxis()->CenterTitle();

      //
      // Create lines to divide primary bins
      //

      std::vector<TLine*> lines;

      for (int i = 1; i < _h_data->GetNbinsX(); i++) {
        TLine *line = new TLine(_h_data->GetNbinsY()  * i, 0, _h_data->GetNbinsY() * i, _covariance_matrix.GetNbinsX());
        line->SetLineColor(kGreen+2);
        line->SetLineWidth(2);
        lines.emplace_back(line);
      }

      for (int i = 1; i < _h_data->GetNbinsX(); i++) {
        TLine *line = new TLine(0, _h_data->GetNbinsY() * i, _covariance_matrix.GetNbinsX(), _h_data->GetNbinsY() * i);
        line->SetLineColor(kGreen+2);
        line->SetLineWidth(2);
        lines.emplace_back(line);
      }

      //
      // Create TLatex lables
      //

      TLatex* tl1 = new TLatex(0.10,0.97, "i, m = cos(#theta_{#mu}) bins");
      tl1->SetTextColor(kBlack);
      tl1->SetTextFont(42);
      tl1->SetNDC();
      tl1->SetTextSize(1/30.);
      tl1->SetTextAlign(12);

      TLatex* tl2 = new TLatex(0.10,0.93, "j, n = p_{#mu} bins");
      tl2->SetTextColor(kBlack);
      tl2->SetTextFont(42);
      tl2->SetNDC();
      tl2->SetTextSize(1/30.);
      tl2->SetTextAlign(12);



      // 
      // Draw the proper matrices
      //

      float text_size = 0.9;

      TCanvas * cov_c = new TCanvas();
      cov_c->SetRightMargin(0.13);
      cov_c->SetFixedAspectRatio();
      _cov_matrix_total->SetMarkerColor(kBlack);
      _cov_matrix_total->SetMarkerSize(text_size);
      _cov_matrix_total->GetXaxis()->CenterTitle();
      _cov_matrix_total->GetYaxis()->CenterTitle();
      _cov_matrix_total->GetXaxis()->SetTitle("Bin i,j");
      _cov_matrix_total->GetYaxis()->SetTitle("Bin m,n");
      _cov_matrix_total->GetXaxis()->SetTickLength(0);
      _cov_matrix_total->GetYaxis()->SetTickLength(0);
      h->Draw();
      _cov_matrix_total->Draw("colz text same");
      // _cov_matrix_total->Draw("colz same");

      for (auto l : lines)
        l->Draw();

      tl1->Draw();
      tl2->Draw();

      PlottingTools::DrawSimulationXSec();
      name = _folder +_name + "_tot_covariance";
      cov_c->SaveAs(name + ".pdf");
      cov_c->SaveAs(name + ".C","C");


      TCanvas * cov_frac_c = new TCanvas();
      cov_frac_c->SetRightMargin(0.13);
      cov_frac_c->SetFixedAspectRatio();
      _frac_cov_matrix_total->SetMarkerColor(kBlack);
      _frac_cov_matrix_total->SetMarkerSize(text_size);
      _frac_cov_matrix_total->GetXaxis()->CenterTitle();
      _frac_cov_matrix_total->GetYaxis()->CenterTitle();
      _frac_cov_matrix_total->GetXaxis()->SetTitle("Bin i,j");
      _frac_cov_matrix_total->GetYaxis()->SetTitle("Bin m,n");
      _frac_cov_matrix_total->GetXaxis()->SetTickLength(0);
      _frac_cov_matrix_total->GetYaxis()->SetTickLength(0);
      h->Draw();
      _frac_cov_matrix_total->Draw("colz text same");
      // _frac_cov_matrix_total->Draw("colz same");

      for (auto l : lines)
        l->Draw();

      tl1->Draw();
      tl2->Draw();

      PlottingTools::DrawSimulationXSec();
      name = _folder +_name + "_tot_fractional_covariance";
      cov_frac_c->SaveAs(name + ".pdf");
      cov_frac_c->SaveAs(name + ".C","C");

      TCanvas * corr_c = new TCanvas();
      corr_c->SetRightMargin(0.13);
      corr_c->SetFixedAspectRatio();
      _corr_matrix_total->SetMarkerColor(kBlack);
      _corr_matrix_total->SetMarkerSize(text_size);
      _corr_matrix_total->GetXaxis()->CenterTitle();
      _corr_matrix_total->GetYaxis()->CenterTitle();
      _corr_matrix_total->GetXaxis()->SetTitle("Bin i,j");
      _corr_matrix_total->GetYaxis()->SetTitle("Bin m,n");
      _corr_matrix_total->GetXaxis()->SetTickLength(0);
      _corr_matrix_total->GetYaxis()->SetTickLength(0);
      h->Draw();
      _corr_matrix_total->Draw("colz text same");
      // _corr_matrix_total->Draw("colz same");

      for (auto l : lines)
        l->Draw();

      tl1->Draw();
      tl2->Draw();

      PlottingTools::DrawSimulationXSec();
      name = _folder +_name + "_tot_correlation";
      corr_c->SaveAs(name + ".pdf");
      corr_c->SaveAs(name + ".C","C");

      gStyle->SetPalette(kRainBow);
    }

  }






  void CrossSectionCalculator2D::DrawMC(TCanvas * c, int c_number, TH1D h)
  {
    c->cd(c_number);
    // h.GetXaxis()->SetTitle(xaxis_label.c_str());
    // h.GetYaxis()->SetTitle(yaxis_label.c_str());
    // h.GetXaxis()->SetTitleOffset(0.95);
    // h.GetYaxis()->SetTitleOffset(0.77);

    h.SetLineColor(kGreen+2);
    h.SetFillColor(29);

    // if (_name.find("mom") != std::string::npos) {
    //   h.SetMinimum(0.);
    //   h.SetMaximum(1.6);
    // } else {
    //   h.SetMinimum(0.);
    //   h.SetMaximum(2.8);
    // }
    h.Draw("E2");

    TH1D* h_main = (TH1D*) h.Clone("h_main");
    h_main->SetLineColor(kGreen+2);
    h_main->SetFillColor(0); // fully transparent
    h_main->Draw("histo same");
  }



  void CrossSectionCalculator2D::Draw(std::vector<std::string> histos_to_subtract)
  {

    TH2D* _h_data_subtracted = (TH2D*)_h_bnbon->Clone("_h_data_subtracted");
    _h_data_subtracted->Sumw2();

    for (auto hname : histos_to_subtract) 
    {
      std::cout << "[CrossSectionCalculator2D] Going to subtract histogram " << hname << std::endl;
      // Need to remove from the data histogram
      _h_data_subtracted->Add(_hmap_bnbcosmic[hname], -1.);
      // But also form the total MC one, to properly propagate unc
      _hmap_bnbcosmic["total"]->Add(_hmap_bnbcosmic[hname], -1.);
    }


    TLegend* leg = new TLegend(0.56,0.37,0.82,0.82,NULL,"brNDC");;

    TCanvas* canvas = new TCanvas();

    THStack *hs_mc = this->ProcessTHStack(_hmap_bnbcosmic, leg, histos_to_subtract);

    TH2D* data = ProcessDataHisto(_h_data_subtracted);

    hs_mc->Draw("hist");
    _hmap_bnbcosmic["total"]->Draw("E2 same"); // errors
    data->Draw("E1 same");

    leg->AddEntry(data, "Data (Background subtracted)", "lep");
    leg->Draw();


    TLatex* l = this->GetPOTLatex(_pot);
    l->Draw();

    TString name = _folder +_name + "_test";
    canvas->SaveAs(name + ".pdf");
    canvas->SaveAs(name + ".C","C");


  }



  void CrossSectionCalculator2D::Draw() 
  {

    TString name = _folder +_name + "_selected_events";
    DrawInProjections(_h_bnbon, _hmap_bnbcosmic, name, false);

    // name = _folder +_name + "_selected_events_scalebinwidth";
    // DrawInProjections(_h_bnbon, _hmap_bnbcosmic, name, true);

  }



  void CrossSectionCalculator2D::DrawInProjections(TH2D* h_data, std::map<std::string,TH2D*> mc, TString save_path, bool scale_bin_width) 
  {

    std::vector<TH1D> xsec_data_histos;
    std::map<std::string,std::vector<TH1D*>> xsec_mc_histos;
    std::vector<THStack*> xsec_mc_hs;
          

    std::vector<std::string> costhetamu_ranges = {"-1.00 #leq cos(#theta_{#mu}^{reco}) < -0.00",
                                                  "0.00 #leq cos(#theta_{#mu}^{reco}) < 0.27",
                                                  "0.27 #leq cos(#theta_{#mu}^{reco}) < 0.45",
                                                  "0.45 #leq cos(#theta_{#mu}^{reco}) < 0.62",
                                                  "0.62 #leq cos(#theta_{#mu}^{reco}) < 0.76",
                                                  "0.76 #leq cos(#theta_{#mu}^{reco}) < 0.86",
                                                  "0.86 #leq cos(#theta_{#mu}^{reco}) < 0.94",
                                                  "0.94 #leq cos(#theta_{#mu}^{reco}) < 1.00",
                                                  "nan #leq cos(#theta_{#mu}^{reco}) < nan",
                                                  "nan #leq cos(#theta_{#mu}^{reco}) < nan",};


    int horizontal_division = 2;
    int vertical_division = floor(h_data->GetNbinsX() / 2.);

    if (h_data->GetNbinsX() / 2. != floor(h_data->GetNbinsX()) / 2.) vertical_division++;

    LOG_INFO() << "Horizontal divisions " << horizontal_division << std::endl;
    LOG_INFO() << "Vertical divisions " << vertical_division << std::endl;

    // TCanvas *c_test = new TCanvas("c_test","multipads",900,700);
    TCanvas *c_test = new TCanvas("c_test", "multipads",0,45,1006,1150);
    c_test->SetBottomMargin(0.15);
    // gStyle->SetOptStat(0);
    c_test->Divide(horizontal_division, vertical_division, 0.01, 0.01);


    xsec_mc_hs.resize(h_data->GetNbinsX());
    for (auto iter : mc) {
      xsec_mc_histos[iter.first].resize(h_data->GetNbinsX());
    }


    for (int i = 0; i < h_data->GetNbinsX(); i++) {
      xsec_data_histos.emplace_back(*h_data->ProjectionY("fuck", i+1, i+1));
      if (scale_bin_width) xsec_data_histos.at(i).Scale(1, "width");
      for (auto iter : mc) {
        xsec_mc_histos[iter.first].at(i) = iter.second->ProjectionY(("fuck" + iter.first + costhetamu_ranges.at(i)).c_str(), i+1, i+1);
        if (scale_bin_width) xsec_mc_histos[iter.first].at(i)->Scale(1, "width");
        // xsec_mc_histos[iter.first].at(i)->Scale(1/_scale_factor_mc_bnbcosmic);
      }
      xsec_mc_hs.at(i) = new THStack("bs",";BS;BS");
    }



    std::fstream fs;
    fs.open ("test.txt", std::fstream::out | std::fstream::app);

    fs << "  & ";

    for (size_t i = 0; i < xsec_data_histos.size(); i++) {

      c_test->cd(i+1);

      gPad->SetBottomMargin(0.15);
      gPad->SetLeftMargin(0.15);
      gPad->SetTopMargin(0.1128947);


      // xsec_mc_histos["beam-off"].at(i)->GetXaxis()->SetTitle("p_{#mu}^{reco} [GeV]");
      // xsec_mc_histos["beam-off"].at(i)->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{#mu}^{reco}dcos(#theta_{#mu}^{reco})} [10^{-38} cm^{2}/GeV/n]");
      // xsec_mc_histos["beam-off"].at(i)->GetXaxis()->CenterTitle();
      // xsec_mc_histos["beam-off"].at(i)->GetYaxis()->CenterTitle();
      // xsec_mc_histos["beam-off"].at(i)->GetXaxis()->SetTitleOffset(0.92);
      // xsec_mc_histos["beam-off"].at(i)->GetYaxis()->SetTitleOffset(1.11);

      double total_background = xsec_mc_histos["beam-off"].at(i)->Integral() / _scale_factor_extbnb + 
                                xsec_mc_histos["dirt"].at(i)->Integral() / _scale_factor_mc_bnbcosmic + 
                                xsec_mc_histos["cosmic"].at(i)->Integral()  / _scale_factor_mc_bnbcosmic + 
                                xsec_mc_histos["outfv"].at(i)->Integral()  / _scale_factor_mc_bnbcosmic + 
                                xsec_mc_histos["nc"].at(i)->Integral()  / _scale_factor_mc_bnbcosmic + 
                                xsec_mc_histos["anumu"].at(i)->Integral()  / _scale_factor_mc_bnbcosmic + 
                                xsec_mc_histos["nue"].at(i)->Integral() / _scale_factor_mc_bnbcosmic; 

      // LOG_CRITICAL() << "In cos(theta) bin " << i << ", total signal " << xsec_mc_histos["signal"].at(i)->Integral()  / _scale_factor_mc_bnbcosmic << ", total background " << total_background  << std::endl;

      
      fs << xsec_mc_histos["signal"].at(i)->Integral()  / _scale_factor_mc_bnbcosmic << " & " << total_background << " & ";


      xsec_mc_histos["beam-off"].at(i)->SetLineColor(kBlue+2);
      xsec_mc_histos["beam-off"].at(i)->SetFillColor(kBlue+2);
      xsec_mc_histos["beam-off"].at(i)->SetFillStyle(3004);
      xsec_mc_hs.at(i)->Add(xsec_mc_histos["beam-off"].at(i));

      xsec_mc_histos["dirt"].at(i)->SetLineColor(kOrange+3);
      xsec_mc_histos["dirt"].at(i)->SetFillColor(kOrange+3);
      xsec_mc_hs.at(i)->Add(xsec_mc_histos["dirt"].at(i));


      xsec_mc_histos["cosmic"].at(i)->SetLineColor(kBlue-3);
      xsec_mc_histos["cosmic"].at(i)->SetFillColor(kBlue-3);
      xsec_mc_hs.at(i)->Add(xsec_mc_histos["cosmic"].at(i));

      xsec_mc_histos["outfv"].at(i)->SetLineColor(kGreen+2);
      xsec_mc_histos["outfv"].at(i)->SetFillColor(kGreen+2);
      xsec_mc_hs.at(i)->Add(xsec_mc_histos["outfv"].at(i));
      xsec_mc_histos["nc"].at(i)->SetLineColor(kGray);
      xsec_mc_histos["nc"].at(i)->SetFillColor(kGray);
      xsec_mc_hs.at(i)->Add(xsec_mc_histos["nc"].at(i));
      xsec_mc_histos["anumu"].at(i)->SetLineColor(kOrange-3);
      xsec_mc_histos["anumu"].at(i)->SetFillColor(kOrange-3);
      xsec_mc_hs.at(i)->Add(xsec_mc_histos["anumu"].at(i));
      xsec_mc_histos["nue"].at(i)->SetLineColor(kMagenta+1);
      xsec_mc_histos["nue"].at(i)->SetFillColor(kMagenta+1);
      xsec_mc_hs.at(i)->Add(xsec_mc_histos["nue"].at(i));
      xsec_mc_histos["signal"].at(i)->SetLineColor(kRed-4);
      xsec_mc_histos["signal"].at(i)->SetFillColor(kRed-4);
      xsec_mc_hs.at(i)->Add(xsec_mc_histos["signal"].at(i));

      if (scale_bin_width) xsec_mc_hs.at(i)->SetTitle((costhetamu_ranges.at(i) + ";p_{#mu}^{reco};Selected Events / GeV").c_str());
      else xsec_mc_hs.at(i)->SetTitle((costhetamu_ranges.at(i) + ";p_{#mu}^{reco};Selected Events").c_str());
      xsec_mc_hs.at(i)->Draw("hist");

      xsec_mc_hs.at(i)->SetMinimum(0.);



      // The proper data points
      xsec_data_histos.at(i).SetMarkerStyle(20);
      xsec_data_histos.at(i).SetMarkerSize(0.5);
      xsec_data_histos.at(i).Draw("E1 X0 same");

      gPad->Modified(); gPad->Update();


      // if (i == 0) {
      //   PlottingTools::DrawPreliminaryXSec();

      //   TLatex* l = this->GetPOTLatex(_pot);
      //   l->Draw();
      // }

    }

    fs << " \\\\ " << std::endl;
    
    c_test->SaveAs(save_path + ".pdf");
    c_test->SaveAs(save_path + ".C","C");

  }





  THStack * CrossSectionCalculator2D::ProcessTHStack(std::map<std::string,TH2D*> themap, TLegend* leg, std::vector<std::string> histos_to_subtract){

    THStack *hs_trklen = new THStack("hs",_label.c_str());

    bool _breakdownPlots = false;

    bool _draw_beamoff = true, _draw_cosmic = true, _draw_outfv = true, _draw_nue = true, _draw_nc = true, _draw_anumu = true;

    for (auto name: histos_to_subtract)
    {
      if (name == "beam-off") _draw_beamoff = false;
      if (name == "cosmic") _draw_cosmic = false;
      if (name == "outfv") _draw_outfv = false;
      if (name == "nue") _draw_nue = false;
      if (name == "nc") _draw_nc = false;
      if (name == "anumu") _draw_anumu = false;

    }

    if (themap["beam-off"] != NULL && _draw_beamoff) {
      themap["beam-off"]->SetLineColor(kBlue+2);
      themap["beam-off"]->SetFillColor(kBlue+2);
      themap["beam-off"]->SetFillStyle(3004);
      hs_trklen->Add(themap["beam-off"]);
    }

    if (themap["intimecosmic"] != NULL) {
      themap["intimecosmic"]->SetLineColor(kBlue+2);
      themap["intimecosmic"]->SetFillColor(kBlue+2);
      themap["intimecosmic"]->SetFillStyle(3004);
      hs_trklen->Add(themap["intimecosmic"]);
    }

    if (_breakdownPlots) {
      themap["cosmic_nostopmu"]->SetLineColor(kBlue+2);
      themap["cosmic_nostopmu"]->SetFillColor(kBlue+2);
      hs_trklen->Add(themap["cosmic_nostopmu"]);
      themap["cosmic_stopmu"]->SetLineColor(kBlue);
      themap["cosmic_stopmu"]->SetFillColor(kBlue);
      hs_trklen->Add(themap["cosmic_stopmu"]);
      themap["outfv_nostopmu"]->SetLineColor(kGreen+3);
      themap["outfv_nostopmu"]->SetFillColor(kGreen+3);
      hs_trklen->Add(themap["outfv_nostopmu"]);
      themap["outfv_stopmu"]->SetLineColor(kGreen+2);
      themap["outfv_stopmu"]->SetFillColor(kGreen+2);
      hs_trklen->Add(themap["outfv_stopmu"]);
      themap["nc_proton"]->SetLineColor(kGray+2);
      themap["nc_proton"]->SetFillColor(kGray+2);
      hs_trklen->Add(themap["nc_proton"]);
      themap["nc_pion"]->SetLineColor(kGray+1);
      themap["nc_pion"]->SetFillColor(kGray+1);
      hs_trklen->Add(themap["nc_pion"]);
      themap["nc_other"]->SetLineColor(kGray);
      themap["nc_other"]->SetFillColor(kGray);
      hs_trklen->Add(themap["nc_other"]);
    }
    else {
      if (_draw_cosmic) {
        themap["cosmic"]->SetLineColor(kBlue+2);
        themap["cosmic"]->SetFillColor(kBlue+2);
        hs_trklen->Add(themap["cosmic"]);
      }
      if (_draw_outfv) {
        themap["outfv"]->SetLineColor(kGreen+2);
        themap["outfv"]->SetFillColor(kGreen+2);
        hs_trklen->Add(themap["outfv"]);
      }
      if (_draw_nc) {
        themap["nc"]->SetLineColor(kGray);
        themap["nc"]->SetFillColor(kGray);
        hs_trklen->Add(themap["nc"]);
      }
    }

    if (_draw_anumu) {
      themap["anumu"]->SetLineColor(kOrange-3);
      themap["anumu"]->SetFillColor(kOrange-3);
      hs_trklen->Add(themap["anumu"]);
    }
    if (_draw_nue) {
      themap["nue"]->SetLineColor(kMagenta+1);
      themap["nue"]->SetFillColor(kMagenta+1);
      hs_trklen->Add(themap["nue"]);
    }

    if (_breakdownPlots) {
      themap["signal_nostopmu"]->SetLineColor(kRed+2);
      themap["signal_nostopmu"]->SetFillColor(kRed+2);
      hs_trklen->Add(themap["signal_nostopmu"]);
      themap["signal_stopmu"]->SetLineColor(kRed);
      themap["signal_stopmu"]->SetFillColor(kRed);
      hs_trklen->Add(themap["signal_stopmu"]);
    }
    else {
      themap["signal"]->SetLineColor(kRed);
      themap["signal"]->SetFillColor(kRed);
      hs_trklen->Add(themap["signal"]);
    }
    hs_trklen->Draw();

  //h_trklen_total->DrawCopy("hist");

  //gStyle->SetHatchesLineWidth(1);
    themap["total"]->SetFillColor(kBlack);
    themap["total"]->SetFillStyle(3005);
  //themap["total"]->Draw("E2 same");







    if (_breakdownPlots){
      //leg = new TLegend(0.56,0.37,0.82,0.82,NULL,"brNDC");
    } else {
      //leg = new TLegend(0.56,0.54,0.82,0.82,NULL,"brNDC");
    }
    std::stringstream sstm;
  // numu
    if (_breakdownPlots) {
      leg->AddEntry(themap["signal_stopmu"],"#nu_{#mu} CC (stopping #mu)","f");
      leg->AddEntry(themap["signal_nostopmu"],"#nu_{#mu} CC (other)","f");
    } else {
      sstm << "#nu_{#mu} CC (signal), " << std::setprecision(2)  << themap["signal"]->Integral() / themap["total"]->Integral()*100. << "%";
      leg->AddEntry(themap["signal"],sstm.str().c_str(),"f");
      sstm.str("");
    }

  // nue
    sstm << "#nu_{e}, #bar{#nu}_{e} CC, " << std::setprecision(2)  << themap["nue"]->Integral() / themap["total"]->Integral()*100. << "%";
    if (_draw_nue) leg->AddEntry(themap["nue"],sstm.str().c_str(),"f");
    sstm.str("");

  // anumu
    sstm << "#bar{#nu}_{#mu} CC, " << std::setprecision(2)  << themap["anumu"]->Integral() / themap["total"]->Integral()*100. << "%";
    if (_draw_anumu)leg->AddEntry(themap["anumu"],sstm.str().c_str(),"f");
    sstm.str("");

  // nc, outfv, cosmic
    if (_breakdownPlots) {
      leg->AddEntry(themap["nc_other"],"NC (other)","f");
      leg->AddEntry(themap["nc_pion"],"NC (pion)","f");
      leg->AddEntry(themap["nc_proton"],"NC (proton)","f");
      leg->AddEntry(themap["outfv_stopmu"],"OUTFV (stopping #mu)","f");
      leg->AddEntry(themap["outfv_nostopmu"],"OUTFV (other)","f");
      leg->AddEntry(themap["cosmic_stopmu"],"Cosmic (stopping #mu)","f");
      leg->AddEntry(themap["cosmic_nostopmu"],"Cosmic (other)","f");
      if (themap["intimecosmic"] != NULL) {
        leg->AddEntry(themap["intimecosmic"],"In-time cosmics","f");
      }
    } else {
      sstm << "NC, " << std::setprecision(2)  << themap["nc"]->Integral() / themap["total"]->Integral()*100. << "%";
      if (_draw_nc) leg->AddEntry(themap["nc"],sstm.str().c_str(),"f");
      sstm.str("");

      sstm << "OUTFV, " << std::setprecision(2)  << themap["outfv"]->Integral() / themap["total"]->Integral()*100. << "%";
      if (_draw_outfv) leg->AddEntry(themap["outfv"],sstm.str().c_str(),"f");
      sstm.str("");

      sstm << "Cosmic, " << std::setprecision(2)  << themap["cosmic"]->Integral() / themap["total"]->Integral()*100. << "%";
      if (_draw_cosmic) leg->AddEntry(themap["cosmic"],sstm.str().c_str(),"f");
      sstm.str("");
    }
    leg->AddEntry(themap["total"],"MC Stat Unc.","f");
    

    return hs_trklen;

  }

  TH2D* CrossSectionCalculator2D::ProcessDataHisto(TH2D* histo) {

    histo->SetMarkerStyle(kFullCircle);
    histo->SetMarkerSize(0.6);

    return histo;

  }


  TLatex* CrossSectionCalculator2D::GetPOTLatex(double pot) {

    std::stringstream sstm2;
    sstm2 << "Accumulated POT: " << pot;
    std::string str = sstm2.str();

    TLatex* pot_latex_2 = new TLatex(.10, .92, str.c_str());
    pot_latex_2->SetTextFont(62);
    pot_latex_2->SetTextColor(kGray+2);
    pot_latex_2->SetNDC();
    pot_latex_2->SetTextSize(1/30.);
    pot_latex_2->SetTextAlign(10);//left adjusted
    //pot_latex_2->Draw();

    return pot_latex_2;
  
  }
  
}

#endif

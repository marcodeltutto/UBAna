#ifndef __BASE_CROSSSECTIONCALCULATOR2DPOLY_CXX__
#define __BASE_CROSSSECTIONCALCULATOR2DPOLY_CXX__

#include "CrossSectionCalculator2DPoly.h"

namespace Base {

  void CrossSectionCalculator2DPoly::Reset() 
  {

    _configured = false;

    //_scale_factor_mc_bnbcosmic = -999;
    //_scale_factor_bnbon = -999;
    //_scale_factor_extbnb = -999;
    //_scale_factor_mc_intimecosmic = -999;

    //_pot = -1;

    _prefix = "Not configured!";
    _label = "Not configured!";

    //_outdir = "NotConfigured";

    _hmap_bnbcosmic.clear();
    _h_bnbon = NULL;
    _h_extbnb = NULL;
    _h_intimecosmic = NULL;

    _h_eff_mumom_num = NULL;
    _h_eff_mumom_den = NULL;

    //_h_true_reco_mom = NULL;
  }

  void CrossSectionCalculator2DPoly::SetScaleFactors(double bnbcosmic, double bnbon, double extbnb, double dirt, double intimecosmic)
  {
    _scale_factor_mc_bnbcosmic = bnbcosmic;
    _scale_factor_bnbon = bnbon;
    _scale_factor_extbnb = extbnb;
    _scale_factor_mc_dirt = dirt;
    _scale_factor_mc_intimecosmic = intimecosmic;

    _configured = true;
  }

  void CrossSectionCalculator2DPoly::SetPOT(double pot)
  {
    _pot = pot;
  }

  void CrossSectionCalculator2DPoly::SetNameAndLabel(std::string name, std::string label)
  {
    _prefix = name;
    _label = label;
  }

  void CrossSectionCalculator2DPoly::SetOutDir(std::string dir)
  {
    std::string out_folder_base = std::getenv("MYSW_OUTDIR");

    _outdir = out_folder_base + dir;

    auto now = std::time(nullptr);
    char buf[sizeof("YYYY-MM-DD_HH-MM-SS")];
    std::string timestamp = std::string(buf,buf + std::strftime(buf,sizeof(buf),"%F_%H-%M-%S",std::gmtime(&now)));

    _folder = _outdir + "_" + timestamp + "/";

    system(("mkdir " + _folder).c_str());

  }

  void CrossSectionCalculator2DPoly::SetCovarianceMatrix(TH2D h)
  {
    _covariance_matrix = h;
    _covariance_matrix_is_set = true;

    if (_frac_covariance_matrix_is_set) {
      LOG_CRITICAL() << "You have set both a covariance and a fractional covariance matrix. Only one is allowed." << std::endl;
      throw std::exception();
    }
  }

  void CrossSectionCalculator2DPoly::SetFractionalCovarianceMatrix(TH2D h)
  {
    _frac_covariance_matrix = h;
    _frac_covariance_matrix_is_set = true;

    if (_covariance_matrix_is_set) {
      LOG_CRITICAL() << "You have set both a covariance and a fractional covariance matrix. Only one is allowed." << std::endl;
      throw std::exception();
    }
  }

  void CrossSectionCalculator2DPoly::PrintConfig() {

    std::cout << "--- CrossSectionCalculator2DPoly:" << std::endl;
    std::cout << "---   _scale_factor_mc_bnbcosmic     = " << _scale_factor_mc_bnbcosmic << std::endl;
    std::cout << "---   _scale_factor_bnbon            = " << _scale_factor_bnbon << std::endl;
    std::cout << "---   _scale_factor_extbnb           = " << _scale_factor_extbnb << std::endl;
    std::cout << "---   _scale_factor_mc_intimecosmic  = " << _scale_factor_mc_intimecosmic << std::endl;
    std::cout << "---   _pot                           = " << _pot << std::endl;

  }

  void CrossSectionCalculator2DPoly::SetHistograms(std::map<std::string,UBTH2Poly*> bnbcosmic, UBTH2Poly* bnbon, UBTH2Poly* extbnb, std::map<std::string,UBTH2Poly*> dirt, UBTH2Poly* intimecosmic) 
  {

    // _hmap_bnbcosmic = bnbcosmic;
    // _hmap_dirt = dirt;
    // _h_bnbon = bnbon;
    // _h_extbnb = extbnb;
    // _h_intimecosmic = intimecosmic;


    for (auto it : bnbcosmic) {
      std::string this_prefix = it.second->GetName();
      _hmap_bnbcosmic[it.first] = (UBTH2Poly*)it.second->Clone((this_prefix + it.first + "_xsec_int_bnbcosmic").c_str());
    }

    for (auto it : dirt) {
      std::string this_prefix = it.second->GetName();
      _hmap_dirt[it.first] = (UBTH2Poly*)it.second->Clone((this_prefix + it.first + "_xsec_int_dirt").c_str());
    }

    _dirt_is_set = false;
    if (dirt.size() != 0) {
      LOG_INFO() << "Dirt Histograms Set Up" << std::endl;
      _dirt_is_set = true;
    }
    
    if (bnbon != NULL) {
      _h_bnbon = (UBTH2Poly*)bnbon->Clone("_h_bnbon");
    }
    if (extbnb != NULL) {
      _h_extbnb = (UBTH2Poly*)extbnb->Clone("_h_extbnb");
    }
    if (intimecosmic != NULL) {
      _h_intimecosmic = (UBTH2Poly*)intimecosmic->Clone("_h_intimecosmic");
    }

  }

  void CrossSectionCalculator2DPoly::SetTruthHistograms(UBTH2Poly* num, UBTH2Poly* den)
  {
    _h_eff_mumom_num = num;
    _h_eff_mumom_den = den;
  }

  void CrossSectionCalculator2DPoly::SetTruthXSec(UBTH2Poly* xsec) 
  {
    _truth_xsec = xsec;
  }

  double CrossSectionCalculator2DPoly::EstimateFlux(std::string flux_file_prefix, std::string histogram_file_prefix) 
  {
    std::string flux_file = std::getenv("MYSW_DIR");
    //flux_file += "/Flux/numode_bnb_470m_r200.root";
    flux_file += "/Flux/";
    flux_file += flux_file_prefix;
    LOG_DEBUG() << "Using flux file: " << flux_file << std::endl;

    LOG_DEBUG() << "Flux correction weight: " << _flux_correction_weight << std::endl;

    TFile * f = TFile::Open(flux_file.c_str());
    f->cd();
    TH1D * h_flux_numu = (TH1D*) f->Get(histogram_file_prefix.c_str());//f->Get("numu");    //h_flux_numu->Scale(_pot/1.e20);
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


    // Save on latex file too
    std::ofstream flux_latex;
    flux_latex.open (_folder + "_flux.tex", std::ofstream::out | std::ofstream::trunc);
    for (int i = 0; i < 34; i++) {
      flux_latex << "$[" << h_flux_numu->GetBinLowEdge(i+1) << ", " << h_flux_numu->GetBinLowEdge(i+1) + h_flux_numu->GetBinWidth(i+1) << ")$ & " << h_flux_numu->GetBinContent(i+1) 
      << " & $[" << h_flux_numu->GetBinLowEdge(i+1+34) << ", " << h_flux_numu->GetBinLowEdge(i+1+34) + h_flux_numu->GetBinWidth(i+1+34) << ")$ & " << h_flux_numu->GetBinContent(i+1+34) 
      << " & $[" << h_flux_numu->GetBinLowEdge(i+1+34*2) << ", " << h_flux_numu->GetBinLowEdge(i+1+34*2) + h_flux_numu->GetBinWidth(i+1+34*2) << ")$ & " << h_flux_numu->GetBinContent(i+1+34*2)
      << " & $[" << h_flux_numu->GetBinLowEdge(i+1+34*3) << ", " << h_flux_numu->GetBinLowEdge(i+1+34*3) + h_flux_numu->GetBinWidth(i+1+34*3) << ")$ & " << h_flux_numu->GetBinContent(i+1+34*3) << "\\\\" << std::endl;
    }
    flux_latex.close();

    
    _flux = h_flux_numu->Integral();

    f->Close();

    LOG_INFO() << "Flux estimated to be " << _flux << std::endl;

    return _flux;
  }

  void CrossSectionCalculator2DPoly::SetSmearingMatrix(TMatrix s)
  {
    _S.ResizeTo(s.GetNrows(), s.GetNcols());
    _S = s;
  }


  void CrossSectionCalculator2DPoly::Smear()
  {

    int n_bins = _h_eff_mumom_den->GetNumberOfBins();

    LOG_DEBUG() << "Number of bins: " << n_bins << std::endl;

    TMatrix matrix_angle_mom_den_truth; matrix_angle_mom_den_truth.Clear(); matrix_angle_mom_den_truth.ResizeTo(n_bins + 1, 1);
    TMatrix matrix_angle_mom_num_truth; matrix_angle_mom_num_truth.Clear(); matrix_angle_mom_num_truth.ResizeTo(n_bins + 1, 1);

    for (int i = 0; i < n_bins; i++) {

      matrix_angle_mom_den_truth[i][0] = _h_eff_mumom_den->GetBinContent(i+1);
      matrix_angle_mom_num_truth[i][0] = _h_eff_mumom_num->GetBinContent(i+1);

    }

    // Adding overflows
    double den_overflow = 0;
    double num_overflow = 0;
    for (int i = -9; i < 0; i++) den_overflow += _h_eff_mumom_den->GetBinContent(i);
    for (int i = -9; i < 0; i++) num_overflow += _h_eff_mumom_num->GetBinContent(i);
    matrix_angle_mom_den_truth[n_bins][0] = den_overflow; // Last bin contains overflows
    matrix_angle_mom_num_truth[n_bins][0] = num_overflow; // Last bin contains overflows


    TCanvas * c_truth_den = new TCanvas;
    _h_eff_mumom_den->SetMarkerColor(kWhite);
    _h_eff_mumom_den->SetMarkerSize(1.6);
    _h_eff_mumom_den->SetTitle("Generated");
    _h_eff_mumom_den->GetXaxis()->SetTitle("cos(#theta_{#mu}^{truth})");
    _h_eff_mumom_den->GetYaxis()->SetTitle("p_{#mu}^{truth}");
    _h_eff_mumom_den->GetXaxis()->SetTitleOffset(0.8);
    _h_eff_mumom_den->GetYaxis()->SetTitleOffset(0.8);
    _h_eff_mumom_den->Draw("colz");

    TString name = _folder +_prefix + "all_truth";
    c_truth_den->SaveAs(name + ".pdf");
    c_truth_den->SaveAs(name + ".C");

    TCanvas * c_truth_num = new TCanvas;
    _h_eff_mumom_num->SetMarkerColor(kWhite);
    _h_eff_mumom_num->SetMarkerSize(1.6);
    _h_eff_mumom_num->SetTitle("Selected");
    _h_eff_mumom_num->GetXaxis()->SetTitle("cos(#theta_{#mu}^{truth})");
    _h_eff_mumom_num->GetYaxis()->SetTitle("p_{#mu}^{truth}");
    _h_eff_mumom_num->GetXaxis()->SetTitleOffset(0.8);
    _h_eff_mumom_num->GetYaxis()->SetTitleOffset(0.8);
    _h_eff_mumom_num->Draw("colz");

    name = _folder +_prefix + "selected_truth";
    c_truth_num->SaveAs(name + ".pdf");
    c_truth_num->SaveAs(name + ".C");


    //
    // Smearing 
    //

    TMatrix matrix_angle_mom_den_smear = _S * matrix_angle_mom_den_truth;
    TMatrix matrix_angle_mom_num_smear = _S * matrix_angle_mom_num_truth;



    //
    // Make a plottable histo of the smeared distributions
    //
    UBTH2Poly * h_eff_den_smear = (UBTH2Poly*) _h_eff_mumom_den->Clone("h_eff_den_smear");
    UBTH2Poly * h_eff_num_smear = (UBTH2Poly*) _h_eff_mumom_num->Clone("h_eff_num_smear");
    for (int i = 0; i < n_bins; i++) {
      h_eff_den_smear->SetBinContent(i+1, matrix_angle_mom_den_smear[i][0]);
      h_eff_num_smear->SetBinContent(i+1, matrix_angle_mom_num_smear[i][0]);
    }

    h_eff_den_smear->SetBinContent(-2, matrix_angle_mom_den_smear[n_bins][0]); // Set overflows to bin number -2 (just convention)
    h_eff_num_smear->SetBinContent(-2, matrix_angle_mom_num_smear[n_bins][0]); // Set overflows to bin number -2 (just convention)


    TCanvas * c_smear_den = new TCanvas;
    h_eff_den_smear->SetMarkerColor(kWhite);
    h_eff_den_smear->SetMarkerSize(1.6);
    h_eff_den_smear->SetTitle("Generated");
    h_eff_den_smear->GetXaxis()->SetTitle("cos(#theta_{#mu}^{reco})");
    h_eff_den_smear->GetYaxis()->SetTitle("p_{#mu}^{reco}");
    h_eff_den_smear->GetXaxis()->SetTitleOffset(0.8);
    h_eff_den_smear->GetYaxis()->SetTitleOffset(0.8);
    h_eff_den_smear->Draw("colz");

    name = _folder +_prefix + "all_smeared";
    c_smear_den->SaveAs(name + ".pdf");
    c_smear_den->SaveAs(name + ".C");


    TCanvas * c_smear_num = new TCanvas;
    h_eff_num_smear->SetMarkerColor(kWhite);
    h_eff_num_smear->SetMarkerSize(1.6);
    h_eff_num_smear->SetTitle("Selected");
    h_eff_num_smear->GetXaxis()->SetTitle("cos(#theta_{#mu}^{reco})");
    h_eff_num_smear->GetYaxis()->SetTitle("p_{#mu}^{reco}");
    h_eff_num_smear->GetXaxis()->SetTitleOffset(0.8);
    h_eff_num_smear->GetYaxis()->SetTitleOffset(0.8);
    h_eff_num_smear->Draw("colz");

    name = _folder +_prefix + "selected_smeared";
    c_smear_num->SaveAs(name + ".pdf");
    c_smear_num->SaveAs(name + ".C");






    double level = 0.683; // 1 sigma
    double alpha = (1.0 - level)/2;


    //
    // Efficiency (true) - Just a plot
    //

    UBTH2Poly * eff_true = (UBTH2Poly*) _h_eff_mumom_num->Clone("eff_true");

    for (int bin = 1; bin <= eff_true->GetNumberOfBins(); bin++) {

        double average = _h_eff_mumom_num->GetBinContent(bin) / _h_eff_mumom_den->GetBinContent(bin);
        double sigma = std::sqrt(average * (1 - average) / _h_eff_mumom_den->GetBinContent(bin));
        double delta = ROOT::Math::normal_quantile(1 - alpha, sigma);

        eff_true->SetBinContent(bin, average);
        eff_true->SetBinError(bin, delta);

    }

    TCanvas * c_eff_true = new TCanvas;
    eff_true->SetMarkerColor(kWhite);
    eff_true->SetMarkerSize(1.6);
    eff_true->SetTitle("Selected");
    eff_true->GetXaxis()->SetTitle("cos(#theta_{#mu}^{reco})");
    eff_true->GetYaxis()->SetTitle("p_{#mu}^{reco}");
    eff_true->SetMaximum(1.0);
    eff_true->SetMinimum(0.0);
    eff_true->GetXaxis()->SetTitleOffset(0.8);
    eff_true->GetYaxis()->SetTitleOffset(0.8);
    eff_true->Draw("colz");

    name = _folder +_prefix + "efficiency_true";
    c_eff_true->SaveAs(name + ".pdf");
    c_eff_true->SaveAs(name + ".C");



    //
    // Efficiency (reco) - Used for cross section extraction (_eff)
    //

    _eff = (UBTH2Poly*) h_eff_num_smear->Clone("_eff");

    for (int bin = 1; bin <= _eff->GetNumberOfBins(); bin++) {

        double average = h_eff_num_smear->GetBinContent(bin) / h_eff_den_smear->GetBinContent(bin);
        double sigma = std::sqrt(average * (1 - average) / h_eff_den_smear->GetBinContent(bin));
        double delta = ROOT::Math::normal_quantile(1 - alpha, sigma);

        _eff->SetBinContent(bin, average);
        _eff->SetBinError(bin, delta);
        LOG_DEBUG() << "bin = " << bin << ", average = " << average << ", sigma = " << sigma << ", delta = " << delta << std::endl;

        // Turn off uncertainties for MC, they are included with cov matrix
        _eff->SetBinError(bin, 0);
    }


    TCanvas * c_eff_reco = new TCanvas;
    UBTH2Poly* eff_reco = (UBTH2Poly*) _eff->Clone("eff_reco");
    eff_reco->SetMarkerColor(kWhite);
    eff_reco->SetMarkerSize(1.6);
    eff_reco->SetTitle("Selected");
    eff_reco->GetXaxis()->SetTitle("cos(#theta_{#mu}^{reco})");
    eff_reco->GetYaxis()->SetTitle("p_{#mu}^{reco}");
    eff_reco->SetMaximum(1.0);
    eff_reco->SetMinimum(0.0);
    eff_reco->GetXaxis()->SetTitleOffset(0.8);
    eff_reco->GetYaxis()->SetTitleOffset(0.8);
    eff_reco->Draw("colz");

    name = _folder +_prefix + "efficiency_smear";
    c_eff_reco->SaveAs(name + ".pdf");
    c_eff_reco->SaveAs(name + ".C");

    LOG_DEBUG() << "bin 40. Eff = " << _eff->GetBinContent(40) << " +- " << _eff->GetBinError(40) << std::endl;

  }



  void CrossSectionCalculator2DPoly::ProcessPlots() 
  {

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
    _h_data_sub = (UBTH2Poly*)_h_bnbon->Clone("_h_data_sub");
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
      UBTH2Poly * h_empty = (UBTH2Poly*) _hmap_bnbcosmic["total"]->Clone("empty");
      h_empty->Reset("");

      _hmap_bnbcosmic["dirt"] = h_empty;
      _hmap_bnbcosmic["outfv_dirt"] = h_empty;
      _hmap_bnbcosmic["cosmic_dirt"] = h_empty;
    }

  }


  UBTH2Poly* CrossSectionCalculator2DPoly::ExtractCrossSection(std::vector<std::string> bkg_prefixs, std::string xaxis_label, std::string yaxis_label, std::string zaxis_label, bool make_plots) 
  {

    //
    // The two histograms we acually need: MC and data (bkg subtracted)
    //

    UBTH2Poly* h_mc = _hmap_bnbcosmic["signal"];
    UBTH2Poly* h_data = (UBTH2Poly*)_h_bnbon->Clone("h_data");
    h_mc->SetTitle(_label.c_str());
    h_data->Sumw2();

   

    if (h_mc->GetSumw2N() == 0) { 
      LOG_WARNING() << "MC cross section histogram does not have Sum2w active." << std::endl;
    }


    // Turn off uncertainties for MC, they are included with cov matrix
    for (auto name : bkg_prefixs) {
      if (name == "beam-off") continue;
      for (int i = 0; i < _hmap_bnbcosmic[name]->GetNumberOfBins(); i++) { 
        _hmap_bnbcosmic[name]->SetBinError(i + 1, 0);
      }
    }




    // LOG_INFO() << "Subtracting backgrouds: ";
    for (auto name : bkg_prefixs) 
    {
      // std::cout << name << ", ";
      h_data->Add(_hmap_bnbcosmic[name], -1.);
      if (_hmap_bnbcosmic[name]->GetSumw2N() == 0) {
        LOG_WARNING() << "Bkg " << name << " does not have Sum2w active." << std::endl;
      }
    }
    // std::cout << std::endl;







    //
    // Divide by efficiency
    //
    UBTH2Poly * h_eff = _eff;

    for (int i = 1; i < h_eff->GetNumberOfBins()+1; i++) {
        LOG_CRITICAL() << "efficiency in bin " << i << " is " << h_eff->GetBinContent(i) << std::endl;
    }

    h_mc->Divide(h_eff);
    h_data->Divide(h_eff);




    //
    // Divide by flux, and N_target and bin width
    //

    // LOG_INFO() << "FLUX: " << _flux << ", N_target: " << _n_target << ", FLUX x N_target: " << _flux*_n_target << std::endl;

    double den_data = _flux * _n_target_data * 1e-38;
    double den_mc   = _flux * _n_target_mc   * 1e-38;

    h_mc->Scale(1. / den_mc, "width");
    h_data->Scale(1. / den_data, "width");

    


    // for (int bin_i = 1; bin_i < h_data->GetNbinsX()+1; bin_i++) {
    //   for (int bin_j = 1; bin_j < h_data->GetNbinsY()+1; bin_j++) {
    //     if (h_data->GetBinContent(bin_i, bin_j) <= 0.) {
    //       LOG_INFO() << "******************************************" << std::endl;
    //       LOG_INFO() << "Cross Section in bin " << bin_i-1 << ", " << bin_j-1 << " is <= 0, value: " << h_data->GetBinContent(bin_i, bin_j) << std::endl;
    //       LOG_INFO() << "******************************************" << std::endl;
    //     }
    //   }
    // }





    // Do it also for the truth xsec
    //_truth_xsec->Scale(1. / den, "width");

    LOG_INFO() << "MC Integral: " << h_mc->Integral() << std::endl;
    LOG_INFO() << "Data Integral: " << h_data->Integral() << std::endl;


    //
    // Add systs uncertainties (if cov. matrix is set)
    //

    if (_extra_fractional_uncertainty != 0) {
      LOG_INFO() << "Adding an extra uncertainty of " << _extra_fractional_uncertainty * 100 << "%" << std::endl;
    }

    _h_syst_unc = (UBTH2Poly*) h_data->Clone("h_syst_unc");

    if (_frac_covariance_matrix_is_set) {

      _covariance_matrix = * ( (TH2D*)_frac_covariance_matrix.Clone("_covariance_matrix") );
      _covariance_matrix.Reset();

      // Loop over the bins and multiply this fractional covariance matrix by the xsec
      // so to obtain a covariance matrix 
      for (int a = 0; a < _frac_covariance_matrix.GetNbinsX(); a++) {

        for (int b = 0; b < _frac_covariance_matrix.GetNbinsX(); b++) {

          _covariance_matrix.SetBinContent(a+1, b+1, _frac_covariance_matrix.GetBinContent(a+1, b+1) * (h_data->GetBinContent(a+1) * h_data->GetBinContent(b+1)) );

        }
      }

      _covariance_matrix_is_set = true;
    }


    if (_covariance_matrix_is_set) {

      // Just to set the right bins:
      _syst_cov_matrix_total = (TH2D*)_covariance_matrix.Clone("_cov_matrix_total");
      _syst_frac_cov_matrix_total = (TH2D*)_covariance_matrix.Clone("_frac_cov_matrix_total");
      _syst_corr_matrix_total = (TH2D*)_covariance_matrix.Clone("_corr_matrix_total");

      _stat_cov_matrix_total = (TH2D*)_covariance_matrix.Clone("_cov_matrix_total");
      _stat_frac_cov_matrix_total = (TH2D*)_covariance_matrix.Clone("_frac_cov_matrix_total");
      _stat_cov_matrix_total->Reset(); _stat_frac_cov_matrix_total->Reset();

      _tot_cov_matrix_total = (TH2D*)_covariance_matrix.Clone("_cov_matrix_total");
      _tot_frac_cov_matrix_total = (TH2D*)_covariance_matrix.Clone("_frac_cov_matrix_total");
      _tot_corr_matrix_total = (TH2D*)_covariance_matrix.Clone("_corr_matrix_total");
      _tot_cov_matrix_total->Reset(); _tot_frac_cov_matrix_total->Reset(); _tot_corr_matrix_total->Reset();

 
      for (int a = 0; a < _covariance_matrix.GetNbinsX(); a++) {

        for (int b = 0; b < _covariance_matrix.GetNbinsX(); b++) {

          // The statistical uncertainty squared
          double unc_stat_2 = h_data->GetBinError(a+1) * h_data->GetBinError(b+1);
          if (a != b) unc_stat_2 = 0.;

          // The systematic uncertainty squared
          double unc_syst_2 = _covariance_matrix.GetBinContent(a+1, b+1);

          // The extra systematic uncertainty squared (POT normalisation, ...)
          double extra_unc_2 = _extra_fractional_uncertainty * h_data->GetBinContent(a+1)   *    _extra_fractional_uncertainty * h_data->GetBinContent(b+1);

          // The total uncertainty (quadrature sum)
          double unc_tot = std::sqrt(unc_stat_2 + unc_syst_2 + extra_unc_2);
          double unc_tot2 = unc_stat_2 + unc_syst_2 + extra_unc_2;

          if (a == b) {
            LOG_INFO() << "Bin " << a + 1 << " - stat: " << std::sqrt(unc_stat_2) << ", syst: " << std::sqrt(unc_syst_2) << ", tot: " << unc_tot << std::endl;
            _h_syst_unc->SetBinError(a+1, unc_tot); 

            _stat_cov_matrix_total->SetBinContent(a+1, b+1, unc_stat_2);
            _stat_frac_cov_matrix_total->SetBinContent(a+1, b+1, unc_stat_2 / (h_data->GetBinContent(a+1) * h_data->GetBinContent(a+1)));
          }

          // Also construct the total syst covariance matrix
          double total_syst_unc_2 = unc_syst_2 + extra_unc_2;

          _syst_cov_matrix_total->SetBinContent(a+1, b+1, total_syst_unc_2);
          if (h_data->GetBinContent(a+1) != 0. && h_data->GetBinContent(b+1) != 0.) {
            _syst_frac_cov_matrix_total->SetBinContent(a+1, b+1, (total_syst_unc_2) / (h_data->GetBinContent(a+1) * h_data->GetBinContent(b+1)));
          } else {
            _syst_frac_cov_matrix_total->SetBinContent(a+1, b+1, 0.);
          }

          // Also construct the total covariance matrix
          _tot_cov_matrix_total->SetBinContent(a+1, b+1, unc_tot2);
          if (h_data->GetBinContent(a+1) != 0. && h_data->GetBinContent(b+1) != 0.) {
            _tot_frac_cov_matrix_total->SetBinContent(a+1, b+1, (unc_tot2) / (h_data->GetBinContent(a+1) * h_data->GetBinContent(b+1)));
          } else {
            _tot_frac_cov_matrix_total->SetBinContent(a+1, b+1, 0.);
          }

        } // j
      } // i

      // And also the correlation matrix
      for (int a = 0; a < _covariance_matrix.GetNbinsX(); a++) {
        for (int b = 0; b < _covariance_matrix.GetNbinsX(); b++) {

          if (_syst_cov_matrix_total->GetBinContent(a+1, a+1) != 0. && _syst_cov_matrix_total->GetBinContent(b+1, b+1) != 0.) {
            _syst_corr_matrix_total->SetBinContent(a+1, b+1, _syst_cov_matrix_total->GetBinContent(a+1, b+1) / (std::sqrt(_syst_cov_matrix_total->GetBinContent(a+1, a+1)) * std::sqrt(_syst_cov_matrix_total->GetBinContent(b+1, b+1))));
          } else {
            _syst_corr_matrix_total->SetBinContent(a+1, b+1, 0.);
          }

          if (_tot_cov_matrix_total->GetBinContent(a+1, a+1) != 0. && _tot_cov_matrix_total->GetBinContent(b+1, b+1) != 0.) {
            _tot_corr_matrix_total->SetBinContent(a+1, b+1, _tot_cov_matrix_total->GetBinContent(a+1, b+1) / (std::sqrt(_tot_cov_matrix_total->GetBinContent(a+1, a+1)) * std::sqrt(_tot_cov_matrix_total->GetBinContent(b+1, b+1))));
          } else {
            _tot_corr_matrix_total->SetBinContent(a+1, b+1, 0.);
          }
        }
      }
    }


 
    _h_data = h_data;
    _h_mc = h_mc;

    if (make_plots) MakeAllCrossSectionPlots(xaxis_label, yaxis_label, zaxis_label);
    if (_do_chi2) CalculateChi2();

    return _h_data;
  }



  void CrossSectionCalculator2DPoly::MakeAllCrossSectionPlots(std::string xaxis_label, std::string yaxis_label, std::string zaxis_label)
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
    c_xsec_mc->SetRightMargin(0.15);
    c_xsec_mc->SetBottomMargin(0.13);
    _h_mc->GetXaxis()->SetTitle(xaxis_label.c_str());
    _h_mc->GetYaxis()->SetTitle(yaxis_label.c_str());
    _h_mc->GetZaxis()->SetTitle(zaxis_label.c_str());
    _h_mc->GetYaxis()->SetTitleOffset(0.77);
    _h_mc->Draw("colz");

    // sim->Draw();

    // xsec_label->Draw();
    PlottingTools::DrawSimulation();

    TString name = _folder +_prefix + "_xsec_mc";
    c_xsec_mc->SaveAs(name + ".pdf");
    c_xsec_mc->SaveAs(name + ".C","C");





    //
    // Plot the cross section for DATA
    //

    TCanvas * c_xsec_data = new TCanvas();
    c_xsec_data->SetRightMargin(0.15);
    c_xsec_data->SetBottomMargin(0.13);
    //h_data->SetMarkerStyle(kFullCircle);
    //h_data->SetMarkerSize(0.6);
    _h_data->SetFillColor(kGreen+2);
    _h_data->SetLineColor(kBlack);
    _h_data->GetXaxis()->SetTitle(xaxis_label.c_str());
    _h_data->GetYaxis()->SetTitle(yaxis_label.c_str());
    _h_data->GetZaxis()->SetTitle(zaxis_label.c_str());
    _h_data->GetYaxis()->SetTitleOffset(0.77);

    // xsec_label->Draw();
    prelim->Draw();

    _h_data->Draw("colz");
    
    PlottingTools::DrawPreliminary();
 
    name = _folder +_prefix + "_xsec_data";
    c_xsec_data->SaveAs(name + ".pdf");
    c_xsec_data->SaveAs(name + ".C","C");














    //
    // Project in cos(theta) bins
    //

    std::vector<std::string> costhetamu_ranges = {"-1.00 #leq cos(#theta_{#mu}^{reco}) < -0.50",
                                                  "-0.50 #leq cos(#theta_{#mu}^{reco}) < 0.00",
                                                  "0.00 #leq cos(#theta_{#mu}^{reco}) < 0.27",
                                                  "0.27 #leq cos(#theta_{#mu}^{reco}) < 0.45",
                                                  "0.45 #leq cos(#theta_{#mu}^{reco}) < 0.62",
                                                  "0.62 #leq cos(#theta_{#mu}^{reco}) < 0.76",
                                                  "0.76 #leq cos(#theta_{#mu}^{reco}) < 0.86",
                                                  "0.86 #leq cos(#theta_{#mu}^{reco}) < 0.94",
                                                  "0.94 #leq cos(#theta_{#mu}^{reco}) < 1.00",
                                                  "nan #leq cos(#theta_{#mu}^{reco}) < nan",
                                                  "nan #leq cos(#theta_{#mu}^{reco}) < nan",};


    int x_bins = _h_data->GetNBinsX();
    LOG_INFO() << "n bins x " << x_bins << std::endl;

    int horizontal_division = 2;
    int vertical_division = floor(x_bins / 2.);

    if (x_bins / 2. != floor(x_bins / 2.)) vertical_division++;

    LOG_INFO() << "Horizontal divisions " << horizontal_division << std::endl;
    LOG_INFO() << "Vertical divisions " << vertical_division << std::endl;

    TCanvas *c_xsec_split = new TCanvas("c_xsec_split", "multipads",0,45,1006,1150);
    c_xsec_split->Divide(horizontal_division, vertical_division, 0.02, 0.01);

    std::vector<int> bin_numbers;


    for (int i = 0; i < x_bins; i++) {
      _xsec_data_histos.emplace_back(*_h_data->ProjectionY("fuck", i+1, bin_numbers));
      _xsec_data_unc_histos.emplace_back(*_h_syst_unc->ProjectionY("fuck", i+1, bin_numbers));
      _xsec_mc_histos.emplace_back(*_h_mc->ProjectionY("fuck", i+1, bin_numbers));
      if (_add_alt_mc_xsec) _xsec_mc_alt_histos.emplace_back(*_h_alt_mc_xsec->ProjectionY("fuck", i+1, bin_numbers));
    }



    for (size_t i = 0; i < _xsec_mc_histos.size(); i++) {

      c_xsec_split->cd(i+1);

      gPad->SetBottomMargin(0.15);
      gPad->SetLeftMargin(0.18);
      gPad->SetRightMargin(0.14);
      gPad->SetTopMargin(0.13);

      _xsec_mc_histos.at(i).SetTitle(costhetamu_ranges.at(i).c_str());
      _xsec_mc_histos.at(i).GetXaxis()->SetTitle("p_{#mu}^{reco} [GeV]");
      _xsec_mc_histos.at(i).GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{#mu}^{reco}dcos(#theta_{#mu}^{reco})} [10^{-38} #frac{cm^{2}}{GeV Nucleon}]");
      _xsec_mc_histos.at(i).GetXaxis()->CenterTitle();
      _xsec_mc_histos.at(i).GetYaxis()->CenterTitle();
      _xsec_mc_histos.at(i).SetLineColor(kGreen+2);
      _xsec_mc_histos.at(i).SetFillColor(29);

      _xsec_mc_histos.at(i).GetXaxis()->SetTitleOffset(0.92);
      _xsec_mc_histos.at(i).GetXaxis()->SetTitleSize(0.07);
      _xsec_mc_histos.at(i).GetXaxis()->SetLabelSize(0.06);

      _xsec_mc_histos.at(i).GetYaxis()->SetTitleOffset(0.90);
      _xsec_mc_histos.at(i).GetYaxis()->SetTitleSize(0.06);
      _xsec_mc_histos.at(i).GetYaxis()->SetLabelSize(0.06);

      gStyle->SetTitleFontSize(0.07);
      gStyle->SetTitleStyle(0);

      _xsec_mc_histos.at(i).Draw("E2");
      TH1D* h_main = (TH1D*) _xsec_mc_histos.at(i).Clone("h_main");
      h_main->SetLineColor(kGreen+2);
      h_main->SetFillColor(0); // fully transparent
      h_main->Draw("histo same");

      // _xsec_mc_histos.at(i).SetMinimum(0.);

      // if (i == 0) {
      //   _xsec_mc_histos.at(i).SetMaximum(0.4);
      // } else if (i == 1) {
      //   _xsec_mc_histos.at(i).SetMaximum(0.4);
      // } 

      
      double min = std::min(_xsec_data_histos.at(i).GetMinimum(), _xsec_mc_histos.at(i).GetMinimum());
      double max = std::max(_xsec_data_histos.at(i).GetMaximum(), _xsec_mc_histos.at(i).GetMaximum());

      _xsec_mc_histos.at(i).SetMinimum(min - std::abs(min) * 0.4);
      _xsec_mc_histos.at(i).SetMaximum(max * 1.6);


      // The alternative cross section
      if (_add_alt_mc_xsec) {
        _xsec_mc_alt_histos.at(i).SetLineColor(kBlue+1);
        _xsec_mc_alt_histos.at(i).SetFillColor(38);
        _xsec_mc_alt_histos.at(i).Draw("E2 same");

        TH1D* h_alt_mc_xsec_main = (TH1D*) _xsec_mc_alt_histos.at(i).Clone("h_alt_mc_xsec_main");
        h_alt_mc_xsec_main->SetLineColor(kBlue+1);
        h_alt_mc_xsec_main->SetFillColor(0); // fully transparent
        h_alt_mc_xsec_main->Draw("histo same");
      }

      // The outer uncertainty bar
      _xsec_data_unc_histos.at(i).SetMarkerStyle(20);
      _xsec_data_unc_histos.at(i).SetMarkerSize(0.1);
      _xsec_data_unc_histos.at(i).SetFillColor(0); // fully transparent
      _xsec_data_unc_histos.at(i).Draw("E1 X0 same");

      // The proper data points
      _xsec_data_histos.at(i).SetMarkerStyle(20);
      _xsec_data_histos.at(i).SetMarkerSize(0.5);
      _xsec_data_histos.at(i).SetFillColor(0); // fully transparent
      _xsec_data_histos.at(i).Draw("E1 X0 same");
      // _xsec_data_histos.at(i).Draw("histo same");

      // if (i == 0) {
      //   TLegend *l;
      //   l = new TLegend(0.3671979,0.67415,0.7178785,0.8019232,NULL,"brNDC");
      //   l->SetFillColor(0);
      //   l->SetFillStyle(0);
      //   l->SetTextSize(0.03407284);
      //   l->AddEntry(&_xsec_mc_histos.at(i), "GENIE Default + Emp. MEC (Stat. Unc.)");
      //   l->AddEntry(&_xsec_data_histos.at(i), "Measured (Stat. Unc.)", "ep");
      //   l->Draw();
      // }
    }
    // PlottingTools::DrawPreliminaryXSec();

    // Add a legend
    int legend_pad = 0;
    if (x_bins / 2. != floor(x_bins / 2.)) legend_pad = horizontal_division * vertical_division; // Last empty pad
    else legend_pad = 1; // First pad

    c_xsec_split->cd(legend_pad);
    TLegend *leg = new TLegend(0.1275766,0.3250297,0.7966395,0.6759589,NULL,"brNDC");
    leg->SetBorderSize(0);
    // leg->SetTextAlign(22);
    leg->SetTextSize(0.08402531);
    leg->SetLineColor(1);
    leg->SetLineStyle(1);
    leg->SetLineWidth(1);
    leg->SetFillColor(0);
    leg->SetFillStyle(0);
    leg->AddEntry(&_xsec_mc_histos.at(0), "GENIE Default + Emp. MEC (Stat. Unc.)");
    // leg->AddEntry(&_xsec_mc_histos.at(0), "Tune 1 (Stat. Unc.)");
    if (_add_alt_mc_xsec) {
      leg->AddEntry(&_xsec_mc_alt_histos.at(0), "GENIE Alternative (Stat. Unc.)");
    }
    if (_covariance_matrix_is_set && _covariance_matrix.GetBinContent(1, 1) != 0.) {
      leg->AddEntry(&_xsec_data_histos.at(0), "Measured (Stat. #oplus Syst. Unc.)", "ep");
      // leg->AddEntry(&_xsec_data_histos.at(0), "Tune 1 (No Flipped Tracks) (Stat #oplus Syst.)", "ep");
    } else {
      leg->AddEntry(&_xsec_data_histos.at(0), "Measured (Stat. Unc.)", "ep");
    }
    leg->Draw();





    TLatex* ub_label = new TLatex(0.154,0.73,"MicroBooNE");
    ub_label->SetNDC();
    ub_label->SetTextColor(kGray+2);
    ub_label->SetTextSize(0.10);
    ub_label->SetLineWidth(2);
    ub_label->SetTextFont(62);
    ub_label->Draw();

    std::stringstream sstm2;
    // sstm2 << _pot << " POT";
    sstm2 << "  Preliminary";
    // sstm2 << "  Internal";
    std::string str = sstm2.str();

    TLatex* ub_label2 = new TLatex(0.40,0.73, str.c_str());
    ub_label2->SetNDC();
    ub_label2->SetTextColor(kGray+2);
    ub_label2->SetTextSize(0.08);
    ub_label2->SetLineWidth(2);
    ub_label2->Draw();


    name = _folder +_prefix + "_xsec_anglesplit";
    c_xsec_split->SaveAs(name + ".pdf");
    c_xsec_split->SaveAs(name + ".C","C");







    //
    // Now plot the covariance matrices
    //

    if (_covariance_matrix_is_set) {

      gStyle->SetPalette(kDeepSea);
      gStyle->SetPaintTextFormat("4.2f");

      const Int_t Number = 9;
      Double_t Red[Number]    = { 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00 };
      Double_t Green[Number]  = { 1.00, 0.90, 0.80, 0.70, 0.60, 0.50, 0.40, 0.30, 0.20 };
      Double_t Blue[Number]   = { 1.00, 0.90, 0.80, 0.70, 0.60, 0.50, 0.40, 0.30, 0.20 };
      Double_t Stops[Number] =  { 0.00, 0.15, 0.30, 0.40, 0.50, 0.60, 0.70, 0.85, 1.00 };
      Int_t nb=100;
      TColor::CreateGradientColorTable(Number,Stops,Red,Green,Blue,nb);


      TH2F *h = new TH2F("h", "", _covariance_matrix.GetNbinsX(), 0, _covariance_matrix.GetNbinsX(),
        _covariance_matrix.GetNbinsY(), 0, _covariance_matrix.GetNbinsY());

      // h->SetMaximum(1);


      for (int i = 1; i <  _covariance_matrix.GetNbinsX()+1; i++) {
        std::ostringstream oss;
        oss << i;
        std::string label = oss.str();
        h->GetXaxis()->SetBinLabel(i,label.c_str());
        h->GetYaxis()->SetBinLabel(i,label.c_str());
      }

      h->GetXaxis()->SetLabelOffset(0.004);
      h->GetXaxis()->SetLabelSize(0.03);
      h->GetYaxis()->SetLabelOffset(0.004);
      h->GetYaxis()->SetLabelSize(0.03);
      h->GetXaxis()->SetTitle("Bin i");
      h->GetYaxis()->SetTitle("Bin j");
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

      Int_t * separators = _h_data->GetSeparators();
      Int_t separators_length = _h_data->GetSeparatorsLength();

      int n_bins = h->GetNbinsX();

      // Vertical lines
      Int_t sum = 0;
      for (Int_t s = 0; s < separators_length - 1; s++) {
        TLine *line = new TLine(separators[s] + sum, 0, separators[s] + sum, n_bins);
        line->SetLineColor(kRed);
        line->SetLineWidth(2);
        lines.emplace_back(line);
        sum += separators[s];
      }

      // Horizontal lines
      sum = 0;
      for (Int_t s = 0; s < separators_length - 1; s++) {
        TLine *line = new TLine(0, separators[s] + sum, n_bins, separators[s] + sum);
        line->SetLineColor(kRed);
        line->SetLineWidth(2);
        lines.emplace_back(line);
        sum += separators[s];
      }





      // 
      // Draw the proper matrices
      //

      float text_size = 0.9;

      TCanvas * cov_c = new TCanvas();
      cov_c->SetRightMargin(0.13);
      cov_c->SetFixedAspectRatio();
      _tot_cov_matrix_total->SetMarkerColor(kBlack);
      _tot_cov_matrix_total->SetMarkerSize(text_size);
      _tot_cov_matrix_total->GetXaxis()->CenterTitle();
      _tot_cov_matrix_total->GetYaxis()->CenterTitle();
      _tot_cov_matrix_total->GetXaxis()->SetTitle("Bin i,j");
      _tot_cov_matrix_total->GetYaxis()->SetTitle("Bin m,n");
      _tot_cov_matrix_total->GetXaxis()->SetTickLength(0);
      _tot_cov_matrix_total->GetYaxis()->SetTickLength(0);
      h->Draw();
      // _cov_matrix_total->Draw("colz text same");
      _tot_cov_matrix_total->Draw("colz same");

      for (auto l : lines)
        l->Draw();

      PlottingTools::DrawSimulationCovariance();
      name = _folder +_prefix + "_tot_covariance";
      cov_c->SaveAs(name + ".pdf");
      cov_c->SaveAs(name + ".C","C");



      TCanvas * cov_frac_c = new TCanvas();
      cov_frac_c->SetRightMargin(0.13);
      cov_frac_c->SetFixedAspectRatio();
      _tot_frac_cov_matrix_total->SetMarkerColor(kBlack);
      _tot_frac_cov_matrix_total->SetMarkerSize(text_size);
      _tot_frac_cov_matrix_total->GetXaxis()->CenterTitle();
      _tot_frac_cov_matrix_total->GetYaxis()->CenterTitle();
      _tot_frac_cov_matrix_total->GetXaxis()->SetTitle("Bin i,j");
      _tot_frac_cov_matrix_total->GetYaxis()->SetTitle("Bin m,n");
      _tot_frac_cov_matrix_total->GetXaxis()->SetTickLength(0);
      _tot_frac_cov_matrix_total->GetYaxis()->SetTickLength(0);
      // _tot_frac_cov_matrix_total->SetBinContent(10, 10, 10);
      // _frac_cov_matrix_total->SetMinimum(-5);
      // _frac_cov_matrix_total->SetMaximum(5);
      gPad->SetLogz(1);
      h->Draw();
      // _frac_cov_matrix_total->Draw("colz text same");
      _tot_frac_cov_matrix_total->Draw("colz same");

      for (auto l : lines)
        l->Draw();

      PlottingTools::DrawSimulationCovariance();
      name = _folder +_prefix + "_tot_fractional_covariance";
      cov_frac_c->SaveAs(name + ".pdf");
      cov_frac_c->SaveAs(name + ".C","C");

      gPad->SetLogz(0);


      TCanvas * corr_c = new TCanvas();
      corr_c->SetRightMargin(0.13);
      corr_c->SetFixedAspectRatio();
      _tot_corr_matrix_total->SetMarkerColor(kBlack);
      _tot_corr_matrix_total->SetMarkerSize(text_size);
      _tot_corr_matrix_total->GetXaxis()->CenterTitle();
      _tot_corr_matrix_total->GetYaxis()->CenterTitle();
      _tot_corr_matrix_total->GetXaxis()->SetTitle("Bin i,j");
      _tot_corr_matrix_total->GetYaxis()->SetTitle("Bin m,n");
      _tot_corr_matrix_total->GetXaxis()->SetTickLength(0);
      _tot_corr_matrix_total->GetYaxis()->SetTickLength(0);
      h->Draw();
      // _corr_matrix_total->Draw("colz text same");
      _tot_corr_matrix_total->Draw("colz same");

      for (auto l : lines)
        l->Draw();

      PlottingTools::DrawSimulationCovariance();
      name = _folder +_prefix + "_tot_correlation";
      corr_c->SaveAs(name + ".pdf");
      corr_c->SaveAs(name + ".C","C");

      gStyle->SetPalette(kRainBow);
    }

  }





  void CrossSectionCalculator2DPoly::CalculateChi2() {

    // _tot_cov_matrix_total is the total covariance matrix. 
    // Need to invert this first.

    LOG_NORMAL() << "Calculating Chi2." << std::endl;

    int n_entries = _tot_cov_matrix_total->GetNbinsX();

    LOG_NORMAL() << "Number of entries in covariance matrix = " << n_entries << std::endl;

    TMatrix V; // Covariance matrix
    V.Clear(); 
    V.ResizeTo(n_entries, n_entries);

    for (int a = 0; a < n_entries; a ++) {
      for (int b = 0; b < n_entries; b ++) {
        V[a][b] = _tot_cov_matrix_total->GetBinContent(a+1, b+1);
        // std::cout << "a = " << a << ", b = " << b << " => " << _tot_cov_matrix_total->GetBinContent(a+1, b+1) << " => V = " << V[a][b] << std::endl;
        // if (a != b) V[a][b] = 0;
      }
    }

    // Uncomment this block for stat only chi2
    // for (int a = 0; a < n_entries; a ++) {
    //   for (int b = 0; b < n_entries; b ++) {
    //     if (a == b) V[a][b] = _h_data->GetBinError(a+1) * _h_data->GetBinError(b+1);
    //     else V[a][b] = 0.;
    //   }
    // }

    // std::cout << "Printing V = " << std::endl;
    // V.Print();

    TMatrix Vm1 = V.Invert();

    // std::cout << "Printing Vm1 = " << std::endl;
    // Vm1.Print();


    // Plot the inverse
    TH2D * h_cov_inverse = (TH2D*) _tot_cov_matrix_total->Clone("h_cov_inverse");
    for (int a = 0; a < n_entries; a ++) {
      for (int b = 0; b < n_entries; b ++) {
        h_cov_inverse->SetBinContent(a+1, b+1, Vm1[a][b]);
      }
    }



    // Calculate chi2
    double chi2 = 0.;
    for (int i = 0; i < n_entries; i++) {
      for (int j = 0; j < n_entries; j++) {

        // if (i == 41 || j == 41 || i == 36 || j == 36) continue;

        double data_i = _h_data->GetBinContent(i+1);
        double mc_i = _h_mc->GetBinContent(i+1);

        double data_j = _h_data->GetBinContent(j+1);
        double mc_j = _h_mc->GetBinContent(j+1);

        chi2 += (data_i - mc_i) * Vm1[i][j] * (data_j - mc_j);

        // std::cout << "i = " << i << ", j = " << j << " => chi2 entry is " << (data_i - mc_i) * Vm1[i][j] * (data_j - mc_j) << std::endl;
      }
    }

    // Calculate chi2
    double chi2_alt = 0.;
    if (_add_alt_mc_xsec) {
      for (int i = 0; i < n_entries; i++) {
        for (int j = 0; j < n_entries; j++) {

          // if (i == 41 || j == 41 || i == 36 || j == 36) continue;

          double data_i = _h_data->GetBinContent(i+1);
          double mc_i = _h_alt_mc_xsec->GetBinContent(i+1);

          double data_j = _h_data->GetBinContent(j+1);
          double mc_j = _h_alt_mc_xsec->GetBinContent(j+1);

          chi2_alt += (data_i - mc_i) * Vm1[i][j] * (data_j - mc_j);
        }
      }
    }

    LOG_NORMAL() << "(Tune 1) Chi2 is " << chi2 << std::endl;
    if (_add_alt_mc_xsec) LOG_NORMAL() << "(Tune 3) Chi2 is " << chi2_alt << std::endl;



    // Get cov matrix for Tune1 and Tune3 MCs
    if (_add_alt_mc_xsec) {
      TMatrix V_tune1; // Covariance matrix
      V_tune1.Clear(); 
      V_tune1.ResizeTo(n_entries, n_entries);

      TMatrix V_tune3; // Covariance matrix
      V_tune3.Clear(); 
      V_tune3.ResizeTo(n_entries, n_entries);

      for (int a = 0; a < n_entries; a ++) {
        for (int b = 0; b < n_entries; b ++) {
          V_tune1[a][b] = _tot_frac_cov_matrix_total->GetBinContent(a+1, b+1) * _h_mc->GetBinContent(a+1) * _h_mc->GetBinContent(b+1);
          V_tune3[a][b] = _tot_frac_cov_matrix_total->GetBinContent(a+1, b+1) * _h_alt_mc_xsec->GetBinContent(a+1) * _h_alt_mc_xsec->GetBinContent(b+1);
        }
      }

      // std::cout << "Printing V = " << std::endl;
      // V.Print();

      if (_add_alt_mc_xsec) {
  
        TMatrix V_tune1_m1 = V_tune1.Invert();
        TMatrix V_tune3_m1 = V_tune3.Invert();


        // Calculate DeltaT_H0 
        double DeltaT_H0 = 0.;
        for (int i = 0; i < n_entries; i++) {
          for (int j = 0; j < n_entries; j++) {

            double tune1_i = _h_mc->GetBinContent(i+1);
            double tune3_i = _h_alt_mc_xsec->GetBinContent(i+1);

            double tune1_j = _h_mc->GetBinContent(j+1);
            double tune3_j = _h_alt_mc_xsec->GetBinContent(j+1);

            DeltaT_H0 += (tune3_i - tune1_i) * V_tune3_m1[i][j] * (tune3_j - tune1_j);
          }
        }

        // Calculate DeltaT_H1
        double DeltaT_H1 = 0.;
        for (int i = 0; i < n_entries; i++) {
          for (int j = 0; j < n_entries; j++) {

            double tune1_i = _h_mc->GetBinContent(i+1);
            double tune3_i = _h_alt_mc_xsec->GetBinContent(i+1);

            double tune1_j = _h_mc->GetBinContent(j+1);
            double tune3_j = _h_alt_mc_xsec->GetBinContent(j+1);

            DeltaT_H1 += (tune1_i - tune3_i) * V_tune1_m1[i][j] * (tune1_j - tune3_j);
          }
        }

        LOG_NORMAL() << "DeltaT_H0 is " << DeltaT_H0 << ", 2*sqrt is " << 2*std::sqrt(DeltaT_H0) << std::endl;
        LOG_NORMAL() << "DeltaT_H1 is " << DeltaT_H1 << ", 2*sqrt is " << 2*std::sqrt(DeltaT_H1) << std::endl;

      }

    }

    
    LOG_NORMAL() << "Chi2 calculation done." << std::endl;

  }



  void CrossSectionCalculator2DPoly::DrawMC(TCanvas * c, int c_number, TH1D h)
  {
    c->cd(c_number);
    // h.GetXaxis()->SetTitle(xaxis_label.c_str());
    // h.GetYaxis()->SetTitle(yaxis_label.c_str());
    // h.GetXaxis()->SetTitleOffset(0.95);
    // h.GetYaxis()->SetTitleOffset(0.77);

    h.SetLineColor(kGreen+2);
    h.SetFillColor(29);

    // if (_prefix.find("mom") != std::string::npos) {
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



  void CrossSectionCalculator2DPoly::Draw(std::vector<std::string> histos_to_subtract)
  {

    UBTH2Poly* _h_data_subtracted = (UBTH2Poly*)_h_bnbon->Clone("_h_data_subtracted");
    _h_data_subtracted->Sumw2();

    for (auto hname : histos_to_subtract) 
    {
      std::cout << "[CrossSectionCalculator2DPoly] Going to subtract histogram " << hname << std::endl;
      // Need to remove from the data histogram
      _h_data_subtracted->Add(_hmap_bnbcosmic[hname], -1.);
      // But also form the total MC one, to properly propagate unc
      _hmap_bnbcosmic["total"]->Add(_hmap_bnbcosmic[hname], -1.);
    }


    TLegend* leg = new TLegend(0.56,0.37,0.82,0.82,NULL,"brNDC");;

    TCanvas* canvas = new TCanvas();

    THStack *hs_mc = this->ProcessTHStack(_hmap_bnbcosmic, leg, histos_to_subtract);

    UBTH2Poly* data = ProcessDataHisto(_h_data_subtracted);

    hs_mc->Draw("hist");
    _hmap_bnbcosmic["total"]->Draw("E2 same"); // errors
    data->Draw("E1 same");

    leg->AddEntry(data, "Data (Background subtracted)", "lep");
    leg->Draw();


    TLatex* l = this->GetPOTLatex(_pot);
    l->Draw();

    TString name = _folder +_prefix + "_test";
    canvas->SaveAs(name + ".pdf");
    canvas->SaveAs(name + ".C","C");


  }



  void CrossSectionCalculator2DPoly::Draw() 
  {

    TString name = _folder +_prefix + "_selected_events";
    DrawInProjections(_h_bnbon, _hmap_bnbcosmic, name, false);

    name = _folder +_prefix + "_selected_events_scalebinwidth";
    DrawInProjections(_h_bnbon, _hmap_bnbcosmic, name, true);

  }



  void CrossSectionCalculator2DPoly::DrawInProjections(UBTH2Poly* h_data, std::map<std::string,UBTH2Poly*> mc, TString save_path, bool scale_bin_width) 
  {

    // std::vector<TH1D> _xsec_data_histos;
    // std::map<std::string,std::vector<TH1D*>> _xsec_mc_histos;
    // std::vector<THStack*> xsec_mc_hs;
          

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


    // int horizontal_division = 2;
    // int vertical_division = floor(h_data->GetNbinsX() / 2.);

    // if (h_data->GetNbinsX() / 2. != floor(h_data->GetNbinsX()) / 2.) vertical_division++;

    // LOG_INFO() << "Horizontal divisions " << horizontal_division << std::endl;
    // LOG_INFO() << "Vertical divisions " << vertical_division << std::endl;

    // // TCanvas *c_xsec_split = new TCanvas("c_xsec_split","multipads",900,700);
    // TCanvas *c_xsec_split = new TCanvas("c_xsec_split", "multipads",0,45,1006,1150);
    // c_xsec_split->SetBottomMargin(0.15);
    // // gStyle->SetOptStat(0);
    // c_xsec_split->Divide(horizontal_division, vertical_division, 0.01, 0.01);


    // xsec_mc_hs.resize(h_data->GetNbinsX());
    // for (auto iter : mc) {
    //   _xsec_mc_histos[iter.first].resize(h_data->GetNbinsX());
    // }


    // for (int i = 0; i < h_data->GetNbinsX(); i++) {
    //   _xsec_data_histos.emplace_back(*h_data->ProjectionY("fuck", i+1, i+1));
    //   if (scale_bin_width) _xsec_data_histos.at(i).Scale(1, "width");
    //   for (auto iter : mc) {
    //     _xsec_mc_histos[iter.first].at(i) = iter.second->ProjectionY(("fuck" + iter.first + costhetamu_ranges.at(i)).c_str(), i+1, i+1);
    //     if (scale_bin_width) _xsec_mc_histos[iter.first].at(i)->Scale(1, "width");
    //   }
    //   xsec_mc_hs.at(i) = new THStack("bs",";BS;BS");
    // }



    // for (size_t i = 0; i < _xsec_data_histos.size(); i++) {

    //   c_xsec_split->cd(i+1);

    //   gPad->SetBottomMargin(0.15);
    //   gPad->SetLeftMargin(0.15);
    //   gPad->SetTopMargin(0.1128947);


    //   // _xsec_mc_histos["beam-off"].at(i)->GetXaxis()->SetTitle("p_{#mu}^{reco} [GeV]");
    //   // _xsec_mc_histos["beam-off"].at(i)->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{#mu}^{reco}dcos(#theta_{#mu}^{reco})} [10^{-38} cm^{2}/GeV/n]");
    //   // _xsec_mc_histos["beam-off"].at(i)->GetXaxis()->CenterTitle();
    //   // _xsec_mc_histos["beam-off"].at(i)->GetYaxis()->CenterTitle();
    //   // _xsec_mc_histos["beam-off"].at(i)->GetXaxis()->SetTitleOffset(0.92);
    //   // _xsec_mc_histos["beam-off"].at(i)->GetYaxis()->SetTitleOffset(1.11);

    //   _xsec_mc_histos["beam-off"].at(i)->SetLineColor(kBlue+2);
    //   _xsec_mc_histos["beam-off"].at(i)->SetFillColor(kBlue+2);
    //   _xsec_mc_histos["beam-off"].at(i)->SetFillStyle(3004);
    //   xsec_mc_hs.at(i)->Add(_xsec_mc_histos["beam-off"].at(i));

    //   _xsec_mc_histos["dirt"].at(i)->SetLineColor(kOrange+3);
    //   _xsec_mc_histos["dirt"].at(i)->SetFillColor(kOrange+3);
    //   xsec_mc_hs.at(i)->Add(_xsec_mc_histos["dirt"].at(i));


    //   _xsec_mc_histos["cosmic"].at(i)->SetLineColor(kBlue-3);
    //   _xsec_mc_histos["cosmic"].at(i)->SetFillColor(kBlue-3);
    //   xsec_mc_hs.at(i)->Add(_xsec_mc_histos["cosmic"].at(i));

    //   _xsec_mc_histos["outfv"].at(i)->SetLineColor(kGreen+2);
    //   _xsec_mc_histos["outfv"].at(i)->SetFillColor(kGreen+2);
    //   xsec_mc_hs.at(i)->Add(_xsec_mc_histos["outfv"].at(i));
    //   _xsec_mc_histos["nc"].at(i)->SetLineColor(kGray);
    //   _xsec_mc_histos["nc"].at(i)->SetFillColor(kGray);
    //   xsec_mc_hs.at(i)->Add(_xsec_mc_histos["nc"].at(i));
    //   _xsec_mc_histos["anumu"].at(i)->SetLineColor(kOrange-3);
    //   _xsec_mc_histos["anumu"].at(i)->SetFillColor(kOrange-3);
    //   xsec_mc_hs.at(i)->Add(_xsec_mc_histos["anumu"].at(i));
    //   _xsec_mc_histos["nue"].at(i)->SetLineColor(kMagenta+1);
    //   _xsec_mc_histos["nue"].at(i)->SetFillColor(kMagenta+1);
    //   xsec_mc_hs.at(i)->Add(_xsec_mc_histos["nue"].at(i));
    //   _xsec_mc_histos["signal"].at(i)->SetLineColor(kRed-4);
    //   _xsec_mc_histos["signal"].at(i)->SetFillColor(kRed-4);
    //   xsec_mc_hs.at(i)->Add(_xsec_mc_histos["signal"].at(i));

    //   if (scale_bin_width) xsec_mc_hs.at(i)->SetTitle((costhetamu_ranges.at(i) + ";p_{#mu}^{reco};Selected Events / GeV").c_str());
    //   else xsec_mc_hs.at(i)->SetTitle((costhetamu_ranges.at(i) + ";p_{#mu}^{reco};Selected Events").c_str());
    //   xsec_mc_hs.at(i)->Draw("hist");

    //   xsec_mc_hs.at(i)->SetMinimum(0.);



    //   // The proper data points
    //   _xsec_data_histos.at(i).SetMarkerStyle(20);
    //   _xsec_data_histos.at(i).SetMarkerSize(0.5);
    //   _xsec_data_histos.at(i).Draw("E1 X0 same");

    //   gPad->Modified(); gPad->Update();


    //   // if (i == 0) {
    //   //   PlottingTools::DrawPreliminaryXSec();

    //   //   TLatex* l = this->GetPOTLatex(_pot);
    //   //   l->Draw();
    //   // }

    // }
    
    // c_xsec_split->SaveAs(save_path + ".pdf");
    // c_xsec_split->SaveAs(save_path + ".C","C");

  }





  THStack * CrossSectionCalculator2DPoly::ProcessTHStack(std::map<std::string,UBTH2Poly*> themap, TLegend* leg, std::vector<std::string> histos_to_subtract){

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

  UBTH2Poly* CrossSectionCalculator2DPoly::ProcessDataHisto(UBTH2Poly* histo) {

    histo->SetMarkerStyle(kFullCircle);
    histo->SetMarkerSize(0.6);

    return histo;

  }


  TLatex* CrossSectionCalculator2DPoly::GetPOTLatex(double pot) {

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

  void CrossSectionCalculator2DPoly::SaveToLatexFile() {
    // Save on latex file too
    std::ofstream file_latex;
    file_latex.open (_folder + "xsec.tex", std::ofstream::out | std::ofstream::trunc);
    for (int i = 0; i < _h_data->GetNumberOfBins(); i++) {
      file_latex << _h_data->GetBinContent(i+1) << " & " << std::sqrt(_tot_cov_matrix_total->GetBinContent(i+1, i+1)) << "\\\\" << std::endl;
    }

    file_latex << std::endl;

    file_latex << "\\begin{equation}" << std::endl;
    file_latex << "E_{ij} =" << std::endl;
    file_latex << "\\begin{bmatrix}" << std::endl;

    for (int i = 0; i < _h_data->GetNumberOfBins(); i++) {
      for (int j = 0; j < _h_data->GetNumberOfBins(); j++) {

        file_latex << std::setprecision(3) << std::scientific << "$" << _tot_cov_matrix_total->GetBinContent(i+1, j+1) << "$  &  ";

      }

      file_latex << " \\\\" << std::endl;
    }

    file_latex << "\\end{bmatrix}" << std::endl;
    file_latex << "\\end{equation}" << std::endl << std::endl;


    file_latex.close();
  }

  void CrossSectionCalculator2DPoly::SaveEventNumbers(std::string file_name)
  {
    std::ofstream f_out;
    f_out.open(_folder+file_name, std::ios::out | std::ios::trunc);

    f_out << "\\begin{table}[]" << std::endl;
    f_out << "\\caption{My caption}" << std::endl;
    f_out << "\\label{tab:mylabel}" << std::endl;
    f_out << "\\centering" << std::endl;
    f_out << "\\begin{tabular}{c|cc|ccccccc}" << std::endl;
    f_out << "\\toprule" << std::endl;
    f_out << "    & \\multicolumn{2}{c}{Data}    & \\multicolumn{6}{c}{MC} \\\\" << std::endl;
    f_out << "Bin & Selected & Cosmic & $\\nu_\\mu$ CC & Cosmic  & OUTFV & DIRT & NC & $\\nu_e$ and $\\bar{\\nu}_e$ & $\\bar{\\nu}_\\mu$ \\\\" << std::endl;
    f_out << "    & Events   & Only   & Signal         & in BNB  &       &      &    &                           &                 \\\\" << std::endl;
    f_out << "\\midrule" << std::endl;
    for (int i = 1; i < _h_bnbon->GetNumberOfBins()+1; i++) {
      f_out << std::setprecision(4) 
            << i << " & "
            << _h_bnbon->GetBinContent(i) << " $\\pm$ " << _h_bnbon->GetBinError(i) << " & " 
            << _hmap_bnbcosmic["beam-off"]->GetBinContent(i) << " $\\pm$ " << _hmap_bnbcosmic["beam-off"]->GetBinError(i) << " & "
            << _hmap_bnbcosmic["signal"]->GetBinContent(i) << " $\\pm$ " << _hmap_bnbcosmic["signal"]->GetBinError(i) << " & "
            << _hmap_bnbcosmic["cosmic"]->GetBinContent(i) << " $\\pm$ " << _hmap_bnbcosmic["cosmic"]->GetBinError(i) << " & "
            << _hmap_bnbcosmic["outfv"]->GetBinContent(i) << " $\\pm$ " << _hmap_bnbcosmic["outfv"]->GetBinError(i) << " & "
            << _hmap_bnbcosmic["dirt"]->GetBinContent(i) << " $\\pm$ " << _hmap_bnbcosmic["dirt"]->GetBinError(i) << " & "
            << _hmap_bnbcosmic["nc"]->GetBinContent(i) << " $\\pm$ " << _hmap_bnbcosmic["nc"]->GetBinError(i) << " & "
            << _hmap_bnbcosmic["nue"]->GetBinContent(i) << " $\\pm$ " << _hmap_bnbcosmic["nue"]->GetBinError(i) << " & "
            << _hmap_bnbcosmic["anumu"]->GetBinContent(i) << " $\\pm$ " << _hmap_bnbcosmic["anumu"]->GetBinError(i) << " \\\\ " << std::endl;
    }
    f_out << "\\bottomrule" << std::endl;
    f_out << "\\end{tabular}" << std::endl;
    f_out << "\\end{table}" << std::endl;
  }
  
}

#endif

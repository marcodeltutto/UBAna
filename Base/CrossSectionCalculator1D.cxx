#ifndef __BASE_CROSSSECTIONCALCULATOR1D_CXX__
#define __BASE_CROSSSECTIONCALCULATOR1D_CXX__

#include "CrossSectionCalculator1D.h"

namespace Base {
	
  void CrossSectionCalculator1D::Reset() 
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

    _h_true_reco_mom = NULL;

    _covariance_matrix_is_set = false;
    _frac_covariance_matrix_is_set = false;
  }

  void CrossSectionCalculator1D::SetScaleFactors(double bnbcosmic, double bnbon, double extbnb, double dirt, double intimecosmic)
  {
    _scale_factor_mc_bnbcosmic = bnbcosmic;
    _scale_factor_bnbon = bnbon;
    _scale_factor_extbnb = extbnb;
    _scale_factor_mc_dirt = dirt;
    _scale_factor_mc_intimecosmic = intimecosmic;

    _configured = true;
  }

  void CrossSectionCalculator1D::SetPOT(double pot)
  {
    _pot = pot;
  }

  void CrossSectionCalculator1D::SetNameAndLabel(std::string name, std::string label)
  {
    _name = name;
    _label = label;
  }

  void CrossSectionCalculator1D::SetOutDir(std::string dir)
  {

    std::string out_folder_base = std::getenv("MYSW_OUTDIR");

    _outdir = out_folder_base + dir;

    auto now = std::time(nullptr);
    char buf[sizeof("YYYY-MM-DD_HH-MM-SS")];
    std::string timestamp = std::string(buf,buf + std::strftime(buf,sizeof(buf),"%F_%H-%M-%S",std::gmtime(&now)));

    _folder = _outdir + "_" + timestamp + "/";

    system(("mkdir " + _folder).c_str());

  }

  void CrossSectionCalculator1D::SetCovarianceMatrix(TH2D h)
  {
    _covariance_matrix = h;
    _covariance_matrix_is_set = true;

    if (_frac_covariance_matrix_is_set) {
      LOG_CRITICAL() << "You have set both a covariance and a fractional covariance matrix. Only one is allowed." << std::endl;
      throw std::exception();
    }
  }

  void CrossSectionCalculator1D::SetFractionalCovarianceMatrix(TH2D h)
  {
    _frac_covariance_matrix = h;
    _frac_covariance_matrix_is_set = true;

    if (_covariance_matrix_is_set) {
      LOG_CRITICAL() << "You have set both a covariance and a fractional covariance matrix. Only one is allowed." << std::endl;
      throw std::exception();
    }
  }

  void CrossSectionCalculator1D::SetMigrationMatrix(TMatrix s) 
  {
    _S.ResizeTo(s.GetNrows(), s.GetNcols());
    _S = s;
  }

  void CrossSectionCalculator1D::PrintConfig() {

    std::cout << "--- CrossSectionCalculator1D:" << std::endl;
    std::cout << "---   _scale_factor_mc_bnbcosmic     = " << _scale_factor_mc_bnbcosmic << std::endl;
    std::cout << "---   _scale_factor_bnbon            = " << _scale_factor_bnbon << std::endl;
    std::cout << "---   _scale_factor_extbnb           = " << _scale_factor_extbnb << std::endl;
    std::cout << "---   _scale_factor_mc_intimecosmic  = " << _scale_factor_mc_intimecosmic << std::endl;
    std::cout << "---   _pot                           = " << _pot << std::endl;

  }

  void CrossSectionCalculator1D::SetHistograms(std::map<std::string,TH1D*> bnbcosmic, TH1D* bnbon, TH1D* extbnb, std::map<std::string,TH1D*> dirt, TH1D* intimecosmic) 
  {

    // _hmap_bnbcosmic = bnbcosmic;

    // std::cout << "MC Histograms: " << std::endl;
    for (auto it : bnbcosmic) {
      // std::cout << "\t" << it.first << std::endl;
      std::string this_name = it.second->GetName();
      _hmap_bnbcosmic[it.first] = (TH1D*)it.second->Clone((this_name + it.first + "_xsec_int_bnbcosmic").c_str());
    }

    for (auto it : dirt) {
      // std::cout << "\t" << it.first << std::endl;
      std::string this_name = it.second->GetName();
      _hmap_dirt[it.first] = (TH1D*)it.second->Clone((this_name + it.first + "_xsec_int_dirt").c_str());
    }

    _dirt_is_set = false;
    if (dirt.size() != 0) {
      _dirt_is_set = true;
    }
    
    if (bnbon != NULL) {
      _h_bnbon = (TH1D*)bnbon->Clone("_h_bnbon");
    }
    if (extbnb != NULL) {
      _h_extbnb = (TH1D*)extbnb->Clone("_h_extbnb");
    }
    if (intimecosmic != NULL) {
      _h_intimecosmic = (TH1D*)intimecosmic->Clone("_h_intimecosmic");
    }
  }

  void CrossSectionCalculator1D::SetTruthHistograms(TH1D* num, TH1D* den, TH2D* h)
  {
    _h_eff_mumom_num = num;
    _h_eff_mumom_den = den;

    _h_true_reco_mom = h;

  }

  void CrossSectionCalculator1D::SetTruthHistograms(TH1D* num, TH1D* den)
  {
    _h_eff_mumom_num = num;
    _h_eff_mumom_den = den;

  }

  void CrossSectionCalculator1D::SetTruthXSec(TH1D* xsec, int n, int m) 
  {
    _truth_xsec = xsec;
    if(_fake_data_mode) this->SmearTruth(n, m);
  }

  TH1D* CrossSectionCalculator1D::GetMCCrossSection()
  {
    return _h_mc;
  }

  double CrossSectionCalculator1D::EstimateFlux(std::string flux_file_name, std::string histogram_file_name) 
  {
    std::string flux_file = std::getenv("MYSW_DIR");
    //flux_file += "/Flux/numode_bnb_470m_r200.root";
    flux_file += "/Flux/";
    flux_file += flux_file_name;
    // std::cout << "[CrossSectionCalculator1D] Using flux file: " << flux_file << std::endl;

    // std::cout << "[CrossSectionCalculator1D] Flux correction weight: " << _flux_correction_weight << std::endl;

    TFile * f = TFile::Open(flux_file.c_str());
    f->cd();
    TH1D * h_flux_numu = (TH1D*) f->Get(histogram_file_name.c_str());//f->Get("numu");
    //h_flux_numu->Scale(_pot/1.e20);
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
    // std::cout << "The mean energy is: " << mean << std::endl;
    int binmean = h_flux_numu -> FindBin(mean);
    // std::cout << "The bin of the mean is: " << binmean << std::endl;

    int n = h_flux_numu -> GetNbinsX();

    // std::cout << "Integral up to " << binmean << " is: " << h_flux_numu->Integral(1, binmean) << std::endl;
    // std::cout << "Integral from to " << binmean << " is: " << h_flux_numu->Integral(binmean, n) << std::endl;


    double lowerint = h_flux_numu -> Integral(1, binmean);
    // std::cout << "Lower Integral: " << lowerint << std::endl;
    double lowerborder = lowerint * 0.32; //h_flux_numu->Integral() * 0.16;
    // std::cout << "Lower Border: " << lowerborder << std::endl;
    double lowersum = 0;
    int i = 0;
    while (lowersum < lowerborder) {
      i++;
      lowersum += h_flux_numu -> GetBinContent(i);
      // std::cout << i << "\t" << lowersum << std::endl;
    }

    // std::cout << "Lower Sum: " << lowersum << std::endl;
    double low = h_flux_numu -> GetBinCenter(i-1);
    // std::cout << "The lower edge bin is: " << i-1 << std::endl;
    // std::cout << "The lower edge center energy is: " << low << std::endl;
    // std::cout << "The lower energy error is: " << mean - low << std::endl;

    double upperint = h_flux_numu -> Integral(binmean, n);
    // std::cout << upperint << std::endl;
    double upperborder = upperint * 0.32; //h_flux_numu->Integral() * 0.16;
    double uppersum = 0;
    int j = 0;
    while (uppersum < upperborder) {
      uppersum += h_flux_numu -> GetBinContent(n+1 - j);
      j++;
    }

    double up = h_flux_numu -> GetBinCenter(n+1 - (j-1));
    // std::cout << "The upper edge bin is: " << j-1 << std::endl;
    // std::cout << "The upper edge center energy is: " << up << std::endl;
    // std::cout << "The upper energy error is: " << up - mean << std::endl;

    // std::cout << "This should be ~0.68: " << h_flux_numu->Integral(i-1, n+1 - (j-1)) / h_flux_numu->Integral() << std::endl;

    // std::cout << "Integral lower border: " << h_flux_numu->Integral(1, i-1) << " - " << h_flux_numu->Integral(1, i-1) / h_flux_numu->Integral() << std::endl;
    // std::cout << "Integral upper border: " << h_flux_numu->Integral(n+1 - (j-1), n) << " - " << h_flux_numu->Integral(n+1 - (j-1), n) / h_flux_numu->Integral() << std::endl;

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

    // LOG_INFO() << "Flux is " << _flux << std::endl;

    return _flux;
  }

  void CrossSectionCalculator1D::DoNotSmear() 
  {

    // double eff = _h_eff_mumom_num->GetBinContent(1) / _h_eff_mumom_den->GetBinContent(1);


    TEfficiency* teff_reco = new TEfficiency(*_h_eff_mumom_num,*_h_eff_mumom_den);

    // std::cout << "The efficiency is " << eff << std::endl;
    LOG_INFO() << "The efficiency is " << teff_reco->GetEfficiency(1) 
                << " + " << teff_reco->GetEfficiencyErrorUp(1) 
                << " - " << teff_reco->GetEfficiencyErrorLow(1) << std::endl;

    _eff = teff_reco;
  }

  void CrossSectionCalculator1D::SmearTruth(int n, int m) {

    TMatrix xsec_truth; xsec_truth.Clear(); xsec_truth.ResizeTo(m, 1);

    for (int bin = 1; bin < m+1; bin++) {
      xsec_truth[bin-1][0] = _truth_xsec->GetBinContent(bin);
      std::cout << "xsec_truth[bin-1] " << _truth_xsec->GetBinContent(bin) << std::endl;
    }

    TMatrix xsec_truth_smear = _S * xsec_truth;

    _truth_xsec_smeared = (TH1D*) _truth_xsec->Clone("_truth_xsec_smeared");

    for (int bin = 1; bin < n+1; bin++) {
      _truth_xsec_smeared->SetBinContent(bin, xsec_truth_smear[bin-1][0]);
      std::cout << "xsec_truth_smear[bin-1][0] " << _truth_xsec_smeared->GetBinContent(bin) << std::endl;
    }

  }

  void CrossSectionCalculator1D::Smear(int n, int m)
  {

    if (!_h_eff_mumom_den || !_h_eff_mumom_num) {
      LOG_CRITICAL() << "Efficiency numberator or denominator truth histograms not correclty set." << std::endl;
      throw std::exception();
    }

    // Settings for true distributions
    _h_eff_mumom_den->SetTitle("");
    _h_eff_mumom_den->GetXaxis()->SetTitle("p_{#mu}^{truth} [GeV]"); //->SetTitle("cos(#theta_{#mu}^{truth})");
    _h_eff_mumom_den->GetYaxis()->SetTitle("Events");
    _h_eff_mumom_den->SetFillColorAlpha(30, 0.35);
    _h_eff_mumom_den->SetLineColor(30);
    _h_eff_mumom_den->SetLineWidth(3);

    _h_eff_mumom_num->SetFillColorAlpha(9, 0.35);
    _h_eff_mumom_num->SetLineColor(9);
    _h_eff_mumom_num->SetLineWidth(3);


    //
    // Efficiency (true)
    //

    TEfficiency* teff_true = new TEfficiency(*_h_eff_mumom_num,*_h_eff_mumom_den);

    TCanvas * c_eff_true = new TCanvas;
    teff_true->SetTitle(";p_{#mu}^{truth};Efficiency");//->SetTitle(";cos(#theta_{#mu}^{truth});Efficiency");
    teff_true->SetLineColor(kGreen+3);
    teff_true->SetMarkerColor(kGreen+3);
    teff_true->SetMarkerStyle(20);
    teff_true->SetMarkerSize(0.5);
    teff_true->Draw("AP");

    gPad->Update(); 
    auto g = teff_true->GetPaintedGraph(); 
    g->SetMinimum(0);
    g->SetMaximum(1);
    gPad->Update(); 

    TString name = _folder +_name + "efficiecy_mumon_true";
    c_eff_true->SaveAs(name + ".pdf");

    // 
    // Do the smearing
    //

    TMatrix eff_num_true; eff_num_true.Clear(); eff_num_true.ResizeTo(m + 1, 1); // Last entry for over/under-flows
    TMatrix eff_den_true; eff_den_true.Clear(); eff_den_true.ResizeTo(m + 1, 1); // Last entry for over/under-flows

    for (int bin = 1; bin < m+1; bin++) {
      eff_num_true[bin-1][0] = _h_eff_mumom_num->GetBinContent(bin);
      eff_den_true[bin-1][0] = _h_eff_mumom_den->GetBinContent(bin);
    }

    eff_num_true[m] = _h_eff_mumom_num->GetBinContent(0) + _h_eff_mumom_num->GetBinContent(m+1);
    eff_den_true[m] = _h_eff_mumom_den->GetBinContent(0) + _h_eff_mumom_den->GetBinContent(m+1);



    // Smearing
    TMatrix eff_num_smear = _S * eff_num_true;
    TMatrix eff_den_smear = _S * eff_den_true;



    TH1D* h_eff_mumom_num_smear = (TH1D*) _h_eff_mumom_num->Clone("h_eff_mumom_num_smear");
    TH1D* h_eff_mumom_den_smear = (TH1D*) _h_eff_mumom_den->Clone("h_eff_mumom_den_smear");

    for (int bin = 1; bin < n+1; bin++) {
      h_eff_mumom_num_smear->SetBinContent(bin, eff_num_smear[bin-1][0]);
      h_eff_mumom_den_smear->SetBinContent(bin, eff_den_smear[bin-1][0]);
    }




    // 
    // Plot without smearing
    //

    _h_eff_mumom_den->Scale(1., "width");
    _h_eff_mumom_num->Scale(1., "width");

    TCanvas * c = new TCanvas;
    _h_eff_mumom_den->SetTitle("");
    _h_eff_mumom_den->GetXaxis()->SetTitle("p_{#mu}^{truth} [GeV]");//->SetTitle("cos(#theta_{#mu}^{truth})");
    _h_eff_mumom_den->GetYaxis()->SetTitle("Events");
    _h_eff_mumom_den->SetFillColorAlpha(30, 0.35);
    _h_eff_mumom_den->SetLineColor(30);
    _h_eff_mumom_den->SetLineWidth(3);

    _h_eff_mumom_den->Draw("histo");

    _h_eff_mumom_num->SetFillColorAlpha(9, 0.35);
    _h_eff_mumom_num->SetLineColor(9);
    _h_eff_mumom_num->SetLineWidth(3);

    _h_eff_mumom_num->Draw("histo same");

    TLegend * ll = new TLegend(0.5315186,0.7515789,0.8696275,0.8821053,NULL,"brNDC");
    ll->AddEntry(_h_eff_mumom_den,"Generated #nu_{#mu} CC in FV","f");
    ll->AddEntry(_h_eff_mumom_num,"Selected #nu_{#mu} CC in FV","f");
    ll->Draw();

    name = _folder +_name + "all_selected";
    c->SaveAs(name + ".pdf");

    LOG_INFO() << "_h_eff_mumom_num->Integral(): " << _h_eff_mumom_num->Integral() << std::endl;
    LOG_INFO() << "_h_eff_mumom_den->Integral(): " << _h_eff_mumom_den->Integral() << std::endl;



    // 
    // Plot with smearing
    //

    h_eff_mumom_den_smear->Scale(1., "width");
    h_eff_mumom_num_smear->Scale(1., "width");

    TCanvas * c_smear = new TCanvas;
    h_eff_mumom_den_smear->SetTitle("");
    h_eff_mumom_den_smear->GetXaxis()->SetTitle("p_{#mu}^{reco} [GeV]");//->SetTitle("cos(#theta_{#mu}^{reco})");
    h_eff_mumom_den_smear->GetYaxis()->SetTitle("Events");
    h_eff_mumom_den_smear->Draw("histo");
    h_eff_mumom_num_smear->Draw("histo same");

    ll->Draw();

    name = _folder +_name + "_all_selected_smear";
    c_smear->SaveAs(name + ".pdf");

    LOG_INFO() << "h_eff_mumom_num_smear->Integral(): " << h_eff_mumom_num_smear->Integral() << std::endl;
    LOG_INFO() << "h_eff_mumom_den_smear->Integral(): " << h_eff_mumom_den_smear->Integral() << std::endl;


    //
    // Efficiency (reco)
    //

    TEfficiency* teff_reco = new TEfficiency(*h_eff_mumom_num_smear,*h_eff_mumom_den_smear);

    TCanvas * c_eff_reco = new TCanvas;
    teff_reco->SetTitle(";p_{#mu}^{reco} [GeV];Efficiency");//->SetTitle(";cos(#theta_{#mu}^{reco});Efficiency");
    teff_reco->SetLineColor(kGreen+3);
    teff_reco->SetMarkerColor(kGreen+3);
    teff_reco->SetMarkerStyle(20);
    teff_reco->SetMarkerSize(0.5);
    teff_reco->Draw("AP");

    gPad->Update(); 
    auto graph = teff_reco->GetPaintedGraph(); 
    graph->SetMinimum(0);
    graph->SetMaximum(1);
    gPad->Update(); 

    name = _folder +_name + "_efficiecy_reco";
    c_eff_reco->SaveAs(name + ".pdf");

    LOG_INFO() << "Statistic option used for efficiency calculation: " << teff_reco->GetStatisticOption() << ", check https://root.cern.ch/doc/v608/classTEfficiency.html#af27fb4e93a1b16ed7a5b593398f86312." << std::endl;
    LOG_INFO() << "Efficiency bin 1: " << teff_reco->GetEfficiency(1) << " - " << teff_reco->GetEfficiencyErrorLow(1) << " + " << teff_reco->GetEfficiencyErrorUp(1) << std::endl;
    LOG_INFO() << "Efficiency bin 2: " << teff_reco->GetEfficiency(2) << " - " << teff_reco->GetEfficiencyErrorLow(2) << " + " << teff_reco->GetEfficiencyErrorUp(2) << std::endl;

    _eff = teff_reco;

  }



  void CrossSectionCalculator1D::ProcessPlots() 
  {

    bool bin_width_scale = false;

    // Scale mc histograms
    for (auto iter : _hmap_bnbcosmic) {
      if ( iter.second == NULL  || iter.first == "intimecosmic" || iter.first == "beam-off"
        || iter.first == "dirt" || iter.first == "dirt_outfv"   || iter.first == "dirt_cosmic") continue;
      iter.second->Sumw2();
      iter.second->Scale(_scale_factor_mc_bnbcosmic);
      if (bin_width_scale) {
        iter.second->Scale(1, "width");
      }
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

    if (bin_width_scale) {
      _h_extbnb->Scale(1, "width");
      _h_bnbon->Scale(1, "width");
    }

    if (_fake_data_mode || _overlay_mode) {
      this->PrintFakeDataMessage();
      _h_bnbon->Add(_h_extbnb);
    }

    // Get the beam-on - beam-off histogram
    _h_data_sub = (TH1D*)_h_bnbon->Clone("_h_data_sub");
    _h_data_sub->Sumw2();
    _h_data_sub->Add(_h_extbnb, -1.);

    
    // Save beam off in the MC backgrounds ...
    _hmap_bnbcosmic["beam-off"] = _h_extbnb;

    // ... and update the total histogram
    _hmap_bnbcosmic["total"]->Add(_h_extbnb);


    if (_dirt_is_set) {

      if (bin_width_scale) {
        for (auto iter : _hmap_dirt) iter.second->Scale(1, "width");
      }

      // Save dirt in the MC backgrounds ...
      _hmap_bnbcosmic["dirt"] = _hmap_dirt["total"];
      _hmap_bnbcosmic["dirt_outfv"] = _hmap_dirt["outfv"];
      _hmap_bnbcosmic["dirt_cosmic"] = _hmap_dirt["cosmic"];

      // ... and update the total histogram
      _hmap_bnbcosmic["total"]->Add(_hmap_dirt["total"]);
    } else {
      TH1D * h_empty = (TH1D*) _hmap_bnbcosmic["total"]->Clone("empty");
      h_empty->Reset();

      _hmap_bnbcosmic["dirt"] = h_empty;
      _hmap_bnbcosmic["outfv_dirt"] = h_empty;
      _hmap_bnbcosmic["cosmic_dirt"] = h_empty;
    }



      LOG_INFO() << "Beam-on integral "  << _h_bnbon->Integral() << std::endl;
      LOG_INFO() << "Beam-off integral " << _hmap_bnbcosmic["beam-off"]->Integral() << std::endl;
      LOG_INFO() << "MC signal "         << _hmap_bnbcosmic["signal"]->Integral() << std::endl;
      LOG_INFO() << "MC cosmic "         << _hmap_bnbcosmic["cosmic"]->Integral() << std::endl;
      LOG_INFO() << "MC outfv "          << _hmap_bnbcosmic["outfv"]->Integral() << std::endl;
      LOG_INFO() << "MC nc "             << _hmap_bnbcosmic["nc"]->Integral() << std::endl;
      LOG_INFO() << "MC nue "            << _hmap_bnbcosmic["nue"]->Integral() << std::endl;
      LOG_INFO() << "MC anumu "          << _hmap_bnbcosmic["anumu"]->Integral() << std::endl;
      if (_dirt_is_set) LOG_INFO() << "MC dirt "           << _hmap_bnbcosmic["dirt"]->Integral() << std::endl;

      LOG_INFO() << "First Bin only: " << std::endl;
      LOG_INFO() << "Beam-on integral "  << _h_bnbon->GetBinContent(1) << " +- " << _h_bnbon->GetBinError(1) << std::endl;
      LOG_INFO() << "Beam-off integral " << _hmap_bnbcosmic["beam-off"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["beam-off"]->GetBinError(1) << std::endl;
      LOG_INFO() << "MC signal "         << _hmap_bnbcosmic["signal"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["signal"]->GetBinError(1) << std::endl;
      LOG_INFO() << "MC cosmic "         << _hmap_bnbcosmic["cosmic"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["cosmic"]->GetBinError(1) << std::endl;
      LOG_INFO() << "MC outfv "          << _hmap_bnbcosmic["outfv"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["outfv"]->GetBinError(1) << std::endl;
      LOG_INFO() << "MC nc "             << _hmap_bnbcosmic["nc"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["nc"]->GetBinError(1) << std::endl;
      LOG_INFO() << "MC nue "            << _hmap_bnbcosmic["nue"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["nue"]->GetBinError(1) << std::endl;
      LOG_INFO() << "MC anumu "          << _hmap_bnbcosmic["anumu"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["anumu"]->GetBinError(1) << std::endl;
      if (_dirt_is_set) LOG_INFO() << "MC dirt "           << _hmap_bnbcosmic["dirt"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["dirt"]->GetBinError(1) << std::endl;

    if (_h_bnbon->GetNbinsX() == 1) {
      // If one bin means we are dealing with the total cross section, print the number of events
      LOG_INFO() << "Number of events for " << _pot << " POT:" << std::endl;
      LOG_INFO() << "Beam-on integral "  << _h_bnbon->GetBinContent(1) << " +- " << _h_bnbon->GetBinError(1) << std::endl;
      LOG_INFO() << "Beam-off integral " << _hmap_bnbcosmic["beam-off"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["beam-off"]->GetBinError(1) << std::endl;
      LOG_INFO() << "MC signal "         << _hmap_bnbcosmic["signal"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["signal"]->GetBinError(1) << std::endl;
      LOG_INFO() << "MC cosmic "         << _hmap_bnbcosmic["cosmic"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["cosmic"]->GetBinError(1) << std::endl;
      LOG_INFO() << "MC outfv "          << _hmap_bnbcosmic["outfv"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["outfv"]->GetBinError(1) << std::endl;
      LOG_INFO() << "MC nc "             << _hmap_bnbcosmic["nc"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["nc"]->GetBinError(1) << std::endl;
      LOG_INFO() << "MC nue "            << _hmap_bnbcosmic["nue"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["nue"]->GetBinError(1) << std::endl;
      LOG_INFO() << "MC anumu "          << _hmap_bnbcosmic["anumu"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["anumu"]->GetBinError(1) << std::endl;
      if (_dirt_is_set) LOG_INFO() << "MC dirt "           << _hmap_bnbcosmic["dirt"]->GetBinContent(1) << " +- " << _hmap_bnbcosmic["dirt"]->GetBinError(1) << std::endl;

      TH1D* total_bkg_temp = (TH1D*) _hmap_bnbcosmic["beam-off"]->Clone("total_bkg_temp");
      total_bkg_temp->Add(_hmap_bnbcosmic["cosmic"]);
      total_bkg_temp->Add(_hmap_bnbcosmic["outfv"]);
      total_bkg_temp->Add(_hmap_bnbcosmic["nc"]);
      total_bkg_temp->Add(_hmap_bnbcosmic["nue"]);
      total_bkg_temp->Add(_hmap_bnbcosmic["anumu"]);
      if (_dirt_is_set) total_bkg_temp->Add(_hmap_bnbcosmic["dirt"]);
      LOG_INFO() << "Total backround " << total_bkg_temp->GetBinContent(1) << " +- " << total_bkg_temp->GetBinError(1) << std::endl;
    }

  }

  void CrossSectionCalculator1D::SaveEventNumbers(std::string file_name)
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
    for (int i = 1; i < _h_bnbon->GetNbinsX()+1; i++) {
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

  
  void CrossSectionCalculator1D::PrintOnFile(std::string name)
  {
    std::ofstream fout; 
    fout.open("xsec_out.txt", std::ofstream::app);
    fout << name << " & " << _hmap_bnbcosmic["signal"]->Integral()
                 << " & " << _hmap_bnbcosmic["cosmic"]->Integral() 
                 << " & " << _hmap_bnbcosmic["outfv"]->Integral()
                 << " & " << _hmap_bnbcosmic["dirt"]->Integral()
                 << " & " << _hmap_bnbcosmic["nc"]->Integral()
                 << " & " << _hmap_bnbcosmic["nue"]->Integral()
                 << " & " << _hmap_bnbcosmic["anumu"]->Integral()
                 << " & " << _eff->GetEfficiency(1) 
                 << " & " << _hmap_bnbcosmic["beam-off"]->Integral()
                 << " & " << _h_bnbon->Integral() << "\\\\" << std::endl;
  }  


  TH1D* CrossSectionCalculator1D::ExtractCrossSection(std::vector<std::string> bkg_names, std::string xaxis_label, std::string yaxis_label) 
  {

    //
    // The two histograms we acually need: MC and data (bkg subtracted)
    //

    _h_mc = _hmap_bnbcosmic["signal"];
    _h_data = (TH1D*)_h_bnbon->Clone("h_data");

    _h_mc->SetTitle(_label.c_str());
    _h_data->Sumw2();

    if (_h_mc->GetSumw2N() == 0) { 
      LOG_WARNING() << "MC cross section histogram does not have Sum2w active." << std::endl;
    }


    // if(_h_data->GetNbinsX() == 1) {
    //   _h_data->SetBinError(1, 0.);
    // }

    // Print the statistical uncertainties on the screen
    LOG_INFO() << "Statistical uncertainty for beam-on: " << _h_data->GetBinError(1) << std::endl;
    if (_h_data->GetNbinsX() == 1) {
      for (auto name : bkg_names) {
        LOG_INFO() << "Statistical uncertainty for " << name << ": "<< _hmap_bnbcosmic[name]->GetBinError(1) << std::endl;
      }
    }



    for (auto name : bkg_names) 
    {
      _h_data->Add(_hmap_bnbcosmic[name], -1.);
      if (_hmap_bnbcosmic[name]->GetSumw2N() == 0) {
        LOG_WARNING() << "Bkg " << name << " does not have Sum2w active." << std::endl;
      }
    }

    

    //
    // Create efficiency histogram
    //

    //TEfficiency* teff_true = new TEfficiency(*_h_eff_mumom_num,*_h_eff_mumom_den);
    //_eff = teff_true;

    TH1D * h_eff = (TH1D*)_h_mc->Clone("h_eff");
    h_eff->Sumw2();
    for (int b = 1; b < _h_mc->GetNbinsX() + 1; b++)
    {
      h_eff->SetBinContent(b, _eff->GetEfficiency(_eff->GetGlobalBin(b)));
      double unc = 0.;
      unc += _eff->GetEfficiencyErrorLow(_eff->GetGlobalBin(b));
      unc += _eff->GetEfficiencyErrorUp(_eff->GetGlobalBin(b));
      unc /= 2.;
      h_eff->SetBinError(b, unc);

    }

    //
    // Divide by efficiency
    //

    _h_mc->Divide(h_eff);
    _h_data->Divide(h_eff);

    //
    // Divide by flux, and N_target and bin width
    //

    // LOG_INFO() << "FLUX: " << _flux << ", N_target: " << _n_target << ", FLUX x N_target: " << _flux*_n_target << std::endl;

    LOG_INFO() << "Number of targets (MC)   = " << _n_target_mc << std::endl;
    LOG_INFO() << "Number of targets (DATA) = " << _n_target_data << std::endl;
    LOG_INFO() << "Flux                     = " << _flux << std::endl;

    double den_data = _flux * _n_target_data * 1e-38;
    double den_mc   = _flux * _n_target_mc   * 1e-38;

    _h_mc->Scale(1. / den_mc, "width");
    _h_data->Scale(1. / den_data, "width");


    // Do it also for the truth xsec
    if (_fake_data_mode) _truth_xsec_smeared->Scale(1. / den_mc, "width");


    LOG_INFO() << "Data Integral: " << _h_data->Integral() << std::endl;
    LOG_INFO() << "MC Integral: " << _h_mc->Integral() << std::endl;

    // if(_h_data->GetNbinsX() == 1) {
    //   LOG_CRITICAL() << "_h_data->GetBinError(1) = " << _h_data->GetBinError(1) << std::endl;
    // }


    // Plot the cross section

    TCanvas * c;

    if (_name.find("onebin") != std::string::npos) c = new TCanvas("c", "c", 0, 45, 400, 888);
    else c = new TCanvas();

    c->SetBottomMargin(0.15);

    _h_mc->GetXaxis()->SetTitle(xaxis_label.c_str());
    _h_mc->GetYaxis()->SetTitle(yaxis_label.c_str());
    _h_mc->GetXaxis()->SetTitleOffset(0.95);
    _h_mc->GetYaxis()->SetTitleOffset(0.77);

    _h_mc->SetLineColor(kGreen+2);
    _h_mc->SetFillColor(29);

    if (_name.find("mom") != std::string::npos) {
      _h_mc->SetMinimum(0.);
      _h_mc->SetMaximum(1.6);
    } else if (_name.find("onebin") != std::string::npos) {
      c->SetLeftMargin(0.2438017);
      c->SetRightMargin(0.1239669);
      c->SetBottomMargin(0.1515789);
      _h_mc->SetMinimum(0.2);
      _h_mc->SetMaximum(1.5);
      _h_mc->GetXaxis()->SetTitle("");
      _h_mc->GetYaxis()->CenterTitle(true);
      _h_mc->GetXaxis()->SetLabelSize(0);
      _h_mc->GetXaxis()->SetTitleSize(0.055);
      _h_mc->GetXaxis()->SetTickLength(0);
      _h_mc->GetYaxis()->SetNdivisions(506);
      _h_mc->GetYaxis()->SetLabelFont(42);
      _h_mc->GetYaxis()->SetLabelSize(0.05);
      _h_mc->GetYaxis()->SetTitleSize(0.07);
      _h_mc->GetYaxis()->SetTitleOffset(1.24);
      _h_mc->GetYaxis()->SetTitleFont(42);
      _h_mc->GetYaxis()->SetTickLength(0.05);
      _h_mc->GetYaxis()->SetDecimals();
    } else {
      _h_mc->SetMinimum(0.);
      _h_mc->SetMaximum(2.8);
    }
    _h_mc->Draw("E2");

    TH1D* h_mc_main = (TH1D*) _h_mc->Clone("h_mc_main");
    h_mc_main->SetLineColor(kGreen+2);
    h_mc_main->SetFillColor(0); // fully transparent
    h_mc_main->Draw("histo same");

    if (_fake_data_mode) _truth_xsec_smeared->SetLineColor(kOrange);
    if (_fake_data_mode) _truth_xsec_smeared->Draw("hist same");

    // h_data->SetMarkerStyle(kFullCircle);
    // h_data->SetMarkerSize(0.6);
    // h_data->Draw("E1 same");


    if (_add_alt_mc_xsec) {
      _h_alt_mc_xsec.SetLineColor(kBlue+1);
      _h_alt_mc_xsec.SetFillColor(38);
      _h_alt_mc_xsec.Draw("E2 same");

      TH1D* _h_alt_mc_xsec_main = (TH1D*) _h_alt_mc_xsec.Clone("_h_alt_mc_xsec_main");
      _h_alt_mc_xsec_main->SetLineColor(kBlue+1);
      _h_alt_mc_xsec_main->SetFillColor(0); // fully transparent
      _h_alt_mc_xsec_main->Draw("histo same");
    }


    //
    // Add systs uncertainties (if cov. matrix is set)
    //

    if (_extra_fractional_uncertainty != 0) {
      if (_verbose) std::cout << "Adding an extra uncertainty of " << _extra_fractional_uncertainty * 100 << "%" << std::endl;
    }

    TH1D * h_syst_unc = (TH1D*) _h_data->Clone("h_syst_unc");

    if (_frac_covariance_matrix_is_set) {

      LOG_INFO() << "Building covariance matrix from imported fractional covariance matrix." << std::endl;

      _covariance_matrix = * ( (TH2D*) _frac_covariance_matrix.Clone("_covariance_matrix"));
      _covariance_matrix.Reset();

      // Loop over the bins and multiply this fractional covariance matrix by the xsec
      // so to obtain a covariance matrix
      for (int i = 0; i < _covariance_matrix.GetNbinsX(); i++) {

        for (int j = 0; j < _covariance_matrix.GetNbinsX(); j++) {

          _covariance_matrix.SetBinContent(i+1, j+1, _frac_covariance_matrix.GetBinContent(i+1, j+1) * (_h_data->GetBinContent(i+1) * _h_data->GetBinContent(j+1)) );

        }
      }

      _covariance_matrix_is_set = true;
    }

    if (_covariance_matrix_is_set) {

      LOG_INFO() << "Evaluating systematic uncertainties from covariance matrix." << std::endl;

      // Just to set the right bins:
      _cov_matrix_total = (TH2D*)_covariance_matrix.Clone("_cov_matrix_total");
      _frac_cov_matrix_total = (TH2D*)_covariance_matrix.Clone("_frac_cov_matrix_total");
      _corr_matrix_total = (TH2D*)_covariance_matrix.Clone("_corr_matrix_total");
 
      for (int i = 0; i < _covariance_matrix.GetNbinsX(); i++) {

        for (int j = 0; j < _covariance_matrix.GetNbinsX(); j++) {

          // The statictial uncertainty squared
          double unc_stat_2 = _h_data->GetBinError(i+1) * _h_data->GetBinError(j+1);

          // The systematic uncertainty squared
          double unc_syst_2 = _covariance_matrix.GetBinContent(i+1, j+1);

          // The extra systematic uncertainty squared (POT normalisation, ...)
          double extra_unc_2 = _extra_fractional_uncertainty * _h_data->GetBinContent(i+1)   *    _extra_fractional_uncertainty * _h_data->GetBinContent(j+1);

          // The total uncertainty (quadrature sum)
          double unc_tot = std::sqrt(unc_stat_2 + unc_syst_2 + extra_unc_2);

          if (i == j) {
            if (_verbose) std::cout << "Bin " << i << " - stat: " << std::sqrt(unc_stat_2) << ", syst: " << std::sqrt(unc_syst_2) << ", tot: " << unc_tot << std::endl;
            h_syst_unc->SetBinError(i+1, unc_tot); 
          }

          // Also construct the total covariance matrix
          double total_syst_unc_2 = unc_syst_2 + extra_unc_2;

          _cov_matrix_total->SetBinContent(i+1, j+1, total_syst_unc_2);
          _frac_cov_matrix_total->SetBinContent(i+1, j+1, (total_syst_unc_2) / (_h_data->GetBinContent(i+1) * _h_data->GetBinContent(j+1)));

        } // j
      } // i

      // And also the correlation matrix
      for (int i = 0; i < _covariance_matrix.GetNbinsX(); i++) {
        for (int j = 0; j < _covariance_matrix.GetNbinsX(); j++) {
          _corr_matrix_total->SetBinContent(i+1, j+1, _cov_matrix_total->GetBinContent(i+1, j+1) / (std::sqrt(_cov_matrix_total->GetBinContent(i+1, i+1)) * std::sqrt(_cov_matrix_total->GetBinContent(j+1, j+1))));
        }
      }
    } 

    gStyle->SetEndErrorSize(5);

    // Draw the systematic error bars
    h_syst_unc->SetMarkerStyle(kFullCircle);
    h_syst_unc->SetMarkerSize(0.1);
    // h_syst_unc->SetMarkerColor(kGray+2);
    // h_syst_unc->SetLineColor(kGray+2);
    h_syst_unc->Draw("E1 X0 same");

    // Draw the statistic error bars
    _h_data->SetMarkerStyle(kFullCircle);
    _h_data->SetMarkerSize(0.6);
    _h_data->Draw("E1 X0 same");



    TLegend *l;

    if (xaxis_label.find("cos") != std::string::npos) {
      l = new TLegend(0.1590258,0.7052632,0.512894,0.8421053,NULL,"brNDC");
      l->SetTextSize(0.03578947);
    }
    else if (_name.find("onebin") != std::string::npos) {
      l = new TLegend(0.2960373,0.8042986,0.7832168,0.8642534,NULL,"brNDC");
      l->SetTextSize(0.04298643);
    } else {
      l = new TLegend(0.3825215,0.7178947,0.7363897,0.8547368,NULL,"brNDC");
      l->SetTextSize(0.03578947);
    }
    l->SetFillColor(0);
    l->SetFillStyle(0);
    
    if (!_add_alt_mc_xsec) l->AddEntry(_h_mc, "MC (Stat. Uncertainty)");
    //l->AddEntry(_truth_xsec, "Monte Carlo (Truth)", "l");
    if (_add_alt_mc_xsec) {
      l->AddEntry(_h_mc, "GENIE Default + Emp. MEC (Stat. Unc.)");
      l->AddEntry(&_h_alt_mc_xsec, "GENIE Alternative (Stat. Unc.)");
    }
    if (_covariance_matrix_is_set && _covariance_matrix.GetBinContent(1, 1) != 0.) {
      l->AddEntry(_h_data, "Measured (Stat. #oplus Syst. Unc.)", "ep");
      ///l->AddEntry(h_data, "Measured (Stat. Uncertainty)", "lep");
      if (_fake_data_mode) l->AddEntry(_truth_xsec_smeared, "Truth (Smeared)", "l");
    } else {
      l->AddEntry(_h_data, "Measured (Stat. Unc.)", "lep");
      if (_fake_data_mode) l->AddEntry(_truth_xsec_smeared, "Truth (Smeared)", "l");
    }
    l->Draw();

    // TLatex* prelim = new TLatex(0.9,0.93, "MicroBooNE Preliminary");
    // prelim->SetTextColor(kGray+1);
    // prelim->SetNDC();
    // prelim->SetTextSize(2/30.);
    // prelim->SetTextAlign(32);
    // prelim->SetTextSize(0.04631579);
    // prelim->Draw();

    if (_fake_data_mode) PlottingTools::DrawSimulation();
    else if (_overlay_mode) PlottingTools::DrawOverlay();
    else if (_name.find("onebin") != std::string::npos) PlottingTools::DrawPreliminaryXSecCentered();
    else PlottingTools::DrawPreliminaryXSec();

    if (_fake_data_mode) {
      TLatex* tex = new TLatex(0.5773639,0.6547368, "FAKE DATA");
      tex->SetNDC();
      tex->SetTextAlign(32);
      tex->SetTextColor(2);
      tex->SetTextSize(0.04210526);
      tex->SetLineWidth(2);
      tex->Draw();
    }
    

    TString name = _folder +_name + "_xsec";
    c->SaveAs(name + ".pdf");
    c->SaveAs(name + ".C","C");

    if (_h_data->GetNbinsX() == 1) {
      LOG_INFO() << "Total cross section - DATA: " << _h_data->GetBinContent(1) << " +- " << _h_data->GetBinError(1) << std::endl;
      LOG_INFO() << "Total cross section - MC  : " << _h_mc->GetBinContent(1)   << " +- " << _h_mc->GetBinError(1) << std::endl;
    }


    if (_covariance_matrix_is_set) {

      gStyle->SetPalette(kDeepSea);
      gStyle->SetPaintTextFormat("4.4f");

      // const Int_t NCont = 100;
      // const Int_t NRGBs = 5;
      // Double_t mainColour[NRGBs]   = { 1.00, 1.00, 1.00, 1.00, 1.00 };
      // Double_t otherColour[NRGBs]   = { 0.99,0.80, 0.60, 0.40, 0.20 };
      // //Double_t otherOtherColour[NRGBs]   = { 0.9,0.80, 0.80, 0.80, 0.80 };
      // Double_t stops[NRGBs] = { 0.00, 0.05, 0.1, 0.4, 1.00 };

      // TColor::CreateGradientColorTable(NRGBs, stops, mainColour, otherColour, otherColour, NCont);
      // gStyle->SetNumberContours(NCont);

      // const int NRGBs = 3; 
      // int NCont = 512; 
      // gStyle->SetNumberContours(NCont); 
      // Double_t stops[NRGBs] = { 0.00, 0.50, 1.00 }; 
      // Double_t red[NRGBs]   = { 0.20, 1.00, 1.00 }; 
      // Double_t green[NRGBs] = { 0.20, 1.00, 0.20 }; 
      // Double_t blue[NRGBs]  = { 0.20, 1.00, 0.20 }; 
      // TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);

      const Int_t Number = 9;
      Double_t Red[Number]    = { 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00 };
      Double_t Green[Number]  = { 1.00, 0.90, 0.80, 0.70, 0.60, 0.50, 0.40, 0.30, 0.20 };
      Double_t Blue[Number]   = { 1.00, 0.90, 0.80, 0.70, 0.60, 0.50, 0.40, 0.30, 0.20 };
      Double_t Stops[Number] =  { 0.00, 0.15, 0.30, 0.40, 0.50, 0.60, 0.70, 0.85, 1.00 };
      Int_t nb=100;
      TColor::CreateGradientColorTable(Number,Stops,Red,Green,Blue,nb);
   

      TH2F *h = new TH2F("h", "", _cov_matrix_total->GetNbinsX(), 0, _cov_matrix_total->GetNbinsX(),
                                  _cov_matrix_total->GetNbinsY(), 0, _cov_matrix_total->GetNbinsY());
      
      h->SetMaximum(1);

      for (int i = 0; i <  _cov_matrix_total->GetNbinsX()+1; i++) {
        std::ostringstream oss;
        oss << i;
        std::string label = oss.str();
        if (i == 0) continue;
        h->GetXaxis()->SetBinLabel(i,label.c_str());
        h->GetYaxis()->SetBinLabel(i,label.c_str());
      }
      
      h->GetXaxis()->SetLabelOffset(0.004);
      h->GetXaxis()->SetLabelSize(0.06);
      h->GetYaxis()->SetLabelOffset(0.004);
      h->GetYaxis()->SetLabelSize(0.06);
      h->GetXaxis()->SetTitle("Bin i");
      h->GetYaxis()->SetTitle("Bin j");
      h->GetXaxis()->CenterTitle();
      h->GetYaxis()->CenterTitle();

      TCanvas * cov_c = new TCanvas();
      cov_c->SetRightMargin(0.13);
      cov_c->SetFixedAspectRatio();
      _cov_matrix_total->SetMarkerColor(kBlack);
      _cov_matrix_total->SetMarkerSize(1.8);
      _cov_matrix_total->GetXaxis()->CenterTitle();
      _cov_matrix_total->GetYaxis()->CenterTitle();
      _cov_matrix_total->GetXaxis()->SetTitle("Bin i");
      _cov_matrix_total->GetYaxis()->SetTitle("Bin j");
      _cov_matrix_total->GetXaxis()->SetTickLength(0);
      _cov_matrix_total->GetYaxis()->SetTickLength(0);
      h->Draw();
      _cov_matrix_total->Draw("colz text same");
      // _cov_matrix_total->Draw("colz same");
      PlottingTools::DrawSimulationCovariance();
      name = _folder +_name + "_tot_covariance";
      cov_c->SaveAs(name + ".pdf");
      cov_c->SaveAs(name + ".C","C");

      TCanvas * cov_frac_c = new TCanvas();
      cov_frac_c->SetRightMargin(0.13);
      cov_frac_c->SetFixedAspectRatio();
      _frac_cov_matrix_total->SetMarkerColor(kBlack);
      _frac_cov_matrix_total->SetMarkerSize(1.8);
      _frac_cov_matrix_total->GetXaxis()->CenterTitle();
      _frac_cov_matrix_total->GetYaxis()->CenterTitle();
      _frac_cov_matrix_total->GetXaxis()->SetTitle("Bin i");
      _frac_cov_matrix_total->GetYaxis()->SetTitle("Bin j");
      _frac_cov_matrix_total->GetXaxis()->SetTickLength(0);
      _frac_cov_matrix_total->GetYaxis()->SetTickLength(0);
      h->Draw();
      _frac_cov_matrix_total->Draw("colz text same");
      // _frac_cov_matrix_total->Draw("colz same");
      PlottingTools::DrawSimulationCovariance();
      name = _folder +_name + "_tot_fractional_covariance";
      cov_frac_c->SaveAs(name + ".pdf");
      cov_frac_c->SaveAs(name + ".C","C");

      TCanvas * corr_c = new TCanvas();
      corr_c->SetRightMargin(0.13);
      corr_c->SetFixedAspectRatio();
      _corr_matrix_total->SetMarkerColor(kBlack);
      _corr_matrix_total->SetMarkerSize(1.8);
      _corr_matrix_total->GetXaxis()->CenterTitle();
      _corr_matrix_total->GetYaxis()->CenterTitle();
      _corr_matrix_total->GetXaxis()->SetTitle("Bin i");
      _corr_matrix_total->GetYaxis()->SetTitle("Bin j");
      _corr_matrix_total->GetXaxis()->SetTickLength(0);
      _corr_matrix_total->GetYaxis()->SetTickLength(0);
      h->Draw();
      _corr_matrix_total->Draw("colz text same");
      // _corr_matrix_total->Draw("colz same");
      PlottingTools::DrawSimulationCovariance();
      name = _folder +_name + "_tot_correlation";
      corr_c->SaveAs(name + ".pdf");
      corr_c->SaveAs(name + ".C","C");

      gStyle->SetPalette(kRainBow);
    }


    gStyle->SetEndErrorSize(3);

    return _h_data;

  }



  void CrossSectionCalculator1D::Draw(std::vector<std::string> histos_to_subtract)
  {

    bool bin_width_scale = false;

    TH1D* _h_data_subtracted = (TH1D*)_h_bnbon->Clone("_h_data_subtracted");
    _h_data_subtracted->Sumw2();

    for (auto hname : histos_to_subtract) 
    {
      LOG_INFO() << "Going to subtract histogram " << hname << std::endl;
      // Need to remove from the data histogram
      _h_data_subtracted->Add(_hmap_bnbcosmic[hname], -1.);
      // But also form the total MC one, to properly propagate unc
      _hmap_bnbcosmic["total"]->Add(_hmap_bnbcosmic[hname], -1.);
    }


    TLegend* leg;

    if (_name.find("costheta") != std::string::npos) {
      leg = new TLegend(0.1733524,0.3936842,0.4340974,0.8442105,NULL,"brNDC");
    } else {
      leg = new TLegend(0.56,0.57,0.82,0.82,NULL,"brNDC");
    }

    TCanvas* canvas = new TCanvas();

    THStack *hs_mc = this->ProcessTHStack(_hmap_bnbcosmic, leg, histos_to_subtract);

    TH1D* data = ProcessDataHisto(_h_data_subtracted);

    if (bin_width_scale) {
      _hmap_bnbcosmic["signal"]->Scale(1, "width");
      _hmap_bnbcosmic["total"]->Scale(1, "width");
      data->Scale(1, "width");
    } 

    hs_mc->Draw("hist");
    _hmap_bnbcosmic["total"]->Draw("E2 same"); // errors
    data->Draw("E1 same");

    leg->AddEntry(data, "Data (Background subtracted)", "lep");
    leg->AddEntry(_hmap_bnbcosmic["total"], "Stat. Unc.");
    leg->Draw();


    TLatex* l = this->GetPOTLatex(_pot);
    l->Draw();

    TString name = _folder +_name + "_selectedevents_bkgsubtracted";
    canvas->SaveAs(name + ".pdf");
    canvas->SaveAs(name + ".C");


  }

  void CrossSectionCalculator1D::Draw() 
  {

    bool bin_width_scale = false;

    TLegend* leg;

    if (_name.find("costheta") != std::string::npos) {
      leg = new TLegend(0.1733524,0.3936842,0.4340974,0.8442105,NULL,"brNDC");
    } else {
      leg = new TLegend(0.56,0.37,0.82,0.82,NULL,"brNDC");
    }

    TCanvas* canvas = new TCanvas("canvas", "canvas", 800, 700);

    TH1D* data = ProcessDataHisto(_h_bnbon);

    if (bin_width_scale) {
      for (auto it : _hmap_bnbcosmic) {
        it.second->Scale(1, "width");
      }
      data->Scale(1, "width");
    } 

    std::vector<std::string> histos_to_subtract; histos_to_subtract.clear();
    THStack *hs_mc = this->ProcessTHStack(_hmap_bnbcosmic, leg, histos_to_subtract);

    

    this->DrawDataMC(canvas, hs_mc, data, leg);

    

    // hs_mc->Draw("hist");
    // _hmap_bnbcosmic["total"]->Draw("E2 same"); // errors
    // data->Draw("same");

    // leg->AddEntry(data, "Data (Beam-on)", "lep");
    // leg->Draw();


    // TLatex* l = this->GetPOTLatex(_pot);
    // l->Draw();




    TString name = _folder +_name + "_selectedevents";
    canvas->SaveAs(name + ".pdf");
    canvas->SaveAs(name + ".C","C");


  } 


  void CrossSectionCalculator1D::DrawDataMC(TCanvas* c, THStack *hs_mc, TH1D* h_data_bnbon, TLegend* leg)
  {

    // Upper plot will be in pad1
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.25, 1, 1.0);
    pad1->SetBottomMargin(0); // Upper and lower plot are joined
    pad1->SetRightMargin(0.06);
    pad1->SetLeftMargin(0.13);
    pad1->SetGridx();         // Vertical grid
    pad1->Draw();             // Draw the upper pad: pad1
    pad1->cd();               // pad1 becomes the current pad
    //if (variable == 0 || variable == 1) histo_p1->SetMaximum(1.);

    // histo_p1->Draw("histo");               // Draw h1
    // histo->Draw("histo same");         // Draw h2 on top of h1
    // histo_m1->Draw("histo same");

    hs_mc->Draw("hist");
    _hmap_bnbcosmic["total"]->Draw("E2 same"); // errors
    h_data_bnbon->Draw("same");

    leg->AddEntry(_hmap_bnbcosmic["total"],"Stat. Unc.","f");
    leg->AddEntry(h_data_bnbon,"Data (Beam-on)","lep");
    leg->Draw();

    PlottingTools::DrawPOTRatio(_pot);
    PlottingTools::DrawPreliminary();


    // Do not draw the Y axis label on the upper plot and redraw a small
    // axis instead, in order to avoid the first label (0) to be clipped.
    // hs_mc->GetYaxis()->SetLabelSize(0.);
    // TGaxis *axis = new TGaxis( -5, 0.1, -5, 4000, 0.1,4000,510,"");
    // axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    // axis->SetLabelSize(15);
    // axis->Draw();
    hs_mc->SetMinimum(0.01);
    hs_mc->GetYaxis()->SetTitleOffset(1.18);
    hs_mc->GetYaxis()->CenterTitle(true);

    double max_up = _hmap_bnbcosmic["total"]->GetBinContent(_hmap_bnbcosmic["total"]->GetMaximumBin());
    hs_mc->SetMaximum(max_up+max_up*0.4);

    // lower plot will be in pad
    c->cd();          // Go back to the main canvas before defining pad2
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.01, 1, 0.25);
    pad2->SetTopMargin(0);
    pad2->SetFrameFillStyle(4000);
    pad2->SetBottomMargin(0.35);
    pad2->SetRightMargin(0.06);
    pad2->SetLeftMargin(0.13);
    pad2->SetGridx(); // vertical grid
    //pad2->SetGridy(); // orizontal grid
    pad2->Draw();
    pad2->cd();       // pad2 becomes the current pad

    // Define the first ratio plot
    TH1D *ratio = (TH1D*)h_data_bnbon->Clone("ratio");
    //ratio->SetMinimum(0.92);  // Define Y ..
    //ratio->SetMaximum(1.08); // .. range
    //ratio->Sumw2();
    ratio->SetStats(0);      // No statistics on lower plot
    ratio->Divide(_hmap_bnbcosmic["total"]);
    ratio->SetLineWidth(2);
    ratio->SetLineColor(kBlack);
    ratio->SetMarkerStyle(kFullCircle);
    ratio->SetMarkerSize(0.6);

    ratio->GetYaxis()->SetTitle("Ratio");
    ratio->GetXaxis()->SetTitle(hs_mc->GetXaxis()->GetTitle());

    ratio->GetXaxis()->CenterTitle(true);
    ratio->GetXaxis()->SetLabelFont(42);
    ratio->GetXaxis()->SetLabelSize(0.12);
    ratio->GetXaxis()->SetTitleSize(0.18);
    ratio->GetXaxis()->SetTickLength(0.09);
    ratio->GetXaxis()->SetTitleOffset(0.8);
    ratio->GetXaxis()->SetTitleFont(42);

    ratio->GetYaxis()->CenterTitle(true);
    ratio->GetYaxis()->SetLabelFont(42);
    ratio->GetYaxis()->SetLabelSize(0.12);
    ratio->GetYaxis()->SetTitleSize(0.16);
    ratio->GetYaxis()->SetTitleOffset(0.27);
    ratio->GetYaxis()->SetTitleFont(42);

    ratio->Draw("E1");       // Draw the ratio plot

    double max = ratio->GetBinContent(ratio->GetMaximumBin());
    double min = ratio->GetBinContent(ratio->GetMinimumBin());

    // std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> max: " << max << std::endl;
    // std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> min: " << min << std::endl;

    ratio->SetMaximum(max+max*0.1);
    ratio->SetMinimum(min-min*0.1);

    gPad->Update();

    TLine *line = new TLine(ratio->GetXaxis()->GetXmin(),1,ratio->GetXaxis()->GetXmax(),1);
    line->SetLineColor(kBlack);
    line->SetLineStyle(9); // dashed
    line->Draw();

  }




  THStack * CrossSectionCalculator1D::ProcessTHStack(std::map<std::string,TH1D*> themap, TLegend* leg, std::vector<std::string> histos_to_subtract){

    THStack *hs_trklen = new THStack("hs",_label.c_str());

    bool _breakdownPlots = false;

    bool _draw_beamoff = true, _draw_dirt = true, _draw_cosmic = true, _draw_outfv = true, _draw_nue = true, _draw_nc = true, _draw_anumu = true;

    for (auto name: histos_to_subtract)
    {
      if (name == "beam-off") _draw_beamoff = false;
      if (name == "dirt") _draw_dirt = false;
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

    if (themap["dirt"] != NULL && _draw_dirt) {
      themap["dirt"]->SetLineColor(kOrange+3);
      themap["dirt"]->SetFillColor(kOrange+3);
      hs_trklen->Add(themap["dirt"]);
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





    std::string int_option = "width";

    if (_breakdownPlots){
      //leg = new TLegend(0.56,0.37,0.82,0.82,NULL,"brNDC");
    } else {
      //leg = new TLegend(0.56,0.54,0.82,0.82,NULL,"brNDC");
    }
    std::stringstream sstm;
  // numu
    if (_breakdownPlots) {
      sstm << "#nu_{#mu} CC (stopping #mu), " << std::setprecision(2)  << themap["signal_stopmu"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
      leg->AddEntry(themap["signal_stopmu"],sstm.str().c_str(),"f");
      sstm.str("");
      sstm << "#nu_{#mu} CC (other), " << std::setprecision(2)  << themap["signal_nostopmu"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
      leg->AddEntry(themap["signal_nostopmu"],sstm.str().c_str(),"f");
      sstm.str("");
      // leg->AddEntry(themap["signal_stopmu"],"#nu_{#mu} CC (stopping #mu)","f");
      // leg->AddEntry(themap["signal_nostopmu"],"#nu_{#mu} CC (other)","f");
    } else {
      sstm << "#nu_{#mu} CC (signal), " << std::setprecision(2)  << themap["signal"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
      leg->AddEntry(themap["signal"],sstm.str().c_str(),"f");
      sstm.str("");
    }

  // nue
    sstm << "#nu_{e}, #bar{#nu}_{e} CC, " << std::setprecision(2)  << themap["nue"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
    if (_draw_nue) leg->AddEntry(themap["nue"],sstm.str().c_str(),"f");
    sstm.str("");

  // anumu
    sstm << "#bar{#nu}_{#mu} CC, " << std::setprecision(2)  << themap["anumu"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
    if (_draw_anumu)leg->AddEntry(themap["anumu"],sstm.str().c_str(),"f");
    sstm.str("");

  // nc, outfv, cosmic
    if (_breakdownPlots) {
      sstm << "NC (other), " << std::setprecision(2)  << themap["nc_other"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
    leg->AddEntry(themap["nc_other"],sstm.str().c_str(),"f");
    sstm.str("");
    // leg2->AddEntry(themap["nc_other"],"NC (other)","f");

    sstm << "NC (pion), " << std::setprecision(2)  << themap["nc_pion"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
    leg->AddEntry(themap["nc_pion"],sstm.str().c_str(),"f");
    sstm.str("");
    // leg2->AddEntry(themap["nc_pion"],"NC (pion)","f");

    sstm << "NC (proton), " << std::setprecision(2)  << themap["nc_proton"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
    leg->AddEntry(themap["nc_proton"],sstm.str().c_str(),"f");
    sstm.str("");
    // leg2->AddEntry(themap["nc_proton"],"NC (proton)","f");

    sstm << "OUTFV (stopping #mu), " << std::setprecision(2)  << themap["outfv_stopmu"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
    leg->AddEntry(themap["outfv_stopmu"],sstm.str().c_str(),"f");
    sstm.str("");
    // leg2->AddEntry(themap["outfv_stopmu"],"OUTFV (stopping #mu)","f");

    sstm << "OUTFV (other), " << std::setprecision(2)  << themap["outfv_nostopmu"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
    leg->AddEntry(themap["outfv_nostopmu"],sstm.str().c_str(),"f");
    sstm.str("");
    // leg2->AddEntry(themap["outfv_nostopmu"],"OUTFV (other)","f");

    sstm << "Cosmic (stopping #mu), " << std::setprecision(2)  << themap["cosmic_stopmu"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
    leg->AddEntry(themap["cosmic_stopmu"],sstm.str().c_str(),"f");
    sstm.str("");
    // leg2->AddEntry(themap["cosmic_stopmu"],"Cosmic (stopping #mu)","f");

    sstm << "Cosmic (other), " << std::setprecision(2)  << themap["cosmic_nostopmu"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
    leg->AddEntry(themap["cosmic_nostopmu"],sstm.str().c_str(),"f");
    sstm.str("");
    // leg2->AddEntry(themap["cosmic_nostopmu"],"Cosmic (other)","f");
      if (themap["intimecosmic"] != NULL) {
        leg->AddEntry(themap["intimecosmic"],"In-time cosmics","f");
      }
    } else {
      sstm << "NC, " << std::setprecision(2)  << themap["nc"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
      if (_draw_nc) leg->AddEntry(themap["nc"],sstm.str().c_str(),"f");
      sstm.str("");

      sstm << "OUTFV, " << std::setprecision(2)  << themap["outfv"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
      if (_draw_outfv) leg->AddEntry(themap["outfv"],sstm.str().c_str(),"f");
      sstm.str("");

      sstm << "Cosmic, " << std::setprecision(2)  << themap["cosmic"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
      if (_draw_cosmic) leg->AddEntry(themap["cosmic"],sstm.str().c_str(),"f");
      sstm.str("");
    }
    //leg->AddEntry(themap["total"],"Stat Unc.","f");


    if (themap["dirt"] != NULL && _draw_dirt){
      sstm << "Dirt, " << std::setprecision(2)  << themap["dirt"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
      leg->AddEntry(themap["dirt"],sstm.str().c_str(),"f");
      sstm.str("");
      // leg->AddEntry(themap["beam-off"],"Data (Beam-off)","f");
    }

    if (themap["beam-off"] != NULL && _draw_beamoff){
      sstm << "Data (Beam-off), " << std::setprecision(2)  << themap["beam-off"]->Integral(int_option.c_str()) / themap["total"]->Integral(int_option.c_str())*100. << "%";
      leg->AddEntry(themap["beam-off"],sstm.str().c_str(),"f");
      sstm.str("");
      // leg->AddEntry(themap["beam-off"],"Data (Beam-off)","f");
    }
    

    return hs_trklen;

  }

  TH1D* CrossSectionCalculator1D::ProcessDataHisto(TH1D* histo) {

    histo->SetMarkerStyle(kFullCircle);
    histo->SetMarkerSize(0.6);

    return histo;

  }


  TLatex* CrossSectionCalculator1D::GetPOTLatex(double pot) {

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

  void CrossSectionCalculator1D::PrintFakeDataMessage() {
    for (int i = 0; i < 10; i++) {   
      std::cout << "****************************** RUNNING WITH FAKE DATA ******************************" << std::endl;
    }
  }
}

#endif

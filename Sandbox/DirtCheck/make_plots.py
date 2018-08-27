import sys, os
import math

from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")





def plot_and_save(histo1, histo2, save_name):

  c_numuEnergy = TCanvas()

  # Upper plot will be in pad1
  pad1 = TPad("pad1", "pad1", 0, 0.25, 1, 1.0);
  pad1.SetBottomMargin(0); # Upper and lower plot are joined
  pad1.SetRightMargin(0.06);
  pad1.SetLeftMargin(0.13);
  pad1.SetGridx();         # Vertical grid
  pad1.Draw();             # Draw the upper pad: pad1
  pad1.cd();               # pad1 becomes the current pad
     



  # Do not draw the Y axis label on the upper plot and redraw a small
  # axis instead, in order to avoid the first label (0) to be clipped.
  # hs_mc->GetYaxis()->SetLabelSize(0.);
  # TGaxis *axis = new TGaxis( -5, 0.1, -5, 4000, 0.1,4000,510,"");
  # axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  # axis->SetLabelSize(15);
  # axis->Draw();
  histo1.SetMinimum(0.01);
  histo1.GetYaxis().SetTitleOffset(1.18);
  histo1.GetYaxis().CenterTitle(True);

  histo1.SetLineColor(kRed+2)
  histo1.Draw("histo")
  histo2.SetLineColor(kGreen+2)
  histo2.Draw("histo same")


  leg = TLegend(0.5744986,0.6940351,0.9340974,0.8512281)
  leg.SetBorderSize(0)
  leg.SetFillColor(0)
  leg.SetFillStyle(0)
  leg.SetTextFont(42)
  leg.SetTextSize(0.05614035)
  leg.AddEntry(histo1,"Nominal Simulation","L")
  leg.AddEntry(histo2,"Dirt Simulation","L")
  leg.Draw()


      # lower plot will be in pad
  c_numuEnergy.cd();          # Go back to the main canvas before defining pad2
  pad2 = TPad("pad2", "pad2", 0, 0.01, 1, 0.25);
  pad2.SetTopMargin(0);
  pad2.SetFrameFillStyle(4000);
  pad2.SetBottomMargin(0.35);
  pad2.SetRightMargin(0.06);
  pad2.SetLeftMargin(0.13);
  pad2.SetGridx(); # vertical grid
  #pad2->SetGridy(); // orizontal grid
  pad2.Draw();
  pad2.cd();       # pad2 becomes the current pad

  # Define the first ratio plot
  ratio = histo1.Clone("ratio");
  #ratio->SetMinimum(0.92);  // Define Y ..
  #ratio->SetMaximum(1.08); // .. range
  #ratio->Sumw2();
  ratio.SetStats(0);      # No statistics on lower plot
  ratio.Divide(histo2);
  ratio.SetLineWidth(2);
  ratio.SetLineColor(kBlack);
  # ratio.SetMarkerStyle(kFullCircle);
  # ratio.SetMarkerSize(0.6)
  ratio.GetYaxis().SetTitle("Ratio");
  ratio.GetXaxis().SetTitle(histo1.GetXaxis().GetTitle());

  ratio.GetXaxis().CenterTitle(True);
  ratio.GetXaxis().SetLabelFont(42);
  ratio.GetXaxis().SetLabelSize(0.12);
  ratio.GetXaxis().SetTitleSize(0.18);
  ratio.GetXaxis().SetTickLength(0.09);
  ratio.GetXaxis().SetTitleOffset(0.8);
  ratio.GetXaxis().SetTitleFont(42);

  ratio.GetYaxis().CenterTitle(True);
  ratio.GetYaxis().SetLabelFont(42);
  ratio.GetYaxis().SetLabelSize(0.12);
  ratio.GetYaxis().SetTitleSize(0.16);
  ratio.GetYaxis().SetTitleOffset(0.27);
  ratio.GetYaxis().SetTitleFont(42);

  ratio.SetFillColor(kGray)
  ratio.Draw("E2");       # Draw the ratio plot
  ratio_main = ratio.Clone("ratio_main");
  # ratio_main.SetLineColor(kGray);
  ratio_main.SetFillColor(0); # fully transparent
  ratio_main.Draw("histo same");

  max = ratio.GetBinContent(ratio.GetMaximumBin());
  min = ratio.GetBinContent(ratio.GetMinimumBin());

  # std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> max: " << max << std::endl;
  # std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> min: " << min << std::endl;

  ratio.SetMaximum(max+max*0.1);
  ratio.SetMinimum(min-min*0.1);

  gPad.Update();

  line = TLine(ratio.GetXaxis().GetXmin(),1,ratio.GetXaxis().GetXmax(),1);
  line.SetLineColor(kBlack);
  line.SetLineStyle(9); # dashed
  line.Draw();

  c_numuEnergy.SaveAs(save_name)















# file_v1 = TFile("dirt_analysed_v1.root");
file_v1 = TFile("dirt_analysed_v1_nc.root");
numuEnergy_v1 = file_v1.Get("numuEnergy")
numuQ2_v1 = file_v1.Get("numuQ2")

# file_dirt = TFile("dirt_analysed_dirt.root");
file_dirt = TFile("dirt_analysed_dirt_nc.root");
numuEnergy_dirt = file_dirt.Get("numuEnergy")
numuQ2_dirt = file_dirt.Get("numuQ2")



# numuEnergy_v1.SetLineColor(kRed+2)
# numuEnergy_v1.Draw("histo")
# numuEnergy_dirt.SetLineColor(kGreen+2)
# numuEnergy_dirt.Draw("histo same")






histo1 = numuEnergy_v1.Rebin(10, "histo1")
histo2 = numuEnergy_dirt.Rebin(10, "histo2")


histo1.Sumw2()
histo2.Sumw2()

histo1.GetXaxis().SetRangeUser(0, 2.)
histo2.GetXaxis().SetRangeUser(0, 2.)

plot_and_save(histo1, histo2, "test.pdf")



histo1 = numuQ2_v1.Rebin(10, "histo1")
histo2 = numuQ2_dirt.Rebin(10, "histo2")

histo1.Sumw2()
histo2.Sumw2()

histo1.GetXaxis().SetRangeUser(0, 2.)
histo2.GetXaxis().SetRangeUser(0, 2.)

plot_and_save(histo1, histo2, "test.pdf")












raw_input("Please press enter to exit.")

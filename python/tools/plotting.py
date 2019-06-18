import ROOT
import array
from ROOT import *
import sys, os, math


def get_mumom_label(text):

  ub_label_mumom = TLatex(0.4240688,0.7473684,"MicroBooNE #bf{" + text + "}")
  if text == "nothing":
    ub_label_mumom = TLatex(0.4670487,0.7515789,"MicroBooNE")

  ub_label_mumom.SetNDC()
  ub_label_mumom.SetTextColor(kGray+2)
  ub_label_mumom.SetTextSize(0.04631579)
  ub_label_mumom.SetLineWidth(2)
  ub_label_mumom.SetTextFont(62)

  return ub_label_mumom


def get_muangle_label(text):

  ub_label_muangle = TLatex(0.2077364,0.7368421,"MicroBooNE #bf{" + text + "}")
  if text == "nothing":
    ub_label_muangle = TLatex(0.2077364,0.7368421,"MicroBooNE")

  ub_label_muangle.SetNDC()
  ub_label_muangle.SetTextColor(kGray+2)
  ub_label_muangle.SetTextSize(0.04631579)
  ub_label_muangle.SetLineWidth(2)
  ub_label_muangle.SetTextFont(62)

  return ub_label_muangle


def get_mumangle_mumom_label(text):

  ub_label = TLatex(0.8753582,0.7515789, "MicroBooNE #bf{" + text + "}")
  if text == "nothing":
    ub_label = TLatex(0.8753582,0.7515789, "MicroBooNE")
  
  ub_label.SetNDC()
  ub_label.SetTextAlign(12)
  ub_label.SetTextColor(kGray+2)
  ub_label.SetTextSize(0.07)
  ub_label.SetTextAlign(32)
  ub_label.SetLineWidth(2)
  ub_label.SetTextFont(62)
  
  return ub_label
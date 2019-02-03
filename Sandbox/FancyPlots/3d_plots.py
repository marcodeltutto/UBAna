import sys, os, math
from array import array
import ROOT
from ROOT import *
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")


f_ubana = ROOT.TFile("./xsec_file_cv.root")
xsec_h = f_ubana.Get("xsec_poly_muangle_mumom_cv")

bins = [(-1, 0, -0.5, 0.18), (-1, 0.18, -0.5, 0.3), (-1, 0.3, -0.5, 0.45), (-1, 0.45, -0.5, 0.77), (-1, 0.77, -0.5, 2.5), (-0.5, 0, 0, 0.18), (-0.5, 0.18, 0, 0.3), (-0.5, 0.3, 0, 0.45), (-0.5, 0.45, 0, 0.77), (-0.5, 0.77, 0, 2.5), (0, 0, 0.27, 0.18), (0, 0.18, 0.27, 0.3), (0, 0.3, 0.27, 0.45), (0, 0.45, 0.27, 0.77), (0, 0.77, 0.27, 2.5), (0.27, 0, 0.45, 0.3), (0.27, 0.3, 0.45, 0.45), (0.27, 0.45, 0.45, 0.77), (0.27, 0.77, 0.45, 2.5), (0.45, 0, 0.62, 0.3), (0.45, 0.3, 0.62, 0.45), (0.45, 0.45, 0.62, 0.77), (0.45, 0.77, 0.62, 2.5), (0.62, 0, 0.76, 0.3), (0.62, 0.3, 0.76, 0.45), (0.62, 0.45, 0.76, 0.77), (0.62, 0.77, 0.76, 2.5), (0.76, 0, 0.86, 0.3), (0.76, 0.3, 0.86, 0.45), (0.76, 0.45, 0.86, 0.77), (0.76, 0.77, 0.86, 1.28), (0.76, 1.28, 0.86, 2.5), (0.86, 0, 0.94, 0.3), (0.86, 0.3, 0.94, 0.45), (0.86, 0.45, 0.94, 0.77), (0.86, 0.77, 0.94, 1.28), (0.86, 1.28, 0.94, 2.5), (0.94, 0, 1, 0.3), (0.94, 0.3, 1, 0.45), (0.94, 0.45, 1, 0.77), (0.94, 0.77, 1, 1.28), (0.94, 1.28, 1, 2.5)]


histos = []
for i in xrange(0, 42):
  this_h = TH2D('h'+str(i), '', 1, bins[i][0], bins[i][1], 1, bins[i][2], bins[i][3])
  this_h.SetBinContent(1, 1, xsec_h.GetBinContent(i+1))
  histos.append(this_h)

# c = TCanvas()

# empty = xsec_h.Clone('empty')
# empty.Draw("lego3 same");
# hs = THStack();
# for i in xrange(0, 42):
#   hs.Draw("lego3 same");
  # hs.Add(histos[i])
# hs.Draw("lego3 same");


# ctbins = array("d",[-1.00, -0.50, 0.00, 0.27, 0.45, 0.62, 0.76, 0.86, 0.94, 1.00])
# pbins = array("d",[0.00, 0.18, 0.30, 0.45, 0.77, 1.28, 2.50])

# xsec_2d = TH2D('xsec_2d', '', 9, ctbins, 6, pbins)
# for i in xrange(0, 42):
#   content = xsec_h.GetBinContent(i+1)
#   bin_center_x = (bins[i][2] + bins[i][0]) / 2
#   bin_center_y = (bins[i][3] + bins[i][1]) / 2
#   xsec_2d.Fill(bin_center_x, bin_center_y, content)
#   print bin_center_x, bin_center_y, content

# xsec_2d.SetBinContent(xsec_2d.FindBin(-0.75, 1), xsec_h.GetBinContent(5))
# xsec_2d.SetBinContent(xsec_2d.FindBin(-0.25, 1), xsec_h.GetBinContent(10))
# xsec_2d.SetBinContent(xsec_2d.FindBin(0.135, 1), xsec_h.GetBinContent(15))
# xsec_2d.SetBinContent(xsec_2d.FindBin(0.36, 1), xsec_h.GetBinContent(18))
# xsec_2d.SetBinContent(xsec_2d.FindBin(0.535, 1), xsec_h.GetBinContent(23))
# xsec_2d.SetBinContent(xsec_2d.FindBin(0.69, 1), xsec_h.GetBinContent(27))

# xsec_2d.SetBinContent(xsec_2d.FindBin(0.36, 0.24), xsec_h.GetBinContent(16))
# xsec_2d.SetBinContent(xsec_2d.FindBin(0.535, 0.24), xsec_h.GetBinContent(20))
# xsec_2d.SetBinContent(xsec_2d.FindBin(0.69, 0.24), xsec_h.GetBinContent(24))
# xsec_2d.SetBinContent(xsec_2d.FindBin(0.81, 0.24), xsec_h.GetBinContent(28))
# xsec_2d.SetBinContent(xsec_2d.FindBin(0.9, 0.24), xsec_h.GetBinContent(33))
# xsec_2d.SetBinContent(xsec_2d.FindBin(0.97, 0.24), xsec_h.GetBinContent(38))


# # xsec_2d.Draw('lego1')
# xsec_2d.SetFillColor(kWhite)
# xsec_2d.SetLineColor(kWhite)

# xsec_2d_clone = xsec_2d.Clone()
# xsec_2d_clone.Scale(0.1)
# xsec_2d_clone.SetFillColor(kGreen+2)
# xsec_2d_clone.SetLineColor(kGreen+2)

# xsec_2d_clone2 = xsec_2d.Clone()
# xsec_2d_clone2.Scale(0.1)
# xsec_2d_clone2.SetFillColor(kRed+2)
# xsec_2d_clone2.SetLineColor(kRed+2)

# xsec_2d_clone3 = xsec_2d.Clone()
# xsec_2d_clone3.Scale(0.1)
# xsec_2d_clone3.SetFillColor(kGreen+2)
# xsec_2d_clone3.SetLineColor(kGreen+2)

# c = TCanvas()
# hs = THStack();
# hs.Add(xsec_2d)
# hs.Add(xsec_2d_clone)
# hs.Add(xsec_2d_clone2)
# hs.Add(xsec_2d_clone3)
# hs.Draw("lego4");




from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
x, y = np.random.rand(2, 100) * 4
hist, xedges, yedges = np.histogram2d(x, y, bins=4, range=[[0, 4], [0, 4]])

# Construct arrays for the anchor positions of the 16 bars.
# Note: np.meshgrid gives arrays in (ny, nx) so we use 'F' to flatten xpos,
# ypos in column-major order. For numpy >= 1.7, we could instead call meshgrid
# with indexing='ij'.
xpos, ypos = np.meshgrid(xedges[:-1] + 0.25, yedges[:-1] + 0.25)
xpos = xpos.flatten('F')
ypos = ypos.flatten('F')
# z position set to zero
zpos = np.zeros_like(xpos)

# Construct arrays with the dimensions for the 16 bars.
dx = np.ones_like(zpos)
dy = dx.copy()
dz = hist.flatten()
# Create a random second histogram
dz2 = dz * np.random.rand(16)
# Set z position to the values of the first histogram
zpos2 = dz

ax.bar3d(xpos, ypos, zpos, dx, dy, dz, color='b', zsort='average')
ax.bar3d(xpos, ypos, zpos2, dx, dy, dz2, color='r', zsort='average')

plt.show()








# from mpl_toolkits.mplot3d import Axes3D
# import matplotlib.pyplot as plt
# import numpy as np

# fig = plt.figure()
# ax = fig.add_subplot(111, projection = "3d")

# ax.set_xlabel("x")
# ax.set_ylabel("y") 
# ax.set_zlabel("z")
# ax.set_xlim3d(0,10)
# ax.set_ylim3d(0,10) 

# xpos = [2,5,8,2,5,8,2,5,8]
# ypos = [1,1,1,5,5,5,9,9,9]
# zpos = np.zeros(9)

# dx = np.ones(9)
# dy = np.ones(9)
# dz = [np.random.random(9) for i in range(4)]  # the heights of the 4 bar sets

# _zpos = zpos   # the starting zpos for each bar
# colors = ['r', 'b', 'g', 'y']
# for i in range(4):
#     ax.bar3d(xpos, ypos, _zpos, dx, dy, dz[i], color=colors[i])
#     _zpos += dz[i]    # add the height of each bar to know where to start the next

# plt.gca().invert_xaxis()
# plt.show()





# fig = plt.figure()
# ax = fig.add_subplot(111, projection='3d')
# colors = ['r', 'g', 'b', 'y']
# for i, (c, z) in enumerate(zip(colors, [30, 20, 10, 0])):
#     xs = np.arange(20)
#     ys = np.random.rand(20)
#     ys2 = np.random.rand(20)
#     ys3 = np.random.rand(20)

#     # You can provide either a single color or an array. To demonstrate this,
#     # the first bar of each set will be colored cyan.
#     cs = [c] * len(xs)
#     cs[0] = 'c'
#     ax.bar(xs, ys, zs=z, zdir='y', color=cs, alpha=0.8)
#     ax.bar(xs, ys2, bottom=ys, zs=z, zdir='y', color=colors[(i+1)%4], alpha=0.8)
#     ax.bar(xs, ys3, bottom=ys+ys2, zs=z, zdir='y', color=colors[(i+2)%4], alpha=0.8)

# ax.set_xlabel('X')
# ax.set_ylabel('Y')
# ax.set_zlabel('Z')

# plt.show()


raw_input("Please press enter to exit.")

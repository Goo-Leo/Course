import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt


class Histogram(object):
    def __init__(self, sri):
        self.sr = cv.imread('../data/home.jpg')

    def histogramgenr(self):
        hist = np.bincount(self.sr.ravel(), minlength=256)  # 生成输入图像的直方图
        plt.plot(hist)

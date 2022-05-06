from numba import jit
import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt


@jit(nopython=False, parallel=True)
def equalize(img):
    output = np.copy(img)
    intput = np.copy(img)
    p_r = []
    p_s = []
    for i in range(256):
        p_r.append(np.sum(intput == i) / (img.shape[0] * img.shape[1]))
    # 输出图像的概率密度函数
    pr = 0
    for i in range(256):
        pr += p_r[i]
        p_s.append(pr)
    # 求解变换后的输出图像
    for i in range(256):
        output[np.where(intput == i)] = 255 * p_s[i]

    return output


def localequalhist(img):
    cv.namedWindow("clahe image", cv.WINDOW_NORMAL)
    clahe = cv.createCLAHE(clipLimit=5, tileGridSize=(7, 7))
    dst = clahe.apply(img)
    cv.imshow("clahe image", dst)


class Histogram(object):
    def __init__(self, sri):
        self.img = cv.imread(sri, 0)

    def histogramgenr(self):
        cv.namedWindow("img", cv.WINDOW_NORMAL)
        cv.imshow('img', self.img)
        hist = cv.calcHist([self.img], [0], None, [256], [0, 256])
        histo = np.zeros(256)
        array = np.array(self.img)
        array = array.reshape(-1)
        for i in range(array.shape[0]):
            histo[(array[i] - 1)] += 1

        plt.plot(histo)
        plt.plot(hist)
        plt.show()

    def equalizehisto(self):

        # equ = cv.equalizeHist(self.img)
        output = equalize(self.img)
        cv.imshow('img', output)
        ehist = cv.calcHist([output], [0], None, [256], [0, 256])
        # ehist1 = cv.calcHist([output], [0], None, [256], [0, 256])
        plt.plot(ehist)
        # plt.plot(equ)
        plt.show()
        localequalhist(self.img)

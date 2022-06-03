from numba import jit
import numpy as np
import cv2 as cv
from scipy import signal
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
        equ = cv.equalizeHist(self.img)
        ehist1 = cv.calcHist([equ], [0], None, [256], [0, 256])
        plt.plot(ehist1)

        output = equalize(self.img)
        cv.imshow('img', output)
        cv.imshow('img', equ)
        ehist = cv.calcHist([output], [0], None, [256], [0, 256])
        plt.plot(ehist)
        plt.show()

        localequalhist(self.img)


class Filter(object):

    def __int__(self, sr):
        self.img = cv.imread(sr)

    def samplize3(self, i, j):
        sample = np.zeros((3, 3))
        sample[0][0] = self.img[i - 1][j - 1]
        sample[0][1] = self.img[i - 1][j]
        sample[0][2] = self.img[i - 1][j + 1]
        sample[1][0] = self.img[i][j - 1]
        sample[1][1] = self.img[i][j]
        sample[1][2] = self.img[i][j + 1]
        sample[2][0] = self.img[i + 1][j - 1]
        sample[2][1] = self.img[i + 1][j]
        sample[2][2] = self.img[i + 1][j + 1]
        return sample

    def samplize5(self, i, j):
        sample = np.zeros((5, 5), np.uint8)
        sample[0] = self.img[i - 1][j - 1]
        sample[1] = self.img[i - 1][j]
        sample[2] = self.img[i - 1][j + 1]
        sample[3] = self.img[i][j - 1]
        sample[4] = self.img[i][j]
        sample[5] = self.img[i][j + 1]
        sample[6] = self.img[i + 1][j - 1]
        sample[7] = self.img[i + 1][j]
        sample[8] = self.img[i + 1][j + 1]
        return sample

    # @jit(nopython=False, parallel=True)
    def lp(self, mode):
        # 均值滤波
        jun = np.array([[1, 1, 1],
                        [1, 1, 1],
                        [1, 1, 1]])
        # 高斯滤波
        gao = np.array([[1, 2, 1],
                        [2, 4, 2],
                        [1, 2, 1]])
        # 拉普拉斯H3算子
        laplace = np.array([[0, -1, 0],
                            [-1, 5, -1],
                            [0, -1, 0]])
        # 拉普拉斯H4掩膜
        laplace2 = np.array([[-1, -1, -1],
                             [-1, 9, -1],
                             [-1, -1, -1]])
        # log 算子
        log = np.array([[0, 0, -1, 0, 0],
                        [0, -1, -2, -1, 0],
                        [-1, -2, 16, -2, -1],
                        [0, -1, -2, -1, 0],
                        [0, 0, -1, 0, 0]])

        # 新创建一个图像，给图像边缘填充0
        img2 = np.zeros((self.img.shape[0] + 4, self.img.shape[1] + 4), np.uint8)

        h, w = img2.shape

        # 将旧图像复制到新图像中
        for i in range(2, h - 2):
            for j in range(2, w - 2):
                img2[i][j] = self.img[i - 2][j - 2]

        # 创建处理图像
        img3 = np.zeros((h, w), np.uint8)

        # 卷积运算
        for i in range(0, h - 4):  # 5*5的矩阵从左到右运算3次，从上到下运算3次,运算次数
            for j in range(0, w - 4):
                # 计算结果图像的每个像素点
                summ = 0
                for row_i in range(5):  # 行
                    for col_j in range(5):  # 列
                        summ = log[row_i][col_j] * img2[i + row_i][j + col_j] + summ

                if summ > 255:
                    summ = 255

                img3[i + 1][j + 1] = summ
                img3[i + 1][j + 1] = abs(summ)

        return img3

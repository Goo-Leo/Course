import sys
import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt

runcase = int(sys.argv[1])
image_path = './test.jpg'

if runcase == 0:
    im = cv.imread(image_path)
    print(im.shape)
    mean, std = cv.meanStdDev(im)
    print("灰度平均值:", mean)
    print("协方差值", std)

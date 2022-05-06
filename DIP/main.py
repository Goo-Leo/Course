import sys
import cv2 as cv
from PIL import Image
import numpy as np
import spacetrans

runcase = int(sys.argv[1])
image_path = './test.jpg'

if runcase == 0:
    im = cv.cvtColor(cv.imread(image_path), cv.COLOR_RGB2GRAY)
    cv.imwrite("test.jpg", im)
    cv.namedWindow("test picture", cv.WINDOW_NORMAL)
    cv.imshow("test picture", im)
    print(im.shape)

    mean, std = cv.meanStdDev(im)
    print("方差:", std)
    print("标准差:", std)

    # 使用numpy计算图像1与图像2之间的协方差
    im = Image.open("test.jpg")

    cv.waitKey(0)

if runcase == 1:
    histo = spacetrans.Histogram(image_path)
    histo.histogramgenr()
    # histo.equalizehisto()
    cv.waitKey(0)

import sys
import os
import cv2 as cv
import numpy as np
from PIL import Image, ImageTk
import tkinter as tk
import tkinter.filedialog
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
    histo.equalizehisto()
    cv.waitKey(0)

if runcase == 2:
    window = tk.Tk()
    window.title('Processor')  # 窗口的标题
    window.geometry('500x400')  # 窗口的大小
    default_dir = r"文件路径"

    file_path = tk.filedialog.askopenfilename(title=u'选择图片',
                                              initialdir=(os.path.expanduser(default_dir))
                                              )
    imagepath = Image.open(file_path)  # 原生io函数对图像文件的支持并不完善，用PIL打开原始图像并显示
    imagepath = imagepath.resize((100, 100))
    orgimg = ImageTk.PhotoImage(imagepath)
    img = tk.Label(window,
                   image=orgimg,
                   )
    img.place(relx=0.1, rely=25 / 400)


    def aver():
        # 均值滤波
        jun = np.array([[1, 1, 1],
                        [1, 1, 1],
                        [1, 1, 1]])

        img1 = cv.imread(file_path)
        img2 = np.zeros((img1.shape[0] + 4, img1.shape[1] + 4), np.uint8)

        h, w = img2.shape

        # 将旧图像复制到新图像中
        for i in range(2, h - 2):
            for j in range(2, w - 2):
                img2[i, j] = img1[i - 2, j - 2]

        # 创建处理图像
        img3 = np.zeros((h, w), np.uint8)
        # 卷积运算
        for i in range(0, h - 4):  # 5*5的矩阵从左到右运算3次，从上到下运算3次,运算次数
             for j in range(0, w - 4):
                # 计算结果图像的每个像素点
                sum = 0
                for row_i in range(5):  # 行
                    for col_j in range(5):  # 列
                        sum = jun[row_i, col_j] * img2[i + row_i, j + col_j] + sum

                # 模板的系数
                # sum = sum// 16

                if sum > 255:
                    sum = 255

            img3[i + 1][j + 1] = sum
            img3[i + 1][j + 1] = abs(sum)
        show2 = tk.Label(window,
                         image=img3,
                         )
        show2.place(relx=0.5, rely=25 / 400)

    def guass():
        # 高斯滤波
        gao = np.array([[1, 2, 1],
                        [2, 4, 2],
                        [1, 2, 1]])

    def laplace3():
        laplace = np.array([[0, -1, 0],
                            [-1, 5, -1],
                            [0, -1, 0]])


    def laplace4():
        laplace2 = np.array([[-1, -1, -1],
                             [-1, 9, -1],
                             [-1, -1, -1]])

    but1 = tk.Button(window, text='低通 (box)', font='Helvetica -12 bold', width=12, height=2, command=aver)
    but1.place(relx=0.8, rely=25 / 400)
    but2 = tk.Button(window, text='低通 (guass)', font='Helvetica -12 bold', width=12, height=2, command=guass)
    but2.place(relx=0.77, rely=(25 + 93) / 400)
    but3 = tk.Button(window, text='拉普拉斯H3', font='Helvetica -12 bold', width=12, height=2, command=laplace3)
    but3.place(relx=0.77, rely=(25 + 93 * 2) / 400)
    but4 = tk.Button(window, text='拉普拉斯H4', font='Helvetica -12 bold', width=11, height=2, command=laplace4)
    but4.place(relx=0.77, rely=(25 + 93 * 3) / 400)

    window.mainloop()

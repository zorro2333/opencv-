//
// Created by 左政 on 2024/9/14.
//
#include <iostream>
#include "quickOpencv.h"
#include <opencv2/opencv.hpp>
#include "add.h"


using namespace std;

using namespace cv;



int main() {

    // 读取图像文件

    Mat src = imread("image/1.jpeg");

    namedWindow("输入窗口");
   // imshow("输入窗口",src);

    QuickOpencv qd;
    qd.operators_demo(src);
    waitKey(0);

    destroyAllWindows();
}
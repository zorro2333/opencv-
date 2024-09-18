//
// Created by 左政 on 2024/9/14.
//
#include "quickOpencv.h"
#include "iostream"
void QuickOpencv::colorSpace_Demo(Mat &img){
    Mat gray,hsv;
    // 假设 img 是你要转换的图像
    if (img.empty()) {
        std::cerr << "图像无效" << std::endl;
        // 处理图像无效的情况
    }

    try {
        cv::Mat convertedImg;
        cv::cvtColor(img, convertedImg, cv::COLOR_BGR2GRAY); // 假设你想要转换到灰度
        // 使用转换后的图像
    } catch (const cv::Exception& ex) {
        std::cerr << "cvtColor 异常：" << ex.what() << std::endl;
        // 处理异常情况
    }
    cvtColor(img,gray,COLOR_BGR2GRAY);
    cvtColor(img,hsv,COLOR_BGR2HSV);

   imshow("灰度",gray);
   imshow("hsv",hsv);

   imwrite("/Users/zorro/Desktop/opencv/image/hsv.jpg",hsv);
    imwrite("./image/gray.jpg",gray);

}


void QuickOpencv::mat_creation(Mat &image){
    Mat m1=Mat::zeros(Size(8,8),CV_8UC3);
    m1= Scalar(0,155,255);

    imshow("创建图像",m1);
    std::cout<<m1;


};



void QuickOpencv::pixel_visit(Mat &image){
    int w=image.cols;
    int h=image.rows;
    int dims= image.channels();
    for(int row=0;row<h;++row){
        for(int col=0;col<w;++col ){
            if(dims==1){
                int pv=image.at<uchar>(row,col);
                image.at<uchar>(row,col)=255-pv;
            }

            if(dims==3){
                Vec3b bgr=image.at<Vec3b >(row,col);
                image.at<Vec3b>(row,col)[0]=255-bgr[0];
                image.at<Vec3b>(row,col)[1]=255-bgr[1];
                image.at<Vec3b>(row,col)[2]=255-bgr[2];
            }
        }

    }

    resize(image, image, Size(256, 256), 0, 0, INTER_LINEAR);

    imwrite("image/熊猫.jpg",image);
    imshow("输出",image);


};



void QuickOpencv::operators_demo(Mat &image){
    Mat dst;
    dst=image+Scalar(50,50,50);

    //变暗两倍 无法进行乘法操作
   dst=image/Scalar(2,2,2);
    //实际乘法操作 变量两倍
    Mat m=Mat::zeros(dst.size(),dst.type());
    multiply(image,m,dst);
            imshow("结果",dst);
    add(image,m,dst)    ;//加
    divide(image,m,dst);//乘
    subtract(image,m,dst);//减



};

static void on_track(int,void*){

}

void QuickOpencv::tracking_bar_demo(Mat &image){
    namedWindow("亮度调整",WINDOW_AUTOSIZE);
    int max_value(100);
    int lightness=50;
    createTrackbar("ValueBar:","亮度调整",&lightness,max_value,on_track);
};


//
// Created by 左政 on 2024/9/14.
//

#ifndef IMAGE_QUICKOPENCV_H
#define IMAGE_QUICKOPENCV_H

#include "opencv2/opencv.hpp"


using namespace cv;
class QuickOpencv{
public:
    /**
     * @brief 切换为gray或者是hsv
     * @param[in] &image 目标图像
     * @return 无返回值
     */
    void colorSpace_Demo(Mat &image);

    /**
     * @brief 初始化mat
     */
    void mat_creation(Mat &image);

    /**
     * @brief 改变图像某一个像素点
     * @param image
     */
    void pixel_visit(Mat &image);

     /**
     * @brief 像素算数操作
     * @Note 翻转颜色
     * @param image
     */
    void operators_demo(Mat &image);


    void tracking_bar_demo(Mat &image);

};


#endif //IMAGE_QUICKOPENCV_H

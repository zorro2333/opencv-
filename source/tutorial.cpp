#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void GetFig(Mat &src, Mat &fig, Point start, Point text, int delta, int max_height){
    int cnt[256], mx = 0;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < src.size().height; ++i){
        for(int j = 0; j < src.size().width; ++j){
            int grayValue = src.at<uchar>(i, j);
            ++cnt[grayValue];
            (mx < cnt[grayValue]) && (mx = cnt[grayValue]);
        }
    }
    assert(mx > 0);
    double scale = max_height * 1.0 / mx;
    for(int i = 0; i < 256; ++i){
        rectangle(fig, Point(start.x + i * delta, start.y - cnt[i] * scale), Point(start.x + (i + 1) * delta, start.y),
                    Scalar(0, 69, 255), FILLED);
    }
    putText(fig, "Grayscale histogram", text, FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255), 2);
}


//int main(){
//    string path = "1.jpeg";
//    Mat src = imread(path, IMREAD_GRAYSCALE);
//    Mat fig(1080, 1920, CV_8UC3, Scalar(255, 255, 255));
//    GetFig(src, fig, Point(192, 850), Point(770, 940), 6, 800);
//    imwrite("output.jpg", fig); //save
//    namedWindow("Fig", WINDOW_NORMAL);
//    resizeWindow("Fig", 1920, 1080);
//    imshow("Fig", fig);
//
//    return 0;
//}

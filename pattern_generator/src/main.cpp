#include <iostream>
#include <opencv2/opencv.hpp>
#include <Cyclical.h>

int main(){

    int width = 1200;
    int height = 700;


    int t = 0;
    cv::namedWindow("Window", cv::WINDOW_AUTOSIZE); // sadece bir kez
    while(true){
        double radians = (t / 100.0) * 2 * M_PI; // 0–2π
        double y = (std::sin(radians) + 1) / 2 * 100 + 10; // -1..1 -> 10..1100
        std::cout << "\n y: " << y;

        cv::Mat img(height, width, CV_8UC3, cv::Scalar(255, 255, 255)); 
        cv::Scalar color(255,0,120);
        cv::Mat res = CyclicalPattern::disciplined(img,3,5,y,2,color);

        cv::imshow("Window", img);

        int key = cv::waitKey(15);
        if(key == 27) break; // ESC ile çıkış

        t += 1;
    }


    return 0;
}
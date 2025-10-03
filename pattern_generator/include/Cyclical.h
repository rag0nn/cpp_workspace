#pragma once

#include <opencv2/opencv.hpp>

class CyclicalPattern {
    public:
        static cv::Mat randomSpaceBetween(cv::Mat& img, int pointCount);
        static cv::Mat disciplined(cv::Mat& img, int rowCount, int columnCount, int lineInterval=30, int lineThickness=4, cv::Scalar color = cv::Scalar(0,0,255));
};

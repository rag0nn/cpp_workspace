
#include <opencv2/opencv.hpp>
#include <math.h>
#include <vector>
#include <Cyclical.h>
#include <random>

cv::Mat CyclicalPattern::randomSpaceBetween(cv::Mat& img, int pointCount){
    //
    int height = img.rows;
    int width = img.cols;
    
    std::random_device rd;  
    std::mt19937 gen(rd()); 

    //
    std::vector<cv::Rect2d> rectangles;
    std::vector<cv::Point2d> points;

    int t = pointCount / 3;   // tam kısım
    int r = pointCount % 3;   // kalan
    std::cout << "standart per row count: " << t;
    std::cout << "stardart last part count: "<< r;

    int partWidth = (width / t) + 1;
    int partHeight = (height / 4) + 1;
    std::cout << "Part Width: " << partWidth;
    std::cout << "Part Height: "<< partHeight;

    // create areas
    for (int i = 0; i < t; i++){
        for(int j = 0; j < 4; j++){
            rectangles.push_back(cv::Rect2d(
                i*partWidth, j*partHeight,  // x, y
                partWidth, partHeight        // width, height
            ));

        }
    }

    // create random points for each area
    for (cv::Rect2d rct: rectangles){
        std::uniform_int_distribution<> distX(rct.x, rct.x + rct.width);
        std::uniform_int_distribution<> distY(rct.y, rct.y + rct.height);
        int w_i = distX(gen);
        int h_i = distY(gen);
        points.push_back(cv::Point2d(w_i,h_i));
    }

    // find max radius for tangent
    std::vector<int> maxRadiues;
    for(size_t i=0; i<points.size(); i++){
        double minDist = std::numeric_limits<double>::max();
        for (size_t j = 0; j < points.size(); ++j) {
            if (i == j) continue;
            double dx = points[i].x - points[j].x;
            double dy = points[i].y - points[j].y;
            double dist = std::sqrt(dx*dx + dy*dy);

            if (dist < minDist) {
                minDist = dist-3;
            }
        maxRadiues.push_back(minDist);
        }
    }

    // paint points
    for(size_t i=0; i < points.size(); i++){
        cv::Scalar color(0, 0, 255); 
        
        for (int j = 0; j < maxRadiues[i];j+=10){
            cv::circle(img,points[i],j,color,4);
        }
        std::cout << "pt: " << points[i] << std::endl;
    }

    return img;
}

cv::Mat CyclicalPattern::disciplined(
    cv::Mat& img, 
    int rowCount, 
    int columnCount, 
    int lineInterval,
    int lineThickness,
    cv::Scalar color
    ){
    
    //checks
    if (rowCount%2 == 0){
        std::cout << "Row Count  must be odd number"<<std::endl;
        return img;
    }
    if (columnCount%2 == 0){
        std::cout << "Column Count  must be odd number"<<std::endl;
        return img;
    }

    // definitions
    int height = img.rows;
    int width = img.cols;

    int partWidth = width / (columnCount+1);
    int partHeight = height / (rowCount+1);

    std::vector<cv::Point2i> points; 

    // build points
    for(int i=0; i < columnCount; i++){
        for(int j=0; j < rowCount; j++){
            points.push_back(cv::Point2i(i*partWidth + partWidth,j*partHeight+ partHeight));
        }
    }

    // paint circles
    int maxRadius = std::min(width,height);
 
    for(int i = 0; i < points.size();i++){
        cv::Point2f p = points[i];
        for(int k = 0; k < maxRadius; k+=lineInterval){            
            cv::circle(img,p,k,color,lineThickness);
        }
        std::cout << "\n" << p.x << " " << p.y;
    }

    return img;
}
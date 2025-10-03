#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <opencv2/opencv.hpp>
#include "Cyclical.h"

namespace py = pybind11;

// numpy -> cv::Mat
cv::Mat numpy_to_mat(py::array_t<uint8_t> input) {
    py::buffer_info info = input.request();
    if (info.ndim != 3) throw std::runtime_error("Expected 3D array");
    int rows = info.shape[0];
    int cols = info.shape[1];
    int channels = info.shape[2];
    if(channels != 3) throw std::runtime_error("Expected 3 channels");

    return cv::Mat(rows, cols, CV_8UC3, (unsigned char*)info.ptr);
}

// cv::Mat -> numpy
py::array_t<uint8_t> mat_to_numpy(const cv::Mat &mat) {
    std::vector<ssize_t> shape = {mat.rows, mat.cols, 3};
    std::vector<ssize_t> strides = {mat.step[0], mat.step[1], 1};
    return py::array_t<uint8_t>(shape, strides, mat.data);
}

PYBIND11_MODULE(cyclicalGenerator, m) {
    m.doc() = "Cyclical core bindings";

    py::class_<CyclicalPattern>(m, "CyclicalPattern")
        .def_static("randomSpaceBetween", [](py::array_t<uint8_t> img, int pointCount){
            cv::Mat mat = numpy_to_mat(img);
            cv::Mat out = CyclicalPattern::randomSpaceBetween(mat, pointCount);
            return mat_to_numpy(out);
        })
        .def_static("disciplined", [](py::array_t<uint8_t> img, int rows, int cols, int lineInterval=30, int lineThickness=4){
            cv::Mat mat = numpy_to_mat(img);
            cv::Mat out = CyclicalPattern::disciplined(mat, rows, cols, lineInterval, lineThickness, cv::Scalar(0,0,255));
            return mat_to_numpy(out);
        });
}

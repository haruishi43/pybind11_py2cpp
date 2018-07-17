#include <iostream>

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <Eigen/Core>

#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>

Eigen::Matrix<uint8_t, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>
process_single_channel_image(Eigen::Matrix<uint8_t, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> src_img) {
    // convert to cv::Mat
    cv::Mat cv_src_img(src_img.rows(), src_img.cols(), CV_8UC1, src_img.data());
    
    cv::imshow("window_cpp_1", cv_src_img);
    cv::waitKey();

    cv::Mat cv_dst_img;
    cv::rotate(cv_src_img, cv_dst_img, cv::ROTATE_90_CLOCKWISE);

    cv::imshow("window_cpp_1", cv_dst_img);
    cv::waitKey();

    // convert to Eigen::Matrix
    using c1_stride = Eigen::Stride<Eigen::Dynamic, 1>;
    using Eigen::Dynamic;
    using Eigen::RowMajor;
    using Eigen::Unaligned;
    c1_stride stride(cv_dst_img.cols, 1);
    auto dst_img = Eigen::Map<Eigen::Matrix<uint8_t, Dynamic, Dynamic, RowMajor>, Unaligned, c1_stride>(reinterpret_cast<uint8_t*>(cv_dst_img.data), cv_dst_img.rows, cv_dst_img.cols, stride);

    return dst_img;
}

PYBIND11_MODULE(process_in_cpp, m) {
    m.def("process_single_channel_image", &process_single_channel_image);
}

//
// Created by jeremie on 10/2/15.
//

#ifndef CAMERA_FEED_WEBCAM_H
#define CAMERA_FEED_WEBCAM_H

#include <memory>
#include <thread>
#include "opencv2/opencv.hpp"


class Webcam : private cv::VideoCapture
{
public:
    Webcam();
    ~Webcam();

    void Start();
    void Stop();
    cv::Mat GetImage();
private:

    void Streaming();

    bool exit_thread_;
    std::shared_ptr<std::thread> thread_;
    cv::Mat image_;
};


#endif //CAMERA_FEED_WEBCAM_H

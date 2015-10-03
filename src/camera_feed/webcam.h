//
// Created by Thibaut Mattio on 2015-10-03.
//

#ifndef REACHARM_CAMERA_FEED_WEBCAM_H_
#define REACHARM_CAMERA_FEED_WEBCAM_H_

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

#endif //REACHARM_CAMERA_FEED_WEBCAM_H_

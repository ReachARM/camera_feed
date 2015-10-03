//
// Created by jeremie on 10/2/15.
//

#include <thread>
#include "ros/ros.h"
#include "camera_feed/webcam.h"

//-----------------------------------------------------------------------------
//
Webcam::Webcam()
    : cv::VideoCapture(),
      exit_thread_(false),
      thread_(nullptr),
      img_transport_(ros::NodeHandle()){
  publisher_ = img_transport_.advertise("webcam_feed", 1);
}

//-----------------------------------------------------------------------------
//
Webcam::~Webcam() {
  if (isOpened())
    Stop();
}

//-----------------------------------------------------------------------------
//
void
Webcam::Start() {
  // Open first streaming device
  open(0);
  if (isOpened()) {
    std::cout << "Webcam OK" << std::endl;
  }
  exit_thread_ = false;
  thread_ = std::make_shared<std::thread>(&Webcam::Streaming, this);
}

//-----------------------------------------------------------------------------
//
void
Webcam::Stop() {
  if (isOpened()) {
    exit_thread_ = true;
    thread_->join();
  }
  release();
}

//-----------------------------------------------------------------------------
//
void
Webcam::Streaming() {
  cv::namedWindow("Webcam feed");

  while (!exit_thread_) {
    operator>>(image_);
    sensor_msgs::ImagePtr msg =
            cv_bridge::CvImage(std_msgs::Header(), "bgr8", image_).toImageMsg();
    publisher_.publish(msg);

  }
}

//-----------------------------------------------------------------------------
//
cv::Mat
Webcam::GetImage() {
  return image_;
}
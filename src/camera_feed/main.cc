/**
 * \file main.cpp
 */

#include <memory>
#include <ros/ros.h>
#include "camera_feed/webcam.h"

bool abort_streaming;

//------------------------------------------------------------------------------
//
void ctrl_c_handler(int s)
{
  abort_streaming = true;
}

//------------------------------------------------------------------------------
//
int main(int argc, char **argv) {
  ros::init(argc, argv, "camera_feed");

  std::shared_ptr<ros::NodeHandle> n =
      std::make_shared<ros::NodeHandle>();
  ros::Rate loop_rate(15);

  abort_streaming = false;

  Webcam webcam;

  webcam.Start();

  while (!abort_streaming);
  webcam.Stop();


  while (ros::ok()) {
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}

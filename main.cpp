#include <iostream>
#include <signal.h>
#include "Webcam.h"

bool abort_streaming;
void ctrl_c_handler(int s)
{
    abort_streaming = true;
}

int main(int argc,char** argv) {

    signal (SIGINT, ctrl_c_handler);


    abort_streaming = false;

    Webcam webcam;

    webcam.Start();

    while( !abort_streaming )
    {
        cv::Mat tmp = webcam.GetImage();
        if( !tmp.empty())
        {
            cv::imshow("Webcam feed", webcam.GetImage());
            cv::waitKey(1);
        }
    }
    webcam.Stop();
    return 0;
}
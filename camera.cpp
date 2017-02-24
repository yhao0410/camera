#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

   int countCameras(){
   cv::VideoCapture temp_camera;
   int maxTested = 10;
   for (int i = 0; i < maxTested; i++){
     cv::VideoCapture temp_camera(i);
     bool res = (!temp_camera.isOpened());
     temp_camera.release();
     if (res)
     {
       std::cout<<"index of camera"<<i<<std::endl;
     }
   }
   return maxTested;
}

int main(int, char**)
{
    VideoCapture cap(1); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat edges;
    namedWindow("frame",1);

    std::cout<<"number of camera ="<<countCameras<<std::endl;


    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
	printf("size = %d %d \n",frame.cols,frame.rows);
        imshow("frame", frame);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}

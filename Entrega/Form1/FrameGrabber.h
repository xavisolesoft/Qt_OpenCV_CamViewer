#pragma once

#include "opencv2/opencv.hpp"

class FrameGrabber
{
public:
	FrameGrabber();

	cv::Mat queryNewFrame();

private:
	cv::VideoCapture videoCapture;
};

#pragma once

#include "opencv2/opencv.hpp"

class FrameGrabber
{
public:
	FrameGrabber();
	~FrameGrabber();

	cv::Mat queryNewFrame();

private:
	cv::VideoCapture videoCapture;
};

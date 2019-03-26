#include "FrameGrabber.h"

FrameGrabber::FrameGrabber() :
	videoCapture(0)
{
	if(!videoCapture.isOpened()){
		throw std::exception("Cannot open VideoCapture.");
	}
}

cv::Mat FrameGrabber::queryNewFrame()
{
	cv::Mat frame;
	videoCapture >> frame;
	cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
	//imshow("MyVideo", frame);
	return frame;
}

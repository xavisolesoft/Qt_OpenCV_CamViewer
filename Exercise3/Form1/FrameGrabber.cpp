#include "FrameGrabber.h"

FrameGrabber::FrameGrabber() :
	videoCapture(0)
{

}

cv::Mat FrameGrabber::queryNewFrame()
{
	cv::Mat frame;
	if(videoCapture.isOpened()){
		videoCapture >> frame;
		cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
	}
	return frame;
}

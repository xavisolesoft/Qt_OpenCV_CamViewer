#include "VideoControllerExercise3.h"

#include <QImage>
#include <QPixmap>

VideoControllerExercise3::VideoControllerExercise3()
{

}

void VideoControllerExercise3::init()
{
	connect(&camTimer,
			&QTimer::timeout,
			[this](){
				cv::Mat frame = frameGrabber->queryNewFrame();
				QImage image(frame.data, frame.cols, frame.rows, (int)frame.step, QImage::Format_RGB888);
				emit showNewFrame(QPixmap::fromImage(image));
			});

	camTimer.setInterval(40);
}

void VideoControllerExercise3::startVideo()
{
	frameGrabber = std::make_unique<FrameGrabber>();
	camTimer.start(40);
}

void VideoControllerExercise3::stopVideo()
{
	camTimer.stop();
	frameGrabber.reset(nullptr);
}

void VideoControllerExercise3::setBwEnabled(bool)
{
	//Do nothing
}

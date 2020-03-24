#include "VideoControllerExercise4.h"
#include "StrategyModifyWB.h"
#include "StrategyModifyInverted.h"

#include <QImage>
#include <QPixmap>
#include <QtConcurrent>
#include <QTime>

VideoControllerExercise4::VideoControllerExercise4()
{

}

void VideoControllerExercise4::init()
{
	connect(&camTimer,
			&QTimer::timeout,
			[this](){
				bool emptyQueue = false;
				do{
					QPixmap image;
					mutex.lock();
					if(!videoQueue.isEmpty()){
						image = videoQueue.dequeue();
					}else{
						emptyQueue = true;
					}
					mutex.unlock();
					if(!emptyQueue){
						emit showNewFrame(image);
					}
				}while(!emptyQueue);
			});

	camTimer.setInterval(20);
}

void VideoControllerExercise4::startVideo()
{
	frameGrabber = std::make_unique<FrameGrabber>();
	camTimer.start(40);

	videoFinished = false;
	QtConcurrent::run([this](){
		QTime prevTime = QTime::currentTime();
		while(!videoFinished && frameGrabber){
			QTime currentTime = QTime::currentTime();
			if(prevTime.msecsTo(currentTime) >= 40){
				cv::Mat frame = frameGrabber->queryNewFrame();

				StrategyModify* modifier;
				if(bwEnabled){
					modifier = new StrategyModifyWB();
				}else{
					modifier = new StrategyModify();
				}
				modifier->modify(frame);

				QImage image(frame.data, frame.cols, frame.rows, (int)frame.step, QImage::Format_RGB888);
				mutex.lock();
				videoQueue.enqueue(QPixmap::fromImage(image));
				mutex.unlock();
			}
		}
	});
}

void VideoControllerExercise4::stopVideo()
{
	camTimer.stop();
	frameGrabber.reset(nullptr);
	videoFinished = true;
}

void VideoControllerExercise4::setBwEnabled(bool value)
{
	bwEnabled = value;
}

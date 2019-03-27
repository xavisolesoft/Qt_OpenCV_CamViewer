#pragma once

#include "FrameGrabber.h"

#include <QTimer>
#include <QObject>

#include <memory>

class VideoControllerExercise3 :
		public QObject
{
	Q_OBJECT

public:
	VideoControllerExercise3();

	void init();
	void startVideo();
	void stopVideo();

	void setBwEnabled(bool value);

signals:
	void showNewFrame(const QPixmap& pixmap);

private:
	QTimer camTimer;
	std::unique_ptr<FrameGrabber> frameGrabber;
};

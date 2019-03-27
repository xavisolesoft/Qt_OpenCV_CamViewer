#pragma once

#include "FrameGrabber.h"

#include <QTimer>
#include <QObject>
#include <QMutex>
#include <QQueue>

#include <memory>

class VideoControllerExercise4 :
		public QObject
{
	Q_OBJECT

public:
	VideoControllerExercise4();

	void init();
	void startVideo();
	void stopVideo();

	void setBwEnabled(bool value);

signals:
	void showNewFrame(const QPixmap& pixmap);

private:
	QTimer camTimer;
	std::unique_ptr<FrameGrabber> frameGrabber;
	QQueue<QPixmap> videoQueue;
	QMutex mutex;
	bool videoFinished;
	bool bwEnabled;
};

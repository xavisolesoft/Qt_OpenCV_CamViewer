#pragma once

#include "FrameGrabber.h"

#include <QMainWindow>
#include <QTimer>
#include <QQueue>
#include <QPixmap>
#include <QMutex>

namespace Ui {
class Form1;
}

class Form1 : public QMainWindow
{
	Q_OBJECT

public:
	explicit Form1(QWidget *parent = 0);
	~Form1();

private:
	void initAcquireButton();
	void initStopButton();
	void initBwCheckbox();
	void initCloseButton();

	void initVideoV1();
	void initVideoV2();
	void startVideo();
	void stopVideo();

	FrameGrabber frameGrabber;
	QTimer camTimer;
	QQueue<QPixmap> videoQueue;
	QMutex mutex;
	Ui::Form1* ui;
};


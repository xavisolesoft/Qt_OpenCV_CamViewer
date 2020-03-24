#pragma once

#include "VideoController.h"

#include <QMainWindow>

namespace Ui {
class Form1;
}

class Form1 : public QMainWindow
{
	Q_OBJECT

public:
	explicit Form1(QWidget *parent = 0);
	~Form1();

private slots:
	void showNewFrame(const QPixmap& pixmap);

private:
	void initAcquireButton();
	void initStopButton();
	void initBwCheckbox();
	void initCloseButton();
	void initVideoController();

	//VideoControllerExercise3 videoController;
	VideoControllerExercise4 videoController;
	Ui::Form1* ui;
};


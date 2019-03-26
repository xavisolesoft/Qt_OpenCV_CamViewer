#pragma once

#include <QMainWindow>

class FrameGLWidget;

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
	Ui::Form1* ui;
	FrameGLWidget* glWidget = nullptr;
};


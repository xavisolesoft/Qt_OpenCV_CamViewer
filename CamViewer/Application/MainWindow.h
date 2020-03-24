#pragma once

#include "VideoController.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void showNewFrame(const QPixmap& pixmap);

private:
	void initAcquireButton();
	void initStopButton();
	void initBwCheckbox();
	void initCloseButton();
	void initVideoController();

	VideoControllerExercise4 videoController;
	Ui::MainWindow* ui;
};


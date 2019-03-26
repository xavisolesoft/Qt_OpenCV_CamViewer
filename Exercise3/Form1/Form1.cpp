#include "Form1.h"
#include "ui_Form1.h"

#include <QImage>
#include <QTime>
#include <QTimer>
#include <QVBoxLayout>
#include <QtConcurrent>

Form1::Form1(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Form1)
{
	ui->setupUi(this);

	initAcquireButton();
	initStopButton();
	initBwCheckbox();
	initCloseButton();
	initVideoV2();
}

Form1::~Form1()
{
	delete ui;
}

void Form1::initAcquireButton()
{
	connect(ui->acquireButton,
			&QAbstractButton::clicked,
			[this](){
				ui->acquireButton->setEnabled(false);
				ui->stopButton->setEnabled(true);
				ui->bwCheckBox->setEnabled(true);
				ui->textEdit->setText(tr("The Acquiring..."));
				startVideo();
	});
}

void Form1::initStopButton()
{
	ui->stopButton->setEnabled(false);

	connect(ui->stopButton,
			&QAbstractButton::clicked,
			[this](){
				ui->acquireButton->setEnabled(true);
				ui->stopButton->setEnabled(false);
				ui->bwCheckBox->setEnabled(false);
				ui->textEdit->setText("");
				stopVideo();
	});
}

void Form1::initBwCheckbox()
{
	ui->bwCheckBox->setChecked(true);
	ui->bwCheckBox->setEnabled(false);
}

void Form1::initCloseButton()
{
	connect(ui->closeButton,
			&QAbstractButton::clicked,
			[this](){
				close();
	});
}

void Form1::initVideoV1()
{
	connect(&camTimer,
			&QTimer::timeout,
			[this](){
				cv::Mat frame = frameGrabber.queryNewFrame();
				QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
				ui->imageLabel->setPixmap(QPixmap::fromImage(image));
			});

	camTimer.setInterval(40);
}

void Form1::initVideoV2()
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
					if(!image.isNull()){
						ui->imageLabel->setPixmap(image);
					}
				}while(!emptyQueue);
			});

	QtConcurrent::run([this](){
		QTime prevTime = QTime::currentTime();
		forever{
			QTime currentTime = QTime::currentTime();
			if(prevTime.msecsTo(currentTime) >= 40){
				cv::Mat frame = frameGrabber.queryNewFrame();
				QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
				//ui->imageLabel->setPixmap(QPixmap::fromImage(image));
				mutex.lock();
				videoQueue.enqueue(QPixmap::fromImage(image));
				mutex.unlock();
			}
		}
	});

	camTimer.setInterval(20);
}

void Form1::startVideo()
{
	camTimer.start(40);
}

void Form1::stopVideo()
{
	camTimer.stop();
}

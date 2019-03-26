#include "Form1.h"
#include "ui_Form1.h"

#include "FrameGrabber.h"
#include "FrameGLWidget.h"

#include <QImage>
#include <QVBoxLayout>

#include <QDialog>
#include <QLabel>

Form1::Form1(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Form1)
{
	ui->setupUi(this);

	initAcquireButton();
	initStopButton();
	initBwCheckbox();
	initCloseButton();

	glWidget = new FrameGLWidget(ui->imageWidget);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(glWidget);
	ui->imageWidget->setLayout(layout);

	FrameGrabber frameGrabber;
	cv::Mat frame = frameGrabber.queryNewFrame();
	QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
	auto dialog = new QDialog(this);
	auto dialogLayout = new QVBoxLayout();
	auto label = new QLabel(dialog);
	label->setPixmap(QPixmap::fromImage(image));
	dialogLayout->addWidget(label);
	dialog->setLayout(dialogLayout);

	dialog->show();
	glWidget->setNewFrame(image);
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

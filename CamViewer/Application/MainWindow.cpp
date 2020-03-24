#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QImage>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	initAcquireButton();
	initStopButton();
	initBwCheckbox();
	initCloseButton();
	initVideoController();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::showNewFrame(const QPixmap& pixmap)
{
	ui->imageLabel->setPixmap(pixmap);
}

void MainWindow::initAcquireButton()
{
	connect(ui->acquireButton,
			&QAbstractButton::clicked,
			[this](){
				ui->acquireButton->setEnabled(false);
				ui->stopButton->setEnabled(true);
				ui->bwCheckBox->setEnabled(true);
				ui->textEdit->setText(tr("The Acquiring..."));
				videoController.startVideo();
	});
}

void MainWindow::initStopButton()
{
	ui->stopButton->setEnabled(false);

	connect(ui->stopButton,
			&QAbstractButton::clicked,
			[this](){
				ui->acquireButton->setEnabled(true);
				ui->stopButton->setEnabled(false);
				ui->bwCheckBox->setEnabled(false);
				ui->textEdit->setText("");
				videoController.stopVideo();
				showNewFrame(QPixmap());
	});
}

void MainWindow::initBwCheckbox()
{
	ui->bwCheckBox->setChecked(true);
	ui->bwCheckBox->setEnabled(false);
}

void MainWindow::initCloseButton()
{
	connect(ui->closeButton,
			&QAbstractButton::clicked,
			[this](){
				close();
	});
}

void MainWindow::initVideoController()
{
	videoController.init();
	videoController.setBwEnabled(ui->bwCheckBox->isChecked());
	connect(&videoController,
			SIGNAL(showNewFrame(const QPixmap&)),
			SLOT(showNewFrame(const QPixmap&)));

	connect(ui->bwCheckBox,
			&QCheckBox::toggled,
			[this](bool checked){
				videoController.setBwEnabled(checked);
			});
}

#include "Form1.h"
#include "ui_Form1.h"

Form1::Form1(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Form1)
{
	ui->setupUi(this);

	initAcquireButton();
	initStopButton();
	initBwCheckbox();
	initCloseButton();
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

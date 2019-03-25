#include "Form1.h"
#include "ui_Form1.h"

Form1::Form1(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Form1)
{
	ui->setupUi(this);
}

Form1::~Form1()
{
	delete ui;
}

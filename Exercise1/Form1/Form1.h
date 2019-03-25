#pragma once

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

private:
	Ui::Form1 *ui;
};


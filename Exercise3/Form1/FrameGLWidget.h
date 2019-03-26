#pragma once

#include <QOpenGLWidget>

class FrameGLWidget :
		public QOpenGLWidget
{
public:
	FrameGLWidget(QWidget* parent = nullptr);

	void setNewFrame(const QImage& image);

private:
	void paintEvent(QPaintEvent* event) override;

	QImage frame;
};

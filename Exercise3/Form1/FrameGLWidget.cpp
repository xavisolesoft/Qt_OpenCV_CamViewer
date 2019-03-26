#include "FrameGLWidget.h"

#include <QPainter>

FrameGLWidget::FrameGLWidget(QWidget* parent) :
	QOpenGLWidget(parent)
{

}

void FrameGLWidget::setNewFrame(const QImage& image)
{
	image.save("C:/Users/xavis/Downloads/rrr.png");
	frame.load("C:/Users/xavis/Downloads/rrr.png");
}

void FrameGLWidget::paintEvent(QPaintEvent*)
{
	QPainter painter;
	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.drawImage(0, 0, frame);
	painter.end();
}

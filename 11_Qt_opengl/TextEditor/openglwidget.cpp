#include "openglwidget.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>


openglwidget::openglwidget(QWidget * parent)
	: QOpenGLWidget(parent)
{
	setMinimumWidth(parent->geometry().width() / 2);
	setMinimumHeight(parent->geometry().height());

	setFocusPolicy(Qt::FocusPolicy::ClickFocus);
}

openglwidget::~openglwidget()
{
}

void openglwidget::initializeGL()
{
	if (glewInit())
		QMessageBox::warning(this, "Error", "You have no opengl Driver !", QMessageBox::Ok);

}

void openglwidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glClearColor(0.4f, 0.5f, 0.9f, 1.0f);
	glClearColor(1.0f, 0.5f, 0.3f, 1.0f);
}

void openglwidget::resizeGL(int width, int height)
{
	setMinimumWidth(this->parentWidget()->geometry().width() / 2);
	setMinimumWidth(this->parentWidget()->geometry().height());
}

void openglwidget::mousePressEvent(QMouseEvent * event)
{
	int dx = event->x();
	int dy = event->y();

	if (event->buttons() & Qt::LeftButton)
	{
		
		printf("%d , %d \n", event->pos().x(), event->pos().y());
	}
}

void openglwidget::mouseReleaseEvent(QMouseEvent * event)
{
	int dx = event->x();
	int dy = event->y();

	if (event->buttons() & Qt::LeftButton)
	{
		event->pos();
	}
}

void openglwidget::mouseMoveEvent(QMouseEvent * event)
{
	int dx = event->x();
	int dy = event->y();

	event->pos();

}

void openglwidget::wheelEvent(QWheelEvent * event)
{
	QPoint numDegrees = event->angleDelta();
	printf("%d , %d \n",numDegrees.x(), numDegrees.y());
}

void openglwidget::keyPressEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key_Escape)
	{
		printf(" pressed \n");
	}
}

void openglwidget::keyReleaseEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key_Escape)
	{
		printf(" released \n");
	}
}

#include <QApplication>
#include <QWidget>

int main(int argc, char* argv[])
{
	QApplication app(argc,argv);

	QWidget* widget = new QWidget();
	widget->setWindowTitle("Hello Qt visual C++");
	widget->setGeometry(0,0,2000,1080);
	widget->show();

	return app.exec();
}


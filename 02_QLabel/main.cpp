#include <QApplication>
#include <QWidget>
#include <QLabel>

int main(int argc, char* argv[])
{
	QApplication app(argc,argv);

	QWidget* widget = new QWidget();
	widget->setWindowTitle("Hello Qt visual C++");
	widget->setGeometry(100,100,500,500);

	QLabel* name_label = new QLabel("Name",widget);
	name_label->move(100,100);


	//QFont font("Arial", 50, QFont::Bold);
	//name_label->setFont(font);

	name_label->setStyleSheet("color : red; font : bold 50px;");


	//auto text =  name_label->text();
	name_label->setText(u8"اسم");


	widget->show();

	return app.exec();
}


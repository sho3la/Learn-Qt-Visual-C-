#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>


class Window : public QWidget
{

public:
	Window(QWidget* parent = nullptr) : QWidget(parent)
	{
		setFixedSize(500,250);

		name_edit = new QLineEdit(this);
		name_edit->move(100,100);
		name_edit->setStyleSheet("background : red; font : bold 15px; color : white;");

		name = new QLabel("Name", this);
		name->move(50,100);
	}

private:
	QLabel* name;
	QLineEdit* name_edit;
};

int main(int argc, char* argv[])
{
	QApplication app(argc,argv);
	Window window;

	window.show();

	return app.exec();
}


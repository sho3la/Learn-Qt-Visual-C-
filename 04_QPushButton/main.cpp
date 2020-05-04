#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>


class Window : public QWidget
{

public:
	Window(QWidget* parent = nullptr) : QWidget(parent)
	{
		setFixedSize(500,250);

		name_edit = new QLineEdit(this);
		name_edit->move(100,100);
		name_edit->setStyleSheet("background : red; font : bold 15px; color : white;");

		connect(name_edit, &QLineEdit::returnPressed, this, &Window::EnterPressed);

		name = new QLabel("Name", this);
		name->move(50,100);


		button = new QPushButton("Hellooo button", this);
		button->move(50,50);

		connect(button, &QPushButton::clicked, this, &Window::buttonpressed);
	}


	void EnterPressed()
	{
		QMessageBox msg;
		msg.setText(name_edit->text());
		msg.exec();
		
	}

	void buttonpressed()
	{
		printf("hellooo ");
	}

private:
	QLabel* name;
	QLineEdit* name_edit;
	QPushButton *button;
};

int main(int argc, char* argv[])
{
	QApplication app(argc,argv);
	Window window;

	window.show();

	return app.exec();
}


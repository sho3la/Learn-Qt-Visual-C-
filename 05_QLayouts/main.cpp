#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>



class Window : public QWidget
{

public:
	Window(QWidget* parent = nullptr) : QWidget(parent)
	{
		setWindowTitle("Login");
		setFixedSize(300,200);

		mainlayout = new QVBoxLayout();
		setLayout(mainlayout);

		row1layout = new QHBoxLayout();
		row1layout->setSpacing(50);
		username_label = new QLabel("username : ");
		username_box  = new QLineEdit();
		row1layout->addWidget(username_label);
		row1layout->addWidget(username_box);

		mainlayout->addLayout(row1layout);


		row2layout = new QHBoxLayout();
		row2layout->setSpacing(50);
		password_label = new QLabel("password : ");
		password_box  = new QLineEdit();
		password_box->setEchoMode(QLineEdit::EchoMode::Password);
		row2layout->addWidget(password_label);
		row2layout->addWidget(password_box);

		mainlayout->addLayout(row2layout);


		row3layout = new QHBoxLayout();
		row3layout->addStretch();

		login = new QPushButton("Login");
		cancel = new QPushButton("Cancel");
		row3layout->addWidget(login);
		row3layout->addWidget(cancel);

		mainlayout->addLayout(row3layout);

		// connections
		connect(login, &QPushButton::clicked, this, &Window::Login_pressed);
		connect(cancel, &QPushButton::clicked, this, &Window::Cancel_pressed);

	}

	void Login_pressed()
	{
		printf("Logged in %s \n", username_box->text().toStdString().c_str());
		printf("Password  %s \n", password_box->text().toStdString().c_str());
	}

	void Cancel_pressed()
	{
		printf("canceled \n");
	}




private:
	QVBoxLayout* mainlayout;
	QHBoxLayout* row1layout;
	QHBoxLayout* row2layout;
	QHBoxLayout* row3layout;


	QLabel* username_label;
	QLabel* password_label;

	QLineEdit* username_box;
	QLineEdit* password_box;

	QPushButton* login;
	QPushButton* cancel;
};

int main(int argc, char* argv[])
{
	QApplication app(argc,argv);

	Window window;
	window.show();

	return app.exec();
}


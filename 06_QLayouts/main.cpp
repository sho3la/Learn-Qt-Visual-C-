#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QTextEdit>

class Window : public QWidget
{

public:
	Window(QWidget* parent = nullptr) : QWidget(parent)
	{
		setWindowTitle("grid layout");
		setGeometry(250,250,500,500);
		
		mainlayout = new QVBoxLayout();
		setLayout(mainlayout);
		
		gridgroup = new QGroupBox();
		gridgroup->setTitle("GridLayout");

		gridlayout = new QGridLayout();
		gridgroup->setLayout(gridlayout);

		mainlayout->addWidget(gridgroup);

		for(int i = 0 ; i < 3; ++i)
		{
			gridlabels[i] = new QLabel(tr("Line %1:").arg(i+1));
			gridlineedits[i] = new QLineEdit();

			gridlayout->addWidget(gridlabels[i], i, 0);
			gridlayout->addWidget(gridlineedits[i], i, 1);
		}

		gridtextedit = new QTextEdit();
		gridlayout->addWidget(gridtextedit, 0, 2 , 3 , 1);

		////////////////
		group2 = new QGroupBox();
		mainlayout->addWidget(group2);
	}



private:
	QVBoxLayout* mainlayout;
	QGridLayout* gridlayout;

	// groub box
	QGroupBox* gridgroup;
	QGroupBox* group2;

	// labels
	QLabel* gridlabels[3];

	// line edits
	QLineEdit* gridlineedits[3];

	// rich text box
	QTextEdit* gridtextedit;

};

int main(int argc, char* argv[])
{
	QApplication app(argc,argv);

	Window window;
	window.show();

	return app.exec();
}


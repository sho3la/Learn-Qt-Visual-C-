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
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>

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
		formgroup = new QGroupBox();
		formgroup->setTitle("form layout");

		formlayout = new QFormLayout();
		formgroup->setLayout(formlayout);
		mainlayout->addWidget(formgroup);

		for(int i = 0 ; i < 3; ++i)
			formlabels[i] = new QLabel(tr("Line %1:").arg(i+1));

		formlineedits = new QLineEdit();

		combobox = new QComboBox();
		combobox->addItem("item 1");
		combobox->addItem("item 2");
		combobox->addItem("item 3");


		spinbox = new QSpinBox();

		formlayout->addRow(formlabels[0], formlineedits);
		formlayout->addRow(formlabels[1], combobox);
		formlayout->addRow(formlabels[2], spinbox);

		// for overloaded functions connections
		connect(combobox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Window::onindexchanged);

		connect(spinbox, QOverload<int>::of(&QSpinBox::valueChanged), this, &Window::onspinchange);

	}


	void onindexchanged(int index)
	{
		auto txt = combobox->itemText(index);
		printf("%s \n", txt.toStdString().c_str());
	}

	void onspinchange(int val)
	{
		//spinbox->value();
		printf("%d \n", val);
	}


private:
	QVBoxLayout* mainlayout;
	QGridLayout* gridlayout;
	QFormLayout* formlayout;

	// groub box
	QGroupBox* gridgroup;
	QGroupBox* formgroup;

	// labels
	QLabel* gridlabels[3];
	QLabel* formlabels[3];

	// line edits
	QLineEdit* gridlineedits[3];
	QLineEdit* formlineedits;

	// combo box
	QComboBox* combobox;

	// spin box
	QSpinBox* spinbox;


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


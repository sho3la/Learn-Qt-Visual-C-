#include "Mainwindow.h"
#include <QShortcut>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QGuiApplication>
#include <QSaveFile>

Window::Window(QWidget * parent)
	: QMainWindow(parent) , font_size(100)
{
	setWindowTitle("TextEditor");
	setGeometry(250, 250, 800, 600);


	textarea = new QPlainTextEdit();
	setCentralWidget(textarea);

	init_menubar();

	init_statusbar();

	init_toolbar();


	connect(NewAction, &QAction::triggered, this, &Window::New);
	connect(OpenAction, &QAction::triggered, this, &Window::Open);
	connect(SaveAction, &QAction::triggered, this, &Window::Save);
	connect(SaveAsAction, &QAction::triggered, this, &Window::SaveAs);
}

Window::~Window()
{

}

void Window::init_menubar()
{
	filemenu = menuBar()->addMenu("File");
	{
		NewAction = new QAction(QIcon(":/icons/new.png"), "New");
		NewAction->setShortcut(QKeySequence::New);
		NewAction->setStatusTip("Create new File");
		filemenu->addAction(NewAction);

		OpenAction = new QAction(QIcon(":/icons/open.png"), "Open");
		OpenAction->setShortcut(QKeySequence::Open);
		OpenAction->setStatusTip("open exist File");
		filemenu->addAction(OpenAction);


		SaveAction = new QAction(QIcon(":/icons/save.png"), "Save");
		SaveAction->setShortcut(QKeySequence::Save);
		SaveAction->setStatusTip("save File");
		filemenu->addAction(SaveAction);

		SaveAsAction = new QAction(QIcon(":/icons/save_as.png"), "Save As");
		//SaveAsAction->setShortcut(QKeySequence::SaveAs); not working
		SaveAsAction->setShortcut(tr("Ctrl+Shift+S"));
		SaveAsAction->setStatusTip("save file as new format");
		filemenu->addAction(SaveAsAction);

		filemenu->addSeparator();
		ExitAction = new QAction(QIcon(":/icons/exit.png"), "Exit");
		ExitAction->setShortcut(tr("Ctrl+Q"));
		ExitAction->setStatusTip("exit program");
		filemenu->addAction(ExitAction);
	}

	helpmenu = menuBar()->addMenu("Help");
	{
		AboutAction = new QAction(QIcon(":/icons/about.png"), "help");
		AboutAction->setStatusTip("about us");
		helpmenu->addAction(AboutAction);
	}
}

void Window::init_toolbar()
{
	toolbar = new QToolBar();
	toolbar->addAction(NewAction);
	toolbar->addAction(OpenAction);
	toolbar->addAction(SaveAction);
	toolbar->addAction(SaveAsAction);

	addToolBar(toolbar);

}

void Window::init_statusbar()
{
	statusBar()->addPermanentWidget(new QLabel(""));
	statusBar()->addPermanentWidget(new QLabel(tr("%1 %").arg(font_size)));
}


/////////////////////////////////////////////////// helpers
bool Window::maybesave()
{
	return true;
}

///////////////////////////////////////////////////// Functions

void Window::New()
{
}

void Window::Open()
{
}

void Window::Save()
{

}

void Window::SaveAs()
{
}

void Window::Loadfile(QString& filename)
{
}

void Window::Exit()
{
}

#include "Mainwindow.h"
#include <QShortcut>

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
}

Window::~Window()
{

}

void Window::init_menubar()
{
	filemenu = menuBar()->addMenu("File");
	editmenu = menuBar()->addMenu("Edit");
	formatmenu = menuBar()->addMenu("Format");
	viewmenu = menuBar()->addMenu("View");
	helpmenu = menuBar()->addMenu("Help");
}

void Window::init_toolbar()
{
	toolbar = new QToolBar();
	toolbar->addAction(QIcon(), "New");
	toolbar->addAction(QIcon(), "Open");
	toolbar->addAction(QIcon(), "Save");
	toolbar->addAction(QIcon(), "Save As");
	toolbar->addAction(QIcon(), "Print");
	toolbar->addAction(QIcon(), "Copy");
	toolbar->addAction(QIcon(), "Cut");
	toolbar->addAction(QIcon(), "Paste");

	addToolBar(toolbar);

}

void Window::init_statusbar()
{
	statusBar()->addPermanentWidget(new QLabel(""));
	statusBar()->addPermanentWidget(new QLabel(tr("%1 %").arg(font_size)));

}

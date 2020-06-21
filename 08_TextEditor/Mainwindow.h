#pragma once
#include <QMainWindow>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QTextEdit>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QPlainTextEdit>


class Window : public QMainWindow
{
public:
	Window(QWidget* parent = nullptr);

	~Window();

private:

	void init_menubar();
	void init_toolbar();
	void init_statusbar();

	int font_size;



	QMenu* filemenu;
	QMenu* editmenu;
	QMenu* formatmenu;
	QMenu* viewmenu;
	QMenu* helpmenu;


	QPlainTextEdit* textarea;
	QToolBar* toolbar;
};
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


	void New();

	void Open();

	void Save();
	void SaveAs();
	void Exit();

private:

	void init_menubar();
	void init_toolbar();
	void init_statusbar();

	void setCurrentFile(QString filename);
	void documntModified();
	bool maybesave();


	int font_size;

	QMenu* filemenu;
	QMenu* editmenu;
	QMenu* formatmenu;
	QMenu* viewmenu;
	QMenu* helpmenu;

	QAction* NewAction;
	QAction* OpenAction;
	QAction* SaveAction;
	QAction* SaveAsAction;
	QAction* ExitAction;
	QAction* AboutAction;

	QPlainTextEdit* textarea;
	QToolBar* toolbar;

	QString CurrentFilename;
};
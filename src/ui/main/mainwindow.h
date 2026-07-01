#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "TopBar/topbar.h"
#include "LeftMenu/leftmenu.h"
#include "RightContent/rightcontent.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	void mousePressEvent(QMouseEvent* event);

	void mouseMoveEvent(QMouseEvent* event);


private:
	Ui::MainWindow* ui;
	QVBoxLayout* mainLayout;
	QHBoxLayout* contentLayout;
	TopBar* topBar;
	LeftMenu* leftMenu;
	RightContent* rightContent;
	QPoint m_dragPos;
};
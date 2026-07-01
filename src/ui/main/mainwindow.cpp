
#include <QMouseEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
	mainLayout = new QVBoxLayout(ui->centralwidget);

	topBar = new TopBar;
	mainLayout->addWidget(topBar);

	contentLayout = new QHBoxLayout;

	leftMenu = new LeftMenu;
	rightContent = new RightContent;
	contentLayout->addWidget(leftMenu,1);
	contentLayout->addWidget(rightContent,5);

	mainLayout->addLayout(contentLayout);

	connect(leftMenu, &LeftMenu::currentRowChanged, rightContent, &RightContent::onCurrentRowChanged);

	//topBar
	connect(topBar, &TopBar::minButtonClicked, this, [=]() {
		this->showMinimized();
	});
	connect(topBar, &TopBar::maxButtonClicked, this, [=]() {
		if (isMaximized())
			showNormal();
		else
			showMaximized();
	});
	connect(topBar, &TopBar::closeButtonClicked, this, [=]() {
		this->close();
	});
}




MainWindow::~MainWindow() {

}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_dragPos = event->globalPosition().toPoint() - frameGeometry().topLeft();
	}
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		move(event->globalPosition().toPoint() - m_dragPos);
	}
}
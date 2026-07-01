


#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

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

}




MainWindow::~MainWindow() {

}
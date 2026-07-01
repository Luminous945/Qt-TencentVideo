
#include "leftmenu.h"
#include "ui_leftmenu.h"

//#include <QListWidget>



LeftMenu::LeftMenu(QWidget* parent) 
	:QWidget(parent)
	, ui(new Ui::LeftMenu)
{
	ui->setupUi(this);

	ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	connect(ui->listWidget, &QListWidget::currentRowChanged, this, [=](int row) {
		emit currentRowChanged(row);
	});

	ui->listWidget->setCurrentRow(0);
	ui->listWidget->setFocus();
}
LeftMenu::~LeftMenu() {

}
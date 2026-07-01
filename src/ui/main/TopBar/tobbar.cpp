#include "topbar.h"
#include "ui_topbar.h"


TopBar::TopBar(QWidget* parent) 
	:QWidget(parent)
	, ui(new Ui::TopBar)
{
	ui->setupUi(this);

	setFixedHeight(60);
}
TopBar::~TopBar() {

}
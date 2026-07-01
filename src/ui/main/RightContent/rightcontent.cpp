

#include "rightcontent.h"
#include "ui_rightcontent.h"

RightContent::RightContent(QWidget* parent) 
	:QWidget(parent)
	, ui(new Ui::RightContent)
{
	ui->setupUi(this);
}
RightContent::~RightContent() {

}

void RightContent::onCurrentRowChanged(int row) {
	ui->stackedWidget->setCurrentIndex(row);
}
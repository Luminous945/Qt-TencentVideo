#include "topbar.h"
#include "ui_topbar.h"
#include <QFile>
#include <QStyle>


TopBar::TopBar(QWidget* parent) 
	:QWidget(parent)
	, ui(new Ui::TopBar)
{
	ui->setupUi(this);

	QFile file(":/qss/topbar.qss");

	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QString qss = QString::fromUtf8(file.readAll());
		this->setStyleSheet(qss);
	}
	else
	{
		qDebug() << "open failed";
	}
	setFixedHeight(60);
	// LOGO
	ui->logoLabel->setScaledContents(true);
	QPixmap pix(":/logo/tv-logo.png");
	ui->logoLabel->setPixmap(
		pix.scaled(
			ui->logoLabel->size(),
			Qt::KeepAspectRatio,
			Qt::SmoothTransformation));
	// 搜索框
	ui->searchEdit->setAttribute(Qt::WA_StyledBackground, true);
	hint = new QLabel("搜索视频...", ui->searchEdit);
	hint->setObjectName("hint");
	hint->move(10, 5);
	hint->show();
	connect(ui->searchEdit, &QLineEdit::textChanged, this, [=](const QString& text) {
		hint->setVisible(text.isEmpty() && !ui->searchEdit->hasFocus());
	});
	ui->searchEdit->installEventFilter(this);
	// 搜索按钮
	ui->searchButton->setText("");
	ui->searchButton->setIcon(QIcon(":/button/search.png"));
	//按钮
	//会员
	ui->vipButton->setText("会员");
	ui->vipButton->setIcon(QIcon(":/button/vip.png"));
	ui->vipButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui->vipButton->setIconSize(QSize(24, 24));
	//历史
	ui->historyButton->setText("历史");
	ui->historyButton->setIcon(QIcon(":/button/history.png"));
	ui->historyButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui->historyButton->setIconSize(QSize(32, 32));
	//下载
	ui->downloadButton->setText("下载");
	ui->downloadButton->setIcon(QIcon(":/button/download.png"));
	ui->downloadButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui->downloadButton->setIconSize(QSize(26, 26));
	//游戏
	ui->gameButton->setText("游戏");
	ui->gameButton->setIcon(QIcon(":/button/game.png"));
	ui->gameButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui->gameButton->setIconSize(QSize(26, 26));
	//更多
	ui->moreButton->setText("更多");
	ui->moreButton->setIcon(QIcon(":/button/more.png"));
	ui->moreButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui->moreButton->setIconSize(QSize(24, 24));
	//登录
	ui->loginButton->setFixedSize(60,30);

	ui->FunctionLayout->setContentsMargins(0, 0, 20, 0);

	//最小化
	ui->minButton->setText("");
	ui->minButton->setIcon(QIcon(":/button/min.png"));
	connect(ui->minButton, &QToolButton::clicked, this, [=]() {
		emit minButtonClicked();
	});
	//最大化 
	ui->maxButton->setText("");
	ui->maxButton->setIcon(QIcon(":/button/max.png"));
	connect(ui->maxButton, &QToolButton::clicked, this, [=]() {
		emit maxButtonClicked();
	});
	//关闭
	ui->closeButton->setText("");
	ui->closeButton->setIcon(QIcon(":/button/close.png"));
	connect(ui->closeButton, &QToolButton::clicked, this, [=]() {
		emit closeButtonClicked();
	});
}
TopBar::~TopBar() {

}

bool TopBar::eventFilter(QObject* obj, QEvent* event)
{
	if (obj == ui->searchEdit)
	{
		if (event->type() == QEvent::FocusIn)
			hint->hide();

		if (event->type() == QEvent::FocusOut && ui->searchEdit->text().isEmpty())
			hint->show();
	}
	return QWidget::eventFilter(obj, event);
}
#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LeftMenu; }
QT_END_NAMESPACE


class LeftMenu : public QWidget
{
	Q_OBJECT
public:
	LeftMenu(QWidget * parent = nullptr);
	~LeftMenu();

signals:
	void currentRowChanged(int row);

private:
	Ui::LeftMenu* ui;
};
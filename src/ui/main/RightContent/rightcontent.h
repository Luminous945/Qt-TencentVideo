#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class RightContent; }
QT_END_NAMESPACE


class RightContent : public QWidget
{
	Q_OBJECT
public:
	RightContent(QWidget* parent = nullptr);
	~RightContent();

public slots:
	void onCurrentRowChanged(int row);

private:
	Ui::RightContent* ui;
};
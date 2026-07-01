#pragma once

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class TopBar; }
QT_END_NAMESPACE

class TopBar : public QWidget
{
	Q_OBJECT
public:
	TopBar(QWidget* parent = nullptr);
	~TopBar();

private:
	Ui::TopBar* ui;
};
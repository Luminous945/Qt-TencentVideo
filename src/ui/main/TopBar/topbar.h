#pragma once

#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class TopBar; }
QT_END_NAMESPACE

class TopBar : public QWidget
{
	Q_OBJECT
public:
	TopBar(QWidget* parent = nullptr);
	~TopBar();

	bool eventFilter(QObject* obj, QEvent* event);

signals:
	void minButtonClicked();
	void maxButtonClicked();
	void closeButtonClicked();

private:
	Ui::TopBar* ui;
	QLabel* hint;
};
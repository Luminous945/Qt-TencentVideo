#include <QApplication>
#include "ui/main/mainwindow.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	qApp->setStyleSheet(R"(
		QWidget {
			background-color: #121212;
			color: white;
		}
	)");

	MainWindow mainwindow;
	mainwindow.show();

	return a.exec();
}
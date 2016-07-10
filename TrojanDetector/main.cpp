#include "trojandetector.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TrojanDetector w;
	w.show();
	return a.exec();
}

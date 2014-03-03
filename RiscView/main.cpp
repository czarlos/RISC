#include "RiscView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RiscView w;
	w.show();
	return a.exec();
}

#include <QApplication>
#include "circleDialog.h"

int main(int argc, char **argv)
{
	QApplication app(argc,argv);
	CircleDialog circle;
	circle.show();

	return app.exec();
}

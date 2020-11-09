#include "slider.h"

int main(int argc, char **argv)
{
	QApplication app(argc,argv);
	SliderDialog parent;
	parent.show();
	return app.exec();
}

#include "stuentdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StuentDialog w;
    w.show();

    return a.exec();
}

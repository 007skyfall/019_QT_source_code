#include "currentdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    currentDialog w;
    w.show();

    return a.exec();
}

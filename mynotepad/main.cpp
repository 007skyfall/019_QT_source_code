#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QPixmap pixmap("splash.png");
    QSplashScreen splash(pixmap);
    splash.show();
    for(unsigned long long i = 0; i<100000000000000000;++i)
    {
        for(unsigned long long i=0;i<80000000000000000;++i);
    }

    MainWindow w;
    w.show();
    splash.finish(&w);

    return a.exec();
}

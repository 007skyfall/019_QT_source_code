#include <QCoreApplication>
#include <QDir>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "root path is " << QDir::rootPath();
    qDebug() << "home path is " << QDir::homePath();
    qDebug() << "temp path is " << QDir::tempPath();


    return a.exec();
}

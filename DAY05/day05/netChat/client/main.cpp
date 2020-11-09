#include "clientdialog.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginDialog login;
    login.show();
    if(login.exec() == QDialog::Accepted)
    {
        ClientDialog w;
        w.show();
        return a.exec();
    }
    else {
        return  -1;
    }
}

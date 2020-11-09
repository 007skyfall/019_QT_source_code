#include "currentdialog.h"
#include "ui_currentdialog.h"

currentDialog::currentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::currentDialog)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    time = new QTime;
    timer->setInterval(1000);
    timer->start();
    connect(timer,SIGNAL(timeout()),
            this,SLOT(on_Timeout_Slots()));
}

currentDialog::~currentDialog()
{
    delete ui;
}

void currentDialog::on_Timeout_Slots(void)
{
    time->start();
    time->currentTime();
    int hour = time->hour();
    int min = time->minute();
    int sec = time->second();
   // QString str = QString::number(hour)+":"+QString::number(min)+":"+QString::number(sec);
    //ui->hourLcdNumber->display(str);

    ui->hourLcdNumber->display(QString::number(hour));
    ui->minLcdNumber->display(QString::number(min));
    ui->secLcdNumber->display(QString::number(sec));
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //system shutdown -s -t 3600*2

    ui->setupUi(this);
//    system("shutdown -s -t 3600*2");
//    system("notepad");
    //使用shutdown -a 注销关机
    QString command = "shutdown -s -t";
    ui->lineEdit->setText("1");
    int second = 3600* ui->lineEdit->text().toInt();
    command = command + " " + QString::number(second);
    qDebug() << "command is " << command;
    system(command.toStdString().data());
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(close()));
    timer->start(10*1000); //以毫秒为单位
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCompleter>
#include <QStringList>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //设置图片
    ui->labelImage->setPixmap(QPixmap("://image/LuffyQ.png"));
    //让图片自动适应label大小
    ui->labelImage->setScaledContents(true);

    //创建动画
    QMovie *myMovie = new QMovie("://image/mario.gif");
    //设置动画
    ui->labelGif->setMovie(myMovie);
    //启动动画
    myMovie->start();
    ui->labelGif->setScaledContents(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_change_clicked()
{
    static int i = 0;
    ui->stackedWidget->setCurrentIndex( ++i % 4 );

}

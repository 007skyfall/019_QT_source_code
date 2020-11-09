#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //测试按钮，点击按钮一下，关闭当前窗口
    connect(ui->closeButton,&QPushButton::clicked,this,&MainWindow::close);

    //行编辑器的测试
    QString lineText = ui->lineEdit->text();
    qDebug() << lineText;
    ui->lineEdit->setText("xixi");
    //设置内容显示间隙
    ui->lineEdit->setContentsMargins(10,0,0,0);
    //设置内容显示的方式
    ui->lineEdit->setEchoMode(QLineEdit::Password);


    //设置LCD数码管
    ui->lcdNumber->display(123);
    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(lcdStartSlot()));

    //设置进度条
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(200);
    ui->progressBar->setValue(100);

    //设置网址
    ui->urlLabel->setText("<h1><a href=\"https://www.baidu.com\">baidu</a></h1>");
    ui->urlLabel->setOpenExternalLinks(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lcdStartSlot()
{
    static int i = 0;

    ui->lcdNumber->display(i++);
    if(i >= 10)
    {
        i = 0;
    }


}

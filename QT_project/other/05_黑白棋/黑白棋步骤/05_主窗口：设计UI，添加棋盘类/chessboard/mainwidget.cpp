#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPainter>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    //把棋盘类对象发到指定的布局里
    ui->boadLayout->addWidget(&this->chessboard);

    this->resize(700, 500);
}

MainWidget::~MainWidget()
{
    delete ui;
}

//绘图，主要是设置主窗口背景图
void MainWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(), QPixmap(":/new/prefix1/image/background.jpg"));
}

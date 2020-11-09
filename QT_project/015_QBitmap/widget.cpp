#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setGeometry(1200,400,400,400);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    //QPixmap 图片背景透明
    p.drawPixmap(0, 0, QPixmap("butterfly.png"));
    //QBitmap 图片背景白色
    p.drawPixmap(200, 0, QBitmap("butterfly.png"));

     //QPixmap 图片背景黑色
    QPixmap pixmap;
    pixmap.load("butterfly1.png");
    p.drawPixmap(0, 200, pixmap);

    //QBitmap 图片背景白色
    QBitmap bitmap;
    bitmap.load("butterfly1.png");
    p.drawPixmap(200, 200, bitmap);

}

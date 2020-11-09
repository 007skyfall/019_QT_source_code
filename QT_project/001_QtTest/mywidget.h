#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    //Q_OBJECT //信号与槽的时候需要

public:
    //MyWidget控件不是任何控件的子控件
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
};

#endif // MYWIDGET_H

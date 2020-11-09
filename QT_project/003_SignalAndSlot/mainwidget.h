#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h" //子窗口头文件

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

public:
    SubWidget subWin;
    QPushButton * mainButton;

private slots:
    void tomainSlot();
    void tosubSlot();
};

#endif // MAINWIDGET_H

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "chesswidget.h" //棋盘类头文件

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

protected:
    //绘图，主要是设置主窗口背景图
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWidget *ui;
    ChessWidget chessboard; //棋盘类对象
};

#endif // MAINWIDGET_H

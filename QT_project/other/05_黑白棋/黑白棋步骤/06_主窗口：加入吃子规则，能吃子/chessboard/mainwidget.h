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


    //黑白棋吃子规则
    int judgeRule(int x, int y, void *chess, ChessWidget::GridState currentRole,bool eatChess=true);

    //初始化棋盘状态
    void initChess();

protected:
    //绘图，主要是设置主窗口背景图
    void paintEvent(QPaintEvent *);

public slots:
    // 槽函数，接收棋盘窗口的信号
    // 参数为棋盘下棋的坐标
    void doPressPoint(int x, int y);

private:
    Ui::MainWidget *ui;
    ChessWidget chessboard; //棋盘类对象

    int chess[64][8][8];    // 三维数组，方便标志棋盘状态
    int step;               // 标志当前下子为第几步

};

#endif // MAINWIDGET_H

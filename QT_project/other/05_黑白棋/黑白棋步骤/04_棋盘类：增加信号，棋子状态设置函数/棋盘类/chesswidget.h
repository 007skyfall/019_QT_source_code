#ifndef CHESSWIDGET_H
#define CHESSWIDGET_H

#include <QWidget>

class ChessWidget : public QWidget
{
    Q_OBJECT

public:
    ChessWidget(QWidget *parent = 0);
    ~ChessWidget();

    // 枚举变量
    // Empty标志为空，Black标志为黑子，White标志为白子
    enum GridState{Empty,Black, White };

    void initChessState();  //初始化棋盘状态

    void setChessManInfo(void *p); //棋子状态设置函数

    //设置背景图，黑白子图片路径
    void setChessPath(QString Path="", QString bPath="", QString wPath="");

protected:
    // resize事件，当改变窗口时自动调用
    // 确定棋盘起点坐标，每格的宽度和高度
    void resizeEvent(QResizeEvent *);

    // 绘图事件，主要功能是画棋盘，棋子
    void paintEvent(QPaintEvent *);

    // 鼠标点击事件，主要是确定棋盘方格的位置
    void mousePressEvent(QMouseEvent *);

signals:
    // 发射的信号, 参数为当前下子的坐标
    void pressPoint(int x, int y);

private:
    int gridWidth, gridHeight;  // 棋盘一个小方格的高度, 宽度
    int startX, startY;  // 棋盘的起点坐标(startX,startY)

    int chessState[8][8];

    QString backgroudPath, blackPath, whitePath;
};

#endif // CHESSWIDGET_H

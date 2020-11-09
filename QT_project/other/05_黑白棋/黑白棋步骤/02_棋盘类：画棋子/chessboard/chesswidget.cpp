#include "chesswidget.h"

#include <QPen>
#include <QPainter>

ChessWidget::ChessWidget(QWidget *parent)
    : QWidget(parent)
{
    this->initChessState(); //初始化棋盘状态
}

ChessWidget::~ChessWidget()
{

}

//确定棋盘起点坐标，每格的宽度和高度
void ChessWidget::resizeEvent(QResizeEvent *)
{

    this->gridWidth = this->width()/10;
    this->gridHeight = this->height()/10;
    this->startX = this->gridWidth;
    this->startY = this->gridHeight;

}

 // 绘图事件，主要功能是画棋盘，棋子
void ChessWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPen myPen;
    myPen.setWidth(4);  // 通过画笔设置线宽
    myPen.setColor(Qt::black);  // 设置画笔颜色
    painter.setPen(myPen);      // 将笔交给画家

    //背景图
    painter.drawPixmap(this->rect(), QPixmap(":/new/prefix1/image/board.jpg"));

    // 画棋盘
    for(int i = 0; i <= 8; i++){
         painter.drawLine(startX, startY+i*this->gridHeight,
                                      startX+8*gridWidth, startY+i*gridHeight);    // 画横线
         painter.drawLine(startX+i*gridWidth, startY,
                                      startX+gridWidth*i, startY+gridHeight*8);    // 画竖线
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){

            if(this->chessState[i][j] == Black){ // 画黑子

                painter.drawPixmap(startX+gridWidth*i, startY+gridHeight*j,
                                   gridWidth, gridHeight,QPixmap(":/new/prefix1/image/black.png"));

            }else if(this->chessState[i][j] == White){// 画白子

                painter.drawPixmap(startX+gridWidth*i, startY+gridHeight*j,
                                   gridWidth, gridHeight,QPixmap(":/new/prefix1/image/white.png"));

            }
        }
    }
}

void ChessWidget::initChessState()
{
    // 64个格全部标志为Empty
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            this->chessState[i][j] = this->Empty;
            //this->chessState[i][j] = this->White;
        }
    }

    // 将棋盘中间的4个空间分别标志位2黑子2白子
    this->chessState[3][3] = this->Black;
    this->chessState[3][4] = this->White;
    this->chessState[4][3] = this->White;
    this->chessState[4][4] = this->Black;
}

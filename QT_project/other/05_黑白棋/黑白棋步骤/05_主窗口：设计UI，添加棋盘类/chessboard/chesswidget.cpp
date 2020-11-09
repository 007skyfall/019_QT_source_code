#include "chesswidget.h"

#include <QPen>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

ChessWidget::ChessWidget(QWidget *parent)
    : QWidget(parent)
{
    this->initChessState(); //初始化棋盘状态

     //设置背景图，黑白子图片路径
    this->setChessPath(":/new/prefix1/image/board.jpg",
                       ":/new/prefix1/image/black.png",
                       ":/new/prefix1/image/white.png");
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
    painter.drawPixmap(this->rect(), QPixmap(this->backgroudPath));

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
                                   gridWidth, gridHeight,QPixmap(this->blackPath));

            }else if(this->chessState[i][j] == White){// 画白子

                painter.drawPixmap(startX+gridWidth*i, startY+gridHeight*j,
                                   gridWidth, gridHeight,QPixmap(this->whitePath));

            }
        }
    }
}

//初始化棋盘状态
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

// 鼠标点击事件，主要是确定棋盘方格的位置
void ChessWidget::mousePressEvent(QMouseEvent *e)
{
    // 获取点击点x,y的坐标
    int x = e->x();
    int y = e->y();
    int i = 0, j = 0;

    // 要保证点击点在棋盘范围里面
    if((x > startX) && (x < (startX + gridWidth*8))&&
       (y > startY)&&(y < (startY + gridHeight*8)))
    {
        // 将坐标值转换为相对棋盘的数组下标
        // 类似于a[i][j]的i和j
        i = (x - startX)/gridWidth;
        j = (y - startY)/gridHeight;
        qDebug() << "i = " << i << ", j = " << j;

        // 发射的信号, 参数为当前下子的坐标
        emit this->pressPoint(i, j);
    }
}

//棋子状态设置函数
void ChessWidget::setChessManInfo(void *p)
{
    /*
    //  通过typedef自定义一个类型(二维数组指针)
    //  因为p本来是(void *)类型的
    // temp(p)[i][j]这样就能把(void *)强制转换为二维数组指针类型
    typedef int (*temp)[8];

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            this->chessState[i][j] = temp(p)[i][j];
        }
    }*/
    memcpy(this->chessState, p, sizeof(int)*64);
	
	this->update(); //更新
}

 //设置背景图，黑白子图片路径
void ChessWidget::setChessPath(QString Path, QString bPath, QString wPath)
{
    this->backgroudPath = Path;
    this->blackPath = bPath;
    this->whitePath = wPath;

    this->update(); //更新
}

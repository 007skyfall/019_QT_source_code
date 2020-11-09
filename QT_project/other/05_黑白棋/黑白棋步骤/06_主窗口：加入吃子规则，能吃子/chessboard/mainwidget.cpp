#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPainter>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    //把棋盘类对象发到指定的布局里
    ui->boadLayout->addWidget(&this->chessboard);

    //this->chessboard.hide(); //棋盘默认隐藏
    this->resize(700, 500);

    // pressPoint()为棋盘发出的信号，doPressPoint()为主窗口的处理函数
    connect(&this->chessboard, SIGNAL(pressPoint(int,int)), this, SLOT(doPressPoint(int,int)));

    this->initChess(); //初始化棋盘状态
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

/*********************************************************************
* 功能：
*     黑白棋吃子规则
* 参数：
*    x, y: 棋盘数组坐标位置
*     chess：棋子状态
*     currentRole：ChessWidget类中枚举变量,enum GridState{Empty,Black, White }
*     eatChess: true代表吃子，false只是判断有子可吃，默认为true
* 返回值：
*    能吃子的个数
***********************************************************************/
int MainWidget::judgeRule(int x, int y, void *chess, ChessWidget::GridState currentRole,bool eatChess)
{
    // 棋盘的八个方向
    int dir[8][2]={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
    int temp_x = x, temp_y = y;             // 临时保存棋盘数组坐标位置
    int i = 0, eatNum = 0;                  // 初始化数据
    typedef int (*p)[8];             // 自定义类型
    p chessFlag = p(chess);                // 类型转换

    if(chessFlag[temp_x][temp_y] != ChessWidget::Empty)  // 如果此方格内已有棋子，返回;
        return 0;

    // 棋盘的8个方向
    for(i = 0 ; i <8; i++)
    {
        temp_x += dir[i][0]; temp_y += dir[i][1];	// 准备判断相邻棋子
        // 如果没有出界，且相邻棋子是对方棋子，才有吃子的可能．
        if((temp_x < 8 && temp_x >=0 && temp_y < 8 && temp_y >= 0)
            && (chessFlag[temp_x][temp_y] != currentRole) && (chessFlag[temp_x][temp_y] != ChessWidget::Empty) )
        {
            temp_x += dir[i][0]; temp_y += dir[i][1];	            // 继续判断下一个，向前走一步
            while(temp_x < 8 && temp_x >=0 && temp_y < 8 && temp_y >= 0)
            {
                if(chessFlag[temp_x][temp_y] == ChessWidget::Empty) // 遇到空位跳出
                        break;
                if(chessFlag[temp_x][temp_y] == currentRole)       // 找到自己的棋子，代表可以吃子
                {
                    if(eatChess == true)                            // 确定吃子
                    {

                        chessFlag[x][y] = currentRole;          // 开始点标志为自己的棋子
                        temp_x -= dir[i][0]; temp_y -= dir[i][1];// 后退一步
                        while((temp_x != x )||(temp_y != y))	 // 只要没有回到开始的位置就执行
                        {
                            chessFlag[temp_x][temp_y] = currentRole;   // 标志为自己的棋子
                            temp_x -= dir[i][0]; temp_y -= dir[i][1];   // 继续后退一步
                            eatNum++;  // 累计
                        }
                    }
                    else    // 不吃子，只是判断这个位置能不能吃子
                    {

                        temp_x -= dir[i][0]; temp_y -= dir[i][1];   // 后退一步
                        while((temp_x != x )||(temp_y != y))        // 只计算可以吃子的个数
                        {
                            temp_x -= dir[i][0]; temp_y -= dir[i][1];// 继续后退一步
                            eatNum ++;
                        }
                    }
                    break;  // 跳出循环
                }// 没有找到自己的棋子，就向前走一步
                temp_x += dir[i][0]; temp_y += dir[i][1];   // 向前走一步
            }
        }// 如果这个方向不能吃子，就换一个方向
        temp_x = x; temp_y = y;
    }

    return eatNum;              // 返回能吃子的个数
}

//初始化棋盘状态
void MainWidget::initChess()
{
    this->step = 0;

    // 64个格全部标志为Empty
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            this->chess[step][i][j] = ChessWidget::Empty;
        }
    }

    // 将棋盘中间的4个空间分别标志位2黑子2白子
    this->chess[step][3][3] = ChessWidget::Black;
    this->chess[step][3][4] = ChessWidget::White;
    this->chess[step][4][3] = ChessWidget::White;
    this->chess[step][4][4] = ChessWidget::Black;

    // 将棋子的状态通过setChessManInfo()传递过去
    this->chessboard.setChessManInfo(&this->chess[step]);

}

void MainWidget::doPressPoint(int x, int y)
{
    // 如果能吃子，返回值大于0
    if(0 < this->judgeRule(x, y, &chess[step], ChessWidget::White)){

        // 将棋子的状态通过setChessManInfo()传递过去
        this->chessboard.setChessManInfo(&this->chess[step]);
    }

}

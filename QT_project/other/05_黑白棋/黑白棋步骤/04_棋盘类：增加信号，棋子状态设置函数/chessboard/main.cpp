#include "chesswidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessWidget w;

    int test[1][8][8];
    int temp[8][8];
    // 64个格全部标志为Empty
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            test[0][i][j] = ChessWidget::White;
            temp[i][j] = ChessWidget::Black;
        }
    }
    w.setChessManInfo(&test[0]);
    //w.setChessManInfo(temp);


    w.show();

    return a.exec();
}

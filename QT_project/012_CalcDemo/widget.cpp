#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTextStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton0, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButton1, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButton2, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButton3, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButton4, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButton5, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButton6, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButton7, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButton8, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButton9, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButtonEqual, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButtonDel, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButtonPlus, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButtonSub, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButtonMul, SIGNAL(pressed()), this, SLOT(dealNum()) );
    connect(ui->pushButtonDiv, SIGNAL(pressed()), this, SLOT(dealNum()) );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::dealNum()
{
    //获取信号发送者
    QPushButton *button = (QPushButton *)this->sender();

    //获取按钮的内容
    QString str = button->text();

    if("c" == str){// 如果是退格键
        buf.chop(1); // 截掉最后 1 个字符
    }else{
        buf += str; //内容追加

        // 运算操作
        if("=" == str)
        { // 如果是 " = "


//            int a, b;
//            QChar c;
//            QTextStream(&buf) >> a >> c >> b;
//            qDebug() << a << c << b;

            //buf.toLocal8Bit().data(): QString -> char *
            char str[100] = {0};
            strcpy(str, buf.toLocal8Bit().data());

            int a, b;
            char c;
            sscanf(str, "%d%c%d", &a, &c, &b);

            if('+' == c)
            {
                buf = QString::number(a+b);
            }
            else if('-' == c)
            {
                buf = QString::number(a-b);
            }
            else if('*' == c)
            {
               buf = QString::number(a*b);
            }
            else if('/' == c)
            {
                buf = QString::number(a/b);
            }
        }
    }

    ui->lineEdit->setText(buf);
}

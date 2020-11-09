#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setGeometry(500,500,500,500);
    //method1:Lambda表达式
    QPushButton *buttonChangeText = new QPushButton("original", this);
    buttonChangeText->setGeometry(100, 100, 200, 20);
    connect(buttonChangeText, &QPushButton::clicked,
            [=]()
            {
                 buttonChangeText->setText("changed");
            }

            );

    //method2: 使用Qt4的宏函数的方式
    QPushButton * buttonHide = new QPushButton("hide me",this);
    buttonHide->setGeometry(100,150,200,20);

    connect(buttonHide, SIGNAL(clicked()),buttonHide,SLOT(hide()));

    //method2: 使用Qt5的方式,可以进行语法检查
    QPushButton * buttonShow = new QPushButton("show button",this);
    buttonShow->setGeometry(100,200,200,20);
    connect(buttonShow, &QPushButton::clicked, buttonHide, &QPushButton::show);





}

Widget::~Widget()
{

}

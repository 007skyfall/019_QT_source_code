#include "mainwidget.h"
#include <QPushButton>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("dage");
    mainButton = new QPushButton(this);
    mainButton->setText("to son");
    mainButton->resize(50,30);
    mainButton->move(100,100);
//    subWin.show();
    QObject::connect(&subWin,SIGNAL(mySignal()),this,SLOT(tomainSlot()));
    QObject::connect(mainButton,SIGNAL(clicked()),this,SLOT(tosubSlot()));
    this->resize(300,300);

}



MainWidget::~MainWidget()
{

}

void MainWidget::tosubSlot()
{
    this->hide();
    subWin.show();
}

void MainWidget::tomainSlot()
{
    this->show();
    subWin.hide();
}

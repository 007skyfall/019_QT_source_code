#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
     this->setWindowTitle("xiaodi");
     subButton = new QPushButton;
     subButton->setParent(this);
     subButton->setText("to main");
     subButton->move(100,100);
     subButton->resize(50,30);
     QObject::connect(subButton,SIGNAL(clicked()),this,SLOT(changeSlot()));
     this->resize(300,300);

}

void SubWidget::changeSlot()
{
    emit mySignal();
}

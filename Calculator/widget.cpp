#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->move(400,100);
    this->setWindowTitle("Calculator");
    this->setMaximumSize(460,180);
    this->setMinimumSize(460,180);
    QObject::connect(ui->calcButton,SIGNAL(clicked(bool)),this,SLOT(clacSlot()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::clacSlot()
{
    int first = ui->firstValueLine->text().toInt();
    int second = ui->secondLineText->text().toInt();
    int result = 0;
//    if(ui->firstValueLine->text() == NULL || ui->secondLineText->text() ==  NULL)
//    {
//       ui->resultLine->setText("");
//    }
    //计算加法
    if(ui->calComboBox->currentIndex() == 0)
    {
        result = first + second;
        ui->resultLine->setText(QString::number(result));
        QMessageBox::information(this,"Result",QString::number(result));
    }
    //计算减法
    else if(ui->calComboBox->currentIndex() == 1)
    {
        result = first - second;
        ui->resultLine->setText(QString::number(result));
        QMessageBox::information(this,"Result",QString::number(result));
    }
    //计算乘法
    else if(ui->calComboBox->currentIndex() == 2)
    {
        result = first * second;
        ui->resultLine->setText(QString::number(result));
        QMessageBox::information(this,"Result",QString::number(result));
    }
    //计算除法
    else
    {
        if (second == 0)
        {
            QMessageBox::warning(this,"Result","Second is not with zero!!");
                 return ;
        }

        result = first / second;
        ui->resultLine->setText(QString::number(result));
        QMessageBox::information(this,"Result",QString::number(result));
    }

}

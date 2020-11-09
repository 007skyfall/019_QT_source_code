#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置密码为隐藏字符
    ui->passwdLineEdit->setEchoMode(QLineEdit::Password);
//    QObject::connect(ui->loginButton,SIGNAL(clicked()),this,SLOT(on_loginButton_clicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_loginButton_clicked()
{
    //user:skyfall password:bond007
    if(ui->userLineEdit->text() == "skyfall" && ui->passwdLineEdit->text() == "bond007")
    {
        QMessageBox::information(this,"Message Login","Login Success");
        //do something
        return ;
    }
    else
    {
        QMessageBox::information(this,"Message Error","Login failed");
        return ;
    }
}

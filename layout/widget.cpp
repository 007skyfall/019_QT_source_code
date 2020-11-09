#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置固定大小
    this->setMaximumSize(317,113);
    this->setMinimumSize(315,113);
    //设置位置
    this->move(0,580);
    //设置标题
    this->setWindowTitle("Running");
    //默认确定按钮为灰色，不可以使用的状态
    ui->submitButton->setEnabled(false);
    //connect(sender,signal(what),receiver,slot(do something))
    QObject::connect(ui->browerButton,SIGNAL(clicked(bool)),this,SLOT(changeTitleSlot()));
//    QObject::connect(ui->browerButton,SIGNAL(clicked(bool)),qApp,SLOT(quit()));
    //点击回车，触发确定按钮启动应用程序
    QObject::connect(ui->cmdlineEdit,SIGNAL(returnPressed()),this,SLOT(on_submitButton_clicked()));
    //行编辑器输入命令后，触发按钮变成可以使用状态
    QObject::connect(ui->cmdlineEdit,SIGNAL(textChanged(QString)),this,SLOT(setButtonEnable(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeTitleSlot()
{
  ui->cancelButton->setText("111");
  this->setWindowTitle("i am skyfall");
}

void Widget::on_cancelButton_clicked(bool checked)
{
   this->setWindowTitle("hello i am zxy");

    this->close();
}


void Widget::on_submitButton_clicked()
{

//    QProcess *myProcess = new QProcess(parent);
//    myProcess->start(program, arguments);
    //启动一个额外的应用程序
    QProcess * progessStart = new QProcess;
    QString lineString = ui->cmdlineEdit->text();
    progessStart->start(lineString.trimmed());
    //行编辑器中的内容清空，该应用程序关闭，以便启动另一个应用程序
    ui->cmdlineEdit->clear();
    this->close();

}

//设置按钮的状态变成可以使用状态
void Widget::setButtonEnable(QString)
{
    ui->submitButton->setEnabled(true);
}

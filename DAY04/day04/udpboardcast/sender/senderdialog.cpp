#include "senderdialog.h"
#include "ui_senderdialog.h"
#include <QMessageBox>
SenderDialog::SenderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SenderDialog)
{
    ui->setupUi(this);
    statu = false;
    udpSocked = new QUdpSocket(this);
}

SenderDialog::~SenderDialog()
{
    delete ui;
}

void SenderDialog::on_startStopButton_clicked()
{
    if(statu == false)  // 开始广播
    {
        statu = true;
        if(ui->portEdit->text() == "")
        {
            QMessageBox::question(this,"端口号",
                          "端口号无效，请输入有效的端口号！",
                                  QMessageBox::Ok);
            return;
        }
        ui->startStopButton->setText("停止广播");
        ui->portEdit->setEnabled(false);
    }
    else
    {    // 停止广播
        statu = false;
        ui->startStopButton->setText("开始广播");
        ui->portEdit->setEnabled(true);
        udpSocked->close();
    }
}

void SenderDialog::on_sendButton_clicked()
{
    sendMessage();  // 发送消息的函数
}

void SenderDialog::sendMessage()
{   // 获取端口号
    port = ui->portEdit->text().toShort();
    // 获取要发送的消息
    msg = ui->textEdit->text();
    if (msg == "")
    {
        QMessageBox::question(this,"发送内容",
                      "发送内容无效，请输入有效的内容！",
                              QMessageBox::Ok);
        return;
    }
    // 发送消息
    udpSocked->writeDatagram(msg.toLocal8Bit(),
             QHostAddress::LocalHost,port);
}








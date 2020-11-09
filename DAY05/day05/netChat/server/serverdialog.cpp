#include "serverdialog.h"
#include "ui_serverdialog.h"

ServerDialog::ServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerDialog)
{
    ui->setupUi(this);
    tcpserver = new QTcpServer(this);
    connect(tcpserver,SIGNAL(newConnection()),
            this,SLOT(on_Newconnection_Slots()));
}

ServerDialog::~ServerDialog()
{
    delete ui;
}

void ServerDialog::on_pushButton_clicked()
{
    // 获取端口号
    serverport = ui->portEdit->text().toShort();
    // 建立连接，等待客户端的连接请求
    bool res = tcpserver->listen(
                QHostAddress::Any,serverport);
    if(res == true)
    {
        qDebug("服务器创建成功");
    }
    else
    {
        qDebug("服务器创建失败");
        return ;
    }

    ui->portEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
}
// 处理客户端连接的槽函数
void ServerDialog::on_Newconnection_Slots()
{
    // 获取和客户端通信的套接字
    QTcpSocket* tcpClientSocked =
            tcpserver->nextPendingConnection();
    // 将客户端连接的套接字追加到QList容器中
    tcpClientList.append(tcpClientSocked);

    // 等待客户端发送数据，客户端发送数据会触发
    // readyRead()信号
    connect(tcpserver,SIGNAL(readyRead()),
            this,SLOT(ON_MessageRev_Slots()));
}
void  ServerDialog::ON_MessageRev_Slots()
{   // 遍历所有的套接字
    for(int i = 0;i < tcpClientList.count();i++)
    {
        // 判断客户端是否有有效的数据
        if(tcpClientList.at(i)->bytesAvailable())
        {
            // 读取客户端发送来的消息
            QByteArray buf =
                    tcpClientList.at(i)->readAll();
            ui->listWidget->addItem(buf);
            sendMessage(buf);
        }

    }
}

void ServerDialog::sendMessage(QByteArray& buf)
{
    // 遍历所有的客户端，都发送一条消息
    for(int i = 0;i < tcpClientList.count();i++)
    {
        tcpClientList.at(i)->write(buf);
    }
}









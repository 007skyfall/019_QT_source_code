#include "clientdialog.h"
#include "ui_clientdialog.h"

ClientDialog::ClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDialog)
{
    ui->setupUi(this);
    tcpsocked = new QTcpSocket(this);
    status = false;
    // 禁用发送消息的按钮
    ui->sendMessageButton->setEnabled(false);
    // 从服务器端接收消息
    connect(tcpsocked,SIGNAL(readyRead()),
            this,SLOT(on_RevMessage_SLOT()));
    // 讲connected信号函数连接到槽函数
    connect(tcpsocked,SIGNAL(connected()),
            this,SLOT(on_Connected_Slots()));
}

ClientDialog::~ClientDialog()
{
    delete ui;
}

void ClientDialog::on_startButton_clicked()
{
    if (status == false)
    {
        // 获取ip地址
        QString ip = ui->serverIpEdit->text();
        if(serverip.setAddress(ip) == false)
        {
            QMessageBox::information(this,"IP地址",
                                     "无效的IP地址");
            return ;
        }
        // 获取服务器的端口号
        serverport = ui->serverPortEdit->text().toShort();
        if(serverport == 0){
            QMessageBox::information(this,"error",
                                     "端口号无效");
            return ;
        }
        userName = ui->clientNameEdit->text();
        if(userName == "")
        {
            QMessageBox::information(this,"error",
                                     "名字无效");
            return ;
        }
        // 和服务器建立连接,产生一个和服务器建立建立的信号
        // connected()
        tcpsocked->connectToHost(serverip,serverport);

        status = true;
    }
    else  // 断开和服务器的连接
    {
        QString buf = userName + ":已下线";
        tcpsocked->write(buf.toLocal8Bit());
        // 和服务器断开连接, 离开服务起产生信号disconnected()
        tcpsocked->disconnectFromHost();
        connect(tcpsocked,SIGNAL(disconnected()),
                this,SLOT(on_Disconnected_Slot()));
        status = false;
    }
}

void ClientDialog::on_sendMessageButton_clicked()
{
    if(ui->sendMessageEdit->text() == "")
    {
        return;
    }
    // 发送消息
    QString msg = userName + ":"
            + ui->sendMessageEdit->text();
    tcpsocked->write(msg.toLocal8Bit());
    // 清空数据
    ui->sendMessageEdit->clear();
}

void ClientDialog::on_Connected_Slots()
{
    // 设置为离开聊天室
    ui->startButton->setText("离开聊天室");
    // 使能发送消息的按钮
    ui->sendMessageButton->setEnabled(true);
    // 禁止ip,port,username组件输入
    ui->serverIpEdit->setEnabled(false);
    ui->serverPortEdit->setEnabled(false);
    ui->clientNameEdit->setEnabled(false);
    QString sendbuf = userName + ":以上线";

    qDebug() << sendbuf;
    qDebug() << ++i;
    tcpsocked->write(sendbuf.toLocal8Bit());
}

void ClientDialog::on_Disconnected_Slot()
{
    // 使能ip,port,username组件输入
    ui->serverIpEdit->setEnabled(true);
    ui->serverPortEdit->setEnabled(true);
    ui->clientNameEdit->setEnabled(true);
    ui->startButton->setText("进入聊天室");
    // 禁止发送消息的按钮
    ui->sendMessageButton->setEnabled(false);
}

void ClientDialog::on_RevMessage_SLOT()
{
    if(tcpsocked->bytesAvailable())
    {
        QByteArray msg;
        msg.resize(tcpsocked->bytesAvailable());
        // 读取服务器返回的数据
        tcpsocked->read(msg.data(),msg.size());
        ui->listWidget->addItem(msg);
    }
}








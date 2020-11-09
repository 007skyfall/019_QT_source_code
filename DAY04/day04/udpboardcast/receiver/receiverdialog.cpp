#include "receiverdialog.h"
#include "ui_receiverdialog.h"

ReceiverDialog::ReceiverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceiverDialog)
{
    ui->setupUi(this);
    udpSocked = new QUdpSocket;
    status = false;
    // 如果接收到消息之后，会产生一个readyRead信号
    connect(udpSocked,SIGNAL(readyRead()),
            this,SLOT(messageReceiverSlots())
            );
}

ReceiverDialog::~ReceiverDialog()
{
    delete ui;
}

void ReceiverDialog::on_pushButton_clicked()
{
    if(status == false)
    {
        status = true;
        // 获取端口号
        port = ui->portEdit->text().toShort();
        // 绑定端口
        bool res = udpSocked->bind(quint16(port));
        if (res == false)
        {
            QMessageBox::information(this,
                           "error","udp bind failed!");
            return ;
        }
        ui->pushButton->setText("停止接收");
        ui->portEdit->setEnabled(false);
    }
    else{
        status = false;
        udpSocked->close();
        ui->pushButton->setText("接收消息");
        ui->portEdit->setEnabled(true);
    }
}
void ReceiverDialog::messageReceiverSlots()
{
    // 判断socked是否有有效的数据
    if(udpSocked->hasPendingDatagrams()){
        QByteArray datagram;
        // 制定数组的大小
        datagram.resize(udpSocked->pendingDatagramSize());
        // 读取接收的数据
        udpSocked->readDatagram(datagram.data()
                                ,datagram.size());
        // 显示接收的数据
        ui->listWidget->addItem(datagram);
    }

}









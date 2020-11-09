#include "networkinfodialog.h"
#include "ui_networkinfodialog.h"
#include <QHostInfo>
#include <QList>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include <QMessageBox>

NetworkInfoDialog::NetworkInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NetworkInfoDialog)
{
    ui->setupUi(this);
    getHostName();
}

NetworkInfoDialog::~NetworkInfoDialog()
{
    delete ui;
}

void NetworkInfoDialog::on_InfoButton_clicked()
{
    QString Detail;
    QList<QNetworkInterface> networkinterface =
            QNetworkInterface::allInterfaces();

    for(int i = 0;i<networkinterface.count();i++)
    {
        QNetworkInterface interface;
        interface = networkinterface.at(i);
        Detail += "网卡的名字：" +
                interface.name() + "\n";
        Detail += "MAC地址：" +
                interface.hardwareAddress() + "\n";
        QList<QNetworkAddressEntry>  netaddr =
                interface.addressEntries();
        QNetworkAddressEntry addrEntry = netaddr.at(0);
        Detail += "IP地址：" +
                addrEntry.ip().toString() + "\n";
        Detail += "广播地址：" +
                addrEntry.broadcast().toString() + "\n";
        Detail += "子网掩码：" +
                addrEntry.netmask().toString() + "\n";
    }
    ui->textEdit->setText(Detail);
   // QMessageBox::information(this,"详细信息",Detail);
    QMessageBox msgBox(QMessageBox::Information,
                       "详细信息",Detail,
                       QMessageBox::Ok,
                       this);
    if(msgBox.exec() ==QMessageBox::Ok )
    {

        msgBox.close();
    }
}
void NetworkInfoDialog::getHostName(void)
{
    QHostInfo  hostName;
    ui->NameEdit->setText(hostName.localHostName());

}










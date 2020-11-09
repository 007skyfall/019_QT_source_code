#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QDialog>
#include <QTcpServer>
#include <QMessageBox>
#include <QDebug>
#include <QTcpSocket>
namespace Ui {
class ServerDialog;
}

class ServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServerDialog(QWidget *parent = nullptr);
    ~ServerDialog();
    void sendMessage(QByteArray& buf);
private slots:
    // 创建服务器的槽函数
    void on_pushButton_clicked();
    // 客户端具有连接请求（Newconnection）是调用槽函数
    void on_Newconnection_Slots();
    // 收到客户端的数据readyRead()信号，调用槽函数
    void ON_MessageRev_Slots();
private:
    Ui::ServerDialog *ui;
    QTcpServer *tcpserver;
    // 服务器的端口号
    quint16  serverport;

    // 存储客户端连接的套接字的容器
    QList <QTcpSocket*> tcpClientList;

};

#endif // SERVERDIALOG_H

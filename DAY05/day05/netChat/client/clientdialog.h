#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <QHostAddress>

namespace Ui {
class ClientDialog;
}

class ClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDialog(QWidget *parent = nullptr);
    ~ClientDialog();

private slots:
    // 进如聊天室的槽函数
    void on_startButton_clicked();
    // 发送消息的槽函数
    void on_sendMessageButton_clicked();
    // 和服务器建立连接的槽函数
    void on_Connected_Slots();
    // 和服务器断开连接的槽函数
    void on_Disconnected_Slot();
    // 接收消息的槽函数
    void on_RevMessage_SLOT();

private:
    Ui::ClientDialog *ui;

    bool status;
    quint16 serverport;
    QHostAddress serverip;
    QTcpSocket *tcpsocked;
    QString userName;
    int i = 0;
};

#endif // CLIENTDIALOG_H

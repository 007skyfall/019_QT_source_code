#ifndef SENDERDIALOG_H
#define SENDERDIALOG_H

#include <QDialog>
#include <QUdpSocket>
namespace Ui {
class SenderDialog;
}

class SenderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SenderDialog(QWidget *parent = nullptr);
    ~SenderDialog();
    void sendMessage();
private slots:
    void on_startStopButton_clicked();

    void on_sendButton_clicked();

private:
    Ui::SenderDialog *ui;
    QUdpSocket *udpSocked;
    bool  statu;
    short port;
    QString msg;
};

#endif // SENDERDIALOG_H

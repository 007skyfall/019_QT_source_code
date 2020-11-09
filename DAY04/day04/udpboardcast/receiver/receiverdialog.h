#ifndef RECEIVERDIALOG_H
#define RECEIVERDIALOG_H

#include <QDialog>
#include <QUdpSocket>
#include <QMessageBox>
namespace Ui {
class ReceiverDialog;
}

class ReceiverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceiverDialog(QWidget *parent = nullptr);
    ~ReceiverDialog();

private slots:
    void on_pushButton_clicked();
    void messageReceiverSlots();

private:
    Ui::ReceiverDialog *ui;
    QUdpSocket * udpSocked;
    short port;
    bool status;
};

#endif // RECEIVERDIALOG_H

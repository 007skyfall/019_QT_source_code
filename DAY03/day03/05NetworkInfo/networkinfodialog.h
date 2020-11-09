#ifndef NETWORKINFODIALOG_H
#define NETWORKINFODIALOG_H

#include <QDialog>

namespace Ui {
class NetworkInfoDialog;
}

class NetworkInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NetworkInfoDialog(QWidget *parent = nullptr);
    ~NetworkInfoDialog();
    void getHostName(void);

private slots:
    void on_InfoButton_clicked();

private:
    Ui::NetworkInfoDialog *ui;
};

#endif // NETWORKINFODIALOG_H

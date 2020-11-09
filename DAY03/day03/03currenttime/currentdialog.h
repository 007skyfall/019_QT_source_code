#ifndef CURRENTDIALOG_H
#define CURRENTDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QTime>

namespace Ui {
class currentDialog;
}

class currentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit currentDialog(QWidget *parent = nullptr);
    ~currentDialog();
public slots:
    void on_Timeout_Slots(void);

private:
    Ui::currentDialog *ui;
    QTimer *timer;
    QTime *time;
};

#endif // CURRENTDIALOG_H

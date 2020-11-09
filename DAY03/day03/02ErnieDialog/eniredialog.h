#ifndef ENIREDIALOG_H
#define ENIREDIALOG_H

#include <QDialog>
#include <QTimer>
namespace Ui {
class EnireDialog;
}

class EnireDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EnireDialog(QWidget *parent = nullptr);
    ~EnireDialog();

private slots:
    void on_StartStopButton_clicked();
    void on_TimeOut_Slots();

private:
    void paintEvent(QPaintEvent *);

private:
    Ui::EnireDialog *ui;
    int m_idex;
    //实例化一个定时器的对象
    QTimer * timer;
};

#endif // ENIREDIALOG_H

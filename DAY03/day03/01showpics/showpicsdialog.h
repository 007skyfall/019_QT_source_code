#ifndef SHOWPICSDIALOG_H
#define SHOWPICSDIALOG_H

#include <QDialog>

namespace Ui {
class ShowPicsDialog;
}

class ShowPicsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowPicsDialog(QWidget *parent = nullptr);
    ~ShowPicsDialog();

private slots:

    void on_downButton_clicked();

    void on_upButton_clicked();

    void on_closeButton_clicked();

private:
    // 绘制事件
    void paintEvent(QPaintEvent *event);


private:
    Ui::ShowPicsDialog *ui;

    int m_idexpics;
};

#endif // SHOWPICSDIALOG_H

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setWebSource(QString context);
    //给Dialog的文本编辑器进行设置文本

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>
#include <QString>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void changeTitleSlot();

    void on_cancelButton_clicked(bool checked);

    void on_submitButton_clicked();

    void setButtonEnable(QString);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

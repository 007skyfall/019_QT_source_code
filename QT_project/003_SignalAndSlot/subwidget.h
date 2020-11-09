#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = 0);

private:
    QPushButton * subButton;

private slots:
    void changeSlot();

signals:
    void mySignal();
};

#endif // SUBWIDGET_H

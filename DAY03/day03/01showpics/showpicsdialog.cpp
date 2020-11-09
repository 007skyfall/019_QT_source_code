#include "showpicsdialog.h"
#include "ui_showpicsdialog.h"
#include <QPainter>
#include <QImage>
#include <QDebug>
ShowPicsDialog::ShowPicsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowPicsDialog)
{
    ui->setupUi(this);
    m_idexpics = 0;
}

ShowPicsDialog::~ShowPicsDialog()
{
    delete ui;
}

void ShowPicsDialog::on_downButton_clicked()
{
    if(m_idexpics <= 0){
        m_idexpics = 20;
    }
    else{
        m_idexpics--;
    }
    qDebug() << m_idexpics;
    update();
}

void ShowPicsDialog::on_upButton_clicked()
{
    if(m_idexpics >= 20)
    {
        m_idexpics = 0;
    }
    else{
        m_idexpics++;
    }
    qDebug() << m_idexpics;
    update();
}

void ShowPicsDialog::on_closeButton_clicked()
{
    close();
}
// 绘制事件处理函数，虚函数，  利用了多态
void ShowPicsDialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // 获取显示的框
    QRect rect = ui->showPicsFrame->rect();
    // 坐标偏移
    rect.translate(ui->showPicsFrame->pos());

    // 获取图片的路径
    QImage image(":/" + QString::number(m_idexpics) + ".jpg");
    // 绘制图片
    painter.drawImage(rect,image);
}

#include "eniredialog.h"
#include "ui_eniredialog.h"
#include <QPainter>
#include <QImage>
#include <QRect>
#include <QDebug>
#include <QRandomGenerator>

EnireDialog::EnireDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnireDialog)
{
    ui->setupUi(this);
    m_idex = 0;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(on_TimeOut_Slots()));
}

EnireDialog::~EnireDialog()
{
    delete ui;
}

void EnireDialog::on_StartStopButton_clicked()
{
    if(ui->StartStopButton->text() == "开始"){
        ui->StartStopButton->setText("停止");
        timer->setInterval(100);
        timer->start();
    }
    else{
        ui->StartStopButton->setText("开始");
        timer->stop();
    }
}
void EnireDialog::on_TimeOut_Slots()
{
    /*
    if(m_idex >= 20)
    {
        m_idex = 0;
    }
    m_idex++;
    */
    QRandomGenerator rand;
    m_idex = rand.global()->bounded(21);

    update();

}
void EnireDialog::paintEvent(QPaintEvent *){
     QPainter painter(this);

    QRect rect = ui->showPictureFrame->rect();
    rect.translate(ui->showPictureFrame->pos());
    QImage image(":/Image/"+QString::number(m_idex)+".jpg");
    painter.drawImage(rect,image);
    QString str = QString::number(m_idex) + "号";
    ui->numEdit->setText(str);
}
















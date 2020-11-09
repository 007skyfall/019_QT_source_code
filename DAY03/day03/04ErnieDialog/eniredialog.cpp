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
    timer1 = new QTimer(this);
    timer1->setInterval(1000);
    timer1->start();
    time = new QTime;

    connect(timer1,SIGNAL(timeout()),
            this,SLOT(on_Currenttime_Slots()));
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
void EnireDialog::on_Currenttime_Slots()
{
    /*
    time->start();
    int hour = time->hour();
    int min = time->minute();
    int sec = time->second();
*/
    QTime time1 = time->currentTime();
    int hour = time1.hour();
    int min = time1.minute();
    int sec = time1.second();

    QString str = QString::number(hour);
    str += ":";
    str += QString::number(min);
    str += ":";
    str += QString::number(sec);
    ui->lcdNumber->display(str);
}















#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{


    ui->setupUi(this);
    this->movie = new QMovie("mario.gif");
    ui->movieLabel->setMovie(this->movie);
    qDebug() << "this movie has " << this->movie->frameCount() << "fps";
    this->movie->start();
    QObject::connect(ui->yesButton,SIGNAL(clicked()),this,SLOT(StartMovieSlot()));
    QObject::connect(ui->noButton,SIGNAL(clicked()),this,SLOT(StopMovieSlot()));
}

about::~about()
{
    delete ui;
}

void about::StartMovieSlot()
{
    this->movie->start(); //开始播放动画
}

void about::StopMovieSlot()
{
    this->movie->stop(); //停止播放动画

}

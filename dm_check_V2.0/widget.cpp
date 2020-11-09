#include "widget.h"
#include "ui_widget.h"
#include "HalconCpp.h"
#include "HDevThread.h"
#include <iostream>
#include <QApplication>
#include <QString>
#include <QPainter>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>

using namespace std;
using namespace HalconCpp;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("2D_CODE_TEST");
    this->setWindowIcon(QIcon("c:/image/logo.png"));
    //退出当前窗口
    connect(ui->quitButton,SIGNAL(clicked()),this,SLOT(quitButtonSlot()));
//    connect(ui->quitButton,SIGNAL(clicked()),this,SLOT(close()));
//    connect(ui->quitButton,&QPushButton::clicked,this,&QWidget::close);
//    connect(ui->quitButton,&QPushButton::clicked,
//            [=]()
//            {
//              this->close();
//            }
//            );
   connect(ui->openButton,SIGNAL(clicked()),this,SLOT(testButtonSlot()));
   quitButtonSlot();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::testButtonSlot()
{
   QString path =  QFileDialog::getOpenFileName(this,"open", "c:/", "image(*.jpg;*.jpeg;*.bmp;*.png)");

   // Local iconic variables
   HObject  ho_Image, ho_SymbolXLDs;
   // Local control variables
   HTuple  hv_DataCodeHandle, hv_ResultHandles, hv_DecodedDataStrings;


   ReadImage(&ho_Image, path.toStdString().data());

   CreateDataCode2dModel("Data Matrix ECC 200", HTuple(), HTuple(), &hv_DataCodeHandle);
   FindDataCode2d(ho_Image, &ho_SymbolXLDs, hv_DataCodeHandle, "train", "all", &hv_ResultHandles,&hv_DecodedDataStrings);

   QPixmap image;
   image.load(path);

   if(hv_DecodedDataStrings.ToString().Text()[0] == '"')
         {
//            qDebug() << "----------->>" << hv_DecodedDataStrings.ToString().Text()[0];

            ui->fileDirLineEdit->setText(path);
            ui->resultLineEdit->setText(hv_DecodedDataStrings.ToString().Text());
            ui->resultLineEdit->setStyleSheet("background-color: rgb(255, 255, 255);font-size:14px;color:blue");
            ui->fileDirLineEdit->setStyleSheet("background-color:rgb(250, 255, 255);font-size:20px;color:blue");



             ui->imageLabel->setPixmap(image.scaledToWidth(300));
             ui->imageLabel->setPixmap(image.scaledToHeight(300));
             ui->imageLabel->pixmap()->toImage();
             ui->imageLabel->show();
            QMessageBox::information(this,"result",hv_DecodedDataStrings.ToString().Text()) ;

         }
         else
         {
//             qDebug() << "----------->>" << hv_DecodedDataStrings.ToString().Text()[0];
             ui->fileDirLineEdit->setText(path);
             ui->resultLineEdit->setStyleSheet("background-color: rgb(255, 0, 0);font-size:14px;color:blue");
             ui->fileDirLineEdit->setStyleSheet("background-color:rgb(250, 0, 0);font-size:20px;color:blue");
             ui->resultLineEdit->setText("not found!");

             ui->imageLabel->setPixmap(image.scaledToWidth(300));
             ui->imageLabel->setPixmap(image.scaledToHeight(300));
             ui->imageLabel->pixmap()->toImage();
             ui->imageLabel->show();

             QMessageBox::critical(this,"result","Not Found!!") ;


         }

}


void Widget::quitButtonSlot()
{
    this->close();
#if 0
        QMessageBox msgBox;
        msgBox.setText("aaa");

        msgBox.setInformativeText(tr("Do you want to save your changes?"));

        msgBox.setDetailedText(tr("Differences here..."));

        msgBox.setStandardButtons(QMessageBox::Save

                                  | QMessageBox::Discard

                                  | QMessageBox::Cancel);

        msgBox.setDefaultButton(QMessageBox::Save);

        int ret = msgBox.exec();

        switch (ret) {

        case QMessageBox::Save:

            qDebug() << "Save document!";

            break;

        case QMessageBox::Discard:

            qDebug() << "Discard changes!";

            break;

        case QMessageBox::Cancel:

            qDebug() << "Close document!";

            break;

        }
#endif

}



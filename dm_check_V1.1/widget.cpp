#include "widget.h"
#include "ui_widget.h"
#include "HalconCpp.h"
#include "HDevThread.h"
#include <iostream>
#include <QApplication>
#include <QString>
#include <QPainter>
#include <QDebug>
#include <QPainter>

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
//    connect(ui->quitButton,SIGNAL(clicked()),this,SLOT(quitButtonSlot()));
//    connect(ui->quitButton,SIGNAL(clicked()),this,SLOT(close()));
//    connect(ui->quitButton,&QPushButton::clicked,this,&QWidget::close);
    connect(ui->quitButton,&QPushButton::clicked,
            [=]()
            {
              this->close();
            }
            );
   connect(ui->openButton,SIGNAL(clicked()),this,SLOT(testButtonSlot()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::testButtonSlot()
{

   static int counter  = 0;
//   char fileName[1024] = {0};
//   QString fileName("c:image/");
//   fileName += QString::number(counter+1);
//   fileName += ".jpg";
   QString fileName = QString("%1%2%3").arg("C:/image/").arg(counter+1,3,10,QLatin1Char('0')).arg(".jpg");


   // Local iconic variables
   HObject  ho_Image, ho_SymbolXLDs;
   // Local control variables
   HTuple  hv_DataCodeHandle, hv_ResultHandles, hv_DecodedDataStrings;
//   sprintf_s(fileName,"%s%03d%s",("c:/image/"), counter + 1, (".jpg"));
   qDebug() << fileName;




   ReadImage(&ho_Image, fileName.toStdString().data());
   CreateDataCode2dModel("Data Matrix ECC 200", HTuple(), HTuple(), &hv_DataCodeHandle);
   FindDataCode2d(ho_Image, &ho_SymbolXLDs, hv_DataCodeHandle, "train", "all", &hv_ResultHandles,&hv_DecodedDataStrings);

//   char lpStr[128] = {0};
//   QString img_id[]   = {"001","002","003","004","005","006","007","008","009","010","011","012","013","014"};
//   QString img_path     = "c:/image/";
//   QString file_format  = ".bmp";

//   QString test = QString("%1%2%3").arg(img_path).arg(img_id[counter]).arg(file_format);
//   sprintf(lpStr, "%s", hv_DecodedDataStrings.ToString().Text());

   QPixmap image;
   image.load(fileName);

   if(hv_DecodedDataStrings.ToString().Text()[0] == '"')
         {
            qDebug() << "----------->>" << hv_DecodedDataStrings.ToString().Text()[0];

            ui->fileDirLineEdit->setText(fileName);
            ui->resultLineEdit->setText(hv_DecodedDataStrings.ToString().Text());
            ui->resultLineEdit->setStyleSheet("background-color: rgb(255, 255, 255);font-size:14px;color:blue");
            ui->fileDirLineEdit->setStyleSheet("background-color:rgb(250, 255, 255);font-size:20px;color:blue");



             ui->imageLabel->setPixmap(image.scaledToWidth(300));
             ui->imageLabel->setPixmap(image.scaledToHeight(300));
             ui->imageLabel->pixmap()->toImage();
             ui->imageLabel->show();

         }
         else
         {
             qDebug() << "----------->>" << hv_DecodedDataStrings.ToString().Text()[0];
             ui->fileDirLineEdit->setText(fileName);
             ui->resultLineEdit->setStyleSheet("background-color: rgb(255, 0, 0);font-size:14px;color:blue");
             ui->fileDirLineEdit->setStyleSheet("background-color:rgb(250, 0, 0);font-size:20px;color:blue");
             ui->resultLineEdit->setText("not found!");

             ui->imageLabel->setPixmap(image.scaledToWidth(300));
             ui->imageLabel->setPixmap(image.scaledToHeight(300));
             ui->imageLabel->pixmap()->toImage();
             ui->imageLabel->show();

         }


           counter++;

           if(counter >= 14)
           {
              counter = 0;
           }

}


void Widget::quitButtonSlot()
{
    this->close();
}



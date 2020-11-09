#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "HalconCpp.h"
#include "HDevThread.h"
#include <iostream>
#include <QApplication>
#include <QString>
#include <QPainter>

using namespace std;
using namespace HalconCpp;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("2D_CODE_TEST");
    this->setWindowIcon(QIcon("c:/image/logo.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{

    char img_file[1024] = {0};
    static int i = 0;//????????
   // Local iconic variables
   HObject  ho_Image, ho_SymbolXLDs;

   // Local control variables
   HTuple  hv_DataCodeHandle, hv_ResultHandles, hv_DecodedDataStrings;

       sprintf_s(img_file,"%s%03d%s",("c:/image/"), i + 1, (".bmp"));
           printf("img_file = %s\n",img_file);

       ReadImage(&ho_Image, img_file);
       CreateDataCode2dModel("Data Matrix ECC 200", HTuple(), HTuple(), &hv_DataCodeHandle);
             FindDataCode2d(ho_Image, &ho_SymbolXLDs, hv_DataCodeHandle, "train", "all", &hv_ResultHandles,
           &hv_DecodedDataStrings);

//     cout << hv_DecodedDataStrings.S() << endl;


      char lpStr[128] = {0};
      QString img_id[]   = {"007","008","003","004","005","006","007","008","009","010","011","012","013","014"};
      QString img_path     = "c:/image/";
      QString file_format  = ".bmp";

      QString test = QString("%1%2%3")
                      .arg(img_path).arg(img_id[i]).arg(file_format);
      sprintf(lpStr, "%s", hv_DecodedDataStrings.ToString().Text());
      QPixmap image;
      image.load(test);
//      cout << "-++" << hv_DecodedDataStrings.ToString().Text() << endl;
      if(lpStr[0] == '"')
      {

         ui->result->setStyleSheet("background-color: rgb(255, 255, 255);font-size:14px;color:blue");
         ui->file_dir->setStyleSheet("background-color:rgb(250, 255, 255);font-size:20px;color:blue");
         ui->result->setText(lpStr);
         ui->file_dir->setText(img_file);


          ui->label->setPixmap(image.scaledToWidth(300));
          ui->label->setPixmap(image.scaledToHeight(300));
          ui->label->pixmap()->toImage();
          ui->label->show();

      }
      else
      {
          ui->result->setStyleSheet("background-color: rgb(255, 0, 0);font-size:14px;color:blue");
          ui->file_dir->setStyleSheet("background-color:rgb(250, 0, 0);font-size:20px;color:blue");
          ui->result->setText("not found!");
          ui->file_dir->setText(img_file);
          ui->label->setPixmap(image.scaledToWidth(300));
          ui->label->setPixmap(image.scaledToHeight(300));
          ui->label->pixmap()->toImage();
          ui->label->show();

      }

      i++;
//      cout << "i = " << i << endl;

      if(i >= sizeof(img_id)/sizeof(img_id[0]))
      {
         i = 0;
      }
}

void MainWindow::on_pushButton_2_pressed()
{
    QApplication* app;
    app->quit();

}

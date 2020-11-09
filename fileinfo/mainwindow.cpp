#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->openButton,SIGNAL(clicked()),this,SLOT(getFileInfoSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::getFileInfoSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open File",QDir::homePath());
    if(fileName.isEmpty())
    {
        QMessageBox::information(this,"Message Error","Open is failed!!");
        return ;
    }
    else
    {
        QFileInfo info(fileName);
        //get file size
        ui->filesizeLineEdit->setText(QString::number(info.size()));

        QDateTime create = info.created();
        ui->createtimeLineEdit->setText(create.toString("yyyy-MM-dd hh:mm:ss"));

        QDateTime lastAccess = info.lastRead();
        ui->lastaccessLineEdit->setText(lastAccess.toString("yyyy-MM-dd hh:mm:ss"));

        if(info.isFile())
        {
            ui->isfileLineEdit->setText("YES!!");
        }
        else
        {
            ui->isfileLineEdit->setText("NO!!");
        }

    }

}

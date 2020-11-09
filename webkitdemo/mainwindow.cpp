#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //实例化进度条
    this->progressbar = new QProgressBar;
    this->initMainPage();
    ui->statusBar->addWidget(this->progressbar);
    QObject::connect(ui->webView,SIGNAL(loadProgress(int)),this->progressbar,SLOT(setValue(int)));
    QObject::connect(ui->webView,SIGNAL(urlChanged(QUrl)),this,SLOT(setUrlSlot(QUrl)));
    //设置窗口标题的信号与槽
    QObject::connect(ui->webView,SIGNAL(urlChanged(QUrl)),this,SLOT(setTitleSlot(QUrl)));
    //设置浏览网页的信号与槽
    QObject::connect(ui->urlLineEdit,SIGNAL(returnPressed()),this,SLOT(browerWebSlot()));
    QObject::connect(ui->forwardButton,SIGNAL(clicked()),this,SLOT(browerWebSlot()));
    //完成后状态栏删除进度条
    QObject::connect(ui->webView,SIGNAL(loadFinished(bool)),this,SLOT(deleteProgressBarSlot(bool)));
    QObject::connect(ui->mainpageAction,SIGNAL(triggered()),this,SLOT(setMainPageSlot()));
    QObject::connect(ui->sourcecodeAction,SIGNAL(triggered()),this,SLOT(sourceCodeSlot()));

//    QObject::connect(ui->forwardButton,SIGNAL(clicked()),this,SLOT(update()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_showButton_clicked()
//{
//     QWebView *view = new QWebView;
//     view->load(QUrl("https://blog.csdn.net/zxy131072"));
//     view->show();
//}

void MainWindow::setUrlSlot(QUrl url)
{
    ui->urlLineEdit->setText(url.toString());

}

void MainWindow::setTitleSlot(QUrl title)
{
//    qDebug() << "aaaa" ;
    this->setWindowTitle(title.toString());
}
void MainWindow::browerWebSlot()
{
   ui->webView->load(QUrl(ui->urlLineEdit->text()));
}

void MainWindow::deleteProgressBarSlot(bool ok)
{
    if(ok)
    {
        delete this->progressbar;
        this->progressbar = NULL;
        this->ui->statusBar->showMessage("Load is finished!",3*1000);

    }
    else
    {
        delete this->progressbar;
        this->progressbar = NULL;
        this->ui->statusBar->showMessage(" ",3*1000);
    }
}

void MainWindow::initMainPage()
{
    QString fileName = "mainpage.ini";
    QFile * file = new QFile;
    file->setFileName(fileName);
    bool ok = file->open(QIODevice::ReadOnly);
    if(ok)
    {
        QTextStream in(file);
        ui->webView->load(QUrl(in.readLine().split("=").at(1)));
        file->close();
        delete file;
        file = NULL;
    }
    else
    {
        QMessageBox::information(this,"Message Error","Init Main Page Error");
        return ;
    }
}

void MainWindow::setMainPageSlot()
{
    QString fileName = "mainpage.ini";
    QFile * file = new QFile;
    file->setFileName(fileName);
    bool ok = file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(file);
        out << "mainpage=" + ui->urlLineEdit->text();
        file->close();
        delete file;
        file = NULL;
        QMessageBox::information(this,"Information","Set Main Page Success!");
        return ;
    }
    else
    {
        qDebug() << "main page error" << file->errorString();
        return ;
    }
}

void MainWindow::sourceCodeSlot()
{
    QString context = ui->webView->page()->currentFrame()->toHtml();
    Dialog  * dialog = new Dialog;
    dialog->setWebSource(context);
    dialog->show();
}

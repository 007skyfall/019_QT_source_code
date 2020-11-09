#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置默认的初始文件名字
    this->setWindowTitle("Untitled ----notepad");
    //新建文件的信号与槽
    QObject::connect(ui->newAction,SIGNAL(triggered()),this,SLOT(newFileSlot()));
    //打开文件的信号与槽
    QObject::connect(ui->openAction,SIGNAL(triggered()),this,SLOT(openFileSlot()));
    //保存文件的信号与槽
    QObject::connect(ui->saveAction,SIGNAL(triggered()),this,SLOT(saveFileSlot()));
    //另存为文件的信号与槽
    QObject::connect(ui->saveAsAction,SIGNAL(triggered()),this,SLOT(saveAsFileSlot()));
    //退出界面的信号与槽
    QObject::connect(ui->quitAction,SIGNAL(triggered()),this,SLOT(close()));

    //edit menu
    //重做
    QObject::connect(ui->redoAction,SIGNAL(triggered()),ui->textEdit,SLOT(redo()));
    //撤销
    QObject::connect(ui->undoAction,SIGNAL(triggered()),ui->textEdit,SLOT(undo()));
    //复制
    QObject::connect(ui->copyAction,SIGNAL(triggered()),ui->textEdit,SLOT(copy()));
    //粘贴
    QObject::connect(ui->pasteAction,SIGNAL(triggered()),ui->textEdit,SLOT(paste()));
    //全选
    QObject::connect(ui->selectAllAction,SIGNAL(triggered()),ui->textEdit,SLOT(selectAll()));
    //剪切
    QObject::connect(ui->cutAction,SIGNAL(triggered()),ui->textEdit,SLOT(cut()));

    //设置字体
    QObject::connect(ui->fontAction,SIGNAL(triggered()),this,SLOT(setFontSlot()));
    //设置颜色
    QObject::connect(ui->colorAction,SIGNAL(triggered()),this,SLOT(setColorSlot()));

    //获取时间
    QObject::connect(ui->datetimeAction,SIGNAL(triggered()),this,SLOT(currentDateTime()));

    //帮助
    //关于Qt
    this->connect(ui->aboutQtAction,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    //关于官网
    this->connect(ui->aboutOfficialAction,SIGNAL(triggered()),this,SLOT(aboutWebsiteSlot()));

    //关于软件
    this->connect(ui->aboutSoftwareAction,SIGNAL(triggered()),this,SLOT(aboutSoftwareSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFileSlot()
{
    //如果当前文档的内容已经更改了
    if(ui->textEdit->document()->isEmpty())
    {
//        qDebug() << "current file is not modified!";
    }
    else
    {
        ui->textEdit->clear();
       this->setWindowTitle("Untitled.txt");
//        qDebug() << "current file is modified!";
    }
}

void MainWindow::openFileSlot()
{
    //get the filename
    QString fileName = QFileDialog::getOpenFileName(this,"Open File",QDir::currentPath());
    qDebug() << "file name is " << fileName;
    if(fileName.isEmpty())
    {
       // QMessageBox::information(this,"Error Msg","Plz select a file");
        return ;
    }
    QFile * file = new QFile;
    file->setFileName(fileName);
    //open the file as readonly mode
    bool ok = file->open(QIODevice::ReadOnly);
    if(ok)
    {
        //文件与文本流相关
        QTextStream in(file);
        ui->textEdit->setText(in.readAll()); // read all context form the file
        file->close();
        delete file;
    }
    else
    {
        QMessageBox::information(this,"Error Msg","File open Error" + file->errorString());
        return ;
    }
}

void MainWindow::saveFileSlot()
{
    if(saveFileName.isEmpty())
    {
        this->saveAsFileSlot();
    }

    else
    {
        QFile * file = new QFile;
        file->setFileName(saveFileName);
        bool ok = file->open(QIODevice::WriteOnly);
        if(ok)
        {
            QTextStream out(file);
            out<<ui->textEdit->toPlainText();//取出textEdit当中的纯文本
            file->close();
            delete file;

        }

    }
}
void MainWindow::saveAsFileSlot()
{
    //get save filename
    QString saveFileName = QFileDialog::getSaveFileName(this,"Save File",QDir::currentPath());
    if(saveFileName.isEmpty())
    {
        QMessageBox::information(this,"Error Msg","Plz select a File");
        return ;
    }
    else
    {
        QFile * file = new QFile;
        file->setFileName(saveFileName);
        this->setWindowTitle(saveFileName + "----------notepad");
        bool ok = file->open(QIODevice::WriteOnly);
        if(ok)
        {
            QTextStream out(file);
            out<<ui->textEdit->toPlainText();//取出textEdit当中的纯文本
            file->close();
            delete file;

        }
        else
        {
            QMessageBox::information(this,"Error Msg","Save File Error");
            return ;
        }
    }
}

void MainWindow::printFileSlot()
{
    //QPrintDialog static member call
}

void MainWindow::setFontSlot()
{
    //get user selected font
#if 0
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Times", 12), this);
    if (ok) {
        // font is set to the font the user selected
    } else {
        // the user canceled the dialog; font is set to the initial
        // value, in this case Times, 12.
    }
#endif
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
    else
    {
        QMessageBox::information(this,"Error Font","Error set Font!!");
        return ;
    }
}


void MainWindow::setColorSlot()
{
#if 0
    const QColorDialog::ColorDialogOptions options = QFlag(colorDialogOptionsWidget->value());
       const QColor color = QColorDialog::getColor(Qt::green, this, "Select Color", options);

       if (color.isValid()) {
           colorLabel->setText(color.name());
           colorLabel->setPalette(QPalette(color));
           colorLabel->setAutoFillBackground(true);
       }

#endif

       QColor color = QColorDialog::getColor(Qt::red,this);
       if(color.isValid())
       {
           ui->textEdit->setTextColor(color);
       }
       else
       {
           QMessageBox::information(this,"Error Color","Error Set Color");
           return ;
       }
}

void MainWindow::currentDateTime()
{
    QDateTime current = QDateTime::currentDateTime();
    QString time = current.toString("yyyy-M-dd hh:mm:ss");
    ui->textEdit->append(time);
}

void MainWindow::aboutWebsiteSlot()
{
    QDesktopServices::openUrl(QUrl("https://www.baidu.com"));

}

void MainWindow::aboutSoftwareSlot()
{
    about * dialog = new about;
    dialog->show();//unmodal dialog
    //dialog.exec(); modal dialog

}

void MainWindow::closeEvent(QCloseEvent *event)
{
//    event->ignore();//该程序无法关闭，需要强制停止
    event->accept();
    if(ui->textEdit->document()->isModified())
    {

        QMessageBox msgBox;

        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret) {
          case QMessageBox::Save:
              // Save was clicked
              this->saveFileSlot();
              break;
          case QMessageBox::Discard:
              // Don't Save was clicked
            event->accept();
              break;
          case QMessageBox::Cancel:
              // Cancel was clicked
            event->ignore();
              break;
          default:
              // should never be reached
              break;
        }


    }
    else
    {
        event->accept();
    }
}

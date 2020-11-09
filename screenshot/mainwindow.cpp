#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->saveScreenButton,SIGNAL(clicked()),this,SLOT(savePictureSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newScreenButton_clicked()
{
    if(ui->hideCheckBox->isChecked())
    {
        this->hide();
        this->timer = new QTimer;
        QObject::connect(this->timer,SIGNAL(timeout()),this,SLOT(shotCsreenSlot()));
//        this->timer->start(ui->timeSpinBox->value()*1000);
        this->timer->start(1000/5);
    }
    else
    {
        qApp->beep();
        this->pixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
        ui->screenLabel->setPixmap(this->pixmap.scaled(ui->screenLabel->size()));
        this->show();

    }
}



void MainWindow::shotCsreenSlot()
{
    this->pixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
    ui->screenLabel->setPixmap(this->pixmap.scaled(ui->screenLabel->size()));
    QClipboard * clipboard = QApplication::clipboard();
//    QString orignalText = clipboard->text();
//    qDebug() << "current clipboard is " << orignalText;
    clipboard->setPixmap(this->pixmap);
    this->show();
    this->timer->stop();
}


void MainWindow::savePictureSlot()
{
//   QString fileName = QFileDialog::getSaveFileName(this,"Save File",QDesktopServices::storageLocation(QDesktopServices::PicturesLocation) )
     QString fileName = QFileDialog::getSaveFileName(this,"Save File",QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) );
     this->pixmap.save(fileName);

}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu * menu = new QMenu(this);
    QAction * action = new QAction(this);
    QAction * processAction = new QAction(this);
    QAction * calcAction = new QAction(this);

    QObject::connect(action,SIGNAL(triggered()),this,SLOT(savePictureSlot()));
    QObject::connect(processAction,SIGNAL(triggered()),this,SLOT(startNotepadSlot()));
    QObject::connect(calcAction,SIGNAL(triggered()),this,SLOT(startCalcSlot()));
    action->setText("Save As");
    processAction->setText("start netepad");
    calcAction->setText("start calculator");

    menu->addAction(action);
    menu->addSeparator();
    menu->addAction(processAction);
    menu->addSeparator();
    menu->addAction(calcAction);

    menu->exec(QCursor::pos());

}

void MainWindow::startNotepadSlot()
{
    QProcess * process = new QProcess;
    process->start("notepad");

}

void MainWindow::startCalcSlot()
{
    QProcess * process = new QProcess;
    process->start("calc");
}

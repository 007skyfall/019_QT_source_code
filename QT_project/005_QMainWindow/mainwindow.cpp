#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(600,600);
   QMenuBar * mBar = menuBar();
   QMenu * pFile = mBar->addMenu("File");
   QAction * pNew = pFile->addAction("new");
   this->connect(pNew,&QAction::triggered,
                 [=]()
                       {
                           qDebug() << "new is pressed!";
                       }

                );
    pFile->addSeparator();
    QAction * pOpen = pFile->addAction("open");
    QObject::connect(pOpen,SIGNAL(triggered()),this,SLOT(openTriggerSlot()));

    QToolBar * toolBar = addToolBar("toolBar");
    toolBar->addAction(pNew);
    toolBar->addSeparator();
    toolBar->addAction(pOpen);
    toolBar->addSeparator();

    QStatusBar * mystatusBar = statusBar();
    QLabel * mylabel = new QLabel(this);
    mylabel->setText("Normal File");
    mystatusBar->addWidget(mylabel);
    mystatusBar->addWidget(new QLabel("22222",this));

    mystatusBar->addPermanentWidget(new QLabel("33333",this));

    QTextEdit * mytextedit = new QTextEdit(this);
    this->setCentralWidget(mytextedit);
    QDockWidget * mydock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,mydock);
    QTextEdit * dockText = new QTextEdit(this);
    dockText->resize(10,10);
    mydock->setWidget(dockText);



}

MainWindow::~MainWindow()
{

}

void MainWindow::openTriggerSlot()
{
   openButton = new QPushButton();
   openButton->setText("open");
   openButton->show();

}

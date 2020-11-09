#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(500,500);
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("dialog");
    QAction *p1 = menu->addAction("motai dialog");
    connect(p1, &QAction::triggered,
            [=]()
            {
                QDialog dlg;
                dlg.exec();
                qDebug() << "111111";
            }

            );

    QAction *p2 = menu->addAction("no motai dialog");
    connect(p2, &QAction::triggered,
            [=]()
            {

                 QDialog *p = new QDialog;
                 p->setAttribute(Qt::WA_DeleteOnClose);
                 p->show();
            }

            );

    QAction *p3 = menu->addAction("about Dialog");
    connect(p3, &QAction::triggered,
            [=]()
            {
               QMessageBox::about(this, "about", "about qt");
            }

            );

    QAction *p4 = menu->addAction("question");
    connect(p4, &QAction::triggered,
            [=]()
            {
               int ret = QMessageBox::question(this,
                           "question", "Are you ok?",
                              QMessageBox::Ok |
                                QMessageBox::Cancel

                                               );
                switch(ret)
                {
                case QMessageBox::Ok:
                    qDebug() << "i am ok";
                    break;
                case QMessageBox::Cancel:
                    qDebug() << "i am bad";
                    break;
                default:
                    break;
                }
            }

            );


    QAction *p5 = menu->addAction("file Dialog");
    connect(p5, &QAction::triggered,
            [=]()
            {
               QString path = QFileDialog::getOpenFileName(
                           this,
                           "OPEN",
                           "../",
             "souce(*.cpp *.h);;Text(*.txt);;all(*.*)"
                           );
               qDebug() << path;
            }

            );


}

MainWindow::~MainWindow()
{

}

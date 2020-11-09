#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFileInfo>
#include <QDir>
#include <QStringList>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int a = 10;
cout << a << endl;

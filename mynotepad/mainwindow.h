#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QDateTime>
#include <QUrl>
#include <QDesktopServices> //用于访问桌面服务的类
#include "about.h"
#include <QCloseEvent> //当前程序需要关闭的时候，所处理的内容

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString saveFileName;
private slots:
    void newFileSlot();
    void openFileSlot();//打开一个已经存在的文件
    void saveFileSlot();//保存文件到磁盘
    void saveAsFileSlot();
    void printFileSlot();
    void setFontSlot();//设置字体的槽函数
    void setColorSlot();//设置文本颜色的槽
    void currentDateTime();//获取当前的系统时间并采取一定的格式打印出来
    void aboutWebsiteSlot();//关于官网，使用默认的浏览器打开
    void aboutSoftwareSlot();//关于软件，弹出一个新的对话框

protected:
    void closeEvent(QCloseEvent *);


};

#endif // MAINWINDOW_H

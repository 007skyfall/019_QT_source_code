#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebKit/QtWebKit>
#include <QUrl>
#include <QWebView>
#include <QtDebug>
#include <QProgressBar> //使用进度条
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QWebFrame>
#include <QDialog>

#include "dialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void initMainPage();//初始化主页面
    ~MainWindow();

private slots:
//    void on_showButton_clicked();//启动一个浏览器
    void setUrlSlot(QUrl url);
    void setTitleSlot(QUrl title);
    void browerWebSlot();
    void deleteProgressBarSlot(bool ok);
    void setMainPageSlot();
    void sourceCodeSlot();


private:
    Ui::MainWindow *ui;
    QProgressBar * progressbar;
};

#endif // MAINWINDOW_H

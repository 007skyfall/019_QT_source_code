#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QMessageBox>
#include <QTimer>
#include <QPixmap>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QClipboard>
#include <QtDebug>
#include <QContextMenuEvent>
#include <QMenu>
#include <QAction>
#include <QProcess>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void on_newScreenButton_clicked();
    void shotCsreenSlot();
    void savePictureSlot(); //保存屏幕截图的槽函数
    void startNotepadSlot();
    void startCalcSlot();

private:
    Ui::MainWindow *ui;
    QTimer * timer;
    QPixmap pixmap;
};

#endif // MAINWINDOW_H

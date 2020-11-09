#ifndef STUENTDIALOG_H
#define STUENTDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class StuentDialog;
}

class StuentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StuentDialog(QWidget *parent = nullptr);
    ~StuentDialog();

private slots:
    void on_sortButton_clicked();

    void on_insertButton_clicked();

    void on_updateButton_clicked();

    void on_deleteButton_clicked();

    void on_selectButton_clicked();
private:
    // 创建并打开数据哭文件
    void createDB(void);
    // 创建数据哭的表
    void createTable(void);
    // 查询函数
    void selectTable(void);
private:
    Ui::StuentDialog *ui;
    QSqlDatabase *db;
    QSqlQueryModel *model;
};

#endif // STUENTDIALOG_H

#include "stuentdialog.h"
#include "ui_stuentdialog.h"

StuentDialog::StuentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StuentDialog)
{
    ui->setupUi(this);
    db = new QSqlDatabase;
    model = new QSqlQueryModel(this);
    createDB();
    createTable();
    selectTable();
}

StuentDialog::~StuentDialog()
{
    delete ui;
}

void StuentDialog::createDB(void)
{   // 添加QSQLITE数据库
    *db = QSqlDatabase::addDatabase("QSQLITE");
    // 设置要连接的数据库名字
    db->setDatabaseName("student.db");
    // 打开数据库
    bool ok = db->open();
    if(ok == false)
    {
        QMessageBox::critical(this,"Error",
                              db->lastError().text());
        return ;
    }
}
void StuentDialog::createTable(void)
{
    QSqlQuery query1;
    QString sqlstr = QString("select count(*) from "
                             "sqlite_master where type='table' and name='student'");
    query1.exec(sqlstr);
    query1.next();
    bool ok = query1.value(0).toInt();
    qDebug() <<  ok;

    if(ok == false)
    {
        QSqlQuery query;

        // 准备SQL语句
        query.prepare("CREATE TABLE student("
                      "id INT PRIMARY KEY NOT NULL,"
                      "name TEXT NOT NULL,"
                      "score REAL NOT NULL)");
        // 执行SQL语句
        bool ok = query.exec();

        if(ok == false)
        {
            QMessageBox::critical(this,"Error create table",
                                  query.lastError().text());
            return ;
        }
    }
    else {
        qDebug() << "这个表已经创建";
    }
}

void StuentDialog::on_sortButton_clicked()
{
    QString valuetext = ui->valueBox->currentText();
    QString sorttext = ui->sortBox->currentText();
    QString value, sort;
    if(valuetext == "学号")
    {
        value = "id";
    }else {
        value = "score";
    }
    if(sorttext == "升序")
    {
        sort = "ASC";
    }
    else
    {
        sort = "DESC";
    }
    QString sortstr =
            QString("SELECT * FROM student "
                "ORDER BY %1 %2").
                arg(value).arg(sort);
    qDebug() << sortstr;
    model->setQuery(sortstr);
    ui->tableView->setModel(model);
}

void StuentDialog::on_insertButton_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO student (id, name,score)"
                  "VALUES(:id,:name,:score)");
    int id = ui->idEdit->text().toInt();
    QString name = ui->nameEdit->text();
    double score = ui->scoreEdit->text().toDouble();
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    query.bindValue(":score",score);
    query.exec();
    selectTable();
}
void StuentDialog::selectTable(void){
    // 构建和执行sql语句
    model->setQuery("SELECT * FROM student");
    ui->tableView->setModel(model);
}
void StuentDialog::on_updateButton_clicked()
{
    int id = ui->idEdit->text().toInt();
    double score = ui->scoreEdit->text().toDouble();
    QString updatestr =
            QString("UPDATE student SET score = %1 "
                    "WHERE id = %2").arg(score).arg(id);
    qDebug() << updatestr;
    model->setQuery(updatestr);
    selectTable();
}

void StuentDialog::on_deleteButton_clicked()
{
    int id = ui->idEdit->text().toInt();
    QString deletestr =
            QString("DELETE FROM student "
                    "WHERE id = %1").arg(id);
    qDebug() << deletestr;
    model->setQuery(deletestr);
    selectTable();
}

void StuentDialog::on_selectButton_clicked()
{
    selectTable();

}











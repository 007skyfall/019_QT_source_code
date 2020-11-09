#include "logindialog.h"
#include "ui_logindialog.h"
#include "stuentdialog.h"

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)
            ->setText("确认");
    ui->buttonBox->button(QDialogButtonBox::Cancel)
            ->setText("取消");
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_buttonBox_accepted()
{

    // 判定账号和密码是否一致
    if(ui->idEdit->text().toInt() == 10001 &&
            ui->nameEdit->text() == "lvbu" &&
            ui->passwdEdit->text() == "123456")
    {
        // 打印信息的类
        qDebug("登录成功");
        accept();
    }
    else
    {
        // 设置错误提示框
        QMessageBox msgBox(QMessageBox::Critical,
                windowTitle(),
                "账号和密码错误请重新输入！",
                QMessageBox::Ok,
                this);
        msgBox.exec();  // 进入阻塞状态

    }
}

void loginDialog::on_buttonBox_rejected()
{
    // 设置取消登录提示框
        QMessageBox msgBox(QMessageBox::Critical,
                windowTitle(),
                "你真的要退出吗",
                QMessageBox::No|QMessageBox::Yes,
                this);
    if(msgBox.exec() == QMessageBox::Yes){
        close();
    }
}

void loginDialog::on_pushButton_clicked()
{
    StuentDialog  dialog;
    dialog.show();
    dialog.exec();
}

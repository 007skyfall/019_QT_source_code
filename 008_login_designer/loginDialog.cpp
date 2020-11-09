#include "loginDialog.h"
#include <QMessageBox>
#include <QDebug>
LoginDialog::LoginDialog(void):ui(new Ui::LoginDialog){
	ui->setupUi(this);
	connect(ui->buttonBox,SIGNAL(accepted()),
			this,SLOT(acceptedSlot()));
	connect(ui->buttonBox,SIGNAL(rejected()),
			this,SLOT(rejectedSlot()));
}

LoginDialog::~LoginDialog(void)
{
	delete ui;
}
// OK按钮的槽函数
void LoginDialog::acceptedSlot(void)
{
	// 判定账号和密码是否一致
	if(ui->userNameEdit->text() == "lvbu"&&
			ui->passwdEdit->text() == "123456")
	{
		// 打印信息的类
		qDebug("登录成功");
		close();
	}
	else
	{
		// 设置错误提示框
		QMessageBox msgBox(QMessageBox::Critical,
				windowTitle(),
				"账号和密码错误，请重新输入！",
				QMessageBox::Ok,
				this);
		msgBox.exec();  // 进入阻塞状态
	
	}
}
// cancel按钮的槽函数
void LoginDialog::rejectedSlot(void)
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

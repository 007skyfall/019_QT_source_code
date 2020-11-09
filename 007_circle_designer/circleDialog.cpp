#include "circleDialog.h"
CircleDialog::CircleDialog():ui(new Ui::CircleDialog)
{
	ui->setupUi(this);
	connect(ui->equalButton,SIGNAL(clicked()),
			this,SLOT(equalSlot()));
	connect(ui->clearButton,SIGNAL(clicked()),
			this,SLOT(clearSlot()));
	connect(ui->rEdit,SIGNAL(textChanged(const QString&)),
			this,SLOT(enableSlot()));

}

CircleDialog::~CircleDialog()
{
	delete ui;
}
void CircleDialog::equalSlot(void){
	//获取redit中的内容，返回值是一个字符串
	QString str = ui->rEdit->text();  
	// 将字符串转换为double类型
	double res = str.toDouble() * str.toDouble() * 3.14;
	//number()：将数字转换为字符串
	str = QString::number(res);
	//设置edit中显示的内筒
	ui->valueEdit->setText(str);

}
void CircleDialog::clearSlot(void){
	//清除Edit中的内容
	ui->rEdit->clear();
	ui->valueEdit->clear();
	ui->equalButton->setEnabled(false);
}
void CircleDialog::enableSlot(void){
	
	ui->equalButton->setEnabled(true);

}

#include "circle.h"
#include <QFont>
#include <QDoubleValidator>//指定为double类型数据

Circle::Circle(void){
	
	QFont ft;
    ft.setPointSize(18);  // 设置字体
	resize(1000,200);
	setWindowTitle("圆的面积计算公式");

	rLabel = new QLabel("半径",this);
	rLabel->move(50,50);
	rLabel->resize(100,50);
	rLabel->setFont(ft);

	rEdit = new QLineEdit(this);
	rEdit->move(50,100);
	rEdit->resize(200,50);
	rEdit->setFont(ft);
	// 设置rEdit只能输入double类型的数字
	rEdit->setValidator(new QDoubleValidator);

	equalButton = new QPushButton("=",this);
	equalButton->move(300,100);
	equalButton->resize(100,50);
	equalButton->setFont(ft);
    // 等号初始化为不可使用
	equalButton->setEnabled(false);

	valueLabel = new QLabel("计算结果",this);
	valueLabel->move(450,50);
	valueLabel->resize(200,50);
	valueLabel->setFont(ft);

	valueEdit = new QLineEdit(this);
	valueEdit->move(450,100);
	valueEdit->resize(200,50);
	valueEdit->setFont(ft);
	// 设置为只读
	valueEdit->setReadOnly(true);

	clearButton = new QPushButton("Clear",this);
	clearButton->move(700,100);
	clearButton->resize(100,50);
	clearButton->setFont(ft);

	connect(equalButton,SIGNAL(clicked()),
			this,SLOT(equalSlot()));
	connect(clearButton,SIGNAL(clicked()),
			this,SLOT(clearSlot()));
	connect(rEdit,SIGNAL(textChanged(const QString&)),
			this,SLOT(enableSlot()));
}
void Circle::equalSlot(void){
	//获取redit中的内容，返回值是一个字符串
	QString str = rEdit->text();  
	// 将字符串转换为double类型
	double res = str.toDouble() * str.toDouble() * 3.14;
	//number()：将数字转换为字符串
	str = QString::number(res);
    //设置edit中显示的内容
	valueEdit->setText(str);

}
void Circle::clearSlot(void){
	//清除Edit中的内容
	rEdit->clear();
	valueEdit->clear();
	equalButton->setEnabled(false);
}
void Circle::enableSlot(void){
	
	equalButton->setEnabled(true);

}
	



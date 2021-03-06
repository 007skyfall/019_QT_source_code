复习：

父类  子类
基类  派生类

1）应用程序框架
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	//我们写的代码
    
    return a.exec();
}

2)项目文件 .pro
QT += widgets
QT += network
QT += sql

CONFIG += C++11 #Lambda

3）自定义类中构造函数里实现
QMainWindow
QWidget
QDialog

MyWdiget w;
w.show();

类的成员函数有个特殊指针，this
谁（哪个对象）调用这个成员函数，this就指向这个对象
this可以操作类型任意成员

4）信号和槽
信号触发了，调用指定的槽函数
connect(sender, &Sender::pressed, receiver, &Receiver::slot);

自定义信号：
函数的声明，只需声明，无需定义
无返回值，但是可以有参数
signals:
	void mySignal(int);
	
信号的使用：	
	emit mySignal(250);
	
自定义的槽：
类中任意成员函数，全局函数，静态函数， Lambda表达式
槽函数没有返回值，槽函数的参数和信号的参数要一一对应‘
void mySignal();
void mySignal(int, QString);
void mySlot(int, QString);

void (MyWdiget::*test)(int, QString) = &MyWdiget::mySignal;
connect(&win, test, );


//项目文件： CONFIG += C++11
connect(b, &QPushButton::pressed, 
[=]()
{
	
}
);

5）坐标系统
相对于屏幕，父窗口

1080p
1920 * 1080

6）内存回收
1)QObject
2)指定父对象

7)QMainWindow
菜单栏
工具栏
状态栏
核心控件
浮动窗口

8)对话框
模态对话框 dlg.exec();
非模态对话框 dlg.show();
标准对话框
QMessageBox::question();
QMessageBox::about();
QMessageBox::information();
QMessageBox::waring();

文件对话框 QFileDialog
QFileDialog::get

颜色对话框 QColorDialog
QColorDialog::getColor();

字体对话框：QFontDialog
QFontDialog::getFont()

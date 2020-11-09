#include <QApplication>
#include <QLabel>

int main(int argc, char** argv)
{
	// QApplication后台管理类
	QApplication app(argc,argv);
	// 实例化一个标签的对象，并且显示内容
    QLabel label("Hello,QT!");
    label.setGeometry(500,500,0,0);
    // 将标签显示出来
	label.show();


	// 进入事件循环，防止QT程序退出
	return app.exec();
}

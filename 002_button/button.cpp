#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc, char** argv)
{
	// QApplication后台管理类
	QApplication app(argc,argv);
	// 实例化一个标签的对象，并且显示内容
    QLabel label("Hello,QT!");
	// 将标签显示出来
	label.show();
    QPushButton button("Exit");
	button.resize(200,50);
	button.show();
	// 信号和槽 
	
//    QObject::connect(&button,SIGNAL(clicked()),
//            &label,SLOT(close()));

    QObject::connect(&button,SIGNAL(clicked()),
            &app,SLOT(closeAllWindows()));

	// 进入事件循环，防止QT程序退出
	return app.exec();
}

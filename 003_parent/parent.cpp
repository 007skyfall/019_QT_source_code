#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QDialog>

int main(int argc, char **argv)
{
	QApplication app(argc,argv);
	QDialog dialog;
	dialog.resize(500,300);

    QPushButton button("Exit",&dialog);
	button.move(50,150);
    QLabel label("Hello,QT!",&dialog);
	label.move(50,50);
	
	dialog.show();

	QObject::connect(&button,SIGNAL(clicked()),
			&dialog,SLOT(close()));
	
	return app.exec();
}

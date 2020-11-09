#include <QApplication>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QMainWindow>

int main(int argc, char **argv)
{
	QApplication app(argc,argv);
	QMainWindow parent;
	parent.resize(300,300);
	parent.setWindowTitle("选值框");

	QSlider slider(Qt::Horizontal,&parent);
	slider.setRange(0,100);
	slider.move(50,50);
	slider.setValue(50);

	QSpinBox spinbox(&parent);
	spinbox.setRange(0,100);
	spinbox.move(50,100);
	spinbox.setValue(50);

	QPushButton button("close",&parent);
	button.move(50,150);
    button.resize(80,20);

	parent.show();

	QObject::connect(&slider,SIGNAL(valueChanged(int)),
			&spinbox,SLOT(setValue(int)));
	QObject::connect(&spinbox,SIGNAL(valueChanged(int)),
			&slider,SLOT(setValue(int)));

	QObject::connect(&button,SIGNAL(clicked()),
			&parent,SLOT(close()));

	return app.exec();
}

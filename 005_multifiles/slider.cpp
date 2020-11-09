#include "slider.h"

SliderDialog::SliderDialog(void){

	resize(300,300);
	setWindowTitle("选值框");

	slider = new QSlider(Qt::Horizontal,this);
	slider->setRange(0,100);
	slider->move(50,50);
	slider->setValue(50);

	spinbox = new QSpinBox(this);
	spinbox->setRange(0,100);
	spinbox->move(50,100);
	spinbox->setValue(50);

	button = new QPushButton("close",this);
	button->move(50,150);
	button->resize(150,50);

	connect(slider,SIGNAL(valueChanged(int)),
			spinbox,SLOT(setValue(int)));
	connect(spinbox,SIGNAL(valueChanged(int)),
			slider,SLOT(setValue(int)));

	connect(button,SIGNAL(clicked()),
			this,SLOT(close()));

}

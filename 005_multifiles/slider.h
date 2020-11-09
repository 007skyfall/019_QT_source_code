#ifndef __SLIDER_H__
#define __SLIDER_H__

#include <QApplication>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QMainWindow>
#include <QDialog>

class SliderDialog:public QDialog{
	public:
		// 构造函数
		SliderDialog(void);
	private:
		QSlider *slider;
		QSpinBox *spinbox;
		QPushButton *button;
};

#endif //__SLIDER_H__

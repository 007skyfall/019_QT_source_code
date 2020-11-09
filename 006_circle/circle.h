#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>

class Circle:public QDialog{
	Q_OBJECT
	public:
	Circle(void);
	public slots:
		void equalSlot(void);
		void clearSlot(void);
		void enableSlot(void);


	private:
	QLineEdit* rEdit;
	QLineEdit* valueEdit;
	QPushButton* equalButton;
	QPushButton* clearButton;
	QLabel* rLabel;
	QLabel* valueLabel;
};

#endif //__CIRCLE_H__

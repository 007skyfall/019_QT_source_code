#ifndef __CIRCLEDIALOG__H__
#define __CIRCLEDIALOG__H__
#include "ui_circleDialog.h"

class CircleDialog:public QDialog{
	Q_OBJECT
	public:
		CircleDialog(void);
		~CircleDialog(void);
	public slots:
		void equalSlot(void);
		void clearSlot(void);
		void enableSlot(void);
		
	private:
		Ui::CircleDialog *ui;
};


#endif  //__CIRCLEDIALOG__H__

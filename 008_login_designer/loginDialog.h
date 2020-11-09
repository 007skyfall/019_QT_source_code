#ifndef __LOGINDIALOG_H__
#define __LOGINDIALOG_H__

#include "ui_LoginDialog.h"

class LoginDialog:public QDialog{
	Q_OBJECT
	public:
		LoginDialog(void);
		~LoginDialog(void);

	public slots:
		// OK按钮的槽函数
		void acceptedSlot(void);
		// cancel按钮的槽函数
		void rejectedSlot(void);
	private:
		Ui::LoginDialog * ui;


};


#endif  //__LOGINDIALOG_H__

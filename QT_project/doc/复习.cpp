��ϰ��

����  ����
����  ������

1��Ӧ�ó�����
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	//����д�Ĵ���
    
    return a.exec();
}

2)��Ŀ�ļ� .pro
QT += widgets
QT += network
QT += sql

CONFIG += C++11 #Lambda

3���Զ������й��캯����ʵ��
QMainWindow
QWidget
QDialog

MyWdiget w;
w.show();

��ĳ�Ա�����и�����ָ�룬this
˭���ĸ����󣩵��������Ա������this��ָ���������
this���Բ������������Ա

4���źźͲ�
�źŴ����ˣ�����ָ���Ĳۺ���
connect(sender, &Sender::pressed, receiver, &Receiver::slot);

�Զ����źţ�
������������ֻ�����������趨��
�޷���ֵ�����ǿ����в���
signals:
	void mySignal(int);
	
�źŵ�ʹ�ã�	
	emit mySignal(250);
	
�Զ���Ĳۣ�
���������Ա������ȫ�ֺ�������̬������ Lambda���ʽ
�ۺ���û�з���ֵ���ۺ����Ĳ������źŵĲ���Ҫһһ��Ӧ��
void mySignal();
void mySignal(int, QString);
void mySlot(int, QString);

void (MyWdiget::*test)(int, QString) = &MyWdiget::mySignal;
connect(&win, test, );


//��Ŀ�ļ��� CONFIG += C++11
connect(b, &QPushButton::pressed, 
[=]()
{
	
}
);

5������ϵͳ
�������Ļ��������

1080p
1920 * 1080

6���ڴ����
1)QObject
2)ָ��������

7)QMainWindow
�˵���
������
״̬��
���Ŀؼ�
��������

8)�Ի���
ģ̬�Ի��� dlg.exec();
��ģ̬�Ի��� dlg.show();
��׼�Ի���
QMessageBox::question();
QMessageBox::about();
QMessageBox::information();
QMessageBox::waring();

�ļ��Ի��� QFileDialog
QFileDialog::get

��ɫ�Ի��� QColorDialog
QColorDialog::getColor();

����Ի���QFontDialog
QFontDialog::getFont()

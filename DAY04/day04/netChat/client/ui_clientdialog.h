/********************************************************************************
** Form generated from reading UI file 'clientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTDIALOG_H
#define UI_CLIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ClientDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *sendMessageEdit;
    QPushButton *sendMessageButton;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *serverIpEdit;
    QLabel *label_2;
    QLineEdit *serverPortEdit;
    QLabel *label_3;
    QLineEdit *clientNameEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *startButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *ClientDialog)
    {
        if (ClientDialog->objectName().isEmpty())
            ClientDialog->setObjectName(QString::fromUtf8("ClientDialog"));
        ClientDialog->resize(613, 564);
        QFont font;
        font.setPointSize(24);
        ClientDialog->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(ClientDialog);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(ClientDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sendMessageEdit = new QLineEdit(ClientDialog);
        sendMessageEdit->setObjectName(QString::fromUtf8("sendMessageEdit"));

        horizontalLayout->addWidget(sendMessageEdit);

        sendMessageButton = new QPushButton(ClientDialog);
        sendMessageButton->setObjectName(QString::fromUtf8("sendMessageButton"));

        horizontalLayout->addWidget(sendMessageButton);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ClientDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        serverIpEdit = new QLineEdit(ClientDialog);
        serverIpEdit->setObjectName(QString::fromUtf8("serverIpEdit"));

        gridLayout->addWidget(serverIpEdit, 0, 1, 1, 1);

        label_2 = new QLabel(ClientDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        serverPortEdit = new QLineEdit(ClientDialog);
        serverPortEdit->setObjectName(QString::fromUtf8("serverPortEdit"));

        gridLayout->addWidget(serverPortEdit, 1, 1, 1, 1);

        label_3 = new QLabel(ClientDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        clientNameEdit = new QLineEdit(ClientDialog);
        clientNameEdit->setObjectName(QString::fromUtf8("clientNameEdit"));

        gridLayout->addWidget(clientNameEdit, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        startButton = new QPushButton(ClientDialog);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        horizontalLayout_2->addWidget(startButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(ClientDialog);

        QMetaObject::connectSlotsByName(ClientDialog);
    } // setupUi

    void retranslateUi(QDialog *ClientDialog)
    {
        ClientDialog->setWindowTitle(QApplication::translate("ClientDialog", "ClientDialog", nullptr));
        sendMessageButton->setText(QApplication::translate("ClientDialog", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        label->setText(QApplication::translate("ClientDialog", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200\357\274\232", nullptr));
        serverIpEdit->setText(QApplication::translate("ClientDialog", "127.0.0.1", nullptr));
        label_2->setText(QApplication::translate("ClientDialog", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        serverPortEdit->setText(QApplication::translate("ClientDialog", "8888", nullptr));
        label_3->setText(QApplication::translate("ClientDialog", "\345\256\242\346\210\267\347\253\257\347\232\204\346\230\265\347\247\260\357\274\232", nullptr));
        clientNameEdit->setText(QApplication::translate("ClientDialog", "\346\233\234", nullptr));
        startButton->setText(QApplication::translate("ClientDialog", "\350\277\233\345\205\245\350\201\212\345\244\251\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientDialog: public Ui_ClientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDIALOG_H

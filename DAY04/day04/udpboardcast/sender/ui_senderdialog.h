/********************************************************************************
** Form generated from reading UI file 'senderdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDERDIALOG_H
#define UI_SENDERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SenderDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *textEdit;
    QLabel *label_2;
    QLineEdit *portEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *startStopButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *sendButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *SenderDialog)
    {
        if (SenderDialog->objectName().isEmpty())
            SenderDialog->setObjectName(QString::fromUtf8("SenderDialog"));
        SenderDialog->resize(560, 336);
        QFont font;
        font.setPointSize(24);
        SenderDialog->setFont(font);
        verticalLayout_2 = new QVBoxLayout(SenderDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(SenderDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        textEdit = new QLineEdit(SenderDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, textEdit);

        label_2 = new QLabel(SenderDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        portEdit = new QLineEdit(SenderDialog);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, portEdit);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        startStopButton = new QPushButton(SenderDialog);
        startStopButton->setObjectName(QString::fromUtf8("startStopButton"));

        horizontalLayout->addWidget(startStopButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        sendButton = new QPushButton(SenderDialog);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout->addWidget(sendButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SenderDialog);

        QMetaObject::connectSlotsByName(SenderDialog);
    } // setupUi

    void retranslateUi(QDialog *SenderDialog)
    {
        SenderDialog->setWindowTitle(QApplication::translate("SenderDialog", "\345\271\277\346\222\255\345\237\272\347\253\231", nullptr));
        label->setText(QApplication::translate("SenderDialog", "\345\271\277\346\222\255\345\206\205\345\256\271\357\274\232", nullptr));
        label_2->setText(QApplication::translate("SenderDialog", "\347\253\257  \345\217\243  \345\217\267\357\274\232", nullptr));
        portEdit->setText(QString());
        startStopButton->setText(QApplication::translate("SenderDialog", "\345\274\200\345\247\213\345\271\277\346\222\255", nullptr));
        sendButton->setText(QApplication::translate("SenderDialog", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SenderDialog: public Ui_SenderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDERDIALOG_H

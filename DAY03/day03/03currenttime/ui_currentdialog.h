/********************************************************************************
** Form generated from reading UI file 'currentdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENTDIALOG_H
#define UI_CURRENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_currentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *hourLcdNumber;
    QLabel *label;
    QLCDNumber *minLcdNumber;
    QLabel *label_2;
    QLCDNumber *secLcdNumber;

    void setupUi(QDialog *currentDialog)
    {
        if (currentDialog->objectName().isEmpty())
            currentDialog->setObjectName(QString::fromUtf8("currentDialog"));
        currentDialog->resize(441, 117);
        QFont font;
        font.setPointSize(24);
        currentDialog->setFont(font);
        verticalLayout = new QVBoxLayout(currentDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        hourLcdNumber = new QLCDNumber(currentDialog);
        hourLcdNumber->setObjectName(QString::fromUtf8("hourLcdNumber"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hourLcdNumber->sizePolicy().hasHeightForWidth());
        hourLcdNumber->setSizePolicy(sizePolicy);
        hourLcdNumber->setDigitCount(10);

        horizontalLayout->addWidget(hourLcdNumber);

        label = new QLabel(currentDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        minLcdNumber = new QLCDNumber(currentDialog);
        minLcdNumber->setObjectName(QString::fromUtf8("minLcdNumber"));
        sizePolicy.setHeightForWidth(minLcdNumber->sizePolicy().hasHeightForWidth());
        minLcdNumber->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(minLcdNumber);

        label_2 = new QLabel(currentDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        secLcdNumber = new QLCDNumber(currentDialog);
        secLcdNumber->setObjectName(QString::fromUtf8("secLcdNumber"));
        sizePolicy.setHeightForWidth(secLcdNumber->sizePolicy().hasHeightForWidth());
        secLcdNumber->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(secLcdNumber);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(currentDialog);

        QMetaObject::connectSlotsByName(currentDialog);
    } // setupUi

    void retranslateUi(QDialog *currentDialog)
    {
        currentDialog->setWindowTitle(QApplication::translate("currentDialog", "currentDialog", nullptr));
        label->setText(QApplication::translate("currentDialog", ":", nullptr));
        label_2->setText(QApplication::translate("currentDialog", ":", nullptr));
    } // retranslateUi

};

namespace Ui {
    class currentDialog: public Ui_currentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTDIALOG_H

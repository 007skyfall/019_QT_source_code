/********************************************************************************
** Form generated from reading UI file 'eniredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENIREDIALOG_H
#define UI_ENIREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EnireDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *numEdit;
    QSpacerItem *horizontalSpacer_2;
    QFrame *showPictureFrame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *StartStopButton;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *EnireDialog)
    {
        if (EnireDialog->objectName().isEmpty())
            EnireDialog->setObjectName(QString::fromUtf8("EnireDialog"));
        EnireDialog->resize(554, 519);
        QFont font;
        font.setPointSize(24);
        EnireDialog->setFont(font);
        verticalLayout_2 = new QVBoxLayout(EnireDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        lcdNumber = new QLCDNumber(EnireDialog);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy);
        lcdNumber->setMinimumSize(QSize(200, 50));
        QFont font1;
        font1.setPointSize(48);
        lcdNumber->setFont(font1);
        lcdNumber->setDigitCount(8);

        horizontalLayout_3->addWidget(lcdNumber);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(EnireDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        numEdit = new QLineEdit(EnireDialog);
        numEdit->setObjectName(QString::fromUtf8("numEdit"));

        horizontalLayout->addWidget(numEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        showPictureFrame = new QFrame(EnireDialog);
        showPictureFrame->setObjectName(QString::fromUtf8("showPictureFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(showPictureFrame->sizePolicy().hasHeightForWidth());
        showPictureFrame->setSizePolicy(sizePolicy1);
        showPictureFrame->setFrameShape(QFrame::StyledPanel);
        showPictureFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(showPictureFrame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        StartStopButton = new QPushButton(EnireDialog);
        StartStopButton->setObjectName(QString::fromUtf8("StartStopButton"));

        horizontalLayout_2->addWidget(StartStopButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(EnireDialog);

        QMetaObject::connectSlotsByName(EnireDialog);
    } // setupUi

    void retranslateUi(QDialog *EnireDialog)
    {
        EnireDialog->setWindowTitle(QApplication::translate("EnireDialog", "\345\210\233\345\256\242\345\255\246\351\231\242\346\221\207\345\245\226\346\234\272", nullptr));
        label->setText(QApplication::translate("EnireDialog", "\344\270\255\345\245\226\350\200\205\347\274\226\345\217\267\357\274\232", nullptr));
        StartStopButton->setText(QApplication::translate("EnireDialog", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnireDialog: public Ui_EnireDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENIREDIALOG_H

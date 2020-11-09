/********************************************************************************
** Form generated from reading UI file 'showpicsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWPICSDIALOG_H
#define UI_SHOWPICSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ShowPicsDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFrame *showPicsFrame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *downButton;
    QPushButton *upButton;
    QPushButton *closeButton;

    void setupUi(QDialog *ShowPicsDialog)
    {
        if (ShowPicsDialog->objectName().isEmpty())
            ShowPicsDialog->setObjectName(QString::fromUtf8("ShowPicsDialog"));
        ShowPicsDialog->resize(491, 477);
        QFont font;
        font.setPointSize(24);
        ShowPicsDialog->setFont(font);
        verticalLayout_2 = new QVBoxLayout(ShowPicsDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        showPicsFrame = new QFrame(ShowPicsDialog);
        showPicsFrame->setObjectName(QString::fromUtf8("showPicsFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(showPicsFrame->sizePolicy().hasHeightForWidth());
        showPicsFrame->setSizePolicy(sizePolicy);
        showPicsFrame->setFrameShape(QFrame::StyledPanel);
        showPicsFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(showPicsFrame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        downButton = new QPushButton(ShowPicsDialog);
        downButton->setObjectName(QString::fromUtf8("downButton"));

        horizontalLayout->addWidget(downButton);

        upButton = new QPushButton(ShowPicsDialog);
        upButton->setObjectName(QString::fromUtf8("upButton"));

        horizontalLayout->addWidget(upButton);

        closeButton = new QPushButton(ShowPicsDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ShowPicsDialog);

        upButton->setDefault(true);


        QMetaObject::connectSlotsByName(ShowPicsDialog);
    } // setupUi

    void retranslateUi(QDialog *ShowPicsDialog)
    {
        ShowPicsDialog->setWindowTitle(QApplication::translate("ShowPicsDialog", "\345\233\276\347\211\207\346\265\217\350\247\210\345\231\250", nullptr));
        downButton->setText(QApplication::translate("ShowPicsDialog", "\344\270\213\344\270\200\345\274\240", nullptr));
        upButton->setText(QApplication::translate("ShowPicsDialog", "\344\270\212\344\270\200\345\274\240", nullptr));
        closeButton->setText(QApplication::translate("ShowPicsDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowPicsDialog: public Ui_ShowPicsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWPICSDIALOG_H

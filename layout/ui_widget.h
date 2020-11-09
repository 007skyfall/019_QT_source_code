/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *infoLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *openLabel;
    QLineEdit *cmdlineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QPushButton *browerButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(331, 110);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        infoLabel = new QLabel(Widget);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));

        verticalLayout->addWidget(infoLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        openLabel = new QLabel(Widget);
        openLabel->setObjectName(QStringLiteral("openLabel"));

        horizontalLayout_2->addWidget(openLabel);

        cmdlineEdit = new QLineEdit(Widget);
        cmdlineEdit->setObjectName(QStringLiteral("cmdlineEdit"));

        horizontalLayout_2->addWidget(cmdlineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        submitButton = new QPushButton(Widget);
        submitButton->setObjectName(QStringLiteral("submitButton"));

        horizontalLayout->addWidget(submitButton);

        cancelButton = new QPushButton(Widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        browerButton = new QPushButton(Widget);
        browerButton->setObjectName(QStringLiteral("browerButton"));

        horizontalLayout->addWidget(browerButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        infoLabel->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; font-style:italic; text-decoration: underline; color:#ff0000;\">\350\257\267\350\276\223\345\205\245\350\246\201\346\230\276\347\244\272\347\232\204\345\221\275\344\273\244\357\274\232</span></p></body></html>", 0));
        openLabel->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">\346\211\223\345\274\200\357\274\232</span></p></body></html>", 0));
        submitButton->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", 0));
        cancelButton->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", 0));
        browerButton->setText(QApplication::translate("Widget", "\346\265\217\350\247\210", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

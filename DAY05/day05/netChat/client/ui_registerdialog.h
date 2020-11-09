/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_registerDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *idEdit;
    QLabel *label_2;
    QLineEdit *userNameEdit;
    QLabel *label_3;
    QLineEdit *passwdEdit;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QPushButton *deleteButton;
    QPushButton *registerButton;

    void setupUi(QDialog *registerDialog)
    {
        if (registerDialog->objectName().isEmpty())
            registerDialog->setObjectName(QString::fromUtf8("registerDialog"));
        registerDialog->resize(448, 490);
        horizontalLayout_3 = new QHBoxLayout(registerDialog);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(registerDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(registerDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        idEdit = new QLineEdit(registerDialog);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        gridLayout->addWidget(idEdit, 0, 1, 1, 1);

        label_2 = new QLabel(registerDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        userNameEdit = new QLineEdit(registerDialog);
        userNameEdit->setObjectName(QString::fromUtf8("userNameEdit"));

        gridLayout->addWidget(userNameEdit, 1, 1, 1, 1);

        label_3 = new QLabel(registerDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        passwdEdit = new QLineEdit(registerDialog);
        passwdEdit->setObjectName(QString::fromUtf8("passwdEdit"));

        gridLayout->addWidget(passwdEdit, 2, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(registerDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);

        deleteButton = new QPushButton(registerDialog);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        registerButton = new QPushButton(registerDialog);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));

        horizontalLayout->addWidget(registerButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(registerDialog);

        QMetaObject::connectSlotsByName(registerDialog);
    } // setupUi

    void retranslateUi(QDialog *registerDialog)
    {
        registerDialog->setWindowTitle(QApplication::translate("registerDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("registerDialog", "\347\224\250\346\210\267ID\357\274\232", nullptr));
        label_2->setText(QApplication::translate("registerDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QApplication::translate("registerDialog", "\345\257\206    \347\240\201\357\274\232", nullptr));
        closeButton->setText(QApplication::translate("registerDialog", "\345\205\263\351\227\255", nullptr));
        deleteButton->setText(QApplication::translate("registerDialog", "\345\210\240\351\231\244", nullptr));
        registerButton->setText(QApplication::translate("registerDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerDialog: public Ui_registerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H

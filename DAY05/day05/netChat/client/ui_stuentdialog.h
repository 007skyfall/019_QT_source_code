/********************************************************************************
** Form generated from reading UI file 'stuentdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUENTDIALOG_H
#define UI_STUENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StuentDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *valueBox;
    QComboBox *sortBox;
    QPushButton *sortButton;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *idEdit;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *scoreEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *insertButton;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QPushButton *selectButton;

    void setupUi(QDialog *StuentDialog)
    {
        if (StuentDialog->objectName().isEmpty())
            StuentDialog->setObjectName(QString::fromUtf8("StuentDialog"));
        StuentDialog->resize(491, 568);
        verticalLayout_2 = new QVBoxLayout(StuentDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        valueBox = new QComboBox(StuentDialog);
        valueBox->addItem(QString());
        valueBox->addItem(QString());
        valueBox->setObjectName(QString::fromUtf8("valueBox"));

        horizontalLayout->addWidget(valueBox);

        sortBox = new QComboBox(StuentDialog);
        sortBox->addItem(QString());
        sortBox->addItem(QString());
        sortBox->setObjectName(QString::fromUtf8("sortBox"));

        horizontalLayout->addWidget(sortBox);

        sortButton = new QPushButton(StuentDialog);
        sortButton->setObjectName(QString::fromUtf8("sortButton"));

        horizontalLayout->addWidget(sortButton);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(StuentDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(StuentDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        idEdit = new QLineEdit(StuentDialog);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        gridLayout->addWidget(idEdit, 0, 1, 2, 2);

        nameEdit = new QLineEdit(StuentDialog);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 2, 2, 1);

        label_2 = new QLabel(StuentDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(StuentDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        scoreEdit = new QLineEdit(StuentDialog);
        scoreEdit->setObjectName(QString::fromUtf8("scoreEdit"));

        gridLayout->addWidget(scoreEdit, 3, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        insertButton = new QPushButton(StuentDialog);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));

        horizontalLayout_2->addWidget(insertButton);

        updateButton = new QPushButton(StuentDialog);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));

        horizontalLayout_2->addWidget(updateButton);

        deleteButton = new QPushButton(StuentDialog);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout_2->addWidget(deleteButton);

        selectButton = new QPushButton(StuentDialog);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));

        horizontalLayout_2->addWidget(selectButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(StuentDialog);

        selectButton->setDefault(true);


        QMetaObject::connectSlotsByName(StuentDialog);
    } // setupUi

    void retranslateUi(QDialog *StuentDialog)
    {
        StuentDialog->setWindowTitle(QApplication::translate("StuentDialog", "StuentDialog", nullptr));
        valueBox->setItemText(0, QApplication::translate("StuentDialog", "\345\255\246\345\217\267", nullptr));
        valueBox->setItemText(1, QApplication::translate("StuentDialog", "\346\210\220\347\273\251", nullptr));

        sortBox->setItemText(0, QApplication::translate("StuentDialog", "\345\215\207\345\272\217", nullptr));
        sortBox->setItemText(1, QApplication::translate("StuentDialog", "\351\231\215\345\272\217", nullptr));

        sortButton->setText(QApplication::translate("StuentDialog", "\346\216\222\345\272\217", nullptr));
        label->setText(QApplication::translate("StuentDialog", "\345\255\246  \345\221\230  ID\357\274\232", nullptr));
        label_2->setText(QApplication::translate("StuentDialog", "\345\255\246\345\221\230\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QApplication::translate("StuentDialog", "\345\255\246\345\221\230\346\210\220\347\273\251\357\274\232", nullptr));
        insertButton->setText(QApplication::translate("StuentDialog", "\346\217\222\345\205\245", nullptr));
        updateButton->setText(QApplication::translate("StuentDialog", "\344\277\256\346\224\271", nullptr));
        deleteButton->setText(QApplication::translate("StuentDialog", "\345\210\240\351\231\244", nullptr));
        selectButton->setText(QApplication::translate("StuentDialog", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StuentDialog: public Ui_StuentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUENTDIALOG_H

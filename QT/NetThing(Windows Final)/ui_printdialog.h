/********************************************************************************
** Form generated from reading UI file 'printdialog.ui'
**
** Created: Fri Mar 30 17:56:16 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTDIALOG_H
#define UI_PRINTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_PrintDialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QSpinBox *spinBox;
    QRadioButton *radioButton;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *ExitButton;
    QPushButton *SaveButton;
    QPushButton *GetButton;

    void setupUi(QDialog *PrintDialog)
    {
        if (PrintDialog->objectName().isEmpty())
            PrintDialog->setObjectName(QString::fromUtf8("PrintDialog"));
        PrintDialog->resize(300, 310);
        PrintDialog->setMinimumSize(QSize(300, 310));
        PrintDialog->setMaximumSize(QSize(300, 310));
        PrintDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/image/print.png);"));
        groupBox = new QGroupBox(PrintDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 261, 211));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 100, 171, 101));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(100, 30, 71, 21));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 70, 101, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 130, 54, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 30, 71, 16));
        ExitButton = new QPushButton(PrintDialog);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        ExitButton->setGeometry(QRect(200, 260, 81, 23));
        SaveButton = new QPushButton(PrintDialog);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(110, 260, 75, 23));
        GetButton = new QPushButton(PrintDialog);
        GetButton->setObjectName(QString::fromUtf8("GetButton"));
        GetButton->setGeometry(QRect(20, 260, 75, 23));
        GetButton->setCheckable(false);

        retranslateUi(PrintDialog);

        QMetaObject::connectSlotsByName(PrintDialog);
    } // setupUi

    void retranslateUi(QDialog *PrintDialog)
    {
        PrintDialog->setWindowTitle(QApplication::translate("PrintDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PrintDialog", "option", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        radioButton->setText(QApplication::translate("PrintDialog", "\351\232\220\350\227\217\346\255\244\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PrintDialog", "\351\242\204\350\247\210\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PrintDialog", "\345\273\266\346\227\266\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        ExitButton->setText(QApplication::translate("PrintDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        SaveButton->setText(QApplication::translate("PrintDialog", "\344\277\235\345\255\230\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        GetButton->setText(QApplication::translate("PrintDialog", "\346\226\260\345\273\272\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PrintDialog: public Ui_PrintDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTDIALOG_H

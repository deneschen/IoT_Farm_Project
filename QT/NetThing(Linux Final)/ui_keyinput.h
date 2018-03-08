/********************************************************************************
** Form generated from reading UI file 'keyinput.ui'
**
** Created: Tue Mar 27 13:36:44 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYINPUT_H
#define UI_KEYINPUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_KeyInput
{
public:
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_user;
    QPushButton *pushButton_c;
    QPushButton *pushButton_0;
    QLineEdit *lineEdit;
    QPushButton *pushButton_up;
    QPushButton *pushButton_down;
    QPushButton *pushButton_phone;
    QPushButton *pushButton_passwd;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *KeyInput)
    {
        if (KeyInput->objectName().isEmpty())
            KeyInput->setObjectName(QString::fromUtf8("KeyInput"));
        KeyInput->resize(190, 230);
        KeyInput->setMinimumSize(QSize(190, 230));
        KeyInput->setMaximumSize(QSize(190, 230));
        KeyInput->setSizeIncrement(QSize(0, 0));
        KeyInput->setStyleSheet(QString::fromUtf8("background-image: url(:/images/calc2.png);"));
        pushButton_1 = new QPushButton(KeyInput);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(10, 50, 51, 21));
        QFont font;
        font.setPointSize(16);
        pushButton_1->setFont(font);
        pushButton_2 = new QPushButton(KeyInput);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 50, 51, 21));
        pushButton_2->setFont(font);
        pushButton_5 = new QPushButton(KeyInput);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 80, 51, 21));
        pushButton_5->setFont(font);
        pushButton_4 = new QPushButton(KeyInput);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 80, 51, 21));
        pushButton_4->setFont(font);
        pushButton_7 = new QPushButton(KeyInput);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 110, 51, 21));
        pushButton_7->setFont(font);
        pushButton_3 = new QPushButton(KeyInput);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 50, 51, 21));
        pushButton_3->setFont(font);
        pushButton_6 = new QPushButton(KeyInput);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(130, 80, 51, 21));
        pushButton_6->setFont(font);
        pushButton_8 = new QPushButton(KeyInput);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(70, 110, 51, 21));
        pushButton_8->setFont(font);
        pushButton_9 = new QPushButton(KeyInput);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(130, 110, 51, 21));
        pushButton_9->setFont(font);
        pushButton_user = new QPushButton(KeyInput);
        pushButton_user->setObjectName(QString::fromUtf8("pushButton_user"));
        pushButton_user->setGeometry(QRect(10, 170, 51, 21));
        pushButton_user->setFont(font);
        pushButton_c = new QPushButton(KeyInput);
        pushButton_c->setObjectName(QString::fromUtf8("pushButton_c"));
        pushButton_c->setGeometry(QRect(130, 140, 51, 21));
        pushButton_c->setFont(font);
        pushButton_0 = new QPushButton(KeyInput);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(70, 140, 51, 21));
        pushButton_0->setFont(font);
        lineEdit = new QLineEdit(KeyInput);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 171, 31));
        lineEdit->setFont(font);
        pushButton_up = new QPushButton(KeyInput);
        pushButton_up->setObjectName(QString::fromUtf8("pushButton_up"));
        pushButton_up->setGeometry(QRect(70, 170, 51, 21));
        pushButton_up->setFont(font);
        pushButton_down = new QPushButton(KeyInput);
        pushButton_down->setObjectName(QString::fromUtf8("pushButton_down"));
        pushButton_down->setGeometry(QRect(130, 170, 51, 21));
        pushButton_down->setFont(font);
        pushButton_phone = new QPushButton(KeyInput);
        pushButton_phone->setObjectName(QString::fromUtf8("pushButton_phone"));
        pushButton_phone->setGeometry(QRect(70, 200, 111, 21));
        pushButton_phone->setFont(font);
        pushButton_passwd = new QPushButton(KeyInput);
        pushButton_passwd->setObjectName(QString::fromUtf8("pushButton_passwd"));
        pushButton_passwd->setGeometry(QRect(10, 200, 51, 21));
        pushButton_passwd->setFont(font);
        pushButton_cancel = new QPushButton(KeyInput);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(10, 140, 51, 21));
        pushButton_cancel->setFont(font);

        retranslateUi(KeyInput);

        QMetaObject::connectSlotsByName(KeyInput);
    } // setupUi

    void retranslateUi(QDialog *KeyInput)
    {
        KeyInput->setWindowTitle(QApplication::translate("KeyInput", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("KeyInput", "1", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("KeyInput", "2", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("KeyInput", "5", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("KeyInput", "4", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("KeyInput", "7", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("KeyInput", "3", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("KeyInput", "6", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("KeyInput", "8", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("KeyInput", "9", 0, QApplication::UnicodeUTF8));
        pushButton_user->setText(QApplication::translate("KeyInput", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        pushButton_c->setText(QApplication::translate("KeyInput", "\346\270\205\351\231\244", 0, QApplication::UnicodeUTF8));
        pushButton_0->setText(QApplication::translate("KeyInput", "0", 0, QApplication::UnicodeUTF8));
        pushButton_up->setText(QApplication::translate("KeyInput", "\344\270\212\351\231\220", 0, QApplication::UnicodeUTF8));
        pushButton_down->setText(QApplication::translate("KeyInput", "\344\270\213\351\231\220", 0, QApplication::UnicodeUTF8));
        pushButton_phone->setText(QApplication::translate("KeyInput", "\346\211\213\346\234\272\345\217\267", 0, QApplication::UnicodeUTF8));
        pushButton_passwd->setText(QApplication::translate("KeyInput", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("KeyInput", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class KeyInput: public Ui_KeyInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYINPUT_H

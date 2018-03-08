/********************************************************************************
** Form generated from reading UI file 'setdota.ui'
**
** Created: Wed Mar 28 18:28:56 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETDOTA_H
#define UI_SETDOTA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetDota
{
public:
    QLabel *tem_down_label;
    QLineEdit *phone_lineEdit;
    QLabel *tem_up_label;
    QLabel *phone_label;
    QLineEdit *tem_up_lineEdit;
    QLineEdit *tem_down_lineEdit;
    QPushButton *return_pushButton_1;
    QPushButton *temup_pushButton;
    QPushButton *sure_pushButton;

    void setupUi(QDialog *SetDota)
    {
        if (SetDota->objectName().isEmpty())
            SetDota->setObjectName(QString::fromUtf8("SetDota"));
        SetDota->resize(480, 272);
        SetDota->setMinimumSize(QSize(480, 272));
        SetDota->setMaximumSize(QSize(480, 272));
        SetDota->setStyleSheet(QString::fromUtf8("background-image: url(:/images/control.png);"));
        tem_down_label = new QLabel(SetDota);
        tem_down_label->setObjectName(QString::fromUtf8("tem_down_label"));
        tem_down_label->setGeometry(QRect(10, 140, 151, 31));
        QFont font;
        font.setPointSize(20);
        tem_down_label->setFont(font);
        tem_down_label->setStyleSheet(QString::fromUtf8("color:#ff3300;"));
        phone_lineEdit = new QLineEdit(SetDota);
        phone_lineEdit->setObjectName(QString::fromUtf8("phone_lineEdit"));
        phone_lineEdit->setGeometry(QRect(170, 190, 121, 31));
        QFont font1;
        font1.setPointSize(14);
        phone_lineEdit->setFont(font1);
        tem_up_label = new QLabel(SetDota);
        tem_up_label->setObjectName(QString::fromUtf8("tem_up_label"));
        tem_up_label->setGeometry(QRect(10, 90, 151, 31));
        tem_up_label->setFont(font);
        tem_up_label->setStyleSheet(QString::fromUtf8("color:#ff3300;"));
        phone_label = new QLabel(SetDota);
        phone_label->setObjectName(QString::fromUtf8("phone_label"));
        phone_label->setGeometry(QRect(10, 190, 151, 31));
        phone_label->setFont(font);
        phone_label->setStyleSheet(QString::fromUtf8("color:#3366ff;"));
        tem_up_lineEdit = new QLineEdit(SetDota);
        tem_up_lineEdit->setObjectName(QString::fromUtf8("tem_up_lineEdit"));
        tem_up_lineEdit->setGeometry(QRect(170, 90, 81, 31));
        QFont font2;
        font2.setPointSize(16);
        tem_up_lineEdit->setFont(font2);
        tem_down_lineEdit = new QLineEdit(SetDota);
        tem_down_lineEdit->setObjectName(QString::fromUtf8("tem_down_lineEdit"));
        tem_down_lineEdit->setGeometry(QRect(170, 140, 81, 31));
        tem_down_lineEdit->setFont(font2);
        return_pushButton_1 = new QPushButton(SetDota);
        return_pushButton_1->setObjectName(QString::fromUtf8("return_pushButton_1"));
        return_pushButton_1->setGeometry(QRect(20, 20, 63, 60));
        return_pushButton_1->setMinimumSize(QSize(63, 60));
        return_pushButton_1->setMaximumSize(QSize(63, 60));
        return_pushButton_1->setStyleSheet(QString::fromUtf8("image: url(:/images/return_ctl.png);"));
        temup_pushButton = new QPushButton(SetDota);
        temup_pushButton->setObjectName(QString::fromUtf8("temup_pushButton"));
        temup_pushButton->setGeometry(QRect(290, 90, 60, 30));
        temup_pushButton->setMinimumSize(QSize(60, 30));
        temup_pushButton->setMaximumSize(QSize(60, 30));
        temup_pushButton->setStyleSheet(QString::fromUtf8("image: url(:/images/keyboard.png);"));
        sure_pushButton = new QPushButton(SetDota);
        sure_pushButton->setObjectName(QString::fromUtf8("sure_pushButton"));
        sure_pushButton->setGeometry(QRect(370, 230, 101, 31));
        sure_pushButton->setFont(font);
        sure_pushButton->setStyleSheet(QString::fromUtf8("color:#3366ff;"));

        retranslateUi(SetDota);

        QMetaObject::connectSlotsByName(SetDota);
    } // setupUi

    void retranslateUi(QDialog *SetDota)
    {
        SetDota->setWindowTitle(QApplication::translate("SetDota", "Dialog", 0, QApplication::UnicodeUTF8));
        tem_down_label->setText(QApplication::translate("SetDota", "  \346\270\251\345\272\246\344\270\213\351\231\220\350\256\276\345\256\232\357\274\232", 0, QApplication::UnicodeUTF8));
        tem_up_label->setText(QApplication::translate("SetDota", "  \346\270\251\345\272\246\344\270\212\351\231\220\350\256\276\345\256\232\357\274\232", 0, QApplication::UnicodeUTF8));
        phone_label->setText(QApplication::translate("SetDota", "  \346\211\213\346\234\272\345\217\267\350\256\276\347\275\256\357\274\232", 0, QApplication::UnicodeUTF8));
        return_pushButton_1->setText(QString());
        temup_pushButton->setText(QString());
        sure_pushButton->setText(QApplication::translate("SetDota", "\346\217\220\344\272\244\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetDota: public Ui_SetDota {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETDOTA_H

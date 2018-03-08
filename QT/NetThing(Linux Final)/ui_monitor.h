/********************************************************************************
** Form generated from reading UI file 'monitor.ui'
**
** Created: Sat Apr 7 13:09:41 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITOR_H
#define UI_MONITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Monitor
{
public:
    QLabel *safe_label;
    QLabel *set_label;
    QLabel *tem_label;
    QLabel *ctl_label;
    QLabel *light_label;
    QLabel *hum_label;
    QPushButton *set_pushButton;
    QPushButton *ctl_pushButton;
    QPushButton *exit_pushButton;
    QTextBrowser *temp_textBrowser;
    QTextBrowser *light_textBrowser;
    QTextBrowser *hum_textBrowser;
    QTextBrowser *RFID_textBrowser;

    void setupUi(QDialog *Monitor)
    {
        if (Monitor->objectName().isEmpty())
            Monitor->setObjectName(QString::fromUtf8("Monitor"));
        Monitor->resize(480, 272);
        Monitor->setMinimumSize(QSize(480, 272));
        Monitor->setMaximumSize(QSize(480, 272));
        Monitor->setStyleSheet(QString::fromUtf8("background-image: url(:/images/backgd1.png);"));
        safe_label = new QLabel(Monitor);
        safe_label->setObjectName(QString::fromUtf8("safe_label"));
        safe_label->setGeometry(QRect(20, 180, 101, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(20);
        safe_label->setFont(font);
        safe_label->setStyleSheet(QString::fromUtf8("color:#ff0066;"));
        set_label = new QLabel(Monitor);
        set_label->setObjectName(QString::fromUtf8("set_label"));
        set_label->setGeometry(QRect(330, 100, 61, 20));
        QFont font1;
        font1.setPointSize(20);
        set_label->setFont(font1);
        set_label->setStyleSheet(QString::fromUtf8("color:#ffff33;"));
        tem_label = new QLabel(Monitor);
        tem_label->setObjectName(QString::fromUtf8("tem_label"));
        tem_label->setGeometry(QRect(50, 40, 71, 31));
        tem_label->setFont(font);
        tem_label->setStyleSheet(QString::fromUtf8("color:#ffff33;"));
        ctl_label = new QLabel(Monitor);
        ctl_label->setObjectName(QString::fromUtf8("ctl_label"));
        ctl_label->setGeometry(QRect(320, 220, 81, 21));
        ctl_label->setFont(font1);
        ctl_label->setStyleSheet(QString::fromUtf8("color:#ffff33;"));
        light_label = new QLabel(Monitor);
        light_label->setObjectName(QString::fromUtf8("light_label"));
        light_label->setGeometry(QRect(50, 80, 71, 31));
        light_label->setFont(font);
        light_label->setStyleSheet(QString::fromUtf8("color:#ffff33;"));
        hum_label = new QLabel(Monitor);
        hum_label->setObjectName(QString::fromUtf8("hum_label"));
        hum_label->setGeometry(QRect(50, 120, 71, 31));
        hum_label->setFont(font);
        hum_label->setStyleSheet(QString::fromUtf8("color:#ffff33;"));
        set_pushButton = new QPushButton(Monitor);
        set_pushButton->setObjectName(QString::fromUtf8("set_pushButton"));
        set_pushButton->setGeometry(QRect(330, 30, 58, 58));
        set_pushButton->setMinimumSize(QSize(58, 58));
        set_pushButton->setMaximumSize(QSize(58, 58));
        set_pushButton->setStyleSheet(QString::fromUtf8("image: url(:/images/set.png);"));
        ctl_pushButton = new QPushButton(Monitor);
        ctl_pushButton->setObjectName(QString::fromUtf8("ctl_pushButton"));
        ctl_pushButton->setGeometry(QRect(330, 150, 60, 60));
        ctl_pushButton->setMinimumSize(QSize(60, 60));
        ctl_pushButton->setMaximumSize(QSize(60, 60));
        ctl_pushButton->setStyleSheet(QString::fromUtf8("image: url(:/images/ctl.png);"));
        exit_pushButton = new QPushButton(Monitor);
        exit_pushButton->setObjectName(QString::fromUtf8("exit_pushButton"));
        exit_pushButton->setGeometry(QRect(430, 210, 45, 45));
        exit_pushButton->setMinimumSize(QSize(45, 45));
        exit_pushButton->setMaximumSize(QSize(45, 45));
        exit_pushButton->setStyleSheet(QString::fromUtf8("image: url(:/images/exit.png);"));
        temp_textBrowser = new QTextBrowser(Monitor);
        temp_textBrowser->setObjectName(QString::fromUtf8("temp_textBrowser"));
        temp_textBrowser->setGeometry(QRect(130, 40, 101, 31));
        light_textBrowser = new QTextBrowser(Monitor);
        light_textBrowser->setObjectName(QString::fromUtf8("light_textBrowser"));
        light_textBrowser->setGeometry(QRect(130, 80, 101, 31));
        hum_textBrowser = new QTextBrowser(Monitor);
        hum_textBrowser->setObjectName(QString::fromUtf8("hum_textBrowser"));
        hum_textBrowser->setGeometry(QRect(130, 120, 101, 31));
        RFID_textBrowser = new QTextBrowser(Monitor);
        RFID_textBrowser->setObjectName(QString::fromUtf8("RFID_textBrowser"));
        RFID_textBrowser->setGeometry(QRect(130, 180, 101, 31));

        retranslateUi(Monitor);

        QMetaObject::connectSlotsByName(Monitor);
    } // setupUi

    void retranslateUi(QDialog *Monitor)
    {
        Monitor->setWindowTitle(QApplication::translate("Monitor", "Dialog", 0, QApplication::UnicodeUTF8));
        safe_label->setText(QApplication::translate("Monitor", "  \351\227\250\347\246\201\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        set_label->setText(QApplication::translate("Monitor", "   \350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        tem_label->setText(QApplication::translate("Monitor", "   \346\270\251\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        ctl_label->setText(QApplication::translate("Monitor", "  \350\277\234\347\250\213\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        light_label->setText(QApplication::translate("Monitor", "   \345\205\211\347\205\247\357\274\232", 0, QApplication::UnicodeUTF8));
        hum_label->setText(QApplication::translate("Monitor", "   \346\271\277\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        set_pushButton->setText(QString());
        ctl_pushButton->setText(QString());
        exit_pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Monitor: public Ui_Monitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITOR_H

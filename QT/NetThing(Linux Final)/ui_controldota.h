/********************************************************************************
** Form generated from reading UI file 'controldota.ui'
**
** Created: Sun Apr 1 13:59:34 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLDOTA_H
#define UI_CONTROLDOTA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ControlDota
{
public:
    QLabel *wind_label_m;
    QLabel *smg_label_m;
    QLabel *label_4;
    QPushButton *return_pushButton;
    QPushButton *wind_off_pushButton_m;
    QPushButton *smg_off_pushButton_m;
    QPushButton *wind_on_pushButton_m;
    QPushButton *smg_on_pushButton_m;
    QPushButton *alarm_on_pushButton_m;
    QPushButton *alarm_off_pushButton_m;
    QLabel *alarm_label_m;
    QPushButton *light_on_pushButton_m;
    QLabel *light_label_m;
    QPushButton *light_off_pushButton_m;
    QGroupBox *groupBox;
    QPushButton *alarm_on_pushButton;
    QLabel *alarm_label_1;
    QPushButton *light_on_pushButton;
    QLabel *light_label_1;
    QPushButton *light_off_pushButton;
    QPushButton *alarm_off_pushButton;
    QGroupBox *steu_groupBox;
    QPushButton *one_pushButton;
    QPushButton *two_pushButton;
    QPushButton *thr_pushButton;
    QPushButton *stop_pushButton;

    void setupUi(QDialog *ControlDota)
    {
        if (ControlDota->objectName().isEmpty())
            ControlDota->setObjectName(QString::fromUtf8("ControlDota"));
        ControlDota->resize(480, 272);
        ControlDota->setMinimumSize(QSize(480, 272));
        ControlDota->setMaximumSize(QSize(480, 272));
        ControlDota->setStyleSheet(QString::fromUtf8("background-image: url(:/images/control_set.png);"));
        wind_label_m = new QLabel(ControlDota);
        wind_label_m->setObjectName(QString::fromUtf8("wind_label_m"));
        wind_label_m->setGeometry(QRect(120, 100, 71, 21));
        QFont font;
        font.setPointSize(20);
        wind_label_m->setFont(font);
        wind_label_m->setStyleSheet(QString::fromUtf8("color:#0033ff;"));
        smg_label_m = new QLabel(ControlDota);
        smg_label_m->setObjectName(QString::fromUtf8("smg_label_m"));
        smg_label_m->setGeometry(QRect(160, 210, 91, 21));
        smg_label_m->setFont(font);
        smg_label_m->setStyleSheet(QString::fromUtf8("color:#0033ff;"));
        label_4 = new QLabel(ControlDota);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 270, 81, 31));
        return_pushButton = new QPushButton(ControlDota);
        return_pushButton->setObjectName(QString::fromUtf8("return_pushButton"));
        return_pushButton->setGeometry(QRect(30, 190, 62, 60));
        return_pushButton->setMinimumSize(QSize(62, 60));
        return_pushButton->setMaximumSize(QSize(62, 60));
        return_pushButton->setStyleSheet(QString::fromUtf8("image: url(:/images/return_ctl.png);"));
        wind_off_pushButton_m = new QPushButton(ControlDota);
        wind_off_pushButton_m->setObjectName(QString::fromUtf8("wind_off_pushButton_m"));
        wind_off_pushButton_m->setGeometry(QRect(130, 40, 55, 55));
        wind_off_pushButton_m->setMinimumSize(QSize(55, 55));
        wind_off_pushButton_m->setMaximumSize(QSize(55, 55));
        wind_off_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/images/wind.png);"));
        smg_off_pushButton_m = new QPushButton(ControlDota);
        smg_off_pushButton_m->setObjectName(QString::fromUtf8("smg_off_pushButton_m"));
        smg_off_pushButton_m->setGeometry(QRect(180, 150, 55, 55));
        smg_off_pushButton_m->setMinimumSize(QSize(55, 55));
        smg_off_pushButton_m->setMaximumSize(QSize(55, 55));
        smg_off_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/images/smg.png);"));
        wind_on_pushButton_m = new QPushButton(ControlDota);
        wind_on_pushButton_m->setObjectName(QString::fromUtf8("wind_on_pushButton_m"));
        wind_on_pushButton_m->setGeometry(QRect(130, 40, 55, 55));
        wind_on_pushButton_m->setMinimumSize(QSize(55, 55));
        wind_on_pushButton_m->setMaximumSize(QSize(55, 55));
        wind_on_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/images/wind_1.png);"));
        smg_on_pushButton_m = new QPushButton(ControlDota);
        smg_on_pushButton_m->setObjectName(QString::fromUtf8("smg_on_pushButton_m"));
        smg_on_pushButton_m->setGeometry(QRect(180, 150, 55, 55));
        smg_on_pushButton_m->setMinimumSize(QSize(55, 55));
        smg_on_pushButton_m->setMaximumSize(QSize(55, 55));
        smg_on_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/images/smg_1.png);"));
        alarm_on_pushButton_m = new QPushButton(ControlDota);
        alarm_on_pushButton_m->setObjectName(QString::fromUtf8("alarm_on_pushButton_m"));
        alarm_on_pushButton_m->setGeometry(QRect(290, 150, 55, 55));
        alarm_on_pushButton_m->setMinimumSize(QSize(55, 55));
        alarm_on_pushButton_m->setMaximumSize(QSize(55, 55));
        alarm_on_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/images/alarm_1.png);"));
        alarm_off_pushButton_m = new QPushButton(ControlDota);
        alarm_off_pushButton_m->setObjectName(QString::fromUtf8("alarm_off_pushButton_m"));
        alarm_off_pushButton_m->setGeometry(QRect(290, 150, 55, 55));
        alarm_off_pushButton_m->setMinimumSize(QSize(55, 55));
        alarm_off_pushButton_m->setMaximumSize(QSize(55, 55));
        alarm_off_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/images/alarm.png);"));
        alarm_label_m = new QLabel(ControlDota);
        alarm_label_m->setObjectName(QString::fromUtf8("alarm_label_m"));
        alarm_label_m->setGeometry(QRect(270, 210, 81, 21));
        alarm_label_m->setFont(font);
        alarm_label_m->setStyleSheet(QString::fromUtf8("color:#0033ff;"));
        light_on_pushButton_m = new QPushButton(ControlDota);
        light_on_pushButton_m->setObjectName(QString::fromUtf8("light_on_pushButton_m"));
        light_on_pushButton_m->setGeometry(QRect(240, 40, 55, 55));
        light_on_pushButton_m->setMinimumSize(QSize(55, 55));
        light_on_pushButton_m->setMaximumSize(QSize(55, 55));
        light_on_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/images/led_1.png);"));
        light_label_m = new QLabel(ControlDota);
        light_label_m->setObjectName(QString::fromUtf8("light_label_m"));
        light_label_m->setGeometry(QRect(230, 100, 71, 21));
        light_label_m->setFont(font);
        light_label_m->setStyleSheet(QString::fromUtf8("color:#0033ff;"));
        light_off_pushButton_m = new QPushButton(ControlDota);
        light_off_pushButton_m->setObjectName(QString::fromUtf8("light_off_pushButton_m"));
        light_off_pushButton_m->setGeometry(QRect(240, 40, 55, 55));
        light_off_pushButton_m->setMinimumSize(QSize(55, 55));
        light_off_pushButton_m->setMaximumSize(QSize(55, 55));
        light_off_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/images/led.png);"));
        groupBox = new QGroupBox(ControlDota);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(390, 20, 71, 231));
        groupBox->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Ae.png);"));
        alarm_on_pushButton = new QPushButton(groupBox);
        alarm_on_pushButton->setObjectName(QString::fromUtf8("alarm_on_pushButton"));
        alarm_on_pushButton->setGeometry(QRect(10, 130, 55, 50));
        alarm_on_pushButton->setMinimumSize(QSize(55, 50));
        alarm_on_pushButton->setMaximumSize(QSize(55, 50));
        alarm_on_pushButton->setStyleSheet(QString::fromUtf8("image: url(:/images/alert_on.png);"));
        alarm_label_1 = new QLabel(groupBox);
        alarm_label_1->setObjectName(QString::fromUtf8("alarm_label_1"));
        alarm_label_1->setGeometry(QRect(10, 190, 41, 21));
        alarm_label_1->setFont(font);
        alarm_label_1->setStyleSheet(QString::fromUtf8("color:#0033ff;"));
        light_on_pushButton = new QPushButton(groupBox);
        light_on_pushButton->setObjectName(QString::fromUtf8("light_on_pushButton"));
        light_on_pushButton->setGeometry(QRect(10, 20, 40, 54));
        light_on_pushButton->setMinimumSize(QSize(40, 54));
        light_on_pushButton->setMaximumSize(QSize(40, 54));
        light_on_pushButton->setStyleSheet(QString::fromUtf8("image: url(:/images/bulb_on.png);"));
        light_label_1 = new QLabel(groupBox);
        light_label_1->setObjectName(QString::fromUtf8("light_label_1"));
        light_label_1->setGeometry(QRect(10, 80, 41, 21));
        light_label_1->setFont(font);
        light_label_1->setStyleSheet(QString::fromUtf8("color:#0033ff;"));
        light_off_pushButton = new QPushButton(groupBox);
        light_off_pushButton->setObjectName(QString::fromUtf8("light_off_pushButton"));
        light_off_pushButton->setGeometry(QRect(10, 20, 40, 54));
        light_off_pushButton->setMinimumSize(QSize(40, 54));
        light_off_pushButton->setMaximumSize(QSize(40, 54));
        light_off_pushButton->setStyleSheet(QString::fromUtf8("image: url(:/images/bulb_off.png);"));
        alarm_off_pushButton = new QPushButton(groupBox);
        alarm_off_pushButton->setObjectName(QString::fromUtf8("alarm_off_pushButton"));
        alarm_off_pushButton->setGeometry(QRect(10, 130, 55, 50));
        alarm_off_pushButton->setMinimumSize(QSize(55, 50));
        alarm_off_pushButton->setMaximumSize(QSize(55, 50));
        alarm_off_pushButton->setStyleSheet(QString::fromUtf8("image: url(:/images/alert_off.png);"));
        steu_groupBox = new QGroupBox(ControlDota);
        steu_groupBox->setObjectName(QString::fromUtf8("steu_groupBox"));
        steu_groupBox->setGeometry(QRect(10, 40, 111, 71));
        one_pushButton = new QPushButton(steu_groupBox);
        one_pushButton->setObjectName(QString::fromUtf8("one_pushButton"));
        one_pushButton->setGeometry(QRect(0, 0, 51, 31));
        QFont font1;
        font1.setPointSize(18);
        one_pushButton->setFont(font1);
        two_pushButton = new QPushButton(steu_groupBox);
        two_pushButton->setObjectName(QString::fromUtf8("two_pushButton"));
        two_pushButton->setGeometry(QRect(0, 40, 51, 31));
        two_pushButton->setFont(font1);
        thr_pushButton = new QPushButton(steu_groupBox);
        thr_pushButton->setObjectName(QString::fromUtf8("thr_pushButton"));
        thr_pushButton->setGeometry(QRect(60, 0, 51, 31));
        thr_pushButton->setFont(font1);
        stop_pushButton = new QPushButton(steu_groupBox);
        stop_pushButton->setObjectName(QString::fromUtf8("stop_pushButton"));
        stop_pushButton->setGeometry(QRect(60, 40, 51, 31));
        stop_pushButton->setFont(font1);

        retranslateUi(ControlDota);

        QMetaObject::connectSlotsByName(ControlDota);
    } // setupUi

    void retranslateUi(QDialog *ControlDota)
    {
        ControlDota->setWindowTitle(QApplication::translate("ControlDota", "Dialog", 0, QApplication::UnicodeUTF8));
        wind_label_m->setText(QApplication::translate("ControlDota", "     \351\200\232\351\243\216", 0, QApplication::UnicodeUTF8));
        smg_label_m->setText(QApplication::translate("ControlDota", "      \345\274\200\350\256\276\345\244\207", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ControlDota", "    \345\274\200\351\243\216\346\211\207", 0, QApplication::UnicodeUTF8));
        return_pushButton->setText(QString());
        wind_off_pushButton_m->setText(QString());
        smg_off_pushButton_m->setText(QString());
        wind_on_pushButton_m->setText(QString());
        smg_on_pushButton_m->setText(QString());
        alarm_on_pushButton_m->setText(QString());
        alarm_off_pushButton_m->setText(QString());
        alarm_label_m->setText(QApplication::translate("ControlDota", "       \350\255\246\346\212\245", 0, QApplication::UnicodeUTF8));
        light_on_pushButton_m->setText(QString());
        light_label_m->setText(QApplication::translate("ControlDota", "     \350\241\245\345\205\211", 0, QApplication::UnicodeUTF8));
        light_off_pushButton_m->setText(QString());
        groupBox->setTitle(QApplication::translate("ControlDota", "Cortex-A8", 0, QApplication::UnicodeUTF8));
        alarm_on_pushButton->setText(QString());
        alarm_label_1->setText(QApplication::translate("ControlDota", " \351\200\232\347\237\245", 0, QApplication::UnicodeUTF8));
        light_on_pushButton->setText(QString());
        light_label_1->setText(QApplication::translate("ControlDota", "\345\274\200\347\201\257", 0, QApplication::UnicodeUTF8));
        light_off_pushButton->setText(QString());
        alarm_off_pushButton->setText(QString());
        steu_groupBox->setTitle(QString());
        one_pushButton->setText(QApplication::translate("ControlDota", "\344\270\200\346\241\243", 0, QApplication::UnicodeUTF8));
        two_pushButton->setText(QApplication::translate("ControlDota", "\344\272\214\346\241\243", 0, QApplication::UnicodeUTF8));
        thr_pushButton->setText(QApplication::translate("ControlDota", "\344\270\211\346\241\243", 0, QApplication::UnicodeUTF8));
        stop_pushButton->setText(QApplication::translate("ControlDota", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ControlDota: public Ui_ControlDota {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLDOTA_H

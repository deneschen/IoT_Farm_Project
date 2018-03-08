/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Apr 7 16:08:29 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *exit_pushButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *save_pushButton;
    QPushButton *exit_pushButton_2;
    QLabel *tem_label;
    QLabel *safe_label;
    QLabel *hum_label;
    QLabel *light_label;
    QPushButton *light_off_pushButton_m;
    QPushButton *smg_on_pushButton_m;
    QPushButton *wind_off_pushButton_m;
    QPushButton *alarm_on_pushButton_m;
    QPushButton *smg_off_pushButton_m;
    QPushButton *light_on_pushButton_m;
    QPushButton *wind_on_pushButton_m;
    QPushButton *alarm_off_pushButton_m;
    QTextBrowser *bat_textBrowser;
    QTextBrowser *light_textBrowser;
    QTextBrowser *temp_textBrowser;
    QTextBrowser *hum_textBrowser;
    QGroupBox *help_groupBox;
    QTextBrowser *help_textBrowser;
    QPushButton *know_pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1195, 725);
        MainWindow->setMinimumSize(QSize(1195, 725));
        MainWindow->setMaximumSize(QSize(1195, 725));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/image/bkg.png);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        exit_pushButton = new QPushButton(centralWidget);
        exit_pushButton->setObjectName(QString::fromUtf8("exit_pushButton"));
        exit_pushButton->setGeometry(QRect(410, 100, 100, 41));
        exit_pushButton->setSizeIncrement(QSize(100, 41));
        exit_pushButton->setBaseSize(QSize(100, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font1.setPointSize(18);
        exit_pushButton->setFont(font1);
        exit_pushButton->setStyleSheet(QString::fromUtf8("image: url(:/image/button.png);\n"
"color: rgb(255, 255, 127);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 180, 351, 231));
        label->setStyleSheet(QString::fromUtf8("image: url(:/image/ck.png);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(540, 180, 501, 231));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/image/xx.png);"));
        save_pushButton = new QPushButton(centralWidget);
        save_pushButton->setObjectName(QString::fromUtf8("save_pushButton"));
        save_pushButton->setGeometry(QRect(170, 100, 100, 41));
        save_pushButton->setSizeIncrement(QSize(100, 41));
        save_pushButton->setBaseSize(QSize(100, 41));
        save_pushButton->setFont(font1);
        save_pushButton->setStyleSheet(QString::fromUtf8("image: url(:/image/button.png);\n"
"color: rgb(0, 0, 255);"));
        exit_pushButton_2 = new QPushButton(centralWidget);
        exit_pushButton_2->setObjectName(QString::fromUtf8("exit_pushButton_2"));
        exit_pushButton_2->setGeometry(QRect(290, 100, 100, 41));
        exit_pushButton_2->setSizeIncrement(QSize(100, 41));
        exit_pushButton_2->setBaseSize(QSize(100, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\273\277\345\256\213"));
        font2.setPointSize(18);
        exit_pushButton_2->setFont(font2);
        exit_pushButton_2->setStyleSheet(QString::fromUtf8("image: url(:/image/button.png);\n"
"color: rgb(0, 0, 255);"));
        tem_label = new QLabel(centralWidget);
        tem_label->setObjectName(QString::fromUtf8("tem_label"));
        tem_label->setGeometry(QRect(410, 500, 61, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(12);
        tem_label->setFont(font3);
        tem_label->setStyleSheet(QString::fromUtf8("color:#ffff99;"));
        safe_label = new QLabel(centralWidget);
        safe_label->setObjectName(QString::fromUtf8("safe_label"));
        safe_label->setGeometry(QRect(200, 530, 91, 31));
        safe_label->setFont(font3);
        safe_label->setStyleSheet(QString::fromUtf8("color:#ff3300;"));
        hum_label = new QLabel(centralWidget);
        hum_label->setObjectName(QString::fromUtf8("hum_label"));
        hum_label->setGeometry(QRect(530, 600, 61, 31));
        hum_label->setFont(font3);
        hum_label->setStyleSheet(QString::fromUtf8("color:#ffff99;"));
        light_label = new QLabel(centralWidget);
        light_label->setObjectName(QString::fromUtf8("light_label"));
        light_label->setGeometry(QRect(410, 540, 61, 31));
        light_label->setFont(font3);
        light_label->setStyleSheet(QString::fromUtf8("color:#ffff99;"));
        light_off_pushButton_m = new QPushButton(centralWidget);
        light_off_pushButton_m->setObjectName(QString::fromUtf8("light_off_pushButton_m"));
        light_off_pushButton_m->setGeometry(QRect(880, 480, 55, 55));
        light_off_pushButton_m->setMinimumSize(QSize(55, 55));
        light_off_pushButton_m->setMaximumSize(QSize(55, 55));
        light_off_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/image/led.png);"));
        smg_on_pushButton_m = new QPushButton(centralWidget);
        smg_on_pushButton_m->setObjectName(QString::fromUtf8("smg_on_pushButton_m"));
        smg_on_pushButton_m->setGeometry(QRect(780, 560, 55, 55));
        smg_on_pushButton_m->setMinimumSize(QSize(55, 55));
        smg_on_pushButton_m->setMaximumSize(QSize(55, 55));
        smg_on_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/image/smg_1.png);"));
        wind_off_pushButton_m = new QPushButton(centralWidget);
        wind_off_pushButton_m->setObjectName(QString::fromUtf8("wind_off_pushButton_m"));
        wind_off_pushButton_m->setGeometry(QRect(740, 480, 55, 55));
        wind_off_pushButton_m->setMinimumSize(QSize(55, 55));
        wind_off_pushButton_m->setMaximumSize(QSize(55, 55));
        wind_off_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/image/wind.png);"));
        alarm_on_pushButton_m = new QPushButton(centralWidget);
        alarm_on_pushButton_m->setObjectName(QString::fromUtf8("alarm_on_pushButton_m"));
        alarm_on_pushButton_m->setGeometry(QRect(920, 560, 55, 55));
        alarm_on_pushButton_m->setMinimumSize(QSize(55, 55));
        alarm_on_pushButton_m->setMaximumSize(QSize(55, 55));
        alarm_on_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/image/alarm_1.png);"));
        smg_off_pushButton_m = new QPushButton(centralWidget);
        smg_off_pushButton_m->setObjectName(QString::fromUtf8("smg_off_pushButton_m"));
        smg_off_pushButton_m->setGeometry(QRect(780, 560, 55, 55));
        smg_off_pushButton_m->setMinimumSize(QSize(55, 55));
        smg_off_pushButton_m->setMaximumSize(QSize(55, 55));
        smg_off_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/image/smg.png);"));
        light_on_pushButton_m = new QPushButton(centralWidget);
        light_on_pushButton_m->setObjectName(QString::fromUtf8("light_on_pushButton_m"));
        light_on_pushButton_m->setGeometry(QRect(880, 480, 55, 55));
        light_on_pushButton_m->setMinimumSize(QSize(55, 55));
        light_on_pushButton_m->setMaximumSize(QSize(55, 55));
        light_on_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/image/led_1.png);"));
        wind_on_pushButton_m = new QPushButton(centralWidget);
        wind_on_pushButton_m->setObjectName(QString::fromUtf8("wind_on_pushButton_m"));
        wind_on_pushButton_m->setGeometry(QRect(740, 480, 55, 55));
        wind_on_pushButton_m->setMinimumSize(QSize(55, 55));
        wind_on_pushButton_m->setMaximumSize(QSize(55, 55));
        wind_on_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/image/wind_1.png);"));
        alarm_off_pushButton_m = new QPushButton(centralWidget);
        alarm_off_pushButton_m->setObjectName(QString::fromUtf8("alarm_off_pushButton_m"));
        alarm_off_pushButton_m->setGeometry(QRect(920, 560, 55, 55));
        alarm_off_pushButton_m->setMinimumSize(QSize(55, 55));
        alarm_off_pushButton_m->setMaximumSize(QSize(55, 55));
        alarm_off_pushButton_m->setStyleSheet(QString::fromUtf8("image: url(:/image/alarm.png);"));
        bat_textBrowser = new QTextBrowser(centralWidget);
        bat_textBrowser->setObjectName(QString::fromUtf8("bat_textBrowser"));
        bat_textBrowser->setGeometry(QRect(280, 610, 101, 31));
        bat_textBrowser->setStyleSheet(QString::fromUtf8("background-image: url(:/image/tembk.png);"));
        light_textBrowser = new QTextBrowser(centralWidget);
        light_textBrowser->setObjectName(QString::fromUtf8("light_textBrowser"));
        light_textBrowser->setGeometry(QRect(510, 540, 101, 31));
        light_textBrowser->setStyleSheet(QString::fromUtf8("background-image: url(:/image/tembk.png);"));
        temp_textBrowser = new QTextBrowser(centralWidget);
        temp_textBrowser->setObjectName(QString::fromUtf8("temp_textBrowser"));
        temp_textBrowser->setGeometry(QRect(510, 500, 101, 31));
        temp_textBrowser->setStyleSheet(QString::fromUtf8("background-image: url(:/image/tembk.png);"));
        hum_textBrowser = new QTextBrowser(centralWidget);
        hum_textBrowser->setObjectName(QString::fromUtf8("hum_textBrowser"));
        hum_textBrowser->setGeometry(QRect(610, 600, 101, 31));
        hum_textBrowser->setStyleSheet(QString::fromUtf8("background-image: url(:/image/tembk.png);"));
        help_groupBox = new QGroupBox(centralWidget);
        help_groupBox->setObjectName(QString::fromUtf8("help_groupBox"));
        help_groupBox->setGeometry(QRect(340, 160, 271, 331));
        help_groupBox->setStyleSheet(QString::fromUtf8("background-image: url(:/image/print.png);"));
        help_textBrowser = new QTextBrowser(help_groupBox);
        help_textBrowser->setObjectName(QString::fromUtf8("help_textBrowser"));
        help_textBrowser->setGeometry(QRect(10, 20, 251, 301));
        help_textBrowser->setStyleSheet(QString::fromUtf8("background-image: url(:/image/print.png);"));
        know_pushButton = new QPushButton(help_groupBox);
        know_pushButton->setObjectName(QString::fromUtf8("know_pushButton"));
        know_pushButton->setGeometry(QRect(170, 292, 81, 21));
        QFont font4;
        font4.setPointSize(12);
        know_pushButton->setFont(font4);
        know_pushButton->setStyleSheet(QString::fromUtf8("image: url(:/image/tembk.png);\n"
"background-color: rgb(255, 0, 0);"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        exit_pushButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QString());
        save_pushButton->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        exit_pushButton_2->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
        tem_label->setText(QApplication::translate("MainWindow", "  \346\270\251\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        safe_label->setText(QApplication::translate("MainWindow", "   \347\224\265\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        hum_label->setText(QApplication::translate("MainWindow", "  \346\271\277\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        light_label->setText(QApplication::translate("MainWindow", "  \345\205\211\347\205\247\357\274\232", 0, QApplication::UnicodeUTF8));
        light_off_pushButton_m->setText(QString());
        smg_on_pushButton_m->setText(QString());
        wind_off_pushButton_m->setText(QString());
        alarm_on_pushButton_m->setText(QString());
        smg_off_pushButton_m->setText(QString());
        light_on_pushButton_m->setText(QString());
        wind_on_pushButton_m->setText(QString());
        alarm_off_pushButton_m->setText(QString());
        help_groupBox->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        help_textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#5500ff;\">1\343\200\201\350\257\245\350\275\257\344\273\266\351\200\232\350\277\207Zigbee\344\270\216M0\350\277\233\350\241\214\346\227\240\347\272\277\351\200\232\344\277\241\343\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10p"
                        "t; color:#5500ff;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#5500ff;\">2\343\200\201\350\257\245\350\275\257\344\273\266\345\217\257\347\233\264\350\247\202\345\256\236\346\227\266\347\232\204\346\230\276\347\244\272M0\350\212\202\347\202\271\346\211\200\345\244\204\347\216\257\345\242\203\347\232\204\346\270\251\345\272\246\357\274\210\342\204\203\357\274\211\343\200\201\346\271\277\345\272\246\357\274\210RH\357\274\211\343\200\201\345\205\211\347\205\247\357\274\210Lax\357\274\211 \344\273\245\345\217\212\345\275\223\345\211\215M0\347\232\204\347\224\265\351\207\217\357\274\210V\357\274\211\347\212\266\346\200\201\343\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; color:#5500ff;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0p"
                        "x; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#5500ff;\">3\343\200\201\346\216\247\345\210\266\347\273\204\346\214\211\351\222\256\345\217\257\344\273\245\345\257\271M0\345\244\226\345\233\264\350\256\276\345\244\207\350\277\233\350\241\214\345\256\236\346\227\266\346\216\247\345\210\266\343\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; color:#5500ff;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#5500ff;\">4\343\200\201\344\277\235\345\255\230\350\256\260\345\275\225\345\212\237\350\203\275\357\274\214\351\200\232\350\277\207\346\210\252\345\261\217\357\274\214\345\217\257\344\273\245\351\232\217\346\227\266\344\277\235\345\255\230\345\275\223\345\211\215\351\241\265\351\235\242\344\277\241\346\201\257\343"
                        "\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; color:#5500ff;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#5500ff;\">5\343\200\201\350\257\245\350\275\257\344\273\266\347\211\210\346\235\203\347\224\261\345\210\200\345\241\224\345\233\242\351\230\237\346\211\200\346\234\211\357\274\214\345\246\202\351\234\200\346\272\220\347\240\201\357\274\214\345\217\221\351\202\256\344\273\266\345\210\260\357\274\232yiranshiwx@sina.com</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        know_pushButton->setText(QApplication::translate("MainWindow", "\347\237\245\351\201\223\344\272\206", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

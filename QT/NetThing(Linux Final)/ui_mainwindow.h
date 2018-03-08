/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Mar 28 18:21:45 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *passwd_lineEdit;
    QLineEdit *name_lineEdit;
    QPushButton *fogget_pushButton;
    QPushButton *login_pushButton;
    QPushButton *inname_pushButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 272);
        MainWindow->setMinimumSize(QSize(480, 272));
        MainWindow->setMaximumSize(QSize(480, 272));
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/images/name.png);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        passwd_lineEdit = new QLineEdit(centralWidget);
        passwd_lineEdit->setObjectName(QString::fromUtf8("passwd_lineEdit"));
        passwd_lineEdit->setGeometry(QRect(180, 120, 161, 21));
        name_lineEdit = new QLineEdit(centralWidget);
        name_lineEdit->setObjectName(QString::fromUtf8("name_lineEdit"));
        name_lineEdit->setGeometry(QRect(180, 70, 161, 21));
        fogget_pushButton = new QPushButton(centralWidget);
        fogget_pushButton->setObjectName(QString::fromUtf8("fogget_pushButton"));
        fogget_pushButton->setGeometry(QRect(270, 170, 71, 23));
        QFont font;
        font.setPointSize(18);
        fogget_pushButton->setFont(font);
        fogget_pushButton->setStyleSheet(QString::fromUtf8("color:#000099;"));
        login_pushButton = new QPushButton(centralWidget);
        login_pushButton->setObjectName(QString::fromUtf8("login_pushButton"));
        login_pushButton->setGeometry(QRect(180, 170, 71, 23));
        login_pushButton->setFont(font);
        login_pushButton->setStyleSheet(QString::fromUtf8("color:#000099;"));
        inname_pushButton = new QPushButton(centralWidget);
        inname_pushButton->setObjectName(QString::fromUtf8("inname_pushButton"));
        inname_pushButton->setGeometry(QRect(360, 40, 56, 28));
        inname_pushButton->setMinimumSize(QSize(56, 28));
        inname_pushButton->setMaximumSize(QSize(56, 28));
        inname_pushButton->setStyleSheet(QString::fromUtf8("image: url(:/images/keyboard.png);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 25));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        fogget_pushButton->setText(QApplication::translate("MainWindow", "\345\277\230\350\256\260\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        login_pushButton->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        inname_pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

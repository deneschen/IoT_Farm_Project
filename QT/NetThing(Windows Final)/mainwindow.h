#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLayout>  //
#include <QDebug>//

#include <QMainWindow>
#include "printdialog.h"

#include "win_qextserialport.h" //

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

    qint16 usMBCRC16( unsigned char * pucFrame, qint16 usLen );  //

private:
    Ui::MainWindow *ui;
    Win_QextSerialPort *myCom;  //
    QByteArray temp1;
    QByteArray temp;

private slots:
    void on_know_pushButton_clicked();
    void on_exit_pushButton_2_clicked();
    void on_save_pushButton_clicked();
    void on_alarm_on_pushButton_m_clicked();
    void on_alarm_off_pushButton_m_clicked();
    void on_smg_on_pushButton_m_clicked();
    void on_smg_off_pushButton_m_clicked();
    void on_light_on_pushButton_m_clicked();
    void on_light_off_pushButton_m_clicked();
    void on_wind_on_pushButton_m_clicked();
    void on_wind_off_pushButton_m_clicked();
    void on_exit_pushButton_clicked();

    void readMyCom();  //
};

#endif // MAINWINDOW_H

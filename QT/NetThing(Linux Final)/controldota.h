#ifndef CONTROLDOTA_H
#define CONTROLDOTA_H

#include <QDialog>
#include "monitor.h"

namespace Ui {
    class ControlDota;
}

class ControlDota : public QDialog {
    Q_OBJECT
public:
    ControlDota(QWidget *parent = 0);
    ~ControlDota();

    QString chose ;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ControlDota *ui;

private slots:

    void on_stop_pushButton_clicked();
    void on_thr_pushButton_clicked();
    void on_two_pushButton_clicked();
    void on_one_pushButton_clicked();

    void on_alarm_on_pushButton_clicked();
    void on_alarm_off_pushButton_clicked();

    void on_light_on_pushButton_clicked();
    void on_light_off_pushButton_clicked();

    void on_wind_on_pushButton_m_clicked();
    void on_wind_off_pushButton_m_clicked();

    void on_smg_on_pushButton_m_clicked();
    void on_smg_off_pushButton_m_clicked();

    void on_alarm_on_pushButton_m_clicked();
    void on_alarm_off_pushButton_m_clicked();

    void on_light_on_pushButton_m_clicked();
    void on_light_off_pushButton_m_clicked();


    void wind();
    void on_return_pushButton_clicked();
};

#endif // CONTROLDOTA_H





#ifndef SETDOTA_H
#define SETDOTA_H

#include <QDialog>
#include "monitor.h"
#include "keyinput.h"

namespace Ui {
    class SetDota;
}

class SetDota : public QDialog {
    Q_OBJECT
public:
    SetDota(QWidget *parent = 0);
    ~SetDota();
    KeyInput *a ;
protected:
    void changeEvent(QEvent *e);

private:
    Ui::SetDota *ui;

private slots:
    void on_sure_pushButton_clicked();
    void on_temup_pushButton_clicked();
    void on_return_pushButton_1_clicked();

    void temupslot(QString);
    void temdownslot(QString);
    void phoneslot(QString);
};

#endif // SETDOTA_H

#ifndef MONITOR_H
#define MONITOR_H

#include <QDialog>
#include "controldota.h"
#include "setdota.h"

namespace Ui {
    class Monitor;
}

class Monitor : public QDialog {
    Q_OBJECT
public:
    Monitor(QWidget *parent = 0);
    ~Monitor();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Monitor *ui;

private slots:

    void on_exit_pushButton_clicked();
    void on_ctl_pushButton_clicked();
    void on_set_pushButton_clicked();

    void refresh();
};

#endif // MONITOR_H

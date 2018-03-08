#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "monitor.h"
#include "keyinput.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    KeyInput *a ;
    
    QString name;
protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

private slots:   
    void on_inname_pushButton_clicked();
    void on_login_pushButton_clicked();

    void nameslot(QString);
    void passwdslot(QString);
};

#endif // MAINWINDOW_H

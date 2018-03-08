#ifndef KEYINPUT_H
#define KEYINPUT_H

#include <QDialog>
#include "keyinput.h"


namespace Ui {
    class KeyInput;
}

class KeyInput : public QDialog {
    Q_OBJECT
public:
    KeyInput(QWidget *parent = 0);
    ~KeyInput();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::KeyInput *ui;

private slots:
    void on_pushButton_phone_clicked();
    void on_pushButton_down_clicked();
    void on_pushButton_up_clicked();
    void on_pushButton_passwd_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_c_clicked();
    void on_pushButton_0_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_user_clicked();


signals:
       void namesignal(QString s);
signals:
       void passwdsignal(QString s);

signals:
       void temupsignal(QString s);
signals:
       void temdownsignal(QString s);
signals:
       void phonesignal(QString s);



};

#endif // KEYINPUT_H

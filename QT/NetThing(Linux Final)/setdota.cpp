#include "setdota.h"
#include "ui_setdota.h"
#include "keyinput.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <errno.h>

#define N 32

struct msg
{
        long type;
        long msgtype;
        unsigned char text[N];
};

struct setEnv
{
        int temMAX;
        int temMIN;
        int humMAX;
        int humMIN;
        int illMAX;
        int illMIN;
};


SetDota::SetDota(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetDota)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->a = new KeyInput();
    this->connect(this->a,SIGNAL(temupsignal(QString)),this,SLOT(temupslot(QString)));
    this->connect(this->a,SIGNAL(temdownsignal(QString)),this,SLOT(temdownslot(QString)));
    this->connect(this->a,SIGNAL(phonesignal(QString)),this,SLOT(phoneslot(QString)));
}

SetDota::~SetDota()
{
    delete ui;
}

void SetDota::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void SetDota::on_return_pushButton_1_clicked()
{

    Monitor *a = new Monitor();
    a->show();

    this->close();

}

void SetDota::on_temup_pushButton_clicked()
{
    a->show();
}

void SetDota::temupslot(QString s)
{
    ui->tem_up_lineEdit->setText(s);
}

void SetDota::temdownslot(QString s)
{
    ui->tem_down_lineEdit->setText(s);
}

void SetDota::phoneslot(QString s)
{
    ui->phone_lineEdit->setText(s);
}




void SetDota::on_sure_pushButton_clicked()
{
    key_t  key;
    struct setEnv new1;
    int msgid;
    struct msg msg_buf;

            memset(&msg_buf,0,sizeof(msg_buf));

            QString tMax = ui->tem_up_lineEdit->text();
            QString tMin = ui->tem_down_lineEdit->text();

            new1.temMAX = tMax.toInt() ;

            new1.temMIN = tMin.toInt() ;

            new1.humMAX = 0;
            new1.humMIN = 0;
            new1.illMAX = 0;
            new1.illMIN = 0;



            if((key = ftok("/app", 'g')) < 0)
            {
                    perror("ftok");
                    exit(1);
            }

            if((msgid = msgget(key, 0666)) < 0)
            {
                    perror("msgget");
                    exit(1);
            }

            memcpy (msg_buf.text+1, &new1, 24);

            msg_buf.type = 1L;
            msg_buf.msgtype = 5L;
            msg_buf.text[0] = 49;

            msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

}

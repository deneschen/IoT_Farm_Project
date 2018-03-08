#include "controldota.h"
#include "ui_controldota.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>


#define N 32

struct msg
{
        long type;
        long msgtype;
        unsigned char text[N];
};

char beepbuf[N];

char ledbuf[N];

ControlDota::ControlDota(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlDota)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    ui->steu_groupBox->setVisible(false);

    ui->alarm_on_pushButton->setVisible(false);
    ui->alarm_off_pushButton->setVisible(true);

    ui->light_on_pushButton->setVisible(false);
    ui->light_off_pushButton->setVisible(true);

    ui->wind_on_pushButton_m->setVisible(false);
    ui->wind_off_pushButton_m->setVisible(true);

    ui->smg_on_pushButton_m->setVisible(false);
    ui->smg_off_pushButton_m->setVisible(true);

    ui->alarm_on_pushButton_m->setVisible(false);
    ui->alarm_off_pushButton_m->setVisible(true);

    ui->light_on_pushButton_m->setVisible(false);
    ui->light_off_pushButton_m->setVisible(true);

}

ControlDota::~ControlDota()
{
    delete ui;
}

void ControlDota::changeEvent(QEvent *e)
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

void ControlDota::on_return_pushButton_clicked()
{

    Monitor *a = new Monitor();

    a->show();
    this->close();

}


void ControlDota::wind()
{

         key_t key;

         int msgid;
         struct msg msg_buf;
         memset(&msg_buf,0,sizeof(msg_buf));

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

        bzero (msg_buf.text, sizeof (msg_buf.text));

        if(chose == "0")
        {
            msg_buf.text[0] = 0x40;
            ui->steu_groupBox->setVisible(false);
            ui->wind_on_pushButton_m->setVisible(false);
            ui->wind_off_pushButton_m->setVisible(true);
        }
        if(chose == "1")
        {
            msg_buf.text[0] = 0x41;
            ui->wind_on_pushButton_m->setVisible(true);
            ui->wind_off_pushButton_m->setVisible(false);
        }
        if(chose == "2")
        {
            msg_buf.text[0] = 0x42;
            ui->wind_on_pushButton_m->setVisible(true);
            ui->wind_off_pushButton_m->setVisible(false);
        }
        if(chose == "3")
        {
             msg_buf.text[0] = 0x43;
             ui->wind_on_pushButton_m->setVisible(true);
             ui->wind_off_pushButton_m->setVisible(false);
        }

        msg_buf.type = 1L;
        msg_buf.msgtype = 4L;
        msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

}


void ControlDota::on_wind_off_pushButton_m_clicked()
{
       ui->steu_groupBox->setVisible(true);
       chose = "1";
       this->wind();
}

void ControlDota::on_one_pushButton_clicked()
{
    chose = "1";
    this->wind();
}

void ControlDota::on_two_pushButton_clicked()
{
    chose = "2";
    this->wind();
}

void ControlDota::on_thr_pushButton_clicked()
{
    chose = "3";
    this->wind();
}

void ControlDota::on_stop_pushButton_clicked()
{
    chose = "0";
    this->wind();
}


void ControlDota::on_light_off_pushButton_clicked()
{    
            key_t key;
            int msgid;

            struct msg msg_buf;
            memset(&msg_buf,0,sizeof(msg_buf));

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

           msg_buf.text[0] =17; // msg_buf.text[0] =16; 亮/灭 0001 0001

            msg_buf.type = 1L;
            msg_buf.msgtype = 1L;
            msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);


    ui->light_on_pushButton->setVisible(true);
    ui->light_off_pushButton->setVisible(false);
}

void ControlDota::on_smg_off_pushButton_m_clicked()
{
            key_t key;
            int msgid;
            struct msg msg_buf;
            memset(&msg_buf,0,sizeof(msg_buf));

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
            bzero (msg_buf.text, sizeof (msg_buf.text));
            msg_buf.text[0] = 0x78;

            msg_buf.type = 1L;
            msg_buf.msgtype = 4L;
            msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

    ui->smg_on_pushButton_m->setVisible(true);
    ui->smg_off_pushButton_m->setVisible(false);
}

void ControlDota::on_alarm_off_pushButton_clicked()
{
            key_t key;
            int msgid;

            struct msg msg_buf;
            memset(&msg_buf,0,sizeof(msg_buf));

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

            msg_buf.text[0] =1;

            msg_buf.type = 1L;
            msg_buf.msgtype = 2L;
            msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

    ui->alarm_on_pushButton->setVisible(true);
    ui->alarm_off_pushButton->setVisible(false);
}




void ControlDota::on_wind_on_pushButton_m_clicked()
{
    chose = "0";
    this->wind();

}

void ControlDota::on_light_on_pushButton_clicked()
{
    key_t key;
    int msgid;

    struct msg msg_buf;
    memset(&msg_buf,0,sizeof(msg_buf));

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

    msg_buf.text[0] =16; // msg_buf.text[0] =17; 灭/亮 0001 0000

    msg_buf.type = 1L;
    msg_buf.msgtype = 1L;
    msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);


    ui->light_on_pushButton->setVisible(false);
    ui->light_off_pushButton->setVisible(true);
}


void ControlDota::on_smg_on_pushButton_m_clicked()
{
            key_t key;
            int msgid;
            struct msg msg_buf;
            memset(&msg_buf,0,sizeof(msg_buf));

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

            bzero (msg_buf.text, sizeof (msg_buf.text));
            msg_buf.text[0] = 0x7f;

            msg_buf.type = 1L;
            msg_buf.msgtype = 4L;
            msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

    ui->smg_on_pushButton_m->setVisible(false);
    ui->smg_off_pushButton_m->setVisible(true);
}


void ControlDota::on_alarm_on_pushButton_clicked()
{
    key_t key;
    int msgid;

    struct msg msg_buf;
    memset(&msg_buf,0,sizeof(msg_buf));

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

    msg_buf.text[0] =0;

    msg_buf.type = 1L;
    msg_buf.msgtype = 2L;
    msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

    ui->alarm_on_pushButton->setVisible(false);
    ui->alarm_off_pushButton->setVisible(true);
}


void ControlDota::on_light_off_pushButton_m_clicked()
{
            key_t key;
            int msgid;
            struct msg msg_buf;
            memset(&msg_buf,0,sizeof(msg_buf));


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

            bzero (msg_buf.text, sizeof (msg_buf.text));

            msg_buf.text[0] = 0x61;

            msg_buf.type = 1L;
            msg_buf.msgtype = 4L;
            msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

    ui->light_on_pushButton_m->setVisible(true);
    ui->light_off_pushButton_m->setVisible(false);
}

void ControlDota::on_light_on_pushButton_m_clicked()
{
    key_t key;
    int msgid;
    struct msg msg_buf;
    memset(&msg_buf,0,sizeof(msg_buf));


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

    bzero (msg_buf.text, sizeof (msg_buf.text));

    msg_buf.text[0] = 0x60;

    msg_buf.type = 1L;
    msg_buf.msgtype = 4L;
    msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

    ui->light_on_pushButton_m->setVisible(false);
    ui->light_off_pushButton_m->setVisible(true);
}

void ControlDota::on_alarm_off_pushButton_m_clicked()
{
            key_t key;
            int msgid;
            struct msg msg_buf;
            memset(&msg_buf,0,sizeof(msg_buf));


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
            msg_buf.text[0] = 0x51;

            msg_buf.type = 1L;
            msg_buf.msgtype = 4L;
            msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

    ui->alarm_on_pushButton_m->setVisible(true);
    ui->alarm_off_pushButton_m->setVisible(false);
}

void ControlDota::on_alarm_on_pushButton_m_clicked()
{
    key_t key;
    int msgid;
    struct msg msg_buf;
    memset(&msg_buf,0,sizeof(msg_buf));


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
    msg_buf.text[0] = 0x50;

    msg_buf.type = 1L;
    msg_buf.msgtype = 4L;
    msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

    ui->alarm_on_pushButton_m->setVisible(false);
    ui->alarm_off_pushButton_m->setVisible(true);
}

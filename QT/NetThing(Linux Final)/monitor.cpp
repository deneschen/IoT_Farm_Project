#include "monitor.h"
#include "ui_monitor.h"

#include <QApplication>
#include <QTimer>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>
#include <sys/sem.h>
#include <unistd.h>
#include "sem.h"
#include "data_global.h"


#define N 1024
struct shm_addr
{
        char cgi_status;
        char qt_status;
        struct env_info_clien_addr rt_status;
};


Monitor::Monitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Monitor)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    this->refresh();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    timer->start(3000);

}

Monitor::~Monitor()
{
    delete ui;
}

void Monitor::changeEvent(QEvent *e)
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



void Monitor::on_set_pushButton_clicked()
{
    SetDota *a = new SetDota();
    a->show();

    this->close();
}

void Monitor::on_ctl_pushButton_clicked()
{
    ControlDota *a = new ControlDota();
    a->show();

    this->close();
}

void Monitor::on_exit_pushButton_clicked()
{
    this->close();
}


void Monitor::refresh()
{

    key_t key;
    int shmid,semid;
    struct shm_addr *shm_buf;


    if((key = ftok("/app",'i')) <0)
    {
        perror("ftok");
         exit(1);
    }


    if((semid  = semget(key, 1, 0666)) < 0)
    {
        perror("semget");
        exit(1);
    }

    if((shmid = shmget(key, N, 0666 )) == -1)
    {
        perror("shmget");
        exit(1);
    }

    if((shm_buf = (struct shm_addr*)shmat(shmid, NULL, 0)) == (void*)-1 )
    {
        perror("shmat");
        exit(1);
    }

    sem_p(semid,0);

    float ttt = shm_buf->rt_status.storage_no[1].temperature ;
    float hhh = shm_buf->rt_status.storage_no[1].humidity ;
    float iii = shm_buf->rt_status.storage_no[1].illumination ;
    sem_v (semid, 0);

    QString temperature = ("      "+QString::number(ttt,'f',1));
    QString humidity = ("      "+QString::number(hhh,'f',1));
    QString illumination = ("      "+QString::number(iii,'f',1));

    ui->temp_textBrowser->setText(temperature);
    ui->hum_textBrowser->setText(humidity);
    ui->light_textBrowser->setText(illumination);


}


#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include <qdebug.h>
#include <QTimer>

struct getEnvMsg
{
        unsigned char sto_no;
        unsigned char tem[2];
        unsigned char hum[2];
        unsigned char x;
        unsigned char y;
        unsigned char z;
        unsigned int ill;
        unsigned int battery;    
        unsigned int adc;
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("物联网仓库管理系统");
    //this->setWindowFlags(Qt::FramelessWindowHint);

    ui->wind_on_pushButton_m->setVisible(false);
    ui->wind_off_pushButton_m->setVisible(true);

    ui->smg_on_pushButton_m->setVisible(false);
    ui->smg_off_pushButton_m->setVisible(true);

    ui->alarm_on_pushButton_m->setVisible(false);
    ui->alarm_off_pushButton_m->setVisible(true);

    ui->light_on_pushButton_m->setVisible(false);
    ui->light_off_pushButton_m->setVisible(true);

    ui->help_groupBox->setVisible(false);

    struct PortSettings myComSetting = {BAUD115200,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,500};
    //定义一个结构体，用来存放串口各个参数

    this->myCom = new Win_QextSerialPort("com4",myComSetting,QextSerialBase::EventDriven);
    //定义串口对象，并传递参数，在构造函数里对其进行初始化

   // this->myCom = new Win_QextSerialPort("com4",QextSerialBase::Polling);
   // QTimer * readTimer = new QTimer(this);
   // readTimer->start(10);

    //以可读写方式打开串口
    this->myCom->open(QIODevice::ReadWrite);


   // QObject::connect(readTimer,SIGNAL(timeout()),this,SLOT(readMyCom()));

    QObject::connect(this->myCom,SIGNAL(readyRead()),this,SLOT(readMyCom()));
    //信号和槽函数关联，当串口缓冲区有数据时，进行读串口操作
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void MainWindow::readMyCom()     //读串口函数
{

    if(myCom->bytesAvailable() > 24 )
      {
        char *p;

             temp = myCom->read(1);
             p = temp.data();
             if (*p == 's')
             {
                 temp = myCom->read(3); //把 " s t ：e" 废掉

                 temp = myCom->readAll();
                 p = temp.data();
                      struct getEnvMsg *pack = (struct getEnvMsg *)p;

                      float temperature1 = (float)pack->tem[0] ;

                      float humidity1 = pack->hum[0] ;

                      float illumination1 = pack->ill;

                 float battery1 = pack->battery;
                       battery1 = (battery1*3.6)/1024.0 ;

                 QString temperature = ("     "+QString::number(temperature1,'f',1));
                 QString humidity = ("     "+QString::number(humidity1,'f',1));
                 QString illumination = ("     "+QString::number(illumination1 ,'f',1));
                 QString bat = ("     "+QString::number(battery1 ,'f',2));

                 ui->temp_textBrowser->setText(temperature);
                 ui->hum_textBrowser->setText(humidity);
                 ui->light_textBrowser->setText(illumination);
                 ui->bat_textBrowser->setText(bat);

             }

   }
}



void MainWindow::on_exit_pushButton_clicked()
{
    myCom->close();
    this->close();
}

void MainWindow::on_wind_off_pushButton_m_clicked()
{
    temp1.resize(1);
    temp1[0] = 0x42;
    myCom->write(temp1,qstrlen(temp1));
    ui->wind_on_pushButton_m->setVisible(true);
    ui->wind_off_pushButton_m->setVisible(false);
}

void MainWindow::on_wind_on_pushButton_m_clicked()
{
    temp1.resize(1);
    temp1[0] = 0x40;
    myCom->write(temp1,qstrlen(temp1));
    ui->wind_on_pushButton_m->setVisible(false);
    ui->wind_off_pushButton_m->setVisible(true);
}

void MainWindow::on_light_off_pushButton_m_clicked()
{
    temp1.resize(1);
    temp1[0] = 0x61;
    myCom->write(temp1,qstrlen(temp1));
    ui->light_on_pushButton_m->setVisible(true);
    ui->light_off_pushButton_m->setVisible(false);
}

void MainWindow::on_light_on_pushButton_m_clicked()
{
    temp1.resize(1);
    temp1[0] = 0x60;
    myCom->write(temp1,qstrlen(temp1));
    ui->light_on_pushButton_m->setVisible(false);
    ui->light_off_pushButton_m->setVisible(true);
}

void MainWindow::on_smg_off_pushButton_m_clicked()
{
    temp1.resize(1);
    temp1[0] = 0x78;
    myCom->write(temp1,qstrlen(temp1));
    ui->smg_on_pushButton_m->setVisible(true);
    ui->smg_off_pushButton_m->setVisible(false);
}

void MainWindow::on_smg_on_pushButton_m_clicked()
{
    temp1.resize(1);
    temp1[0] = 0x7f;
    myCom->write(temp1,qstrlen(temp1));
    ui->smg_on_pushButton_m->setVisible(false);
    ui->smg_off_pushButton_m->setVisible(true);
}

void MainWindow::on_alarm_off_pushButton_m_clicked()
{
    temp1.resize(1);
    temp1[0] = 0x51;
    myCom->write(temp1,qstrlen(temp1));
    ui->alarm_on_pushButton_m->setVisible(true);
    ui->alarm_off_pushButton_m->setVisible(false);
}

void MainWindow::on_alarm_on_pushButton_m_clicked()
{
    temp1.resize(1);
    temp1[0] = 0x50;
    myCom->write(temp1,qstrlen(temp1));
    ui->alarm_on_pushButton_m->setVisible(false);
    ui->alarm_off_pushButton_m->setVisible(true);
}

void MainWindow::on_save_pushButton_clicked()
{
    PrintDialog *a = new PrintDialog();
    a->show();
}


void MainWindow::on_exit_pushButton_2_clicked()
{
    ui->help_groupBox->setVisible(true);
}

void MainWindow::on_know_pushButton_clicked()
{
    ui->help_groupBox->setVisible(false);
}

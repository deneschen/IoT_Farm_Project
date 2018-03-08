#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "keyinput.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);    
    this->a = new KeyInput();
    this->connect(this->a,SIGNAL(namesignal(QString)),this,SLOT(nameslot(QString)));
    this->connect(this->a,SIGNAL(passwdsignal(QString)),this,SLOT(passwdslot(QString)));


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

void MainWindow::on_login_pushButton_clicked()
{
    Monitor *a = new Monitor();
    a->show();

    this->close();
}

void MainWindow::on_inname_pushButton_clicked()
{
      a->show();
}

void MainWindow::nameslot(QString s)
{
    ui->name_lineEdit->setText(s);
}

void MainWindow::passwdslot(QString s)
{
     ui->passwd_lineEdit->setText(s);
}

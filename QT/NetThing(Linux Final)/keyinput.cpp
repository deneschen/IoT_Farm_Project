#include "keyinput.h"
#include "ui_keyinput.h"


KeyInput::KeyInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KeyInput)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

}

KeyInput::~KeyInput()
{
    delete ui;
}

void KeyInput::changeEvent(QEvent *e)
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

void KeyInput::on_pushButton_1_clicked()
{
    QString str = ui->lineEdit->text();
    str = str+"1";
    ui->lineEdit->setText(str);
}

void KeyInput::on_pushButton_2_clicked()
{
    QString str = ui->lineEdit->text();
    str = str+"2";
    ui->lineEdit->setText(str);
}

void KeyInput::on_pushButton_3_clicked()
{
    QString str = ui->lineEdit->text();
    str = str+"3";
    ui->lineEdit->setText(str);
}

void KeyInput::on_pushButton_4_clicked()
{
    QString str = ui->lineEdit->text();
    str = str+"4";
    ui->lineEdit->setText(str);
}

void KeyInput::on_pushButton_5_clicked()
{
    QString str = ui->lineEdit->text();
    str = str+"5";
    ui->lineEdit->setText(str);
}

void KeyInput::on_pushButton_6_clicked()
{
    QString str = ui->lineEdit->text();
    str = str+"6";
    ui->lineEdit->setText(str);
}

void KeyInput::on_pushButton_7_clicked()
{
    QString str = ui->lineEdit->text();
    str = str+"7";
    ui->lineEdit->setText(str);
}

void KeyInput::on_pushButton_8_clicked()
{
    QString str = ui->lineEdit->text();
    str = str+"8";
    ui->lineEdit->setText(str);
}

void KeyInput::on_pushButton_9_clicked()
{
    QString str = ui->lineEdit->text();
    str = str+"9";
    ui->lineEdit->setText(str);
}

void KeyInput::on_pushButton_0_clicked()
{
    QString str = ui->lineEdit->text();
    str = str+"0";
    ui->lineEdit->setText(str);
}

void KeyInput::on_pushButton_c_clicked()
{
    ui->lineEdit->setText("");
}


void KeyInput::on_pushButton_cancel_clicked()
{
    this->close();
}

void KeyInput::on_pushButton_user_clicked()
{
    QString str = ui->lineEdit->text();
    emit namesignal(str);
    ui->lineEdit->setText("");
    this->close();
}

void KeyInput::on_pushButton_passwd_clicked()
{
    QString str = ui->lineEdit->text();
    emit passwdsignal(str);
    ui->lineEdit->setText("");
    this->close();
}


void KeyInput::on_pushButton_up_clicked()
{
    QString str = ui->lineEdit->text();
    emit temupsignal(str);
    ui->lineEdit->setText("");
    this->close();
}


void KeyInput::on_pushButton_down_clicked()
{
    QString str = ui->lineEdit->text();
    emit temdownsignal(str);
    ui->lineEdit->setText("");
    this->close();
}

void KeyInput::on_pushButton_phone_clicked()
{
    QString str = ui->lineEdit->text();
    emit phonesignal(str);ui->lineEdit->setText("");
    this->close();
}

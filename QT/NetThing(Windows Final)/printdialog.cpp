#include "printdialog.h"
#include "ui_printdialog.h"

#include <QTimer>
#include <QPixmap>
#include <QString>
#include "QFileDialog.h"
#include "QDesktopWidget"

PrintDialog::PrintDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->label->setVisible(false);


}

PrintDialog::~PrintDialog()
{
    delete ui;
}

void PrintDialog::changeEvent(QEvent *e)
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

void PrintDialog::on_GetButton_clicked()
{
    this->hide();
    ui->label->setVisible(true);
    if(ui->radioButton->isChecked())
    {
        timer= new QTimer;
        QObject::connect(timer, SIGNAL(timeout()),this,SLOT(shotScreen()));
        timer->start(ui->spinBox->value()*1000);
    }
    else
    {
       qApp->beep();
    }
}

void PrintDialog::shotScreen()
{
    pixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
    ui->label->setPixmap(pixmap.scaled(ui->label->size()));
    this->timer->stop();
    this->show();
}



void PrintDialog::on_SaveButton_clicked()
{//untitle
    QString format = "png";
    QString initialPath = QDir::currentPath()+tr("/±£´æ¼ÇÂ¼Îª.")+format;

    QString fileName = QFileDialog::getSaveFileName(this,tr("Save As"),
                                                    initialPath,
                                                    tr("%1 Files(*.%2);;All Files(*)")
                                                    .arg(format.toUpper())
                                                    .arg(format));

    if(! fileName.isEmpty())
    {
        pixmap.save(fileName, format.toAscii());
    }
}

void PrintDialog::on_ExitButton_clicked()
{
    this->close();

}

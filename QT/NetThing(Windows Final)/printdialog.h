#ifndef PRINTDIALOG_H
#define PRINTDIALOG_H

#include <QDialog>

namespace Ui {
    class PrintDialog;
}

class PrintDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrintDialog(QWidget *parent = 0);
    ~PrintDialog();
protected:
    void changeEvent(QEvent *e);

private:
    QPixmap pixmap;
    QTimer *timer;

private slots:
    void on_GetButton_clicked();
    void on_ExitButton_clicked();
    void on_SaveButton_clicked();
    void shotScreen();


private:
    Ui::PrintDialog *ui;
};

#endif // PRINTDIALOG_H

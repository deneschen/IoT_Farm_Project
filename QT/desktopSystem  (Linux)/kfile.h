#ifndef KFILE_H
#define KFILE_H

#include <QObject>

#include "pictureflow.h"
#define  kdir 0x1
#define  kfile 0x2
#define  ksys   0x3


class KFILE : public QObject
{
    Q_OBJECT
public:
    explicit KFILE(QObject *parent = 0);
    PictureFlow *picf;

public :  // wrap of the pic-flow
    void Outpicflow_files(QString&);
    QStringList findfiles(QString&);
    int getFileType(QString);


    QStringList list;
    void getexelist(QString);

signals:
    void FINISH();
public slots:
    void GOOD(int);

};

#endif // KFILE_H

#include <QDir>
#include "kfile.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <QProcess>
#include <qchar.h>




KFILE::KFILE(QObject *parent) :
    QObject(parent)
{


}


void KFILE::Outpicflow_files(QString &path)
{
     // QDir dir = QDir::current();

     QStringList list  = this->findfiles(path);
     int mark[256]={0};

     for(int i=0;i<list.count();i++)
        mark[i] = this->getFileType(list.at(i));


            this->picf = new PictureFlow ;

            this->connect(this->picf,SIGNAL(GO(int)),this,SLOT(GOOD(int)));
            this->connect(this,SIGNAL(FINISH()),this->picf,SLOT(update()));


#if defined(_WS_QWS) || defined(Q_WS_QWS)
  picf->showFullScreen();
  int ww = picf->width();
  int wh = picf->height();
  int dim = (ww > wh) ? wh : ww;
  dim = dim * 3 / 4;
  picf->setSlideSize(QSize(3*dim/5, dim));
#else
  picf->setSlideSize(QSize(2*70, 4*60));
  picf->resize(420, 340);
#endif

//传图
            QImage img;
            for(int i = 0; i < list.count(); i++)
            {
                if(img.load(list[i]))
                    picf->addSlide(img);

            }

            picf->setCenterIndex(picf->slideCount()/2);
            picf->setBackgroundColor(Qt::BlankCursor);//设置背景颜色
            picf->show();
     // return files;
}

QStringList KFILE::findfiles(QString &path)
{
    QStringList files;
    QDir dir(path);
    if(!path.isEmpty())
      dir = QDir(path);//读取目录

    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);//读取文件

    QFileInfoList list = dir.entryInfoList(QDir::Files,QDir::Name);
    for (int i = 0; i < list.size(); ++i)
    {
      QFileInfo fileInfo = list.at(i);
      files.append(dir.absoluteFilePath(fileInfo.fileName()));
    }

   return  files ;
}


int KFILE::getFileType(QString file)
{

    QFileInfo finfo(file);

     if(finfo.isDir())
     {
        return kdir;
     }else if(finfo.isFile())
     {
           return kfile;
     }else
     {
           //this is sys file
          //to  get the flle name without path
             QString s =  finfo.fileName();
             // check the sys icon list

             //return reserved

     }


}


void KFILE::getexelist(QString path1)
{


      char *path =  path1.toLatin1().data();
     // qDebug("%s\n",path);
    //  QStringList list;
          QString temp;
      char buffer[1];
      char buf[100];

      int file;
      int count ;
      unsigned int i=0;

      file = open(path1.toLatin1().data(),O_RDWR);

      while(read(file,buffer,1)>0)
                {

                            buf[i++]=*buffer;
                            if(*buffer=='\n')
                            {
                                     //i--;
                                    buf[--i]='\0';
                                    i=0;
                                   //qDebug("%s\n",buf);
                                    temp = QString(buf);
                                    list+=temp;
                            }
                }


/*
      for(int i=0;i<list.count();i++)
      {
          temp = list.at(i);
          qDebug("%s",temp.toLatin1().data());

      }
*/
}


/*to execute a new process and start a new Game*/

void KFILE::GOOD(int index)
{

    QString tmp = list.at(index);
    QChar c = QChar('\0');
   /*

   int size = tmp.toLatin1().size();
   char *p = tmp.toLatin1().data();
   // char tm = t.at(0);
    p++;
    char *p2 = p ;
    p=p+(size-1);
    *p = '\0';
   */

      /*the following code help u to pick up the exe absolute path from config file*/

     char *pp = tmp.toLatin1().data();
     tmp = QString(++pp);
     tmp.replace(tmp.size(),1,&c,1);

     QProcess *myp = new QProcess();
     QStringList list;
     list<<QString("-qws");
     myp->execute(tmp,list);

     emit FINISH(); //to update the framebuffer


}


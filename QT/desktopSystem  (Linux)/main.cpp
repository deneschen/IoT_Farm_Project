/*
  PictureFlow - animated image show widget
  http://pictureflow.googlecode.com

  Copyright (C) 2008 Ariya Hidayat (ariya@kde.org)
  Copyright (C) 2007 Ariya Hidayat (ariya@kde.org)

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#include <qapplication.h>
#include <qdir.h>
#include <qevent.h>
#include <qfileinfo.h>
#include <qimage.h>
#include <QTime>

#include "pictureflow.h"
#include "kfile.h"


int main( int argc, char ** argv )
{
  QApplication* app = new QApplication( argc, argv );


   /*TO hide the cursor on LCD*/
   qApp->setOverrideCursor(QCursor(Qt::BlankCursor));

   KFILE *kf = new KFILE;
   QString s("/home/App/");
   kf->Outpicflow_files(s);
   kf->getexelist(QString("/home/config"));

/*


*/



  app->connect( app, SIGNAL(lastWindowClosed()), app, SLOT(quit()));
  int result = app->exec();

  delete app;
  return result;
}

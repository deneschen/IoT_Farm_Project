/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Apr 7 15:01:37 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      41,   11,   11,   11, 0x08,
      72,   11,   11,   11, 0x08,
     101,   11,   11,   11, 0x08,
     136,   11,   11,   11, 0x08,
     172,   11,   11,   11, 0x08,
     205,   11,   11,   11, 0x08,
     239,   11,   11,   11, 0x08,
     274,   11,   11,   11, 0x08,
     310,   11,   11,   11, 0x08,
     344,   11,   11,   11, 0x08,
     379,   11,   11,   11, 0x08,
     408,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_know_pushButton_clicked()\0"
    "on_exit_pushButton_2_clicked()\0"
    "on_save_pushButton_clicked()\0"
    "on_alarm_on_pushButton_m_clicked()\0"
    "on_alarm_off_pushButton_m_clicked()\0"
    "on_smg_on_pushButton_m_clicked()\0"
    "on_smg_off_pushButton_m_clicked()\0"
    "on_light_on_pushButton_m_clicked()\0"
    "on_light_off_pushButton_m_clicked()\0"
    "on_wind_on_pushButton_m_clicked()\0"
    "on_wind_off_pushButton_m_clicked()\0"
    "on_exit_pushButton_clicked()\0readMyCom()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_know_pushButton_clicked(); break;
        case 1: on_exit_pushButton_2_clicked(); break;
        case 2: on_save_pushButton_clicked(); break;
        case 3: on_alarm_on_pushButton_m_clicked(); break;
        case 4: on_alarm_off_pushButton_m_clicked(); break;
        case 5: on_smg_on_pushButton_m_clicked(); break;
        case 6: on_smg_off_pushButton_m_clicked(); break;
        case 7: on_light_on_pushButton_m_clicked(); break;
        case 8: on_light_off_pushButton_m_clicked(); break;
        case 9: on_wind_on_pushButton_m_clicked(); break;
        case 10: on_wind_off_pushButton_m_clicked(); break;
        case 11: on_exit_pushButton_clicked(); break;
        case 12: readMyCom(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

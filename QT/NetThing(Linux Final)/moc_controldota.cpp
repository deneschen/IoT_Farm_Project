/****************************************************************************
** Meta object code from reading C++ file 'controldota.h'
**
** Created: Sat Apr 7 10:43:16 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "controldota.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controldota.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ControlDota[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      42,   12,   12,   12, 0x08,
      70,   12,   12,   12, 0x08,
      98,   12,   12,   12, 0x08,
     126,   12,   12,   12, 0x08,
     159,   12,   12,   12, 0x08,
     193,   12,   12,   12, 0x08,
     226,   12,   12,   12, 0x08,
     260,   12,   12,   12, 0x08,
     294,   12,   12,   12, 0x08,
     329,   12,   12,   12, 0x08,
     362,   12,   12,   12, 0x08,
     396,   12,   12,   12, 0x08,
     431,   12,   12,   12, 0x08,
     467,   12,   12,   12, 0x08,
     502,   12,   12,   12, 0x08,
     538,   12,   12,   12, 0x08,
     545,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ControlDota[] = {
    "ControlDota\0\0on_stop_pushButton_clicked()\0"
    "on_thr_pushButton_clicked()\0"
    "on_two_pushButton_clicked()\0"
    "on_one_pushButton_clicked()\0"
    "on_alarm_on_pushButton_clicked()\0"
    "on_alarm_off_pushButton_clicked()\0"
    "on_light_on_pushButton_clicked()\0"
    "on_light_off_pushButton_clicked()\0"
    "on_wind_on_pushButton_m_clicked()\0"
    "on_wind_off_pushButton_m_clicked()\0"
    "on_smg_on_pushButton_m_clicked()\0"
    "on_smg_off_pushButton_m_clicked()\0"
    "on_alarm_on_pushButton_m_clicked()\0"
    "on_alarm_off_pushButton_m_clicked()\0"
    "on_light_on_pushButton_m_clicked()\0"
    "on_light_off_pushButton_m_clicked()\0"
    "wind()\0on_return_pushButton_clicked()\0"
};

const QMetaObject ControlDota::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ControlDota,
      qt_meta_data_ControlDota, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ControlDota::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ControlDota::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ControlDota::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControlDota))
        return static_cast<void*>(const_cast< ControlDota*>(this));
    return QDialog::qt_metacast(_clname);
}

int ControlDota::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_stop_pushButton_clicked(); break;
        case 1: on_thr_pushButton_clicked(); break;
        case 2: on_two_pushButton_clicked(); break;
        case 3: on_one_pushButton_clicked(); break;
        case 4: on_alarm_on_pushButton_clicked(); break;
        case 5: on_alarm_off_pushButton_clicked(); break;
        case 6: on_light_on_pushButton_clicked(); break;
        case 7: on_light_off_pushButton_clicked(); break;
        case 8: on_wind_on_pushButton_m_clicked(); break;
        case 9: on_wind_off_pushButton_m_clicked(); break;
        case 10: on_smg_on_pushButton_m_clicked(); break;
        case 11: on_smg_off_pushButton_m_clicked(); break;
        case 12: on_alarm_on_pushButton_m_clicked(); break;
        case 13: on_alarm_off_pushButton_m_clicked(); break;
        case 14: on_light_on_pushButton_m_clicked(); break;
        case 15: on_light_off_pushButton_m_clicked(); break;
        case 16: wind(); break;
        case 17: on_return_pushButton_clicked(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

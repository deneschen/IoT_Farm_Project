/****************************************************************************
** Meta object code from reading C++ file 'kfile.h'
**
** Created: Tue Mar 20 13:27:59 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "kfile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kfile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KFILE[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      16,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_KFILE[] = {
    "KFILE\0\0FINISH()\0GOOD(int)\0"
};

const QMetaObject KFILE::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KFILE,
      qt_meta_data_KFILE, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KFILE::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KFILE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KFILE::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KFILE))
        return static_cast<void*>(const_cast< KFILE*>(this));
    return QObject::qt_metacast(_clname);
}

int KFILE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: FINISH(); break;
        case 1: GOOD((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void KFILE::FINISH()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

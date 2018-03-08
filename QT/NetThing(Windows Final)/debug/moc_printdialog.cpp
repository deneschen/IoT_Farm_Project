/****************************************************************************
** Meta object code from reading C++ file 'printdialog.h'
**
** Created: Thu Mar 29 17:31:43 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../printdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PrintDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      36,   12,   12,   12, 0x08,
      60,   12,   12,   12, 0x08,
      84,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PrintDialog[] = {
    "PrintDialog\0\0on_GetButton_clicked()\0"
    "on_ExitButton_clicked()\0on_SaveButton_clicked()\0"
    "shotScreen()\0"
};

const QMetaObject PrintDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PrintDialog,
      qt_meta_data_PrintDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PrintDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PrintDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PrintDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrintDialog))
        return static_cast<void*>(const_cast< PrintDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PrintDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_GetButton_clicked(); break;
        case 1: on_ExitButton_clicked(); break;
        case 2: on_SaveButton_clicked(); break;
        case 3: shotScreen(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

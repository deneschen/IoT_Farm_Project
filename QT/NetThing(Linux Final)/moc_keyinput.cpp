/****************************************************************************
** Meta object code from reading C++ file 'keyinput.h'
**
** Created: Tue Mar 27 16:25:34 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "keyinput.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keyinput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KeyInput[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   10,    9,    9, 0x05,
      32,   10,    9,    9, 0x05,
      54,   10,    9,    9, 0x05,
      75,   10,    9,    9, 0x05,
      98,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     119,    9,    9,    9, 0x08,
     149,    9,    9,    9, 0x08,
     178,    9,    9,    9, 0x08,
     205,    9,    9,    9, 0x08,
     236,    9,    9,    9, 0x08,
     267,    9,    9,    9, 0x08,
     293,    9,    9,    9, 0x08,
     319,    9,    9,    9, 0x08,
     345,    9,    9,    9, 0x08,
     371,    9,    9,    9, 0x08,
     397,    9,    9,    9, 0x08,
     423,    9,    9,    9, 0x08,
     449,    9,    9,    9, 0x08,
     475,    9,    9,    9, 0x08,
     501,    9,    9,    9, 0x08,
     527,    9,    9,    9, 0x08,
     553,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_KeyInput[] = {
    "KeyInput\0\0s\0namesignal(QString)\0"
    "passwdsignal(QString)\0temupsignal(QString)\0"
    "temdownsignal(QString)\0phonesignal(QString)\0"
    "on_pushButton_phone_clicked()\0"
    "on_pushButton_down_clicked()\0"
    "on_pushButton_up_clicked()\0"
    "on_pushButton_passwd_clicked()\0"
    "on_pushButton_cancel_clicked()\0"
    "on_pushButton_c_clicked()\0"
    "on_pushButton_0_clicked()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_1_clicked()\0"
    "on_pushButton_user_clicked()\0"
};

const QMetaObject KeyInput::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_KeyInput,
      qt_meta_data_KeyInput, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KeyInput::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KeyInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KeyInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KeyInput))
        return static_cast<void*>(const_cast< KeyInput*>(this));
    return QDialog::qt_metacast(_clname);
}

int KeyInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: namesignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: passwdsignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: temupsignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: temdownsignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: phonesignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: on_pushButton_phone_clicked(); break;
        case 6: on_pushButton_down_clicked(); break;
        case 7: on_pushButton_up_clicked(); break;
        case 8: on_pushButton_passwd_clicked(); break;
        case 9: on_pushButton_cancel_clicked(); break;
        case 10: on_pushButton_c_clicked(); break;
        case 11: on_pushButton_0_clicked(); break;
        case 12: on_pushButton_9_clicked(); break;
        case 13: on_pushButton_8_clicked(); break;
        case 14: on_pushButton_7_clicked(); break;
        case 15: on_pushButton_6_clicked(); break;
        case 16: on_pushButton_5_clicked(); break;
        case 17: on_pushButton_4_clicked(); break;
        case 18: on_pushButton_3_clicked(); break;
        case 19: on_pushButton_2_clicked(); break;
        case 20: on_pushButton_1_clicked(); break;
        case 21: on_pushButton_user_clicked(); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void KeyInput::namesignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KeyInput::passwdsignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KeyInput::temupsignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KeyInput::temdownsignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KeyInput::phonesignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE

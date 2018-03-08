/****************************************************************************
** Meta object code from reading C++ file 'pictureflow.h'
**
** Created: Tue Mar 20 13:28:00 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pictureflow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pictureflow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PictureFlow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       4,  109, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x05,
      43,   12,   12,   12, 0x05,
      54,   12,   12,   12, 0x05,
      65,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   73,   12,   12, 0x0a,
     103,   96,   12,   12, 0x0a,
     133,  121,   12,   12, 0x0a,
     167,  154,   12,   12, 0x0a,
     189,   13,   12,   12, 0x0a,
     209,   12,   12,   12, 0x0a,
     217,   12,   12,   12, 0x0a,
     232,   12,   12,   12, 0x0a,
     243,   13,   12,   12, 0x0a,
     258,   12,   12,   12, 0x0a,
     267,   12,   12,   12, 0x0a,
     283,   12,   12,   12, 0x0a,
     291,   12,   12,   12, 0x0a,
     298,   12,   12,   12, 0x0a,
     310,   12,   12,   12, 0x08,

 // properties: name, type, flags
     335,  328, 0x43095103,
     357,  351, 0x15095103,
     371,  367, 0x02095001,
     382,  367, 0x02095103,

       0        // eod
};

static const char qt_meta_stringdata_PictureFlow[] = {
    "PictureFlow\0\0index\0centerIndexChanged(int)\0"
    "sig_test()\0sig_tail()\0GO(int)\0image\0"
    "addSlide(QImage)\0pixmap\0addSlide(QPixmap)\0"
    "index,image\0setSlide(int,QImage)\0"
    "index,pixmap\0setSlide(int,QPixmap)\0"
    "setCenterIndex(int)\0clear()\0showPrevious()\0"
    "showNext()\0showSlide(int)\0render()\0"
    "triggerRender()\0print()\0test()\0"
    "show_tail()\0updateAnimation()\0QColor\0"
    "backgroundColor\0QSize\0slideSize\0int\0"
    "slideCount\0centerIndex\0"
};

const QMetaObject PictureFlow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PictureFlow,
      qt_meta_data_PictureFlow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PictureFlow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PictureFlow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PictureFlow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PictureFlow))
        return static_cast<void*>(const_cast< PictureFlow*>(this));
    return QWidget::qt_metacast(_clname);
}

int PictureFlow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: centerIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: sig_test(); break;
        case 2: sig_tail(); break;
        case 3: GO((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: addSlide((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 5: addSlide((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 6: setSlide((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2]))); break;
        case 7: setSlide((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 8: setCenterIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: clear(); break;
        case 10: showPrevious(); break;
        case 11: showNext(); break;
        case 12: showSlide((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: render(); break;
        case 14: triggerRender(); break;
        case 15: print(); break;
        case 16: test(); break;
        case 17: show_tail(); break;
        case 18: updateAnimation(); break;
        default: ;
        }
        _id -= 19;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = backgroundColor(); break;
        case 1: *reinterpret_cast< QSize*>(_v) = slideSize(); break;
        case 2: *reinterpret_cast< int*>(_v) = slideCount(); break;
        case 3: *reinterpret_cast< int*>(_v) = centerIndex(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setBackgroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: setSlideSize(*reinterpret_cast< QSize*>(_v)); break;
        case 3: setCenterIndex(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void PictureFlow::centerIndexChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PictureFlow::sig_test()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void PictureFlow::sig_tail()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void PictureFlow::GO(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

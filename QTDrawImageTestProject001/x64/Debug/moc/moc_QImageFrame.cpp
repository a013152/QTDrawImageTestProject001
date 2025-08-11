/****************************************************************************
** Meta object code from reading C++ file 'QImageFrame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QImageFrame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QImageFrame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QImageFrame_t {
    QByteArrayData data[10];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QImageFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QImageFrame_t qt_meta_stringdata_QImageFrame = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QImageFrame"
QT_MOC_LITERAL(1, 12, 14), // "SigCloneCanvas"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "QPixmap*"
QT_MOC_LITERAL(4, 37, 4), // "pPix"
QT_MOC_LITERAL(5, 42, 7), // "QPoint&"
QT_MOC_LITERAL(6, 50, 2), // "pt"
QT_MOC_LITERAL(7, 53, 24), // "SigShowImageInMainThread"
QT_MOC_LITERAL(8, 78, 13), // "OnCloneCanvas"
QT_MOC_LITERAL(9, 92, 23) // "OnShowImageInMainThread"

    },
    "QImageFrame\0SigCloneCanvas\0\0QPixmap*\0"
    "pPix\0QPoint&\0pt\0SigShowImageInMainThread\0"
    "OnCloneCanvas\0OnShowImageInMainThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QImageFrame[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       7,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   40,    2, 0x0a /* Public */,
       9,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,

       0        // eod
};

void QImageFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QImageFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SigCloneCanvas((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 1: _t->SigShowImageInMainThread(); break;
        case 2: _t->OnCloneCanvas((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 3: _t->OnShowImageInMainThread(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QImageFrame::*)(QPixmap * , QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QImageFrame::SigCloneCanvas)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QImageFrame::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QImageFrame::SigShowImageInMainThread)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QImageFrame::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_QImageFrame.data,
    qt_meta_data_QImageFrame,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QImageFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QImageFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QImageFrame.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int QImageFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QImageFrame::SigCloneCanvas(QPixmap * _t1, QPoint & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QImageFrame::SigShowImageInMainThread()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

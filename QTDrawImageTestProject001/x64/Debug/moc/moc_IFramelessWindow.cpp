/****************************************************************************
** Meta object code from reading C++ file 'IFramelessWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../IFramelessWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IFramelessWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IFramelessWindow_t {
    QByteArrayData data[6];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IFramelessWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IFramelessWindow_t qt_meta_stringdata_IFramelessWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "IFramelessWindow"
QT_MOC_LITERAL(1, 17, 15), // "SigWindowClosed"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "FORM_TYPE_e"
QT_MOC_LITERAL(4, 46, 5), // "eForm"
QT_MOC_LITERAL(5, 52, 14) // "OnClickBtnExit"

    },
    "IFramelessWindow\0SigWindowClosed\0\0"
    "FORM_TYPE_e\0eForm\0OnClickBtnExit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IFramelessWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   27,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void IFramelessWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IFramelessWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SigWindowClosed((*reinterpret_cast< FORM_TYPE_e(*)>(_a[1]))); break;
        case 1: _t->OnClickBtnExit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IFramelessWindow::*)(FORM_TYPE_e );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IFramelessWindow::SigWindowClosed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IFramelessWindow::staticMetaObject = { {
    &IFramelessWidget<QFrame>::staticMetaObject,
    qt_meta_stringdata_IFramelessWindow.data,
    qt_meta_data_IFramelessWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IFramelessWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IFramelessWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IFramelessWindow.stringdata0))
        return static_cast<void*>(this);
    return IFramelessWidget<QFrame>::qt_metacast(_clname);
}

int IFramelessWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IFramelessWidget<QFrame>::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void IFramelessWindow::SigWindowClosed(FORM_TYPE_e _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'modelview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/views/modelview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modelview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ModelView_t {
    QByteArrayData data[9];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModelView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModelView_t qt_meta_stringdata_ModelView = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ModelView"
QT_MOC_LITERAL(1, 10, 18), // "interpreterChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "Interpreter"
QT_MOC_LITERAL(4, 42, 7), // "addFile"
QT_MOC_LITERAL(5, 50, 10), // "removeFile"
QT_MOC_LITERAL(6, 61, 10), // "renameFile"
QT_MOC_LITERAL(7, 72, 20), // "onInterpreterChanged"
QT_MOC_LITERAL(8, 93, 1) // "r"

    },
    "ModelView\0interpreterChanged\0\0Interpreter\0"
    "addFile\0removeFile\0renameFile\0"
    "onInterpreterChanged\0r"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void ModelView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModelView *_t = static_cast<ModelView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->interpreterChanged((*reinterpret_cast< Interpreter(*)>(_a[1]))); break;
        case 1: _t->addFile(); break;
        case 2: _t->removeFile(); break;
        case 3: _t->renameFile(); break;
        case 4: _t->onInterpreterChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ModelView::*_t)(Interpreter );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelView::interpreterChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ModelView::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_ModelView.data,
      qt_meta_data_ModelView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ModelView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ModelView.stringdata0))
        return static_cast<void*>(const_cast< ModelView*>(this));
    return QFrame::qt_metacast(_clname);
}

int ModelView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ModelView::interpreterChanged(Interpreter _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

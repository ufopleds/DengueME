/****************************************************************************
** Meta object code from reading C++ file 'modelbuilder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../builder/modelbuilder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modelbuilder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ModelBuilder_t {
    QByteArrayData data[15];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModelBuilder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModelBuilder_t qt_meta_stringdata_ModelBuilder = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ModelBuilder"
QT_MOC_LITERAL(1, 13, 15), // "openModelWizard"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14), // "modelActivated"
QT_MOC_LITERAL(4, 45, 5), // "index"
QT_MOC_LITERAL(5, 51, 16), // "selectionChanged"
QT_MOC_LITERAL(6, 68, 7), // "current"
QT_MOC_LITERAL(7, 76, 8), // "previous"
QT_MOC_LITERAL(8, 85, 13), // "onModelClosed"
QT_MOC_LITERAL(9, 99, 11), // "deleteModel"
QT_MOC_LITERAL(10, 111, 9), // "editModel"
QT_MOC_LITERAL(11, 121, 8), // "newModel"
QT_MOC_LITERAL(12, 130, 10), // "setToolbar"
QT_MOC_LITERAL(13, 141, 1), // "i"
QT_MOC_LITERAL(14, 143, 11) // "actionClose"

    },
    "ModelBuilder\0openModelWizard\0\0"
    "modelActivated\0index\0selectionChanged\0"
    "current\0previous\0onModelClosed\0"
    "deleteModel\0editModel\0newModel\0"
    "setToolbar\0i\0actionClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelBuilder[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    1,   65,    2, 0x08 /* Private */,
       5,    2,   68,    2, 0x08 /* Private */,
       5,    1,   73,    2, 0x28 /* Private | MethodCloned */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    1,   80,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    6,    7,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void ModelBuilder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModelBuilder *_t = static_cast<ModelBuilder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openModelWizard(); break;
        case 1: _t->modelActivated((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->selectionChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 3: _t->selectionChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->onModelClosed(); break;
        case 5: _t->deleteModel(); break;
        case 6: _t->editModel(); break;
        case 7: _t->newModel(); break;
        case 8: _t->setToolbar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->actionClose(); break;
        default: ;
        }
    }
}

const QMetaObject ModelBuilder::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ModelBuilder.data,
      qt_meta_data_ModelBuilder,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ModelBuilder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelBuilder::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ModelBuilder.stringdata0))
        return static_cast<void*>(const_cast< ModelBuilder*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ModelBuilder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

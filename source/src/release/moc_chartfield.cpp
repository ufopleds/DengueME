/****************************************************************************
** Meta object code from reading C++ file 'chartfield.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/components/chartfield.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chartfield.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChartField_t {
    QByteArrayData data[9];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChartField_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChartField_t qt_meta_stringdata_ChartField = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ChartField"
QT_MOC_LITERAL(1, 11, 16), // "onActionVariable"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "onActionDelete"
QT_MOC_LITERAL(4, 44, 13), // "onActionClone"
QT_MOC_LITERAL(5, 58, 8), // "offField"
QT_MOC_LITERAL(6, 67, 7), // "onField"
QT_MOC_LITERAL(7, 75, 10), // "validateId"
QT_MOC_LITERAL(8, 86, 9) // "purgeName"

    },
    "ChartField\0onActionVariable\0\0"
    "onActionDelete\0onActionClone\0offField\0"
    "onField\0validateId\0purgeName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChartField[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    1,   52,    2, 0x0a /* Public */,
       6,    1,   55,    2, 0x0a /* Public */,
       7,    1,   58,    2, 0x0a /* Public */,
       8,    1,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::QString, QMetaType::QString,    2,

       0        // eod
};

void ChartField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChartField *_t = static_cast<ChartField *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onActionVariable(); break;
        case 1: _t->onActionDelete(); break;
        case 2: _t->onActionClone(); break;
        case 3: _t->offField((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onField((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->validateId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: { QString _r = _t->purgeName((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject ChartField::staticMetaObject = {
    { &Component::staticMetaObject, qt_meta_stringdata_ChartField.data,
      qt_meta_data_ChartField,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChartField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChartField::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChartField.stringdata0))
        return static_cast<void*>(const_cast< ChartField*>(this));
    return Component::qt_metacast(_clname);
}

int ChartField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Component::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'logfield.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/components/logfield.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logfield.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LogField_t {
    QByteArrayData data[13];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogField_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogField_t qt_meta_stringdata_LogField = {
    {
QT_MOC_LITERAL(0, 0, 8), // "LogField"
QT_MOC_LITERAL(1, 9, 16), // "onActionVariable"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "onActionDelete"
QT_MOC_LITERAL(4, 42, 8), // "offField"
QT_MOC_LITERAL(5, 51, 6), // "enable"
QT_MOC_LITERAL(6, 58, 7), // "onField"
QT_MOC_LITERAL(7, 66, 14), // "useLogVariable"
QT_MOC_LITERAL(8, 81, 17), // "notUseLogVariable"
QT_MOC_LITERAL(9, 99, 10), // "validateId"
QT_MOC_LITERAL(10, 110, 9), // "purgeName"
QT_MOC_LITERAL(11, 120, 3), // "add"
QT_MOC_LITERAL(12, 124, 3) // "del"

    },
    "LogField\0onActionVariable\0\0onActionDelete\0"
    "offField\0enable\0onField\0useLogVariable\0"
    "notUseLogVariable\0validateId\0purgeName\0"
    "add\0del"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogField[] = {

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
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    1,   66,    2, 0x0a /* Public */,
       6,    1,   69,    2, 0x0a /* Public */,
       7,    0,   72,    2, 0x0a /* Public */,
       8,    0,   73,    2, 0x0a /* Public */,
       9,    1,   74,    2, 0x0a /* Public */,
      10,    1,   77,    2, 0x0a /* Public */,
      11,    0,   80,    2, 0x0a /* Public */,
      12,    0,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::QString, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LogField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogField *_t = static_cast<LogField *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onActionVariable(); break;
        case 1: _t->onActionDelete(); break;
        case 2: _t->offField((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onField((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->useLogVariable(); break;
        case 5: _t->notUseLogVariable(); break;
        case 6: _t->validateId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: { QString _r = _t->purgeName((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: _t->add(); break;
        case 9: _t->del(); break;
        default: ;
        }
    }
}

const QMetaObject LogField::staticMetaObject = {
    { &Component::staticMetaObject, qt_meta_stringdata_LogField.data,
      qt_meta_data_LogField,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LogField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogField::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LogField.stringdata0))
        return static_cast<void*>(const_cast< LogField*>(this));
    return Component::qt_metacast(_clname);
}

int LogField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Component::qt_metacall(_c, _id, _a);
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

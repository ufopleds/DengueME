/****************************************************************************
** Meta object code from reading C++ file 'field.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/components/field.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'field.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Field_t {
    QByteArrayData data[12];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Field_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Field_t qt_meta_stringdata_Field = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Field"
QT_MOC_LITERAL(1, 6, 15), // "onActionBoolean"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "onActionText"
QT_MOC_LITERAL(4, 36, 15), // "onActionInteger"
QT_MOC_LITERAL(5, 52, 16), // "onActionFloating"
QT_MOC_LITERAL(6, 69, 16), // "onActionCheckbox"
QT_MOC_LITERAL(7, 86, 16), // "onActionCombobox"
QT_MOC_LITERAL(8, 103, 15), // "onActionOptions"
QT_MOC_LITERAL(9, 119, 14), // "onActionDelete"
QT_MOC_LITERAL(10, 134, 13), // "onActionClone"
QT_MOC_LITERAL(11, 148, 11) // "onActionCsv"

    },
    "Field\0onActionBoolean\0\0onActionText\0"
    "onActionInteger\0onActionFloating\0"
    "onActionCheckbox\0onActionCombobox\0"
    "onActionOptions\0onActionDelete\0"
    "onActionClone\0onActionCsv"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Field[] = {

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
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Field::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Field *_t = static_cast<Field *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onActionBoolean(); break;
        case 1: _t->onActionText(); break;
        case 2: _t->onActionInteger(); break;
        case 3: _t->onActionFloating(); break;
        case 4: _t->onActionCheckbox(); break;
        case 5: _t->onActionCombobox(); break;
        case 6: { bool _r = _t->onActionOptions();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->onActionDelete(); break;
        case 8: _t->onActionClone(); break;
        case 9: _t->onActionCsv(); break;
        default: ;
        }
    }
}

const QMetaObject Field::staticMetaObject = {
    { &Component::staticMetaObject, qt_meta_stringdata_Field.data,
      qt_meta_data_Field,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Field::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Field::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Field.stringdata0))
        return static_cast<void*>(const_cast< Field*>(this));
    return Component::qt_metacast(_clname);
}

int Field::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

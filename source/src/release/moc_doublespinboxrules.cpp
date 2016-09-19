/****************************************************************************
** Meta object code from reading C++ file 'doublespinboxrules.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/components/constraints/doublespinboxrules.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doublespinboxrules.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DoubleSpinBoxRules_t {
    QByteArrayData data[8];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DoubleSpinBoxRules_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DoubleSpinBoxRules_t qt_meta_stringdata_DoubleSpinBoxRules = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DoubleSpinBoxRules"
QT_MOC_LITERAL(1, 19, 16), // "precisionChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 1), // "p"
QT_MOC_LITERAL(4, 39, 14), // "minimumChanged"
QT_MOC_LITERAL(5, 54, 1), // "n"
QT_MOC_LITERAL(6, 56, 14), // "maximumChanged"
QT_MOC_LITERAL(7, 71, 11) // "stepChanged"

    },
    "DoubleSpinBoxRules\0precisionChanged\0"
    "\0p\0minimumChanged\0n\0maximumChanged\0"
    "stepChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DoubleSpinBoxRules[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       7,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,

       0        // eod
};

void DoubleSpinBoxRules::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DoubleSpinBoxRules *_t = static_cast<DoubleSpinBoxRules *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->precisionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->minimumChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->maximumChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->stepChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DoubleSpinBoxRules::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DoubleSpinBoxRules.data,
      qt_meta_data_DoubleSpinBoxRules,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DoubleSpinBoxRules::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DoubleSpinBoxRules::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DoubleSpinBoxRules.stringdata0))
        return static_cast<void*>(const_cast< DoubleSpinBoxRules*>(this));
    return QDialog::qt_metacast(_clname);
}

int DoubleSpinBoxRules::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE

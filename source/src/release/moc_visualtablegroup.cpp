/****************************************************************************
** Meta object code from reading C++ file 'visualtablegroup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/visualtablegroup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualtablegroup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VisualTableGroup_t {
    QByteArrayData data[17];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VisualTableGroup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VisualTableGroup_t qt_meta_stringdata_VisualTableGroup = {
    {
QT_MOC_LITERAL(0, 0, 16), // "VisualTableGroup"
QT_MOC_LITERAL(1, 17, 13), // "heightChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "onRemove"
QT_MOC_LITERAL(4, 41, 11), // "removeField"
QT_MOC_LITERAL(5, 53, 14), // "askRemoveGroup"
QT_MOC_LITERAL(6, 68, 10), // "cloneField"
QT_MOC_LITERAL(7, 79, 10), // "changeType"
QT_MOC_LITERAL(8, 90, 11), // "addVariable"
QT_MOC_LITERAL(9, 102, 17), // "VisualTableField*"
QT_MOC_LITERAL(10, 120, 18), // "togglePlotCheckbox"
QT_MOC_LITERAL(11, 139, 12), // "addComponent"
QT_MOC_LITERAL(12, 152, 10), // "Component*"
QT_MOC_LITERAL(13, 163, 4), // "comp"
QT_MOC_LITERAL(14, 168, 10), // "validateId"
QT_MOC_LITERAL(15, 179, 4), // "name"
QT_MOC_LITERAL(16, 184, 9) // "purgeName"

    },
    "VisualTableGroup\0heightChanged\0\0"
    "onRemove\0removeField\0askRemoveGroup\0"
    "cloneField\0changeType\0addVariable\0"
    "VisualTableField*\0togglePlotCheckbox\0"
    "addComponent\0Component*\0comp\0validateId\0"
    "name\0purgeName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VisualTableGroup[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   72,    2, 0x08 /* Private */,
       4,    0,   73,    2, 0x08 /* Private */,
       5,    0,   74,    2, 0x08 /* Private */,
       6,    0,   75,    2, 0x08 /* Private */,
       7,    1,   76,    2, 0x08 /* Private */,
       8,    0,   79,    2, 0x0a /* Public */,
      10,    1,   80,    2, 0x0a /* Public */,
      11,    1,   83,    2, 0x0a /* Public */,
      14,    1,   86,    2, 0x0a /* Public */,
      16,    1,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    0x80000000 | 9,
    QMetaType::Void, QMetaType::Bool,    2,
    0x80000000 | 12, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::QString, QMetaType::QString,   15,

       0        // eod
};

void VisualTableGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VisualTableGroup *_t = static_cast<VisualTableGroup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->heightChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onRemove(); break;
        case 2: _t->removeField(); break;
        case 3: _t->askRemoveGroup(); break;
        case 4: _t->cloneField(); break;
        case 5: _t->changeType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: { VisualTableField* _r = _t->addVariable();
            if (_a[0]) *reinterpret_cast< VisualTableField**>(_a[0]) = _r; }  break;
        case 7: _t->togglePlotCheckbox((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: { Component* _r = _t->addComponent((*reinterpret_cast< Component*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Component**>(_a[0]) = _r; }  break;
        case 9: _t->validateId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: { QString _r = _t->purgeName((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Component* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VisualTableGroup::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VisualTableGroup::heightChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject VisualTableGroup::staticMetaObject = {
    { &Component::staticMetaObject, qt_meta_stringdata_VisualTableGroup.data,
      qt_meta_data_VisualTableGroup,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VisualTableGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VisualTableGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VisualTableGroup.stringdata0))
        return static_cast<void*>(const_cast< VisualTableGroup*>(this));
    return Component::qt_metacast(_clname);
}

int VisualTableGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Component::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void VisualTableGroup::heightChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'group.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/group.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'group.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Group_t {
    QByteArrayData data[21];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Group_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Group_t qt_meta_stringdata_Group = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Group"
QT_MOC_LITERAL(1, 6, 13), // "heightChanged"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "onRemove"
QT_MOC_LITERAL(4, 30, 11), // "removeField"
QT_MOC_LITERAL(5, 42, 14), // "askRemoveGroup"
QT_MOC_LITERAL(6, 57, 10), // "cloneField"
QT_MOC_LITERAL(7, 68, 10), // "changeType"
QT_MOC_LITERAL(8, 79, 10), // "morphField"
QT_MOC_LITERAL(9, 90, 4), // "type"
QT_MOC_LITERAL(10, 95, 10), // "addBoolean"
QT_MOC_LITERAL(11, 106, 6), // "Field*"
QT_MOC_LITERAL(12, 113, 7), // "addText"
QT_MOC_LITERAL(13, 121, 10), // "addInteger"
QT_MOC_LITERAL(14, 132, 11), // "addFloating"
QT_MOC_LITERAL(15, 144, 11), // "addCombobox"
QT_MOC_LITERAL(16, 156, 6), // "addCsv"
QT_MOC_LITERAL(17, 163, 10), // "ImportCsv*"
QT_MOC_LITERAL(18, 174, 12), // "addComponent"
QT_MOC_LITERAL(19, 187, 10), // "Component*"
QT_MOC_LITERAL(20, 198, 4) // "comp"

    },
    "Group\0heightChanged\0\0onRemove\0removeField\0"
    "askRemoveGroup\0cloneField\0changeType\0"
    "morphField\0type\0addBoolean\0Field*\0"
    "addText\0addInteger\0addFloating\0"
    "addCombobox\0addCsv\0ImportCsv*\0"
    "addComponent\0Component*\0comp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Group[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   87,    2, 0x08 /* Private */,
       4,    0,   88,    2, 0x08 /* Private */,
       5,    0,   89,    2, 0x08 /* Private */,
       6,    0,   90,    2, 0x08 /* Private */,
       7,    1,   91,    2, 0x08 /* Private */,
       8,    1,   94,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x0a /* Public */,
      12,    0,   98,    2, 0x0a /* Public */,
      13,    0,   99,    2, 0x0a /* Public */,
      14,    0,  100,    2, 0x0a /* Public */,
      15,    0,  101,    2, 0x0a /* Public */,
      16,    0,  102,    2, 0x0a /* Public */,
      18,    1,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    9,
    0x80000000 | 11,
    0x80000000 | 11,
    0x80000000 | 11,
    0x80000000 | 11,
    0x80000000 | 11,
    0x80000000 | 17,
    0x80000000 | 19, 0x80000000 | 19,   20,

       0        // eod
};

void Group::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Group *_t = static_cast<Group *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->heightChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onRemove(); break;
        case 2: _t->removeField(); break;
        case 3: _t->askRemoveGroup(); break;
        case 4: _t->cloneField(); break;
        case 5: _t->changeType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->morphField((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: { Field* _r = _t->addBoolean();
            if (_a[0]) *reinterpret_cast< Field**>(_a[0]) = _r; }  break;
        case 8: { Field* _r = _t->addText();
            if (_a[0]) *reinterpret_cast< Field**>(_a[0]) = _r; }  break;
        case 9: { Field* _r = _t->addInteger();
            if (_a[0]) *reinterpret_cast< Field**>(_a[0]) = _r; }  break;
        case 10: { Field* _r = _t->addFloating();
            if (_a[0]) *reinterpret_cast< Field**>(_a[0]) = _r; }  break;
        case 11: { Field* _r = _t->addCombobox();
            if (_a[0]) *reinterpret_cast< Field**>(_a[0]) = _r; }  break;
        case 12: { ImportCsv* _r = _t->addCsv();
            if (_a[0]) *reinterpret_cast< ImportCsv**>(_a[0]) = _r; }  break;
        case 13: { Component* _r = _t->addComponent((*reinterpret_cast< Component*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Component**>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
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
            typedef void (Group::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Group::heightChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Group::staticMetaObject = {
    { &Component::staticMetaObject, qt_meta_stringdata_Group.data,
      qt_meta_data_Group,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Group::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Group::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Group.stringdata0))
        return static_cast<void*>(const_cast< Group*>(this));
    return Component::qt_metacast(_clname);
}

int Group::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Component::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Group::heightChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'grouplist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/grouplist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grouplist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GroupList_t {
    QByteArrayData data[11];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GroupList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GroupList_t qt_meta_stringdata_GroupList = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GroupList"
QT_MOC_LITERAL(1, 10, 8), // "addGroup"
QT_MOC_LITERAL(2, 19, 6), // "Group*"
QT_MOC_LITERAL(3, 26, 0), // ""
QT_MOC_LITERAL(4, 27, 11), // "removeGroup"
QT_MOC_LITERAL(5, 39, 13), // "addPopulation"
QT_MOC_LITERAL(6, 53, 12), // "updateHeight"
QT_MOC_LITERAL(7, 66, 6), // "height"
QT_MOC_LITERAL(8, 73, 12), // "addComponent"
QT_MOC_LITERAL(9, 86, 10), // "Component*"
QT_MOC_LITERAL(10, 97, 4) // "comp"

    },
    "GroupList\0addGroup\0Group*\0\0removeGroup\0"
    "addPopulation\0updateHeight\0height\0"
    "addComponent\0Component*\0comp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    3, 0x08 /* Private */,
       4,    0,   40,    3, 0x08 /* Private */,
       5,    0,   41,    3, 0x08 /* Private */,
       6,    1,   42,    3, 0x08 /* Private */,
       8,    1,   45,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    0x80000000 | 9, 0x80000000 | 9,   10,

       0        // eod
};

void GroupList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupList *_t = static_cast<GroupList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { Group* _r = _t->addGroup();
            if (_a[0]) *reinterpret_cast< Group**>(_a[0]) = _r; }  break;
        case 1: _t->removeGroup(); break;
        case 2: _t->addPopulation(); break;
        case 3: _t->updateHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: { Component* _r = _t->addComponent((*reinterpret_cast< Component*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Component**>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Component* >(); break;
            }
            break;
        }
    }
}

const QMetaObject GroupList::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_GroupList.data,
      qt_meta_data_GroupList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GroupList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GroupList.stringdata0))
        return static_cast<void*>(const_cast< GroupList*>(this));
    return QFrame::qt_metacast(_clname);
}

int GroupList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

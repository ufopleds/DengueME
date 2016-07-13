/****************************************************************************
** Meta object code from reading C++ file 'grouplist.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/editor/grouplist.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grouplist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GroupList[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   10,   11,   10, 0x08,
      29,   10,   10,   10, 0x08,
      43,   10,   10,   10, 0x08,
      66,   59,   10,   10, 0x08,
     100,   95,   84,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GroupList[] = {
    "GroupList\0\0Group*\0addGroup()\0removeGroup()\0"
    "addPopulation()\0height\0updateHeight(int)\0"
    "Component*\0comp\0addComponent(Component*)\0"
};

void GroupList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GroupList *_t = static_cast<GroupList *>(_o);
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
    }
}

const QMetaObjectExtraData GroupList::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GroupList::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_GroupList,
      qt_meta_data_GroupList, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GroupList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GroupList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GroupList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GroupList))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE

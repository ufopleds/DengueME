/****************************************************************************
** Meta object code from reading C++ file 'dirmodel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/dirmodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dirmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DirModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      26,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DirModel[] = {
    "DirModel\0\0aboutToUpdate()\0updated()\0"
    "updateDir()\0"
};

void DirModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DirModel *_t = static_cast<DirModel *>(_o);
        switch (_id) {
        case 0: _t->aboutToUpdate(); break;
        case 1: _t->updated(); break;
        case 2: _t->updateDir(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DirModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DirModel::staticMetaObject = {
    { &QStandardItemModel::staticMetaObject, qt_meta_stringdata_DirModel,
      qt_meta_data_DirModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DirModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DirModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DirModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DirModel))
        return static_cast<void*>(const_cast< DirModel*>(this));
    return QStandardItemModel::qt_metacast(_clname);
}

int DirModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DirModel::aboutToUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void DirModel::updated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE

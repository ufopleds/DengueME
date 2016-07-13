/****************************************************************************
** Meta object code from reading C++ file 'field.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/components/field.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'field.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Field[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      25,    6,    6,    6, 0x0a,
      40,    6,    6,    6, 0x0a,
      58,    6,    6,    6, 0x0a,
      77,    6,    6,    6, 0x0a,
      96,    6,    6,    6, 0x0a,
     120,    6,  115,    6, 0x0a,
     138,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Field[] = {
    "Field\0\0onActionBoolean()\0onActionText()\0"
    "onActionInteger()\0onActionFloating()\0"
    "onActionCheckbox()\0onActionCombobox()\0"
    "bool\0onActionOptions()\0onActionDelete()\0"
};

void Field::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Field *_t = static_cast<Field *>(_o);
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
        default: ;
        }
    }
}

const QMetaObjectExtraData Field::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Field::staticMetaObject = {
    { &Component::staticMetaObject, qt_meta_stringdata_Field,
      qt_meta_data_Field, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Field::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Field::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Field::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Field))
        return static_cast<void*>(const_cast< Field*>(this));
    return Component::qt_metacast(_clname);
}

int Field::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Component::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

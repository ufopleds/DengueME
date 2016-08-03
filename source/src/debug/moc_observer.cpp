/****************************************************************************
** Meta object code from reading C++ file 'observer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/components/observer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'observer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Observer[] = {

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
      18,    9,   10,    9, 0x0a,
      28,    9,    9,    9, 0x0a,
      42,    9,    9,    9, 0x0a,
      55,    9,    9,    9, 0x0a,
      66,    9,    9,    9, 0x0a,
      92,   84,    9,    9, 0x0a,
     118,  113,    9,    9, 0x0a,
     151,    9,  138,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Observer[] = {
    "Observer\0\0QString\0outData()\0setColorBar()\0"
    "parameters()\0setColor()\0showColorDialog()\0"
    "newText\0ChangeValue(QString)\0root\0"
    "setXml(QDomElement)\0QDomDocument\0"
    "getXml()\0"
};

void Observer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Observer *_t = static_cast<Observer *>(_o);
        switch (_id) {
        case 0: { QString _r = _t->outData();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: _t->setColorBar(); break;
        case 2: _t->parameters(); break;
        case 3: _t->setColor(); break;
        case 4: _t->showColorDialog(); break;
        case 5: _t->ChangeValue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->setXml((*reinterpret_cast< QDomElement(*)>(_a[1]))); break;
        case 7: { QDomDocument _r = _t->getXml();
            if (_a[0]) *reinterpret_cast< QDomDocument*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Observer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Observer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Observer,
      qt_meta_data_Observer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Observer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Observer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Observer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Observer))
        return static_cast<void*>(const_cast< Observer*>(this));
    return QWidget::qt_metacast(_clname);
}

int Observer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

/****************************************************************************
** Meta object code from reading C++ file 'observer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/components/observer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'observer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Observer_t {
    QByteArrayData data[14];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Observer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Observer_t qt_meta_stringdata_Observer = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Observer"
QT_MOC_LITERAL(1, 9, 7), // "outData"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 11), // "setColorBar"
QT_MOC_LITERAL(4, 30, 10), // "parameters"
QT_MOC_LITERAL(5, 41, 8), // "setColor"
QT_MOC_LITERAL(6, 50, 15), // "showColorDialog"
QT_MOC_LITERAL(7, 66, 11), // "ChangeValue"
QT_MOC_LITERAL(8, 78, 7), // "newText"
QT_MOC_LITERAL(9, 86, 6), // "setXml"
QT_MOC_LITERAL(10, 93, 11), // "QDomElement"
QT_MOC_LITERAL(11, 105, 4), // "root"
QT_MOC_LITERAL(12, 110, 6), // "getXml"
QT_MOC_LITERAL(13, 117, 12) // "QDomDocument"

    },
    "Observer\0outData\0\0setColorBar\0parameters\0"
    "setColor\0showColorDialog\0ChangeValue\0"
    "newText\0setXml\0QDomElement\0root\0getXml\0"
    "QDomDocument"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Observer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    1,   59,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      12,    0,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    0x80000000 | 13,

       0        // eod
};

void Observer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Observer *_t = static_cast<Observer *>(_o);
        Q_UNUSED(_t)
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

const QMetaObject Observer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Observer.data,
      qt_meta_data_Observer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Observer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Observer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Observer.stringdata0))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

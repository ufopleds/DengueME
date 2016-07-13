/****************************************************************************
** Meta object code from reading C++ file 'modelview.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/views/modelview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modelview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ModelView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   10,   10,   10, 0x08,
      53,   10,   10,   10, 0x08,
      66,   10,   10,   10, 0x08,
      81,   79,   10,   10, 0x08,
     107,   79,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ModelView[] = {
    "ModelView\0\0interpreterChanged(Interpreter)\0"
    "addFile()\0removeFile()\0renameFile()\0"
    "r\0onInterpreterChanged(int)\0"
    "onMainFileChanged(QString)\0"
};

void ModelView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ModelView *_t = static_cast<ModelView *>(_o);
        switch (_id) {
        case 0: _t->interpreterChanged((*reinterpret_cast< Interpreter(*)>(_a[1]))); break;
        case 1: _t->addFile(); break;
        case 2: _t->removeFile(); break;
        case 3: _t->renameFile(); break;
        case 4: _t->onInterpreterChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onMainFileChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ModelView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ModelView::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_ModelView,
      qt_meta_data_ModelView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ModelView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ModelView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ModelView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModelView))
        return static_cast<void*>(const_cast< ModelView*>(this));
    return QFrame::qt_metacast(_clname);
}

int ModelView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ModelView::interpreterChanged(Interpreter _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

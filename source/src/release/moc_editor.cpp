/****************************************************************************
** Meta object code from reading C++ file 'editor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Editor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      26,   17,    7,    7, 0x05,
      52,   43,    7,    7, 0x05,
      72,    7,    7,    7, 0x05,
     102,   93,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     139,  134,  126,    7, 0x0a,
     191,  173,  168,    7, 0x0a,
     226,  215,    7,    7, 0x0a,
     246,  242,  168,    7, 0x0a,
     257,    7,    7,    7, 0x0a,
     270,    7,  168,    7, 0x0a,
     277,    7,  168,    7, 0x0a,
     286,    7,    7,    7, 0x08,
     311,    7,    7,    7, 0x08,
     337,   93,    7,    7, 0x08,
     369,  364,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Editor[] = {
    "Editor\0\0closed()\0filename\0renamed(QString)\0"
    "lvl,text\0output(int,QString)\0"
    "interpreterStarted()\0exitCode\0"
    "interpreterStopped(int)\0QString\0node\0"
    "loadDescription(QDomElement)\0bool\0"
    "filename,editMode\0loadModel(QString,bool)\0"
    "stepByStep\0execModel(bool)\0del\0"
    "close(int)\0clearModel()\0save()\0saveAs()\0"
    "readyReadStandardError()\0"
    "readyReadStandardOutput()\0"
    "onInterpreterFinished(int)\0intr\0"
    "onInterpreterChanged(Interpreter)\0"
};

void Editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Editor *_t = static_cast<Editor *>(_o);
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->renamed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->output((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->interpreterStarted(); break;
        case 4: _t->interpreterStopped((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: { QString _r = _t->loadDescription((*reinterpret_cast< QDomElement(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->loadModel((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->execModel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: { bool _r = _t->close((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->clearModel(); break;
        case 10: { bool _r = _t->save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->saveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: _t->readyReadStandardError(); break;
        case 13: _t->readyReadStandardOutput(); break;
        case 14: _t->onInterpreterFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->onInterpreterChanged((*reinterpret_cast< Interpreter(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Editor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Editor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Editor,
      qt_meta_data_Editor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Editor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Editor))
        return static_cast<void*>(const_cast< Editor*>(this));
    return QWidget::qt_metacast(_clname);
}

int Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Editor::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Editor::renamed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Editor::output(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Editor::interpreterStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Editor::interpreterStopped(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE

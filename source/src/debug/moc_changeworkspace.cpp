/****************************************************************************
** Meta object code from reading C++ file 'changeworkspace.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../changeworkspace.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changeworkspace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChangeWorkspace[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChangeWorkspace[] = {
    "ChangeWorkspace\0\0workspaceChanged()\0"
    "accept()\0"
};

void ChangeWorkspace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChangeWorkspace *_t = static_cast<ChangeWorkspace *>(_o);
        switch (_id) {
        case 0: _t->workspaceChanged(); break;
        case 1: _t->accept(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ChangeWorkspace::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChangeWorkspace::staticMetaObject = {
    { &QWizard::staticMetaObject, qt_meta_stringdata_ChangeWorkspace,
      qt_meta_data_ChangeWorkspace, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChangeWorkspace::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChangeWorkspace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChangeWorkspace::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChangeWorkspace))
        return static_cast<void*>(const_cast< ChangeWorkspace*>(this));
    return QWizard::qt_metacast(_clname);
}

int ChangeWorkspace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizard::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ChangeWorkspace::workspaceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_detail__SelectPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      43,   38,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_detail__SelectPage[] = {
    "detail::SelectPage\0\0browseWorkspace()\0"
    "path\0validate(QString)\0"
};

void detail::SelectPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SelectPage *_t = static_cast<SelectPage *>(_o);
        switch (_id) {
        case 0: _t->browseWorkspace(); break;
        case 1: _t->validate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData detail::SelectPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject detail::SelectPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_detail__SelectPage,
      qt_meta_data_detail__SelectPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &detail::SelectPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *detail::SelectPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *detail::SelectPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_detail__SelectPage))
        return static_cast<void*>(const_cast< SelectPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int detail::SelectPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

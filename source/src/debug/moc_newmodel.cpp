/****************************************************************************
** Meta object code from reading C++ file 'newmodel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../newmodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      42,   10,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_NewModel[] = {
    "NewModel\0\0category,type,project,name,demo\0"
    "accepted(QString,QString,QString,QString,bool)\0"
};

void NewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewModel *_t = static_cast<NewModel *>(_o);
        switch (_id) {
        case 0: _t->accepted((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NewModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewModel::staticMetaObject = {
    { &QWizard::staticMetaObject, qt_meta_stringdata_NewModel,
      qt_meta_data_NewModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewModel))
        return static_cast<void*>(const_cast< NewModel*>(this));
    return QWizard::qt_metacast(_clname);
}

int NewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizard::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void NewModel::accepted(QString _t1, QString _t2, QString _t3, QString _t4, bool _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_TypePage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      24,    9,    9,    9, 0x0a,
      43,   38,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TypePage[] = {
    "TypePage\0\0itemChanged()\0itemClicked()\0"
    "item\0nameSelected(QString)\0"
};

void TypePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TypePage *_t = static_cast<TypePage *>(_o);
        switch (_id) {
        case 0: _t->itemChanged(); break;
        case 1: _t->itemClicked(); break;
        case 2: _t->nameSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TypePage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TypePage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_TypePage,
      qt_meta_data_TypePage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TypePage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TypePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TypePage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TypePage))
        return static_cast<void*>(const_cast< TypePage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int TypePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_ProjectPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      27,   12,   12,   12, 0x0a,
      40,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ProjectPage[] = {
    "ProjectPage\0\0itemChanged()\0newProject()\0"
    "loadWorkspace()\0"
};

void ProjectPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ProjectPage *_t = static_cast<ProjectPage *>(_o);
        switch (_id) {
        case 0: _t->itemChanged(); break;
        case 1: _t->newProject(); break;
        case 2: _t->loadWorkspace(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ProjectPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ProjectPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_ProjectPage,
      qt_meta_data_ProjectPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProjectPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProjectPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProjectPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProjectPage))
        return static_cast<void*>(const_cast< ProjectPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int ProjectPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_NamePage[] = {

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
      15,   10,    9,    9, 0x0a,
      45,   40,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NamePage[] = {
    "NamePage\0\0name\0validateProject(QString)\0"
    "path\0setWorkspace(QString)\0"
};

void NamePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NamePage *_t = static_cast<NamePage *>(_o);
        switch (_id) {
        case 0: _t->validateProject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setWorkspace((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NamePage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NamePage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_NamePage,
      qt_meta_data_NamePage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NamePage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NamePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NamePage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NamePage))
        return static_cast<void*>(const_cast< NamePage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int NamePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

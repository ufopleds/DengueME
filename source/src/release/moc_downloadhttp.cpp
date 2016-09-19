/****************************************************************************
** Meta object code from reading C++ file 'downloadhttp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../downloadhttp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadhttp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DownloadHTTP_t {
    QByteArrayData data[18];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DownloadHTTP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DownloadHTTP_t qt_meta_stringdata_DownloadHTTP = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DownloadHTTP"
QT_MOC_LITERAL(1, 13, 7), // "addLine"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 6), // "qsLine"
QT_MOC_LITERAL(4, 29, 16), // "downloadComplete"
QT_MOC_LITERAL(5, 46, 8), // "progress"
QT_MOC_LITERAL(6, 55, 11), // "nPercentage"
QT_MOC_LITERAL(7, 67, 8), // "download"
QT_MOC_LITERAL(8, 76, 3), // "url"
QT_MOC_LITERAL(9, 80, 12), // "finishedHead"
QT_MOC_LITERAL(10, 93, 8), // "finished"
QT_MOC_LITERAL(11, 102, 16), // "downloadProgress"
QT_MOC_LITERAL(12, 119, 13), // "bytesReceived"
QT_MOC_LITERAL(13, 133, 10), // "bytesTotal"
QT_MOC_LITERAL(14, 144, 5), // "error"
QT_MOC_LITERAL(15, 150, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(16, 178, 4), // "code"
QT_MOC_LITERAL(17, 183, 7) // "timeout"

    },
    "DownloadHTTP\0addLine\0\0qsLine\0"
    "downloadComplete\0progress\0nPercentage\0"
    "download\0url\0finishedHead\0finished\0"
    "downloadProgress\0bytesReceived\0"
    "bytesTotal\0error\0QNetworkReply::NetworkError\0"
    "code\0timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DownloadHTTP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    0,   67,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   71,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x08 /* Private */,
       9,    0,   75,    2, 0x08 /* Private */,
      10,    0,   76,    2, 0x08 /* Private */,
      11,    2,   77,    2, 0x08 /* Private */,
      14,    1,   82,    2, 0x08 /* Private */,
      17,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QUrl,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,

       0        // eod
};

void DownloadHTTP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DownloadHTTP *_t = static_cast<DownloadHTTP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->downloadComplete(); break;
        case 2: _t->progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->download((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 4: _t->download(); break;
        case 5: _t->finishedHead(); break;
        case 6: _t->finished(); break;
        case 7: _t->downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 8: _t->error((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 9: _t->timeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DownloadHTTP::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownloadHTTP::addLine)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DownloadHTTP::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownloadHTTP::downloadComplete)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DownloadHTTP::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownloadHTTP::progress)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject DownloadHTTP::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DownloadHTTP.data,
      qt_meta_data_DownloadHTTP,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DownloadHTTP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DownloadHTTP::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadHTTP.stringdata0))
        return static_cast<void*>(const_cast< DownloadHTTP*>(this));
    return QObject::qt_metacast(_clname);
}

int DownloadHTTP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void DownloadHTTP::addLine(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DownloadHTTP::downloadComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void DownloadHTTP::progress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

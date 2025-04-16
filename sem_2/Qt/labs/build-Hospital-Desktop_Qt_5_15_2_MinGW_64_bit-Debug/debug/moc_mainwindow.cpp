/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Hospital/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "signalSurname"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "sur"
QT_MOC_LITERAL(4, 30, 9), // "signalAge"
QT_MOC_LITERAL(5, 40, 15), // "signalDiagnosis"
QT_MOC_LITERAL(6, 56, 7), // "patient"
QT_MOC_LITERAL(7, 64, 10), // "signalWard"
QT_MOC_LITERAL(8, 75, 11), // "slotSurname"
QT_MOC_LITERAL(9, 87, 4), // "qStr"
QT_MOC_LITERAL(10, 92, 7), // "slotAge"
QT_MOC_LITERAL(11, 100, 13), // "slotDiagnosis"
QT_MOC_LITERAL(12, 114, 10), // "diagnosis_"
QT_MOC_LITERAL(13, 125, 8), // "slotWard"
QT_MOC_LITERAL(14, 134, 4), // "ward"
QT_MOC_LITERAL(15, 139, 29), // "on_readFromFileButton_clicked"
QT_MOC_LITERAL(16, 169, 17), // "on_findBy_clicked"
QT_MOC_LITERAL(17, 187, 15), // "on_show_clicked"
QT_MOC_LITERAL(18, 203, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(19, 224, 23) // "on_deleteButton_clicked"

    },
    "MainWindow\0signalSurname\0\0sur\0signalAge\0"
    "signalDiagnosis\0patient\0signalWard\0"
    "slotSurname\0qStr\0slotAge\0slotDiagnosis\0"
    "diagnosis_\0slotWard\0ward\0"
    "on_readFromFileButton_clicked\0"
    "on_findBy_clicked\0on_show_clicked\0"
    "on_addButton_clicked\0on_deleteButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    1,   85,    2, 0x06 /* Public */,
       7,    1,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   91,    2, 0x0a /* Public */,
      10,    1,   94,    2, 0x0a /* Public */,
      11,    1,   97,    2, 0x0a /* Public */,
      13,    1,  100,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,
      18,    0,  106,    2, 0x08 /* Private */,
      19,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalSurname((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signalAge((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signalDiagnosis((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->signalWard((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slotSurname((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slotAge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slotDiagnosis((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->slotWard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_readFromFileButton_clicked(); break;
        case 9: _t->on_findBy_clicked(); break;
        case 10: _t->on_show_clicked(); break;
        case 11: _t->on_addButton_clicked(); break;
        case 12: _t->on_deleteButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalSurname)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalAge)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalDiagnosis)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalWard)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalSurname(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::signalAge(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::signalDiagnosis(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::signalWard(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

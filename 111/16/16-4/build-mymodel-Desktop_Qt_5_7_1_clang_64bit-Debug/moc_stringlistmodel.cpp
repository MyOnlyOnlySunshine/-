/****************************************************************************
** Meta object code from reading C++ file 'stringlistmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mymodel/stringlistmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stringlistmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StringListModel_t {
    QByteArrayData data[9];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StringListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StringListModel_t qt_meta_stringdata_StringListModel = {
    {
QT_MOC_LITERAL(0, 0, 15), // "StringListModel"
QT_MOC_LITERAL(1, 16, 9), // "showValue"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "flags"
QT_MOC_LITERAL(4, 33, 13), // "Qt::ItemFlags"
QT_MOC_LITERAL(5, 47, 5), // "index"
QT_MOC_LITERAL(6, 53, 7), // "setData"
QT_MOC_LITERAL(7, 61, 5), // "value"
QT_MOC_LITERAL(8, 67, 4) // "role"

    },
    "StringListModel\0showValue\0\0flags\0"
    "Qt::ItemFlags\0index\0setData\0value\0"
    "role"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StringListModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       6,    3,   38,    2, 0x0a /* Public */,
       6,    2,   45,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 4, QMetaType::QModelIndex,    5,
    QMetaType::Bool, QMetaType::QModelIndex, QMetaType::QVariant, QMetaType::Int,    5,    7,    8,
    QMetaType::Bool, QMetaType::QModelIndex, QMetaType::QVariant,    5,    7,

       0        // eod
};

void StringListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StringListModel *_t = static_cast<StringListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showValue(); break;
        case 1: { Qt::ItemFlags _r = _t->flags((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Qt::ItemFlags*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->setData((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->setData((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject StringListModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_StringListModel.data,
      qt_meta_data_StringListModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StringListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StringListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StringListModel.stringdata0))
        return static_cast<void*>(const_cast< StringListModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int StringListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

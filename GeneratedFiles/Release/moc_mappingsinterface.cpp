/****************************************************************************
** Meta object code from reading C++ file 'mappingsinterface.h'
**
** Created: Fri Jun 3 03:04:18 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mappingsinterface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mappingsinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MappingsInterface[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_MappingsInterface[] = {
    "MappingsInterface\0"
};

const QMetaObject MappingsInterface::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MappingsInterface,
      qt_meta_data_MappingsInterface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MappingsInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MappingsInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MappingsInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MappingsInterface))
        return static_cast<void*>(const_cast< MappingsInterface*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MappingsInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "addNewTab",
    "",
    "switchTab",
    "index",
    "closeTab",
    "navigateToUrl",
    "url",
    "updateUrlBar",
    "goBack",
    "goForward",
    "reloadPage",
    "updateHistory",
    "addBookmark",
    "showHistory",
    "showBookmarks",
    "openFromHistory",
    "QListWidgetItem*",
    "item",
    "openFromBookmarks",
    "handleDownload",
    "QWebEngineDownloadRequest*",
    "download",
    "updateDownloadState",
    "QWebEngineDownloadRequest::DownloadState",
    "state",
    "showDownloads",
    "openDownloadedFile",
    "clearAllHistory",
    "clearSelectedHistory",
    "clearAllBookmarks",
    "clearSelectedBookmark",
    "clearAllDownloads",
    "clearSelectedDownload"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  164,    2, 0x08,    1 /* Private */,
       3,    1,  165,    2, 0x08,    2 /* Private */,
       5,    1,  168,    2, 0x08,    4 /* Private */,
       6,    0,  171,    2, 0x08,    6 /* Private */,
       6,    1,  172,    2, 0x08,    7 /* Private */,
       8,    1,  175,    2, 0x08,    9 /* Private */,
       9,    0,  178,    2, 0x08,   11 /* Private */,
      10,    0,  179,    2, 0x08,   12 /* Private */,
      11,    0,  180,    2, 0x08,   13 /* Private */,
      12,    1,  181,    2, 0x08,   14 /* Private */,
      13,    0,  184,    2, 0x08,   16 /* Private */,
      14,    0,  185,    2, 0x08,   17 /* Private */,
      15,    0,  186,    2, 0x08,   18 /* Private */,
      16,    1,  187,    2, 0x08,   19 /* Private */,
      19,    1,  190,    2, 0x08,   21 /* Private */,
      20,    1,  193,    2, 0x08,   23 /* Private */,
      23,    1,  196,    2, 0x08,   25 /* Private */,
      26,    0,  199,    2, 0x08,   27 /* Private */,
      27,    1,  200,    2, 0x08,   28 /* Private */,
      28,    0,  203,    2, 0x08,   30 /* Private */,
      29,    0,  204,    2, 0x08,   31 /* Private */,
      30,    0,  205,    2, 0x08,   32 /* Private */,
      31,    0,  206,    2, 0x08,   33 /* Private */,
      32,    0,  207,    2, 0x08,   34 /* Private */,
      33,    0,  208,    2, 0x08,   35 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,    7,
    QMetaType::Void, QMetaType::QUrl,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'addNewTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'closeTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'navigateToUrl'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'navigateToUrl'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QUrl, std::false_type>,
        // method 'updateUrlBar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QUrl, std::false_type>,
        // method 'goBack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'goForward'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reloadPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>,
        // method 'addBookmark'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showBookmarks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openFromHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'openFromBookmarks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'handleDownload'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWebEngineDownloadRequest *, std::false_type>,
        // method 'updateDownloadState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWebEngineDownloadRequest::DownloadState, std::false_type>,
        // method 'showDownloads'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openDownloadedFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'clearAllHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearSelectedHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearAllBookmarks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearSelectedBookmark'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearAllDownloads'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearSelectedDownload'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addNewTab(); break;
        case 1: _t->switchTab((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->closeTab((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->navigateToUrl(); break;
        case 4: _t->navigateToUrl((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 5: _t->updateUrlBar((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 6: _t->goBack(); break;
        case 7: _t->goForward(); break;
        case 8: _t->reloadPage(); break;
        case 9: _t->updateHistory((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 10: _t->addBookmark(); break;
        case 11: _t->showHistory(); break;
        case 12: _t->showBookmarks(); break;
        case 13: _t->openFromHistory((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 14: _t->openFromBookmarks((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 15: _t->handleDownload((*reinterpret_cast< std::add_pointer_t<QWebEngineDownloadRequest*>>(_a[1]))); break;
        case 16: _t->updateDownloadState((*reinterpret_cast< std::add_pointer_t<QWebEngineDownloadRequest::DownloadState>>(_a[1]))); break;
        case 17: _t->showDownloads(); break;
        case 18: _t->openDownloadedFile((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 19: _t->clearAllHistory(); break;
        case 20: _t->clearSelectedHistory(); break;
        case 21: _t->clearAllBookmarks(); break;
        case 22: _t->clearSelectedBookmark(); break;
        case 23: _t->clearAllDownloads(); break;
        case 24: _t->clearSelectedDownload(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWebEngineDownloadRequest* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}
QT_WARNING_POP

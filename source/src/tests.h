#ifndef TESTS_H
#define TESTS_H

#include <QtCore>
#include "dengueme.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

struct MainWindow_UnitTests {
    template<typename T = QString>
    class Error {
        T t;
    public:
        inline Error(T t) : t(t) { }
        inline T get() { return t; }
    };

    static QString workspace_config(MainWindow *);
    static QString new_project(MainWindow *);
    static QString menu_signals(MainWindow *mw);
    static QList<QPair<QString, QString(*)(MainWindow*)> > get_tests();
};

#endif // TESTS_H

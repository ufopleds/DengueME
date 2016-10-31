#include "tests.h"

QString MainWindow_UnitTests::workspace_config(MainWindow *) {
    QString ws = dengueme::config("workspace");
    if (ws.isEmpty()) throw Error<>("workspace not set.");
    if (!QDir(ws).exists()) return "workspace folder does not exist.\n(\"" + ws + "\")";
    return "";
}

QString MainWindow_UnitTests::new_project(MainWindow *) {
    int n = 0;
    QString name;
    do {
        name = "dummy" + QString::number(++n);
    } while(QDir(dengueme::config("workspace") + '/' + name).exists());

    QDir dir(dengueme::config("workspace") + '/' + name);
    if (!dir.mkpath(dir.path()) || !dir.exists()) throw Error<>("failed to create project path.\n(\"" + dir.path() + "\")");

    dir.rmdir(dir.path());
    if (dir.exists()) return "failed to remove temporary directory. \n(\"" + dir.path() + "\")";
    return "";
}

QString MainWindow_UnitTests::menu_signals(MainWindow *mw) {
    struct QObject_rec : public QObject {  // Classe auxiliar para acessar método protegido.
        using QObject::receivers;          // (https://groups.google.com/forum/#!topic/comp.std.c++/5NZ7duc72sE).
    };

    QString ret;
    foreach(QAction *a, mw->menuBar()->actions()) {
        foreach(QAction *b, a->menu()->actions()) {
            int n = (b->*&QObject_rec::receivers)(SIGNAL(triggered()));
            n -= mw->ui->mainToolBar->actions().contains(b)? 1: 0;

            if (!b->text().isEmpty()) {
                if (n < 2)
                    ret += a->text() + " -> " + b->text() + " not connected.\n";
            }
        }
    }

    ret.chop(1);
    return ret;
}

QList<QPair<QString, QString(*)(MainWindow*)> > MainWindow_UnitTests::get_tests() {
    QList<QPair<QString, QString(*)(MainWindow*)> > ret;
    ret
            << QPair<QString, QString(*)(MainWindow*)>("Check if the workspace is valid", workspace_config)
            << QPair<QString, QString(*)(MainWindow*)>("Check ability to create and delete projects in the workspace", new_project)
            << QPair<QString, QString(*)(MainWindow*)>("Check if all menu options are connected to slots", menu_signals);
    return ret;
}

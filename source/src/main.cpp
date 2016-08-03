#include <QApplication>

#include "dengueme.h"
#include "changeworkspace.h"
#include "mainwindow.h"
#include "newmodel.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    //Finds workspace based on settings file, if not defined, creates a new Folder
    if (dengueme::config("prompt_workspace") == "true" || dengueme::config("workspace").isEmpty() || !QDir(dengueme::config("workspace")).exists()) {
        if (ChangeWorkspace().exec() != QDialog::Accepted) return 1;
        QDir dir(dengueme::config("workspace"));
        dir.mkpath(dir.absolutePath());
    }
    //Finds terraME
    if (dengueme::config("terrame").isEmpty()) {
        dengueme::saveconfig("terrame","TerraME");
        dengueme::setconfig("terrame","TerraME");
    }
    if (dengueme::config("terrame/gui").isEmpty()) {
        dengueme::saveconfig("terrame/gui","true");
        dengueme::setconfig("terrame/gui","true");
    }

    ///TODO - Translator
    if (! dengueme::config("locale").isEmpty() && dengueme::config("locale") != "Default") {
        QTranslator translator;
        translator.load(QString("translations/") + dengueme::config("locale"));
        app.installTranslator(&translator);
    }
    QTranslator translator;
    translator.load(QString("translations/") + dengueme::config("locale"));
    app.installTranslator(&translator);
    ///TODO - Translator

    (new MainWindow)->show();

    return app.exec();
}


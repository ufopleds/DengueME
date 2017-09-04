#include <QApplication>
#include <QStandardPaths>

#include "dengueme.h"
#include "changeworkspace.h"
#include "mainwindow.h"
#include "newmodel.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    /* To generate the translate file, please use these commands in terminal
     * lupdate -pro DengueME.pro -ts languageName.ts
     * open the .ts file on QTLinguistic.
     * after translated everything
     * use lrelease languageName.ts
     * a .qm file will be created, put this file on the translations folder
    */

    #if defined(Q_OS_MACOS)
        QDir modelsDir(ABS_APP_DIR);
        modelsDir.cdUp();
        modelsDir.cdUp();
        modelsDir.cdUp();
        if (!QDir(ABS_APP_DIR + "/Models/").exists()){
            QDir().mkdir(ABS_APP_DIR + "/Models/");
        }
        QString modelsPath = modelsDir.absolutePath() + "/Models/";
        dengueme::copy_dir_recursive(modelsPath, ABS_APP_DIR + "/Models/", 1);
    #endif

    QDir dir(QCoreApplication::applicationDirPath() + "/translations/");
    if (! dengueme::config("locale").isEmpty() && dengueme::config("locale") != "English") {
        QTranslator translator;
        translator.load(dir.absolutePath() +"/"+ dengueme::config("locale")+".qm");
        app.installTranslator(&translator);
    }

    QTranslator translator;
    translator.load(dir.absolutePath() +"/"+ dengueme::config("locale")+".qm");
    app.installTranslator(&translator);

    if (dengueme::config("prompt_workspace") == "true" || dengueme::config("workspace").isEmpty() || !QDir(dengueme::config("workspace")).exists()) {
        if (ChangeWorkspace().exec() != QDialog::Accepted) return 1;
        QDir dir(dengueme::config("workspace"));
        dir.mkpath(dir.absolutePath());
    }

    if (dengueme::config("terrame").isEmpty()) {
        dengueme::saveconfig("terrame","TerraME");
        dengueme::setconfig("terrame","TerraME");
    }
    if (dengueme::config("terrame/gui").isEmpty()) {
        dengueme::saveconfig("terrame/gui","true");
        dengueme::setconfig("terrame/gui","true");
    }
    if(dengueme::config("modelsVersion").isEmpty()){
        dengueme::saveconfig("modelsVersion","v0.1");
        dengueme::setconfig("modelsVersion","v0.1");
    }
    (new MainWindow)->show();

    return app.exec();
}


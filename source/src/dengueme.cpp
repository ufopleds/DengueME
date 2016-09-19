

#include "dengueme.h"
#include "mainwindow.h"
#include <QDebug>

//Settings and General functions

namespace dengueme {
    QSettings settingsFile(QSettings::IniFormat,QSettings::UserScope,"LEDS","DengueME");
    QString project;
    QHash<QString, QVariant> loadSettings() {
        QHash<QString, QVariant> settingsTable;
        foreach (QString x, settingsFile.allKeys())
            settingsTable[x] = settingsFile.value(x);
        return settingsTable;
    }

    QHash<QString, QVariant> settingsTable = loadSettings();

    // Config File
    QString config(QString opt, QString def) {
        return settingsTable.contains(opt) ?
                    settingsTable[opt].toString() :
                    def;
    }

    void saveconfig(QString opt, QString val) {
        settingsFile.setValue(opt, val);
    }

    void setconfig(QString opt, QString val) {
        settingsTable[opt] = val;
    }

    //Name Validation Functions
    NameValidation validateName(QString path, QString name, QString ext) {
        if (name.isEmpty())
            return EmptyName;

        if (!QRegExp("[A-Za-z0-9-_.]+").exactMatch(name))
            return UnallowedChar;

        if (QFile(path + QDir::separator() + name + ext).exists())
            return FileExists;

        return ValidName;
    }

    QString purgeName(QString name) {
        return name.remove(QRegExp("[^A-Za-z0-9-_.]"));
    }

    //File related Functions
    bool createProject(QString name) {
        QDir dir(config("workspace") + QDir::separator() + name);
        return dir.mkpath(dir.absolutePath());
    }

    bool openFile(QFile &file, QIODevice::OpenMode flags) {
        if (! file.exists() && flags & QFile::WriteOnly) {
            QDir dir;
            if (! dir.mkpath(QFileInfo(file).path())) {
                //            emit output(3,"Failed to create file: " + file.fileName());
                return false;
            }
        }
        if (! file.open(flags)) {
            //        emit output(3,"Failed to open file: " + file.fileName());
            return false;
        }
        return true;
    }

    bool copyFile(QString from, QString to, bool overwrite) {
        QFile file(from);

        file.setFileName(from);
        if (!file.exists()) {
            qDebug() << from << "does not exist.";
            return false;
        }

        QFileInfo info_to(to);
        if (info_to.exists()) {
            if (overwrite) {
                if (!remove(to)) {
                    qDebug() << to << "can't be removed.";
                    return false;
                }
            } else {
                return true; // no error if file is not overwirtten
            }
        }

        QDir dir;
        if (!dir.mkpath(info_to.path())) {
            qDebug() << "failed to make path" << info_to.path();
            return false;
        }

        if (!QFile::copy(from, to)) {
            qDebug() << "failed to create file" << to;
            return false;
        }

        return true;
    }

    bool remove(QString path) {
        QFileInfo info(path);
        if (!info.exists())
            return true;

        if (info.isDir()) {
            QDir dir(path);
            QFileInfoList entries = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst);
            bool ret = true;
            foreach (QFileInfo entryInfo, entries)
                ret &= remove(entryInfo.absoluteFilePath());
            return ret & dir.rmdir(dir.absolutePath());
        } else if (info.isFile()) {
            return QFile::remove(path);
        }
        return false;
    }

    bool createEmptyModel(QString filename) {
        QString blank = QDir::toNativeSeparators(DEFAULT_MODELS_DIR + "new_model.xml");

        return copyFile(blank, filename, true);
    }
    void setProject(QString proj){
        project = proj;
    }

    QString getProjectType(){
        qDebug() << project;
        return project;
    }

    bool createModel(QString dest, QString type, QString category) {

        QDir projdir(QFileInfo(dest).path());
        QDir modeldir;

        QString default_dir = DEFAULT_MODELS_DIR + category + '/' + type;
        QFileInfo default_model(default_dir + '/' + type + ".xml");

        if (default_model.exists()) {
            modeldir.setCurrent(default_dir);
            dengueme::copyFile(default_model.filePath(), dest, true);
        } else {
            QString user_models_dir = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)+"/dengueme" + '/' + category + '/' + type;


            QFileInfo user_model(user_models_dir + '/' + type + ".xml");

            if (user_model.exists()) {
                modeldir.setCurrent(user_models_dir);
                dengueme::copyFile(user_model.filePath(), dest, true);
            }
        }

        dengueme::copy(modeldir.filePath(type + "_scripts"), projdir.filePath(QFileInfo(dest).baseName() + "_scripts"), true);

        return true;
    }

    //Model Interface Lists
    QList<QPair<QString, QStringList> > model_types() {

        QString user_models =QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)+"/dengueme";
        QDir ent_usr_dir(user_models + "/vector");
        QDir epi_usr_dir(user_models + "/transmission");

        QDir ent_def_dir(DEFAULT_MODELS_DIR + "/vector");
        QDir epi_def_dir(DEFAULT_MODELS_DIR + "/transmission");

        QStringList ent_types;
        QStringList epi_types;

        foreach(QString x, ent_def_dir.entryList(QDir::NoDotAndDotDot | QDir::Dirs, QDir::Name))
            ent_types << x;

        foreach(QString x, epi_def_dir.entryList(QDir::NoDotAndDotDot | QDir::Dirs, QDir::Name))
            epi_types << x;

        foreach(QString x, ent_usr_dir.entryList(QDir::NoDotAndDotDot | QDir::Dirs, QDir::Name))
            ent_types << x;

        foreach(QString x, epi_usr_dir.entryList(QDir::NoDotAndDotDot | QDir::Dirs, QDir::Name))
            epi_types << x;

        QPair<QString, QStringList> ent("vector", ent_types);
        QPair<QString, QStringList> epi("transmission", epi_types);

        QList<QPair<QString, QStringList> > ret;
        ret.append(ent);
        ret.append(epi);
        return ret;
    }

    //adapted from:
    //https://github.com/danimo/qt-creator/blob/master/src/libs/utils/fileutils.cpp
    bool copy(const QString &srcFilePath, const QString &tgtFilePath, bool overwrite){
        if (QFileInfo(tgtFilePath).exists()) {
            if (overwrite) {
                if (!remove(tgtFilePath)) {
                    qDebug() << tgtFilePath << "can't be removed.";
                    return false;
                }
            } else {
                return true; // no error if file is not overwirtten
            }
        }

        QFileInfo srcFileInfo(srcFilePath);
        QDir().mkpath(QFileInfo(tgtFilePath).path());
        if (srcFileInfo.isDir()) {
            QDir targetDir(tgtFilePath);
            targetDir.cdUp();
            if (!targetDir.mkdir(QFileInfo(tgtFilePath).fileName()))
                return false;
            QDir sourceDir(srcFilePath);
            QStringList fileNames = sourceDir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
            foreach (const QString &fileName, fileNames) {
                const QString newSrcFilePath = srcFilePath + QLatin1Char('/') + fileName;
                const QString newTgtFilePath = tgtFilePath + QLatin1Char('/') + fileName;
                if (!copy(newSrcFilePath, newTgtFilePath))
                    return false;
            }
        } else {
            if (!QFile::copy(srcFilePath, tgtFilePath))
                return false;
        }
        return true;
    }
}

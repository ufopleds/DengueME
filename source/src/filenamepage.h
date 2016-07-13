#ifndef FILENAMEPAGE_H
#define FILENAMEPAGE_H

#include <QWizardPage>
#include <QLineEdit>
#include <QLabel>

#include "dengueme.h"

class FilenamePage: public QWizardPage {
    Q_OBJECT

public:
    FilenamePage(QString path, QString def = QString(), QString extension = QString());

    int nextId() const;

private:
    QString path;
    QString def;
    QString ext;
    QString subtitle;
    QLabel *projectName;
    QLineEdit *projectLineEdit;
    dengueme::NameValidation state;

    bool isComplete() const;

public slots:
    void validateProject(QString name);
};

#endif // FILENAMEPAGE_H

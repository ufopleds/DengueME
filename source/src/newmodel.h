#ifndef NEWMODEL_H
#define NEWMODEL_H

#include <QWizard>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QTreeWidget>

#include "dengueme.h"

class NewModel : public QWizard {
    Q_OBJECT
public:
    NewModel(QString workspace, QString project = QString(), QWidget *parent = 0);
    enum { idNamePage, idProjectPage, idNewProjectPage, idTypePage };

private:
    void accept();

signals:
    void accepted(QString category, QString type, QString project, QString name);
};

class TypePage: public QWizardPage {
    Q_OBJECT

public:
    struct {
        QStringList types;
        QList<QStringList> names;
    } models;


    QTreeWidget *modelType;
    QListWidget *modelName;

    TypePage();

    bool isComplete() const;

public slots:
    void itemChanged();
    void itemClicked();
    void nameSelected(QString item);
};

class ProjectPage: public QWizardPage {
    Q_OBJECT

public:
    QListWidget *projects;
    QPushButton *newproject;
    QString workspace;
    QString project;

    ProjectPage(QString workspace, QString project);
    bool isComplete() const;

public slots:
    void itemChanged();
    void newProject();
    void loadWorkspace();
};

class NamePage: public QWizardPage {
    Q_OBJECT

public:
    QLabel *modelName;
    QLineEdit *projectLineEdit;
    QListWidget *projects;
    QString subtitle;
    QString workspace;
    dengueme::NameValidation state;

    NamePage(QString workspace);


    bool isComplete() const;

public slots:
    void validateProject(QString name);
    void setWorkspace(QString path);
};

#endif // NEWMODEL_H

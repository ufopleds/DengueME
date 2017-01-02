#include <QGridLayout>
#include <QToolTip>

#include "qdebug.h"
#include "filenamepage.h"
#include "dengueme.h"


FilenamePage::FilenamePage(QString path, QString def, QString extension)
    : path(path), def(def), ext(extension),
      subtitle(tr("Specify a unique name to identify your project in the workspace.")),
      state(dengueme::EmptyName){

    setTitle(tr("Specify a name"));
    setSubTitle(subtitle);

    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    projectName = new QLabel(tr("&Name:"));
    projectLineEdit = new QLineEdit(def);
    projectName->setBuddy(projectLineEdit);

    connect(projectLineEdit, SIGNAL(textChanged(QString)), this, SLOT(validateProject(QString)));

    registerField("name*", projectLineEdit);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(projectName, 0, 0);
    layout->addWidget(projectLineEdit, 0, 1);
    setLayout(layout);
    projectLineEdit->setFocus();

}


void FilenamePage::validateProject(QString name) {

    switch (dengueme::validateName(path, name, ext)) {

    case dengueme::EmptyName:
        if (state != dengueme::EmptyName) {
            setSubTitle(subtitle);
            state = dengueme::EmptyName;
            setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/error.png"));
        }
        break;

    case dengueme::UnallowedChar:
        projectLineEdit->setText(dengueme::purgeName(name));
        QToolTip::showText( projectLineEdit->mapToGlobal(QPoint(0, projectLineEdit->height())),
                            tr("The project name can contain only\nalphanumeric chars, hyphen (-), \nunderscore (_) and dot (.)."));
        break;

    case dengueme::FileExists:

        state = dengueme::FileExists;
        if (def.isEmpty() || def != name) {
            setSubTitle(tr("A file with that name already exists."));
            setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/error.png"));
        } else {
            setSubTitle(tr("Specify a new unique name:"));
            setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/error.png"));
        }

        break;

    case dengueme::ValidName:
        if (state != dengueme::ValidName) {
            setSubTitle(subtitle);
            state = dengueme::ValidName;
            setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/ok.png"));
        }
        break;
    }
}

int FilenamePage::nextId() const {
    return -1;
}

bool FilenamePage::isComplete() const {
    return state == dengueme::ValidName;
}

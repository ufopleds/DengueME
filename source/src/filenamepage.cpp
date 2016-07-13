#include <QGridLayout>
#include <QToolTip>

#include "filenamepage.h"
#include "dengueme.h"

//Defines the FileName page
FilenamePage::FilenamePage(QString path, QString def, QString extension)
    : path(path), def(def), ext(extension),
      subtitle(tr("Specify a unique name to identify your project in the workspace.")),
      state(dengueme::EmptyName)
{
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

//Validate project - Observes if the name is not Empty, if all chararacters used in the name are allowed , if it already exists

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
//        if (state != dengueme::FileExists) {
        state = dengueme::FileExists;
        if (def.isEmpty() || def != name) {
            setSubTitle(tr("A file with that name already exists."));
            setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/error.png"));
        } else {
            setSubTitle(tr("Specify a new name for your project."));
            setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/error.png"));
        }
//        }
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

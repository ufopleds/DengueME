#include <QFileDialog>
#include <QDesktopServices>
#include <QHBoxLayout>

#include "changeworkspace.h"
#include "dengueme.h"

using namespace detail;

ChangeWorkspace::ChangeWorkspace(QWidget *parent) :
    QWizard(parent)
{
     this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setPage(Page_SelectWorkspace, new SelectPage(this));
    setStartId(Page_SelectWorkspace);
    setOption(QWizard::NoBackButtonOnLastPage);
 //   setPixmap(QWizard::LogoPixmap, QPixmap(":/Resources/logo.png"));
    setWindowTitle(tr("Workspace Directory"));

}

void ChangeWorkspace::accept() {
    QString path(field("path").toString());
    if (field("setDefault").toBool()) {
        dengueme::setconfig("workspace", path);
        dengueme::saveconfig("workspace", path);
        dengueme::setconfig("prompt_workspace", "false");
        dengueme::saveconfig("prompt_workspace", "false");
    }
    else
        dengueme::setconfig("workspace", path);

    done(QDialog::Accepted);
}

SelectPage::SelectPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Workpace"));
    setSubTitle(tr("Specify the workspace path."));

    pathLabel = new QLabel(tr("&Workspace path:"));

   pathLineEdit = new QLineEdit(
                dengueme::config("workspace").isEmpty() ?
                    QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation) + "/dengueme_workspace"
                  :
                    dengueme::config("workspace")
                );
    pathLabel->setBuddy(pathLineEdit);
    connect(pathLineEdit, SIGNAL(textChanged(QString)), SLOT(validate(QString)));
    registerField("path", pathLineEdit);

    browse = new QPushButton(tr("Browse"));
    connect(browse, SIGNAL(pressed()), SLOT(browseWorkspace()));

    setDefault = new QCheckBox(tr("Use as default workspace"));
    registerField("setDefault", setDefault);

    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pathLabel);
    hlayout->addWidget(pathLineEdit);
    hlayout->addWidget(browse);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(hlayout);
    layout->addWidget(setDefault);

    setLayout(layout);
    pathLineEdit->setFocus();

}

void SelectPage::browseWorkspace() {
    QString path(QFileDialog::getExistingDirectory(this,tr("Workspace Path"),dengueme::config("workspace")));
    if (!path.isEmpty())
        pathLineEdit->setText(path);
}

void SelectPage::validate(QString path) {
    if (path.isEmpty())
        wizard()->button(QWizard::FinishButton)->setEnabled(false);
    else
        wizard()->button(QWizard::FinishButton)->setEnabled(true);
}

int SelectPage::nextId() const {
    return -1;
}

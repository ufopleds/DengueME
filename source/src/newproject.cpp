#include "newproject.h"
#include "filenamepage.h"

NewProject::NewProject(QString workspace, QWidget *parent)
    : QWizard(parent){

    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    setOption(QWizard::NoBackButtonOnLastPage);
    setPage(Page_Filename, new FilenamePage(workspace));
    setStartId(Page_Filename);
    setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/img/logo.png"));
    setWindowTitle(tr("New project"));

    this->setButtonText(QWizard::FinishButton,tr("Finish"));
    this->setButtonText(QWizard::CancelButton,tr("Cancel"));
}

void NewProject::accept(){
    emit accepted(field("name").toString());
    QWizard::accept();
}



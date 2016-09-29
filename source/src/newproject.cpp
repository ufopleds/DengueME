#include "newproject.h"
#include "filenamepage.h"

NewProject::NewProject(QString workspace, QWidget *parent)
    : QWizard(parent){
         this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setOption(QWizard::NoBackButtonOnLastPage);
    setPage(Page_Filename, new FilenamePage(workspace));
    setStartId(Page_Filename);
//#ifndef Q_WS_MAC
//    setWizardStyle(ModernStyle);
//#endif
//    setOption(HaveHelpButton, true);
  setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/img/logo.png"));
//    connect(this, SIGNAL(helpRequested()), this, SLOT(showHelp()));
    setWindowTitle(tr("New project"));
    this->setButtonText(QWizard::FinishButton,tr("Finish"));
    this->setButtonText(QWizard::CancelButton,tr("Cancel"));
}

void NewProject::accept(){
    emit accepted(field("name").toString());
    QWizard::accept();
}

//void NewProject::showHelp() {
//    QString message;

//    switch (currentId()) {
//        break;
//    case Page_Filename:
//        message = tr("The project name can contain only alphanumeric chars, hyphen (-) and underscore (_).");
//        break;
//    default:
//        return;
//    }

//    QMessageBox::information(this, tr("Help"), message);
//}


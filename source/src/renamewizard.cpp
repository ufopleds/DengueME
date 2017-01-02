#include "renamewizard.h"
#include "dengueme.h"
#include "filenamepage.h"

RenameWizard::RenameWizard(QString path, QString name, bool isProject, QWidget *parent) :
    QWizard(parent){

    FilenamePage *page = new FilenamePage(path, name, isProject ? "" : ".xml");

    setOption(QWizard::NoBackButtonOnLastPage);
    setPage(Page_Filename, page);
    setStartId(Page_Filename);
    page->validateProject(name);
    setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/img/icon-error.png"));
    setWindowTitle(tr("Project name"));
}

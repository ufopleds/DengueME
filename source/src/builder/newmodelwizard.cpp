#include "newmodelwizard.h"
#include "../newmodel.h"

NewModelWizard::NewModelWizard(QString workspace, QString project, QWidget *parent)
    : QWizard(parent)
{
    ProjectPage *proj = new ProjectPage(workspace, project);
    delete proj->newproject;
    addPage(proj);
    addPage(new NamePage(workspace));
}

NewModelWizard::~NewModelWizard()
{

}


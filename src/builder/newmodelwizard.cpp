#include "newmodelwizard.h"
#include "../newmodel.h"

NewModelWizard::NewModelWizard(QString workspace, QString project, QWidget* parent)
  : QWizard(parent) {
  this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
  setWindowTitle(tr("New model"));

  CategoryPage* proj = new CategoryPage(workspace, project);

  addPage(proj);
  addPage(new NamePage(workspace));

  this->setButtonText(QWizard::NextButton,  tr("Next"));
  this->setButtonText(QWizard::CancelButton,  tr("Cancel"));
  this->setButtonText(QWizard::FinishButton,  tr("Create"));
}

NewModelWizard::~NewModelWizard() {

}


#include "newproject.h"
#include "newmodel.h"
#include "mainwindow.h"
#include "ui_newproject.h"
#include "dengueme.h"
#include "iconsFontAwesome.h"

NewProject::NewProject(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::NewProject) {
  ui->setupUi(this);
  this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

  connect(ui->project_name, SIGNAL(textChanged(QString)), this, SLOT(checkLineEdited(QString)), Qt::UniqueConnection);
  connect(ui->cancelButton, SIGNAL(released()), this, SLOT(close()));
  connect(ui->okButton, SIGNAL(released()), this, SLOT(onOkPressed()));

  ui->error_message->setText("");
  ui->error_message->setWordWrap(true);
  ui->okButton->setDisabled(true);
  ui->project_name->setMaxLength(40);
}

NewProject::~NewProject() {
  delete ui;
}

void NewProject::accept() {
  this->close();
  if (ui->newModelCheckBox->isChecked()) {
    int checked = 1;
    emit accepted((ui->project_name->text()), checked);
  } else {
    int notChecked = 0;
    emit accepted((ui->project_name->text()), notChecked);
  }
}

void NewProject::onOkPressed() {
  this->accept();
}

QString NewProject::getProjectName() {
  return ui->project_name->text();
}

void NewProject::checkLineEdited(const QString& str) {
  QFont fontAwesome;
  fontAwesome.setFamily("FontAwesome");
  fontAwesome.setPixelSize(12);
  ui->error_message->setFont(fontAwesome);

  QString path = dengueme::config("workspace") + QDir::separator() + str;
  QRegExp regexp("^[A-Z0-9-a-z_]*$");
  if (!regexp.exactMatch(str)) {
    ui->okButton->setDisabled(true);
    ui->project_name->setStyleSheet("border: 1px solid red");
    ui->error_message->setText(ICON_FA_TIMES_CIRCLE + tr("  The project name can only contain alphanumeric chars, hyphen (-) and underscore (_)."));
  } else if (QFile(path).exists()) {
    ui->project_name->setStyleSheet("border: 1px solid red");
    ui->error_message->setText(ICON_FA_TIMES_CIRCLE + tr("  A project with this name already exists in current workspace."));
    ui->okButton->setDisabled(true);
  } else {
    ui->project_name->setStyleSheet("");
    ui->okButton->setDisabled(false);
    ui->error_message->setText("");
  }
  if ((ui->project_name->text()).trimmed().isEmpty()) {
    ui->project_name->setStyleSheet("");
    ui->error_message->setText("");
    ui->okButton->setDisabled(true);
  }
}

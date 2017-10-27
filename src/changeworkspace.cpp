#include <QFileDialog>
#include <QDesktopServices>
#include "ui_changeworkspace.h"
#include "changeworkspace.h"
#include "dengueme.h"
#include "iconsFontAwesome.h"

ChangeWorkspace::ChangeWorkspace(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::ChangeWorkspace) {
  ui->setupUi(this);
  this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

  connect(ui->okButton, SIGNAL(clicked()), this, SLOT(accept()));
  connect(ui->cancelButton, SIGNAL(released()), this, SLOT(close()));
  connect(ui->workspaceLineEdit, SIGNAL(textChanged(QString)), this, SLOT(checkLineEdited(QString)), Qt::UniqueConnection);
  connect(ui->browseButton, SIGNAL(released()), SLOT(browseWorkspace()));

  ui->error_message->setText("");
  ui->error_message->setWordWrap(true);
  if(dengueme::config("workspace").isEmpty())
    ui->workspaceLineEdit->setText(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/dengueme_workspace");
  else
    ui->workspaceLineEdit->setText(dengueme::config("workspace"));

}

ChangeWorkspace::~ChangeWorkspace() {
  delete ui;
}

void ChangeWorkspace::browseWorkspace() {
  QString path = QFileDialog::getExistingDirectory(this, tr("Browse"), dengueme::config("workspace"));
  if (!path.isEmpty())
    ui->workspaceLineEdit->setText(path);
}

void ChangeWorkspace::checkLineEdited(const QString& path) {
  QFont fontAwesome;
  fontAwesome.setFamily("FontAwesome");
  fontAwesome.setPixelSize(12);
  ui->error_message->setFont(fontAwesome);

  if (QDir(path).exists()) {
    ui->workspaceLineEdit->setStyleSheet("");
    ui->error_message->setText("");
    if (!path.isEmpty())
      ui->okButton->setEnabled(true);
    else
      ui->okButton->setEnabled(false);
  } else {
    ui->workspaceLineEdit->setStyleSheet("border: 1px solid red");
    ui->error_message->setText(ICON_FA_TIMES_CIRCLE + tr("  This folder does not exist."));
    ui->okButton->setEnabled(false);
  }
}

void ChangeWorkspace::accept() {

  QString path(ui->workspaceLineEdit->text());

  if (ui->defaultCheckBox->isChecked()) {
    dengueme::setconfig("workspace", path);
    dengueme::saveconfig("workspace", path);
    dengueme::setconfig("prompt_workspace", "false");
    dengueme::saveconfig("prompt_workspace", "false");
  } else
    dengueme::setconfig("workspace", path);

  done(QDialog::Accepted);
}


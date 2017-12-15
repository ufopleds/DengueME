#include <QTranslator>
#include <QFileDialog>
#include "dengueme.h"
#include "options.h"
#include "ui_options.h"
#include "iconsFontAwesome.h"

Options::Options(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::Options) {
  ui->setupUi(this);
  this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

  QFont fontAwesome;
  fontAwesome.setFamily("FontAwesome");
  fontAwesome.setPixelSize(12);

  ui->warningMessageLabel->setFont(fontAwesome);
  ui->errorWorksapcePath->setFont(fontAwesome);
  ui->errorTmePath->setFont(fontAwesome);
  ui->errorRPath->setFont(fontAwesome);

  ui->warningMessageLabel->setText("");
  ui->errorWorksapcePath->setText("");
  ui->errorTmePath->setText("");
  ui->errorRPath->setText("");

  ui->workspaceLineEdit->setText(dengueme::settingsFile.value("workspace").toString());
  ui->tmeLineEdit->setText(dengueme::settingsFile.value("terrame").toString());
  ui->rLineEdit->setText(dengueme::settingsFile.value("rscript").toString());

  ui->startupPathCheckBox->setChecked(dengueme::settingsFile.value("prompt_workspace") == "true");
  ui->languageComboBox->addItem("English");

  QDir dir(QCoreApplication::applicationDirPath() + "/translations");
  foreach (QFileInfo x, dir.entryInfoList(QDir::Files))
    if (x.suffix() == "qm")
      ui->languageComboBox->addItem(x.baseName());

  for (int i = 0; i < ui->languageComboBox->count(); ++i)
    if (ui->languageComboBox->itemText(i) == dengueme::settingsFile.value("locale"))
      ui->languageComboBox->setCurrentIndex(i);

  connect(ui->browseWorkspaceButton, SIGNAL(pressed()), this, SLOT(browseWorkspace()));
  connect(ui->browseTmeButton, SIGNAL(pressed()), this, SLOT(browseTerraME()));
  connect(ui->browseRButton, SIGNAL(pressed()), this, SLOT(browseRscript()));
  connect(ui->languageComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(languageMessage()));

  connect(ui->workspaceLineEdit, SIGNAL(textChanged(QString)), this, SLOT(checkPath(QString)), Qt::UniqueConnection);
  connect(ui->tmeLineEdit, SIGNAL(textChanged(QString)), this, SLOT(checkPath(QString)), Qt::UniqueConnection);
  connect(ui->rLineEdit, SIGNAL(textChanged(QString)), this, SLOT(checkPath(QString)), Qt::UniqueConnection);

  connect(ui->startupPathCheckBox, SIGNAL(stateChanged(int)), this, SLOT(checkCheckBox()));

  connect(ui->okButton, SIGNAL(clicked()), this, SLOT(accept()));
  connect(ui->cancelButton, SIGNAL(released()), this, SLOT(close()));

}

Options::~Options() {
  delete ui;
}

void Options::languageMessage() {
  QString actualLanguage = dengueme::config("locale");

  if (actualLanguage != ui->languageComboBox->currentText()) {
    ui->warningMessageLabel->setText(ICON_FA_EXCLAMATION_TRIANGLE + tr("  You must roboot DengueME to apply the language change."));
  } else {
    ui->warningMessageLabel->setText("");
  }
}

void Options::checkCheckBox() {
  if(ui->startupPathCheckBox->isChecked()) {
    ui->workspaceLineEdit->setEnabled(false);
  } else {
    ui->workspaceLineEdit->setEnabled(true);
  }
}

void Options::browseWorkspace() {
  QString path(QFileDialog::getExistingDirectory(this, tr("Workspace Path"), ui->workspaceLineEdit->text()));
  if (!path.isEmpty())
    ui->workspaceLineEdit->setText(path);
}

void Options::browseTerraME() {
  QString path(QFileDialog::getOpenFileName(this, tr("TerraME Path"), ui->tmeLineEdit->text(), "TerraME Executable (*.*)"));
  if (!path.isEmpty())
    ui->tmeLineEdit->setText(path);
}

void Options::browseRscript() {
  QString path(QFileDialog::getOpenFileName(this, tr("Rscript Path"), ui->rLineEdit->text(), "TerraME Executable (*.*)"));
  if (!path.isEmpty())
    ui->rLineEdit->setText(path);
}

void Options::checkPath(QString path) {
  QObject* obj = sender();

  QString errorMessage = tr("  This folder does not exist.");
  QString errorMessageInterpreter = tr("  This path is not valid.");
  QString styleSheet = "border: 1px solid red";

  if(obj == ui->workspaceLineEdit) {
    if (QDir(path).exists()) {
      ui->workspaceLineEdit->setStyleSheet("");
      ui->errorWorksapcePath->setText("");
      if (!path.isEmpty())
        ui->okButton->setEnabled(true);
      else
        ui->okButton->setEnabled(false);
    } else {
      ui->workspaceLineEdit->setStyleSheet(styleSheet);
      ui->errorWorksapcePath->setText(ICON_FA_TIMES_CIRCLE + errorMessage);
      ui->okButton->setEnabled(false);
    }
  } else {
    if (QFile(path).exists() || path.isEmpty()) {
      ui->tmeLineEdit->setStyleSheet("");
      ui->rLineEdit->setStyleSheet("");
      ui->errorTmePath->setText("");
      ui->errorRPath->setText("");
      ui->okButton->setEnabled(true);
    } else {
      if (obj == ui->tmeLineEdit) {
        ui->tmeLineEdit->setStyleSheet(styleSheet);
        ui->errorTmePath->setText(ICON_FA_TIMES_CIRCLE + errorMessageInterpreter);
      } else {
        ui->rLineEdit->setStyleSheet(styleSheet);
        ui->errorRPath->setText(ICON_FA_TIMES_CIRCLE + errorMessageInterpreter);
      }
      ui->okButton->setEnabled(false);
    }
  }

}

void Options::accept() {
  dengueme::saveconfig("workspace", ui->workspaceLineEdit->text());
  dengueme::setconfig("workspace", ui->workspaceLineEdit->text());

  dengueme::saveconfig("terrame", ui->tmeLineEdit->text());
  dengueme::setconfig("terrame", ui->tmeLineEdit->text());

  dengueme::saveconfig("rscript", ui->rLineEdit->text());
  dengueme::setconfig("rscript", ui->rLineEdit->text());

  dengueme::saveconfig("prompt_workspace", ui->startupPathCheckBox->isChecked() ? "true" : "false");
  dengueme::setconfig("prompt_workspace", ui->startupPathCheckBox->isChecked() ? "true" : "false");

  dengueme::saveconfig("locale", ui->languageComboBox->currentText());
  dengueme::setconfig("locale", ui->languageComboBox->currentText());
  close();
}


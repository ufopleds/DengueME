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
  ui->iconWarning->setFont(fontAwesome);

  ui->iconWarningRunLabel->setFont(fontAwesome);
  ui->warningRunLabel->setFont(fontAwesome);

  ui->errorWorksapcePath->setFont(fontAwesome);
  ui->errorTmePath->setFont(fontAwesome);
  ui->errorRPath->setFont(fontAwesome);

  ui->warningRunLabel->setText("");
  ui->iconWarningRunLabel->setText("");

  ui->warningMessageLabel->setText("");
  ui->iconWarning->setText("");

  ui->errorWorksapcePath->setText("");
  ui->errorTmePath->setText("");
  ui->errorRPath->setText("");

  ui->workspaceLineEdit->setText(dengueme::settingsFile.value("workspace").toString());
  ui->tmeLineEdit->setText(dengueme::settingsFile.value("terrame").toString());
  ui->rLineEdit->setText(dengueme::settingsFile.value("rscript").toString());

  ui->startupPathCheckBox->setChecked(dengueme::settingsFile.value("prompt_workspace") == "true");

  if (dengueme::config("locale") == "English")
    ui->languageComboBox->addItem("English");
  else
    ui->languageComboBox->addItem("Inglês");

  QDir dir(QCoreApplication::applicationDirPath() + "/translations");
  foreach (QFileInfo x, dir.entryInfoList(QDir::Files))
    if (x.suffix() == "qm") {
      if (dengueme::config("locale") == "English")
        ui->languageComboBox->addItem(x.baseName());
      else
        ui->languageComboBox->addItem(getLanguageName(x.baseName()));
    }

  for (int i = 0; i < ui->languageComboBox->count(); ++i) {
    if (dengueme::settingsFile.value("locale") != dengueme::settingsFile.value("gui_user_language")) {
      if (getLanguageName(ui->languageComboBox->itemText(i)) == dengueme::settingsFile.value("locale"))
        ui->languageComboBox->setCurrentIndex(i);

      QString userLanguage = dengueme::config("locale") == "English" ? dengueme::config("gui_user_language") : getLanguageName(dengueme::config("gui_user_language"));
      QString warningLanguage = tr("  There is a pending update: the interface will change to ") + userLanguage +  tr(" in the next initialization.");

      ui->iconWarning->setText(ICON_FA_EXCLAMATION_TRIANGLE);
      ui->warningMessageLabel->setText(warningLanguage);
    } else {
      if (getLanguageName(ui->languageComboBox->itemText(i)) == dengueme::settingsFile.value("gui_user_language"))
        ui->languageComboBox->setCurrentIndex(i);
    }
  }

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
  QString systemLanguage = dengueme::config("locale") == "English" ? dengueme::config("locale") : getLanguageName(dengueme::config("locale"));

  if (systemLanguage != ui->languageComboBox->currentText()) {
    ui->iconWarning->setText(ICON_FA_EXCLAMATION_TRIANGLE);
    ui->warningMessageLabel->setText(tr("Please restart DengueME for the changes to take effect."));
  } else {
    QString oldWorkspacePath = dengueme::settingsFile.value("workspace").toString();
    if (errorWorkspace == false && (oldWorkspacePath == ui->workspaceLineEdit->text())) {
      ui->iconWarning->setText("");
      ui->warningMessageLabel->setText("");
    }


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

  QString warningMessage = tr("You must reboot DengueME to apply the path change.");
  QString errorMessage = tr("  This folder does not exist.");
  QString errorMessageInterpreter = tr("  This path is not valid.");
  QString styleSheet = "border: 1px solid red";

  if(obj == ui->workspaceLineEdit) {
    if (QDir(path).exists()) {
      QString oldWorkspacePath = dengueme::settingsFile.value("workspace").toString();
      if (path != oldWorkspacePath) {
        ui->iconWarning->setText(ICON_FA_EXCLAMATION_TRIANGLE);
        ui->warningMessageLabel->setText(tr("You must reboot DengueME to apply the change."));
      }

      errorWorkspace = false;
      ui->workspaceLineEdit->setStyleSheet("");
      ui->errorWorksapcePath->setText("");
      if (!path.isEmpty()) {
        if (errorR == false && errorTme == false) {
          ui->okButton->setEnabled(true);
        } else {
          ui->okButton->setEnabled(false);
        }
      }
    } else {
      errorWorkspace = true;
      ui->workspaceLineEdit->setStyleSheet(styleSheet);
      ui->errorWorksapcePath->setText(ICON_FA_TIMES_CIRCLE + errorMessage);
      ui->okButton->setEnabled(false);
    }
  } else {
    if (QFile(path).exists() || path.isEmpty()) {
      if (obj == ui->tmeLineEdit) {
        ui->tmeLineEdit->setStyleSheet("");
        ui->errorTmePath->setText("");
        errorTme = false;
        if (errorR == false && errorWorkspace == false)
          ui->okButton->setEnabled(true);
      } else {
        ui->rLineEdit->setStyleSheet("");
        ui->errorRPath->setText("");
        errorR = false;
        if (errorTme == false && errorWorkspace == false)
          ui->okButton->setEnabled(true);
      }

      QString oldPathTME = dengueme::settingsFile.value("terrame").toString();
      QString oldPathR = dengueme::settingsFile.value("rscript").toString();
      if ((oldPathTME != path) && (oldPathR != path)) {
        ui->iconWarningRunLabel->setText(ICON_FA_EXCLAMATION_TRIANGLE);
        ui->warningRunLabel->setText(warningMessage);
      } else {
        ui->iconWarningRunLabel->setText("");
        ui->warningRunLabel->setText("");
      }

    } else {
      if (obj == ui->tmeLineEdit) {
        ui->tmeLineEdit->setStyleSheet(styleSheet);
        ui->errorTmePath->setText(ICON_FA_TIMES_CIRCLE + errorMessageInterpreter);
        errorTme = true;
      } else {
        ui->rLineEdit->setStyleSheet(styleSheet);
        ui->errorRPath->setText(ICON_FA_TIMES_CIRCLE + errorMessageInterpreter);
        errorR = true;
      }
      ui->okButton->setEnabled(false);

    }
  }

}

QString Options::getLanguageName(QString name) {
  if (name == "English")
    return "Inglês";
  else if (name == "Inglês")
    return "English";
  else if (name == "Portuguese")
    return "Português";
  else if (name == "Português")
    return "Portuguese";
  else
    return {};
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

  if (dengueme::config("locale") == "English") {
    dengueme::saveconfig("gui_user_language", ui->languageComboBox->currentText());
    dengueme::setconfig("gui_user_language", ui->languageComboBox->currentText());
  } else {
    dengueme::saveconfig("gui_user_language", getLanguageName(ui->languageComboBox->currentText()));
    dengueme::setconfig("gui_user_language", getLanguageName(ui->languageComboBox->currentText()));
  }

  close();
}


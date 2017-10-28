#include "rename.h"
#include "ui_rename.h"
#include "dengueme.h"
#include "iconsFontAwesome.h"

RenameModel::RenameModel(QString path, QString name, QString extension, QWidget* parent) :
  QDialog(parent),
  path(path),
  modelName(name),
  fileExtension(extension),
  state(dengueme::EmptyName),
  ui(new Ui::RenameModel) {
  ui->setupUi(this);
  this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

  ui->error_message->setText("");
  ui->error_message->setWordWrap(true);
  ui->okButton->setDisabled(true);
  ui->namelineEdit->setText(modelName);

  connect(ui->namelineEdit, SIGNAL(textChanged(QString)), this, SLOT(checkLineEdited(QString)), Qt::UniqueConnection);
  connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(close()));
  connect(ui->okButton, SIGNAL(clicked()), this, SLOT(accept()));
  connect(ui->namelineEdit, SIGNAL(returnPressed()), this, SLOT(onEnterPressed()));
}

RenameModel::~RenameModel() {
  delete ui;
}

void RenameModel::onEnterPressed() {
  if(ui->okButton->isEnabled())
    ui->okButton->click();
  else
    ui->namelineEdit->setFocus();
}

QString RenameModel::getModelName() {
  return ui->namelineEdit->text();
}

void RenameModel::setModelName(const QString& modelName) {
  ui->namelineEdit->setText(modelName);
}

void RenameModel::checkLineEdited(const QString& str) {
  QFont fontAwesome;
  fontAwesome.setFamily("FontAwesome");
  fontAwesome.setPixelSize(12);
  ui->error_message->setFont(fontAwesome);

  switch (dengueme::validateName(path, str, fileExtension)) {
    case dengueme::EmptyName:
      if (state != dengueme::EmptyName) {
        ui->namelineEdit->setStyleSheet("");
        ui->error_message->setText("");
        ui->okButton->setDisabled(true);
      }
      break;

    case dengueme::UnallowedChar:
      ui->okButton->setDisabled(true);
      ui->namelineEdit->setStyleSheet("border: 1px solid red");
      ui->error_message->setText(ICON_FA_TIMES_CIRCLE + tr("  The model name can contain only alphanumeric chars, hyphen (-) and / or underscore (_)."));
      break;

    case dengueme::FileExists:
      state = dengueme::FileExists;
      if (modelName == str) {
        ui->okButton->setDisabled(true);
        ui->namelineEdit->setStyleSheet("");
        ui->error_message->setText("");
      } else {
        if ((!QFile(path + QDir::separator() + str + ".xml").exists())) {
          state = dengueme::ValidName;
          ui->okButton->setDisabled(false);
          ui->namelineEdit->setStyleSheet("");
          ui->error_message->setText("");
        } else {
          ui->namelineEdit->setStyleSheet("border: 1px solid red");
          ui->error_message->setText(ICON_FA_TIMES_CIRCLE + tr("  A model with this name already exists in current project."));
          ui->okButton->setDisabled(true);
        }
      }
      break;

    case dengueme::ValidName:
      if (state != dengueme::ValidName) {
        ui->okButton->setDisabled(false);
        ui->namelineEdit->setStyleSheet("");
        ui->error_message->setText("");
      }
      break;
  }
}

#include "newmodelbuilder.h"
#include "ui_newmodelbuilder.h"
#include "iconsFontAwesome.h"
#include "dengueme.h"
#include <QStandardItemModel>

#include <QDebug>

NewModelBuilder::NewModelBuilder(QString workspace, QString project, QWidget* parent) :
  workspace(workspace),
  project(project),
  QDialog(parent),
  ui(new Ui::NewModelBuilder) {
  ui->setupUi(this);
  this->setWindowModality(Qt::ApplicationModal);
  this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

  connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(close()));
  connect(ui->createButton, SIGNAL(clicked()), this, SLOT(onCreateButton()));
  connect(ui->nameLineEdit, SIGNAL(textChanged(QString)), this, SLOT(checkModelName(QString)), Qt::UniqueConnection);
  connect(ui->categoriesComboBox, SIGNAL(activated(int)), this, SLOT(checkComboBox()));

  QList<QPair<QString, QStringList> > modelTypes = dengueme::model_types();

  for (int i = 0; i < modelTypes.size(); ++i)
    models.types.append(modelTypes[i].first);

  for (int i = 0; i < modelTypes.size(); ++i)
    models.names.append(modelTypes[i].second);

  ui->errorLabelName->setText("");
  ui->createButton->setDisabled(true);

  addCategories();
}

NewModelBuilder::~NewModelBuilder() {
  delete ui;
}

void NewModelBuilder::addCategories() {
  ui->categoriesComboBox->clear();
  QString rootItem = tr("Select a category");
  if (dengueme::config("locale") != "English") {
    for (int i = 0; i < models.types.size(); i++) {
      models.types[i] = getCategoryName(models.types[i]);
    }
  }

  ui->categoriesComboBox->addItem(rootItem);
  qobject_cast<QStandardItemModel*>(ui->categoriesComboBox->model())->item( 0 )->setEnabled( false );

  ui->categoriesComboBox->addItems(models.types);
  ui->categoriesComboBox->setCurrentIndex(0);
}

QString NewModelBuilder::getCategoryName(QString category) {
  if (category == "vector")
    return "vetor";
  else if (category == "vetor")
    return "vector";
  else if (category == "transmission")
    return "transmissão";
  else if (category == "transmissão")
    return "transmission";
  else if (category == "hospedeiro")
    return "host";
  else if (category == "host")
    return "hospedeiro";
  else if (category == "mobilidade")
    return "mobility";
  else if (category == "mobility")
    return "mobilidade";
  else if (category == "landscape")
    return "classificação de paisagem";
  else if (category == "classificação de paisagem")
    return "landspace";
  else if (category == "virus")
    return "vírus";
  else if (category == "vírus")
    return "virus";
  else
    return {};
}

void NewModelBuilder::checkComboBox() {
  QString modelName = ui->nameLineEdit->text();
  checkModelName(modelName);
}

void NewModelBuilder::checkModelName(const QString& str) {
  QFont fontAwesome;
  fontAwesome.setFamily("FontAwesome");
  fontAwesome.setPixelSize(12);
  ui->errorLabelName->setFont(fontAwesome);

  QString category = ui->categoriesComboBox->currentText();
  if (dengueme::config("locale") != "English")
    category = getCategoryName(category);

  QString path = workspace + QDir::separator() + category + QDir::separator() + str;

  switch (validateName(path, str)) {
    case dengueme::EmptyName:
      ui->nameLineEdit->setStyleSheet("");
      ui->errorLabelName->setText("");
      ui->createButton->setDisabled(true);
      break;

    case dengueme::UnallowedChar:
      ui->createButton->setDisabled(true);
      ui->nameLineEdit->setStyleSheet("border: 1px solid red");
      ui->errorLabelName->setText(ICON_FA_TIMES_CIRCLE + tr("  The model name can contain only alphanumeric chars, hyphen (-) and / or underscore (_)."));
      break;

    case dengueme::FileExists:
      ui->nameLineEdit->setStyleSheet("border: 1px solid red");
      ui->errorLabelName->setText(ICON_FA_TIMES_CIRCLE + tr("  A model with this name already exists in the current library."));
      ui->createButton->setDisabled(true);
      break;

    case dengueme::ValidName:
      ui->nameLineEdit->setStyleSheet("");
      ui->errorLabelName->setText("");
      if (ui->categoriesComboBox->currentIndex() != 0)
        ui->createButton->setDisabled(false);
      break;
  }
}

dengueme::NameValidation  NewModelBuilder::validateName(QString path, QString name) {
  if (name.isEmpty())
    return dengueme::EmptyName;

  if (!QRegExp("^[A-Z0-9-a-z_]*$").exactMatch(name))
    return dengueme::UnallowedChar;

  if (QFile(path).exists())
    return dengueme::FileExists;

  return dengueme::ValidName;
}

void NewModelBuilder::onCreateButton() {
  this->close();

  QString category = ui->categoriesComboBox->currentText();
  if (dengueme::config("locale") != "English")
    category = getCategoryName(category);

  QString name = ui->nameLineEdit->text();
  emit accepted(name, category);
}



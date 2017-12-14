#include "iconsFontAwesome.h"
#include "dengueme.h"
#include "newmodel.h"
#include "ui_newmodel.h"
#include "newproject.h"

NewModel::NewModel(QString workspace, QString project, QWidget* parent) :
  workspace(workspace),
  project(project),
  QDialog(parent),
  ui(new Ui::NewModel) {
  ui->setupUi(this);
  this->setWindowModality(Qt::ApplicationModal);
  this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

  QFont fontAwesome;
  fontAwesome.setFamily("FontAwesome");
  fontAwesome.setPixelSize(12);
  ui->icon_project->setFont(fontAwesome);
  ui->icon_project->setText(ICON_FA_FOLDER_OPEN);

  connect(ui->cancelButtonPage1, SIGNAL(clicked()), this, SLOT(close()));
  connect(ui->cancelButtonType, SIGNAL(clicked()), this, SLOT(close()));

  connect(ui->nextButtonPage1, SIGNAL(clicked()), this, SLOT(navigateUp()));
  connect(ui->previousButton, SIGNAL(clicked()), this, SLOT(navigateBack()));

  connect(ui->createButton, SIGNAL(clicked(bool)), this, SLOT(onCreateButton()));

  connect(ui->projectslistWidget, SIGNAL(itemSelectionChanged()), SLOT(enableNext()));
  connect(ui->projectslistWidget, SIGNAL(doubleClicked(QModelIndex)), SLOT(changePage()));

  connect(ui->typeComboBox, SIGNAL(activated(int)), this, SLOT(addNamesTypePage()));
  connect(ui->modelNameslistWidget, SIGNAL(currentTextChanged(QString)), SLOT(addDescription(QString)));

  connect(ui->idLineEdit, SIGNAL(textChanged(QString)), this, SLOT(checkIdLineEdit(QString)), Qt::UniqueConnection);
  connect(ui->idLineEdit, SIGNAL(returnPressed()), this, SLOT(onCreateButton()));

  QList<QPair<QString, QStringList> > modelTypes = dengueme::model_types();

  for (int i = 0; i < modelTypes.size(); ++i)
    models.types.append(modelTypes[i].first);

  for (int i = 0; i < modelTypes.size(); ++i)
    models.names.append(modelTypes[i].second);

  ui->stackedWidget->setCurrentIndex(0);
  ui->nextButtonPage1->setDisabled(true);
  ui->createButton->setDisabled(true);
  ui->error_idLabel->setText("");
  ui->error_idLabel->setWordWrap(true);

  loadModelsInfo() ;
  addTypeTypePage();
  addNamesTypePage();
  addProjects();
}

NewModel::~NewModel() {
  delete ui;
}

void NewModel::loadModelsInfo() {
  QString modelInfo;

  for (int i = 0; i < models.types.size(); i++) {
    foreach(QString modelName, models.names.at(i)) {
      modelInfo = "";

      QString xmlModelPath = ABS_APP_DIR + "/Models/" + models.types[i] + "/" + modelName + "/" + modelName + ".xml";
      QString userModelPath = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + "/dengueme/" + models.types[i] + "/" + modelName + "/" + modelName + ".xml";

      QString id = readXmlModel(xmlModelPath, "id");
      if (id.isEmpty())
        id = readXmlModel(userModelPath, "id");

      QString name = readXmlModel(xmlModelPath, "name");
      if (name.isEmpty())
        name = readXmlModel(userModelPath, "name");

      QString category = readXmlModel(xmlModelPath, "category");
      if (category.isEmpty())
        category = readXmlModel(userModelPath, "category");
      if (dengueme::config("locale") != "English")
        category = getCategoryName(category);

      QString title = readXmlModel(xmlModelPath, "title");
      if (title.isEmpty())
        title = readXmlModel(userModelPath, "title");

      QString interpreter = readXmlModel(xmlModelPath, "interpreter");
      if (interpreter.isEmpty())
        interpreter = readXmlModel(userModelPath, "interpreter");

      QString version = readXmlModel(xmlModelPath, "version");
      if (version.isEmpty())
        version = readXmlModel(userModelPath, "version");

      QString description = readXmlModel(xmlModelPath, "description");
      if (description.isEmpty())
        description = readXmlModel(userModelPath, "description");

      modelInfo.append(name);
      modelInfo.append("$&*");
      modelInfo.append(category);
      modelInfo.append("$&*");
      modelInfo.append(title);
      modelInfo.append("$&*");
      modelInfo.append(interpreter);
      modelInfo.append("$&*");
      modelInfo.append(version);
      modelInfo.append("$&*");
      modelInfo.append(description);

      modelsInfoHash.insert(id, modelInfo);
    }
  }

}

void NewModel::onCreateButton() {
  if (!ui->createButton->isEnabled())
    return;

  this->close();
  QString data = modelsInfoHash[selectedModelID];
  QStringList info = data.split("$&*");

  QString category;
  if (dengueme::config("locale") != "English")
    category = getCategoryName(info[1]);
  else
    category = info[1];

  QString projetSelected = ui->projectslistWidget->currentItem()->text();
  QString nameIDTyped = ui->idLineEdit->text();

  emit accepted(category, selectedModelID, projetSelected, nameIDTyped);
}

void NewModel::navigateBack() {
  int indexPage = ui->stackedWidget->currentIndex();
  ui->stackedWidget->setCurrentIndex(indexPage - 1);
}

void NewModel::navigateUp() {
  int indexPage = ui->stackedWidget->currentIndex();
  ui->stackedWidget->setCurrentIndex(indexPage + 1);
  QString modelName = ui->idLineEdit->text();
  if (!modelName.isEmpty())
    checkIdLineEdit(modelName);

}

void NewModel::addTypeTypePage() {
  ui->typeComboBox->clear();
  QString itemAll = tr("All");

  if (dengueme::config("locale") != "English") {
    for (int i = 0; i < models.types.size(); i++) {
      models.types[i] = getCategoryName(models.types[i]);
    }
  }

  ui->typeComboBox->addItem(itemAll);
  ui->typeComboBox->addItems(models.types);
  ui->typeComboBox->setCurrentIndex(0);
}

void NewModel::addNamesTypePage() {
  ui->modelDescription->clear();
  ui->modelNameslistWidget->clear();

  QListWidgetItem* tme = new QListWidgetItem("TerraME");
  tme->setBackground(QBrush(QApplication::palette().color(QPalette::Background)));
  ui->modelNameslistWidget->addItem(tme);

  QListWidgetItem* r = new QListWidgetItem("R");
  r->setBackground(QBrush(QApplication::palette().color(QPalette::Background)));
  ui->modelNameslistWidget->addItem(r);

  QHashIterator<QString, QString> i(modelsInfoHash);

  while (i.hasNext()) {
    i.next();
    QString data = i.value();
    QStringList info = data.split("$&*");
    QString name = info[0];
    QString category = info[1];
    QString interpreter = info[3];

    if (ui->typeComboBox->currentText() == category) {
      if (interpreter == "TerraME") {
        ui->modelNameslistWidget->insertItem(ui->modelNameslistWidget->row(tme) + 1, name);
        name = name + "_TME";
        namesMap.insert(i.key(), name);
      } else if(interpreter == "R")  {
        ui->modelNameslistWidget->insertItem(ui->modelNameslistWidget->row(r) + 1, name);
        name = name + "_RST";
        namesMap.insert(i.key(), name);
      }
    } else if ((ui->typeComboBox->currentText() == "All") || (ui->typeComboBox->currentText() == "Todas")) {
      if (interpreter == "TerraME") {
        ui->modelNameslistWidget->insertItem(ui->modelNameslistWidget->row(tme) + 1, name);
        name = name + "_TME";
        namesMap.insert(i.key(), name);
      } else if(interpreter == "R")  {
        ui->modelNameslistWidget->insertItem(ui->modelNameslistWidget->row(r) + 1, name);
        name = name + "_RST";
        namesMap.insert(i.key(), name);
      }
    }
  }
}

void NewModel::addDescription(QString modelName) {
  ui->modelDescription->clear();

  if (modelName.isEmpty()) {
    ui->createButton->setDisabled(true);
    return;
  }
  if ((modelName == "TerraME") || (modelName == "R")) {
    ui->createButton->setDisabled(true);
    return;
  }

  int rowSelected = ui->modelNameslistWidget->currentRow();
  QList<QListWidgetItem*> rowR = ui->modelNameslistWidget->findItems("R", Qt::MatchExactly);
  int indexR = ui->modelNameslistWidget->row(rowR[0]);

  if (rowSelected < indexR) {
    modelName = modelName + "_TME";
  } else {
    modelName = modelName + "_RST";
  }

  QString key;
  QMapIterator<QString, QString> i(namesMap);
  while (i.hasNext()) {
    i.next();
    if (namesMap[i.key()] == modelName) {
      key = i.key();
      break;
    }
  }

  QString data = modelsInfoHash[key];
  QStringList info = data.split("$&*");
  QString title = info[2];
  QString interpreter = info[3];
  QString version = info[4];
  QString description = info[5];

  if (!title.isEmpty())
    ui->modelDescription->append(title);
  if(version.isEmpty())
    ui->modelDescription->append(interpreter);
  else
    ui->modelDescription->append(interpreter + " (" + version + ")\n");
  if (!description.isEmpty())
    ui->modelDescription->append(description);

  QTextCursor cursor = ui->modelDescription->textCursor();
  cursor.setPosition(0);
  ui->modelDescription->setTextCursor(cursor);

  if (!ui->idLineEdit->text().isEmpty())
    ui->createButton->setDisabled(false);
  checkIdLineEdit(ui->idLineEdit->text());

  selectedModelID = key;
}

QString NewModel::readXmlModel(QString path, QString tag) {
  QFile xmlFile(path);

  if(!xmlFile.open(QIODevice::ReadOnly))
    return {};

  QXmlStreamReader reader;
  reader.setDevice(&xmlFile);
  while(!reader.atEnd() && !reader.hasError()) {
    if (tag == "interpreter") {
      if(reader.readNext() == QXmlStreamReader::StartElement && reader.name() == "sourcecode" && reader.attributes().hasAttribute("interpreter")) {
        return  reader.attributes().value("interpreter").toString();
      }
    } else if (tag == "version") {
      if(reader.readNext() == QXmlStreamReader::StartElement && reader.name() == "sourcecode" && reader.attributes().hasAttribute("version")) {
        return  reader.attributes().value("version").toString();
      }
    } else {
      if(reader.readNext() == QXmlStreamReader::StartElement && reader.name() == tag) {
        return reader.readElementText();
      }
    }
  }
  return {};
}

void NewModel::enableNext() {
  ui->nextButtonPage1->setDisabled(false);
  ui->project_name->setText(ui->projectslistWidget->currentItem()->text());
}

void NewModel::changePage() {
  ui->stackedWidget->setCurrentIndex(1);
}

void NewModel::addProjects() {
  ui->projectslistWidget->clear();
  QDir dir(workspace);
  foreach(QFileInfo x, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
    QListWidgetItem* item = new QListWidgetItem(x.fileName());
    ui->projectslistWidget->addItem(item);
    if (x.fileName() == project)
      ui->projectslistWidget->setCurrentItem(item);
  }
}

QString NewModel::getCategoryName(QString category) {
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

void NewModel::checkIdLineEdit(const QString& str) {
  QFont fontAwesome;
  fontAwesome.setFamily("FontAwesome");
  fontAwesome.setPixelSize(12);
  ui->error_idLabel->setFont(fontAwesome);

  QString projct = ui->projectslistWidget->currentItem()->text();
  QString path = workspace + QDir::separator() + projct;

  switch (dengueme::validateName(path, str, ".xml")) {
    case dengueme::EmptyName:
      if (state != dengueme::EmptyName) {
        state = dengueme::EmptyName;
        ui->idLineEdit->setStyleSheet("");
        ui->error_idLabel->setText("");
        ui->createButton->setDisabled(true);
      }
      break;

    case dengueme::UnallowedChar:
      state = dengueme::UnallowedChar;
      ui->createButton->setDisabled(true);
      ui->idLineEdit->setStyleSheet("border: 1px solid red");
      ui->error_idLabel->setText(ICON_FA_TIMES_CIRCLE + tr("  The model name can contain only alphanumeric chars, hyphen (-) and / or underscore (_)."));
      break;

    case dengueme::FileExists:
      state = dengueme::FileExists;
      if (!QFile(path + QDir::separator() + str + ".xml").exists()) {
        state = dengueme::ValidName;
        if(ui->modelNameslistWidget->currentIndex().row() != -1 && ui->modelNameslistWidget->currentItem()->text() != "TerraME" && ui->modelNameslistWidget->currentItem()->text() != "R")
          ui->createButton->setDisabled(false);
        ui->idLineEdit->setStyleSheet("");
        ui->error_idLabel->setText("");
      } else {
        ui->idLineEdit->setStyleSheet("border: 1px solid red");
        ui->error_idLabel->setText(ICON_FA_TIMES_CIRCLE + tr("  A model with this name already exists in current project."));
        ui->createButton->setDisabled(true);
      }
      break;

    case dengueme::ValidName:
      if (state != dengueme::ValidName) {
        state = dengueme::ValidName;
        if(ui->modelNameslistWidget->currentIndex().row() != -1 && ui->modelNameslistWidget->currentItem()->text() != "TerraME" && ui->modelNameslistWidget->currentItem()->text() != "R")
          ui->createButton->setDisabled(false);
        ui->idLineEdit->setStyleSheet("");
        ui->error_idLabel->setText("");
      }
      break;
  }
}

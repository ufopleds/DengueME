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
  this->setWindowFlags(Qt::Tool | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint);

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
  connect(ui->idLineEdit, SIGNAL(returnPressed()), ui->createButton, SIGNAL(clicked()));

  QList<QPair<QString, QStringList> > modelTypes = dengueme::model_types();

  for (int i = 0; i < modelTypes.size(); ++i)
    models.types.append(modelTypes[i].first);

  for (int i = 0; i < modelTypes.size(); ++i)
    models.names.append(modelTypes[i].second);

  ui->stackedWidget->setCurrentIndex(0);
  ui->nextButtonPage1->setDisabled(true);
  ui->createButton->setDisabled(true);
  ui->error_idLabel->setText("");

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
  this->close();
  QString data = modelsInfoHash[selectedModelID];
  QStringList info = data.split("$&*");
  QString category = info[1];

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
}

void NewModel::addTypeTypePage() {
  ui->typeComboBox->clear();
  ui->typeComboBox->addItem("All");
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
    } else if (ui->typeComboBox->currentText() == "All") {
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
      ui->error_idLabel->setText(ICON_FA_TIMES_CIRCLE + tr("  The model name can contain only alphanumeric chars, hyphen (-) and / or underscore (_)"));
      break;

    case dengueme::FileExists:
      state = dengueme::FileExists;
      ui->idLineEdit->setStyleSheet("border: 1px solid red");
      ui->error_idLabel->setText(ICON_FA_TIMES_CIRCLE + tr("  A model with this name already exists in current project."));
      ui->createButton->setDisabled(true);
      break;

    case dengueme::ValidName:
      if (state != dengueme::ValidName) {
        state = dengueme::ValidName;
        if(ui->modelNameslistWidget->currentIndex().row() != -1)
          ui->createButton->setDisabled(false);
        ui->idLineEdit->setStyleSheet("");
        ui->error_idLabel->setText("");
      }
      break;
  }
}

/* Category Page and Name Page */
/* New Model - Model Builder */

CategoryPage::CategoryPage(QString workspace, QString project)
  : workspace(workspace),
    project(project) {
  setTitle(tr("Category"));
  setSubTitle(tr("Select the category in which the model will be created."));
  setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/error.png"));

  projects = new QListWidget;

  loadWorkspace();

  QVBoxLayout* layout = new QVBoxLayout;
  layout->setMargin(8);

  layout->addWidget(projects);
  setLayout(layout);

  connect(projects, SIGNAL(itemSelectionChanged()), SLOT(itemChanged()));
  this->setButtonText(QWizard::NextButton,  tr("Next"));
  this->setButtonText(QWizard::CancelButton,  tr("Cancel"));
  this->setButtonText(QWizard::FinishButton,  tr("Create"));
}

bool CategoryPage::isComplete() const {
  if (!projects->selectedItems().isEmpty()) {
    wizard()->setProperty("project", projects->selectedItems().first()->text());
    return true;
  } else
    return false;
}

void CategoryPage::itemChanged() {
  emit completeChanged();
}

void CategoryPage::newProject() {
  newproject->hide();
  projects->hide();

  NewProject* n = new NewProject(this);
  if (n->exec()) {
    QString name = n->getProjectName();
    QDir dir(workspace + QDir::separator() + name);
    if (dir.mkpath(dir.absolutePath())) {
      loadWorkspace();
      QList<QListWidgetItem*> items = projects->findItems(name, Qt::MatchCaseSensitive);
      if (!items.isEmpty()) items.at(0)->setSelected(true);
    } else {
      QMessageBox::critical(this, tr("Error"), tr("Failed to create project folder."));
    }
  }
  newproject->show();
  projects->show();
}

void CategoryPage::loadWorkspace() {
  projects->clear();
  QDir dir(workspace);
  foreach(QFileInfo x, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
    QListWidgetItem* item = new QListWidgetItem(x.fileName());
    item->setSizeHint(QSize(-1, 20));
    projects->addItem(item);
    if (x.fileName() == project)
      item->setSelected(true);
  }

  if (project.isEmpty() && projects->count() > 0) projects->itemAt(0, 0)->setSelected(true);
}

NamePage::NamePage(QString workspace)
  : subtitle(tr("Please specify an unique identifier for the new model.")),
    workspace(workspace),
    state(dengueme::EmptyName) {

  setTitle(tr("Specify an ID:"));
  setSubTitle(subtitle);
  setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/error.png"));

  modelName = new QLabel(tr("&Id:"));
  projectLineEdit = new QLineEdit;
  modelName->setBuddy(projectLineEdit);

  connect(projectLineEdit, SIGNAL(textChanged(QString)), this, SLOT(validateProject(QString)));

  registerField("name*", projectLineEdit);

  QGridLayout* layout = new QGridLayout;
  layout->addWidget(modelName, 0, 0);
  layout->addWidget(projectLineEdit, 0, 1);
  setLayout(layout);
  projectLineEdit->setFocus();

  this->setButtonText(QWizard::NextButton,  tr("Next"));
  this->setButtonText(QWizard::CancelButton,  tr("Cancel"));
  this->setButtonText(QWizard::FinishButton,  tr("Create"));

}

void NamePage::validateProject(QString name) {
  QString path = workspace + QDir::separator() + wizard()->property("project").toString();
  switch (dengueme::validateName(path, name, ".xml")) {
    case dengueme::EmptyName:
      if (state != dengueme::EmptyName) {
        setSubTitle(subtitle);
        state = dengueme::EmptyName;
        setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/error.png"));
      }
      break;

    case dengueme::UnallowedChar:
      projectLineEdit->setText(dengueme::purgeName(name));
      QToolTip::showText(projectLineEdit->mapToGlobal(QPoint(0, projectLineEdit->height())),
                         tr("The file name can contain only\nalphanumeric chars, hyphen (-),"
                            " \nunderscore (_) and dot (.)."));
      break;

    case dengueme::FileExists:
      if (state != dengueme::FileExists) {
        state = dengueme::FileExists;
        setSubTitle(tr("A file with that name already exists."));
        setPixmap(QWizard::LogoPixmap, QPixmap(":/Resources/error.png"));
      }
      break;

    case dengueme::ValidName:
      if (state != dengueme::ValidName) {
        setSubTitle(subtitle);
        state = dengueme::ValidName;
        setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/ok.png"));
      }
      break;
  }
}

void NamePage::setWorkspace(QString path) {
  workspace = path;
}

bool NamePage::isComplete() const {
  return state == dengueme::ValidName;
}


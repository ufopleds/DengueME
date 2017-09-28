#include "dengueme.h"
#include "modelview.h"
#include "ui_modelview.h"
#include "builder/modeldocument.h"

struct FileInfo : QWidget {
  QLineEdit* path;
  QToolButton* remove;
  QString oldPath;
  FileInfo() {
    resize(0, 40);
    QHBoxLayout* layout = new QHBoxLayout(this);
    path = new QLineEdit;
    path->setFrame(false);
    path->setStyleSheet("background:transparent;");
    layout->addWidget(path);

    remove = new QToolButton;
    remove->setAutoRaise(true);
    remove->setIcon(QIcon(":/Resources/delete.png"));
    layout->addWidget(remove);
  }
};

ModelView::ModelView(QWidget* parent) :
  QFrame(parent),
  ui(new Ui::ModelView) {
  ui->setupUi(this);
  setBackgroundRole(QPalette::Base);

  connect(ui->buttonAdd, SIGNAL(clicked()), SLOT(addFile()));
  connect(ui->interpreter, SIGNAL(currentIndexChanged(int)), SLOT(onInterpreterChanged(int)));
  connect(ui->add, SIGNAL(clicked()), SLOT(add()));
  connect(ui->del, SIGNAL(clicked()), SLOT(del()));

  ui->userIdText->setEnabled(false);
  ui->categoryCombo->setEnabled(false);

  ui->modelInfo->setText(dengueme::getProjectType());
  ui->modelInfo->setVisible(false);
  ui->modelType->setVisible(false);
}


ModelView::~ModelView() {
  delete ui;
}
void ModelView::add() {

  QListWidgetItem* label = new QListWidgetItem ("New Author");

  label->setFlags(label->flags () | Qt::ItemIsEditable);
  ui->authorsList->addItem(label);
}
void ModelView::del() {
  for(int i = 0; i < ui->authorsList->count(); i++) {
    if(ui->authorsList->item(i)->isSelected())
      ui->authorsList->takeItem(i);
  }
}
void ModelView::setScriptDir(QString dir) {
  QDir().mkpath(dir);
  _scriptDir = dir;
}

QString ModelView::scriptDir() {
  return _scriptDir;
}

QDomDocument ModelView::getXml() {
  QDomDocument doc;
  QDomElement root = doc.createElement("model");

  QDomElement id = doc.createElement("id");
  id.appendChild(doc.createTextNode(ui->userIdText->text()));
  QDomElement userid = doc.createElement("userid");
  userid.appendChild(doc.createTextNode(ui->userIdText->text()));
  QDomElement name = doc.createElement("name");
  name.appendChild(doc.createTextNode(ui->nameText->text()));
  QDomElement category = doc.createElement("category");
  category.appendChild(doc.createTextNode(scriptDir().contains("transmission") ? "transmission" : "vector" ));
  QDomElement title = doc.createElement("title");
  title.appendChild(doc.createTextNode(ui->titleText->text()));
  QDomElement type = doc.createElement("type");
  type.appendChild(doc.createTextNode(ui->typeCombo->currentText()));

  QDomElement authorsRoot = doc.createElement("authors");
  for (int i = 0; i < ui->authorsList->count(); ++i) {

    QDomElement author = doc.createElement("author");
    author.appendChild(doc.createTextNode(ui->authorsList->item(i)->text()));
    authorsRoot.appendChild(author);
  }

  QDomElement description = doc.createElement("description");
  description.appendChild(doc.createTextNode(ui->descriptionText->toPlainText()));

  root.appendChild(id);
  root.appendChild(userid);
  root.appendChild(name);
  root.appendChild(category);
  root.appendChild(type);
  root.appendChild(title);
  root.appendChild(authorsRoot);
  root.appendChild(description);

  QDomElement root2 = doc.createElement("sourcecode");
  root2.setAttribute("lang", ui->interpreter->currentText() == "TerraME" ? "TerraML" : "R");
  root2.setAttribute("interpreter", ui->interpreter->currentText());
  root2.setAttribute("version", ui->versionCombo->currentText());

  QDomElement modelVersion = doc.createElement("version");
  modelVersion.appendChild(doc.createTextNode("1.0"));
  root2.appendChild(modelVersion);
  QDomElement fileRoot = doc.createElement("files");
  for (int i = 0; i < ui->list->count(); ++i) {

    FileInfo* fi = dynamic_cast<FileInfo*>(ui->list->itemWidget(ui->list->item(i)));
    if (fi == NULL) continue;

    QDomElement file = doc.createElement("file");
    file.appendChild(doc.createTextNode(fi->path->text()));
    fileRoot.appendChild(file);
  }

  root2.appendChild(fileRoot);
  QDomElement main = doc.createElement("main");
  main.appendChild(doc.createTextNode(ui->mainFile->currentText()));
  root2.appendChild(main);
  QDomElement dependencies = doc.createElement("dependencies");
  dependencies.appendChild(doc.createTextNode("dependencias"));
  root2.appendChild(dependencies);

  ui->userIdText->setEnabled(false);
  ui->categoryCombo->setEnabled(false);

  root.appendChild(root2);
  doc.appendChild(root);
  return doc;
}

void ModelView::setXml(QDomElement node) {
  ui->categoryCombo->setCurrentIndex(ui->categoryCombo->findText(scriptDir().contains("transmission") ? "transmission" : "vector" ));
  ui->userIdText->setEnabled(false);
  ui->userIdText->setText(scriptDir().remove(0, scriptDir().lastIndexOf('/') + 1).replace("_scripts", ""));

  ui->list->clear();
  ui->mainFile->clear();

  ui->titleText->setText(node.firstChildElement("title").text());
  ui->nameText->setText(node.firstChildElement("name").text());

  ui->typeCombo->setCurrentIndex(ui->typeCombo->findText(node.firstChildElement("type").text()));
  ui->descriptionText->setText(node.firstChildElement("description").text());
  QDomElement authors = node.firstChildElement("authors");
  ui->authorsList->clear();
  for (QDomElement author = authors.firstChildElement("author"); !author.isNull(); author = author.nextSiblingElement("author")) {
    QListWidgetItem* item = new QListWidgetItem(author.text());
    item->setFlags(item->flags () | Qt::ItemIsEditable);
    ui->authorsList->addItem(item);
  }
  QDomElement source = node.firstChildElement("sourcecode");
  QDomElement files = source.firstChildElement("files");

  ui->mainFile->setCurrentIndex(ui->mainFile->findText(source.firstChildElement("main").text()));
  ui->interpreter->setCurrentIndex(ui->interpreter->findText(source.attribute("interpreter")));
  ui->versionCombo->setCurrentIndex(ui->versionCombo->findText(source.attribute("version")));

  for (QDomElement file = files.firstChildElement("file");
       !file.isNull(); file = file.nextSiblingElement("file")) {
    addItem(file.text());
  }

  ui->userIdText->setEnabled(false);
  ui->categoryCombo->setEnabled(false);

  ui->modelInfo->setVisible(false);
  ui->modelType->setVisible(false);
  ui->modelInfo->setText(node.firstChildElement("category").text());
}

ModelView::Interpreter ModelView::interpreter() {
  if (ui->interpreter->currentIndex() == 1)
    return RScript;
  else
    return TerraME;
}

QStringList ModelView::scripts() {
  QStringList ret;
  for (int i = 0; i < ui->mainFile->count(); ++i)
    ret.append(_scriptDir + '/' + ui->mainFile->itemText(i));
  return ret;
}

QString ModelView::mainScript() {
  return ui->mainFile->currentText();
}

void ModelView::addItem(QString fileName) {
  QListWidgetItem* item = new QListWidgetItem;
  FileInfo* fi = new FileInfo;
  fi->path->setText(fileName.replace("\\", "/"));
  fi->oldPath = fileName.replace("\\", "/");
  item->setSizeHint(fi->size());

  ui->list->addItem(item);
  ui->list->setItemWidget(item, fi);

  map[fi->remove] = item;
  map[fi->path] = item;
  connect(fi->remove, SIGNAL(clicked()), SLOT(removeFile()));
  connect(fi->path, SIGNAL(editingFinished()), SLOT(renameFile()));

  if (!QFileInfo(_scriptDir + "/" + fileName).exists()) {
    fi->path->setDisabled(true);
    fi->setToolTip(tr("File not found."));
  } else {
    ui->mainFile->addItem(fileName);
  }
  ui->modelType->setText (ui->mainFile->currentText().remove(ui->mainFile->currentText().indexOf('.'), 4));

}

void ModelView::addFile() {
  if (_scriptDir.isEmpty()) return;

  QString path(QFileDialog::getOpenFileName(0, "Model", "", "Model script (*.lua *.r)"));

  if (path.isEmpty()) return;

  QString fileName = QFileInfo(path).fileName();
  QString dest = _scriptDir + "/" + fileName;
  if (ui->mainFile->findText(fileName, Qt::MatchFixedString) != -1) {
    QMessageBox::critical(this, tr("Error"), tr("A file with that name already exists."));
    return;
  }

  if (!dengueme::remove(dest) || !dengueme::copy(path, dest)) {
    QMessageBox::critical(this, tr("Error"), tr("Failed to copy file."));
    return;
  }

  addItem(fileName);
}

void ModelView::removeFile() {
  if (_scriptDir.isEmpty()) return;

  QObject* wid = QObject::sender();
  if (!map.contains(wid)) return;

  FileInfo* fi = dynamic_cast<FileInfo*>(ui->list->itemWidget(map.value(wid)));
  if (fi == NULL) return;

  ui->mainFile->removeItem(ui->mainFile->findText(fi->path->text()));

  QFile(_scriptDir + "/" + fi->path->text()).remove();

  delete ui->list->takeItem(ui->list->row(map.value(wid)));
}

void ModelView::renameFile() {
  if (_scriptDir.isEmpty()) return;

  QObject* wid = QObject::sender();
  if (!map.contains(wid)) return;

  FileInfo* fi = dynamic_cast<FileInfo*>(ui->list->itemWidget(map.value(wid)));
  if (fi == NULL) return;

  QString from = _scriptDir + "/" + fi->oldPath;
  QString to = _scriptDir + "/" + fi->path->text();

  QDir dir;
  if (!dir.mkpath(QFileInfo(to).path()))
    fi->path->setText(fi->oldPath);

  if (ui->mainFile->findText(fi->path->text() + "/", Qt::MatchStartsWith | Qt::MatchFixedString) == -1
      && ui->mainFile->findText(fi->path->text(), Qt::MatchFixedString) == -1
      && !dengueme::remove(to)) {
    fi->path->setText(fi->oldPath);
    return;
  }

  if (!QFile::rename(from, to)) {
    fi->path->setText(fi->oldPath);
    return;
  }

  ui->mainFile->setItemText(ui->mainFile->findText(fi->oldPath), fi->path->text());
  fi->oldPath = fi->path->text();
}

void ModelView::onInterpreterChanged(int r) {
  if (r == 1)
    emit interpreterChanged(RScript);
  else
    emit interpreterChanged(TerraME);
}

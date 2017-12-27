#include "openmodel.h"
#include "ui_openmodel.h"
#include "builder/modelbuilder.h"
#include "ui_modelbuilder.h"
#include "builder/builderdirmodel.h"
#include "dengueme.h"

OpenModel::OpenModel(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::OpenModel) {
  this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

  QDir dir(QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + "/dengueme");
  dir.mkpath("vector");
  dir.mkpath("transmission");

  ui->setupUi(this);
  BuilderDirModel* model = new BuilderDirModel;

  connect(ui->ok, SIGNAL(clicked()), SLOT(setIndex()));
  connect(ui->cancel, SIGNAL(clicked()), SLOT(close()));
  ui->treeView->setDirModel(model);
  ui->ok->setEnabled(false);
  ui->treeView->setWorkspace(QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + "/dengueme");
  connect(model, SIGNAL(updated()), ui->treeView, SLOT(expandAll()));

  connect(ui->treeView, SIGNAL(doubleClicked(QModelIndex)), SLOT(setIndex()));
  connect(ui->treeView, SIGNAL(clicked(QModelIndex)), SLOT(selectionChanged(QModelIndex)));
}

void OpenModel::selectionChanged(const QModelIndex& current) {
  ui->ok->setEnabled(false);
  if (!current.isValid()) return;

  QFileInfo info = ui->treeView->fileInfo(current);
  if (info.dir().canonicalPath() != QDir( QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + "/dengueme").canonicalPath()) {
    ui->ok->setEnabled(true);
  }
}

OpenModel::~OpenModel() {
  delete ui;
}

void OpenModel::setIndex() {
  this->index = ui->treeView->currentIndex();
  emit accept();
}
QString OpenModel::getFilePath() {
  return  ui->treeView->filePath(this->index);
}

QString OpenModel::getFileName() {
  return  ui->treeView->fileInfo(this->index).fileName();
}





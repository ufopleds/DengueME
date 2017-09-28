#include <QMessageBox>
#include <QAction>
#include <QDir>

#include "rename.h"
#include "workspaceview.h"

WorkspaceView::WorkspaceView(QWidget* parent)
  : QTreeView(parent),
    model(NULL) { }

WorkspaceView::~WorkspaceView() { }

void WorkspaceView::setWorkspace(QString workspace) {
  model->setDir(workspace);
}

QString WorkspaceView::filePath(QModelIndex index) {
  return model->filePath(index);
}

QFileInfo WorkspaceView::fileInfo(QModelIndex index) {
  return model->fileInfo(index);
}

QModelIndex WorkspaceView::indexFromPath(QString path) {
  return model->indexFromPath(path);
}

bool WorkspaceView::askDelete(QModelIndex index) {
  if (!index.isValid()) return false;

  QFileInfo fileinfo = fileInfo(index);

  int opt = -1;

  if (fileinfo.isDir()) {
    opt = QMessageBox::question(this, tr("Delete folder"),
                                tr("Are you sure you want to delete the project '") + fileinfo.baseName() + tr("' and all its content? This will delete all model related files from your disk <b>permanently</b>"),
                                QMessageBox::Yes | QMessageBox::No);
  } else if (fileinfo.isFile() ) {
    opt = QMessageBox::question(this, tr("Delete model"),
                                tr("Are you sure you want to delete the model '") + fileinfo.baseName() + tr( "? This will delete all model related files from your disk <b>permanently</b>"),
                                QMessageBox::Yes | QMessageBox::No);
  }    else
    return false;

  if (opt != QMessageBox::Yes)
    return false;
  QString path = fileinfo.absoluteFilePath();
  path.replace(".xml", "_scripts");

  model->remove(index);

  model->removeDir(path);

  path = fileinfo.absoluteFilePath();
  path.replace(".xml", "_input.lua");

  model->remove_recursively(path);

  return true;
}

QString WorkspaceView::askRename(QModelIndex index) {
  QFileInfo info = fileInfo(index);
  RenameModel* n = new RenameModel(info.path(), info.baseName(), info.isDir() ? "" : ".xml", this);
  if (n->exec() == QDialog::Accepted) {
    QString newname(n->getModelName());
    if (info.isDir()) {
      QString oldpath = info.filePath();
      QString newpath = info.path() + QDir::separator() + newname;
      if (QFile::rename(oldpath, newpath)) {
        n->close();
        return newpath;
      }
    } else {
      n->close();
      {
        QString oldpath = info.filePath();
        QString newpath = info.path() + '/' + newname + ".xml";
        if (!QFile::rename(oldpath, newpath)) {

          return "false";
        }
      }
      {
        QString oldpath = info.path() + '/' + info.baseName() + "_scripts";
        QString newpath = info.path() + '/' + newname + "_scripts";
        if (!QFile::rename(oldpath, newpath))
          return "false";
      }
      return newname;
    }
    QMessageBox::critical(this, tr("Error"), tr("Error trying to rename file/folder."));
  }
  n->close();
  return "false";
}

void WorkspaceView::setDirModel(DirModel* model) {
  if (this->model) return;

  this->model = model;
  connect(model, SIGNAL(updated()), SLOT(onModelUpdated()));
  connect(model, SIGNAL(aboutToUpdate()), SLOT(onModelToUpdate()));
  QTreeView::setModel(model);
}

void WorkspaceView::onModelUpdated() {
  setCurrentIndex(indexFromPath(selected));
  foreach(QString path, expanded) {
    expand(indexFromPath(path));
  }
  expanded.clear();
  selected = "";
}

void WorkspaceView::onModelToUpdate() {
  expanded.clear();
  selected = filePath(currentIndex());
  for (int i = 0; i < model->rowCount(); ++i) {
    QModelIndex index = model->index(i, 0);
    if (isExpanded(index)) {
      expanded.append(filePath(index));
    }
  }
}


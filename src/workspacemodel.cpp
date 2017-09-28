#include <QFileInfo>

#include "workspacemodel.h"

WorkspaceModel::WorkspaceModel(QObject* parent)
  : DirModel(parent) { }

QModelIndex WorkspaceModel::addRootItem(QString path) {
  QFileInfo info(path);
  QStandardItem* item = new QStandardItem(icon.icon(info), info.fileName());
  item->setSizeHint(QSize(-1, 20));

  appendRow(item);

  return indexFromItem(item);
}

QModelIndex WorkspaceModel::addItem(QModelIndex parent, QString path) {
  QFileInfo info(path);
  QStandardItem* name = new QStandardItem(icon.icon(info), info.baseName());

  name->setSizeHint(QSize(-1, 20));

  itemFromIndex(parent)->appendRow(name);

  return indexFromItem(name);
}

bool WorkspaceModel::acceptFile(QString name) {
  QFileInfo info(name);
  if (!info.isFile()) return false;

  return info.suffix().compare("xml", Qt::CaseInsensitive) == 0;
}


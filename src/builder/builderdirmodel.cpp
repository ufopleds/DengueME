#include <QPalette>
#include <QApplication>
#include <QDirIterator>
#include "builderdirmodel.h"

BuilderDirModel::BuilderDirModel(QObject* parent)
  : DirModel(parent)
{ }

QModelIndex BuilderDirModel::addRootItem(QString path) {
  QStandardItem* item = new QStandardItem(QFileInfo(path).fileName());
  item->setSizeHint(QSize(-1, 20));
  item->setBackground(QBrush(QApplication::palette().color(QPalette::Background)));
  item->setSelectable(false);
  appendRow(item);
  return indexFromItem(item);
}

QModelIndex BuilderDirModel::addItem(QModelIndex parent, QString path) {
  QDir subdir(path);
  QStandardItem* name = new QStandardItem(subdir.dirName());

  name->setSizeHint(QSize(-1, 20));

  itemFromIndex(parent)->appendRow(name);

  QModelIndex index = indexFromItem(name);

  return index;
}

bool BuilderDirModel::acceptFile(QString name) {
  QFileInfo info(name);
  if (!info.isDir()) return false;

  QDir subdir(name);

  return subdir.exists(subdir.dirName() + ".xml");
}


#ifndef BUILDERMODEL_H
#define BUILDERMODEL_H

#include <QFileInfo>
#include <QStandardItemModel>
#include <QFileSystemWatcher>
#include <QMap>
#include "../dirmodel.h"

class BuilderDirModel : public DirModel {
  Q_OBJECT
 public:
  BuilderDirModel(QObject* parent = 0);

 private:
  virtual QModelIndex addRootItem(QString path);
  virtual QModelIndex addItem(QModelIndex parent, QString path);
  virtual bool acceptFile(QString name);
};

#endif // BUILDERMODEL_H


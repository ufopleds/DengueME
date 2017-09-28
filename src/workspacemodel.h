#ifndef WORKSPACEMODEL_H
#define WORKSPACEMODEL_H

#include <QFileIconProvider>

#include "dirmodel.h"

class WorkspaceModel : public DirModel {
 public:
  WorkspaceModel(QObject* parent = 0);
 protected:
  virtual QModelIndex addRootItem(QString path);
  virtual QModelIndex addItem(QModelIndex parent, QString path);
  virtual bool acceptFile(QString name);

 private:
  QFileIconProvider icon;
};

#endif // WORKSPACEMODEL_H

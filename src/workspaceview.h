#ifndef WORKSPACEVIEW_H
#define WORKSPACEVIEW_H

#include <QTreeView>
#include <QFileInfo>

#include "dirmodel.h"

class WorkspaceView : public QTreeView {
  Q_OBJECT
 public:
  WorkspaceView(QWidget* parent = 0);
  ~WorkspaceView();
  void setWorkspace(QString workspace);
  QString filePath(QModelIndex index);
  QFileInfo fileInfo(QModelIndex index);
  QModelIndex indexFromPath(QString path);
  bool askDelete(QModelIndex index);
  QString askRename(QModelIndex index);
  void setDirModel(DirModel* model);

 private:
  DirModel* model;
  QList<QString> expanded;
  QString selected;

 public slots:
  void onModelUpdated();
  void onModelToUpdate();

 signals:
  void workspaceReloaded();
  void workspaceToReload();
};

#endif // WORKSPACEVIEW_H


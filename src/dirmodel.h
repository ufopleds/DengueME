#ifndef DIRMODEL_H
#define DIRMODEL_H

#include <QFileInfo>
#include <QStandardItemModel>
#include <QFileSystemWatcher>
#include <QMap>

class DirModel : public QStandardItemModel {
  Q_OBJECT
 public:
  DirModel(QObject* parent = 0);
  ~DirModel();

  void setDir(QString dir);
  QString filePath(QModelIndex index);
  QFileInfo fileInfo(QModelIndex index);
  bool remove(QModelIndex index);
  QModelIndex indexFromPath(QString path);
  bool removeDir(QString path);
  bool remove_recursively(QString path);


 protected:
  virtual QModelIndex addRootItem(QString path) = 0;
  virtual QModelIndex addItem(QModelIndex parent, QString path) = 0;
  virtual bool acceptFile(QString name) = 0;

 private:
  QString dir;
  QMap<QString, QPersistentModelIndex> pathmap;
  QFileSystemWatcher* fsw;
  void resetFsw();


 private slots:
  void updateDir();

 signals:
  void aboutToUpdate();
  void updated();
};

#endif // DIRMODEL_H

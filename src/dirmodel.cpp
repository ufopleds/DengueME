#include "dirmodel.h"
#include <QPalette>
#include <QApplication>
#include <QDirIterator>

/*The dir models is used to assist the Tree View
Controlls the model directories and folders.*/

DirModel::DirModel(QObject* parent)
  : QStandardItemModel(0, 1, parent),
    fsw(NULL) {
  resetFsw();
}

DirModel::~DirModel()
{ }

void DirModel::setDir(QString dir) {
  if (dir.isEmpty()) return;
  this->dir = dir;
  updateDir();

}

QString DirModel::filePath(QModelIndex index) {
  return pathmap.key(index);
}

QFileInfo DirModel::fileInfo(QModelIndex index) {
  return QFileInfo(filePath(index));
}

QModelIndex DirModel::indexFromPath(QString path) {
  return pathmap.value(QFileInfo(path).canonicalFilePath());
}

void DirModel::resetFsw() {
  delete fsw;
  fsw = new QFileSystemWatcher;
  connect(fsw, SIGNAL(directoryChanged(QString)), SLOT(updateDir()));
  connect(fsw, SIGNAL(fileChanged(QString)), SLOT(updateDir()));
}

void DirModel::updateDir() {
  emit aboutToUpdate();
  clear();
  pathmap.clear();
  resetFsw();
  fsw->addPath(dir);

  QDirIterator itr(dir, QDir::NoDotAndDotDot | QDir::Dirs);
  while (itr.hasNext()) {
    QString sub = itr.next();
    fsw->addPath(sub);
    QModelIndex root = addRootItem(sub);
    if (root.isValid()) {
      pathmap.insert(QFileInfo(sub).canonicalFilePath(), QPersistentModelIndex(root));

      QDirIterator subitr(sub, QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

      while (subitr.hasNext()) {
        QString path = subitr.next();

        fsw->addPath(path);

        if (acceptFile(path)) {
          QModelIndex index = addItem(root, path);
          if (index.isValid())
            pathmap.insert(QFileInfo(path).canonicalFilePath(), QPersistentModelIndex(index));
        }
      }
    }
  }

  sort(0);
  emit updated();
}

bool DirModel::remove_recursively(QString path) {
  QFileInfo fileinfo(path);
  if (fileinfo.isDir()) {
    QDir dir(fileinfo.filePath());
    QFileInfoList entries = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden | QDir::AllDirs | QDir::Files, QDir::NoSort);
    foreach (QFileInfo entryInfo, entries) {
      remove_recursively(entryInfo.filePath());
    }
    fsw->removePath(dir.path());  // windows issue: https://bugreports.qt.io/browse/QTBUG-2331
    return dir.rmdir(dir.path());
  } else if (fileinfo.isFile()) {
    fsw->removePath(fileinfo.filePath());  // windows issue: https://bugreports.qt.io/browse/QTBUG-2331
    return QFile::remove(fileinfo.filePath());
  }
  return false;
}

bool DirModel::removeDir(QString dirName) {
  bool result = true;
  QDir dir(dirName);

  if (dir.exists()) {
    Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
      if (info.isDir()) {

        result = removeDir(info.absoluteFilePath());
        fsw->removePath(dir.path());  // windows issue: https://bugreports.qt.io/browse/QTBUG-2331
      } else {
        result = QFile::remove(info.absoluteFilePath());
        fsw->removePath(dir.path());  // windows issue: https://bugreports.qt.io/browse/QTBUG-2331
      }

      if (!result) {

        return result;
      }
    }
    fsw->removePath(dir.path());  // windows issue: https://bugreports.qt.io/browse/QTBUG-2331
    result = dir.rmdir(dirName);
  }

  return result;
}
bool DirModel::remove(QModelIndex index) {

  if (!index.isValid()) return false;

  return remove_recursively(filePath(index));
}


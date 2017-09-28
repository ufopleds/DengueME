#include "downloadmanager.h"
#include <QFileInfo>
#include <QDateTime>

DownloadManager::DownloadManager(QObject* parent) :
  QObject(parent)
  , _pHTTP(NULL) {
}

void DownloadManager::download(QUrl url) {
  _pHTTP = new DownloadHTTP(this);
  connect(_pHTTP, SIGNAL(addLine(QString)), this, SLOT(localAddLine(QString)));
  connect(_pHTTP, SIGNAL(progress(int)), this, SLOT(localProgress(int)));
  connect(_pHTTP, SIGNAL(downloadComplete()), this, SLOT(localDownloadComplete()));
  connect(_pHTTP, SIGNAL(downloadError()), this, SLOT(localDownloadError()));
  _pHTTP->download(url);

}

void DownloadManager::localAddLine(QString qsLine) {
  emit addLine(qsLine);
}


void DownloadManager::localProgress(int nPercentage) {
  emit progress(nPercentage);
}

void DownloadManager::localDownloadError() {

  emit downloadError();
}

void DownloadManager::localDownloadComplete() {

  emit downloadComplete();
}

#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QtGlobal>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QTimer>

#include "downloadhttp.h"

class DownloadManager : public QObject {
  Q_OBJECT

 public:
  explicit DownloadManager(QObject* parent = 0);

 signals:
  void addLine(QString qsLine);
  void progress(int nPercentage);
  void downloadComplete();
  void downloadError();

 public slots:
  void download(QUrl url);


 private slots:
  void localAddLine(QString qsLine);
  void localProgress(int nPercentage);
  void localDownloadComplete();
  void localDownloadError();

 private:
  QUrl _URL;
  DownloadHTTP* _pHTTP;

};

#endif // DOWNLOADMANAGER_H

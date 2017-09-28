#ifndef DOWNLOADHTTP_H
#define DOWNLOADHTTP_H

#include <QtGlobal>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QTimer>

class DownloadHTTP : public QObject {
  Q_OBJECT

 public:
  explicit DownloadHTTP(QObject* parent = 0);
  virtual ~DownloadHTTP();

 signals:
  void addLine(QString qsLine);
  void downloadComplete(); 
  void progress(int nPercentage);

 public slots:
  void download(QUrl url);

 private slots:
  void download();
  void finishedHead();
  void finished();
  void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);



 private:
  QUrl _URL;
  QString _qsFileName;
  QNetworkAccessManager* _pManager;
  QNetworkRequest _CurrentRequest;
  QNetworkReply* _pCurrentReply;
  QFile* _pFile;
  int _nDownloadTotal;
  bool _bAcceptRanges;
  int _nDownloadSize;
  int _nDownloadSizeAtPause;
  QTimer _Timer;
};





#endif // DOWNLOADHTTP_H

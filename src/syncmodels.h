#ifndef SYNCMODELS_H
#define SYNCMODELS_H

#include <QDialog>
#include <QFile>
#include <QObject>
#include <QQueue>
#include <QTime>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QProcess>
#include <QListWidgetItem>
#include "downloadmanager.h"

namespace Ui {
class SyncModels;
}

class SyncModels : public QDialog {
  Q_OBJECT

 public:
  explicit SyncModels(QWidget* parent = 0);
  ~SyncModels();

 private slots:
  void addLine(QString qsLine);
  void progress(int nPercentage);
  void finished();
  void finishedWithErrors();
  void updateAction();
  void checkNewModel();
  void finishedHead();
  void timeout();
  void downloadAction();
  void error(QNetworkReply::NetworkError code);
  void onItemClicked();

 private:
  Ui::SyncModels* ui;
  DownloadManager* mManager;
  QNetworkAccessManager* _pManager;
  QNetworkRequest _CurrentRequest;
  QNetworkReply* _pCurrentReply;
  QFile* _pFile;
  int _nDownloadTotal;
  bool _bAcceptRanges;
  QString version;
  int _nDownloadSize;
  int _nDownloadSizeAtPause;
  QTimer _Timer;

};

#endif // SYNCMODELS_H

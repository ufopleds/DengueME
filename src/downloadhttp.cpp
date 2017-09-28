#include "downloadhttp.h"
#include <QFileInfo>
#include <QDateTime>

DownloadHTTP::DownloadHTTP(QObject* parent) :
  QObject(parent)
  , _pManager(NULL)
  , _pCurrentReply(NULL)
  , _pFile(NULL)
  , _nDownloadTotal(0)
  , _bAcceptRanges(false)
  , _nDownloadSize(0)
  , _nDownloadSizeAtPause(0) {
}

DownloadHTTP::~DownloadHTTP() {
  if (_pCurrentReply != NULL) {
  }
}

void DownloadHTTP::download(QUrl url) {

  _URL = url;
  {
    QFileInfo fileInfo(url.toString());
    _qsFileName = fileInfo.fileName() + ".zip";
  }

  _nDownloadSize = 0;
  _nDownloadSizeAtPause = 0;

  _pManager = new QNetworkAccessManager(this);
  _CurrentRequest = QNetworkRequest(url);

  _pCurrentReply = _pManager->head(_CurrentRequest);

  _Timer.setInterval(5000);
  _Timer.setSingleShot(true);
  connect(&_Timer, SIGNAL(timeout()), this, SLOT(timeout()));
  _Timer.start();

  connect(_pCurrentReply, SIGNAL(finished()), this, SLOT(finishedHead()));
  connect(_pCurrentReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
}

void DownloadHTTP::download() {


  if (_bAcceptRanges) {
    QByteArray rangeHeaderValue = "bytes=" + QByteArray::number(_nDownloadSizeAtPause) + "-";
    if (_nDownloadTotal > 0) {
      rangeHeaderValue += QByteArray::number(_nDownloadTotal);
    }
    _CurrentRequest.setRawHeader("Range", rangeHeaderValue);
  }

  _pCurrentReply = _pManager->get(_CurrentRequest);

  _Timer.setInterval(5000);
  _Timer.setSingleShot(true);
  connect(&_Timer, SIGNAL(timeout()), this, SLOT(timeout()));
  _Timer.start();

  connect(_pCurrentReply, SIGNAL(finished()), this, SLOT(finished()));
  connect(_pCurrentReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
  connect(_pCurrentReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
}

void DownloadHTTP::finishedHead() {
  _Timer.stop();
  _bAcceptRanges = false;

  QList<QByteArray> list = _pCurrentReply->rawHeaderList();
  foreach (QByteArray header, list) {
    QString qsLine = QString(header) + " = " + _pCurrentReply->rawHeader(header);

  }

  if (_pCurrentReply->hasRawHeader("Accept-Ranges")) {
    QString qstrAcceptRanges = _pCurrentReply->rawHeader("Accept-Ranges");
    _bAcceptRanges = (qstrAcceptRanges.compare("bytes", Qt::CaseInsensitive) == 0);

  }

  _nDownloadTotal = _pCurrentReply->header(QNetworkRequest::ContentLengthHeader).toInt();

  _CurrentRequest.setRawHeader("Connection", "Keep-Alive");
  _CurrentRequest.setAttribute(QNetworkRequest::HttpPipeliningAllowedAttribute, true);
  _pFile = new QFile(_qsFileName + ".part");

  if (!_bAcceptRanges) {
    _pFile->remove();
  }
  _pFile->open(QIODevice::ReadWrite | QIODevice::Append);
  _nDownloadSizeAtPause = _pFile->size();
  download();
}

void DownloadHTTP::finished() {

  int size = _pFile->size();

  if(_pCurrentReply->errorString().contains("Unknown error")) {
    if(size != _nDownloadSize) {
      _Timer.stop();
      _pFile->close();
      QFile::remove(_pFile->fileName());
      _pFile = NULL;
      _pCurrentReply = 0;
      addLine(tr("Corrupted file. Please try again."));

    } else {

      _Timer.stop();
      _pFile->close();
      QFile::remove(_qsFileName);
      _pFile->rename(_qsFileName + ".part", _qsFileName);

      _pFile = NULL;
      _pCurrentReply = 0;        ;
      emit downloadComplete();
    }
  } else {
    _Timer.stop();
    _pFile->close();
    QFile::remove(_pFile->fileName());
    _pFile = NULL;
    _pCurrentReply = 0;


  }
}

void DownloadHTTP::downloadProgress(qint64 bytesReceived, qint64 bytesTotal) {
  _Timer.stop();
  _nDownloadSize = _nDownloadSizeAtPause + bytesReceived;

  _pFile->write(_pCurrentReply->readAll());
  int nPercentage = static_cast<int>((static_cast<float>(_nDownloadSizeAtPause + bytesReceived) * 100.0) / static_cast<float>(_nDownloadSizeAtPause + bytesTotal));
  emit progress(nPercentage);
  _Timer.start(5000);
}

#include "syncmodels.h"
#include "ui_syncmodels.h"
#include <QProgressBar>
#include <QPushButton>
#include <QDesktopServices>
#include <QStandardItemModel>
#include <dengueme.h>
#include <QDebug>
#include <QMessageBox>
#ifdef Q_OS_LINUX
#define SO_MACHINE "Linux"
#else
#define SO_MACHINE "Windows"
#endif
SyncModels::SyncModels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SyncModels)
{

    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel(0, 1, this);
    ui->listView->setModel(model);

    ui->downloadButton->setEnabled(false);
    mManager = new DownloadManager(this);
    connect(mManager, SIGNAL(addLine(QString)), this, SLOT(addLine(QString)));
    connect(mManager, SIGNAL(downloadComplete()), this, SLOT(finished()));
    connect(mManager, SIGNAL(progress(int)), this, SLOT(progress(int)));
    connect(ui->updateButton,SIGNAL(clicked()),this,SLOT(updateAction()));
    connect(ui->downloadButton,SIGNAL(clicked()),this,SLOT(downloadAction()));
}


void SyncModels::downloadAction(){

    ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
    addLine(tr("Updating models..."));

    QUrl url("https://codeload.github.com/ufopleds/DengueMELib/zip/models_"+version);
    mManager->download(url);


}
void SyncModels::checkNewModel(){
    ui->progressBar->setValue(0);

    ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
    QUrl url("https://github.com/ufopleds/DengueMELib/releases/latest");
    ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
    _pManager = new QNetworkAccessManager(this);
    _CurrentRequest = QNetworkRequest(url);

    _pCurrentReply = _pManager->head(_CurrentRequest);
    addLine(tr("Checking for updates"));

    _Timer.setInterval(10000);
    _Timer.setSingleShot(true);
    connect(&_Timer, SIGNAL(timeout()), this, SLOT(timeout()));
    _Timer.start();

    connect(_pCurrentReply, SIGNAL(finished()), this, SLOT(finishedHead()));
    connect(_pCurrentReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
}
void SyncModels::finishedHead(){
    QString actualVersion = dengueme::config("modelsVersion") ;

    _Timer.stop();
    version = "";
    QList<QByteArray> list = _pCurrentReply->rawHeaderList();

    foreach (QByteArray header, list)
    {
        QString qsLine = QString(header) + " = " + _pCurrentReply->rawHeader(header);
        if(header == "Location"){
            this->version = _pCurrentReply->rawHeader(header);
            version.remove(0,version.lastIndexOf("/")+1);
            version.remove(0,version.lastIndexOf("_v")+1);
        }

    }

    if(!version.isEmpty()){
        if(actualVersion >= version){
            addLine(tr("Your models are up to date."));
            QString actualVersion = dengueme::config("modelsVersion") ;
            addLine(tr("Your current version is:  ")+actualVersion);
            _pCurrentReply->abort();
            ui->downloadButton->setEnabled(false);
        }else if(actualVersion < version){
            addLine(tr("Your models are not up to date. \nNew version: ")+version);
            _pCurrentReply->abort();
            ui->downloadButton->setEnabled(true);
            ui->downloadButton->setFocus();
        }
    }else{
        addLine(tr("Connection Closed."));
        _pCurrentReply->abort();
    }

    if(QDir(ABS_APP_DIR+"/Models").entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries).count() == 0)    {
        ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
        addLine(tr("Your models folder is empty or misssing. Please download it."));
        ui->downloadButton->setEnabled(true);
    }


}

void SyncModels::timeout(){
    ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
    addLine(tr("Timeout, Sorry for the incovenience"));
    addLine(tr("You may download the models from the website"));
    addLine(tr("And extract the Models folder into the DengueME folder "));
    addLine("https://github.com/ufopleds/DengueMELib/releases/latest");
    addLine(tr("Or try again."));
}

void SyncModels::updateAction(){
    ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
    ui->listView->reset();
    checkNewModel();
}

void SyncModels::addLine(QString qsLine){
    int nRow = ui->listView->model()->rowCount();
    ui->listView->model()->insertRow(nRow);
    ui->listView->model()->setData(ui->listView->model()->index(nRow, 0), qsLine);
}


void SyncModels::progress(int nPercentage){
    ui->progressBar->setValue(nPercentage);
}

void SyncModels::finished(){
    addLine(tr("Download completed."));
    addLine(tr("Models library updated. New version: ")+version);
    addLine(tr("A zip file was downloaded into the DengueME main directory."));
    addLine(tr("Please extract this file directly into the DengueME folder."));

    dengueme::saveconfig("modelsVersion",version);
    dengueme::setconfig("modelsVersion",version);

    QString file =ABS_APP_DIR;
    QUrl url = QUrl::fromLocalFile(file);
    QDesktopServices::openUrl(url); //works

    ui->downloadButton->setEnabled(false);
    ui->updateButton->setEnabled(true);
}


void SyncModels::error(QNetworkReply::NetworkError code){

    if(code == 3){
        ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
        addLine(tr("No internet connection."));
        addLine(tr("You may download the models from the website"));
        addLine(tr("And extract the Models folder into the DengueME folder "));
        addLine("https://github.com/ufopleds/DengueMELib/releases/latest");
        addLine(tr("Or try again."));
    }else{
        ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
        addLine(_pCurrentReply->errorString());
        addLine(tr("You may download the models from the website"));
        addLine(tr("And extract the Models folder into the DengueME folder "));
        addLine(tr("https://github.com/ufopleds/DengueMELib/releases/latest"));
        addLine(tr("Or try again."));
    }

}
SyncModels::~SyncModels()
{
    delete ui;
}

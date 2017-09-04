#include <QProgressBar>
#include <QPushButton>
#include <QDesktopServices>
#include <QStandardItemModel>
#include <dengueme.h>
#include <QMessageBox>
#include <QtXml>

#include "syncmodels.h"
#include "ui_syncmodels.h"

#ifdef Q_OS_LINUX
#define SO_MACHINE "Linux"
#else
#define SO_MACHINE "Windows"
#endif

SyncModels::SyncModels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SyncModels){

    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QStandardItemModel *model = new QStandardItemModel(0, 1, this);
    ui->listView->setModel(model);

    ui->downloadButton->setEnabled(false);
    mManager = new DownloadManager(this);

    connect(mManager, SIGNAL(addLine(QString)), this, SLOT(addLine(QString)));
    connect(mManager, SIGNAL(downloadComplete()), this, SLOT(finished()));
    connect(mManager, SIGNAL(downloadError()), this, SLOT(finishedWithErrors()));
    connect(mManager, SIGNAL(progress(int)), this, SLOT(progress(int)));
    connect(ui->updateButton,SIGNAL(clicked()),this,SLOT(updateAction()));
    connect(ui->downloadButton,SIGNAL(clicked()),this,SLOT(downloadAction()));
    connect(ui->listView, SIGNAL(doubleClicked(QModelIndex )), SLOT(onItemClicked()));
}


void SyncModels::downloadAction(){
    ui->updateButton->setEnabled(false);
    ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
    addLine(tr("Updating models..."));

    QUrl url("https://codeload.github.com/ufopleds/DengueMELib/zip/models_v"+version);
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


void SyncModels::onItemClicked(){

    QModelIndex index = ui->listView->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();

    if(itemText.contains("https:")){
        QUrl myUrl(itemText);
        QDesktopServices::openUrl(myUrl);
    }

}

void SyncModels::finishedHead(){

    QString actualVersion = dengueme::config("modelsVersion");

    _Timer.stop();
    version = "";
    QList<QByteArray> list = _pCurrentReply->rawHeaderList();

    foreach (QByteArray header, list)
    {
        if(header == "Location"){
            this->version = _pCurrentReply->rawHeader(header);
            version.remove(0,version.lastIndexOf("/")+1);
            version.remove(0,version.lastIndexOf("_v")+1);
            version.replace("v","");
        }

    }

    QFileInfo info(DEFAULT_MODELS_DIR+"dmelib.xml");
    QFile file(DEFAULT_MODELS_DIR+"dmelib.xml");
    if (!file.open(QFile::ReadOnly)){
        ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
        addLine(tr("Files in the Models Library folder are missing. Please click on the button to download the Models Library"));
        ui->downloadButton->setEnabled(true);
        ui->updateButton->setEnabled(true);
        _pCurrentReply->abort();
        return;
    }
    QDomDocument versionXml;

    if (!versionXml.setContent(&file)){
        ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
        addLine(tr("Files in the Models Library folder are missing. Please click on the button to download the Models Library"));
        ui->downloadButton->setEnabled(true);
        ui->updateButton->setEnabled(true);
        _pCurrentReply->abort();
        return;
    }
    QDomElement root = versionXml.firstChildElement("denguemelib");
    QDomElement versionChild = root.firstChildElement("version");

    actualVersion = versionChild.text();

    if(!version.isEmpty()){
        if(actualVersion >= version){
            addLine(tr("Models Library is updated."));
            QString actualVersion = dengueme::config("modelsVersion") ;
            addLine(tr("Your current version is: ")+actualVersion);
            _pCurrentReply->abort();
            ui->downloadButton->setEnabled(false);
            ui->updateButton->setEnabled(true);
        }else if(actualVersion < version){
            addLine(tr("Your models are not up to date. \nNew version: ")+version);
            _pCurrentReply->abort();
            ui->downloadButton->setEnabled(true);
            ui->updateButton->setEnabled(true);
            ui->downloadButton->setFocus();
        }
    }else{
        addLine(tr("Connection Closed."));
        ui->updateButton->setEnabled(true);
        _pCurrentReply->abort();
    }

    if(QDir(ABS_APP_DIR+"/Models").entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries).count() == 0)    {
        ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
        addLine(tr("The Models Library folder is empty or missing.  Click on the button to download the Models Library"));
        ui->downloadButton->setEnabled(true);
        ui->updateButton->setEnabled(true);
        _pCurrentReply->abort();
    }


}

void SyncModels::timeout(){
    ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
    addLine(tr("Timeout"));
    addLine(tr("You may try again. "));
    addLine(tr("Or you can download the Models Library yourself. To do this, please perform the following steps: "));
    addLine(tr("1) Access the website and download the compressed file.  "));
    addLine(tr("https://github.com/ufopleds/DengueMELib/releases/latest"));
    addLine(tr("2) Extract the folder named \"Models\" into the same folder where DengueME is installed, replacing existing one if there is."));
    addLine(tr("3) Click \"Check updates\" button to verify if Models Library was updated sucessfully."));
    ui->updateButton->setEnabled(true);
}

void SyncModels::updateAction(){
    ui->updateButton->setEnabled(false);
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

void SyncModels::finishedWithErrors(){

    ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
    addLine(tr("It seems that computer does not have internet connection."));
    addLine(tr("You may try again. "));
    addLine(tr("Or you can download the Models Library yourself. To do this, please perform the following steps: "));
    addLine(tr("1) Access the website and download the compressed file.  "));
    addLine(tr("https://github.com/ufopleds/DengueMELib/releases/latest"));
    addLine(tr("2) Extract the folder named \"Models\" into the same folder where DengueME is installed, replacing existing one if there is."));
    addLine(tr("3) Click \"Check updates\" button to verify if Models Library was updated sucessfully."));
    ui->updateButton->setEnabled(true);
    _pCurrentReply->abort();
    ui->downloadButton->setEnabled(false);
}

void SyncModels::finished(){

    qDebug()<< _pCurrentReply->errorString();
    addLine(tr("Models Library compressed file was downloaded, version: ")+version);
    addLine(tr("Please extract the folder named \"Models\" into the same folder where DengueME is installed, replacing existing one if there is. " ));
    addLine(tr("Then, click \"Check updates\" button again to verify if Models Library was updated sucessfully."));

    dengueme::saveconfig("modelsVersion",version);
    dengueme::setconfig("modelsVersion",version);

    QString file = ABS_APP_DIR;
    QUrl url = QUrl::fromLocalFile(file);
    QDesktopServices::openUrl(url);

    ui->downloadButton->setEnabled(false);
    ui->updateButton->setEnabled(true);
}


void SyncModels::error(QNetworkReply::NetworkError code){

    if(code == 3){
        ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
        addLine(tr("It seems that computer does not have internet connection."));
        addLine(tr("You may try again."));
        addLine(tr("Or you can download the Models Library yourself. To do this, please perform the following steps: "));
        addLine(tr("1) Access the website and download the compressed file.  "));
        addLine(tr("https://github.com/ufopleds/DengueMELib/releases/latest"));
        addLine(tr("2) Extract the folder named \"Models\" into the same folder where DengueME is installed, replacing existing one if there is."));
        addLine(tr("3) Click \"Check updates\" button to verify if Models Library was updated sucessfully."));
        ui->updateButton->setEnabled(true);
    }else{
        ui->listView->model()->removeRows(0,ui->listView->model()->rowCount());
        addLine(tr("You may try again."));
        addLine(tr("Or you can download the Models Library yourself. To do this, please perform the following steps: "));
        addLine(tr("1) Access the website and download the compressed file. "));
        addLine(tr("https://github.com/ufopleds/DengueMELib/releases/latest"));
        addLine(tr("2) Extract the folder named \"Models\" into the same folder where DengueME is installed, replacing existing one if there is."));
        addLine(tr("3) Click \"Check updates\" button to verify if Models Library was updated sucessfully."));
        ui->updateButton->setEnabled(true);
    }

}
SyncModels::~SyncModels()
{
    delete ui;
}

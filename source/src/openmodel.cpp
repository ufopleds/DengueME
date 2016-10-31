#include "openmodel.h"
#include "ui_openmodel.h"
#include "builder/modelbuilder.h"
#include "ui_modelbuilder.h"
#include "builder/newmodelwizard.h"
#include "builder/builderdirmodel.h"
#include "dengueme.h"

OpenModel::OpenModel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenModel){

    QDir dir(QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)+"/dengueme");
    dir.mkpath("vector");
    dir.mkpath("transmission");

    ui->setupUi(this);
    BuilderDirModel *model = new BuilderDirModel;
    /* ui->listView->setDirModel(model);
    ui->listView->setWorkspace(QDesktopServices::storageLocation(QDesktopServices::DataLocation));
    connect(model, SIGNAL(updated()), ui->listView, SLOT(expandAll()));
    connect(ui->listView, SIGNAL(collapsed(QModelIndex)), ui->listView, SLOT(expand(QModelIndex)));
    ui->listView->expandAll();

  connect(ui->listView, SIGNAL(activated(QModelIndex)), SLOT(setIndex()));*/


    connect(ui->ok, SIGNAL(clicked()),SLOT(setIndex()));
    connect(ui->cancel, SIGNAL(clicked()),SLOT(close()));
    ui->treeView->setDirModel(model);
    ui->treeView->setWorkspace(QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)+"/dengueme");
    connect(model, SIGNAL(updated()), ui->treeView, SLOT(expandAll()));



    connect(ui->treeView, SIGNAL(doubleClicked(QModelIndex)), SLOT(setIndex()));

}

OpenModel::~OpenModel()
{
    delete ui;
}

void OpenModel::setIndex(){

    this->index = ui->treeView->currentIndex();
    emit accept();
}
QString OpenModel::getFilePath(){
    return  ui->treeView->filePath(this->index);
}

QString OpenModel::getFileName(){
    return  ui->treeView->fileInfo(this->index).fileName();
}





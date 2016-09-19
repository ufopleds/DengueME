#include "modelbuilder.h"
#include "ui_modelbuilder.h"
#include "newmodelwizard.h"
#include "builderdirmodel.h"
#include "../dengueme.h"
#include "openmodel.h"
#include <QDebug>

ModelBuilder::ModelBuilder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModelBuilder)
{
    ui->setupUi(this);
     this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
      QString user_models = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)+"/dengueme";

      qDebug() << user_models;
    QDir dir(user_models);
    dir.mkpath("vector");
    dir.mkpath("transmission");

    BuilderDirModel *model = new BuilderDirModel;
    ui->listView->setDirModel(model);
    ui->listView->setWorkspace(user_models);
    connect(model, SIGNAL(updated()), ui->listView, SLOT(expandAll()));
    connect(ui->listView, SIGNAL(collapsed(QModelIndex)), ui->listView, SLOT(expand(QModelIndex)));
    ui->listView->expandAll();

    setWindowTitle("DengueME Model Builder");
    connect(ui->listView, SIGNAL(activated(QModelIndex)), SLOT(modelActivated(QModelIndex)));
    connect(ui->listView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), SLOT(selectionChanged(QModelIndex,QModelIndex)));
    connect(ui->editor, SIGNAL(closed()), SLOT(onModelClosed()));
    connect(ui->editor, SIGNAL(renamed(QString)), ui->modelFile, SLOT(setText(QString)));
    connect(ui->actionSave, SIGNAL(triggered()), ui->editor, SLOT(save()));
    connect(ui->actionDelete, SIGNAL(triggered()), SLOT(deleteModel()));
    connect(ui->actionEdit, SIGNAL(triggered()), SLOT(openModelWizard()));
    connect(ui->actionNew, SIGNAL(triggered()), SLOT(newModel()));
    connect(ui->buttonClose, SIGNAL(clicked()), SLOT(actionClose()));
    connect(ui->stackedWidget, SIGNAL(currentChanged(int)), SLOT(setToolbar(int)));
    ui->actionSave->setEnabled(false);
    ui->actionDelete->setEnabled(false);
    ui->toolBar->addAction(ui->actionEdit);
    ui->toolBar->addAction(ui->actionNew);

}

void ModelBuilder::openModelWizard(){

    OpenModel *openWizard = new OpenModel(this);

      if(openWizard->exec() == QDialog::Accepted){

          QFileInfo modelinfo(openWizard->getFilePath() + QDir::separator() +openWizard->getFileName() + ".xml");
          qDebug() << modelinfo.filePath();
           if (modelinfo.isFile()) {
              if (!ui->editor->loadModel(modelinfo.filePath(), true))
                  return;
               ui->stackedWidget->setCurrentIndex(1);
      }
  }

}
void ModelBuilder::actionClose() {
    ui->editor->close(0);
}
ModelBuilder::~ModelBuilder()
{
    delete ui;
}

void ModelBuilder::closeEvent(QCloseEvent *event) {
    if (ui->editor->close(0)) {
        QMainWindow::closeEvent(event);
    } else
        event->ignore();
}

void ModelBuilder::modelActivated(QModelIndex index)
{

    QFileInfo modelinfo(ui->listView->filePath(index) + QDir::separator() + ui->listView->fileInfo(index).fileName() + ".xml");
    qDebug() << modelinfo.filePath();
    if (modelinfo.isFile()) {
        if (!ui->editor->loadModel(modelinfo.filePath(), true))
            return;
       ui->stackedWidget->setCurrentIndex(1);

    }
}

void ModelBuilder::selectionChanged(const QModelIndex &current, const QModelIndex &/*previous*/)
{
    ui->toolBar->clear();

    ui->actionDelete->setEnabled(false);

    ui->actionSave->setEnabled(false);

    ui->toolBar->addAction(ui->actionNew);
    ui->actionNew->setEnabled(true);
    ui->toolBar->addAction(ui->actionEdit);
    ui->actionEdit->setEnabled(true);

    if (!current.isValid()) return;

    QFileInfo info = ui->listView->fileInfo(current);
    if (info.dir().canonicalPath() != QDir( QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)+"/dengueme").canonicalPath()) {
        ui->toolBar->addAction(ui->actionEdit);
        ui->actionEdit->setEnabled(true);

        ui->toolBar->addAction(ui->actionDelete);
        ui->actionDelete->setEnabled(true);
    }
}


void ModelBuilder::onModelClosed()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void ModelBuilder::deleteModel()
{
    switch (ui->stackedWidget->currentIndex()) {
    case 0:
        ui->listView->askDelete(ui->listView->currentIndex());
        break;

    case 1: {
        QModelIndex index = ui->listView->indexFromPath(QFileInfo(ui->editor->getModelFile()).path());
        if (index.isValid() && ui->listView->askDelete(index)) {
            ui->editor->clearModel();
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
    default:
        return;
    }
}

void ModelBuilder::editModel() {
    modelActivated(ui->listView->currentIndex());
}

void ModelBuilder::newModel() {
    if (!ui->editor->close(0))
        return;

    NewModelWizard *n = new NewModelWizard( QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)+"/dengueme",QString(),this);
    if (!n->exec()) return;

    QString proj = n->property("project").toString();
    QString name = n->field("name").toString();
    QString dest = QDir::toNativeSeparators( QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)+"/dengueme" + "/" + proj + "/" + name + "/" + name + ".xml");

    dengueme::createEmptyModel(dest);
    dengueme::setProject(proj);
    ui->editor->loadModel(dest, true);
    ui->modelFile->setText(ui->editor->getModelFile());
    ui->stackedWidget->setCurrentIndex(1);


}


void ModelBuilder::setToolbar(int i)
{
    ui->toolBar->clear();
    switch (i) {
    case 0:
        ui->actionEdit->setEnabled(true);
        selectionChanged(ui->listView->currentIndex());
        break;

    case 1:
        ui->toolBar->addAction(ui->actionDelete);
        ui->actionDelete->setEnabled(true);

        ui->toolBar->addAction(ui->actionSave);
        ui->actionSave->setEnabled(true);

       // ui->actionEdit->setEnabled(false);
        ui->actionNew->setEnabled(false);
        break;
    }
}


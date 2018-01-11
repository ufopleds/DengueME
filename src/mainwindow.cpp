#include <QDialog>
#include <QDir>
#include <iostream>
#include "mainwindow.h"
#include "dengueme.h"
#include "newproject.h"
#include "ui_mainwindow.h"
#include "options.h"
#include "about.h"
#include "changeworkspace.h"
#include "newmodel.h"
#include "builder/modelbuilder.h"
#include "workspacemodel.h"
#include "descriptionwindow.h"
#include "dirmodel.h"
#include "syncmodels.h"

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent),
  ui(new Ui::MainWindow),
  helpDialog(new QDialog(this)),
  helpHasBeenCreated(false) {

  ui->setupUi(this);

  ui->treeView->setDirModel(new WorkspaceModel);
  ui->treeView->setWorkspace(dengueme::config("workspace"));
  ui->treeView->expandAll();

  this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
  setMinimumSize(760, 560);
  setState(Browsing);

  if (dengueme::config("mainwindow/defaultstate").isNull()) {

    QByteArray state = saveState().toBase64();
    dengueme::saveconfig("mainwindow/defaultstate", state);
    dengueme::setconfig("mainwindow/defaultstate", state);
  }

  restoreGeometry(QByteArray::fromBase64(dengueme::config("mainwindow/geometry").toLocal8Bit()));
  restoreState(QByteArray::fromBase64(dengueme::config("mainwindow/state").toLocal8Bit()));
  setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);

  ui->actionRunByStep->setEnabled(false);
  ui->actionRunByStep->setVisible(false);

  connect(ui->buttonHelp,         SIGNAL(clicked()), SLOT(onHelpRequested()));
  connect(ui->actionExit,         SIGNAL(triggered()), SLOT(close()));
  connect(ui->buttonDefault,      SIGNAL(clicked()), SLOT(actionDefault()));

  connect(ui->actionNewModel,     SIGNAL(triggered()), SLOT(actionNewModel()));
  connect(ui->actionNewProject,   SIGNAL(triggered()), SLOT(actionNewProject()));

  connect(ui->actionBuilder,      SIGNAL(triggered()), SLOT(actionModelBuilder()));
  connect(ui->actionSave,         SIGNAL(triggered()), SLOT(actionSave()));
  connect(ui->actionClose,        SIGNAL(triggered()), SLOT(actionClose()));
  connect(ui->actionRun,          SIGNAL(triggered()), SLOT(actionRun()));
  connect(ui->actionRemove,       SIGNAL(triggered()), SLOT(actionRemove()));
  connect(ui->actionRename,       SIGNAL(triggered()), SLOT(actionRename()));
  connect(ui->actionSynchronize,  SIGNAL(triggered()), SLOT(actionSync()));
  connect(ui->actionOpenExplorer, SIGNAL(triggered()), SLOT(actionOpenExplorer()));

  connect(ui->actionAbout,        SIGNAL(triggered()), SLOT(actionAbout()));
  connect(ui->actionSetWorkspace, SIGNAL(triggered()), SLOT(actionSetWorkspace()));
  connect(ui->actionOptions,      SIGNAL(triggered()), SLOT(actionOptions()));
  connect(ui->actionModelBuilder, SIGNAL(triggered()), SLOT(actionModelBuilder()));
  connect(ui->actionResetViews,   SIGNAL(triggered()), SLOT(actionResetViews()));

  connect(ui->treeView->selectionModel(), SIGNAL(currentChanged(QModelIndex, QModelIndex)), SLOT(changeToolbar(QModelIndex)));
  connect(ui->treeView, SIGNAL(activated(QModelIndex)), SLOT(modelActivated(QModelIndex)));
  connect(ui->treeView, SIGNAL(customContextMenuRequested(QPoint)), SLOT(workspaceContextMenu(QPoint)));

  connect(ui->editor, SIGNAL(renamed(QString)), ui->modelFile, SLOT(setText(QString)));
  connect(ui->editor, SIGNAL(closed()),   SLOT(onModelClosed()));
  connect(ui->editor, SIGNAL(output(int, QString)),     SLOT(output(int, QString)));
  connect(ui->editor, SIGNAL(interpreterStarted()),    SLOT(onModelStarted()));
  connect(ui->editor, SIGNAL(interpreterStopped(int)), SLOT(onModelStopped(int)));

  connect(ui->run_stopButton, SIGNAL(clicked()), SLOT(actionRun()));
  connect(ui->buttonClose,    SIGNAL(clicked()), SLOT(actionClose()));
  connect(ui->clearButton,    SIGNAL(clicked()), ui->outputBrowser, SLOT(clear()));

  {
    QPushButton* output = new QPushButton(tr("Output"));
    output->setCheckable(true);

    ui->statusBar->setLayoutDirection(Qt::RightToLeft);
    ui->statusBar->addWidget(output);

    connect(ui->outputDock, SIGNAL(visibilityChanged(bool)), output, SLOT(setChecked(bool)));
    connect(output, SIGNAL(toggled(bool)), ui->outputDock, SLOT(setVisible(bool)));
  }

}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::closeEvent(QCloseEvent* event) {

  if (ui->editor->close(0)) {
    dengueme::saveconfig("mainwindow/geometry", saveGeometry().toBase64());
    dengueme::saveconfig("mainwindow/state", saveState().toBase64());
    QMainWindow::closeEvent(event);
  } else
    event->ignore();
}

void MainWindow::setState(State state) {

  switch (state) {
    case Editing:
      ui->editorView->show();
      ui->run_stopButton->setEnabled(true);
      ui->actionRun->setEnabled(true);
      ui->actionModelBuilder->setEnabled(true);
      ui->actionBuilder->setEnabled(true);
      ui->actionClose->setEnabled(true);
      ui->actionSave->setEnabled(true);
      break;

    case Browsing:
      setWindowTitle("DengueME");
      ui->editorView->hide();
      ui->outputDock->close();
      ui->run_stopButton->setEnabled(false);
      ui->actionRun->setEnabled(false);
      ui->actionRunByStep->setEnabled(false);
      ui->actionClose->setEnabled(false);
      ui->actionSave->setEnabled(false);
      ui->actionRename->setEnabled(false);
      ui->actionRemove->setEnabled(false);
      ui->treeView->clearFocus();
      ui->treeView->selectionModel()->clearSelection();
      ui->treeView->selectionModel()->clearCurrentIndex();
      break;

    case Running:
      ui->outputDock->show();
      break;
  }
}


void MainWindow::workspaceContextMenu(const QPoint& point) {
  QModelIndex index = ui->treeView->indexAt(point);
  if (!index.isValid()) return;
  ui->treeView->selectionModel()->setCurrentIndex(index, QItemSelectionModel::Select);

  QPoint globalPos = ui->treeView->mapToGlobal(point);

  enum Action { Open, Close, AddNew, Rename, Remove, OpenExplorer };

  QMenu menu;
  QMap<int, QAction*> actions;
  QFileInfo info = ui->treeView->fileInfo(index);
  actions.insert(OpenExplorer, ui->actionOpenExplorer);
  actions.insert(Remove, ui->actionRemove);

  if (info.absoluteFilePath() == ui->editor->getModelFile()) {
    actions.insert(Close, ui->actionClose);
  } else
    actions.insert(Open, new QAction(tr("Open"), &menu));

  if (info.isDir()) {
    actions.insert(AddNew, new QAction(tr("Add model"), &menu));
  } else
    actions.insert(Rename, ui->actionRename);

  menu.addActions(actions.values());

  QAction* opt = menu.exec(globalPos);

  if (opt)
    switch (actions.key(opt)) {
      case Open:
        modelActivated(index);
        break;

      case AddNew:
        actionNewModel(info.fileName());
        break;

      default:
        break;
    }
}
void MainWindow::changeToolbar(QModelIndex index) {

  QFileInfo modelinfo(ui->treeView->fileInfo(index));
  if (modelinfo.isFile()) {
    ui->actionRename->setEnabled(true);
    ui->actionRemove->setEnabled(true);
  } else if (modelinfo.isDir()) {
    ui->actionRemove->setEnabled(true);
    ui->actionRename->setEnabled(false);
  } else {
    ui->actionRename->setEnabled(false);
    ui->actionRemove->setEnabled(false);
  }

}

void MainWindow::modelActivated(QModelIndex index) {

  QFileInfo modelinfo(ui->treeView->fileInfo(index));

  if (modelinfo.isFile()) {

    if (ui->editor->loadModel(modelinfo.filePath(), false)) {

      setState(Editing);
    }
  }
}
void MainWindow::actionNewModel(QString project) {
  NewModel n(dengueme::config("workspace"), project);
  connect(&n, SIGNAL(accepted(QString, QString, QString, QString)),
          SLOT(newModel(QString, QString, QString, QString)));
  n.exec();
}

void MainWindow::actionNewProject() {
  NewProject n(this);
  connect(&n, SIGNAL(accepted(QString, int)), SLOT(newProject(QString, int)));
  n.exec();
}

void MainWindow::actionSave() {
  ui->editor->save();
}

void MainWindow::actionDefault() {

  int opt = QMessageBox::question(this, tr("Reset Model"),
                                  tr("This action will reset all changes that you made so far. Do you want to continue?"),
                                  QMessageBox::Yes | QMessageBox::No);

  if(opt == QMessageBox::Yes) {
    QString path = ui->modelFile->text();

    QFile file(path);

    QDomDocument modelXml;
    file.open(QFile::ReadOnly);


    modelXml.clear();
    modelXml.setContent(&file);

    QDomElement root = modelXml.firstChildElement("xmlmodel");

    QDomElement a = root.firstChildElement("model");

    QString modelcategory = a.firstChildElement("category").text();
    QString modeltype = a.firstChildElement("name").text();
    file.close();

    ui->editor->close(2);

    QString original_dir = DEFAULT_MODELS_DIR + modelcategory + '/' + modeltype;
    QFileInfo original_file(original_dir + '/' + modeltype + ".xml");
    if(original_file.exists()) {
      dengueme::copy(original_file.absoluteFilePath(), path, true);
      QModelIndex index = ui->treeView->indexFromPath(path);
      modelActivated(index);
    }
    QString appData = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + "/dengueme/" + modelcategory + '/' + modeltype;
    QFileInfo app_data(appData + '/' + modeltype + ".xml");
    if(app_data.exists()) {
      dengueme::copy(app_data.absoluteFilePath(), path, true);
      QModelIndex index = ui->treeView->indexFromPath(path);
      modelActivated(index);
    }
  }

}

void MainWindow::actionClose() {
  ui->editor->close(0);
}

void MainWindow::actionOpenExplorer() {

  QModelIndex index = ui->treeView->currentIndex();
  if (!index.isValid()) return;

  QFileInfo fileInfo = ui->treeView->fileInfo(index);
  QString path = "";
  if (fileInfo.isDir()) {
    path = fileInfo.absolutePath();
  } else {
    path = fileInfo.absolutePath() + "/" + fileInfo.baseName() + "_scripts";
  }
  QUrl url = path;
  QDesktopServices::openUrl(url);
}

void MainWindow::actionRemove() {
  QModelIndex index = ui->treeView->currentIndex();
  if (!index.isValid()) return;

  if(ui->treeView->askDelete(index)) {
    ui->editor->close(2);
    ui->actionRemove->setDisabled(true);
    ui->actionRename->setDisabled(true);
  } else {
    ui->actionRemove->setDisabled(false);
  }

}

void MainWindow::actionSync() {

  SyncModels* sync = new SyncModels(this);
  sync->exec();
}

void MainWindow::actionRename() {
  QModelIndex index = ui->treeView->currentIndex();
  if (!index.isValid()) return;

  QString newPath = ui->treeView->askRename(index);
  if(newPath != "false") {
    QFileInfo info = ui->treeView->fileInfo(index);
    QStringList namePath = ui->editor->getModelFile().split( "/" );
    QString modelName = namePath.value(namePath.size() - 1);
    if ( (ui->editor->getModelFile().isEmpty()) || (modelName != (info.baseName() + ".xml")) ) {
      newPath = info.path() + '/' + newPath + ".xml";
    } else {
      newPath = info.path() + '/' + newPath + ".xml";
      ui->modelFile->setText(newPath);
      ui->editor->updateModelInfo(newPath);
    }
    ui->actionRename->setDisabled(true);
    ui->actionRemove->setDisabled(true);
  }
  ui->treeView->selectionModel()->select(index,  QItemSelectionModel::ClearAndSelect);
}

void MainWindow::actionRun() {
  if(ui->editorView->isVisible()) {
    setState(Running);
    if(! ui->editor->isRunning()) ui->editor->execModel(false);
    else ui->editor->stopModel();
  }

  ui->editor->execModel(false);
}


void MainWindow::actionOptions() {

  QString actualWorkspacePath = dengueme::settingsFile.value("workspace").toString();
  Options(this).exec();
  if (QDialog::Accepted) {
#if defined(Q_OS_MACOS)
    QString newWorkspacePath = dengueme::settingsFile.value("workspace").toString();
    if (actualWorkspacePath != newWorkspacePath) {
      ui->treeView->setWorkspace(dengueme::config("workspace"));
      ui->treeView->expandAll();
    }
#endif
  }

}

void MainWindow::actionAbout() {
  About(this).exec();
}

void MainWindow::actionSetWorkspace() {
  ui->treeView->clearSelection();
  if (ChangeWorkspace(this).exec() == QDialog::Accepted)
    ui->treeView->setWorkspace(dengueme::config("workspace"));

  if (ui->treeView->currentIndex().row() < 0 ) {
    ui->actionRemove->setEnabled(false);
    ui->actionRename->setEnabled(false);
  }
  ui->treeView->clearSelection();
}

void MainWindow::actionModelBuilder() {
  ModelBuilder* builder = new ModelBuilder(this);
  builder->show();

}

void MainWindow::actionResetViews() {
  restoreState(QByteArray::fromBase64(dengueme::config("mainwindow/state").toLatin1()));
}

void MainWindow::onModelStarted() {

  ui->run_stopButton->setText(tr("Stop"));
  ui->actionRun->setIcon( QIcon(":/Resources/stop.png"));

  output(1, tr("LOADING MODEL..."));
}

void MainWindow::onModelClosed() {
  setState(Browsing);
}

void MainWindow::onModelStopped(int exitCode) {

  ui->run_stopButton->setText(tr("Run"));
  ui->actionRun->setIcon( QIcon(":/Resources/run.png"));
  if(ui->editor->view_model->interpreter() == ui->editor->view_model->TerraME)
    output (1, tr("TerraME process exited with code ") + QString::number(exitCode));
  else
    output (1, tr("R process exited with code ") + QString::number(exitCode));
}

void MainWindow::output(int lvl, QString text) {

  setState(Running);

  text = text.replace('\n', "<br>").replace(' ', "&nbsp;");
  switch (lvl) {
    default:
    case 1:
      ui->outputBrowser->append("<font face=\"Monospace\">" + text);
      break;
    case 2:
      ui->outputBrowser->append("<font face=\"Monospace\" color=\"orange\">" + text);
      break;
    case 3:
      ui->outputBrowser->append("<font face=\"Monospace\" color=\"red\">" + text);
      break;
  }
}

void MainWindow::newModel(QString category, QString type, QString project, QString name) {
  QString dest = QDir::toNativeSeparators(dengueme::config("workspace") + "/" + project + "/" + name + ".xml");

  if ((false && dengueme::createDemo(type, dest, category))
      || (true && dengueme::createModel(dest, type, category)))
    if (ui->editor->loadModel(dest, false)) {
      setState(Editing);
    }
}

void MainWindow::newProject(QString name, int newModel) {
  int checked = 1;
  QDir dir(dengueme::config("workspace") + '/' + name);
  if (!dir.mkpath(dir.path())) {
    QMessageBox::critical(this, tr("Error"), tr("Error creating project folder."));
  }
  if (newModel == checked) {
    actionNewModel(name);
  }
}

void MainWindow::onHelpRequested() {

  DescriptionWindow* description = new DescriptionWindow(this, ui->editor->modelDescription);
  description->show();
}



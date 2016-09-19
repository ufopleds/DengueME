#include <QDialog>

#include "mainwindow.h"
#include "dengueme.h"
#include "tests.h"
#include "newproject.h"
#include "ui_mainwindow.h"
#include "options.h"
#include "about.h"
#include "changeworkspace.h"
#include "renamewizard.h"
#include "newmodel.h"
#include "builder/modelbuilder.h"
#include "workspacemodel.h"
#include "descriptionwindow.h"
#include "dirmodel.h"
#include "syncmodels.h"
#include <QDebug>


//Primary Window
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
    ui(new Ui::MainWindow),
    helpDialog(new QDialog(this)),
    helpText(new HelpBrowser("dengueme.qhc",helpDialog)),
    helpHasBeenCreated(false)
{
    ui->setupUi(this);
    ui->treeView->setDirModel(new WorkspaceModel);
    ui->treeView->setWorkspace(dengueme::config("workspace"));
    ui->treeView->expandAll();
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setMinimumSize(760,560);
    setState(Browsing);
    if (dengueme::config("mainwindow/defaultstate").isNull()) {
        QByteArray state = saveState().toBase64();
        dengueme::saveconfig("mainwindow/defaultstate", state);
        dengueme::setconfig("mainwindow/defaultstate", state);
    }

    restoreGeometry(QByteArray::fromBase64(dengueme::config("mainwindow/geometry").toLocal8Bit()));
    restoreState(QByteArray::fromBase64(dengueme::config("mainwindow/state").toLocal8Bit()));
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);

    connect(ui->buttonHelp, SIGNAL(clicked()),SLOT(onHelpRequested()));
    connect(ui->actionExit,         SIGNAL(triggered()), SLOT(close()));
    connect(ui->buttonDefault,         SIGNAL(clicked()), SLOT(actionDefault()));

    connect(ui->actionNewModel,     SIGNAL(triggered()), SLOT(actionNewModel()));
    connect(ui->actionNewProject,   SIGNAL(triggered()), SLOT(actionNewProject()));

    connect(ui->actionBuilder, SIGNAL(triggered()), SLOT(actionModelBuilder()));
    connect(ui->actionSave,         SIGNAL(triggered()), SLOT(actionSave()));
    connect(ui->actionClose,        SIGNAL(triggered()), SLOT(actionClose()));
    connect(ui->actionRun,          SIGNAL(triggered()), SLOT(actionRun()));
    connect(ui->actionRunByStep,    SIGNAL(triggered()), SLOT(actionRunByStep()));
    connect(ui->actionRemove,       SIGNAL(triggered()), SLOT(actionRemove()));
    connect(ui->actionRename,       SIGNAL(triggered()), SLOT(actionRename()));
    connect(ui->actionSynchronize,       SIGNAL(triggered()), SLOT(actionSync()));


    connect(ui->actionAbout,        SIGNAL(triggered()), SLOT(actionAbout()));
    connect(ui->actionSetWorkspace, SIGNAL(triggered()), SLOT(actionSetWorkspace()));
    connect(ui->actionOptions,      SIGNAL(triggered()), SLOT(actionOptions()));
    connect(ui->actionModelBuilder, SIGNAL(triggered()), SLOT(actionModelBuilder()));
    connect(ui->actionResetViews,   SIGNAL(triggered()), SLOT(actionResetViews()));

    connect(ui->treeView, SIGNAL(activated(QModelIndex)), SLOT(modelActivated(QModelIndex)));
    connect(ui->treeView, SIGNAL(customContextMenuRequested(QPoint)), SLOT(workspaceContextMenu(QPoint)));

    connect(ui->editor, SIGNAL(renamed(QString)), ui->modelFile, SLOT(setText(QString)));
    connect(ui->editor, SIGNAL(closed()),                SLOT(onModelClosed()));
    connect(ui->editor, SIGNAL(output(int,QString)),     SLOT(output(int,QString)));
    connect(ui->editor, SIGNAL(interpreterStarted()),    SLOT(onModelStarted()));
    connect(ui->editor, SIGNAL(interpreterStopped(int)), SLOT(onModelStopped(int)));

    connect(ui->run_stopButton, SIGNAL(clicked()), SLOT(actionRun()));
    connect(ui->buttonClose,    SIGNAL(clicked()), SLOT(actionClose()));
    connect(ui->clearButton,    SIGNAL(clicked()), ui->outputBrowser, SLOT(clear()));

    {
        QPushButton *output = new QPushButton(tr("Output"));
        output->setCheckable(true);

        ui->statusBar->setLayoutDirection(Qt::RightToLeft);
        ui->statusBar->addWidget(output);

        connect(ui->outputDock, SIGNAL(visibilityChanged(bool)), output, SLOT(setChecked(bool)));
        connect(output, SIGNAL(toggled(bool)), ui->outputDock, SLOT(setVisible(bool)));
    }



    ///TODO - Shortcuts
    new QShortcut(QKeySequence("Ctrl+F2"),this,SLOT(runUnitTests()));

    ///TODO - Shortcuts
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event) {
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
        ui->actionRunByStep->setEnabled(true);
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

    enum Action { Open, Close , AddNew, Rename, Remove };

    QMenu menu;
    QMap<int, QAction *> actions;
    QFileInfo info = ui->treeView->fileInfo(index);

    actions.insert(Rename, ui->actionRename);
    actions.insert(Remove, ui->actionRemove);

    if (info.absoluteFilePath() == ui->editor->getModelFile())
        actions.insert(Close, ui->actionClose);
    else
        actions.insert(Open, new QAction(tr("Open"), &menu));

    if (info.isDir())
        actions.insert(AddNew, new QAction(tr("Add model"), &menu));

    menu.addActions(actions.values());

    QAction *opt = menu.exec(globalPos);

    if (opt)
        switch (actions.key(opt)) {
        case Open:
            modelActivated(index);
            break;

        case AddNew:
            actionNewModel(info.fileName());
            break;

        default: break;
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
    NewModel n(dengueme::config("workspace"),project);
    connect(&n, SIGNAL(accepted(QString,QString,QString,QString)),
            SLOT(newModel(QString,QString,QString,QString)));
    n.exec();
}

void MainWindow::actionNewProject() {
    NewProject n(dengueme::config("workspace"),this);
    connect(&n, SIGNAL(accepted(QString)), SLOT(newProject(QString)));
    n.exec();
}

void MainWindow::actionSave() {
    ui->editor->save();
}

void MainWindow::actionDefault() {
    int opt = QMessageBox::question(this,tr("Reset Model"),
                                    "This action will reset all changes that you made so far. Do you want to continue?",
                                    QMessageBox::Yes | QMessageBox::No);


    if(opt == QMessageBox::Yes){
        QString path = ui->modelFile->text();

        QFile file(path);
        QStringList dirList = path.split("/");
        QDomDocument modelXml;
        file.open(QFile::ReadOnly);


        modelXml.clear();
        modelXml.setContent(&file);

        QDomElement root = modelXml.firstChildElement("xmlmodel");

        QDomElement a = root.firstChildElement("script");
        QString modelcategory = a.firstChildElement("modelcategory").text();
        QString modeltype = a.firstChildElement("modeltype").text();
        file.close();



        ui->editor->close(2);

        QString original_dir = DEFAULT_MODELS_DIR + modelcategory + '/' + modeltype;
        QFileInfo original_file(original_dir + '/' + modeltype+ ".xml");
        dengueme::copy(original_file.absoluteFilePath(),path,true);
        QModelIndex index = ui->treeView->indexFromPath(path);

        modelActivated(index);
    }

}



void MainWindow::actionClose() {
    ui->editor->close(0);
}

void MainWindow::actionRemove() {
    QModelIndex index = ui->treeView->currentIndex();
    if (!index.isValid()) return;


    if(ui->treeView->askDelete(index)){
        ui->editor->close(2);
    }



}

void MainWindow::actionSync(){
    SyncModels *sync = new SyncModels(this);
    sync->exec();
}

void MainWindow::actionRename() {
    QModelIndex index = ui->treeView->currentIndex();
    if (!index.isValid()) return;

    QString newPath = ui->treeView->askRename(index);
    if(newPath != "false"){
        QFileInfo info = ui->treeView->fileInfo(index);
        newPath = info.path()+ '/' + newPath + ".xml";
        ui->modelFile->setText(newPath);
        ui->editor->updateModelInfo(newPath);
    }

}

void MainWindow::actionRun() {
    if(ui->editorView->isVisible()) {
        setState(Running);
        if(! ui->editor->isRunning()) ui->editor->execModel(false);
        else ui->editor->stopModel();
    }
}


void MainWindow::actionRunByStep() {
    if(ui->editorView->isVisible()) {
        setState(Running);
        if(! ui->editor->isRunning()) ui->editor->execModel(true);
        else ui->editor->stopModel();
    }
}

void MainWindow::actionOptions() {
    Options(this).exec();
}

void MainWindow::actionAbout() {
    About(this).exec();
}

void MainWindow::actionSetWorkspace() {
    if (ChangeWorkspace(this).exec() == QDialog::Accepted)
        ui->treeView->setWorkspace(dengueme::config("workspace"));
}

void MainWindow::actionModelBuilder() {
    ModelBuilder *builder = new ModelBuilder(this);
    builder->show();

}


void MainWindow::actionResetViews() {
    restoreState(QByteArray::fromBase64(dengueme::config("mainwindow/state").toLatin1()));
}

void MainWindow::onModelStarted() {
    ui->run_stopButton->setText(tr("Stop"));


}

void MainWindow::onModelClosed()
{
    setState(Browsing);
}

void MainWindow::onModelStopped(int exitCode) {
    ui->run_stopButton->setText(tr("Run"));
    output (1, "Process exited with code " + QString::number(exitCode));
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

void MainWindow::newModel(QString category, QString type, QString project, QString name)
{
    QString dest = QDir::toNativeSeparators(dengueme::config("workspace") + "/" + project + "/" + name + ".xml");

    if ((false && dengueme::createDemo(type, dest,category))
            || (true && dengueme::createModel(dest, type, category)))
        if (ui->editor->loadModel(dest, false)){
            setState(Editing);
        }
}

void MainWindow::newProject(QString name)
{
    QDir dir(dengueme::config("workspace") + '/' + name);
    if (!dir.mkpath(dir.path())) {
        QMessageBox::critical(this, tr("Error"), tr("Error creating project folder."));
    }
}


void MainWindow::onHelpRequested() {
    DescriptionWindow *description = new DescriptionWindow(this,ui->editor->modelDescription);
    description->show();


}

void MainWindow::runUnitTests()
{
    QTreeWidget *log = new QTreeWidget;
    log->resize(640,480);
    log->show();
    QList<QPair<QString, QString(*)(MainWindow*)> > tests = MainWindow_UnitTests::get_tests();
    for (QList<QPair<QString, QString(*)(MainWindow*)> >::iterator test = tests.begin();
         test != tests.end(); ++test) {
        QTreeWidgetItem *item = new QTreeWidgetItem(QStringList(test->first));
        log->addTopLevelItem(item);
        try {
            QString m = test->second(this);
            if (!m.isEmpty()) {
                QLabel *label = new QLabel(m);
                QTreeWidgetItem *textitem = new QTreeWidgetItem;
                item->addChild(textitem);
                item->setTextColor(0,QColor(192,128,0));
                label->setWordWrap(true);
                log->setItemWidget(textitem,0,label);
            }
        }
        catch (MainWindow_UnitTests::Error<> e) {
            QLabel *label = new QLabel(e.get());
            QTreeWidgetItem *textitem = new QTreeWidgetItem;
            item->addChild(textitem);
            item->setTextColor(0,QColor(255,0,0));
            label->setWordWrap(true);
            log->setItemWidget(textitem,0,label);
            break;
        }
    }
}


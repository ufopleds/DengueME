#include "editor.h"
#include "ui_editor.h"
#include "dengueme.h" //Namespace containing basic control and setting files

#include <QtCore>
#include <QtXml>
#include <QDebug>

Editor::Editor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Editor),
    editMode(true),
    interpreter(this)
{
    ui->setupUi(this);

    QPalette pallet;
    pallet.setColor(QPalette::Base,this->palette().window().color());
    ui->list->setPalette(pallet);

    //ui->list->setMaximumWidth(104 + qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent));
    connect(ui->list, SIGNAL(currentRowChanged(int)), ui->stack, SLOT(setCurrentIndex(int)));

    connect(&interpreter, SIGNAL(readyReadStandardOutput()), SLOT(readyReadStandardOutput()));
    connect(&interpreter, SIGNAL(readyReadStandardError()), SLOT(readyReadStandardError()));
    connect(&interpreter, SIGNAL(finished(int)), SLOT(onInterpreterFinished(int)));
    //    connect(&interpreter, SIGNAL(started()), SLOT());

    parametersGroup = new GroupList;
    view_model = new ModelView;
    view_database = new QFrame;
    {
        QWidget *cont = new QWidget;
        cont->setAutoFillBackground(true);
        cont->setBackgroundRole(QPalette::Base);

        view_database->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
        view_database->setLayout(new QVBoxLayout);
        view_database->layout()->addWidget(cont);
        view_database->layout()->setMargin(0);

        QVBoxLayout *layout = new QVBoxLayout(cont);
        QGroupBox *group = new QGroupBox(tr("Database"));
        QVBoxLayout *groupLayout = new QVBoxLayout(group);
        groupLayout->addWidget(this->database = new Database);

        enableDatabase = new QCheckBox(tr("Use database"));
        connect(enableDatabase, SIGNAL(toggled(bool)), group, SLOT(setVisible(bool)));
        group->setVisible(false);

        layout->addWidget(enableDatabase);
        layout->addWidget(group);
        layout->addStretch(1);
    }

    view_parameters = parametersGroup;

    view_simulation = new QFrame;
    {
        QWidget *cont = new QWidget;
        cont->setAutoFillBackground(true);
        cont->setBackgroundRole(QPalette::Base);

        view_simulation->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
        view_simulation->setLayout(new QVBoxLayout);
        view_simulation->layout()->setMargin(0);
        view_simulation->layout()->addWidget(cont);

        QVBoxLayout *layout = new QVBoxLayout(cont);
        layout->setMargin(0);
        simulationGroup = new Group;
        simulationGroup->setRemovable(false);
        simulationGroup->setLabel(tr("Simulation"));
        layout->addWidget(simulationGroup);

        ///TODO  - Observers

        QGroupBox *group = new QGroupBox(tr("Observer"));
        QVBoxLayout *groupLayout = new QVBoxLayout(group);
        groupLayout->addWidget(observer = new Observer);
        enableObserver = new QCheckBox(tr("Use observer"));
        connect(enableObserver, SIGNAL(toggled(bool)), group, SLOT(setVisible(bool)));
        group->setVisible(false);
        layout->addWidget(enableObserver);
        layout->addWidget(group);

        ///TODO - Observers

        layout->addStretch(1);
    }

    view_results = new QFrame;
    {
        QWidget *cont = new QWidget;
        cont->setAutoFillBackground(true);
        cont->setBackgroundRole(QPalette::Base);

        view_results->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
        view_results->setLayout(new QVBoxLayout);
        view_results->layout()->addWidget(cont);
        view_results->layout()->setMargin(0);


        QVBoxLayout *layout = new QVBoxLayout(cont);
        resultsGroup = new Group;
        resultsGroup->setRemovable(false);
        resultsGroup->setLabel("Results");
        resultsGroup->layout()->setMargin(0);

        enableResults = new QCheckBox(tr("Use results view"));
        layout->addWidget(enableResults);

        connect(enableResults, SIGNAL(toggled(bool)), resultsGroup, SLOT(setVisible(bool)));
        resultsGroup->setVisible(false);

        layout->addWidget(resultsGroup);
        layout->addStretch(1);
    }

    viewmap.insert(ViewModel,      ViewData(tr("Model"),      view_model));

    viewmap.insert(ViewDatabase,   ViewData(tr("Database"),   view_database));
    viewmap.insert(ViewParameters, ViewData(tr("Parameters"), view_parameters));
    viewmap.insert(ViewSimulation, ViewData(tr("Simulation"), view_simulation));
    viewmap.insert(ViewResults,    ViewData(tr("Results"),    view_results));

    ///TODO - Interpreter new Window
    ///IDEA - Show just model, add a OK button, after pressed get all the information and show the right views
    connect(view_model, SIGNAL(interpreterChanged(Interpreter)), SLOT(onInterpreterChanged(Interpreter)));
    ///TODO - Interpreter new Window

}

Editor::~Editor(){
    delete ui;
}

QString Editor::getModelFile(){
    return modelFile;
}

void Editor::setupViews(){
    ui->list->clear();
    for (QWidget *w = ui->stack->currentWidget(); w ; w = ui->stack->currentWidget())
        ui->stack->removeWidget(w);

    if (editMode) {
        foreach(ViewData x, viewmap)
            if (x.visibleEM)
                addView(x.name, x.widget);
    } else {
        foreach(ViewData x, viewmap)
            if (x.visible)
                addView(x.name, x.widget);
    }
}

void Editor::addView(QString name, QWidget *content){


    QListWidgetItem *item = new QListWidgetItem(ui->list);
    item->setIcon(QIcon(":/img/Resources/" + name.toLower() + ".png"));

    item->setText(name);
    item->setTextAlignment(Qt::AlignHCenter);
    item->setSizeHint(QSize(90,70));

    ui->list->addItem(item);
    ui->stack->addWidget(content);
}

void Editor::setEditModeEnabled(bool enable){
    editMode = enable;

    viewmap[ViewModel].visible = enable;

    resultsGroup->setEditMode(enable);
    parametersGroup->setEditMode(enable);
    simulationGroup->setEditMode(enable);
    enableResults->setVisible(enable);
    enableObserver->setVisible(enable && view_model->interpreter() == view_model->TerraME);
    enableDatabase->setVisible(enable);

    setupViews();
}

bool Editor::isRunning(){
    return interpreter.isOpen();
}

void Editor::stopModel(){
    interpreter.close();
}
QString Editor::loadDescription(QDomElement par){
    modelDescription += "";
    for (QDomElement node = par.firstChildElement(); !node.isNull(); node = node.nextSiblingElement()) {
        if (node.tagName().compare("groupbox", Qt::CaseInsensitive) == 0){
            for (QDomElement child = node.firstChildElement(); !child.isNull(); child = child.nextSiblingElement()) {
                if (child.nodeName() == "field") {
                    modelDescription+=child.attribute("label") + ": "+ child.attribute("description") + "\n";
                }
            }
        }
        else{
            modelDescription+=node.attribute("label") + ": "+ node.attribute("description") + "\n";

        }
    }
    return modelDescription;
}
///BUG
bool Editor::loadModel(QString filename, bool editMode){


    if(renameFlag==0){
        if (!modelFile.isEmpty() && !close(0)){
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Model already exists in your workspace!");
            messageBox.setFixedSize(500,200);
            return false;

        }
    }
    renameFlag =0;

    QFileInfo info(filename);
    QFile file(filename);

    if (!file.open(QFile::ReadOnly)){
        QMessageBox messageBox;
        messageBox.critical(0,"Error", "<b>Failed to open model. Please verify your model folder.</b>");
        messageBox.setFixedSize(500,200);
        return false;

    }

    modelXml.clear();
    if (!modelXml.setContent(&file)){
        QMessageBox messageBox;
        messageBox.critical(0,"Error ", "<b>Failed to create XML file. Please verify your model folder.</b>");
        messageBox.setFixedSize(500,200);
        return false;

    }
    modelDescription = "";
    modelFile = info.absoluteFilePath();

    emit renamed(modelFile);
    QDomElement root = modelXml.firstChildElement("xmlmodel");

    view_model->setScriptDir(info.absolutePath() + '/' + info.baseName() + "_scripts");
    view_model->setXml(root.firstChildElement("script"));
    
    QDomElement datEl = root.firstChildElement("Database");
    QDomElement par = root.firstChildElement("parameters");
    QDomElement sim = root.firstChildElement("simulation");
    QDomElement obsEl = root.firstChildElement("Observer");
    QDomElement res = root.firstChildElement("results");
    loadDescription(par);
    loadDescription(sim);
    viewmap[ViewDatabase].visible = !datEl.isNull();
    database->setXml(datEl);
    enableDatabase->setChecked(!datEl.isNull());



    parametersGroup->setXml(par);
    parametersGroup->scrollToTop();


    viewmap[ViewSimulation].visible = !sim.isNull() || !obsEl.isNull();
    sim.setAttribute("label", "Simulation");
    simulationGroup->setXml(sim);

    observer->setXml(obsEl);
    enableObserver->setChecked(!obsEl.isNull());

    viewmap[ViewResults].visible = !res.isNull();
    enableResults->setChecked(!res.isNull());
    res.setAttribute("label", "Results");
    resultsGroup->setXml(res);

    setEditModeEnabled(editMode);

    return true;
}

// Run
void Editor::execModel(bool stepByStep){
    if (modelFile.isEmpty())
        return;

    QFileInfo modelInfo(modelFile);
    QString model = modelInfo.baseName();
    QString dir = modelInfo.path();

    if (interpreter.isOpen())
        interpreter.kill();

    if (view_model->interpreter() == view_model->TerraME) {
        QFile input(dir + '/' + model + "_input.lua");
        input.open(QFile::WriteOnly | QFile::Truncate);
        QTextStream out(&input);

        //.replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n");
        out <<  "print(\'LOADING INPUT FILE AND RUNNING MODEL\')\n";
        out << "io.flush();\n";
        if (enableDatabase->isChecked())
            out << database->outData();

        if (enableObserver->isChecked())
            out << observer->outData();

        if (enableResults->isChecked())
            out << resultsGroup->genLua();

        out << parametersGroup->genLua();
        out << simulationGroup->genLua();

        out << "BASE_PATH = \"" + dir + "\"\n";
        out << "SCRIPT_PATH = \"" + view_model->scriptDir() + "\"\n";
        out << "dofile(SCRIPT_PATH .. \"/" << view_model->mainScript() << "\")\n";

        input.close();

        QStringList args;
        if(stepByStep)
            args << "-gui";

        args << input.fileName();

        interpreter.start(dengueme::config("terrame"), args);
    } else if (view_model->interpreter() == view_model->RScript) {
        QFile input(dir + '/' + model + "_input.r");
        input.open(QFile::WriteOnly | QFile::Truncate);
        QTextStream out(&input);

        if (enableResults->isChecked())
            out << resultsGroup->genR();

        out << parametersGroup->genR();
        out << simulationGroup->genR();

        out << "BASE_PATH = \"" + dir + "\"\n";
        out << "SCRIPT_PATH =\"" + view_model->scriptDir() + "\"\n";
        out << "source(paste0(SCRIPT_PATH, \"/" << view_model->mainScript() << "\"))\n";

        input.close();

        QStringList args;
        args << input.fileName();

        interpreter.start(dengueme::config("rscript"), args);
    }

    if (! interpreter.waitForStarted()) {
        emit output(3, "Failed to start interpreter.");
        return;
    }

    emit interpreterStarted();
}

void Editor::updateModelInfo(QString newPath){
    modelFile = newPath;
    renameFlag = 1;
}

bool Editor::close(int del){
    if (modelFile.isEmpty()) return true;

    if(del==1){
        emit closed();
        return true;
    }
    if(del==2){
        clearModel();
        return true;
    }
    QMessageBox::StandardButton opt = QMessageBox::question(this, tr("Close model"),
                                                            tr("Save model before closing?"),
                                                            QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    switch (opt) {
    case QMessageBox::Cancel:
        return false;

    case QMessageBox::Save:
        save();

        //Fallthrough
    case QMessageBox::Discard:
        clearModel();
        return true;

    default:
        return false;
    }
}

void Editor::clearModel(){
    modelFile.clear();
    ui->list->clear();

    for (QWidget *w = ui->stack->currentWidget(); w ; w = ui->stack->currentWidget())
        ui->stack->removeWidget(w);

    emit closed();
}

bool Editor::save(){
    if (modelFile.isEmpty())
        return false;

    QFile file(modelFile);
    if (!file.open(QFile::WriteOnly | QFile::Truncate)) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to save model."));
        return false;
    }

    QDomDocument doc;
    QDomElement root = doc.createElement("xmlmodel");

    root.appendChild(view_model->getXml());
    root.appendChild(parametersGroup->getXml());

    QDomDocument sim = simulationGroup->getXml();
    sim.firstChildElement().setTagName("simulation");
    root.appendChild(sim);


    if (enableResults->isChecked()) {
        QDomDocument res = resultsGroup->getXml();
        QDomElement resr = res.firstChildElement();
        if (!resr.isNull()) {
            resr.setTagName("results");
            root.appendChild(res);
        }
    }

    if (enableDatabase->isChecked())
        root.appendChild(database->getXml());

    if (enableObserver->isChecked())
        root.appendChild(observer->getXml());

    doc.appendChild(root);

    QTextStream out(&file);
    doc.save(out, 2);

    return true;
}

bool Editor::saveAs(){
    if (modelFile.isEmpty())
        return false;

    QFileInfo fileinfo(modelFile);
    QString name = QFileDialog::getSaveFileName(this, "Save as...", fileinfo.path(), "*.xml");
    if (name.isNull())
        return false;

    modelFile = name;
    emit renamed(modelFile);
    return save();
}

void Editor::readyReadStandardError(){
    emit output (3, interpreter.readAllStandardError());
}

void Editor::readyReadStandardOutput(){
    emit output (1, interpreter.readAllStandardOutput());
}

//Interpreter Functions - TerraME or R
///TODO - R Interpreter
void Editor::onInterpreterFinished(int exitCode){
    interpreter.close();
    emit interpreterStopped(exitCode);
}
/// TODO - INTERPRETER DINAMIC WINDOW
void Editor::onInterpreterChanged(ModelView::Interpreter intr)
{
    if (intr == ModelView::TerraME) {
        enableObserver->setVisible(editMode);
        viewmap[ViewDatabase].visible = true;
        viewmap[ViewDatabase].visibleEM = true;

    } else {
        enableObserver->setChecked(false);
        enableObserver->setVisible(false);
        viewmap[ViewDatabase].visible = false;
        viewmap[ViewDatabase].visibleEM = false;
    }
    setupViews();
}
///TODO - R Interpreter

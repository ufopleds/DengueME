#include <QtCore>
#include <QtXml>

#include "editor.h"
#include "ui_editor.h"
#include "dengueme.h"

Editor::Editor(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Editor),
  editMode(true),
  interpreter(this) {

  ui->setupUi(this);

  QPalette pallet;
  pallet.setColor(QPalette::Base, this->palette().window().color());
  ui->list->setPalette(pallet);

  connect(ui->list, SIGNAL(currentRowChanged(int)), ui->stack, SLOT(setCurrentIndex(int)));
  connect(&interpreter, SIGNAL(readyReadStandardOutput()), SLOT(readyReadStandardOutput()));
  connect(&interpreter, SIGNAL(readyReadStandardError()), SLOT(readyReadStandardError()));
  connect(&interpreter, SIGNAL(finished(int)), SLOT(onInterpreterFinished(int)));

  parametersGroup = new GroupList;
  resultsGroup = new ObserversList;
  view_model = new ModelView;
  view_database = new QFrame;
  {
    QWidget* cont = new QWidget;
    cont->setAutoFillBackground(true);
    cont->setBackgroundRole(QPalette::Base);

    view_database->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    view_database->setLayout(new QVBoxLayout);
    view_database->layout()->addWidget(cont);
    view_database->layout()->setMargin(0);

    QVBoxLayout* layout = new QVBoxLayout(cont);
    QGroupBox* group = new QGroupBox(tr("Database"));
    QVBoxLayout* groupLayout = new QVBoxLayout(group);

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
    QWidget* cont = new QWidget;
    cont->setAutoFillBackground(true);
    cont->setBackgroundRole(QPalette::Base);

    view_simulation->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    view_simulation->setLayout(new QVBoxLayout);
    view_simulation->layout()->setMargin(0);
    view_simulation->layout()->addWidget(cont);

    QVBoxLayout* layout = new QVBoxLayout(cont);
    layout->setMargin(0);
    simulationGroup = new Group;

    layout->addWidget(simulationGroup);
    layout->addStretch(1);

  }

  view_results = resultsGroup;

  viewmap.insert(ViewModel,      ViewData(tr("Model"), "model",    view_model));
  viewmap.insert(ViewDatabase,   ViewData(tr("Database"),  "database", view_database));
  viewmap.insert(ViewParameters, ViewData(tr("Parameters"), "parameters", view_parameters));
  viewmap.insert(ViewSimulation, ViewData(tr("Simulation"), "simulation", view_simulation));
  viewmap.insert(ViewResults,    ViewData(tr("Results"),  "results",  view_results));

  connect(view_model, SIGNAL(interpreterChanged(Interpreter)), SLOT(onInterpreterChanged(Interpreter)));
}

Editor::~Editor() {
  delete ui;
}

QString Editor::getModelFile() {
  return modelFile;
}

void Editor::setupViews() {

  ui->list->clear();
  for (QWidget* w = ui->stack->currentWidget(); w ; w = ui->stack->currentWidget())
    ui->stack->removeWidget(w);

  if (editMode) {
    foreach(ViewData x, viewmap)
      if (x.visibleEM)
        addView(x.variableName, x.widget, x.name);
  } else {
    foreach(ViewData x, viewmap)
      if (x.visible)
        addView(x.variableName, x.widget, x.name);
  }
}

void Editor::addView(QString variableName, QWidget* content, QString name) {

  QListWidgetItem* item = new QListWidgetItem(ui->list);
  item->setIcon(QIcon(":/img/Resources/" + variableName + ".png"));

  item->setText(name);
  item->setTextAlignment(Qt::AlignHCenter);
  item->setSizeHint(QSize(90, 70));

  ui->list->addItem(item);
  ui->stack->addWidget(content);
}

void Editor::setEditModeEnabled(bool enable) {
  editMode = enable;
  viewmap[ViewModel].visible = enable;
  parametersGroup->setEditMode(enable);
  simulationGroup->setEditMode(enable);
  simulationGroup->setRemovable(false);
  resultsGroup->setEditMode(enable);
  enableDatabase->setVisible(enable);
  setupViews();
}

bool Editor::isRunning() {
  return interpreter.isOpen();
}

void Editor::stopModel() {
  interpreter.close();
}
QString Editor::loadDescription(QDomElement par) {
  modelDescription += "";
  for (QDomElement node = par.firstChildElement(); !node.isNull(); node = node.nextSiblingElement()) {
    if (node.tagName().compare("groupbox", Qt::CaseInsensitive) == 0) {
      for (QDomElement child = node.firstChildElement(); !child.isNull(); child = child.nextSiblingElement()) {
        if (child.nodeName() == "field") {
          modelDescription += child.attribute("label") + ": " + child.attribute("description") + "\n";
        }
      }
    } else {
      modelDescription += node.attribute("label") + ": " + node.attribute("description") + "\n";

    }
  }
  return modelDescription;
}

bool Editor::loadModel(QString filename, bool editMode) {

  if(renameFlag == 0) {
    if (!modelFile.isEmpty() && !close(0)) {
      return false;
    }
  }
  renameFlag = 0;

  QFileInfo info(filename);
  QFile file(filename);

  if (!file.open(QFile::ReadOnly)) {
    QMessageBox messageBox;
    messageBox.critical(0, "Error", "<b>Failed to open model. Please verify your model folder.</b>");
    messageBox.setFixedSize(500, 200);
    return false;
  }

  modelXml.clear();
  if (!modelXml.setContent(&file)) {
    QMessageBox messageBox;
    messageBox.critical(0, "Error ", "<b>Failed to create XML file. Please verify your model folder.</b>");
    messageBox.setFixedSize(500, 200);
    return false;
  }
  modelDescription = "";
  modelFile = info.absoluteFilePath();

  emit renamed(modelFile);
  QDomElement root = modelXml.firstChildElement("xmlmodel");

  view_model->setScriptDir(info.absolutePath() + '/' + info.baseName() + "_scripts");
  view_model->setXml(root.firstChildElement("model"));

  QDomElement datEl = root.firstChildElement("Database");
  QDomElement par = root.firstChildElement("parameters");
  QDomElement sim = root.firstChildElement("simulation");
  QDomElement res = root.firstChildElement("results");

  loadDescription(par);
  loadDescription(sim);

  viewmap[ViewDatabase].visible = !datEl.isNull();
  enableDatabase->setChecked(!datEl.isNull());

  parametersGroup->setXml(par);
  parametersGroup->scrollToTop();

  viewmap[ViewSimulation].visible = !sim.isNull() ;
  sim.setAttribute("label", "Simulation");
  simulationGroup->setXml(sim);
  simulationGroup->setRemovable(false);

  viewmap[ViewResults].visible = !res.isNull();
  res.setAttribute("label", "Results");
  resultsGroup->setXml(res);

  setEditModeEnabled(editMode);

  return true;
}


void Editor::execModel(bool stepByStep) {

  if (modelFile.isEmpty())
    return;

  QFileInfo modelInfo(modelFile);
  QString model = modelInfo.baseName();
  QString dir = modelInfo.path();

  if (view_model->interpreter() == view_model->TerraME) {
    QFile input(dir + '/' + model + "_input.lua");
    input.open(QFile::WriteOnly | QFile::Truncate);
    QTextStream out(&input);
    out << "-- INPUT FILE\n";
    out <<  "print(\'LOADING INPUT FILE AND RUNNING MODEL\')\n";
    out << "io.flush();\n";

    out << "\n-- PATH CONFIG \n";
    out << "BASE_PATH = \"" + dir + "\"\n";
    out << "SCRIPT_PATH = \"" + view_model->scriptDir() + "\"\n";
    out << "RESULTS_PATH = BASE_PATH\n";

    out << "\n-- PARAMETERS \n";
    out << parametersGroup->genLua();
    out << "\n-- SIMULATION  \n";
    out << simulationGroup->genLua();
    out << "\n-- RESULTS \n";
    out << resultsGroup->genLua();
    out << "\n-- LOADING MODEL  \n";
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

    out << "# INPUT FILE\n";
    out <<  "print(\'LOADING INPUT FILE AND RUNNING MODEL\')\n";

    out << "\n# DEPENDENCIES\n";
    out << "MODEL_RVERSION <- " << "\"3.4.1\"" << "\n";
    out << "DEPENDENCIES <- " << "data.frame(lib = c(\"deSolve\"), version = c(\"1.20\"), stringsAsFactors = F)\n";

    out << "\n# PATH CONFIG\n";
    out << "MODEL_PATH <- \"" + DEFAULT_MODELS_DIR + "\"\n";
    out << "BASE_PATH <- \"" + dir + "\"\n";
    out << "SCRIPT_PATH <- \"" + view_model->scriptDir() + "\"\n";
    out << "RESULTS_PATH <- BASE_PATH\n";

    out << "\n# checking dependencies\n";
    out << "USER_RVERSION <- package_version(R.version)\n";
    out << "USER_PACKINFO <- installed.packages(fields = c(\"Package\", \"Version\"))\n";
    out << "source(paste0(MODEL_PATH, \"dmelib.r\"))\n";
    out << "dmelib_check_dependencies(modelRVersion = MODEL_RVERSION, modelDependences = DEPENDENCIES, userRVersion = USER_RVERSION, userLibs = USER_PACKINFO)\n";



    out << "\n# PARAMETERS\n";
    out << parametersGroup->genR();

    out << "\n# SIMULATION\n";
    out << simulationGroup->genR();

    out << "\n# RESULTS";
    out << resultsGroup->genR();

    out << "\n# LOADING MODEL  \n";
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

void Editor::updateModelInfo(QString newPath) {
  modelFile = newPath;
  renameFlag = 1;
}

bool Editor::close(int del) {
  if (modelFile.isEmpty()) return true;

  if(del == 1) {
    emit closed();
    return true;
  }
  if(del == 2) {
    clearModel();
    return true;
  }

  QMessageBox msgBox(
    QMessageBox::Question,
    tr("Close model"),
    tr("Save model before closing?"),
    QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

  msgBox.setButtonText(QMessageBox::Save, trUtf8("Save"));
  msgBox.setButtonText(QMessageBox::Discard, trUtf8("Discard"));
  msgBox.setButtonText(QMessageBox::Cancel, trUtf8("Cancel"));
  switch (msgBox.exec()) {
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

void Editor::clearModel() {
  modelFile.clear();
  ui->list->clear();

  for (QWidget* w = ui->stack->currentWidget(); w ; w = ui->stack->currentWidget())
    ui->stack->removeWidget(w);

  emit closed();
}

bool Editor::save() {
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

  root.appendChild(resultsGroup->getXml());


  doc.appendChild(root);

  QTextStream out(&file);
  doc.save(out, 2);

  return true;
}

bool Editor::saveAs() {
  if (modelFile.isEmpty())
    return false;

  QFileInfo fileinfo(modelFile);
  QString name = QFileDialog::getSaveFileName(this, tr("Save as..."), fileinfo.path(), "*.xml");
  if (name.isNull())
    return false;

  modelFile = name;
  emit renamed(modelFile);
  return save();
}

void Editor::readyReadStandardError() {
  emit output (3, interpreter.readAllStandardError());
}

void Editor::readyReadStandardOutput() {
  emit output (1, interpreter.readAllStandardOutput());
}

void Editor::onInterpreterFinished(int exitCode) {

  if(exitCode == 0 && interpreter.exitStatus() == QProcess::NormalExit)
    emit output(1, "SIMULATION FINISHED");
  interpreter.close();
  emit interpreterStopped(exitCode);
}

void Editor::onInterpreterChanged(ModelView::Interpreter intr) {
  if (intr == ModelView::TerraME) {

    viewmap[ViewDatabase].visible = true;
    viewmap[ViewDatabase].visibleEM = true;

  } else {

    viewmap[ViewDatabase].visible = false;
    viewmap[ViewDatabase].visibleEM = false;
  }
  setupViews();
}


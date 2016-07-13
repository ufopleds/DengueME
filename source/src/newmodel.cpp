#include <QtCore>
#include <QtGui>

#include "dengueme.h"
#include "newmodel.h"
#include "newproject.h"


#include <QDebug>
NewModel::NewModel(QString workspace, QString project, QWidget *parent) :
    QWizard(parent)
{
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    addPage(new TypePage());
    addPage(new ProjectPage(workspace, project));
    addPage(new NamePage(workspace));
    setWindowTitle(tr("New model"));
}

void NewModel::accept()
{
    QString category = property("category").toString();
    QString type = property("type").toString();
    QString project = property("project").toString();
    QString name = field("name").toString();



    emit accepted(category,type,project,name);
    QWizard::accept();
}

TypePage::TypePage() {
    setTitle(tr("Type"));
    setSubTitle(tr("Specify the type of the new model"));
//    setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/ok.png"));

    QList<QPair<QString, QStringList> > modelTypes = dengueme::model_types();

    for (int i = 0; i < modelTypes.size(); ++i)
        models.types.append(modelTypes[i].first);

    for (int i = 0; i < modelTypes.size(); ++i)
        models.names.append(modelTypes[i].second);


    modelType = new QTreeWidget;
    modelName = new QListWidget;

    QTreeWidgetItem *type = new QTreeWidgetItem(QStringList(tr("Model")));
    type->setFlags(Qt::ItemIsEnabled);
    type->setBackground(0,QBrush(palette().color(QPalette::Background)));
    type->setSizeHint(0,QSize(-1,20));
    modelType->addTopLevelItem(type);

    foreach(QString c, models.types) {
        QTreeWidgetItem *item = new QTreeWidgetItem(QStringList(c));
        item->setSizeHint(0,QSize(-1,20));
        type->addChild(item);
    }

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(modelType);
    layout->addWidget(modelName);
    setLayout(layout);

    connect(modelType, SIGNAL(itemSelectionChanged()), SLOT(itemChanged()));
    connect(modelType, SIGNAL(clicked(QModelIndex)), SLOT(itemClicked()));
    connect(modelName, SIGNAL(currentTextChanged(QString)), SLOT(nameSelected(QString)));

    connect(modelType, SIGNAL(collapsed(QModelIndex)), modelType, SLOT(expand(QModelIndex)));

    modelType->setIndentation(4);
    modelType->setRootIsDecorated(false);
    modelType->setHeaderHidden(true);
    modelType->expandAll();
}

bool TypePage::isComplete() const {

    return !modelName->selectedItems().isEmpty();
}

void TypePage::itemChanged() {
    modelName->clear();
    QList<QTreeWidgetItem *> selected = modelType->selectedItems();
    if (!selected.isEmpty()) {
        wizard()->setProperty("category", selected.first()->text(0));

        QString cl = selected.first()->parent()->text(0);
        int i;
        QList<QStringList> names;


            names = models.names;
            i = models.types.indexOf(selected.first()->text(0));


        wizard()->setProperty("class", cl);

        if (i >= 0 && i < names.size()) {
            foreach(QString t, names.at(i)) {
                QListWidgetItem *item = new QListWidgetItem(t);
                item->setSizeHint(QSize(-1,20));
                modelName->addItem(item);
            }
            QListWidgetItem *item = modelName->item(0);
            if (item)
                item->setSelected(true);
        }
    }
}

void TypePage::itemClicked() {
    if (!modelType->selectedItems().isEmpty())
        modelName->setFocus();
}

void TypePage::nameSelected(QString item) {
    wizard()->setProperty("type", item);
    emit completeChanged();
}

ProjectPage::ProjectPage(QString workspace, QString project)
    : workspace(workspace),
      project(project)
{
    setTitle(tr("Project"));
    setSubTitle(tr("Specify the project where the model will be created."));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/error.png"));

    projects = new QListWidget;

    newproject = new QPushButton(tr("New project"));
    connect(newproject, SIGNAL(clicked()), SLOT(newProject()));

    loadWorkspace();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->addWidget(projects);
    layout->addWidget(newproject,0,Qt::AlignRight);
    setLayout(layout);

    connect(projects, SIGNAL(itemSelectionChanged()), SLOT(itemChanged()));
}

bool ProjectPage::isComplete() const {
    if (!projects->selectedItems().isEmpty()) {
        wizard()->setProperty("project", projects->selectedItems().first()->text());
        return true;
    } else
        return false;
}

void ProjectPage::itemChanged() {
    emit completeChanged();
}

void ProjectPage::newProject()
{
    newproject->hide();
    projects->hide();

    NewProject *n = new NewProject(workspace,this);
    if (n->exec()) {
        QString name = n->field("name").toString();
        QDir dir(workspace + QDir::separator() + name);
        if (dir.mkpath(dir.absolutePath())) {
            loadWorkspace();
            QList<QListWidgetItem*> items = projects->findItems(name, Qt::MatchCaseSensitive);
            if (!items.isEmpty()) items.at(0)->setSelected(true);
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Failed to create project folder."));
        }
    }
    newproject->show();
    projects->show();
}

void ProjectPage::loadWorkspace()
{
    projects->clear();
    QDir dir(workspace);
    foreach(QFileInfo x, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        QListWidgetItem *item = new QListWidgetItem(x.fileName());
        item->setSizeHint(QSize(-1,20));
        projects->addItem(item);
        if (x.fileName() == project)
            item->setSelected(true);
    }

    if (project.isEmpty() && projects->count() > 0) projects->itemAt(0,0)->setSelected(true);
}

NamePage::NamePage(QString workspace)
    : subtitle(tr("Specify a unique name to identify your project in the workspace.")),
      workspace(workspace),
      state(dengueme::EmptyName)
{

    setTitle(tr("Specify a name"));
    setSubTitle(subtitle);
    setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/error.png"));

    modelName = new QLabel(tr("&Name:"));
    projectLineEdit = new QLineEdit;
    modelName->setBuddy(projectLineEdit);

    connect(projectLineEdit, SIGNAL(textChanged(QString)), this, SLOT(validateProject(QString)));

    registerField("name*", projectLineEdit);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(modelName, 0, 0);
    layout->addWidget(projectLineEdit, 0, 1);
    setLayout(layout);
    projectLineEdit->setFocus();

}

void NamePage::validateProject(QString name) {
    QString path = workspace + QDir::separator() + wizard()->property("project").toString();
    switch (dengueme::validateName(path, name, ".xml")) {
    case dengueme::EmptyName:
        if (state != dengueme::EmptyName) {
            setSubTitle(subtitle);
            state = dengueme::EmptyName;
            setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/error.png"));
        }
        break;

    case dengueme::UnallowedChar:
        projectLineEdit->setText(dengueme::purgeName(name));
        QToolTip::showText(projectLineEdit->mapToGlobal(QPoint(0, projectLineEdit->height())),
                           tr("The project name can contain only\nalphanumeric chars, hyphen (-),"
                              " \nunderscore (_) and dot (.)."));
        break;

    case dengueme::FileExists:
        if (state != dengueme::FileExists) {
            state = dengueme::FileExists;
            setSubTitle(tr("A file with that name already exists."));
            setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/error.png"));
        }
        break;

    case dengueme::ValidName:
        if (state != dengueme::ValidName) {
            setSubTitle(subtitle);
            state = dengueme::ValidName;
            setPixmap(QWizard::LogoPixmap, QPixmap(":/img/Resources/ok.png"));
        }
        break;
    }
}

void NamePage::setWorkspace(QString path)
{
    workspace = path;
}

bool NamePage::isComplete() const {
    return state == dengueme::ValidName;
}

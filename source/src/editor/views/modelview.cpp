#include "dengueme.h"
#include "modelview.h"
#include "ui_modelview.h"

struct FileInfo : QWidget {
    QLineEdit *path;
    QToolButton *remove;
    QString oldPath;
    FileInfo() {
        resize(0,40);
        QHBoxLayout *layout = new QHBoxLayout(this);

        path = new QLineEdit;
        path->setFrame(false);
        path->setStyleSheet("background:transparent;");
        layout->addWidget(path);

        remove = new QToolButton;
        remove->setAutoRaise(true);
        remove->setIcon(QIcon(":/Resources/delete.png"));
        layout->addWidget(remove);
    }
};

ModelView::ModelView(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ModelView)
{
    ui->setupUi(this);
    setBackgroundRole(QPalette::Base);

    connect(ui->buttonAdd, SIGNAL(clicked()), SLOT(addFile()));
    connect(ui->interpreter, SIGNAL(currentIndexChanged(int)), SLOT(onInterpreterChanged(int)));
}

ModelView::~ModelView()
{
    delete ui;
}

void ModelView::setScriptDir(QString dir)
{
    QDir().mkpath(dir);
    _scriptDir = dir;
}

QString ModelView::scriptDir()
{
    return _scriptDir;
}
//XML TIAGO
QDomDocument ModelView::getXml()
{
    QDomDocument doc;
    QDomElement root = doc.createElement("script");
    root.setAttribute("interpreter", ui->interpreter->currentText());

    for (int i = 0; i < ui->list->count(); ++i) {
        FileInfo *fi = dynamic_cast<FileInfo *>(ui->list->itemWidget(ui->list->item(i)));
        if (fi == NULL) continue;

        QDomElement file = doc.createElement("file");
        file.appendChild(doc.createTextNode(fi->path->text()));
        root.appendChild(file);
    }


    QDomElement main = doc.createElement("main");
    main.appendChild(doc.createTextNode(ui->mainFile->currentText()));
    root.appendChild(main);


    QDomElement cat = doc.createElement("modelcategory");
    cat.appendChild(doc.createTextNode(ui->modelInfo->text()));
    root.appendChild(cat);
    QDomElement type = doc.createElement("modeltype");
    type.appendChild(doc.createTextNode( ui->modelType->text()));
    root.appendChild(type);

    doc.appendChild(root);
    return doc;
}
//XML TIAGO
void ModelView::setXml(QDomElement node)
{
    ui->list->clear();
    ui->mainFile->clear();
    for (QDomElement file = node.firstChildElement("file");
         !file.isNull(); file = file.nextSiblingElement("file")) {
        addItem(file.text());
    }
    ui->interpreter->setCurrentIndex(ui->interpreter->findText(node.attribute("interpreter")));
    ui->mainFile->setCurrentIndex(ui->mainFile->findText(node.firstChildElement("main").text()));
    ui->modelInfo->setText(node.firstChildElement("modelcategory").text());
    ui->modelType->setText(node.firstChildElement("modeltype").text());
}

ModelView::Interpreter ModelView::interpreter()
{
    if (ui->interpreter->currentIndex() == 1)
        return RScript;
    else
        return TerraME;
}

QStringList ModelView::scripts()
{
    QStringList ret;
    for (int i = 0; i < ui->mainFile->count(); ++i)
        ret.append(_scriptDir + '/' + ui->mainFile->itemText(i));
    return ret;
}

QString ModelView::mainScript()
{
    return ui->mainFile->currentText();
}

void ModelView::addItem(QString fileName)
{
    QListWidgetItem *item = new QListWidgetItem;
    FileInfo *fi = new FileInfo;
    fi->path->setText(fileName.replace("\\","/"));
    fi->oldPath = fileName.replace("\\","/");
    item->setSizeHint(fi->size());

    ui->list->addItem(item);
    ui->list->setItemWidget(item, fi);

    map[fi->remove] = item;
    map[fi->path] = item;
    connect(fi->remove, SIGNAL(clicked()), SLOT(removeFile()));
    connect(fi->path, SIGNAL(editingFinished()), SLOT(renameFile()));

    if (!QFileInfo(_scriptDir + "/" + fileName).exists()) {
        fi->path->setDisabled(true);
        fi->setToolTip(tr("File not found."));
    } else {
        ui->mainFile->addItem(fileName);
    }
    ui->modelInfo->setText(dengueme::getProjectType());
    ui->modelType->setText (ui->mainFile->currentText().remove(ui->mainFile->currentText().indexOf('.'),4));

}

void ModelView::addFile()
{
    if (_scriptDir.isEmpty()) return;

    QString path(QFileDialog::getOpenFileName(0,"Model","","Model script (*.lua *.r)"));

    if (path.isEmpty()) return;

    QString fileName = QFileInfo(path).fileName();
    QString dest = _scriptDir + "/" + fileName;
    if (ui->mainFile->findText(fileName, Qt::MatchFixedString) != -1) {
        QMessageBox::critical(this, tr("Error"), tr("A file with that name already exists."));
        return;
    }

    if (!dengueme::remove(dest) || !dengueme::copyFile(path, dest)) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to copy file."));
        return;
    }

    addItem(fileName);
}

void ModelView::removeFile()
{
    if (_scriptDir.isEmpty()) return;

    QObject *wid = QObject::sender();
    if (!map.contains(wid)) return;

    FileInfo *fi = dynamic_cast<FileInfo *>(ui->list->itemWidget(map.value(wid)));
    if (fi == NULL) return;

    ui->mainFile->removeItem(ui->mainFile->findText(fi->path->text()));

    QFile(_scriptDir + "/" + fi->path->text()).remove();

    delete ui->list->takeItem(ui->list->row(map.value(wid)));
}

void ModelView::renameFile()
{
    if (_scriptDir.isEmpty()) return;

    QObject *wid = QObject::sender();
    if (!map.contains(wid)) return;

    FileInfo *fi = dynamic_cast<FileInfo *>(ui->list->itemWidget(map.value(wid)));
    if (fi == NULL) return;

    QString from = _scriptDir + "/" + fi->oldPath;
    QString to = _scriptDir + "/" + fi->path->text();

    QDir dir;
    if (!dir.mkpath(QFileInfo(to).path()))
        fi->path->setText(fi->oldPath);

    if (ui->mainFile->findText(fi->path->text() + "/", Qt::MatchStartsWith | Qt::MatchFixedString) == -1
         && ui->mainFile->findText(fi->path->text(), Qt::MatchFixedString) == -1
         && !dengueme::remove(to)) {
        fi->path->setText(fi->oldPath);
        return;
    }

    if (!QFile::rename(from, to)) {
        fi->path->setText(fi->oldPath);
        return;
    }

    ui->mainFile->setItemText(ui->mainFile->findText(fi->oldPath), fi->path->text());
    fi->oldPath = fi->path->text();
}

void ModelView::onInterpreterChanged(int r)
{
    if (r == 1)
        emit interpreterChanged(RScript);
    else
        emit interpreterChanged(TerraME);
}

#include "dengueme.h"
#include "importcsv.h"
#include "ui_importcsv.h"

ImportCsv::ImportCsv(QWidget *parent) :
    Component(parent),
    ui(new Ui::ImportCsv)
{
    ui->setupUi(this);

    connect(ui->importButton, SIGNAL(clicked()), this, SLOT(openCsv()));

    QMenu *menu = new QMenu(this);

    QAction *actionBoolean = new QAction(tr("&Boolean"),menu);
    QAction *actionText     = new QAction(tr("&Text"),menu);
    QAction  *actionInteger  = new QAction(tr("&Integer"),menu);
    QAction *actionFloating = new QAction(tr("&Floating point"),menu);
    QAction *actionCombobox = new QAction(tr("C&ombobox"),menu);
    QAction *actionCsv = new QAction(tr("Csv"),menu);
    QAction *actionClone = new QAction(tr("Clone"),menu);


    actionCsv->setCheckable(true);
    actionBoolean->setCheckable(true);
    actionText->setCheckable(true);
    actionInteger->setCheckable(true);
    actionFloating->setCheckable(true);
    actionCombobox->setCheckable(true);

    menu->addAction(actionCsv);
    menu->addAction(actionBoolean);
    menu->addAction(actionText);
    menu->addAction(actionInteger);
    menu->addAction(actionFloating);
    menu->addAction(actionCombobox);




    ui->options->setMenu(menu);

    //connect(actionCsv, SIGNAL(triggered()), SLOT(onActionCsv()));
    connect(actionText,     SIGNAL(triggered()), SLOT(onMorphText()));
    connect(actionInteger,  SIGNAL(triggered()), SLOT(onMorphInteger()));
    connect(actionFloating, SIGNAL(triggered()), SLOT(onMorphFloat()));
    connect(actionCombobox, SIGNAL(triggered()), SLOT(onMorphCombobox()));
    connect(actionBoolean, SIGNAL(triggered()), SLOT(onMorphBoolean()));
    connect(ui->toolDelete,   SIGNAL(clicked()), SLOT(onActionDelete()));
     connect(ui->toolClone,   SIGNAL(clicked()), SLOT(onActionClone()));

     ui->toolOptions->setEnabled(false);
     ui->toolOptions->setToolTip("Options");
     ui->toolDelete->setToolTip("Delete");
     ui->toolClone->setToolTip("Clone");
    ui->options->setMenu(menu);
}


ImportCsv::~ImportCsv()
{
    delete ui;
}

QDomDocument ImportCsv::getXml()
{
    QDomDocument doc;
    QDomElement root = doc.createElement("csv");
    root.setAttribute("id", ui->var->text());
    root.setAttribute("label", ui->label->text());
    root.appendChild(doc.createTextNode(ui->textEdit->toPlainText()));
    doc.appendChild(root);
    return doc;
}

void ImportCsv::setXml(QDomElement node)
{
    ui->var->setText(node.attribute("id"));
    ui->label->setText(node.attribute("label"));
    ui->textEdit->setText(node.text());
}

void ImportCsv::setEditMode(bool enable)
{
    ui->options->setVisible(enable);
    ui->var->setVisible(enable);
    ui->line->setVisible(enable);
    ui->label->setReadOnly(!enable);

    if (enable) {
        ui->textEdit->setToolTip("Default value");
        ui->label->setToolTip("Label");
    } else {
        ui->textEdit->setToolTip("");
        ui->label->setToolTip("");
    }
}

QString ImportCsv::genLua()
{
    QString ret = ui->var->text() + " = {";
    ret += ui->textEdit->toPlainText().replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n");
    ret += "}\n";
    return ret;
}

QString ImportCsv::genR()
{
    QString ret = ui->var->text() + " = c(";
    ret += ui->textEdit->toPlainText().replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n");
    ret += ")\n";
    return ret;
}

void ImportCsv::openCsv()
{
    QFileDialog::Options options;
    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Opening  CSV file"),
                                                    "",
                                                    tr("CSV Files (*.csv)"),
                                                    &selectedFilter,
                                                    options);
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Truncate)) {

            QString str;
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                str += line;
            }
            ui->textEdit->setText(str);

        } else {
            QMessageBox::information(this, tr("Error"),
                                     tr("Error opening file."));
        }
    }
}

void ImportCsv::onMorphBoolean( )
{
    emit remove();
    emit csv( "Boolean");
}
void ImportCsv::onMorphText( )
{
    emit remove();
    emit csv( "Text");
}
void ImportCsv::onMorphInteger( )
{
    emit remove();
    emit csv( "Integer");
}
void ImportCsv::onMorphFloat( )
{
    emit remove();
    emit csv( "Float");
}
void ImportCsv::onMorphCombobox( )
{
    emit remove();
    emit csv( "Combobox");
}

void ImportCsv::onActionClone(){
    emit clone();
}
void ImportCsv::onActionDelete( )
{

    int opt = QMessageBox::question(this,tr("Remove Field"),
                                    "This action will remove this field. Do you want to continue?",
                                    QMessageBox::Yes | QMessageBox::No);

    if(opt == QMessageBox::Yes){
        emit remove();
    }

}


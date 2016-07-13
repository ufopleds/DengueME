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
    QAction *del = new QAction("&Delete", menu);

    menu->addAction(del);

    connect(del, SIGNAL(triggered()), SLOT(onActionDelete()));

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
                                                    tr("Opening Temperature CSV file"),
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

void ImportCsv::onActionDelete()
{
    emit remove();
}


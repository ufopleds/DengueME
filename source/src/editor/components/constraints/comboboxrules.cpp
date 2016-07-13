#include <limits>
#include <QtXml>

#include "comboboxrules.h"
#include "ui_comboboxrules.h"

ComboBoxRules::ComboBoxRules(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComboBoxRules)
{
    ui->setupUi(this);

    connect(ui->add, SIGNAL(clicked()), SLOT(add()));
    connect(ui->del, SIGNAL(clicked()), SLOT(del()));
}

ComboBoxRules::~ComboBoxRules() {
    delete ui;
}

QList<QString> ComboBoxRules::items()
{
    QList<QString> ret;
    for (int i = 0; i < ui->list->count(); ++i)
        if (!ret.contains(ui->list->item(i)->text()))
            ret.append(ui->list->item(i)->text());
    return ret;
}

void ComboBoxRules::setItems(QList<QString> items)
{
    ui->list->clear();
    foreach(QString x, items) {
        QListWidgetItem *item = new QListWidgetItem(x);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        ui->list->addItem(item);
    }
}

void ComboBoxRules::add()
{
    QListWidgetItem *item = new QListWidgetItem("New item");
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->list->addItem(item);
    ui->list->scrollToItem(item);
    item->setSelected(true);
    ui->list->setFocus();
    ui->list->editItem(item);
}

void ComboBoxRules::del()
{
    delete ui->list->takeItem(ui->list->currentRow());
}


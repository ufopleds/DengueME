#include "visualtablefield.h"
#include "ui_visualtablefield.h"

VisualTableField::VisualTableField(QWidget* parent) :
  Component(parent),
  widget(NULL),
  ui(new Ui::VisualTableField),
  type(Null) {
  ui->setupUi(this);
  menu = new QMenu(this);
  actionVariable     = new QAction(tr("&Variable"), menu);

  actionVariable->setCheckable(true);

  menu->addAction(actionVariable);

  connect(actionVariable,     SIGNAL(triggered()), SLOT(onActionVariable()));
  connect(ui->rButton,     SIGNAL(clicked()), this, SLOT(useLogVariable()));
  connect(ui->lButton,     SIGNAL(clicked()), this, SLOT(notUseLogVariable()));
  connect(ui->add, SIGNAL(clicked()), SLOT(add()));
  connect(ui->del, SIGNAL(clicked()), SLOT(del()));
  connect(ui->selectDefault, SIGNAL(toggled(bool)), SLOT(selectAllDefaultVars(bool)));
  connect(ui->selectUse, SIGNAL(toggled(bool)), SLOT(selectAllUseVars(bool)));

  updateMenu();
}

VisualTableField::~VisualTableField() {
  delete ui;
}
void VisualTableField::selectAllDefaultVars(bool select) {
  if(select)
    ui->defaultVarList->selectAll();
  else
    ui->defaultVarList->clearSelection();
}

void VisualTableField::selectAllUseVars(bool select) {
  if(select)
    ui->useVarList->selectAll();
  else
    ui->useVarList->clearSelection();
}

void VisualTableField::useLogVariable() {
  QModelIndexList selection =  ui->defaultVarList->selectionModel()->selectedRows();

  for(int i = 0; i < selection.count(); i++) {
    QTableWidgetItem* label = new QTableWidgetItem (ui->defaultVarList->item(selection.at(i).row(), 1)->text());
    QTableWidgetItem* id = new QTableWidgetItem (ui->defaultVarList->item(selection.at(i).row(), 0)->text());
    int currentRowCount =    ui->useVarList->rowCount();
    ui->useVarList->insertRow(currentRowCount);
    ui->useVarList->setItem(currentRowCount, 1, label);
    ui->useVarList->setItem(currentRowCount, 0, id);
  }

  QList<QTableWidgetItem*> items = ui->defaultVarList->selectedItems();
  for(int i = 0; i < items.length(); i = i + 2) {
    int row = items[i]->row();
    if(row >= 0) {
      ui->defaultVarList->removeRow(row);
      ui->defaultVarList->setCurrentIndex(ui->defaultVarList->model()->index(row, 0));
    }
  }
  ui->selectDefault->setChecked(false);
}
void VisualTableField::notUseLogVariable() {
  QModelIndexList selection =  ui->useVarList->selectionModel()->selectedRows();
  for(int i = 0; i < selection.count(); i++) {
    QTableWidgetItem* label = new QTableWidgetItem (ui->useVarList->item(selection.at(i).row(), 1)->text());
    QTableWidgetItem* id = new QTableWidgetItem (ui->useVarList->item(selection.at(i).row(), 0)->text());
    int currentRowCount =    ui->defaultVarList->rowCount();
    ui->defaultVarList->insertRow(currentRowCount);
    ui->defaultVarList->setItem(currentRowCount, 1, label);
    ui->defaultVarList->setItem(currentRowCount, 0, id);

  }
  QList<QTableWidgetItem*> items = ui->useVarList->selectedItems();

  for(int i = 0; i < items.length(); i = i + 2) {
    int row = items[i]->row();
    if(row >= 0) {
      ui->useVarList->removeRow(row);
      ui->useVarList->setCurrentIndex(ui->useVarList->model()->index(row, 0));
    }
  }
  ui->selectUse->setChecked(false);
}

void VisualTableField::add() {
  QTableWidgetItem* label = new QTableWidgetItem ("New Label");
  QTableWidgetItem* id = new QTableWidgetItem ("New id");

  int currentRowCount =    ui->defaultVarList->rowCount();
  ui->defaultVarList->insertRow(currentRowCount);
  ui->defaultVarList->setItem(currentRowCount, 1, label);
  ui->defaultVarList->setItem(currentRowCount, 0, id);
}

void VisualTableField::del() {
  QModelIndex currentIndex = ui->defaultVarList->currentIndex();
  ui->defaultVarList->removeRow(currentIndex.row());
  QList<QTableWidgetItem*> items = ui->defaultVarList->selectedItems();
  for(int i = 0; i < items.length(); i = i + 2) {
    int row = items[i]->row();
    if(row >= 0) {
      ui->defaultVarList->removeRow(row);
      ui->defaultVarList->setCurrentIndex(ui->defaultVarList->model()->index(row, 0));
    }
  }
}

QDomDocument VisualTableField::getXml() {
  QDomDocument ret;
  if(ui->useVarList->rowCount() == 0 && ui->defaultVarList->rowCount() == 0) {
    QDomElement opt = ret.createElement("variable");
    opt.appendChild(ret.createTextNode("empty"));
    opt.setAttribute("output", "false");
    ret.appendChild(opt);
  }

  for (int i = 0; i < ui->useVarList->rowCount(); ++i) {
    QDomElement opt = ret.createElement("variable");
    opt.setAttribute("id", ui->useVarList->item(i, 0)->text());
    opt.setAttribute("select", ui->useVarList->item(i, 0)->text());
    opt.setAttribute("label", ui->useVarList->item(i, 1)->text());
    opt.setAttribute("output", "true");
    ret.appendChild(opt);
  }
  for (int i = 0; i < ui->defaultVarList->rowCount(); ++i) {
    QDomElement opt = ret.createElement("variable");
    opt.setAttribute("id", ui->defaultVarList->item(i, 0)->text());
    opt.setAttribute("select", ui->defaultVarList->item(i, 0)->text());
    opt.setAttribute("label", ui->defaultVarList->item(i, 1)->text());
    opt.setAttribute("output", "false");
    ret.appendChild(opt);
  }
  return ret;
}

void VisualTableField::setXml(QDomElement node) {
  if(node.text() != "empty") {
    for (QDomElement opt = node; !opt.isNull(); opt = opt.nextSiblingElement("variable")) {

      if(opt.attribute("output") == "true") {
        QTableWidgetItem* label = new QTableWidgetItem (opt.attribute("label"));
        QTableWidgetItem* id = new QTableWidgetItem (opt.attribute("id"));
        int currentRowCount =    ui->useVarList->rowCount();
        ui->useVarList->insertRow(currentRowCount);
        ui->useVarList->setItem(currentRowCount, 1, label);
        ui->useVarList->setItem(currentRowCount, 0, id);
      }

      else {
        QTableWidgetItem* label = new QTableWidgetItem (opt.attribute("label"));
        QTableWidgetItem* id = new QTableWidgetItem (opt.attribute("id"));
        int currentRowCount =    ui->defaultVarList->rowCount();
        ui->defaultVarList->insertRow(currentRowCount);
        ui->defaultVarList->setItem(currentRowCount, 1, label);
        ui->defaultVarList->setItem(currentRowCount, 0, id);
      }

    }
  }

}

void VisualTableField::offField( bool enable) {
  onField(enable);
}

void VisualTableField::onField(bool editable) {
  ui->selectDefault->setChecked(false);
  ui->selectUse->setChecked(false);
  ui->selectDefault->setEnabled(editable);
  ui->selectUse->setEnabled(editable);
  ui->lButton->setEnabled(editable);
  ui->rButton->setEnabled(editable);
  ui->useVarList->setEnabled(editable);
  ui->defaultVarList->setEnabled(editable);
}

void VisualTableField::setEditMode(bool enable) {
  if(!enable) {
    ui->defaultVarList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->useVarList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->labelGeneral->setText(tr("Variables that will not be used:"));
    ui->labelToBeUse->setText(tr("Variables that will be used:"));
    ui->upperLabel->setText(tr("Pick variables that you want to use."));
  }
  ui->add->setVisible(enable);
  ui->del->setVisible(enable);

  if (enable) {
    ui->container->setToolTip("Default value");
    ui->horizontalLayout->setStretch(ui->horizontalLayout->indexOf(ui->container), 0);
  } else {
    ui->container->setToolTip("");
    ui->horizontalLayout->setStretch(ui->horizontalLayout->indexOf(ui->container), 5);
  }
}

QString VisualTableField::genLua() {
  QString ret = "";
  if(ui->useVarList->rowCount() == 0)
    return "false";

  for (int i = 0; i < ui->useVarList->rowCount(); ++i) {
    ret.append(ui->useVarList->item(i, 0)->text() + ",");

  }
  ret.remove(ret.size() - 1, 1);
  return ret;
}

QString VisualTableField::genR() {
  QString ret = "";

  if(ui->useVarList->rowCount() == 0)
    return "FALSE";

  for (int i = 0; i < ui->useVarList->rowCount(); ++i) {
    ret.append(ui->useVarList->item(i, 0)->text() + ",");

  }
  ret.remove(ret.size() - 1, 1);
  return ret;
}

void VisualTableField::updateMenu() {
  actionVariable->setChecked(type == Variable);
}

void VisualTableField::setWidget(QWidget* widget) {
  delete this->widget;
  this->widget = widget;
  widget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  widget->setMinimumWidth(160);
  widget->setMaximumWidth(160);

  ui->container->layout()->addWidget(widget);
  ui->container->layout()->setAlignment(widget, Qt::AlignLeft);
  // setTabOrder(ui->userLabel, widget);
  updateMenu();
}

void VisualTableField::onActionVariable() {
  type = Variable;
  emit changeType("Variable");
}

void VisualTableField::onActionClone() {
  emit clone();
}

void VisualTableField::onActionDelete() {
  int opt = QMessageBox::question(this, tr("Remove Field"),
                                  tr("This action will remove this field. Do you want to continue?"),
                                  QMessageBox::Yes | QMessageBox::No);
  if(opt == QMessageBox::Yes) {
    emit remove();
  }

}

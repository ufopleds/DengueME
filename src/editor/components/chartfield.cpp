#include "chartfield.h"
#include "ui_chartfield.h"

ChartField::ChartField(QWidget* parent) :
  Component(parent),
  widget(NULL),
  ui(new Ui::ChartField),
  type(Null) {
  ui->setupUi(this);

  menu = new QMenu(this);

  actionVariable     = new QAction(tr("&Plot Variable"), menu);
  actionDelete   = new QAction(tr("&Delete"), menu);
  actionClone = new QAction(tr("Cl&one"), menu);

  actionVariable->setCheckable(true);

  menu->addAction(actionVariable);

  connect(actionVariable,     SIGNAL(triggered()), SLOT(onActionVariable()));
  connect(ui->toolDelete,   SIGNAL(clicked()), SLOT(onActionDelete()));
  connect(ui->toolClone,   SIGNAL(clicked()), SLOT(onActionClone()));

  connect(ui->checkUse, SIGNAL(toggled(bool)), SLOT(onField(bool)));
  connect(ui->selectId, SIGNAL(textChanged(QString)), this, SLOT(validateId(QString)));

  ui->toolDelete->setToolTip(tr("Delete"));
  ui->toolClone->setToolTip(tr("Clone"));
  updateMenu();
}

ChartField::~ChartField() {
  delete ui;
}

void ChartField::validateId(QString name) {
  if (!QRegExp("[A-Za-z0-9_]+").exactMatch(name)) {
    ui->selectId->setText(purgeName(name));
    QToolTip::showText(  ui->selectId->mapToGlobal(QPoint(0,  ui->selectId->height())),
                         tr("The id name can contain only\nalphanumeric chars and,"
                            " \nunderscore (_)."));
  }
}

QString ChartField::purgeName(QString name) {
  return name.remove(QRegExp("[^A-Za-z0-9_]"));
}

QDomDocument ChartField::getXml() {
  QDomDocument ret;
  QDomElement node = ret.createElement("variable");

  node.setAttribute("label", ui->chartLabel->text());
  node.setAttribute("style", ui->style->currentText());
  node.setAttribute("color", ui->color->currentText());
  node.setAttribute("select", ui->selectId->text());
  node.setAttribute("id", ui->userLabel->text());
  node.setAttribute("output", ui->checkUse->isChecked() ? "true" : "false");
  ret.appendChild(node);

  return ret;
}

void ChartField::setXml(QDomElement node) {
  ui->userLabel->setText(node.attribute("id"));
  ui->selectId->setText(node.attribute("select"));
  ui->chartLabel->setText(node.attribute("label"));
  ui->color->setCurrentIndex(ui->color->findText(node.attribute("color")));
  ui->style->setCurrentIndex(ui->style->findText(node.attribute("style")));
  if(node.attribute("output") == "true") {
    ui->checkUse->setChecked(true);
  } else {
    ui->checkUse->setChecked(false);
  }

}

void ChartField::setLabel(QString label) {
  ui->selectId->setText(label);
}

void ChartField::setId(QString id) {
  ui->selectId->setText(id);
}
void ChartField::offField( bool enable) {
  ui->checkUse->setEnabled(enable);
  if(!enable) {
    ui->checkUse->setChecked(enable);
    onField(enable);
  }
}

void ChartField::onField(bool editable) {
  ui->chartLabel->setEnabled(editable);
  ui->chartLabel->setFrame(editable);
  ui->style->setEnabled(editable);
  ui->color->setEnabled(editable);
  ui->userLabel->setEnabled(editable);
  ui->selectId->setEnabled(editable);

}

void ChartField::setEditMode(bool enable) {
  ui->userLabel->setEnabled(enable);
  ui->chartLabel->setEnabled(enable);
  ui->style->setEnabled(enable);
  ui->color->setEnabled(enable);
  ui->labelUserLabel->setVisible(enable);
  ui->labelSelect->setVisible(enable);
  ui->line2->setVisible(enable);
  ui->selectId->setVisible(enable);
  ui->toolClone->setVisible(enable);
  ui->toolDelete->setVisible(enable);
  ui->userLabel->setReadOnly(!enable);
  ui->color->setFrame(!enable);
  ui->style->setFrame(!enable);
  ui->chartLabel->setFrame(enable);
  ui->userLabel->setFrame(enable);

  if(ui->checkUse->isChecked()) {
    ui->checkUse->setEnabled(true);
    onField(true);
  }

  if (enable) {
    ui->container->setToolTip("Default value");
    ui->userLabel->setToolTip("UserLabel");
    ui->userLabel->setPlaceholderText("User label...");

    ui->horizontalLayout->setStretch(ui->horizontalLayout->indexOf(ui->container), 0);
  } else {
    ui->container->setToolTip("");
    ui->userLabel->setToolTip("");
    ui->userLabel->setPlaceholderText("");

    ui->horizontalLayout->setStretch(ui->horizontalLayout->indexOf(ui->container), 5);
  }
}

QString ChartField::genLua() {
  QString ret = "";
  ret = "false";

  if(ui->checkUse->isChecked()) {
    ret = "";
    ret.append(ui->chartLabel->text() + ",");
    ret.append(ui->selectId->text() + ",");
    ret.append(ui->color->currentText() + ",");
    ret.append(ui->style->currentText());
    /* ret += "\"";
    // ret += field->text().replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n");
    ret += "\"";
    ret+= "--- "+ui->id->text();*/
  }
  //  ret += "\n";
  return ret;
}

QString ChartField::genR() {
  QString ret = "";
  ret = "FALSE";
  if(ui->checkUse->isChecked()) {
    ret = "";
    ret.append(ui->chartLabel->text() + ",");
    ret.append(ui->selectId->text() + ",");
    ret.append(ui->color->currentText() + ",");
    ret.append(ui->style->currentText());

  }
  return ret;
}

void ChartField::updateMenu() {
  actionVariable->setChecked(type == Variable);
}

void ChartField::setWidget(QWidget* widget) {
  delete this->widget;
  this->widget = widget;
  widget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  widget->setMinimumWidth(160);
  widget->setMaximumWidth(160);
  ui->container->layout()->addWidget(widget);
  ui->container->layout()->setAlignment(widget, Qt::AlignLeft);
  setTabOrder(ui->userLabel, widget);
  updateMenu();
}

void ChartField::onActionVariable() {
  type = Variable;
  emit changeType("Variable");
}

void ChartField::onActionClone() {
  emit clone();
}

void ChartField::onActionDelete() {
  emit remove();

}

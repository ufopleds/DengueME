#include "chartgroup.h"
#include "ui_group.h"

ChartGroup::ChartGroup(QWidget* parent):
  Component(parent),
  ui(new Ui::Group) {
  ui->setupUi(this);
  defaultHeight = height();
  setMinimumHeight(height());

  listDefaultHeight = 64;
  ui->widgets->setMaximumHeight(listDefaultHeight);

  QFont font;
  font.setBold(true);
  ui->userLabel->setFont(font);
  ui->addField->setText(tr("Add plot variable"));

  connect(ui->removeGroup, SIGNAL(clicked(bool)), SLOT(askRemoveGroup()));

  QMenu*   menu     = new QMenu(this);
  QAction* plotVariable = new QAction(tr("&Plot variable"), menu);

  menu->addAction(plotVariable);

  connect(    ui->addField,      SIGNAL(clicked()), SLOT(addVariable()));
  connect(ui->useGroup, SIGNAL(toggled(bool)), SLOT(togglePlotCheckbox(bool)));
  connect(ui->observerID, SIGNAL(textChanged(QString)), this, SLOT(validateId(QString)));

  ui->removeGroup->setText("Remove chart");
  ui->userLabel->setFrame(true);
  ui->observerID->setFrame(true);
  ui->userLabel->setText(tr("New Chart"));
  ui->useGroup->setChecked(true);
  addVariable();
  //  ui->addField->setMenu(menu);
}

ChartGroup::~ChartGroup() {
  delete ui;
}

void ChartGroup::validateId(QString name) {
  if (!QRegExp("[A-Za-z0-9_]+").exactMatch(name)) {
    ui->observerID->setText(purgeName(name));
    QToolTip::showText(  ui->observerID->mapToGlobal(QPoint(0,  ui->observerID->height())),
                         tr("The id name can contain only\nalphanumeric chars and,"
                            " \nunderscore (_)."));
  }
}

QString ChartGroup::purgeName(QString name) {
  return name.remove(QRegExp("[^A-Za-z0-9_]"));
}

void ChartGroup::askRemoveGroup() {
  int opt = QMessageBox::question(this, tr("Remove Chart"),
                                  tr("This action will remove the chart and all its variabes. Do you want to continue?"),
                                  QMessageBox::Yes | QMessageBox::No);

  if(opt == QMessageBox::Yes) {
    onRemove();
  }
}

void ChartGroup::setLabel(QString label) {
  ui->userLabel->setText(label);
}

QDomDocument ChartGroup::getXml() {
  QDomDocument ret;

  if (ui->widgets->count() == 0) return ret;

  QDomElement root = ret.createElement("outChart");

  root.setAttribute("label", ui->userLabel->text());
  root.setAttribute("id", ui->observerID->text());
  root.setAttribute("output", ui->useGroup->isChecked() ? "true" : "false");

  for (int i = 0; i < ui->widgets->count(); ++i) {
    Component* comp = map.value(ui->widgets->item(i));

    if (comp)
      root.appendChild(comp->getXml());
  }
  ret.appendChild(root);
  return ret;
}


void ChartGroup::setXml(QDomElement root) {
  ui->widgets->clear();
  ui->userLabel->setText(root.attribute("label"));
  ui->observerID->setText(root.attribute("id"));
  if(root.attribute("output") == "true") {
    ui->useGroup->setChecked(true);
  } else {
    ui->useGroup->setChecked(false);
  }

  for (QDomElement node = root.firstChildElement(); !node.isNull(); node = node.nextSiblingElement()) {
    if (node.nodeName() == "variable") {
      addComponent(new ChartField)->setXml(node);
    }
  }
}

void ChartGroup::setEditMode(bool enable) {

  for (int i = 0; i < ui->widgets->count(); ++i) {
    Component* comp = map.value(ui->widgets->item(i));
    if (comp)
      comp->setEditMode(enable);
  }
  ui->observerID->setVisible(enable);
  ui->userLabel->setFrame(enable);
  ui->observerID->setFrame(enable);
  ui->removeGroup->setVisible(enable);
  ui->addField->setVisible(enable);
  ui->userLabel->setReadOnly(!enable);

  if(ui->useGroup->isChecked()) {
    for (int i = 0; i < ui->widgets->count(); ++i) {
      ChartField* comp =  dynamic_cast<ChartField*>(map.value(ui->widgets->item(i)));
      if (comp) {
        comp->offField(true);
      }
    }
  } else {
    for (int i = 0; i < ui->widgets->count(); ++i) {
      ChartField* comp =  dynamic_cast<ChartField*>(map.value(ui->widgets->item(i)));

      if (comp) {
        comp->offField(false);
      }
    }
  }

  if (enable) {
    ui->widgets->setSelectionMode(QAbstractItemView::SingleSelection);
  } else {
    ui->widgets->setSelectionMode(QAbstractItemView::NoSelection);
  }
}


void ChartGroup::setRemovable(bool enable) {
  ui->removeGroup->setVisible(enable);
  ui->userLabel->setReadOnly(!enable);
}


QString ChartGroup::genLua() {
  QString ret, chart, select, label, style, color;

  chart = ui->observerID->text() + "= false\n";
  int countFalse = 0;

  if(ui->useGroup->isChecked()) {

    select = ui->observerID->text() + "Select = {";
    label = ui->observerID->text() + "Label = {";
    style = ui->observerID->text() + "Style = {";
    color = ui->observerID->text() + "Color = {";
    chart =  ui->observerID->text() + " = true";

    for (int i = 0; i < ui->widgets->count(); ++i) {

      ChartField* comp =  dynamic_cast<ChartField*>(map.value(ui->widgets->item(i)));

      if (comp) {

        ret = comp->genLua();

        if(ret != "false") {
          QStringList values = ret.split(',');
          select += "\"" + values.value(1) + "\",";
          label += "\"" + values.value(0) + "\",";
          color += "\"" + values.value(2) + "\",";
          style += "\"" + values.value(3) + "\",";
        } else {
          countFalse++;
          ret = "";
        }
      }
    }
    select.remove(select.size() - 1, 1);
    label.remove(label.size() - 1, 1);
    style.remove(style.size() - 1, 1);
    color.remove(color.size() - 1, 1);

    select += "}";
    label += "}";
    style += "}";
    color += "}";

    ret = chart + "\n" + select + "\n" + label + "\n" + style + "\n" + color + "\n";
  }

  if(ui->widgets->count() == countFalse || !ui->useGroup->isChecked() ) {
    ret =     ui->observerID->text() + "= false \n";
  }

  return ret;
}

QString ChartGroup::genR() {
  QString ret, chart, select, label, style, color;

  chart = ui->observerID->text() + "<- FALSE\n";
  int countFalse = 0;

  if(ui->useGroup->isChecked()) {

    select = ui->observerID->text() + "Select <- c(";
    label = ui->observerID->text() + "Label <- c(";
    style = ui->observerID->text() + "Style <- c(";
    color = ui->observerID->text() + "Color <- c(";
    chart = ui->observerID->text() + " <- TRUE";

    for (int i = 0; i < ui->widgets->count(); ++i) {
      ChartField* comp =  dynamic_cast<ChartField*>(map.value(ui->widgets->item(i)));

      if (comp) {
        ret = comp->genR();

        if(ret != "FALSE") {
          QStringList values = ret.split(',');
          select += "\"" + values.value(1) + "\",";
          label += "\"" + values.value(0) + "\",";
          color += "\"" + values.value(2) + "\",";
          QString rstyle;
          if (!values.value(3).compare("lines")) {
            rstyle = "l";
          } else if (!values.value(3).compare("dots")) {
            rstyle = "o";
          } else if (!values.value(3).compare("steps")) {
            rstyle = "s";
          } else {
            rstyle = "h";
          }
          style += "\"" + rstyle + "\",";
        } else {
          countFalse++;
          ret = "";
        }
      }
    }
    select.remove(select.size() - 1, 1);
    label.remove(label.size() - 1, 1);
    style.remove(style.size() - 1, 1);
    color.remove(color.size() - 1, 1);

    select += ")";
    label += ")";
    style += ")";
    color += ")";

    ret = chart + "\n" + select + "\n" + label + "\n" + style + "\n" + color + "\n";
  }

  if(ui->widgets->count() == countFalse || !ui->useGroup->isChecked() ) {
    ret =     ui->observerID->text() + "<- FALSE \n";
  }

  return ret;
}



void ChartGroup::updateHeight() {
  int height = 8;
  for (int i = 0; i < ui->widgets->count(); ++i)
    height += ui->widgets->sizeHintForRow(i);

  if (height < listDefaultHeight) height = listDefaultHeight;

  ui->widgets->setMaximumHeight(height);

  height = height + defaultHeight - listDefaultHeight;
  setMinimumHeight(height);
  emit heightChanged(height);
}



void ChartGroup::removeField() {
  QObject* field = QObject::sender();
  if(ui->widgets->count() == 1) {
    int opt = QMessageBox::question(this, tr("Remove last Field"),
                                    tr("The chart must have at least one field. If you delete this field the chart will be deleted. Are you sure?"),
                                    QMessageBox::Yes | QMessageBox::No);
    if(opt == QMessageBox::Yes) {
      delete ui->widgets->takeItem(ui->widgets->row(map.key((ChartField*) field)));
      onRemove();
    }
  } else {
    int opt = QMessageBox::question(this, tr("Remove Field"),
                                    tr("This action will remove this field. Do you want to continue?"),
                                    QMessageBox::Yes | QMessageBox::No);
    if(opt == QMessageBox::Yes)
      delete ui->widgets->takeItem(ui->widgets->row(map.key((ChartField*) field)));
  }
  updateHeight();

}


void ChartGroup::cloneField() {
  addVariable();
}

void ChartGroup::togglePlotCheckbox(bool enable) {
  for (int i = 0; i < ui->widgets->count(); ++i) {
    ChartField* comp =  dynamic_cast<ChartField*>(map.value(ui->widgets->item(i)));
    if (comp) {
      comp->offField(enable);
    }
  }
}

ChartField* ChartGroup::addVariable() {

  ChartField* field = new ChartField;
  field->onActionVariable();
  field->setToolTip("Variable");
  addComponent(field);

  return field;
}

void ChartGroup::changeType(QString type) {

  QObject* field = QObject::sender();

  ui->widgets->item( ui->widgets->row(map.key((ChartField*) field)))->setToolTip(type);

  updateHeight();

}

Component* ChartGroup::addComponent(Component* comp) {

  QListWidgetItem* item = new QListWidgetItem;

  item->setSizeHint(QSize(-1, comp->height()));
  item->setToolTip(comp->toolTip());


  ui->widgets->addItem(item);
  ui->widgets->setItemWidget(item, comp);
  ui->widgets->scrollToBottom();

  connect(comp, SIGNAL(remove()), SLOT(removeField ()));
  connect(comp, SIGNAL(clone()), SLOT(cloneField ()));
  connect(comp, SIGNAL(changeType(QString)), SLOT(changeType (QString)));
  map.insert(item, comp);

  updateHeight();
  return comp;
}


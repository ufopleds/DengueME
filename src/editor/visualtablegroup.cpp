#include "visualtablegroup.h"
#include "ui_group.h"

VisualTableGroup::VisualTableGroup(QWidget* parent):
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
  ui->observerID->setFont(font);
  ui->addField->setText(tr("Add variable"));

  connect(ui->removeGroup, SIGNAL(clicked(bool)), SLOT(askRemoveGroup()));

  QMenu*   menu     = new QMenu(this);

  connect(ui->useGroup, SIGNAL(toggled(bool)), SLOT(togglePlotCheckbox(bool)));
  connect(ui->observerID, SIGNAL(textChanged(QString)), this, SLOT(validateId(QString)));

  ui->addField->setVisible(false);
  ui->useGroup->setText("Use Visual Table:");
  ui->removeGroup->setText("Remove visual table");
  ui->userLabel->setFrame(true);
  ui->observerID->setFrame(true);
  ui->userLabel->setText(tr("New Visual Table"));
  ui->addField->setMenu(menu);
  ui->useGroup->setChecked(true);
  addVariable();
}

VisualTableGroup::~VisualTableGroup() {
  delete ui;
}

void VisualTableGroup::validateId(QString name) {
  if (!QRegExp("[A-Za-z0-9_]+").exactMatch(name)) {
    ui->observerID->setText(purgeName(name));
    QToolTip::showText(  ui->observerID->mapToGlobal(QPoint(0,  ui->observerID->height())),
                         tr("The id name can contain only\nalphanumeric chars and,"
                            " \nunderscore (_)."));
  }
}

QString VisualTableGroup::purgeName(QString name) {
  return name.remove(QRegExp("[^A-Za-z0-9_]"));
}

void VisualTableGroup::askRemoveGroup() {
  int opt = QMessageBox::question(this, tr("Remove Visual Table"),
                                  tr("This action will remove the Visual Table and all its variabes. Do you want to continue?"),
                                  QMessageBox::Yes | QMessageBox::No);

  if(opt == QMessageBox::Yes) {
    onRemove();
  }
}


QDomDocument VisualTableGroup::getXml() {
  QDomDocument ret;
  if (ui->widgets->count() == 0) return ret;

  QDomElement root = ret.createElement("outVisualTable");
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

void VisualTableGroup::setXml(QDomElement root) {
  ui->widgets->clear();
  ui->observerID->setText(root.attribute("id"));
  ui->userLabel->setText(root.attribute("label"));
  if(root.attribute("output") == "true") {
    ui->useGroup->setChecked(true);
  } else {
    ui->useGroup->setChecked(false);
  }

  QDomElement node = root.firstChildElement();
  if (node.nodeName() == "variable") {
    addComponent(new VisualTableField)->setXml(node);
  }

}

void VisualTableGroup::setEditMode(bool enable) {
  for (int i = 0; i < ui->widgets->count(); ++i) {
    Component* comp = map.value(ui->widgets->item(i));
    if (comp)
      comp->setEditMode(enable);
  }

  ui->observerID->setVisible(enable);
  ui->userLabel->setFrame(enable);
  ui->removeGroup->setVisible(enable);

  ui->userLabel->setReadOnly(!enable);

  if(ui->useGroup->isChecked()) {
    for (int i = 0; i < ui->widgets->count(); ++i) {
      VisualTableField* comp =  dynamic_cast<VisualTableField*>(map.value(ui->widgets->item(i)));
      if (comp) {
        comp->offField(true);
      }
    }
  } else {
    for (int i = 0; i < ui->widgets->count(); ++i) {
      VisualTableField* comp =  dynamic_cast<VisualTableField*>(map.value(ui->widgets->item(i)));
      if (comp) {
        comp->offField(false);
      }
    }
  }
  ui->useGroup->setText("Use Visual Table:");
  if (enable) {
    ui->widgets->setSelectionMode(QAbstractItemView::SingleSelection);
  } else {
    ui->widgets->setSelectionMode(QAbstractItemView::NoSelection);
  }
}

void VisualTableGroup::setRemovable(bool enable) {
  ui->removeGroup->setVisible(enable);
  ui->userLabel->setReadOnly(!enable);
}


QString VisualTableGroup::genLua() {
  QString ret, textScreen, select;

  if(ui->useGroup->isChecked()) {
    select = ui->observerID->text() + "Select = {";
    textScreen =  ui->observerID->text() + " = true";

    VisualTableField* comp =  dynamic_cast<VisualTableField*>(map.value(ui->widgets->item(0)));

    if (comp) {
      ret = comp->genLua();
      if(ret != "false") {
        QStringList values = ret.split(',');
        for(int i = 0; i < values.count(); i++) {
          select += "\"" + values.value(i) + "\",";
        }
        select.remove(select.size() - 1, 1);
        select += "}";
      } else {
        select = ui->observerID->text() + "Select = {}";
      }
    }
    return  ret =  textScreen + "\n" + select + "\n";
  } else {
    return ret = ui->observerID->text() + "= false\n";
  }

}

QString VisualTableGroup::genR() {
  QString ret, textScreen, select;
  if(ui->useGroup->isChecked()) {
    select = ui->observerID->text() + "Select <- c(";
    textScreen =  ui->observerID->text() + " <- TRUE";

    VisualTableField* comp =  dynamic_cast<VisualTableField*>(map.value(ui->widgets->item(0)));

    if (comp) {
      ret = comp->genLua();
      if(ret != "FALSE") {
        QStringList values = ret.split(',');
        for(int i = 0; i < values.count(); i++) {
          select += "\"" + values.value(i) + "\",";
        }
        select.remove(select.size() - 1, 1);
        select += ")";
      } else {
        select = ui->observerID->text() + "Select <- c()";
      }
    }
    return  ret =  textScreen + "\n" + select + "\n";
  } else {
    return ret = ui->observerID->text() + "<- FALSE\n";
  }
}


void VisualTableGroup::updateHeight() {
  int height = 8;
  //    int count = (ui->widgets->count() < 4) ? ui->widgets->count() : 4;
  for (int i = 0; i < ui->widgets->count(); ++i)
    height += ui->widgets->sizeHintForRow(i);

  if (height < listDefaultHeight) height = listDefaultHeight;

  ui->widgets->setMaximumHeight(height);

  height = height + defaultHeight - listDefaultHeight;
  setMinimumHeight(height);
  emit heightChanged(height);
}

void VisualTableGroup::removeField() {
  QObject* field = QObject::sender();

  delete ui->widgets->takeItem(ui->widgets->row(map.key((VisualTableField*) field)));

  updateHeight();
}

void VisualTableGroup::cloneField() {
  addVariable();
}

void VisualTableGroup::togglePlotCheckbox(bool enable) {
  for (int i = 0; i < ui->widgets->count(); ++i) {
    VisualTableField* comp =  dynamic_cast<VisualTableField*>(map.value(ui->widgets->item(i)));
    if (comp) {
      comp->offField(enable);
    }
  }
}

VisualTableField* VisualTableGroup::addVariable() {
  VisualTableField* field = new VisualTableField;
  field->onActionVariable();
  field->setToolTip("Variable");
  addComponent(field);

  return field;
}


void VisualTableGroup::changeType(QString type) {
  QObject* field = QObject::sender();
  ui->widgets->item( ui->widgets->row(map.key((VisualTableField*) field)))->setToolTip(type);
  updateHeight();
}


Component* VisualTableGroup::addComponent(Component* comp) {
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

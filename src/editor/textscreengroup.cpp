#include "textscreengroup.h"
#include "ui_group.h"

TextScreenGroup::TextScreenGroup(QWidget* parent):
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
  ui->addField->setText(tr("Add variable"));

  connect(ui->removeGroup, SIGNAL(clicked(bool)), SLOT(askRemoveGroup()));

  QMenu*   menu     = new QMenu(this);

  connect(ui->useGroup, SIGNAL(toggled(bool)), SLOT(togglePlotCheckbox(bool)));
  connect(ui->observerID, SIGNAL(textChanged(QString)), this, SLOT(validateId(QString)));

  ui->addField->setVisible(false);
  ui->useGroup->setText("Use Text Screen:");
  ui->removeGroup->setText("Remove text screen");
  ui->observerID->setFrame(true);
  ui->userLabel->setFrame(true);
  ui->userLabel->setText(tr("New Text Screen"));
  ui->addField->setMenu(menu);
  ui->useGroup->setChecked(true);

  addVariable();
}



TextScreenGroup::~TextScreenGroup() {
  delete ui;
}

void TextScreenGroup::validateId(QString name) {
  if (!QRegExp("[A-Za-z0-9_]+").exactMatch(name)) {
    ui->observerID->setText(purgeName(name));
    QToolTip::showText(  ui->observerID->mapToGlobal(QPoint(0,  ui->observerID->height())),
                         tr("The id name can contain only\nalphanumeric chars and,"
                            " \nunderscore (_)."));
  }
}

QString TextScreenGroup::purgeName(QString name) {
  return name.remove(QRegExp("[^A-Za-z0-9_]"));
}

void TextScreenGroup::askRemoveGroup() {
  int opt = QMessageBox::question(this, tr("Remove Text Screen"),
                                  tr("This action will remove the Text Screen and all its variabes. Do you want to continue?"),
                                  QMessageBox::Yes | QMessageBox::No);

  if(opt == QMessageBox::Yes) {
    onRemove();
  }
}



QDomDocument TextScreenGroup::getXml() {
  QDomDocument ret;
  if (ui->widgets->count() == 0) return ret;

  QDomElement root = ret.createElement("outTextScreen");
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

void TextScreenGroup::setXml(QDomElement root) {
  ui->widgets->clear();
  ui->userLabel->setText(root.attribute("label"));
  ui->observerID->setText(root.attribute("id"));
  if(root.attribute("output") == "true") {
    ui->useGroup->setChecked(true);
  } else {
    ui->useGroup->setChecked(false);
  }
  QDomElement node = root.firstChildElement();
  if (node.nodeName() == "variable") {
    addComponent(new TextScreenField)->setXml(node);
  }

}

void TextScreenGroup::setEditMode(bool enable) {
  for (int i = 0; i < ui->widgets->count(); ++i) {
    Component* comp = map.value(ui->widgets->item(i));
    if (comp)
      comp->setEditMode(enable);
  }

  ui->observerID->setVisible(enable);
  ui->userLabel->setFrame(enable);
  ui->observerID->setFrame(enable);
  ui->removeGroup->setVisible(enable);

  ui->userLabel->setReadOnly(!enable);

  if(ui->useGroup->isChecked()) {
    for (int i = 0; i < ui->widgets->count(); ++i) {
      TextScreenField* comp =  dynamic_cast<TextScreenField*>(map.value(ui->widgets->item(i)));
      if (comp) {
        comp->offField(true);
      }
    }
  } else {
    for (int i = 0; i < ui->widgets->count(); ++i) {
      TextScreenField* comp =  dynamic_cast<TextScreenField*>(map.value(ui->widgets->item(i)));
      if (comp) {
        comp->offField(false);
      }
    }
  }
  ui->useGroup->setText("Use Text Screen: ");
  if (enable) {
    ui->widgets->setSelectionMode(QAbstractItemView::SingleSelection);
  } else {
    ui->widgets->setSelectionMode(QAbstractItemView::NoSelection);
  }
}

void TextScreenGroup::setRemovable(bool enable) {
  ui->removeGroup->setVisible(enable);
  ui->userLabel->setReadOnly(!enable);
}


QString TextScreenGroup::genLua() {
  QString ret, textScreen, select;

  if(ui->useGroup->isChecked()) {
    select = ui->observerID->text() + "Select = {";
    textScreen =  ui->observerID->text() + " = true";

    TextScreenField* comp =  dynamic_cast<TextScreenField*>(map.value(ui->widgets->item(0)));

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

QString TextScreenGroup::genR() {
  QString ret, textScreen, select;

  if(ui->useGroup->isChecked()) {
    select = ui->observerID->text() + "Select <- c(";
    textScreen =  ui->observerID->text() + " <- TRUE";

    TextScreenField* comp =  dynamic_cast<TextScreenField*>(map.value(ui->widgets->item(0)));

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
        select = ui->observerID->text() + "Select <- ()";
      }
    }
    return  ret =  textScreen + "\n" + select + "\n";
  } else {
    return ret = ui->observerID->text() + "<- FALSE\n";
  }
}


void TextScreenGroup::updateHeight() {
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

void TextScreenGroup::removeField() {
  QObject* field = QObject::sender();

  delete ui->widgets->takeItem(ui->widgets->row(map.key((TextScreenField*) field)));

  updateHeight();
}

void TextScreenGroup::cloneField() {
  addVariable();
}

void TextScreenGroup::togglePlotCheckbox(bool enable) {
  for (int i = 0; i < ui->widgets->count(); ++i) {
    TextScreenField* comp =  dynamic_cast<TextScreenField*>(map.value(ui->widgets->item(i)));
    if (comp) {
      comp->offField(enable);
    }
  }
}

TextScreenField* TextScreenGroup::addVariable() {
  TextScreenField* field = new TextScreenField;
  field->onActionVariable();
  field->setToolTip("Variable");
  addComponent(field);

  return field;
}

void TextScreenGroup::changeType(QString type) {
  QObject* field = QObject::sender();

  ui->widgets->item( ui->widgets->row(map.key((TextScreenField*) field)))->setToolTip(type);

  updateHeight();
}


Component* TextScreenGroup::addComponent(Component* comp) {
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

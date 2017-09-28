#include "loggroup.h"
#include "ui_group.h"

LogGroup::LogGroup(QWidget* parent):
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
  ui->addField->setText(tr("Add log file"));

  connect(ui->removeGroup, SIGNAL(clicked(bool)), SLOT(askRemoveGroup()));

  QMenu*   menu     = new QMenu(this);

  connect(ui->useGroup, SIGNAL(toggled(bool)), SLOT(togglePlotCheckbox(bool)));
  connect(ui->observerID, SIGNAL(textChanged(QString)), this, SLOT(validateId(QString)));

  ui->addField->setVisible(false);
  ui->useGroup->setText("Use Log:");
  ui->removeGroup->setText("Remove log");
  ui->userLabel->setFrame(true);
  ui->userLabel->setText(tr("New Log"));
  ui->addField->setMenu(menu);

  ui->useGroup->setChecked(true);
  addVariable();
}

LogGroup::~LogGroup() {
  delete ui;
}

void LogGroup::validateId(QString name) {
  if (!QRegExp("[A-Za-z0-9_]+").exactMatch(name)) {
    ui->observerID->setText(purgeName(name));
    QToolTip::showText(  ui->observerID->mapToGlobal(QPoint(0,  ui->observerID->height())),
                         tr("The id name can contain only\nalphanumeric chars and,"
                            " \nunderscore (_)."));
  }
}

QString LogGroup::purgeName(QString name) {
  return name.remove(QRegExp("[^A-Za-z0-9_]"));
}

void LogGroup::askRemoveGroup() {
  int opt = QMessageBox::question(this, tr("Remove Log"),
                                  tr("This action will remove the log and all properties that you set. Do you want to continue?"),
                                  QMessageBox::Yes | QMessageBox::No);

  if(opt == QMessageBox::Yes) {
    onRemove();
  }
}

void LogGroup::setLabel(QString label) {
  ui->userLabel->setText(label);
}

QDomDocument LogGroup::getXml() {

  QDomDocument ret;
  if (ui->widgets->count() == 0) return ret;
  QDomElement root = ret.createElement("outLog");
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

void LogGroup::setXml(QDomElement root) {
  ui->widgets->clear();
  ui->observerID->setText(root.attribute("id"));
  ui->userLabel->setText(root.attribute("label"));
  if(root.attribute("output") == "true") {
    ui->useGroup->setChecked(true);
  } else {
    ui->useGroup->setChecked(false);
  }
  for (QDomElement node = root.firstChildElement(); !node.isNull(); node = node.nextSiblingElement()) {

    if (node.nodeName() == "config") {
      ui->addField->setEnabled(false);
      addComponent(new LogField)->setXml(node);
    }
  }
}

void LogGroup::setEditMode(bool enable) {
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
      LogField* comp =  dynamic_cast<LogField*>(map.value(ui->widgets->item(i)));
      if (comp) {
        comp->offField(true);
      }
    }
  } else {
    for (int i = 0; i < ui->widgets->count(); ++i) {
      LogField* comp =  dynamic_cast<LogField*>(map.value(ui->widgets->item(i)));

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

void LogGroup::setRemovable(bool enable) {
  ui->removeGroup->setVisible(enable);
  ui->userLabel->setReadOnly(!enable);
}

QString LogGroup::genLua() {
  QString ret, log, select, label, separator, filename, overwrite;

  int count = 0;

  if(ui->useGroup->isChecked()) {
    select = ui->observerID->text() + "Select = {";
    overwrite = ui->observerID->text() + "Overwrite = ";
    separator = ui->observerID->text() + "Separator = ";
    filename = ui->observerID->text() + "File = RESULTS_PATH ..";

    for (int i = 0; i < ui->widgets->count(); ++i) {
      LogField* comp =  dynamic_cast<LogField*>(map.value(ui->widgets->item(i)));
      if (comp) {
        log =  ui->observerID->text() + " = true";
        ret = comp->genLua();
        QStringList values = ret.split(',');
        filename += "\"" + values.value(0);
        overwrite += values.value(1);
        separator += "\"" + values.value(2) + "\"";
        for(int i = 3; i < values.count(); i++) {
          select += "\"" + values.value(i) + "\",";
          count++;
        }

      }
    }
    if(count > 0)
      select.remove(select.size() - 1, 1);
    filename.append(".csv");
    select += "}";
    filename += "\"";
    if(separator.contains("comma"))
      separator = ui->observerID->text() + "Separator = \",\" ";
    ret =  log + "\n" + select + "\n" + separator + "\n" + filename + "\n" + overwrite + "\n";

    return ret;
  } else {
    return ret = ui->observerID->text() + "= false";
  }

}

QString LogGroup::genR() {
  QString ret, log, select, label, separator, filename, overwrite;
  int count = 0;
  if(ui->useGroup->isChecked()) {
    select = ui->observerID->text() + "Select <- c(";
    overwrite = ui->observerID->text() + "Overwrite <- ";
    separator = ui->observerID->text() + "Separator <- ";
    filename = ui->observerID->text() + "File <- paste0(RESULTS_PATH, ";

    for (int i = 0; i < ui->widgets->count(); ++i) {
      LogField* comp =  dynamic_cast<LogField*>(map.value(ui->widgets->item(i)));
      if (comp) {
        log =  ui->observerID->text() + " <- TRUE";
        ret = comp->genR();
        QStringList values = ret.split(',');
        filename += "\"/" + values.value(0);
        overwrite += values.value(1);
        separator += "\"" + values.value(2) + "\"";
        for(int i = 3; i < values.count(); i++) {
          select += "\"" + values.value(i) + "\",";
          count++;
        }

      }
    }
    if(count > 0)
      select.remove(select.size() - 1, 1);
    filename.append(".csv");
    select += ")";
    filename += "\"";
    if(separator.contains("comma"))
      separator = ui->observerID->text() + "Separator <- \",\" ";
    ret =  log + "\n" + select + "\n" + separator + "\n" + filename + ")\n" + overwrite + "\n";

    return ret;
  } else {
    return ret = ui->observerID->text() + "<- FALSE";
  }
}

void LogGroup::updateHeight() {
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

void LogGroup::removeField() {
  QObject* field = QObject::sender();

  delete ui->widgets->takeItem(ui->widgets->row(map.key((LogField*) field)));

  updateHeight();
  ui->addField->setEnabled(true);
}

void LogGroup::cloneField() {
  // addVariable();
}

void LogGroup::togglePlotCheckbox(bool enable) {
  for (int i = 0; i < ui->widgets->count(); ++i) {
    LogField* comp =  dynamic_cast<LogField*>(map.value(ui->widgets->item(i)));
    if (comp) {
      comp->offField(enable);
    }
  }
}

LogField* LogGroup::addVariable() {
  LogField* field = new LogField;
  field->onActionVariable();
  field->setToolTip("Variable");
  addComponent(field);
  ui->addField->setEnabled(false);
  return field;
}

void LogGroup::changeType(QString type) {
  QObject* field = QObject::sender();

  ui->widgets->item( ui->widgets->row(map.key((LogField*) field)))->setToolTip(type);

  updateHeight();
}

Component* LogGroup::addComponent(Component* comp) {
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

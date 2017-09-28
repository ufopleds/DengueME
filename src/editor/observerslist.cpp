#include "observerslist.h"
#include "ui_observerslist.h"

ObserversList::ObserversList(QWidget* parent) :
  QFrame(parent),
  ui(new Ui::ObserversList),
  add(new QToolButton) {
  ui->setupUi(this);
  setBackgroundRole(QPalette::Base);

  QMenu* menu = new QMenu;
  QAction* chart = new QAction(tr("&Chart"), menu);
  QAction* textscreen = new QAction(tr("&Text Screen"), menu);
  QAction* visualTable = new QAction(tr("&Visual Table"), menu);
  QAction* log = new QAction(tr("&Log File"), menu);

  connect(chart, SIGNAL(triggered()), SLOT(addChartGroup()));
  connect(textscreen, SIGNAL(triggered()), SLOT(addTextGroup()));
  connect(visualTable, SIGNAL(triggered()), SLOT(addTableGroup()));
  connect(log, SIGNAL(triggered()), SLOT(addLogGroup()));

  menu->addAction(chart);
  menu->addAction(log);
  menu->addAction(textscreen);
  menu->addAction(visualTable);

  ui->addObserver->setMenu(menu);

}

ObserversList::~ObserversList() {

}

QDomDocument ObserversList::getXml() {
  QDomDocument ret;

  if(ui->widgets->count() == 0) {
    return ret;
  }

  QDomElement root = ret.createElement("results");
  Component* group;
  for(int i = 0; i < ui->widgets->count(); ++i) {

    QString objectType = ui->widgets->itemWidget(ui->widgets->item(i))->metaObject()->className() ;

    if(objectType == "ChartGroup") {
      group = dynamic_cast<ChartGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));
    } else if(objectType == "TextScreenGroup") {
      group = dynamic_cast<TextScreenGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));
    } else if(objectType == "VisualTableGroup") {
      group = dynamic_cast<VisualTableGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));
    } else {
      group = dynamic_cast<LogGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));
    }
    if (group) {
      root.appendChild(group->getXml());
    }
  }

  ret.appendChild(root);
  return ret;
}

void ObserversList::setXml(QDomNode root) {
  ui->widgets->clear();
  for(QDomElement node = root.firstChildElement(); !node.isNull(); node = node.nextSiblingElement()) {
    if(node.tagName().compare("outChart", Qt::CaseInsensitive) == 0)
      addChartGroup()->setXml(node);
    else if(node.tagName().compare("outTextScreen", Qt::CaseInsensitive) == 0)
      addTextGroup()->setXml(node);
    else  if(node.tagName().compare("outVisualTable", Qt::CaseInsensitive) == 0)
      addTableGroup()->setXml(node);
    else  if(node.tagName().compare("outLog", Qt::CaseInsensitive) == 0)
      addLogGroup()->setXml(node);

  }

}

void ObserversList::setEditMode(bool enable) {
  for(int i = 0; i < ui->widgets->count(); i++) {
    QString objectType = ui->widgets->itemWidget(ui->widgets->item(i))->metaObject()->className() ;
    if(objectType == "ChartGroup") {
      ChartGroup* group = dynamic_cast<ChartGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));
      if (group)
        group->setEditMode(enable);
    } else if(objectType == "TextScreenGroup") {
      TextScreenGroup* group = dynamic_cast<TextScreenGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));
      if (group)
        group->setEditMode(enable);
    } else if(objectType == "VisualTableGroup") {
      VisualTableGroup* group = dynamic_cast<VisualTableGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));
      if (group)
        group->setEditMode(enable);
    } else {
      LogGroup* group = dynamic_cast<LogGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));
      if (group)
        group->setEditMode(enable);
    }
  }

  ui->panel->setVisible(enable);
  ui->widgets->setAlternatingRowColors(enable);

  if (enable) {
    ui->widgets->setSelectionMode(QAbstractItemView::SingleSelection);
  } else {
    ui->widgets->setSelectionMode(QAbstractItemView::NoSelection);
  }
}

QString ObserversList::genLua() {
  if(ui->widgets->count() == 0)
    return  "";

  QString ret, luaRet, output;
  output += "output = ";
  Component* group;
  for (int i = 0; i < ui->widgets->count(); ++i) {
    QString objectType = ui->widgets->itemWidget(ui->widgets->item(i))->metaObject()->className() ;
    if(objectType == "ChartGroup") {
      group = dynamic_cast<ChartGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));

    } else if(objectType == "TextScreenGroup") {
      group = dynamic_cast<TextScreenGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));

    } else if(objectType == "VisualTableGroup") {
      group = dynamic_cast<VisualTableGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));

    } else {
      group = dynamic_cast<LogGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));

    }
    if (group) {
      luaRet = group->genLua();
      QStringList splitRet = luaRet.split('=');
      if(luaRet.contains("false")) {
        output += splitRet.value(0) + " or ";
      } else {
        output += splitRet.value(0) + " or ";
      }
      ret += "\n" + luaRet;
    }
  }
  output.remove(output.size() - 3, 4);
  output += "\n";
  ret = ret + "\n" + output ;


  return ret;
}

QString ObserversList::genR() {
  if(ui->widgets->count() == 0)
    return  "";

  QString ret, RRet, output;
  output += "output <- ";
  Component* group;
  for (int i = 0; i < ui->widgets->count(); ++i) {
    QString objectType = ui->widgets->itemWidget(ui->widgets->item(i))->metaObject()->className() ;
    if(objectType == "ChartGroup") {
      group = dynamic_cast<ChartGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));

    } else if(objectType == "TextScreenGroup") {
      group = dynamic_cast<TextScreenGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));

    } else if(objectType == "VisualTableGroup") {
      group = dynamic_cast<VisualTableGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));

    } else {
      group = dynamic_cast<LogGroup*>(ui->widgets->itemWidget(ui->widgets->item(i)));

    }
    if (group) {
      RRet = group->genR();
      QStringList splitRet = RRet.split(QRegExp("<-"));
      if(RRet.contains("FALSE")) {
        output += splitRet.value(0) + " | ";
      } else {
        output += splitRet.value(0) + " | ";
      }
      ret += "\n" + RRet;
    }
  }
  output.remove(output.size() - 3, 4);
  output += "\n";
  ret = ret + "\n" + output ;

  return ret;
}

void ObserversList::scrollToTop() {
  ui->widgets->scrollToTop();
}

LogGroup* ObserversList::addLogGroup() {
  LogGroup* group = new LogGroup;
  connect(group, SIGNAL(heightChanged(int)), SLOT(updateHeight(int)));
  addComponent(group);
  return group;

}

VisualTableGroup* ObserversList::addTableGroup() {
  VisualTableGroup* group = new VisualTableGroup;
  connect(group, SIGNAL(heightChanged(int)), SLOT(updateHeight(int)));
  addComponent(group);
  return group;

}

TextScreenGroup* ObserversList::addTextGroup() {
  TextScreenGroup* group = new TextScreenGroup;
  connect(group, SIGNAL(heightChanged(int)), SLOT(updateHeight(int)));
  addComponent(group);
  return group;

}

ChartGroup* ObserversList::addChartGroup() {
  ChartGroup* group = new ChartGroup;
  connect(group, SIGNAL(heightChanged(int)), SLOT(updateHeight(int)));
  addComponent(group);
  return group;

}


void ObserversList::removeGroup() {
  QObject* wid = QObject::sender();
  if (!map.contains(wid)) return;

  delete ui->widgets->takeItem(ui->widgets->row(map.value(wid)));
}


void ObserversList::updateHeight(int height) {
  QObject* wid = QObject::sender();
  if (!map.contains(wid)) return;

  QListWidgetItem* item = map[wid];
  item->setSizeHint(QSize(-1, height));

  ui->widgets->scrollToItem(item);
}


Component* ObserversList::addComponent(Component* comp) {
  QListWidgetItem* item = new QListWidgetItem;

  item->setSizeHint(QSize(-1, comp->height()));

  ui->widgets->addItem(item);
  ui->widgets->setItemWidget(item, comp);
  ui->widgets->scrollToBottom();

  connect(comp, SIGNAL(remove()), SLOT(removeGroup()));

  map[comp] = item;
  return comp;
}

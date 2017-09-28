#include "grouplist.h"
#include "ui_grouplist.h"


GroupList::GroupList(QWidget* parent) :
  QFrame(parent),
  ui(new Ui::GroupEditor),
  add(new QToolButton) {
  ui->setupUi(this);
  setBackgroundRole(QPalette::Base);

  connect(ui->addGroup, SIGNAL(clicked(bool)), SLOT(addGroup()));
}


GroupList::~GroupList() {

}

QDomDocument GroupList::getXml() {
  QDomDocument ret;
  if (ui->widgets->count() == 0) return ret;

  QDomElement root = ret.createElement("parameters");

  for (int i = 0; i < ui->widgets->count(); ++i) {
    Group* group = dynamic_cast<Group*>(ui->widgets->itemWidget(ui->widgets->item(i)));
    if (group)
      root.appendChild(group->getXml());
  }

  ret.appendChild(root);
  return ret;
}

void GroupList::setXml(QDomNode root) {
  ui->widgets->clear();
  for (QDomElement node = root.firstChildElement(); !node.isNull(); node = node.nextSiblingElement()) {
    if (node.tagName().compare("groupbox", Qt::CaseInsensitive) == 0)
      addGroup()->setXml(node);   
  }
}

void GroupList::setEditMode(bool enable) {
  for (int i = 0; i < ui->widgets->count(); ++i) {
    Group* group = dynamic_cast<Group*>(ui->widgets->itemWidget(ui->widgets->item(i)));
    if (group)
      group->setEditMode(enable);
  }
  ui->panel->setVisible(enable);
  ui->widgets->setAlternatingRowColors(enable);

  if (enable) {
    ui->widgets->setSelectionMode(QAbstractItemView::SingleSelection);
  } else {
    ui->widgets->setSelectionMode(QAbstractItemView::NoSelection);
  }
}

QString GroupList::genLua() {
  QString ret;
  for (int i = 0; i < ui->widgets->count(); ++i) {
    Group* group = dynamic_cast<Group*>(ui->widgets->itemWidget(ui->widgets->item(i)));
    if (group)
      ret += group->genLua();
  }
  return ret;
}

QString GroupList::genR() {
  QString ret;
  for (int i = 0; i < ui->widgets->count(); ++i) {
    Group* group = dynamic_cast<Group*>(ui->widgets->itemWidget(ui->widgets->item(i)));
    if (group)
      ret += group->genR();
  }
  return ret;
}

void GroupList::scrollToTop() {
  ui->widgets->scrollToTop();
}

Group* GroupList::addGroup() {
  Group* group = new Group;
  connect(group, SIGNAL(heightChanged(int)), SLOT(updateHeight(int)));
  addComponent(group);
  return group;
}

void GroupList::removeGroup() {
  QObject* wid = QObject::sender();
  if (!map.contains(wid)) return;

  delete ui->widgets->takeItem(ui->widgets->row(map.value(wid)));
}



void GroupList::updateHeight(int height) {
  QObject* wid = QObject::sender();
  if (!map.contains(wid)) return;

  QListWidgetItem* item = map[wid];
  item->setSizeHint(QSize(-1, height));

  ui->widgets->scrollToItem(item);
}

Component* GroupList::addComponent(Component* comp) {
  QListWidgetItem* item = new QListWidgetItem;

  item->setSizeHint(QSize(-1, comp->height()));

  ui->widgets->addItem(item);
  ui->widgets->setItemWidget(item, comp);
  ui->widgets->scrollToBottom();

  connect(comp, SIGNAL(remove()), SLOT(removeGroup()));

  map[comp] = item;

  return comp;
}


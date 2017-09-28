#ifndef GROUPLIST_H
#define GROUPLIST_H

#include <QtWidgets>
#include <QtXml>
#include "group.h"

namespace Ui {
class GroupEditor;
}

class GroupList : public QFrame {
  Q_OBJECT

 public:
  explicit GroupList(QWidget* parent = 0);
  ~GroupList();
  QDomDocument getXml();
  void setXml(QDomNode root);
  void setEditMode(bool enable);
  QString genLua();
  QString genR();
  void scrollToTop();

 private:
  Ui::GroupEditor* ui;
  QToolButton* add;
  QMap<QObject*, QListWidgetItem*> map;

 private slots:
  Group* addGroup();
  void removeGroup();
  void updateHeight(int height);
  Component* addComponent(Component* comp);
};

#endif // GROUPLIST_H


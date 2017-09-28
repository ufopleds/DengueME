#ifndef VISUALTABLEGROUP_H
#define VISUALTABLEGROUP_H

#include <QtWidgets>
#include <QtXml>

#include "component.h"
#include "components/VisualTableField.h"

namespace Ui {
class Group;
}

class VisualTableGroup : public Component {
  Q_OBJECT
 public:
  explicit VisualTableGroup(QWidget* parent = 0);
  ~VisualTableGroup();
  QDomDocument getXml();
  void setXml(QDomElement root);
  void setEditMode(bool enable);
  void setRemovable(bool enable);
  QString genLua();
  QString genR();
 protected:
  Ui::Group* ui;

 private:
  QMap<QListWidgetItem*, Component*> map;
  int listDefaultHeight;
  int defaultHeight;
  void updateHeight();

 private slots:
  inline void onRemove() {
    emit remove();
  }
  void removeField();
  void askRemoveGroup();
  void cloneField();
  void changeType(QString);


 public slots:


  VisualTableField* addVariable();
  void togglePlotCheckbox(bool);
  Component* addComponent(Component* comp);
  void validateId(QString name);
  QString purgeName(QString name) ;

 signals:
  void heightChanged(int);
};

#endif // VISUALTABLEGROUP_H

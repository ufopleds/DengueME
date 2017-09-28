#ifndef CHARTGROUP_H
#define CHARTGROUP_H

#include <QtWidgets>
#include <QtXml>

#include "component.h"
#include "components/chartfield.h"
#include "components/field.h"
namespace Ui {
class Group;
}

class ChartGroup: public Component {
  Q_OBJECT
 public:
  explicit ChartGroup(QWidget* parent = 0);
  ~ChartGroup();
  void setLabel(QString label);
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
  ChartField* addVariable();
  void togglePlotCheckbox(bool);
  Component* addComponent(Component* comp);
  void validateId(QString name);
  QString purgeName(QString name) ;

 signals:
  void heightChanged(int);
};

#endif // CHARTGROUP_H

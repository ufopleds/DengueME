#ifndef LOGGROUP_H
#define LOGGROUP_H

#include <QtWidgets>
#include <QtXml>

#include "component.h"
#include "components/logfield.h"

namespace Ui {
class Group;
}

class LogGroup: public Component {
  Q_OBJECT
 public:
  explicit LogGroup(QWidget* parent = 0);
  ~LogGroup();
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
  LogField* addVariable();
  void togglePlotCheckbox(bool);
  Component* addComponent(Component* comp);
  void validateId(QString name);
  QString purgeName(QString name) ;

 signals:
  void heightChanged(int);
};

#endif // LOGGROUP_H

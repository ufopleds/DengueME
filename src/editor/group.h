#ifndef GROUP_H
#define GROUP_H

#include <QtWidgets>
#include <QtXml>

#include "component.h"
#include "components/field.h"
#include "components/importcsv.h"

namespace Ui {
class Group;
}

class Group : public Component {
  Q_OBJECT

 public:
  explicit Group(QWidget* parent = 0);
  ~Group();
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
  void morphField(QString type);

 public slots:
  Field* addBoolean();
  Field* addText();
  Field* addInteger();
  Field* addFloating();
  Field* addEquation();
  //Field *addCheckbox();
  Field* addCombobox();
  ImportCsv* addCsv();
  Component* addComponent(Component* comp);
  void configureSimulation();
 signals:
  void heightChanged(int);
};

#endif // GROUP_H


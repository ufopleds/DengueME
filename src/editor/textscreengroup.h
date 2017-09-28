#ifndef TEXTSCREENGROUP_H
#define TEXTSCREENGROUP_H

#include <QtWidgets>
#include <QtXml>


#include "component.h"
#include "components/textscreenfield.h"

namespace Ui {
class Group;
}

class TextScreenGroup: public Component {
  Q_OBJECT
 public:
  explicit TextScreenGroup(QWidget* parent = 0);
  ~TextScreenGroup();
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


  TextScreenField* addVariable();
  void togglePlotCheckbox(bool);
  Component* addComponent(Component* comp);
  void validateId(QString name);
  QString purgeName(QString name) ;

 signals:
  void heightChanged(int);


};

#endif // TEXTSCREENGROUP_H

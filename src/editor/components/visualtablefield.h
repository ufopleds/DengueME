#ifndef VISUALTABLEFIELD_H
#define VISUALTABLEFIELD_H

#include <QtWidgets>
#include <QtXml>
#include "../component.h"

namespace Ui {
class VisualTableField;
}

class VisualTableField : public Component {
  Q_OBJECT

 public:
  enum FieldType { Null, Variable = 1};

  QMap<QString, QString> attr;
  QWidget* widget;

  explicit VisualTableField(QWidget* parent = 0);
  ~VisualTableField();
  QDomDocument getXml();
  void setXml(QDomElement node);
  void setEditMode(bool enable);
  QString genLua();
  QString genR();

 private:
  QMenu* menu;
  QAction* actionVariable;
  QAction* actionOptions;
  QAction* actionDelete;
  QAction* actionClone;
  Ui::VisualTableField* ui;
  FieldType type;

  void updateMenu();
  void setWidget(QWidget* widget);

 public slots:
  void onActionVariable();
  void onActionDelete();
  void onActionClone();
  void offField(bool);
  void onField(bool);
  void useLogVariable();
  void notUseLogVariable();
  void selectAllDefaultVars(bool select);
  void selectAllUseVars(bool select);
  void add();
  void del();
};

#endif // VISUALTABLEFIELD_H

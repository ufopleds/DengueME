#ifndef TEXTSCREENFIELD_H
#define TEXTSCREENFIELD_H

#include <QtWidgets>
#include <QtXml>
#include "../component.h"

namespace Ui {
class TextScreenField;
}

class TextScreenField : public Component {
  Q_OBJECT

 public:
  enum FieldType { Null, Variable = 1};

  QMap<QString, QString> attr;
  QWidget* widget;

  explicit TextScreenField(QWidget* parent = 0);
  ~TextScreenField();
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
  Ui::TextScreenField* ui;
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

#endif // TEXTSCREENFIELD_H

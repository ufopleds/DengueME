#ifndef CHARTFIELD_H
#define CHARTFIELD_H

#include <QtWidgets>
#include <QtXml>
#include "../component.h"

namespace Ui {
class ChartField;
}

class ChartField : public Component {
  Q_OBJECT

 public:
  enum FieldType { Null, Variable = 1};

  QMap<QString, QString> attr;
  QWidget* widget;

  explicit ChartField(QWidget* parent = 0);
  ~ChartField();
  QDomDocument getXml();
  void setXml(QDomElement node);
  void setLabel(QString label);
  void setId(QString id);
  void setEditMode(bool enable);
  QString genLua();
  QString genR();

 private:
  QMenu* menu;
  QAction* actionVariable;
  QAction* actionOptions;
  QAction* actionDelete;
  QAction* actionClone;
  Ui::ChartField* ui;
  FieldType type;

  void updateMenu();
  void setWidget(QWidget* widget);

 public slots:
  void onActionVariable();
  void onActionDelete();
  void onActionClone();
  void offField(bool);
  void onField(bool);
  void validateId(QString);
  QString purgeName(QString);

};

#endif // CHARTFIELD_H

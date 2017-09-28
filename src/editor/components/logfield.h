#ifndef LOGFIELD_H
#define LOGFIELD_H

#include <QtWidgets>
#include <QtXml>
#include "../component.h"
#include <QtAlgorithms>
namespace Ui {
class LogField;
}

class LogField : public Component {
  Q_OBJECT

 public:
  enum FieldType { Null, Variable = 1};

  QMap<QString, QString> attr;
  QWidget* widget;

  explicit LogField(QWidget* parent = 0);
  ~LogField();
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
  Ui::LogField* ui;
  FieldType type;

  void updateMenu();
  void setWidget(QWidget* widget);

 public slots:
  void onActionVariable();
  void onActionDelete();
  void offField(bool enable);
  void onField(bool);
  void useLogVariable();
  void notUseLogVariable();
  void validateId(QString);
  QString purgeName(QString);
  void selectAllDefaultVars(bool select);
  void selectAllUseVars(bool select);
  void add();
  void del();
};

#endif // LOGFIELD_H

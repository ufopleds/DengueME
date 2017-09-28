#ifndef FIELD_H
#define FIELD_H

#include <QtWidgets>
#include <QtXml>
#include "../component.h"
#include "calculator/lepton/Lepton.h"

namespace Ui {
class Field;
}

class Field : public Component {
  Q_OBJECT

 public:
  enum FieldType { Null, Text = 1, Integer, Floating, Checkbox, Combobox, Boolean, Equation};

  QMap<QString, QString> attr;
  QWidget* widget;

  explicit Field(QWidget* parent = 0);
  ~Field();
  QDomDocument getXml();
  void setXml(QDomElement node);
  void setLabel(QString label);
  void setId(QString id);
  void setEditMode(bool enable);
  QString genLua();
  QString genR();

 private:
  QMenu*   menu;
  QAction* actionText;
  QAction* actionBoolean;
  QAction* actionCsv;
  QAction* actionInteger;
  QAction* actionFloating;
  QAction* actionCheckbox;
  QAction* actionCombobox;
  QAction* actionEquation;
  QAction* actionOptions;
  QAction* actionDelete;
  QAction* actionClone;
  Ui::Field* ui;
  FieldType type;
  Lepton::Parser parser;

  void updateMenu();
  void setWidget(QWidget* widget);

 public slots:
  void onActionBoolean();
  void onActionText();
  void onActionInteger();
  void onActionFloating();
  void onActionCheckbox();
  void onActionCombobox();
  bool onActionOptions();
  void onActionDelete();
  void onActionClone();
  void onActionEquation();
  void onActionCsv();
  void configureField();
  void onActionCalculator();

 private slots:
  void onSentEquation(QString);

};

#endif // FIELD_H


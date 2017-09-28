#ifndef COMBOBOXRULES_H
#define COMBOBOXRULES_H

#include <QtWidgets>

namespace Ui {
class ComboBoxRules;
}

class ComboBoxRules : public QDialog {
  Q_OBJECT

 public:
  explicit ComboBoxRules(QWidget* parent = 0);
  ~ComboBoxRules();
  QList<QString> items();
  void setItems(QList<QString> items);

 private:
  Ui::ComboBoxRules* ui;

 public slots:
  void add();
  void del();
};

#endif // COMBOBOXRULES_H


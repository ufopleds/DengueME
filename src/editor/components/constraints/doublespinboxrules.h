#ifndef DOUBLESPINBOXRULES_H
#define DOUBLESPINBOXRULES_H

#include <QDialog>

namespace Ui {
class DoubleSpinBoxRules;
}

class DoubleSpinBoxRules : public QDialog {
  Q_OBJECT

 public:
  explicit DoubleSpinBoxRules(QWidget* parent = 0);
  ~DoubleSpinBoxRules();
  QMap<QString, QString> attributes();
  void setAttributes(QMap<QString, QString> const& attr);

 private:
  Ui::DoubleSpinBoxRules* ui;

 public slots:
  void precisionChanged(int p);
  void minimumChanged(double n);
  void maximumChanged(double n);
  void stepChanged(double n);
};

#endif // DOUBLESPINBOXRULES_H


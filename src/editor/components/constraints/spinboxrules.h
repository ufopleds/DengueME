#ifndef SPINBOXRULES_H
#define SPINBOXRULES_H

#include <QDialog>

namespace Ui {
class SpinBoxRules;
}

class SpinBoxRules : public QDialog {
  Q_OBJECT

 public:
  explicit SpinBoxRules(QWidget* parent = 0);
  ~SpinBoxRules();
  QMap<QString, QString> attributes();
  void setAttributes(QMap<QString, QString> const& attr);

 private:
  Ui::SpinBoxRules* ui;

 public slots:
  void minimumChanged(int n);
  void maximumChanged(int n);
};

#endif // SPINBOXRULES_H


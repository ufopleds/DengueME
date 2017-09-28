#include <limits>
#include <cmath>
#include "doublespinboxrules.h"
#include "ui_doublespinboxrules.h"

DoubleSpinBoxRules::DoubleSpinBoxRules(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::DoubleSpinBoxRules) {
  ui->setupUi(this);
  ui->precision->setValue(2);
  ui->minimum->setMinimum(-std::numeric_limits<double>::max());
  ui->minimum->setMaximum(0);
  ui->maximum->setMinimum(0);
  ui->maximum->setMaximum(std::numeric_limits<double>::max());
}

DoubleSpinBoxRules::~DoubleSpinBoxRules() {
  delete ui;
}

QMap<QString, QString> DoubleSpinBoxRules::attributes() {
  QMap<QString, QString> ret;
  ret.insert("precision", QString::number(ui->precision->value()));
  ret.insert("minimum", QString::number(ui->minimum->value(), 'f', ui->precision->value()));
  ret.insert("maximum", QString::number(ui->maximum->value(), 'f', ui->precision->value()));
  ret.insert("step", QString::number(ui->step->value(), 'f', ui->precision->value()));
  return ret;
}

void DoubleSpinBoxRules::setAttributes(const QMap<QString, QString>& attr) {
  ui->precision->setValue(attr["precision"].toInt());
  ui->minimum->setValue(attr["minimum"].toDouble());
  ui->maximum->setValue(attr["maximum"].toDouble());
  ui->step->setValue(attr["step"].toDouble());
}

void DoubleSpinBoxRules::precisionChanged(int p) {
  ui->minimum->setDecimals(p);
  ui->maximum->setDecimals(p);
  ui->step->setDecimals(p);

  double min = 1.0 / std::pow(10, p);
  ui->step->setValue(min);
  ui->step->setSingleStep(min);
}

void DoubleSpinBoxRules::minimumChanged(double n) {
  ui->maximum->setMinimum(n);
}

void DoubleSpinBoxRules::maximumChanged(double n) {
  ui->minimum->setMaximum(n);
}

void DoubleSpinBoxRules::stepChanged(double n) {
  ui->minimum->setSingleStep(n);
  ui->maximum->setSingleStep(n);
}

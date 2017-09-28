#include <limits>
#include <QtXml>

#include "spinboxrules.h"
#include "ui_spinboxrules.h"

SpinBoxRules::SpinBoxRules(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::SpinBoxRules) {
  ui->setupUi(this);
  ui->minimum->setMinimum(std::numeric_limits<int>::min());
  ui->minimum->setMaximum(0);
  ui->maximum->setMinimum(0);
  ui->maximum->setMaximum(std::numeric_limits<int>::max());
}

SpinBoxRules::~SpinBoxRules() {
  delete ui;
}

QMap<QString, QString> SpinBoxRules::attributes() {
  QMap<QString, QString> ret;
  ret.insert("minimum", QString::number(ui->minimum->value()));
  ret.insert("maximum", QString::number(ui->maximum->value()));
  return ret;
}

void SpinBoxRules::setAttributes(const QMap<QString, QString>& attr) {
  ui->minimum->setValue(attr.value("minimum").toDouble());
  ui->maximum->setValue(attr.value("maximum").toDouble());
}

void SpinBoxRules::minimumChanged(int n) {
  ui->maximum->setMinimum(n);
}

void SpinBoxRules::maximumChanged(int n) {
  ui->minimum->setMaximum(n);
}


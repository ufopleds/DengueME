#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtWidgets>
#include "lepton/Lepton.h"

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow {
  Q_OBJECT

 public:
  explicit Calculator(QWidget* parent = 0);
  ~Calculator();
  QString getEquation() const;
  void setEquation(const QString& equationFromField);

 private:
  Ui::Calculator* ui;
  Lepton::Parser parser;
  int getNumberOfDigits();
  bool check_displayIsZero();

 private slots:
  void onDigitPressed();
  void onPointPressed();
  void onClearPressed();
  void onOperationPressed();
  void onErasePressed();
  void onParenthesisPressed();
  void onOkPressed();
  void evaluate();

 signals:
  void sendEquation(QString);
};

#endif // CALCULATOR_H

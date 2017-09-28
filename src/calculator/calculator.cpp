#include "calculator.h"
#include "ui_calculator.h"
#include "../editor/components/field.h"

Calculator::Calculator(QWidget* parent) : QMainWindow(parent),
  ui(new Ui::Calculator) {
  this->setWindowModality(Qt::ApplicationModal);
  this->setWindowFlags(Qt::Tool | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint);
  ui->setupUi(this);

  connect(ui->toolButtonZero,  SIGNAL(pressed()), this, SLOT(onDigitPressed()));
  connect(ui->toolButtonOne,   SIGNAL(pressed()), this, SLOT(onDigitPressed()));
  connect(ui->toolButtonTwo,   SIGNAL(pressed()), this, SLOT(onDigitPressed()));
  connect(ui->toolButtonThree, SIGNAL(pressed()), this, SLOT(onDigitPressed()));
  connect(ui->toolButtonFour,  SIGNAL(pressed()), this, SLOT(onDigitPressed()));
  connect(ui->toolButtonFive,  SIGNAL(pressed()), this, SLOT(onDigitPressed()));
  connect(ui->toolButtonSix,   SIGNAL(pressed()), this, SLOT(onDigitPressed()));
  connect(ui->toolButtonSeven, SIGNAL(pressed()), this, SLOT(onDigitPressed()));
  connect(ui->toolButtonEight, SIGNAL(pressed()), this, SLOT(onDigitPressed()));
  connect(ui->toolButtonNine,  SIGNAL(pressed()), this, SLOT(onDigitPressed()));

  connect(ui->toolButtonZero,  SIGNAL(released()), this, SLOT(evaluate()));
  connect(ui->toolButtonOne,   SIGNAL(released()), this, SLOT(evaluate()));
  connect(ui->toolButtonTwo,   SIGNAL(released()), this, SLOT(evaluate()));
  connect(ui->toolButtonThree, SIGNAL(released()), this, SLOT(evaluate()));
  connect(ui->toolButtonFour,  SIGNAL(released()), this, SLOT(evaluate()));
  connect(ui->toolButtonFive,  SIGNAL(released()), this, SLOT(evaluate()));
  connect(ui->toolButtonSix,   SIGNAL(released()), this, SLOT(evaluate()));
  connect(ui->toolButtonSeven, SIGNAL(released()), this, SLOT(evaluate()));
  connect(ui->toolButtonEight, SIGNAL(released()), this, SLOT(evaluate()));
  connect(ui->toolButtonNine,  SIGNAL(released()), this, SLOT(evaluate()));

  connect(ui->toolButtonPlus,     SIGNAL(pressed()), this, SLOT(onOperationPressed()));
  connect(ui->toolButtonMinus,    SIGNAL(pressed()), this, SLOT(onOperationPressed()));
  connect(ui->toolButtonMultiply, SIGNAL(pressed()), this, SLOT(onOperationPressed()));
  connect(ui->toolButtonDivide,   SIGNAL(pressed()), this, SLOT(onOperationPressed()));

  connect(ui->toolButtonPlus,     SIGNAL(released()), this, SLOT(evaluate()));
  connect(ui->toolButtonMinus,    SIGNAL(released()), this, SLOT(evaluate()));
  connect(ui->toolButtonMultiply, SIGNAL(released()), this, SLOT(evaluate()));
  connect(ui->toolButtonDivide,   SIGNAL(released()), this, SLOT(evaluate()));

  connect(ui->toolButtonParenthesisBegin, SIGNAL(pressed()), this, SLOT(onParenthesisPressed()));
  connect(ui->toolButtonParenthesisEnd,   SIGNAL(pressed()), this, SLOT(onParenthesisPressed()));

  connect(ui->toolButtonParenthesisBegin, SIGNAL(released()), this, SLOT(evaluate()));
  connect(ui->toolButtonParenthesisEnd,   SIGNAL(released()), this, SLOT(evaluate()));

  connect(ui->toolButtonPoint, SIGNAL(pressed()),  this, SLOT(onPointPressed()));
  connect(ui->toolButtonPoint, SIGNAL(released()), this, SLOT(evaluate()));

  connect(ui->toolButtonErase, SIGNAL(pressed()),  this, SLOT(onErasePressed()));
  connect(ui->toolButtonErase, SIGNAL(released()), this, SLOT(evaluate()));

  connect(ui->toolButtonClear, SIGNAL(pressed()),  this, SLOT(onClearPressed()));
  connect(ui->toolButtonClear, SIGNAL(released()), this, SLOT(evaluate()));

  connect(ui->toolButtonOK, SIGNAL(released()), this, SLOT(onOkPressed()));
}

Calculator::~Calculator() {
  delete ui;
}

void Calculator::onOkPressed() {
  if (ui->result->text() == "error") {
    return;
  } else {
    emit sendEquation(ui->display->text());
    this->close();
  }
}

void Calculator::onDigitPressed() {
  QToolButton* clickedButton =  (QToolButton*)sender();
  if(getNumberOfDigits() < 25) {
    if (check_displayIsZero() == true) {
      ui->display->setText(clickedButton->text());
    } else {
      ui->display->setText(ui->display->text() + clickedButton->text());
    }
  }
}

void Calculator::onPointPressed() {
  if(getNumberOfDigits() < 25) {
    ui->display->setText(ui->display->text() + tr("."));
  }
}

void Calculator::onClearPressed() {
  ui->display->setText("0");
}

void Calculator::onOperationPressed() {
  QToolButton* clickedButton = (QToolButton*)sender();
  QString clickedOperator = clickedButton->text();
  if (check_displayIsZero() == false) {
    if(getNumberOfDigits() < 25) {
      if (clickedOperator == "+") {
        ui->display->setText(ui->display->text() + clickedButton->text());
      } else if (clickedOperator == "-") {
        ui->display->setText(ui->display->text() + clickedButton->text());
      } else if (clickedOperator == "*") {
        ui->display->setText(ui->display->text() + clickedButton->text());
      } else if (clickedOperator == "/") {
        ui->display->setText(ui->display->text() + clickedButton->text());
      }
    }
  }
}

void Calculator::onParenthesisPressed() {
  QToolButton* clickedButton = (QToolButton*)sender();
  if(getNumberOfDigits() < 25) {
    if (check_displayIsZero() == true)
      ui->display->setText(clickedButton->text());
    else
      ui->display->setText(ui->display->text() + clickedButton->text());
  }
}

void Calculator::onErasePressed() {
  if (check_displayIsZero() == false) {
    QString displayedText = ui->display->text();
    displayedText.remove(displayedText.length() - 1, 1);
    ui->display->setText(displayedText);
  }
}

void Calculator::evaluate() {
  try {
    QString expr = ui->display->text();
    parser.parse(expr.toStdString()).evaluate();
    ui->result->setText("");
    ui->toolButtonOK->setDisabled(false);
  } catch(Lepton::Exception e) {
    ui->result->setStyleSheet("QLabel {qproperty-alignment: 'AlignVCenter | AlignRight'; border: 1px solid gray; background-color : #F8F8F8; font-weight: bold; color:darkRed }");
    ui->result->setText("error");
    ui->toolButtonOK->setDisabled(true);
  }

}

bool Calculator::check_displayIsZero() {
  return (ui->display->text() == "0") ? true : false;
}

void Calculator::setEquation(const QString& equationFromField) {
  ui->display->setText(equationFromField);
  return;
}

int Calculator::getNumberOfDigits() {
  return ui->display->text().length() - 1;

}

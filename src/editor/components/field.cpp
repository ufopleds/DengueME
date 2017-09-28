#include <limits>
#include "field.h"
#include "ui_field.h"
#include "importcsv.h"
#include "calculator/calculator.h"
#include "constraints/doublespinboxrules.h"
#include "constraints/spinboxrules.h"
#include "constraints/comboboxrules.h"

struct EditableCheckbox : public QWidget {
  QCheckBox* checkbox;
  QLineEdit* lineedit;

  EditableCheckbox() :
    checkbox(new QCheckBox),
    lineedit(new QLineEdit) {
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    checkbox->setMaximumWidth(checkbox->sizeHint().height());
    layout->addWidget(checkbox);

    lineedit->setStyleSheet("background-color:transparent;");
    lineedit->setFrame(false);
    layout->addWidget(lineedit);
  }

  bool isChecked() {
    return checkbox->isChecked();
  }

  void setChecked(bool check) {
    return checkbox->setChecked(check);
  }

  QString name() {
    return lineedit->text();
  }

  void setName(QString name) {
    return lineedit->setText(name);
  }
};

Field::Field(QWidget* parent) :
  Component(parent),
  widget(NULL),
  ui(new Ui::Field),
  type(Null) {
  ui->setupUi(this);

  attr["precision"] = QString::number(3);
  attr["step"] = QString::number(0.001);
  attr["minimum"] = QString::number(-999999.999);
  attr["maximum"] = QString::number(999999.999);

  menu = new QMenu(this);

  actionCsv      = new QAction(tr("&Csv"), menu);
  actionBoolean  = new QAction(tr("&Boolean"), menu);
  actionText     = new QAction(tr("&Text"), menu);
  actionInteger  = new QAction(tr("&Integer"), menu);
  actionFloating = new QAction(tr("&Floating point"), menu);
  actionCheckbox = new QAction(tr("&Checkbox"), menu);
  actionCombobox = new QAction(tr("C&ombobox"), menu);
  actionOptions  = new QAction(tr("&Options"), menu);
  actionDelete   = new QAction(tr("&Delete"), menu);
  actionClone    = new QAction(tr("Cl&one"), menu);
  actionEquation = new QAction(tr("&Equation"), menu);

  actionCsv      ->setCheckable(true);
  actionBoolean  ->setCheckable(true);
  actionText     ->setCheckable(true);
  actionInteger  ->setCheckable(true);
  actionFloating ->setCheckable(true);
  actionCombobox ->setCheckable(true);
  actionEquation ->setCheckable(true);

  menu->addAction(actionCsv);
  menu->addAction(actionBoolean);
  menu->addAction(actionText);
  menu->addAction(actionInteger);
  menu->addAction(actionFloating);
  menu->addAction(actionCombobox);
  menu->addAction(actionEquation);

  ui->options->setMenu(menu);

  connect(actionCsv,       SIGNAL(triggered()), SLOT(onActionCsv()));
  connect(actionBoolean,   SIGNAL(triggered()), SLOT(onActionBoolean()));
  connect(actionText,      SIGNAL(triggered()), SLOT(onActionText()));
  connect(actionInteger,   SIGNAL(triggered()), SLOT(onActionInteger()));
  connect(actionFloating,  SIGNAL(triggered()), SLOT(onActionFloating()));
  connect(actionCombobox,  SIGNAL(triggered()), SLOT(onActionCombobox()));
  connect(actionEquation,  SIGNAL(triggered()), SLOT(onActionEquation()));

  connect(ui->toolOptions,    SIGNAL(clicked()),   SLOT(onActionOptions()));
  connect(ui->toolDelete,     SIGNAL(clicked()),   SLOT(onActionDelete()));
  connect(ui->toolClone,      SIGNAL(clicked()),   SLOT(onActionClone()));
  connect(ui->toolCalculator, SIGNAL(clicked()),   SLOT(onActionCalculator()));

  ui->toolOptions->setToolTip(tr("Options"));
  ui->toolDelete->setToolTip(tr("Delete"));
  ui->toolClone->setToolTip(tr("Clone"));
  updateMenu();
}

Field::~Field() {
  delete ui;
}
void Field::onActionCsv() {
  emit remove();
  emit csv("csv");
}

QDomDocument Field::getXml() {
  QDomDocument ret;
  QDomElement node = ret.createElement("field");

  switch (type) {
    case Integer: {
      node.setAttribute("type", "spinbox");

      QSpinBox* field = dynamic_cast<QSpinBox*>(widget);
      if (field)
        node.appendChild(ret.createTextNode(QString::number(field->value())));

      node.setAttribute("label", ui->label->text());
      node.setAttribute("id", ui->var->text());
      node.setAttribute("minimum", attr["minimum"]);
      node.setAttribute("maximum", attr["maximum"]);
      node.setAttribute("description", ui->descript->text());

      ret.appendChild(node);
      break;
    }
    case Floating: {
      node.setAttribute("type", "doublespinbox");

      QDoubleSpinBox* field = dynamic_cast<QDoubleSpinBox*>(widget);
      if (field)
        node.appendChild(ret.createTextNode(QString::number(field->value(), 'f', attr["precision"].toInt())));

      node.setAttribute("label", ui->label->text());
      node.setAttribute("id", ui->var->text());
      node.setAttribute("precision", attr["precision"]);
      node.setAttribute("step", attr["step"]);
      node.setAttribute("minimum", attr["minimum"]);
      node.setAttribute("maximum", attr["maximum"]);
      node.setAttribute("description", ui->descript->text());

      ret.appendChild(node);
      break;
    }
    case Text: {
      node.setAttribute("type", "lineedit");

      QLineEdit* field = dynamic_cast<QLineEdit*>(widget);
      if (field)
        node.appendChild(ret.createTextNode(field->text()));

      node.setAttribute("label", ui->label->text());
      node.setAttribute("id", ui->var->text());
      node.setAttribute("description", ui->descript->text());

      ret.appendChild(node);
      break;
    }
    case Equation: {
      node.setAttribute("type", "equation");

      QLineEdit* field = dynamic_cast<QLineEdit*>(widget);
      if (field)
        node.appendChild(ret.createTextNode(field->text()));

      node.setAttribute("label", ui->label->text());
      node.setAttribute("id", ui->var->text());
      node.setAttribute("description", ui->descript->text());

      ret.appendChild(node);
      break;
    }
    case Boolean: {
      node.setAttribute("type", "boolean");

      EditableCheckbox* field = dynamic_cast<EditableCheckbox*>(widget);
      if (field) {
        node.setAttribute("name", field->name());
        node.appendChild(ret.createTextNode(field->isChecked() ? "true" : "false"));
      }

      node.setAttribute("label", ui->label->text());
      node.setAttribute("id", ui->var->text());
      node.setAttribute("description", ui->descript->text());

      ret.appendChild(node);
      break;
    }
    case Checkbox: {
      node.setAttribute("type", "checkbox");

      EditableCheckbox* field = dynamic_cast<EditableCheckbox*>(widget);
      if (field) {
        node.setAttribute("name", field->name());
        node.appendChild(ret.createTextNode(field->isChecked() ? "true" : "false"));
      }

      node.setAttribute("label", ui->label->text());
      node.setAttribute("id", ui->var->text());
      node.setAttribute("description", ui->descript->text());

      ret.appendChild(node);
      break;
    }
    case Combobox: {
      node.setAttribute("type", "combobox");

      QComboBox* field = dynamic_cast<QComboBox*>(widget);
      if (field) {
        node.setAttribute("value", field->currentText());

        for (int i = 0; i < field->count(); ++i) {
          QDomElement opt = ret.createElement("option");
          opt.appendChild(ret.createTextNode(field->itemText(i)));
          node.appendChild(opt);
        }
      }

      node.setAttribute("label", ui->label->text());
      node.setAttribute("id", ui->var->text());
      node.setAttribute("description", ui->descript->text());

      ret.appendChild(node);
      break;
    }
    default:
      break;
  }
  return ret;
}
void Field::configureField() {
  ui->toolClone->setVisible(false);
  ui->toolDelete->setVisible(false);
  ui->options->setVisible(false);
  ui->toolOptions->setVisible(false);
  ui->toolCalculator->setVisible(false);
}

void Field::setXml(QDomElement node) {
  if (node.attribute("type").compare("spinbox") == 0) {
    ui->label->setText(node.attribute("label"));
    ui->var->setText(node.attribute("id"));
    ui->descript->setText(node.attribute("description"));
    attr["minimum"] = node.attribute("minimum");
    attr["maximum"] = node.attribute("maximum");
    onActionInteger();
    QSpinBox* field = dynamic_cast<QSpinBox*>(widget);
    if (field)
      field->setValue(node.text().toInt());

  } else if (node.attribute("type").compare("doublespinbox") == 0) {
    ui->label->setText(node.attribute("label"));
    ui->var->setText(node.attribute("id"));
    ui->descript->setText(node.attribute("description"));
    attr["precision"] = node.attribute("precision");
    attr["step"] = node.attribute("step");
    attr["minimum"] = node.attribute("minimum");
    attr["maximum"] = node.attribute("maximum");
    onActionFloating();
    QDoubleSpinBox* field = dynamic_cast<QDoubleSpinBox*>(widget);
    if (field)
      field->setValue(node.text().toDouble());

  } else if (node.attribute("type").compare("equation") == 0) {
    ui->label->setText(node.attribute("equation"));
    ui->label->setText(node.attribute("label"));
    ui->var->setText(node.attribute("id"));
    ui->descript->setText(node.attribute("description"));
    onActionEquation();
    QLineEdit* field = dynamic_cast<QLineEdit*>(widget);
    if (field)
      field->setText(node.text());

  } else if (node.attribute("type").compare("lineedit") == 0) {
    ui->label->setText(node.attribute("label"));
    ui->var->setText(node.attribute("id"));
    ui->descript->setText(node.attribute("description"));

    onActionText();
    QLineEdit* field = dynamic_cast<QLineEdit*>(widget);
    if (field)
      field->setText(node.text());
  } else if (node.attribute("type").compare("checkbox") == 0) {
    ui->label->setText(node.attribute("label"));
    ui->var->setText(node.attribute("id"));
    ui->descript->setText(node.attribute("description"));

    onActionBoolean();
    EditableCheckbox* field = dynamic_cast<EditableCheckbox*>(widget);
    if (field) {
      field->setChecked(node.text().compare("true", Qt::CaseInsensitive) == 0);
      field->setName(node.attribute("name"));
    }
  } else if (node.attribute("type").compare("boolean") == 0) {
    ui->label->setText(node.attribute("label"));
    ui->var->setText(node.attribute("id"));
    ui->descript->setText(node.attribute("description"));

    onActionBoolean();
    EditableCheckbox* field = dynamic_cast<EditableCheckbox*>(widget);
    if (field) {
      field->setChecked(node.text().compare("true", Qt::CaseInsensitive) == 0);
      field->setName(node.attribute("name"));
    }
  } else if (node.attribute("type").compare("combobox") == 0) {
    ui->label->setText(node.attribute("label"));
    ui->var->setText(node.attribute("id"));
    ui->descript->setText(node.attribute("description"));
    onActionCombobox();
    QComboBox* field = dynamic_cast<QComboBox*>(widget);

    for (QDomElement opt = node.firstChildElement("option"); !opt.isNull(); opt = opt.nextSiblingElement("option"))
      field->addItem(opt.text());

    field->setCurrentIndex(field->findText(node.attribute("value")));
  }
}

void Field::setLabel(QString label) {
  ui->label->setText(label);
}

void Field::setId(QString id) {
  ui->var->setText(id);
}

void Field::setEditMode(bool enable) {
  ui->options->setVisible(enable);
  ui->var->setVisible(enable);
  ui->line->setVisible(enable);
  ui->descript->setVisible(enable);
  ui->label->setReadOnly(!enable);
  ui->toolOptions->setVisible(enable);
  ui->toolClone->setVisible(enable);
  ui->toolDelete->setVisible(enable);

  ui->toolCalculator->setVisible(type == Equation);

  if (type == Boolean) {
    EditableCheckbox* field = dynamic_cast<EditableCheckbox*>(widget);
    if (field)
      field->lineedit->setReadOnly(!enable);
  }

  if (enable) {
    ui->container->setToolTip("Default value");
    ui->label->setToolTip("Label");
    ui->label->setPlaceholderText("Label...");
    ui->label->setAlignment(Qt::AlignLeft);
    ui->horizontalLayout->setStretch(ui->horizontalLayout->indexOf(ui->container), 0);
  } else {
    ui->container->setToolTip("");
    ui->label->setToolTip("");
    ui->label->setPlaceholderText("");
    ui->label->setAlignment(Qt::AlignRight);
    ui->horizontalLayout->setStretch(ui->horizontalLayout->indexOf(ui->container), 5);
  }
}

QString Field::genLua() {
  if (!type || !widget) return QString();

  QString ret = ui->var->text() + " = ";

  switch (type) {
    case Integer: {
      QSpinBox* field = dynamic_cast<QSpinBox*>(widget);
      if (field)
        ret += QString::number(field->value());
      ret += " -- " + ui->descript->text();

      break;
    }
    case Boolean: {
      EditableCheckbox* field = dynamic_cast<EditableCheckbox*>(widget);
      if (field) {
        ret += field->isChecked() ? "true" : "false";
        ret += " -- " + ui->descript->text();
      }
      break;
    }
    case Floating: {
      QDoubleSpinBox* field = dynamic_cast<QDoubleSpinBox*>(widget);
      if (field)
        ret += QString::number(field->value(), 'f', attr["precision"].toInt());
      ret += " -- " + ui->descript->text();
      break;
    }
    case Text: {
      QLineEdit* field = dynamic_cast<QLineEdit*>(widget);
      if (field) {
        ret += "\"";
        ret += field->text().replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n");
        ret += "\"";

        ret += " -- " + ui->descript->text();
      }
      break;
    }
    case Equation: {
      QLineEdit* field = dynamic_cast<QLineEdit*>(widget);
      QString expr = field->text();
      double value = parser.parse(expr.toStdString()).evaluate();
      if (field) {
        ret += QString::number(value, 'f', attr["precision"].toInt());
        ret += " -- " + ui->descript->text();
      }
      break;
    }
    case Checkbox: {
      EditableCheckbox* field = dynamic_cast<EditableCheckbox*>(widget);
      if (field) {
        ret += field->isChecked() ? "true" : "false";
        ret += " -- " + ui->descript->text();
      }
      break;
    }
    case Combobox: {
      QComboBox* field = dynamic_cast<QComboBox*>(widget);
      if (field) {
        ret += "\"";
        ret += field->currentText().replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n");
        ret += "\"";

        ret += " -- " + ui->descript->text();
      }
      break;
    }
    default:
      break;
  }

  ret += "\n";

  return ret;
}

QString Field::genR() {
  if (!type || !widget) return QString();
  QString ret = ui->var->text() + " <- ";

  switch (type) {
    case Integer: {
      QSpinBox* field = dynamic_cast<QSpinBox*>(widget);
      if (field)
        ret += QString::number(field->value());
      ret += " # " + ui->descript->text();

      break;
    }
    case Boolean: {
      EditableCheckbox* field = dynamic_cast<EditableCheckbox*>(widget);
      if (field) {
        ret += field->isChecked() ? "true" : "false";
        ret += " #" + ui->descript->text();
      }
      break;
    }
    case Floating: {
      QDoubleSpinBox* field = dynamic_cast<QDoubleSpinBox*>(widget);
      if (field)
        ret += QString::number(field->value(), 'f', attr["precision"].toInt());
      ret += " # " + ui->descript->text();
      break;
    }
    case Equation: {
      QLineEdit* field = dynamic_cast<QLineEdit*>(widget);
      QString expr = field->text();
      double value = parser.parse(expr.toStdString()).evaluate();
      if (field)
        ret += QString::number(value, 'f', attr["precision"].toInt());
      ret += " # " + ui->descript->text();
      break;
    }
    case Text: {
      QLineEdit* field = dynamic_cast<QLineEdit*>(widget);
      if (field) {
        ret += "\"";
        ret += field->text().replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n");
        ret += "\"";
        ret += " #  " + ui->descript->text();
      }
      break;
    }
    case Checkbox: {
      EditableCheckbox* field = dynamic_cast<EditableCheckbox*>(widget);
      if (field) {
        ret += field->isChecked() ? "true" : "false";
        ret += " # " + ui->descript->text();
      }
      break;
    }
    case Combobox: {
      QComboBox* field = dynamic_cast<QComboBox*>(widget);
      if (field) {
        ret += "\"";
        ret += field->currentText().replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n");
        ret += "\"";
        ret += " #" + ui->descript->text();
      }
      break;
    }
    default:
      break;
  }

  ret += "\n";
  return ret;
}

void Field::updateMenu() {
  actionBoolean  ->setChecked(type == Boolean);
  actionText     ->setChecked(type == Text);
  actionInteger  ->setChecked(type == Integer);
  actionFloating ->setChecked(type == Floating);
  actionCheckbox ->setChecked(type == Checkbox);
  actionCombobox ->setChecked(type == Combobox);
  actionEquation ->setChecked(type == Equation);

  ui->toolOptions->setDisabled(type == Text || type == Boolean || type == Equation);

  if (type != Equation) {
    ui->toolCalculator->setVisible(false);
  } else {
    ui->toolCalculator->setVisible(true);
    QLineEdit* field = dynamic_cast<QLineEdit*>(widget);
    if(field)
      field->setReadOnly(true);
  }
}

void Field::setWidget(QWidget* widget) {
  delete this->widget;
  this->widget = widget;

  widget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  widget->setMinimumWidth(160);
  widget->setMaximumWidth(160);

  ui->container->layout()->addWidget(widget);
  ui->container->layout()->setAlignment(widget, Qt::AlignLeft);

  setTabOrder(ui->label, widget);
  setTabOrder(widget, ui->options);

  updateMenu();
}

void Field::onActionBoolean() {
  type = Boolean;
  emit changeType("Boolean");
  setWidget(new EditableCheckbox);
}

void Field::onActionText() {
  type = Text;
  emit changeType("Text");
  setWidget(new QLineEdit);
}

void Field::onActionEquation() {
  type = Equation;
  emit changeType("Equation");
  setWidget(new QLineEdit);
}

void Field::onActionInteger() {
  type = Integer;
  emit changeType("Integer");
  QSpinBox* w = new QSpinBox;
  double x;
  w->setMinimum(x = attr["minimum"].toDouble());
  w->setMaximum(attr["maximum"].toDouble());
  setWidget(w);
}

void Field::onActionFloating() {
  type = Floating;
  emit changeType("Float");
  QDoubleSpinBox* w = new QDoubleSpinBox;
  w->setDecimals(attr["precision"].toInt());
  w->setSingleStep(attr["step"].toDouble());
  w->setMinimum(attr["minimum"].toDouble());
  w->setMaximum(attr["maximum"].toDouble());
  setWidget(w);
}

void Field::onActionCheckbox() {
  type = Checkbox;
  emit changeType("Boolean");
  setWidget(new EditableCheckbox);
}

void Field::onActionCombobox() {
  type = Combobox;
  emit changeType("Combobox");
  setWidget(new QComboBox);
}

bool Field::onActionOptions() {
  switch (type) {
    case Integer: {
      SpinBoxRules integerRules;
      integerRules.setAttributes(attr);
      if (!integerRules.exec())
        break;

      QMap<QString, QString> t = integerRules.attributes();
      attr["minimum"] = t["minimum"];
      attr["maximum"] = t["maximum"];

      QSpinBox* field = dynamic_cast<QSpinBox*>(widget);
      if (field) {
        field->setMinimum(attr["minimum"].toDouble());
        field->setMaximum(attr["maximum"].toDouble());
      }
      return true;
    }
    case Floating: {
      DoubleSpinBoxRules floatingRules;
      floatingRules.setAttributes(attr);
      if (!floatingRules.exec())
        break;

      QMap<QString, QString> t = floatingRules.attributes();
      attr["precision"] = t["precision"];
      attr["step"] = t["step"];
      attr["minimum"] = t["minimum"];
      attr["maximum"] = t["maximum"];

      QDoubleSpinBox* field = dynamic_cast<QDoubleSpinBox*>(widget);
      if (field) {
        field->setDecimals(attr["precision"].toDouble());
        field->setSingleStep(attr["step"].toDouble());
        field->setMinimum(attr["minimum"].toDouble());
        field->setMaximum(attr["maximum"].toDouble());
      }
      return true;
    }

    case Combobox: {
      QComboBox* field = dynamic_cast<QComboBox*>(widget);
      if (!field) break;
      QList<QString> items;
      for (int i = 0; i < field->count(); ++i)
        items.append(field->itemText(i));

      ComboBoxRules comboboxRules;
      comboboxRules.setItems(items);
      if (!comboboxRules.exec())
        break;

      field->clear();
      field->insertItems(0, comboboxRules.items());
      return true;
    }
    default:
      break;
  }
  return false;
}

void Field::onActionClone() {
  emit clone();
}

void Field::onActionDelete() {
  int opt = QMessageBox::question(this, tr("Remove Field"),
                                  tr("This action will remove this field. Do you want to continue?"),
                                  QMessageBox::Yes | QMessageBox::No);
  if(opt == QMessageBox::Yes) {
    emit remove();
  }
}

void Field::onActionCalculator() {
  Calculator* calculatorWindow = new Calculator(this);
  calculatorWindow->setAttribute(Qt::WA_DeleteOnClose);
  connect(calculatorWindow, SIGNAL(sendEquation(QString)), this, SLOT(onSentEquation(QString)));
  calculatorWindow->show();
  QLineEdit* field = dynamic_cast<QLineEdit*>(widget);
  if(field)
    calculatorWindow->setEquation(field->text());
}

void Field::onSentEquation(QString equationFromField) {
  QLineEdit* field = dynamic_cast<QLineEdit*>(widget);
  if(field)
    field->setText(equationFromField);
}

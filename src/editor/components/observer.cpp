#include "dengueme.h"
#include "observer.h"
#include "ui_observer.h"
#include <QtWidgets>

Observer::Observer(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Observer) {
  ui->setupUi(this);

  connect(ui->getColorBarButton, SIGNAL(clicked()), this, SLOT(setColorBar()));
  connect(ui->pushButton_ColoBar, SIGNAL(clicked()), this, SLOT(showColorDialog()));
}

Observer::~Observer() {
  delete ui;
}

QString Observer::outData() {
  QString legendScale = ui->legendScale_lineEdit->text();
  QString type = ui->type_lineEdit->text();
  QString grouping = ui->grouping_lineEdit->text();
  QString slices = ui->slices_lineEdit->text();
  QString precision = ui->precision_lineEdit->text();
  QString stdDeviation = ui->stdDeviation_lineEdit->text();
  QString maximum = ui->maximum_lineEdit->text();
  QString minimum = ui->minimum_lineEdit->text();
  QString colorBar = ui->colorBar_textEdit->toPlainText();

  QString out;

  out = "---------------------------------------------------------------------------------------------------\n";
  out += "-- OBSERVER\n";
  out += "---------------------------------------------------------------------------------------------------\n";
  out += "-- used to centralize the map\n";
  out += "forEachCell(cs, function(cell)\n";
  out += "\tcell.x = cell.x - cs.minCol\n";
  out += "\tcell.y = cell.y - cs.minRow\n";
  out += "end);\n";
  out += "\n";

  out += "-- Create a Legend\n";
  out += "legend_scale = " + legendScale + ";\n";
  out += "legenda = Legend{\n";
  out += "\ttype = \"" + type + "\",\n";
  out += "--	groupingMode = \"equalsteps\",\t\t\t\t\t-- TerraME 1.1.2\n";
  out += "\tgrouping = \"" + grouping + "\",\t\t\t\t\t\t-- TerraME 1.2.1\n";
  out += "\tslices = " + slices + ",\n";
  out += "\tprecision = " + precision + ",\n";
  out += "\tstdDeviation = \"" + stdDeviation + "\",\n";
  out += "\tmaximum = " + maximum + ",\n";
  out += "\tminimum = " + minimum + ",\n";
  out += "\tcolorBar = {" + colorBar + "},\n";
  out += "\tstdColorBar = {}\n";
  out += "}\n";
  out += "\n";

  if(ui->map_checkBox->isChecked()) {
    out += "-- Create a Observer Image\n";
    out += "observerImage = Observer {\n";
    out += "\tsubject = cs,\n";
    out += "\ttype = \"image\",\n";
    out += "\tattributes = {\"focus\"},\n";
    out += "prefix = \"focus_\",\n";
    out += "\tpath = RESULTS_PATH,\n";
    out += "\tlegends={legenda}\n";
    out += "}\n";
    out += "\n";
  }

  if(ui->viewExec_checkBox->isChecked()) {
    out += "-- Create a Observer Map\n";
    out += "observerMap = Observer{\n";
    out += "\tsubject = cs,\n";
    out += "\ttype = \"map\",\n";
    out += "\tattributes={\"focus\"},\n";
    out += "\tlegends= {legenda}\n";
    out += "}\n";
    out += "\n";
  }

  if(ui->viewExec_checkBox->isChecked() || ui->map_checkBox->isChecked()) {
    out += "cs:notify()\n";
  }

  return out;
}

void Observer::setXml(QDomElement root) {
  QDomNodeList obsvAtt = root.elementsByTagName("legendScale");
  QDomNode legendScaleNode = obsvAtt.at(0);
  QDomElement legendScale = legendScaleNode.toElement();
  ui->legendScale_lineEdit->setText(legendScale.attribute("Value"));

  obsvAtt = root.elementsByTagName("type");
  QDomNode typeNode = obsvAtt.at(0);
  QDomElement type = typeNode.toElement();
  ui->type_lineEdit->setText(type.attribute("Value"));

  obsvAtt = root.elementsByTagName("grouping");
  QDomNode groupingNode = obsvAtt.at(0);
  QDomElement grouping = groupingNode.toElement();
  ui->grouping_lineEdit->setText(grouping.attribute("Value"));

  obsvAtt = root.elementsByTagName("slices");
  QDomNode slicesNode = obsvAtt.at(0);
  QDomElement slices = slicesNode.toElement();
  ui->slices_lineEdit->setText(slices.attribute("Value"));

  obsvAtt = root.elementsByTagName("precision");
  QDomNode precisionNode = obsvAtt.at(0);
  QDomElement precision = precisionNode.toElement();
  ui->precision_lineEdit->setText(precision.attribute("Value"));

  obsvAtt = root.elementsByTagName("stdDeviation");
  QDomNode stdDeviationNode = obsvAtt.at(0);
  QDomElement stdDeviation = stdDeviationNode.toElement();
  ui->stdDeviation_lineEdit->setText(stdDeviation.attribute("Value"));

  obsvAtt = root.elementsByTagName("maximum");
  QDomNode maximumNode = obsvAtt.at(0);
  QDomElement maximum = maximumNode.toElement();
  ui->maximum_lineEdit->setText(maximum.attribute("Value"));

  obsvAtt = root.elementsByTagName("minimum");
  QDomNode minimumNode = obsvAtt.at(0);
  QDomElement minimum = minimumNode.toElement();
  ui->minimum_lineEdit->setText(minimum.attribute("Value"));

  obsvAtt = root.elementsByTagName("colorBar");
  QDomNode colorBarNode = obsvAtt.at(0);
  QDomElement colorBar = colorBarNode.toElement();
  ui->colorBar_textEdit->setText(colorBar.attribute("Value"));

  obsvAtt = root.elementsByTagName("map");
  QDomNode mapNode = obsvAtt.at(0);
  QDomElement map = mapNode.toElement();
  if(map.attribute("Value") == "true") {
    ui->map_checkBox->setChecked("true");
  } else {
    ui->map_checkBox->setChecked("false");
  }

  obsvAtt = root.elementsByTagName("viewExec");
  QDomNode viewExecNode = obsvAtt.at(0);
  QDomElement viewExec = viewExecNode.toElement();
  if(viewExec.attribute("Value") == "true") {
    ui->viewExec_checkBox->setChecked("true");
  } else {
    ui->viewExec_checkBox->setChecked("false");
  }
}

QDomDocument Observer::getXml() {
  QDomDocument document;
  QString legendScale_ = ui->legendScale_lineEdit->text();
  QString type_ = ui->type_lineEdit->text();
  QString grouping_ = ui->grouping_lineEdit->text();
  QString slices_ = ui->slices_lineEdit->text();
  QString precision_ = ui->precision_lineEdit->text();
  QString stdDeviation_ = ui->stdDeviation_lineEdit->text();
  QString maximum_ = ui->maximum_lineEdit->text();
  QString minimum_ = ui->minimum_lineEdit->text();
  QString colorBar_ = ui->colorBar_textEdit->toPlainText();

  QDomElement root = document.createElement("Observer");
  document.appendChild(root);

  QDomElement legend = document.createElement("legendScale");
  legend.setAttribute("Value", legendScale_);
  root.appendChild(legend);

  QDomElement type = document.createElement("type");
  type.setAttribute("Value", type_);
  root.appendChild(type);

  QDomElement grouping = document.createElement("grouping");
  grouping.setAttribute("Value", grouping_);
  root.appendChild(grouping);

  QDomElement slices = document.createElement("slices");
  slices.setAttribute("Value", slices_);
  root.appendChild(slices);

  QDomElement precision = document.createElement("precision");
  precision.setAttribute("Value", precision_);
  root.appendChild(precision);

  QDomElement stdD = document.createElement("stdDeviation");
  stdD.setAttribute("Value", stdDeviation_);
  root.appendChild(stdD);

  QDomElement max = document.createElement("maximum");
  max.setAttribute("Value", maximum_);
  root.appendChild(max);

  QDomElement min = document.createElement("minimum");
  min.setAttribute("Value", minimum_);
  root.appendChild(min);

  QDomElement colorBar = document.createElement("colorBar");
  colorBar.setAttribute("Value", colorBar_);
  root.appendChild(colorBar);

  if(ui->map_checkBox->isChecked()) {
    QDomElement map = document.createElement("map");
    map.setAttribute("Value", "true");
    root.appendChild(map);
  } else {
    QDomElement map = document.createElement("map");
    map.setAttribute("Value", "false");
    root.appendChild(map);
  }

  if(ui->viewExec_checkBox->isChecked()) {
    QDomElement viewExec = document.createElement("viewExec");
    viewExec.setAttribute("Value", "true");
    root.appendChild(viewExec);
  } else {
    QDomElement viewExec = document.createElement("viewExec");
    viewExec.setAttribute("Value", "false");
    root.appendChild(viewExec);
  }

  return document;
}

void Observer::parameters() {
  ui->legendScale_lineEdit->setText("1");
  ui->type_lineEdit->setText("number");
  ui->grouping_lineEdit->setText("equalsteps");
  ui->slices_lineEdit->setText("100");
  ui->precision_lineEdit->setText("10");
  ui->stdDeviation_lineEdit->setText("none");
  ui->maximum_lineEdit->setText("100");
  ui->minimum_lineEdit->setText("0");
  ui->colorBar_textEdit->setText("{color = {0, 255, 255}, value = 10 * legend_scale}, {color = {0, 227, 170}, "
                                 "value = 20 * legend_scale}, {color = {0, 199, 85}, value = 30 * legend_scale}, "
                                 "{color = {0, 170, 0}, value = 40 * legend_scale}, {color = {85, 198, 0}, "
                                 "value = 50 * legend_scale}, {color = {170, 226, 0}, value = 60 * legend_scale}, "
                                 "{color = {255, 255, 0}, value = 70 * legend_scale}, {color = {255, 170, 0}, "
                                 "value = 80 * legend_scale}, {color = {255, 85, 0}, value = 90 * legend_scale}, "
                                 "{color = {255, 1, 0}, value = 100* legend_scale}");
  ui->map_checkBox->setChecked(true);
  ui->viewExec_checkBox->setChecked(true);
}

void Observer::ChangeValue(const QString& newText) {
  ui->colorBar_textEdit->setText(newText);
}


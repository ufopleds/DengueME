#include "dengueme.h"
#include "database.h"
#include "ui_database.h"
#include <QtWidgets>
#include <QtWidgets>

Database::Database(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::Database) {
  ui->setupUi(this);
  databaseConf();

  connect(ui->radioButton_mysql, SIGNAL(clicked()), this, SLOT(databaseConf()));
#ifndef _WIN32
  ui->radioButton_access->setVisible(false);
  ui->widget_access->setVisible(false);
#endif

#ifdef _WIN32
  connect(ui->radioButton_access, SIGNAL(clicked()), this, SLOT(databaseConf()));
#endif

  connect(ui->radioButton_virtual, SIGNAL(clicked()), this, SLOT(databaseConf()));

#ifdef _WIN32
  connect(ui->pushButton_access, SIGNAL(clicked()), this, SLOT(setFile()));
#endif
}

Database::~Database() {
  delete ui;
}

void Database::setXml(QDomElement root) {
  QDomElement dbType = root.firstChildElement("dbType");

  if(dbType.attribute("Value") == "mysql") {
    ui->radioButton_mysql->setChecked(true);

    databaseConf();

    QDomElement host = root.firstChildElement("host");
    ui->lineEdit_host->setText(host.attribute("Value"));

    QDomElement dbName = root.firstChildElement("db");
    ui->lineEdit_db->setText(dbName.attribute("Value"));

    QDomElement user = root.firstChildElement("user");
    ui->lineEdit_user->setText(user.attribute("Value"));

    QDomElement pass = root.firstChildElement("password");
    ui->lineEdit_password->setText(pass.attribute("Value"));

    QDomElement layer = root.firstChildElement("layer");
    ui->lineEdit_layer->setText(layer.attribute("Value"));

    QDomElement theme = root.firstChildElement("theme");
    ui->lineEdit_theme->setText(theme.attribute("Value"));

    QDomElement select = root.firstChildElement("select");
    ui->lineEdit_select->setText(select.attribute("Value"));
  } else if(dbType.attribute("Value") == "access") {
    ui->radioButton_access->setChecked(true);

    databaseConf();

    QDomElement dbAc = root.firstChildElement("dbAc");
    ui->lineEdit_access->setText(dbAc.attribute("Value"));

    QDomElement layerAc = root.firstChildElement("layerAc");
    ui->lineEdit_layerAccess->setText(layerAc.attribute("Value"));

    QDomElement themeAc = root.firstChildElement("themeAc");
    ui->lineEdit_themeAccess->setText(themeAc.attribute("Value"));

    QDomElement selectAc = root.firstChildElement("selectAc");
    ui->lineEdit_selectAccess->setText(selectAc.attribute("Value"));

  } else if(dbType.attribute("Value") == "virtual") {
    ui->radioButton_virtual->setChecked(true);

    databaseConf();

    QDomElement xdim = root.firstChildElement("xdim");
    ui->spinBox_xdim->setValue(xdim.attribute("Value").toInt());

    QDomElement ydim = root.firstChildElement("ydim");
    ui->spinBox_ydim->setValue(ydim.attribute("Value").toInt());
  }
}

QString Database::outData() {
  QString host = ui->lineEdit_host->text();
  QString db = ui->lineEdit_db->text();
  QString user = ui->lineEdit_user->text();
  QString password = ui->lineEdit_password->text();
  QString layer = ui->lineEdit_layer->text();
  QString theme = ui->lineEdit_theme->text();
  QString select = ui->lineEdit_select->text();

#ifdef _WIN32
  QString dbAc = ui->lineEdit_access->text();
  QString layerAc = ui->lineEdit_layerAccess->text();
  QString themeAc = ui->lineEdit_themeAccess->text();
  QString selectAc = ui->lineEdit_selectAccess->text();
#endif

  QString xdim = ui->spinBox_xdim->text();
  QString ydim = ui->spinBox_ydim->text();

  QString out;

  out = "---------------------------------------------------------------------------------------------------\n";
  out += "-- DATABASE\n";
  out += "---------------------------------------------------------------------------------------------------\n";
  if(ui->radioButton_mysql->isChecked()) {
    out += "-- load the cellular space from database\n";
    out += "cs = CellularSpace {\n";
    out += "\tdbType = \"mysql\",\n";
    out += "\thost = \"" + host + "\",\n";
    out += "\tdatabase = \"" + db + "\",\n";
    out += "\tuser = \"" + user + "\",\n";
    out += "\tpassword = \"" + password + "\",\n";
    out += "\tlayer = \"" + layer + "\",\n";
    out += "\ttheme = \"" + theme + "\",\n";
    out += "\tselect = {" + select + "}\n";
    out += "}\n";
  } else if(ui->radioButton_virtual->isChecked()) {
    out += "-- Creating the Cellular Space at the memory\n";
    out += "cs = CellularSpace {\n";
    out += "\txdim = " + xdim + ",\n";
    out += "\tydim = " + ydim + "\n";
    out += "}\n";
    out += "forEachCell(cs,\n";
    out += "\tfunction(cell)\n";
    out += "\t\tcell.Intensidade = 1;\n";
    out += "\t\tcell.Legenda = 0;\n";
    out += "\t\tcell.focus = 0;\n";
    out += "\t\treturn true;\n";
    out += "\tend\n";
    out += ");\n";
  }
#ifdef _WIN32
  else if(ui->radioButton_access->isChecked()) {
    out += "-- load the cellular space from database\n";
    out += "cs = CellularSpace {\n";
    out += "    dbType = \"ado\",\n";
    out += "    database = \"" + dbAc + "\",\n";
    out += "    layer = \"" + layerAc + "\",\n";
    out += "    theme = \"" + themeAc + "\",\n";
    out += "    select = {" + selectAc + "}\n";
    out += "}\n";
  }
#endif
  out += "--cs:load();\n";
  out += "forEachCell( cs,\n";
  out += "\tfunction(cell)\n";
  out += "\t\tcell.focus = 0;\n";
  out += "\tend\n";
  out += ")\n";
  out += "\n";

  return out;
}

QString Database::epiOutData() {
  QString host = ui->lineEdit_host->text();
  QString db = ui->lineEdit_db->text();
  QString user = ui->lineEdit_user->text();
  QString password = ui->lineEdit_password->text();
  QString layer = ui->lineEdit_layer->text();
  QString theme = ui->lineEdit_theme->text();
  QString select = ui->lineEdit_select->text();

#ifdef _WIN32
  QString dbAc = ui->lineEdit_access->text();
  QString layerAc = ui->lineEdit_layerAccess->text();
  QString themeAc = ui->lineEdit_themeAccess->text();
  QString selectAc = ui->lineEdit_selectAccess->text();
#endif

  QString xdim = ui->spinBox_xdim->text();
  QString ydim = ui->spinBox_ydim->text();
  QString out;

  out = "---------------------------------------------------------------------------------------------------\n";
  out += "-- DATABASE\n";
  out += "---------------------------------------------------------------------------------------------------\n";
  if(ui->radioButton_mysql->isChecked()) {
    out += "VIRTUAL_CS = false\n\n";
    out += "-- load the cellular space from database\n";
    out += "cs = CellularSpace {\n";
    out += "\tdbType = \"mysql\",\n";
    out += "\thost = \"" + host + "\",\n";
    out += "\tdatabase = \"" + db + "\",\n";
    out += "\tuser = \"" + user + "\",\n";
    out += "\tpassword = \"" + password + "\",\n";
    out += "\tlayer = \"" + layer + "\",\n";
    out += "\ttheme = \"" + theme + "\",\n";
    out += "\tselect = {" + select + "}\n";
    out += "}\n";
  } else if(ui->radioButton_virtual->isChecked()) {
    out += "VIRTUAL_CS = true\n\n";
    out += "-- Creating the Cellular Space at the memory\n";
    out += "cs = CellularSpace {\n";
    out += "\txdim = " + xdim + ",\n";
    out += "\tydim = " + ydim + "\n";
    out += "}\n";
  }
#ifdef _WIN32
  else if(ui->radioButton_access->isChecked()) {
    out += "VIRTUAL_CS = false\n\n";
    out += "-- load the cellular space from database\n";
    out += "cs = CellularSpace {\n";
    out += "    dbType = \"ado\",\n";
    out += "    database = \"" + dbAc + "\",\n";
    out += "    layer = \"" + layerAc + "\",\n";
    out += "    theme = \"" + themeAc + "\",\n";
    out += "    select = {" + selectAc + "}\n";
    out += "}\n";
  }
#endif
  out += "--cs:load();\n";
  out += "\n";

  return out;
}

QString Database::coupledOutData() {
  QString host = ui->lineEdit_host->text();
  QString db = ui->lineEdit_db->text();
  QString user = ui->lineEdit_user->text();
  QString password = ui->lineEdit_password->text();
  QString layer = ui->lineEdit_layer->text();
  QString theme = ui->lineEdit_theme->text();
  QString select = ui->lineEdit_select->text();

#ifdef _WIN32
  QString dbAc = ui->lineEdit_access->text();
  QString layerAc = ui->lineEdit_layerAccess->text();
  QString themeAc = ui->lineEdit_themeAccess->text();
  QString selectAc = ui->lineEdit_selectAccess->text();
#endif

  QString xdim = ui->spinBox_xdim->text();
  QString ydim = ui->spinBox_ydim->text();

  QString out;

  out = "---------------------------------------------------------------------------------------------------\n";
  out += "-- DATABASE\n";
  out += "---------------------------------------------------------------------------------------------------\n";
  if(ui->radioButton_mysql->isChecked()) {
    out += "-- load the cellular space from database\n";
    out += "cs = CellularSpace {\n";
    out += "\tdbType = \"mysql\",\n";
    out += "\thost = \"" + host + "\",\n";
    out += "\tdatabase = \"" + db + "\",\n";
    out += "\tuser = \"" + user + "\",\n";
    out += "\tpassword = \"" + password + "\",\n";
    out += "\tlayer = \"" + layer + "\",\n";
    out += "\ttheme = \"" + theme + "\",\n";
    out += "\tselect = {" + select + "}\n";
    out += "}\n";
  } else if(ui->radioButton_virtual->isChecked()) {
    out += "-- Creating the Cellular Space at the memory\n";
    out += "cs = CellularSpace {\n";
    out += "\txdim = " + xdim + ",\n";
    out += "\tydim = " + ydim + "\n";
    out += "}\n";
    out += "forEachCell(cs,\n";
    out += "\tfunction(cell)\n";
    out += "\t\tcell.Intensidade = 1;\n";
    out += "\t\tcell.Legenda = 0;\n";
    out += "\t\tcell.focus = 0;\n";
    out += "\t\treturn true;\n";
    out += "\tend\n";
    out += ");\n";
  }
#ifdef _WIN32
  else if(ui->radioButton_access->isChecked()) {
    out += "-- load the cellular space from database\n";
    out += "cs = CellularSpace {\n";
    out += "    dbType = \"ado\",\n";
    out += "    database = \"" + dbAc + "\",\n";
    out += "    layer = \"" + layerAc + "\",\n";
    out += "    theme = \"" + themeAc + "\",\n";
    out += "    select = {" + selectAc + "}\n";
    out += "}\n";
  }
#endif
  out += "--cs:load();\n";
  out += "\n";
  out += "forEachCell(cs,\n";
  out += "       function(cell)\n";
  out += "               cell.focus = 0;\n";
  out += "       end\n";
  out += ");\n";

  return out;
}

QDomDocument Database::getXml() {
  QString dbType;
  if(ui->radioButton_mysql->isChecked()) {
    dbType = "mysql";
  } else if(ui->radioButton_access->isChecked()) {
    dbType = "access";
  } else if(ui->radioButton_virtual->isChecked()) {
    dbType = "virtual";
  }

  QDomDocument document;

  QDomElement root = document.createElement("Database");
  document.appendChild(root);

  if(dbType == "mysql") {
    QString host_ = ui->lineEdit_host->text();
    QString db_ = ui->lineEdit_db->text();
    QString user_ = ui->lineEdit_user->text();
    QString password_ = ui->lineEdit_password->text();
    QString layer_ = ui->lineEdit_layer->text();
    QString theme_ = ui->lineEdit_theme->text();
    QString select_ = ui->lineEdit_select->text();

    QDomElement dbType_ = document.createElement("dbType");
    dbType_.setAttribute("Value", dbType);
    root.appendChild(dbType_);

    QDomElement host = document.createElement("host");
    host.setAttribute("Value", host_);
    root.appendChild(host);

    QDomElement db = document.createElement("db");
    db.setAttribute("Value", db_);
    root.appendChild(db);

    QDomElement user = document.createElement("user");
    user.setAttribute("Value", user_);
    root.appendChild(user);

    QDomElement password = document.createElement("password");
    password.setAttribute("Value", password_);
    root.appendChild(password);

    QDomElement layer = document.createElement("layer");
    layer.setAttribute("Value", layer_);
    root.appendChild(layer);

    QDomElement theme = document.createElement("theme");
    theme.setAttribute("Value", theme_);
    root.appendChild(theme);

    QDomElement select = document.createElement("select");
    select.setAttribute("Value", select_);
    root.appendChild(select);

  } else if(dbType == "access") {
    QString dbAc_ = ui->lineEdit_access->text();
    QString layerAc_ = ui->lineEdit_layerAccess->text();
    QString themeAc_ = ui->lineEdit_themeAccess->text();
    QString selectAc_ = ui->lineEdit_selectAccess->text();

    QDomElement dbType_ = document.createElement("dbType");
    dbType_.setAttribute("Value", dbType);
    root.appendChild(dbType_);

    QDomElement dbAc = document.createElement("dbAc");
    dbAc.setAttribute("Value", dbAc_);
    root.appendChild(dbAc);

    QDomElement layerAc = document.createElement("layerAc");
    layerAc.setAttribute("Value", layerAc_);
    root.appendChild(layerAc);

    QDomElement themeAc = document.createElement("themeAc");
    themeAc.setAttribute("Value", themeAc_);
    root.appendChild(themeAc);

    QDomElement selectAc = document.createElement("selectAc");
    selectAc.setAttribute("Value", selectAc_);
    root.appendChild(selectAc);
  } else if(dbType == "virtual") {
    QString xdim_ = ui->spinBox_xdim->text();
    QString ydim_ = ui->spinBox_ydim->text();

    QDomElement dbType_ = document.createElement("dbType");
    dbType_.setAttribute("Value", dbType);
    root.appendChild(dbType_);

    QDomElement xdim = document.createElement("xdim");
    xdim.setAttribute("Value", xdim_);
    root.appendChild(xdim);

    QDomElement ydim = document.createElement("ydim");
    ydim.setAttribute("Value", ydim_);
    root.appendChild(ydim);
  }

  return document;
}

void Database::databaseConf() {
  if(ui->radioButton_mysql->isChecked()) {
#ifdef _WIN32
    ui->widget_access->setVisible(false);
#endif
    ui->widget_virtual->setVisible(false);

    ui->widget_mysql->setVisible(true);
  }
#ifdef _WIN32
  else if(ui->radioButton_access->isChecked()) {
    ui->widget_access->setVisible(true);

    ui->widget_virtual->setVisible(false);
    ui->widget_mysql->setVisible(false);
  }
#endif
  else if(ui->radioButton_virtual->isChecked()) {
#ifdef _WIN32
    ui->widget_access->setVisible(false);
#endif
    ui->widget_mysql->setVisible(false);

    ui->widget_virtual->setVisible(true);
  }
}

void Database::parameters() {
  ui->lineEdit_host->setText("localhost");
  ui->lineEdit_db->setText("ilha_governador");
  ui->lineEdit_user->setText("root");
  ui->lineEdit_password->setText("");
  ui->lineEdit_layer->setText("cells_100x100_reduzido");
  ui->lineEdit_theme->setText("cells_100x100_reduzido");
  ui->lineEdit_select->setText("");
#ifdef _WIN32
  ui->lineEdit_access->setText("C:\\\\DengueME\\\\database\\\\ilha_governador.mdb");
  ui->lineEdit_layerAccess->setText("cells_100x100_reduzido");
  ui->lineEdit_themeAccess->setText("cells_100x100_reduzido");
  ui->lineEdit_selectAccess->setText("");
#endif
}

void Database::coupledParameters() {
  ui->lineEdit_host->setText("localhost");
  ui->lineEdit_db->setText("ilha_governador");
  ui->lineEdit_user->setText("root");
  ui->lineEdit_password->setText("");
  ui->lineEdit_layer->setText("cells_100x100");
  ui->lineEdit_theme->setText("cells_100x100");
  ui->lineEdit_select->setText("");
#ifdef _WIN32
  ui->lineEdit_access->setText("C:\\\\DengueME\\\\database\\\\ilha_governador.mdb");
  ui->lineEdit_layerAccess->setText("cells_100x100");
  ui->lineEdit_themeAccess->setText("cells_100x100");
  ui->lineEdit_selectAccess->setText("");
#endif
}

void Database::epidemiologicalParameters() {
  ui->lineEdit_host->setText("localhost");
  ui->lineEdit_db->setText("ilha_governador");
  ui->lineEdit_user->setText("root");
  ui->lineEdit_password->setText("");
  ui->lineEdit_layer->setText("cells_100x100");
  ui->lineEdit_theme->setText("cells_100x100");
  ui->lineEdit_select->setText("");
#ifdef _WIN32
  ui->lineEdit_access->setText("C:\\\\DengueME\\\\database\\\\ilha_governador.mdb");
  ui->lineEdit_layerAccess->setText("cells_100x100");
  ui->lineEdit_themeAccess->setText("cells_100x100");
  ui->lineEdit_selectAccess->setText("");
#endif
}

void Database::setFile() {
  QFileDialog::Options options;
  QString selectedFilter;
  QString fileName = QFileDialog::getOpenFileName(this,
                                                  tr("Opening Access Database File"),
                                                  "",
                                                  tr("MDB Files (*.mdb)"),
                                                  &selectedFilter,
                                                  options);
  if (!fileName.isEmpty()) {
    QString newPath;
    QStringList list;
    list = fileName.split("/");

    int size = list.size();
    int i;

    for (i = 0; i < size; i++) {
      if(i == size - 1)
        newPath += list[i];
      else
        newPath += list[i] + "\\\\";
    }
    ui->lineEdit_access->setText(newPath);
  }
}


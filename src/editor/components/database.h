#ifndef DATABASE_H
#define DATABASE_H

#include <QWidget>
#include <QtXml>

namespace Ui {
class Database;
}

class Database : public QWidget {
  Q_OBJECT

 public:
  explicit Database(QWidget* parent = 0);

  QDomDocument getXml();
  void setXml(QDomElement root);
  QString outData();
  QString epiOutData();
  QString coupledOutData();
  void parameters();
  void coupledParameters();
  void epidemiologicalParameters();
  ~Database();

 public slots:
  void databaseConf();
  void setFile();


 private:
  Ui::Database* ui;
};

#endif // DATABASE_H

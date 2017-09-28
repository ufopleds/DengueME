#ifndef OBSERVER_H
#define OBSERVER_H

#include <QWidget>
#include <QtXml>
#include <QtWidgets>


namespace Ui {
class Observer;
}

class Observer : public QWidget {
  Q_OBJECT

 public:
  explicit Observer(QWidget* parent = 0);  
  ~Observer();

 public slots:
  QString outData(); 
  void parameters(); 
  void ChangeValue(const QString& newText);
  void setXml(QDomElement root);
  QDomDocument getXml();

 private:
  Ui::Observer* ui;
};

#endif // OBSERVER_H

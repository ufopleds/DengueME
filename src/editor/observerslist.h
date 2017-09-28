#ifndef OBSERVERSLIST_H
#define OBSERVERSLIST_H

#include <QtWidgets>
#include <QtXml>
#include "chartgroup.h"
#include "textscreengroup.h"
#include "visualtablegroup.h"
#include "loggroup.h"
#include <QListWidget>
namespace Ui {
class ObserversList;
}

class ObserversList : public QFrame {
  Q_OBJECT

 public:
  explicit ObserversList(QWidget* parent = 0);
  ~ObserversList();
  QDomDocument getXml();
  void setXml(QDomNode root);
  void setEditMode(bool enable);
  QString genLua();
  QString genR();
  void scrollToTop();
  //  QListWidget *listagem ;


 private:
  Ui::ObserversList* ui;
  QToolButton* add;
  QMap <QObject*, QListWidgetItem*> map;

 private slots:
  ChartGroup* addChartGroup();
  TextScreenGroup* addTextGroup();
  VisualTableGroup* addTableGroup();
  LogGroup* addLogGroup();
  void removeGroup();
  void updateHeight(int height);
  Component* addComponent(Component* comp);
};

#endif // OBSERVERSLIST_H

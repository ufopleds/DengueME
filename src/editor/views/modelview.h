#ifndef MODELVIEW_H
#define MODELVIEW_H

#include <QtCore>
#include <QtWidgets>
#include <QtXml>

namespace Ui {
class ModelView;
}

class ModelView : public QFrame {
  Q_OBJECT

 public:
  enum Interpreter {TerraME, RScript};

  explicit ModelView(QWidget* parent = 0);
  ~ModelView();
  QDomDocument getXml();
  void setXml(QDomElement node);
  Interpreter interpreter();
  void setScriptDir(QString dir);
  QString scriptDir();
  QStringList scripts();
  QString mainScript();

 private:
  Ui::ModelView* ui;
  QString _scriptDir;
  QMap<QObject*, QListWidgetItem*> map;

  void addItem(QString fileName);

 private slots:
  void addFile();
  void removeFile();
  void renameFile();
  void onInterpreterChanged(int r);
  void add();
  void del();

 signals:
  void interpreterChanged(Interpreter);
};

#endif // MODELVIEW_H

#ifndef EDITOR_H
#define EDITOR_H

#include <QtWidgets>
#include "editor/grouplist.h"
#include "editor/observerslist.h"
#include "editor/components/database.h"
#include "editor/components/observer.h"
#include "editor/views/modelview.h"

namespace Ui {
class Editor;
}

class Editor : public QWidget {
  Q_OBJECT

 public:
  typedef ModelView::Interpreter Interpreter;

  explicit Editor(QWidget* parent = 0);
  ~Editor();

  QString getModelFile();
  QString modelDescription;
  bool isRunning();
  void stopModel();
  ModelView* view_model;

 private:
  QWidget* contents;
  Ui::Editor* ui;
  QString modelFile;
  int renameFlag = 0;
  QWidget* view_results;
  QWidget* view_parameters;
  QFrame* view_database;
  QFrame* view_simulation;


  GroupList* parametersGroup;
  Group* simulationGroup;
  ObserversList* resultsGroup;
  QCheckBox* enableDatabase;
  QCheckBox* enableResults;
  bool editMode;

  enum View { ViewModel = 0, ViewDatabase, ViewParameters, ViewSimulation, ViewResults, ViewOther };

  struct ViewData {
    ViewData() : widget(NULL), visible(true), visibleEM(true) {}
    ViewData(QString n, QString d, QWidget* w)
      : name(n), variableName(d), widget(w), visible(true), visibleEM(true) {}
    QString name;
    QString variableName;
    QWidget* widget;
    bool visible, visibleEM;
  };
  QList<ViewData> viewmap;
  QProcess interpreter;
  QDomDocument modelXml;

  void setupViews();
  void addView(QString variableName, QWidget* content, QString name);
  void setEditModeEnabled(bool enable);

 public slots:
  QString loadDescription(QDomElement node);
  bool loadModel(QString filename, bool editMode);
  void execModel(bool stepByStep);
  bool close(int del);
  void updateModelInfo(QString newPath);
  void clearModel();
  bool save();
  bool saveAs();

 private slots:
  void readyReadStandardError();
  void readyReadStandardOutput();
  void onInterpreterFinished(int exitCode);
  void onInterpreterChanged(Interpreter intr);

 signals:
  void closed();
  void renamed(QString filename);
  void output(int lvl, QString text);
  void interpreterStarted();
  void interpreterStopped(int exitCode);
};

#endif // EDITOR_H


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QtGui>
#include "helpbrowser.h"

namespace Ui {
class MainWindow;
}

struct MainWindow_UnitTests;

class MainWindow : public QMainWindow {
    friend struct MainWindow_UnitTests;
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QDialog *helpDialog;
    HelpBrowser *helpText;
    bool helpHasBeenCreated;

    void closeEvent(QCloseEvent *event);

    enum State {Running, Editing, Browsing};
    void setState(State state);

private slots:
    void onModelStarted();
    void onModelClosed();
    void onModelStopped(int exitCode);
    void workspaceContextMenu(const QPoint &point);
    void modelActivated(QModelIndex index);
    void onHelpRequested();
    void runUnitTests();

public slots:
    void actionDefault();
    void actionNewModel(QString project = QString());
    void actionNewProject();
    void actionSave();
    void actionClose();
    void actionRemove();
    void actionRename();
    void actionRun();
    void actionRunByStep();

    void actionOptions();
    void actionAbout();
    void actionSetWorkspace();
    void actionModelBuilder();
    void actionResetViews();

public slots:
    void output(int lvl, QString text);
    void newModel(QString category, QString type, QString project, QString name);
    void newProject(QString name);

signals:
    void clickedByUser(QString action);
};

#endif // MAINWINDOW_H

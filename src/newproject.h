#ifndef NEWPROJECT_H
#define NEWPROJECT_H

#include <QDialog>

namespace Ui {
class NewProject;
}

class NewProject : public QDialog {
  Q_OBJECT

 public:
  explicit NewProject(QWidget* parent = 0);
  ~NewProject();
  QString getProjectName();

 private:
  Ui::NewProject* ui;

 private slots:
  void accept();
  void onOkPressed();
  void checkLineEdited(const QString& str);

 signals:
  void accepted(QString, int);
};

#endif // NEWPROJECT_H

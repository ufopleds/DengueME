#ifndef CHANGEWORKSPACE_H
#define CHANGEWORKSPACE_H

#include <QDialog>

namespace Ui {
class ChangeWorkspace;
}

class ChangeWorkspace : public QDialog {
  Q_OBJECT

 public:
  explicit ChangeWorkspace(QWidget* parent = 0);
  ~ChangeWorkspace();

 private:
  Ui::ChangeWorkspace* ui;

 public slots:
  void browseWorkspace();
  void accept();

 private slots:
  void checkLineEdited(const QString& path);

 signals:
};

#endif // CHANGEWORKSPACE_H

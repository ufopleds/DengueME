#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>

namespace Ui {
class Options;
}

class Options : public QDialog {
  Q_OBJECT

 public:
  explicit Options(QWidget* parent = 0);
  ~Options();

 private slots:
  void browseWorkspace();
  void browseTerraME();
  void browseRscript();
  void accept();
  void languageMessage();
  void checkPath(QString path);
  void checkCheckBox();

 private:
  Ui::Options* ui;
  QString locale;
};

#endif // OPTIONS_H

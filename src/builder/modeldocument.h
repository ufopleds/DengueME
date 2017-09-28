#ifndef MODELDOCUMENT_H
#define MODELDOCUMENT_H

#include <QDialog>
#include <QtCore>
#include <QtWidgets>

namespace Ui {
class ModelDocument;
}

class ModelDocument : public QDialog {
  Q_OBJECT

 public:
  explicit ModelDocument(QWidget* parent = 0, QString filename = "");
  ~ModelDocument();

 private:
  Ui::ModelDocument* ui;
  void closeEvent(QCloseEvent* event);

 private slots:
  void save();
  void openSyntaxHelp();
};

#endif // MODELDOCUMENT_H

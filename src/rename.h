#ifndef RENAME_H
#define RENAME_H

#include <QDialog>
#include "dengueme.h"

namespace Ui {
class RenameModel;
}

class RenameModel : public QDialog {
  Q_OBJECT

 public:
  explicit RenameModel(QString path, QString name, QString extension, QWidget* parent = 0);
  ~RenameModel();
  void setModelName(const QString& modelName);
  QString getModelName();

 private:
  Ui::RenameModel* ui;
  QString path;
  QString modelName;
  QString fileExtension;
  dengueme::NameValidation state;

 private slots:
  void checkLineEdited(const QString& str);
  void onEnterPressed();
};

#endif // RENAME_H

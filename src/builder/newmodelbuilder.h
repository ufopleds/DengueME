#ifndef NEWMODELBUILDER_H
#define NEWMODELBUILDER_H

#include <QDialog>
#include "dengueme.h"

namespace Ui {
class NewModelBuilder;
}

class NewModelBuilder : public QDialog {
  Q_OBJECT

 public:
  struct {
    QStringList types;
    QList<QStringList> names;
  } models;

  explicit NewModelBuilder(QString workspace, QString project = QString(), QWidget* parent = 0);
  ~NewModelBuilder();
  QString getCategoryName(QString category);

 private:
  Ui::NewModelBuilder* ui;
  QString workspace;
  QString project;

 public slots:
  void addCategories();
  void onCreateButton();
  void checkModelName(const QString& str);
  void checkComboBox();
  dengueme::NameValidation validateName(QString path, QString name);


 signals:
  void accepted(QString name, QString project);

};

#endif // NEWMODELBUILDER_H

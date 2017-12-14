#ifndef NEWMODEL_H
#define NEWMODEL_H

#include <QDialog>
#include "dengueme.h"
#include "editor/views/modelview.h"

namespace Ui {
class NewModel;
}

class NewModel : public QDialog {
  Q_OBJECT

 public:
  struct {
    QStringList types;
    QList<QStringList> names;
  } models;

  QHash<QString, QString> modelsInfoHash;
  QMap<QString, QString> namesMap;
  QString selectedModelID;

  explicit NewModel(QString workspace, QString project, QWidget* parent = 0);
  ~NewModel();
  void readModelsInfo();
  void addTypeTypePage();

  void loadModelsInfo();
  QString readXmlModel(QString path, QString tag);
  QString getCategoryName(QString category);

 private:
  Ui::NewModel* ui;
  QString workspace;
  QString project;
  dengueme::NameValidation state;

 public slots:
  void navigateBack();
  void navigateUp();
  void onCreateButton();
  void addProjects();
  void enableNext();
  void changePage();
  void addNamesTypePage();
  void addDescription(QString modelName);
  void checkIdLineEdit(const QString& str);

 signals:
  void accepted(QString category, QString type, QString project, QString name);

};

#endif // NEWMODEL_H

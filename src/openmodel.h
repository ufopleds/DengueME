#ifndef OPENMODEL_H
#define OPENMODEL_H


#include <QtWidgets>
#include <string>

namespace Ui {
class OpenModel;
}

class OpenModel : public QDialog {
  Q_OBJECT

 public:
  QModelIndex index;
  explicit OpenModel(QWidget* parent = 0);
  ~OpenModel();
  QModelIndex getIndex();
  QString getFilePath();
  QString getFileName();
 private:
  Ui::OpenModel* ui;
 private slots:
  void setIndex( );
  void selectionChanged(const QModelIndex& current);


};

#endif // OPENMODEL_H

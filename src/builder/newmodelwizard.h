#ifndef NEWMODELWIZARD_H
#define NEWMODELWIZARD_H

#include <QWizard>
#include <QPushButton>

class NewModelWizard : public QWizard {
 public:
  NewModelWizard(QString workspace, QString project = QString(), QWidget* parent = 0);
  ~NewModelWizard();
};

#endif // NEWMODELWIZARD_H


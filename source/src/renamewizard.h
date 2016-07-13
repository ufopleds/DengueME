#ifndef RENAMEPROJECT_H
#define RENAMEPROJECT_H

#include <QWizard>
#include <QLabel>
#include <QRadioButton>
#include <QLineEdit>
#include <QCheckBox>

class RenameWizard : public QWizard {
    Q_OBJECT

public:
    enum { Page_Filename };

    RenameWizard(QString path, QString name, bool isProject, QWidget *parent = 0);

private slots:
//    void showHelp();
};

#endif // RENAMEPROJECT_H

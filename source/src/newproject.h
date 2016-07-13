#ifndef NEWPROJECT_H
#define NEWPROJECT_H

#include <QWizard>

class NewProject : public QWizard {
    Q_OBJECT

public:
    enum { Page_Filename };

    NewProject(QString workspace, QWidget *parent = 0);

private slots:
    void accept();

signals:
    void accepted(QString);
};

#endif // NEWPROJECT_H


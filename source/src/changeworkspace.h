#ifndef CHANGEWORKSPACE_H
#define CHANGEWORKSPACE_H

#include <QWizard>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

class ChangeWorkspace : public QWizard {
    Q_OBJECT

public:
    enum { Page_SelectWorkspace };

    explicit ChangeWorkspace(QWidget *parent = 0);

public slots:
    void accept();

signals:
    void workspaceChanged();
};

namespace detail {

class SelectPage : public QWizardPage {
    Q_OBJECT

public:
    SelectPage(QWidget *parent = 0);

    int nextId() const;

private:
    QLabel *pathLabel;
    QLineEdit *pathLineEdit;
    QCheckBox *setDefault;
    QPushButton *browse;

public slots:
    void browseWorkspace();

private slots:
    void validate(QString path);
};

}

#endif // CHANGEWORKSPACE_H

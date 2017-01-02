#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include <QtWidgets>
#include <string>
namespace Ui {
class ModelBuilder;
}

class ModelBuilder : public QMainWindow
{
    Q_OBJECT

public:

    explicit ModelBuilder(QWidget *parent = 0);
    ~ModelBuilder();


private:
    Ui::ModelBuilder *ui;
    void closeEvent(QCloseEvent *event);

private slots:
void openModelWizard();
    void modelActivated(QModelIndex index);
    void selectionChanged(const QModelIndex &current, const QModelIndex &previous = QModelIndex());
    void onModelClosed();
    void deleteModel();
    void editModel();
    void newModel();
    void helpModelBuilder();

    void setToolbar(int i);
    void actionClose();

};

#endif // MODELBUILDER_H

#ifndef IMPORTCSV_H
#define IMPORTCSV_H

#include <QtGui>
#include <QtXml>
#include "../component.h"

namespace Ui {
class ImportCsv;
}

class ImportCsv : public Component
{
    Q_OBJECT
    
public:
    explicit ImportCsv(QWidget *parent = 0);
    ~ImportCsv();
    QDomDocument getXml();
    void setXml(QDomElement node);
    void setEditMode(bool enable);
    QString genLua();
    QString genR();

private slots:
    void openCsv();
    void onActionDelete();

private:
    Ui::ImportCsv *ui;
};

#endif // IMPORTCSV_H


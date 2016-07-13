#ifndef POPULATIONDATA_H
#define POPULATIONDATA_H

#include <QWidget>

#include "../group.h"

struct CBField;

class PopulationData : public Group
{
    Q_OBJECT

public:
    explicit PopulationData(QWidget *parent = 0);
    QDomDocument getXml();
    void setXml(QDomElement root);
    void setEditMode(bool enable);

private:
    CBField *usePopData;
    Field *pa,  *pp,   *pcwh, *hpc,
          *dmr, *dmrp, *ahrr, *paih;

    void varNames();
};

#endif // POPULATIONDATA_H

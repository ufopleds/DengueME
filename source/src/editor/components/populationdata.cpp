#include "populationdata.h"
#include "ui_group.h"

struct CBField : public Component {
    QCheckBox *cbox;
    QString var;

    CBField() {
        var = "USE_POPULATION_DATA";
        resize(-1,41);
        QHBoxLayout *layout = new QHBoxLayout;
        setLayout(layout);

        cbox = new QCheckBox("Use population data");
        layout->addWidget(cbox);
    }

    virtual QDomDocument getXml() {
        QDomDocument doc;
        QDomElement root = doc.createElement("usepopdata");
        doc.appendChild(root);
        root.appendChild(doc.createTextNode(cbox->isChecked() ? "true" : "false"));
        return doc;
    }

    virtual void setXml(QDomElement node) {
        cbox->setChecked(node.text().compare("true", Qt::CaseInsensitive) == 0);
    }

    virtual void setEditMode(bool /*enable*/) {

    }

    virtual QString genLua() {
        return var + " = " + (cbox->isChecked() ? "true" : "false") + '\n';
    }

    virtual QString genR() {
        return genLua();
    }
};

PopulationData::PopulationData(QWidget *parent) :
    Group(parent)
{
    usePopData = new CBField;
    addComponent(usePopData);

    pa = addText();
    pa->setLabel("Population attribute:");
    pa->setEnabled(false);

    pp = addFloating();
    pp->setLabel("Population percentage:");
    pp->attr["precision"] = QString::number(4);
    pp->attr["step"] = QString::number(0.0001);
    pp->attr["minimum"] = QString::number(0);
    pp->attr["maximum"] = QString::number(1);
    pp->setEnabled(false);

    pcwh = addFloating();
    pcwh->setLabel("Percentage of cells with humans:");
    pcwh->attr["precision"] = QString::number(4);
    pcwh->attr["step"] = QString::number(0.0001);
    pcwh->attr["minimum"] = QString::number(0);
    pcwh->attr["maximum"] = QString::number(1);

    hpc = addInteger();
    hpc->setLabel("Humans per cell:");
    hpc->attr["minimum"] = QString::number(1);
    hpc->attr["maximum"] = QString::number(999999999);

    connect(usePopData->cbox, SIGNAL(toggled(bool)), pa, SLOT(setEnabled(bool)));
    connect(usePopData->cbox, SIGNAL(toggled(bool)), pp, SLOT(setEnabled(bool)));
    connect(usePopData->cbox, SIGNAL(toggled(bool)), pcwh, SLOT(setDisabled(bool)));
    connect(usePopData->cbox, SIGNAL(toggled(bool)), hpc, SLOT(setDisabled(bool)));

    dmr = addFloating();
    dmr->setLabel("Daily mobility rate:");
    dmr->attr["precision"] = QString::number(4);
    dmr->attr["step"] = QString::number(0.0001);
    dmr->attr["minimum"] = QString::number(0);
    dmr->attr["maximum"] = QString::number(1);

    dmrp = addFloating();
    dmrp->setLabel("Daily mobility rate to public locations:");
    dmrp->attr["precision"] = QString::number(4);
    dmrp->attr["step"] = QString::number(0.0001);
    dmrp->attr["minimum"] = QString::number(0);
    dmrp->attr["maximum"] = QString::number(1);

    ahrr = addFloating();
    ahrr->setLabel("Annual human renewal rate:");
    ahrr->attr["precision"] = QString::number(4);
    ahrr->attr["step"] = QString::number(0.0001);
    ahrr->attr["minimum"] = QString::number(0);
    ahrr->attr["maximum"] = QString::number(1);

    paih = addFloating();
    paih->setLabel("Percentage of assymptomatic infected humans:");
    paih->attr["precision"] = QString::number(4);
    paih->attr["step"] = QString::number(0.0001);
    paih->attr["minimum"] = QString::number(0);
    paih->attr["maximum"] = QString::number(1);

    setLabel("Parameters about humans");

    Group::setEditMode(false);
    setEditMode(true);
}

QDomDocument PopulationData::getXml()
{
    QDomDocument doc;
    QDomElement root = doc.createElement("populationdata");

    root.appendChild(usePopData->getXml());
    {
        QDomElement s = pa->getXml().firstChildElement();
        s.setTagName("pa");
        root.appendChild(s);
    }
    {
        QDomElement s = pp->getXml().firstChildElement();
        s.setTagName("pp");
        root.appendChild(s);
    }
    {
        QDomElement s = pcwh->getXml().firstChildElement();
        s.setTagName("pcwh");
        root.appendChild(s);
    }
    {
        QDomElement s = hpc->getXml().firstChildElement();
        s.setTagName("hpc");
        root.appendChild(s);
    }
    {
        QDomElement s = dmr->getXml().firstChildElement();
        s.setTagName("dmr");
        root.appendChild(s);
    }
    {
        QDomElement s = dmrp->getXml().firstChildElement();
        s.setTagName("dmrp");
        root.appendChild(s);
    }
    {
        QDomElement s = ahrr->getXml().firstChildElement();
        s.setTagName("ahrr");
        root.appendChild(s);
    }
    {
        QDomElement s = paih->getXml().firstChildElement();
        s.setTagName("paih");
        root.appendChild(s);
    }

    doc.appendChild(root);

    return doc;
}

void PopulationData::setXml(QDomElement root)
{
    usePopData->setXml(root.firstChildElement("usepopdata"));
    pa->setXml(root.firstChildElement("pa"));
    pp->setXml(root.firstChildElement("pp"));
    pcwh->setXml(root.firstChildElement("pcwh"));
    hpc->setXml(root.firstChildElement("hpc"));
    dmr->setXml(root.firstChildElement("dmr"));
    dmrp->setXml(root.firstChildElement("dmrp"));
    ahrr->setXml(root.firstChildElement("ahrr"));
    paih->setXml(root.firstChildElement("paih"));

    varNames();
}

void PopulationData::setEditMode(bool enable)
{
    ui->removeGroup->setVisible(enable);
}

void PopulationData::varNames()
{
    pa->setId("POPULATION_ATTRIBUTE");
    pp->setId("POPULATION_PERCENTAGE");
    pcwh->setId("PERCENTAGE_CELLS_HUMANS");
    hpc->setId("HUMANS_BY_CELL");
    dmr->setId("HUMAN_MOBILITY_PERCENTAGE");
    dmrp->setId("PERCENTAGE_HUMANS_PUBLIC_LOCATIONS");
    ahrr->setId("ANNUAL_HUMAN_RENEWAL");
    paih->setId("PERCENTAGE_ASSYMPTOMATIC_INFECTED_HUM");
}


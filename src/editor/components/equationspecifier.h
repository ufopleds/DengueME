#ifndef EQUATIONSPECIFIER_H
#define EQUATIONSPECIFIER_H

#include <QtWidgets>
#include <QtXml>
#include "../component.h"

namespace Ui {
class EquationSpecifier;
}

class EquationSpecifier : public Component
{
    Q_OBJECT

public:
    explicit EquationSpecifier(QWidget *parent = 0);
    ~EquationSpecifier();
    QDomDocument getXml();
    void setXml(QDomElement node);
    void setEditMode(bool enable);
    QString genLua();
    QString genR();

private slots:
    void openCalculator();
    void onActionDelete();
   /* void onMorphBoolean( );
    void onMorphCombobox();
    void onMorphText();
    void onMorphInteger();
    void onMorphFloat();*/
    void onMorph(QString);


    void onActionClone();
private:
    Ui::EquationSpecifier *ui;
};

#endif // EQUATIONSPECIFIER_H


#ifndef COMPONENT_H
#define COMPONENT_H

#include <QtXml>
#include <QWidget>

class Component : public QWidget {
    Q_OBJECT
public:
    inline Component(QWidget *parent = 0) : QWidget(parent) { }
    virtual inline ~Component() { }
    virtual QDomDocument getXml() = 0;
    virtual void setXml(QDomElement node) = 0;
    virtual void setEditMode(bool enable) = 0;
    virtual QString genLua() = 0; // quick and dirty
    virtual QString genR() = 0; // quick and dirty

signals:
    void remove();
};

#endif // COMPONENT_H


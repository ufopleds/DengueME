#include "group.h"
#include "ui_group.h"
#include <QDebug>
Group::Group(QWidget *parent) :
    Component(parent),
    ui(new Ui::Group)
{
    ui->setupUi(this);
    defaultHeight = height();
    setMinimumHeight(height());

    listDefaultHeight = 64;
    ui->widgets->setMaximumHeight(listDefaultHeight);

    QFont font;
    font.setBold(true);
    ui->label->setFont(font);

    connect(ui->removeGroup, SIGNAL(clicked(bool)), SLOT(askRemoveGroup()));

    QMenu   *menu     = new QMenu(this);
    QAction *boolean = new QAction("&Boolean field",menu);
    QAction *text     = new QAction("&Text field", menu);
    QAction *integer  = new QAction("&Integer field", menu);
    QAction *floating = new QAction("&Floating field", menu);
    QAction *combobox = new QAction("C&ombobox", menu);
    QAction *csv      = new QAction("C&SV", menu);

    menu->addAction(boolean);
    menu->addAction(text);
    menu->addAction(integer);
    menu->addAction(floating);
    menu->addAction(combobox);
    menu->addAction(csv);

    connect(boolean, SIGNAL(triggered()),SLOT(addBoolean()));
    connect(text,     SIGNAL(triggered()), SLOT(addText()));
    connect(integer,  SIGNAL(triggered()), SLOT(addInteger()));
    connect(floating, SIGNAL(triggered()), SLOT(addFloating()));
    connect(combobox, SIGNAL(triggered()), SLOT(addCombobox()));
    connect(csv,      SIGNAL(triggered()), SLOT(addCsv()));

    ui->addField->setMenu(menu);
}

Group::~Group()
{
    delete ui;
}
void Group::askRemoveGroup(){
    int opt = QMessageBox::question(this,tr("Remove Group"),
                                    tr("This action will remove the group and all its fields. Do you want to continue?"),
                                    QMessageBox::Yes | QMessageBox::No);


    if(opt == QMessageBox::Yes){
        onRemove();
    }
}

void Group::setLabel(QString label){

    ui->label->setText(label);
}

QDomDocument Group::getXml()
{
    QDomDocument ret;
    if (ui->widgets->count() == 0) return ret;

    QDomElement root = ret.createElement("groupbox");
    root.setAttribute("label", ui->label->text());

    for (int i = 0; i < ui->widgets->count(); ++i) {
        Component *comp = map.value(ui->widgets->item(i));
        if (comp)
            root.appendChild(comp->getXml());
    }

    ret.appendChild(root);
    return ret;
}

void Group::setXml(QDomElement root)
{
    ui->widgets->clear();
    ui->label->setText(root.attribute("label"));
    for (QDomElement node = root.firstChildElement(); !node.isNull(); node = node.nextSiblingElement()) {
        if (node.nodeName() == "field") {
            addComponent(new Field)->setXml(node);
        } else if (node.tagName() == "csv") {
            Component *comp = new ImportCsv;
            comp->setXml(node);
            addComponent(comp);
        }
    }
}

void Group::setEditMode(bool enable)
{
    for (int i = 0; i < ui->widgets->count(); ++i) {
        Component *comp = map.value(ui->widgets->item(i));
        if (comp)
            comp->setEditMode(enable);
    }
    ui->removeGroup->setVisible(enable);
    ui->addField->setVisible(enable);
    ui->label->setReadOnly(!enable);

    if (enable) {
        ui->widgets->setSelectionMode(QAbstractItemView::SingleSelection);
    } else {
        ui->widgets->setSelectionMode(QAbstractItemView::NoSelection);
    }
}

void Group::setRemovable(bool enable)
{
    ui->removeGroup->setVisible(enable);
    ui->label->setReadOnly(!enable);
}

QString Group::genLua()
{
    QString ret;
    for (int i = 0; i < ui->widgets->count(); ++i) {
        Component *comp = map.value(ui->widgets->item(i));
        if (comp)
            ret += comp->genLua();

    }
    return ret;
}

QString Group::genR()
{
    QString ret;
    for (int i = 0; i < ui->widgets->count(); ++i) {
        Component *comp = map.value(ui->widgets->item(i));
        if (comp)
            ret += comp->genR();
    }
    return ret;
}

void Group::updateHeight(){

    int height = 8;
//    int count = (ui->widgets->count() < 4) ? ui->widgets->count() : 4;
    for (int i = 0; i < ui->widgets->count(); ++i)
        height += ui->widgets->sizeHintForRow(i);

    if (height < listDefaultHeight) height = listDefaultHeight;

    ui->widgets->setMaximumHeight(height);

    height = height + defaultHeight - listDefaultHeight;
    setMinimumHeight(height);
    emit heightChanged(height);
}

void Group::removeField(){

    QObject *field = QObject::sender();

    delete ui->widgets->takeItem(ui->widgets->row(map.key((Field *) field)));

    updateHeight();
}

void Group::cloneField(){
        QObject *field = QObject::sender();
        /// TODO - MELHORAR CLONE

         if("Text" ==  ui->widgets->item( ui->widgets->row(map.key((Field *) field)))->toolTip()){
            addText();
        }
        else if("Boolean" ==  ui->widgets->item( ui->widgets->row(map.key((Field *) field)))->toolTip()){
            addBoolean();
        }
        else if("Integer" ==  ui->widgets->item( ui->widgets->row(map.key((Field *) field)))->toolTip()){
            addInteger();
        }
        else if("Float" ==  ui->widgets->item( ui->widgets->row(map.key((Field *) field)))->toolTip()){
            addFloating();
        }
        else if("Combobox" ==  ui->widgets->item( ui->widgets->row(map.key((Field *) field)))->toolTip()){
            addCombobox();
        }
        else if("ImportCsv" ==   QObject::sender()->objectName()){
            addCsv();
        }

}

Field *Group::addText(){

    Field *field = new Field;
    field->onActionText();
    field->setToolTip("Text");
    addComponent(field);

    return field;
}
Field *Group::addBoolean(){

    Field *field = new Field;
    field->onActionBoolean();
    field->setToolTip("Boolean");
    addComponent(field);

    return field;
}
Field *Group::addInteger(){

    Field *field = new Field;
    field->onActionInteger();
    field->setToolTip("Integer");
    addComponent(field);

    return field;
}

Field *Group::addFloating(){

    Field *field = new Field;
    field->onActionFloating();
    field->setToolTip("Float");
    addComponent(field);

    return field;
}

/*Field *Group::addCheckbox()
{
    Field *field = new Field;
    field->onActionCheckbox();

    addComponent(field);

    return field;
}*/

Field *Group::addCombobox(){

    Field *field = new Field;

    field->onActionCombobox();
     field->setToolTip("Combobox");

    if (field->onActionOptions())
        addComponent(field);
    else {
        delete field;
        field = NULL;
    }

    return field;
}

ImportCsv *Group::addCsv()
{
    ImportCsv *field = new ImportCsv;
    field->setToolTip("Csv");
    addComponent(field);

    return field;
}

void Group::morphField(QString type){

    if(type == "Boolean")
        addBoolean();
    else if(type == "csv")
        addCsv();
    else if(type == "Text")
        addText();
    else if(type == "Integer")
        addInteger();
    else if(type == "Float")
        addFloating();
    else if(type == "Combobox")
        addCombobox();

}

void Group::changeType(QString type){

    QObject *field = QObject::sender();

   ui->widgets->item( ui->widgets->row(map.key((Field *) field)))->setToolTip(type);

    updateHeight();
}

Component *Group::addComponent(Component *comp){

    QListWidgetItem *item = new QListWidgetItem;

    item->setSizeHint(QSize(-1,comp->height()));
    item->setToolTip(comp->toolTip());

    ui->widgets->addItem(item);
    ui->widgets->setItemWidget(item,comp);
    ui->widgets->scrollToBottom();

    connect(comp, SIGNAL(remove()), SLOT(removeField ()));
    connect(comp, SIGNAL(clone()), SLOT(cloneField ()));
    connect(comp, SIGNAL(csv(QString)), SLOT(morphField(QString)));
    connect(comp, SIGNAL(changeType(QString)), SLOT(changeType (QString)));
    map.insert(item, comp);

    updateHeight();
    return comp;
}


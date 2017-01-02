#include "chartgroup.h"
#include "ui_group.h"

ChartGroup::ChartGroup(QWidget *parent):
    Component(parent),
    ui(new Ui::Group){


    ui->setupUi(this);
    defaultHeight = height();
    setMinimumHeight(height());

    listDefaultHeight = 64;
    ui->widgets->setMaximumHeight(listDefaultHeight);

    QFont font;
    font.setBold(true);
    ui->label->setFont(font);
    ui->addField->setText(tr("Add plot variable"));

    connect(ui->removeGroup, SIGNAL(clicked(bool)), SLOT(askRemoveGroup()));

    QMenu   *menu     = new QMenu(this);
    QAction *plotVariable = new QAction(tr("&Plot variable"), menu);


    menu->addAction(plotVariable);

    connect(    ui->addField,      SIGNAL(clicked()), SLOT(addVariable()));
    connect(ui->useGroup, SIGNAL(toggled(bool)), SLOT(togglePlotCheckbox(bool)));
    connect(ui->label, SIGNAL(textChanged(QString)), this, SLOT(validateId(QString)));


    ui->removeGroup->setText("Remove chart");
    ui->label->setFrame(true);
    ui->label->setText(tr("New Chart"));
  //  ui->addField->setMenu(menu);
}

ChartGroup::~ChartGroup(){
    delete ui;
}



void ChartGroup::validateId(QString name){

    if (!QRegExp("[A-Za-z0-9_]+").exactMatch(name)){
        ui->label->setText(purgeName(name));
        QToolTip::showText(  ui->label->mapToGlobal(QPoint(0,  ui->label->height())),
                             tr("The id name can contain only\nalphanumeric chars and,"
                                " \nunderscore (_)."));
    }
}

QString ChartGroup::purgeName(QString name) {
    return name.remove(QRegExp("[^A-Za-z0-9_]"));
}

void ChartGroup::askRemoveGroup(){
    int opt = QMessageBox::question(this,tr("Remove Chart"),
                                    tr("This action will remove the chart and all its variabes. Do you want to continue?"),
                                    QMessageBox::Yes | QMessageBox::No);

    if(opt == QMessageBox::Yes) {
        onRemove();
    }
}

void ChartGroup::setLabel(QString label) {
    ui->label->setText(label);
}


QDomDocument ChartGroup::getXml() {

    QDomDocument ret;

    if (ui->widgets->count() == 0) return ret;

    QDomElement root = ret.createElement("outChart");

    root.setAttribute("label", ui->label->text());
    root.setAttribute("output", ui->useGroup->isChecked() ? "true": "false");

    for (int i = 0; i < ui->widgets->count(); ++i) {
        Component *comp = map.value(ui->widgets->item(i));

        if (comp)
            root.appendChild(comp->getXml());
    }
    ret.appendChild(root);
    return ret;
}


void ChartGroup::setXml(QDomElement root){

    ui->widgets->clear();
    ui->label->setText(root.attribute("label"));

    if(root.attribute("output") == "true"){
        ui->useGroup->setChecked(true);
    }else{
        ui->useGroup->setChecked(false);
    }

    for (QDomElement node = root.firstChildElement(); !node.isNull(); node = node.nextSiblingElement()) {
        if (node.nodeName() == "variable") {
            addComponent(new ChartField)->setXml(node);
        }
    }
}


void ChartGroup::setEditMode(bool enable){

    for (int i = 0; i < ui->widgets->count(); ++i) {
        Component *comp = map.value(ui->widgets->item(i));
        if (comp)
            comp->setEditMode(enable);
    }

    ui->label->setFrame(enable);
    ui->removeGroup->setVisible(enable);
    ui->addField->setVisible(enable);
    ui->label->setReadOnly(!enable);


    if(ui->useGroup->isChecked()){
        for (int i = 0; i < ui->widgets->count(); ++i) {
            ChartField *comp =  dynamic_cast<ChartField *>(map.value(ui->widgets->item(i)));
            if (comp){
                comp->offField(true);
            }
        }
    }else{
        for (int i = 0; i < ui->widgets->count(); ++i) {
            ChartField *comp =  dynamic_cast<ChartField *>(map.value(ui->widgets->item(i)));

            if (comp){
                comp->offField(false);
            }
        }
    }

    if (enable) {
        ui->widgets->setSelectionMode(QAbstractItemView::SingleSelection);
    } else {
        ui->widgets->setSelectionMode(QAbstractItemView::NoSelection);
    }
}


void ChartGroup::setRemovable(bool enable){
    ui->removeGroup->setVisible(enable);
    ui->label->setReadOnly(!enable);
}


QString ChartGroup::genLua(){

    QString ret,chart, select, label, style, color;

    chart = ui->label->text()+"= false\n";
    int countFalse = 0;

    if(ui->useGroup->isChecked()){

        select =ui->label->text()+ "Select = {";
        label = ui->label->text()+"Label = {";
        style =ui->label->text()+ "Style = {";
        color = ui->label->text()+"Color = {";
        chart =  ui->label->text()+" = true\n";

        for (int i = 0; i < ui->widgets->count(); ++i) {

            ChartField *comp =  dynamic_cast<ChartField *>(map.value(ui->widgets->item(i)));

            if (comp){

                ret = comp->genLua();

                if(ret !="false"){
                    QStringList values = ret.split(',');
                    select+="\""+values.value(1)+"\",";
                    label+="\""+values.value(0)+"\",";
                    color+="\""+values.value(2)+"\",";
                    style+="\""+values.value(3)+"\",";
                }
                else{
                    countFalse++;
                    ret = "";
                }
            }
        }
        select.remove(select.size()-1,1);
        label.remove(label.size()-1,1);
        style.remove(style.size()-1,1);
        color.remove(color.size()-1,1);

        select+= "}";
        label+= "}";
        style+= "}";
        color+= "}";

        ret =chart+"\n"+ select+"\n"+label+"\n"+style+"\n"+color+"\n";
    }

    if(ui->widgets->count() == countFalse || !ui->useGroup->isChecked() ){
        ret =     ui->label->text()+"= false \n";
    }

    return ret;
}


QString ChartGroup::genR(){
    return "";
}



void ChartGroup::updateHeight(){

    int height = 8;
    for (int i = 0; i < ui->widgets->count(); ++i)
        height += ui->widgets->sizeHintForRow(i);

    if (height < listDefaultHeight) height = listDefaultHeight;

    ui->widgets->setMaximumHeight(height);

    height = height + defaultHeight - listDefaultHeight;
    setMinimumHeight(height);
    emit heightChanged(height);
}



void ChartGroup::removeField(){

    QObject *field = QObject::sender();

    delete ui->widgets->takeItem(ui->widgets->row(map.key((ChartField *) field)));

    updateHeight();

}


void ChartGroup::cloneField(){ 
    addVariable();
}

void ChartGroup::togglePlotCheckbox(bool enable){
    for (int i = 0; i < ui->widgets->count(); ++i) {
        ChartField *comp =  dynamic_cast<ChartField *>(map.value(ui->widgets->item(i)));
        if (comp){
            comp->offField(enable);
        }
    }
}

ChartField *ChartGroup::addVariable(){

    ChartField *field = new ChartField;
    field->onActionVariable();
    field->setToolTip("Variable");
    addComponent(field);

    return field;
}


void ChartGroup::changeType(QString type){

    QObject *field = QObject::sender();

    ui->widgets->item( ui->widgets->row(map.key((ChartField *) field)))->setToolTip(type);

    updateHeight();

}


Component *ChartGroup::addComponent(Component *comp){

    QListWidgetItem *item = new QListWidgetItem;

    item->setSizeHint(QSize(-1,comp->height()));
    item->setToolTip(comp->toolTip());


    ui->widgets->addItem(item);
    ui->widgets->setItemWidget(item,comp);
    ui->widgets->scrollToBottom();

    connect(comp, SIGNAL(remove()), SLOT(removeField ()));
    connect(comp, SIGNAL(clone()), SLOT(cloneField ()));
    connect(comp, SIGNAL(changeType(QString)), SLOT(changeType (QString)));
    map.insert(item, comp);


    updateHeight();
    return comp;
}


#include "visualtablefield.h"
#include "ui_visualtablefield.h"

VisualTableField::VisualTableField(QWidget *parent) :
    Component(parent),
    widget(NULL),
    ui(new Ui::VisualTableField),
    type(Null)
{
    ui->setupUi(this);
    menu = new QMenu(this);

    actionVariable     = new QAction(tr("&Variable"),menu);
    actionDelete   = new QAction(tr("&Delete"),menu);
    actionClone =new QAction(tr("Cl&one"),menu);

    actionVariable->setCheckable(true);

    menu->addAction(actionVariable);

    connect(actionVariable,     SIGNAL(triggered()), SLOT(onActionVariable()));
    connect(ui->rButton,     SIGNAL(clicked()),this, SLOT(useLogVariable()));
    connect(ui->lButton,     SIGNAL(clicked()), this, SLOT(notUseLogVariable()));
    connect(ui->add, SIGNAL(clicked()), SLOT(add()));
    connect(ui->del, SIGNAL(clicked()), SLOT(del()));

    updateMenu();
}

VisualTableField::~VisualTableField()
{
    delete ui;
}

void VisualTableField::useLogVariable(){
    QList<QListWidgetItem *> selected = ui->defaultVarList->selectedItems();
    if(!selected.empty()){
        for(int i=0; i<selected.count();i++){
            QListWidgetItem *item = new QListWidgetItem("");
            item->setText(selected.at(i)->text());
            item->setFlags(item->flags());
            ui->useVarList->addItem(item);
            ui->useVarList->scrollToItem(item);
            ui->useVarList->setFocus();
        }
        qDeleteAll(  ui->defaultVarList->selectedItems());

    }
}
void VisualTableField::notUseLogVariable(){
    QList<QListWidgetItem *> selected = ui->useVarList->selectedItems();
    if(!selected.empty()){
        for(int i=0; i<selected.count();i++){
            QListWidgetItem *item = new QListWidgetItem("");
            item->setText(selected.at(i)->text());
            item->setFlags(item->flags() | Qt::ItemIsEditable);
            ui->defaultVarList->addItem(item);
            ui->defaultVarList->scrollToItem(item);
            ui->defaultVarList->setFocus();
        }
        qDeleteAll(  ui->useVarList->selectedItems());
    }
}

void VisualTableField::add(){
    QListWidgetItem *item = new QListWidgetItem("New item");
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->defaultVarList->addItem(item);
    ui->defaultVarList->scrollToItem(item);
    ui->defaultVarList->setFocus();
    ui->defaultVarList->editItem(item);
}

void VisualTableField::del(){
    delete ui->defaultVarList->takeItem(ui->defaultVarList->currentRow());
}

QDomDocument VisualTableField::getXml(){

    QDomDocument ret;
    if(ui->useVarList->count() == 0 && ui->defaultVarList->count() == 0){
        QDomElement opt = ret.createElement("tableVariable");
        opt.appendChild(ret.createTextNode("empty"));
        opt.setAttribute("use", "0");
        ret.appendChild(opt);
    }

    for (int i = 0; i < ui->useVarList->count(); ++i) {
        QDomElement opt = ret.createElement("tableVariable");
        opt.appendChild(ret.createTextNode(ui->useVarList->item(i)->text()));
        opt.setAttribute("use", "1");
        ret.appendChild(opt);
    }
    for (int i = 0; i < ui->defaultVarList->count(); ++i) {
        QDomElement opt = ret.createElement("tableVariable");
        opt.appendChild(ret.createTextNode(ui->defaultVarList->item(i)->text()));
        opt.setAttribute("use", "0");
        ret.appendChild(opt);
    }



    return ret;
}

void VisualTableField::setXml(QDomElement node){
    if(node.text() != "empty"){
        for (QDomElement opt = node; !opt.isNull(); opt = opt.nextSiblingElement("tableVariable")){
            if(opt.attribute("use")=="1")
                ui->useVarList->addItem(opt.text());
            else
                ui->defaultVarList->addItem(opt.text());
        }
    }

}




void VisualTableField::offField( bool enable){


    onField(enable);
}

void VisualTableField::onField(bool editable){
    ui->lButton->setEnabled(editable);
    ui->rButton->setEnabled(editable);
    ui->useVarList->setEnabled(editable);
    ui->defaultVarList->setEnabled(editable);
}


void VisualTableField::setEditMode(bool enable){


    ui->add->setVisible(enable);
    ui->del->setVisible(enable);

    if (enable) {
        ui->container->setToolTip("Default value");
        ui->horizontalLayout->setStretch(ui->horizontalLayout->indexOf(ui->container),0);
    } else {
        ui->container->setToolTip("");
        ui->horizontalLayout->setStretch(ui->horizontalLayout->indexOf(ui->container),5);
    }
}

QString VisualTableField::genLua(){

    QString ret ="";
    if(ui->useVarList->count()==0){
        return "false";
    }
    else{
        for(int i=0; i<ui->useVarList->count();i++){
            ret.append(ui->useVarList->item(i)->text()+",");
        }

        ret.remove(ret.size()-1,1);
        return ret;
    }
}

QString VisualTableField::genR(){
    return "";
}

void VisualTableField::updateMenu(){
    actionVariable->setChecked(type == Variable);
}

void VisualTableField::setWidget(QWidget *widget){
    delete this->widget;
    this->widget = widget;

    widget->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    widget->setMinimumWidth(160);
    widget->setMaximumWidth(160);

    ui->container->layout()->addWidget(widget);
    ui->container->layout()->setAlignment(widget, Qt::AlignLeft);

    // setTabOrder(ui->userLabel, widget);


    updateMenu();
}


void VisualTableField::onActionVariable(){
    type = Variable;
    emit changeType("Variable");


}

void VisualTableField::onActionClone(){
    emit clone();
}

void VisualTableField::onActionDelete()
{
    int opt = QMessageBox::question(this,tr("Remove Field"),
                                    tr("This action will remove this field. Do you want to continue?"),
                                    QMessageBox::Yes | QMessageBox::No);


    if(opt == QMessageBox::Yes){
        emit remove();
    }

}

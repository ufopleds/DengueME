#include "logfield.h"
#include "ui_logfield.h"

LogField::LogField(QWidget *parent):
    Component(parent),
    widget(NULL),
    ui(new Ui::LogField),
    type(Null)
{
    ui->setupUi(this);

    menu = new QMenu(this);

    actionVariable     = new QAction(tr("&Plot Variable"),menu);
    actionDelete   = new QAction(tr("&Delete"),menu);
    actionClone =new QAction(tr("Cl&one"),menu);

    actionVariable->setCheckable(true);

    menu->addAction(actionVariable);

    connect(actionVariable,     SIGNAL(triggered()), SLOT(onActionVariable()));
    connect(ui->fileName, SIGNAL(textChanged(QString)), this, SLOT(validateId(QString)));
    connect(ui->rButton, SIGNAL(clicked()), this, SLOT(useLogVariable()));
    connect(ui->lButton, SIGNAL(clicked()), this, SLOT(notUseLogVariable()));
    connect(ui->add, SIGNAL(clicked()), SLOT(add()));
    connect(ui->del, SIGNAL(clicked()), SLOT(del()));

    ui->separator->setCurrentIndex(0);
    updateMenu();

}
void LogField::updateMenu(){
    actionVariable->setChecked(type == Variable);
}
LogField::~LogField(){
    delete ui;
}
void LogField::useLogVariable(){
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
void LogField::notUseLogVariable(){
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

void LogField::add(){
    QListWidgetItem *item = new QListWidgetItem("New item");
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->defaultVarList->addItem(item);
    ui->defaultVarList->scrollToItem(item);
    ui->defaultVarList->setFocus();
    ui->defaultVarList->editItem(item);
}

void LogField::del(){
    delete ui->defaultVarList->takeItem(ui->defaultVarList->currentRow());
}

void LogField::validateId(QString name){

    if (!QRegExp("[A-Za-z0-9_]+").exactMatch(name)){
        ui->fileName->setText(purgeName(name));
        QToolTip::showText(  ui->fileName->mapToGlobal(QPoint(0,  ui->fileName->height())),
                             tr("The id name can contain only\nalphanumeric chars and,"
                                " \nunderscore (_)."));
    }
}

QString LogField::purgeName(QString name) {
    return name.remove(QRegExp("[^A-Za-z0-9_]"));
}

QDomDocument LogField::getXml(){

    QDomDocument ret;
    QDomElement node = ret.createElement("logConfig");

    for (int i = 0; i < ui->useVarList->count(); ++i) {
        QDomElement opt = ret.createElement("logVariable");
        opt.appendChild(ret.createTextNode(ui->useVarList->item(i)->text()));
        opt.setAttribute("use", "1");
        node.appendChild(opt);
    }
    for (int i = 0; i < ui->defaultVarList->count(); ++i) {
        QDomElement opt = ret.createElement("logVariable");
        opt.appendChild(ret.createTextNode(ui->defaultVarList->item(i)->text()));
        opt.setAttribute("use", "0");
        node.appendChild(opt);
    }

    node.setAttribute("filename", ui->fileName->text());
    node.setAttribute("separator", ui->separator->currentText());
    node.setAttribute("overwrite",ui->overwrite->isChecked() ? "true": "false");
    ret.appendChild(node);

    return ret;
}

void LogField::setXml(QDomElement node){


    ui->fileName->setText(node.attribute("filename"));
    ui->overwrite->setChecked(node.attribute("overwrite") == "true" ? true : false);
    ui->separator->setCurrentIndex(ui->separator->findText(node.attribute("separator")));
    for (QDomElement opt = node.firstChildElement("logVariable"); !opt.isNull(); opt = opt.nextSiblingElement("logVariable")){
        if(opt.attribute("use")=="1")
            ui->useVarList->addItem(opt.text());
        else
            ui->defaultVarList->addItem(opt.text());

    }




}

void LogField::offField(bool enable){
    onField(enable);

}

void LogField::onField(bool editable){

    ui->lButton->setEnabled(editable);
    ui->rButton->setEnabled(editable);
    ui->useVarList->setEnabled(editable);
    ui->defaultVarList->setEnabled(editable);
    ui->fileName->setEnabled(editable);
    ui->fileName->setFrame(editable);
    ui->separator->setEnabled(editable);
    ui->overwrite->setEnabled(editable);
}


void LogField::setEditMode(bool enable){




    ui->labelId->setVisible(enable);
    ui->id->setVisible(enable);
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
void LogField::onActionVariable(){
    type = Variable;
    emit changeType("Variable");


}
QString LogField::genLua(){

    QString ret ="";

    ret.append(ui->fileName->text()+",");
    ret.append(ui->overwrite->isChecked()? "true," : "false,");
    if(ui->separator->currentText() ==","){
        ret.append("comma,");
    }else{
        ret.append(ui->separator->currentText()+",");
    }


    for(int i=0; i<ui->useVarList->count();i++){       
            ret.append(ui->useVarList->item(i)->text()+",");        
    }

    ret.remove(ret.size()-1,1);



    return ret;
}

QString LogField::genR(){
    return "";
}

void LogField::setWidget(QWidget *widget){
    delete this->widget;
    this->widget = widget;

    widget->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    widget->setMinimumWidth(160);
    widget->setMaximumWidth(160);

    ui->container->layout()->addWidget(widget);
    ui->container->layout()->setAlignment(widget, Qt::AlignLeft);





}


void LogField::onActionDelete()
{
    int opt = QMessageBox::question(this,tr("Remove Field"),
                                    tr("This action will remove this field. Do you want to continue?"),
                                    QMessageBox::Yes | QMessageBox::No);


    if(opt == QMessageBox::Yes){
        emit remove();
    }

}

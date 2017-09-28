#include "dengueme.h"
#include "equationspecifier.h"
#include "ui_equationspecifier.h"

EquationSpecifier::EquationSpecifier(QWidget *parent) :
    Component(parent),
    ui(new Ui::EquationSpecifier)
{
    ui->setupUi(this);

    connect(ui->toolCalculator, SIGNAL(clicked()), this, SLOT(openCalculator()));

    QMenu *menu = new QMenu(this);

    QAction *actionBoolean  = new QAction(tr("&Boolean"),menu);
    QAction *actionText     = new QAction(tr("&Text"),menu);
    QAction  *actionInteger = new QAction(tr("&Integer"),menu);
    QAction *actionFloating = new QAction(tr("&Floating point"),menu);
    QAction *actionCombobox = new QAction(tr("C&ombobox"),menu);
    QAction *actionCsv      = new QAction(tr("Csv"),menu);
    QAction *actionEquation = new QAction(tr("Csv"),menu);

    actionCsv->setCheckable(true);
    actionEquation->setCheckable(true);
    actionBoolean->setCheckable(true);
    actionText->setCheckable(true);
    actionInteger->setCheckable(true);
    actionFloating->setCheckable(true);
    actionCombobox->setCheckable(true);

    menu->addAction(actionEquation);
    menu->addAction(actionCsv);
    menu->addAction(actionBoolean);
    menu->addAction(actionText);
    menu->addAction(actionInteger);
    menu->addAction(actionFloating);
    menu->addAction(actionCombobox);


    ui->options->setMenu(menu);

    //C++ 11  +  Qt5 lambda connect, necessary to pass parameters
    connect(actionText,  &QAction::triggered, this, [this]{ onMorph("Text"); });
    connect(actionInteger,  &QAction::triggered, this, [this]{ onMorph("Integer"); });
    connect(actionFloating,  &QAction::triggered, this, [this]{ onMorph("Float"); });
    connect(actionCombobox,  &QAction::triggered, this, [this]{ onMorph("Combobox"); });
    connect(actionBoolean,  &QAction::triggered, this, [this]{ onMorph("Boolean"); });

    connect(ui->toolDelete,   SIGNAL(clicked()), SLOT(onActionDelete()));
    connect(ui->toolClone,   SIGNAL(clicked()), SLOT(onActionClone()));

    ui->toolOptions->setEnabled(false);
    ui->toolOptions->setToolTip("Options");
    ui->toolDelete->setToolTip("Delete");
    ui->toolClone->setToolTip("Clone");
    ui->options->setMenu(menu);
}


EquationSpecifier::~EquationSpecifier()
{
    delete ui;
}

QDomDocument EquationSpecifier::getXml()
{
    QDomDocument ret;
    QDomElement node = ret.createElement("field");

    node.setAttribute("type","lineedit");
    node.setAttribute("label", ui->label->text());
    node.setAttribute("id", ui->var->text());
    node.setAttribute("description",ui->descript->text());

    ret.appendChild(node);
    return ret;

}

void EquationSpecifier::setXml(QDomElement node)
{


}

void EquationSpecifier::setEditMode(bool enable)
{
    ui->options->setVisible(enable);
    ui->var->setVisible(enable);
    ui->line->setVisible(enable);
    ui->label->setReadOnly(!enable);
    ui->toolClone->setVisible(enable);
    ui->toolDelete->setVisible(enable);
    ui->toolOptions->setVisible(enable);

}

QString EquationSpecifier::genLua()
{

}

QString EquationSpecifier::genR()
{

}

void EquationSpecifier::openCalculator()
{

}

void EquationSpecifier::onMorph(QString type){
    emit remove();

}


void EquationSpecifier::onActionClone(){
    emit clone();
}
void EquationSpecifier::onActionDelete( )
{

    int opt = QMessageBox::question(this,tr("Remove Field"),
                                    tr("This action will remove this field. Do you want to continue?"),
                                    QMessageBox::Yes | QMessageBox::No);

    if(opt == QMessageBox::Yes){
        emit remove();
    }

}


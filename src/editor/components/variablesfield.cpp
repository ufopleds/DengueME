
include "variablesfield.h"
#include "ui_variablesfield.h"

VariablesField::VariablesField(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VariablesField)
{
    ui->setupUi(this);
}

VariablesField::~VariablesField()
{
    delete ui;
}

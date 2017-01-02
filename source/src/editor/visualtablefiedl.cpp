#include "visualtablefiedl.h"
#include "ui_visualtablefiedl.h"

VisualTableFiedl::VisualTableFiedl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisualTableFiedl)
{
    ui->setupUi(this);
}

VisualTableFiedl::~VisualTableFiedl()
{
    delete ui;
}

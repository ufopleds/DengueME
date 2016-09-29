#include "descriptionwindow.h"
#include "ui_descriptionwindow.h"
#include <QDebug>
#include <QSizePolicy>
DescriptionWindow::DescriptionWindow(QWidget *parent,QString description) :
    QDialog(parent),
    ui(new Ui::DescriptionWindow){

    ui->setupUi(this);
     ui->textBrowser->setText(description);
     this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

}

DescriptionWindow::~DescriptionWindow(){
    delete ui;
}

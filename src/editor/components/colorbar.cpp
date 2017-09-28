#include "colorbar.h"
#include "ui_colorbar.h"

ColorBar::ColorBar(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::ColorBar) {
  ui->setupUi(this);
  connect(this->ui->pushButton_selectColor, SIGNAL(clicked()), this, SLOT(selectColor()));
  connect(this->ui->pushButton_insert, SIGNAL(clicked()), this, SLOT(insert()));
  connect(this->ui->pushButton_cancel, SIGNAL(clicked()), this, SLOT(closeDialog()));
  connect(this->ui->pushButton_OK, SIGNAL(clicked()), this, SLOT(on_pushButton_OK_clicked()));
  connect(this->ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(enableDelButton()));

  this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

  this->ui->pushButton_del->setEnabled(false);
}

ColorBar::~ColorBar() {
  delete ui;
}

void ColorBar::selectColor() {
  QColor color = QColorDialog::getColor(Qt::white, this);
  if(color.isValid()) {
    QString colorRgb = QString("{%1,%2,%3}").arg(color.red()).arg(color.green()).arg(color.blue());
    this->ui->lineEdit_color->setText(colorRgb);

    QPalette* palette = new QPalette();
    palette->setColor(QPalette::Base, color);

    this->ui->lineEdit_color->setPalette(*palette);
    this->ui->lineEdit_color->setAutoFillBackground(true);
  }
}

void ColorBar::insert() {
  if(this->ui->lineEdit_color->text().isEmpty()) {
    QMessageBox::critical(this, "Undefined color", "A color must be defined");
  } else {
    this->color = "";
    this->color += "{color = ";
    this->color += this->ui->lineEdit_color->text();
    this->color += ", value = ";
    this->color += this->ui->spinBox_attValue->text();
    this->color += " * legend_scale}";

    this->ui->listWidget->insertItem(0, this->color);
  }
}

void ColorBar::closeDialog() {
  this->color = "";
  close();
}

void ColorBar::on_pushButton_OK_clicked() {
  QStringList item;
  QString colorBar;
  int count = ui->listWidget->count();

  for(int index = 0;
      index < count;
      index++) {
    item << ui->listWidget->item(index)->text();
  }

  colorBar = item.join(", ");

  emit valueChanged(colorBar);

  close();
}

void ColorBar::enableDelButton() {
  this->ui->pushButton_del->setEnabled(true);
  connect(this->ui->pushButton_del, SIGNAL(clicked()), this, SLOT(delItem()));
}

void ColorBar::delItem() {
  delete this->ui->listWidget->takeItem(this->ui->listWidget->currentRow());
}

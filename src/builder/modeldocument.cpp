#include "modeldocument.h"
#include "ui_modeldocument.h"
#include "descriptionwindow.h"

ModelDocument::ModelDocument(QWidget* parent, QString filepath) :
  QDialog(parent),
  ui(new Ui::ModelDocument) {
  ui->setupUi(this);

  QStringList information = filepath.split("/");
  filepath = filepath.replace(".xml", "Doc.html");

  QFileInfo info(filepath);
  QFile file(filepath);

  if(!file.exists()) {
    file.open(QFile::WriteOnly | QFile::Truncate);
  } else {

    file.open(QFile::ReadOnly | QFile::Truncate);
    QTextStream out(&file);
    QString text = out.readAll();
    text.replace("<h1>", "##");
    text.replace("</h1><br>", "\n");
    text.replace("<b>", "**");
    text.replace("</b>", "**");
    text.replace("<br>\n", "\n");
    ui->descriptionBox->setText(text);

  }
  file.close();
  ui->filenameLabel->setText(tr("Filepath: ") + filepath);
  ui->modelName->setText(information.at(information.count() - 2));
  ui->modelType->setText(information.at(information.count() - 3));
  connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(save()));
  connect(ui->helpSyntax, SIGNAL(clicked()), this, SLOT(openSyntaxHelp()));
}

void ModelDocument::closeEvent(QCloseEvent* event) {

  QMessageBox msgBox(
    QMessageBox::Question,
    tr("Close Description"),
    tr("Save description before closing?"),
    QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

  msgBox.setButtonText(QMessageBox::Save, trUtf8("Save"));
  msgBox.setButtonText(QMessageBox::Discard, trUtf8("Discard"));
  msgBox.setButtonText(QMessageBox::Cancel, trUtf8("Cancel"));
  switch (msgBox.exec()) {
    case QMessageBox::Cancel:
      event->ignore();


    case QMessageBox::Save:
      save();

    //Fallthrough
    case QMessageBox::Discard:
      QDialog ::closeEvent(event);

  }
}
void ModelDocument::openSyntaxHelp() {

  QString helpText = tr("<h1> Syntax Help </h1> \n"
                        "If you want to make titles, just use the double # keyword and break a line at the end <br>"
                        "<br>Example =\n ## Model Description"
                        "<br> Text Text <br>"
                        "<br>To make a word/phrase bold, use **<br>"
                        "Example = **Bold Words **")
                     ;
  DescriptionWindow* descript = new DescriptionWindow(this, helpText);
  descript->show();
}

void ModelDocument::save() {

  QFile file(ui->filenameLabel->text().replace("Filepath: ", ""));
  file.open(QFile::WriteOnly | QFile::Truncate);

  QTextStream out(&file);
  QString text = ui->descriptionBox->toPlainText();

  int count = 0;

  while(count < text.size() - 1) {
    if(text.at(count) == '#' && text.at(count + 1) == '#') {
      int location = count;

      while(text.at(count) != '\n' && count < text.size() - 1)
        count ++;

      if(count < text.size() - 1) {
        text.replace(location, 2, "<h1>");
        text.replace(count + 2, 1, "</h1>\n");
      }
    } else if(text.at(count) == '*' && text.at(count + 1) == '*') {
      int location = count;
      count ++;
      while((text.at(count) != '*' || text.at(count + 1) != '*') && count < text.size() - 1)
        count ++;

      if(count < text.size() - 1) {
        text.replace(location, 2, "<b>");
        text.replace(count + 1, 2, "</b>");
      }
    } else if(text.at(count) == '\n') {
      text.replace(count, 1, "<br>");
      count++;
    } else
      count++;
  }

  out << text;
  file.close();

}

ModelDocument::~ModelDocument() {
  delete ui;
}

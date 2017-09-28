#include "dengueme.h"
#include "about.h"
#include "ui_about.h"

About::About(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::About) {
  this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
  ui->setupUi(this);

  connect(ui->closeButton, SIGNAL(released()), this, SLOT(close()));

  QDir modelsDir(ABS_APP_DIR);
#if defined(Q_OS_MACOS)
  modelsDir.cdUp();
  modelsDir.cdUp();
#endif
  modelsDir.cdUp();

  if (dengueme::config("locale") != "English")
    ui->textBrowser->setSource(*new QUrl("file:///" + modelsDir.absolutePath() + "/docs/about_ptbr.html"));
  else
    ui->textBrowser->setSource(*new QUrl("file:///" + modelsDir.absolutePath() + "/docs/about.html"));
}

About::~About() {
  delete ui;
}

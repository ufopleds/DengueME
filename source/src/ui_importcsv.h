/********************************************************************************
** Form generated from reading UI file 'importcsv.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTCSV_H
#define UI_IMPORTCSV_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImportCsv
{
public:
    QAction *actionHelp;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *var;
    QFrame *line;
    QLineEdit *label;
    QWidget *spacer;
    QPushButton *importButton;
    QToolButton *options;
    QTextEdit *textEdit;

    void setupUi(QWidget *ImportCsv)
    {
        if (ImportCsv->objectName().isEmpty())
            ImportCsv->setObjectName(QString::fromUtf8("ImportCsv"));
        ImportCsv->resize(399, 124);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImportCsv->sizePolicy().hasHeightForWidth());
        ImportCsv->setSizePolicy(sizePolicy);
        actionHelp = new QAction(ImportCsv);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/Resources/img/icon_information.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon);
        verticalLayout = new QVBoxLayout(ImportCsv);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        var = new QLineEdit(ImportCsv);
        var->setObjectName(QString::fromUtf8("var"));
        var->setStyleSheet(QString::fromUtf8("QLineEdit { background-color:transparent; }"));
        var->setFrame(false);

        horizontalLayout->addWidget(var);

        line = new QFrame(ImportCsv);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label = new QLineEdit(ImportCsv);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("QLineEdit { background-color:transparent; }"));
        label->setFrame(false);

        horizontalLayout->addWidget(label);

        spacer = new QWidget(ImportCsv);
        spacer->setObjectName(QString::fromUtf8("spacer"));
        spacer->setMinimumSize(QSize(32, 0));

        horizontalLayout->addWidget(spacer);

        importButton = new QPushButton(ImportCsv);
        importButton->setObjectName(QString::fromUtf8("importButton"));

        horizontalLayout->addWidget(importButton);

        options = new QToolButton(ImportCsv);
        options->setObjectName(QString::fromUtf8("options"));
        options->setPopupMode(QToolButton::InstantPopup);
        options->setToolButtonStyle(Qt::ToolButtonTextOnly);
        options->setAutoRaise(true);
        options->setArrowType(Qt::DownArrow);

        horizontalLayout->addWidget(options);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(2, 3);

        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(ImportCsv);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        retranslateUi(ImportCsv);

        QMetaObject::connectSlotsByName(ImportCsv);
    } // setupUi

    void retranslateUi(QWidget *ImportCsv)
    {
        ImportCsv->setWindowTitle(QApplication::translate("ImportCsv", "Form", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("ImportCsv", "Help", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        var->setToolTip(QApplication::translate("ImportCsv", "Variable name", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        var->setPlaceholderText(QApplication::translate("ImportCsv", "Variable...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("ImportCsv", "Label", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setPlaceholderText(QApplication::translate("ImportCsv", "Label...", 0, QApplication::UnicodeUTF8));
        importButton->setText(QApplication::translate("ImportCsv", "Import From CSV", 0, QApplication::UnicodeUTF8));
        options->setText(QString());
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("ImportCsv", "Default value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        textEdit->setHtml(QApplication::translate("ImportCsv", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImportCsv: public Ui_ImportCsv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTCSV_H

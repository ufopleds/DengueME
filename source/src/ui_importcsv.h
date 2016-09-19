/********************************************************************************
** Form generated from reading UI file 'importcsv.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTCSV_H
#define UI_IMPORTCSV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QPushButton *importButton;
    QToolButton *options;
    QToolButton *toolClone;
    QToolButton *toolOptions;
    QToolButton *toolDelete;
    QTextEdit *textEdit;

    void setupUi(QWidget *ImportCsv)
    {
        if (ImportCsv->objectName().isEmpty())
            ImportCsv->setObjectName(QStringLiteral("ImportCsv"));
        ImportCsv->resize(590, 187);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImportCsv->sizePolicy().hasHeightForWidth());
        ImportCsv->setSizePolicy(sizePolicy);
        actionHelp = new QAction(ImportCsv);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/Resources/img/icon_information.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon);
        verticalLayout = new QVBoxLayout(ImportCsv);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        var = new QLineEdit(ImportCsv);
        var->setObjectName(QStringLiteral("var"));
        var->setStyleSheet(QStringLiteral("QLineEdit { background-color:transparent; }"));
        var->setFrame(false);

        horizontalLayout->addWidget(var);

        line = new QFrame(ImportCsv);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label = new QLineEdit(ImportCsv);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("QLineEdit { background-color:transparent; }"));
        label->setFrame(false);

        horizontalLayout->addWidget(label);

        importButton = new QPushButton(ImportCsv);
        importButton->setObjectName(QStringLiteral("importButton"));

        horizontalLayout->addWidget(importButton);

        options = new QToolButton(ImportCsv);
        options->setObjectName(QStringLiteral("options"));
        options->setPopupMode(QToolButton::InstantPopup);
        options->setToolButtonStyle(Qt::ToolButtonTextOnly);
        options->setAutoRaise(true);
        options->setArrowType(Qt::DownArrow);

        horizontalLayout->addWidget(options);

        toolClone = new QToolButton(ImportCsv);
        toolClone->setObjectName(QStringLiteral("toolClone"));
        toolClone->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/clone.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolClone->setIcon(icon1);
        toolClone->setIconSize(QSize(24, 24));
        toolClone->setPopupMode(QToolButton::InstantPopup);
        toolClone->setAutoRaise(true);

        horizontalLayout->addWidget(toolClone);

        toolOptions = new QToolButton(ImportCsv);
        toolOptions->setObjectName(QStringLiteral("toolOptions"));
        toolOptions->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolOptions->setIcon(icon2);
        toolOptions->setIconSize(QSize(24, 24));
        toolOptions->setPopupMode(QToolButton::InstantPopup);
        toolOptions->setAutoRaise(true);

        horizontalLayout->addWidget(toolOptions);

        toolDelete = new QToolButton(ImportCsv);
        toolDelete->setObjectName(QStringLiteral("toolDelete"));
        toolDelete->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/Resources/Trash-52 (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        toolDelete->setIcon(icon3);
        toolDelete->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(toolDelete);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(2, 5);

        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(ImportCsv);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);


        retranslateUi(ImportCsv);

        QMetaObject::connectSlotsByName(ImportCsv);
    } // setupUi

    void retranslateUi(QWidget *ImportCsv)
    {
        ImportCsv->setWindowTitle(QApplication::translate("ImportCsv", "Form", 0));
        actionHelp->setText(QApplication::translate("ImportCsv", "Help", 0));
#ifndef QT_NO_TOOLTIP
        var->setToolTip(QApplication::translate("ImportCsv", "Variable name", 0));
#endif // QT_NO_TOOLTIP
        var->setPlaceholderText(QApplication::translate("ImportCsv", "Variable...", 0));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("ImportCsv", "Label", 0));
#endif // QT_NO_TOOLTIP
        label->setPlaceholderText(QApplication::translate("ImportCsv", "Label...", 0));
        importButton->setText(QApplication::translate("ImportCsv", "Import From CSV", 0));
        options->setText(QApplication::translate("ImportCsv", "Type", 0));
        toolClone->setText(QApplication::translate("ImportCsv", "...", 0));
        toolClone->setShortcut(QApplication::translate("ImportCsv", "Ctrl++", 0));
        toolOptions->setText(QApplication::translate("ImportCsv", "...", 0));
        toolDelete->setText(QApplication::translate("ImportCsv", "...", 0));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("ImportCsv", "Default value", 0));
#endif // QT_NO_TOOLTIP
        textEdit->setHtml(QApplication::translate("ImportCsv", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class ImportCsv: public Ui_ImportCsv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTCSV_H

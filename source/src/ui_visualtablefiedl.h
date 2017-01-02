/********************************************************************************
** Form generated from reading UI file 'visualtablefiedl.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALTABLEFIEDL_H
#define UI_VISUALTABLEFIEDL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisualTableFiedl
{
public:

    void setupUi(QWidget *VisualTableFiedl)
    {
        if (VisualTableFiedl->objectName().isEmpty())
            VisualTableFiedl->setObjectName(QStringLiteral("VisualTableFiedl"));
        VisualTableFiedl->resize(400, 300);

        retranslateUi(VisualTableFiedl);

        QMetaObject::connectSlotsByName(VisualTableFiedl);
    } // setupUi

    void retranslateUi(QWidget *VisualTableFiedl)
    {
        VisualTableFiedl->setWindowTitle(QApplication::translate("VisualTableFiedl", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class VisualTableFiedl: public Ui_VisualTableFiedl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALTABLEFIEDL_H

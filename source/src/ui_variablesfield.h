/********************************************************************************
** Form generated from reading UI file 'variablesfield.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VARIABLESFIELD_H
#define UI_VARIABLESFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VariablesField
{
public:

    void setupUi(QWidget *VariablesField)
    {
        if (VariablesField->objectName().isEmpty())
            VariablesField->setObjectName(QStringLiteral("VariablesField"));
        VariablesField->resize(706, 353);

        retranslateUi(VariablesField);

        QMetaObject::connectSlotsByName(VariablesField);
    } // setupUi

    void retranslateUi(QWidget *VariablesField)
    {
        VariablesField->setWindowTitle(QApplication::translate("VariablesField", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class VariablesField: public Ui_VariablesField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIABLESFIELD_H

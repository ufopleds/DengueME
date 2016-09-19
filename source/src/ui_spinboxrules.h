/********************************************************************************
** Form generated from reading UI file 'spinboxrules.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPINBOXRULES_H
#define UI_SPINBOXRULES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SpinBoxRules
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QSpinBox *minimum;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *maximum;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SpinBoxRules)
    {
        if (SpinBoxRules->objectName().isEmpty())
            SpinBoxRules->setObjectName(QStringLiteral("SpinBoxRules"));
        SpinBoxRules->resize(400, 129);
        SpinBoxRules->setMinimumSize(QSize(400, 0));
        verticalLayout = new QVBoxLayout(SpinBoxRules);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        minimum = new QSpinBox(SpinBoxRules);
        minimum->setObjectName(QStringLiteral("minimum"));

        formLayout->setWidget(0, QFormLayout::FieldRole, minimum);

        label = new QLabel(SpinBoxRules);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(SpinBoxRules);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        maximum = new QSpinBox(SpinBoxRules);
        maximum->setObjectName(QStringLiteral("maximum"));

        formLayout->setWidget(1, QFormLayout::FieldRole, maximum);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(SpinBoxRules);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SpinBoxRules);
        QObject::connect(buttonBox, SIGNAL(accepted()), SpinBoxRules, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SpinBoxRules, SLOT(reject()));
        QObject::connect(minimum, SIGNAL(valueChanged(int)), SpinBoxRules, SLOT(minimumChanged(int)));
        QObject::connect(maximum, SIGNAL(valueChanged(int)), SpinBoxRules, SLOT(maximumChanged(int)));

        QMetaObject::connectSlotsByName(SpinBoxRules);
    } // setupUi

    void retranslateUi(QDialog *SpinBoxRules)
    {
        SpinBoxRules->setWindowTitle(QApplication::translate("SpinBoxRules", "Dialog", 0));
        label->setText(QApplication::translate("SpinBoxRules", "Minimum:", 0));
        label_2->setText(QApplication::translate("SpinBoxRules", "Maximum:", 0));
    } // retranslateUi

};

namespace Ui {
    class SpinBoxRules: public Ui_SpinBoxRules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPINBOXRULES_H

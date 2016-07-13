/********************************************************************************
** Form generated from reading UI file 'spinboxrules.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPINBOXRULES_H
#define UI_SPINBOXRULES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

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
            SpinBoxRules->setObjectName(QString::fromUtf8("SpinBoxRules"));
        SpinBoxRules->resize(400, 129);
        SpinBoxRules->setMinimumSize(QSize(400, 0));
        verticalLayout = new QVBoxLayout(SpinBoxRules);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        minimum = new QSpinBox(SpinBoxRules);
        minimum->setObjectName(QString::fromUtf8("minimum"));

        formLayout->setWidget(0, QFormLayout::FieldRole, minimum);

        label = new QLabel(SpinBoxRules);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(SpinBoxRules);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        maximum = new QSpinBox(SpinBoxRules);
        maximum->setObjectName(QString::fromUtf8("maximum"));

        formLayout->setWidget(1, QFormLayout::FieldRole, maximum);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(SpinBoxRules);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
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
        SpinBoxRules->setWindowTitle(QApplication::translate("SpinBoxRules", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SpinBoxRules", "Minimum:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SpinBoxRules", "Maximum:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SpinBoxRules: public Ui_SpinBoxRules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPINBOXRULES_H

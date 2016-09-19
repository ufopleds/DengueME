/********************************************************************************
** Form generated from reading UI file 'doublespinboxrules.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLESPINBOXRULES_H
#define UI_DOUBLESPINBOXRULES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DoubleSpinBoxRules
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *precision;
    QLabel *label_2;
    QDoubleSpinBox *minimum;
    QLabel *label_3;
    QDoubleSpinBox *maximum;
    QDoubleSpinBox *step;
    QLabel *label_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DoubleSpinBoxRules)
    {
        if (DoubleSpinBoxRules->objectName().isEmpty())
            DoubleSpinBoxRules->setObjectName(QStringLiteral("DoubleSpinBoxRules"));
        DoubleSpinBoxRules->resize(400, 193);
        DoubleSpinBoxRules->setMinimumSize(QSize(400, 0));
        verticalLayout = new QVBoxLayout(DoubleSpinBoxRules);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(DoubleSpinBoxRules);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        precision = new QSpinBox(DoubleSpinBoxRules);
        precision->setObjectName(QStringLiteral("precision"));
        precision->setMaximum(323);

        formLayout->setWidget(0, QFormLayout::FieldRole, precision);

        label_2 = new QLabel(DoubleSpinBoxRules);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        minimum = new QDoubleSpinBox(DoubleSpinBoxRules);
        minimum->setObjectName(QStringLiteral("minimum"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(minimum->sizePolicy().hasHeightForWidth());
        minimum->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, minimum);

        label_3 = new QLabel(DoubleSpinBoxRules);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        maximum = new QDoubleSpinBox(DoubleSpinBoxRules);
        maximum->setObjectName(QStringLiteral("maximum"));
        sizePolicy.setHeightForWidth(maximum->sizePolicy().hasHeightForWidth());
        maximum->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, maximum);

        step = new QDoubleSpinBox(DoubleSpinBoxRules);
        step->setObjectName(QStringLiteral("step"));
        sizePolicy.setHeightForWidth(step->sizePolicy().hasHeightForWidth());
        step->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::FieldRole, step);

        label_4 = new QLabel(DoubleSpinBoxRules);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(DoubleSpinBoxRules);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DoubleSpinBoxRules);
        QObject::connect(buttonBox, SIGNAL(accepted()), DoubleSpinBoxRules, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DoubleSpinBoxRules, SLOT(reject()));
        QObject::connect(precision, SIGNAL(valueChanged(int)), DoubleSpinBoxRules, SLOT(precisionChanged(int)));
        QObject::connect(minimum, SIGNAL(valueChanged(double)), DoubleSpinBoxRules, SLOT(minimumChanged(double)));
        QObject::connect(maximum, SIGNAL(valueChanged(double)), DoubleSpinBoxRules, SLOT(maximumChanged(double)));
        QObject::connect(step, SIGNAL(valueChanged(double)), DoubleSpinBoxRules, SLOT(stepChanged(double)));

        QMetaObject::connectSlotsByName(DoubleSpinBoxRules);
    } // setupUi

    void retranslateUi(QDialog *DoubleSpinBoxRules)
    {
        DoubleSpinBoxRules->setWindowTitle(QApplication::translate("DoubleSpinBoxRules", "Double Spin Box Settings", 0));
        label->setText(QApplication::translate("DoubleSpinBoxRules", "Precision:", 0));
        label_2->setText(QApplication::translate("DoubleSpinBoxRules", "Mininum:", 0));
        label_3->setText(QApplication::translate("DoubleSpinBoxRules", "Maximum:", 0));
        label_4->setText(QApplication::translate("DoubleSpinBoxRules", "Single step:", 0));
    } // retranslateUi

};

namespace Ui {
    class DoubleSpinBoxRules: public Ui_DoubleSpinBoxRules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLESPINBOXRULES_H

/********************************************************************************
** Form generated from reading UI file 'doublespinboxrules.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLESPINBOXRULES_H
#define UI_DOUBLESPINBOXRULES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

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
            DoubleSpinBoxRules->setObjectName(QString::fromUtf8("DoubleSpinBoxRules"));
        DoubleSpinBoxRules->resize(400, 193);
        DoubleSpinBoxRules->setMinimumSize(QSize(400, 0));
        verticalLayout = new QVBoxLayout(DoubleSpinBoxRules);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(DoubleSpinBoxRules);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        precision = new QSpinBox(DoubleSpinBoxRules);
        precision->setObjectName(QString::fromUtf8("precision"));
        precision->setMaximum(323);

        formLayout->setWidget(0, QFormLayout::FieldRole, precision);

        label_2 = new QLabel(DoubleSpinBoxRules);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        minimum = new QDoubleSpinBox(DoubleSpinBoxRules);
        minimum->setObjectName(QString::fromUtf8("minimum"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(minimum->sizePolicy().hasHeightForWidth());
        minimum->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, minimum);

        label_3 = new QLabel(DoubleSpinBoxRules);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        maximum = new QDoubleSpinBox(DoubleSpinBoxRules);
        maximum->setObjectName(QString::fromUtf8("maximum"));
        sizePolicy.setHeightForWidth(maximum->sizePolicy().hasHeightForWidth());
        maximum->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, maximum);

        step = new QDoubleSpinBox(DoubleSpinBoxRules);
        step->setObjectName(QString::fromUtf8("step"));
        sizePolicy.setHeightForWidth(step->sizePolicy().hasHeightForWidth());
        step->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::FieldRole, step);

        label_4 = new QLabel(DoubleSpinBoxRules);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(DoubleSpinBoxRules);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
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
        DoubleSpinBoxRules->setWindowTitle(QApplication::translate("DoubleSpinBoxRules", "Double Spin Box Settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DoubleSpinBoxRules", "Precision:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DoubleSpinBoxRules", "Mininum:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DoubleSpinBoxRules", "Maximum:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DoubleSpinBoxRules", "Single step:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DoubleSpinBoxRules: public Ui_DoubleSpinBoxRules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLESPINBOXRULES_H

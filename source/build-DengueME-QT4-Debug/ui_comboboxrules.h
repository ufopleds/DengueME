/********************************************************************************
** Form generated from reading UI file 'comboboxrules.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMBOBOXRULES_H
#define UI_COMBOBOXRULES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ComboBoxRules
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *list;
    QVBoxLayout *verticalLayout_2;
    QToolButton *add;
    QToolButton *del;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ComboBoxRules)
    {
        if (ComboBoxRules->objectName().isEmpty())
            ComboBoxRules->setObjectName(QString::fromUtf8("ComboBoxRules"));
        ComboBoxRules->resize(400, 169);
        ComboBoxRules->setMinimumSize(QSize(400, 0));
        verticalLayout = new QVBoxLayout(ComboBoxRules);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        list = new QListWidget(ComboBoxRules);
        list->setObjectName(QString::fromUtf8("list"));
        list->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        list->setDragEnabled(true);
        list->setDragDropMode(QAbstractItemView::InternalMove);

        horizontalLayout->addWidget(list);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        add = new QToolButton(ComboBoxRules);
        add->setObjectName(QString::fromUtf8("add"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/plus"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon);

        verticalLayout_2->addWidget(add);

        del = new QToolButton(ComboBoxRules);
        del->setObjectName(QString::fromUtf8("del"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Resources/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        del->setIcon(icon1);

        verticalLayout_2->addWidget(del);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(ComboBoxRules);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ComboBoxRules);
        QObject::connect(buttonBox, SIGNAL(accepted()), ComboBoxRules, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ComboBoxRules, SLOT(reject()));

        QMetaObject::connectSlotsByName(ComboBoxRules);
    } // setupUi

    void retranslateUi(QDialog *ComboBoxRules)
    {
        ComboBoxRules->setWindowTitle(QApplication::translate("ComboBoxRules", "Dialog", 0, QApplication::UnicodeUTF8));
        add->setText(QApplication::translate("ComboBoxRules", "+", 0, QApplication::UnicodeUTF8));
        del->setText(QApplication::translate("ComboBoxRules", "-", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ComboBoxRules: public Ui_ComboBoxRules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBOBOXRULES_H

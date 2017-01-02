/********************************************************************************
** Form generated from reading UI file 'chartgroup.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTGROUP_H
#define UI_CHARTGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QListWidget *widgets;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *label;
    QCheckBox *useChart;
    QToolButton *addField;
    QSpacerItem *horizontalSpacer;
    QToolButton *removeGroup;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(450, 115);
        widgets = new QListWidget(Form);
        widgets->setObjectName(QStringLiteral("widgets"));
        widgets->setGeometry(QRect(10, 30, 432, 73));
        widgets->setDragDropMode(QAbstractItemView::InternalMove);
        widgets->setSelectionMode(QAbstractItemView::ExtendedSelection);
        widgets->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        widgets->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 431, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLineEdit(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral(""));
        label->setFrame(true);

        horizontalLayout->addWidget(label);

        useChart = new QCheckBox(layoutWidget);
        useChart->setObjectName(QStringLiteral("useChart"));
        useChart->setEnabled(false);

        horizontalLayout->addWidget(useChart);

        addField = new QToolButton(layoutWidget);
        addField->setObjectName(QStringLiteral("addField"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/plus"), QSize(), QIcon::Normal, QIcon::Off);
        addField->setIcon(icon);
        addField->setIconSize(QSize(15, 15));
        addField->setPopupMode(QToolButton::InstantPopup);
        addField->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        addField->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(addField);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        removeGroup = new QToolButton(layoutWidget);
        removeGroup->setObjectName(QStringLiteral("removeGroup"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeGroup->setIcon(icon1);
        removeGroup->setPopupMode(QToolButton::InstantPopup);
        removeGroup->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        removeGroup->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(removeGroup);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("Form", "Group name", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Form", "New chart", 0));
        useChart->setText(QApplication::translate("Form", "Use this chart view?", 0));
        addField->setText(QApplication::translate("Form", "Add field", 0));
        removeGroup->setText(QApplication::translate("Form", "Remove chart", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTGROUP_H
